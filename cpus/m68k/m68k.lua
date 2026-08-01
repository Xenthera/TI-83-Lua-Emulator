-- Reusable Motorola 68000 CPU core.
-- Memory only via bus callbacks; no calculator-specific logic.
-- Timing is approximate (not cycle-perfect).

local bit = require("framework.util.bit")
local EA = require("cpus.m68k.ea")
local band, bor, bxor, bnot, lshift, rshift =
  bit.band, bit.bor, bit.bxor, bit.bnot, bit.lshift, bit.rshift

local SR_C, SR_V, SR_Z, SR_N, SR_X = 0x01, 0x02, 0x04, 0x08, 0x10
local SR_I = 0x0700
local SR_S = 0x2000
local SR_T = 0x8000

local M68K = {}
M68K.__index = M68K
M68K.SR_C, M68K.SR_V, M68K.SR_Z, M68K.SR_N, M68K.SR_X = SR_C, SR_V, SR_Z, SR_N, SR_X
M68K.SR_S, M68K.SR_T = SR_S, SR_T

function M68K.new(bus)
  local self = setmetatable({}, M68K)
  self.bus = bus or {}
  self.d = { 0, 0, 0, 0, 0, 0, 0, 0 } -- 0-based indices via [0]..[7]
  for i = 0, 7 do self.d[i] = 0 end
  self.a = {}
  for i = 0, 7 do self.a[i] = 0 end
  self.usp = 0
  self.ssp = 0
  self.pc = 0
  self.sr = SR_S -- supervisor after reset
  self.stopped = false
  self.halted = false
  self.cycles = 0
  self.irq_level = 0
  -- When set (TI $600005 sleep), the next accepted IRQ bypasses the IPL mask.
  self.sleep_unmask = false
  self:reset()
  return self
end

function M68K:get_a(i)
  if i == 7 then
    if band(self.sr, SR_S) ~= 0 then return self.ssp else return self.usp end
  end
  return self.a[i]
end

function M68K:set_a(i, v)
  v = band(v, 0xFFFFFFFF)
  if i == 7 then
    if band(self.sr, SR_S) ~= 0 then self.ssp = v else self.usp = v end
  else
    self.a[i] = v
  end
end

function M68K:read8(addr)
  local a = band(addr or 0, 0xFFFFFFFF)
  return band(self.bus.read8(a) or 0, 0xFF)
end

function M68K:write8(addr, v)
  self.bus.write8(band(addr, 0xFFFFFFFF), band(v, 0xFF))
end

function M68K:read16(addr)
  addr = band(addr, 0xFFFFFFFF)
  if self.bus.read16 then
    return band(self.bus.read16(addr), 0xFFFF)
  end
  local hi = self:read8(addr)
  local lo = self:read8(band(addr + 1, 0xFFFFFFFF))
  return bor(lshift(hi, 8), lo)
end

function M68K:write16(addr, v)
  addr = band(addr, 0xFFFFFFFF)
  v = band(v, 0xFFFF)
  if self.bus.write16 then
    self.bus.write16(addr, v)
    return
  end
  self:write8(addr, rshift(v, 8))
  self:write8(band(addr + 1, 0xFFFFFFFF), band(v, 0xFF))
end

function M68K:read32(addr)
  addr = band(addr, 0xFFFFFFFF)
  if self.bus.read32 then
    return band(self.bus.read32(addr), 0xFFFFFFFF)
  end
  local hi = self:read16(addr)
  local lo = self:read16(band(addr + 2, 0xFFFFFFFF))
  return bor(lshift(hi, 16), lo)
end

function M68K:write32(addr, v)
  addr = band(addr, 0xFFFFFFFF)
  v = band(v, 0xFFFFFFFF)
  if self.bus.write32 then
    self.bus.write32(addr, v)
    return
  end
  self:write16(addr, rshift(v, 16))
  self:write16(band(addr + 2, 0xFFFFFFFF), band(v, 0xFFFF))
end

function M68K:fetch16()
  local pc = self.pc
  local bus = self.bus
  local v
  if bus.read16 then
    v = bus.read16(pc)
  else
    v = self:read16(pc)
  end
  self.pc = pc + 2
  return v
end

function M68K:fetch32()
  local pc = self.pc
  local bus = self.bus
  local hi, lo
  if bus.read16 then
    hi = bus.read16(pc)
    lo = bus.read16(pc + 2)
  else
    hi = self:read16(pc)
    lo = self:read16(pc + 2)
  end
  self.pc = pc + 4
  return hi * 65536 + lo
end

function M68K:reset()
  self.stopped = false
  self.halted = false
  self.irq_level = 0
  self.sr = SR_S
  self.ssp = self:read32(0)
  self.pc = self:read32(4)
  self.usp = 0
  for i = 0, 6 do
    self.d[i] = 0
    self.a[i] = 0
  end
  self.d[7] = 0
  self.cycles = 0
end

function M68K:supervisor()
  return band(self.sr, SR_S) ~= 0
end

function M68K:set_sr(v, force)
  v = band(v, 0xA71F) -- implemented bits
  local old_s = band(self.sr, SR_S) ~= 0
  local new_s = band(v, SR_S) ~= 0
  if not force and not old_s and new_s == false and false then
    -- privilege: already in user
  end
  if old_s and not new_s then
    -- leaving supervisor: ssp already in ssp field
  elseif not old_s and new_s then
    -- entering supervisor
  end
  self.sr = v
