#!/usr/bin/env lua
-- Input/LCD validation harness.
-- With synth.rom: press Enter and expect LCD + RAM side effects.
-- With a real TI ROM: inject "1+1" Enter and look for framebuffer changes.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]basic_smoke%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Machine = require("core.machine")

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

local function load_rom(machine)
  for _, path in ipairs({
    ROOT .. "/rom/ti83plus.rom",
    ROOT .. "/rom/ti83plus.bin",
    ROOT .. "/rom/83plus.rom",
    ensure_synth(),
  }) do
    if machine:load_rom_file(path) then
      return path
    end
  end
end

local function fb_hash(fb)
  local h = 0
  for i = 0, 12 * 64 - 1 do
    h = (h * 131 + (fb[i] or 0)) % 2147483647
  end
  return h
end

local function tap(machine, key, hold_cycles)
  machine:set_key(key, true)
  machine:run_cycles(hold_cycles or 80000)
  machine:set_key(key, false)
  machine:run_cycles(hold_cycles or 80000)
end

local machine = Machine.new()
local path = load_rom(machine)
if not path then
  print("FAIL: could not load any ROM")
  os.exit(1)
end

print("ROM " .. path)
machine:reset()

local is_synth = path:find("synth%.rom") ~= nil

if is_synth then
  machine:run_cycles(2 * 1000 * 1000)
  local ready = machine.mmu:read(0xC001)
  local display_on = machine:is_display_on()
  local fb = machine:framebuffer()
  local top = fb[0]

  print(string.format("ready=%02X display_on=%s top_byte=%02X irq_ctr=%02X",
    ready, tostring(display_on), top, machine.mmu:read(0xC000)))

  if ready ~= 0x42 or not display_on or top ~= 0xFF then
    print("FAIL: synth firmware did not initialize LCD/ready flag")
    os.exit(1)
  end

  local before = fb_hash(fb)
  tap(machine, "enter", 100000)
  machine:run_cycles(500000)
  local enter_flag = machine.mmu:read(0xC002)
  local after = fb_hash(machine:framebuffer())
  local row4 = machine:framebuffer()[4 * 12]

  print(string.format("enter_flag=%02X row4=%02X fb_changed=%s irq_ctr=%02X",
    enter_flag, row4, tostring(before ~= after), machine.mmu:read(0xC000)))

  if enter_flag ~= 0x99 or row4 ~= 0xFF then
    print("FAIL: Enter key did not reach synth firmware / LCD")
    os.exit(1)
  end

  print("BASIC smoke OK (synth): keypad -> firmware -> LCD")
  os.exit(0)
end

-- Real TI ROM path
machine:run_cycles(80 * 1000 * 1000)
local before = fb_hash(machine:framebuffer())
tap(machine, "on", 100000)
machine:run_cycles(5 * 1000 * 1000)
tap(machine, "1")
tap(machine, "plus")
tap(machine, "1")
tap(machine, "enter")
machine:run_cycles(10 * 1000 * 1000)
local after = fb_hash(machine:framebuffer())

print(string.format("PC=%04X display_on=%s fb_before=%d fb_after=%d",
  machine:pc(), tostring(machine:is_display_on()), before, after))

if before ~= after then
  print("BASIC smoke OK: LCD framebuffer changed after key sequence")
else
  print("PARTIAL: keys injected but FB hash unchanged; use Love2D for interactive check")
end
os.exit(0)
