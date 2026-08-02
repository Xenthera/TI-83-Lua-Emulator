-- Portable bit operations for LuaJIT, PUC Lua, and ComputerCraft.
-- Prefer: Lua 5.3+ native ops, global `bit` (CC / LuaJIT), `bit32`, then slow fallback.

local band, bor, bxor, bnot, lshift, rshift
local backend = "pure-lua"
local U32 = 0xFFFFFFFF

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

-- Lua 5.3+/5.4/5.5: native bitwise operators (orders of magnitude faster than
-- the pure-Lua bit loops). Detect via load() so this file stays parseable on 5.1.
local native_ok = false
do
  local maj = tonumber((_VERSION or ""):match("Lua (%d+)%.") or 0)
  local min = tonumber((_VERSION or ""):match("Lua %d+%.(%d+)") or 0)
  -- Bitwise operators exist from Lua 5.3 onward (not LuaJIT / 5.1 / 5.2).
  if maj > 5 or (maj == 5 and min >= 3) then
    local chunk = load([[
      local U32 = 0xFFFFFFFF
      local function u32(v) return v & U32 end
      return {
        band = function(a, b) return u32(a) & u32(b) end,
        bor = function(a, b) return u32(a) | u32(b) end,
        bxor = function(a, b) return u32(a) ~ u32(b) end,
        bnot = function(a) return (~u32(a)) & U32 end,
        lshift = function(a, n) return (u32(a) << n) & U32 end,
        rshift = function(a, n) return u32(a) >> n end,
      }
    ]])
    if chunk then
      local ok, lib = pcall(chunk)
      if ok and take(lib, "lua53-native") then
        native_ok = true
      end
    end
  end
end

if not native_ok then
  -- Prefer bit32 (unsigned) over legacy `bit` (often signed int32) when both
  -- exist - ComputerCraft:Tweaked ships both; unsigned skips u32 wrapping.
  if not take(rawget(_G, "bit32"), "bit32-global") then
    if not take(rawget(_G, "bit"), "bit-global") then
      local ok, lib = pcall(require, "bit32")
      if not (ok and take(lib, "bit32")) then
        ok, lib = pcall(require, "bit")
        if not (ok and take(lib, "bit")) then
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
end

-- LuaJIT/bit32 return signed int32 (-2^31..2^31-1). The emulator assumes
-- unsigned 0..0xFFFFFFFF (Lua 5.3+ native). Normalize when needed.
-- lua53-native / bit32 already return unsigned - skip the branch.
local need_u32 = (backend ~= "lua53-native"
  and backend ~= "bit32-global"
  and backend ~= "bit32")

local function u32(v)
  if v < 0 then return v + 0x100000000 end
  return v
end

-- LuaJIT bit / many bit32 builds only accept two operands. Emulator code
-- frequently uses bor(C, V, Z, N, X). Inline 2-arg hot path (no nested closure).
do
  local _band, _bor, _bxor, _bnot = band, bor, bxor, bnot
  local _lshift, _rshift = lshift, rshift
  if need_u32 then
    -- Hot path: wrap once at the end; 2-arg is by far the common case.
    local U32 = 0x100000000
    function band(a, b, c, d, e)
      local r = _band(a, b)
      if c ~= nil then
        r = _band(r, c)
        if d ~= nil then
          r = _band(r, d)
          if e ~= nil then r = _band(r, e) end
        end
      end
      if r < 0 then r = r + U32 end
      return r
    end
    function bor(a, b, c, d, e)
      local r = _bor(a, b)
      if c ~= nil then
        r = _bor(r, c)
        if d ~= nil then
          r = _bor(r, d)
          if e ~= nil then r = _bor(r, e) end
        end
      end
      if r < 0 then r = r + U32 end
      return r
    end
    function bxor(a, b, c, d, e)
      local r = _bxor(a, b)
      if c ~= nil then
        r = _bxor(r, c)
        if d ~= nil then
          r = _bxor(r, d)
          if e ~= nil then r = _bxor(r, e) end
        end
      end
      if r < 0 then r = r + U32 end
      return r
    end
    function bnot(a)
      local r = _bnot(a)
      if r < 0 then return r + U32 end
      return r
    end
    function lshift(a, n)
      local r = _lshift(a, n)
      if r < 0 then return r + U32 end
      return r
    end
    function rshift(a, n)
      local r = _rshift(a, n)
      if r < 0 then return r + U32 end
      return r
    end
  else
    function band(a, b, c, d, e)
      local r = _band(a, b)
      if c == nil then return r end
      r = _band(r, c)
      if d == nil then return r end
      r = _band(r, d)
      if e == nil then return r end
      return _band(r, e)
    end
    function bor(a, b, c, d, e)
      local r = _bor(a, b)
      if c == nil then return r end
      r = _bor(r, c)
      if d == nil then return r end
      r = _bor(r, d)
      if e == nil then return r end
      return _bor(r, e)
    end
    function bxor(a, b, c, d, e)
      local r = _bxor(a, b)
      if c == nil then return r end
      r = _bxor(r, c)
      if d == nil then return r end
      r = _bxor(r, d)
      if e == nil then return r end
      return _bxor(r, e)
    end
    bnot = _bnot
    lshift = _lshift
    rshift = _rshift
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
