-- Portable bit operations for LuaJIT and Lua 5.1+.
local ok, bitlib = pcall(require, "bit")
if not ok then
  ok, bitlib = pcall(require, "bit32")
end

local band, bor, bxor, bnot, lshift, rshift

if ok and bitlib then
  band = bitlib.band
  bor = bitlib.bor
  bxor = bitlib.bxor
  bnot = bitlib.bnot
  lshift = bitlib.lshift
  rshift = bitlib.rshift
else
  -- Pure Lua fallback (slower).
  function band(a, b)
    local r, bit = 0, 1
    a, b = a % 0x100000000, b % 0x100000000
    for _ = 1, 32 do
      if a % 2 == 1 and b % 2 == 1 then
        r = r + bit
      end
      a, b, bit = math.floor(a / 2), math.floor(b / 2), bit * 2
    end
    return r
  end

  function bor(a, b)
    local r, bit = 0, 1
    a, b = a % 0x100000000, b % 0x100000000
    for _ = 1, 32 do
      if a % 2 == 1 or b % 2 == 1 then
        r = r + bit
      end
      a, b, bit = math.floor(a / 2), math.floor(b / 2), bit * 2
    end
    return r
  end

  function bxor(a, b)
    local r, bit = 0, 1
    a, b = a % 0x100000000, b % 0x100000000
    for _ = 1, 32 do
      if (a % 2) ~= (b % 2) then
        r = r + bit
      end
      a, b, bit = math.floor(a / 2), math.floor(b / 2), bit * 2
    end
    return r
  end

  function bnot(a)
    return (-1 - a) % 0x100000000
  end

  function lshift(a, n)
    return (a * (2 ^ n)) % 0x100000000
  end

  function rshift(a, n)
    return math.floor((a % 0x100000000) / (2 ^ n))
  end
end

local function u8(v)
  return band(v, 0xFF)
end

local function u16(v)
  return band(v, 0xFFFF)
end

local function low(v)
  return band(v, 0xFF)
end

local function high(v)
  return band(rshift(v, 8), 0xFF)
end

local function pair(h, l)
  return bor(lshift(band(h, 0xFF), 8), band(l, 0xFF))
end

local function test(v, mask)
  return band(v, mask) ~= 0
end

return {
  band = band,
  bor = bor,
  bxor = bxor,
  bnot = bnot,
  lshift = lshift,
  rshift = rshift,
  u8 = u8,
  u16 = u16,
  low = low,
  high = high,
  pair = pair,
  test = test,
}
