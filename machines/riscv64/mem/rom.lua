-- Firmware / OpenSBI image window (byte array, read-mostly).

local bit = require("framework.util.bit")
local band = bit.band

local Rom = {}
Rom.__index = Rom

function Rom.new(size)
  local self = setmetatable({}, Rom)
  self.size = size or 0
  self.data = {}
  self.blob = nil -- string path: faster byte() than sparse table
  return self
end

function Rom:set_bytes(bytes)
  self.data = {}
  self.blob = nil
  if type(bytes) == "string" then
    self.blob = bytes
    self.size = #bytes
  elseif type(bytes) == "table" then
    local n = 0
    for k, v in pairs(bytes) do
      if type(k) == "number" then
        self.data[k] = band(v, 0xFF)
        if k + 1 > n then n = k + 1 end
      end
    end
    self.size = n
  else
    self.size = 0
  end
end

function Rom:reset()
  -- Contents persist across CPU reset (like flash); clear only on new load.
end

function Rom:read8(offset)
  if offset < 0 or offset >= self.size then
    return 0
  end
  local blob = self.blob
  if blob then
    return blob:byte(offset + 1) or 0
  end
  return self.data[offset] or 0
end

function Rom:read32(offset)
  if offset < 0 or offset + 3 >= self.size then
    return 0
  end
  local blob = self.blob
  if blob then
    local b0, b1, b2, b3 = blob:byte(offset + 1, offset + 4)
    return (b0 or 0) + (b1 or 0) * 256 + (b2 or 0) * 65536 + (b3 or 0) * 16777216
  end
  local d = self.data
  return (d[offset] or 0)
    + (d[offset + 1] or 0) * 256
    + (d[offset + 2] or 0) * 65536
    + (d[offset + 3] or 0) * 16777216
end

function Rom:write8(_offset, _value)
  -- ROM: ignore writes
end

return Rom
