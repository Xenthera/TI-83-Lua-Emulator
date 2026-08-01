-- RISC-V CSR file + trap helpers (M-mode first; S/U wired for later).
--
-- Mental model: CSRs are the CPU's "control panel". Linux does not poke
-- devices for every privilege change — it writes mtvec/mepc/mstatus/satp
-- and relies on traps. A trap freezes the faulting PC into mepc, records
-- why in mcause, and jumps to mtvec. mret undoes that.

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift
local U64 = require("cpus.riscv.u64")

local Csr = {}

-- Privilege levels (encoding matches mstatus.MPP).
Csr.PRIV_U = 0
Csr.PRIV_S = 1
Csr.PRIV_M = 3

-- Exception causes (mcause when interrupt bit clear).
Csr.CAUSE_ILLEGAL = 2
Csr.CAUSE_BREAKPOINT = 3
Csr.CAUSE_ECALL_U = 8
Csr.CAUSE_ECALL_S = 9
Csr.CAUSE_ECALL_M = 11
Csr.CAUSE_INST_PAGE_FAULT = 12
Csr.CAUSE_LOAD_PAGE_FAULT = 13
Csr.CAUSE_STORE_PAGE_FAULT = 15

-- Interrupt causes (mcause with high bit set).
Csr.INT_M_TIMER = 7
Csr.INT_S_TIMER = 5
Csr.INT_M_EXTERNAL = 11
Csr.INT_S_EXTERNAL = 9

-- CSR addresses
local MSTATUS = 0x300
local MISA = 0x301
local MEDELEG = 0x302
local MIDELEG = 0x303
local MIE = 0x304
local MTVEC = 0x305
local MSCRATCH = 0x340
local MEPC = 0x341
local MCAUSE = 0x342
local MTVAL = 0x343
local MIP = 0x344
local MHARTID = 0xF14
local MVENDORID = 0xF11
local MARCHID = 0xF12
local MIMPID = 0xF13

-- S-mode (stubs usable once privilege lands)
local SSTATUS = 0x100
local SIE = 0x104
local STVEC = 0x105
local SSCRATCH = 0x140
local SEPC = 0x141
local SCAUSE = 0x142
local STVAL = 0x143
local SIP = 0x144
local SATP = 0x180

-- Counters (read-only views)
local CYCLE = 0xC00
local TIME = 0xC01
local INSTRET = 0xC02
local MCYCLE = 0xB00
local MINSTRET = 0xB02

-- mstatus bit fields
local MSTATUS_SIE = 0x2
local MSTATUS_MIE = 0x8
local MSTATUS_SPIE = 0x20
local MSTATUS_MPIE = 0x80
local MSTATUS_SPP = 0x100 -- bit 8
local MSTATUS_MPP_SHIFT = 11
local MSTATUS_MPP_MASK = 0x1800 -- bits 12:11

local function u64_from_cause(cause, is_interrupt)
  if is_interrupt then
    return U64.new(0x80000000, band(cause, 0xFFFFFFFF))
  end
  return U64.from_u32(cause)
end

Csr.__index = Csr

function Csr.new()
  local self = setmetatable({
    priv = Csr.PRIV_M,
    mstatus = U64.zero(),
    misa = U64.new(0x80000000, 0), -- MXLEN=64 placeholder; extensions filled below
    medeleg = U64.zero(),
    mideleg = U64.zero(),
    mie = U64.zero(),
    mtvec = U64.zero(),
    mscratch = U64.zero(),
    mepc = U64.zero(),
    mcause = U64.zero(),
    mtval = U64.zero(),
    mip = U64.zero(),
    -- S
    stvec = U64.zero(),
    sscratch = U64.zero(),
    sepc = U64.zero(),
    scause = U64.zero(),
    stval = U64.zero(),
    satp = U64.zero(),
    -- time base (mtime mirror; board advances this)
    time = U64.zero(),
  }, Csr)
  -- misa: RV64IMA + S + U (A=0, I=8, M=12, S=18, U=20).
  -- MXL in [63:62]: 1=RV32, 2=RV64 → set bit 63 (hi bit 31).
  local ext = bor(
    bor(bor(lshift(1, 0), lshift(1, 8)), lshift(1, 12)),
    bor(lshift(1, 18), lshift(1, 20))
  )
  self.misa = U64.new(0x80000000, ext)
  -- Soft stubs for CSRs OpenSBI probes (debug triggers / PMP).
  self._stub = {}
  return self
