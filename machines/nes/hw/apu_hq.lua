-- Modern NES APU render path (optional).
-- Same CPU register state as classic APU; PolyBLEP pulses, smooth triangle,
-- filtered noise/DMC. Does not change timing / envelopes / IRQ behavior.

local bit = require("framework.util.bit")
local band, rshift = bit.band, bit.rshift

local Hq = {}

local CPU_HZ = 1789773

-- NES duty widths (fraction of period). Index 3 is 75% (inv 25%).
local DUTY_WIDTH = { [0] = 0.125, 0.25, 0.5, 0.75 }

local function polyblep(t, dt)
  if dt <= 0 then return 0 end
  if t < dt then
    t = t / dt
    return t + t - t * t - 1
  elseif t > 1 - dt then
    t = (t - 1) / dt
    return t * t + t + t + 1
  end
  return 0
end

local function pulse_amp(ch)
  if not ch.enabled or ch.length == 0 or ch.sweep_mute or ch.timer_period < 8 then
    return 0
  end
  return (ch.constant and ch.volume or ch.env_vol) / 15
end

local function tri_amp(tr)
  if not tr.enabled or tr.length == 0 or tr.linear == 0 or tr.timer_period < 2 then
    return 0
  end
  return 1
end

local function noise_amp(n)
  if not n.enabled or n.length == 0 then return 0 end
  return (n.constant and n.volume or n.env_vol) / 15
end

--- Create HQ oscillator state (attached to Apu as self._hq).
function Hq.new_state()
  return {
    p1_phase = 0,
    p2_phase = 0,
    tri_phase = 0,
    noise_lpf = 0,
    dmc_lpf = 0,
    mix_lpf = 0,
  }
end

local function render_pulse(phase, dt, duty, amp)
  if amp <= 0 or dt <= 0 then return 0, phase end
  -- Advance happens in caller; here phase is post-advance in 0..1.
  local width = DUTY_WIDTH[duty] or 0.5
  local v
  if phase < width then v = 1 else v = -1 end
  v = v + polyblep(phase, dt)
  local t2 = phase - width
  if t2 < 0 then t2 = t2 + 1 end
  v = v - polyblep(t2, dt)
  -- Map bipolar oscillator to 0..amp (nesdev-ish energy, smoother edges).
  return (0.5 + 0.5 * v) * amp, phase
end

local function render_triangle(phase, amp)
  if amp <= 0 then return 0 end
  -- Smooth triangle from phase 0..1 (band-limited-ish via polyblep-ish shaping).
  local t = phase
  local tri
  if t < 0.5 then
    tri = t * 4 - 1
  else
    tri = 3 - t * 4
  end
  -- Gentle sine blend removes stair-step harshness while keeping NES body.
  local sine = math.sin(t * 6.283185307179586)
  return (tri * 0.72 + sine * 0.28) * 0.5 * amp
end

--- Mix one HQ sample. Advances HQ phases by `step` CPU cycles.
-- Returns unipolar-ish mix ~0..1 (caller applies DC / soft clip).
function Hq.mix(apu, step)
  local hq = apu._hq
  if not hq then
    hq = Hq.new_state()
    apu._hq = hq
  end
  step = step or 1
  if step < 1 then step = 1 end

  local p1, p2 = apu.pulse1, apu.pulse2
  local tr, nch, d = apu.triangle, apu.noise, apu.dmc

  -- Pulse: f = CPU / (16*(t+1)); phase += step / period_samples
  local function pulse_dt(ch)
    local period = (ch.timer_period + 1) * 16
    if period < 16 then period = 16 end
    return step / period
  end

  local a1 = pulse_amp(p1)
  local dt1 = pulse_dt(p1)
  hq.p1_phase = hq.p1_phase + dt1
  if hq.p1_phase >= 1 then hq.p1_phase = hq.p1_phase - math.floor(hq.p1_phase) end
  local o1 = 0
  if a1 > 0 then
    o1 = select(1, render_pulse(hq.p1_phase, dt1, p1.duty, a1))
  end

  local a2 = pulse_amp(p2)
  local dt2 = pulse_dt(p2)
  hq.p2_phase = hq.p2_phase + dt2
  if hq.p2_phase >= 1 then hq.p2_phase = hq.p2_phase - math.floor(hq.p2_phase) end
  local o2 = 0
  if a2 > 0 then
    o2 = select(1, render_pulse(hq.p2_phase, dt2, p2.duty, a2))
  end

  -- Triangle: f = CPU / (32*(t+1))
  local ta = tri_amp(tr)
  local tri_period = (tr.timer_period + 1) * 32
  if tri_period < 32 then tri_period = 32 end
  local dt_tri = step / tri_period
  hq.tri_phase = hq.tri_phase + dt_tri
  if hq.tri_phase >= 1 then hq.tri_phase = hq.tri_phase - math.floor(hq.tri_phase) end
  local otri = render_triangle(hq.tri_phase, ta)

  -- Noise: classic LFSR bit, one-pole lowpass for less hiss hash.
  local na = noise_amp(nch)
  local nbit = 0
  if na > 0 and band(nch.shift, 1) == 0 then nbit = 1 end
  local ntarget = nbit * na
  hq.noise_lpf = hq.noise_lpf + (ntarget - hq.noise_lpf) * 0.18
  local onoise = hq.noise_lpf

  -- DMC: lowpass the 7-bit DAC
  local dtarget = (d.output or 0) / 127
  hq.dmc_lpf = hq.dmc_lpf + (dtarget - hq.dmc_lpf) * 0.25

  -- Soft linear mix (clearer than nonlinear nesdev curve for "hi-fi" mode).
  local s = o1 * 0.28 + o2 * 0.28 + otri * 0.34 + onoise * 0.18 + hq.dmc_lpf * 0.22
  -- Gentle tone LPF (~12 kHz-ish at 48 kHz) to tame residual aliasing.
  hq.mix_lpf = hq.mix_lpf + (s - hq.mix_lpf) * 0.55
  return hq.mix_lpf
end

function Hq.reset(apu)
  apu._hq = Hq.new_state()
end

Hq.CPU_HZ = CPU_HZ
return Hq
