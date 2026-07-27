#!/usr/bin/env lua
-- Build a page-0 function inventory for the OS -> Tiny-C lift.
-- Usage: lua tools/os_inventory.lua [out.md]

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]os_inventory%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Disasm = require("asm.disasm")
local Infer = require("asm.infer_names")

local PAGE = 0x4000
local FLASH = 512 * 1024
local out_md = (arg and arg[1]) or (ROOT .. "/rom/os_p0_inventory.md")
local out_json = ROOT .. "/rom/os_p0_inventory.json"

local f = assert(io.open(ROOT .. "/rom/ti83plus.rom", "rb"))
local data = f:read("*a")
f:close()
assert(#data == FLASH, "expected 512KB ti83plus.rom")

local page0 = data:sub(1, PAGE)
local seeds = { 0x0000, 0x0008, 0x0010, 0x0018, 0x0020, 0x0028, 0x0030, 0x0038 }
local symbols, meta = Infer.infer_bytes(page0, { size = PAGE, seeds = seeds })
local read8 = function(a)
  return page0:byte(a + 1) or 0
end

local function sorted_keys(t)
  local ks = {}
  for k in pairs(t) do ks[#ks + 1] = k end
  table.sort(ks)
  return ks
end

local function ports_list(set)
  local ks = sorted_keys(set)
  local out = {}
  for _, p in ipairs(ks) do
    out[#out + 1] = string.format("0x%02X", p)
  end
  return out
end

local function size_to_ret(entry, fp)
  -- Walk fallthrough until ret / no_fallthrough / leave body, capped.
  local a = entry
  local bytes = 0
  local guard = 0
  while guard < 256 do
    guard = guard + 1
    local insn = Disasm.decode(read8, a)
    if not insn then break end
    bytes = bytes + insn.size
    if insn.ret and not insn.fallthrough then
      break
    end
    if not insn.fallthrough then
      break
    end
    -- Stop before next inventory entry (another function)
    local next_a = insn.fallthrough
    if next_a ~= a + insn.size then
      -- branched; use fingerprint body span instead
      break
    end
    if meta.entries[next_a] and next_a ~= entry then
      break
    end
    a = next_a
  end
  if bytes == 0 and fp then
    local max_a = entry
    for b in pairs(fp.body or {}) do
      if b > max_a then max_a = b end
    end
    bytes = (max_a - entry) + 1
  end
  return bytes
end

local rows = {}
for addr in pairs(meta.entries) do
  local fp = meta.fingerprints[addr]
  local name = meta.addr_name[addr] or string.format("L_%04X", addr)
  local callees = {}
  if fp then
    for c in pairs(fp.calls) do
      local cn = meta.addr_name[c] or string.format("L_%04X", c)
      callees[#callees + 1] = { addr = c, name = cn }
    end
    table.sort(callees, function(a, b) return a.addr < b.addr end)
  end
  local leaf = fp and (not next(fp.calls)) or false
  local outs = fp and ports_list(fp.outs) or {}
  local ins = fp and ports_list(fp.ins) or {}
  rows[#rows + 1] = {
    addr = addr,
    name = name,
    insn_n = fp and fp.insn_n or 0,
    size = size_to_ret(addr, fp),
    leaf = leaf,
    callees = callees,
    out_ports = outs,
    in_ports = ins,
    lifted = nil,
  }
end

table.sort(rows, function(a, b) return a.addr < b.addr end)

-- Known first-lift targets + already-lifted map from hybrid note file
local LIFT_HINTS = {
  mmu_set_bankA = true,
  lcd_busy_wait = true,
  lcd_write_cmd = true,
  lcd_cmd_07 = true,
  lcd_cmd_05 = true,
  key_scan = true,
}
local lifted = {}
local note_f = io.open(ROOT .. "/rom/os_p0_lifted.txt", "r")
if note_f then
  for line in note_f:lines() do
    local name, tc = line:match("^0x%x+%s+([%w_]+)%s+%->%s+([%w_]+)")
    if name then lifted[name] = tc end
  end
  note_f:close()
end

local json_rows = {}
for _, r in ipairs(rows) do
  local callee_names = {}
  for _, c in ipairs(r.callees) do
    callee_names[#callee_names + 1] = c.name
  end
  json_rows[#json_rows + 1] = {
    addr = string.format("0x%04X", r.addr),
    name = r.name,
    insn_n = r.insn_n,
    size = r.size,
    leaf = r.leaf,
    callees = callee_names,
    out_ports = r.out_ports,
    in_ports = r.in_ports,
    lift_candidate = LIFT_HINTS[r.name] == true,
    lifted = lifted[r.name],
  }
end

local function json_encode(v)
  local t = type(v)
  if t == "nil" then return "null"
  elseif t == "boolean" then return v and "true" or "false"
  elseif t == "number" then return tostring(v)
  elseif t == "string" then
    return '"' .. v:gsub("\\", "\\\\"):gsub('"', '\\"') .. '"'
  elseif t == "table" then
    if #v > 0 or next(v) == nil then
      local parts = {}
      for i = 1, #v do parts[i] = json_encode(v[i]) end
      return "[" .. table.concat(parts, ",") .. "]"
    end
    local keys = {}
    for k in pairs(v) do keys[#keys + 1] = k end
    table.sort(keys)
    local parts = {}
    for _, k in ipairs(keys) do
      parts[#parts + 1] = json_encode(k) .. ":" .. json_encode(v[k])
    end
    return "{" .. table.concat(parts, ",") .. "}"
  end
  return "null"
end

local jf = assert(io.open(out_json, "w"))
jf:write(json_encode({
  page = 0,
  size = PAGE,
  function_count = #json_rows,
  functions = json_rows,
}) .. "\n")
jf:close()

local leaves, named = 0, 0
for _, r in ipairs(rows) do
  if r.leaf then leaves = leaves + 1 end
  if not r.name:match("^L_") then named = named + 1 end
end

local md = {}
local function w(s) md[#md + 1] = s end
w("# TI-83+ page 0 function inventory")
w("")
w(string.format("Generated by `tools/os_inventory.lua` from `rom/ti83plus.rom`."))
w("")
w(string.format("- Functions (call/RST entries): **%d**", #rows))
w(string.format("- Leaves (no calls): **%d**", leaves))
w(string.format("- Semantically named: **%d**", named))
w("")
w("## Lift candidates")
w("")
w("Rebuild hybrid: `lua tools/os_hybrid_page0.lua`")
w("")
w("| Addr | Name | Size | Insns | Ports in | Ports out | Leaf | Status |")
w("|------|------|------|-------|----------|-----------|------|--------|")
local shown = {}
for _, r in ipairs(rows) do
  if LIFT_HINTS[r.name] then
    shown[r.name] = true
    local status = lifted[r.name] and ("**lifted** -> `" .. lifted[r.name] .. "`") or "candidate"
    w(string.format("| `0x%04X` | `%s` | %d | %d | %s | %s | %s | %s |",
      r.addr, r.name, r.size, r.insn_n,
      table.concat(r.in_ports, " ") ~= "" and table.concat(r.in_ports, " ") or "-",
      table.concat(r.out_ports, " ") ~= "" and table.concat(r.out_ports, " ") or "-",
      r.leaf and "yes" or "no",
      status))
  end
end
-- Lifted symbols that are not yet inventory entries (pattern-seeded trampolines)
for name, tc in pairs(lifted) do
  if not shown[name] then
    w(string.format("| - | `%s` | - | - | - | - | - | **lifted** -> `%s` |", name, tc))
  end
end
w("")
w("## All functions")
w("")
w("| Addr | Name | Size | Insns | Leaf | Callees | In | Out |")
w("|------|------|------|-------|------|---------|----|-----|")
for _, r in ipairs(rows) do
  local callee_s = {}
  for i, c in ipairs(r.callees) do
    if i > 4 then callee_s[#callee_s + 1] = "..."; break end
    callee_s[#callee_s + 1] = c.name
  end
  w(string.format("| `0x%04X` | `%s` | %d | %d | %s | %s | %s | %s |",
    r.addr, r.name, r.size, r.insn_n,
    r.leaf and "yes" or "",
    table.concat(callee_s, ", "),
    table.concat(r.in_ports, " "),
    table.concat(r.out_ports, " ")))
end
w("")

local mf = assert(io.open(out_md, "w"))
mf:write(table.concat(md, "\n"))
mf:close()

print(string.format("wrote %s (%d functions)", out_md, #rows))
print(string.format("wrote %s", out_json))
