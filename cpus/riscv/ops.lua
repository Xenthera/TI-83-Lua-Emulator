-- RV64IMA + Zicsr instruction execute.
--
-- Walkthrough of a trap: instead of advancing PC, we set cpu.trap_cause and
-- return; rv64i.step() calls csr:trap_to_m() so mepc points at the faulting
-- instruction (or ecall), and PC becomes mtvec.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local U64 = require("cpus.riscv.u64")
local Csr = require("cpus.riscv.csr")

local Ops = {}

local OP_LOAD = 0x03
local OP_MISC_MEM = 0x0F
local OP_OP_IMM = 0x13
local OP_AUIPC = 0x17
local OP_OP_IMM_32 = 0x1B
local OP_STORE = 0x23
local OP_AMO = 0x2F -- A extension (OpenSBI boot lottery / locks)
local OP_OP = 0x33
local OP_LUI = 0x37
local OP_OP_32 = 0x3B
local OP_BRANCH = 0x63
local OP_JALR = 0x67
local OP_JAL = 0x6F
local OP_SYSTEM = 0x73

local function s32(u)
  u = band(u, 0xFFFFFFFF)
  if band(u, 0x80000000) ~= 0 then return u - 4294967296 end
  return u
end

local FOUR = U64.FOUR
local ALIGN_MASK = U64.ALIGN_MASK

local function imm_u64(n)
  return U64.from_number(n)
end

local function sext8(b)
  b = band(b, 0xFF)
  if band(b, 0x80) ~= 0 then
    return U64.from_i32(bor(b, 0xFFFFFF00))
  end
  return U64.from_u32(b)
end

local function sext16(w)
  w = band(w, 0xFFFF)
  if band(w, 0x8000) ~= 0 then
    return U64.from_i32(bor(w, 0xFFFF0000))
  end
  return U64.from_u32(w)
end

