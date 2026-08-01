-- Sv39 virtual memory walk.
--
-- Think of satp as "page table base + on/off switch":
--   MODE=0  → bare: VA is PA (what we had in phase 1)
--   MODE=8  → Sv39: split VA into 3 VPN indexes + 12-bit page offset,
--             walk PTE[2]→PTE[1]→PTE[0], then PA = PPN<<12 | offset.
--
-- Faults become traps (instruction/load/store page fault) with stval/mtval=VA.

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift
local U64 = require("cpus.riscv.u64")
local Csr = require("cpus.riscv.csr")

local Sv39 = {}

local PTE_V = 0x001
local PTE_R = 0x002
local PTE_W = 0x004
local PTE_X = 0x008
local PTE_U = 0x010
local PTE_G = 0x020
local PTE_A = 0x040
local PTE_D = 0x080

local SATP_MODE_BARE = 0
local SATP_MODE_SV39 = 8

local MSTATUS_SUM = 0x40000 -- bit 18
local MSTATUS_MXR = 0x80000 -- bit 19

function Sv39.mode(satp)
  -- MODE lives in satp[63:60]
  return band(rshift(satp.hi, 28), 0xF)
end

function Sv39.ppn(satp)
  -- PPN in satp[43:0]
  return U64.band(satp, U64.new(0x00000FFF, 0xFFFFFFFF))
end

local function read_pte(cpu, paddr)
  -- PTE is 8 bytes little-endian at physical address
  return cpu:read64_phys(paddr)
end

local function write_pte(cpu, paddr, pte)
  cpu:write64_phys(paddr, pte)
end

local function pte_ppn(pte)
  -- PPN = pte[53:10]
  return U64.srl(U64.band(pte, U64.new(0x003FFFFF, 0xFFFFFC00)), 10)
end

local function va_vpn(va, level)
  -- VPN[2]=va[38:30], VPN[1]=va[29:21], VPN[0]=va[20:12]
  if level == 2 then
    return band(rshift(va.lo, 30), 0x1FF) + band(va.hi, 0x7F) * 4 -- bits 38:32 in hi low + 30:31 from lo
  elseif level == 1 then
    return band(rshift(va.lo, 21), 0x1FF)
  else
    return band(rshift(va.lo, 12), 0x1FF)
  end
end

-- Fix VPN[2]: va bits 38:30 = (va >> 30) & 0x1FF
local function va_vpn_fixed(va, level)
  local shifted = U64.srl(va, 12 + 9 * level)
  return band(shifted.lo, 0x1FF)
end

