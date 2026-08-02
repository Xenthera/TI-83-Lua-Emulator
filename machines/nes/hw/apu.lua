-- NES APU (2A03): pulse1/2, triangle, noise, DMC + frame counter.
-- Batched tick (frame seq + sample edges); mono float samples at SAMPLE_RATE.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Apu = {}
Apu.__index = Apu
Apu.SAMPLE_RATE = 44100

local CPU_HZ = 1789773
local CYCLES_PER_SAMPLE = CPU_HZ / Apu.SAMPLE_RATE

local LENGTH_TABLE = {
  [0]=10,254,20,2,40,4,80,6,160,8,60,10,14,12,26,14,
  12,16,24,18,48,20,96,22,192,24,72,26,16,28,32,30,
}

local DUTY = {
  [0] = {0,1,0,0,0,0,0,0},
  [1] = {0,1,1,0,0,0,0,0},
  [2] = {0,1,1,1,1,0,0,0},
  [3] = {1,0,0,1,1,1,1,1},
}

local TRI_SEQ = {
  15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,
  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
}

local NOISE_PERIOD = {
  [0]=4,8,16,32,64,96,128,160,202,254,380,508,762,1016,2034,4068,
}

local DMC_RATE = {
  [0]=428,380,340,320,286,254,226,214,190,160,142,128,106,84,72,54,
}

-- NTSC frame sequencer step lengths (CPU cycles), 4-step then 5-step.
local FRAME4 = {7457, 7456, 7458, 7458}
local FRAME5 = {7457, 7456, 7458, 7458, 7452}

local function make_pulse()
  return {
    enabled = false, duty = 0, duty_step = 0,
    timer = 0, timer_period = 0, length = 0,
    halt = false, constant = false, volume = 0,
    env_start = false, env_vol = 0, env_div = 0, env_loop = false,
    sweep_enabled = false, sweep_period = 0, sweep_neg = false,
    sweep_shift = 0, sweep_reload = false, sweep_div = 0, sweep_mute = false,
  }
end

local function make_triangle()
  return {
    enabled = false, timer = 0, timer_period = 0, length = 0,
    halt = false, linear = 0, linear_reload = 0,
    linear_reload_flag = false, step = 0, control = false,
  }
end

local function make_noise()
  return {
    enabled = false, timer = 0, timer_period = 0, length = 0,
    halt = false, constant = false, volume = 0,
    env_start = false, env_vol = 0, env_div = 0, env_loop = false,
    mode = false, shift = 1,
  }
end

function Apu.new()
  return setmetatable({
    pulse1 = make_pulse(),
    pulse2 = make_pulse(),
    triangle = make_triangle(),
    noise = make_noise(),
    dmc = {
      enabled = false, irq_enable = false, loop = false, rate_index = 0,
      timer = 0, timer_period = DMC_RATE[0],
      addr = 0xC000, addr_cur = 0xC000, length = 1, bytes_remaining = 0,
      bits_remaining = 0, sample_buffer = 0, sample_buffer_empty = true,
      silence = true, shift = 0, output = 0, irq = false,
    },
    frame_mode = 0,
    frame_irq_inhibit = false,
    frame_irq = false,
    frame_step = 0,
    frame_timer = FRAME4[1],
    sample_timer = 0,
    samples = {},
    sample_r = 1,
    sample_w = 1,
    sample_count = 0,
    sample_cap = Apu.SAMPLE_RATE,
    _debt = 0,
    cpu = nil,
  }, Apu)
end

function Apu:set_cpu(cpu)
  self.cpu = cpu
end

function Apu:reset()
  self.pulse1 = make_pulse()
  self.pulse2 = make_pulse()
  self.triangle = make_triangle()
  self.noise = make_noise()
  local d = self.dmc
  d.enabled, d.irq = false, false
  d.bytes_remaining, d.bits_remaining = 0, 0
  d.sample_buffer_empty, d.silence = true, true
  d.output, d.timer = 0, 0
  self.frame_mode, self.frame_irq_inhibit, self.frame_irq = 0, false, false
  self.frame_step, self.frame_timer = 0, FRAME4[1]
  self.sample_timer = 0
  self.samples = {}
  self.sample_r, self.sample_w, self.sample_count = 1, 1, 0
  self._debt = 0
  self.noise.shift = 1
