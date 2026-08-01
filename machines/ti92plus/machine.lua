-- TI-92 Plus: MC68000 HW2 + 256KB RAM + 2MB Flash + 240×128 QWERTY landscape.

local M68K = require("cpus.m68k.m68k")
local Ram = require("machines.ti92plus.mem.ram")
local Flash = require("machines.ti92plus.mem.flash")
local Lcd = require("machines.ti92plus.hw.lcd")
local Keyboard = require("machines.ti92plus.hw.keyboard")
local Bus = require("machines.ti92plus.hw.bus")
local Protocol = require("framework.machine")
local SaveState = require("framework.savestate")

local CPU_HZ = 12000000 -- HW2-class (~12 MHz; same family as TI-89 HW2)
local MACHINE_ID = "ti92plus"
local FLASH_SIZE = 2 * 1024 * 1024

local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ
Machine.MACHINE_ID = MACHINE_ID
Machine.MODEL = "TI-92 Plus"

function Machine.new()
  local self = setmetatable({}, Machine)
  self.ram = Ram.new()
  self.flash = Flash.new(FLASH_SIZE)
  self.lcd = Lcd.new()
  self.keyboard = Keyboard.new()
  self.bus = Bus.new({
    ram = self.ram,
    flash = self.flash,
    lcd = self.lcd,
    keyboard = self.keyboard,
  })
  self.bus.hw = 2
  local bus = self.bus
  self.cpu = M68K.new({
    read8 = function(a) return bus:read8(a) end,
    write8 = function(a, v) bus:write8(a, v) end,
    read16 = function(a) return bus:read16(a) end,
    write16 = function(a, v) bus:write16(a, v) end,
    read32 = function(a) return bus:read32(a) end,
    write32 = function(a, v) bus:write32(a, v) end,
    exec_allowed = function(_, addr) return bus:exec_allowed(addr) end,
  })
  bus.cpu = self.cpu
  self.memory = self.bus
  self.mmu = self.bus
  self.rom_loaded = false
  self.total_cycles = 0
  Protocol.apply(self)
  return self
end

function Machine:load_rom_bytes(bytes)
  local TiflOs = require("machines.ti92plus.util.tifl_os")
  local image, meta = TiflOs.extract_rom(bytes)
  if not image then return nil, meta end
  local ok, err = self.flash:load(image)
  if not ok then return nil, err end
  local src = 0
  local w = self.flash:read8(0x12000) * 256 + self.flash:read8(0x12001)
  if w == 0x800F or w == 0x800E then
    src = 0x12088
  end
  for i = 0, 0xFF do
    self.ram.bytes[i] = self.flash:read8(src + i)
  end
  self.rom_loaded = true
  self.rom_meta = meta
  return true, meta
end

function Machine:load_rom_file(path)
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local data = f:read("*a")
  f:close()
  return self:load_rom_bytes(data)
end

function Machine:reset()
  self.bus:reset()
  -- 10-row QWERTY mask (docs often $03FF / $0280-class); force after bus reset.
  self.keyboard:write_mask(0x03FF)
  if self.rom_loaded then
    local src = 0
    local w = self.flash:read8(0x12000) * 256 + self.flash:read8(0x12001)
    if w == 0x800F or w == 0x800E then
      src = 0x12088
    end
    for i = 0, 0xFF do
      self.ram.bytes[i] = self.flash:read8(src + i)
    end
  end
  self.cpu:reset()
  self.cpu.sr = 0x2700
  self.total_cycles = 0
  self.lcd._dirty = true
end