--- Access kinds: "fetch", "load", "store"
--- Returns phys_addr u64, or nil + cause
function Sv39.translate(cpu, va, access)
  local csr = cpu.csr
  local mode = Sv39.mode(csr.satp)
  if mode == SATP_MODE_BARE or csr.priv == Csr.PRIV_M then
    -- M-mode / bare: VA is PA. Return the same object — no clone (hot path).
    return va, nil
  end
  if mode ~= SATP_MODE_SV39 then
    return nil, Csr.CAUSE_INST_PAGE_FAULT
  end

  -- Canonical VA check for Sv39: bits 63:39 = sign extension of bit 38
  local bit38 = band(rshift(va.hi, 6), 1) -- va bit 38 is hi bit 6
  local upper = U64.srl(va, 39)
  local expect = bit38 ~= 0 and U64.new(0xFFFFFFFF, 0xFFFFFFFF) or U64.zero()
  -- Compare bits above 38: for simplicity check hi bits 31:7 all 0 or all 1 matching bit38
  if bit38 == 0 then
    if band(va.hi, 0xFFFFFF80) ~= 0 then
      return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
        or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
    end
  else
    if band(va.hi, 0xFFFFFF80) ~= 0xFFFFFF80 then
      return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
        or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
    end
  end

  local a = U64.sll(Sv39.ppn(csr.satp), 12)
  local pte_addr, pte

  for i = 2, 0, -1 do
    local vpn = va_vpn_fixed(va, i)
    pte_addr = U64.add(a, U64.from_u32(vpn * 8))
    pte = read_pte(cpu, pte_addr)
    local bits = pte.lo
    if band(bits, PTE_V) == 0 then
      return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
        or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
    end
    local r = band(bits, PTE_R) ~= 0
    local w = band(bits, PTE_W) ~= 0
    local x = band(bits, PTE_X) ~= 0
    if not r and not w and not x then
      -- non-leaf: next level
      if i == 0 then
        return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
          or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
      end
      a = U64.sll(pte_ppn(pte), 12)
    else
      -- leaf
      if w and not r then
        return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
          or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
      end
      -- privilege U bit
      local u = band(bits, PTE_U) ~= 0
      if csr.priv == Csr.PRIV_U and not u then
        return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
          or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
      end
      if csr.priv == Csr.PRIV_S and u then
        local sum = band(csr.mstatus.lo, MSTATUS_SUM) ~= 0
        if access == "fetch" or not sum then
          return nil, access == "store" and Csr.CAUSE_STORE_PAGE_FAULT
            or (access == "fetch" and Csr.CAUSE_INST_PAGE_FAULT or Csr.CAUSE_LOAD_PAGE_FAULT)
        end
      end
      -- permission for access type
      if access == "fetch" and not x then
        return nil, Csr.CAUSE_INST_PAGE_FAULT
      end
      if access == "load" then
        local mxr = band(csr.mstatus.lo, MSTATUS_MXR) ~= 0
        if not r and not (mxr and x) then
          return nil, Csr.CAUSE_LOAD_PAGE_FAULT
        end
      end
      if access == "store" and not w then
        return nil, Csr.CAUSE_STORE_PAGE_FAULT
      end
      -- A/D: set in PTE if clear (common hardware behavior)
      local need = false
      local nb = bits
      if band(bits, PTE_A) == 0 then
        nb = bor(nb, PTE_A)
        need = true
      end
      if access == "store" and band(bits, PTE_D) == 0 then
        nb = bor(nb, PTE_D)
        need = true
      end
      if need then
        write_pte(cpu, pte_addr, U64.new(pte.hi, nb))
      end
      -- physical page: for megapage/gigapage, fill lower PPN from VA
      local ppn = pte_ppn(pte)
      local pa
      if i > 0 then
        -- superpage: replace low VPN bits of PPN with VA's
        local off_vpn = U64.band(U64.srl(va, 12), U64.from_u32(lshift(1, 9 * i) - 1))
        ppn = U64.bor(U64.band(ppn, U64.bnot(U64.from_u32(lshift(1, 9 * i) - 1))), off_vpn)
      end
      pa = U64.bor(U64.sll(ppn, 12), U64.band(va, U64.from_u32(0xFFF)))
      return pa, nil
    end
  end
  return nil, Csr.CAUSE_LOAD_PAGE_FAULT
end

Sv39.PTE_V = PTE_V
Sv39.PTE_R = PTE_R
Sv39.PTE_W = PTE_W
Sv39.PTE_X = PTE_X
Sv39.PTE_U = PTE_U
Sv39.PTE_A = PTE_A
Sv39.PTE_D = PTE_D
Sv39.SATP_MODE_SV39 = SATP_MODE_SV39

--- Encode satp for Sv39 with given root PPN (physical page number of L2 table).
function Sv39.make_satp(root_ppn)
  local ppn = type(root_ppn) == "table" and root_ppn or U64.from_u32(root_ppn)
  -- MODE=8 in [63:60] → hi bits 31:28 = 8
  return U64.bor(U64.new(lshift(8, 28), 0), U64.band(ppn, U64.new(0x00000FFF, 0xFFFFFFFF)))
end

--- Encode a leaf PTE: ppn + flags (OR of PTE_*).
function Sv39.make_pte(ppn, flags)
  ppn = type(ppn) == "table" and ppn or U64.from_u32(ppn)
  local p = U64.sll(ppn, 10)
  return U64.bor(p, U64.from_u32(bor(flags, PTE_V)))
end

return Sv39
