return function(ok)
  local Machine = require("machines.gameboy.machine")
  local bit = require("framework.util.bit")
  local band = bit.band

  -- Minimal ROM-only cart: NOP sled + HALT at 0x150, header at 0x100
  local function make_rom()
    local bytes = {}
    for i = 1, 0x8000 do bytes[i] = string.char(0x00) end
    -- entry at 0x100: JR to 0x150
    bytes[0x101] = string.char(0x00) -- placeholder; rebuild as string
    local t = {}
    for i = 0, 0x7FFF do t[i + 1] = 0x00 end
    -- Nintendo logo region / header fields
    t[0x0147 + 1] = 0x00 -- ROM only
    t[0x0148 + 1] = 0x00 -- 32KB
    t[0x0149 + 1] = 0x00 -- no RAM
    -- Title
    local title = "TESTROM"
    for i = 1, #title do t[0x0134 + i] = title:byte(i) end
    -- Code at 0x0100 (post-boot entry): LD A,$42; LDH ($80),A; HALT
    local code = { 0x3E, 0x42, 0xE0, 0x80, 0x76 }
    for i, b in ipairs(code) do t[0x0100 + i] = b end
    local s = {}
    for i = 1, #t do s[i] = string.char(t[i]) end
    return table.concat(s)
  end

  local m = Machine.new()
  local loaded = m:load_rom_bytes(make_rom())
  ok("load rom", loaded)
  m:reset()
  ok("post-boot pc", m.cpu.pc == 0x0100)
  ok("cart title", m.cart.title == "TESTROM")

  -- WRAM / HRAM via MMU
  m.mmu:write(0xC000, 0x55)
  ok("wram", m.mmu:read(0xC000) == 0x55 and m.mmu:read(0xE000) == 0x55)
  m.mmu:write(0xFF80, 0xAA)
  ok("hram", m.mmu:read(0xFF80) == 0xAA)

  -- APU registers (powered via reset post-boot NR52)
  m.mmu:write(0xFF24, 0x77)
  ok("apu nr50", m.mmu:read(0xFF24) == 0x77)
  local nr52 = m.mmu:read(0xFF26)
  ok("apu powered", band(nr52, 0x80) ~= 0)

  -- Run until HALT
  for _ = 1, 100 do
    if m.cpu.halted then break end
    m:step_instruction()
  end
  ok("run homebrew", m.cpu.halted and m.cpu.a == 0x42 and m.mmu:read(0xFF80) == 0x42)

  -- Timer DIV increments
  local div0 = m.mmu:read(0xFF04)
  m:run_cycles(256)
  local div1 = m.mmu:read(0xFF04)
  ok("div ticks", div1 ~= div0)

  -- Joypad
  m:set_key("a", true)
  m.mmu:write(0xFF00, 0x10) -- select action buttons (clear bit5... actually bit5=0 selects action)
  -- P15 (bit5)=0 selects A/B/Select/Start; write 0x10 means bit4=1 bit5=0
  m.mmu:write(0xFF00, 0x10)
  local p1 = m.mmu:read(0xFF00)
  ok("joypad a", band(p1, 0x01) == 0) -- A is bit0 of action nibble

  -- PPU framebuffer exists after some lines
  m.ppu.lcdc = 0x91
  m:run_cycles(456 * 10)
  ok("ppu ly advances", m.ppu.ly > 0)
  local fb = m:framebuffer()
  ok("framebuffer size", fb and fb[0] ~= nil and fb[160 * 144 - 1] ~= nil)

  -- IE/IF
  m.mmu:write(0xFFFF, 0x04)
  m.irq:request(0x04)
  ok("irq pending", m.irq:pending() == 0x04)

  -- Cartridge SRAM sidecar (.sav / rom_data) — ROM file stays read-only.
  ok("save path beside rom", Machine.save_path_for("rom/gb/foo.gb") == "rom/gb/foo.sav")
  ok("save path save_dir", Machine.save_path_for("foo.gb", { save_dir = "saves/gameboy" })
    == "saves/gameboy/foo.sav")

  local function make_ram_cart()
    local t = {}
    for i = 0, 0x7FFF do t[i + 1] = 0x00 end
    t[0x0147 + 1] = 0x03 -- MBC1+RAM+BATTERY
    t[0x0148 + 1] = 0x00
    t[0x0149 + 1] = 0x02 -- 8KB RAM
    local title = "SAVETST"
    for i = 1, #title do t[0x0134 + i] = title:byte(i) end
    local s = {}
    for i = 1, #t do s[i] = string.char(t[i]) end
    return table.concat(s)
  end

  local m2 = Machine.new()
  ok("load ram cart", m2:load_rom_bytes(make_ram_cart(), { path = "savetst.gb", skip_save = true }))
  ok("has save ram", m2.cart:has_save_ram() and m2.cart.ram_size == 8192)
  ok("save path set", m2.save_path == "savetst.sav")
  m2.cart.ram_enable = true
  m2.mmu:write(0xA000, 0x5A)
  m2.mmu:write(0xA001, 0xA5)
  local exported = m2.cart:export_ram()
  ok("export ram len", #exported == 8192 and exported:byte(1) == 0x5A and exported:byte(2) == 0xA5)

  local m3 = Machine.new()
  ok("load second cart", m3:load_rom_bytes(make_ram_cart(), { path = "savetst.gb", skip_save = true }))
  ok("import ram", m3.cart:import_ram(exported))
  m3.cart.ram_enable = true
  ok("import roundtrip", m3.mmu:read(0xA000) == 0x5A and m3.mmu:read(0xA001) == 0xA5)

  local st = m2:saveState()
  ok("saveState rom_data", st and st.blobs and type(st.blobs.rom_data) == "string"
    and #st.blobs.rom_data == 8192)
  local function make_other_cart()
    local t = {}
    for i = 0, 0x7FFF do t[i + 1] = 0x00 end
    t[0x0147 + 1] = 0x03
    t[0x0149 + 1] = 0x02
    local title = "OTHER"
    for i = 1, #title do t[0x0134 + i] = title:byte(i) end
    local s = {}
    for i = 1, #t do s[i] = string.char(t[i]) end
    return table.concat(s)
  end
  local m4 = Machine.new()
  assert(m4:load_rom_bytes(make_other_cart(), { path = "other.gb", skip_save = true }))
  local lok, lerr = m4:loadState(st)
  ok("loadState title mismatch", not lok and type(lerr) == "string")
  local m5 = Machine.new()
  assert(m5:load_rom_bytes(make_ram_cart(), { path = "savetst.gb", skip_save = true }))
  ok("loadState same cart", m5:loadState(st))
  m5.cart.ram_enable = true
  ok("loadState ram", m5.mmu:read(0xA000) == 0x5A)
end
