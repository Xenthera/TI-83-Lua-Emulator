#!/usr/bin/env lua
-- Disassemble a ROM/bin into our assembler dialect.
-- Usage:
--   lua tools/disasm.lua rom/pipeline.rom -o out.asm
--   lua tools/disasm.lua rom/pipeline.rom --symbols-from-asm asm/generated/hello.asm
--   lua tools/disasm.lua rom/ti83plus.rom --page 0 --infer-names -o rom/ti83plus_p0_dis.asm

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]disasm%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Disasm = require("asm.disasm")
local Infer = require("asm.infer_names")
local Assembler = require("asm.assembler")
local font8 = require("asm.font8")

local PAGE = 0x4000

local function usage()
  io.stderr:write([[
Usage: lua tools/disasm.lua <rom.bin> [out.asm] [options]
  -o FILE                 output path (default: <rom>_dis.asm)
  --size N                bytes to cover (default: last non-zero + 1)
  --page N                flash page (16KB); sets size=0x4000 and slices ROM
  --seed ADDR             entry point (repeatable; default 0x0000 + RST vectors)
  --map FILE              symbol map (NAME 0xADDR per line)
  --symbols-from-asm FILE assemble FILE first and use its symbol table
  --infer-names           name functions from port I/O behavior (TI-83+)
]])
end

local function parse_num(s)
  if not s then return nil end
  s = tostring(s)
  if s:match("^0[xX]%x+$") then return tonumber(s)
  elseif s:match("^%$%x+$") then return tonumber(s:sub(2), 16)
  else return tonumber(s) end
end

local function build_ascii_map()
  local map = {}
  for i = 0, 255 do map[i + 1] = 0 end
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

local in_path, out_path
local size_opt
local page_opt
local seeds = {}
local map_path
local sym_asm
local infer_names = false
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
    os.exit(0)
  elseif a == "-o" then
    i = i + 1
    out_path = arg[i]
  elseif a == "--size" then
    i = i + 1
    size_opt = parse_num(arg[i])
  elseif a == "--page" then
    i = i + 1
    page_opt = parse_num(arg[i])
  elseif a == "--seed" then
    i = i + 1
    seeds[#seeds + 1] = parse_num(arg[i])
  elseif a == "--map" then
    i = i + 1
    map_path = arg[i]
  elseif a == "--symbols-from-asm" then
    i = i + 1
    sym_asm = arg[i]
  elseif a == "--infer-names" then
    infer_names = true
  elseif a:sub(1, 1) == "-" then
    io.stderr:write("unknown option: " .. a .. "\n")
    usage()
    os.exit(1)
  elseif not in_path then
    in_path = a
  elseif not out_path then
    out_path = a
  else
    io.stderr:write("unexpected arg: " .. a .. "\n")
    os.exit(1)
  end
  i = i + 1
end

if not in_path then
  usage()
  os.exit(1)
end

local f, err = io.open(in_path, "rb")
if not f then
  io.stderr:write("cannot open " .. in_path .. ": " .. tostring(err) .. "\n")
  os.exit(1)
end
local data = f:read("*a")
f:close()

local page = page_opt
local size = size_opt
local slice = data

if page ~= nil then
  local base = page * PAGE
  if base >= #data then
    io.stderr:write(string.format("page %d past end of ROM (%d bytes)\n", page, #data))
    os.exit(1)
  end
  local endp = math.min(base + PAGE, #data)
  slice = data:sub(base + 1, endp)
  if not size_opt then
    size = #slice
  end
elseif not size then
  local last = 0
  for j = 1, #data do
    if data:byte(j) ~= 0 then last = j end
  end
  size = math.max(last, 1)
  -- Keep a trailing NUL so final C-strings still round-trip / quote.
  if last < #slice and slice:byte(last + 1) == 0 then
    size = last + 1
  elseif last < #data and data:byte(last + 1) == 0 then
    size = last + 1
  end
end

if #seeds == 0 then
  -- Keep default seeds sparse so zero gaps stay as `org` (not nop fills).
  -- --infer-names adds RST vectors itself.
  seeds = { 0x0000, 0x0038 }
end

local symbols = {}
if map_path then
  local m, merr = Disasm.load_map_file(map_path)
  if not m then
    io.stderr:write("map: " .. tostring(merr) .. "\n")
    os.exit(1)
  end
  for k, v in pairs(m) do symbols[k] = v end
end
if sym_asm then
  local ok, result = pcall(Assembler.assemble_file, sym_asm, {
    root = ROOT,
    blobs = { font8 = font8.blob(), ascii_map = build_ascii_map() },
    max_size = 0x4000,
  })
  if not ok then
    io.stderr:write("symbols-from-asm failed: " .. tostring(result) .. "\n")
    os.exit(1)
  end
  for k, v in pairs(result.symbols) do
    if type(k) == "string" and type(v) == "number" then
      symbols[k] = v
    end
  end
  if not size_opt and page == nil then
    size = result.size
  end
end

local inferred_n = 0
local disasm_seeds = seeds
if infer_names then
  -- Include RST vectors for TI-style naming; keep disasm seeds sparse for clean org gaps.
  local infer_seeds = {
    0x0000, 0x0008, 0x0010, 0x0018, 0x0020, 0x0028, 0x0030, 0x0038,
  }
  for _, s in ipairs(seeds) do
    infer_seeds[#infer_seeds + 1] = s
  end
  local inferred, imeta = Infer.infer_bytes(slice, {
    size = size,
    page = 0, -- already sliced
    seeds = infer_seeds,
    symbols = symbols,
  })
  symbols = inferred
  for _ in pairs(imeta.addr_name or {}) do
    inferred_n = inferred_n + 1
  end
  -- Keep listing seeds sparse so zero RST gaps stay as `org`/`ds`, not nop fills.
  disasm_seeds = seeds
end

local src, meta = Disasm.disassemble_bytes(slice, {
  size = size,
  seeds = disasm_seeds,
  symbols = symbols,
})
if not out_path then
  local tag = page ~= nil and ("_p" .. tostring(page)) or ""
  out_path = in_path:gsub("%.[^/\\]+$", "") .. tag .. "_dis.asm"
end

local out = assert(io.open(out_path, "w"))
out:write(src)
out:close()

local ncode = 0
for _ in pairs(meta.code_at) do ncode = ncode + 1 end
local nnames = 0
for _ in pairs(meta.names or {}) do nnames = nnames + 1 end
io.stdout:write(string.format(
  "Wrote %s (%d bytes, %d instructions, %d named symbols%s)\n",
  out_path, size, ncode, nnames,
  infer_names and (", infer=" .. tostring(inferred_n)) or ""
))
