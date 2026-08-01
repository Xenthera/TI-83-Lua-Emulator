-- TI-83 Plus ASIC: port decode for keypad, LCD, paging, interrupts.

local bit = require("framework.util.bit")
local band, bor, bnot, rshift, lshift = bit.band, bit.bor, bit.bnot, bit.rshift, bit.lshift

local function bnot_u8(v)
  return band(bnot(v), 0xFF)
end

local Asic = {}
Asic.__index = Asic

function Asic.new(opts)
  local self = setmetatable({}, Asic)
  self.mmu = opts.mmu
  self.lcd = opts.lcd
  self.keypad = opts.keypad
  self.timer = opts.timer

  self.int_mask = 0
  self.int_status = 0
  self.port04 = 0
  -- Port 0 write latch: bit set = pull that line low (idle write = 0).
  self.link_out = 0
  self.flash_port = 0
  self.ram_page_port = 0
  self._on_prev = false
  return self
end

function Asic:reset()
  self.int_mask = 0
  self.int_status = 0
  self.port04 = 0
  self.link_out = 0
  self.flash_port = 0
  self.ram_page_port = 0
  self._on_prev = false
  self.mmu:reset()
  self.lcd:reset()
  self.keypad:reset()
  self.timer:reset()
end

--- Link port lines (no peer): high unless this calc is pulling them low.
function Asic:link_lines()
  local out = band(self.link_out, 0x03)
  local tip = band(out, 0x01) == 0 and 0x01 or 0
  local ring = band(out, 0x02) == 0 and 0x02 or 0
  -- Bits 4-5 mirror which lines we are holding low.
  return bor(tip + ring, lshift(out, 4))
end

function Asic:tick(cycles)
  local lcd = self.lcd
  if lcd.busy_cycles > 0 then
    lcd:tick(cycles)
  end
  self.timer:tick(cycles)
  -- Port 04 bit1 = first timer, bit2 = second timer (WikiTI).
  -- Only latch sources that are enabled; a disabled timer2 pending bit
  -- made the ISR take the wrong branch (BIT 2) and break cursor blink.
  local timer = self.timer
  if timer.pending1 then
    if band(self.int_mask, 0x02) ~= 0 then
      self.int_status = bor(self.int_status, 0x02)
    else
      timer:ack1()
    end
  end
  if timer.pending2 then
    if band(self.int_mask, 0x04) ~= 0 then
      self.int_status = bor(self.int_status, 0x04)
    else
      timer:ack2()
    end
  end
  -- ON key interrupt is edge-triggered; only recheck when keypad changes.
  local keypad = self.keypad
  if keypad.input_dirty then
    keypad.input_dirty = false
    local on_now = keypad:is_on_pressed()
    if on_now and not self._on_prev then
      self.int_status = bor(self.int_status, 0x01)
    end
    self._on_prev = on_now
  end
end

function Asic:irq_line()
  return band(self.int_status, self.int_mask) ~= 0
end

function Asic:ack_interrupt()
  -- TI keeps interrupt sources latched until acked via port 03.
  -- Clearing here (Z80 INT accept) made the ISR's IN A,(4) miss the timer
  -- bit, so keyscan never ran. ON still worked because it was never
  -- auto-cleared on accept.
end

function Asic:in_port(port)
  port = band(port, 0xFF)
  if port == 0x00 then
    return band(self:link_lines(), 0xFF)
  elseif port == 0x01 then
    return self.keypad:read()
  elseif port == 0x02 then
    -- TI-83+ Basic: bit0 battery, bit1 LCD ready, bit2 flash unlock,
    -- bits3-5 mirror port 05 bits0-2, bit7 clear (not SE/84+).
    local s = 0x01
    if self.lcd.busy_cycles <= 0 then
      s = bor(s, 0x02)
    end
    if self.mmu.flash_unlocked then
      s = bor(s, 0x04)
    end
    s = bor(s, lshift(band(self.ram_page_port, 0x07), 3))
    return band(s, 0xFF)
  elseif port == 0x03 then
    return band(self.int_mask, 0xFF)
  elseif port == 0x04 then
    -- Read: interrupt source bits (write value's map mode is not readable)
    local v = band(self.int_status, 0x07)
    if not self.keypad:is_on_pressed() then
      v = bor(v, 0x08)
    end
    return band(v, 0xFF)
  elseif port == 0x05 then
    return band(self.ram_page_port, 0xFF)
  elseif port == 0x06 then
    local v = self.mmu.page_bankA
    if self.mmu.bankA_is_ram then
      v = bor(v, 0x40)
    end
    return band(v, 0xFF)
  elseif port == 0x07 then
    local v = self.mmu.page_bankB
    if self.mmu.bankB_is_ram then
      v = bor(v, 0x40)
    end
    return band(v, 0xFF)
  elseif port == 0x10 then
    return self.lcd:status()
  elseif port == 0x11 then
    return self.lcd:data_read()
  elseif port == 0x14 then
    return band(self.flash_port, 0xFF)
  end
  return 0x00
end

function Asic:out_port(port, value)
  port = band(port, 0xFF)
  value = band(value, 0xFF)

  if port == 0x00 then
    self.link_out = band(value, 0x03)
  elseif port == 0x01 then
    self.keypad:write_group(value)
  elseif port == 0x03 then
    -- Writing 0 to an enable bit acknowledges / disables that interrupt source.
    self.int_mask = value
    if band(value, 0x01) == 0 then
      self.int_status = band(self.int_status, bnot_u8(0x01))
    end
    if band(value, 0x02) == 0 then
      self.timer:ack1()
      self.int_status = band(self.int_status, bnot_u8(0x02))
    end
    if band(value, 0x04) == 0 then
      self.timer:ack2()
      self.int_status = band(self.int_status, bnot_u8(0x04))
    end
  elseif port == 0x04 then
    self.port04 = value
    -- Bit 0: memory map mode. Bits 1-2: hardware timer speed.
    self.mmu:set_mem_mode(band(value, 0x01))
    self.timer:set_speed(band(rshift(value, 1), 0x03))
  elseif port == 0x05 then
    self.ram_page_port = value
  elseif port == 0x06 then
    self.mmu:set_bankA(value)
  elseif port == 0x07 then
    self.mmu:set_bankB(value)
  elseif port == 0x10 then
    self.lcd:command(value)
  elseif port == 0x11 then
    self.lcd:data_write(value)
  elseif port == 0x14 then
    self.flash_port = value
    local unlocked = band(value, 0x01) ~= 0
    self.mmu.flash_unlocked = unlocked
    -- Locking aborts any in-progress AMD command sequence.
    if not unlocked and self.mmu.flash.reset_cmd then
      self.mmu.flash:reset_cmd()
    end
  end
end

return Asic
