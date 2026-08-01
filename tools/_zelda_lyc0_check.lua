-- Verify LY=153 quirk fires LYC=0 during VBlank, and dump title after Start.
package.path = "./?.lua;./?/init.lua;" .. package.path
local M = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local m = M.new()
assert(m:load_rom_file("rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"))
m:reset()
local frame = 154 * 456

-- Warm up into intro LYC chain
for _ = 1, 60 * 3 do m:run_cycles(frame) end

local lyc0 = 0
local old_req = m.irq.request
function m.irq:request(mask)
  if band(mask, 0x02) ~= 0 and m.ppu.lyc == 0 and m.ppu.ly == 0 then
    lyc0 = lyc0 + 1
    if lyc0 <= 8 then
      print(string.format(
        "LYC0 IRQ #%d  _line=%d ly=%d lc=%d mode=%d scx=%d",
        lyc0, m.ppu._line, m.ppu.ly, m.ppu.line_cycles, m.ppu.mode, m.ppu.scx
      ))
    end
  end
  return old_req(self, mask)
end

for _ = 1, 60 * 2 do m:run_cycles(frame) end
print("LYC=0 IRQs in 2s:", lyc0)

-- Run to ~25s, mash start for title
for _ = 1, 60 * 20 do m:run_cycles(frame) end
for _ = 1, 10 do
  m:set_key("start", true)
  for _i = 1, 3 do m:run_cycles(frame) end
  m:set_key("start", false)
  for _i = 1, 40 do m:run_cycles(frame) end
end
for _ = 1, 60 * 5 do m:run_cycles(frame) end

local p = m.ppu
print(string.format(
  "after start: lcdc=%02X scx=%d scy=%d lyc=%d bgp=%02X _line=%d",
  p.lcdc, p.scx, p.scy, p.lyc, p.bgp, p._line
))

local f = assert(io.open("rom/gb/_title_menu.ppm", "wb"))
f:write("P6\n160 144\n255\n")
local S = { [0] = {224,248,208}, {136,192,112}, {52,104,86}, {8,24,32} }
for i = 0, 160 * 144 - 1 do
  local s = p.fb[i] or 0
  if s < 0 then s = 0 elseif s > 3 then s = 3 end
  local c = S[s]
  f:write(string.char(c[1], c[2], c[3]))
end
f:close()
print("wrote rom/gb/_title_menu.ppm")
