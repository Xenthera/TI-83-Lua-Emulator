-- Wait until flash programming goes idle, then try ON / report LCD.
package.path = "./?.lua;./?/init.lua;" .. package.path

local Machine = require("machines.ti89.machine")
local m = Machine.new()
assert(m:load_rom_file(arg[1] or "rom/ti89.rom"))
m:reset()

local writes = 0
local fw = m.flash.write16
function m.flash:write16(a, v)
  writes = writes + 1
  return fw(self, a, v)
end

local last_w = 0
local idle_secs = 0
for sec = 1, 300 do
  local w0 = writes
  m:run_cycles(16000000)
  local dw = writes - w0
  local fb = m:framebuffer()
  local nz = 0
  for i = 0, 1999 do
    if (fb[i] or 0) ~= 0 then nz = nz + 1 end
  end
  if sec % 10 == 0 or dw == 0 then
    print(string.format(
      "t=%3ds PC=%06X flash_wr/s=%d total_wr=%d nz=%d 843E=%d",
      sec, m:pc(), dw, writes, nz, m.bus:read32(0x843E)
    ))
  end
  if dw < 10 then
    idle_secs = idle_secs + 1
  else
    idle_secs = 0
  end
  if idle_secs >= 5 and sec > 30 then
    print("flash idle for 5s at t=", sec)
    break
  end
end

local function dump()
  local fb = m:framebuffer()
  for y = 0, 40 do
    local t = {}
    for x = 0, 159 do
      local byte = fb[y * 20 + math.floor(x / 8)] or 0
      local bit = 7 - (x % 8)
      t[#t + 1] = (math.floor(byte / 2 ^ bit) % 2 == 1) and "#" or " "
    end
    local r = table.concat(t)
    if r:find("%S") then print(string.format("%02d %s", y, r)) end
  end
end

print("--- LCD when flash idle ---")
dump()

print("--- long ON hold ---")
m:set_key("on", true)
m:run_cycles(16000000 * 2)
m:set_key("on", false)
m:run_cycles(16000000 * 5)
print(string.format("PC=%06X", m:pc()))
dump()

-- try 2nd+ON style reset keys? just enter/esc
for _, k in ipairs({ "esc", "enter", "apps", "home" }) do
  m:set_key(k, true)
  m:run_cycles(500000)
  m:set_key(k, false)
  m:run_cycles(2000000)
end
print("--- after keys ---")
print(string.format("PC=%06X", m:pc()))
dump()
