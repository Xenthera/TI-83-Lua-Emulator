-- Game Boy joypad (P1 @ FF00).

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Joypad = {}
Joypad.__index = Joypad

local BUTTONS = {
  right = 0, left = 1, up = 2, down = 3,
  a = 4, b = 5, select = 6, start = 7,
}

function Joypad.new(irq)
  return setmetatable({
    irq = irq,
    select = 0x30,
    buttons = 0xFF,
  }, Joypad)
end

function Joypad:reset()
  self.select = 0x30
  self.buttons = 0xFF
end

function Joypad:set_key(name, down)
  local bitn = BUTTONS[name]
  if bitn == nil then return false end
  local mask = lshift(1, bitn)
  local prev = self.buttons
  if down then
    self.buttons = band(self.buttons, bxor(0xFF, mask))
  else
    self.buttons = bor(self.buttons, mask)
  end
  if down and band(prev, mask) ~= 0 then
    self.irq:request(0x10)
  end
  return true
end

function Joypad:read()
  local v = bor(0xC0, band(self.select, 0x30))
  local low = 0x0F
  if band(self.select, 0x10) == 0 then
    low = band(low, band(self.buttons, 0x0F))
  end
  if band(self.select, 0x20) == 0 then
    low = band(low, band(rshift(self.buttons, 4), 0x0F))
  end
  return bor(v, low)
end

function Joypad:write(v)
  self.select = band(v, 0x30)
end

return Joypad
