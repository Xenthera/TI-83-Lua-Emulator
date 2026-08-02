-- Game Boy timer: DIV, TIMA, TMA, TAC (batched tick for CC speed).

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local Timer = {}
Timer.__index = Timer

-- TAC clock select -> bit of DIV that clocks TIMA on falling edge
local TAC_BITS = { [0] = 9, [1] = 3, [2] = 5, [3] = 7 }

function Timer.new(irq)
  return setmetatable({
    irq = irq,
    div = 0,
    tima = 0,
    tma = 0,
    tac = 0,
    overflow_delay = -1,
  }, Timer)
end

function Timer:reset()
  self.div = 0
  self.tima = 0
  self.tma = 0
  self.tac = 0
  self.overflow_delay = -1
end

function Timer:read(reg)
  if reg == 0xFF04 then return rshift(self.div, 8)
  elseif reg == 0xFF05 then return self.tima
  elseif reg == 0xFF06 then return self.tma
  elseif reg == 0xFF07 then return bor(self.tac, 0xF8)
  end
  return 0xFF
end

function Timer:write(reg, v)
  v = v % 256
  if reg == 0xFF04 then
    self:_set_div(0)
  elseif reg == 0xFF05 then
    self.tima = v
    self.overflow_delay = -1
  elseif reg == 0xFF06 then
    self.tma = v
  elseif reg == 0xFF07 then
    local old_bit = self:_timer_bit()
    local old_en = band(self.tac, 4) ~= 0
    self.tac = band(v, 7)
    local new_bit = self:_timer_bit()
    if old_en and old_bit and not new_bit then
      self:_inc_tima()
    end
  end
end

function Timer:_timer_bit()
  if band(self.tac, 4) == 0 then return false end
  local bitn = TAC_BITS[band(self.tac, 3)] or 9
  return band(rshift(self.div, bitn), 1) ~= 0
end

function Timer:_set_div(v)
  local old_bit = self:_timer_bit()
  self.div = v
  if old_bit and not self:_timer_bit() then
    self:_inc_tima()
  end
end

function Timer:_inc_tima()
  local t = self.tima + 1
  if t > 0xFF then
    self.tima = self.tma
    self.irq:request(0x04)
  else
    self.tima = t
  end
end

--- Advance timer by T-cycles (O(overflows), not O(cycles)).
function Timer:tick(cycles)
  if cycles <= 0 then return end
  if band(self.tac, 4) == 0 then
    -- DIV-only: pure add (no falling-edge TIMA). Mod 65536 without bit wrapper.
    self.div = (self.div + cycles) % 65536
    return
  end
  local bitn = TAC_BITS[band(self.tac, 3)] or 9
  local period = lshift(1, bitn + 1) -- cycles between falling edges
  local pmask = period - 1
  local left = cycles
  local div = self.div
  -- Large ticks: jump whole TIMA increments when possible.
  while left > 0 do
    local phase = div % (pmask + 1)
    local to_edge = period - phase
    if to_edge <= 0 then to_edge = period end
    if left >= to_edge then
      div = (div + to_edge) % 65536
      left = left - to_edge
      self.div = div
      self:_inc_tima()
      div = self.div
    else
      self.div = (div + left) % 65536
      return
    end
  end
  self.div = div
end

return Timer
