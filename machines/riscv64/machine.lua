-- Custom RV64 machine: modular bus + devices (Love IDE / unit tests).
--
-- Devices register on the bus; CPU only sees read/write callbacks.
-- Boot payloads (OpenSBI / Image / DTB) are host files - see boot.lua.

local Ram = require("machines.riscv64.mem.ram")
local Rom = require("machines.riscv64.mem.rom")
local Uart = require("machines.riscv64.hw.uart")
local Clint = require("machines.riscv64.hw.clint")
local Plic = require("machines.riscv64.hw.plic")
local Halt = require("machines.riscv64.hw.halt")
local Bus = require("machines.riscv64.hw.bus")
local Lcd = require("machines.riscv64.hw.lcd")
local Boot = require("machines.riscv64.boot")
local RV64I = require("cpus.riscv.rv64i")
local U64 = require("cpus.riscv.u64")
local Csr = require("cpus.riscv.csr")
local Sbi = require("machines.riscv64.sbi")
local Protocol = require("framework.machine")
local SaveState = require("framework.savestate")
local bit = require("framework.util.bit")

-- Target guest clock for the IDE speed meter. Real sustained rate is lower in
-- pure Lua; the Love frame loop is deadline-capped so UI stays interactive.
local CPU_HZ = 10000000
local MACHINE_ID = "riscv64"
local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ
Machine.MACHINE_ID = MACHINE_ID
Machine.MODEL = "RV64 Custom"

local function wire_bus(self)
  local bus = Bus.new()
  self.bus_dev = bus
  self.halt_dev = Halt.new(bus)

  -- Priority: first match wins - halt before UART window, devices before RAM/ROM.
  bus:map("halt", Bus.HALT_ADDR, 1, self.halt_dev)
  bus:map("uart", Bus.UART_BASE, Uart.SIZE or 0x100, self.uart)
  bus:map("clint", Bus.CLINT_BASE, Clint.SIZE or 0x10000, self.clint)
  bus:map("plic", Plic.BASE, Plic.SIZE, self.plic)
  bus:map("ram", Bus.RAM_BASE, self.ram.size, self.ram)
  -- Low firmware window (console demos / optional ROM images).
  bus:map("rom", Bus.ROM_BASE, 0x02000000, self.rom)
end

function Machine.new()
  local self = setmetatable({}, Machine)
  self.ram = Ram.new()
  self.rom = Rom.new(0)
  self.uart = Uart.new()
  self.clint = Clint.new()
  self.plic = Plic.new()
  self.lcd = Lcd.new()
  wire_bus(self)

  local bus_dev = self.bus_dev
  local self_ref = self
  self.cpu = RV64I.new({
    read8 = function(a) return bus_dev:read8(a) end,
    write8 = function(a, v)
      bus_dev:write8(a, v)
      if bus_dev.halted and self_ref.cpu then
        self_ref.cpu.halted = true
      end
    end,
    read16 = function(a) return bus_dev:read16(a) end,
    write16 = function(a, v) bus_dev:write16(a, v) end,
    read32 = function(a) return bus_dev:read32(a) end,
    write32 = function(a, v) bus_dev:write32(a, v) end,
  })
  self.rom_loaded = false
  self.use_lua_sbi = true -- until real OpenSBI is loaded
  self.total_cycles = 0
  self._console_len = 0
  local self_m = self
  self.cpu.on_ecall_s = function()
    if not self_m.use_lua_sbi then
      return -- OpenSBI (guest) handles the trap
    end
    if Sbi.handle(self_m.cpu, self_m) then
      Sbi.finish(self_m.cpu)
    end
  end
  Protocol.apply(self)
  return self
end

function Machine:boot_linux(opts)
  -- Prefer OpenSBI path when fw bytes/path provided.
  opts = opts or {}
  if opts.fw_bytes or opts.fw_path then
    return Boot.load_opensbi(self, opts)
  end
  return Boot.load_kernel_s_mode(self, opts)
end

function Machine:boot_opensbi(opts)
  return Boot.load_opensbi(self, opts)
end

