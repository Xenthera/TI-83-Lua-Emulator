-- Minimal base64 (encode/decode) for bridge protocol frame payloads.

local M = {}

local ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
local DEC = {}
for i = 1, #ALPH do
  DEC[ALPH:byte(i)] = i - 1
end
DEC[("="):byte()] = 0

function M.encode(data)
  local out = {}
  local n = #data
  local i = 1
  local o = 1
  while i <= n do
    local a = data:byte(i) or 0
    local b = data:byte(i + 1) or 0
    local c = data:byte(i + 2) or 0
    local triple = a * 65536 + b * 256 + c
    local remain = n - i + 1
    out[o] = ALPH:sub(math.floor(triple / 262144) % 64 + 1, math.floor(triple / 262144) % 64 + 1)
    out[o + 1] = ALPH:sub(math.floor(triple / 4096) % 64 + 1, math.floor(triple / 4096) % 64 + 1)
    if remain >= 2 then
      out[o + 2] = ALPH:sub(math.floor(triple / 64) % 64 + 1, math.floor(triple / 64) % 64 + 1)
    else
      out[o + 2] = "="
    end
    if remain >= 3 then
      out[o + 3] = ALPH:sub(triple % 64 + 1, triple % 64 + 1)
    else
      out[o + 3] = "="
    end
    o = o + 4
    i = i + 3
  end
  return table.concat(out)
end

function M.decode(s)
  if not s or s == "" then return "" end
  s = s:gsub("%s", "")
  local out = {}
  local o = 1
  for i = 1, #s, 4 do
    local a = DEC[s:byte(i)] or 0
    local b = DEC[s:byte(i + 1)] or 0
    local c = DEC[s:byte(i + 2)] or 0
    local d = DEC[s:byte(i + 3)] or 0
    local triple = a * 262144 + b * 4096 + c * 64 + d
    out[o] = string.char(math.floor(triple / 65536) % 256)
    if s:sub(i + 2, i + 2) ~= "=" then
      out[o + 1] = string.char(math.floor(triple / 256) % 256)
      o = o + 1
    end
    if s:sub(i + 3, i + 3) ~= "=" then
      out[o + 1] = string.char(triple % 256)
      o = o + 1
    end
    o = o + 1
  end
  return table.concat(out)
end

--- Pack 0-based byte array (fb[0]..fb[n-1] or sparse) into a binary string.
function M.pack_fb(fb, nbytes)
  local t = {}
  for i = 0, nbytes - 1 do
    t[i + 1] = string.char(fb[i] or 0)
  end
  return table.concat(t)
end

--- Unpack binary string into 0-based table (unrolled).
function M.unpack_fb(bin, dest)
  dest = dest or {}
  local n = #bin
  local i = 1
  while i + 7 <= n do
    local a, b, c, d, e, f, g, h = bin:byte(i, i + 7)
    dest[i - 1] = a
    dest[i] = b
    dest[i + 1] = c
    dest[i + 2] = d
    dest[i + 3] = e
    dest[i + 4] = f
    dest[i + 5] = g
    dest[i + 6] = h
    i = i + 8
  end
  while i <= n do
    dest[i - 1] = bin:byte(i)
    i = i + 1
  end
  return dest
end

return M
