-- Sharp SM83 / LR35902 (Game Boy) CPU interpreter.
-- Memory-mapped IE/IF and no I/O ports; bus is { read, write } only.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local u8, u16, pair = bit.u8, bit.u16, bit.pair

local Z, N, H, C = 0x80, 0x40, 0x20, 0x10

local SM83 = {}
SM83.__index = SM83
SM83.FLAG_Z, SM83.FLAG_N, SM83.FLAG_H, SM83.FLAG_C = Z, N, H, C

function SM83.new(bus)
  local self = setmetatable({}, SM83)
  self.bus = bus
  self:reset()
  return self
end

function SM83:reset()
  self.a = 0
  self.f = 0
  self.b = 0
  self.c = 0
  self.d = 0
  self.e = 0
  self.h = 0
  self.l = 0
  self.sp = 0
  self.pc = 0
  self.ime = false
  self.ei_delay = false
  self.halted = false
  self.halt_bug = false
  self.stopped = false
  self.cycles = 0
end

--- Post-boot DMG register state (no boot ROM).
function SM83:power_on_dmg()
  self.a = 0x01
  self.f = 0xB0
  self.b = 0x00
  self.c = 0x13
  self.d = 0x00
  self.e = 0xD8
  self.h = 0x01
  self.l = 0x4D
  self.sp = 0xFFFE
  self.pc = 0x0100
  self.ime = false
  self.ei_delay = false
  self.halted = false
  self.halt_bug = false
  self.stopped = false
end

function SM83:af()
  return bor(lshift(self.a, 8), band(self.f, 0xF0))
end
function SM83:set_af(v)
  v = u16(v)
  self.a = rshift(v, 8)
  self.f = band(v, 0xF0)
end
function SM83:bc()
  return bor(lshift(self.b, 8), self.c)
end
function SM83:set_bc(v)
  v = u16(v)
  self.b = rshift(v, 8)
  self.c = band(v, 0xFF)
end
function SM83:de()
  return bor(lshift(self.d, 8), self.e)
end
function SM83:set_de(v)
  v = u16(v)
  self.d = rshift(v, 8)
  self.e = band(v, 0xFF)
end
function SM83:hl()
  return bor(lshift(self.h, 8), self.l)
end
function SM83:set_hl(v)
  v = u16(v)
  self.h = rshift(v, 8)
  self.l = band(v, 0xFF)
end

--- Advance one M-cycle (4 T-cycles). Ticks bus hardware when provided.
function SM83:mcycle()
  self.cycles = self.cycles + 4
  local tick = self.bus.tick
  if tick then tick(4) end
end

function SM83:read8(addr)
  -- Access at the start of the M-cycle, then advance hardware (matches
  -- DMG: LCDC enable during the write cycle counts toward scanline time).
  local v = self.bus.read(band(addr, 0xFFFF))
  self:mcycle()
  return v
end
function SM83:write8(addr, v)
  self.bus.write(band(addr, 0xFFFF), band(v, 0xFF))
  self:mcycle()
end
function SM83:read16(addr)
  local lo = self:read8(addr)
  local hi = self:read8(band(addr + 1, 0xFFFF))
  return pair(hi, lo)
end
function SM83:write16(addr, v)
  self:write8(addr, band(v, 0xFF))
  self:write8(band(addr + 1, 0xFFFF), band(rshift(v, 8), 0xFF))
end

function SM83:fetch8()
  local pc = self.pc
  local v = self.bus.read(pc)
  -- DMG HALT bug: next byte after HALT is read twice (PC fails to advance once).
  if self.halt_bug then
    self.halt_bug = false
  else
    self.pc = band(pc + 1, 0xFFFF)
  end
  self:mcycle()
  return v
end
function SM83:fetch16()
  local lo = self:fetch8()
  local hi = self:fetch8()
  return pair(hi, lo)
end
function SM83:fetch_rel()
  local d = self:fetch8()
  if d >= 0x80 then
    return d - 256
  end
  return d
end

function SM83:push16(v)
  self.sp = u16(self.sp - 2)
  self:write16(self.sp, v)
end
function SM83:pop16()
  local v = self:read16(self.sp)
  self.sp = u16(self.sp + 2)
  return v
end

function SM83:flag_z()
  return band(self.f, Z) ~= 0
end
function SM83:flag_c()
  return band(self.f, C) ~= 0
end

function SM83:set_znhc(z, n, h, c)
  local f = 0
  if z then f = bor(f, Z) end
  if n then f = bor(f, N) end
  if h then f = bor(f, H) end
  if c then f = bor(f, C) end
  self.f = f
end

function SM83:add8(a, b, carry)
  a, b = u8(a), u8(b)
  local cy = carry and 1 or 0
  local res = a + b + cy
  self:set_znhc(u8(res) == 0, false, band(a, 0x0F) + band(b, 0x0F) + cy > 0x0F, res > 0xFF)
  return u8(res)
end

function SM83:sub8(a, b, carry)
  a, b = u8(a), u8(b)
  local cy = carry and 1 or 0
  local res = a - b - cy
  self:set_znhc(u8(res) == 0, true, band(a, 0x0F) - band(b, 0x0F) - cy < 0, res < 0)
  return u8(res)
end

function SM83:and8(a, b)
  local res = band(a, b)
  self:set_znhc(res == 0, false, true, false)
  return res
end

function SM83:xor8(a, b)
  local res = bxor(a, b)
  self:set_znhc(res == 0, false, false, false)
  return res
end

function SM83:or8(a, b)
  local res = bor(a, b)
  self:set_znhc(res == 0, false, false, false)
  return res
