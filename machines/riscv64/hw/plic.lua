-- PLIC stub — external interrupt controller placeholder.
-- Enough MMIO so DTB/probe does not fault; no real IRQ routing yet.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Plic = {}
Plic.__index = Plic
Plic.BASE = 0x0C000000
Plic.SIZE = 0x4000000 -- 64 MiB window (standard PLIC span)

function Plic.new()
  return setmetatable({ regs = {}, source_pending = 0 }, Plic)
end

function Plic:reset()
  self.regs = {}
  self.source_pending = 0
end

function Plic:read8(offset)
  local word = math.floor(offset / 4)
  local shift = (offset % 4) * 8
  local v = self.regs[word] or 0
  return band(rshift(v, shift), 0xFF)
end

function Plic:write8(offset, value)
  local word = math.floor(offset / 4)
  local shift = (offset % 4) * 8
  local mask = bxor(0xFFFFFFFF, lshift(0xFF, shift))
  local cur = self.regs[word] or 0
  self.regs[word] = bor(band(cur, mask), lshift(band(value, 0xFF), shift))
end

function Plic:set_pending(source, pending)
  source = band(source or 0, 0x3FF)
  if source == 0 then return end
  local bitn = (source - 1) % 32
  if pending then
    self.source_pending = bor(self.source_pending, lshift(1, bitn))
  else
    self.source_pending = band(self.source_pending, bxor(0xFFFFFFFF, lshift(1, bitn)))
  end
end

return Plic
