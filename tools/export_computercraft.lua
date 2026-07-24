#!/usr/bin/env lua
-- Build a single-file ComputerCraft export of the emulator + CC frontend.
--
--   lua tools/export_computercraft.lua
--
-- Copy to a CC computer:
--   ti83_cc.lua   (or rename to `test` and run: test)
--   pipeline.rom or ti83plus.rom  (512KB)
-- Two advanced monitors attached.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]export_computercraft%.lua$") or "."

local out = "dist/ti83_cc.lua"
local i = 1
while i <= #arg do
  if arg[i] == "-o" then
    i = i + 1
    out = arg[i]
  end
  i = i + 1
end

local dir = out:match("^(.*)[/\\][^/\\]+$")
if dir and dir ~= "" then
  os.execute(string.format('mkdir -p "%s"', dir))
end

local cmd = string.format(
  'lua "%s/tools/bundle.lua" -o "%s" --root "%s" --entry frontend.computercraft.api '
    .. "frontend.computercraft.api",
  ROOT, out, ROOT
)
local ok = os.execute(cmd)
if not (ok == true or ok == 0) then
  io.stderr:write("bundle failed\n")
  os.exit(1)
end

-- Tiny launcher you can copy as `test` on the computer.
local test_path = dir and (dir .. "/test.lua") or "test.lua"
local f = assert(io.open(test_path, "w"))
f:write([[-- Copy this file to your ComputerCraft computer as `test`.
-- Also copy ti83_cc.lua and a 512KB ROM (e.g. pipeline.rom).
-- Attach two advanced monitors, then run:  test

print("test.lua: loading ti83_cc.lua ...")

if not fs.exists("ti83_cc.lua") then
  print("ERROR: ti83_cc.lua not found in this folder.")
  print("Copy dist/ti83_cc.lua from the repo onto this computer.")
  return
end

local ok, ti83 = pcall(dofile, "ti83_cc.lua")
if not ok then
  print("ERROR: dofile(ti83_cc.lua) failed:")
  print(tostring(ti83))
  return
end

if type(ti83) ~= "table" then
  print("ERROR: ti83_cc.lua did not return the API table (got " .. type(ti83) .. ")")
  return
end

if type(ti83.run) ~= "function" then
  print("ERROR: API has no .run — wrong/corrupt ti83_cc.lua?")
  print("Keys:")
  for k in pairs(ti83) do
    print("  " .. tostring(k))
  end
  return
end

print("test.lua: starting emulator...")
print("  (need ROM + 2 advanced monitors)")

local args = { ... }
local lcd, pad, rom = args[1], args[2], args[3] or "ti83plus.rom"

if not lcd and peripheral.isPresent("left") and peripheral.getType("left") == "monitor" then
  lcd = "left"
end
if not pad and peripheral.isPresent("right") and peripheral.getType("right") == "monitor" then
  pad = "right"
end

ti83.run({
  lcd = lcd,
  pad = pad,
  rom = rom,
  fps = 30,
})
]])
f:close()
io.stdout:write("wrote " .. test_path .. "  (copy to CC as `test`)\n")
io.stdout:write("wrote " .. out .. "\n")
io.stdout:write("\nOn the CC computer you need:\n")
io.stdout:write("  1) ti83_cc.lua\n")
io.stdout:write("  2) test          (from dist/test.lua)\n")
io.stdout:write("  3) ti83plus.rom or pipeline.rom (512KB)\n")
io.stdout:write("  4) two advanced monitors\n")
io.stdout:write("Then run:  test\n")
