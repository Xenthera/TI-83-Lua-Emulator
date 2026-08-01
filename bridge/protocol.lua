-- Shared WebSocket message codec (JSON text frames) for LuaJIT host + CC client.
-- Keep this module free of socket / CC / Love deps so both sides can require it.

local B64 = require("bridge.b64")

local M = {}
M.VERSION = 1

local MACHINES = {
  ti83plus = { w = 96, h = 64, bpr = 12, id = "ti83plus" },
  ti84plus = { w = 96, h = 64, bpr = 12, id = "ti84plus" },
  ti89 = { w = 160, h = 100, bpr = 20, id = "ti89" },
  ti92plus = { w = 240, h = 128, bpr = 30, id = "ti92plus" },
  -- Shade framebuffer: 1 byte/pixel, values 0-3 (not 1bpp packed).
  gameboy = { w = 160, h = 144, bpr = 160, id = "gameboy", fmt = "shade" },
}

-- Short / GPU-client aliases -> canonical machine records.
MACHINES.ti83 = MACHINES.ti83plus
MACHINES.ti84 = MACHINES.ti84plus
MACHINES.ti92 = MACHINES.ti92plus
MACHINES.gb = MACHINES.gameboy
MACHINES.ti83_gpu = MACHINES.ti83plus
MACHINES.ti84_gpu = MACHINES.ti84plus
MACHINES.ti89_gpu = MACHINES.ti89
MACHINES.ti92_gpu = MACHINES.ti92plus
MACHINES.gb_gpu = MACHINES.gameboy
MACHINES.gameboy_gpu = MACHINES.gameboy

function M.canonical_id(id)
  id = tostring(id or "")
  local aliases = {
    ti83 = "ti83plus",
    ti83_gpu = "ti83plus",
    ti83plus_gpu = "ti83plus",
    ti84 = "ti84plus",
    ti84_gpu = "ti84plus",
    ti84plus_gpu = "ti84plus",
    ti89_gpu = "ti89",
    ti92 = "ti92plus",
    ti92_gpu = "ti92plus",
    ti92plus_gpu = "ti92plus",
    gb = "gameboy",
    gb_gpu = "gameboy",
    gameboy_gpu = "gameboy",
  }
  return aliases[id] or id
end

function M.machine_info(id)
  return MACHINES[M.canonical_id(id)] or MACHINES[id]
end

local function esc(s)
  s = tostring(s or "")
  s = s:gsub("\\", "\\\\")
  s = s:gsub('"', '\\"')
  s = s:gsub("\n", "\\n")
  s = s:gsub("\r", "\\r")
  s = s:gsub("\t", "\\t")
  return s
end

