-- MC68000 instruction execute (modular dispatch by opcode groups).
local bit = require("framework.util.bit")
local EA = require("cpus.m68k.ea")
local band, bor, bxor, bnot, lshift, rshift =
  bit.band, bit.bor, bit.bxor, bit.bnot, bit.lshift, bit.rshift

local SR_C, SR_V, SR_Z, SR_N, SR_X = 0x01, 0x02, 0x04, 0x08, 0x10
local SR_S = 0x2000

local Ops = {}

local function size_from_bits(s)
  if s == 0 then return 1 elseif s == 1 then return 2 else return 4 end
end

-- Lua numbers used in signed arithmetic. EA.sign_extend returns u32 (e.g. 0xFFFFFFFF
-- for -1); multiplying/dividing those as Lua numbers is wrong and loses precision.
local function as_signed(u, bits)
  if bits == 8 then
    u = band(u, 0xFF)
    return (u >= 0x80) and (u - 0x100) or u
  elseif bits == 16 then
    u = band(u, 0xFFFF)
    return (u >= 0x8000) and (u - 0x10000) or u
  end
  u = band(u, 0xFFFFFFFF)
  return (u >= 0x80000000) and (u - 0x100000000) or u
end

local function cond_true(cpu, cc)
  local sr = cpu.sr
  local c = band(sr, SR_C) ~= 0
  local v = band(sr, SR_V) ~= 0
  local z = band(sr, SR_Z) ~= 0
  local n = band(sr, SR_N) ~= 0
  if cc == 0 then return true -- T
  elseif cc == 1 then return false -- F
  elseif cc == 2 then return not c and not z -- HI
  elseif cc == 3 then return c or z -- LS
  elseif cc == 4 then return not c -- CC
  elseif cc == 5 then return c -- CS
  elseif cc == 6 then return not z -- NE
  elseif cc == 7 then return z -- EQ
  elseif cc == 8 then return not v -- VC
  elseif cc == 9 then return v -- VS
  elseif cc == 10 then return not n -- PL
  elseif cc == 11 then return n -- MI
  elseif cc == 12 then return (n and v) or (not n and not v) -- GE
  elseif cc == 13 then return (n and not v) or (not n and v) -- LT
  elseif cc == 14 then return not z and ((n and v) or (not n and not v)) -- GT
  elseif cc == 15 then return z or (n and not v) or (not n and v) -- LE
  end
  return false
end

local function add_flags(cpu, src, dst, result, size)
  local m = EA.mask(size)
  local sm = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  src, dst, result = band(src, m), band(dst, m), band(result, m)
  cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V, SR_Z, SR_N, SR_X)))
  if result == 0 then cpu.sr = bor(cpu.sr, SR_Z) end
  if band(result, sm) ~= 0 then cpu.sr = bor(cpu.sr, SR_N) end
  -- Carry: result didn't fit
  local carry
  if size == 1 then carry = (src + dst) > 0xFF
  elseif size == 2 then carry = (src + dst) > 0xFFFF
  else carry = (src + dst) > 0xFFFFFFFF end
  if carry then cpu.sr = bor(cpu.sr, SR_C, SR_X) end
  local ds, ss, rs = band(dst, sm) ~= 0, band(src, sm) ~= 0, band(result, sm) ~= 0
  if (not ss and not ds and rs) or (ss and ds and not rs) then
    cpu.sr = bor(cpu.sr, SR_V)
  end
end

local function sub_flags(cpu, src, dst, result, size)
  local m = EA.mask(size)
  local sm = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  src, dst, result = band(src, m), band(dst, m), band(result, m)
  cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V, SR_Z, SR_N, SR_X)))
  if result == 0 then cpu.sr = bor(cpu.sr, SR_Z) end
  if band(result, sm) ~= 0 then cpu.sr = bor(cpu.sr, SR_N) end
  if src > dst then cpu.sr = bor(cpu.sr, SR_C, SR_X) end
  local ds, ss, rs = band(dst, sm) ~= 0, band(src, sm) ~= 0, band(result, sm) ~= 0
  if (not ss and ds and not rs) or (ss and not ds and rs) then
    cpu.sr = bor(cpu.sr, SR_V)
  end
end

local function op_move(cpu, op)
  -- Hot path: MOVE <Dn>,<Dn> / MOVEA <Dn>,An (no EA side effects).
  local dst_mode = math.floor(op / 64) % 8
  local src_mode = math.floor(op / 8) % 8
  local src_reg = op % 8
  local dst_reg = math.floor(op / 512) % 8
  local size_bits = math.floor(op / 4096) % 4 -- 1=B 2=L 3=W for MOVE
  local size = (size_bits == 1) and 1 or ((size_bits == 3) and 2 or 4)

  if src_mode == 0 then
    local val = cpu.d[src_reg]
    if size == 1 then
      val = val % 256
    elseif size == 2 then
      val = val % 65536
    else
      val = band(val, 0xFFFFFFFF)
    end
    if dst_mode == 1 then
      if size == 2 then
        val = (val >= 0x8000) and (val + 0xFFFF0000) or val
      end
      cpu:set_a(dst_reg, band(val, 0xFFFFFFFF))
      return 8
    end
    if dst_mode == 0 then
      if size == 1 then
        cpu.d[dst_reg] = bor(band(cpu.d[dst_reg], 0xFFFFFF00), val)
      elseif size == 2 then
        cpu.d[dst_reg] = bor(band(cpu.d[dst_reg], 0xFFFF0000), val)
      else
        cpu.d[dst_reg] = val
      end
      cpu:set_nz(val, size)
      cpu.sr = band(cpu.sr, bnot(SR_C))
      return 8
    end
    -- Fall through for mem dest with Dn source.
    local addr, cat = EA.decode_mode_reg(cpu, dst_mode, dst_reg, size)
    if cat == "mem" then
      if size == 1 then cpu:write8(addr, val)
      elseif size == 2 then cpu:write16(addr, val)
      else cpu:write32(addr, val) end
    end
    cpu:set_nz(val, size)
    cpu.sr = band(cpu.sr, bnot(SR_C))
    return 8
  end

  local val, _, src_cat = EA.read_ea(cpu, src_mode, src_reg, size)
  -- MOVEA when dst mode is An
  if dst_mode == 1 then
    if size == 2 then val = EA.sign_extend(val, 16) end
    cpu:set_a(dst_reg, val)
    return 8
  end
  -- For dest modes that modify address regs during EA calc, compute dest carefully.
  -- Re-read pattern: write using decode that may side-effect An.
  if dst_mode == 0 then
    EA.write_ea(cpu, 0, dst_reg, size, val, nil, "dn")
  else
    local addr, cat = EA.decode_mode_reg(cpu, dst_mode, dst_reg, size)
    if cat == "mem" then
      if size == 1 then cpu:write8(addr, val)
      elseif size == 2 then cpu:write16(addr, val)
      else cpu:write32(addr, val) end
    end
  end
  cpu:set_nz(val, size)
  cpu.sr = band(cpu.sr, bnot(SR_C))
  return 8