--- Execute one decoded insn. Mutates cpu. Returns cycles.
function Ops.execute(cpu, d)
  local opcode = d.opcode
  local rd, rs1, rs2 = d.rd, d.rs1, d.rs2
  local pc = cpu.pc
  local next_pc = cpu._npc or U64.add(pc, FOUR)
  if cpu._npc then
    U64.add_into(next_pc, pc, FOUR)
  end
  local wrote = false
  local result

  if opcode == OP_LUI then
    result = U64.from_i32(d.imm_u)
    wrote = true
  elseif opcode == OP_AUIPC then
    result = U64.add(pc, U64.from_i32(d.imm_u))
    wrote = true
  elseif opcode == OP_JAL then
    result = next_pc
    wrote = true
    next_pc = U64.add(pc, imm_u64(d.imm_j))
  elseif opcode == OP_JALR then
    result = next_pc
    wrote = true
    local t = U64.add(cpu:get_x(rs1), imm_u64(d.imm_i))
    next_pc = U64.band(t, ALIGN_MASK)
  elseif opcode == OP_BRANCH then
    local a, b = cpu:get_x(rs1), cpu:get_x(rs2)
    local take = false
    if d.funct3 == 0 then
      take = U64.eq(a, b)
    elseif d.funct3 == 1 then
      take = not U64.eq(a, b)
    elseif d.funct3 == 4 then
      take = U64.slt(a, b)
    elseif d.funct3 == 5 then
      take = not U64.slt(a, b)
    elseif d.funct3 == 6 then
      take = U64.ult(a, b)
    elseif d.funct3 == 7 then
      take = not U64.ult(a, b)
    else
      cpu.illegal = true
    end
    if take then
      next_pc = U64.add(pc, imm_u64(d.imm_b))
    end
  elseif opcode == OP_LOAD then
    local addr = U64.add(cpu:get_x(rs1), imm_u64(d.imm_i))
    if d.funct3 == 0 then
      result = sext8(cpu:read8(addr))
    elseif d.funct3 == 1 then
      result = sext16(cpu:read16(addr))
    elseif d.funct3 == 2 then
      result = U64.from_i32(cpu:read32(addr))
    elseif d.funct3 == 3 then
      result = cpu:read64(addr)
    elseif d.funct3 == 4 then
      result = U64.from_u32(cpu:read8(addr))
    elseif d.funct3 == 5 then
      result = U64.from_u32(cpu:read16(addr))
    elseif d.funct3 == 6 then
      result = U64.from_u32(cpu:read32(addr))
    else
      cpu.illegal = true
    end
    wrote = result ~= nil
  elseif opcode == OP_STORE then
    local addr = U64.add(cpu:get_x(rs1), imm_u64(d.imm_s))
    local v = cpu:get_x(rs2)
    if d.funct3 == 0 then
      cpu:write8(addr, band(v.lo, 0xFF))
    elseif d.funct3 == 1 then
      cpu:write16(addr, band(v.lo, 0xFFFF))
    elseif d.funct3 == 2 then
      cpu:write32(addr, v.lo)
    elseif d.funct3 == 3 then
      cpu:write64(addr, v)
    else
      cpu.illegal = true
    end
  elseif opcode == OP_OP_IMM then
    local a = cpu:get_x(rs1)
    local imm = imm_u64(d.imm_i)
    if d.funct3 == 0 then
      result = U64.add(a, imm)
    elseif d.funct3 == 2 then
      result = U64.from_u32(U64.slt(a, imm) and 1 or 0)
    elseif d.funct3 == 3 then
      result = U64.from_u32(U64.ult(a, imm) and 1 or 0)
    elseif d.funct3 == 4 then
      result = U64.bxor(a, imm)
    elseif d.funct3 == 6 then
      result = U64.bor(a, imm)
    elseif d.funct3 == 7 then
      result = U64.band(a, imm)
    elseif d.funct3 == 1 then
      result = U64.sll(a, d.shamt)
    elseif d.funct3 == 5 then
      -- funct6 in [31:26]: 000000 SRLI, 010000 SRAI
      local f6 = band(rshift(d.insn, 26), 0x3F)
      if f6 == 0 then
        result = U64.srl(a, d.shamt)
      elseif f6 == 0x10 then
        result = U64.sra(a, d.shamt)
      else
        cpu.illegal = true
      end
    else
      cpu.illegal = true
    end
    wrote = result ~= nil
  elseif opcode == OP_OP_IMM_32 then
    local alo = cpu:get_x(rs1).lo
    if d.funct3 == 0 then -- ADDIW
      result = U64.from_i32(band(alo + d.imm_i, 0xFFFFFFFF))
    elseif d.funct3 == 1 then -- SLLIW
      result = U64.from_i32(lshift(alo, band(d.shamt, 0x1F)))
    elseif d.funct3 == 5 then
      local sh = band(d.shamt, 0x1F)
      local f = band(rshift(d.insn, 25), 0x7F)
      if f == 0 then
        result = U64.from_i32(rshift(alo, sh))
      elseif f == 0x20 then
        local n = alo
        if band(n, 0x80000000) ~= 0 then n = n - 4294967296 end
        result = U64.from_i32(math.floor(n / (2 ^ sh)))
      else
        cpu.illegal = true
      end
    else
      cpu.illegal = true
    end
    wrote = result ~= nil
  elseif opcode == OP_OP then
    local a, b = cpu:get_x(rs1), cpu:get_x(rs2)
    if d.funct7 == 0 then
      if d.funct3 == 0 then result = U64.add(a, b)
      elseif d.funct3 == 1 then result = U64.sll(a, band(b.lo, 63))
      elseif d.funct3 == 2 then result = U64.from_u32(U64.slt(a, b) and 1 or 0)
      elseif d.funct3 == 3 then result = U64.from_u32(U64.ult(a, b) and 1 or 0)
      elseif d.funct3 == 4 then result = U64.bxor(a, b)
      elseif d.funct3 == 5 then result = U64.srl(a, band(b.lo, 63))
      elseif d.funct3 == 6 then result = U64.bor(a, b)
      elseif d.funct3 == 7 then result = U64.band(a, b)
      end
    elseif d.funct7 == 0x20 then
      if d.funct3 == 0 then result = U64.sub(a, b)
      elseif d.funct3 == 5 then result = U64.sra(a, band(b.lo, 63))
      else cpu.illegal = true
      end
    elseif d.funct7 == 1 then
      -- M extension (64-bit)
      if d.funct3 == 0 then result = U64.mul(a, b)
      elseif d.funct3 == 1 then result = U64.mulh(a, b)
      elseif d.funct3 == 2 then result = U64.mulhsu(a, b)
      elseif d.funct3 == 3 then result = U64.mulhu(a, b)
      elseif d.funct3 == 4 then local q = U64.divs(a, b); result = q
      elseif d.funct3 == 5 then local q = U64.divu(a, b); result = q
      elseif d.funct3 == 6 then local _, r = U64.divs(a, b); result = r
      elseif d.funct3 == 7 then local _, r = U64.divu(a, b); result = r
      else cpu.illegal = true
      end
    else
      cpu.illegal = true
    end
    wrote = result ~= nil
  elseif opcode == OP_OP_32 then
    local a, b = cpu:get_x(rs1).lo, cpu:get_x(rs2).lo
    local sh = band(b, 0x1F)
    if d.funct7 == 0 then
      if d.funct3 == 0 then
        result = U64.from_i32(band(a + b, 0xFFFFFFFF))
      elseif d.funct3 == 1 then
        result = U64.from_i32(lshift(a, sh))
      elseif d.funct3 == 5 then
        result = U64.from_i32(rshift(a, sh))
      else cpu.illegal = true
      end
    elseif d.funct7 == 0x20 then
      if d.funct3 == 0 then
        result = U64.from_i32(band(a - b, 0xFFFFFFFF))
      elseif d.funct3 == 5 then
        local n = a
        if band(n, 0x80000000) ~= 0 then n = n - 4294967296 end
        result = U64.from_i32(math.floor(n / (2 ^ sh)))
      else cpu.illegal = true
      end
    elseif d.funct7 == 1 then
      -- M extension word ops: operate on low 32, sign-extend result
      local function to_i32(u)
        u = band(u, 0xFFFFFFFF)
        if band(u, 0x80000000) ~= 0 then return u - 4294967296 end
        return u
      end
      if d.funct3 == 0 then -- MULW
        result = U64.from_i32(U64.mul(U64.from_i32(a), U64.from_i32(b)).lo)
      elseif d.funct3 == 4 then -- DIVW
        local da, db = to_i32(a), to_i32(b)
        if db == 0 then result = U64.from_i32(-1)
        elseif da == -2147483648 and db == -1 then result = U64.from_i32(-2147483648)
        else result = U64.from_i32(math.floor(da / db))
        end
      elseif d.funct3 == 5 then -- DIVUW
        if b == 0 then result = U64.from_i32(0xFFFFFFFF)
        else result = U64.from_i32(math.floor(band(a, 0xFFFFFFFF) / band(b, 0xFFFFFFFF)))
        end
      elseif d.funct3 == 6 then -- REMW
        local da, db = to_i32(a), to_i32(b)
        if db == 0 then result = U64.from_i32(da)
        elseif da == -2147483648 and db == -1 then result = U64.from_i32(0)
        else result = U64.from_i32(da - db * math.floor(da / db))
        end
      elseif d.funct3 == 7 then -- REMUW
        if b == 0 then result = U64.from_i32(a)
        else
          local ua, ub = band(a, 0xFFFFFFFF), band(b, 0xFFFFFFFF)
          result = U64.from_i32(ua - ub * math.floor(ua / ub))
        end
      else cpu.illegal = true
      end
    else
      cpu.illegal = true
    end
    wrote = result ~= nil
  elseif opcode == OP_MISC_MEM then
    -- FENCE / FENCE.I - nop for now
  elseif opcode == OP_AMO then
    -- Single-hart: AMOs are load -> modify -> store; LR/SC always succeed.
    local addr = cpu:get_x(rs1)
    local src = cpu:get_x(rs2)
    local funct5 = band(rshift(d.insn, 27), 0x1F)
    if d.funct3 == 2 then -- *.W
      local old32 = cpu:read32(addr)
      local old = U64.from_i32(old32)
      if funct5 == 2 then -- LR.W
        result = old
        wrote = true
      elseif funct5 == 3 then -- SC.W
        cpu:write32(addr, src.lo)
        result = U64.ZERO
        wrote = true
      else
        local new32
        local a, b = old32, src.lo
        if funct5 == 0 then -- AMOADD.W
          new32 = band(a + b, 0xFFFFFFFF)
        elseif funct5 == 1 then -- AMOSWAP.W
          new32 = band(b, 0xFFFFFFFF)
        elseif funct5 == 4 then -- AMOXOR.W
          new32 = bxor(a, b)
        elseif funct5 == 8 then -- AMOOR.W
          new32 = bor(a, b)
        elseif funct5 == 12 then -- AMOAND.W
          new32 = band(a, b)
        elseif funct5 == 16 then -- AMOMIN.W (signed)
          new32 = (s32(a) < s32(b)) and a or b
        elseif funct5 == 20 then -- AMOMAX.W (signed)
          new32 = (s32(a) > s32(b)) and a or b
        elseif funct5 == 24 then -- AMOMINU.W
          new32 = (band(a, 0xFFFFFFFF) < band(b, 0xFFFFFFFF)) and a or b
        elseif funct5 == 28 then -- AMOMAXU.W
          new32 = (band(a, 0xFFFFFFFF) > band(b, 0xFFFFFFFF)) and a or b
        else
          cpu.illegal = true
        end
        if not cpu.illegal then
          cpu:write32(addr, new32)
          result = old
          wrote = true
        end
      end
    elseif d.funct3 == 3 then -- *.D
      local old = cpu:read64(addr)
      if funct5 == 2 then -- LR.D
        result = old
        wrote = true
      elseif funct5 == 3 then -- SC.D
        cpu:write64(addr, src)
        result = U64.ZERO
        wrote = true
      else
        local newv
        if funct5 == 0 then
          newv = U64.add(old, src)
        elseif funct5 == 1 then
          newv = src
        elseif funct5 == 4 then
          newv = U64.bxor(old, src)
        elseif funct5 == 8 then
          newv = U64.bor(old, src)
        elseif funct5 == 12 then
          newv = U64.band(old, src)
        elseif funct5 == 16 then
          newv = U64.slt(old, src) and old or src
        elseif funct5 == 20 then
          newv = U64.slt(src, old) and old or src
        elseif funct5 == 24 then
          newv = U64.ult(old, src) and old or src
        elseif funct5 == 28 then
          newv = U64.ult(src, old) and old or src
        else
          cpu.illegal = true
        end
        if newv then
          cpu:write64(addr, newv)
          result = old
          wrote = true
        end
      end
    else
      cpu.illegal = true
    end
  elseif opcode == OP_SYSTEM then
    if d.funct3 == 0 then
      local imm = band(rshift(d.insn, 20), 0xFFF)
      if imm == 0 then -- ECALL
        local cause = Csr.CAUSE_ECALL_M
        if cpu.csr.priv == Csr.PRIV_U then cause = Csr.CAUSE_ECALL_U
        elseif cpu.csr.priv == Csr.PRIV_S then cause = Csr.CAUSE_ECALL_S
        end
        cpu.trap_cause = cause
        cpu.trap_interrupt = false
        cpu.trap_tval = U64.zero()
        cpu.ecall = true
      elseif imm == 1 then -- EBREAK
        cpu.trap_cause = Csr.CAUSE_BREAKPOINT
        cpu.trap_interrupt = false
        cpu.trap_tval = U64.zero()
        cpu.ebreak = true
      elseif imm == 0x302 then -- MRET
        if cpu.csr.priv ~= Csr.PRIV_M then
          cpu.illegal = true
        else
          U64.assign(cpu.pc, cpu.csr:mret())
          return 1
        end
      elseif imm == 0x102 then -- SRET
        local npc = cpu.csr:sret()
        if not npc then
          cpu.illegal = true
        else
          U64.assign(cpu.pc, npc)
          return 1
        end
      elseif imm == 0x105 then -- WFI - stall like 68k STOP until an IRQ
        cpu.waiting = true
      elseif band(rshift(d.insn, 25), 0x7F) == 9 then
        -- SFENCE.VMA - no TLB cache yet; walk is always fresh
      else
        cpu.illegal = true
      end
    else
      -- Zicsr: CSRRW/CSRRS/CSRRC and immediate forms
      local csr_addr = band(rshift(d.insn, 20), 0xFFF)
      local src
      if d.funct3 >= 5 then
        src = U64.from_u32(rs1) -- zimm in rs1 field
      else
        src = cpu:get_x(rs1)
      end
      local old
      local f3 = d.funct3
      if f3 == 1 or f3 == 5 then
        old = cpu.csr:csrrw(csr_addr, src, cpu)
      elseif f3 == 2 or f3 == 6 then
        old = cpu.csr:csrrs(csr_addr, src, cpu)
      elseif f3 == 3 or f3 == 7 then
        old = cpu.csr:csrrc(csr_addr, src, cpu)
      else
        cpu.illegal = true
      end
      if old == nil then
        cpu.illegal = true
      else
        result = old
        wrote = true
      end
    end
  else
    cpu.illegal = true
  end

  if cpu.illegal then
    cpu.trap_cause = Csr.CAUSE_ILLEGAL
    cpu.trap_interrupt = false
    cpu.trap_tval = U64.from_u32(d.insn)
  end

  if cpu.trap_cause ~= nil then
    -- Do not advance PC; step() will vector through mtvec.
    return 1
  end

  if wrote and result then
    cpu:set_x(rd, result)
  end
  U64.assign(cpu.pc, next_pc)
  return 1
end

return Ops
