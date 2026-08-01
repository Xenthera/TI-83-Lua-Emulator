-- PCM helpers for bridge <-> CC speaker streaming.
-- APU produces float -1..1 @ 32768 Hz; CC speaker.playAudio wants s8 @ 48 kHz.

local M = {}

M.SPEAKER_RATE = 48000
-- ~100 ms WS chunks. Balance latency vs websocket flood on CC.
M.CHUNK_SAMPLES = 4800
-- Cap bridge-side pending PCM (~300 ms). Excess is trimmed (oldest dropped).
M.MAX_PENDING_BYTES = M.CHUNK_SAMPLES * 3

local function float_to_s8(x)
  if x > 1 then x = 1 elseif x < -1 then x = -1 end
  local v = math.floor(x * 127 + 0.5)
  if v > 127 then v = 127 elseif v < -128 then v = -128 end
  return v
end

--- Resample mono float samples to signed 8-bit PCM bytes (0..255 storage).
-- Returns binary string, sample count.
function M.resample_s8(floats, n, src_rate, dst_rate)
  n = n or (floats and #floats) or 0
  if n < 1 then return "", 0 end
  src_rate = src_rate or 32768
  dst_rate = dst_rate or M.SPEAKER_RATE
  local out_n = math.floor(n * dst_rate / src_rate + 0.5)
  if out_n < 1 then out_n = 1 end
  -- Cap one resample burst (~0.25s wall).
  local max_out = math.floor((dst_rate or M.SPEAKER_RATE) * 0.25)
  if out_n > max_out then out_n = max_out end

  local chars = {}
  if n == 1 or out_n == 1 then
    local s = float_to_s8(floats[1] or 0)
    for i = 1, out_n do
      chars[i] = string.char((s + 256) % 256)
    end
    return table.concat(chars), out_n
  end

  local scale = (n - 1) / (out_n - 1)
  for i = 1, out_n do
    local src_pos = (i - 1) * scale + 1
    local i0 = math.floor(src_pos)
    local frac = src_pos - i0
    if i0 < 1 then i0 = 1 end
    if i0 >= n then
      i0 = n
      frac = 0
    end
    local a = floats[i0] or 0
    local b = floats[i0 + 1] or a
    local s = float_to_s8(a + (b - a) * frac)
    chars[i] = string.char((s + 256) % 256)
  end
  return table.concat(chars), out_n
end

--- Unpack binary PCM (byte = s8 as unsigned) into a 1-based amplitude table.
function M.unpack_s8(bin)
  local t = {}
  local n = #bin
  local i = 1
  while i + 7 <= n do
    local a, b, c, d, e, f, g, h = bin:byte(i, i + 7)
    t[i] = a >= 128 and a - 256 or a
    t[i + 1] = b >= 128 and b - 256 or b
    t[i + 2] = c >= 128 and c - 256 or c
    t[i + 3] = d >= 128 and d - 256 or d
    t[i + 4] = e >= 128 and e - 256 or e
    t[i + 5] = f >= 128 and f - 256 or f
    t[i + 6] = g >= 128 and g - 256 or g
    t[i + 7] = h >= 128 and h - 256 or h
    i = i + 8
  end
  while i <= n do
    local v = bin:byte(i)
    t[i] = v >= 128 and v - 256 or v
    i = i + 1
  end
  return t
end

--- Resample floats directly to a playAudio-ready table.
function M.resample_s8_table(floats, n, src_rate, dst_rate)
  local bin = M.resample_s8(floats, n, src_rate, dst_rate)
  return M.unpack_s8(bin)
end

return M