end

local function op_ori_to_ccr_sr(cpu, op)
  if op == 0x003C then
    local imm = band(cpu:fetch16(), 0xFF)
    cpu.sr = bor(cpu.sr, band(imm, 0x1F))
    return 20
  elseif op == 0x007C then
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    local imm = cpu:fetch16()
    cpu.sr = bor(cpu.sr, band(imm, 0xA71F))
    return 20
  end
  return nil
end

local function op_andi_to_ccr_sr(cpu, op)
  if op == 0x023C then
    local imm = band(cpu:fetch16(), 0xFF)
    cpu.sr = band(cpu.sr, bor(0xFFE0, imm))
    return 20
  elseif op == 0x027C then
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    local imm = cpu:fetch16()
    cpu.sr = band(cpu.sr, imm)
    return 20
  end
  return nil
end

local function op_eori_to_ccr_sr(cpu, op)
  if op == 0x0A3C then
    local imm = band(cpu:fetch16(), 0xFF)
    cpu.sr = bxor(cpu.sr, band(imm, 0x1F))
    return 20
  elseif op == 0x0A7C then
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    local imm = cpu:fetch16()
    cpu.sr = band(bxor(cpu.sr, imm), 0xA71F)
    return 20
  end
  return nil
end

local function op_immediate(cpu, op)
  -- Reject before any fetch: bit8 marks MOVEP/dynamic bit ops; kind 4 is static BTST/etc.
  if band(op, 0x0100) ~= 0 then return nil end
  local kind = band(rshift(op, 9), 7) -- 0=ORI 1=ANDI 2=SUBI 3=ADDI 5=EORI 6=CMPI
  if kind == 4 or kind == 7 then return nil end
  local size_bits = band(rshift(op, 6), 3)
  if size_bits == 3 then return nil end -- size 11 is not an immediate form
  local size = size_from_bits(size_bits)
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)
  if mode == 1 or (mode == 7 and reg >= 2) then return nil end -- An dest illegal
  local imm
  if size == 1 then imm = band(cpu:fetch16(), 0xFF)
  elseif size == 2 then imm = cpu:fetch16()
  else imm = cpu:fetch32() end
  local dst, addr, cat = EA.read_ea(cpu, mode, reg, size)
  local result
  if kind == 0 then -- ORI
    result = bor(dst, imm)
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
  elseif kind == 1 then -- ANDI
    result = band(dst, imm)
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
  elseif kind == 2 then -- SUBI
    result = band(dst - imm, EA.mask(size))
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    sub_flags(cpu, imm, dst, result, size)
  elseif kind == 3 then -- ADDI
    result = band(dst + imm, EA.mask(size))
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    add_flags(cpu, imm, dst, result, size)
  elseif kind == 5 then -- EORI
    result = bxor(dst, imm)
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
  elseif kind == 6 then -- CMPI
    result = band(dst - imm, EA.mask(size))
    sub_flags(cpu, imm, dst, result, size)
  else
    return nil
  end
  return 12
end

-- MOVEP: 0000 ddd 1ss 001 rrr (ss=00.. reserved; 100/101/110/111 = W/L × dir).
-- Shares opcode space with dynamic bit ops; distinguished by mode field == An (001).
local function op_movep(cpu, op)
  if band(rshift(op, 12), 15) ~= 0 then return nil end
  if band(rshift(op, 3), 7) ~= 1 then return nil end
  local bits86 = band(rshift(op, 6), 7)
  if bits86 < 4 then return nil end -- 100..111 only
  local dx = band(rshift(op, 9), 7)
  local ay = band(op, 7)
  local disp = EA.sign_extend(cpu:fetch16(), 16)
  local addr = band(cpu:get_a(ay) + disp, 0xFFFFFFFF)
  local to_mem = bits86 >= 6
  local long = (bits86 == 5 or bits86 == 7)
  if to_mem then
    local v = cpu.d[dx]
    if long then
      cpu:write8(addr, rshift(v, 24))
      cpu:write8(band(addr + 2, 0xFFFFFFFF), rshift(v, 16))
      cpu:write8(band(addr + 4, 0xFFFFFFFF), rshift(v, 8))
      cpu:write8(band(addr + 6, 0xFFFFFFFF), v)
    else
      cpu:write8(addr, rshift(v, 8))
      cpu:write8(band(addr + 2, 0xFFFFFFFF), v)
    end
    return long and 24 or 16
  end
  if long then
    local v = bor(
      lshift(cpu:read8(addr), 24),
      lshift(cpu:read8(band(addr + 2, 0xFFFFFFFF)), 16),
      lshift(cpu:read8(band(addr + 4, 0xFFFFFFFF)), 8),
      cpu:read8(band(addr + 6, 0xFFFFFFFF))
    )
    cpu.d[dx] = band(v, 0xFFFFFFFF)
    return 24
  end
  local w = bor(lshift(cpu:read8(addr), 8), cpu:read8(band(addr + 2, 0xFFFFFFFF)))
  cpu.d[dx] = bor(band(cpu.d[dx], 0xFFFF0000), band(w, 0xFFFF))
  return 16
end

local function op_bit(cpu, op)
  -- BTST/BCHG/BCLR/BSET: static 0000 1000 tt ..., dynamic 0000 ddd 1 tt ...
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)
  local typ = band(rshift(op, 6), 3) -- 0 BTST 1 BCHG 2 BCLR 3 BSET
  local is_dyn = band(op, 0x0100) ~= 0
  if is_dyn then
    if mode == 1 then return nil end -- An illegal (MOVEP uses this slot)
  else
    if band(op, 0xFF00) ~= 0x0800 then return nil end
  end
  local bitno
  if is_dyn then
    bitno = band(cpu.d[band(rshift(op, 9), 7)], 31)
  else
    bitno = band(cpu:fetch16(), 31)
  end
  local size = (mode == 0) and 4 or 1
  if size == 1 then bitno = band(bitno, 7) end
  local val, addr, cat = EA.read_ea(cpu, mode, reg, size)
  local mask = lshift(1, bitno)
  if band(val, mask) == 0 then cpu.sr = bor(cpu.sr, SR_Z) else cpu.sr = band(cpu.sr, bnot(SR_Z)) end
  if typ == 1 then val = bxor(val, mask)
  elseif typ == 2 then val = band(val, bnot(mask))
  elseif typ == 3 then val = bor(val, mask)
  else return 6 end -- BTST
  if typ ~= 0 then EA.write_ea(cpu, mode, reg, size, val, addr, cat) end
  return 8
end

