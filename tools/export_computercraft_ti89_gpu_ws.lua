#!/usr/bin/env lua
-- Build thin WebSocket CC client: TI-89 Tom's GPU face (no in-CC emu).

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]export_computercraft_ti89_gpu_ws%.lua$") or "."

local out = "dist/ti89_gpu_cc_ws.lua"
local i = 1
while i <= #arg do
  if arg[i] == "-o" then i = i + 1; out = arg[i] end
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

local entry = "frontends.computercraft.api_ti89_gpu_ws"
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
io.stdout:write("PC host:  bridge\\run.cmd --machine ti89 --rom rom\\ti89.rom --port 8765\n")
io.stdout:write("CC:       ti89_gpu_cc_ws --url ws://127.0.0.1:8765\n")
