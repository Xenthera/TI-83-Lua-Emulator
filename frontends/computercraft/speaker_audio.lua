-- ComputerCraft speaker sink for signed 8-bit PCM @ 48 kHz (speaker.playAudio).
-- Short buffers: video shows the newest frame, so queued audio = A/V lag.
-- See https://tweaked.cc/peripheral/speaker.html

local M = {}
M.SPEAKER_RATE = 48000
-- ~100 ms play buffers. Bigger queue = fewer underrun pauses on CC.
M.PLAY_SAMPLES = 4800
M.PREFILL_SAMPLES = 4800
-- Hard cap on staged PCM (~300 ms).
M.MAX_QUEUED_SAMPLES = 14400

local function find_speaker()
  if type(peripheral) ~= "table" or type(peripheral.find) ~= "function" then
    return nil
  end
  local ok, sp = pcall(peripheral.find, "speaker")
  if ok and sp and type(sp.playAudio) == "function" then
    return sp
  end
  return nil
end

local function chunk_len(ch)
  return (type(ch) == "table" and #ch) or 0
end

local function apply_gain(samples, gain)
  gain = tonumber(gain) or 1
  if not gain or gain == 1 or type(samples) ~= "table" then
    return samples
  end
  local out = {}
  for i = 1, #samples do
    local v = (samples[i] or 0) * gain
    if v > 127 then v = 127 elseif v < -128 then v = -128 end
    -- playAudio wants integers
    if v >= 0 then out[i] = math.floor(v + 0.5) else out[i] = math.ceil(v - 0.5) end
  end
  return out
end

function M.new(opts)
  opts = opts or {}
  return setmetatable({
    speaker = find_speaker(),
    muted = not not opts.muted,
    volume = tonumber(opts.volume) or 1,
    -- Extra PCM multiply (CC volume 1..3 is mostly hearing *range*, not loudness).
    digital_gain = tonumber(opts.digital_gain) or 1,
    queue = {},
    queued_samples = 0,
    playing = false,
    primed = false,
    play_samples = tonumber(opts.play_samples) or M.PLAY_SAMPLES,
    prefill = tonumber(opts.prefill) or M.PREFILL_SAMPLES,
    max_queued = tonumber(opts.max_queued) or M.MAX_QUEUED_SAMPLES,
    max_chunks = 4,
    _warned = false,
  }, { __index = M })
end

function M:refresh()
  if not self.speaker then
    self.speaker = find_speaker()
  end
  return self.speaker ~= nil
end

function M:clear()
  self.queue = {}
  self.queued_samples = 0
  self.playing = false
  self.primed = false
end

function M:set_muted(m)
  self.muted = not not m
  self:clear()
  if self.muted and self.speaker and type(self.speaker.stop) == "function" then
    pcall(function() self.speaker.stop() end)
  end
end

function M:toggle_mute()
  self:set_muted(not self.muted)
  return self.muted
end

local function drop_oldest(self)
  local ch = table.remove(self.queue, 1)
  if ch then
    self.queued_samples = self.queued_samples - chunk_len(ch)
    if self.queued_samples < 0 then self.queued_samples = 0 end
  end
end

--- Drop oldest staged PCM until queued_samples <= max_n (A/V catch-up).
function M:trim_to(max_n)
  max_n = math.max(0, math.floor(tonumber(max_n) or 0))
  while self.queued_samples > max_n and #self.queue > 0 do
    drop_oldest(self)
  end
end

function M:push_pcm(samples)
  if self.muted then return true end
  if type(samples) ~= "table" or #samples < 1 then return true end
  if not self.speaker and not self:refresh() then
    if not self._warned then
      self._warned = true
      print("No speaker peripheral - GB audio muted until one is attached.")
    end
    return false
  end
  samples = apply_gain(samples, self.digital_gain)
  self.queue[#self.queue + 1] = samples
  self.queued_samples = self.queued_samples + #samples
  while self.queued_samples > self.max_queued and #self.queue > 1 do
    drop_oldest(self)
  end
  return true
end

function M:play_pcm(samples)
  return self:push_pcm(samples)
end

function M:needs_data()
  if self.muted then return false end
  if not self.primed then
    return self.queued_samples < self.prefill
  end
  -- Keep about one play buffer staged while another is playing.
  return self.queued_samples < self.play_samples
end

local function coalesce(self, want)
  local parts = {}
  local n = 0
  while #self.queue > 0 and n < want do
    local ch = self.queue[1]
    local cn = chunk_len(ch)
    if cn < 1 then
      table.remove(self.queue, 1)
    elseif n > 0 and n + cn > want then
      break
    else
      table.remove(self.queue, 1)
      parts[#parts + 1] = ch
      n = n + cn
      self.queued_samples = self.queued_samples - cn
    end
  end
  if self.queued_samples < 0 then self.queued_samples = 0 end
  if n < 1 then return nil, 0 end
  if #parts == 1 then
    return parts[1], n
  end
  local samples = {}
  local o = 0
  for pi = 1, #parts do
    local ch = parts[pi]
    for i = 1, #ch do
      o = o + 1
      samples[o] = ch[i]
    end
  end
  return samples, n
end

function M:pump()
  if self.muted or self.playing then return false end
  if not self.speaker and not self:refresh() then return false end
  if #self.queue < 1 then return false end
  if not self.primed and self.queued_samples < self.prefill then
    return false
  end

  local want = self.play_samples
  if self.primed and self.queued_samples < want then
    want = self.queued_samples
    -- Allow a half-buffer tail so we don't stall waiting for a perfect fill.
    if want < math.floor(self.play_samples / 2) then
      return false
    end
  end

  local samples, n = coalesce(self, want)
  if not samples then return false end

  local ok, accepted = pcall(function()
    return self.speaker.playAudio(samples, self.volume)
  end)
  if not ok then
    table.insert(self.queue, 1, samples)
    self.queued_samples = self.queued_samples + n
    return false
  end
  if accepted then
    self.playing = true
    self.primed = true
    return true
  end
  table.insert(self.queue, 1, samples)
  self.queued_samples = self.queued_samples + n
  self.playing = true
  return false
end

function M:on_empty()
  self.playing = false
  self:pump()
end

return M
