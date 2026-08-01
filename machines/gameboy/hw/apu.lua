-- Game Boy (DMG) APU: 2 pulse + wave + noise, mono sample buffer for host audio.
-- Timing is T-cycles (same as CPU/PPU). Sample rate = CPU_HZ / 128 = 32768 Hz.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Apu = {}
Apu.__index = Apu

local CPU_HZ = 4194304
Apu.SAMPLE_RATE = 32768
local CYCLES_PER_SAMPLE = CPU_HZ / Apu.SAMPLE_RATE -- 128
local FRAME_SEQ_PERIOD = 8192 -- 512 Hz

local DUTY = {
  [0] = { [0] = 0, 0, 0, 0, 0, 0, 0, 1 },
  [1] = { [0] = 1, 0, 0, 0, 0, 0, 0, 1 },
  [2] = { [0] = 1, 1, 1, 1, 0, 0, 0, 0 },
  [3] = { [0] = 0, 1, 1, 1, 1, 1, 1, 0 },
}

-- Read masks (OR with register to get open-bus bits).
local READ_MASK = {
  [0xFF10] = 0x80, [0xFF11] = 0x3F, [0xFF12] = 0x00, [0xFF13] = 0xFF, [0xFF14] = 0xBF,
  [0xFF16] = 0x3F, [0xFF17] = 0x00, [0xFF18] = 0xFF, [0xFF19] = 0xBF,
  [0xFF1A] = 0x7F, [0xFF1B] = 0xFF, [0xFF1C] = 0x9F, [0xFF1D] = 0xFF, [0xFF1E] = 0xBF,
  [0xFF20] = 0xFF, [0xFF21] = 0x00, [0xFF22] = 0x00, [0xFF23] = 0xBF,
  [0xFF24] = 0x00, [0xFF25] = 0x00, [0xFF26] = 0x70,
}

local function ch_pulse()
  return {
    enabled = false,
    dac = false,
    duty = 0,
    duty_step = 0,
    length = 0,
    length_enable = false,
    volume = 0,
    env_vol = 0,
    env_dir = 0,
    env_period = 0,
    env_timer = 0,
    freq = 0,
    period = 0,
    timer = 0,
    -- CH1 sweep
    sweep_period = 0,
    sweep_dir = 0,
    sweep_shift = 0,
    sweep_timer = 0,
    sweep_enable = false,
    shadow_freq = 0,
  }
end

local function ch_wave()
  return {
    enabled = false,
    dac = false,
    length = 0,
    length_enable = false,
    volume_code = 0,
    freq = 0,
    period = 0,
    timer = 0,
    pos = 0,
    sample = 0,
  }
end

local function ch_noise()
  return {
    enabled = false,
    dac = false,
    length = 0,
    length_enable = false,
    volume = 0,
    env_vol = 0,
    env_dir = 0,
    env_period = 0,
    env_timer = 0,
    clock_shift = 0,
    width_mode = 0,
    divisor_code = 0,
    timer = 0,
    lfsr = 0x7FFF,
  }
end

function Apu.new()
  local self = setmetatable({
    power = false,
    nr50 = 0,
    nr51 = 0,
    ch1 = ch_pulse(),
    ch2 = ch_pulse(),
    ch3 = ch_wave(),
    ch4 = ch_noise(),
    wave = {},
    -- Frame sequencer
    fs_timer = 0,
    fs_step = 0,
    -- Sample generation
    sample_timer = 0,
    samples = {},
    sample_r = 1,
    sample_w = 1,
    sample_count = 0,
    sample_cap = Apu.SAMPLE_RATE * 2, -- ~2s ring
    -- Latched register bytes for reads
    reg = {},
  }, Apu)
  for i = 0, 15 do self.wave[i] = 0 end
  for a = 0xFF10, 0xFF3F do self.reg[a] = 0 end
  return self
end

function Apu:reset()
  self.power = false
  self.nr50 = 0
  self.nr51 = 0
  self.ch1 = ch_pulse()
  self.ch2 = ch_pulse()
  self.ch3 = ch_wave()
  self.ch4 = ch_noise()
  for i = 0, 15 do self.wave[i] = 0 end
  self.fs_timer = 0
  self.fs_step = 0
  self.sample_timer = 0
  self.samples = {}
  self.sample_r = 1
  self.sample_w = 1
  self.sample_count = 0
  for a = 0xFF10, 0xFF3F do self.reg[a] = 0 end
