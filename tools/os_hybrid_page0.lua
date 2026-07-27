#!/usr/bin/env lua
-- Hybrid page0: Tiny-C lifted leaves + trampolines into stock page0 + splice ROM.
-- Usage: lua tools/os_hybrid_page0.lua [out.rom]

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]os_hybrid_page0%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Compiler = require("lang.compiler")
local Assembler = require("asm.assembler")
local Infer = require("asm.infer_names")

local PAGE = 0x4000
local FLASH = 512 * 1024

-- Original page0 entry -> Tiny-C label
-- mode "tramp" (default): jp from entry into FF-gap blob (lift.tc)
-- mode "inplace": assemble TC at entry, must fit in max_size bytes
local LIFTS = {
  { entry = 0x0630, name = "mmu_set_bankA", tc = "mmu_set_bankA_tc" },
  { entry = 0x0AAE, name = "lcd_busy_wait", tc = "lcd_busy_wait_tc" },
  { entry = 0x0AB7, name = "lcd_write_cmd", tc = "lcd_write_cmd_tc" },
  { entry = 0x1813, name = "lcd_cmd_07", tc = "lcd_cmd_07_tc" },
  { entry = 0x181D, name = "lcd_cmd_05", tc = "lcd_cmd_05_tc" },
  {
    entry = 0x035A,
    name = "key_scan",
    tc = "key_scan_tc",
    mode = "inplace",
    max_size = 0x25, -- original 0x035A..0x037E
    src = "key.tc",
  },
}

local rom_out = (arg and arg[1]) or (ROOT .. "/rom/ti83plus_reasm.rom")
local lift_asm_out = ROOT .. "/asm/generated/os_lift.asm"
local inv_json = ROOT .. "/rom/os_p0_inventory.json"

local function read_all(path)
  local f = assert(io.open(path, "rb"))
  local d = f:read("*a")
  f:close()
  return d
end

local function write_all(path, data)
  local f = assert(io.open(path, "wb"))
  f:write(data)
  f:close()
end

