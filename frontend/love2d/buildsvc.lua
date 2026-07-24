-- In-process build: Tiny-C and/or ASM -> 512KB ROM bytes.

local Compiler = require("lang.compiler")
local Assembler = require("asm.assembler")
local font8 = require("asm.font8")

local FLASH = 512 * 1024

local M = {}

local function ascii_map()
  local map = {}
  for i = 0, 255 do map[i + 1] = 0 end
  for i = 1, #font8.CHARSET do
    local ch = font8.CHARSET:sub(i, i)
    map[ch:byte() + 1] = i - 1
    local lower = ch:lower()
    if lower ~= ch then map[lower:byte() + 1] = i - 1 end
  end
  return map
end

local function flash_from_result(result)
  local chunks = {}
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
    chunks[#chunks + 1] = table.concat(t)
  end
  return table.concat(chunks)
end

--- opts: entry filename, files VFS map, root already set by caller
function M.build_tc(root, tc_source, opts)
  opts = opts or {}
  opts.root = opts.root or root
  local entry = opts.entry or "ide.tc"
  local ok, asm_or_err = pcall(Compiler.compile_source, tc_source, entry, opts)
  if not ok then
    return nil, tostring(asm_or_err)
  end
  local asm = asm_or_err
  local asm_path = root .. "/asm/generated/ide.asm"
  local f = assert(io.open(asm_path, "w"))
  f:write(asm)
  f:close()

  local ok2, result = pcall(Assembler.assemble_file, "asm/generated/ide.asm", {
    root = root,
    blobs = { font8 = font8.blob(), ascii_map = ascii_map() },
    max_size = 0x4000,
  })
  if not ok2 then
    return nil, tostring(result), asm
  end
  return flash_from_result(result), nil, asm, result
end

function M.build_asm(root, asm_source)
  local asm_path = root .. "/asm/generated/ide.asm"
  local f = assert(io.open(asm_path, "w"))
  f:write(asm_source)
  f:close()

  local ok, result = pcall(Assembler.assemble_file, "asm/generated/ide.asm", {
    root = root,
    blobs = { font8 = font8.blob(), ascii_map = ascii_map() },
    max_size = 0x4000,
  })
  if not ok then
    return nil, tostring(result)
  end
  return flash_from_result(result), nil, result
end

function M.write_rom(root, bytes)
  local path = root .. "/rom/pipeline.rom"
  local f = assert(io.open(path, "wb"))
  f:write(bytes)
  f:close()
  return path
end

return M