end

local function pulse_period(freq)
  return (2048 - band(freq, 0x7FF)) * 4
end

local function wave_period(freq)
  return (2048 - band(freq, 0x7FF)) * 2
end

local function noise_period(ch)
  -- Integer form of (divisor==0 ? 0.5 : divisor) * 8 * 2^shift
  local div = ch.divisor_code
  local base = (div == 0) and 4 or (div * 8)
  local shift = ch.clock_shift
  if shift > 13 then shift = 13 end -- keep period in a sane range
  return base * lshift(1, shift)
end

local function dac_enable_envelope(nrx2)
  return band(nrx2, 0xF8) ~= 0
end

local function trigger_pulse(ch, is_ch1)
  ch.enabled = ch.dac
  if ch.length == 0 then ch.length = 64 end
  ch.timer = ch.period
  ch.env_vol = ch.volume
  ch.env_timer = ch.env_period
  if ch.env_timer == 0 then ch.env_timer = 8 end
  ch.duty_step = 0
  if is_ch1 then
    ch.shadow_freq = ch.freq
    local shift = ch.sweep_shift
    ch.sweep_timer = ch.sweep_period
    if ch.sweep_timer == 0 then ch.sweep_timer = 8 end
    ch.sweep_enable = (ch.sweep_period > 0) or (shift > 0)
    if shift > 0 then
      -- Overflow check
      local f = ch.shadow_freq + rshift(ch.shadow_freq, shift)
      if f > 0x7FF then ch.enabled = false end
    end
  end
end

local function trigger_wave(self)
  local ch = self.ch3
  ch.enabled = ch.dac
  if ch.length == 0 then ch.length = 256 end
  ch.timer = ch.period
  ch.pos = 0
end

local function trigger_noise(ch)
  ch.enabled = ch.dac
  if ch.length == 0 then ch.length = 64 end
  ch.timer = noise_period(ch)
  ch.env_vol = ch.volume
  ch.env_timer = ch.env_period
  if ch.env_timer == 0 then ch.env_timer = 8 end
  ch.lfsr = 0x7FFF
end

local function sweep_calc(ch)
  local f = ch.shadow_freq
  local d = rshift(f, ch.sweep_shift)
  if ch.sweep_dir ~= 0 then
    f = f - d
  else
    f = f + d
  end
  if f > 0x7FF then
    ch.enabled = false
    return ch.shadow_freq
  end
  if ch.sweep_shift > 0 then
    ch.shadow_freq = f
    ch.freq = f
    ch.period = pulse_period(f)
  end
  return f
end

local function clock_length(ch, max_len)
  if ch.length_enable and ch.length > 0 then
    ch.length = ch.length - 1
    if ch.length == 0 then
      ch.enabled = false
    end
  end
end

local function clock_envelope(ch)
  if ch.env_period == 0 then return end
  if ch.env_timer > 0 then
    ch.env_timer = ch.env_timer - 1
  end
  if ch.env_timer == 0 then
    ch.env_timer = ch.env_period
    if ch.env_dir ~= 0 then
      if ch.env_vol < 15 then ch.env_vol = ch.env_vol + 1 end
    else
      if ch.env_vol > 0 then ch.env_vol = ch.env_vol - 1 end
    end
  end
end

function Apu:_frame_sequencer()
  local step = self.fs_step
  -- Length: steps 0,2,4,6
  if step % 2 == 0 then
    clock_length(self.ch1, 64)
    clock_length(self.ch2, 64)
    clock_length(self.ch3, 256)
    clock_length(self.ch4, 64)
  end
  -- Sweep: steps 2,6
  if step == 2 or step == 6 then
    local ch = self.ch1
    if ch.sweep_enable and ch.sweep_period > 0 then
      ch.sweep_timer = ch.sweep_timer - 1
      if ch.sweep_timer <= 0 then
        ch.sweep_timer = ch.sweep_period
        if ch.sweep_timer == 0 then ch.sweep_timer = 8 end
        local f = sweep_calc(ch)
        if ch.sweep_shift > 0 then
          sweep_calc(ch) -- second overflow check
        end
        self.reg[0xFF13] = band(f, 0xFF)
        self.reg[0xFF14] = bor(band(self.reg[0xFF14], 0xF8), rshift(band(f, 0x700), 8))
      end
    end
  end
  -- Envelope: step 7
  if step == 7 then
    clock_envelope(self.ch1)
    clock_envelope(self.ch2)
    clock_envelope(self.ch4)
  end
  self.fs_step = (step + 1) % 8