local function op_moveq(cpu, op)
  local dn = math.floor(op / 512) % 8
  local imm = op % 256
  local data = (imm >= 128) and (0xFFFFFF00 + imm) or imm
  cpu.d[dn] = data
  cpu:set_nz(data, 4)
  cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
  return 4
end

local function op_branch(cpu, op)
  local cc = math.floor(op / 256) % 16
  local disp8 = op % 256
  local base = cpu.pc
  local disp
  if disp8 == 0 then
    disp = EA.sign_extend(cpu:fetch16(), 16)
  elseif disp8 == 0xFF then
    disp = cpu:fetch32() -- 68020; treat as 32 on 68000 rare
  elseif disp8 >= 128 then
    disp = disp8 - 256
  else
    disp = disp8
  end
  if cc == 1 then -- BSR
    cpu:push32(cpu.pc)
    cpu.pc = band(base + disp, 0xFFFFFFFF)
    return 18
  end
  if cc == 0 or cond_true(cpu, cc) then
    cpu.pc = band(base + disp, 0xFFFFFFFF)
    return 10
  end
  return 8
end

local function op_dbcc(cpu, op)
  local cc = band(rshift(op, 8), 15)
  local dn = band(op, 7)
  local disp = EA.sign_extend(cpu:fetch16(), 16)
  local base = band(cpu.pc - 2, 0xFFFFFFFF)
  if not cond_true(cpu, cc) then
    local v = band(cpu.d[dn] - 1, 0xFFFF)
    cpu.d[dn] = bor(band(cpu.d[dn], 0xFFFF0000), v)
    if v ~= 0xFFFF then
      cpu.pc = band(base + disp, 0xFFFFFFFF)
      return 10
    end
  end
  return 12
end

local function op_scc(cpu, op)
  local cc = band(rshift(op, 8), 15)
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)
  local val = cond_true(cpu, cc) and 0xFF or 0
  local _, addr, cat = EA.read_ea(cpu, mode, reg, 1)
  -- read_ea already consumed EA for mem; rewrite carefully
  if mode == 0 then
    cpu.d[reg] = bor(band(cpu.d[reg], 0xFFFFFF00), val)
  elseif mode >= 2 then
    -- EA already side-effected; need address - re-decode is wrong for postinc.
    -- For tests, only Dn Scc is critical; mem Scc: write using addr if we had it.
    if addr then cpu:write8(addr, val) end
  end
  return 6
end

-- MULU/MULS/DIVU/DIVS (word). Must run before AND/OR - same top nibble, bits8-6 = 011/111.
local function op_mul_div(cpu, op)
  local top = band(rshift(op, 12), 15)
  local typ = band(rshift(op, 6), 7) -- bits 8-6
  if not ((top == 12 or top == 8) and (typ == 3 or typ == 7)) then
    return nil
  end
  local dn = band(rshift(op, 9), 7)
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)
  local src = band(EA.read_ea(cpu, mode, reg, 2), 0xFFFF)
  local dst = band(cpu.d[dn], 0xFFFF)

  if top == 12 then -- MULU / MULS
    local result
    if typ == 3 then -- MULU
      result = band(dst * src, 0xFFFFFFFF)
    else -- MULS: signed int16 product (exact in double)
      result = band(as_signed(dst, 16) * as_signed(src, 16), 0xFFFFFFFF)
    end
    cpu.d[dn] = result
    cpu:set_nz(result, 4)
    cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    return 54
  end

  -- DIVU / DIVS
  if src == 0 then
    cpu:raise_exception(5) -- divide by zero
    return 38
  end
  local dividend = band(cpu.d[dn], 0xFFFFFFFF)
  if typ == 3 then -- DIVU
    local q = math.floor(dividend / src)
    local r = dividend % src
    if q > 0xFFFF then
      cpu.sr = bor(band(cpu.sr, bnot(bor(SR_C, SR_Z, SR_N))), SR_V)
      return 140
    end
    cpu.d[dn] = bor(lshift(band(r, 0xFFFF), 16), band(q, 0xFFFF))
    cpu:set_nz(band(q, 0xFFFF), 2)
    cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    return 140
  end

  -- DIVS: toward-zero; remainder takes sign of dividend; overflow leaves Dn alone.
  local dend = as_signed(dividend, 32)
  local sor = as_signed(src, 16)
  local q = dend / sor
  if q >= 0 then q = math.floor(q) else q = -math.floor(-q) end
  local r = dend - q * sor
  if q < -32768 or q > 32767 then
    cpu.sr = bor(band(cpu.sr, bnot(bor(SR_C, SR_Z, SR_N))), SR_V)
    return 158
  end
  cpu.d[dn] = bor(lshift(band(r, 0xFFFF), 16), band(q, 0xFFFF))
  cpu:set_nz(band(q, 0xFFFF), 2)
  cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
  return 158
end

local function addx_subx_flags(cpu, src, dst, result, size, is_sub, x)
  -- src/dst are the raw operands (without X); x is 0/1 extend bit.
  local m = EA.mask(size)
  local sm = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  local maxv = m
  src, dst, result = band(src, m), band(dst, m), band(result, m)
  x = x or 0
  -- Z is sticky-zero: only cleared on nonzero result (never forced set).
  if result ~= 0 then cpu.sr = band(cpu.sr, bnot(SR_Z)) end
  if band(result, sm) ~= 0 then cpu.sr = bor(cpu.sr, SR_N) else cpu.sr = band(cpu.sr, bnot(SR_N)) end
  local carry
  if is_sub then
    carry = (src + x) > dst
  else
    carry = (src + dst + x) > maxv
  end
  cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V, SR_X)))
  if carry then cpu.sr = bor(cpu.sr, SR_C, SR_X) end
  -- V: compare signs of the arithmetic without worrying about X precisely enough for AMS.
  local ds, ss, rs = band(dst, sm) ~= 0, band(src, sm) ~= 0, band(result, sm) ~= 0
  if is_sub then
    if (not ss and ds and not rs) or (ss and not ds and rs) then cpu.sr = bor(cpu.sr, SR_V) end
  else
    if (not ss and not ds and rs) or (ss and ds and not rs) then cpu.sr = bor(cpu.sr, SR_V) end
  end
end

