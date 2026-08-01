-- Hardware timers that generate TI-OS interrupts (WikiTI 83Plus:Ports:04).

local Timer = {}
Timer.__index = Timer

-- TI-83+ first-timer frequencies (Hz) for port 04 bits 1-2.
-- Second timer runs at 2x. CPU assumed 6 MHz for period conversion.
local CPU_HZ = 6000000
local FREQ1 = {
  [0] = 560,
  [1] = 248,
  [2] = 170,
  [3] = 118,
}

local function period_for(hz)
  return math.floor(CPU_HZ / hz + 0.5)
end

function Timer.new()
  local self = setmetatable({}, Timer)
  self.counter1 = 0
  self.counter2 = 0
  self.speed = 1
  self.period1 = period_for(FREQ1[1])
  self.period2 = period_for(FREQ1[1] * 2)
  self.pending1 = false
  self.pending2 = false
  return self
end

function Timer:reset()
  self.counter1 = 0
  self.counter2 = 0
  self.speed = 1
  self.period1 = period_for(FREQ1[1])
  self.period2 = period_for(FREQ1[1] * 2)
  self.pending1 = false
  self.pending2 = false
end

function Timer:set_speed(speed)
  self.speed = speed % 4
  local f1 = FREQ1[self.speed] or FREQ1[1]
  self.period1 = period_for(f1)
  self.period2 = period_for(f1 * 2)
end

function Timer:tick(cycles)
  -- Single-instruction ticks are << period; keep a while for large jumps.
  local c1 = self.counter1 + cycles
  local p1 = self.period1
  if c1 >= p1 then
    repeat
      c1 = c1 - p1
      self.pending1 = true
    until c1 < p1
  end
  self.counter1 = c1

  local c2 = self.counter2 + cycles
  local p2 = self.period2
  if c2 >= p2 then
    repeat
      c2 = c2 - p2
      self.pending2 = true
    until c2 < p2
  end
  self.counter2 = c2
end

--- Back-compat: true if either timer is pending.
function Timer:irq_pending()
  return self.pending1 or self.pending2
end

function Timer:ack()
  self.pending1 = false
  self.pending2 = false
end

function Timer:ack1()
  self.pending1 = false
end

function Timer:ack2()
  self.pending2 = false
end

return Timer
