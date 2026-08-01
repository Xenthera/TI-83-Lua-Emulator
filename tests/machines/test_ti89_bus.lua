-- Foundational TI-89 bus / RAM / flash / IRQ tests (no AMS install path).
return function(ok)
  local bit = require("framework.util.bit")
  local band = bit.band
  local Manager = require("framework.manager")
  local Flash = require("machines.ti89.mem.flash")

  local m = assert(Manager.create("ti89"))
  local bus = m.bus

  ------------------------------------------------------------------
  -- RAM mirror + vector write-protect ($000–$11F, all mirrors)
  ------------------------------------------------------------------
  bus:reset()
  bus:write8(0x000400, 0x5A)
  ok("ram write low", bus:read8(0x000400) == 0x5A)
  ok("ram mirror 256k", bus:read8(0x040400) == 0x5A)
  ok("ram mirror high", bus:read8(0x1C0400) == 0x5A)

  bus:write8(0x000000, 0x11)
  bus:write8(0x00011F, 0x22)
  bus:write8(0x000120, 0x33)
  ok("vector protect 0", bus:read8(0x000000) == 0xFF, string.format("%02X", bus:read8(0x000000)))
  ok("vector protect 11F", bus:read8(0x00011F) == 0xFF, string.format("%02X", bus:read8(0x00011F)))
  ok("ram after protect", bus:read8(0x000120) == 0x33)

  bus.ram.bytes[0] = 0xAA
  bus:write8(0x040000, 0x55)
  ok("mirror vector protect", bus.ram.bytes[0] == 0xAA, string.format("%02X", bus.ram.bytes[0]))
  bus:write8(0x040120, 0x66)
  ok("mirror after vector ok", bus.ram.bytes[0x120] == 0x66, string.format("%02X", bus.ram.bytes[0x120]))

  ------------------------------------------------------------------
  -- Flash map: $800000 and $200000 mirrors
  ------------------------------------------------------------------
  m.flash:poke8(0x1234, 0xC3)
  ok("flash @800000", bus:read8(0x801234) == 0xC3)
  ok("flash @200000", bus:read8(0x201234) == 0xC3)
  ok("unmapped read ff", bus:read8(0x600020) == 0xFF)

  ------------------------------------------------------------------
  -- Sharp flash FSM (direct + via bus word writes)
  ------------------------------------------------------------------
  local fl = Flash.new(4 * 1024 * 1024)
  fl:write16(0, 0x9090) -- ID
  ok("flash id manuf", fl:read8(1) == 0x89, string.format("%02X", fl:read8(1)))
  ok("flash id device", fl:read8(3) == 0xB5, string.format("%02X", fl:read8(3)))
  fl:write16(0, 0xFFFF) -- read array

  fl:write16(0, 0x9898) -- CFI
  ok("cfi Q", fl:read8(0x20) == 0x51, string.format("%02X", fl:read8(0x20)))
  ok("cfi R", fl:read8(0x22) == 0x52, string.format("%02X", fl:read8(0x22)))
  ok("cfi Y", fl:read8(0x24) == 0x59, string.format("%02X", fl:read8(0x24)))
  ok("cfi size 4MB", fl:read8(0x4E) == 0x16, string.format("%02X", fl:read8(0x4E)))
  fl:write16(0, 0xFFFF)

  -- Program clears bits only. After program/erase the chip is in status mode
  -- until $FF returns it to read-array.
  fl:poke8(0x8000, 0xFF)
  fl:poke8(0x8001, 0xFF)
  fl:write16(0x8000, 0x4040)
  fl:write16(0x8000, 0x55AA)
  ok("program status ready", fl:read8(0x8000) == 0x80, string.format("%02X", fl:read8(0x8000)))
  fl:write16(0, 0xFFFF)
  ok("program hi", fl:read8(0x8000) == 0x55, string.format("%02X", fl:read8(0x8000)))
  ok("program lo", fl:read8(0x8001) == 0xAA, string.format("%02X", fl:read8(0x8001)))
  fl:write16(0x8000, 0x4040)
  fl:write16(0x8000, 0x00FF) -- 0x55&0x00=0, 0xAA&0xFF=0xAA
  fl:write16(0, 0xFFFF)
  ok("program bit-clear only", fl:read8(0x8000) == 0x00 and fl:read8(0x8001) == 0xAA,
    string.format("%02X%02X", fl:read8(0x8000), fl:read8(0x8001)))

  -- Erase 8KB parameter block; neighbor intact.
  for i = 0, 0x3FFF do fl:poke8(i, 0x00) end
  fl:write16(0x1000, 0x2020)
  fl:write16(0x1000, 0xD0D0)
  fl:write16(0, 0xFFFF)
  ok("erase 8k cleared", fl:read8(0x1000) == 0xFF)
  ok("erase spares neighbor 8k", fl:read8(0x2000) == 0x00, string.format("%02X", fl:read8(0x2000)))

  -- Via machine bus: word command path (not split write8).
  bus:reset()
  m.flash:load(string.rep("\255", m.flash.size))
  bus:write16(0x800000, 0x9090)
  ok("bus flash id", bus:read8(0x800001) == 0x89, string.format("%02X", bus:read8(0x800001)))
  bus:write16(0x800000, 0xFFFF)

  ------------------------------------------------------------------
  -- Timers / IRQs / sleep wake
  ------------------------------------------------------------------
  bus:reset()
  bus:tick(62500)
  ok("ai1 pending", band(bus.irq_pending, 0x02) ~= 0, string.format("%02X", bus.irq_pending))
  bus.irq_pending = 0
  bus:tick(800000)
  ok("ai5 pending", band(bus.irq_pending, 0x20) ~= 0, string.format("%02X", bus.irq_pending))
  bus.irq_pending = 0
  bus:write8(0x71005F, 0x03)
  bus:tick(16000000)
  ok("ai3 pending", band(bus.irq_pending, 0x08) ~= 0, string.format("%02X", bus.irq_pending))
  -- $71005F bit0 is RTC enable (must stick); TiEmu forces bit7.
  ok("rtc enable sticks", bus:read8(0x71005F) == 0x83, string.format("%02X", bus:read8(0x71005F)))

  -- HW3 RTC: writing $71005F with bit0=1,bit1=0 reloads count from load regs.
  bus:write8(0x71005F, 0x00) -- disable
  bus:write8(0x710040, 0x00)
  bus:write8(0x710041, 0x00)
  bus:write8(0x710042, 0x00)
  bus:write8(0x710043, 0x64) -- 100 seconds
  bus:write8(0x710044, 0x00)
  bus:write8(0x71005F, 0x01) -- enable + reload (bit1 clear)
  ok("rtc reload lo", bus:read8(0x710049) == 0x64, string.format("%02X", bus:read8(0x710049)))
  ok("rtc enable bit", band(bus:read8(0x71005F), 0x01) ~= 0)
  bus:write8(0x71005F, 0x03) -- leave enabled with bit1 set

  -- $600005 sleep: AI3|AI4 mask ($0C) wakes on AI3 even at IPL 7.
  local bytes = {}
  for i = 0, 0xFFFF do bytes[i] = 0 end
  local function poke16(addr, v)
    bytes[addr] = math.floor(v / 256) % 256
    bytes[addr + 1] = v % 256
  end
  local function poke32(addr, v)
    poke16(addr, math.floor(v / 65536) % 65536)
    poke16(addr + 2, v % 65536)
  end
  poke32(0, 0x1000)
  poke32(4, 0x0400)
  -- All autovectors park at $800: after sleep wake, lower IRQs still pending
  -- in the bus latch can fire before the test inspects PC.
  for lvl = 1, 7 do poke32((24 + lvl) * 4, 0x0400) end
  -- Handler lives in RAM ($000000–$1FFFFF); flash image only supplies reset vectors.
  poke16(0x400, 0x60FE) -- BRA.S * park (written into RAM after reset)
  local parts = {}
  for i = 0, 0xFFFF do parts[i + 1] = string.char(bytes[i]) end
  local m2 = assert(Manager.create("ti89"))
  assert(m2:load_rom_bytes(table.concat(parts)))
  m2:reset()
  m2.bus:write16(0x400, 0x60FE) -- park loop in RAM
  m2.cpu.sr = 0x2700
  m2.cpu.pc = 0x420
  m2.bus:write8(0x600005, 0x0C) -- sleep, wake AI3|AI4
  ok("sleep stopped", m2.cpu.stopped == true)
  m2:run_cycles(16000000 + 2000)
  ok("sleep woke on ai3", m2.cpu.stopped == false)
  ok("sleep landed ai3 vec", m2:pc() == 0x400,
    string.format("%X", m2:pc()))

  -- Without sleep, IPL 7 masks AI3.
  local m3 = assert(Manager.create("ti89"))
  assert(m3:load_rom_bytes(table.concat(parts)))
  m3:reset()
  m3.cpu.sr = 0x2700
  m3.cpu.pc = 0x420
  m3.bus:write16(0x420, 0x4E71)
  m3.bus:write16(0x422, 0x60FE) -- BRA.S *
  m3.bus.irq_pending = 0
  m3.bus:tick(16000000)
  local lvl = m3.bus:irq_level_pending()
  ok("ipl7 masks ai3", lvl == 0, tostring(lvl))

  ------------------------------------------------------------------
  -- LCD snoop window + display enable
  ------------------------------------------------------------------
  bus:reset()
  local lcd = m.lcd
  lcd:set_snoop_range(0) -- $4C00
  bus:write8(0x4C00, 0x81)
  ok("lcd snoop default", lcd.fb[0] == 0x81, string.format("%02X", lcd.fb[0] or -1))
  bus:write8(0x700017, 1) -- snoop $5C00
  lcd:set_snoop_range(1)
  bus:write8(0x4C00, 0x00)
  bus:write8(0x5C00, 0x42)
  ok("lcd snoop moved", lcd.fb[0] == 0x42, string.format("%02X", lcd.fb[0] or -1))

  bus:write8(0x70001D, 0x00)
  ok("lcd off via 70001D", lcd.display_on == false)
  bus:write8(0x70001D, 0x02)
  ok("lcd on via 70001D", lcd.display_on == true)

  ------------------------------------------------------------------
  -- Misc I/O defaults
  ------------------------------------------------------------------
  bus:reset()
  ok("battery ok bit", band(bus:read8(0x600000), 0x04) ~= 0)
  ok("710055 default", bus:read8(0x710055) == 0x14, string.format("%02X", bus:read8(0x710055)))
  bus:write8(0x710057, 0x2A)
  ok("710057 retain", bus:read8(0x710057) == 0x2A)

  ------------------------------------------------------------------
  -- $700012 flash exec protect + AI4
  ------------------------------------------------------------------
  bus:reset()
  ok("700012 default hi", bus:read8(0x700012) == 0x00)
  ok("700012 default n=18", bus:read8(0x700013) == 0x18, string.format("%02X", bus:read8(0x700013)))
  -- AMS image area (classic $212188) is below $390000 → allowed
  ok("ams flash exec ok", bus:exec_allowed(0x812188) == true)
  -- Archive sector at classic $390000 / Titanium $990000 forbidden
  ok("archive flash exec blocked", bus:exec_allowed(0x990000) == false)
  bus:write8(0x700013, 0x3F) -- raise cutoff; almost nothing protected below end
  ok("cutoff raised allows mid", bus:exec_allowed(0x990000) == true)

  -- TI-92+ 2MB: ROM vectors use $40xxxx aliases of $20xxxx (flash size wrap).
  local m92 = assert(Manager.create("ti92plus"))
  local b92 = m92.bus
  b92:reset()
  ok("92 alias $400132 exec", b92:exec_allowed(0x400132) == true)
  ok("92 low $200132 exec", b92:exec_allowed(0x200132) == true)
  ok("92 alias $412188 exec", b92:exec_allowed(0x412188) == true)
  ok("92 archive still blocked", b92:exec_allowed(0x390000) == false)

  bus:reset()
  bus.irq_pending = 0
  bus:tick(2000000)
  ok("ai4 pending", band(bus.irq_pending, 0x10) ~= 0, string.format("%02X", bus.irq_pending))

  -- RAM exec protect only when Protection latch is on.
  bus:reset()
  bus.protect_enabled = true
  ok("ram $400 blocked by default mask", bus:exec_allowed(0x400) == false)
  ok("ram $5000 allowed", bus:exec_allowed(0x5000) == true)
  bus:write16(0x700000, 0x0000) -- allow all low pages
  ok("ram allow-all", bus:exec_allowed(0x400) == true)
end