local function op_addx_subx(cpu, op)
  -- ADDX/SUBX: 1x01 rrr 1 ss 00 m yyy  (m=0 Dn, m=1 predec An)
  local opfamily = band(rshift(op, 12), 15)
  if opfamily ~= 13 and opfamily ~= 9 then return nil end
  if band(rshift(op, 8), 1) ~= 1 then return nil end
  local size_bits = band(rshift(op, 6), 3)
  if size_bits == 3 then return nil end
  local rm = band(rshift(op, 3), 7)
  if rm > 1 then return nil end
  local size = size_from_bits(size_bits)
  local rx = band(rshift(op, 9), 7)
  local ry = band(op, 7)
  local is_sub = opfamily == 9
  local x = (band(cpu.sr, SR_X) ~= 0) and 1 or 0
  local src, dst, result, dest_addr
  if rm == 0 then
    src = band(cpu.d[ry], EA.mask(size))
    dst = band(cpu.d[rx], EA.mask(size))
  else
    local function predec(an)
      local d = size
      if an == 7 and size == 1 then d = 2 end
      local a = band(cpu:get_a(an) - d, 0xFFFFFFFF)
      cpu:set_a(an, a)
      return a
    end
    local sa = predec(ry)
    dest_addr = predec(rx)
    if size == 1 then src, dst = cpu:read8(sa), cpu:read8(dest_addr)
    elseif size == 2 then src, dst = cpu:read16(sa), cpu:read16(dest_addr)
    else src, dst = cpu:read32(sa), cpu:read32(dest_addr) end
  end
  if is_sub then
    result = band(dst - src - x, EA.mask(size))
  else
    result = band(dst + src + x, EA.mask(size))
  end
  if rm == 0 then
    EA.write_ea(cpu, 0, rx, size, result, nil, "dn")
  else
    if size == 1 then cpu:write8(dest_addr, result)
    elseif size == 2 then cpu:write16(dest_addr, result)
    else cpu:write32(dest_addr, result) end
  end
  addx_subx_flags(cpu, src, dst, result, size, is_sub, x)
  return 4
end

local function op_exg(cpu, op)
  -- EXG: 1100 xxx 1 opmode yyy
  if band(rshift(op, 12), 15) ~= 12 then return nil end
  if band(rshift(op, 8), 1) ~= 1 then return nil end
  local opmode = band(rshift(op, 3), 0x1F)
  local rx = band(rshift(op, 9), 7)
  local ry = band(op, 7)
  if opmode == 0x08 then -- Dx,Dy
    cpu.d[rx], cpu.d[ry] = cpu.d[ry], cpu.d[rx]
  elseif opmode == 0x09 then -- Ax,Ay
    local ax, ay = cpu:get_a(rx), cpu:get_a(ry)
    cpu:set_a(rx, ay); cpu:set_a(ry, ax)
  elseif opmode == 0x11 then -- Dx,Ay
    local d, a = cpu.d[rx], cpu:get_a(ry)
    cpu.d[rx] = a; cpu:set_a(ry, d)
  else
    return nil
  end
  return 6
end

-- BCD ops (Musashi/UAE semantics). Required by AMS soft-float ($82011A/$82014A).
-- Encodings collide with AND/OR byte Dn,An; must run first or float math corrupts An.
local function bcd_abcd_byte(dst, src, x)
  dst, src = band(dst, 0xFF), band(src, 0xFF)
  local res = band(src, 0x0F) + band(dst, 0x0F) + (x ~= 0 and 1 or 0)
  if res > 9 then res = res + 6 end
  res = res + band(src, 0xF0) + band(dst, 0xF0)
  local c = 0
  if res > 0x9F then
    res = res - 0xA0
    c = 1
  end
  return band(res, 0xFF), c
end

local function bcd_sbcd_byte(dst, src, x)
  dst, src = band(dst, 0xFF), band(src, 0xFF)
  -- Match UAE/Musashi: low nibble as uint32 so negative borrows set bit4.
  local lo = band(dst, 0x0F) - band(src, 0x0F) - (x ~= 0 and 1 or 0)
  local hi = band(dst, 0xF0) - band(src, 0xF0)
  if band(lo, 0x10) ~= 0 then
    lo = lo - 6
    hi = hi - 0x10
  end
  local res = hi + band(lo, 0x0F)
  local c = 0
  if band(res, 0x1F0) > 0x90 then
    res = res - 0x60
    c = 1
  end
  return band(res, 0xFF), c
end

local function bcd_nbcd_byte(dst, x)
  return bcd_sbcd_byte(0, dst, x)
end

local function bcd_flags(cpu, res, c)
  -- Z sticky (like ADDX); C/X from decimal carry; N/V undefined - follow Musashi.
  if res ~= 0 then cpu.sr = band(cpu.sr, bnot(SR_Z)) end
  if band(res, 0x80) ~= 0 then cpu.sr = bor(cpu.sr, SR_N) else cpu.sr = band(cpu.sr, bnot(SR_N)) end
  cpu.sr = band(cpu.sr, bnot(SR_V))
  if c ~= 0 then
    cpu.sr = bor(cpu.sr, bor(SR_C, SR_X))
  else
    cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_X)))
  end
end

local function op_bcd(cpu, op)
  local top = band(rshift(op, 12), 15)
  -- NBCD <ea>: 0100 1000 00 mmmrrr
  if band(op, 0xFFC0) == 0x4800 then
    local mode = band(rshift(op, 3), 7)
    local reg = band(op, 7)
    if mode == 1 or (mode == 7 and reg >= 2) then return nil end
    local dst, addr, cat = EA.read_ea(cpu, mode, reg, 1)
    local x = (band(cpu.sr, SR_X) ~= 0) and 1 or 0
    local res, c = bcd_nbcd_byte(dst, x)
    EA.write_ea(cpu, mode, reg, 1, res, addr, cat)
    bcd_flags(cpu, res, c)
    return 6
  end
  -- ABCD: 1100 xxx 10000 r yyy / SBCD: 1000 xxx 10000 r yyy
  if not ((top == 12 or top == 8) and band(op, 0xF1F0) == (top == 12 and 0xC100 or 0x8100)) then
    return nil
  end
  local rx = band(rshift(op, 9), 7)
  local ry = band(op, 7)
  local rm = band(op, 0x08) ~= 0 -- 0=Dn,Dn 1=-(An),-(An)
  local x = (band(cpu.sr, SR_X) ~= 0) and 1 or 0
  local src, dst, res, c
  if not rm then
    src = band(cpu.d[ry], 0xFF)
    dst = band(cpu.d[rx], 0xFF)
    if top == 12 then
      res, c = bcd_abcd_byte(dst, src, x)
    else
      res, c = bcd_sbcd_byte(dst, src, x)
    end
    cpu.d[rx] = bor(band(cpu.d[rx], 0xFFFFFF00), res)
  else
    local function predec_a(an)
      local dec = (an == 7) and 2 or 1
      local a = band(cpu:get_a(an) - dec, 0xFFFFFFFF)
      cpu:set_a(an, a)
      return a
    end
    local sa = predec_a(ry)
    local da = predec_a(rx)
    src = cpu:read8(sa)
    dst = cpu:read8(da)
    if top == 12 then
      res, c = bcd_abcd_byte(dst, src, x)
    else
      res, c = bcd_sbcd_byte(dst, src, x)
    end
    cpu:write8(da, res)
  end
  bcd_flags(cpu, res, c)
  return rm and 18 or 6