end

function Apu:owe(c)
  if c > 0 then self._debt = self._debt + c end
end

function Apu:flush()
  local d = self._debt
  if d > 0 then
    self._debt = 0
    self:tick(d)
  end
end

local function pulse_target(ch, ones_complement)
  local change = rshift(ch.timer_period, ch.sweep_shift)
  if ch.sweep_neg then
    change = -change - (ones_complement and 1 or 0)
  end
  return ch.timer_period + change
end

local function pulse_update_mute(ch, ones_complement)
  local t = pulse_target(ch, ones_complement)
  ch.sweep_mute = (ch.timer_period < 8) or (t > 0x7FF)
end

local function clock_envelope(ch)
  if ch.env_start then
    ch.env_start = false
    ch.env_vol = 15
    ch.env_div = ch.volume
  else
    if ch.env_div > 0 then
      ch.env_div = ch.env_div - 1
    else
      ch.env_div = ch.volume
      if ch.env_vol > 0 then
        ch.env_vol = ch.env_vol - 1
      elseif ch.env_loop or ch.halt then
        ch.env_vol = 15
      end
    end
  end
end

local function clock_sweep(ch, ones_complement)
  pulse_update_mute(ch, ones_complement)
  if ch.sweep_div == 0 and ch.sweep_enabled and ch.sweep_shift > 0 and not ch.sweep_mute then
    local t = pulse_target(ch, ones_complement)
    if t <= 0x7FF then ch.timer_period = band(t, 0x7FF) end
  end
  if ch.sweep_div == 0 or ch.sweep_reload then
    ch.sweep_div = ch.sweep_period
    ch.sweep_reload = false
  else
    ch.sweep_div = ch.sweep_div - 1
  end
end

local function clock_length(ch)
  if ch.length > 0 and not ch.halt then ch.length = ch.length - 1 end
end

local function clock_triangle_linear(tr)
  if tr.linear_reload_flag then
    tr.linear = tr.linear_reload
  elseif tr.linear > 0 then
    tr.linear = tr.linear - 1
  end
  if not tr.control then tr.linear_reload_flag = false end
end

function Apu:_quarter_frame()
  clock_envelope(self.pulse1)
  clock_envelope(self.pulse2)
  clock_envelope(self.noise)
  clock_triangle_linear(self.triangle)
end

function Apu:_half_frame()
  clock_length(self.pulse1)
  clock_length(self.pulse2)
  clock_length(self.triangle)
  clock_length(self.noise)
  clock_sweep(self.pulse1, true)
  clock_sweep(self.pulse2, false)
end

function Apu:_do_frame_step()
  local step = self.frame_step
  if self.frame_mode == 0 then
    if step == 0 or step == 2 then
      self:_quarter_frame()
    elseif step == 1 then
      self:_quarter_frame()
      self:_half_frame()
    else
      self:_quarter_frame()
      self:_half_frame()
      if not self.frame_irq_inhibit then
        self.frame_irq = true
        if self.cpu then self.cpu.irq = true end
      end
    end
    self.frame_step = (step + 1) % 4
    self.frame_timer = FRAME4[self.frame_step + 1]
  else
    if step == 0 or step == 2 then
      self:_quarter_frame()
    elseif step == 1 or step == 3 then
      self:_quarter_frame()
      self:_half_frame()
    end
    self.frame_step = (step + 1) % 5
    self.frame_timer = FRAME5[self.frame_step + 1]
  end
end

