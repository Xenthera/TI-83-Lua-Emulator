-- Z80 opcode implementations. Returns T-states consumed.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local u8, u16, pair = bit.u8, bit.u16, bit.pair

local S, Z, H, P, N, C = 0x80, 0x40, 0x10, 0x04, 0x02, 0x01
local X, Y = 0x08, 0x20

local M = {}

local function idx_addr(cpu, xy)
  local d = cpu:fetch_disp()
  return u16(xy + d)
end

local function get_xy_r(cpu, xy_name, i)
  if i == 4 then
    return xy_name == "ix" and cpu:ixh() or cpu:iyh()
  elseif i == 5 then
    return xy_name == "ix" and cpu:ixl() or cpu:iyl()
  elseif i == 6 then
    local addr = idx_addr(cpu, xy_name == "ix" and cpu.ix or cpu.iy)
    return cpu:read8(addr), addr
  else
    return cpu:get_r8(i)
  end
end

local function set_xy_r(cpu, xy_name, i, v, addr)
  if i == 4 then
    if xy_name == "ix" then cpu:set_ixh(v) else cpu:set_iyh(v) end
  elseif i == 5 then
    if xy_name == "ix" then cpu:set_ixl(v) else cpu:set_iyl(v) end
  elseif i == 6 then
    cpu:write8(addr, v)
  else
    cpu:set_r8(i, v)
  end
end

local function exec_cb(cpu)
  cpu:inc_r()
  local op = cpu:fetch8()
  local y = band(rshift(op, 3), 7)
  local z = band(op, 7)
  local x = rshift(op, 6)

  if x == 0 then
    local v = cpu:get_r8(z)
    local res
    if y == 0 then res = cpu:op_rlc(v)
    elseif y == 1 then res = cpu:op_rrc(v)
    elseif y == 2 then res = cpu:op_rl(v)
    elseif y == 3 then res = cpu:op_rr(v)
    elseif y == 4 then res = cpu:op_sla(v)
    elseif y == 5 then res = cpu:op_sra(v)
    elseif y == 6 then res = cpu:op_sll(v)
    else res = cpu:op_srl(v) end
    cpu:set_r8(z, res)
    return z == 6 and 15 or 8
  elseif x == 1 then
    local v = cpu:get_r8(z)
    local f = band(cpu:f(), C)
    f = bor(f, H)
    if band(v, lshift(1, y)) == 0 then
      f = bor(f, bor(Z, P))
    elseif y == 7 then
      f = bor(f, S)
    end
    if z ~= 6 then
      f = bor(f, band(v, bor(X, Y)))
    end
    cpu:set_f(f)
    return z == 6 and 12 or 8
  elseif x == 2 then
    local v = band(cpu:get_r8(z), band(bit.bnot(lshift(1, y)), 0xFF))
    cpu:set_r8(z, u8(v))
    return z == 6 and 15 or 8
  else
    local v = bor(cpu:get_r8(z), lshift(1, y))
    cpu:set_r8(z, u8(v))
    return z == 6 and 15 or 8
  end
end

local function exec_ddcb_fdcb(cpu, xy)
  local d = cpu:fetch_disp()
  local addr = u16(xy + d)
  cpu:inc_r()
  local op = cpu:fetch8()
  local y = band(rshift(op, 3), 7)
  local z = band(op, 7)
  local x = rshift(op, 6)
  local v = cpu:read8(addr)

  if x == 0 then
    local res
    if y == 0 then res = cpu:op_rlc(v)
    elseif y == 1 then res = cpu:op_rrc(v)
    elseif y == 2 then res = cpu:op_rl(v)
    elseif y == 3 then res = cpu:op_rr(v)
    elseif y == 4 then res = cpu:op_sla(v)
    elseif y == 5 then res = cpu:op_sra(v)
    elseif y == 6 then res = cpu:op_sll(v)
    else res = cpu:op_srl(v) end
    cpu:write8(addr, res)
    if z ~= 6 then cpu:set_r8(z, res) end
    return 23
  elseif x == 1 then
    local f = band(cpu:f(), C)
    f = bor(f, H)
    if band(v, lshift(1, y)) == 0 then
      f = bor(f, bor(Z, P))
    elseif y == 7 then
      f = bor(f, S)
    end
    cpu:set_f(f)
    return 20
  elseif x == 2 then
    local res = band(v, band(bit.bnot(lshift(1, y)), 0xFF))
    cpu:write8(addr, u8(res))
    if z ~= 6 then cpu:set_r8(z, u8(res)) end
    return 23
  else
    local res = bor(v, lshift(1, y))
    cpu:write8(addr, u8(res))
    if z ~= 6 then cpu:set_r8(z, u8(res)) end
    return 23
  end
