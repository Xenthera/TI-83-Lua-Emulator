#!/usr/bin/env lua
-- Headless ROM bring-up: run millions of cycles and report progress.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]bringup%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Machine = require("machines.ti83plus.machine")

-- Prefer a real TI dump if present; otherwise build/use synthetic bring-up ROM.
local function ensure_synth()
  local path = ROOT .. "/rom/synth.rom"
  local f = io.open(path, "rb")
  if f then
    local n = #f:read("*a")
    f:close()
    if n == 512 * 1024 then
      return path
    end
  end
  os.execute(string.format('lua "%s/tools/make_synth_rom.lua"', ROOT))
  return path
end

local candidates = {
  ROOT .. "/rom/ti83plus.rom",
  ROOT .. "/rom/ti83plus.bin",
  ROOT .. "/rom/83plus.rom",
  ensure_synth(),
}

local machine = Machine.new()
local loaded
for _, path in ipairs(candidates) do
  local ok, err = machine:load_rom_file(path)
  if ok then
    print("Loaded " .. path)
    loaded = path
    break
  end
end

if not loaded then
  print("SKIP: no 512KB ROM in rom/ - place ti83plus.rom to bring up OS")
  os.exit(0)
end

machine:reset()

local is_synth = loaded:find("synth%.rom") ~= nil
local BUDGET = is_synth and (2 * 1000 * 1000) or (20 * 1000 * 1000)
local STEP = 50000
local last_pc = -1
local pc_changes = 0
local display_on_seen = false

for _ = 1, math.floor(BUDGET / STEP) do
  machine:run_cycles(STEP)
  local pc = machine:pc()
  if pc ~= last_pc then
    pc_changes = pc_changes + 1
    last_pc = pc
  end
  if machine:is_display_on() then
    display_on_seen = true
  end
end

print(string.format("cycles=%d  PC=%04X  pc_changes=%d  display_on=%s  dirty=%s",
  machine.total_cycles, machine:pc(), pc_changes,
  tostring(display_on_seen), tostring(machine:display_dirty())))

if is_synth then
  local ready = machine.mmu:read(0xC001)
  if not display_on_seen or ready ~= 0x42 then
    print(string.format("FAIL: synth bring-up (ready=%02X)", ready))
    os.exit(1)
  end
  print("Bring-up OK (synth firmware: LCD on, ready flag set)")
  os.exit(0)
end

if pc_changes < 10 then
  print("WARN: PC barely moved - possible hang / missing port")
  os.exit(1)
end

print("Bring-up smoke OK (CPU executing; check Love2D for homescreen)")
os.exit(0)
