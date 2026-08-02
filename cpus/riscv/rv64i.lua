-- Reusable RV64IM CPU core (Zicsr + M-mode traps).
-- Memory only via bus callbacks; no board-specific logic.
--
-- One step:
--   1. Check pending interrupts (timer) if MIE allows
--   2. Fetch insn at pc (physical for now; Sv39 later)
--   3. Decode + execute
--   4. If trap_cause set -> save mepc/mcause, jump mtvec

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift
local U64 = require("cpus.riscv.u64")
local Decode = require("cpus.riscv.decode")
local Ops = require("cpus.riscv.ops")
local Csr = require("cpus.riscv.csr")
local Sv39 = require("cpus.riscv.sv39")

local RV64I = {}
RV64I.__index = RV64I

function RV64I.new(bus)
  local self = setmetatable({}, RV64I)
  self.bus = bus or {}
  self.x = {}
  for i = 0, 31 do
    self.x[i] = U64.zero()
  end
  self.pc = U64.zero()
  self.cycles = 0
  self.halted = false
  self.illegal = false
  self.ecall = false
  self.ebreak = false
  self.trap_cause = nil
  self.trap_interrupt = false
  self.trap_tval = nil
  self.csr = Csr.new()
  self._dec = {}
  self._npc = U64.zero()
  self._irq_div = 0
  self.waiting = false -- WFI stall (like 68k STOP): burns cycles cheaply
  self:reset()
  return self
end

function RV64I:reset()
  for i = 0, 31 do
    U64.assign(self.x[i], U64.ZERO)
  end
  U64.assign(self.pc, U64.ZERO)
  self.cycles = 0
  self.halted = false
  self.waiting = false
  self.illegal = false
  self.ecall = false
  self.ebreak = false
  self.trap_cause = nil
  self.trap_interrupt = false
  self.trap_tval = nil
  self.csr:reset()
end

local ZERO = U64.ZERO
local ONE = U64.ONE
local TWO = U64.TWO
local THREE = U64.THREE
local FOUR = U64.FOUR

function RV64I:get_x(i)
  i = band(i or 0, 0x1F)
  if i == 0 then
    return ZERO
  end
  return self.x[i]
end

function RV64I:set_x(i, v)
  i = band(i or 0, 0x1F)
  if i == 0 then
    return
  end
  -- Copy into the preallocated slot (no per-write table/cdata alloc).
  U64.assign(self.x[i], v or ZERO)
end

local function addr_u32(a)
  return a.lo
end

--- Physical bus access (page-table walks must use these - no translation).
function RV64I:read8_phys(addr)
  local a = addr_u32(addr)
  if self.bus.read8 then
    return band(self.bus.read8(a, addr) or 0, 0xFF)
  end
  return 0
end

function RV64I:write8_phys(addr, v)
  local a = addr_u32(addr)
  if self.bus.write8 then
    self.bus.write8(a, band(v, 0xFF), addr)
  end
end

function RV64I:read32_phys(addr)
  local a = addr_u32(addr)
  local bus = self.bus
  if bus.read32 then
    return band(bus.read32(a, addr) or 0, 0xFFFFFFFF)
  end
  local b0 = self:read8_phys(addr)
  local b1 = self:read8_phys(U64.add(addr, ONE))
  local b2 = self:read8_phys(U64.add(addr, TWO))
  local b3 = self:read8_phys(U64.add(addr, THREE))
  return bor(bor(b0, lshift(b1, 8)), bor(lshift(b2, 16), lshift(b3, 24)))
end

function RV64I:write32_phys(addr, v)
  v = band(v, 0xFFFFFFFF)
  local a = addr_u32(addr)
  local bus = self.bus
  if bus.write32 then
    bus.write32(a, v, addr)
    return
  end
  self:write8_phys(addr, band(v, 0xFF))
  self:write8_phys(U64.add(addr, ONE), band(rshift(v, 8), 0xFF))
  self:write8_phys(U64.add(addr, TWO), band(rshift(v, 16), 0xFF))
  self:write8_phys(U64.add(addr, THREE), band(rshift(v, 24), 0xFF))
end

function RV64I:read64_phys(addr)
  local lo = self:read32_phys(addr)
  local hi = self:read32_phys(U64.add(addr, FOUR))
  return U64.new(hi, lo)
end

function RV64I:write64_phys(addr, v)
  self:write32_phys(addr, v.lo)
  self:write32_phys(U64.add(addr, FOUR), v.hi)
end

function RV64I:translate(addr, access)
  local pa, cause = Sv39.translate(self, addr, access)
  if not pa then
    self.trap_cause = cause
    self.trap_interrupt = false
    self.trap_tval = U64.clone(addr)
    return nil
  end
  return pa
end

function RV64I:read8(addr)
  local pa = self:translate(addr, "load")
  if not pa then return 0 end
  return self:read8_phys(pa)
end

function RV64I:write8(addr, v)
  local pa = self:translate(addr, "store")
  if not pa then return end
  self:write8_phys(pa, v)
end

function RV64I:read16(addr)
  local pa = self:translate(addr, "load")
  if not pa then return 0 end
  local lo = self:read8_phys(pa)
  local hi = self:read8_phys(U64.add(pa, ONE))
  return bor(lo, lshift(hi, 8))