end

function Csr:reset()
  self.priv = Csr.PRIV_M
  self.mstatus = U64.zero()
  self.medeleg = U64.zero()
  self.mideleg = U64.zero()
  self.mie = U64.zero()
  self.mtvec = U64.zero()
  self.mscratch = U64.zero()
  self.mepc = U64.zero()
  self.mcause = U64.zero()
  self.mtval = U64.zero()
  self.mip = U64.zero()
  self.stvec = U64.zero()
  self.sscratch = U64.zero()
  self.sepc = U64.zero()
  self.scause = U64.zero()
  self.stval = U64.zero()
  self.satp = U64.zero()
  self.time = U64.zero()
  self._stub = {}
end

local function is_stub_csr(addr)
  -- Sdtrig debug triggers
  if addr >= 0x7A0 and addr <= 0x7A8 then return true end
  -- PMP config / address (OpenSBI programs these; we don't enforce yet)
  if addr >= 0x3A0 and addr <= 0x3EF then return true end
  -- menvcfg / mseccfg / mcounteren / scounteren commonly touched
  if addr == 0x30A or addr == 0x747 or addr == 0x306 or addr == 0x106 then return true end
  return false
end

local function sstatus_view(mstatus)
  -- sstatus is a shadow of mstatus (SIE/SPIE/SPP/SUM/MXR/…); expose low bits for now
  return U64.band(mstatus, U64.from_u32(0x000DE133))
end

function Csr:read(addr, cpu)
  addr = band(addr, 0xFFF)
  if addr == MSTATUS then return U64.clone(self.mstatus) end
  if addr == SSTATUS then return sstatus_view(self.mstatus) end
  if addr == MISA then return U64.clone(self.misa) end
  if addr == MEDELEG then return U64.clone(self.medeleg) end
  if addr == MIDELEG then return U64.clone(self.mideleg) end
  if addr == MIE then return U64.clone(self.mie) end
  if addr == SIE then return U64.band(self.mie, self.mideleg) end
  if addr == MTVEC then return U64.clone(self.mtvec) end
  if addr == STVEC then return U64.clone(self.stvec) end
  if addr == MSCRATCH then return U64.clone(self.mscratch) end
  if addr == SSCRATCH then return U64.clone(self.sscratch) end
  if addr == MEPC then return U64.clone(self.mepc) end
  if addr == SEPC then return U64.clone(self.sepc) end
  if addr == MCAUSE then return U64.clone(self.mcause) end
  if addr == SCAUSE then return U64.clone(self.scause) end
  if addr == MTVAL then return U64.clone(self.mtval) end
  if addr == STVAL then return U64.clone(self.stval) end
  if addr == MIP then return U64.clone(self.mip) end
  if addr == SIP then return U64.band(self.mip, self.mideleg) end
  if addr == SATP then return U64.clone(self.satp) end
  if addr == MHARTID or addr == MVENDORID or addr == MARCHID or addr == MIMPID then
    return U64.zero()
  end
  if addr == CYCLE or addr == MCYCLE or addr == INSTRET or addr == MINSTRET then
    return U64.from_number(cpu and cpu.cycles or 0)
  end
  if addr == TIME then
    return U64.clone(self.time)
  end
  if is_stub_csr(addr) then
    return U64.clone(self._stub[addr] or U64.ZERO)
  end
  return nil -- unknown
end

function Csr:write(addr, value)
  addr = band(addr, 0xFFF)
  value = value or U64.zero()
  if addr == MSTATUS then
    self.mstatus = U64.clone(value)
    return true
  end
  if addr == SSTATUS then
    local mask = U64.from_u32(0x000DE133)
    self.mstatus = U64.bor(U64.band(self.mstatus, U64.bnot(mask)), U64.band(value, mask))
    return true
  end
  if addr == MEDELEG then self.medeleg = U64.clone(value); return true end
  if addr == MIDELEG then self.mideleg = U64.clone(value); return true end
  if addr == MIE then self.mie = U64.clone(value); return true end
  if addr == SIE then
    local d = self.mideleg
    self.mie = U64.bor(U64.band(self.mie, U64.bnot(d)), U64.band(value, d))
    return true
  end
  if addr == MTVEC then self.mtvec = U64.clone(value); return true end
  if addr == STVEC then self.stvec = U64.clone(value); return true end
  if addr == MSCRATCH then self.mscratch = U64.clone(value); return true end
  if addr == SSCRATCH then self.sscratch = U64.clone(value); return true end
  if addr == MEPC then self.mepc = U64.band(value, U64.new(0xFFFFFFFF, 0xFFFFFFFE)); return true end
  if addr == SEPC then self.sepc = U64.band(value, U64.new(0xFFFFFFFF, 0xFFFFFFFE)); return true end
  if addr == MCAUSE then self.mcause = U64.clone(value); return true end
  if addr == SCAUSE then self.scause = U64.clone(value); return true end
  if addr == MTVAL then self.mtval = U64.clone(value); return true end
  if addr == STVAL then self.stval = U64.clone(value); return true end
  if addr == MIP then
    -- software may clear/set SSIP etc.; keep MTIP from hardware mostly
    self.mip = U64.clone(value)
    return true
  end
  if addr == SIP then
    local d = self.mideleg
    self.mip = U64.bor(U64.band(self.mip, U64.bnot(d)), U64.band(value, d))
    return true
  end
  if addr == SATP then self.satp = U64.clone(value); return true end
  if addr == MISA then return true end -- WARL ignore
  if is_stub_csr(addr) then
    self._stub[addr] = U64.clone(value)
    return true
  end
  return false
end

--- CSR modify: write_val is new full value for CSRRW; for set/clear use mask ops.
function Csr:csrrw(addr, new_val, cpu)
  local old = self:read(addr, cpu)
  if not old then return nil end
  if not self:write(addr, new_val) and addr ~= MISA then
    -- read-only
  end
  return old
end

function Csr:csrrs(addr, mask, cpu)
  local old = self:read(addr, cpu)
  if not old then return nil end
  if not U64.is_zero(mask) then
    self:write(addr, U64.bor(old, mask))
  end
  return old
end

function Csr:csrrc(addr, mask, cpu)
  local old = self:read(addr, cpu)
  if not old then return nil end
  if not U64.is_zero(mask) then
    self:write(addr, U64.band(old, U64.bnot(mask)))
  end
  return old
end

local function mpp_get(mstatus)
  return band(rshift(mstatus.lo, MSTATUS_MPP_SHIFT), 3)
end

local function mpp_set(mstatus, priv)
  local lo = band(mstatus.lo, bxor(0xFFFFFFFF, MSTATUS_MPP_MASK))
  lo = bor(lo, lshift(band(priv, 3), MSTATUS_MPP_SHIFT))
  return U64.new(mstatus.hi, lo)
end

--- Should this trap go to S-mode? (delegation + not already in M)
function Csr:delegated_to_s(cause, is_interrupt)
  if self.priv == Csr.PRIV_M then
    return false
  end
  local bitn = band(cause, 63)
  local map = is_interrupt and self.mideleg or self.medeleg
  local bit = U64.band(U64.srl(map, bitn), U64.from_u32(1))
  return bit.lo ~= 0
end

function Csr:trap_to_m(epc, cause, tval, is_interrupt)
  self.mepc = U64.clone(epc)
  self.mcause = u64_from_cause(cause, is_interrupt)
  self.mtval = tval and U64.clone(tval) or U64.zero()
  local mie = band(self.mstatus.lo, MSTATUS_MIE) ~= 0
  local lo = band(self.mstatus.lo, bxor(0xFFFFFFFF, bor(MSTATUS_MIE, MSTATUS_MPIE)))
  if mie then lo = bor(lo, MSTATUS_MPIE) end
  self.mstatus = mpp_set(U64.new(self.mstatus.hi, lo), self.priv)
  self.priv = Csr.PRIV_M
  local base = U64.band(self.mtvec, U64.new(0xFFFFFFFF, 0xFFFFFFFC))
  local mode = band(self.mtvec.lo, 3)
  if mode == 1 and is_interrupt then
    return U64.add(base, U64.from_u32(4 * band(cause, 0xFF)))
  end
  return base
end

function Csr:trap_to_s(epc, cause, tval, is_interrupt)
  self.sepc = U64.clone(epc)
  self.scause = u64_from_cause(cause, is_interrupt)
  self.stval = tval and U64.clone(tval) or U64.zero()
  local sie = band(self.mstatus.lo, MSTATUS_SIE) ~= 0
  local lo = band(self.mstatus.lo, bxor(0xFFFFFFFF, bor(MSTATUS_SIE, MSTATUS_SPIE, MSTATUS_SPP)))
  if sie then lo = bor(lo, MSTATUS_SPIE) end
  -- SPP <- previous privilege (0=U, 1=S)
  if self.priv == Csr.PRIV_S then
    lo = bor(lo, MSTATUS_SPP)
  end
  self.mstatus = U64.new(self.mstatus.hi, lo)
  self.priv = Csr.PRIV_S
  local base = U64.band(self.stvec, U64.new(0xFFFFFFFF, 0xFFFFFFFC))
  local mode = band(self.stvec.lo, 3)
  if mode == 1 and is_interrupt then
    return U64.add(base, U64.from_u32(4 * band(cause, 0xFF)))
  end
  return base
end

--- Route trap to S (if delegated) or M. Returns new PC.
function Csr:trap(epc, cause, tval, is_interrupt)
  if self:delegated_to_s(cause, is_interrupt) then
    return self:trap_to_s(epc, cause, tval, is_interrupt)
  end
  return self:trap_to_m(epc, cause, tval, is_interrupt)
end

--- MRET: restore PC and privilege from MPP.
function Csr:mret()
  local mpp = mpp_get(self.mstatus)
  local mpie = band(self.mstatus.lo, MSTATUS_MPIE) ~= 0
  local lo = self.mstatus.lo
  if mpie then
    lo = bor(lo, MSTATUS_MIE)
  else
    lo = band(lo, bxor(0xFFFFFFFF, MSTATUS_MIE))
  end
  lo = bor(lo, MSTATUS_MPIE)
  lo = band(lo, bxor(0xFFFFFFFF, MSTATUS_MPP_MASK))
  self.mstatus = U64.new(self.mstatus.hi, lo)
  self.priv = (mpp == Csr.PRIV_U or mpp == Csr.PRIV_S or mpp == Csr.PRIV_M) and mpp or Csr.PRIV_M
  return U64.clone(self.mepc)
end

--- SRET: restore PC and privilege from SPP (U or S).
function Csr:sret()
  if self.priv ~= Csr.PRIV_S and self.priv ~= Csr.PRIV_M then
    return nil -- illegal from U
  end
  local spp = band(self.mstatus.lo, MSTATUS_SPP) ~= 0 and Csr.PRIV_S or Csr.PRIV_U
  local spie = band(self.mstatus.lo, MSTATUS_SPIE) ~= 0
  local lo = self.mstatus.lo
  if spie then
    lo = bor(lo, MSTATUS_SIE)
  else
    lo = band(lo, bxor(0xFFFFFFFF, MSTATUS_SIE))
  end
  lo = bor(lo, MSTATUS_SPIE)
  lo = band(lo, bxor(0xFFFFFFFF, MSTATUS_SPP)) -- SPP <- U
  self.mstatus = U64.new(self.mstatus.hi, lo)
  self.priv = spp
  return U64.clone(self.sepc)
end

function Csr:set_mip_bit(bit_index, set)
  local mask = U64.sll(U64.from_u32(1), bit_index)
  if set then
    self.mip = U64.bor(self.mip, mask)
  else
    self.mip = U64.band(self.mip, U64.bnot(mask))
  end
end

function Csr:timer_pending()
  return band(self.mip.lo, lshift(1, Csr.INT_M_TIMER)) ~= 0
end

function Csr:timer_enabled()
  return band(self.mie.lo, lshift(1, Csr.INT_M_TIMER)) ~= 0
    and band(self.mstatus.lo, MSTATUS_MIE) ~= 0
end

Csr.MSTATUS_MIE = MSTATUS_MIE
Csr.MSTATUS_SIE = MSTATUS_SIE
Csr.MSTATUS_MPP_MASK = MSTATUS_MPP_MASK
Csr.MSTATUS_MPP_SHIFT = MSTATUS_MPP_SHIFT
Csr.u64_from_cause = u64_from_cause
Csr.mpp_set = mpp_set
Csr.mpp_get = mpp_get

return Csr
