-- Hardware timers (WikiTI 83Plus:Ports:04). Periods track current CPU Hz
-- so wall-clock IRQ rates stay correct at 6/15 MHz (port 20).

local Timer = {}
Timer.__index = Timer

local FREQ1 = {
  [0] = 560,
  [1] = 248,
  [2] = 170,
  [3] = 118,
}

local function period_for(cpu_hz, hz)
  return math.floor(cpu_hz / hz + 0.5)
end

function Timer.new(cpu_hz)
  local self = setmetatable({}, Timer)
  self.cpu_hz = cpu_hz or 15000000
  self.counter1 = 0
  self.counter2 = 0
  self.speed = 1
  self.period1 = period_for(self.cpu_hz, FREQ1[1])
  self.period2 = period_for(self.cpu_hz, FREQ1[1] * 2)
  self.pending1 = false
  self.pending2 = false
  return self
end

function Timer:set_cpu_hz(hz)
  self.cpu_hz = hz or self.cpu_hz
  self:set_speed(self.speed)
end

function Timer:reset()
  self.counter1 = 0
  self.counter2 = 0
  self.speed = 1
  self.period1 = period_for(self.cpu_hz, FREQ1[1])
  self.period2 = period_for(self.cpu_hz, FREQ1[1] * 2)
  self.pending1 = false
  self.pending2 = false
end

function Timer:set_speed(speed)
  self.speed = speed % 4
  local f1 = FREQ1[self.speed] or FREQ1[1]
  self.period1 = period_for(self.cpu_hz, f1)
  self.period2 = period_for(self.cpu_hz, f1 * 2)
end

function Timer:tick(cycles)
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
