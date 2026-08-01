-- Reusable Z80 CPU interpreter.
-- Implements documented ops + common undocumented (SLL, IX/IY halves).
-- Memory and I/O go through bus callbacks only; no machine-specific logic.

local bit = require("framework.util.bit")
local band, bor, bxor, bnot, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.bnot, bit.lshift, bit.rshift
local u8, u16, pair = bit.u8, bit.u16, bit.pair

local S, Z, H, P, N, C = 0x80, 0x40, 0x10, 0x04, 0x02, 0x01
local X, Y = 0x08, 0x20

local parity = {}
for i = 0, 255 do
  local n, v = i, 0
  while n > 0 do
    v = v + band(n, 1)
    n = rshift(n, 1)
  end
  parity[i] = (band(v, 1) == 0) and P or 0
end

local Z80 = {}
Z80.__index = Z80

function Z80.new(bus)
  local self = setmetatable({}, Z80)
  -- bus: { read, write, in_port, out_port, irq_pending, ack_irq, im2_vector_lo? }
  self.bus = bus
  self:reset()
  return self
end

function Z80:reset()
  self.af = 0xFFFF
  self.bc = 0xFFFF
  self.de = 0xFFFF
  self.hl = 0xFFFF
  self.ix = 0xFFFF
  self.iy = 0xFFFF
  self.sp = 0xFFFF
  self.pc = 0x0000
  self.af_ = 0xFFFF
  self.bc_ = 0xFFFF
  self.de_ = 0xFFFF
  self.hl_ = 0xFFFF
  self.i = 0
  self.r = 0
  self.im = 0
  self.iff1 = false
  self.iff2 = false
  self.halted = false
  self.ei_delay = false
  self.cycles = 0
end

-- Register accessors
function Z80:a() return rshift(self.af, 8) end
function Z80:f() return band(self.af, 0xFF) end
function Z80:set_a(v) self.af = bor(lshift(u8(v), 8), band(self.af, 0xFF)) end
function Z80:set_f(v) self.af = bor(band(self.af, 0xFF00), u8(v)) end
function Z80:b() return rshift(self.bc, 8) end
function Z80:c() return band(self.bc, 0xFF) end
function Z80:set_b(v) self.bc = bor(lshift(u8(v), 8), band(self.bc, 0xFF)) end
function Z80:set_c(v) self.bc = bor(band(self.bc, 0xFF00), u8(v)) end
function Z80:d() return rshift(self.de, 8) end
function Z80:e() return band(self.de, 0xFF) end
function Z80:set_d(v) self.de = bor(lshift(u8(v), 8), band(self.de, 0xFF)) end
function Z80:set_e(v) self.de = bor(band(self.de, 0xFF00), u8(v)) end
function Z80:h() return rshift(self.hl, 8) end
function Z80:l() return band(self.hl, 0xFF) end
function Z80:set_h(v) self.hl = bor(lshift(u8(v), 8), band(self.hl, 0xFF)) end
function Z80:set_l(v) self.hl = bor(band(self.hl, 0xFF00), u8(v)) end
function Z80:ixh() return rshift(self.ix, 8) end
function Z80:ixl() return band(self.ix, 0xFF) end
function Z80:set_ixh(v) self.ix = bor(lshift(u8(v), 8), band(self.ix, 0xFF)) end
function Z80:set_ixl(v) self.ix = bor(band(self.ix, 0xFF00), u8(v)) end
function Z80:iyh() return rshift(self.iy, 8) end
function Z80:iyl() return band(self.iy, 0xFF) end
function Z80:set_iyh(v) self.iy = bor(lshift(u8(v), 8), band(self.iy, 0xFF)) end
function Z80:set_iyl(v) self.iy = bor(band(self.iy, 0xFF00), u8(v)) end