end

local function pulse_out(ch)
  if not ch.enabled or not ch.dac then return 0 end
  local bitv = DUTY[ch.duty][ch.duty_step] or 0
  if bitv == 0 then return 0 end
  return ch.env_vol
end

local function wave_out(ch)
  if not ch.enabled or not ch.dac then return 0 end
  local s = ch.sample
  local code = ch.volume_code
  if code == 0 then return 0
  elseif code == 1 then return s
  elseif code == 2 then return rshift(s, 1)
  else return rshift(s, 2)
  end
end

local function noise_out(ch)
  if not ch.enabled or not ch.dac then return 0 end
  if band(ch.lfsr, 1) ~= 0 then return 0 end
  return ch.env_vol
end

function Apu:_push_sample(s)
  if self.sample_count >= self.sample_cap then
    -- Drop oldest
    self.sample_r = self.sample_r % self.sample_cap + 1
    self.sample_count = self.sample_count - 1
  end
  self.samples[self.sample_w] = s
  self.sample_w = self.sample_w % self.sample_cap + 1
  self.sample_count = self.sample_count + 1
end

function Apu:_mix_sample()
  if not self.power then
    self:_push_sample(0)
    return
  end
  local s1 = pulse_out(self.ch1)
  local s2 = pulse_out(self.ch2)
  local s3 = wave_out(self.ch3)
  local s4 = noise_out(self.ch4)
  -- NR51 panning — mono mix of L+R enables
  local left, right = 0, 0
  local n = self.nr51
  if band(n, 0x01) ~= 0 then right = right + s1 end
  if band(n, 0x02) ~= 0 then right = right + s2 end
  if band(n, 0x04) ~= 0 then right = right + s3 end
  if band(n, 0x08) ~= 0 then right = right + s4 end
  if band(n, 0x10) ~= 0 then left = left + s1 end
  if band(n, 0x20) ~= 0 then left = left + s2 end
  if band(n, 0x40) ~= 0 then left = left + s3 end
  if band(n, 0x80) ~= 0 then left = left + s4 end
  local vol_l = band(self.nr50, 0x70) / 0x10 + 1 -- 1..8
  local vol_r = band(self.nr50, 0x07) + 1
  -- Each channel 0..15; four channels -> 0..60 before master vol (1..8)
  local mono = (left * vol_l + right * vol_r) * 0.5
  -- Map toward -1..1 (peak ~60*8=480); /240 leaves headroom but stays audible.
  self:_push_sample(mono / 240)
end

local function clock_pulse(ch, cycles)
  if not ch.enabled then return end
  local period = ch.period
  if period < 4 then period = 4 end
  ch.timer = ch.timer - cycles
  while ch.timer <= 0 do
    ch.timer = ch.timer + period
    ch.duty_step = (ch.duty_step + 1) % 8
  end
end

local function clock_wave(self, cycles)
  local ch = self.ch3
  if not ch.enabled then return end
  local period = ch.period
  if period < 2 then period = 2 end
  ch.timer = ch.timer - cycles
  while ch.timer <= 0 do
    ch.timer = ch.timer + period
    ch.pos = (ch.pos + 1) % 32
    local b = self.wave[rshift(ch.pos, 1)] or 0
    if band(ch.pos, 1) == 0 then
      ch.sample = rshift(b, 4)
    else
      ch.sample = band(b, 0x0F)
    end
  end
end

local function clock_noise(ch, cycles)
  if not ch.enabled then return end
  local p = noise_period(ch)
  if p < 8 then p = 8 end
  ch.timer = ch.timer - cycles
  -- Cap LFSR steps so a large catch-up tick cannot hang the host.
  local steps = 0
  while ch.timer <= 0 and steps < 128 do
    ch.timer = ch.timer + p
    local xorv = bxor(band(ch.lfsr, 1), band(rshift(ch.lfsr, 1), 1))
    ch.lfsr = bor(rshift(ch.lfsr, 1), lshift(xorv, 14))
    if ch.width_mode ~= 0 then
      ch.lfsr = band(ch.lfsr, 0x7FBF) -- clear bit 6
      ch.lfsr = bor(ch.lfsr, lshift(xorv, 6))
    end
    steps = steps + 1
  end
  if ch.timer <= 0 then
    ch.timer = p
  end
