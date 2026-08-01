-- Trace when LYC/SCX freeze during title scroll-up.
package.path = "./?.lua;./?/init.lua;" .. package.path
local M = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local m = M.new()
assert(m:load_rom_file("rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"))
m:reset()
local frame = 154 * 456

-- Skip to ~35s
for _ = 1, 60 * 35 do m:run_cycles(frame) end
print(string.format("at 35s scx=%d lyc=%d scy=%d", m.ppu.scx, m.ppu.lyc, m.ppu.scy))

local ppu = m.ppu
local old = ppu.write_io
local frame_i = 0
function ppu:write_io(reg, v)
  if reg == 0xFF43 or reg == 0xFF45 or reg == 0xFF42 then
    local name = ({ [0xFF43] = "SCX", [0xFF45] = "LYC", [0xFF42] = "SCY" })[reg]
    -- print first frames after 35s heavily
    if frame_i < 120 then
      print(string.format(
        "f+%d %s=%02X ly=%d _line=%d mode=%d lc=%d (scx=%d lyc=%d scy=%d)",
        frame_i, name, v % 256, self.ly, self._line, self.mode, self.line_cycles,
        self.scx, self.lyc, self.scy
      ))
    end
  end
  return old(self, reg, v)
end

for fi = 1, 60 * 10 do
  frame_i = fi
  m:run_cycles(frame)
  if fi % 60 == 0 then
    print(string.format(
      "== sec+%d scx=%d lyc=%d scy=%d ==",
      fi / 60, ppu.scx, ppu.lyc, ppu.scy
    ))
  end
end
