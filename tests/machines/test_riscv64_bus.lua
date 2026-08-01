-- Registerable bus + device routing tests.

return function(ok)
  local Bus = require("machines.riscv64.hw.bus")
  local Machine = require("machines.riscv64.machine")
  local Boot = require("machines.riscv64.boot")
  local bit = require("framework.util.bit")
  local band = bit.band

  do
    local hits = {}
    local dev = {
      read8 = function(self, off) hits[#hits + 1] = { "r", off }; return 0x5A end,
      write8 = function(self, off, v) hits[#hits + 1] = { "w", off, v } end,
    }
    local bus = Bus.new()
    bus:map("dev", 0x1000, 0x100, dev)
    ok("bus read routes", bus:read8(0x1010) == 0x5A and hits[1][2] == 0x10)
    bus:write8(0x1011, 0x42)
    ok("bus write routes", hits[2][1] == "w" and hits[2][2] == 0x11 and hits[2][3] == 0x42)
    ok("bus unmapped read 0", bus:read8(0x2000) == 0)
  end

  do
    local m = Machine.new()
    ok("uart mapped", m.bus_dev:device("uart") == m.uart)
    ok("clint mapped", m.bus_dev:device("clint") == m.clint)
    ok("plic mapped", m.bus_dev:device("plic") == m.plic)
    m.bus_dev:write8(Bus.UART_BASE, 65) -- 'A'
    ok("uart via bus", m.uart:text() == "A")
    m.bus_dev:write8(Bus.HALT_ADDR, 1)
    ok("halt via bus", m.bus_dev.halted == true)
  end

  do
    local m = Machine.new()
    -- OpenSBI-style load into RAM (fake fw)
    local fw = string.rep(string.char(0x13, 0x00, 0x00, 0x00), 4) -- nops
    local okb, err = Boot.load_opensbi(m, {
      fw_bytes = fw,
      kernel_bytes = "KERN",
      dtb_bytes = "DTB!",
    })
    ok("opensbi load", okb, err)
    ok("opensbi disables lua sbi", m.use_lua_sbi == false)
    ok("pc at fw base", m.cpu.pc.lo == Bus.FW_BASE)
    ok("a1 dtb", m.cpu:get_x(11).lo == Bus.DTB_BASE)
    ok("kernel in ram", m.ram:read8(Bus.KERNEL_BASE - Bus.RAM_BASE) == string.byte("K"))
  end

  do
    local m = Machine.new()
    local okb = Boot.load_kernel_s_mode(m, {
      kernel_bytes = "ABCD",
      entry = Bus.RAM_BASE,
      dtb_addr = Bus.DTB_BASE,
      dtb_bytes = "dtb",
    })
    ok("s-mode kernel boot", okb and m.use_lua_sbi == true)
    ok("s-mode priv", m.cpu.csr.priv == 1)
  end
end
