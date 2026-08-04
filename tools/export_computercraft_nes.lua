#!/usr/bin/env lua
-- Build a single-file ComputerCraft export of the NES emulator.
--
-- Prefer (Windows):
--   tools\export_computercraft_nes.cmd
-- Or:
--   tools\luajit\luajit.exe tools/export_computercraft_nes.lua

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]export_computercraft_nes%.lua$") or "."

local out = "dist/nes_cc.lua"
local i = 1
while i <= #arg do
  if arg[i] == "-o" then
    i = i + 1
    out = arg[i]
  end
  i = i + 1
end

local function exists(path)
  local f = io.open(path, "rb")
  if f then f:close() return true end
  return false
end

local dir = out:match("^(.*)[/\\][^/\\]+$")
if dir and dir ~= "" then
  if package.config:sub(1, 1) == "\\" then
    os.execute(string.format('mkdir "%s" 2>nul', dir:gsub("/", "\\")))
  else
    os.execute(string.format('mkdir -p "%s" 2>/dev/null', dir))
  end
end

local entry = "frontends.computercraft.api_nes"
local bundle_path = ROOT .. "/tools/bundle.lua"
if not exists(bundle_path) then
  io.stderr:write("missing " .. bundle_path .. "\n")
  os.exit(1)
end

io.stdout:write("bundling " .. entry .. " -> " .. out .. " ...\n")
io.stdout:flush()

local saved_arg = arg
arg = {
  [-1] = saved_arg[-1],
  [0] = bundle_path,
  [1] = "-o",
  [2] = out,
  [3] = "--root",
  [4] = ROOT,
  [5] = "--entry",
  [6] = entry,
  [7] = entry,
}
local ok, err = pcall(dofile, bundle_path)
arg = saved_arg
if not ok then
  io.stderr:write("bundle failed: " .. tostring(err) .. "\n")
  os.exit(1)
end

io.stdout:write("wrote " .. out .. "  (monolith)\n")
io.stdout:write("\nOn the CC computer you need:\n")
io.stdout:write("  1) nes_cc.lua   (from dist/nes_cc.lua)\n")
io.stdout:write("  2) a .nes cart (e.g. mario.nes)\n")
io.stdout:write("  3) one+ advanced monitors (LCD/PAD/MEM/OFF per monitor)\n")
io.stdout:write("Then run:\n")
io.stdout:write("  nes_cc --help\n")
io.stdout:write("  nes_cc --rom mario.nes\n")
