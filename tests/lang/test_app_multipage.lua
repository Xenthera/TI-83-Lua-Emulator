return function(ok)
  local AppLink = require("lang.app_link")
  local BuildSvc = require("frontend.love2d.buildsvc")
  local Eightxk = require("core.util.eightxk")
  local Tiproj = require("lang.tiproj")

  local src = [[
byte fat_work(byte n) {
  byte a;
  byte b;
  a = n;
  b = 0;
  while (b < 20) {
    a = a + b + 1;
    b = b + 1;
  }
  return a;
}
void main() {
  byte r;
  os_clr_lcd();
  os_home_up();
  r = fat_work(3);
  os_put_str("MP");
  os_get_key();
  os_exit();
}
]]

  local okc, err = pcall(function()
    local asm, meta = AppLink.compile_app_source(src, "mp.tc", {
      root = ".",
      app_name = "MPAGE",
      force_pages = 2,
    })
    ok("multipage asm", type(asm) == "string" and #asm > 0)
    ok("multipage n_pages 2", meta and meta.n_pages == 2)
    ok("multipage far call", asm:find("__far_call") ~= nil)
    ok("multipage page dir", asm:find("page 1") ~= nil)
    ok("multipage save base", asm:find("__app_save_base") ~= nil)
    ok("multipage header count", asm:find("0x81, 0x02") ~= nil or asm:find("0x81, 0x2") ~= nil)
  end)
  ok("multipage link ok", okc, okc and nil or tostring(err))

  local xk, xerr = BuildSvc.build_tc_app(".", src, {
    app_name = "MPAGE",
    force_pages = 2,
    entry = "mp.tc",
    sign = false,
  })
  ok("multipage build_tc_app", xk ~= nil, tostring(xerr))
  if xk then
    ok("multipage 8xk TIFL", xk:sub(1, 8) == "**TIFL**")
    local rom = string.rep("\255", Eightxk.FLASH_SIZE)
    rom = "\195" .. rom:sub(2)
    local out, meta = Eightxk.inject(rom, xk)
    ok("multipage inject", out ~= nil, tostring(meta))
    ok("multipage inject 2 pages", meta and meta.pages == 2)
  end

  -- tiproj force_pages round-trip
  local doc = Tiproj.open("projects/multipage_smoke/project.tiproj")
  Tiproj.reload_from_dir(doc)
  local opts = Tiproj.compile_opts(doc, ".")
  ok("tiproj force_pages", opts.force_pages == 2)
  opts.sign = false -- packing only; signing covered by test_appsign
  local body = doc.files[doc.entry]
  local xk2, e2, _, _, info = BuildSvc.build_tc( ".", body, opts)
  ok("tiproj multipage build", xk2 ~= nil, tostring(e2))
  ok("tiproj multipage info pages", info and info.n_pages == 2)
end
