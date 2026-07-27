return function(ok)
  local Assembler = require("asm.assembler")
  local Disasm = require("asm.disasm")

  local path = "asm/generated/_ixiy_smoke.asm"
  local f = assert(io.open(path, "w"))
  f:write([[
    org 0
    ld iy,0x8000
    bit 2,(iy+0x16)
    ld a,(iy+0x02)
    ld (iy-0x01),a
    push iy
    pop iy
    add iy,bc
    inc (iy+0x10)
    res 0,(iy+0x08)
    set 7,(iy+0x08)
    jp (iy)
]])
  f:close()

  local ok_asm, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 256 })
  os.remove(path)
  ok("ixiy assembles", ok_asm, (not ok_asm) and tostring(r) or nil)
  if not ok_asm then return end

  -- FD 21 00 80
  ok("ld iy,nn", r.bytes[0] == 0xFD and r.bytes[1] == 0x21 and r.bytes[2] == 0x00 and r.bytes[3] == 0x80)
  -- FD CB 16 56  = bit 2,(iy+0x16)
  ok("bit (iy+d)", r.bytes[4] == 0xFD and r.bytes[5] == 0xCB and r.bytes[6] == 0x16 and r.bytes[7] == 0x56)

  local src = Disasm.disassemble_bytes(r.bytes, { size = r.size, seeds = { 0 } })
  ok("disasm has bit iy", src:find("bit 2,%(iy%+0x16%)") ~= nil or src:find("bit 2,%(iy%+") ~= nil)
  ok("disasm has ld iy", src:find("ld iy,") ~= nil)

  local tmp = "asm/generated/_ixiy_round.asm"
  local out = assert(io.open(tmp, "w"))
  out:write(src)
  out:close()
  local ok2, r2 = pcall(Assembler.assemble_file, tmp, { root = ".", max_size = 256 })
  ok("ixiy reassemble", ok2, (not ok2) and tostring(r2) or nil)
  if ok2 then
    local mism = 0
    for i = 0, r.size - 1 do
      if (r.bytes[i] or 0) ~= (r2.bytes[i] or 0) then mism = mism + 1 end
    end
    ok("ixiy round-trip", mism == 0, "mism=" .. mism)
  end
end