function Z80:read8(addr) return self.bus.read(band(addr, 0xFFFF)) end
function Z80:write8(addr, v) self.bus.write(band(addr, 0xFFFF), band(v, 0xFF)) end
function Z80:read16(addr)
  addr = band(addr, 0xFFFF)
  local lo = self.bus.read(addr)
  local hi = self.bus.read(band(addr + 1, 0xFFFF))
  return pair(hi, lo)
end
function Z80:write16(addr, v)
  addr = band(addr, 0xFFFF)
  self.bus.write(addr, band(v, 0xFF))
  self.bus.write(band(addr + 1, 0xFFFF), band(rshift(v, 8), 0xFF))
end

function Z80:fetch8()
  local pc = self.pc
  local v = self.bus.read(pc)
  self.pc = band(pc + 1, 0xFFFF)
  return v
end
function Z80:fetch16()
  local pc = self.pc
  local lo = self.bus.read(pc)
  local hi = self.bus.read(band(pc + 1, 0xFFFF))
  self.pc = band(pc + 2, 0xFFFF)
  return pair(hi, lo)
end
function Z80:fetch_disp()
  local d = self:fetch8()
  if d >= 0x80 then
    return d - 256
  end
  return d
end

function Z80:push16(v)
  self.sp = u16(self.sp - 2)
  self:write16(self.sp, v)
end
function Z80:pop16()
  local v = self:read16(self.sp)
  self.sp = u16(self.sp + 2)
  return v
end

function Z80:inc_r()
  -- R increments 7 bits; bit7 preserved
  local r7 = band(self.r, 0x80)
  self.r = bor(r7, band(band(self.r, 0x7F) + 1, 0x7F))
end

-- Flag helpers
local function sz(v)
  v = u8(v)
  local f = band(v, bor(S, X, Y))
  if v == 0 then f = bor(f, Z) end
  return f
end

local function szp(v)
  return bor(sz(v), parity[u8(v)])
end

local function sz53(v)
  return sz(v)
end

function Z80:add8(a, b, carry)
  a, b = u8(a), u8(b)
  carry = carry and 1 or 0
  local res = a + b + carry
  local f = sz53(res)
  if band(res, 0x100) ~= 0 then f = bor(f, C) end
  if band(bxor(a, bxor(b, res)), 0x10) ~= 0 then f = bor(f, H) end
  if band(bxor(a, b), 0x80) == 0 and band(bxor(a, res), 0x80) ~= 0 then f = bor(f, P) end
  self:set_f(f)
  return u8(res)
end

function Z80:sub8(a, b, carry)
  a, b = u8(a), u8(b)
  carry = carry and 1 or 0
  local res = a - b - carry
  local f = bor(sz53(res), N)
  if band(res, 0x100) ~= 0 then f = bor(f, C) end
  if band(bxor(a, bxor(b, res)), 0x10) ~= 0 then f = bor(f, H) end
  if band(bxor(a, b), 0x80) ~= 0 and band(bxor(a, res), 0x80) ~= 0 then f = bor(f, P) end
  self:set_f(f)
  return u8(res)
end

function Z80:and8(a, b)
  local res = band(a, b)
  self:set_f(bor(szp(res), H))
  return res
end

function Z80:xor8(a, b)
  local res = bxor(a, b)
  self:set_f(szp(res))
  return res
end

function Z80:or8(a, b)
  local res = bor(a, b)
  self:set_f(szp(res))
  return res
end

function Z80:cp8(a, b)
  self:sub8(a, b, false)
end

function Z80:inc8(v)
  local res = u8(v + 1)
  local f = band(self:f(), C)
  f = bor(f, sz53(res))
  if band(res, 0x0F) == 0 then f = bor(f, H) end
  if res == 0x80 then f = bor(f, P) end
  self:set_f(f)
  return res
end

function Z80:dec8(v)
  local res = u8(v - 1)
  local f = bor(band(self:f(), C), N)
  f = bor(f, sz53(res))
  if band(res, 0x0F) == 0x0F then f = bor(f, H) end
  if res == 0x7F then f = bor(f, P) end
  self:set_f(f)
  return res
