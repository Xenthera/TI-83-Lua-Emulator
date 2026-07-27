#!/usr/bin/env lua
-- Lift flat flash pages from a TI ROM into Tiny-C recovery sources.
-- Does NOT target reassembly - portable / rename / stub HW.
--
-- Usage:
--   lua tools/asm_to_tc.lua rom/ti83plus.rom -o projects/os83_port
--   lua tools/asm_to_tc.lua rom/ti83plus.rom --pages 0 -o projects/os83_port

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]asm_to_tc%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Recover = require("lang.lift.recover")
local Flash = require("asm.flash_page")

local PAGE = Flash.PAGE

local function usage()
  io.stderr:write([[
Usage: lua tools/asm_to_tc.lua <rom.bin> [options]
  -o DIR            output project dir (default: projects/os83_port)
  --pages A-B|N,N   pages to lift (default: all non-blank)
  --max-fns N       cap functions per page (smoke / iterate)
  --no-infer        skip behavior-based names
  --keep-blank      include empty 0xFF pages
  --no-curated      do not collapse known leaves to clean/*
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

local function ensure_dir(path)
  os.execute(string.format('mkdir -p "%s"', path:gsub('"', '\\"')))
end

local function slice_page(data, page)
  local base = page * PAGE
  local slice = data:sub(base + 1, math.min(base + PAGE, #data))
  if #slice < PAGE then
    slice = slice .. string.rep("\0", PAGE - #slice)
  end
  return slice
end

local in_path, out_dir, pages_spec
local max_fns = nil
local infer = true
local keep_blank = false
local curated = true
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
    os.exit(0)
  elseif a == "-o" then
    i = i + 1
    out_dir = arg[i]
  elseif a == "--pages" then
    i = i + 1
    pages_spec = arg[i]
  elseif a == "--max-fns" then
    i = i + 1
    max_fns = tonumber(arg[i])
  elseif a == "--no-infer" then
    infer = false
  elseif a == "--keep-blank" then
    keep_blank = true
  elseif a == "--no-curated" then
    curated = false
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

out_dir = out_dir or (ROOT .. "/projects/os83_port")

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

ensure_dir(out_dir)
ensure_dir(out_dir .. "/gen")
ensure_dir(out_dir .. "/clean")

local hw_path = out_dir .. "/hw.tc"
local hf = assert(io.open(hw_path, "w"))
hf:write(Recover.hw_prelude())
hf:close()
io.stdout:write("Wrote " .. hw_path .. "\n")

-- Pass 1: recover page0 to build cross-page symbol map
local cross, cross_raw = {}, {}
if page_set[0] then
  local s0 = slice_page(data, 0)
  if not Flash.is_blank(s0) then
    local _, meta0 = Recover.page_to_tc(s0, {
      page = 0,
      infer = infer,
      max_fns = max_fns,
      curated = false, -- need by_addr from full mechanical pass
    })
    for addr, name in pairs(meta0.by_addr or {}) do
      cross_raw[addr] = name
      cross[addr] = "p00_" .. name
    end
    io.stdout:write(string.format(
      "cross-map: %d page0 symbols\n",
      (function()
        local n = 0
        for _ in pairs(cross) do n = n + 1 end
        return n
      end)()
    ))
  end
end

local main_lines = {
  "// Auto-generated TI-OS recovery project (not a bootable ROM).",
  "// Prefer clean/* APIs; gen/* is mechanical Z80 lift for the rest.",
  "",
  '#include "hw.tc"',
  '#include "clean/stubs.tc"',
  '#include "clean/mmu.tc"',
  '#include "clean/lcd.tc"',
  '#include "clean/key.tc"',
  "",
}

local total_fns = 0
local total_curated = 0
local skipped = 0
local included = {}

for _, page in ipairs(page_list) do
  local slice = slice_page(data, page)
  if not keep_blank and Flash.is_blank(slice) then
    skipped = skipped + 1
    io.stdout:write(string.format("page %02d: blank - skipped\n", page))
  else
    local tc, meta = Recover.page_to_tc(slice, {
      page = page,
      infer = infer,
      max_fns = max_fns,
      curated = curated,
      cross = cross,
      cross_raw = cross_raw,
    })
    local rel = string.format("gen/page%02d.tc", page)
    local path = out_dir .. "/" .. rel
    local pf = assert(io.open(path, "w"))
    pf:write(tc)
    pf:close()
    total_fns = total_fns + (meta.functions or 0)
    total_curated = total_curated + (meta.curated or 0)
    included[#included + 1] = rel
    io.stdout:write(string.format(
      "page %02d -> %s (%d fn, %d curated, cpu 0x%04X)\n",
      page, rel, meta.functions or 0, meta.curated or 0, meta.window_lo or 0
    ))
  end
end

for _, rel in ipairs(included) do
  main_lines[#main_lines + 1] = string.format('#include "%s"', rel)
end

main_lines[#main_lines + 1] = ""
main_lines[#main_lines + 1] = "void main() {"
main_lines[#main_lines + 1] = "  hw_init_ports();"
main_lines[#main_lines + 1] = "  /* Prefer clean APIs: key_scan / lcd_* / mmu_set_bank_* */"
main_lines[#main_lines + 1] = "  /* Or enter mechanical boot: p00_rst00_boot(); */"
main_lines[#main_lines + 1] = "  while (1) {"
main_lines[#main_lines + 1] = "    halt();"
main_lines[#main_lines + 1] = "  }"
main_lines[#main_lines + 1] = "}"
main_lines[#main_lines + 1] = ""

local main_path = out_dir .. "/main.tc"
local mf = assert(io.open(main_path, "w"))
mf:write(table.concat(main_lines, "\n"))
mf:close()
io.stdout:write("Wrote " .. main_path .. "\n")
io.stdout:write(string.format(
  "Done: %d pages (%d blank skipped), %d functions (%d curated) -> %s\n",
  #page_list, skipped, total_fns, total_curated, out_dir
))