-- Advance waveform sequencers by `n` CPU clocks (period jumps).
local function advance_pulse(ch, n)
  local period = ch.timer_period + 1
  if period <= 0 then return end
  local t = ch.timer - n
  if t >= 0 then
    ch.timer = t
    return
  end
  local clocks = math.floor((-t - 1) / period) + 1
  ch.timer = t + clocks * period
  ch.duty_step = band(ch.duty_step + clocks, 7)
end

local function advance_triangle(tr, n)
  local period = tr.timer_period + 1
  if period <= 0 then return end
  local t = tr.timer - n
  if t >= 0 then
    tr.timer = t
    return
  end
  local clocks = math.floor((-t - 1) / period) + 1
  tr.timer = t + clocks * period
  if tr.linear > 0 and tr.length > 0 then
    tr.step = (tr.step + clocks) % 32
  end
end

local function advance_noise(nch, n)
  local period = nch.timer_period
  if period <= 0 then period = 4 end
  local t = nch.timer - n
  if t >= 0 then
    nch.timer = t
    return
  end
  local clocks = math.floor((-t - 1) / period) + 1
  nch.timer = t + clocks * period
  if clocks > 64 then clocks = 64 end -- bound LFSR catch-up
  for _ = 1, clocks do
    local bit0 = band(nch.shift, 1)
    local other = nch.mode and band(rshift(nch.shift, 6), 1) or band(rshift(nch.shift, 1), 1)
    nch.shift = bor(rshift(nch.shift, 1), lshift(bxor(bit0, other), 14))
  end
end

function Apu:_dmc_fill_sample()
  local d = self.dmc
  if not d.sample_buffer_empty or d.bytes_remaining == 0 then return end
  local cpu = self.cpu
  local v = 0
  if cpu and cpu.bus and cpu.bus.read then
    v = cpu.bus.read(band(d.addr_cur, 0xFFFF)) or 0
    cpu.stall = (cpu.stall or 0) + 4
  end
  d.sample_buffer = band(v, 0xFF)
  d.sample_buffer_empty = false
  d.addr_cur = band(d.addr_cur + 1, 0xFFFF)
  if d.addr_cur < 0x8000 then d.addr_cur = bor(d.addr_cur, 0x8000) end
  d.bytes_remaining = d.bytes_remaining - 1
  if d.bytes_remaining == 0 then
    if d.loop then
      d.addr_cur = d.addr
      d.bytes_remaining = d.length
    elseif d.irq_enable then
      d.irq = true
      if cpu then cpu.irq = true end
    end
  end
end

local function advance_dmc(self, n)
  local d = self.dmc
  local period = d.timer_period
  if period <= 0 then period = 428 end
  local t = d.timer - n
  if t >= 0 then
    d.timer = t
    return
  end
  local clocks = math.floor((-t - 1) / period) + 1
  d.timer = t + clocks * period
  if clocks > 48 then clocks = 48 end
  for _ = 1, clocks do
    if not d.silence then
      if band(d.shift, 1) ~= 0 then
        if d.output <= 125 then d.output = d.output + 2 end
      else
        if d.output >= 2 then d.output = d.output - 2 end
      end
      d.shift = rshift(d.shift, 1)
    end
    if d.bits_remaining == 0 then
      d.bits_remaining = 8
      if d.sample_buffer_empty then
        d.silence = true
      else
        d.silence = false
        d.shift = d.sample_buffer
        d.sample_buffer_empty = true
      end
      self:_dmc_fill_sample()
    else
      d.bits_remaining = d.bits_remaining - 1
    end
  end
end

local function pulse_out(ch)
  if not ch.enabled or ch.length == 0 or ch.sweep_mute or ch.timer_period < 8 then
    return 0
  end
  if DUTY[ch.duty][ch.duty_step + 1] == 0 then return 0 end
  return ch.constant and ch.volume or ch.env_vol
end

local function triangle_out(tr)
  if not tr.enabled or tr.length == 0 or tr.linear == 0 or tr.timer_period < 2 then
    return 0
  end
  return TRI_SEQ[tr.step + 1]
end

