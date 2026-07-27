return function(ok)
  local Recover = require("lang.lift.recover")

  local f = assert(io.open("rom/ti83plus.rom", "rb"))
  local rom = f:read("*a")
  f:close()
  local page0 = rom:sub(1, 0x4000)

  local c, meta = Recover.page_to_c(page0, {
    page = 0,
    max_fns = 80,
    curated = true,
  })

  ok("page_to_c dialect", meta.dialect == "c")
  ok("page_to_c includes ti_cpu.h", c:find('#include "ti_cpu.h"') ~= nil)
  ok("page_to_c includes ti_hw_api.h", c:find('#include "ti_hw_api.h"') ~= nil)
  ok("page_to_c includes ti_mem.h", c:find('#include "ti_mem.h"') ~= nil)
  ok("page_to_c no Tiny-C byte locals", c:find("byte a;") == nil)
  ok("page_to_c emits uint8_t ops or global regs", c:find("uint8_t") ~= nil
    or c:find("a = ") ~= nil)
  ok("page_to_c names key_scan", c:find("void p00_key_scan%(void%)") ~= nil)
  ok("page_to_c curated key_scan", c:find("a = key_scan%(a%)") ~= nil
    or c:find("CURATED") ~= nil)
  ok("page_to_c uses mem or push helpers", c:find("mem_read8") ~= nil
    or c:find("cpu_push") ~= nil
    or c:find("set_hl") ~= nil)

  local raw = Recover.page_to_c(page0, {
    page = 0,
    max_fns = 80,
    curated = false,
  })
  ok("raw C key_scan uses hw_in", raw:find("hw_in%(PORT_STATUS%)") ~= nil
    or raw:find("hw_in%(PORT_KEYPAD%)") ~= nil)

  -- Boot must continue into banked flash (jp 0x80D5), not a dead comment.
  local boot = Recover.page_to_c(page0, { page = 0, max_fns = 20, curated = false })
  ok("boot emits os_banked_call 80D5", boot:find("os_banked_call%(0x80D5%)") ~= nil)
  ok("ld hl,imm emits set_hl", boot:find("set_hl%(0x") ~= nil
    or raw:find("set_hl%(0x") ~= nil)

  -- OS cold-start seeds must lift; boot page must jp into page0 OS, not "No OS".
  local os_entry = Recover.page_to_c(page0, { page = 0, curated = false })
  ok("page0 lifts OS cold start", os_entry:find("void p00_L_0A6C%(void%)") ~= nil)
  ok("OS cold start emits halt", os_entry:find("p00_L_0A6C.-halt%(%)") ~= nil
    or os_entry:find("halt%(%)") ~= nil)
  ok("OS cold start emits add ix,sp", os_entry:find("cpu_add_ix_sp%(%)") ~= nil)

  local page31 = rom:sub(0x1F * 0x4000 + 1, 0x20 * 0x4000)
  local p31 = Recover.page_to_c(page31, {
    page = 31,
    curated = false,
    cross = { [0x0053] = "p00_L_0053" },
    cross_raw = { [0x0053] = "L_0053" },
  })
  ok("boot page jp z OS entry", p31:find("if %(flag_z%(%)%) %{ p00_L_0053%(%)%; return; %}") ~= nil)
  ok("boot page does not comment-out OS jp",
    p31:find("jp z,0x0053", 1, true) == nil
      or p31:find("p00_L_0053") ~= nil)
end
