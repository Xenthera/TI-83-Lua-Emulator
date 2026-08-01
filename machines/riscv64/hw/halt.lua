-- Test / syscon-style halt latch (write nonzero → stop hart).

local bit = require("framework.util.bit")
local band = bit.band

local Halt = {}
Halt.__index = Halt

function Halt.new(bus)
  local self = setmetatable({ bus = bus, value = 0 }, Halt)
  return self
end

function Halt:reset()
  self.value = 0
  if self.bus then self.bus.halted = false end
end

function Halt:read8(_offset)
  return self.bus and self.bus.halted and 1 or self.value
end

function Halt:write8(_offset, value)
  value = band(value, 0xFF)
  self.value = value
  if value ~= 0 and self.bus then
    self.bus.halted = true
  end
end

return Halt
