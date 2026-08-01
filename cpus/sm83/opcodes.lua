-- SM83 base + CB opcode handlers. Returns T-cycles (4 × M-cycles).

return function(SM83, bit)
  local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
  local u8, u16 = bit.u8, bit.u16
  local Z, N, H, C = SM83.FLAG_Z, SM83.FLAG_N, SM83.FLAG_H, SM83.FLAG_C
  local OP, CB = SM83.OP, SM83.CB

  local function r8_get(cpu, i)
    if i == 0 then return cpu.b
    elseif i == 1 then return cpu.c
    elseif i == 2 then return cpu.d
    elseif i == 3 then return cpu.e
    elseif i == 4 then return cpu.h
    elseif i == 5 then return cpu.l
    elseif i == 6 then return cpu:read8(cpu:hl())
    else return cpu.a
    end
  end

  local function r8_set(cpu, i, v)
    v = u8(v)
    if i == 0 then cpu.b = v
    elseif i == 1 then cpu.c = v
    elseif i == 2 then cpu.d = v
    elseif i == 3 then cpu.e = v
    elseif i == 4 then cpu.h = v
    elseif i == 5 then cpu.l = v
    elseif i == 6 then cpu:write8(cpu:hl(), v)
    else cpu.a = v
    end
  end

  local function cond(cpu, cc)
    if cc == 0 then return not cpu:flag_z()
    elseif cc == 1 then return cpu:flag_z()
    elseif cc == 2 then return not cpu:flag_c()
    else return cpu:flag_c()
    end
  end

  -- CB rotate/shift helpers (set ZNHC)
  local function rlc(cpu, v)
    v = u8(v)
    local c = rshift(v, 7)
    local res = u8(lshift(v, 1) + c)
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function rrc(cpu, v)
    v = u8(v)
    local c = band(v, 1)
    local res = u8(rshift(v, 1) + lshift(c, 7))
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function rl(cpu, v)
    v = u8(v)
    local oldc = cpu:flag_c() and 1 or 0
    local c = rshift(v, 7)
    local res = u8(lshift(v, 1) + oldc)
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function rr(cpu, v)
    v = u8(v)
    local oldc = cpu:flag_c() and 1 or 0
    local c = band(v, 1)
    local res = u8(rshift(v, 1) + lshift(oldc, 7))
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function sla(cpu, v)
    v = u8(v)
    local c = rshift(v, 7)
    local res = u8(lshift(v, 1))
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function sra(cpu, v)
    v = u8(v)
    local c = band(v, 1)
    local res = u8(rshift(v, 1) + band(v, 0x80))
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end
  local function swap(cpu, v)
    v = u8(v)
    local res = bor(lshift(band(v, 0x0F), 4), rshift(v, 4))
    cpu:set_znhc(res == 0, false, false, false)
    return res
  end
  local function srl(cpu, v)
    v = u8(v)
    local c = band(v, 1)
    local res = u8(rshift(v, 1))
    cpu:set_znhc(res == 0, false, false, c ~= 0)
    return res
  end

  local cb_ops = { rlc, rrc, rl, rr, sla, sra, swap, srl }

  for op = 0, 255 do
    local x = rshift(op, 6)
    local y = band(rshift(op, 3), 7)
    local z = band(op, 7)
    if x == 0 then
      local fn = cb_ops[y + 1]
      CB[op] = function(cpu)
        local v = r8_get(cpu, z)
        r8_set(cpu, z, fn(cpu, v))
        return (z == 6) and 16 or 8
      end
    elseif x == 1 then
      -- BIT
      CB[op] = function(cpu)
        local v = r8_get(cpu, z)
        local bitset = band(v, lshift(1, y)) ~= 0
        local c = band(cpu.f, C)
        local f = H
        if not bitset then f = bor(f, Z) end
        cpu.f = bor(f, c)
        return (z == 6) and 12 or 8
      end
    elseif x == 2 then
      -- RES
      CB[op] = function(cpu)
        local v = band(r8_get(cpu, z), bxor(0xFF, lshift(1, y)))
        r8_set(cpu, z, v)
        return (z == 6) and 16 or 8
      end
    else
      -- SET
      CB[op] = function(cpu)
        local v = bor(r8_get(cpu, z), lshift(1, y))
        r8_set(cpu, z, v)
        return (z == 6) and 16 or 8
      end
    end
  end

  -- --- Base opcodes ---
  OP[0x00] = function() return 4 end -- NOP
  OP[0x10] = function(cpu) -- STOP
    cpu:fetch8() -- always followed by 00
    cpu.stopped = true
    return 4
  end
  OP[0x76] = function(cpu) -- HALT
    -- DMG HALT bug: IME=0 with a pending interrupt does not halt; the
    -- following byte is fetched twice (handled in fetch8 via halt_bug).
    if (not cpu.ime) and cpu:pending_irqs() ~= 0 then
      cpu.halt_bug = true
    else
      cpu.halted = true
    end
  end
  OP[0xF3] = function(cpu) -- DI
    cpu.ime = false
    cpu.ei_delay = false
    return 4
  end
  OP[0xFB] = function(cpu) -- EI
    cpu.ei_delay = true
    return 4
  end

  -- LD r16,nn
  OP[0x01] = function(cpu) cpu:set_bc(cpu:fetch16()); return 12 end
  OP[0x11] = function(cpu) cpu:set_de(cpu:fetch16()); return 12 end
  OP[0x21] = function(cpu) cpu:set_hl(cpu:fetch16()); return 12 end
  OP[0x31] = function(cpu) cpu.sp = cpu:fetch16(); return 12 end

  -- ADD HL,r16 (fetch + 1 internal)
  OP[0x09] = function(cpu) cpu:mcycle(); cpu:add16_hl(cpu:bc()) end
  OP[0x19] = function(cpu) cpu:mcycle(); cpu:add16_hl(cpu:de()) end
  OP[0x29] = function(cpu) cpu:mcycle(); cpu:add16_hl(cpu:hl()) end
  OP[0x39] = function(cpu) cpu:mcycle(); cpu:add16_hl(cpu.sp) end

  -- INC/DEC r16 (fetch + 1 internal)
  OP[0x03] = function(cpu) cpu:mcycle(); cpu:set_bc(u16(cpu:bc() + 1)) end
  OP[0x13] = function(cpu) cpu:mcycle(); cpu:set_de(u16(cpu:de() + 1)) end
  OP[0x23] = function(cpu) cpu:mcycle(); cpu:set_hl(u16(cpu:hl() + 1)) end
  OP[0x33] = function(cpu) cpu:mcycle(); cpu.sp = u16(cpu.sp + 1) end
  OP[0x0B] = function(cpu) cpu:mcycle(); cpu:set_bc(u16(cpu:bc() - 1)) end
  OP[0x1B] = function(cpu) cpu:mcycle(); cpu:set_de(u16(cpu:de() - 1)) end
  OP[0x2B] = function(cpu) cpu:mcycle(); cpu:set_hl(u16(cpu:hl() - 1)) end
  OP[0x3B] = function(cpu) cpu:mcycle(); cpu.sp = u16(cpu.sp - 1) end

  -- LD (r16),A / LD A,(r16)
  OP[0x02] = function(cpu) cpu:write8(cpu:bc(), cpu.a); return 8 end
  OP[0x12] = function(cpu) cpu:write8(cpu:de(), cpu.a); return 8 end
  OP[0x0A] = function(cpu) cpu.a = cpu:read8(cpu:bc()); return 8 end
  OP[0x1A] = function(cpu) cpu.a = cpu:read8(cpu:de()); return 8 end

  -- LD (HL±),A / LD A,(HL±)
  OP[0x22] = function(cpu)
    local hl = cpu:hl()
    cpu:write8(hl, cpu.a)
    cpu:set_hl(u16(hl + 1))
    return 8
  end
  OP[0x32] = function(cpu)
    local hl = cpu:hl()
    cpu:write8(hl, cpu.a)
    cpu:set_hl(u16(hl - 1))
    return 8
  end
  OP[0x2A] = function(cpu)
    local hl = cpu:hl()
    cpu.a = cpu:read8(hl)
    cpu:set_hl(u16(hl + 1))
    return 8
  end
  OP[0x3A] = function(cpu)
    local hl = cpu:hl()
    cpu.a = cpu:read8(hl)
    cpu:set_hl(u16(hl - 1))
    return 8
  end

  -- INC/DEC r8
  local inc_ops = { 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x34, 0x3C }
  local dec_ops = { 0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D }
  for i = 0, 7 do
    local ri = i
    OP[inc_ops[i + 1]] = function(cpu)
      r8_set(cpu, ri, cpu:inc8(r8_get(cpu, ri)))
      return (ri == 6) and 12 or 4
    end
    OP[dec_ops[i + 1]] = function(cpu)
      r8_set(cpu, ri, cpu:dec8(r8_get(cpu, ri)))
      return (ri == 6) and 12 or 4
    end
  end

  -- LD r8,n
  local ld_n = { 0x06, 0x0E, 0x16, 0x1E, 0x26, 0x2E, 0x36, 0x3E }
  for i = 0, 7 do
    local ri = i
    OP[ld_n[i + 1]] = function(cpu)
      r8_set(cpu, ri, cpu:fetch8())
      return (ri == 6) and 12 or 8
    end
  end

  -- LD (nn),SP
  OP[0x08] = function(cpu)
    local a = cpu:fetch16()
    cpu:write16(a, cpu.sp)
    return 20
  end

  -- JR (taken: fetch + e + internal; not taken: fetch + e)
  OP[0x18] = function(cpu)
    local e = cpu:fetch_rel()
    cpu:mcycle()
    cpu.pc = u16(cpu.pc + e)
  end
  for i = 0, 3 do
    local cc = i
    OP[0x20 + i * 8] = function(cpu)
      local e = cpu:fetch_rel()
      if cond(cpu, cc) then
        cpu:mcycle()
        cpu.pc = u16(cpu.pc + e)
      end
    end
  end

  -- RLCA / RRCA / RLA / RRA (Z cleared)
  OP[0x07] = function(cpu)
    local a = cpu.a
    local c = rshift(a, 7)
    cpu.a = u8(lshift(a, 1) + c)
    cpu:set_znhc(false, false, false, c ~= 0)
    return 4
  end
  OP[0x0F] = function(cpu)
    local a = cpu.a
    local c = band(a, 1)
    cpu.a = u8(rshift(a, 1) + lshift(c, 7))
    cpu:set_znhc(false, false, false, c ~= 0)
    return 4
  end
  OP[0x17] = function(cpu)
    local a = cpu.a
    local oldc = cpu:flag_c() and 1 or 0
    local c = rshift(a, 7)
    cpu.a = u8(lshift(a, 1) + oldc)
    cpu:set_znhc(false, false, false, c ~= 0)
    return 4
  end
  OP[0x1F] = function(cpu)
    local a = cpu.a
    local oldc = cpu:flag_c() and 1 or 0
    local c = band(a, 1)
    cpu.a = u8(rshift(a, 1) + lshift(oldc, 7))
    cpu:set_znhc(false, false, false, c ~= 0)
    return 4
  end

  OP[0x27] = function(cpu) cpu:daa(); return 4 end
  OP[0x2F] = function(cpu) -- CPL
    cpu.a = u8(bxor(cpu.a, 0xFF))
    cpu.f = bor(band(cpu.f, bor(Z, C)), N, H)
    return 4
  end
  OP[0x37] = function(cpu) -- SCF
    cpu.f = bor(band(cpu.f, Z), C)
    return 4
  end
  OP[0x3F] = function(cpu) -- CCF
    local z = band(cpu.f, Z)
    local c = band(cpu.f, C) == 0 and C or 0
    cpu.f = bor(z, c)
    return 4
  end

  -- LD r,r' (including HALT at 0x76 already set)
  for dst = 0, 7 do
    for src = 0, 7 do
      local op = bor(0x40, lshift(dst, 3), src)
      if op ~= 0x76 then
        local d, s = dst, src
        OP[op] = function(cpu)
          r8_set(cpu, d, r8_get(cpu, s))
          return (d == 6 or s == 6) and 8 or 4
        end
      end
    end
  end

  -- ALU A,r
  local alu_fn = {
    function(cpu, v) cpu.a = cpu:add8(cpu.a, v, false) end,
    function(cpu, v) cpu.a = cpu:add8(cpu.a, v, cpu:flag_c()) end, -- ADC
    function(cpu, v) cpu.a = cpu:sub8(cpu.a, v, false) end,
    function(cpu, v) cpu.a = cpu:sub8(cpu.a, v, cpu:flag_c()) end, -- SBC
    function(cpu, v) cpu.a = cpu:and8(cpu.a, v) end,
    function(cpu, v) cpu.a = cpu:xor8(cpu.a, v) end,
    function(cpu, v) cpu.a = cpu:or8(cpu.a, v) end,
    function(cpu, v) cpu:cp8(cpu.a, v) end,
  }
  for y = 0, 7 do
    for z = 0, 7 do
      local op = bor(0x80, lshift(y, 3), z)
      local fn, ri = alu_fn[y + 1], z
      OP[op] = function(cpu)
        fn(cpu, r8_get(cpu, ri))
        return (ri == 6) and 8 or 4
      end
    end
  end

  -- ALU A,n
  local alu_imm = { 0xC6, 0xCE, 0xD6, 0xDE, 0xE6, 0xEE, 0xF6, 0xFE }
  for y = 0, 7 do
    local fn = alu_fn[y + 1]
    OP[alu_imm[y + 1]] = function(cpu)
      fn(cpu, cpu:fetch8())
      return 8
    end
  end

  -- RET / RET cc / RETI
  -- RET: fetch + pop(2) + 1 internal = 4
  OP[0xC9] = function(cpu)
    cpu.pc = cpu:pop16()
    cpu:mcycle()
  end
  OP[0xD9] = function(cpu) -- RETI
    cpu.pc = cpu:pop16()
    cpu:mcycle()
    cpu.ime = true
  end
  for i = 0, 3 do
    local cc = i
    OP[0xC0 + i * 8] = function(cpu)
      cpu:mcycle() -- condition check / idle
      if cond(cpu, cc) then
        cpu.pc = cpu:pop16()
        cpu:mcycle()
      end
    end
  end

  -- JP nn / JP cc,nn / JP (HL)
  OP[0xC3] = function(cpu)
    cpu.pc = cpu:fetch16()
    cpu:mcycle()
  end
  OP[0xE9] = function(cpu)
    cpu.pc = cpu:hl()
  end
  for i = 0, 3 do
    local cc = i
    OP[0xC2 + i * 8] = function(cpu)
      local nn = cpu:fetch16()
      if cond(cpu, cc) then
        cpu:mcycle()
        cpu.pc = nn
      end
    end
  end

  -- CALL nn / CALL cc,nn
  -- taken: fetch + nn(2) + internal + push(2) = 6
  OP[0xCD] = function(cpu)
    local nn = cpu:fetch16()
    cpu:mcycle()
    cpu:push16(cpu.pc)
    cpu.pc = nn
  end
  for i = 0, 3 do
    local cc = i
    OP[0xC4 + i * 8] = function(cpu)
      local nn = cpu:fetch16()
      if cond(cpu, cc) then
        cpu:mcycle()
        cpu:push16(cpu.pc)
        cpu.pc = nn
      end
    end
  end

  -- RST: fetch + internal + push(2) = 4
  for i = 0, 7 do
    local vec = i * 8
    OP[0xC7 + i * 8] = function(cpu)
      cpu:mcycle()
      cpu:push16(cpu.pc)
      cpu.pc = vec
    end
  end

  -- POP: fetch + 2 reads = 3; PUSH: fetch + internal + 2 writes = 4
  OP[0xC1] = function(cpu) cpu:set_bc(cpu:pop16()) end
  OP[0xD1] = function(cpu) cpu:set_de(cpu:pop16()) end
  OP[0xE1] = function(cpu) cpu:set_hl(cpu:pop16()) end
  OP[0xF1] = function(cpu) cpu:set_af(cpu:pop16()) end
  OP[0xC5] = function(cpu) cpu:mcycle(); cpu:push16(cpu:bc()) end
  OP[0xD5] = function(cpu) cpu:mcycle(); cpu:push16(cpu:de()) end
  OP[0xE5] = function(cpu) cpu:mcycle(); cpu:push16(cpu:hl()) end
  OP[0xF5] = function(cpu) cpu:mcycle(); cpu:push16(cpu:af()) end

  -- LDH / LD (C),A etc.
  OP[0xE0] = function(cpu) -- LDH (n),A
    local n = cpu:fetch8()
    cpu:write8(bor(0xFF00, n), cpu.a)
    return 12
  end
  OP[0xF0] = function(cpu) -- LDH A,(n)
    local n = cpu:fetch8()
    cpu.a = cpu:read8(bor(0xFF00, n))
    return 12
  end
  OP[0xE2] = function(cpu) -- LD (C),A
    cpu:write8(bor(0xFF00, cpu.c), cpu.a)
    return 8
  end
  OP[0xF2] = function(cpu) -- LD A,(C)
    cpu.a = cpu:read8(bor(0xFF00, cpu.c))
    return 8
  end
  OP[0xEA] = function(cpu) -- LD (nn),A
    cpu:write8(cpu:fetch16(), cpu.a)
    return 16
  end
  OP[0xFA] = function(cpu) -- LD A,(nn)
    cpu.a = cpu:read8(cpu:fetch16())
    return 16
  end

  OP[0xE8] = function(cpu) -- ADD SP,e (fetch + e + 2 internal)
    local e = cpu:fetch_rel()
    cpu:mcycle()
    cpu:mcycle()
    cpu.sp = cpu:add_sp(e)
  end
  OP[0xF8] = function(cpu) -- LD HL,SP+e (fetch + e + 1 internal)
    local e = cpu:fetch_rel()
    cpu:mcycle()
    cpu:set_hl(cpu:add_sp(e))
  end
  OP[0xF9] = function(cpu) -- LD SP,HL (fetch + 1 internal)
    cpu:mcycle()
    cpu.sp = cpu:hl()
  end

  -- CB prefix
  OP[0xCB] = function(cpu)
    local op = cpu:fetch8()
    return CB[op](cpu)
  end
end
