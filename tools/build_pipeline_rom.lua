#!/usr/bin/env lua
-- Compile examples/hello.tc -> asm -> rom/pipeline.rom (512KB flash image).

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]build_pipeline_rom%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Compiler = require("lang.compiler")
local Assembler = require("asm.assembler")
local font8 = require("asm.font8")

local FLASH = 512 * 1024
local TC_SRC = "examples/hello.tc"
local GEN_ASM = "asm/generated/hello.asm"

local M = {}

local function build_ascii_map()
  local map = {}
  for i = 0, 255 do
    map[i + 1] = 0
  end
  for i = 1, #font8.CHARSET do
    local ch = font8.CHARSET:sub(i, i)
    map[ch:byte() + 1] = i - 1
    local lower = ch:lower()
    if lower ~= ch then
      map[lower:byte() + 1] = i - 1
    end
  end
  return map
end

function M.build(root)
  root = root or ROOT
  local out_rom = root .. "/rom/pipeline.rom"
  local tc_path = root .. "/" .. TC_SRC
  local asm_path = root .. "/" .. GEN_ASM

  local asm, err = Compiler.compile_to_file(tc_path, asm_path, { root = root })
  if not asm then
    error("tc compile failed: " .. tostring(err))
  end

  local result = Assembler.assemble_file(GEN_ASM, {
    root = root,
    blobs = {
      font8 = font8.blob(),
      ascii_map = build_ascii_map(),
    },
    max_size = 0x4000,
  })

  local f = assert(io.open(out_rom, "wb"))
  local BLOCK = 16384
  for off = 0, FLASH - 1, BLOCK do
    local t = {}
    for i = 0, BLOCK - 1 do
      local idx = off + i
      if idx < result.size then
        t[#t + 1] = string.char(result.bytes[idx] or 0)
      else
        t[#t + 1] = "\0"
      end
    end
    f:write(table.concat(t))
  end
  f:close()
  return out_rom, result, asm_path
end

if arg and arg[0] and tostring(arg[0]):match("build_pipeline_rom") then
  local path, result, asm_path = M.build(ROOT)
  print(string.format("Compiled %s -> %s (%d bytes) -> %s",
    TC_SRC, asm_path, result.size, path))
end

return M
