-- Trace LYC/STAT IRQ timing vs SCX writes during Zelda title wave.
local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

local ppu, irq = m.ppu, m.irq
local CPF = 70224
local logs = {}
local frame = 0

local function log(msg)
  logs[#logs + 1] = string.format("f=%d ly=%d L=%d mode=%d lc=%d scx=%02X lyc=%02X stat=%02X | %s",
    frame, ppu.ly, ppu._line, ppu.mode, ppu.line_cycles, ppu.scx, ppu.lyc, ppu.stat, msg)
end

local orig_req = irq.request
function irq:request(mask)
  local before = self.iff or 0
  orig_req(self, mask)
  if band(mask, 0x02) ~= 0 and band(before, 0x02) == 0 then
    log(string.format("STAT_IRQ cond_lyc=%s mode=%d",
      tostring(ppu.ly == ppu.lyc), ppu.mode))
  end
end

local orig_w = ppu.write_io
function ppu:write_io(reg, v)
  if reg == 0xFF43 or reg == 0xFF45 or reg == 0xFF41 then
    local names = { [0xFF43] = "SCX", [0xFF45] = "LYC", [0xFF41] = "STAT" }
    log(string.format("WR %s=%02X", names[reg], v % 256))
  end
  return orig_w(self, reg, v)
end

-- Warm up to title scroll (~35s)
for _ = 1, 35 * 60 do
  m:run_cycles(CPF)
  frame = frame + 1
end

print(string.format("warm scx=%d lyc=%d scy=%d stat=%02X", ppu.scx, ppu.lyc, ppu.scy, ppu.stat))
logs = {}

for _ = 1, 3 do
  m:run_cycles(CPF)
  frame = frame + 1
end

for i = 1, #logs do
  print(logs[i])
end
print("total logs", #logs)
