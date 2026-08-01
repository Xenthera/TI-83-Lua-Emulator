-- Guest payload loader (OpenSBI + Linux Image + DTB).
-- These are host files; the emulator only places them in guest memory.
--
-- OpenSBI fw_jump convention (DRAM):
--   FW     @ 0x80000000  (reset PC)
--   Image  @ 0x80200000
--   DTB    @ 0x82000000
--   a0 = hartid, a1 = dtb pa
--
-- Until a real fw_jump.bin is present, Machine keeps the Lua SBI shim.

local Bus = require("machines.riscv64.hw.bus")
local U64 = require("cpus.riscv.u64")

local Boot = {}

Boot.FW_BASE = Bus.FW_BASE
Boot.KERNEL_BASE = Bus.KERNEL_BASE
Boot.DTB_BASE = Bus.DTB_BASE

local function read_file(path)
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local data = f:read("*a")
  f:close()
  if not data or #data == 0 then
    return nil, "empty file: " .. path
  end
  return data
end

--- Write arbitrary bytes at a physical address (RAM or ROM window).
function Boot.poke(machine, phys, bytes)
  local bit = require("framework.util.bit")
  phys = bit.band(phys, 0xFFFFFFFF)
  if phys >= Bus.RAM_BASE then
    return machine:write_ram(phys, bytes)
  end
  -- Low ROM window
  local rom = machine.rom
  if not rom then
    return nil, "no ROM device"
  end
  for i = 1, #bytes do
    local off = phys + i - 1
    rom.data[off] = bytes:byte(i)
    if off + 1 > (rom.size or 0) then
      rom.size = off + 1
    end
  end
  return true
end

--- Load OpenSBI firmware + optional kernel/dtb; start at firmware in M-mode.
function Boot.load_opensbi(machine, opts)
  opts = opts or {}
  local fw = opts.fw_bytes
  if opts.fw_path and not fw then
    local data, err = read_file(opts.fw_path)
    if not data then return nil, err end
    fw = data
  end
  if not fw then
    return nil, "OpenSBI firmware required (fw_jump.bin)"
  end

  local fw_base = opts.fw_base or Boot.FW_BASE
  local kern_base = opts.kernel_base or Boot.KERNEL_BASE
  local dtb_base = opts.dtb_base or Boot.DTB_BASE

  local ok, err = Boot.poke(machine, fw_base, fw)
  if not ok then return nil, err end

  if opts.kernel_bytes or opts.kernel_path then
    local k = opts.kernel_bytes
    if not k then
      k, err = read_file(opts.kernel_path)
      if not k then return nil, err end
    end
    ok, err = Boot.poke(machine, kern_base, k)
    if not ok then return nil, err end
  end

  if opts.dtb_bytes or opts.dtb_path then
    local d = opts.dtb_bytes
    if not d then
      d, err = read_file(opts.dtb_path)
      if not d then return nil, err end
    end
    ok, err = Boot.poke(machine, dtb_base, d)
    if not ok then return nil, err end
  end

  machine.cpu:reset()
  if machine.clint then machine.clint:reset() end
  machine.use_lua_sbi = false -- real firmware owns SBI ecalls
  machine.cpu:set_x(10, U64.zero()) -- a0 hartid
  machine.cpu:set_x(11, U64.from_u32(dtb_base)) -- a1 dtb
  machine.cpu.pc = U64.from_u32(fw_base)
  machine.cpu.csr.priv = require("cpus.riscv.csr").PRIV_M
  machine.rom_loaded = true
  return true
end

--- Legacy helper: jump straight into S-mode kernel (Lua SBI).
function Boot.load_kernel_s_mode(machine, opts)
  opts = opts or {}
  local entry = opts.entry or Boot.KERNEL_BASE
  local dtb = opts.dtb_addr or Boot.DTB_BASE
  if opts.kernel_bytes then
    local ok, err = Boot.poke(machine, entry, opts.kernel_bytes)
    if not ok then return nil, err end
  end
  if opts.dtb_bytes then
    local ok, err = Boot.poke(machine, dtb, opts.dtb_bytes)
    if not ok then return nil, err end
  end
  local Csr = require("cpus.riscv.csr")
  machine.cpu:reset()
  if machine.clint then machine.clint:reset() end
  machine.use_lua_sbi = true
  machine.cpu:set_x(10, U64.zero())
  machine.cpu:set_x(11, U64.from_u32(dtb))
  machine.cpu:set_x(2, U64.from_u32(Bus.RAM_BASE + machine.ram.size))
  machine.cpu.csr.mepc = U64.from_u32(entry)
  machine.cpu.csr.mstatus = Csr.mpp_set(machine.cpu.csr.mstatus, Csr.PRIV_S)
  machine.cpu.pc = machine.cpu.csr:mret()
  machine.rom_loaded = true
  return true
end

return Boot
