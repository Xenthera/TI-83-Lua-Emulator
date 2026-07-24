return function(ok)
  local Compiler = require("lang.compiler")
  local Tiproj = require("lang.tiproj")
  local Pre = require("lang.preprocess")

  local files = {
    ["main.tc"] = '#include "util.tc"\nvoid main() { util(); while (1) { halt(); } }\n',
    ["util.tc"] = "void util() { poke(0xC001, 0xA5); }\n",
  }
  local expanded = Pre.preprocess(files["main.tc"], "main.tc", { files = files, root = "." })
  ok("include expands util", expanded:find("void util") ~= nil)
  ok("include once", select(2, expanded:gsub("void util", "")) == 1)

  local asm = nil
  local cok, result = pcall(Compiler.compile_source, files["main.tc"], "main.tc", {
    files = files,
    root = ".",
  })
  ok("multi-file compiles", cok, cok and nil or tostring(result))
  if cok then asm = result end
  if asm then
    ok("emits util label", asm:find("util:") ~= nil)
    ok("poke-only skips gfx runtime", asm:find('include "asm/lib/gfx.asm"') == nil)
    ok("poke-only skips font blob", asm:find("blob font8") == nil)
  end

  local empty = "void main() {}\n"
  local oke, asme = pcall(Compiler.compile_source, empty, "empty.tc", { root = "." })
  ok("empty main compiles", oke, oke and nil or tostring(asme))
  if oke then
    ok("empty main has no lcd runtime", asme:find("asm/lib/lcd.asm") == nil)
    ok("empty main has no font", asme:find("blob font8") == nil)
  end

  local pix = [[
void main() {
  lcd_init();
  draw_pixel(10, 20);
  while (1) { halt(); }
}
]]
  local okp, asmp = pcall(Compiler.compile_source, pix, "pix.tc", { root = "." })
  ok("draw_pixel compiles", okp, okp and nil or tostring(asmp))
  if okp then
    ok("calls draw_pixel", asmp:find("call draw_pixel") ~= nil)
    ok("links lcd+gfx for draw_pixel", asmp:find('include "asm/lib/lcd.asm"') ~= nil
      and asmp:find('include "asm/lib/gfx.asm"') ~= nil)
    ok("draw_pixel skips font", asmp:find("blob font8") == nil)
  end

  local doc = Tiproj.open("projects/shapes")
  ok("shapes project opens", doc ~= nil, doc and nil or "missing projects/shapes")
  if doc then
    ok("shapes has disk main.tc", doc.files["main.tc"] ~= nil)
    ok("shapes has disk banner.tc", doc.files["banner.tc"] ~= nil)
    local oks, asms = pcall(Compiler.compile_source, doc.files[doc.entry], doc.entry, {
      root = ".",
      files = doc.files,
    })
    ok("shapes project compiles", oks, oks and nil or tostring(asms))
    ok("shapes banner source present",
      doc.files["banner.tc"]:find("draw_banner") ~= nil)
  end
end
