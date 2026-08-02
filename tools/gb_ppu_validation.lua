-- Game Boy PPU/CPU validation harness (read-only diagnostics; no emulator fixes).
-- Usage: luajit tools/gb_ppu_validation.lua

local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local ROOT = "rom/gb/tests"
local OUT = ROOT .. "/out"
local PACK = ROOT .. "/pack"
local CPF = 70224

local function ensure_dir(path)
  local sep = package.config:sub(1, 1)
  local acc = ""
  for part in string.gmatch(path, "[^/\\" .. sep .. "]+") do
    acc = acc == "" and part or (acc .. sep .. part)
    pcall(function()
      if sep == "\\" then os.execute('mkdir "' .. acc .. '" 2>nul') else os.execute("mkdir - p '" .. acc .. "'") end
    end)
  end
end

ensure_dir(OUT)

local function write_ppm(path, fb)
  local f = assert(io.open(path, "wb"))
  f:write("P6\n160 144\n255\n")
  local shades = {
    [0] = string.char(155, 188, 15),
    [1] = string.char(139, 172, 15),
    [2] = string.char(48, 98, 48),
    [3] = string.char(15, 56, 15),
  }
  for i = 0, 160 * 144 - 1 do
    f:write(shades[fb[i] or 0] or shades[0])
  end
  f:close()
end

local function fb_checksum(fb)
  local h = 2166136261
  for i = 0, 160 * 144 - 1 do
    h = band(h, 0xFFFFFFFF)
    h = band((h * 16777619) + (fb[i] or 0), 0xFFFFFFFF)
  end
  return string.format("%08X", h)
end

local function mooneye_result(cpu)
  local b, c, d, e, h, l = cpu.b, cpu.c, cpu.d, cpu.e, cpu.h, cpu.l
  if b == 3 and c == 5 and d == 8 and e == 13 and h == 21 and l == 34 then
    return "PASS"
  end
  return string.format("FAIL regs B=%02X C=%02X D=%02X E=%02X H=%02X L=%02X", b, c, d, e, h, l)
end

local function run_rom(path, opts)
  opts = opts or {}
  local frames = opts.frames or 120
  local m = Machine.new()
  local ok, err = m:load_rom_file(path)
  if not ok then return { status = "LOAD_FAIL", err = err } end
  m:reset()

  local serial = {}
  local orig_w = m.mmu.write
  function m.mmu:write(addr, v)
    addr = band(addr, 0xFFFF)
    v = band(v, 0xFF)
    if addr == 0xFF01 then
      serial[#serial + 1] = v
    end
    return orig_w(self, addr, v)
  end

  local last_pc, stable = -1, 0
  for i = 1, frames do
    m:run_cycles(CPF)
    if m.cpu.pc == last_pc then
      stable = stable + 1
      if stable >= 8 and opts.early_exit ~= false then break end
    else
      last_pc, stable = m.cpu.pc, 0
    end
  end

  local ser = ""
  for i = 1, #serial do
    local ch = serial[i]
    if ch >= 32 and ch < 127 then ser = ser .. string.char(ch) end
  end

  return {
    status = "RAN",
    cpu = m.cpu,
    ppu = m.ppu,
    mmu = m.mmu,
    cart = m.cart,
    serial = ser,
    fb = m:framebuffer(),
    frames = frames,
  }
end

local report = {}
local function add(cat, name, result, detail)
  report[#report + 1] = { cat = cat, name = name, result = result, detail = detail or "" }
  print(string.format("[%s] %-10s %s  %s", cat, result, name, detail or ""))
end

local function basename(path)
  return (path:gsub(".*[/\\]", ""))
end

----------------------------------------------------------------
-- 1) dmg-acid2 (visual / checksum)
----------------------------------------------------------------
do
  local path = PACK .. "/dmg-acid2/dmg-acid2.gb"
  local r = run_rom(path, { frames = 10, early_exit = false })
  if r.status ~= "RAN" then
    add("acid2", "dmg-acid2", "LOAD_FAIL", r.err)
  else
    local ppm = OUT .. "/dmg-acid2.ppm"
    write_ppm(ppm, r.fb)
    local sum = fb_checksum(r.fb)
    -- Reference DMG acid2 has a known structure; we record checksum + dump for human/visual compare.
    add("acid2", "dmg-acid2", "DUMPED", string.format("checksum=%s ppm=%s lcdc=%02X", sum, ppm, r.ppu.lcdc))
  end
end

----------------------------------------------------------------
-- 2) Mooneye acceptance (PPU-first, then related)
----------------------------------------------------------------
local function collect_gbs(dir)
  local list = {}
  local win = package.config:sub(1, 1) == "\\"
  local d = win and dir:gsub("/", "\\") or dir
  local cmd = win
      and ('cmd /c dir /s /b "' .. d .. '\\*.gb"')
      or ('find "' .. d .. '" -name "*.gb" -print')
  local p = io.popen(cmd)
  if not p then return list end
  for line in p:lines() do
    if line ~= "" and not line:lower():match("file not found") then
      list[#list + 1] = line
    end
  end
  p:close()
  table.sort(list)
  return list
end

local moon_dirs = {
  { "mooneye-ppu", PACK .. "/mooneye-test-suite/acceptance/ppu" },
  { "mooneye-oam", PACK .. "/mooneye-test-suite/acceptance/oam_dma" },
  { "mooneye-bits", PACK .. "/mooneye-test-suite/acceptance/bits" },
  { "mooneye-timer", PACK .. "/mooneye-test-suite/acceptance/timer" },
  { "mooneye-intr", PACK .. "/mooneye-test-suite/acceptance/interrupts" },
  { "mooneye-mbc1", PACK .. "/mooneye-test-suite/emulator-only/mbc1" },
}

-- Root acceptance (skip model-specific boot_* that need exact boot ROM)
local root = collect_gbs(PACK .. "/mooneye-test-suite/acceptance")
for _, path in ipairs(root) do
  local name = basename(path)
  if not name:match("^boot_") and not path:match("[/\\]ppu[/\\]")
      and not path:match("[/\\]oam_dma[/\\]")
      and not path:match("[/\\]bits[/\\]")
      and not path:match("[/\\]timer[/\\]")
      and not path:match("[/\\]interrupts[/\\]")
      and not path:match("[/\\]instr[/\\]")
      and not path:match("[/\\]serial[/\\]") then
    local r = run_rom(path, { frames = 180 })
    if r.status ~= "RAN" then
      add("mooneye-root", name, "LOAD_FAIL", r.err)
    else
      local res = mooneye_result(r.cpu)
      add("mooneye-root", name, res:sub(1, 4) == "PASS" and "PASS" or "FAIL", res)
    end
  end
end

for _, ent in ipairs(moon_dirs) do
  local cat, dir = ent[1], ent[2]
  for _, path in ipairs(collect_gbs(dir)) do
    local name = basename(path)
    -- Skip CGB/SGB-only where marked, still run - GS (DMG/SGB) and plain
    local frames = 240
    if cat == "mooneye-mbc1" then frames = 300 end
    local r = run_rom(path, { frames = frames })
    if r.status ~= "RAN" then
      add(cat, name, "LOAD_FAIL", r.err)
    else
      local res = mooneye_result(r.cpu)
      local pass = res:sub(1, 4) == "PASS"
      add(cat, name, pass and "PASS" or "FAIL", res)
      if cat == "mooneye-ppu" then
        write_ppm(OUT .. "/moon_" .. name:gsub("%.gb$", "") .. ".ppm", r.fb)
      end
    end
  end
end

-- boot regs for DMG ABC (no boot ROM: expects post-boot state)
do
  local path = PACK .. "/mooneye-test-suite/acceptance/boot_regs-dmgABC.gb"
  local r = run_rom(path, { frames = 60 })
  if r.status == "RAN" then
    local res = mooneye_result(r.cpu)
    add("mooneye-boot", "boot_regs-dmgABC", res:sub(1, 4) == "PASS" and "PASS" or "FAIL", res)
  end
end

----------------------------------------------------------------
-- 3) Blargg
----------------------------------------------------------------
local blargg = {
  { "blargg-cpu", ROOT .. "/blargg/cpu_instrs/individual", 1200 },
  { "blargg-mem", ROOT .. "/blargg/mem_timing/individual", 600 },
  { "blargg-oam", ROOT .. "/blargg/oam_bug/rom_singles", 600 },
  { "blargg-misc", ROOT .. "/blargg", 600 },
}

