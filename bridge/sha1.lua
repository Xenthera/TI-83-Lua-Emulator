-- Tiny SHA-1 (for WebSocket handshake Accept key). Pure Lua.

local M = {}

local function band(a, b)
  local res, bit, p = 0, 1, 1
  for _ = 1, 32 do
    local aa, bb = a % 2, b % 2
    if aa == 1 and bb == 1 then res = res + p end
    a, b, p = (a - aa) / 2, (b - bb) / 2, p * 2
  end
  return res
end

local function bor(a, b)
  local res, p = 0, 1
  for _ = 1, 32 do
    local aa, bb = a % 2, b % 2
    if aa == 1 or bb == 1 then res = res + p end
    a, b, p = (a - aa) / 2, (b - bb) / 2, p * 2
  end
  return res
end

local function bxor(a, b)
  local res, p = 0, 1
  for _ = 1, 32 do
    local aa, bb = a % 2, b % 2
    if aa ~= bb then res = res + p end
    a, b, p = (a - aa) / 2, (b - bb) / 2, p * 2
  end
  return res
end

local function bnot(x)
  return 4294967295 - x
end

local function lrot(x, n)
  n = n % 32
  return band(bor(x * (2 ^ n), math.floor(x / (2 ^ (32 - n)))), 4294967295)
end

local function to_u32(x)
  return x % 4294967296
end

local function bytes_to_u32(s, i)
  local a, b, c, d = s:byte(i, i + 3)
  return ((a * 256 + b) * 256 + c) * 256 + d
end

local function u32_to_bytes(n)
  local a = math.floor(n / 16777216) % 256
  local b = math.floor(n / 65536) % 256
  local c = math.floor(n / 256) % 256
  local d = n % 256
  return string.char(a, b, c, d)
end

function M.sha1(msg)
  local h0, h1, h2, h3, h4 = 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0
  local ml = #msg * 8
  msg = msg .. "\128"
  while (#msg % 64) ~= 56 do
    msg = msg .. "\0"
  end
  local hi = math.floor(ml / 4294967296)
  local lo = ml % 4294967296
  msg = msg .. u32_to_bytes(hi) .. u32_to_bytes(lo)

  for chunk = 1, #msg, 64 do
    local w = {}
    for i = 0, 15 do
      w[i] = bytes_to_u32(msg, chunk + i * 4)
    end
    for i = 16, 79 do
      w[i] = lrot(bxor(bxor(w[i - 3], w[i - 8]), bxor(w[i - 14], w[i - 16])), 1)
    end
    local a, b, c, d, e = h0, h1, h2, h3, h4
    for i = 0, 79 do
      local f, k
      if i < 20 then
        f = bor(band(b, c), band(bnot(b), d))
        k = 0x5A827999
      elseif i < 40 then
        f = bxor(bxor(b, c), d)
        k = 0x6ED9EBA1
      elseif i < 60 then
        f = bor(bor(band(b, c), band(b, d)), band(c, d))
        k = 0x8F1BBCDC
      else
        f = bxor(bxor(b, c), d)
        k = 0xCA62C1D6
      end
      local temp = to_u32(lrot(a, 5) + f + e + k + w[i])
      e, d, c, b, a = d, c, lrot(b, 30), a, temp
    end
    h0 = to_u32(h0 + a)
    h1 = to_u32(h1 + b)
    h2 = to_u32(h2 + c)
    h3 = to_u32(h3 + d)
    h4 = to_u32(h4 + e)
  end
  return u32_to_bytes(h0) .. u32_to_bytes(h1) .. u32_to_bytes(h2)
    .. u32_to_bytes(h3) .. u32_to_bytes(h4)
end

local B64ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

function M.b64(data)
  local out = {}
  local n = #data
  local i, o = 1, 1
  while i <= n do
    local a, b, c = data:byte(i, i + 2)
    a, b, c = a or 0, b or 0, c or 0
    local triple = a * 65536 + b * 256 + c
    local remain = n - i + 1
    out[o] = B64ALPH:sub(math.floor(triple / 262144) % 64 + 1, math.floor(triple / 262144) % 64 + 1)
    out[o + 1] = B64ALPH:sub(math.floor(triple / 4096) % 64 + 1, math.floor(triple / 4096) % 64 + 1)
    out[o + 2] = remain >= 2 and B64ALPH:sub(math.floor(triple / 64) % 64 + 1, math.floor(triple / 64) % 64 + 1) or "="
    out[o + 3] = remain >= 3 and B64ALPH:sub(triple % 64 + 1, triple % 64 + 1) or "="
    o = o + 4
    i = i + 3
  end
  return table.concat(out)
end

function M.ws_accept(key)
  return M.b64(M.sha1(key .. "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"))
end

return M