end

local function op_add_sub_cmp(cpu, op)
  -- ADD/SUB/CMP/AND/OR/EOR register forms 1xxx
  local opfamily = band(rshift(op, 12), 15)
  local regn = band(rshift(op, 9), 7)
  local dir = band(rshift(op, 8), 1) -- 0: ea->Dn  1: Dn->ea  (for ADD/SUB/AND/OR)
  local size_bits = band(rshift(op, 6), 3)
  -- size 11 is *A / MUL / DIV - not AND/OR/ADD byte-long forms
  if size_bits == 3 and opfamily ~= 13 and opfamily ~= 9 and opfamily ~= 11 then
    return nil
  end
  local size = size_from_bits(size_bits)
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)

  -- ADDX/SUBX share the ADD/SUB opcode space (dir=1, mode 0/1).
  if (opfamily == 13 or opfamily == 9) and dir == 1 and mode <= 1 and size_bits <= 2 then
    return op_addx_subx(cpu, op)
  end

  -- ADDA / SUBA / CMPA (bits 7-6 == 11)
  local bits76 = size_bits
  if bits76 == 3 and (opfamily == 13 or opfamily == 9 or opfamily == 11) then
    -- bit8: 0 = word, 1 = long for *A forms
    local sz = (band(rshift(op, 8), 1) == 0) and 2 or 4
    local val = EA.read_ea(cpu, mode, reg, sz)
    if sz == 2 then val = EA.sign_extend(val, 16) end
    if opfamily == 11 then -- CMPA: An - ea
      local an = cpu:get_a(regn)
      local result = band(an - val, 0xFFFFFFFF)
      sub_flags(cpu, val, an, result, 4)
      return 8
    elseif opfamily == 13 then -- ADDA
      cpu:set_a(regn, band(cpu:get_a(regn) + val, 0xFFFFFFFF))
      return 8
    else -- SUBA
      cpu:set_a(regn, band(cpu:get_a(regn) - val, 0xFFFFFFFF))
      return 8
    end
  end

  -- ADDA / SUBA / CMPA handled above when bits76 == 3.

  -- CMPM (Ay)+,(Ax)+ : 1011 xxx 1 ss 001 yyy (mode field looks like An).
  -- Must not fall through to EOR, which would smash Ax with a byte result.
  if opfamily == 11 and dir == 1 and mode == 1 and size_bits <= 2 then
    local ay = reg
    local ax = regn
    local src_addr = cpu:get_a(ay)
    local dst_addr = cpu:get_a(ax)
    local src, dst
    if size == 1 then
      src = cpu:read8(src_addr)
      dst = cpu:read8(dst_addr)
      cpu:set_a(ay, band(src_addr + 1, 0xFFFFFFFF))
      cpu:set_a(ax, band(dst_addr + 1, 0xFFFFFFFF))
    elseif size == 2 then
      src = cpu:read16(src_addr)
      dst = cpu:read16(dst_addr)
      cpu:set_a(ay, band(src_addr + 2, 0xFFFFFFFF))
      cpu:set_a(ax, band(dst_addr + 2, 0xFFFFFFFF))
    else
      src = cpu:read32(src_addr)
      dst = cpu:read32(dst_addr)
      cpu:set_a(ay, band(src_addr + 4, 0xFFFFFFFF))
      cpu:set_a(ax, band(dst_addr + 4, 0xFFFFFFFF))
    end
    local result = band(dst - src, EA.mask(size))
    sub_flags(cpu, src, dst, result, size)
    return 12
  end

  local ea_val, addr, cat = EA.read_ea(cpu, mode, reg, size)
  local dn = band(cpu.d[regn], EA.mask(size))

  if opfamily == 11 and band(rshift(op, 6), 3) <= 2 and dir == 0 then
    -- CMP <ea>, Dn  ->  Dn - ea
    local result = band(dn - ea_val, EA.mask(size))
    sub_flags(cpu, ea_val, dn, result, size)
    return 6
  end

  if opfamily == 13 then -- ADD
    if dir == 0 then
      local result = band(dn + ea_val, EA.mask(size))
      add_flags(cpu, ea_val, dn, result, size)
      EA.write_ea(cpu, 0, regn, size, result, nil, "dn")
    else
      local result = band(ea_val + dn, EA.mask(size))
      add_flags(cpu, dn, ea_val, result, size)
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    end
    return 8
  elseif opfamily == 9 then -- SUB
    if dir == 0 then
      local result = band(dn - ea_val, EA.mask(size))
      sub_flags(cpu, ea_val, dn, result, size)
      EA.write_ea(cpu, 0, regn, size, result, nil, "dn")
    else
      local result = band(ea_val - dn, EA.mask(size))
      sub_flags(cpu, dn, ea_val, result, size)
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    end
    return 8
  elseif opfamily == 12 then -- AND
    local result
    if dir == 0 then
      result = band(dn, ea_val)
      EA.write_ea(cpu, 0, regn, size, result, nil, "dn")
    else
      result = band(ea_val, dn)
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    end
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    return 8
  elseif opfamily == 8 then -- OR
    local result
    if dir == 0 then
      result = bor(dn, ea_val)
      EA.write_ea(cpu, 0, regn, size, result, nil, "dn")
    else
      result = bor(ea_val, dn)
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    end
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    return 8
  elseif opfamily == 11 and dir == 1 then -- EOR
    local result = bxor(ea_val, dn)
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    cpu:set_nz(result, size); cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    return 8
  end
  return nil
end