end

function Z80:add16(a, b)
  a, b = u16(a), u16(b)
  local res = a + b
  local f = band(self:f(), bor(S, Z, P))
  if band(res, 0x10000) ~= 0 then f = bor(f, C) end
  if band(bxor(a, bxor(b, res)), 0x1000) ~= 0 then f = bor(f, H) end
  f = bor(f, band(rshift(res, 8), bor(X, Y)))
  self:set_f(f)
  return u16(res)
end

function Z80:adc16(a, b)
  a, b = u16(a), u16(b)
  local carry = band(self:f(), C) ~= 0 and 1 or 0
  local res = a + b + carry
  local f = 0
  if band(res, 0x10000) ~= 0 then f = bor(f, C) end
  if band(bxor(a, bxor(b, res)), 0x1000) ~= 0 then f = bor(f, H) end
  if band(bxor(a, b), 0x8000) == 0 and band(bxor(a, res), 0x8000) ~= 0 then f = bor(f, P) end
  local hi = rshift(u16(res), 8)
  f = bor(f, band(hi, bor(S, X, Y)))
  if u16(res) == 0 then f = bor(f, Z) end
  self:set_f(f)
  return u16(res)
end

function Z80:sbc16(a, b)
  a, b = u16(a), u16(b)
  local carry = band(self:f(), C) ~= 0 and 1 or 0
  local res = a - b - carry
  local f = N
  if band(res, 0x10000) ~= 0 then f = bor(f, C) end
  if band(bxor(a, bxor(b, res)), 0x1000) ~= 0 then f = bor(f, H) end
  if band(bxor(a, b), 0x8000) ~= 0 and band(bxor(a, res), 0x8000) ~= 0 then f = bor(f, P) end
  local hi = rshift(u16(res), 8)
  f = bor(f, band(hi, bor(S, X, Y)))
  if u16(res) == 0 then f = bor(f, Z) end
  self:set_f(f)
  return u16(res)
end

function Z80:rlc8(v, with_a)
  v = u8(v)
  local c = band(v, 0x80) ~= 0
  local res = u8(lshift(v, 1) + (c and 1 or 0))
  local f = with_a and band(self:f(), bor(S, Z, P)) or szp(res)
  if with_a then f = bor(band(f, bnot(bor(H, N, C))), band(res, bor(X, Y))) end
  if not with_a then f = szp(res) end
  if c then f = bor(f, C) end
  if with_a then
    f = band(bor(band(self:f(), bor(S, Z, P)), band(res, bor(X, Y))), bnot(bor(H, N)))
    if c then f = bor(f, C) end
  end
  self:set_f(f)
  return res
end

-- Cleaner rotate/shift helpers
function Z80:op_rlc(v)
  v = u8(v)
  local c = rshift(v, 7)
  local res = u8(lshift(v, 1) + c)
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_rrc(v)
  v = u8(v)
  local c = band(v, 1)
  local res = u8(rshift(v, 1) + lshift(c, 7))
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_rl(v)
  v = u8(v)
  local oldc = band(self:f(), C) ~= 0 and 1 or 0
  local c = rshift(v, 7)
  local res = u8(lshift(v, 1) + oldc)
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_rr(v)
  v = u8(v)
  local oldc = band(self:f(), C) ~= 0 and 1 or 0
  local c = band(v, 1)
  local res = u8(rshift(v, 1) + lshift(oldc, 7))
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_sla(v)
  v = u8(v)
  local c = rshift(v, 7)
  local res = u8(lshift(v, 1))
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_sra(v)
  v = u8(v)
  local c = band(v, 1)
  local res = u8(rshift(v, 1) + band(v, 0x80))
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_sll(v) -- undocumented
  v = u8(v)
  local c = rshift(v, 7)
  local res = u8(lshift(v, 1) + 1)
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_srl(v)
  v = u8(v)
  local c = band(v, 1)
  local res = u8(rshift(v, 1))
  self:set_f(bor(szp(res), c ~= 0 and C or 0))
  return res
