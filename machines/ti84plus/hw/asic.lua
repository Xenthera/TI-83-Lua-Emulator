-- TI-84 Plus ASIC: SE-class paging, CPU speed, crystal timers, RTC, USB stubs.

local bit = require("framework.util.bit")
local band, bor, bnot, rshift, lshift = bit.band, bit.bor, bit.bnot, bit.rshift, bit.lshift
local Crystal = require("machines.ti84plus.hw.crystal")

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
  self.on_cpu_hz = opts.on_cpu_hz
  self.crystal = Crystal.new()

  self.int_mask = 0
  self.int_status = 0
  self.port04 = 0
  self.link_out = 0
  self.flash_port = 0
  self.ram_page_port = 0
  self.cpu_speed = 0 -- port 20: 0=6MHz, 1+=15MHz
  self.port21 = 0x00 -- 1MB flash, 32K RAM (TI-84+ BE)
  self._on_prev = false

  -- RTC (ports 40–48)
  self.rtc_ctrl = 0
  self.rtc_set = { 0, 0, 0, 0 } -- 41–44
  self.rtc_cur = { 0, 0, 0, 0 } -- 45–48
  self._rtc_cycle_acc = 0
  self._usb = {} -- stub latches
  return self
end

function Asic:reset()
  self.int_mask = 0
  self.int_status = 0
  self.port04 = 0
  self.link_out = 0
  self.flash_port = 0
  self.ram_page_port = 0
  self.cpu_speed = 0
  self.port21 = 0x00
  self._on_prev = false
  self.rtc_ctrl = 0
  self.rtc_set = { 0, 0, 0, 0 }
  self.rtc_cur = { 0, 0, 0, 0 }
  self._rtc_cycle_acc = 0
  self._usb = {}
  self.crystal:reset()
  self.mmu:reset()
  self.lcd:reset()
  self.keypad:reset()
  self.timer:reset()
  if self.on_cpu_hz then
    self.on_cpu_hz(6000000)
  end
end

function Asic:effective_cpu_hz()
  return (band(self.cpu_speed, 0x03) == 0) and 6000000 or 15000000
end

function Asic:link_lines()
  local out = band(self.link_out, 0x03)
  local tip = band(out, 0x01) == 0 and 0x01 or 0
  local ring = band(out, 0x02) == 0 and 0x02 or 0
  return bor(tip + ring, lshift(out, 4))
end

local function rtc_seconds(bytes)
  return bytes[1]
    + bytes[2] * 256
    + bytes[3] * 65536
    + bytes[4] * 16777216
end

local function rtc_write_seconds(bytes, secs)
  secs = secs % 4294967296
  bytes[1] = secs % 256
  bytes[2] = math.floor(secs / 256) % 256
  bytes[3] = math.floor(secs / 65536) % 256
  bytes[4] = math.floor(secs / 16777216) % 256
end

function Asic:tick(cycles)
  local lcd = self.lcd
  if lcd.busy_cycles > 0 then
    lcd:tick(cycles)
  end
  self.timer:tick(cycles)
  local hz = self:effective_cpu_hz()
  self.crystal:tick(cycles, hz)

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

  local keypad = self.keypad
  if keypad.input_dirty then
    keypad.input_dirty = false
    local on_now = keypad:is_on_pressed()
    if on_now and not self._on_prev then
      self.int_status = bor(self.int_status, 0x01)
    end
    self._on_prev = on_now
  end

  -- RTC advances in wall seconds while enabled (bit0 of port 40).
  if band(self.rtc_ctrl, 0x01) ~= 0 then
    self._rtc_cycle_acc = self._rtc_cycle_acc + cycles
    if self._rtc_cycle_acc >= hz then
      local add = math.floor(self._rtc_cycle_acc / hz)
      self._rtc_cycle_acc = self._rtc_cycle_acc % hz
      rtc_write_seconds(self.rtc_cur, rtc_seconds(self.rtc_cur) + add)
    end
  end
end

function Asic:irq_line()
  if band(self.int_status, self.int_mask) ~= 0 then
    return true
  end
  return self.crystal:irq_pending()
end

function Asic:ack_interrupt()
end

