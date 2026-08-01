-- Run AMS for N seconds of emulated time and dump LCD as ASCII.
package.path = "./?.lua;./?/init.lua;" .. package.path

local Machine = require("machines.ti89.machine")
local secs = tonumber(arg[1]) or 3
local rom = arg[2] or "rom/ti89.rom"

local m = Machine.new()
assert(m:load_rom_file(rom))
m:reset()

local t0 = os.clock()
local target = 16000000 * secs
local ran = m:run_cycles(target)
local e = os.clock() - t0
local cpu = m.cpu

print(string.format("ran=%d time=%.2fs cps=%.0f PC=%06X SR=%04X", ran, e, ran / e, cpu.pc, cpu.sr))
print(string.format(
  "A0=%06X A1=%06X A2=%06X A3=%06X A4=%06X A5=%06X A6=%06X A7=%06X",
  cpu:get_a(0), cpu:get_a(1), cpu:get_a(2), cpu:get_a(3),
  cpu:get_a(4), cpu:get_a(5), cpu:get_a(6), cpu:get_a(7)
))
print(string.format("LCD base=%06X on=%s", m.lcd.base, tostring(m.lcd.display_on)))

-- Use packed 160×100 view (respects logical 240px stride).
local fb = m:framebuffer()
print(string.format("logical_bpr=%d height_reg=%02X", m.lcd:logical_row_bytes(), m.lcd.height_reg))
local function biton(row, col)
  local byte = fb[row * 20 + math.floor(col / 8)] or 0
  local bit = 7 - (col % 8)
  return math.floor(byte / 2 ^ bit) % 2 == 1
end

for y = 0, 99, 2 do
  local line = {}
  for x = 0, 159, 2 do
    local n = 0
    if biton(y, x) then n = n + 1 end
    if biton(y, x + 1) then n = n + 1 end
    if y + 1 <= 99 then
      if biton(y + 1, x) then n = n + 1 end
      if biton(y + 1, x + 1) then n = n + 1 end
    end
    line[#line + 1] = (n >= 2) and "#" or ((n == 1) and "." or " ")
  end
  print(table.concat(line))
end

local pc = cpu.pc
print("near PC:")
for a = pc - 8, pc + 24, 2 do
  print(string.format(" %06X: %04X", a, m.bus:read16(a)))
end
