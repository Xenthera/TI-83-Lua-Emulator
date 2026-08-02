return function(ok)
  local bit = require("framework.util.bit")
  local band = bit.band
  local Manager = require("framework.manager")
  local Debugger = require("framework.debugger")

  local ids = Manager.list()
  local function has(id)
    for _, x in ipairs(ids) do if x == id then return true end end
    return false
  end
  ok("manager lists ti83plus", has("ti83plus"))
  ok("manager lists ti84plus", has("ti84plus"))
  ok("manager lists ti89", has("ti89"))
  ok("manager lists ti92plus", has("ti92plus"))

  local m89 = assert(Manager.create("ti89"))
  ok("ti89 model is Titanium", m89.MODEL == "TI-89 Titanium")
  ok("ti89 flash 4MB", m89.flash.size == 4 * 1024 * 1024)
  ok("ti89 has lcd 160", m89.lcd.WIDTH == 160)
  ok("ti89 has lcd 100", m89.lcd.HEIGHT == 100)

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
  poke32(0, 0x00001000)
  poke32(4, 0x00000400)
  poke16(0x400, 0x7001)
  poke16(0x402, 0x60FE)
  local parts = {}
  for i = 0, 0xFFFF do parts[i + 1] = string.char(bytes[i]) end
  local rom = table.concat(parts)

  ok("ti89 load rom", m89:load_rom_bytes(rom))
  m89:reset()
  ok("ti89 reset pc", m89:pc() == 0x400, string.format("%X", m89:pc()))
  m89:run_cycles(100)
  ok("ti89 ran", m89.total_cycles > 0)
  ok("ti89 keyDown", m89:keyDown("enter") == true)
  ok("ti89 getLCD", type(m89:getLCD().framebuffer) == "table")

  -- HW3 RTC control at $71005F: only bits 0-1 stick; bit7 always set (TiEmu).
  m89.bus:write8(0x71005F, 0xFE)
  ok("ti89 hw3 rtc ctrl mask", m89.bus:read8(0x71005F) == 0x82,
    string.format("%02X", m89.bus:read8(0x71005F)))
  ok("ti89 hw3 rtc status default", m89.bus:read8(0x710055) == 0x14,
    string.format("%02X", m89.bus:read8(0x710055)))
  -- AI3 ~1 Hz; RTC enable bit must remain set (install checks $71005F:0).
  m89.bus:write8(0x71005F, 0x03)
  m89.bus:tick(16000000)
  ok("ti89 ai3 raised", band(m89.bus.irq_pending, 0x08) ~= 0,
    string.format("%02X", m89.bus.irq_pending))
  ok("ti89 rtc enable sticks", m89.bus:read8(0x71005F) == 0x83,
    string.format("%02X", m89.bus:read8(0x71005F)))

  local st = m89:saveState()
  m89:keyUp("enter")
  m89.cpu.d[0] = 0
  ok("ti89 loadState", m89:loadState(st))

  local m92 = assert(Manager.create("ti92plus"))
  ok("ti92 model", m92.MODEL == "TI-92 Plus")
  ok("ti92 flash 2MB", m92.flash.size == 2 * 1024 * 1024)
  ok("ti92 lcd 240", m92.lcd.WIDTH == 240)
  ok("ti92 lcd 128", m92.lcd.HEIGHT == 128)
  ok("ti92 qwerty has q", m92.keyboard.KEY_MAP.q ~= nil)
  ok("ti92 qwerty has enter", m92.keyboard.KEY_MAP.enter ~= nil)
  ok("ti92 qwerty 10 rows", m92.keyboard.ROWS == 10)
  -- Matrix: Q is row9 col3; mask only that row -> column bit3 clears.
  m92:set_key("q", true)
  m92.keyboard:write_mask(band(0xFFFF, bit.bnot(bit.lshift(1, 9))))
  local cols = m92.keyboard:read()
  ok("ti92 q scan clears col3", band(cols, 0x08) == 0, string.format("%02X", cols))
  m92:set_key("q", false)
  ok("ti92 keyDown enter", m92:keyDown("enter") == true)

  local dbg = Debugger.new(m89)
  ok("debugger disasm", type(dbg:disassemble_at(m89:pc())) == "string")
end
