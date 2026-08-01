#!/usr/bin/env lua
-- Lift TI ROM flash pages into mechanical ISO C for native/.
--
-- Usage:
--   lua tools/asm_to_c.lua rom/ti83plus.rom -o native/gen --pages 0
--   lua tools/asm_to_c.lua rom/ti83plus.rom -o native/gen

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]asm_to_c%.lua$")
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
Usage: lua tools/asm_to_c.lua <rom.bin> [options]
  -o DIR            output dir (default: native/gen)
  --pages A-B|N,N   pages to lift (default: 0)
  --pages banked    page 0 + every page targeted by 2B07/2B3C trampolines
  --max-fns N       cap functions per page
  --no-infer        skip behavior-based names
  --no-curated      full mechanical bodies for known leaves
  --keep-blank      include empty 0xFF pages
]])
end

local function parse_pages(spec, max_page, banked_by_page)
  local set = {}
  if not spec then
    set[0] = true
    return set
  end
  if tostring(spec) == "banked" then
    set[0] = true
    for p in pairs(banked_by_page or {}) do
      if p >= 0 and p <= max_page then set[p] = true end
    end
    -- Boot continue page
    if max_page >= 31 then set[31] = true end
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
  require("framework.path").ensure_dir(path)
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

out_dir = out_dir or (ROOT .. "/native/gen")

local f, err = io.open(in_path, "rb")
if not f then
  io.stderr:write("cannot open " .. in_path .. ": " .. tostring(err) .. "\n")
  os.exit(1)
end
local data = f:read("*a")
f:close()

