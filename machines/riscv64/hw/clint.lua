-- CLINT-shaped timer (our addresses, virt-compatible offsets).
--
-- Why a timer: Linux needs periodic interrupts. Software writes mtimecmp;
-- hardware raises mip.MTIP when mtime >= mtimecmp. SBI later converts that
-- into a supervisor timer interrupt for the kernel.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local U64 = require("cpus.riscv.u64")

local Clint = {}
Clint.__index = Clint
Clint.BASE = 0x02000000
Clint.SIZE = 0x10000 -- exported for bus:map
Clint.MSIP = 0x0000
Clint.MTIMECMP = 0x4000
Clint.MTIME = 0xBFF8

function Clint.new()
  local self = setmetatable({}, Clint)
  self.msip = 0
  self.mtime = U64.zero()
  self.mtimecmp = U64.new(0xFFFFFFFF, 0xFFFFFFFF) -- no interrupt until programmed
  return self
end

function Clint:reset()
  self.msip = 0
  self.mtime = U64.zero()
  self.mtimecmp = U64.new(0xFFFFFFFF, 0xFFFFFFFF)
end

function Clint:advance(cycles)
  cycles = math.floor(tonumber(cycles) or 0)
  if cycles <= 0 then return end
  -- Mutate in place — avoid alloc every timer sync (was a hot-path tax).
  U64.iadd_uint(self.mtime, cycles)
end

function Clint:timer_pending()
  return not U64.ult(self.mtime, self.mtimecmp)
end

local function write_u64_le(target, offset, byte)
  -- Merge one byte into a u64 at byte offset 0..7
  byte = band(byte, 0xFF)
  local shift = offset * 8
  if shift < 32 then
    local mask = bxor(0xFFFFFFFF, lshift(0xFF, shift))
    local lo = bor(band(target.lo, mask), lshift(byte, shift))
    return U64.new(target.hi, lo)
  end
  shift = shift - 32
  local mask = bxor(0xFFFFFFFF, lshift(0xFF, shift))
  local hi = bor(band(target.hi, mask), lshift(byte, shift))
  return U64.new(hi, target.lo)
end

local function read_u64_byte(v, offset)
  if offset < 4 then
    return band(rshift(v.lo, offset * 8), 0xFF)
  end
  return band(rshift(v.hi, (offset - 4) * 8), 0xFF)
end

function Clint:read8(offset)
  offset = band(offset, 0xFFFF)
  if offset == Clint.MSIP then
    return band(self.msip, 1)
  end
  if offset >= Clint.MTIMECMP and offset < Clint.MTIMECMP + 8 then
    return read_u64_byte(self.mtimecmp, offset - Clint.MTIMECMP)
  end
  if offset >= Clint.MTIME and offset < Clint.MTIME + 8 then
    return read_u64_byte(self.mtime, offset - Clint.MTIME)
  end
  return 0
end

function Clint:write8(offset, value)
  offset = band(offset, 0xFFFF)
  value = band(value, 0xFF)
  if offset == Clint.MSIP then
    self.msip = band(value, 1)
    return
  end
  if offset >= Clint.MTIMECMP and offset < Clint.MTIMECMP + 8 then
    self.mtimecmp = write_u64_le(self.mtimecmp, offset - Clint.MTIMECMP, value)
    return
  end
  if offset >= Clint.MTIME and offset < Clint.MTIME + 8 then
    self.mtime = write_u64_le(self.mtime, offset - Clint.MTIME, value)
  end
end

return Clint