end

function Z80:op_rlca()
  local a = self:a()
  local c = rshift(a, 7)
  local res = u8(lshift(a, 1) + c)
  local f = band(self:f(), bor(S, Z, P))
  f = bor(f, band(res, bor(X, Y)))
  if c ~= 0 then f = bor(f, C) end
  self:set_a(res)
  self:set_f(f)
end

function Z80:op_rrca()
  local a = self:a()
  local c = band(a, 1)
  local res = u8(rshift(a, 1) + lshift(c, 7))
  local f = band(self:f(), bor(S, Z, P))
  f = bor(f, band(res, bor(X, Y)))
  if c ~= 0 then f = bor(f, C) end
  self:set_a(res)
  self:set_f(f)
end

function Z80:op_rla()
  local a = self:a()
  local oldc = band(self:f(), C) ~= 0 and 1 or 0
  local c = rshift(a, 7)
  local res = u8(lshift(a, 1) + oldc)
  local f = band(self:f(), bor(S, Z, P))
  f = bor(f, band(res, bor(X, Y)))
  if c ~= 0 then f = bor(f, C) end
  self:set_a(res)
  self:set_f(f)
end

function Z80:op_rra()
  local a = self:a()
  local oldc = band(self:f(), C) ~= 0 and 1 or 0
  local c = band(a, 1)
  local res = u8(rshift(a, 1) + lshift(oldc, 7))
  local f = band(self:f(), bor(S, Z, P))
  f = bor(f, band(res, bor(X, Y)))
  if c ~= 0 then f = bor(f, C) end
  self:set_a(res)
  self:set_f(f)
end

function Z80:daa()
  local a = self:a()
  local f = self:f()
  local corr = 0
  local c = band(f, C) ~= 0
  local h = band(f, H) ~= 0
  local n = band(f, N) ~= 0
  if h or (not n and band(a, 0x0F) > 9) then corr = 0x06 end
  if c or (not n and a > 0x99) then corr = bor(corr, 0x60) end
  if not n then
    a = u8(a + corr)
  else
    a = u8(a - corr)
  end
  local nf = bor(szp(a), band(f, N))
  if corr >= 0x60 then nf = bor(nf, C) end
  if n then
    if h and band(self:a(), 0x0F) < 6 then nf = bor(nf, H) end
  else
    if band(self:a(), 0x0F) > 9 then nf = bor(nf, H) end
  end
  -- Use previous a for H calc more carefully
  local old = self:a()
  self:set_a(a)
  nf = bor(szp(a), band(f, N))
  if c or (not n and old > 0x99) then nf = bor(nf, C) end
  if not n then
    if band(old, 0x0F) > 9 then nf = bor(nf, H) end
  else
    if h and band(old, 0x0F) < 6 then nf = bor(nf, H) end
  end
  self:set_f(nf)
end

function Z80:get_r8(i)
  if i == 0 then return self:b()
  elseif i == 1 then return self:c()
  elseif i == 2 then return self:d()
  elseif i == 3 then return self:e()
  elseif i == 4 then return self:h()
  elseif i == 5 then return self:l()
  elseif i == 6 then return self:read8(self.hl)
  else return self:a() end
end

function Z80:set_r8(i, v)
  if i == 0 then self:set_b(v)
  elseif i == 1 then self:set_c(v)
  elseif i == 2 then self:set_d(v)
  elseif i == 3 then self:set_e(v)
  elseif i == 4 then self:set_h(v)
  elseif i == 5 then self:set_l(v)
  elseif i == 6 then self:write8(self.hl, v)
  else self:set_a(v) end
end

function Z80:get_rp(i)
  if i == 0 then return self.bc
  elseif i == 1 then return self.de
  elseif i == 2 then return self.hl
  else return self.sp end
end

