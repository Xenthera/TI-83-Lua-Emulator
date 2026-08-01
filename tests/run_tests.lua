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
dofile(ROOT .. "/tests/cpus/m68k/test_m68k.lua")(ok)
dofile(ROOT .. "/tests/cpus/riscv/test_rv64i.lua")(ok)
dofile(ROOT .. "/tests/cpus/sm83/test_sm83.lua")(ok)

print("== Hardware tests ==")
dofile(ROOT .. "/tests/hw/test_lcd.lua")(ok)
dofile(ROOT .. "/tests/hw/test_keypad.lua")(ok)

print("== MMU tests ==")
dofile(ROOT .. "/tests/cpu/test_mmu.lua")(ok)
dofile(ROOT .. "/tests/cpu/test_flash.lua")(ok)

print("== 68k machine tests ==")
dofile(ROOT .. "/tests/machines/test_m68k_machines.lua")(ok)
dofile(ROOT .. "/tests/machines/test_ti89_bus.lua")(ok)

print("== RV64 bus / boot tests ==")
dofile(ROOT .. "/tests/machines/test_riscv64_bus.lua")(ok)

print("== Game Boy bus tests ==")
dofile(ROOT .. "/tests/machines/test_gameboy_bus.lua")(ok)

print("== TI-84+ machine tests ==")
dofile(ROOT .. "/tests/machines/test_ti84plus.lua")(ok)

print("== Assembler tests ==")
dofile(ROOT .. "/tests/asm/test_assembler.lua")(ok)
dofile(ROOT .. "/tests/asm/test_ixiy.lua")(ok)
dofile(ROOT .. "/tests/asm/test_ed_block.lua")(ok)
dofile(ROOT .. "/tests/asm/test_disasm_roundtrip.lua")(ok)
dofile(ROOT .. "/tests/asm/test_infer_names.lua")(ok)
dofile(ROOT .. "/tests/asm/test_build_splice.lua")(ok)

print("== Tiny-C tests ==")
dofile(ROOT .. "/tests/lang/test_tc.lua")(ok)
dofile(ROOT .. "/tests/lang/test_preprocess.lua")(ok)
dofile(ROOT .. "/tests/lang/test_key_natives.lua")(ok)
dofile(ROOT .. "/tests/lang/test_os_lift.lua")(ok)
dofile(ROOT .. "/tests/lang/test_os_recover.lua")(ok)
dofile(ROOT .. "/tests/lang/test_os_recover_c.lua")(ok)
dofile(ROOT .. "/tests/lang/test_app_multipage.lua")(ok)

print("== Flash App (.8xk) tests ==")
dofile(ROOT .. "/tests/util/test_eightxk.lua")(ok)
dofile(ROOT .. "/tests/util/test_appsign.lua")(ok)

print("== Export / bundle tests ==")
dofile(ROOT .. "/tests/export/test_bundle.lua")(ok)
dofile(ROOT .. "/tests/export/test_bundle_ti89.lua")(ok)
dofile(ROOT .. "/tests/export/test_launcher.lua")(ok)
dofile(ROOT .. "/tests/bridge/test_protocol_machines.lua")(ok)

print(("\n%d passed, %d failed"):format(passed, failed))
if failed == 0 then
  print("\n== Pipeline screen test ==")
  local sep = package.config:sub(1, 1)
  local function join(...)
    return table.concat({ ... }, sep)
  end
  local lua_bin = "lua"
  local vendored = join(ROOT, "tools", "luajit", (sep == "\\") and "luajit.exe" or "luajit")
  local vf = io.open(vendored, "rb")
  if vf then
    vf:close()
    lua_bin = vendored
  else
    local h = io.popen((sep == "\\" and "where luajit 2>nul" or "command -v luajit 2>/dev/null"))
    if h then
      local line = h:read("*l")
      h:close()
      if line and line ~= "" then
        lua_bin = "luajit"
      end
    end
  end
  local script = join(ROOT, "tools", "pipeline_test.lua")
  -- Avoid extra quotes on Windows (LuaJIT os.execute + quoted relative paths
  -- often returns a bogus non-zero status even when the child succeeds).
  local cmd
  if sep == "\\" then
    cmd = lua_bin .. " " .. script
  else
    cmd = string.format("%q %q", lua_bin, script)
  end
  local pipe = os.execute(cmd)
  if not (pipe == true or pipe == 0) then
    print("PIPELINE FAILED (" .. tostring(pipe) .. ") cmd=" .. cmd)
    os.exit(1)
  end
end
os.exit(failed == 0 and 0 or 1)
