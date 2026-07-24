return function(ok)
  local Assembler = require("asm.assembler")
  local path = "tests/asm/_tmp_smoke.asm"
  local f = assert(io.open(path, "w"))
  f:write([[
    org 0
    ld a,0x42
    ld hl,0xC000
    ld (hl),a
    halt
]])
  f:close()

  local ok_asm, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 256 })
  os.remove(path)

  ok("assembler runs", ok_asm, ok_asm and nil or tostring(r))
  if not ok_asm then
    ok("assembles ld/halt", false)
    return
  end

  -- 3E 42  21 00 C0  77  76
  ok("assembles ld/halt",
    r.bytes[0] == 0x3E and r.bytes[1] == 0x42
      and r.bytes[2] == 0x21 and r.bytes[5] == 0x77 and r.bytes[6] == 0x76)
  ok("assembler size", r.size == 7)
end
