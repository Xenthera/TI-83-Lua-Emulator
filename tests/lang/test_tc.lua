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

  local arr_src = [[
void main() {
  byte a[4];
  byte i;
  byte s;
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  s = 0;
  for (i = 0; i < 4; i = i + 1) {
    s = s + a[i];
  }
  poke(0xC001, s);
  while (1) { halt(); }
}
]]
  local oka, asma = pcall(Compiler.compile_source, arr_src, "arr.tc", { root = "." })
  ok("arrays/for compile", oka, oka and nil or tostring(asma))
  if oka then
    ok("array index store", asma:find("ld %(hl%),a") ~= nil)
    ok("for loop labels", asma:find("for_") ~= nil or asma:find("for:") ~= nil)
  end

  local mod_src = [[
void main() {
  byte r;
  r = 20 % 6;
  poke(0xC001, r);
  r = 20 / 6;
  poke(0xC002, r);
  while (1) { halt(); }
}
]]
  local okm, asmm = pcall(Compiler.compile_source, mod_src, "mod.tc", { root = "." })
  ok("mod/div compile", okm, okm and nil or tostring(asmm))
  if okm then
    ok("emits umod", asmm:find("umod_u16") ~= nil)
    ok("emits udiv", asmm:find("udiv_u16") ~= nil)
    ok("includes arith", asmm:find("arith.asm") ~= nil)
  end

  local brk_src = [[
void main() {
  byte n;
  n = 0;
  while (1) {
    n = n + 1;
    if (n == 3) { break; }
    continue;
  }
  poke(0xC001, n);
  while (1) { halt(); }
}
]]
  local okk, asmk = pcall(Compiler.compile_source, brk_src, "brk.tc", { root = "." })
  ok("break/continue compile", okk, okk and nil or tostring(asmk))

  -- byte + (byte * byte) must preserve the multiply result in HL
  local muladd_src = [[
void main() {
  byte x;
  byte i;
  byte k;
  byte cx;
  x = 10;
  i = 2;
  k = 7;
  cx = x + i * k;
  poke(0xC001, cx);
  while (1) { halt(); }
}
]]
  local okma, asmma = pcall(Compiler.compile_source, muladd_src, "muladd.tc", { root = "." })
  ok("mul-add compiles", okma, okma and nil or tostring(asmma))
  if okma then
    ok("mul-add keeps product", asmma:find("call mul_u16\n    ex de,hl\n    pop af") ~= nil)
  end

  local arr2_src = [[
byte GRID[2][3] = {
  {1, 2, 3},
  {4, 5, 6},
};
void main() {
  byte s;
  byte r;
  byte c;
  s = 0;
  r = 0;
  while (r < 2) {
    c = 0;
    while (c < 3) {
      s = s + GRID[r][c];
      c = c + 1;
    }
    r = r + 1;
  }
  poke(0xC001, s);
  while (1) { halt(); }
}
]]
  local ok2, asm2 = pcall(Compiler.compile_source, arr2_src, "arr2.tc", { root = "." })
  ok("2d array init compiles", ok2, ok2 and nil or tostring(asm2))
  if ok2 then
    ok("2d array in ROM", asm2:find("__tc_g_GRID:") ~= nil)
    ok("2d array has data", asm2:find("0x01, 0x02, 0x03") ~= nil)
  end
end