local max_page = math.floor((#data - 1) / PAGE)

-- Banked trampoline destinations from the whole ROM -> seeds per page.
local banked_by_page = Flash.scan_banked_targets(data)
do
  local n = 0
  for _, list in pairs(banked_by_page) do n = n + #list end
  io.stdout:write(string.format("banked trampoline targets: %d across pages\n", n))
end

local page_set = parse_pages(pages_spec, max_page, banked_by_page)
local page_list = {}
for p = 0, max_page do
  if page_set[p] then page_list[#page_list + 1] = p end
end

ensure_dir(out_dir)

local cross, cross_raw = {}, {}
if page_set[0] then
  local s0 = slice_page(data, 0)
  if not Flash.is_blank(s0) then
    local _, meta0 = Recover.page_to_c(s0, {
      page = 0,
      infer = infer,
      max_fns = max_fns,
      curated = false,
      extra_seeds = banked_by_page[0],
    })
    for addr, name in pairs(meta0.by_addr or {}) do
      cross_raw[addr] = name
      cross[addr] = "p00_" .. name
    end
  end
end

local total_fns = 0
local skipped = 0
local pages_written = {}
local defined = {} -- fname -> true
local sources = {} -- list of {page, path, csrc}
-- Dispatch: (page << 16 | cpu_addr) for bank window, or addr for page0
local dispatch = {} -- list of { page, addr, fname }

for _, page in ipairs(page_list) do
  local slice = slice_page(data, page)
  if not keep_blank and Flash.is_blank(slice) then
    skipped = skipped + 1
    io.stdout:write(string.format("page %02d: blank - skipped\n", page))
  else
    local csrc, meta = Recover.page_to_c(slice, {
      page = page,
      infer = infer,
      max_fns = max_fns,
      curated = curated,
      cross = cross,
      cross_raw = cross_raw,
      extra_seeds = banked_by_page[page],
    })
    for fname in csrc:gmatch("void%s+(p%d%d_[A-Za-z0-9_]+)%s*%(void%)%s*{") do
      defined[fname] = true
    end
    -- Map every recovered entry -> dispatch (by_addr names + L_XXXX labels).
    if meta and meta.by_addr then
      for addr, raw in pairs(meta.by_addr) do
        local fname = string.format("p%02d_%s", page, raw)
        dispatch[#dispatch + 1] = { page = page, addr = addr, fname = fname }
      end
    end
    for fname in csrc:gmatch("void%s+(p%d%d_[A-Za-z0-9_]+)%s*%(void%)%s*{") do
      local pg, hex = fname:match("^p(%d%d)_L_(%x+)$")
      if pg and hex then
        local addr = tonumber(hex, 16)
        local pgn = tonumber(pg, 10)
        if addr then
          dispatch[#dispatch + 1] = { page = pgn, addr = addr, fname = fname }
        end
      end
    end
    local rel = string.format("page%02d.c", page)
    local path = out_dir .. "/" .. rel
    sources[#sources + 1] = { page = page, path = path, csrc = csrc }
    total_fns = total_fns + (meta.functions or 0)
    pages_written[#pages_written + 1] = page
    io.stdout:write(string.format(
      "page %02d -> %s (%d fn, cpu 0x%04X)\n",
      page, path, meta.functions or 0, meta.window_lo or 0
    ))
  end
end

-- Cross-page calls to missing symbols become empty stubs.
local needed = {}
for _, src in ipairs(sources) do
  for fname in src.csrc:gmatch("%f[%w](p%d%d_[A-Za-z0-9_]+)%s*%(") do
    if not defined[fname] then needed[fname] = true end
  end
end

local stub_lines = {
  "/* Auto-generated stubs for unresolved cross-page calls. */",
  '#include "ti_cpu.h"',
  '#include "ti_hw_api.h"',
  '#include "ti_mem.h"',
  "",
}
local stub_n = 0
local stub_names = {}
for fname in pairs(needed) do
  stub_names[#stub_names + 1] = fname
end
table.sort(stub_names)
for _, fname in ipairs(stub_names) do
  stub_lines[#stub_lines + 1] = "void " .. fname .. "(void) { /* unresolved */ }"
  defined[fname] = true
  stub_n = stub_n + 1
end
local stub_path = out_dir .. "/stubs.c"
local sf = assert(io.open(stub_path, "w"))
sf:write(table.concat(stub_lines, "\n") .. "\n")
sf:close()
io.stdout:write(string.format("Wrote %s (%d stubs)\n", stub_path, stub_n))

local hdr_names = {}
for fname in pairs(defined) do
  hdr_names[#hdr_names + 1] = fname
end
table.sort(hdr_names)
local hdr_lines = {
  "/* Auto-generated mechanical TI-OS page entries. */",
  "#ifndef TI_OS_GEN_H",
  "#define TI_OS_GEN_H",
  "",
}
for _, fname in ipairs(hdr_names) do
  hdr_lines[#hdr_lines + 1] = "void " .. fname .. "(void);"
end
hdr_lines[#hdr_lines + 1] = ""
hdr_lines[#hdr_lines + 1] = "#endif"
local hdr_path = out_dir .. "/ti_os_gen.h"
local hf = assert(io.open(hdr_path, "w"))
hf:write(table.concat(hdr_lines, "\n") .. "\n")
hf:close()
io.stdout:write("Wrote " .. hdr_path .. "\n")

-- Ensure each page .c can see cross-page prototypes.
for _, src in ipairs(sources) do
  local csrc = src.csrc
  if not csrc:find('#include "ti_os_gen.h"', 1, true) then
    csrc = csrc:gsub(
      '#include "ti_mem.h"\n',
      '#include "ti_mem.h"\n#include "ti_os_gen.h"\n',
      1
    )
  end
  local pf = assert(io.open(src.path, "w"))
  pf:write(csrc)
  pf:write("\n")
  pf:close()
end

-- Deduplicate dispatch entries and emit os_banked / os_jp helpers.
do
  local seen, list = {}, {}
  for _, e in ipairs(dispatch) do
    local key = string.format("%d:%04X", e.page, e.addr)
    if not seen[key] and defined[e.fname] then
      seen[key] = true
      list[#list + 1] = e
    end
  end
  table.sort(list, function(a, b)
    if a.page ~= b.page then return a.page < b.page end
    return a.addr < b.addr
  end)

  local dlines = {
    "/* Auto-generated enter/dispatch for recovered flash pages. */",
    '#include "ti_cpu.h"',
    '#include "ti_hw_api.h"',
    '#include "ti_mem.h"',
    '#include "ti_os_gen.h"',
    "",
    "#include <stdio.h>",
    "",
    "void os_bump_step(void);",
    "",
    "static int os_enter_page_addr(uint8_t page, uint16_t addr) {",
    "  os_bump_step();",
    "  switch (((uint32_t)page << 16) | (uint32_t)addr) {",
  }
  for _, e in ipairs(list) do
    dlines[#dlines + 1] = string.format(
      "    case 0x%02X%04Xu: %s(); return 1;",
      e.page, e.addr, e.fname
    )
  end
  dlines[#dlines + 1] = "    default: return 0;"
  dlines[#dlines + 1] = "  }"
  dlines[#dlines + 1] = "}"
  dlines[#dlines + 1] = ""
  dlines[#dlines + 1] = "void os_banked_call(uint16_t cpu_addr) {"
  dlines[#dlines + 1] = "  os_bump_step();"
  dlines[#dlines + 1] = "  uint8_t page = g_hw.mmu.bank_a & 0x1F;"
  dlines[#dlines + 1] = "  uint16_t off;"
  dlines[#dlines + 1] = "  if (cpu_addr >= 0x8000 && cpu_addr < 0xC000) off = (uint16_t)(cpu_addr - 0x8000);"
  dlines[#dlines + 1] = "  else if (cpu_addr >= 0x4000 && cpu_addr < 0x8000) off = (uint16_t)(cpu_addr - 0x4000);"
  dlines[#dlines + 1] = "  else { fprintf(stderr, \"os_banked_call: ignore %04X\\n\", cpu_addr); return; }"
  dlines[#dlines + 1] = "  uint16_t bank_addr = (uint16_t)(0x4000 + off);"
  dlines[#dlines + 1] = "  /* Boot vector always page 1F continue. */"
  dlines[#dlines + 1] = "  if (cpu_addr == 0x80D5 || bank_addr == 0x40D5) page = 0x1F;"
  dlines[#dlines + 1] = "  if (!os_enter_page_addr(page, bank_addr)) {"
  dlines[#dlines + 1] = "    static int once;"
  dlines[#dlines + 1] = "    if (once < 8) {"
  dlines[#dlines + 1] = "      fprintf(stderr, \"os_banked_call: unhandled %04X (page=%02X bank=%04X)\\n\", cpu_addr, page, bank_addr);"
  dlines[#dlines + 1] = "      once++;"
  dlines[#dlines + 1] = "    }"
  dlines[#dlines + 1] = "  }"
  dlines[#dlines + 1] = "}"
  dlines[#dlines + 1] = ""
  dlines[#dlines + 1] = "void os_jp_hl(void) {"
  dlines[#dlines + 1] = "  uint16_t t = hl();"
  dlines[#dlines + 1] = "  if (t < 0x4000) {"
  dlines[#dlines + 1] = "    if (!os_enter_page_addr(0, t)) {"
  dlines[#dlines + 1] = "      static int once;"
  dlines[#dlines + 1] = "      if (once < 4) { fprintf(stderr, \"os_jp_hl: unhandled %04X\\n\", t); once++; }"
  dlines[#dlines + 1] = "    }"
  dlines[#dlines + 1] = "  } else {"
  dlines[#dlines + 1] = "    os_banked_call(t);"
  dlines[#dlines + 1] = "  }"
  dlines[#dlines + 1] = "}"
  dlines[#dlines + 1] = ""
  dlines[#dlines + 1] = "void os_jp_ix(void) { set_hl(ix); os_jp_hl(); }"
  dlines[#dlines + 1] = "void os_jp_iy(void) { set_hl(iy); os_jp_hl(); }"
  dlines[#dlines + 1] = ""

  local dpath = out_dir .. "/dispatch.c"
  local df = assert(io.open(dpath, "w"))
  df:write(table.concat(dlines, "\n") .. "\n")
  df:close()
  io.stdout:write(string.format("Wrote %s (%d entries)\n", dpath, #list))
end

io.stdout:write(string.format(
  "Done: %d pages (%d blank skipped), %d functions, %d stubs -> %s\n",
  #pages_written, skipped, total_fns, stub_n, out_dir
))