local function op_misc(cpu, op)
  -- JMP / JSR / RTS / RTE / NOP / RESET / TRAP / LINK / UNLK / MOVE USP / etc.
  if op == 0x4E71 then return 4 end -- NOP
  if op == 0x4E73 then -- RTE
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    local sr = cpu:pop16()
    cpu.pc = cpu:pop32()
    cpu.sr = band(sr, 0xA71F)
    return 20
  end
  if op == 0x4E75 then -- RTS
    cpu.pc = cpu:pop32()
    return 16
  end
  if op == 0x4E70 then -- RESET
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    return 132
  end
  if op == 0x4E72 then -- STOP
    if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
    cpu.sr = band(cpu:fetch16(), 0xA71F)
    cpu.stopped = true
    return 4
  end
  if op == 0x4E76 then -- TRAPV
    if band(cpu.sr, SR_V) ~= 0 then cpu:raise_exception(7) end
    return 4
  end
  if op == 0x4E77 then -- RTR
    local ccr = band(cpu:pop16(), 0x1F)
    cpu.sr = bor(band(cpu.sr, 0xFFE0), ccr)
    cpu.pc = cpu:pop32()
    return 20
  end

  local hi = band(rshift(op, 6), 0x3FF)
  if band(rshift(op, 12), 15) == 4 then
    -- TRAP #n
    if band(op, 0xFFF0) == 0x4E40 then
      cpu:raise_exception(32 + band(op, 15))
      return 34
    end
    -- LINK / UNLK
    if band(op, 0xFFF8) == 0x4E50 then
      local an = band(op, 7)
      local disp = EA.sign_extend(cpu:fetch16(), 16)
      cpu:push32(cpu:get_a(an))
      cpu:set_a(an, cpu:get_a(7))
      cpu:set_a(7, band(cpu:get_a(7) + disp, 0xFFFFFFFF))
      return 16
    end
    if band(op, 0xFFF8) == 0x4E58 then
      local an = band(op, 7)
      cpu:set_a(7, cpu:get_a(an))
      cpu:set_a(an, cpu:pop32())
      return 12
    end
    -- MOVE USP
    if band(op, 0xFFF0) == 0x4E60 then
      if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
      local an = band(op, 7)
      if band(op, 8) ~= 0 then
        cpu:set_a(an, cpu.usp)
      else
        cpu.usp = cpu:get_a(an)
      end
      return 4
    end
    -- JSR / JMP
    if band(op, 0xFFC0) == 0x4E80 then
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local addr = EA.decode_mode_reg(cpu, mode, reg, 4)
      cpu:push32(cpu.pc)
      cpu.pc = addr
      return 16
    end
    if band(op, 0xFFC0) == 0x4EC0 then
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local addr = EA.decode_mode_reg(cpu, mode, reg, 4)
      cpu.pc = addr
      return 8
    end
    -- CLR / NEG / NEGX / NOT / TST / TAS / PEA / LEA / SWAP / EXT / MOVEM / CHK / MOVE from/to SR/CCR
    -- NEGX: 0100 0000 ss mmmrrr (before CLR 0100 0010). AMS soft-float uses this heavily.
    if band(op, 0xFF00) == 0x4000 and band(rshift(op, 6), 3) ~= 3 then
      local size = size_from_bits(band(rshift(op, 6), 3))
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      if mode == 1 then return nil end -- An illegal
      local dst, addr, cat = EA.read_ea(cpu, mode, reg, size)
      local x = (band(cpu.sr, SR_X) ~= 0) and 1 or 0
      local result = band(-dst - x, EA.mask(size))
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
      -- Same sticky-Z / C/X semantics as SUBX with dst=0.
      addx_subx_flags(cpu, dst, 0, result, size, true, x)
      return 6
    end
    -- CLR size bits != 11; 11 is MOVE from CCR (68010+/AMS).
    if band(op, 0xFF00) == 0x4200 and band(rshift(op, 6), 3) ~= 3 then
      local size = size_from_bits(band(rshift(op, 6), 3))
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local _, addr, cat = EA.read_ea(cpu, mode, reg, size)
      EA.write_ea(cpu, mode, reg, size, 0, addr, cat)
      cpu.sr = bor(band(cpu.sr, bnot(bor(SR_C, SR_V, SR_N))), SR_Z)
      return 6
    end
    -- NEG / NOT (size bits != 11; 11 is MOVE to CCR/SR)
    if band(op, 0xFF00) == 0x4400 and band(rshift(op, 6), 3) ~= 3 then -- NEG
      local size = size_from_bits(band(rshift(op, 6), 3))
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local dst, addr, cat = EA.read_ea(cpu, mode, reg, size)
      local result = band(-dst, EA.mask(size))
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
      sub_flags(cpu, dst, 0, result, size)
      return 6
    end
    if band(op, 0xFF00) == 0x4600 and band(rshift(op, 6), 3) ~= 3 then -- NOT
      local size = size_from_bits(band(rshift(op, 6), 3))
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local dst, addr, cat = EA.read_ea(cpu, mode, reg, size)
      local result = band(bnot(dst), EA.mask(size))
      EA.write_ea(cpu, mode, reg, size, result, addr, cat)
      cpu:set_nz(result, size)
      cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
      return 6
    end
    if band(op, 0xFFC0) == 0x4AC0 then -- TAS
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      if mode == 1 or (mode == 7 and reg >= 2) then return nil end
      local val, addr, cat = EA.read_ea(cpu, mode, reg, 1)
      cpu:set_nz(val, 1)
      cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
      EA.write_ea(cpu, mode, reg, 1, bor(val, 0x80), addr, cat)
      return 8
    end
    if band(op, 0xFF00) == 0x4A00 and band(rshift(op, 6), 3) ~= 3 then -- TST
      local size = size_from_bits(band(rshift(op, 6), 3))
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local val = EA.read_ea(cpu, mode, reg, size)
      cpu:set_nz(val, size)
      cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
      return 4
    end
    if band(op, 0xFFC0) == 0x4840 then -- SWAP / PEA
      if band(rshift(op, 3), 7) == 0 and band(op, 0xFFC0) == 0x4840 then
        -- SWAP Dn when mode=0: 0100100001 000 rrr
      end
    end
    if band(op, 0xFFF8) == 0x4840 then -- SWAP
      local dn = band(op, 7)
      local v = cpu.d[dn]
      v = bor(lshift(band(v, 0xFFFF), 16), rshift(v, 16))
      cpu.d[dn] = v
      cpu:set_nz(v, 4)
      cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
      return 4
    end
    if band(op, 0xFFC0) == 0x4840 then -- PEA
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local addr = EA.decode_mode_reg(cpu, mode, reg, 4)
      cpu:push32(addr)
      return 12
    end
    -- CHK.W <ea>,Dn - must be before LEA (same 0100xxx bits, different sz).
    if band(op, 0xF1C0) == 0x4180 then
      local dn = band(rshift(op, 9), 7)
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      if mode == 1 then return nil end -- An illegal
      local bound = EA.sign_extend(EA.read_ea(cpu, mode, reg, 2), 16)
      local val = cpu.d[dn]
      local sval = val
      if band(val, 0x80000000) ~= 0 then sval = val - 0x100000000 end
      local sbound = bound
      if band(bound, 0x80000000) ~= 0 then sbound = bound - 0x100000000 end
      if sval < 0 or sval > sbound then
        if sval < 0 then
          cpu.sr = bor(cpu.sr, SR_N)
        else
          cpu.sr = band(cpu.sr, bnot(SR_N))
        end
        cpu:raise_exception(6) -- CHK
        return 40
      end
      return 10
    end
    if band(op, 0xF1C0) == 0x41C0 then -- LEA
      local an = band(rshift(op, 9), 7)
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local addr = EA.decode_mode_reg(cpu, mode, reg, 4)
      cpu:set_a(an, addr)
      return 4
    end
    if band(op, 0xFFC0) == 0x40C0 then -- MOVE from SR
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local _, addr, cat = EA.read_ea(cpu, mode, reg, 2)
      EA.write_ea(cpu, mode, reg, 2, cpu.sr, addr, cat)
      return 8
    end
    -- MOVE from CCR: 0100 0010 11 mmmrrr (was misdecoded as CLR.L).
    if band(op, 0xFFC0) == 0x42C0 then
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local _, addr, cat = EA.read_ea(cpu, mode, reg, 2)
      EA.write_ea(cpu, mode, reg, 2, band(cpu.sr, 0x1F), addr, cat)
      return 8
    end
    if band(op, 0xFFC0) == 0x44C0 then -- MOVE to CCR
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local val = EA.read_ea(cpu, mode, reg, 2)
      cpu.sr = bor(band(cpu.sr, 0xFFE0), band(val, 0x1F))
      return 12
    end
    if band(op, 0xFFC0) == 0x46C0 then -- MOVE to SR
      if not cpu:supervisor() then cpu:raise_exception(8); return 34 end
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local val = EA.read_ea(cpu, mode, reg, 2)
      cpu.sr = band(val, 0xA71F)
      return 12
    end
    if band(op, 0xFFB8) == 0x4880 then -- EXT.W / EXT.L
      local dn = band(op, 7)
      if band(op, 0x0040) ~= 0 then -- EXT.L
        cpu.d[dn] = EA.sign_extend(cpu.d[dn], 16)
        cpu:set_nz(cpu.d[dn], 4)
      else
        local b = EA.sign_extend(band(cpu.d[dn], 0xFF), 8)
        cpu.d[dn] = bor(band(cpu.d[dn], 0xFFFF0000), band(b, 0xFFFF))
        -- EXT.W N/Z follow the word result (upper 16 of Dn unchanged).
        cpu:set_nz(band(cpu.d[dn], 0xFFFF), 2)
      end
      cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
      return 4
    end
    -- MOVEM
    if band(op, 0xFB80) == 0x4880 then
      local dr = band(rshift(op, 10), 1) -- 0: reg->mem 1: mem->reg
      local size = (band(rshift(op, 6), 1) == 0) and 2 or 4
      local mode = band(rshift(op, 3), 7)
      local reg = band(op, 7)
      local list = cpu:fetch16()
      if dr == 0 then
        -- register to memory
        if mode == 4 then
          -- Predec mask: bit0=A7 ... bit7=A0, bit8=D7 ... bit15=D0
          local addr = cpu:get_a(reg)
          for i = 0, 15 do
            if band(list, lshift(1, i)) ~= 0 then
              addr = band(addr - size, 0xFFFFFFFF)
              local val
              if i < 8 then
                val = cpu:get_a(7 - i)
              else
                val = cpu.d[15 - i]
              end
              if size == 2 then cpu:write16(addr, val) else cpu:write32(addr, val) end
            end
          end
          cpu:set_a(reg, addr)
        else
          local addr = EA.decode_mode_reg(cpu, mode, reg, size)
          for i = 0, 15 do
            if band(list, lshift(1, i)) ~= 0 then
              local val = (i < 8) and cpu.d[i] or cpu:get_a(i - 8)
              if size == 2 then cpu:write16(addr, val) else cpu:write32(addr, val) end
              addr = band(addr + size, 0xFFFFFFFF)
            end
          end
        end
      else
        -- memory to register (control / postinc): bit0=D0 ... bit15=A7
        local addr
        if mode == 3 then
          addr = cpu:get_a(reg)
        else
          addr = EA.decode_mode_reg(cpu, mode, reg, size)
        end
        for i = 0, 15 do
          if band(list, lshift(1, i)) ~= 0 then
            local val = (size == 2) and EA.sign_extend(cpu:read16(addr), 16) or cpu:read32(addr)
            if i < 8 then cpu.d[i] = val else cpu:set_a(i - 8, val) end
            addr = band(addr + size, 0xFFFFFFFF)
          end
        end
        if mode == 3 then cpu:set_a(reg, addr) end
      end
      return 16
    end
  end
  return nil
