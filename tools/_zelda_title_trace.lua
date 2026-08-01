-- Trace SCX/LYC/LCDC around the title transition (~15-25s).
package.path = "./?.lua;./?/init.lua;" .. package.path
local M = require("machines.gameboy.machine")

local m = M.new()
assert(m:load_rom_file("rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"))
m:reset()
local frame = 154 * 456
for _ = 1, 60 * 14 do m:run_cycles(frame) end

local log = {}
local ppu = m.ppu
local old = ppu.write_io
function ppu:write_io(reg, v)
  if reg == 0xFF40 or reg == 0xFF42 or reg == 0xFF43 or reg == 0xFF45 or reg == 0xFF47 then
    log[#log + 1] = {
      reg = reg, v = v % 256, ly = self.ly, mode = self.mode,
      scx = self.scx, scy = self.scy, lyc = self.lyc, lcdc = self.lcdc,
    }
  end
  return old(self, reg, v)
end

-- Capture ~3 seconds through transition
for fi = 1, 60 * 8 do
  log = {}
  m:run_cycles(frame)
  if #log > 0 and (fi % 30 == 0 or #log > 8) then
    print(string.format("--- frame +%d writes=%d scx=%d scy=%d lyc=%d bgp=%02X ---",
      fi, #log, ppu.scx, ppu.scy, ppu.lyc, ppu.bgp))
    for i = 1, math.min(12, #log) do
      local e = log[i]
      local name = ({
        [0xFF40]="LCDC",[0xFF42]="SCY",[0xFF43]="SCX",
        [0xFF45]="LYC",[0xFF47]="BGP",
      })[e.reg]
      print(string.format("  %s=%02X ly=%d mode=%d (scx=%d scy=%d lyc=%d)",
        name, e.v, e.ly, e.mode, e.scx, e.scy, e.lyc))
    end
  end
end
print(string.format("end scx=%d scy=%d lyc=%d lcdc=%02X bgp=%02X",
  ppu.scx, ppu.scy, ppu.lyc, ppu.lcdc, ppu.bgp))
