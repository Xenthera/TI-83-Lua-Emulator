-- Inspect code path that kills title LYC (PC=7615).
local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band, bor, rshift = bit.band, bit.bor, bit.rshift

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

local ppu, irq, cpu, mmu, cart = m.ppu, m.irq, m.cpu, m.mmu, m.cart
local CPF = 70224

-- Run until SCX=A0 write from PC near 7615
local hit = false
local orig_write = mmu.write
function mmu:write(addr, v)
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)
  if not hit and addr == 0xFF43 and v == 0xA0 and cpu.pc >= 0x7600 and cpu.pc < 0x7700 then
    hit = true
    print(string.format("HIT pc=%04X bank=%d ly=%d scx=%02X->A0 ie=%02X",
      cpu.pc, cart.rom_bank or -1, ppu.ly, ppu.scx, irq.ie))
    print(string.format("regs AF=%04X BC=%04X DE=%04X HL=%04X SP=%04X",
      cpu:af(), cpu:bc(), cpu:de(), cpu:hl(), cpu.sp))
    -- dump stack return addresses
    for off = 0, 7 do
      local a = band(cpu.sp + off * 2, 0xFFFF)
      local ret = mmu:read(a) + mmu:read(band(a + 1, 0xFFFF)) * 256
      print(string.format("  stack[%d]=%04X", off, ret))
    end
    -- dump code bytes around PC
    local b = {}
    for i = -16, 32 do
      b[#b + 1] = string.format("%02X", mmu:read(band(cpu.pc + i, 0xFFFF)))
    end
    print("bytes:", table.concat(b, " "))
    -- WRAM game-state nibbles often used by LA
    local addrs = { 0xDB95, 0xDB96, 0xDB97, 0xDB98, 0xDB99, 0xDB9A, 0xFFD1, 0xFFD2, 0xFFD3, 0xFFE7, 0xFFE8 }
    for _, a in ipairs(addrs) do
      print(string.format("  [%04X]=%02X", a, mmu:read(a)))
    end
  end
  return orig_write(self, addr, v)
end

for f = 1, 40 * 60 do
  m:run_cycles(CPF)
  if hit then
    print("hit at frame", f)
    -- continue a few frames
    for _ = 1, 5 do m:run_cycles(CPF) end
    print(string.format("after: scx=%02X lyc=%02X ie=%02X lcdc=%02X bgp=%02X",
      ppu.scx, ppu.lyc, irq.ie, ppu.lcdc, ppu.bgp))
    break
  end
end
if not hit then print("never hit") end