end

local function exec_ed(cpu)
  cpu:inc_r()
  local op = cpu:fetch8()
  local y = band(rshift(op, 3), 7)
  local z = band(op, 7)
  local x = rshift(op, 6)
  local p = band(rshift(op, 4), 3)
  local q = band(rshift(op, 3), 1)

  if x == 1 then
    if z == 0 then
      -- IN r,(C)
      local v = cpu.bus.in_port(cpu:c())
      if y ~= 6 then cpu:set_r8(y, v) end
      local f = band(cpu:f(), C)
      f = bor(f, (function()
        local ff = 0
        if band(v, 0x80) ~= 0 then ff = bor(ff, S) end
        if v == 0 then ff = bor(ff, Z) end
        ff = bor(ff, band(v, bor(X, Y)))
        local n, vv = v, 0
        while n > 0 do vv = vv + band(n, 1); n = rshift(n, 1) end
        if band(vv, 1) == 0 then ff = bor(ff, P) end
        return ff
      end)())
      cpu:set_f(f)
      return 12
    elseif z == 1 then
      -- OUT (C),r
      local v = y == 6 and 0 or cpu:get_r8(y)
      cpu.bus.out_port(cpu:c(), v)
      return 12
    elseif z == 2 then
      if q == 0 then
        cpu.hl = cpu:sbc16(cpu.hl, cpu:get_rp(p))
      else
        cpu.hl = cpu:adc16(cpu.hl, cpu:get_rp(p))
      end
      return 15
    elseif z == 3 then
      if q == 0 then
        local addr = cpu:fetch16()
        cpu:write16(addr, cpu:get_rp(p))
      else
        local addr = cpu:fetch16()
        cpu:set_rp(p, cpu:read16(addr))
      end
      return 20
    elseif z == 4 then
      -- NEG
      local a = cpu:a()
      cpu:set_a(cpu:sub8(0, a, false))
      return 8
    elseif z == 5 then
      if y == 1 then
        -- RETI
        cpu.pc = cpu:pop16()
        cpu.iff1 = cpu.iff2
        return 14
      else
        -- RETN
        cpu.pc = cpu:pop16()
        cpu.iff1 = cpu.iff2
        return 14
      end
    elseif z == 6 then
      -- IM 0/1/2 (including undocumented aliases)
      -- ED46/4E/66/6E → IM 0; ED56/76 → IM 1; ED5E/7E → IM 2
      if y == 0 or y == 1 or y == 4 or y == 5 then
        cpu.im = 0
      elseif y == 2 or y == 6 then
        cpu.im = 1
      else -- y == 3 (ED5E) or y == 7 (ED7E)
        cpu.im = 2
      end
      return 8
    elseif z == 7 then
      if y == 0 then -- LD I,A
        cpu.i = cpu:a()
        return 9
      elseif y == 1 then -- LD R,A
        cpu.r = cpu:a()
        return 9
      elseif y == 2 then -- LD A,I
        local v = cpu.i
        cpu:set_a(v)
        local f = band(cpu:f(), C)
        if band(v, 0x80) ~= 0 then f = bor(f, S) end
        if v == 0 then f = bor(f, Z) end
        f = bor(f, band(v, bor(X, Y)))
        if cpu.iff2 then f = bor(f, P) end
        cpu:set_f(f)
        return 9
      elseif y == 3 then -- LD A,R
        local v = cpu.r
        cpu:set_a(v)
        local f = band(cpu:f(), C)
        if band(v, 0x80) ~= 0 then f = bor(f, S) end
        if v == 0 then f = bor(f, Z) end
        f = bor(f, band(v, bor(X, Y)))
        if cpu.iff2 then f = bor(f, P) end
        cpu:set_f(f)
        return 9
      elseif y == 4 then -- RRD
        local a = cpu:a()
        local m = cpu:read8(cpu.hl)
        local newm = bor(lshift(band(a, 0x0F), 4), rshift(m, 4))
        local newa = bor(band(a, 0xF0), band(m, 0x0F))
        cpu:write8(cpu.hl, u8(newm))
        cpu:set_a(newa)
        local f = band(cpu:f(), C)
        local v = newa
        if band(v, 0x80) ~= 0 then f = bor(f, S) end
        if v == 0 then f = bor(f, Z) end
        f = bor(f, band(v, bor(X, Y)))
        local n, vv = v, 0
        while n > 0 do vv = vv + band(n, 1); n = rshift(n, 1) end
        if band(vv, 1) == 0 then f = bor(f, P) end
        cpu:set_f(f)
        return 18
      elseif y == 5 then -- RLD
        local a = cpu:a()
        local m = cpu:read8(cpu.hl)
        local newa = bor(band(a, 0xF0), rshift(m, 4))
        local newm = bor(lshift(band(m, 0x0F), 4), band(a, 0x0F))
        cpu:write8(cpu.hl, u8(newm))
        cpu:set_a(newa)
        local f = band(cpu:f(), C)
        local v = newa
        if band(v, 0x80) ~= 0 then f = bor(f, S) end
        if v == 0 then f = bor(f, Z) end
        f = bor(f, band(v, bor(X, Y)))
        local n, vv = v, 0
        while n > 0 do vv = vv + band(n, 1); n = rshift(n, 1) end
        if band(vv, 1) == 0 then f = bor(f, P) end
        cpu:set_f(f)
        return 18
      else
        return 8 -- NOP
      end
    end
  elseif x == 2 then
    -- block instructions
    if z == 0 then
      -- LDI/LDD/LDIR/LDDR
      local v = cpu:read8(cpu.hl)
      cpu:write8(cpu.de, v)
      if y == 0 or y == 1 then -- LDI / LDIR? y=4 LDI, y=0? 
      end
    end
    -- Decode ED block: A0=LDI A8=LDD B0=LDIR B8=LDDR
    --                   A1=CPI A9=CPD B1=CPIR B9=CPDR
    --                   A2=INI AA=IND B2=INIR BA=INDR
    --                   A3=OUTI AB=OUTD B3=OTIR BB=OTDR
  end

  -- Explicit ED block ops
  if op == 0xA0 or op == 0xA8 or op == 0xB0 or op == 0xB8 then
    local v = cpu:read8(cpu.hl)
    cpu:write8(cpu.de, v)
    cpu.bc = u16(cpu.bc - 1)
    if op == 0xA0 or op == 0xB0 then
      cpu.hl = u16(cpu.hl + 1)
      cpu.de = u16(cpu.de + 1)
    else
      cpu.hl = u16(cpu.hl - 1)
      cpu.de = u16(cpu.de - 1)
    end
    local f = band(cpu:f(), bor(S, Z, C))
    local n = u8(v + cpu:a())
    if band(n, 0x02) ~= 0 then f = bor(f, Y) end
    if band(n, 0x08) ~= 0 then f = bor(f, X) end
    if cpu.bc ~= 0 then f = bor(f, P) end
    cpu:set_f(f)
    if (op == 0xB0 or op == 0xB8) and cpu.bc ~= 0 then
      cpu.pc = u16(cpu.pc - 2)
      return 21
    end
    return 16
  elseif op == 0xA1 or op == 0xA9 or op == 0xB1 or op == 0xB9 then
    local v = cpu:read8(cpu.hl)
    local a = cpu:a()
    local res = u8(a - v)
    cpu.bc = u16(cpu.bc - 1)
    if op == 0xA1 or op == 0xB1 then
      cpu.hl = u16(cpu.hl + 1)
    else
      cpu.hl = u16(cpu.hl - 1)
    end
    local f = bor(band(cpu:f(), C), N)
    if band(res, 0x80) ~= 0 then f = bor(f, S) end
    if res == 0 then f = bor(f, Z) end
    if band(bxor(a, bxor(v, res)), 0x10) ~= 0 then f = bor(f, H) end
    local n = u8(a - v - (band(f, H) ~= 0 and 1 or 0))
    if band(n, 0x02) ~= 0 then f = bor(f, Y) end
    if band(n, 0x08) ~= 0 then f = bor(f, X) end
    if cpu.bc ~= 0 then f = bor(f, P) end
    cpu:set_f(f)
    if (op == 0xB1 or op == 0xB9) and cpu.bc ~= 0 and band(f, Z) == 0 then
      cpu.pc = u16(cpu.pc - 2)
      return 21
    end
    return 16
  elseif op == 0xA2 or op == 0xAA or op == 0xB2 or op == 0xBA then
    -- INI/IND/INIR/INDR
    local v = cpu.bus.in_port(cpu:c())
    cpu:write8(cpu.hl, v)
    cpu:set_b(u8(cpu:b() - 1))
    if op == 0xA2 or op == 0xB2 then cpu.hl = u16(cpu.hl + 1) else cpu.hl = u16(cpu.hl - 1) end
    local f = N
    if cpu:b() == 0 then f = bor(f, Z) end
    cpu:set_f(bor(band(cpu:f(), C), f))
    if (op == 0xB2 or op == 0xBA) and cpu:b() ~= 0 then
      cpu.pc = u16(cpu.pc - 2)
      return 21
    end
    return 16
  elseif op == 0xA3 or op == 0xAB or op == 0xB3 or op == 0xBB then
    local v = cpu:read8(cpu.hl)
    cpu:set_b(u8(cpu:b() - 1))
    cpu.bus.out_port(cpu:c(), v)
    if op == 0xA3 or op == 0xB3 then cpu.hl = u16(cpu.hl + 1) else cpu.hl = u16(cpu.hl - 1) end
    local f = N
    if cpu:b() == 0 then f = bor(f, Z) end
    cpu:set_f(bor(band(cpu:f(), C), f))
    if (op == 0xB3 or op == 0xBB) and cpu:b() ~= 0 then
      cpu.pc = u16(cpu.pc - 2)
      return 21
    end
    return 16
  end

  return 8 -- unknown ED -> NOP
