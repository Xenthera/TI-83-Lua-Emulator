-- TI-84 Plus identity, SE-class paging, CPU speed, RTC.
return function(ok)
  local bit = require("framework.util.bit")
  local band = bit.band
  local Manager = require("framework.manager")

  ok("manager lists ti84plus", (function()
    for _, id in ipairs(Manager.list()) do
      if id == "ti84plus" then return true end
    end
    return false
  end)())

  local m = assert(Manager.create("ti84plus"))
  ok("model", m.MODEL == "TI-84 Plus")
  ok("flash 1MB", m.flash.SIZE == 1024 * 1024)
  ok("flash 64 pages", m.flash.NUM_PAGES == 64)
  ok("ram 8 pages", m.ram.NUM_PAGES == 8)
  ok("cpu hz class", m.CPU_HZ == 15000000)

  m.asic:reset()
  local p2 = m.asic:in_port(0x02)
  ok("port02 SE bit7", band(p2, 0x80) ~= 0, string.format("%02X", p2))
  ok("port02 USB bit5", band(p2, 0x20) ~= 0, string.format("%02X", p2))
  ok("port21 1MB", band(m.asic:in_port(0x21), 0x03) == 0)

  -- SE-style RAM select on bit7 (not bit6).
  m.asic:out_port(0x06, 0x81)
  ok("bankA ram via bit7", m.mmu.bankA_is_ram == true)
  ok("bankA ram page 1", m.mmu.page_bankA == 1)
  local r6 = m.asic:in_port(0x06)
  ok("port06 read bit7", band(r6, 0x80) ~= 0, string.format("%02X", r6))

  m.asic:out_port(0x06, 0x2A)
  ok("bankA flash page", m.mmu.page_bankA == 0x2A)
  ok("bankA not ram", m.mmu.bankA_is_ram == false)

  m.ram.bytes[0x4000 + 0x10] = 0x5A -- page 1 offset 0x10
  m.asic:out_port(0x05, 0x01)
  ok("port05 ram page", m.mmu.ram_page == 1)
  ok("C000 maps ram page1", m.mmu:read(0xC010) == 0x5A)

  m.asic:out_port(0x20, 0x01)
  ok("cpu 15MHz", m.asic:effective_cpu_hz() == 15000000)
  ok("machine tracks hz", m._cpu_hz == 15000000)
  m.asic:out_port(0x20, 0x00)
  ok("cpu 6MHz", m.asic:effective_cpu_hz() == 6000000)

  -- RTC set -> latch -> run
  m.asic:out_port(0x41, 0x10)
  m.asic:out_port(0x42, 0x00)
  m.asic:out_port(0x43, 0x00)
  m.asic:out_port(0x44, 0x00)
  m.asic:out_port(0x40, 0x01) -- enable, clear set bit
  m.asic:out_port(0x40, 0x03) -- set edge
  ok("rtc latched", m.asic:in_port(0x45) == 0x10)

  -- Crystal timer 3: OS delay polls port 04 bit 7.
  m.asic:out_port(0x36, 0x47) -- 8 Hz crystal
  m.asic:out_port(0x37, 0x00) -- no loop / no irq (ACK)
  m.asic:out_port(0x38, 0x01) -- 1 tick
  ok("xt3 armed", m.asic.crystal.timers[3].active == true)
  m.asic:tick(m.asic:effective_cpu_hz()) -- ~1s at 8Hz is long; tick full period once
  -- Force enough cycles for one 8Hz tick at current CPU Hz
  local period = m.asic.crystal.timers[3].period
  m.asic:tick(period)
  ok("xt3 expired", m.asic.crystal.timers[3].expired == true)
  ok("port04 bit7", band(m.asic:in_port(0x04), 0x80) ~= 0)
  m.asic:out_port(0x37, 0x00)
  ok("xt3 ack clears", band(m.asic:in_port(0x04), 0x80) == 0)

  local rom = string.rep("\0", 1024 * 1024)
  rom = "\xC3" .. rom:sub(2)
  ok("load 1MB rom", m:load_rom_bytes(rom))

  -- Real dump: cold boot must reach soft power-off, then wake past $0C99.
  local rf = io.open("rom/ti84plus.rom", "rb")
  if not rf then
    ok("ti84plus.rom present", false, "optional; skip boot smoke")
    return
  end
  local raw = rf:read("*a")
  rf:close()
  if #raw ~= 1024 * 1024 then
    ok("ti84plus.rom 1MB", false, tostring(#raw))
    return
  end
  local m2 = assert(Manager.create("ti84plus"))
  ok("boot load", m2:load_rom_bytes(raw))
  m2:reset()
  for _ = 1, 40 do
    m2:run_cycles(500000)
    if m2.cpu.halted and m2:pc() == 0x0C99 then break end
  end
  ok("cold power-off at 0C99", m2.cpu.halted and m2:pc() == 0x0C99,
    string.format("PC=%04X halt=%s", m2:pc(), tostring(m2.cpu.halted)))
  local Eightxp = require("machines.ti84plus.util.eightxp")
  local woke = m2:wake_os({ slice = 1000000 })
  ok("wake_os", woke == true)
  ok("left power-off", m2:pc() ~= 0x0C99 or not m2.cpu.halted,
    string.format("PC=%04X", m2:pc()))
  ok("VAT ready", Eightxp.vat_ready(m2.mmu) == true)
  local lit = 0
  local fb = m2:framebuffer()
  if fb then
    for j = 0, 15 * 64 - 1 do
      if (fb[j] or 0) ~= 0 then lit = lit + 1 end
    end
  end
  -- Homescreen may still be mid-delay; paint within a couple wall-seconds.
  if lit < 20 then
    for _ = 1, 30 do
      m2:run_cycles(1000000)
      lit = 0
      fb = m2:framebuffer()
      if fb then
        for j = 0, 15 * 64 - 1 do
          if (fb[j] or 0) ~= 0 then lit = lit + 1 end
        end
      end
      if lit >= 20 then break end
    end
  end
  ok("LCD painted after wake", lit >= 20, "lit=" .. tostring(lit))
end
