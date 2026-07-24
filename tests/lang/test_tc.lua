return function(ok)
  local Compiler = require("lang.compiler")
  local src = [[
void main() {
  byte n;
  n = 1 + 2;
  if (n == 3) {
    poke(0xC001, 0xA5);
  }
  while (1) { halt(); }
}
]]
  local okc, asm = pcall(Compiler.compile_source, src, "test.tc")
  ok("tc compiles", okc, okc and nil or tostring(asm))
  if okc then
    ok("tc emits main", asm:find("main:") ~= nil)
    ok("tc emits poke/halt", asm:find("ld %(hl%),a") ~= nil and asm:find("halt") ~= nil)
  end

  local ret_src = [[
byte twice(byte n) {
  return n + n;
}
word widen(byte n) {
  return n;
}
void main() {
  byte a;
  word w;
  a = twice(7);
  w = widen(3);
  poke(0xC001, a);
  while (1) { halt(); }
}
]]
  local okr, asmr = pcall(Compiler.compile_source, ret_src, "ret.tc", { root = "." })
  ok("typed returns compile", okr, okr and nil or tostring(asmr))
  if okr then
    ok("byte return uses A", asmr:find("twice:") ~= nil and asmr:find("call twice") ~= nil)
    ok("no double ret after return", not asmr:find("ret\n    ret"))
  end

  local bad = "test() { return 1; }\nvoid main() { test(); }\n"
  local okb, errb = pcall(Compiler.compile_source, bad, "bad.tc", { root = "." })
  ok("untyped function rejected", not okb)
  if not okb then
    ok("untyped error mentions return type", tostring(errb):find("return type") ~= nil)
  end
end
