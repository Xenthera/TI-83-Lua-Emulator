#!/usr/bin/env lua
-- Compile Tiny-C source to Z80 assembly.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]tc_compile%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Compiler = require("lang.compiler")

local src = arg[1] or (ROOT .. "/examples/hello.tc")
local out = arg[2] or (ROOT .. "/asm/generated/hello.asm")

local path, err = Compiler.compile_to_file(src, out, { root = ROOT })
if not path then
  io.stderr:write("tc_compile error: " .. tostring(err) .. "\n")
  os.exit(1)
end
print("Wrote " .. path)
os.exit(0)
