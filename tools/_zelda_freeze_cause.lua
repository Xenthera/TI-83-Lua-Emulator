-- Zoom in on frame where SCX=A0 / IE loses STAT during title wave.
local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

local ppu, irq, cpu, mmu = m.ppu, m.irq, m.cpu, m.mmu
local CPF = 70224
local frame = 0
local arm = false
local logs = {}

local function log(msg)
  if not arm then return end
  logs[#logs + 1] = string.format(
    "f=%d ly=%d lc=%3d scx=%02X lyc=%02X ie=%02X if=%02X ime=%s pc=%04X sp=%04X | %s",
    frame, ppu.ly, ppu.line_cycles, ppu.scx, ppu.lyc,
    irq.ie, irq.iff, tostring(cpu.ime), cpu.pc, cpu.sp, msg)
end

-- Hook IE writes via MMU
local orig_write = mmu.write
function mmu:write(addr, v)
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)
  if arm and addr == 0xFFFF then
    log(string.format("WR IE=%02X (was %02X)", v, irq.ie))
  end
  if arm and addr == 0xFF0F then
    log(string.format("WR IF=%02X", v))
  end
  if arm and (addr == 0xFF43 or addr == 0xFF45) then
    log(string.format("WR %s=%02X", addr == 0xFF43 and "SCX" or "LYC", v))
  end
  return orig_write(self, addr, v)
end

print("warm to frame 2360...")
for _ = 1, 2360 do
  m:run_cycles(CPF)
  frame = frame + 1
end

arm = true
print("armed at frame", frame, "scx", ppu.scx, "lyc", ppu.lyc)

for i = 1, 20 do
  m:run_cycles(CPF)
  frame = frame + 1
  if ppu.scx == 0xA0 then
    print("frozen at frame", frame, "ie", irq.ie, "lyc", ppu.lyc)
    break
  end
end

-- Find SCX=A0 write and context
local idx = 1
for i = 1, #logs do
  if logs[i]:find("WR SCX=A0", 1, true) then idx = i; break end
end
local a = math.max(1, idx - 30)
local b = math.min(#logs, idx + 40)
for i = a, b do print(logs[i]) end

-- Dump stack around freeze PC
print(string.format("\nfinal pc=%04X sp=%04X ie=%02X lyc=%02X scx=%02X",
  cpu.pc, cpu.sp, irq.ie, ppu.lyc, ppu.scx))
local sp = cpu.sp
for off = 0, 15 do
  local lo = mmu:read(band(sp + off * 2, 0xFFFF))
  local hi = mmu:read(band(sp + off * 2 + 1, 0xFFFF))
  print(string.format("  [SP+%d] %04X", off * 2, lo + hi * 256))
end