function Asic:in_port(port)
  port = band(port, 0xFF)
  if port == 0x00 then
    return band(self:link_lines(), 0xFF)
  elseif port == 0x01 then
    return self.keypad:read()
  elseif port == 0x02 then
    -- 84+: bit0 batt, bit1 LCD ready, bit2 flash unlock,
    -- bit5 USB-capable, bit6 link assist, bit7 SE-class ASIC.
    local s = 0xE1 -- batt + USB + link-assist + SE
    if self.lcd.busy_cycles <= 0 then
      s = bor(s, 0x02)
    end
    if self.mmu.flash_unlocked then
      s = bor(s, 0x04)
    end
    return band(s, 0xFF)
  elseif port == 0x03 then
    return band(self.int_mask, 0xFF)
  elseif port == 0x04 then
    local v = band(self.int_status, 0x17) -- ON/timer1/timer2 + link bit4 if set
    v = bor(v, self.crystal:port04_bits())
    if not self.keypad:is_on_pressed() then
      v = bor(v, 0x08)
    end
    self.crystal:consume_pulse04()
    return band(v, 0xFF)
  elseif port == 0x05 then
    return band(self.ram_page_port, 0xFF)
  elseif port == 0x06 then
    local v = self.mmu.page_bankA
    if self.mmu.bankA_is_ram then
      v = bor(v, 0x80)
    end
    return band(v, 0xFF)
  elseif port == 0x07 then
    local v = self.mmu.page_bankB
    if self.mmu.bankB_is_ram then
      v = bor(v, 0x80)
    end
    return band(v, 0xFF)
  elseif port == 0x10 then
    return self.lcd:status()
  elseif port == 0x11 then
    return self.lcd:data_read()
  elseif port == 0x14 then
    return band(self.flash_port, 0xFF)
  elseif port == 0x20 then
    return band(self.cpu_speed, 0x03)
  elseif port == 0x21 then
    return band(self.port21, 0xFF)
  elseif port == 0x40 then
    return band(self.rtc_ctrl, 0x03)
  elseif port >= 0x41 and port <= 0x44 then
    return self.rtc_set[port - 0x40]
  elseif port >= 0x45 and port <= 0x48 then
    return self.rtc_cur[port - 0x44]
  elseif port >= 0x4C and port <= 0x57 then
    -- USB idle defaults (WikiTI / 84+ OS IM1 dispatcher).
    -- Port 55 MUST read $1F when quiet — any low bit in 0..4 makes the ISR
    -- take the USB path and skip keypad scanning.
    if self._usb[port] ~= nil then
      return self._usb[port]
    end
    if port == 0x4C then
      return 0x22
    elseif port == 0x4D then
      return 0xA0 -- ID high, Vbus low (unplugged)
    elseif port == 0x55 then
      return 0x1F -- no USB interrupt sources
    elseif port == 0x56 then
      return 0x00 -- no line events
    end
    return 0x00
  elseif port == 0x30 then
    return self.crystal:read_freq(1)
  elseif port == 0x31 then
    return self.crystal:read_loop(1)
  elseif port == 0x32 then
    return self.crystal:read_counter(1)
  elseif port == 0x33 then
    return self.crystal:read_freq(2)
  elseif port == 0x34 then
    return self.crystal:read_loop(2)
  elseif port == 0x35 then
    return self.crystal:read_counter(2)
  elseif port == 0x36 then
    return self.crystal:read_freq(3)
  elseif port == 0x37 then
    return self.crystal:read_loop(3)
  elseif port == 0x38 then
    return self.crystal:read_counter(3)
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
  elseif port == 0x02 then
    -- SE/84+: ACK interrupt sources by clearing enable bits style.
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
  elseif port == 0x03 then
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
    self.mmu:set_mem_mode(band(value, 0x01))
    self.timer:set_speed(band(rshift(value, 1), 0x03))
  elseif port == 0x05 then
    self.ram_page_port = value
    self.mmu:set_ram_page(value)
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
    if not unlocked and self.mmu.flash.reset_cmd then
      self.mmu.flash:reset_cmd()
    end
  elseif port == 0x20 then
    self.cpu_speed = band(value, 0x03)
    local hz = self:effective_cpu_hz()
    self.timer:set_cpu_hz(hz)
    self.crystal:on_cpu_hz(hz)
    if self.on_cpu_hz then
      self.on_cpu_hz(hz)
    end
  elseif port == 0x21 then
    -- Protected on real hw; allow for dumps/tests.
    self.port21 = bor(band(value, 0x33), band(self.port21, 0xCC))
  elseif port == 0x30 then
    self.crystal:set_freq(1, value, self:effective_cpu_hz())
  elseif port == 0x31 then
    self.crystal:set_loop(1, value)
  elseif port == 0x32 then
    self.crystal:set_counter(1, value, self:effective_cpu_hz())
  elseif port == 0x33 then
    self.crystal:set_freq(2, value, self:effective_cpu_hz())
  elseif port == 0x34 then
    self.crystal:set_loop(2, value)
  elseif port == 0x35 then
    self.crystal:set_counter(2, value, self:effective_cpu_hz())
  elseif port == 0x36 then
    self.crystal:set_freq(3, value, self:effective_cpu_hz())
  elseif port == 0x37 then
    self.crystal:set_loop(3, value)
  elseif port == 0x38 then
    self.crystal:set_counter(3, value, self:effective_cpu_hz())
  elseif port == 0x40 then
    local prev = self.rtc_ctrl
    self.rtc_ctrl = band(value, 0x03)
    -- Rising edge on bit1 copies set → current.
    if band(prev, 0x02) == 0 and band(self.rtc_ctrl, 0x02) ~= 0 then
      for i = 1, 4 do
        self.rtc_cur[i] = self.rtc_set[i]
      end
    end
  elseif port >= 0x41 and port <= 0x44 then
    self.rtc_set[port - 0x40] = value
  elseif port >= 0x45 and port <= 0x48 then
    self.rtc_cur[port - 0x44] = value
  elseif port >= 0x4C and port <= 0x57 then
    self._usb[port] = value
  end
end

return Asic