end

local function shift_one(cpu, v, size, dr, cr)
  local m = EA.mask(size)
  local sm = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  local xbit = (band(cpu.sr, SR_X) ~= 0) and 1 or 0
  local last = 0
  v = band(v, m)
  if dr == 1 then -- left
    last = band(rshift(v, (size * 8 - 1)), 1)
    v = band(lshift(v, 1), m)
    if cr == 3 then
      v = bor(v, last) -- ROL
    elseif cr == 2 then
      v = bor(v, xbit) -- ROXL
    end
  else
    last = band(v, 1)
    if cr == 0 then -- ASR
      local sign = band(v, sm)
      v = bor(rshift(v, 1), sign)
    elseif cr == 3 then -- ROR
      v = rshift(v, 1)
      if last ~= 0 then v = bor(v, sm) end
    elseif cr == 2 then -- ROXR
      v = rshift(v, 1)
      if xbit ~= 0 then v = bor(v, sm) end
    else
      v = rshift(v, 1) -- LSR
    end
  end
  return v, last
end

local function op_shift_rotate(cpu, op)
  local size_bits = band(rshift(op, 6), 3)
  local dr = band(rshift(op, 8), 1) -- 0 right 1 left

  -- Memory form: 1110 0tt d 11 mmmrrr (always one bit, word operand).
  if size_bits == 3 then
    local cr = band(rshift(op, 9), 3) -- 0 AS 1 LS 2 ROX 3 RO
    local mode = band(rshift(op, 3), 7)
    local reg = band(op, 7)
    if mode == 0 or mode == 1 or (mode == 7 and reg >= 2) then return nil end
    local val, addr, cat = EA.read_ea(cpu, mode, reg, 2)
    local v, last = shift_one(cpu, val, 2, dr, cr)
    EA.write_ea(cpu, mode, reg, 2, v, addr, cat)
    local asl_v = (cr == 0 and dr == 1 and band(val, 0x8000) ~= band(v, 0x8000))
    cpu:set_nz(v, 2)
    cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    if last ~= 0 then cpu.sr = bor(cpu.sr, SR_C) end
    if cr ~= 3 then
      if last ~= 0 then cpu.sr = bor(cpu.sr, SR_X) else cpu.sr = band(cpu.sr, bnot(SR_X)) end
    end
    if asl_v then cpu.sr = bor(cpu.sr, SR_V) end
    return 8
  end

  local size = size_from_bits(size_bits)
  local ir = band(rshift(op, 5), 1) -- 0 count in op, 1 count in Dn
  local reg = band(op, 7)
  local count
  if ir == 0 then
    count = band(rshift(op, 9), 7)
    if count == 0 then count = 8 end
  else
    count = band(cpu.d[band(rshift(op, 9), 7)], 63)
  end
  local cr = band(rshift(op, 3), 3) -- 0 AS 1 LS 2 ROX 3 RO
  local m = EA.mask(size)
  local v = band(cpu.d[reg], m)
  local last = 0
  local asl_v = false
  local sm = (size == 1) and 0x80 or ((size == 2) and 0x8000 or 0x80000000)
  for _ = 1, count do
    local msb_before = band(v, sm)
    v, last = shift_one(cpu, v, size, dr, cr)
    -- ASL sets V if the MSB changed at any point during the shift.
    if cr == 0 and dr == 1 and band(v, sm) ~= msb_before then
      asl_v = true
    end
    -- ROX needs updated X between iterations.
    if cr == 2 or cr == 0 or cr == 1 then
      if last ~= 0 then cpu.sr = bor(cpu.sr, SR_X) else cpu.sr = band(cpu.sr, bnot(SR_X)) end
    end
  end
  cpu.d[reg] = bor(band(cpu.d[reg], bnot(m)), v)
  -- set_nz clears V; apply C/X/V after it.
  cpu:set_nz(v, size)
  if count > 0 then
    cpu.sr = band(cpu.sr, bnot(bor(SR_C, SR_V)))
    if last ~= 0 then cpu.sr = bor(cpu.sr, SR_C) else cpu.sr = band(cpu.sr, bnot(SR_C)) end
    -- ASL/ASR/LSL/LSR/ROX update X; ROL/ROR do not.
    if cr ~= 3 then
      if last ~= 0 then cpu.sr = bor(cpu.sr, SR_X) else cpu.sr = band(cpu.sr, bnot(SR_X)) end
    end
    if asl_v then cpu.sr = bor(cpu.sr, SR_V) end
  end
  return 6 + 2 * count