end

local function exec_dd_fd(cpu, xy_name)
  cpu:inc_r()
  local op = cpu:fetch8()
  local xy = xy_name == "ix" and cpu.ix or cpu.iy
  local function set_xy(v)
    if xy_name == "ix" then cpu.ix = u16(v) else cpu.iy = u16(v) end
  end
  local function get_xy()
    return xy_name == "ix" and cpu.ix or cpu.iy
  end

  -- Common subset: treat HL->IX/IY for many ops
  if op == 0x21 then -- LD IX,nn
    set_xy(cpu:fetch16())
    return 14
  elseif op == 0x22 then -- LD (nn),IX
    cpu:write16(cpu:fetch16(), get_xy())
    return 20
  elseif op == 0x2A then -- LD IX,(nn)
    set_xy(cpu:read16(cpu:fetch16()))
    return 20
  elseif op == 0x23 then -- INC IX
    set_xy(u16(get_xy() + 1))
    return 10
  elseif op == 0x2B then -- DEC IX
    set_xy(u16(get_xy() - 1))
    return 10
  elseif op == 0x24 then -- INC IXh
    if xy_name == "ix" then cpu:set_ixh(cpu:inc8(cpu:ixh())) else cpu:set_iyh(cpu:inc8(cpu:iyh())) end
    return 8
  elseif op == 0x25 then
    if xy_name == "ix" then cpu:set_ixh(cpu:dec8(cpu:ixh())) else cpu:set_iyh(cpu:dec8(cpu:iyh())) end
    return 8
  elseif op == 0x26 then
    if xy_name == "ix" then cpu:set_ixh(cpu:fetch8()) else cpu:set_iyh(cpu:fetch8()) end
    return 11
  elseif op == 0x2C then
    if xy_name == "ix" then cpu:set_ixl(cpu:inc8(cpu:ixl())) else cpu:set_iyl(cpu:inc8(cpu:iyl())) end
    return 8
  elseif op == 0x2D then
    if xy_name == "ix" then cpu:set_ixl(cpu:dec8(cpu:ixl())) else cpu:set_iyl(cpu:dec8(cpu:iyl())) end
    return 8
  elseif op == 0x2E then
    if xy_name == "ix" then cpu:set_ixl(cpu:fetch8()) else cpu:set_iyl(cpu:fetch8()) end
    return 11
  elseif op == 0x29 then -- ADD IX,IX
    set_xy(cpu:add16(get_xy(), get_xy()))
    return 15
  elseif op == 0x09 then
    set_xy(cpu:add16(get_xy(), cpu.bc))
    return 15
  elseif op == 0x19 then
    set_xy(cpu:add16(get_xy(), cpu.de))
    return 15
  elseif op == 0x39 then
    set_xy(cpu:add16(get_xy(), cpu.sp))
    return 15
  elseif op == 0x34 then -- INC (IX+d)
    local addr = idx_addr(cpu, get_xy())
    cpu:write8(addr, cpu:inc8(cpu:read8(addr)))
    return 23
  elseif op == 0x35 then
    local addr = idx_addr(cpu, get_xy())
    cpu:write8(addr, cpu:dec8(cpu:read8(addr)))
    return 23
  elseif op == 0x36 then
    local addr = idx_addr(cpu, get_xy())
    cpu:write8(addr, cpu:fetch8())
    return 19
  elseif op == 0x46 or op == 0x4E or op == 0x56 or op == 0x5E or op == 0x66 or op == 0x6E or op == 0x7E then
    local r = band(rshift(op, 3), 7)
    local addr = idx_addr(cpu, get_xy())
    cpu:set_r8(r, cpu:read8(addr))
    return 19
  elseif op == 0x70 or op == 0x71 or op == 0x72 or op == 0x73 or op == 0x74 or op == 0x75 or op == 0x77 then
    local r = band(op, 7)
    local addr = idx_addr(cpu, get_xy())
    cpu:write8(addr, cpu:get_r8(r))
    return 19
  elseif op == 0x86 then -- ADD A,(IX+d)
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:add8(cpu:a(), cpu:read8(addr), false))
    return 19
  elseif op == 0x8E then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:add8(cpu:a(), cpu:read8(addr), band(cpu:f(), C) ~= 0))
    return 19
  elseif op == 0x96 then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:sub8(cpu:a(), cpu:read8(addr), false))
    return 19
  elseif op == 0x9E then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:sub8(cpu:a(), cpu:read8(addr), band(cpu:f(), C) ~= 0))
    return 19
  elseif op == 0xA6 then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:and8(cpu:a(), cpu:read8(addr)))
    return 19
  elseif op == 0xAE then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:xor8(cpu:a(), cpu:read8(addr)))
    return 19
  elseif op == 0xB6 then
    local addr = idx_addr(cpu, get_xy())
    cpu:set_a(cpu:or8(cpu:a(), cpu:read8(addr)))
    return 19
  elseif op == 0xBE then
    local addr = idx_addr(cpu, get_xy())
    cpu:cp8(cpu:a(), cpu:read8(addr))
    return 19
  elseif op == 0xE1 then -- POP IX
    set_xy(cpu:pop16())
    return 14
  elseif op == 0xE3 then -- EX (SP),IX
    local tmp = cpu:read16(cpu.sp)
    cpu:write16(cpu.sp, get_xy())
    set_xy(tmp)
    return 23
  elseif op == 0xE5 then -- PUSH IX
    cpu:push16(get_xy())
    return 15
  elseif op == 0xE9 then -- JP (IX)
    cpu.pc = get_xy()
    return 8
  elseif op == 0xF9 then -- LD SP,IX
    cpu.sp = get_xy()
    return 10
  elseif op == 0xCB then
    return exec_ddcb_fdcb(cpu, get_xy())
  end

  -- LD r,IXh/IXl and ALU with IXh/IXl
  local x = rshift(op, 6)
  local y = band(rshift(op, 3), 7)
  local z = band(op, 7)
  if x == 1 and not (y == 6 and z == 6) then
    -- LD r,r' with IXH/IXL replacing H/L
    local function get(i)
      if i == 4 then return xy_name == "ix" and cpu:ixh() or cpu:iyh()
      elseif i == 5 then return xy_name == "ix" and cpu:ixl() or cpu:iyl()
      elseif i == 6 then
        local addr = idx_addr(cpu, get_xy())
        return cpu:read8(addr)
      else return cpu:get_r8(i) end
    end
    local function set(i, v)
      if i == 4 then if xy_name == "ix" then cpu:set_ixh(v) else cpu:set_iyh(v) end
      elseif i == 5 then if xy_name == "ix" then cpu:set_ixl(v) else cpu:set_iyl(v) end
      elseif i == 6 then
        -- shouldn't happen for dest with (ix+d) in this form without prior fetch
        cpu:set_r8(i, v)
      else cpu:set_r8(i, v) end
    end
    if y == 6 then
      local addr = idx_addr(cpu, get_xy())
      cpu:write8(addr, get(z))
      return 19
    elseif z == 6 then
      local addr = idx_addr(cpu, get_xy())
      set(y, cpu:read8(addr))
      return 19
    else
      set(y, get(z))
      return 8
    end
  elseif x == 2 then
    local v
    if z == 4 then v = xy_name == "ix" and cpu:ixh() or cpu:iyh()
    elseif z == 5 then v = xy_name == "ix" and cpu:ixl() or cpu:iyl()
    elseif z == 6 then
      local addr = idx_addr(cpu, get_xy())
      v = cpu:read8(addr)
      -- ALU already handled for z==6 above mostly
    else v = cpu:get_r8(z) end
    if y == 0 then cpu:set_a(cpu:add8(cpu:a(), v, false))
    elseif y == 1 then cpu:set_a(cpu:add8(cpu:a(), v, band(cpu:f(), C) ~= 0))
    elseif y == 2 then cpu:set_a(cpu:sub8(cpu:a(), v, false))
    elseif y == 3 then cpu:set_a(cpu:sub8(cpu:a(), v, band(cpu:f(), C) ~= 0))
    elseif y == 4 then cpu:set_a(cpu:and8(cpu:a(), v))
    elseif y == 5 then cpu:set_a(cpu:xor8(cpu:a(), v))
    elseif y == 6 then cpu:set_a(cpu:or8(cpu:a(), v))
    else cpu:cp8(cpu:a(), v) end
    return z == 6 and 19 or 8
  end

  -- Fall back: execute as unprefixed (DD/FD acts as prefix cancel for many)
  return M.exec(cpu, op)