end

function Apu:tick(cycles)
  if cycles <= 0 then return end
  if not self.power then
    -- Still advance sample clock so hosts get silence at a steady rate.
    self.sample_timer = self.sample_timer + cycles
    while self.sample_timer >= CYCLES_PER_SAMPLE do
      self.sample_timer = self.sample_timer - CYCLES_PER_SAMPLE
      self:_push_sample(0)
    end
    return
  end

  local left = cycles
  while left > 0 do
    local step = left
    local to_fs = FRAME_SEQ_PERIOD - self.fs_timer
    local to_samp = CYCLES_PER_SAMPLE - self.sample_timer
    if to_fs < step then step = to_fs end
    if to_samp < step then step = to_samp end
    if step < 1 then step = 1 end

    clock_pulse(self.ch1, step)
    clock_pulse(self.ch2, step)
    clock_wave(self, step)
    clock_noise(self.ch4, step)

    self.fs_timer = self.fs_timer + step
    if self.fs_timer >= FRAME_SEQ_PERIOD then
      self.fs_timer = self.fs_timer - FRAME_SEQ_PERIOD
      self:_frame_sequencer()
    end

    self.sample_timer = self.sample_timer + step
    if self.sample_timer >= CYCLES_PER_SAMPLE then
      self.sample_timer = self.sample_timer - CYCLES_PER_SAMPLE
      self:_mix_sample()
    end

    left = left - step
  end
end

--- Drain up to `maxn` mono float samples (-1..1). Returns array, count.
function Apu:drain_samples(maxn)
  maxn = maxn or self.sample_count
  if maxn > self.sample_count then maxn = self.sample_count end
  local out = {}
  for i = 1, maxn do
    out[i] = self.samples[self.sample_r] or 0
    self.sample_r = self.sample_r % self.sample_cap + 1
  end
  self.sample_count = self.sample_count - maxn
  return out, maxn
end

function Apu:samples_pending()
  return self.sample_count
end

function Apu:_power_off()
  for a = 0xFF10, 0xFF25 do
    self.reg[a] = 0
  end
  self.ch1 = ch_pulse()
  self.ch2 = ch_pulse()
  self.ch3 = ch_wave()
  self.ch4 = ch_noise()
  self.nr50 = 0
  self.nr51 = 0
  self.fs_timer = 0
  self.fs_step = 0
end

function Apu:read(addr)
  addr = band(addr, 0xFFFF)
  if addr >= 0xFF30 and addr <= 0xFF3F then
    return self.wave[addr - 0xFF30] or 0
  end
  if addr == 0xFF26 then
    local v = self.power and 0x80 or 0x00
    if self.ch1.enabled then v = bor(v, 0x01) end
    if self.ch2.enabled then v = bor(v, 0x02) end
    if self.ch3.enabled then v = bor(v, 0x04) end
    if self.ch4.enabled then v = bor(v, 0x08) end
    return bor(v, 0x70)
  end
  local mask = READ_MASK[addr] or 0xFF
  return bor(self.reg[addr] or 0, mask)
end

