-- TI-83 Plus machine facade (engine-agnostic).

local Flash = require("core.mem.flash")
local Ram = require("core.mem.ram")
local Mmu = require("core.mem.mmu")
local Lcd = require("core.hw.lcd")
local Keypad = require("core.hw.keypad")
local Timer = require("core.hw.timer")
local Asic = require("core.hw.asic")
local Z80 = require("core.cpu.z80")
local romutil = require("core.util.rom")

local CPU_HZ = 6000000
local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ

function Machine.new()
  local self = setmetatable({}, Machine)
  self.flash = Flash.new()
  self.ram = Ram.new()
  self.mmu = Mmu.new(self.flash, self.ram)
  self.lcd = Lcd.new()
  self.keypad = Keypad.new()
  self.timer = Timer.new()
  self.asic = Asic.new({
    mmu = self.mmu,
    lcd = self.lcd,
    keypad = self.keypad,
    timer = self.timer,
  })

  local asic = self.asic
  local mmu = self.mmu
  self.cpu = Z80.new({
    read = function(addr) return mmu:read(addr) end,
    write = function(addr, value) mmu:write(addr, value) end,
    in_port = function(port) return asic:in_port(port) end,
    out_port = function(port, value) asic:out_port(port, value) end,
    irq_pending = function() return asic:irq_line() end,
    ack_irq = function() asic:ack_interrupt() end,
  })

  self.rom_loaded = false
  self.total_cycles = 0
  -- Short UI taps can press+release between emu frames; keep keys down for a
  -- minimum emulated time so GetCSC/GetKey can see them (~1 frame at 6 MHz).
  self.min_key_hold_cycles = math.floor(CPU_HZ / 60)
  -- TI power-on from HALT needs ON held ~0.5M+ cycles; a frame is too short
  -- and the calc silently returns to the power-off HALT.
  self.min_on_hold_cycles = math.floor(CPU_HZ / 2)
  self._key_down_at = {}
  self._key_release_at = {}
  return self
end

function Machine:load_rom_bytes(bytes)
  local data, err = romutil.validate(bytes)
  if not data then
    return nil, err
  end
  self.flash:load(data)
  self.rom_loaded = true
  return true
end

function Machine:load_rom_file(path)
  local data, err = romutil.load(path)
  if not data then
    return nil, err
  end
  self.flash:load(data)
  self.rom_loaded = true
  return true
end

--- Full cold reset: RAM, ASIC/LCD/keypad/timer/MMU banks, CPU. Stays at PC=0.
function Machine:reset()
  self.ram:clear()
  self.asic:reset()
  self.cpu:reset()
  self.total_cycles = 0
  self._key_down_at = {}
  self._key_release_at = {}
  self.lcd._dirty = true
end

function Machine:_release_due_keys()
  for name, at in pairs(self._key_release_at) do
    if self.total_cycles >= at then
      self.keypad:set_key(name, false)
      self._key_release_at[name] = nil
      self._key_down_at[name] = nil
    end
  end
end

function Machine:run_cycles(budget)
  if not self.rom_loaded then
    return 0
  end
  local cpu = self.cpu
  local asic = self.asic
  local keypad = self.keypad
  local ran = 0
  local pending = 0
  -- Batch ASIC work while executing; flush often enough for ~timer accuracy.
  local BATCH = 48

  while ran < budget do
    local cyc = cpu:step()
    pending = pending + cyc
    ran = ran + cyc
    if pending >= BATCH or cpu.halted then
      asic:tick(pending)
      pending = 0
    end
  end
  if pending > 0 then
    asic:tick(pending)
  end
  self.total_cycles = self.total_cycles + ran
  self:_release_due_keys()
  return ran
end

function Machine:set_key(name, down)
  if down then
    self._key_release_at[name] = nil
    if not self._key_down_at[name] then
      self._key_down_at[name] = self.total_cycles
    end
    return self.keypad:set_key(name, true)
  end

  local down_at = self._key_down_at[name]
  if not down_at then
    return self.keypad:set_key(name, false)
  end

  local hold = self.min_key_hold_cycles
  if name == "on" then
    hold = self.min_on_hold_cycles or hold
  end
  local release_at = down_at + hold
  if self.total_cycles >= release_at then
    self._key_down_at[name] = nil
    self._key_release_at[name] = nil
    return self.keypad:set_key(name, false)
  end

  -- Defer release until the key has been down long enough for TI-OS to see it.
  self._key_release_at[name] = release_at
  return true
end

function Machine:set_key_matrix(group, bitn, down)
  self.keypad:set_key_matrix(group, bitn, down)
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

--- Execute one Z80 instruction (and tick ASIC by its cycle cost).
--- Respects HALT: burns 4 T-states until an interrupt wakes the CPU.
function Machine:step_instruction()
  if not self.rom_loaded then
    return 0
  end
  local cyc = self.cpu:step()
  self.asic:tick(cyc)
  self.total_cycles = self.total_cycles + cyc
  self.lcd._dirty = true
  self:_release_due_keys()
  return cyc
end

function Machine:cycles_per_frame(fps)
  fps = fps or 60
  return math.floor(CPU_HZ / fps)
end

return Machine