end

function M.exec(cpu, op)
  local x = rshift(op, 6)
  local y = band(rshift(op, 3), 7)
  local z = band(op, 7)
  local p = band(rshift(op, 4), 3)
  local q = band(rshift(op, 3), 1)

  -- Prefixes
  if op == 0xCB then return exec_cb(cpu) end
  if op == 0xED then return exec_ed(cpu) end
  if op == 0xDD then return exec_dd_fd(cpu, "ix") end
  if op == 0xFD then return exec_dd_fd(cpu, "iy") end

  if x == 0 then
    if z == 0 then
      if y == 0 then return 4 -- NOP
      elseif y == 1 then -- EX AF,AF'
        local t = cpu.af; cpu.af = cpu.af_; cpu.af_ = t
        return 4
      elseif y == 2 then -- DJNZ
        cpu:set_b(u8(cpu:b() - 1))
        local d = cpu:fetch_disp()
        if cpu:b() ~= 0 then cpu.pc = u16(cpu.pc + d); return 13 end
        return 8
      elseif y == 3 then -- JR d
        local d = cpu:fetch_disp()
        cpu.pc = u16(cpu.pc + d)
        return 12
      else -- JR cc,d
        local d = cpu:fetch_disp()
        local cc = y - 4
        if cpu:cond(cc) then cpu.pc = u16(cpu.pc + d); return 12 end
        return 7
      end
    elseif z == 1 then
      if q == 0 then -- LD rp,nn
        cpu:set_rp(p, cpu:fetch16())
        return 10
      else -- ADD HL,rp
        cpu.hl = cpu:add16(cpu.hl, cpu:get_rp(p))
        return 11
      end
    elseif z == 2 then
      if q == 0 then
        if p == 0 then cpu:write8(cpu.bc, cpu:a()); return 7
        elseif p == 1 then cpu:write8(cpu.de, cpu:a()); return 7
        elseif p == 2 then cpu:write16(cpu:fetch16(), cpu.hl); return 16
        else cpu:write8(cpu:fetch16(), cpu:a()); return 13 end
      else
        if p == 0 then cpu:set_a(cpu:read8(cpu.bc)); return 7
        elseif p == 1 then cpu:set_a(cpu:read8(cpu.de)); return 7
        elseif p == 2 then cpu.hl = cpu:read16(cpu:fetch16()); return 16
        else cpu:set_a(cpu:read8(cpu:fetch16())); return 13 end
      end
    elseif z == 3 then
      if q == 0 then cpu:set_rp(p, u16(cpu:get_rp(p) + 1)); return 6
      else cpu:set_rp(p, u16(cpu:get_rp(p) - 1)); return 6 end
    elseif z == 4 then -- INC r
      cpu:set_r8(y, cpu:inc8(cpu:get_r8(y)))
      return y == 6 and 11 or 4
    elseif z == 5 then -- DEC r
      cpu:set_r8(y, cpu:dec8(cpu:get_r8(y)))
      return y == 6 and 11 or 4
    elseif z == 6 then -- LD r,n
      cpu:set_r8(y, cpu:fetch8())
      return y == 6 and 10 or 7
    else -- z==7
      if y == 0 then cpu:op_rlca(); return 4
      elseif y == 1 then cpu:op_rrca(); return 4
      elseif y == 2 then cpu:op_rla(); return 4
      elseif y == 3 then cpu:op_rra(); return 4
      elseif y == 4 then cpu:daa(); return 4
      elseif y == 5 then -- CPL
        cpu:set_a(u8(bxor(cpu:a(), 0xFF)))
        local f = bor(cpu:f(), bor(H, N))
        f = bor(band(f, band(bit.bnot(bor(X, Y)), 0xFF)), band(cpu:a(), bor(X, Y)))
        cpu:set_f(f)
        return 4
      elseif y == 6 then -- SCF
        local f = band(cpu:f(), bor(S, Z, P))
        f = bor(f, C)
        f = bor(f, band(cpu:a(), bor(X, Y)))
        cpu:set_f(f)
        return 4
      else -- CCF
        local f = band(cpu:f(), bor(S, Z, P))
        if band(cpu:f(), C) ~= 0 then f = bor(f, H) else f = bor(f, C) end
        f = bor(f, band(cpu:a(), bor(X, Y)))
        cpu:set_f(f)
        return 4
      end
    end
  elseif x == 1 then
    if y == 6 and z == 6 then -- HALT
      cpu.halted = true
      return 4
    end
    cpu:set_r8(y, cpu:get_r8(z))
    return (y == 6 or z == 6) and 7 or 4
  elseif x == 2 then
    local v = cpu:get_r8(z)
    if y == 0 then cpu:set_a(cpu:add8(cpu:a(), v, false))
    elseif y == 1 then cpu:set_a(cpu:add8(cpu:a(), v, band(cpu:f(), C) ~= 0))
    elseif y == 2 then cpu:set_a(cpu:sub8(cpu:a(), v, false))
    elseif y == 3 then cpu:set_a(cpu:sub8(cpu:a(), v, band(cpu:f(), C) ~= 0))
    elseif y == 4 then cpu:set_a(cpu:and8(cpu:a(), v))
    elseif y == 5 then cpu:set_a(cpu:xor8(cpu:a(), v))
    elseif y == 6 then cpu:set_a(cpu:or8(cpu:a(), v))
    else cpu:cp8(cpu:a(), v) end
    return z == 6 and 7 or 4
  else -- x == 3
    if z == 0 then -- RET cc
      if cpu:cond(y) then cpu.pc = cpu:pop16(); return 11 end
      return 5
    elseif z == 1 then
      if q == 0 then -- POP rp2
        cpu:set_rp2(p, cpu:pop16())
        return 10
      else
        if p == 0 then cpu.pc = cpu:pop16(); return 10 -- RET
        elseif p == 1 then -- EXX
          local t
          t = cpu.bc; cpu.bc = cpu.bc_; cpu.bc_ = t
          t = cpu.de; cpu.de = cpu.de_; cpu.de_ = t
          t = cpu.hl; cpu.hl = cpu.hl_; cpu.hl_ = t
          return 4
        elseif p == 2 then cpu.pc = cpu.hl; return 4 -- JP HL
        else cpu.sp = cpu.hl; return 6 end -- LD SP,HL
      end
    elseif z == 2 then -- JP cc,nn
      local addr = cpu:fetch16()
      if cpu:cond(y) then cpu.pc = addr end
      return 10
    elseif z == 3 then
      if y == 0 then cpu.pc = cpu:fetch16(); return 10 -- JP nn
      elseif y == 1 then return exec_cb(cpu)
      elseif y == 2 then -- OUT (n),A
        cpu.bus.out_port(cpu:fetch8(), cpu:a())
        return 11
      elseif y == 3 then -- IN A,(n)
        cpu:set_a(cpu.bus.in_port(cpu:fetch8()))
        return 11
      elseif y == 4 then -- EX (SP),HL
        local t = cpu:read16(cpu.sp)
        cpu:write16(cpu.sp, cpu.hl)
        cpu.hl = t
        return 19
      elseif y == 5 then -- EX DE,HL
        local t = cpu.de; cpu.de = cpu.hl; cpu.hl = t
        return 4
      elseif y == 6 then -- DI
        cpu.iff1 = false
        cpu.iff2 = false
        return 4
      else -- EI
        cpu.iff1 = true
        cpu.iff2 = true
        cpu.ei_delay = true
        return 4
      end
    elseif z == 4 then -- CALL cc,nn
      local addr = cpu:fetch16()
      if cpu:cond(y) then
        cpu:push16(cpu.pc)
        cpu.pc = addr
        return 17
      end
      return 10
    elseif z == 5 then
      if q == 0 then -- PUSH rp2
        cpu:push16(cpu:get_rp2(p))
        return 11
      else
        if p == 0 then -- CALL nn
          local addr = cpu:fetch16()
          cpu:push16(cpu.pc)
          cpu.pc = addr
          return 17
        elseif p == 1 then return exec_dd_fd(cpu, "ix")
        elseif p == 2 then return exec_ed(cpu)
        else return exec_dd_fd(cpu, "iy") end
      end
    elseif z == 6 then -- ALU A,n
      local v = cpu:fetch8()
      if y == 0 then cpu:set_a(cpu:add8(cpu:a(), v, false))
      elseif y == 1 then cpu:set_a(cpu:add8(cpu:a(), v, band(cpu:f(), C) ~= 0))
      elseif y == 2 then cpu:set_a(cpu:sub8(cpu:a(), v, false))
      elseif y == 3 then cpu:set_a(cpu:sub8(cpu:a(), v, band(cpu:f(), C) ~= 0))
      elseif y == 4 then cpu:set_a(cpu:and8(cpu:a(), v))
      elseif y == 5 then cpu:set_a(cpu:xor8(cpu:a(), v))
      elseif y == 6 then cpu:set_a(cpu:or8(cpu:a(), v))
      else cpu:cp8(cpu:a(), v) end
      return 7
    else -- z==7 RST
      cpu:push16(cpu.pc)
      cpu.pc = y * 8
      return 11
    end
  end
  return 4
end

return M
