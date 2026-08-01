-- Game Boy interrupt flag / enable (IF @ FF0F, IE @ FFFF).

local bit = require("framework.util.bit")
local band, bor = bit.band, bit.bor

local Irq = {}
Irq.__index = Irq

Irq.VBLANK = 0x01
Irq.STAT = 0x02
Irq.TIMER = 0x04
Irq.SERIAL = 0x08
Irq.JOYPAD = 0x10

function Irq.new()
  return setmetatable({ iff = 0xE1, ie = 0x00 }, Irq)
end

function Irq:reset()
  self.iff = 0xE1
  self.ie = 0x00
end

function Irq:request(mask)
  self.iff = bor(self.iff, band(mask, 0x1F))
end

function Irq:read_if()
  return bor(self.iff, 0xE0)
end

function Irq:write_if(v)
  self.iff = band(v, 0x1F)
end

function Irq:read_ie()
  return self.ie
end

function Irq:write_ie(v)
  self.ie = band(v, 0x1F)
end

function Irq:pending()
  return band(self.ie, self.iff, 0x1F)
end

return Irq