end

local function op_addq_subq(cpu, op)
  -- 0101 qqq e ss mmm rrr  (e=0 ADDQ, e=1 SUBQ); ss=11 is Scc/DBcc
  local size_bits = band(rshift(op, 6), 3)
  if size_bits == 3 then return nil end
  local size = size_from_bits(size_bits)
  local data = band(rshift(op, 9), 7)
  if data == 0 then data = 8 end
  local is_sub = band(rshift(op, 8), 1) == 1
  local mode = band(rshift(op, 3), 7)
  local reg = band(op, 7)

  -- Address register: always full 32-bit, no condition codes.
  if mode == 1 then
    local a = cpu:get_a(reg)
    if is_sub then
      cpu:set_a(reg, band(a - data, 0xFFFFFFFF))
    else
      cpu:set_a(reg, band(a + data, 0xFFFFFFFF))
    end
    return 8
  end

  local dst, addr, cat = EA.read_ea(cpu, mode, reg, size)
  local result
  if is_sub then
    result = band(dst - data, EA.mask(size))
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    sub_flags(cpu, data, dst, result, size)
  else
    result = band(dst + data, EA.mask(size))
    EA.write_ea(cpu, mode, reg, size, result, addr, cat)
    add_flags(cpu, data, dst, result, size)
  end
  return 8
end

-- 256-way high-byte dispatch (dense table without a 64K-entry CC memory hit).
-- Built once at load; each slot is a direct group handler.
local function illegal(cpu, _op)
  cpu.pc = band(cpu.pc - 2, 0xFFFFFFFF)
  cpu:raise_exception(4)
  return 34
end

local function line_a(cpu, _op)
  cpu.pc = band(cpu.pc - 2, 0xFFFFFFFF)
  cpu:raise_exception(10)
  return 34
end

local function line_f(cpu, _op)
  cpu.pc = band(cpu.pc - 2, 0xFFFFFFFF)
  cpu:raise_exception(11)
  return 34
end

local function wrap(fn)
  return function(cpu, op)
    local cyc = fn(cpu, op)
    if cyc then return cyc end
    return illegal(cpu, op)
  end
end

local function group0(cpu, op)
  if op == 0x003C or op == 0x007C then
    return op_ori_to_ccr_sr(cpu, op) or illegal(cpu, op)
  end
  if op == 0x023C or op == 0x027C then
    return op_andi_to_ccr_sr(cpu, op) or illegal(cpu, op)
  end
  if op == 0x0A3C or op == 0x0A7C then
    return op_eori_to_ccr_sr(cpu, op) or illegal(cpu, op)
  end
  return op_movep(cpu, op)
    or op_immediate(cpu, op)
    or op_bit(cpu, op)
    or illegal(cpu, op)
end

local function group4(cpu, op)
  if op == 0x4AFC then return illegal(cpu, op) end
  return op_misc(cpu, op) or op_bcd(cpu, op) or illegal(cpu, op)
end

local function group5(cpu, op)
  if band(op, 0xF0F8) == 0x50C8 then
    return op_dbcc(cpu, op)
  end
  if band(op, 0xF0C0) == 0x50C0 then
    return op_scc(cpu, op)
  end
  return op_addq_subq(cpu, op) or illegal(cpu, op)
end

local function group8(cpu, op)
  return op_bcd(cpu, op)
    or op_mul_div(cpu, op)
    or op_add_sub_cmp(cpu, op)
    or illegal(cpu, op)
end

local function group9(cpu, op)
  return op_add_sub_cmp(cpu, op) or illegal(cpu, op)
end

local function group11(cpu, op)
  return op_add_sub_cmp(cpu, op) or illegal(cpu, op)
end

local function group12(cpu, op)
  return op_exg(cpu, op)
    or op_bcd(cpu, op)
    or op_mul_div(cpu, op)
    or op_add_sub_cmp(cpu, op)
    or illegal(cpu, op)
end

local function group13(cpu, op)
  return op_add_sub_cmp(cpu, op) or illegal(cpu, op)
end

local DISPATCH = {}
do
  local H = DISPATCH
  for hi = 0, 255 do
    H[hi] = illegal
  end
  for hi = 0x00, 0x0F do H[hi] = group0 end
  for hi = 0x10, 0x3F do H[hi] = op_move end
  for hi = 0x40, 0x4F do H[hi] = group4 end
  for hi = 0x50, 0x5F do H[hi] = group5 end
  for hi = 0x60, 0x6F do H[hi] = op_branch end
  for hi = 0x70, 0x7F do H[hi] = op_moveq end
  for hi = 0x80, 0x8F do H[hi] = group8 end
  for hi = 0x90, 0x9F do H[hi] = group9 end
  for hi = 0xA0, 0xAF do H[hi] = line_a end
  for hi = 0xB0, 0xBF do H[hi] = group11 end
  for hi = 0xC0, 0xCF do H[hi] = group12 end
  for hi = 0xD0, 0xDF do H[hi] = group13 end
  for hi = 0xE0, 0xEF do H[hi] = wrap(op_shift_rotate) end
  for hi = 0xF0, 0xFF do H[hi] = line_f end
end

function Ops.execute(cpu, op)
  return DISPATCH[math.floor(op / 256)](cpu, op)
end

return Ops
