#!/usr/bin/env luajit
-- Boot ti83plus.rom through soft power-off + ON wake; report LCD state.
-- Use LuaJIT - PUC Lua is ~20-50x slower for long OS bring-up.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]boot_os_smoke%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path
io.stdout:setvbuf("no")

local rom_path = (arg and arg[1]) or (ROOT .. "/rom/ti83plus.rom")
local Machine = require("machines.ti83plus.machine")
local m = Machine.new()
assert(m:load_rom_file(rom_path), "missing ROM: " .. rom_path)
print("ROM " .. rom_path)
m:reset()

local function fb_nz()
  local n = 0
  for i = 0, 767 do
    if m.asic.lcd.fb[i] ~= 0 then n = n + 1 end
  end
  return n
end

print("waiting for power-off HALT...")
local t0 = os.clock()
while not m.cpu.halted do
  m:run_cycles(50000)
end
print(string.format("HALT PC=%04X cyc=%d (%.2fs)", m.cpu.pc, m.total_cycles, os.clock() - t0))

print("holding ON to wake...")
m:set_key("on", true)
m:run_cycles(3 * 1000 * 1000)
m:set_key("on", false)

local best_nz = 0
for i = 1, 40 do
  m:run_cycles(1000000)
  local nz = fb_nz()
  if nz > best_nz then best_nz = nz end
  print(string.format(
    "t=%02d PC=%04X disp=%s nz=%d halt=%s (%.2fs)",
    i, m.cpu.pc, tostring(m:is_display_on()), nz, tostring(m.cpu.halted), os.clock() - t0
  ))
  if m:is_display_on() and (nz > 50 or (m.cpu.halted and m.cpu.pc == 0x02A4)) then
    break
  end
  if m.cpu.halted then
    m:set_key("on", true)
    m:run_cycles(2 * 1000 * 1000)
    m:set_key("on", false)
  end
end

local fb = m:framebuffer()
for row = 0, 15 do
  local any = false
  for c = 0, 11 do
    if (fb[row * 12 + c] or 0) ~= 0 then any = true break end
  end
  if any then
    local t = {}
    for c = 0, 11 do
      t[#t + 1] = string.format("%02X", fb[row * 12 + c] or 0)
    end
    print(string.format("R%02d %s", row, table.concat(t, " ")))
  end
end

print(string.format("done in %.2fs  best_nz=%d", os.clock() - t0, best_nz))
if m:is_display_on() then
  print("BOOT OS SMOKE OK")
  os.exit(0)
else
  print("BOOT OS SMOKE FAIL: display still off")
  os.exit(1)
end