local function noise_out(n)
  if not n.enabled or n.length == 0 or band(n.shift, 1) ~= 0 then return 0 end
  return n.constant and n.volume or n.env_vol
end

local function mix(p1, p2, tri, noi, dmc)
  local pulse = p1 + p2
  local pulse_out_v = 0
  if pulse > 0 then pulse_out_v = 95.88 / ((8128 / pulse) + 100) end
  local tnd = 0
  local t = tri / 8227 + noi / 12241 + dmc / 22638
  if t > 0 then tnd = 159.79 / ((1 / t) + 100) end
  local s = (pulse_out_v + tnd) * 1.5
  if s > 1 then s = 1 end
  return s
end

function Apu:_push_sample(s)
  if self.sample_count >= self.sample_cap then
    self.sample_r = self.sample_r % self.sample_cap + 1
    self.sample_count = self.sample_count - 1
  end
  self.samples[self.sample_w] = s
  self.sample_w = self.sample_w % self.sample_cap + 1
  self.sample_count = self.sample_count + 1
end

function Apu:_advance_channels(n)
  if n <= 0 then return end
  advance_pulse(self.pulse1, n)
  advance_pulse(self.pulse2, n)
  advance_triangle(self.triangle, n)
  advance_noise(self.noise, n)
  advance_dmc(self, n)
end

function Apu:tick(cycles)
  if cycles <= 0 then return end
  local left = cycles
  while left > 0 do
    local to_frame = self.frame_timer
    local to_sample = CYCLES_PER_SAMPLE - self.sample_timer
    if to_sample < 1 then to_sample = 1 end
    local step = left
    if to_frame < step then step = to_frame end
    if to_sample < step then step = math.floor(to_sample) end
    if step < 1 then step = 1 end

    self:_advance_channels(step)
    self.frame_timer = self.frame_timer - step
    self.sample_timer = self.sample_timer + step
    left = left - step

    if self.frame_timer <= 0 then
      self:_do_frame_step()
    end
    if self.sample_timer >= CYCLES_PER_SAMPLE then
      self.sample_timer = self.sample_timer - CYCLES_PER_SAMPLE
      self:_push_sample(mix(
        pulse_out(self.pulse1), pulse_out(self.pulse2),
        triangle_out(self.triangle), noise_out(self.noise),
        self.dmc.output
      ))
    end
  end
end

local function write_pulse(ch, reg, v, ones_complement)
  if reg == 0 then
    ch.duty = rshift(band(v, 0xC0), 6)
    ch.halt = band(v, 0x20) ~= 0
    ch.env_loop = ch.halt
    ch.constant = band(v, 0x10) ~= 0
    ch.volume = band(v, 0x0F)
  elseif reg == 1 then
    ch.sweep_enabled = band(v, 0x80) ~= 0
    ch.sweep_period = rshift(band(v, 0x70), 4)
    ch.sweep_neg = band(v, 0x08) ~= 0
    ch.sweep_shift = band(v, 0x07)
    ch.sweep_reload = true
    pulse_update_mute(ch, ones_complement)
  elseif reg == 2 then
    ch.timer_period = bor(band(ch.timer_period, 0x700), v)
    pulse_update_mute(ch, ones_complement)
  elseif reg == 3 then
    ch.timer_period = bor(band(ch.timer_period, 0xFF), lshift(band(v, 7), 8))
    if ch.enabled then ch.length = LENGTH_TABLE[rshift(v, 3)] or 0 end
    ch.duty_step = 0
    ch.env_start = true
    pulse_update_mute(ch, ones_complement)
  end
end

