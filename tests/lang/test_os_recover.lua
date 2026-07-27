return function(ok)
  local Recover = require("lang.lift.recover")
  local Flash = require("asm.flash_page")
  local Disasm = require("asm.disasm")

  local f = assert(io.open("rom/ti83plus.rom", "rb"))
  local rom = f:read("*a")
  f:close()
  local page0 = rom:sub(1, 0x4000)
  local page1 = rom:sub(0x4001, 0x8000)

  local tc, meta = Recover.page_to_tc(page0, {
    page = 0,
    max_fns = 80,
    curated = true,
  })
  ok("recover page0 emits functions", meta.functions and meta.functions > 10)
  ok("recover page0 window 0", meta.window_lo == 0)
  ok("recover names key_scan", tc:find("void p00_key_scan()") ~= nil)
  ok("recover names lcd_busy_wait", tc:find("void p00_lcd_busy_wait()") ~= nil)
  ok("curated key_scan delegates", tc:find("a = key_scan%(a%)") ~= nil
    or tc:find("CURATED") ~= nil)
  ok("curated count", meta.curated and meta.curated >= 1)

  local tc_raw = Recover.page_to_tc(page0, {
    page = 0,
    max_fns = 80,
    curated = false,
  })
  ok("raw key_scan uses hw_in", tc_raw:find("hw_in%(PORT_STATUS%)") ~= nil
    or tc_raw:find("hw_in%(PORT_KEYPAD%)") ~= nil)
  ok("raw key_scan shared tail", tc_raw:find("p00_L_036F%(%);") ~= nil
    or tc_raw:find("p00_L_036F") ~= nil)

  local hw = Recover.hw_prelude()
  ok("hw prelude declares bcall", hw:find("os_bcall") ~= nil)
  ok("hw prelude declares mmu", hw:find("mmu_set_bank_a") ~= nil)

  ok("page1 not blank", not Flash.is_blank(page1))
  local banked = Flash.scan_banked_targets(rom)
  ok("scan banked finds page1 targets", banked[1] and #banked[1] > 10)
  local has_6048 = false
  for _, a in ipairs(banked[1] or {}) do
    if a == 0x6048 then has_6048 = true break end
  end
  ok("scan banked includes 6048@01", has_6048)
  local view1 = Flash.view(page1, 1, { extra_seeds = banked[1] })
  ok("page1 window 0x4000", view1.window_lo == 0x4000)
  local seeded_6048 = false
  for _, a in ipairs(view1.infer_seeds) do
    if a == 0x6048 then seeded_6048 = true break end
  end
  ok("page1 seeds include trampoline 6048", seeded_6048)
  local _, meta1d = Disasm.disassemble(view1.read8, {
    size = view1.size,
    seeds = view1.seeds,
    window_lo = view1.window_lo,
    window_hi = view1.window_hi,
    skip_equ = true,
  })
  local n1 = 0
  for _ in pairs(meta1d.code_at or {}) do n1 = n1 + 1 end
  ok("page1 bank-window finds code", n1 > 100, "insns=" .. tostring(n1))

  local cross = { [0x035A] = "p00_key_scan" }
  local tc1, m1 = Recover.page_to_tc(page1, {
    page = 1,
    max_fns = 40,
    cross = cross,
  })
  ok("recover page1 window 0x4000", m1.window_lo == 0x4000)
  ok("recover page1 has 0x4xxx labels", tc1:find("p01_L_4") ~= nil
    or tc1:find("void p01_") ~= nil)

  -- bcall emit smoke on synthetic rst 28
  local fake = string.char(0xEF, 0x34, 0x12, 0xC9) -- rst 28; dw 0x1234; ret
  fake = fake .. string.rep("\0", 0x4000 - #fake)
  local tcb = select(1, Recover.page_to_tc(fake, {
    page = 0,
    infer = false,
    curated = false,
  }))
  ok("emits os_bcall", tcb:find("os_bcall%(0x1234%)") ~= nil)
end
