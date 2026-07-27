return function(ok)
  local Assembler = require("asm.assembler")
  local Disasm = require("asm.disasm")

  local path = "asm/generated/_ed_smoke.asm"
  local f = assert(io.open(path, "w"))
  f:write([[
    org 0
    daa
    rld
    rrd
    ldi
    ldir
    ldd
    lddr
    cpir
    ld (0x83E8),sp
    ld sp,(0x83E8)
    sll b
    sbc hl,bc
    sbc hl,de
    adc hl,de
    in a,(c)
    out (c),a
    ld a,r
    halt
]])
  f:close()

  local ok_asm, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 256 })
  os.remove(path)
  ok("ed/daa assembles", ok_asm, (not ok_asm) and tostring(r) or nil)
  if not ok_asm then return end

  ok("daa", r.bytes[0] == 0x27)
  ok("rld", r.bytes[1] == 0xED and r.bytes[2] == 0x6F)
  ok("ldir", r.bytes[7] == 0xED and r.bytes[8] == 0xB0)
  ok("ld (nn),sp", r.bytes[15] == 0xED and r.bytes[16] == 0x73)
  ok("ld sp,(nn)", r.bytes[19] == 0xED and r.bytes[20] == 0x7B)
  ok("sll b", r.bytes[23] == 0xCB and r.bytes[24] == 0x30)
  ok("sbc hl,bc", r.bytes[25] == 0xED and r.bytes[26] == 0x42)
  ok("sbc hl,de", r.bytes[27] == 0xED and r.bytes[28] == 0x52)
  ok("in a,(c)", r.bytes[31] == 0xED and r.bytes[32] == 0x78)

  local src = Disasm.disassemble_bytes(r.bytes, { size = r.size, seeds = { 0 } })
  ok("disasm daa", src:find("daa") ~= nil)
  ok("disasm ldir", src:find("ldir") ~= nil)
  ok("disasm ld sp", src:find("ld sp,%(") ~= nil)

  local tmp = "asm/generated/_ed_round.asm"
  local out = assert(io.open(tmp, "w"))
  out:write(src)
  out:close()
  local ok2, r2 = pcall(Assembler.assemble_file, tmp, { root = ".", max_size = 256 })
  ok("ed reassemble", ok2, (not ok2) and tostring(r2) or nil)
  if ok2 then
    local mism = 0
    for i = 0, r.size - 1 do
      if (r.bytes[i] or 0) ~= (r2.bytes[i] or 0) then mism = mism + 1 end
    end
    ok("ed round-trip", mism == 0, "mism=" .. mism)
  end
end