function Apu:write(addr, v)
  self:flush()
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)

  if addr <= 0x4003 then
    write_pulse(self.pulse1, addr - 0x4000, v, true)
  elseif addr <= 0x4007 then
    write_pulse(self.pulse2, addr - 0x4004, v, false)
  elseif addr == 0x4008 then
    local tr = self.triangle
    tr.control = band(v, 0x80) ~= 0
    tr.halt = tr.control
    tr.linear_reload = band(v, 0x7F)
  elseif addr == 0x400A then
    local tr = self.triangle
    tr.timer_period = bor(band(tr.timer_period, 0x700), v)
  elseif addr == 0x400B then
    local tr = self.triangle
    tr.timer_period = bor(band(tr.timer_period, 0xFF), lshift(band(v, 7), 8))
    if tr.enabled then tr.length = LENGTH_TABLE[rshift(v, 3)] or 0 end
    tr.linear_reload_flag = true
  elseif addr == 0x400C then
    local n = self.noise
    n.halt = band(v, 0x20) ~= 0
    n.env_loop = n.halt
    n.constant = band(v, 0x10) ~= 0
    n.volume = band(v, 0x0F)
  elseif addr == 0x400E then
    local n = self.noise
    n.mode = band(v, 0x80) ~= 0
    n.timer_period = NOISE_PERIOD[band(v, 0x0F)] or 4
  elseif addr == 0x400F then
    local n = self.noise
    if n.enabled then n.length = LENGTH_TABLE[rshift(v, 3)] or 0 end
    n.env_start = true
  elseif addr == 0x4010 then
    local d = self.dmc
    d.irq_enable = band(v, 0x80) ~= 0
    d.loop = band(v, 0x40) ~= 0
    d.rate_index = band(v, 0x0F)
    d.timer_period = DMC_RATE[d.rate_index] or 428
    if not d.irq_enable then d.irq = false end
  elseif addr == 0x4011 then
    self.dmc.output = band(v, 0x7F)
  elseif addr == 0x4012 then
    self.dmc.addr = bor(0xC000, lshift(v, 6))
  elseif addr == 0x4013 then
    self.dmc.length = lshift(v, 4) + 1
  elseif addr == 0x4015 then
    local p1, p2, tr, n, d = self.pulse1, self.pulse2, self.triangle, self.noise, self.dmc
    p1.enabled = band(v, 0x01) ~= 0
    if not p1.enabled then p1.length = 0 end
    p2.enabled = band(v, 0x02) ~= 0
    if not p2.enabled then p2.length = 0 end
    tr.enabled = band(v, 0x04) ~= 0
    if not tr.enabled then tr.length = 0 end
    n.enabled = band(v, 0x08) ~= 0
    if not n.enabled then n.length = 0 end
    if band(v, 0x10) ~= 0 then
      d.enabled = true
      if d.bytes_remaining == 0 then
        d.addr_cur = d.addr
        d.bytes_remaining = d.length
      end
      self:_dmc_fill_sample()
    else
      d.enabled = false
      d.bytes_remaining = 0
    end
    d.irq = false
  elseif addr == 0x4017 then
    self.frame_mode = band(v, 0x80) ~= 0 and 1 or 0
    self.frame_irq_inhibit = band(v, 0x40) ~= 0
    if self.frame_irq_inhibit then self.frame_irq = false end
    self.frame_step = 0
    self.frame_timer = (self.frame_mode == 0) and FRAME4[1] or FRAME5[1]
    if self.frame_mode == 1 then
      self:_quarter_frame()
      self:_half_frame()
    end
  end
end

function Apu:read(addr)
  self:flush()
  addr = band(addr, 0xFFFF)
  if addr ~= 0x4015 then return nil end
  local v = 0
  if self.pulse1.length > 0 then v = bor(v, 0x01) end
  if self.pulse2.length > 0 then v = bor(v, 0x02) end
  if self.triangle.length > 0 then v = bor(v, 0x04) end
  if self.noise.length > 0 then v = bor(v, 0x08) end
  if self.dmc.bytes_remaining > 0 then v = bor(v, 0x10) end
  if self.frame_irq then v = bor(v, 0x40) end
  if self.dmc.irq then v = bor(v, 0x80) end
  self.frame_irq = false
  return v
end

function Apu:drain_samples(maxn)
  self:flush()
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
  self:flush()
  return self.sample_count
end

return Apu