function Apu:write(addr, v)
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)

  if addr >= 0xFF30 and addr <= 0xFF3F then
    self.wave[addr - 0xFF30] = v
    self.reg[addr] = v
    return
  end

  if addr == 0xFF26 then
    local on = band(v, 0x80) ~= 0
    if on and not self.power then
      self.power = true
      self.fs_timer = 0
      self.fs_step = 0
    elseif not on and self.power then
      self.power = false
      self:_power_off()
    end
    self.reg[0xFF26] = band(v, 0x80)
    return
  end

  if not self.power then
    -- Length registers can be written on DMG while off (NRx1 lower bits).
    if addr == 0xFF11 then
      self.ch1.length = 64 - band(v, 0x3F)
      self.reg[addr] = v
    elseif addr == 0xFF16 then
      self.ch2.length = 64 - band(v, 0x3F)
      self.reg[addr] = v
    elseif addr == 0xFF1B then
      self.ch3.length = 256 - v
      self.reg[addr] = v
    elseif addr == 0xFF20 then
      self.ch4.length = 64 - band(v, 0x3F)
      self.reg[addr] = v
    end
    return
  end

  self.reg[addr] = v
  local ch1, ch2, ch3, ch4 = self.ch1, self.ch2, self.ch3, self.ch4

  if addr == 0xFF10 then
    ch1.sweep_period = band(rshift(v, 4), 0x07)
    ch1.sweep_dir = band(v, 0x08)
    ch1.sweep_shift = band(v, 0x07)
  elseif addr == 0xFF11 then
    ch1.duty = band(rshift(v, 6), 0x03)
    ch1.length = 64 - band(v, 0x3F)
  elseif addr == 0xFF12 then
    ch1.volume = band(rshift(v, 4), 0x0F)
    ch1.env_dir = band(v, 0x08)
    ch1.env_period = band(v, 0x07)
    ch1.dac = dac_enable_envelope(v)
    if not ch1.dac then ch1.enabled = false end
  elseif addr == 0xFF13 then
    ch1.freq = bor(band(ch1.freq, 0x700), v)
    ch1.period = pulse_period(ch1.freq)
  elseif addr == 0xFF14 then
    ch1.freq = bor(band(ch1.freq, 0xFF), lshift(band(v, 0x07), 8))
    ch1.period = pulse_period(ch1.freq)
    ch1.length_enable = band(v, 0x40) ~= 0
    if band(v, 0x80) ~= 0 then trigger_pulse(ch1, true) end

  elseif addr == 0xFF16 then
    ch2.duty = band(rshift(v, 6), 0x03)
    ch2.length = 64 - band(v, 0x3F)
  elseif addr == 0xFF17 then
    ch2.volume = band(rshift(v, 4), 0x0F)
    ch2.env_dir = band(v, 0x08)
    ch2.env_period = band(v, 0x07)
    ch2.dac = dac_enable_envelope(v)
    if not ch2.dac then ch2.enabled = false end
  elseif addr == 0xFF18 then
    ch2.freq = bor(band(ch2.freq, 0x700), v)
    ch2.period = pulse_period(ch2.freq)
  elseif addr == 0xFF19 then
    ch2.freq = bor(band(ch2.freq, 0xFF), lshift(band(v, 0x07), 8))
    ch2.period = pulse_period(ch2.freq)
    ch2.length_enable = band(v, 0x40) ~= 0
    if band(v, 0x80) ~= 0 then trigger_pulse(ch2, false) end

  elseif addr == 0xFF1A then
    ch3.dac = band(v, 0x80) ~= 0
    if not ch3.dac then ch3.enabled = false end
  elseif addr == 0xFF1B then
    ch3.length = 256 - v
  elseif addr == 0xFF1C then
    ch3.volume_code = band(rshift(v, 5), 0x03)
  elseif addr == 0xFF1D then
    ch3.freq = bor(band(ch3.freq, 0x700), v)
    ch3.period = wave_period(ch3.freq)
  elseif addr == 0xFF1E then
    ch3.freq = bor(band(ch3.freq, 0xFF), lshift(band(v, 0x07), 8))
    ch3.period = wave_period(ch3.freq)
    ch3.length_enable = band(v, 0x40) ~= 0
    if band(v, 0x80) ~= 0 then trigger_wave(self) end

  elseif addr == 0xFF20 then
    ch4.length = 64 - band(v, 0x3F)
  elseif addr == 0xFF21 then
    ch4.volume = band(rshift(v, 4), 0x0F)
    ch4.env_dir = band(v, 0x08)
    ch4.env_period = band(v, 0x07)
    ch4.dac = dac_enable_envelope(v)
    if not ch4.dac then ch4.enabled = false end
  elseif addr == 0xFF22 then
    ch4.clock_shift = band(rshift(v, 4), 0x0F)
    ch4.width_mode = band(v, 0x08)
    ch4.divisor_code = band(v, 0x07)
  elseif addr == 0xFF23 then
    ch4.length_enable = band(v, 0x40) ~= 0
    if band(v, 0x80) ~= 0 then trigger_noise(ch4) end

  elseif addr == 0xFF24 then
    self.nr50 = v
  elseif addr == 0xFF25 then
    self.nr51 = v
  end
end

return Apu