end

function SM83:cp8(a, b)
  self:sub8(a, b, false)
end

function SM83:inc8(v)
  local res = u8(v + 1)
  local c = band(self.f, C)
  local f = 0
  if res == 0 then f = bor(f, Z) end
  if band(v, 0x0F) == 0x0F then f = bor(f, H) end
  self.f = bor(f, c)
  return res
end

function SM83:dec8(v)
  local res = u8(v - 1)
  local c = band(self.f, C)
  local f = N
  if res == 0 then f = bor(f, Z) end
  if band(v, 0x0F) == 0 then f = bor(f, H) end
  self.f = bor(f, c)
  return res
end

function SM83:add16_hl(v)
  local a = self:hl()
  v = u16(v)
  local res = a + v
  local z = band(self.f, Z)
  local f = z
  if band(a, 0x0FFF) + band(v, 0x0FFF) > 0x0FFF then f = bor(f, H) end
  if res > 0xFFFF then f = bor(f, C) end
  self.f = f
  self:set_hl(u16(res))
end

function SM83:add_sp(e)
  local sp = self.sp
  local res = u16(sp + e)
  -- Flags from low byte add (signed e as unsigned for half/carry on low 8)
  local ue = band(e, 0xFF)
  self:set_znhc(false, false, band(sp, 0x0F) + band(ue, 0x0F) > 0x0F, band(sp, 0xFF) + ue > 0xFF)
  return res
end

function SM83:daa()
  local a = self.a
  local f = self.f
  local n = band(f, N) ~= 0
  local h = band(f, H) ~= 0
  local c = band(f, C) ~= 0
  if not n then
    if c or a > 0x99 then
      a = a + 0x60
      c = true
    end
    if h or band(a, 0x0F) > 0x09 then
      a = a + 0x06
    end
  else
    if c then a = a - 0x60 end
    if h then a = a - 0x06 end
  end
  a = u8(a)
  self.a = a
  self:set_znhc(a == 0, n, false, c)
end

local IRQ_VECS = { 0x40, 0x48, 0x50, 0x58, 0x60 }

function SM83:pending_irqs()
  local irq = self.bus.irq
  if irq then
    return band(irq.ie, irq.iff, 0x1F)
  end
  local ie = self.bus.read(0xFFFF)
  local iff = self.bus.read(0xFF0F)
  return band(ie, iff, 0x1F)
end

--- Service highest-priority interrupt if IME and pending. Returns T-cycles or 0.
function SM83:service_interrupt()
  local pending = self:pending_irqs()
  if pending == 0 or not self.ime then
    return 0
  end
  local c0 = self.cycles
  self.ime = false
  self.halted = false
  self.stopped = false
  local irq = self.bus.irq
  local iff = irq and irq.iff or self.bus.read(0xFF0F)
  for i = 0, 4 do
    local mask = lshift(1, i)
    if band(pending, mask) ~= 0 then
      local cleared = band(iff, bxor(0xFF, mask))
      if irq then
        irq.iff = cleared
      else
        self.bus.write(0xFF0F, cleared)
      end
      -- 5 M-cycles: 3 internal + push PC (2 writes)
      self:mcycle()
      self:mcycle()
      self:mcycle()
      self:push16(self.pc)
      self.pc = IRQ_VECS[i + 1]
      return self.cycles - c0
    end
  end
  return 0
end

function SM83:getRegisters()
  return {
    a = self.a, f = self.f,
    b = self.b, c = self.c,
    d = self.d, e = self.e,
    h = self.h, l = self.l,
    af = self:af(), bc = self:bc(), de = self:de(), hl = self:hl(),
    sp = self.sp, pc = self.pc,
    ime = self.ime, halted = self.halted,
  }
end

function SM83:setRegisters(r)
  if r.a then self.a = u8(r.a) end
  if r.f then self.f = band(r.f, 0xF0) end
  if r.b then self.b = u8(r.b) end
  if r.c then self.c = u8(r.c) end
  if r.d then self.d = u8(r.d) end
  if r.e then self.e = u8(r.e) end
  if r.h then self.h = u8(r.h) end
  if r.l then self.l = u8(r.l) end
  if r.af then self:set_af(r.af) end
  if r.bc then self:set_bc(r.bc) end
  if r.de then self:set_de(r.de) end
  if r.hl then self:set_hl(r.hl) end
  if r.sp then self.sp = u16(r.sp) end
  if r.pc then self.pc = u16(r.pc) end
  if r.ime ~= nil then self.ime = not not r.ime end
end

-- Opcode table filled by opcodes.lua
SM83.OP = {}
SM83.CB = {}

require("cpus.sm83.opcodes")(SM83, bit)

function SM83:step()
  local c0 = self.cycles
  if self.stopped then
    self:mcycle()
    return self.cycles - c0
  end

  -- HALT exit / IRQ before fetch
  local pending = self:pending_irqs()
  if self.halted then
    if pending ~= 0 then
      self.halted = false
      if self.ime then
        return self:service_interrupt()
      end
      -- IME off: leave HALT and execute next insn (DMG halt bug omitted)
    else
      self:mcycle()
      return self.cycles - c0
    end
  elseif self.ime and pending ~= 0 then
    return self:service_interrupt()
  end

  local enable_ime = self.ei_delay
  self.ei_delay = false

  local op = self:fetch8()
  local handler = SM83.OP[op]
  if handler then
    handler(self)
  end
  -- Cycle count comes from mcycle() during fetch/mem/internal ops.

  if enable_ime then
    self.ime = true
  end

  return self.cycles - c0
end

return SM83
