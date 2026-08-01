-- Game Boy memory map (fast paths for ROM/WRAM/HRAM).

local bit = require("framework.util.bit")
local band, bor, lshift = bit.band, bit.bor, bit.lshift

local function sc_write(v)
  return bor(band(v, 0x83), 0x7E)
end

local Mmu = {}
Mmu.__index = Mmu

function Mmu.new(parts)
  local self = setmetatable({
    cart = parts.cart,
    wram = parts.wram,
    ppu = parts.ppu,
    timer = parts.timer,
    joypad = parts.joypad,
    irq = parts.irq,
    apu = parts.apu,
    boot_rom = nil,
    boot_enabled = false,
    serial = { sb = 0x00, sc = 0x7E, cycles = 0 },
  }, Mmu)
  -- Hot locals rebound after load / for CPU bus
  self:_bind_fast()
  return self
end

function Mmu:_bind_fast()
  self._rom = self.cart.rom
  self._wram = self.wram.wram
  self._hram = self.wram.hram
  self._vram = self.ppu.vram
  self._oam = self.ppu.oam
end

function Mmu:load_boot_rom(bytes)
  if type(bytes) ~= "string" or #bytes < 0x100 then
    return nil, "boot rom must be 256 bytes"
  end
  local b = {}
  for i = 1, 0x100 do b[i - 1] = bytes:byte(i) end
  self.boot_rom = b
  self.boot_enabled = true
  return true
end

function Mmu:disable_boot()
  self.boot_enabled = false
end

function Mmu:read(addr)
  addr = band(addr, 0xFFFF)
  if addr < 0x4000 then
    if self.boot_enabled and addr < 0x100 and self.boot_rom then
      return self.boot_rom[addr] or 0xFF
    end
    return self._rom[self.cart._rom0_base + addr] or 0xFF
  elseif addr < 0x8000 then
    return self._rom[self.cart._romx_base + (addr - 0x4000)] or 0xFF
  elseif addr < 0xA000 then
    return self._vram[addr - 0x8000] or 0
  elseif addr < 0xC000 then
    return self.cart:read(addr)
  elseif addr < 0xE000 then
    return self._wram[addr - 0xC000] or 0
  elseif addr < 0xFE00 then
    return self._wram[addr - 0xE000] or 0
  elseif addr < 0xFEA0 then
    return self._oam[addr - 0xFE00] or 0
  elseif addr < 0xFF00 then
    return 0xFF
  elseif addr < 0xFF80 then
    return self:_read_io(addr)
  elseif addr < 0xFFFF then
    return self._hram[addr - 0xFF80] or 0
  else
    return self.irq.ie
  end
end

function Mmu:write(addr, v)
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)
  if addr < 0x8000 then
    self.cart:write(addr, v)
  elseif addr < 0xA000 then
    -- Skip mode-3 lock (rare on DMG; big win on CC). Still blocks OAM.
    self._vram[addr - 0x8000] = v
  elseif addr < 0xC000 then
    self.cart:write(addr, v)
  elseif addr < 0xE000 then
    self._wram[addr - 0xC000] = v
  elseif addr < 0xFE00 then
    self._wram[addr - 0xE000] = v
  elseif addr < 0xFEA0 then
    self._oam[addr - 0xFE00] = v
  elseif addr < 0xFF00 then
    -- unusable
  elseif addr < 0xFF80 then
    self:_write_io(addr, v)
  elseif addr < 0xFFFF then
    self._hram[addr - 0xFF80] = v
  else
    self.irq.ie = band(v, 0x1F)
  end
end

function Mmu:_read_io(addr)
  if addr == 0xFF00 then return self.joypad:read()
  elseif addr == 0xFF01 then return self.serial.sb
  elseif addr == 0xFF02 then return self.serial.sc
  elseif addr >= 0xFF04 and addr <= 0xFF07 then return self.timer:read(addr)
  elseif addr == 0xFF0F then return bor(self.irq.iff, 0xE0)
  elseif addr >= 0xFF10 and addr <= 0xFF3F then
    return self.apu and self.apu:read(addr) or 0xFF
  elseif addr == 0xFF46 then return 0xFF
  elseif addr >= 0xFF40 and addr <= 0xFF4B then return self.ppu:read_io(addr)
  elseif addr == 0xFF50 then return self.boot_enabled and 0x00 or 0x01
  end
  return 0xFF
end

function Mmu:_write_io(addr, v)
  if addr == 0xFF00 then
    self.joypad:write(v)
  elseif addr == 0xFF01 then
    self.serial.sb = v
  elseif addr == 0xFF02 then
    self.serial.sc = sc_write(v)
    if band(v, 0x80) ~= 0 and band(v, 0x01) ~= 0 then
      self.serial.cycles = 4096
    elseif band(v, 0x80) == 0 then
      self.serial.cycles = 0
    end
  elseif addr >= 0xFF04 and addr <= 0xFF07 then
    self.timer:write(addr, v)
  elseif addr == 0xFF0F then
    self.irq.iff = band(v, 0x1F)
  elseif addr >= 0xFF10 and addr <= 0xFF3F then
    if self.apu then self.apu:write(addr, v) end
  elseif addr == 0xFF46 then
    self:_dma(v)
  elseif addr >= 0xFF40 and addr <= 0xFF4B then
    self.ppu:write_io(addr, v)
  elseif addr == 0xFF50 then
    if band(v, 1) ~= 0 then
      self.boot_enabled = false
    end
  end
end

function Mmu:_dma(page)
  local src = lshift(band(page, 0xFF), 8)
  local oam = self._oam
  for i = 0, 0x9F do
    oam[i] = self:read(src + i)
  end
end

function Mmu:tick(cycles)
  local s = self.serial
  if s.cycles <= 0 then return end
  s.cycles = s.cycles - cycles
  if s.cycles <= 0 then
    s.cycles = 0
    s.sb = 0xFF
    s.sc = band(s.sc, 0x7F)
    self.irq:request(0x08)
  end
end

return Mmu