local stock = read_all(ROOT .. "/rom/ti83plus.rom")
assert(#stock == FLASH, "expected 512KB ti83plus.rom")

-- Find a free FF run large enough for lift blob (prefer high addresses)
local function find_free_org(page, need)
  local best_a, best_n = nil, 0
  local i = 0
  while i < PAGE do
    if page:byte(i + 1) == 0xFF then
      local j = i
      while j < PAGE and page:byte(j + 1) == 0xFF do
        j = j + 1
      end
      local n = j - i
      if n >= need and n >= best_n then
        best_a, best_n = i, n
      end
      i = j
    else
      i = i + 1
    end
  end
  return best_a, best_n
end

-- Compile lift.tc at a provisional org; measure size; recompile at chosen org.
local lift_src = read_all(ROOT .. "/projects/os83/lift.tc")
local function compile_lift(org)
  local ok, asm = pcall(Compiler.compile_source, lift_src, "lift.tc", {
    root = ROOT .. "/projects/os83",
    no_crt = true,
    code_org = org,
  })
  if not ok then
    error("Tiny-C lift compile failed: " .. tostring(asm))
  end
  write_all(lift_asm_out, asm)
  local ok2, result = pcall(Assembler.assemble_file, "asm/generated/os_lift.asm", {
    root = ROOT,
    max_size = PAGE,
  })
  if not ok2 then
    error("lift assemble failed: " .. tostring(result))
  end
  return asm, result
end

-- First pass at 0 to measure (assembler still uses org inside)
local _, probe = compile_lift(0x3E00)
local lift_size = 0
for i = 0, PAGE - 1 do
  if probe.bytes[i] then
    -- size is end PC from assembler
  end
end
lift_size = probe.size - 0x3E00
if lift_size < 0 then lift_size = probe.size end
-- probe.org was 0x3E00 so size is end address
if probe.size > 0x3E00 then
  lift_size = probe.size - 0x3E00
else
  lift_size = probe.size
end

local page0 = stock:sub(1, PAGE)
local free_org, free_n = find_free_org(page0, lift_size + 4)
if not free_org then
  error(string.format("no FF gap >= %d bytes in page0 for lift blob", lift_size + 4))
end
print(string.format("lift blob ~%d bytes -> org 0x%04X (gap %d)", lift_size, free_org, free_n))

local _, lift = compile_lift(free_org)
local lift_start = free_org
local lift_end = lift.size
lift_size = lift_end - lift_start
print(string.format("assembled lift 0x%04X..0x%04X (%d bytes)", lift_start, lift_end - 1, lift_size))

-- Resolve TC symbol addresses from assembler
local function sym_addr(name)
  local s = lift.symbols and lift.symbols[name]
  if type(s) == "number" then return s end
  -- assembler may store differently
  if lift.symbols then
    for k, v in pairs(lift.symbols) do
      if k == name or k:lower() == name:lower() then
        return v
      end
    end
  end
  return nil
end

-- Build mutable page0
local bytes = {}
for i = 1, PAGE do
  bytes[i] = page0:byte(i)
end

local function put8(addr, v)
  assert(addr >= 0 and addr < PAGE)
  bytes[addr + 1] = v % 256
end

local function put_jp(at, target)
  put8(at, 0xC3)
  put8(at + 1, target % 256)
  put8(at + 2, math.floor(target / 256) % 256)
end

-- Place trampoline lift blob
for a = lift_start, lift_end - 1 do
  put8(a, lift.bytes[a] or 0)
end

local function compile_unit(rel_src, org)
  local src = read_all(ROOT .. "/projects/os83/" .. rel_src)
  local ok, asm = pcall(Compiler.compile_source, src, rel_src, {
    root = ROOT .. "/projects/os83",
    no_crt = true,
    code_org = org,
  })
  if not ok then
    error("compile " .. rel_src .. " failed: " .. tostring(asm))
  end
  local path = "asm/generated/os_" .. rel_src:gsub("%.tc$", "") .. ".asm"
  write_all(ROOT .. "/" .. path, asm)
  local ok2, result = pcall(Assembler.assemble_file, path, {
    root = ROOT,
    max_size = PAGE,
  })
  if not ok2 then
    error("assemble " .. rel_src .. " failed: " .. tostring(result))
  end
  return result
end

-- Trampolines + in-place overlays
for _, L in ipairs(LIFTS) do
  if L.mode == "inplace" then
    local r = compile_unit(L.src or "key.tc", L.entry)
    local size = r.size - L.entry
    if size < 0 then size = r.size end
    if size > (L.max_size or 0) then
      error(string.format("%s inplace size %d > max %d", L.tc, size, L.max_size or 0))
    end
    for a = L.entry, L.entry + size - 1 do
      put8(a, r.bytes[a] or 0)
    end
    print(string.format("inplace %s @ 0x%04X (%d bytes, max %d)",
      L.name, L.entry, size, L.max_size or 0))
  else
    local target = sym_addr(L.tc)
    if not target then
      error("missing lift symbol " .. L.tc)
    end
    put_jp(L.entry, target)
    print(string.format("trampoline %s @ 0x%04X -> %s @ 0x%04X",
      L.name, L.entry, L.tc, target))
  end
end

local out_page = {}
for i = 1, PAGE do
  out_page[i] = string.char(bytes[i])
end
local new_page0 = table.concat(out_page)
local rom = new_page0 .. stock:sub(PAGE + 1)
write_all(rom_out, rom)
print("wrote " .. rom_out .. " (" .. #rom .. " bytes)")

local note = ROOT .. "/rom/os_p0_lifted.txt"
local nf = assert(io.open(note, "w"))
nf:write("# Lifted into Tiny-C (hybrid)\n")
for _, L in ipairs(LIFTS) do
  local how = (L.mode == "inplace") and "inplace" or "tramp"
  nf:write(string.format("0x%04X %s -> %s (%s)\n", L.entry, L.name, L.tc, how))
end
nf:close()
print("wrote " .. note)

-- Mark lift candidates in inventory JSON
local inv_f = io.open(inv_json, "r")
if inv_f then
  local inv = inv_f:read("*a")
  inv_f:close()
  for _, L in ipairs(LIFTS) do
    inv = inv:gsub(
      '("name":"' .. L.name .. '"(.-)"lifted":)null',
      '%1"tc"'
    )
  end
  write_all(inv_json, inv)
  print("updated " .. inv_json)
end

print("boot with: luajit tools/boot_os_smoke.lua " .. rom_out)
