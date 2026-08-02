-- NES controller strobe / shift register (controller 1 + 2).

local bit = require("framework.util.bit")
local band, bor, bxor, rshift, lshift = bit.band, bit.bor, bit.bxor, bit.rshift, bit.lshift

local Joypad = {}
Joypad.__index = Joypad

-- Bit order: A B Select Start Up Down Left Right
local KEY_BITS = {
  a = 0, b = 1, select = 2, start = 3,
  up = 4, down = 5, left = 6, right = 7,
}

function Joypad.new()
  return setmetatable({
    state = { [1] = 0, [2] = 0 },
    shift = { [1] = 0, [2] = 0 },
    strobe = false,
  }, Joypad)
end

function Joypad:reset()
  self.state[1], self.state[2] = 0, 0
  self.shift[1], self.shift[2] = 0, 0
  self.strobe = false
end

function Joypad:set_key(name, down, pad)
  pad = pad or 1
  local bitn = KEY_BITS[name]
  if bitn == nil then return false end
  local mask = lshift(1, bitn)
  if down then
    self.state[pad] = bor(self.state[pad], mask)
  else
    self.state[pad] = band(self.state[pad], bxor(0xFF, mask))
  end
  if self.strobe then
    self.shift[pad] = self.state[pad]
  end
  return true
end

function Joypad:write(v)
  self.strobe = band(v, 1) ~= 0
  if self.strobe then
    self.shift[1] = self.state[1]
    self.shift[2] = self.state[2]
  end
end

function Joypad:read(pad)
  pad = pad or 1
  local s = self.shift[pad] or 0
  local bitv = band(s, 1)
  if not self.strobe then
    self.shift[pad] = bor(rshift(s, 1), 0x80) -- open bus high bits after 8 reads
  end
  return bor(bitv, 0x40) -- bit 6 often high on NES
end

return Joypad
