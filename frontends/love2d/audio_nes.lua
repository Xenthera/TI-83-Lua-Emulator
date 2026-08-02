-- Love2D queueable sink for NES APU samples (mono, 44100 Hz).

local Apu = require("machines.nes.hw.apu")

local Audio = {}
Audio.__index = Audio

local SAMPLE_RATE = Apu.SAMPLE_RATE
local BUFFER_SAMPLES = 2048
local QUEUE_BUFFERS = 6

function Audio.new()
  local self = setmetatable({
    source = nil,
    muted = false,
    _bufs = {},
    _ok = false,
  }, Audio)
  local ok, src = pcall(love.audio.newQueueableSource, SAMPLE_RATE, 16, 1, QUEUE_BUFFERS)
  if not ok or not src then
    ok, src = pcall(love.audio.newQueueableSource, SAMPLE_RATE, 16, 1)
  end
  if ok and src then
    self.source = src
    self._ok = true
    for i = 1, QUEUE_BUFFERS do
      self._bufs[i] = love.sound.newSoundData(BUFFER_SAMPLES, SAMPLE_RATE, 16, 1)
    end
    self._bi = 1
  end
  return self
end

function Audio:set_muted(m)
  self.muted = not not m
  if self.muted and self.source then
    self.source:stop()
  end
end

function Audio:stop()
  if self.source then
    pcall(function() self.source:stop() end)
  end
end

local function clamp16(x)
  if x > 1 then x = 1 elseif x < -1 then x = -1 end
  return x
end

--- Pull samples from machine.apu and queue to the Love audio device.
function Audio:update(machine)
  if not self._ok or not machine or not machine.apu then return end
  if self.muted then
    machine.apu:drain_samples(machine.apu:samples_pending())
    return
  end

  local src = self.source
  local hp = self._hp or 0
  local prev = self._prev or 0
  while src:getFreeBufferCount() > 0 do
    local need = BUFFER_SAMPLES
    local pending = machine.apu:samples_pending()
    if pending < need then
      break
    end
    local samples = machine.apu:drain_samples(need)
    local sd = self._bufs[self._bi]
    self._bi = self._bi % #self._bufs + 1
    for i = 1, need do
      local x = samples[i] or 0
      -- DC blocker so unipolar APU mix is centered for PCM.
      hp = hp * 0.995 + x - prev
      prev = x
      sd:setSample(i - 1, clamp16(hp))
    end
    src:queue(sd)
  end
  self._hp, self._prev = hp, prev

  if not src:isPlaying() and src:getFreeBufferCount() < QUEUE_BUFFERS then
    src:play()
  end
end

return Audio
