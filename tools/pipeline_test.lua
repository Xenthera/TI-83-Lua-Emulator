#!/usr/bin/env lua
-- Pipeline: Tiny-C -> asm -> 512KB ROM -> emulate -> verify LCD.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]pipeline_test%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Builder = require("tools.build_pipeline_rom")
local textref = require("asm.textref")
local Machine = require("core.machine")

local function fb_preview(fb, rows)
  for r = 0, (rows or 8) - 1 do
    local line = {}
    for c = 0, 11 do
      line[#line + 1] = string.format("%02X", fb[r * 12 + c] or 0)
    end
    print(string.format("R%02d %s", r, table.concat(line, " ")))
  end
end

print("== pipeline: tc compile + assemble ==")
local out_rom, art, asm_path = Builder.build(ROOT)
print(string.format("ASM %s (%d bytes, main=%04X)",
  asm_path, art.size, art.symbols.main or 0))
print("Wrote " .. out_rom)

print("== pipeline: emulate ==")
local machine = Machine.new()
assert(machine:load_rom_file(out_rom))
machine:reset()
machine:run_cycles(800000)

local ready = machine.mmu:read(0xC001)
local display_on = machine:is_display_on()
local actual = machine:framebuffer()
local expected = textref.expected_text_screen()
local mismatches, first = textref.diff(actual, expected)

print(string.format("PC=%04X ready=%02X display_on=%s mismatches=%d",
  machine:pc(), ready, tostring(display_on), mismatches))
print("-- actual rows 0-7 --")
fb_preview(actual, 8)

if ready ~= 0xA5 then
  print("FAIL: ready magic")
  os.exit(1)
end
if not display_on then
  print("FAIL: display off")
  os.exit(1)
end
if mismatches ~= 0 then
  print(string.format("FAIL: FB mismatch first @ row=%d col=%d got=%02X want=%02X",
    first.row, first.col, first.a, first.e))
  os.exit(1)
end

print("PIPELINE OK: Tiny-C -> assembler -> text renderer -> LCD")
os.exit(0)