function Z80:set_rp(i, v)
  v = u16(v)
  if i == 0 then self.bc = v
  elseif i == 1 then self.de = v
  elseif i == 2 then self.hl = v
  else self.sp = v end
end

function Z80:get_rp2(i)
  if i == 0 then return self.bc
  elseif i == 1 then return self.de
  elseif i == 2 then return self.hl
  else return self.af end
end

function Z80:set_rp2(i, v)
  v = u16(v)
  if i == 0 then self.bc = v
  elseif i == 1 then self.de = v
  elseif i == 2 then self.hl = v
  else self.af = v end
end

function Z80:cond(cc)
  local f = self:f()
  if cc == 0 then return band(f, Z) == 0
  elseif cc == 1 then return band(f, Z) ~= 0
  elseif cc == 2 then return band(f, C) == 0
  elseif cc == 3 then return band(f, C) ~= 0
  elseif cc == 4 then return band(f, P) == 0
  elseif cc == 5 then return band(f, P) ~= 0
  elseif cc == 6 then return band(f, S) == 0
  else return band(f, S) ~= 0 end
end

function Z80:accept_interrupt()
  if not self.iff1 then
    return 0
  end
  if not self.bus.irq_pending or not self.bus.irq_pending() then
    return 0
  end
  self.halted = false
  self.iff1 = false
  self.iff2 = false
  self:inc_r()
  if self.bus.ack_irq then
    self.bus.ack_irq()
  end
  if self.im == 0 or self.im == 1 then
    self:push16(self.pc)
    self.pc = 0x0038
    return 13
  else -- IM 2
    self:push16(self.pc)
    local lo = self.bus.im2_vector_lo
    if lo == nil then
      lo = 0xFF
    end
    local vec = pair(self.i, band(lo, 0xFF))
    local addr = self:read16(vec)
    self.pc = addr
    return 19
  end
end

function Z80:getRegisters()
  return {
    af = self.af, bc = self.bc, de = self.de, hl = self.hl,
    ix = self.ix, iy = self.iy, sp = self.sp, pc = self.pc,
    af_ = self.af_, bc_ = self.bc_, de_ = self.de_, hl_ = self.hl_,
    i = self.i, r = self.r, im = self.im,
    iff1 = self.iff1, iff2 = self.iff2, halted = self.halted,
  }
end

function Z80:setRegisters(regs)
  if not regs then return end
  for _, k in ipairs({
    "af", "bc", "de", "hl", "ix", "iy", "sp", "pc",
    "af_", "bc_", "de_", "hl_", "i", "r", "im",
  }) do
    if regs[k] ~= nil then
      self[k] = regs[k]
    end
  end
  if regs.iff1 ~= nil then self.iff1 = regs.iff1 end
  if regs.iff2 ~= nil then self.iff2 = regs.iff2 end
  if regs.halted ~= nil then self.halted = regs.halted end
end

-- Prefixed opcode handlers loaded from opcodes module to keep this file manageable
local opcodes = require("cpus.z80.opcodes")

function Z80:step()
  -- EI enables IFF immediately but suppresses IRQ for one instruction.
  if self.ei_delay then
    self.ei_delay = false
  elseif self.iff1 then
    -- Hot path: skip irq_pending() callback when interrupts are disabled.
    local irq_cyc = self:accept_interrupt()
    if irq_cyc > 0 then
      self.cycles = self.cycles + irq_cyc
      return irq_cyc
    end
  end

  if self.halted then
    -- Still need R bump + 4T; IRQ wake checked above when iff1.
    local r = self.r
    self.r = bor(band(r, 0x80), band(band(r, 0x7F) + 1, 0x7F))
    self.cycles = self.cycles + 4
    return 4
  end

  local r = self.r
  self.r = bor(band(r, 0x80), band(band(r, 0x7F) + 1, 0x7F))
  local op = self:fetch8()
  local cyc = opcodes.exec(self, op)
  self.cycles = self.cycles + cyc
  return cyc
end

return Z80
