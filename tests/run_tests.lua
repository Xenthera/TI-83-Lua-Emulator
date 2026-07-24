#!/usr/bin/env luajit
-- Simple test runner (no external deps). Prefer LuaJIT when available.

local ROOT = arg[0]:match("(.+)[/\\]tests[/\\]run_tests%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local passed, failed = 0, 0

local function ok(name, cond, msg)
  if cond then
    passed = passed + 1
    print("  PASS  " .. name)
  else
    failed = failed + 1
    print("  FAIL  " .. name .. (msg and (" - " .. msg) or ""))
  end
end

print("== CPU tests ==")
dofile(ROOT .. "/tests/cpu/test_z80.lua")(ok)

print("== Hardware tests ==")
dofile(ROOT .. "/tests/hw/test_lcd.lua")(ok)
dofile(ROOT .. "/tests/hw/test_keypad.lua")(ok)

print("== MMU tests ==")
dofile(ROOT .. "/tests/cpu/test_mmu.lua")(ok)

print("== Assembler tests ==")
dofile(ROOT .. "/tests/asm/test_assembler.lua")(ok)

print("== Tiny-C tests ==")
dofile(ROOT .. "/tests/lang/test_tc.lua")(ok)
dofile(ROOT .. "/tests/lang/test_preprocess.lua")(ok)
dofile(ROOT .. "/tests/lang/test_key_natives.lua")(ok)

print("== Export / bundle tests ==")
dofile(ROOT .. "/tests/export/test_bundle.lua")(ok)

print(("\n%d passed, %d failed"):format(passed, failed))
if failed == 0 then
  print("\n== Pipeline screen test ==")
  local pipe = os.execute(string.format('luajit "%s/tools/pipeline_test.lua"', ROOT))
  if not (pipe == true or pipe == 0) then
    print("PIPELINE FAILED")
    os.exit(1)
  end
end
os.exit(failed == 0 and 0 or 1)
