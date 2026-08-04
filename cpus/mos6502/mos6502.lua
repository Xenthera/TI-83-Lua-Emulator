-- MOS 6502 / Ricoh 2A03 CPU (NES: no decimal mode).
-- Bus: { read(addr), write(addr, v), tick(cpu_cycles) optional }

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local u8, u16 = bit.u8, bit.u16

local C, Z, I, D, B, U, V, N = 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

local CPU = {}
CPU.__index = CPU
CPU.FLAG_C, CPU.FLAG_Z, CPU.FLAG_I, CPU.FLAG_D = C, Z, I, D
CPU.FLAG_B, CPU.FLAG_V, CPU.FLAG_N = B, V, N

function CPU.new(bus)
  local self = setmetatable({ bus = bus }, CPU)
  self:reset_regs()
  return self
end

function CPU:reset_regs()
  self.a, self.x, self.y = 0, 0, 0
  self.sp = 0xFD
  self.pc = 0
  self.p = bor(I, U)
  self.cycles = 0
  self.stall = 0
  self.nmi = false
  self.irq = false
  self.apu_irq = false
  self.mapper_irq = false
  self.nmi_edge = false
  self.nmi_defer_once = false
  self._cy = 0 -- cycles so far in current step()
end

--- Power-on / RESET: read vector at $FFFC.
function CPU:power_on()
  self:reset_regs()
  -- Vector read without mid-instruction accounting (cold start).
  local lo = self.bus.read(0xFFFC)
  local hi = self.bus.read(0xFFFD)
  self.pc = bor(lo, lshift(hi, 8))
end

--- Advance 1 CPU cycle (PPU/APU via bus.tick). Used for bus ops + internals.
function CPU:tick1()
  self._mid_ticks = (self._mid_ticks or 0) + 1
  self.cycles = self.cycles + 1
  local t = self.bus.tick
  if t then t(1) end
end

--- Finish instruction: pad any internal cycles not covered by bus accesses.
function CPU:_done(total)
  local mid = self._mid_ticks or 0
  self._mid_ticks = 0
  if mid < total then
    local n = total - mid
    self.cycles = self.cycles + n
    local t = self.bus.tick
    if t then t(n) end
  elseif mid > total then
    total = mid
  end
  return total
end

function CPU:read(addr)
  -- Sample at cycle start, then advance PPU/APU (tick-after).
  local v = self.bus.read(band(addr, 0xFFFF))
  self:tick1()
  return v
end

function CPU:write(addr, v)
  self.bus.write(band(addr, 0xFFFF), band(v, 0xFF))
  self:tick1()
end

function CPU:read16(addr)
  local lo = self:read(addr)
  local hi = self:read(band(addr + 1, 0xFFFF))
  return bor(lo, lshift(hi, 8))
end

-- JMP ($xxFF) bug: high byte from $xx00, not $xx+1.
function CPU:read16_bug(addr)
  local lo = self:read(addr)
  local hi_addr = bor(band(addr, 0xFF00), band(addr + 1, 0xFF))
  local hi = self:read(hi_addr)
  return bor(lo, lshift(hi, 8))
end

function CPU:push(v)
  self:write(0x100 + self.sp, v)
  self.sp = band(self.sp - 1, 0xFF)
end

function CPU:pull()
  self.sp = band(self.sp + 1, 0xFF)
  return self:read(0x100 + self.sp)
end

function CPU:push16(v)
  self:push(rshift(v, 8))
  self:push(band(v, 0xFF))
end

function CPU:pull16()
  local lo = self:pull()
  local hi = self:pull()
  return bor(lo, lshift(hi, 8))
end

function CPU:set_zn(v)
  v = band(v, 0xFF)
  local p = band(self.p, bxor(0xFF, bor(Z, N)))
  if v == 0 then p = bor(p, Z) end
  if band(v, 0x80) ~= 0 then p = bor(p, N) end
  self.p = p
  return v
end

function CPU:flag(mask)
  return band(self.p, mask) ~= 0
end

function CPU:set_flag(mask, on)
  if on then
    self.p = bor(self.p, mask)
  else
    self.p = band(self.p, bxor(0xFF, mask))
  end
end

function CPU:page_crossed(a, b)
  return band(a, 0xFF00) ~= band(b, 0xFF00)
end

-- Addressing helpers. `mode`: nil/"read" = page-cross dummy only when needed;
-- "write"/"rmw" = always perform the uncorrected dummy read.
function CPU:addr_imm()
  local a = self.pc
  self.pc = band(self.pc + 1, 0xFFFF)
  return a, 0
end

function CPU:addr_zp()
  local a = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  return a, 0
end

function CPU:addr_zpx()
  local zp = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  self:read(zp) -- dummy
  return band(zp + self.x, 0xFF), 0
end

function CPU:addr_zpy()
  local zp = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  self:read(zp) -- dummy
  return band(zp + self.y, 0xFF), 0
end

function CPU:addr_abs()
  local a = self:read16(self.pc)
  self.pc = band(self.pc + 2, 0xFFFF)
  return a, 0
end