local function encode_value(v)
  local tv = type(v)
  if tv == "nil" then
    return "null"
  elseif tv == "boolean" then
    return v and "true" or "false"
  elseif tv == "number" then
    if v ~= v or v == math.huge or v == -math.huge then
      return "null"
    end
    return string.format("%.14g", v)
  elseif tv == "string" then
    return '"' .. esc(v) .. '"'
  elseif tv == "table" then
    -- array if contiguous from 1?
    local n = #v
    local is_arr = n > 0
    if is_arr then
      for i = 1, n do
        if v[i] == nil then is_arr = false break end
      end
    end
    if is_arr then
      local parts = {}
      for i = 1, n do
        parts[i] = encode_value(v[i])
      end
      return "[" .. table.concat(parts, ",") .. "]"
    end
    local parts = {}
    for k, val in pairs(v) do
      if type(k) == "string" then
        parts[#parts + 1] = '"' .. esc(k) .. '":' .. encode_value(val)
      end
    end
    table.sort(parts)
    return "{" .. table.concat(parts, ",") .. "}"
  end
  return "null"
end

function M.encode(msg)
  return encode_value(msg)
end

-- Minimal JSON object parser (enough for our flat / shallow messages).
local function skip_ws(s, i)
  while true do
    local c = s:sub(i, i)
    if c == " " or c == "\t" or c == "\n" or c == "\r" then
      i = i + 1
    else
      return i
    end
  end
end

local parse_value

local function parse_string(s, i)
  i = i + 1
  local out = {}
  while i <= #s do
    local c = s:sub(i, i)
    if c == '"' then
      return table.concat(out), i + 1
    elseif c == "\\" then
      local n = s:sub(i + 1, i + 1)
      if n == "n" then out[#out + 1] = "\n"
      elseif n == "r" then out[#out + 1] = "\r"
      elseif n == "t" then out[#out + 1] = "\t"
      else out[#out + 1] = n end
      i = i + 2
    else
      out[#out + 1] = c
      i = i + 1
    end
  end
  return nil, i
end

local function parse_object(s, i)
  local obj = {}
  i = skip_ws(s, i + 1)
  if s:sub(i, i) == "}" then return obj, i + 1 end
  while i <= #s do
    i = skip_ws(s, i)
    if s:sub(i, i) ~= '"' then return nil, i end
    local key
    key, i = parse_string(s, i)
    if not key then return nil, i end
    i = skip_ws(s, i)
    if s:sub(i, i) ~= ":" then return nil, i end
    i = skip_ws(s, i + 1)
    local val
    val, i = parse_value(s, i)
    if val == nil and s:sub(i, i) ~= "n" then
      -- allow explicit null
    end
    obj[key] = val
    i = skip_ws(s, i)
    local c = s:sub(i, i)
    if c == "}" then return obj, i + 1 end
    if c ~= "," then return nil, i end
    i = i + 1
  end
  return nil, i
end

parse_value = function(s, i)
  i = skip_ws(s, i)
  local c = s:sub(i, i)
  if c == '"' then
    return parse_string(s, i)
  elseif c == "{" then
    return parse_object(s, i)
  elseif c == "t" and s:sub(i, i + 3) == "true" then
    return true, i + 4
  elseif c == "f" and s:sub(i, i + 4) == "false" then
    return false, i + 5
  elseif c == "n" and s:sub(i, i + 3) == "null" then
    return nil, i + 4
  elseif c == "-" or (c >= "0" and c <= "9") then
    local j = i
    if s:sub(j, j) == "-" then j = j + 1 end
    while s:sub(j, j):match("%d") do j = j + 1 end
    if s:sub(j, j) == "." then
      j = j + 1
      while s:sub(j, j):match("%d") do j = j + 1 end
    end
    return tonumber(s:sub(i, j - 1)), j
  end
  return nil, i
end

function M.decode(text)
  if type(text) ~= "string" or text == "" then
    return nil, "empty"
  end
  local obj, i = parse_object(text, skip_ws(text, 1))
  if type(obj) ~= "table" or not obj.t then
    return nil, "not a message object"
  end
  return obj
end

function M.hello(machine_id, role)
  return { t = "hello", v = M.VERSION, machine = machine_id, role = role or "display" }
end

function M.hello_ok(info)
  local msg = {
    t = "hello_ok",
    v = M.VERSION,
    machine = info.id,
    w = info.w,
    h = info.h,
    bpr = info.bpr,
  }
  if info.fmt then
    msg.fmt = info.fmt
  end
  if info.rom_loaded ~= nil then
    msg.rom_loaded = not not info.rom_loaded
  end
  if info.rom then
    msg.rom = tostring(info.rom)
  end
  return msg
end

--- Client -> server: one chunk of a cart/ROM upload (raw bytes as b64).
-- i is 0-based; n is total chunk count. size is total raw byte length.
function M.load_rom_chunk(opts)
  opts = opts or {}
  return {
    t = "load_rom",
    v = M.VERSION,
    name = opts.name and tostring(opts.name) or nil,
    size = tonumber(opts.size) or 0,
    i = tonumber(opts.i) or 0,
    n = tonumber(opts.n) or 1,
    b64 = tostring(opts.b64 or ""),
  }
end

function M.load_rom_ok(opts)
  opts = opts or {}
  local msg = {
    t = "load_rom_ok",
    v = M.VERSION,
    size = tonumber(opts.size) or 0,
  }
  if opts.name then msg.name = tostring(opts.name) end
  if opts.title then msg.title = tostring(opts.title) end
  return msg
end

--- Client -> server: pause LCD frames before a cart upload (avoids TCP fill).
function M.load_rom_begin(opts)
  opts = opts or {}
  return {
    t = "load_rom_begin",
    v = M.VERSION,
    name = opts.name and tostring(opts.name) or nil,
    size = tonumber(opts.size) or 0,
  }
end

--- Client -> server: LCD frames are welcome again after connect / upload.
function M.ready()
  return { t = "ready", v = M.VERSION }
end

function M.key(name, down)
  return { t = "key", name = tostring(name), down = not not down }
end

--- One-shot key press: server holds for `hold` emu cycles then releases.
function M.tap(name, hold)
  return {
    t = "tap",
    name = tostring(name),
    hold = tonumber(hold) or 100000,
  }
end

function M.frame(seq, on, fb, nbytes)
  local bin = B64.pack_fb(fb, nbytes)
  return {
    t = "frame",
    seq = seq or 0,
    on = not not on,
    w = nil, -- filled by caller optionally
    b64 = B64.encode(bin),
  }
end

function M.decode_frame_fb(msg, dest)
  if not msg or not msg.b64 then return nil end
  local bin = B64.decode(msg.b64)
  return B64.unpack_fb(bin, dest), #bin
end

--- Fast path: pull b64 out of a raw frame JSON blob (skip full object parse).
-- Returns true, on  or nil.
function M.decode_frame_raw(json, dest)
  if type(json) ~= "string" then return nil end
  local b64 = json:match('"b64"%s*:%s*"([^"]*)"')
  if not b64 or b64 == "" then return nil end
  local bin = B64.decode(b64)
  if not bin or #bin < 1 then return nil end
  B64.unpack_fb(bin, dest)
  local on = not json:find('"on"%s*:%s*false', 1)
  return true, on
end

--- Server -> client: PCM audio chunk (signed 8-bit samples as raw bytes in b64).
-- Legacy JSON path; prefer audio_binary for CC (no b64 tax).
function M.audio(seq, rate, pcm_bin)
  pcm_bin = pcm_bin or ""
  return {
    t = "audio",
    seq = seq or 0,
    rate = tonumber(rate) or 48000,
    n = #pcm_bin,
    b64 = B64.encode(pcm_bin),
  }
end

local function u32le(n)
  n = math.floor(tonumber(n) or 0) % 4294967296
  local b1 = n % 256
  n = math.floor(n / 256)
  local b2 = n % 256
  n = math.floor(n / 256)
  local b3 = n % 256
  n = math.floor(n / 256)
  local b4 = n % 256
  return string.char(b1, b2, b3, b4)
end

local function read_u32le(s, off)
  local a, b, c, d = s:byte(off, off + 3)
  if not a then return 0 end
  return a + b * 256 + c * 65536 + d * 16777216
end

--- Binary LCD frame: "EFRM" + seq u32le + flags u8 + nbytes u32le + raw fb.
-- Much cheaper on CC than JSON+b64 (no JSON parse, no base64).
function M.frame_binary(seq, on, fb, nbytes)
  local bin = B64.pack_fb(fb, nbytes)
  local flags = (on and 1 or 0)
  return "EFRM" .. u32le(seq or 0) .. string.char(flags) .. u32le(#bin) .. bin
end

function M.is_frame_binary(data)
  return type(data) == "string" and #data >= 13 and data:sub(1, 4) == "EFRM"
end

--- Decode binary frame into dest. Returns true, on  or nil.
function M.decode_frame_binary(data, dest)
  if not M.is_frame_binary(data) then return nil end
  local flags = data:byte(9) or 0
  local n = read_u32le(data, 10)
  if n < 1 or #data < 13 + n then return nil end
  B64.unpack_fb(data:sub(14, 13 + n), dest)
  return true, (flags % 2) == 1
end

--- Binary WS audio frame: "GBAS" + seq u32le + rate u32le + n u32le + n bytes s8.
-- Much cheaper on CC than JSON+base64 (~25% size, no b64 decode).
function M.audio_binary(seq, rate, pcm_bin)
  pcm_bin = pcm_bin or ""
  return "GBAS" .. u32le(seq or 0) .. u32le(rate or 48000) .. u32le(#pcm_bin) .. pcm_bin
end

function M.is_audio_binary(data)
  return type(data) == "string" and #data >= 16 and data:sub(1, 4) == "GBAS"
end

--- Returns pcm_bin, rate, seq or nil.
function M.decode_audio_binary(data)
  if not M.is_audio_binary(data) then return nil end
  local seq = read_u32le(data, 5)
  local rate = read_u32le(data, 9)
  local n = read_u32le(data, 13)
  if n < 1 or #data < 16 + n then return nil end
  return data:sub(17, 16 + n), rate, seq
end

function M.decode_audio_pcm(msg)
  if not msg or not msg.b64 then return nil, 0 end
  local AudioPcm = require("bridge.audio_pcm")
  local bin = B64.decode(msg.b64)
  return AudioPcm.unpack_s8(bin), tonumber(msg.rate) or 48000
end

--- Fast path: pull b64 out of a raw audio JSON blob (skip full object parse).
function M.decode_audio_raw(json)
  if type(json) ~= "string" then return nil end
  local b64 = json:match('"b64"%s*:%s*"([^"]*)"')
  if not b64 or b64 == "" then return nil end
  local AudioPcm = require("bridge.audio_pcm")
  local bin = B64.decode(b64)
  if not bin or #bin < 1 then return nil end
  return AudioPcm.unpack_s8(bin)
end

function M.state(fields)
  local m = { t = "state" }
  for k, v in pairs(fields or {}) do
    m[k] = v
  end
  return m
end

function M.error_msg(text)
  return { t = "error", msg = tostring(text) }
end

return M
