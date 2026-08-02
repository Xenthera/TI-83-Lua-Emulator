#!/usr/bin/env lua
local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]export_computercraft_gameboy_ws%.lua$") or "."
local out = "dist/gb_cc_ws.lua"
local i = 1
while i <= #arg do
  if arg[i] == "-o" then i = i + 1; out = arg[i] end
  i = i + 1
end
local dir = out:match("^(.*)[/\\][^/\\]+$")
if dir and dir ~= "" then
  if package.config:sub(1, 1) == "\\" then
    os.execute(string.format('mkdir "%s" 2>nul', dir:gsub("/", "\\")))
  else
    os.execute(string.format('mkdir - p "%s" 2>/dev/null', dir))
  end
end
local entry = "frontends.computercraft.api_gameboy_ws"
local bundle_path = ROOT .. "/tools/bundle.lua"
io.stdout:write("bundling " .. entry .. " -> " .. out .. " ...\n")
local saved_arg = arg
arg = { [-1] = saved_arg[-1], [0] = bundle_path, [1] = "-o", [2] = out,
  [3] = "--root", [4] = ROOT, [5] = "--entry", [6] = entry, [7] = entry }
local ok, err = pcall(dofile, bundle_path)
arg = saved_arg
if not ok then
  io.stderr:write("bundle failed: " .. tostring(err) .. "\n")
  os.exit(1)
end
io.stdout:write("wrote " .. out .. "\n")
