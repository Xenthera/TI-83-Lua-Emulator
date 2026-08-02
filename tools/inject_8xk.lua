#!/usr/bin/env lua
-- Install TI-83+ Flash Apps (.8xk) into a 512KB ROM archive (offline TI-Link).
--
--   lua tools/inject_8xk.lua rom/ti83plus.rom app.8xk [-o rom/ti83plus_apps.rom]
--   lua tools/inject_8xk.lua rom/ti83plus.rom a.8xk b.8xk - o out.rom

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]inject_8xk%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Eightxk = require("machines.ti83plus.util.eightxk")

local function usage()
  io.stderr:write([[
Usage: lua tools/inject_8xk.lua <rom.bin> <app.8xk> [app2.8xk ...] [-o out.rom]
]])
  os.exit(1)
end

local rom_path, out_path
local apps = {}
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
  elseif a == "-o" then
    i = i + 1
    out_path = arg[i]
  elseif a:sub(1, 1) == "-" then
    io.stderr:write("unknown option: " .. a .. "\n")
    usage()
  elseif not rom_path then
    rom_path = a
  else
    apps[#apps + 1] = a
  end
  i = i + 1
end

if not rom_path or #apps == 0 then
  usage()
end
out_path = out_path or (rom_path:gsub("%.rom$", "") .. "_apps.rom")

local function read_bin(path)
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local d = f:read("*a")
  f:close()
  return d
end

local rom, err = read_bin(rom_path)
if not rom then
  io.stderr:write("cannot read ROM: " .. tostring(err) .. "\n")
  os.exit(1)
end

local app_bytes = {}
for _, path in ipairs(apps) do
  local b, e = read_bin(path)
  if not b then
    io.stderr:write("cannot read app: " .. path .. ": " .. tostring(e) .. "\n")
    os.exit(1)
  end
  app_bytes[#app_bytes + 1] = b
end

local out, metas = Eightxk.inject_many(rom, app_bytes)
if not out then
  io.stderr:write("inject failed: " .. tostring(metas) .. "\n")
  os.exit(1)
end

local f, ferr = io.open(out_path, "wb")
if not f then
  io.stderr:write("cannot write " .. out_path .. ": " .. tostring(ferr) .. "\n")
  os.exit(1)
end
f:write(out)
f:close()

for i, meta in ipairs(metas) do
  local pages = {}
  for _, p in ipairs(meta.placed or {}) do
    pages[#pages + 1] = string.format("%02X", p.physical)
  end
  io.stdout:write(string.format(
    "installed %s (%d page(s) @ %s)\n",
    meta.name or apps[i],
    meta.pages or 0,
    table.concat(pages, ",")
  ))
end
io.stdout:write("wrote " .. out_path .. "\n")
