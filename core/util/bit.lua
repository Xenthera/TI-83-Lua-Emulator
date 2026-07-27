-- Portable bit operations for LuaJIT, PUC Lua, and ComputerCraft.
-- Prefer native backends: global `bit` (CC / LuaJIT), `bit32`, then require().

local band, bor, bxor, bnot, lshift, rshift
local backend = "pure-lua"

local function take(lib, name)
  if type(lib) == "table" and type(lib.band) == "function" then
    band = lib.band
    bor = lib.bor
    bxor = lib.bxor
    bnot = lib.bnot
    lshift = lib.lshift or lib.blshift
    rshift = lib.rshift or lib.blogic_rshift or lib.brshift
    if band and bor and bxor and bnot and lshift and rshift then
      backend = name
      return true
    end
  end
  return false
end

if not take(rawget(_G, "bit"), "bit-global") then
  if not take(rawget(_G, "bit32"), "bit32-global") then
    local ok, lib = pcall(require, "bit")
    if not (ok and take(lib, "bit")) then
      ok, lib = pcall(require, "bit32")
      if not (ok and take(lib, "bit32")) then
        -- Pure Lua fallback (much slower - avoid on CC if possible).
        function band(a, b)
          local r, bitv = 0, 1
          a, b = a % 0x100000000, b % 0x100000000
          for _ = 1, 32 do
            if a % 2 == 1 and b % 2 == 1 then
              r = r + bitv
            end
            a, b, bitv = math.floor(a / 2), math.floor(b / 2), bitv * 2
          end
          return r
        end

        function bor(a, b)
          local r, bitv = 0, 1
          a, b = a % 0x100000000, b % 0x100000000
          for _ = 1, 32 do
            if a % 2 == 1 or b % 2 == 1 then
              r = r + bitv
            end
            a, b, bitv = math.floor(a / 2), math.floor(b / 2), bitv * 2
          end
          return r
        end

        function bxor(a, b)
          local r, bitv = 0, 1
          a, b = a % 0x100000000, b % 0x100000000
          for _ = 1, 32 do
            if (a % 2) ~= (b % 2) then
              r = r + bitv
            end
            a, b, bitv = math.floor(a / 2), math.floor(b / 2), bitv * 2
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
    end
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
  backend = backend,
}
