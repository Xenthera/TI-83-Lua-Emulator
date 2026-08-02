-- Minimal SBI (Supervisor Binary Interface) served from M-mode.
--
-- Linux does not program the CLINT directly for timers once up -
-- it ecalls into firmware: a7=extension, a6=function, a0..a5=args.
-- We implement enough for early bring-up (not full OpenSBI).

local bit = require("framework.util.bit")
local band = bit.band
local U64 = require("cpus.riscv.u64")
local Csr = require("cpus.riscv.csr")

local Sbi = {}

-- Extension IDs
local EID_BASE = 0x10
local EID_TIMER = 0x54494D45 -- "TIME"
local EID_CONSOLE = 0x4442434E -- legacy "DBCN" skip; use legacy putchar
local EID_LEGACY_PUTCHAR = 0x01
local EID_LEGACY_GETCHAR = 0x02
local EID_LEGACY_SET_TIMER = 0x00
local EID_SRST = 0x53525354 -- "SRST"
local EID_BASE_PROBE = 0x10

local SBI_SUCCESS = 0
local SBI_ERR_NOT_SUPPORTED = -2

local function set_ret(cpu, err, value)
  cpu:set_x(10, U64.from_i32(err)) -- a0
  cpu:set_x(11, value or U64.zero()) -- a1
end

local function skip_ecall(cpu)
  cpu.csr.mepc = U64.add(cpu.csr.mepc, U64.from_u32(4))
end

--- Handle an S-mode ecall that has already trapped to M.
--- Returns true if handled (caller should mret).
function Sbi.handle(cpu, machine)
  if not cpu or not cpu.csr then return false end
  if cpu.csr.mcause.lo ~= Csr.CAUSE_ECALL_S then
    return false
  end
  local eid = cpu:get_x(17).lo -- a7
  local fid = cpu:get_x(16).lo -- a6
  local a0 = cpu:get_x(10)

  -- Legacy SBI (v0.1) still used by some early paths
  if eid == EID_LEGACY_SET_TIMER and fid == 0 then
    if machine and machine.clint then
      machine.clint.mtimecmp = U64.clone(a0)
      cpu.csr:set_mip_bit(Csr.INT_M_TIMER, machine.clint:timer_pending())
    end
    set_ret(cpu, SBI_SUCCESS, U64.zero())
    skip_ecall(cpu)
    return true
  end
  if eid == EID_LEGACY_PUTCHAR then
    if machine and machine.uart then
      machine.uart:tx(band(a0.lo, 0xFF))
    end
    set_ret(cpu, SBI_SUCCESS, U64.zero())
    skip_ecall(cpu)
    return true
  end
  if eid == EID_LEGACY_GETCHAR then
    local ch = -1
    if machine and machine.uart and #machine.uart.rx > 0 then
      ch = table.remove(machine.uart.rx, 1)
    end
    set_ret(cpu, ch, U64.zero())
    skip_ecall(cpu)
    return true
  end

  if eid == EID_BASE then
    -- fid 0: spec version, 1: impl id, 2: impl version, 3: probe extension
    if fid == 0 then
      set_ret(cpu, SBI_SUCCESS, U64.from_u32(0x00010000))
    elseif fid == 1 then
      set_ret(cpu, SBI_SUCCESS, U64.from_u32(0x1)) -- custom
    elseif fid == 2 then
      set_ret(cpu, SBI_SUCCESS, U64.from_u32(1))
    elseif fid == 3 then
      local ext = a0.lo
      local ok = (ext == EID_BASE or ext == EID_TIMER or ext == EID_SRST
        or ext == EID_LEGACY_PUTCHAR or ext == EID_LEGACY_SET_TIMER)
      set_ret(cpu, SBI_SUCCESS, U64.from_u32(ok and 1 or 0))
    else
      set_ret(cpu, SBI_ERR_NOT_SUPPORTED, U64.zero())
    end
    skip_ecall(cpu)
    return true
  end

  if eid == EID_TIMER and fid == 0 then
    -- sbi_set_timer(stime_value)
    if machine and machine.clint then
      machine.clint.mtimecmp = U64.clone(a0)
      cpu.csr:set_mip_bit(Csr.INT_M_TIMER, false) -- clear until deadline
      -- pending will re-assert when mtime catches up
      cpu.csr:set_mip_bit(Csr.INT_M_TIMER, machine.clint:timer_pending())
    end
    set_ret(cpu, SBI_SUCCESS, U64.zero())
    skip_ecall(cpu)
    return true
  end

  if eid == EID_SRST and fid == 0 then
    if machine and machine.bus_dev then
      machine.bus_dev.halted = true
      cpu.halted = true
    end
    set_ret(cpu, SBI_SUCCESS, U64.zero())
    skip_ecall(cpu)
    return true
  end

  -- Unknown: return not supported and skip ecall so we don't loop
  set_ret(cpu, SBI_ERR_NOT_SUPPORTED, U64.zero())
  skip_ecall(cpu)
  return true
end

--- After SBI handle, return to S-mode via mret.
function Sbi.finish(cpu)
  cpu.pc = cpu.csr:mret()
end

return Sbi
