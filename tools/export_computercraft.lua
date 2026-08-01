#!/usr/bin/env lua
-- Build a single-file ComputerCraft export of the emulator + CC frontend.
--
--   lua tools/export_computercraft.lua
--
-- Deploy:
--   cp dist/test.lua .../computer/0/test.lua
-- Plus ti83plus.rom and advanced monitors. Run:  test
-- (CC resolves `test` -> test.lua; do not keep a bare `test` file.)

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
  package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path
  require("framework.path").ensure_dir(dir)
end

local cmd = string.format(
  'lua "%s/tools/bundle.lua" -o "%s" --root "%s" --entry frontends.computercraft.api '
    .. "frontends.computercraft.api",
  ROOT, out, ROOT
)
local ok = os.execute(cmd)
if not (ok == true or ok == 0) then
  io.stderr:write("bundle failed\n")
  os.exit(1)
end

-- Deploy name: test.lua (shell `test` finds it; avoid a separate bare `test`).
local test_path = dir and (dir .. "/test.lua") or "test.lua"
do
  local src = assert(io.open(out, "rb"))
  local bytes = src:read("*a")
  src:close()
  local dst = assert(io.open(test_path, "wb"))
  dst:write(bytes)
  dst:close()
end

io.stdout:write("wrote " .. out .. "  (monolith)\n")
io.stdout:write("wrote " .. test_path .. "  (copy this to the CC computer)\n")
io.stdout:write("\nOn the CC computer you need:\n")
io.stdout:write("  1) test.lua   (from dist/test.lua)\n")
io.stdout:write("  2) ti83plus.rom\n")
io.stdout:write("  3) one+ advanced monitors (LCD/PAD/MEM/OFF per monitor)\n")
io.stdout:write("  4) optional .8xk / .8xp files\n")
io.stdout:write("Then run:\n")
io.stdout:write("  test --help\n")
io.stdout:write("  test --loadapp MyApp.8xk\n")
io.stdout:write("  test   # control panel: click .8xp/.8xk to load\n")
