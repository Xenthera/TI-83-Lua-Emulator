-- NS16550-compatible UART (enough for Linux earlycon / 8250 driver).
-- TX still appends to the console ring for the Love LCD.
--
-- Register map (byte offsets):
--   0 RBR/THR (/DLL if DLAB)   1 IER (/DLM)   2 IIR/FCR   3 LCR
--   4 MCR   5 LSR   6 MSR   7 SCR

local bit = require("framework.util.bit")
local band, bor = bit.band, bit.bor

local Uart = {}
Uart.__index = Uart
Uart.BASE = 0x10000000
Uart.SIZE = 0x100

-- Legacy aliases used by older tests
Uart.REG_DATA = 0
Uart.REG_STATUS = 5 -- LSR

local LSR_DR = 0x01  -- data ready
local LSR_THRE = 0x20 -- thr empty
local LSR_TEMT = 0x40 -- transmitter empty

function Uart.new(opts)
  opts = opts or {}
  local self = setmetatable({}, Uart)
  self.ring = {}
  self.max = opts.max or 8192
  self.rx = {}
  self.ier = 0
  self.iir = 0x01 -- no interrupt pending
  self.lcr = 0
  self.mcr = 0
  self.msr = 0
  self.scr = 0
  self.dll = 1
  self.dlm = 0
  return self
end

function Uart:reset()
  self.ring = {}
  self.rx = {}
  self.ier = 0
  self.iir = 0x01
  self.lcr = 0
  self.mcr = 0
  self.msr = 0
  self.scr = 0
  self.dll = 1
  self.dlm = 0
end

function Uart:tx(byte)
  byte = band(byte, 0xFF)
  self.ring[#self.ring + 1] = byte
  if #self.ring > self.max then
    table.remove(self.ring, 1)
  end
end

function Uart:push_rx(byte)
  self.rx[#self.rx + 1] = band(byte, 0xFF)
end

function Uart:lsr()
  local st = bor(LSR_THRE, LSR_TEMT)
  if #self.rx > 0 then
    st = bor(st, LSR_DR)
  end
  return st
end

function Uart:read8(offset)
  offset = band(offset, 0xFF)
  local dlab = band(self.lcr, 0x80) ~= 0
  if offset == 0 then
    if dlab then return self.dll end
    if #self.rx > 0 then
      return table.remove(self.rx, 1)
    end
    return 0
  elseif offset == 1 then
    if dlab then return self.dlm end
    return self.ier
  elseif offset == 2 then
    return self.iir
  elseif offset == 3 then
    return self.lcr
  elseif offset == 4 then
    return self.mcr
  elseif offset == 5 then
    return self:lsr()
  elseif offset == 6 then
    return self.msr
  elseif offset == 7 then
    return self.scr
  end
  return 0
end

function Uart:write8(offset, value)
  offset = band(offset, 0xFF)
  value = band(value, 0xFF)
  local dlab = band(self.lcr, 0x80) ~= 0
  if offset == 0 then
    if dlab then
      self.dll = value
    else
      self:tx(value)
    end
  elseif offset == 1 then
    if dlab then
      self.dlm = value
    else
      self.ier = value
    end
  elseif offset == 2 then
    -- FCR ignored
  elseif offset == 3 then
    self.lcr = value
  elseif offset == 4 then
    self.mcr = value
  elseif offset == 7 then
    self.scr = value
  end
end

function Uart:text()
  local parts = {}
  for i = 1, #self.ring do
    parts[i] = string.char(self.ring[i])
  end
  return table.concat(parts)
end

return Uart
