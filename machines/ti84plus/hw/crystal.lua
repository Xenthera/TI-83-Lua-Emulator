-- SE/84+ crystal timers (ports 30–38). WikiTI 83Plus:Ports:30.
-- Three independent countdown timers; expiry sets port 04 bits 5/6/7.

local bit = require("framework.util.bit")
local band, bor, rshift = bit.band, bit.bor, bit.rshift

local XTAL = 32768

local CRYSTAL_HZ = {
  [0x40] = XTAL / 3,
  [0x41] = XTAL / 33,
  [0x42] = XTAL / 328,
  [0x43] = XTAL / 3277,
  [0x44] = XTAL,
  [0x45] = 2048,
  [0x46] = 128,
  [0x47] = 8,
}

local Crystal = {}
Crystal.__index = Crystal

local function make_timer()
  return {
    freq = 0,
    loop = 0,
    count = 0,
    reload = 0,
    acc = 0,
    period = 0,
    active = false,
    expired = false,
  }
end

local function refresh_oneshot_live(self)
  for i = 1, 3 do
    local t = self.timers[i]
    if t.active and not t.expired and band(t.loop, 0x01) == 0 then
      self.oneshot_live = true
      return
    end
  end
  self.oneshot_live = false
end

local function recompute_period(t, cpu_hz)
  local mode = band(rshift(t.freq, 6), 0x03)
  local hz = 0
  if mode == 0 then
    t.period = 0
    t.active = false
    return
  elseif mode == 1 then
    hz = CRYSTAL_HZ[band(t.freq, 0xFF)]
    if not hz then
      local d = band(t.freq, 0x3F)
      hz = XTAL / (d + 1)
    end
  else
    local d = band(t.freq, 0x3F)
    local div = (d == 0) and 1 or (d * 2)
    hz = cpu_hz / div
  end
  if hz <= 0 then
    t.period = 0
    t.active = false
    return
  end
  t.period = math.max(1, math.floor(cpu_hz / hz + 0.5))
end

function Crystal.new()
  return setmetatable({
    timers = { make_timer(), make_timer(), make_timer() },
    oneshot_live = false,
    _pulse04 = 0,
  }, Crystal)
end

function Crystal:reset()
  for i = 1, 3 do
    self.timers[i] = make_timer()
  end
  self.oneshot_live = false
  self._pulse04 = 0
end

function Crystal:set_freq(idx, value, cpu_hz)
  local t = self.timers[idx]
  t.freq = band(value, 0xFF)
  recompute_period(t, cpu_hz or 6000000)
  if band(rshift(t.freq, 6), 0x03) == 0 then
    t.active = false
  end
  refresh_oneshot_live(self)
end

function Crystal:set_loop(idx, value)
  local t = self.timers[idx]
  t.loop = band(value, 0xFF)
  t.expired = false
  refresh_oneshot_live(self)
end

function Crystal:set_counter(idx, value, cpu_hz)
  local t = self.timers[idx]
  value = band(value, 0xFF)
  if value == 0 then
    t.reload = 256
    t.count = 256
    t.active = false
    t.expired = false
    t.acc = 0
    refresh_oneshot_live(self)
    return
  end
  t.reload = value
  t.count = value
  t.acc = 0
  t.expired = false
  recompute_period(t, cpu_hz or 6000000)
  t.active = t.period > 0 and band(rshift(t.freq, 6), 0x03) ~= 0
  refresh_oneshot_live(self)
end

function Crystal:read_counter(idx)
  return band(self.timers[idx].count, 0xFF)
end

function Crystal:read_freq(idx)
  return self.timers[idx].freq
end

function Crystal:read_loop(idx)
  return self.timers[idx].loop
end

function Crystal:port04_bits()
  local v = band(self._pulse04 or 0, 0xE0)
  if self.timers[1].expired then v = bor(v, 0x20) end
  if self.timers[2].expired then v = bor(v, 0x40) end
  if self.timers[3].expired then v = bor(v, 0x80) end
  return v
end

