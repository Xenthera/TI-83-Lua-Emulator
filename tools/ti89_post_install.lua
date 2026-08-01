-- Trace post-install / ON-key behavior.
package.path = "./?.lua;./?/init.lua;" .. package.path

local Machine = require("machines.ti89.machine")
local m = Machine.new()
assert(m:load_rom_file(arg[1] or "rom/ti89.rom"))
m:reset()

local function lcd_stats()
  local fb = m:framebuffer()
  local nz, ff = 0, 0
  for i = 0, 1999 do
    local v = fb[i] or 0
    if v ~= 0 then nz = nz + 1 end
    if v == 255 then ff = ff + 1 end
  end
  return nz, ff, fb
end

local function dump_rows(fb, maxy)
  for y = 0, maxy or 24 do
    local t = {}
    for x = 0, 159 do
      local byte = fb[y * 20 + math.floor(x / 8)] or 0
      local bit = 7 - (x % 8)
      t[#t + 1] = (math.floor(byte / 2 ^ bit) % 2 == 1) and "#" or " "
    end
    local r = table.concat(t)
    if r:find("%S") then
      print(string.format("%02d %s", y, r))
    end
  end
end

local prev_nz = -1
for sec = 1, 90 do
  m:run_cycles(16000000)
  local nz, ff = lcd_stats()
  if sec % 5 == 0 or nz ~= prev_nz then
    print(string.format(
      "t=%2ds PC=%06X SR=%04X nz=%d ff=%d stopped=%s sleep=%02X pending=%02X",
      sec, m:pc(), m.cpu.sr, nz, ff, tostring(m.cpu.stopped),
      m.bus.sleep_mask or 0, m.bus.irq_pending or 0
    ))
  end
  prev_nz = nz
  if sec >= 15 and nz < 80 and ff < 100 then
    print("screen cleared-ish at", sec)
    break
  end
end

print("--- LCD before ON ---")
local _, _, fb = lcd_stats()
dump_rows(fb, 30)

print("--- ON pulse ---")
m:set_key("on", true)
m:run_cycles(8000000)
print(string.format("ON down PC=%06X SR=%04X", m:pc(), m.cpu.sr))
m:set_key("on", false)

for sec = 1, 45 do
  m:run_cycles(16000000)
  local nz, ff = lcd_stats()
  if sec % 3 == 0 or sec <= 3 then
    print(string.format(
      "afterON+%2ds PC=%06X nz=%d ff=%d 5B12=%04X 5B18=%02X 5B30=%02X 5B32=%02X",
      sec, m:pc(), nz, ff,
      m.bus:read16(0x5B12), m.bus:read8(0x5B18), m.bus:read8(0x5B30), m.bus:read8(0x5B32)
    ))
  end
end

print("--- LCD after ON ---")
_, _, fb = lcd_stats()
dump_rows(fb, 40)
print(string.format("flash mode=%s bytes=%s", m.flash.mode, tostring(m.flash.bytes ~= nil)))
