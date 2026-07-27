#!/usr/bin/env lua
-- Flat disassembly of every 16KB flash page into one ASM listing.
-- Page 0 @ 0x0000; pages >=1 in the 0x4000 bank window. Labels page-prefixed.
-- Banking is flattened for recovery - not for ROM round-trip.
--
-- Usage:
--   lua tools/disasm_all_pages.lua rom/ti83plus.rom -o rom/ti83plus_all_dis.asm
--   lua tools/disasm_all_pages.lua rom/ti83plus.rom --pages 0-3 -o rom/ti83plus_p0-3_dis.asm

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]disasm_all_pages%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Disasm = require("asm.disasm")
local Infer = require("asm.infer_names")
local Flash = require("asm.flash_page")

local PAGE = Flash.PAGE

local function usage()
  io.stderr:write([[
Usage: lua tools/disasm_all_pages.lua <rom.bin> [options]
  -o FILE           output ASM (default: <rom>_all_dis.asm)
  --pages A-B|N,N   page range/list (default: all pages in ROM)
  --no-infer        skip behavior-based naming
  --keep-blank      include 0xFF/empty pages
  --json FILE       also write function index JSON
]])
end

local function parse_pages(spec, max_page)
  local set = {}
  if not spec then
    for p = 0, max_page do set[p] = true end
    return set
  end
  for part in tostring(spec):gmatch("[^,]+") do
    local a, b = part:match("^(%d+)%-(%d+)$")
    if a then
      a, b = tonumber(a), tonumber(b)
      if a > b then a, b = b, a end
      for p = a, b do
        if p >= 0 and p <= max_page then set[p] = true end
      end
    else
      local p = tonumber(part)
      if p and p >= 0 and p <= max_page then set[p] = true end
    end
  end
  return set
end

local in_path, out_path, pages_spec, json_path
local infer_names = true
local keep_blank = false
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
    os.exit(0)
  elseif a == "-o" then
    i = i + 1
    out_path = arg[i]
  elseif a == "--pages" then
    i = i + 1
    pages_spec = arg[i]
  elseif a == "--no-infer" then
    infer_names = false
  elseif a == "--keep-blank" then
    keep_blank = true
  elseif a == "--json" then
    i = i + 1
    json_path = arg[i]
  elseif a:sub(1, 1) == "-" then
    io.stderr:write("unknown option: " .. a .. "\n")
    usage()
    os.exit(1)
  elseif not in_path then
    in_path = a
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

