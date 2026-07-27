return function(ok)
  local Compiler = require("lang.compiler")
  local Assembler = require("asm.assembler")

  local src = [[
extern byte key_scan();

void mmu_set_bankA_tc(byte page) osabi {
  out_port(0x06, page);
}

void lcd_busy_wait_tc() osabi saveaf {
  while ((in_port(0x02) & 0x02) == 0) {
  }
}

void lcd_write_cmd_tc() osabi {
  byte cmd;
  cmd = 0x02;
  while ((in_port(0x02) & 0x02) == 0) {
  }
  out_port(0x10, cmd);
}

void main() {
  byte k;
  k = key_scan();
  while (1) { halt(); }
}
]]
  local okc, asm = pcall(Compiler.compile_source, src, "oslift.tc", { root = "." })
  ok("os lift compiles", okc, okc and nil or tostring(asm))
  if not okc then return end

  ok("emits in_port", asm:find("in a,%(0x02%)") ~= nil)
  ok("emits out_port", asm:find("out %(0x06%),a") ~= nil)
  ok("osabi shadows in C", asm:find("ld c,a") ~= nil)
  ok("saveaf pushes AF", asm:find("lcd_busy_wait_tc:\n    push af") ~= nil
    or asm:find("lcd_busy_wait_tc:\r\n    push af") ~= nil
    or asm:match("lcd_busy_wait_tc:%s*\n%s*push af") ~= nil)
  ok("write_cmd has no saveaf", asm:find("lcd_write_cmd_tc:\n    push bc") ~= nil
    or asm:match("lcd_write_cmd_tc:%s*\n%s*push bc") ~= nil)
  ok("extern call", asm:find("call key_scan") ~= nil)
  -- osabi helpers must not spill their byte arg to Tiny-C RAM slots
  local mmu = asm:match("mmu_set_bankA_tc:.-ret")
  ok("no RAM spill for osabi param", mmu and not mmu:find("0xC0"))

  local no_crt = [[
void mmu_set_bankA_tc(byte page) osabi {
  out_port(0x06, page);
}
]]
  local ok2, asm2 = pcall(Compiler.compile_source, no_crt, "nocrt.tc", {
    root = ".", no_crt = true, code_org = 0x3E00,
  })
  ok("no_crt compiles without main", ok2, ok2 and nil or tostring(asm2))
  if ok2 then
    ok("no_crt org", asm2:find("org 0x3E00") ~= nil)
    ok("no_crt skips jp main", not asm2:find("jp main"))
  end

  -- Full project lift.tc
  local lift = assert(io.open("projects/os83/lift.tc")):read("*a")
  local ok3, asm3 = pcall(Compiler.compile_source, lift, "lift.tc", {
    root = "projects/os83", no_crt = true, code_org = 0x3FAB,
  })
  ok("projects/os83/lift.tc compiles", ok3, ok3 and nil or tostring(asm3))
  if ok3 then
    local path = "asm/generated/_test_os_lift.asm"
    local f = assert(io.open(path, "w"))
    f:write(asm3)
    f:close()
    local oka, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 0x4000 })
    ok("lift assembles", oka, oka and nil or tostring(r))
    os.remove(path)
  end

  -- key_scan in-place at 0x035A (must fit original 0x25-byte slot)
  local key = assert(io.open("projects/os83/key.tc")):read("*a")
  local ok4, asm4 = pcall(Compiler.compile_source, key, "key.tc", {
    root = "projects/os83", no_crt = true, code_org = 0x035A,
  })
  ok("projects/os83/key.tc compiles", ok4, ok4 and nil or tostring(asm4))
  if ok4 then
    ok("key_scan peep in_port mask", asm4:find("and 0x80") ~= nil)
    local path = "asm/generated/_test_os_key.asm"
    local f = assert(io.open(path, "w"))
    f:write(asm4)
    f:close()
    local oka, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 0x4000 })
    ok("key assembles", oka, oka and nil or tostring(r))
    if oka then
      local size = r.size - 0x035A
      ok("key_scan fits inplace (<=0x25)", size > 0 and size <= 0x25, "size=" .. tostring(size))
    end
    os.remove(path)
  end
end
