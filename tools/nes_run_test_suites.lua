-- Run prioritized NES test-ROM suites (CPU / PPU / mem). Skips APU for now.
-- Usage: luajit tools/nes_run_test_suites.lua [--frames N]

package.path = "?.lua;?/init.lua;" .. (package.path or "")

local frames = 900
local args = { ... }
for i = 1, #args do
  if args[i] == "--frames" then frames = tonumber(args[i + 1]) or frames end
end

local suites = {
  { name = "instr_test-v5 singles", dir = "tools/nes-test-roms/instr_test-v5/rom_singles", frames = 900 },
  { name = "instr_test-v5 official", roms = { "tools/nes-test-roms/instr_test-v5/official_only.nes" }, frames = 2000 },
  { name = "ppu_vbl_nmi", dir = "tools/nes-test-roms/ppu_vbl_nmi/rom_singles", frames = 600 },
  { name = "vbl_nmi_timing", dir = "tools/nes-test-roms/vbl_nmi_timing", frames = 400 },
  { name = "sprite_overflow", dir = "tools/nes-test-roms/sprite_overflow_tests", frames = 400 },
  { name = "oam_read", dir = "tools/nes-test-roms/oam_read", frames = 200 },
  { name = "ppu_open_bus", dir = "tools/nes-test-roms/ppu_open_bus", frames = 400 },
  { name = "ppu_read_buffer", dir = "tools/nes-test-roms/ppu_read_buffer", frames = 400 },
  { name = "cpu_dummy_reads", dir = "tools/nes-test-roms/cpu_dummy_reads", frames = 400 },
  { name = "cpu_dummy_writes", dir = "tools/nes-test-roms/cpu_dummy_writes", frames = 400 },
  { name = "instr_misc", dir = "tools/nes-test-roms/instr_misc/rom_singles", frames = 600 },
  { name = "branch_timing", dir = "tools/nes-test-roms/branch_timing_tests", frames = 400 },
  { name = "cpu_exec_space", dir = "tools/nes-test-roms/cpu_exec_space", frames = 400 },
  { name = "cpu_interrupts_v2", dir = "tools/nes-test-roms/cpu_interrupts_v2/rom_singles", frames = 600 },
}

local function sh_quote(s)
  return '"' .. tostring(s):gsub('"', '\\"') .. '"'
end

local total_pass, total_fail, total_other = 0, 0, 0

for _, s in ipairs(suites) do
  print("\n######## " .. s.name .. " ########")
  local cmd = 'tools\\luajit\\luajit.exe tools\\nes_blargg_run.lua --frames ' .. tostring(s.frames or frames)
  if s.dir then
    cmd = cmd .. " --suite " .. sh_quote(s.dir)
  else
    for _, r in ipairs(s.roms or {}) do
      cmd = cmd .. " " .. sh_quote(r)
    end
  end
  local ok = os.execute(cmd)
  -- os.execute return varies; parse is best-effort via exit
end

print("\n(see per-suite summaries above)")
