#!/usr/bin/env lua
-- Copy the CC emulator launcher to dist/emu.lua (no bundle needed).

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]export_computercraft_launcher%.lua$") or "."
local src = ROOT .. "/frontends/computercraft/launcher.lua"
local out = "dist/emu.lua"

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

if not exists(src) then
  io.stderr:write("missing " .. src .. "\n")
  os.exit(1)
end

local dir = out:match("^(.*)[/\\][^/\\]+$")
if dir and dir ~= "" then
  if package.config:sub(1, 1) == "\\" then
    os.execute(string.format('mkdir "%s" 2>nul', dir:gsub("/", "\\")))
  else
    os.execute(string.format('mkdir - p "%s" 2>/dev/null', dir))
  end
end

local inf = assert(io.open(src, "rb"))
local data = inf:read("*a")
inf:close()
local ouf = assert(io.open(out, "wb"))
ouf:write(data)
ouf:close()

io.stdout:write("wrote " .. out .. "  (CC launcher)\n")
io.stdout:write("Deploy with frontends/ next to it:\n")
io.stdout:write("  emu.lua\n")
io.stdout:write("  frontends/ti83_cc.lua\n")
io.stdout:write("  frontends/gb_cc.lua\n")
io.stdout:write("  ...\n")