for _, ent in ipairs(blargg) do
  local cat, dir, frames = ent[1], ent[2], ent[3]
  for _, path in ipairs(collect_gbs(dir)) do
    -- only top-level for blargg-misc
    if cat == "blargg-misc" then
      local parent = path:match("blargg[/\\]([^/\\]+)%.gb$")
      if not parent then goto continue end
    end
    local name = basename(path)
    local r = run_rom(path, { frames = frames, early_exit = false })
    if r.status ~= "RAN" then
      add(cat, name, "LOAD_FAIL", r.err)
    else
      local ser = r.serial
      local result
      if ser:find("Passed") then
        result = "PASS"
      elseif ser:find("Failed") then
        result = "FAIL"
      else
        -- some finish with mooneye-like fibonacci or just dump serial
        local moon = mooneye_result(r.cpu)
        if moon:sub(1, 4) == "PASS" then
          result = "PASS"
        else
          result = "UNKNOWN"
        end
      end
      add(cat, name, result, string.format("serial=%q %s", ser:sub(1, 80), mooneye_result(r.cpu)))
      write_ppm(OUT .. "/blargg_" .. name:gsub("[^%w%.%-]", "_"):gsub("%.gb$", "") .. ".ppm", r.fb)
    end
    ::continue::
  end
end

----------------------------------------------------------------
-- Summary
----------------------------------------------------------------
local counts = {}
for _, row in ipairs(report) do
  counts[row.result] = (counts[row.result] or 0) + 1
end

print("\n==== SUMMARY ====")
local keys = {}
for k in pairs(counts) do keys[#keys + 1] = k end
table.sort(keys)
for _, k in ipairs(keys) do
  print(string.format("%s: %d", k, counts[k]))
end
print(string.format("total: %d", #report))

local f = assert(io.open(OUT .. "/report.txt", "w"))
f:write("Game Boy validation report\n")
f:write(os.date("!%Y-%m-%d %H:%M:%SZ") .. "\n\n")
for _, row in ipairs(report) do
  f:write(string.format("%-14s %-8s %s | %s\n", row.cat, row.result, row.name, row.detail))
end
f:write("\nSUMMARY\n")
for _, k in ipairs(keys) do
  f:write(string.format("%s: %d\n", k, counts[k]))
end
f:close()
print("wrote " .. OUT .. "/report.txt")