function Machine:reset()
  self.bus_dev:reset()
  self.cpu:reset()
  self.cpu:set_x(2, U64.new(0, Bus.RAM_BASE + self.ram.size))
  self.lcd:clear()
  self.lcd:render_text(self.rom_loaded and "" or "RV64 ready\nLoad firmware / OpenSBI")
  self._console_len = 0
  self.total_cycles = 0
  if self.use_lua_sbi == nil then
    self.use_lua_sbi = true
  end
end

function Machine:load_rom_bytes(bytes)
  if type(bytes) ~= "string" or #bytes == 0 then
    return nil, "firmware must be a non-empty binary string"
  end
  self.rom:set_bytes(bytes)
  self.use_lua_sbi = true
  self.rom_loaded = true
  self:reset()
  return true
end

function Machine:load_rom_file(path)
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local data = f:read("*a")
  f:close()
  return self:load_rom_bytes(data)
end

function Machine:sync_timer(cycles)
  if cycles and cycles > 0 then
    self.clint:advance(cycles)
  end
  U64.assign(self.cpu.csr.time, self.clint.mtime)
  self.cpu.csr:set_mip_bit(Csr.INT_M_TIMER, self.clint:timer_pending())
end

function Machine:sync_console()
  local text = self.uart:text()
  if #text ~= self._console_len then
    self._console_len = #text
    self.lcd:render_text(text)
  end
  if self.bus_dev.halted then
    self.cpu.halted = true
  end
end

function Machine:run_cycles(n)
  local budget = math.floor(tonumber(n) or 0)
  local ran = 0
  -- Large slices + infrequent timer sync (68k batches bus ticks the same way).
  while ran < budget do
    local chunk = budget - ran
    if chunk > 65536 then chunk = 65536 end
    local got = self.cpu:run_cycles(chunk)
    if got <= 0 then break end
    ran = ran + got
    self:sync_timer(got)
  end
  -- If mtime crossed mtimecmp on the last slice, enter the IRQ handler.
  if self.clint:timer_pending() and self.cpu.csr:timer_enabled() then
    ran = ran + self.cpu:run_cycles(16)
    self:sync_timer(0)
  end
  self.total_cycles = self.total_cycles + ran
  self:sync_console()
  return ran
end

function Machine:step_instruction()
  local cyc = self.cpu:step()
  self.total_cycles = self.total_cycles + cyc
  self:sync_timer(cyc)
  self:sync_console()
  return cyc
end

function Machine:write_ram(phys_addr, bytes)
  phys_addr = bit.band(phys_addr, 0xFFFFFFFF)
  if phys_addr < Bus.RAM_BASE then
    return nil, "address not in RAM"
  end
  local off = phys_addr - Bus.RAM_BASE
  for i = 1, #bytes do
    self.ram:write8(off + i - 1, bytes:byte(i))
  end
  return true
end

function Machine:cycles_per_frame(fps)
  fps = fps or 60
  return math.floor(CPU_HZ / fps)
end

function Machine:pc()
  return self.cpu:pc_u32()
end

function Machine:set_key(key, down)
  if down and type(key) == "string" and #key == 1 then
    self.uart:push_rx(key:byte(1))
  end
end

function Machine:framebuffer()
  return self.lcd:framebuffer()
end

function Machine:display_dirty()
  return self.lcd:dirty()
end

function Machine:clear_display_dirty()
  self.lcd:clear_dirty()
end

function Machine:is_display_on()
  return self.lcd:is_on()
end

function Machine:saveState()
  return SaveState.new(MACHINE_ID, {
    pc = U64.to_hex(self.cpu.pc),
    total_cycles = self.total_cycles,
    rom_loaded = self.rom_loaded,
    console = self.uart:text(),
  })
end

function Machine:loadState(state)
  local ok, err = SaveState.validate(state, MACHINE_ID)
  if not ok then return nil, err end
  local b = state.blobs or {}
  if type(b.console) == "string" then
    self.uart:reset()
    for i = 1, #b.console do
      self.uart:tx(b.console:byte(i))
    end
    self:sync_console()
  end
  return true
end

return Machine
