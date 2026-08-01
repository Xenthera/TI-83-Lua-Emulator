-- Run intro until title-ish screen; dump LCD regs + PPM.
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

local function dump(label)
  local p = m.ppu
  print(string.format(
    "[%s] lcdc=%02X scy=%d scx=%d wy=%d wx=%d lyc=%d bgp=%02X win=%d",
    label, p.lcdc, p.scy, p.scx, p.wy, p.wx, p.lyc, p.bgp,
    band(p.lcdc, 0x20) ~= 0 and 1 or 0
  ))
end

-- No input: intro runs itself to title
for sec = 1, 45 do
  for _ = 1, 60 do m:run_cycles(frame) end
  local p = m.ppu
  -- title often has higher SCY as beach scrolls, or settles with SCY near 0 and win off
  if sec % 5 == 0 or p.scy > 40 or (sec > 15 and p.scx == 0 and band(p.lcdc, 0x20) == 0) then
    dump(string.format("t=%ds", sec))
    ppm(string.format("rom/gb/_title_%02d.ppm", sec))
  end
end
dump("final")
ppm("rom/gb/_title_final.ppm")
print("done")