--- mode: nil = read (dummy only on page cross if check);
--- "write"/"rmw" = always dummy-read uncorrected address.
--- Also returns extra=1 when a page-cross dummy was NOT done but cycle
--- still needed (shouldn't happen). Kept for call-site compat.
function CPU:addr_abx(check, mode)
  local lo = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local hi = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local base = bor(lo, lshift(hi, 8))
  local a = band(base + self.x, 0xFFFF)
  local crossed = self:page_crossed(base, a)
  if mode == "write" or mode == "rmw" or (check and crossed) then
    self:read(bor(lshift(hi, 8), band(base + self.x, 0xFF)))
  elseif check and not crossed then
    -- no extra
  end
  return a, 0
end

function CPU:addr_aby(check, mode)
  local lo = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local hi = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local base = bor(lo, lshift(hi, 8))
  local a = band(base + self.y, 0xFFFF)
  local crossed = self:page_crossed(base, a)
  if mode == "write" or mode == "rmw" or (check and crossed) then
    self:read(bor(lshift(hi, 8), band(base + self.y, 0xFF)))
  end
  return a, 0
end

function CPU:addr_indx()
  local ptr = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  self:read(ptr) -- dummy while adding X
  ptr = band(ptr + self.x, 0xFF)
  local lo = self:read(ptr)
  local hi = self:read(band(ptr + 1, 0xFF))
  return bor(lo, lshift(hi, 8)), 0
end

function CPU:addr_indy(check, mode)
  local ptr = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local lo = self:read(ptr)
  local hi = self:read(band(ptr + 1, 0xFF))
  local base = bor(lo, lshift(hi, 8))
  local a = band(base + self.y, 0xFFFF)
  local crossed = self:page_crossed(base, a)
  if mode == "write" or mode == "rmw" or (check and crossed) then
    self:read(bor(lshift(hi, 8), band(base + self.y, 0xFF)))
  end
  return a, 0
end

function CPU:branch(cond)
  local off = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  local total = 2
  if cond then
    if off >= 0x80 then off = off - 256 end
    local from = self.pc
    local target = band(from + off, 0xFFFF)
    -- Taken: dummy fetch at PC, then extra dummy on page cross.
    self:read(from)
    total = 3
    if self:page_crossed(from, target) then
      self:read(target)
      total = 4
    end
    self.pc = target
  end
  return self:_done(total)
end

local function adc(cpu, v)
  local a = cpu.a
  local c = cpu:flag(C) and 1 or 0
  local sum = a + v + c
  cpu:set_flag(C, sum > 0xFF)
  -- V = (A^sum) & (M^sum) & 0x80  (nested band for 2-arg bit libs)
  cpu:set_flag(V, band(band(bxor(a, sum), bxor(v, sum)), 0x80) ~= 0)
  cpu.a = cpu:set_zn(sum)
end

local function sbc(cpu, v)
  adc(cpu, bxor(v, 0xFF))
end

local function cmp(cpu, reg, v)
  local t = reg - v
  cpu:set_flag(C, reg >= v)
  cpu:set_zn(t)
end

local function asl_v(cpu, v)
  cpu:set_flag(C, band(v, 0x80) ~= 0)
  return cpu:set_zn(lshift(v, 1))
end

local function lsr_v(cpu, v)
  cpu:set_flag(C, band(v, 1) ~= 0)
  return cpu:set_zn(rshift(v, 1))
end

local function rol_v(cpu, v)
  local c = cpu:flag(C) and 1 or 0
  cpu:set_flag(C, band(v, 0x80) ~= 0)
  return cpu:set_zn(bor(lshift(v, 1), c))
end

local function ror_v(cpu, v)
  local c = cpu:flag(C) and 0x80 or 0
  cpu:set_flag(C, band(v, 1) ~= 0)
  return cpu:set_zn(bor(rshift(v, 1), c))
end

local function bit_op(cpu, v)
  cpu:set_flag(Z, band(cpu.a, v) == 0)
  cpu:set_flag(V, band(v, 0x40) ~= 0)
  cpu:set_flag(N, band(v, 0x80) ~= 0)
end

local function dec_v(cpu, v)
  return cpu:set_zn(v - 1)
end

local function inc_v(cpu, v)
  return cpu:set_zn(v + 1)
end

-- Hoisted helpers (module-level) so _exec does not allocate closures per insn.
local function lda(cpu, addr, base)
  cpu.a = cpu:set_zn(cpu:read(addr))
  return cpu:_done(base)
end
local function ldx(cpu, addr, base)
  cpu.x = cpu:set_zn(cpu:read(addr))
  return cpu:_done(base)
end
local function ldy(cpu, addr, base)
  cpu.y = cpu:set_zn(cpu:read(addr))
  return cpu:_done(base)
end
local function sta(cpu, addr, base)
  cpu:write(addr, cpu.a)
  return cpu:_done(base)
end
local function stx(cpu, addr, base)
  cpu:write(addr, cpu.x)
  return cpu:_done(base)
end
local function sty(cpu, addr, base)
  cpu:write(addr, cpu.y)
  return cpu:_done(base)
end
local function rmw(cpu, addr, fn, base)
  local v = cpu:read(addr)
  cpu:write(addr, v)
  v = fn(cpu, v)
  cpu:write(addr, v)
  return cpu:_done(base)
end
-- Implied ops: unused fetch at PC (visible when executing from PPU I/O).
local function imp(cpu)
  cpu:read(cpu.pc)
end

local function slo(cpu, addr, base, extra)
  local v = cpu:read(addr)
  cpu:write(addr, v)
  v = asl_v(cpu, v)
  cpu:write(addr, v)
  cpu.a = cpu:set_zn(bor(cpu.a, v))
  return cpu:_done(base + (extra or 0))
end
local function rla(cpu, addr, base, extra)
  local v = cpu:read(addr)
  cpu:write(addr, v)
  v = rol_v(cpu, v)
  cpu:write(addr, v)
  cpu.a = cpu:set_zn(band(cpu.a, v))
  return cpu:_done(base + (extra or 0))
end
local function sre(cpu, addr, base, extra)
  local v = cpu:read(addr)
  cpu:write(addr, v)
  v = lsr_v(cpu, v)
  cpu:write(addr, v)
  cpu.a = cpu:set_zn(bxor(cpu.a, v))
  return cpu:_done(base + (extra or 0))
end
local function rra(cpu, addr, base, extra)
  local v = cpu:read(addr)
  cpu:write(addr, v)
  v = ror_v(cpu, v)
  cpu:write(addr, v)
  adc(cpu, v)
  return cpu:_done(base + (extra or 0))
end
local function sax(cpu, addr, base)
  cpu:write(addr, band(cpu.a, cpu.x))
  return cpu:_done(base)
end
local function lax(cpu, addr, base, extra)
  local v = cpu:read(addr)
  cpu.a = cpu:set_zn(v)
  cpu.x = v
  return cpu:_done(base + (extra or 0))
end
local function dcp(cpu, addr, base, extra)
  local old = cpu:read(addr)
  cpu:write(addr, old)
  local v = band(old - 1, 0xFF)
  cpu:write(addr, v)
  cmp(cpu, cpu.a, v)
  return cpu:_done(base + (extra or 0))
end
local function isc(cpu, addr, base, extra)
  local old = cpu:read(addr)
  cpu:write(addr, old)
  local v = band(old + 1, 0xFF)
  cpu:write(addr, v)
  sbc(cpu, v)
  return cpu:_done(base + (extra or 0))
end

--- Execute one instruction (or NMI/IRQ). Returns CPU cycles consumed.
function CPU:step()
  self._mid_ticks = 0

  -- Catch up PPU/APU before interrupt poll (MMC3 IRQ, delayed NMI).
  local flush = self.bus.flush
  if flush then flush() end

  if self.stall > 0 then
    local n = self.stall
    self.stall = 0
    self.cycles = self.cycles + n
    local t = self.bus.tick
    if t then t(n) end
    if flush then flush() end
    return n
  end

  if self.nmi_edge then
    if self.nmi_defer_once then
      -- Skip taking NMI for one instruction (see PPU $2000 enable path).
      self.nmi_defer_once = false
    else
      self.nmi_edge = false
      self.nmi = false
      self:push16(self.pc)
      -- Interrupt pushes: B clear, U set.
      self:push(bor(band(self.p, bxor(0xFF, B)), U))
      self:set_flag(I, true)
      self.pc = self:read16(0xFFFA)
      return self:_done(7)
    end
  end

  if self.irq and not self:flag(I) then
    self:push16(self.pc)
    self:push(bor(band(self.p, bxor(0xFF, B)), U))
    self:set_flag(I, true)
    self.pc = self:read16(0xFFFE)
    return self:_done(7)
  end

  local op = self:read(self.pc)
  self.pc = band(self.pc + 1, 0xFFFF)
  return self:_exec(op)
end

function CPU:trigger_nmi()
  self.nmi_edge = true
  self.nmi = true
end

function CPU:oam_dma_stall()
  -- 513 or 514 cycles; approximate 513 + (odd frame)
  self.stall = self.stall + 513
end

-- Opcode implementation (returns cycles including extras).
function CPU:_exec(op)
  -- Official opcodes (illegal ops treated as NOP-ish for homebrew safety)
  if op == 0x00 then -- BRK
    imp(self) -- signature byte
    self.pc = band(self.pc + 1, 0xFFFF)
    self:push16(self.pc)
    self:push(bor(self.p, B, U))
    self:set_flag(I, true)
    self.pc = self:read16(0xFFFE)
    return self:_done(7)
  elseif op == 0x01 then local addr = self:addr_indx(); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(6)
  elseif op == 0x05 then local addr = self:addr_zp(); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(3)
  elseif op == 0x06 then local addr = self:addr_zp(); return rmw(self, addr, asl_v, 5)
  elseif op == 0x08 then imp(self); self:push(bor(self.p, B, U)); return self:_done(3) -- PHP
  elseif op == 0x09 then local addr = self:addr_imm(); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(2)
  elseif op == 0x0A then imp(self); self.a = asl_v(self, self.a); return self:_done(2)
  elseif op == 0x0D then local addr = self:addr_abs(); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x0E then local addr = self:addr_abs(); return rmw(self, addr, asl_v, 6)
  elseif op == 0x10 then return self:branch(not self:flag(N)) -- BPL
  elseif op == 0x11 then local addr, e = self:addr_indy(true); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(5)
  elseif op == 0x15 then local addr = self:addr_zpx(); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x16 then local addr = self:addr_zpx(); return rmw(self, addr, asl_v, 6)
  elseif op == 0x18 then imp(self); self:set_flag(C, false); return self:_done(2) -- CLC
  elseif op == 0x19 then local addr, e = self:addr_aby(true); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x1D then local addr, e = self:addr_abx(true); self.a = self:set_zn(bor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x1E then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, asl_v, 7)
  elseif op == 0x20 then -- JSR
    local target = self:read16(self.pc)
    self:push16(band(self.pc + 1, 0xFFFF))
    self.pc = target
    return self:_done(6)
  elseif op == 0x21 then local addr = self:addr_indx(); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(6)
  elseif op == 0x24 then local addr = self:addr_zp(); bit_op(self, self:read(addr)); return self:_done(3)
  elseif op == 0x25 then local addr = self:addr_zp(); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(3)
  elseif op == 0x26 then local addr = self:addr_zp(); return rmw(self, addr, rol_v, 5)
  elseif op == 0x28 then -- PLP
    imp(self)
    self.p = bor(band(self:pull(), bxor(0xFF, B)), U)
    return self:_done(4)
  elseif op == 0x29 then local addr = self:addr_imm(); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(2)
  elseif op == 0x2A then imp(self); self.a = rol_v(self, self.a); return self:_done(2)
  elseif op == 0x2C then local addr = self:addr_abs(); bit_op(self, self:read(addr)); return self:_done(4)
  elseif op == 0x2D then local addr = self:addr_abs(); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x2E then local addr = self:addr_abs(); return rmw(self, addr, rol_v, 6)
  elseif op == 0x30 then return self:branch(self:flag(N)) -- BMI
  elseif op == 0x31 then local addr, e = self:addr_indy(true); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(5)
  elseif op == 0x35 then local addr = self:addr_zpx(); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x36 then local addr = self:addr_zpx(); return rmw(self, addr, rol_v, 6)
  elseif op == 0x38 then imp(self); self:set_flag(C, true); return self:_done(2) -- SEC
  elseif op == 0x39 then local addr, e = self:addr_aby(true); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x3D then local addr, e = self:addr_abx(true); self.a = self:set_zn(band(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x3E then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, rol_v, 7)
  elseif op == 0x40 then -- RTI
    imp(self)
    self.p = bor(band(self:pull(), bxor(0xFF, B)), U)
    self.pc = self:pull16()
    return self:_done(6)
  elseif op == 0x41 then local addr = self:addr_indx(); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(6)
  elseif op == 0x45 then local addr = self:addr_zp(); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(3)
  elseif op == 0x46 then local addr = self:addr_zp(); return rmw(self, addr, lsr_v, 5)
  elseif op == 0x48 then imp(self); self:push(self.a); return self:_done(3) -- PHA
  elseif op == 0x49 then local addr = self:addr_imm(); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(2)
  elseif op == 0x4A then imp(self); self.a = lsr_v(self, self.a); return self:_done(2)
  elseif op == 0x4C then self.pc = self:read16(self.pc); return self:_done(3) -- JMP abs
  elseif op == 0x4D then local addr = self:addr_abs(); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x4E then local addr = self:addr_abs(); return rmw(self, addr, lsr_v, 6)
  elseif op == 0x50 then return self:branch(not self:flag(V)) -- BVC
  elseif op == 0x51 then local addr, e = self:addr_indy(true); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(5)
  elseif op == 0x55 then local addr = self:addr_zpx(); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x56 then local addr = self:addr_zpx(); return rmw(self, addr, lsr_v, 6)
  elseif op == 0x58 then imp(self); self:set_flag(I, false); return self:_done(2) -- CLI
  elseif op == 0x59 then local addr, e = self:addr_aby(true); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x5D then local addr, e = self:addr_abx(true); self.a = self:set_zn(bxor(self.a, self:read(addr))); return self:_done(4)
  elseif op == 0x5E then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, lsr_v, 7)
  elseif op == 0x60 then -- RTS
    imp(self) -- unused fetch of following byte (resets PPU $2002 latch when at $2001)
    local addr = self:pull16()
    self:read(addr) -- dummy fetch at pulled address
    self.pc = band(addr + 1, 0xFFFF)
    return self:_done(6)

  elseif op == 0x61 then local addr = self:addr_indx(); adc(self, self:read(addr)); return self:_done(6)
  elseif op == 0x65 then local addr = self:addr_zp(); adc(self, self:read(addr)); return self:_done(3)
  elseif op == 0x66 then local addr = self:addr_zp(); return rmw(self, addr, ror_v, 5)
  elseif op == 0x68 then imp(self); self.a = self:set_zn(self:pull()); return self:_done(4) -- PLA
  elseif op == 0x69 then local addr = self:addr_imm(); adc(self, self:read(addr)); return self:_done(2)
  elseif op == 0x6A then imp(self); self.a = ror_v(self, self.a); return self:_done(2)
  elseif op == 0x6C then -- JMP ind
    local ptr = self:read16(self.pc)
    self.pc = self:read16_bug(ptr)
    return self:_done(5)
  elseif op == 0x6D then local addr = self:addr_abs(); adc(self, self:read(addr)); return self:_done(4)
  elseif op == 0x6E then local addr = self:addr_abs(); return rmw(self, addr, ror_v, 6)
  elseif op == 0x70 then return self:branch(self:flag(V)) -- BVS
  elseif op == 0x71 then local addr, e = self:addr_indy(true); adc(self, self:read(addr)); return self:_done(5)
  elseif op == 0x75 then local addr = self:addr_zpx(); adc(self, self:read(addr)); return self:_done(4)
  elseif op == 0x76 then local addr = self:addr_zpx(); return rmw(self, addr, ror_v, 6)
  elseif op == 0x78 then imp(self); self:set_flag(I, true); return self:_done(2) -- SEI
  elseif op == 0x79 then local addr, e = self:addr_aby(true); adc(self, self:read(addr)); return self:_done(4)
  elseif op == 0x7D then local addr, e = self:addr_abx(true); adc(self, self:read(addr)); return self:_done(4)
  elseif op == 0x7E then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, ror_v, 7)
  elseif op == 0x81 then local addr = self:addr_indx(); return sta(self, addr, 6)
  elseif op == 0x84 then local addr = self:addr_zp(); return sty(self, addr, 3)
  elseif op == 0x85 then local addr = self:addr_zp(); return sta(self, addr, 3)
  elseif op == 0x86 then local addr = self:addr_zp(); return stx(self, addr, 3)
  elseif op == 0x88 then imp(self); self.y = self:set_zn(self.y - 1); return self:_done(2) -- DEY
  elseif op == 0x8A then imp(self); self.a = self:set_zn(self.x); return self:_done(2) -- TXA
  elseif op == 0x8C then local addr = self:addr_abs(); return sty(self, addr, 4)
  elseif op == 0x8D then local addr = self:addr_abs(); return sta(self, addr, 4)
  elseif op == 0x8E then local addr = self:addr_abs(); return stx(self, addr, 4)
  elseif op == 0x90 then return self:branch(not self:flag(C)) -- BCC
  elseif op == 0x91 then local addr = self:addr_indy(false, "write"); return sta(self, addr, 6)
  elseif op == 0x94 then local addr = self:addr_zpx(); return sty(self, addr, 4)
  elseif op == 0x95 then local addr = self:addr_zpx(); return sta(self, addr, 4)
  elseif op == 0x96 then local addr = self:addr_zpy(); return stx(self, addr, 4)
  elseif op == 0x98 then imp(self); self.a = self:set_zn(self.y); return self:_done(2) -- TYA
  elseif op == 0x99 then local addr = self:addr_aby(false, "write"); return sta(self, addr, 5)
  elseif op == 0x9A then imp(self); self.sp = self.x; return self:_done(2) -- TXS
  elseif op == 0x9D then local addr = self:addr_abx(false, "write"); return sta(self, addr, 5)
  elseif op == 0xA0 then local addr = self:addr_imm(); return ldy(self, addr, 2)
  elseif op == 0xA1 then local addr = self:addr_indx(); return lda(self, addr, 6)
  elseif op == 0xA2 then local addr = self:addr_imm(); return ldx(self, addr, 2)
  elseif op == 0xA4 then local addr = self:addr_zp(); return ldy(self, addr, 3)
  elseif op == 0xA5 then local addr = self:addr_zp(); return lda(self, addr, 3)
  elseif op == 0xA6 then local addr = self:addr_zp(); return ldx(self, addr, 3)
  elseif op == 0xA8 then imp(self); self.y = self:set_zn(self.a); return self:_done(2) -- TAY
  elseif op == 0xA9 then local addr = self:addr_imm(); return lda(self, addr, 2)
  elseif op == 0xAA then imp(self); self.x = self:set_zn(self.a); return self:_done(2) -- TAX
  elseif op == 0xAC then local addr = self:addr_abs(); return ldy(self, addr, 4)
  elseif op == 0xAD then local addr = self:addr_abs(); return lda(self, addr, 4)
  elseif op == 0xAE then local addr = self:addr_abs(); return ldx(self, addr, 4)
  elseif op == 0xB0 then return self:branch(self:flag(C)) -- BCS
  elseif op == 0xB1 then local addr, e = self:addr_indy(true); return lda(self, addr, 5)
  elseif op == 0xB4 then local addr = self:addr_zpx(); return ldy(self, addr, 4)
  elseif op == 0xB5 then local addr = self:addr_zpx(); return lda(self, addr, 4)
  elseif op == 0xB6 then local addr = self:addr_zpy(); return ldx(self, addr, 4)
  elseif op == 0xB8 then imp(self); self:set_flag(V, false); return self:_done(2) -- CLV
  elseif op == 0xB9 then local addr, e = self:addr_aby(true); return lda(self, addr, 4)
  elseif op == 0xBA then imp(self); self.x = self:set_zn(self.sp); return self:_done(2) -- TSX
  elseif op == 0xBC then local addr, e = self:addr_abx(true); return ldy(self, addr, 4)
  elseif op == 0xBD then local addr, e = self:addr_abx(true); return lda(self, addr, 4)
  elseif op == 0xBE then local addr, e = self:addr_aby(true); return ldx(self, addr, 4)
  elseif op == 0xC0 then local addr = self:addr_imm(); cmp(self, self.y, self:read(addr)); return self:_done(2)
  elseif op == 0xC1 then local addr = self:addr_indx(); cmp(self, self.a, self:read(addr)); return self:_done(6)
  elseif op == 0xC4 then local addr = self:addr_zp(); cmp(self, self.y, self:read(addr)); return self:_done(3)
  elseif op == 0xC5 then local addr = self:addr_zp(); cmp(self, self.a, self:read(addr)); return self:_done(3)
  elseif op == 0xC6 then local addr = self:addr_zp(); return rmw(self, addr, dec_v, 5)
  elseif op == 0xC8 then imp(self); self.y = self:set_zn(self.y + 1); return self:_done(2) -- INY
  elseif op == 0xC9 then local addr = self:addr_imm(); cmp(self, self.a, self:read(addr)); return self:_done(2)
  elseif op == 0xCA then imp(self); self.x = self:set_zn(self.x - 1); return self:_done(2) -- DEX
  elseif op == 0xCC then local addr = self:addr_abs(); cmp(self, self.y, self:read(addr)); return self:_done(4)
  elseif op == 0xCD then local addr = self:addr_abs(); cmp(self, self.a, self:read(addr)); return self:_done(4)
  elseif op == 0xCE then local addr = self:addr_abs(); return rmw(self, addr, dec_v, 6)
  elseif op == 0xD0 then return self:branch(not self:flag(Z)) -- BNE
  elseif op == 0xD1 then local addr, e = self:addr_indy(true); cmp(self, self.a, self:read(addr)); return self:_done(5)
  elseif op == 0xD5 then local addr = self:addr_zpx(); cmp(self, self.a, self:read(addr)); return self:_done(4)
  elseif op == 0xD6 then local addr = self:addr_zpx(); return rmw(self, addr, dec_v, 6)
  elseif op == 0xD8 then imp(self); self:set_flag(D, false); return self:_done(2) -- CLD
  elseif op == 0xD9 then local addr, e = self:addr_aby(true); cmp(self, self.a, self:read(addr)); return self:_done(4)
  elseif op == 0xDD then local addr, e = self:addr_abx(true); cmp(self, self.a, self:read(addr)); return self:_done(4)
  elseif op == 0xDE then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, dec_v, 7)
  elseif op == 0xE0 then local addr = self:addr_imm(); cmp(self, self.x, self:read(addr)); return self:_done(2)
  elseif op == 0xE1 then local addr = self:addr_indx(); sbc(self, self:read(addr)); return self:_done(6)
  elseif op == 0xE4 then local addr = self:addr_zp(); cmp(self, self.x, self:read(addr)); return self:_done(3)
  elseif op == 0xE5 then local addr = self:addr_zp(); sbc(self, self:read(addr)); return self:_done(3)
  elseif op == 0xE6 then local addr = self:addr_zp(); return rmw(self, addr, inc_v, 5)
  elseif op == 0xE8 then imp(self); self.x = self:set_zn(self.x + 1); return self:_done(2) -- INX
  elseif op == 0xE9 then local addr = self:addr_imm(); sbc(self, self:read(addr)); return self:_done(2)
  elseif op == 0xEA then imp(self); return self:_done(2) -- NOP
  elseif op == 0xEC then local addr = self:addr_abs(); cmp(self, self.x, self:read(addr)); return self:_done(4)
  elseif op == 0xED then local addr = self:addr_abs(); sbc(self, self:read(addr)); return self:_done(4)
  elseif op == 0xEE then local addr = self:addr_abs(); return rmw(self, addr, inc_v, 6)
  elseif op == 0xF0 then return self:branch(self:flag(Z)) -- BEQ
  elseif op == 0xF1 then local addr, e = self:addr_indy(true); sbc(self, self:read(addr)); return self:_done(5)
  elseif op == 0xF5 then local addr = self:addr_zpx(); sbc(self, self:read(addr)); return self:_done(4)
  elseif op == 0xF6 then local addr = self:addr_zpx(); return rmw(self, addr, inc_v, 6)
  elseif op == 0xF8 then imp(self); self:set_flag(D, true); return self:_done(2) -- SED (ignored on 2A03 ALU)
  elseif op == 0xF9 then local addr, e = self:addr_aby(true); sbc(self, self:read(addr)); return self:_done(4)
  elseif op == 0xFD then local addr, e = self:addr_abx(true); sbc(self, self:read(addr)); return self:_done(4)
  elseif op == 0xFE then local addr = self:addr_abx(false, "rmw"); return rmw(self, addr, inc_v, 7)
  end

  ------------------------------------------------------------------
  -- Unofficial / illegal opcodes (NES 2A03 = NMOS 6502 behavior)
  ------------------------------------------------------------------
  -- KIL / JAM: freeze (treat as 2-cycle spin for harness safety)
  if op == 0x02 or op == 0x12 or op == 0x22 or op == 0x32
    or op == 0x42 or op == 0x52 or op == 0x62 or op == 0x72
    or op == 0x92 or op == 0xB2 or op == 0xD2 or op == 0xF2 then
    self.pc = band(self.pc - 1, 0xFFFF) -- jam on same opcode
    return self:_done(2)
  end

  -- NOP implied (1 byte): 1A 3A 5A 7A DA FA
  if op == 0x1A or op == 0x3A or op == 0x5A or op == 0x7A
    or op == 0xDA or op == 0xFA then
    imp(self); return self:_done(2)
  end

  -- DOP / NOP zp, imm, zp,X (2 bytes)
  if op == 0x04 or op == 0x44 or op == 0x64 then -- NOP zp
    self:addr_zp(); return self:_done(3)
  elseif op == 0x14 or op == 0x34 or op == 0x54 or op == 0x74
    or op == 0xD4 or op == 0xF4 then -- NOP zp,X
    self:addr_zpx(); return self:_done(4)
  elseif op == 0x80 or op == 0x82 or op == 0x89 or op == 0xC2 or op == 0xE2 then -- NOP #imm
    self:addr_imm(); return self:_done(2)
  end

  -- TOP / NOP abs / abs,X (3 bytes)
  if op == 0x0C then -- NOP abs
    self:addr_abs(); return self:_done(4)
  elseif op == 0x1C or op == 0x3C or op == 0x5C or op == 0x7C
    or op == 0xDC or op == 0xFC then -- NOP abs,X
    local _, e = self:addr_abx(true); return self:_done(4)
  end

  -- SLO
  if op == 0x03 then local addr = self:addr_indx(); return slo(self, addr, 8)
  elseif op == 0x07 then local addr = self:addr_zp(); return slo(self, addr, 5)
  elseif op == 0x0F then local addr = self:addr_abs(); return slo(self, addr, 6)
  elseif op == 0x13 then local addr = self:addr_indy(false, "rmw"); return slo(self, addr, 8)
  elseif op == 0x17 then local addr = self:addr_zpx(); return slo(self, addr, 6)
  elseif op == 0x1B then local addr = self:addr_aby(false, "rmw"); return slo(self, addr, 7)
  elseif op == 0x1F then local addr = self:addr_abx(false, "rmw"); return slo(self, addr, 7)
  end

  -- RLA
  if op == 0x23 then local addr = self:addr_indx(); return rla(self, addr, 8)
  elseif op == 0x27 then local addr = self:addr_zp(); return rla(self, addr, 5)
  elseif op == 0x2F then local addr = self:addr_abs(); return rla(self, addr, 6)
  elseif op == 0x33 then local addr = self:addr_indy(false, "rmw"); return rla(self, addr, 8)
  elseif op == 0x37 then local addr = self:addr_zpx(); return rla(self, addr, 6)
  elseif op == 0x3B then local addr = self:addr_aby(false, "rmw"); return rla(self, addr, 7)
  elseif op == 0x3F then local addr = self:addr_abx(false, "rmw"); return rla(self, addr, 7)
  end

  -- SRE
  if op == 0x43 then local addr = self:addr_indx(); return sre(self, addr, 8)
  elseif op == 0x47 then local addr = self:addr_zp(); return sre(self, addr, 5)
  elseif op == 0x4F then local addr = self:addr_abs(); return sre(self, addr, 6)
  elseif op == 0x53 then local addr = self:addr_indy(false, "rmw"); return sre(self, addr, 8)
  elseif op == 0x57 then local addr = self:addr_zpx(); return sre(self, addr, 6)
  elseif op == 0x5B then local addr = self:addr_aby(false, "rmw"); return sre(self, addr, 7)
  elseif op == 0x5F then local addr = self:addr_abx(false, "rmw"); return sre(self, addr, 7)
  end

  -- RRA
  if op == 0x63 then local addr = self:addr_indx(); return rra(self, addr, 8)
  elseif op == 0x67 then local addr = self:addr_zp(); return rra(self, addr, 5)
  elseif op == 0x6F then local addr = self:addr_abs(); return rra(self, addr, 6)
  elseif op == 0x73 then local addr = self:addr_indy(false, "rmw"); return rra(self, addr, 8)
  elseif op == 0x77 then local addr = self:addr_zpx(); return rra(self, addr, 6)
  elseif op == 0x7B then local addr = self:addr_aby(false, "rmw"); return rra(self, addr, 7)
  elseif op == 0x7F then local addr = self:addr_abx(false, "rmw"); return rra(self, addr, 7)
  end

  -- SAX / AAX
  if op == 0x83 then local addr = self:addr_indx(); return sax(self, addr, 6)
  elseif op == 0x87 then local addr = self:addr_zp(); return sax(self, addr, 3)
  elseif op == 0x8F then local addr = self:addr_abs(); return sax(self, addr, 4)
  elseif op == 0x97 then local addr = self:addr_zpy(); return sax(self, addr, 4)
  end

  -- LAX
  if op == 0xA3 then local addr = self:addr_indx(); return lax(self, addr, 6)
  elseif op == 0xA7 then local addr = self:addr_zp(); return lax(self, addr, 3)
  elseif op == 0xAF then local addr = self:addr_abs(); return lax(self, addr, 4)
  elseif op == 0xB3 then local addr, e = self:addr_indy(true); return lax(self, addr, 5, e)
  elseif op == 0xB7 then local addr = self:addr_zpy(); return lax(self, addr, 4)
  elseif op == 0xBF then local addr, e = self:addr_aby(true); return lax(self, addr, 4, e)
  end

  -- DCP
  if op == 0xC3 then local addr = self:addr_indx(); return dcp(self, addr, 8)
  elseif op == 0xC7 then local addr = self:addr_zp(); return dcp(self, addr, 5)
  elseif op == 0xCF then local addr = self:addr_abs(); return dcp(self, addr, 6)
  elseif op == 0xD3 then local addr = self:addr_indy(false, "rmw"); return dcp(self, addr, 8)
  elseif op == 0xD7 then local addr = self:addr_zpx(); return dcp(self, addr, 6)
  elseif op == 0xDB then local addr = self:addr_aby(false, "rmw"); return dcp(self, addr, 7)
  elseif op == 0xDF then local addr = self:addr_abx(false, "rmw"); return dcp(self, addr, 7)
  end

  -- ISC / ISB
  if op == 0xE3 then local addr = self:addr_indx(); return isc(self, addr, 8)
  elseif op == 0xE7 then local addr = self:addr_zp(); return isc(self, addr, 5)
  elseif op == 0xEF then local addr = self:addr_abs(); return isc(self, addr, 6)
  elseif op == 0xF3 then local addr = self:addr_indy(false, "rmw"); return isc(self, addr, 8)
  elseif op == 0xF7 then local addr = self:addr_zpx(); return isc(self, addr, 6)
  elseif op == 0xFB then local addr = self:addr_aby(false, "rmw"); return isc(self, addr, 7)
  elseif op == 0xFF then local addr = self:addr_abx(false, "rmw"); return isc(self, addr, 7)
  end

  -- SBC unofficial alias
  if op == 0xEB then local addr = self:addr_imm(); sbc(self, self:read(addr)); return self:_done(2) end

  -- ANC / AAC #imm: AND + copy N to C
  if op == 0x0B or op == 0x2B then
    local addr = self:addr_imm()
    self.a = self:set_zn(band(self.a, self:read(addr)))
    self:set_flag(C, self:flag(N))
    return self:_done(2)
  end

  -- ALR / ASR #imm: AND then LSR A
  if op == 0x4B then
    local addr = self:addr_imm()
    self.a = band(self.a, self:read(addr))
    self.a = lsr_v(self, self.a)
    return self:_done(2)
  end

  -- ARR #imm: AND then ROR A; C/V from quirky rules
  if op == 0x6B then
    local addr = self:addr_imm()
    self.a = band(self.a, self:read(addr))
    self.a = ror_v(self, self.a)
    local a = self.a
    self:set_flag(C, band(a, 0x40) ~= 0)
    self:set_flag(V, band(bxor(rshift(a, 6), rshift(a, 5)), 1) ~= 0)
    self:set_zn(a)
    return self:_done(2)
  end

  -- LXA / ATX #imm: unstable; blargg NES checksums match (A|0xFF)&imm (= imm)
  if op == 0xAB then
    local addr = self:addr_imm()
    local v = band(bor(self.a, 0xFF), self:read(addr))
    self.a = self:set_zn(v)
    self.x = v
    return self:_done(2)
  end

  -- AXS / SBX #imm: X = (A&X) - imm, flags like CMP
  if op == 0xCB then
    local addr = self:addr_imm()
    local v = self:read(addr)
    local t = band(self.a, self.x) - v
    self:set_flag(C, band(self.a, self.x) >= v)
    self.x = self:set_zn(t)
    return self:_done(2)
  end

  -- SHY / SYA abs,X: store Y & (high+1)
  if op == 0x9C then
    local base = self:read16(self.pc)
    self.pc = band(self.pc + 2, 0xFFFF)
    local addr = band(base + self.x, 0xFFFF)
    local hi = rshift(base, 8)
    local v = band(self.y, band(hi + 1, 0xFF))
    if self:page_crossed(base, addr) then
      addr = bor(band(addr, 0xFF), lshift(v, 8))
    end
    self:write(addr, v)
    return self:_done(5)
  end

  -- SHX / SXA abs,Y
  if op == 0x9E then
    local base = self:read16(self.pc)
    self.pc = band(self.pc + 2, 0xFFFF)
    local addr = band(base + self.y, 0xFFFF)
    local hi = rshift(base, 8)
    local v = band(self.x, band(hi + 1, 0xFF))
    if self:page_crossed(base, addr) then
      addr = bor(band(addr, 0xFF), lshift(v, 8))
    end
    self:write(addr, v)
    return self:_done(5)
  end

  -- SHA / AHX (abs,Y) / (ind),Y - unstable; approximate
  if op == 0x9F then
    local base = self:read16(self.pc)
    self.pc = band(self.pc + 2, 0xFFFF)
    local addr = band(base + self.y, 0xFFFF)
    local v = band(band(self.a, self.x), band(rshift(base, 8) + 1, 0xFF))
    self:write(addr, v)
    return self:_done(5)
  elseif op == 0x93 then
    local ptr = self:read(self.pc)
    self.pc = band(self.pc + 1, 0xFFFF)
    local lo = self:read(ptr)
    local hi = self:read(band(ptr + 1, 0xFF))
    local base = bor(lo, lshift(hi, 8))
    local addr = band(base + self.y, 0xFFFF)
    local v = band(band(self.a, self.x), band(hi + 1, 0xFF))
    self:write(addr, v)
    return self:_done(6)
  end

  -- LAS abs,Y
  if op == 0xBB then
    local addr, e = self:addr_aby(true)
    local v = band(self:read(addr), self.sp)
    self.a = self:set_zn(v)
    self.x = v
    self.sp = v
    return self:_done(4)
  end

  -- TAS / SHS abs,Y
  if op == 0x9B then
    local base = self:read16(self.pc)
    self.pc = band(self.pc + 2, 0xFFFF)
    local addr = band(base + self.y, 0xFFFF)
    self.sp = band(self.a, self.x)
    local v = band(self.sp, band(rshift(base, 8) + 1, 0xFF))
    self:write(addr, v)
    return self:_done(5)
  end

  -- XAA (unstable) - approximate AND X then AND imm
  if op == 0x8B then
    local addr = self:addr_imm()
    self.a = self:set_zn(band(band(self.a, self.x), self:read(addr)))
    return self:_done(2)
  end

  -- Fallback: 1-byte NOP (should be unreachable if table is complete)
  return self:_done(2)
end

return CPU
