#!/usr/bin/env lua
-- Disassemble TI-83+ flash page 0 -> reassemble -> splice into a bootable 512KB ROM.
-- Usage: lua tools/reasm_ti_page0.lua [out.rom]

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]reasm_ti_page0%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Disasm = require("asm.disasm")
local Infer = require("asm.infer_names")
local Assembler = require("asm.assembler")

local PAGE = 0x4000
local FLASH = 512 * 1024
local in_rom = ROOT .. "/rom/ti83plus.rom"
local asm_out = ROOT .. "/rom/ti83plus_p0_dis.asm"
local rom_out = (arg and arg[1]) or (ROOT .. "/rom/ti83plus_reasm.rom")

local f = assert(io.open(in_rom, "rb"))
local data = f:read("*a")
f:close()
assert(#data == FLASH, "expected 512KB ti83plus.rom, got " .. #data)

local page0 = data:sub(1, PAGE)
local seeds = { 0x0000, 0x0008, 0x0010, 0x0018, 0x0020, 0x0028, 0x0030, 0x0038 }

local symbols = Infer.infer_bytes(page0, { size = PAGE, seeds = seeds })
local src = Disasm.disassemble_bytes(page0, {
  size = PAGE,
  seeds = seeds,
  symbols = symbols,
})

local af = assert(io.open(asm_out, "w"))
af:write(src)
af:close()
print("wrote " .. asm_out)

local ok, result = pcall(Assembler.assemble_file, "rom/ti83plus_p0_dis.asm", {
  root = ROOT,
  max_size = PAGE,
})
if not ok then
  io.stderr:write("assemble failed: " .. tostring(result) .. "\n")
  os.exit(1)
end

local mism = 0
local first = nil
for i = 0, PAGE - 1 do
  local want = page0:byte(i + 1) or 0
  local got = result.bytes[i] or 0
  if want ~= got then
    mism = mism + 1
    if not first then first = string.format("0x%04X want=%02X got=%02X", i, want, got) end
  end
end
print(string.format("page0 reassemble: size=%d mismatches=%d%s",
  result.size, mism, first and (" first " .. first) or " (byte-identical)"))

if mism > 0 then
  io.stderr:write("refusing to splice non-identical page 0\n")
  os.exit(1)
end

-- Splice identical page 0 + original remainder
local out = assert(io.open(rom_out, "wb"))
local block = {}
for i = 0, PAGE - 1 do
  block[#block + 1] = string.char(result.bytes[i] or 0)
end
out:write(table.concat(block))
out:write(data:sub(PAGE + 1))
out:close()
print("wrote " .. rom_out .. " (" .. FLASH .. " bytes)")
print("boot with: luajit tools/boot_os_smoke.lua  (point it at this ROM, or replace ti83plus.rom)")
