return function(ok)
  local Eightxk = require("core.util.eightxk")
  local Args = require("frontend.computercraft.args")

  local app = Eightxk.make_synthetic({ name = "DEMO", pages = 1, base_page = 0x15 })
  ok("synthetic starts with TIFL", app:sub(1, 8) == "**TIFL**")

  local hex, meta = Eightxk.extract_hex(app)
  ok("extract hex", type(hex) == "string" and hex:sub(1, 1) == ":")
  ok("extract name", meta and meta.name == "DEMO")
  ok("extract type app", meta and meta.data_type == 0x24)

  local pages, perr = Eightxk.parse_intel_hex(hex)
  ok("parse hex pages", pages ~= nil, perr)
  ok("has page 15", pages and pages[0x15] ~= nil)
  ok("header 80", pages and pages[0x15]:byte(1) == 0x80)

  local rom = string.rep("\255", Eightxk.FLASH_SIZE)
  -- Fake a non-blank OS page 0 so size is right; archive stays blank.
  rom = "\195" .. rom:sub(2)

  local out, imeta = Eightxk.inject(rom, app)
  ok("inject ok", out ~= nil, tostring(imeta))
  ok("placed on page 15", imeta and imeta.placed and imeta.placed[1].physical == 0x15)
  if out then
    local off = 0x15 * 0x4000
    ok("rom has header", out:byte(off + 1) == 0x80)
    -- Name field is 80 4n after the 6-byte master field.
    local name_at = off + 7 -- 1-based: skip 80 0F 00 00 00 00
    ok("name field tag", out:byte(name_at) == 0x80 and out:byte(name_at + 1) == 0x44)
    ok("name in rom", out:sub(name_at + 2, name_at + 5) == "DEMO")
  else
    ok("rom has header", false, "no rom")
    ok("name field tag", false, "no rom")
    ok("name in rom", false, "no rom")
  end

  -- pack_app round-trip: header builder -> pack -> inject
  local page = Eightxk.build_app_header("PACKED") .. string.char(0xC9)
  local packed, perr = Eightxk.pack_app(page, { name = "PACKED" })
  ok("pack_app ok", packed ~= nil, tostring(perr))
  ok("pack_app TIFL", packed and packed:sub(1, 8) == "**TIFL**")
  local pout, pmeta = Eightxk.inject(rom, packed)
  ok("pack_app inject", pout ~= nil, tostring(pmeta))
  ok("pack_app page 15", pmeta and pmeta.placed and pmeta.placed[1].physical == 0x15)
  if pout then
    local poff = 0x15 * 0x4000
    ok("pack_app header", pout:byte(poff + 1) == 0x80)
    ok("pack_app name", pout:sub(poff + 9, poff + 14) == "PACKED")
  end

  -- multipage pack: 2 pages, header page count 02
  local p0 = Eightxk.build_app_header("TWOPAGE", 2) .. string.char(0xC9)
  local p1 = string.char(0x00, 0xC9)
  local multi, merr = Eightxk.pack_app({ p0, p1 }, { name = "TWOPAGE" })
  ok("pack_app 2page ok", multi ~= nil, tostring(merr))
  local mout, mmeta = Eightxk.inject(rom, multi)
  ok("pack_app 2page inject", mout ~= nil, tostring(mmeta))
  ok("pack_app 2page count", mmeta and mmeta.pages == 2)
  if mout and mmeta and mmeta.placed then
    ok("pack_app 2page base 15", mmeta.placed[1].physical == 0x15)
    ok("pack_app 2page next 14", mmeta.placed[2] and mmeta.placed[2].physical == 0x14)
    local hoff = 0x15 * 0x4000
    -- Find 80 81 02 in header
    local found = false
    for i = 0, 40 do
      if mout:byte(hoff + 1 + i) == 0x80 and mout:byte(hoff + 2 + i) == 0x81
          and mout:byte(hoff + 3 + i) == 0x02 then
        found = true
        break
      end
    end
    ok("pack_app 2page header count", found)
  end

  local app2 = Eightxk.make_synthetic({ name = "SECOND", pages = 2, base_page = 0x14 })
  local out2, metas = Eightxk.inject_many(rom, { app, app2 })
  ok("inject two apps", out2 ~= nil, tostring(metas))
  ok("two metas", type(metas) == "table" and #metas == 2)

  local parsed = Args.parse({
    "--rom", "foo.rom", "--loadapp", "a.8xk", "--loadapp", "b.8xk", "left", "right",
  })
  ok("parse --rom", parsed and parsed.rom == "foo.rom")
  ok("parse loadapp count", parsed and #parsed.loadapp == 2)
  ok("parse lcd/pad", parsed and parsed.lcd == "left" and parsed.pad == "right")

  local legacy = Args.parse({ "left", "right", "ti83plus.rom" })
  ok("legacy positional rom", legacy and legacy.rom == "ti83plus.rom")

  local bare = Args.parse({ "MyApp.8xk" })
  ok("bare .8xk", bare and #bare.loadapp == 1 and bare.loadapp[1] == "MyApp.8xk")

  local eq = Args.parse({ "--loadapp=Foo.8xk" })
  ok("equals form", eq and eq.loadapp[1] == "Foo.8xk")

  local prog = Args.parse({ "--loadprog", "HI.8xp", "game.8xp" })
  ok("parse loadprog", prog and #prog.loadprog == 2)

  local help = Args.parse({ "--help" })
  ok("parse help", help and help.help == true)
  ok("manpage help has SYNOPSIS", Args.usage_text():find("SYNOPSIS", 1, true) ~= nil)

  local recovered = Args.recover_misparsed({
    lcd = "--loadapp",
    pad = "MyApp.8xk",
    rom = "ti83plus.rom",
  })
  ok("recover old launcher", recovered and recovered.loadapp[1] == "MyApp.8xk"
    and recovered.lcd == nil)

  -- Older GraphLink files often have a nonsense 32-bit size field.
  local solid = Eightxk.make_synthetic({ name = "BOGUS", pages = 1 })
  local huge = solid:sub(1, 74) .. string.char(0xFF, 0xFF, 0xFF, 0x7F) .. solid:sub(79)
  local hex2, err2 = Eightxk.extract_hex(huge)
  ok("bogus TIFL size still extracts", hex2 ~= nil and hex2:sub(1, 1) == ":", tostring(err2))

  local Eightxp = require("core.util.eightxp")
  local xp = Eightxp.make_synthetic({ name = "DEMO" })
  local parsed_xp, xerr = Eightxp.parse(xp)
  ok("parse synthetic 8xp", parsed_xp ~= nil, tostring(xerr))
  ok("8xp name DEMO", parsed_xp and parsed_xp.name == "DEMO")

  local grp = Eightxp.make_synthetic_group({ names = { "AAA", "BBB", "CCC" } })
  local gvars, gerr = Eightxp.parse_vars(grp)
  ok("parse synthetic 8xg", gvars ~= nil, tostring(gerr))
  ok("8xg has 3 vars", gvars and #gvars == 3)
  ok("8xg first AAA", gvars and gvars[1].name == "AAA")
  ok("8xg last CCC", gvars and gvars[3].name == "CCC")

  -- VAT-ready gate (no full OS boot in unit tests).
  local ram = {}
  local fake = {
    read = function(_, a) return ram[a] or 0 end,
    write = function(_, a, v) ram[a] = v % 256 end,
  }
  local function set16(addr, v)
    fake:write(addr, v % 256)
    fake:write(addr + 1, math.floor(v / 256) % 256)
  end
  local function get16(addr)
    return fake:read(addr) + fake:read(addr + 1) * 256
  end
  set16(Eightxp.PROG_PTR, 0xFE66)
  set16(0x982E, 0xFE66) -- PTemp
  set16(0x9824, 0xFE66) -- FPS
  ok("VAT not ready at symTable/symTable", not Eightxp.vat_ready(fake))

  -- Minimal homescreen-like program VAT: two dummy progs + free gap below.
  local progptr = 0xFD10
  -- Entry "X" (8 bytes) at FD10, entry "Y" (8 bytes) below -> ptemp = FD00
  local ptemp, fps = 0xFD00, 0xFD01
  set16(Eightxp.PROG_PTR, progptr)
  set16(0x982E, ptemp)
  set16(0x9824, fps)
  set16(0x9820, fps) -- tempMem
  set16(0x9822, fps) -- fpBase
  set16(0x9826, ptemp) -- OPBase
  set16(0x9828, ptemp) -- OPS
  local function put_prog(hl, name, data_addr)
    fake:write(hl, 0x05)
    fake:write(hl - 1, 0)
    fake:write(hl - 2, 0)
    fake:write(hl - 3, data_addr % 256)
    fake:write(hl - 4, math.floor(data_addr / 256) % 256)
    fake:write(hl - 5, 0)
    fake:write(hl - 6, 1)
    fake:write(hl - 7, string.byte(name))
    fake:write(data_addr, 0)
    fake:write(data_addr + 1, 0)
  end
  put_prog(progptr, "X", 0x9D95)
  put_prog(progptr - 8, "Y", 0x9D97)
  ok("VAT ready with free RAM gap", Eightxp.vat_ready(fake))

  local gmetas, gierr = Eightxp.inject_file(fake, grp)
  ok("inject 8xg group", gmetas ~= nil, tostring(gierr))
  ok("inject 8xg count 3", gmetas and #gmetas == 3)
  ok("inject 8xg names", gmetas and gmetas[1].name == "AAA" and gmetas[3].name == "CCC")
  if gmetas then
    -- Newest entry stays at ProgPtr; walk should stay aligned to PTemp.
    local hl = get16(Eightxp.PROG_PTR)
    local pt = get16(0x982E)
    local n = 0
    while hl > pt and n < 16 do
      n = n + 1
      local nl = fake:read(hl - 6)
      if nl > 8 then break end
      hl = hl - (7 + nl)
    end
    ok("inject 8xg VAT walk aligns", hl == pt and n >= 4)
  end

  -- Live flash inject (control-panel .8xk path).
  local flash = {}
  for i = 0, Eightxk.FLASH_SIZE - 1 do
    flash[i] = 0xFF
  end
  local live = Eightxk.make_synthetic({ name = "LIVE", pages = 1, base_page = 0x15 })
  local lmeta, lerr = Eightxk.inject_flash(flash, live)
  ok("inject_flash ok", lmeta ~= nil, tostring(lerr))
  ok("inject_flash page 15", lmeta and lmeta.placed and lmeta.placed[1].physical == 0x15)
  if lmeta then
    local off = 0x15 * 0x4000
    ok("inject_flash wrote header", flash[off] == 0x80)
  end

  local Gui = require("frontend.computercraft.control_gui")
  ok("program_dir is string", type(Gui.program_dir()) == "string")
  local wrapped = Gui.wrap_text(
    "VAT not ready yet - wait until the homescreen is up, then retry",
    20
  )
  ok("wrap_text multiple lines", #wrapped >= 3)
  local long_ok = true
  for _, line in ipairs(wrapped) do
    if #line > 20 then long_ok = false end
  end
  ok("wrap_text respects width", long_ok)
  ok("role cycle lcd->pad", Gui.next_role("lcd") == "pad")
  ok("role cycle pad->mem", Gui.next_role("pad") == "mem")
  ok("role cycle mem->off", Gui.next_role("mem") == "off")
  ok("role cycle off->lcd", Gui.next_role("off") == "lcd")

  local Prefs = require("frontend.computercraft.prefs")
  local tmp = os.tmpname()
  -- Prefs.path uses program dir; exercise save/load via explicit filename by
  -- writing through save_monitors after stubbing path - use load on a hand file.
  local sample = "monitor left lcd\nmonitor right mem\n# comment\nmonitor top off\n"
  local wf = assert(io.open(tmp, "w"))
  wf:write(sample)
  wf:close()
  -- Direct parse by reading through CC.read_file won't see tmp unless we
  -- call Prefs.load with that name from CWD - instead unit-test VALID_ROLE
  -- and round-trip save into a dir we control via monkeypatch-free helper:
  local saved_path = Prefs.save_monitors({
    left = "lcd",
    right = "pad",
    top = "mem",
  }, "ti83_prefs_test.tmp")
  ok("prefs save writes path", type(saved_path) == "string")
  if saved_path then
    local loaded = Prefs.load("ti83_prefs_test.tmp")
    ok("prefs load left lcd", loaded.monitors.left == "lcd")
    ok("prefs load right pad", loaded.monitors.right == "pad")
    ok("prefs load top mem", loaded.monitors.top == "mem")
    os.remove(saved_path)
  end
  os.remove(tmp)
end
