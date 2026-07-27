return function(ok)
  local Disasm = require("asm.disasm")
  local Assembler = require("asm.assembler")
  local Build = require("tools.build_pipeline_rom")

  local rom_path, built = Build.build(".")
  local size = built.size
  ok("pipeline builds", size > 0, "size=" .. tostring(size))

  local f = assert(io.open(rom_path, "rb"))
  local data = f:read("*a")
  f:close()
  ok("pipeline.rom readable", #data >= size)

  local src, meta = Disasm.disassemble_bytes(data, {
    size = size,
    seeds = { 0x0000, 0x0038 },
    symbols = built.symbols,
  })
  local nins = 0
  for _ in pairs(meta.code_at) do nins = nins + 1 end
  ok("disasm found instructions", nins > 20, "n=" .. tostring(nins))
  ok("recovered main", src:find("main:") ~= nil)
  ok("recovered lcd_init call", src:find("call lcd_init") ~= nil)
  ok("recovered draw_string", src:find("call draw_string") ~= nil)
  ok("recovered font label", src:find("font:") ~= nil)
  ok("recovered string literal", src:find('db "Bobby is cool",0') ~= nil)
  ok("uses ds for zero runs", src:find("ds ") ~= nil)
  ok("LCD_CMD equ", src:find("LCD_CMD:") ~= nil and src:find("out %(LCD_CMD%),a") ~= nil)

  local tmp = "asm/generated/_pipeline_dis.asm"
  local out = assert(io.open(tmp, "w"))
  out:write(src)
  out:close()

  local ok_asm, result = pcall(Assembler.assemble_file, tmp, {
    root = ".",
    max_size = 0x4000,
  })
  ok("reassemble named disasm", ok_asm, ok_asm and nil or tostring(result))
  if not ok_asm then
    return
  end

  local mismatch = nil
  local cmp = math.max(size, result.size)
  for i = 0, cmp - 1 do
    local a = data:byte(i + 1) or 0
    local b = result.bytes[i] or 0
    if a ~= b then
      mismatch = string.format("byte 0x%04X: rom=%02X re=%02X", i, a, b)
      break
    end
  end
  ok("pipeline round-trip byte-identical", mismatch == nil, mismatch)
end