function Machine:run_cycles(budget)
  if not self.rom_loaded then return 0 end
  local cpu = self.cpu
  local bus = self.bus
  local ran = 0
  local pending = 0
  local BATCH = 256
  local irq_every = 16
  local until_irq = irq_every

  while ran < budget do
    if cpu.stopped then
      if pending > 0 then
        bus:tick(pending)
        pending = 0
      end
      local slice = math.min(62500, budget - ran)
      bus:tick(slice)
      ran = ran + slice
      local irq = bus:irq_level_pending()
      if irq > 0 then cpu:interrupt(irq) end
    else
      until_irq = until_irq - 1
      if until_irq == 0 then
        until_irq = irq_every
        if pending > 0 then
          bus:tick(pending)
          pending = 0
        end
        local irq = bus:irq_level_pending()
        if irq > 0 then cpu:interrupt(irq) end
      end
      local cyc = cpu:step()
      pending = pending + cyc
      ran = ran + cyc
      if pending >= BATCH then
        bus:tick(pending)
        pending = 0
      end
    end
  end
  if pending > 0 then
    bus:tick(pending)
  end
  self.total_cycles = self.total_cycles + ran
  return ran
end

function Machine:step_instruction()
  if not self.rom_loaded then return 0 end
  local cyc = self.cpu:step()
  self.bus:tick(cyc)
  self.total_cycles = self.total_cycles + cyc
  self.lcd._dirty = true
  return cyc
end

function Machine:cycles_per_frame(fps)
  return math.floor(CPU_HZ / (fps or 60))
end

function Machine:set_key(name, down)
  return self.keyboard:set_key(name, down)
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
  return self.lcd:is_display_on()
end

function Machine:pc()
  return self.cpu.pc
end

local function copy_bytes(src, dst, n)
  if type(src) ~= "table" then return end
  for i = 0, n - 1 do
    dst[i] = src[i] or 0
  end
end

function Machine:saveState()
  local bus = self.bus
  return SaveState.new(MACHINE_ID, {
    cpu = self.cpu:getRegisters(),
    ram = SaveState.pack_bytes(self.ram.bytes, self.ram.SIZE),
    flash = self.flash:dump(),
    flash_cmd = {
      mode = self.flash.mode,
      status = self.flash.status,
    },
    lcd_base = self.lcd.base,
    lcd_fb = SaveState.pack_bytes(self.lcd.fb, 30 * 128),
    io = bus.io,
    io7 = bus.io7,
    io71 = bus.io71,
    bus_extra = {
      rtc_div = bus.rtc_div,
      rtc3_load_s = bus.rtc3_load_s,
      rtc3_load_frac = bus.rtc3_load_frac,
      rtc3_cycles = bus.rtc3_cycles,
    },
    total_cycles = self.total_cycles,
    rom_loaded = self.rom_loaded,
  })
end

function Machine:loadState(state)
  local ok, err = SaveState.validate(state, MACHINE_ID)
  if not ok then return nil, err end
  local b = state.blobs
  local bus = self.bus
  self.cpu:setRegisters(b.cpu)
  SaveState.unpack_bytes(b.ram, self.ram.bytes)
  if b.flash then
    self.flash:load(b.flash)
  end
  if b.flash_cmd then
    self.flash.mode = b.flash_cmd.mode or "read"
    self.flash.status = b.flash_cmd.status or 0x80
  end
  if b.lcd_fb then SaveState.unpack_bytes(b.lcd_fb, self.lcd.fb) end
  self.lcd.base = b.lcd_base or self.lcd.base
  copy_bytes(b.io, bus.io, 256)
  copy_bytes(b.io7, bus.io7, 256)
  copy_bytes(b.io71, bus.io71, 256)
  if b.bus_extra then
    bus.rtc_div = b.bus_extra.rtc_div or bus.rtc_div
    bus.rtc3_load_s = b.bus_extra.rtc3_load_s or bus.rtc3_load_s
    bus.rtc3_load_frac = b.bus_extra.rtc3_load_frac or bus.rtc3_load_frac
    bus.rtc3_cycles = b.bus_extra.rtc3_cycles or bus.rtc3_cycles
  end
  self.total_cycles = b.total_cycles or 0
  self.rom_loaded = b.rom_loaded
  self.lcd._dirty = true
  return true
end

return Machine
