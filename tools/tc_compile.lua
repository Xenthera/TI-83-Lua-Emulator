#!/usr/bin/env lua
-- Compile Tiny-C source to Z80 assembly (or a Flash App .8xk with --app).

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]tc_compile%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Compiler = require("lang.compiler")
local BuildSvc = require("frontends.love2d.buildsvc")

local function usage()
  io.stderr:write([[
Usage:
  lua tools/tc_compile.lua [src.tc] [out.asm]
  lua tools/tc_compile.lua --app [src.tc] [out.8xk] [--name APPNAME] [--sign|--no-sign]

Bare-metal (default): Tiny-C -> Z80 assembly.
Flash App:            Tiny-C -> .8xk (APPS menu), via --app.
  --sign     Require RabbitSign (0104) for real calculators (default when available).
  --no-sign  Leave .8xk unsigned (emulator-only).
]])
end

local args = {}
local app = false
local app_name = nil
local sign = nil -- nil = auto
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
    os.exit(0)
  elseif a == "--app" then
    app = true
  elseif a == "--sign" then
    sign = true
  elseif a == "--no-sign" then
    sign = false
  elseif a == "--name" then
    i = i + 1
    app_name = arg[i]
  elseif a:sub(1, 7) == "--name=" then
    app_name = a:sub(8)
  else
    args[#args + 1] = a
  end
  i = i + 1
end

local src = args[1] or (ROOT .. "/examples/hello.tc")
local out = args[2]

if app then
  out = out or (ROOT .. "/dist/app.8xk")
  local f = io.open(src, "r")
  if not f then
    io.stderr:write("tc_compile error: cannot open " .. tostring(src) .. "\n")
    os.exit(1)
  end
  local src_body = f:read("*a")
  f:close()
  local name = app_name
  if not name then
    name = src:match("([^/\\]+)%.tc$") or "TINYAPP"
  end
  local xk, err, _, _, info = BuildSvc.build_tc_app(ROOT, src_body, {
    entry = src,
    app_name = name,
    root = ROOT,
    sign = sign,
  })
  if not xk then
    io.stderr:write("tc_compile --app error: " .. tostring(err) .. "\n")
    os.exit(1)
  end
  local dir = out:match("^(.*)[/\\][^/\\]+$")
  if dir and dir ~= "" then
    package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path
    require("framework.path").ensure_dir(dir)
  end
  local wf = assert(io.open(out, "wb"))
  wf:write(xk)
  wf:close()
  local sig = (info and info.signed) and "signed" or "unsigned"
  local code = (info and info.code_bytes) or (info and info.size) or 0
  local pages = (info and info.n_pages) or 1
  local page_sz = (info and info.page_bytes) or 16384
  print(string.format(
    "Wrote %s (%d bytes file, app %s, %s) - %d bytes code, %d page%s (%d bytes/page)",
    out, #xk, name:upper(), sig, code, pages, pages == 1 and "" or "s", page_sz
  ))
  os.exit(0)
end

out = out or (ROOT .. "/asm/generated/hello.asm")
local path, err = Compiler.compile_to_file(src, out, { root = ROOT })
if not path then
  io.stderr:write("tc_compile error: " .. tostring(err) .. "\n")
  os.exit(1)
end
print("Wrote " .. path)
os.exit(0)