end

function M68K:push16(v)
  local sp = band(self:get_a(7) - 2, 0xFFFFFFFF)
  self:set_a(7, sp)
  self:write16(sp, v)
end

function M68K:push32(v)
  local sp = band(self:get_a(7) - 4, 0xFFFFFFFF)
  self:set_a(7, sp)
  self:write32(sp, v)
end

function M68K:pop16()
  local sp = self:get_a(7)
  local v = self:read16(sp)
  self:set_a(7, band(sp + 2, 0xFFFFFFFF))
  return v
end

function M68K:pop32()
  local sp = self:get_a(7)
  local v = self:read32(sp)
  self:set_a(7, band(sp + 4, 0xFFFFFFFF))
  return v
end

function M68K:set_nz(v, size)
  local m = EA.mask(size)
  v = band(v, m)
  if v == 0 then self.sr = bor(self.sr, SR_Z) else self.sr = band(self.sr, bnot(SR_Z)) end
  local nbit = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  if band(v, nbit) ~= 0 then self.sr = bor(self.sr, SR_N) else self.sr = band(self.sr, bnot(SR_N)) end
  self.sr = band(self.sr, bnot(SR_V))
end

function M68K:raise_exception(vector)
  local old_sr = self.sr
  -- Enter supervisor
  if band(self.sr, SR_S) == 0 then
    self.usp = self:get_a(7)
    self.sr = bor(self.sr, SR_S)
  end
  self.sr = band(self.sr, bnot(SR_T))
  self:push32(self.pc)
  self:push16(old_sr)
  local addr = self:read32(vector * 4)
  self.pc = addr
  self.stopped = false
end

--- Deliver autovector IRQ. Returns true if accepted, false if masked.
function M68K:interrupt(level)
  level = band(level or 0, 7)
  self.irq_level = level
  if level == 0 then return false end
  local mask = rshift(band(self.sr, SR_I), 8)
  -- $600005 hardware sleep wakes on masked auto-ints even at IPL 7.
  if not self.sleep_unmask and level <= mask and level ~= 7 then
    return false
  end
  self.sleep_unmask = false
  -- Autovector
  local old_sr = self.sr
  if band(self.sr, SR_S) == 0 then
    -- A7 is USP while in user mode (stored in self.usp). Do not touch
    -- self.a[7]: it is unused, and in Lua `0 or x` yields 0 (0 is truthy),
    -- which previously wiped USP on every user-mode IRQ.
    self.sr = bor(self.sr, SR_S)
  end
  self.sr = band(self.sr, bnot(SR_T))
  self.sr = bor(band(self.sr, bnot(SR_I)), lshift(level, 8))
  self:push32(self.pc)
  self:push16(old_sr)
  self.pc = self:read32((24 + level) * 4)
  self.stopped = false
  self.irq_level = 0
  return true
end

function M68K:getRegisters()
  local a = {}
  for i = 0, 7 do a[i] = self:get_a(i) end
  local d = {}
  for i = 0, 7 do d[i] = self.d[i] end
  return {
    d = d, a = a, pc = self.pc, sr = self.sr,
    usp = self.usp, ssp = self.ssp,
    stopped = self.stopped, halted = self.halted,
  }
end

function M68K:setRegisters(regs)
  if not regs then return end
  if regs.d then for i = 0, 7 do if regs.d[i] then self.d[i] = band(regs.d[i], 0xFFFFFFFF) end end end
  if regs.pc then self.pc = band(regs.pc, 0xFFFFFFFF) end
  if regs.sr then self.sr = band(regs.sr, 0xFFFF) end
  if regs.usp then self.usp = band(regs.usp, 0xFFFFFFFF) end
  if regs.ssp then self.ssp = band(regs.ssp, 0xFFFFFFFF) end
  if regs.a then
    for i = 0, 6 do if regs.a[i] then self.a[i] = band(regs.a[i], 0xFFFFFFFF) end end
    if regs.a[7] then self:set_a(7, regs.a[7]) end
  end
end

-- Forward-declare ops module (loaded after helpers)
local ops

function M68K:step()
  if self.halted then
    return 4
  end
  if self.stopped then
    if self.irq_level > 0 then
      self:interrupt(self.irq_level)
    else
      return 4
    end
  end
  local bus = self.bus
  local pc = self.pc
  -- Hot path: AMS code in Titanium flash below the archive cutoff.
  if pc >= 0x800000 and pc < 0xC00000 then
    local classic = 0x200000 + (pc - 0x800000)
    if classic >= (bus.flash_exec_first or 0x390000) then
      self:raise_exception(2)
      self.cycles = self.cycles + 50
      return 50
    end
  elseif bus.exec_allowed and not bus:exec_allowed(pc) then
    self:raise_exception(2) -- bus error
    self.cycles = self.cycles + 50
    return 50
  end
  local op = bus.read16 and bus.read16(pc) or self:read16(pc)
  self.pc = pc + 2
  local cyc = ops.execute(self, op) or 4
  self.cycles = self.cycles + cyc
  return cyc
end

ops = require("cpus.m68k.ops")
return M68K