local max_page = math.floor((#data - 1) / PAGE)
local page_set = parse_pages(pages_spec, max_page)
local page_list = {}
for p = 0, max_page do
  if page_set[p] then page_list[#page_list + 1] = p end
end

if not out_path then
  out_path = in_path:gsub("%.[^/\\]+$", "") .. "_all_dis.asm"
end

local out = assert(io.open(out_path, "w"))
out:write("; Flat TI flash disassembly - page-prefixed labels.\n")
out:write("; Page0 @ 0x0000; other pages in 0x4000 bank window.\n")
out:write("; Recovery listing only: not meant to reassemble into a banked ROM.\n")
out:write(string.format("; source=%s pages=%d size=%d\n\n", in_path, #page_list, #data))

local index = { source = in_path, pages = {} }
local total_insns = 0
local total_named = 0
local skipped = 0

for _, page in ipairs(page_list) do
  local base = page * PAGE
  local slice = data:sub(base + 1, base + PAGE)
  if #slice < PAGE then
    slice = slice .. string.rep("\0", PAGE - #slice)
  end

  if not keep_blank and Flash.is_blank(slice) then
    skipped = skipped + 1
    io.stdout:write(string.format("page %02d: blank - skipped\n", page))
    index.pages[#index.pages + 1] = {
      page = page,
      flash_base = base,
      blank = true,
      instructions = 0,
      inferred = 0,
      symbols = {},
    }
  else
    local view = Flash.view(slice, page)
    local prefix = string.format("p%02d_", page)
    local symbols = {}
    local inferred_n = 0
    if infer_names then
      local inferred, imeta = Infer.infer(view.read8, {
        size = view.size,
        seeds = view.infer_seeds,
        window_lo = view.window_lo,
        window_hi = view.window_hi,
        symbols = symbols,
      })
      symbols = inferred
      for _ in pairs(imeta.addr_name or {}) do
        inferred_n = inferred_n + 1
      end
    end

    local src, meta = Disasm.disassemble(view.read8, {
      size = view.size,
      seeds = view.seeds,
      symbols = symbols,
      window_lo = view.window_lo,
      window_hi = view.window_hi,
      label_prefix = prefix,
      skip_header = true,
      skip_equ = true,
      skip_org = true,
      header_comment = string.format(
        "; -------- flash page %d (linear 0x%06X..0x%06X) cpu %s..%s prefix=%s infer=%d --------",
        page, base, base + PAGE - 1,
        string.format("0x%04X", view.window_lo),
        string.format("0x%04X", view.window_hi - 1),
        prefix, inferred_n
      ),
    })

    out:write(src)
    if not src:match("\n$") then out:write("\n") end
    out:write("\n")

    local ncode = 0
    for _ in pairs(meta.code_at or {}) do ncode = ncode + 1 end
    total_insns = total_insns + ncode

    local names = {}
    for addr, name in pairs(meta.names or {}) do
      names[#names + 1] = {
        addr = addr,
        name = name,
        flash = base + (addr - view.window_lo),
      }
      total_named = total_named + 1
    end
    table.sort(names, function(a, b) return a.addr < b.addr end)
    index.pages[#index.pages + 1] = {
      page = page,
      flash_base = base,
      window_lo = view.window_lo,
      instructions = ncode,
      inferred = inferred_n,
      symbols = names,
    }

    io.stdout:write(string.format(
      "page %02d: %d insns, %d named (cpu 0x%04X)\n",
      page, ncode, inferred_n, view.window_lo
    ))
  end
end

out:close()
io.stdout:write(string.format(
  "Wrote %s (%d pages, %d skipped blank, %d instructions, %d named symbols)\n",
  out_path, #page_list, skipped, total_insns, total_named
))

if json_path then
  local function enc_str(s)
    return '"' .. tostring(s):gsub('\\', '\\\\'):gsub('"', '\\"') .. '"'
  end
  local parts = { "{\n" }
  parts[#parts + 1] = "  \"source\": " .. enc_str(index.source) .. ",\n"
  parts[#parts + 1] = "  \"pages\": [\n"
  for pi, pg in ipairs(index.pages) do
    parts[#parts + 1] = "    {\n"
    parts[#parts + 1] = string.format("      \"page\": %d,\n", pg.page)
    parts[#parts + 1] = string.format("      \"flash_base\": %d,\n", pg.flash_base)
    if pg.window_lo then
      parts[#parts + 1] = string.format("      \"window_lo\": %d,\n", pg.window_lo)
    end
    parts[#parts + 1] = string.format("      \"blank\": %s,\n", pg.blank and "true" or "false")
    parts[#parts + 1] = string.format("      \"instructions\": %d,\n", pg.instructions)
    parts[#parts + 1] = string.format("      \"inferred\": %d,\n", pg.inferred)
    parts[#parts + 1] = "      \"symbols\": [\n"
    for si, s in ipairs(pg.symbols) do
      parts[#parts + 1] = string.format(
        "        {\"addr\": %d, \"flash\": %d, \"name\": %s}%s\n",
        s.addr, s.flash, enc_str(s.name), si < #pg.symbols and "," or ""
      )
    end
    parts[#parts + 1] = "      ]\n"
    parts[#parts + 1] = "    }" .. (pi < #index.pages and "," or "") .. "\n"
  end
  parts[#parts + 1] = "  ]\n}\n"
  local jf = assert(io.open(json_path, "w"))
  jf:write(table.concat(parts))
  jf:close()
  io.stdout:write("Wrote " .. json_path .. "\n")
end