end

function RV64I:write16(addr, v)
  v = band(v, 0xFFFF)
  local pa = self:translate(addr, "store")
  if not pa then return end
  self:write8_phys(pa, band(v, 0xFF))
  self:write8_phys(U64.add(pa, ONE), band(rshift(v, 8), 0xFF))
end

function RV64I:read32(addr)
  local pa = self:translate(addr, "load")
  if not pa then return 0 end
  return self:read32_phys(pa)
end

function RV64I:write32(addr, v)
  local pa = self:translate(addr, "store")
  if not pa then return end
  self:write32_phys(pa, v)
end

function RV64I:read64(addr)
  local pa = self:translate(addr, "load")
  if not pa then return ZERO end
  return self:read64_phys(pa)
end

function RV64I:write64(addr, v)
  local pa = self:translate(addr, "store")
  if not pa then return end
  self:write64_phys(pa, v)
end

function RV64I:take_trap()
  local cause = self.trap_cause
  local is_int = self.trap_interrupt and true or false
  local tval = self.trap_tval or U64.zero()
  self.trap_cause = nil
  self.trap_interrupt = false
  self.trap_tval = nil
  self.illegal = false
  local new_pc = self.csr:trap(self.pc, cause, tval, is_int)
  U64.assign(self.pc, new_pc)
  self.waiting = false
  -- Optional board hook: serve SBI ecalls in Lua (M-mode firmware stand-in).
  if not is_int and cause == Csr.CAUSE_ECALL_S and self.on_ecall_s then
    self.on_ecall_s()
  end
end

function RV64I:check_interrupts()
  local csr = self.csr
  if csr.priv == Csr.PRIV_M and not csr:timer_enabled() then
    -- still allow if MIE set - timer_enabled checks both
  end
  if csr:timer_pending() and csr:timer_enabled() then
    -- Only take M-mode timer when in M with MIE, or when lower privilege
    local take = false
    if csr.priv < Csr.PRIV_M then
      take = band(csr.mie.lo, lshift(1, Csr.INT_M_TIMER)) ~= 0
    elseif band(csr.mstatus.lo, Csr.MSTATUS_MIE) ~= 0
        and band(csr.mie.lo, lshift(1, Csr.INT_M_TIMER)) ~= 0 then
      take = true
    end
    if take then
      self.trap_cause = Csr.INT_M_TIMER
      self.trap_interrupt = true
      self.trap_tval = U64.zero()
      return true
    end
  end
  return false
end

function RV64I:step()
  -- Match 68k: halted/STOP still retire cycles so the host clock meter is honest.
  if self.halted then
    self.cycles = self.cycles + 4
    return 4
  end
  if self.waiting then
    if self:check_interrupts() then
      self.waiting = false
      self:take_trap()
      self.cycles = self.cycles + 1
      return 1
    end
    -- No wake IRQ yet (UART RX isn't on the PLIC): burn a large idle slice
    -- then continue so poll loops after WFI still make progress (68k STOP-like).
    self.waiting = false
    self.cycles = self.cycles + 4096
    return 4096
  end

  self.illegal = false
  self.ecall = false
  self.ebreak = false
  self.trap_cause = nil

  -- Timer IRQ check every 16 steps (still responsive; huge win when idle).
  local irq_div = self._irq_div + 1
  if irq_div >= 16 then
    self._irq_div = 0
    if self:check_interrupts() then
      self:take_trap()
      self.cycles = self.cycles + 1
      return 1
    end
  else
    self._irq_div = irq_div
  end

  local csr = self.csr
  local pa = self.pc
  -- Fast path: M-mode or bare satp -> PC is already physical (no Sv39 / no clone).
  if csr.priv ~= Csr.PRIV_M and Sv39.mode(csr.satp) ~= 0 then
    pa = self:translate(self.pc, "fetch")
    if not pa then
      self:take_trap()
      self.cycles = self.cycles + 1
      return 1
    end
  end
  local insn = self:read32_phys(pa)
  local d = Decode.decode_into(self._dec, insn)
  local cyc = Ops.execute(self, d)
  if self.trap_cause ~= nil then
    self:take_trap()
  end
  self.cycles = self.cycles + (cyc or 1)
  return cyc or 1
end

function RV64I:run_cycles(budget)
  budget = math.floor(tonumber(budget) or 0)
  local ran = 0
  local step = RV64I.step
  while ran < budget do
    local c = step(self)
    if c <= 0 then break end
    ran = ran + c
  end
  return ran
end

function RV64I:getRegisters()
  local regs = {
    pc = U64.to_hex(self.pc),
    priv = self.csr.priv,
    mstatus = U64.to_hex(self.csr.mstatus),
    mtvec = U64.to_hex(self.csr.mtvec),
    mepc = U64.to_hex(self.csr.mepc),
    mcause = U64.to_hex(self.csr.mcause),
  }
  for i = 0, 31 do
    regs["x" .. i] = U64.to_hex(self:get_x(i))
  end
  return regs
end

function RV64I:pc_u32()
  return self.pc.lo
end

return RV64I
