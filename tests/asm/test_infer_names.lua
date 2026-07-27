return function(ok)
  local Infer = require("asm.infer_names")
  local Assembler = require("asm.assembler")
  local Disasm = require("asm.disasm")

  -- Synthetic: lcd_busy_wait + lcd_write_cmd matching TI-83+ patterns.
  local asm = [[
    org 0x0000
    jp main
    org 0x0038
    reti

    org 0x0100
main:
    call lcd_busy_wait
    call lcd_write_cmd
    call key_scan
    halt

lcd_busy_wait:
    push af
wait_loop:
    in a,(0x02)
    and 0x02
    jr z,wait_loop
    pop af
    ret

lcd_write_cmd:
    push af
cmd_wait:
    in a,(0x02)
    and 0x02
    jr z,cmd_wait
    pop af
    out (0x10),a
    ret

key_scan:
    ld a,0xFE
    out (0x01),a
    in a,(0x01)
    ret
]]

  local path = "asm/generated/_infer_synth.asm"
  local f = assert(io.open(path, "w"))
  f:write(asm)
  f:close()
  local built = Assembler.assemble_file(path, { root = ".", max_size = 0x4000 })
  local bytes = {}
  for i = 0, built.size - 1 do
    bytes[i] = built.bytes[i] or 0
  end

  local syms, meta = Infer.infer_bytes(bytes, {
    size = built.size,
    seeds = { 0x0000, 0x0038, 0x0100 },
  })

  local function addr_of(name)
    return syms[name]
  end

  ok("infer lcd_busy_wait", addr_of("lcd_busy_wait") == built.symbols.lcd_busy_wait,
    string.format("got %s want %s", tostring(addr_of("lcd_busy_wait")),
      tostring(built.symbols.lcd_busy_wait)))
  ok("infer lcd_write_cmd", addr_of("lcd_write_cmd") == built.symbols.lcd_write_cmd,
    string.format("got %s want %s", tostring(addr_of("lcd_write_cmd")),
      tostring(built.symbols.lcd_write_cmd)))
  ok("infer key_scan", addr_of("key_scan") == built.symbols.key_scan,
    string.format("got %s want %s", tostring(addr_of("key_scan")),
      tostring(built.symbols.key_scan)))
  ok("infer rst38_isr", addr_of("rst38_isr") == 0x0038)

  -- Round-trip with inferred names still byte-identical
  local src = Disasm.disassemble_bytes(bytes, {
    size = built.size,
    seeds = { 0x0000, 0x0038 },
    symbols = syms,
  })
  local tmp = "asm/generated/_infer_roundtrip.asm"
  local out = assert(io.open(tmp, "w"))
  out:write(src)
  out:close()
  local ok_asm, result = pcall(Assembler.assemble_file, tmp, { root = ".", max_size = 0x4000 })
  ok("infer reassemble", ok_asm, (not ok_asm) and tostring(result) or nil)
  if ok_asm then
    local mism = nil
    for i = 0, built.size - 1 do
      if (bytes[i] or 0) ~= (result.bytes[i] or 0) then
        mism = string.format("0x%04X", i)
        break
      end
    end
    ok("infer round-trip identical", mism == nil, mism)
  end

  -- Smoke: real TI-83+ page 0
  local romf = io.open("rom/ti83plus.rom", "rb")
  if not romf then
    ok("ti83plus.rom present", false, "missing rom/ti83plus.rom")
    return
  end
  local page = romf:read(0x4000)
  romf:close()
  local ti_syms, ti_meta = Infer.infer_bytes(page, { size = 0x4000 })
  ok("ti83 page0 lcd_busy_wait", ti_syms.lcd_busy_wait ~= nil,
    "addr=" .. tostring(ti_syms.lcd_busy_wait))
  ok("ti83 page0 lcd_write_cmd", ti_syms.lcd_write_cmd ~= nil,
    "addr=" .. tostring(ti_syms.lcd_write_cmd))
  ok("ti83 page0 busy at 0x0AAE", ti_meta.addr_name[0x0AAE] == "lcd_busy_wait",
    tostring(ti_meta.addr_name[0x0AAE]))
  ok("ti83 page0 cmd at 0x0AB7", ti_meta.addr_name[0x0AB7] == "lcd_write_cmd",
    tostring(ti_meta.addr_name[0x0AB7]))
end
