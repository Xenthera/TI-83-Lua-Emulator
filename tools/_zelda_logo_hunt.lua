-- Hunt for the ZELDA logo title screen (no Start); dump when BGP/SCX look stable.
package.path = "./?.lua;./?/init.lua;" .. package.path
local M = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local m = M.new()
assert(m:load_rom_file("rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"))
m:reset()
local frame = 154 * 456

local function ppm(path)
  local p = m.ppu
  local f = assert(io.open(path, "wb"))
  f:write("P6\n160 144\n255\n")
  local S = { [0] = {224,248,208}, {136,192,112}, {52,104,86}, {8,24,32} }
  for i = 0, 160 * 144 - 1 do
    local s = p.fb[i] or 0
    if s < 0 then s = 0 elseif s > 3 then s = 3 end
    local c = S[s]
    f:write(string.char(c[1], c[2], c[3]))
  end
  f:close()
end

local last_bgp, last_scy = -1, -1
for sec = 1, 60 do
  for _ = 1, 60 do m:run_cycles(frame) end
  local p = m.ppu
  local changed = (p.bgp ~= last_bgp) or (math.abs(p.scy - last_scy) > 10)
  if changed or sec % 5 == 0 then
    print(string.format(
      "t=%02ds lcdc=%02X scy=%3d scx=%3d lyc=%3d bgp=%02X",
      sec, p.lcdc, p.scy, p.scx, p.lyc, p.bgp
    ))
    ppm(string.format("rom/gb/_logo_%02d.ppm", sec))
    last_bgp, last_scy = p.bgp, p.scy
  end
end
