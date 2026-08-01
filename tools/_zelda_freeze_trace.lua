-- Trace exact moment title LYC chain freezes (SCX stuck at A0 / LYC=48).
local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

local ppu, irq, cpu = m.ppu, m.irq, m.cpu
local CPF = 70224
local frame = 0
local logging = false
local logs = {}

local function log(msg)
  if not logging then return end
  logs[#logs + 1] = string.format(
    "f=%d ly=%d L=%d m=%d lc=%3d scx=%02X lyc=%02X ie=%02X if=%02X ime=%s halt=%s pc=%04X | %s",
    frame, ppu.ly, ppu._line, ppu.mode, ppu.line_cycles, ppu.scx, ppu.lyc,
    irq.ie, irq.iff, tostring(cpu.ime), tostring(cpu.halted), cpu.pc, msg)
end

local orig_req = irq.request
function irq:request(mask)
  local before = self.iff or 0
  orig_req(self, mask)
  if band(mask, 0x02) ~= 0 and band(before, 0x02) == 0 then
    log("STAT_IRQ")
  end
  if band(mask, 0x01) ~= 0 and band(before, 0x01) == 0 then
    log("VBLANK_IRQ")
  end
end

local orig_w = ppu.write_io
function ppu:write_io(reg, v)
  if logging and (reg == 0xFF43 or reg == 0xFF45 or reg == 0xFF41 or reg == 0xFF40) then
    local n = ({ [0xFF43] = "SCX", [0xFF45] = "LYC", [0xFF41] = "STAT", [0xFF40] = "LCDC" })[reg]
    log(string.format("WR %s=%02X", n, v % 256))
  end
  return orig_w(self, reg, v)
end

print("warm to 37s...")
for _ = 1, 37 * 60 do
  m:run_cycles(CPF)
  frame = frame + 1
end

logging = true
print("logging from t=37s...")
for i = 1, 150 do
  m:run_cycles(CPF)
  frame = frame + 1
  if i % 30 == 0 or (ppu.lyc == 48 and ppu.scx == 0xA0) then
    print(string.format("frame+%d scx=%02X lyc=%02X scy=%d logs=%d", i, ppu.scx, ppu.lyc, ppu.scy, #logs))
  end
  if ppu.lyc == 48 and ppu.scx == 0xA0 and i > 60 then
    break
  end
end

-- print last 80 logs before freeze and first after
local start = math.max(1, #logs - 120)
for i = start, #logs do
  print(logs[i])
end
print("done logs", #logs, "scx", ppu.scx, "lyc", ppu.lyc)
