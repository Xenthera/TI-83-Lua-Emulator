-- Unsigned/signed 64-bit helpers for RV64.
--
-- On LuaJIT/Love: union { uint64_t u; lo/hi } so arithmetic is native 64-bit
-- (same idea as the 68k core's plain numbers). On PUC Lua: hi/lo software carry.

local bit = require("framework.util.bit")
local band, bor, bxor, bnot, lshift, rshift =
  bit.band, bit.bor, bit.bxor, bit.bnot, bit.lshift, bit.rshift

local U32 = 0xFFFFFFFF
local U64 = {}

local function u32(v)
  return band(v or 0, U32)
end

local HAS_U64 = false
local ctype
local mk
local assign_u

do
  local ok, ffi = pcall(require, "ffi")
  if ok and ffi and ffi.typeof then
    pcall(ffi.cdef, [[
      typedef union rv_u64 {
        uint64_t u;
        struct { uint32_t lo; uint32_t hi; };
      } rv_u64;
    ]])
    local ok_t, t = pcall(ffi.typeof, "rv_u64")
    if ok_t and t then
      ctype = t
      HAS_U64 = true
      mk = function(hi, lo)
        local r = ctype()
        r.lo = u32(lo)
        r.hi = u32(hi)
        return r
      end
      assign_u = function(dst, src)
        dst.u = src.u
        return dst
      end
    end
  end
  if not HAS_U64 then
    mk = function(hi, lo)
      return { hi = u32(hi), lo = u32(lo) }
    end
    assign_u = function(dst, src)
      dst.hi = src.hi
      dst.lo = src.lo
      return dst
    end
  end
end

U64.HAS_NATIVE = HAS_U64
U64._ctype = ctype

function U64.new(hi, lo)
  return mk(hi, lo)
end

function U64.zero()
  return mk(0, 0)
end

function U64.clone(a)
  return mk(a.hi, a.lo)
end

function U64.assign(dst, src)
  return assign_u(dst, src)
end

function U64.from_u32(lo)
  return mk(0, lo)
end

function U64.from_i32(v)
  v = u32(v)
  local hi = (band(v, 0x80000000) ~= 0) and U32 or 0
  return mk(hi, v)
end

U64.ZERO = U64.zero()
U64.ONE = U64.from_u32(1)
U64.TWO = U64.from_u32(2)
U64.THREE = U64.from_u32(3)
U64.FOUR = U64.from_u32(4)
U64.ALIGN_MASK = U64.new(0xFFFFFFFF, 0xFFFFFFFE)

function U64.from_number(n)
  n = n or 0
  if n >= 0 then
    return mk(u32(math.floor(n / 4294967296)), u32(n))
  end
  return U64.neg(U64.from_number(-n))
end

function U64.eq(a, b)
  if HAS_U64 then return a.u == b.u end
  return a.hi == b.hi and a.lo == b.lo
end

function U64.is_zero(a)
  if HAS_U64 then return a.u == 0 end
  return a.hi == 0 and a.lo == 0
end

function U64.slt(a, b)
  local sa = band(a.hi, 0x80000000) ~= 0
  local sb = band(b.hi, 0x80000000) ~= 0
  if sa ~= sb then return sa end
  return U64.ult(a, b)
end

function U64.ult(a, b)
  if HAS_U64 then return a.u < b.u end
  if a.hi ~= b.hi then return a.hi < b.hi end
  return a.lo < b.lo
end

function U64.add(a, b)
  if HAS_U64 then
    local r = ctype()
    r.u = a.u + b.u
    return r
  end
  local lo = a.lo + b.lo
  local carry = 0
  if lo > U32 then
    carry = 1
    lo = lo - 4294967296
  end
  local hi = a.hi + b.hi + carry
  if hi > U32 then hi = hi - 4294967296 end
  return mk(hi, lo)
end

function U64.add_into(dst, a, b)
  if HAS_U64 then
    dst.u = a.u + b.u
    return dst
  end
  local lo = a.lo + b.lo
  local carry = 0
  if lo > U32 then
    carry = 1
    lo = lo - 4294967296
  end
  local hi = a.hi + b.hi + carry
  if hi > U32 then hi = hi - 4294967296 end
  dst.hi = u32(hi)
  dst.lo = u32(lo)
  return dst
end

function U64.iadd_uint(a, n)
  n = math.floor(tonumber(n) or 0)
  if n == 0 then return a end
  if HAS_U64 then
    a.u = a.u + n
    return a
  end
  local lo = a.lo + n
  local carry = math.floor(lo / 4294967296)
  a.lo = u32(lo)
  if carry ~= 0 then a.hi = u32(a.hi + carry) end
  return a
end

function U64.sub(a, b)
  if HAS_U64 then
    local r = ctype()
    r.u = a.u - b.u
    return r
  end
  return U64.add(a, U64.neg(b))
end

function U64.neg(a)
  if HAS_U64 then
    local r = ctype()
    r.u = -a.u
    return r
  end
  return U64.add(mk(bnot(a.hi), bnot(a.lo)), U64.ONE)
end

function U64.band(a, b)
  return mk(band(a.hi, b.hi), band(a.lo, b.lo))
end

function U64.bor(a, b)
  return mk(bor(a.hi, b.hi), bor(a.lo, b.lo))
end

function U64.bxor(a, b)
  return mk(bxor(a.hi, b.hi), bxor(a.lo, b.lo))
end

function U64.bnot(a)
  return mk(bnot(a.hi), bnot(a.lo))
end

function U64.sll(a, shamt)
  shamt = band(shamt or 0, 63)
  if shamt == 0 then return U64.clone(a) end
  -- Limb shifts (portable; avoids LuaJIT-only 0ULL literals in this file).
  if shamt >= 32 then
    return mk(lshift(a.lo, shamt - 32), 0)
  end
  return mk(
    bor(lshift(a.hi, shamt), rshift(a.lo, 32 - shamt)),
    lshift(a.lo, shamt)
  )
end

function U64.srl(a, shamt)
  shamt = band(shamt or 0, 63)
  if shamt == 0 then return U64.clone(a) end
  if shamt >= 32 then
    return mk(0, rshift(a.hi, shamt - 32))
  end
  return mk(
    rshift(a.hi, shamt),
    bor(rshift(a.lo, shamt), lshift(a.hi, 32 - shamt))
  )
end

function U64.sra(a, shamt)
  shamt = band(shamt or 0, 63)
  if shamt == 0 then return U64.clone(a) end
  local sign = band(a.hi, 0x80000000) ~= 0
  if shamt >= 32 then
    if sign then
      local n = a.hi - 4294967296
      return mk(U32, u32(math.floor(n / (2 ^ (shamt - 32)))))
    end
    return mk(0, rshift(a.hi, shamt - 32))
  end
  local lo = bor(rshift(a.lo, shamt), lshift(a.hi, 32 - shamt))
  local hi
  if sign then
    hi = u32(math.floor((a.hi - 4294967296) / (2 ^ shamt)))
  else
    hi = rshift(a.hi, shamt)
  end
  return mk(hi, lo)
end

function U64.as_u32(a)
  return a.lo
end

function U64.sext_w(a)
  return U64.from_i32(a.lo)
end

function U64.to_hex(a)
  return string.format("%08x%08x", a.hi, a.lo)
end

function U64.to_number(a)
  return a.hi * 4294967296 + a.lo
end

local function umul32(x, y)
  x, y = u32(x), u32(y)
  local x0, x1 = band(x, 0xFFFF), rshift(x, 16)
  local y0, y1 = band(y, 0xFFFF), rshift(y, 16)
  local t = x0 * y0
  local w0 = band(t, 0xFFFF)
  local k = rshift(t, 16)
  t = x1 * y0 + k
  local w1 = band(t, 0xFFFF)
  local w2 = rshift(t, 16)
  t = x0 * y1 + w1
  w1 = band(t, 0xFFFF)
  k = rshift(t, 16)
  t = x1 * y1 + w2 + k
  return u32(t), u32(bor(w0, lshift(w1, 16)))
end

function U64.mul_u128(a, b)
  local p00h, p00l = umul32(a.lo, b.lo)
  local p01h, p01l = umul32(a.lo, b.hi)
  local p10h, p10l = umul32(a.hi, b.lo)
  local p11h, p11l = umul32(a.hi, b.hi)
  local r0, r1, r2, r3 = p00l, p00h, 0, 0
  local function add32(idx, v)
    v = u32(v)
    if idx == 0 then
      local s = r0 + v
      r0 = u32(s)
      if s > U32 then add32(1, 1) end
    elseif idx == 1 then
      local s = r1 + v
      r1 = u32(s)
      if s > U32 then add32(2, 1) end
    elseif idx == 2 then
      local s = r2 + v
      r2 = u32(s)
      if s > U32 then add32(3, 1) end
    else
      r3 = u32(r3 + v)
    end
  end
  add32(1, p01l); add32(2, p01h)
  add32(1, p10l); add32(2, p10h)
  add32(2, p11l); add32(3, p11h)
  return mk(r1, r0), mk(r3, r2)
end

function U64.mul(a, b)
  if HAS_U64 then
    local r = ctype()
    r.u = a.u * b.u
    return r
  end
  local lo = U64.mul_u128(a, b)
  return lo
end

local function is_neg(a)
  return band(a.hi, 0x80000000) ~= 0
end

local function neg128(lo, hi)
  local nlo = U64.add(U64.bnot(lo), U64.ONE)
  local nhi = U64.bnot(hi)
  if U64.is_zero(lo) then
    nhi = U64.add(nhi, U64.ONE)
  end
  return nlo, nhi
end

function U64.mulh(a, b)
  local neg = false
  local aa, bb = a, b
  if is_neg(a) then aa = U64.neg(a); neg = not neg end
  if is_neg(b) then bb = U64.neg(b); neg = not neg end
  local lo, hi = U64.mul_u128(aa, bb)
  if neg then _, hi = neg128(lo, hi) end
  return hi
end

function U64.mulhsu(a, b)
  local neg = is_neg(a)
  local aa = neg and U64.neg(a) or a
  local lo, hi = U64.mul_u128(aa, b)
  if neg then _, hi = neg128(lo, hi) end
  return hi
end

function U64.mulhu(a, b)
  local _, hi = U64.mul_u128(a, b)
  return hi
end

function U64.divu(a, b)
  if U64.is_zero(b) then
    return U64.new(U32, U32), U64.clone(a)
  end
  if HAS_U64 then
    local q, r = ctype(), ctype()
    q.u = a.u / b.u
    r.u = a.u % b.u
    return q, r
  end
  local quot = U64.zero()
  local rem = U64.zero()
  for i = 63, 0, -1 do
    rem = U64.sll(rem, 1)
    local bit_i = U64.band(U64.srl(a, i), U64.ONE)
    if bit_i.lo ~= 0 then
      rem = U64.bor(rem, U64.ONE)
    end
    if not U64.ult(rem, b) then
      rem = U64.sub(rem, b)
      quot = U64.bor(quot, U64.sll(U64.ONE, i))
    end
  end
  return quot, rem
end

function U64.divs(a, b)
  local min64 = U64.new(0x80000000, 0)
  local neg1 = U64.new(U32, U32)
  if U64.eq(a, min64) and U64.eq(b, neg1) then
    return min64, U64.zero()
  end
  if U64.is_zero(b) then
    return neg1, U64.clone(a)
  end
  local na, nb = is_neg(a), is_neg(b)
  local aa = na and U64.neg(a) or a
  local bb = nb and U64.neg(b) or b
  local q, r = U64.divu(aa, bb)
  if na ~= nb then q = U64.neg(q) end
  if na then r = U64.neg(r) end
  return q, r
end

function U64.read_le(get8, addr)
  local function b(i)
    return band(get8(addr + i) or 0, 0xFF)
  end
  local lo = bor(bor(b(0), lshift(b(1), 8)), bor(lshift(b(2), 16), lshift(b(3), 24)))
  local hi = bor(bor(b(4), lshift(b(5), 8)), bor(lshift(b(6), 16), lshift(b(7), 24)))
  return mk(hi, lo)
end

function U64.write_le(set8, addr, v)
  local lo, hi = v.lo, v.hi
  set8(addr + 0, band(lo, 0xFF))
  set8(addr + 1, band(rshift(lo, 8), 0xFF))
  set8(addr + 2, band(rshift(lo, 16), 0xFF))
  set8(addr + 3, band(rshift(lo, 24), 0xFF))
  set8(addr + 4, band(hi, 0xFF))
  set8(addr + 5, band(rshift(hi, 8), 0xFF))
  set8(addr + 6, band(rshift(hi, 16), 0xFF))
  set8(addr + 7, band(rshift(hi, 24), 0xFF))
end

return U64
