-- TI-89 RAM (256KB classic).

local SIZE = 256 * 1024

local Ram = {}
Ram.__index = Ram
Ram.SIZE = SIZE

function Ram.new()
  local self = setmetatable({}, Ram)
  self.bytes = {}
  -- Power-on SRAM reads as $FF; AMS boot checks ($400).W == $FFFF.
  for i = 0, SIZE - 1 do self.bytes[i] = 0xFF end
  return self
end

function Ram:clear()
  for i = 0, SIZE - 1 do self.bytes[i] = 0xFF end
end

function Ram:read8(addr)
  return self.bytes[addr % SIZE] or 0
end

function Ram:write8(addr, v)
  self.bytes[addr % SIZE] = v % 256
end

return Ram