--- Clear one-shot port-$04 pulses after the OS has observed them.
function Crystal:consume_pulse04()
  self._pulse04 = 0
end

function Crystal:irq_pending()
  for i = 1, 3 do
    local t = self.timers[i]
    if t.expired and band(t.loop, 0x02) ~= 0 then
      return true
    end
  end
  return false
end

function Crystal:tick(cycles, cpu_hz)
  local changed = false
  for i = 1, 3 do
    local t = self.timers[i]
    if t.active and t.period > 0 then
      t.acc = t.acc + cycles
      while t.acc >= t.period and t.active do
        t.acc = t.acc - t.period
        t.count = t.count - 1
        if t.count <= 0 then
          t.expired = true
          t.count = t.reload
          if band(t.loop, 0x01) == 0 then
            t.active = false
          end
          changed = true
          break
        end
      end
    end
  end
  if changed then
    refresh_oneshot_live(self)
  end
end

function Crystal:on_cpu_hz(cpu_hz)
  for i = 1, 3 do
    local t = self.timers[i]
    if band(rshift(t.freq, 6), 0x03) ~= 0 then
      recompute_period(t, cpu_hz)
    end
  end
end

--- Cycles until the soonest active one-shot timer expires (nil if none).
function Crystal:cycles_to_next_expiry()
  local best = nil
  for i = 1, 3 do
    local t = self.timers[i]
    -- Only one-shot delays (OS waits); looping timers keep running normally.
    if t.active and not t.expired and t.period > 0 and t.count > 0
        and band(t.loop, 0x01) == 0 then
      local left = (t.count - 1) * t.period + (t.period - t.acc)
      if left < 0 then left = 0 end
      if not best or left < best then
        best = left
      end
    end
  end
  return best
end

--- End the soonest one-shot delay immediately (no ASIC time warp).
-- Used so port-$04 busy-waits do not consume the realtime budget or skip
-- keyscan IRQs / key-hold accounting.
function Crystal:force_nearest_expiry()
  local best_i, best_left = nil, nil
  for i = 1, 3 do
    local t = self.timers[i]
    if t.active and not t.expired and t.period > 0 and t.count > 0
        and band(t.loop, 0x01) == 0 then
      local left = (t.count - 1) * t.period + (t.period - t.acc)
      if left < 0 then left = 0 end
      if not best_left or left < best_left then
        best_i, best_left = i, left
      end
    end
  end
  if not best_i then
    refresh_oneshot_live(self)
    return false
  end
  local t = self.timers[best_i]
  -- Pulse the port-$04 expiry bit for the waiting poll, but do not leave it
  -- sticky — a stuck bit 7 steers every IM1 into the crystal handler.
  t.expired = false
  t.active = false
  t.count = t.reload
  t.acc = 0
  self._pulse04 = bor(self._pulse04 or 0, ({ 0x20, 0x40, 0x80 })[best_i])
  refresh_oneshot_live(self)
  return true
end

function Crystal:has_oneshot()
  return self.oneshot_live
end

--- TI-OS delay loops: IN A,(4) / BIT 5|6|7,A / JR Z back into that poll.
function Crystal:is_port04_delay_spin(mmu, pc)
  local op = mmu:read(pc)
  -- INC HL ; IN A,(4) — common TI delay prologue
  if op == 0x23 and mmu:read(pc + 1) == 0xDB and mmu:read(pc + 2) == 0x04 then
    return true
  end
  if op == 0xDB and mmu:read(pc + 1) == 0x04 then
    return true
  end
  if op == 0xCB then
    local n = mmu:read(pc + 1)
    if n == 0x6F or n == 0x77 or n == 0x7F then -- BIT 5/6/7,A
      return true
    end
  end
  if op == 0x28 then -- JR Z
    local rel = mmu:read(pc + 1)
    if rel >= 0x80 then rel = rel - 256 end
    local dest = band(pc + 2 + rel, 0xFFFF)
    local d0 = mmu:read(dest)
    if d0 == 0xDB or d0 == 0xCB or d0 == 0x23 then
      return true
    end
  end
  return false
end

return Crystal
