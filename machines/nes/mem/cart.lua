-- iNES cartridge + mappers 0 (NROM), 1 (MMC1), 2 (UxROM), 3 (CNROM),
-- 4 (MMC3), 7 (AxROM / AOROM), 79 (NINA-03/06).
-- MMC3 IRQ is clocked on PPU A12 rising edges (CHR fetches / PPUADDR).

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Cart = {}
Cart.__index = Cart

function Cart.new()
  return setmetatable({
    prg = {},
    chr = {},
    prg_size = 0,
    chr_size = 0,
    mapper = 0,
    mirror = 0, -- 0=horizontal, 1=vertical, 2=single0, 3=single1, 4=four
    battery = false,
    prg_ram = {},
    title = "",
    -- banking
    prg_bank0 = 0,
    prg_bank1 = 0,
    chr_bank0 = 0,
    chr_bank1 = 0,
    -- MMC1
    mmc1_shift = 0,
    mmc1_bits = 0,
    mmc1_ctrl = 0x0C,
    mmc1_chr0 = 0,
    mmc1_chr1 = 0,
    mmc1_prg = 0,
    chr_ram = false,
    -- MMC3
    mmc3_bank = { 0, 2, 4, 5, 6, 7, 0, 1 }, -- R0..R7
    mmc3_bank_select = 0,
    mmc3_prg_mode = 0,
    mmc3_chr_mode = 0,
    mmc3_irq_latch = 0,
    mmc3_irq_counter = 0,
    mmc3_irq_enabled = false,
    mmc3_irq_reload = false,
    mmc3_a12 = 0,
    mmc3_irq_pending = false,
    cpu = nil, -- for IRQ
  }, Cart)
end

function Cart:set_cpu(cpu)
  self.cpu = cpu
end

function Cart:reset_banks()
  local banks = math.max(1, math.floor(self.prg_size / 0x4000))
  self.prg_bank0 = 0
  self.prg_bank1 = banks - 1
  self.chr_bank0 = 0
  self.chr_bank1 = 1
  self.mmc1_shift = 0
  self.mmc1_bits = 0
  self.mmc1_ctrl = 0x0C
  self.mmc1_chr0 = 0
  self.mmc1_chr1 = 0
  self.mmc1_prg = 0
  self.mmc3_bank = { 0, 2, 4, 5, 6, 7, 0, 1 }
  self.mmc3_bank_select = 0
  self.mmc3_prg_mode = 0
  self.mmc3_chr_mode = 0
  self.mmc3_irq_latch = 0
  self.mmc3_irq_counter = 0
  self.mmc3_irq_enabled = false
  self.mmc3_irq_reload = false
  self.mmc3_a12 = 0
  self.mmc3_irq_pending = false
  if self.mapper == 7 then
    -- AxROM: 32KB PRG bank 0, single-screen nametable page 0.
    self.prg_bank0 = 0
    self.mirror = 2
  end
end

function Cart:load(bytes)
  if type(bytes) ~= "string" or #bytes < 16 then
    return nil, "cart too small"
  end
  if bytes:sub(1, 4) ~= "NES\x1a" then
    return nil, "not an iNES ROM"
  end
  local b4, b5, b6, b7 = bytes:byte(5, 8)
  local prg_banks = b4
  local chr_banks = b5
  if prg_banks == 0 then prg_banks = 1 end
  local mapper = bor(rshift(b6, 4), band(b7, 0xF0))
  -- Ignore NES 2.0 for now; treat as iNES 1
  self.mapper = mapper
  self.battery = band(b6, 0x02) ~= 0
  if band(b6, 0x08) ~= 0 then
    self.mirror = 4 -- four-screen
  elseif band(b6, 0x01) ~= 0 then
    self.mirror = 1 -- vertical
  else
    self.mirror = 0 -- horizontal
  end

  local trainer = band(b6, 0x04) ~= 0 and 512 or 0
  local off = 16 + trainer
  self.prg_size = prg_banks * 0x4000
  self.chr_size = chr_banks * 0x2000
  if off + self.prg_size > #bytes then
    return nil, "truncated PRG"
  end

  local prg = {}
  for i = 0, self.prg_size - 1 do
    prg[i] = bytes:byte(off + 1 + i)
  end
  self.prg = prg
  off = off + self.prg_size

  local chr = {}
  if self.chr_size == 0 then
    self.chr_ram = true
    self.chr_size = 0x2000
    for i = 0, 0x1FFF do chr[i] = 0 end
  else
    self.chr_ram = false
    if off + self.chr_size > #bytes then
      return nil, "truncated CHR"
    end
    for i = 0, self.chr_size - 1 do
      chr[i] = bytes:byte(off + 1 + i)
    end
  end
  self.chr = chr

  for i = 0, 0x1FFF do self.prg_ram[i] = 0 end
  self.title = string.format("MAPPER%d", mapper)
  self:reset_banks()
  return true
end

function Cart:nt_mirror(addr)
  local a = band(addr, 0x0FFF)
  local table = rshift(a, 10) -- 0..3
  local off = band(a, 0x03FF)
  local m = self.mirror
  if m == 0 then -- horizontal: 0,0,1,1
    if table == 1 then table = 0
    elseif table >= 2 then table = 1 end
  elseif m == 1 then -- vertical: 0,1,0,1
    table = band(table, 1)
  elseif m == 2 then
    table = 0
  elseif m == 3 then
    table = 1
  end
  -- four-screen uses external VRAM; we map 0..3 into 2KB with wrap
  if m == 4 then
    return band(a, 0x0FFF)
  end
  return table * 0x400 + off
end

function Cart:_prg_map(addr)
  local a = band(addr, 0xFFFF)
  if a < 0x8000 then return nil end
  local banks16 = math.max(1, math.floor(self.prg_size / 0x4000))
  if self.mapper == 0 then
    if self.prg_size > 0x4000 then
      return a - 0x8000
    end
    return band(a - 0x8000, 0x3FFF)
  elseif self.mapper == 2 then -- UxROM
    if a < 0xC000 then
      return self.prg_bank0 * 0x4000 + (a - 0x8000)
    end
    return (banks16 - 1) * 0x4000 + (a - 0xC000)
  elseif self.mapper == 3 then -- CNROM
    if self.prg_size > 0x4000 then
      return a - 0x8000
    end
    return band(a - 0x8000, 0x3FFF)
  elseif self.mapper == 1 then -- MMC1
    local mode = band(rshift(self.mmc1_ctrl, 2), 3)
    local bank = self.mmc1_prg % banks16
    if mode == 0 or mode == 1 then
      bank = band(bank, 0xFE) % banks16
      return bank * 0x4000 + (a - 0x8000)
    elseif mode == 2 then
      if a < 0xC000 then return a - 0x8000 end
      return bank * 0x4000 + (a - 0xC000)
    else -- mode 3
      if a < 0xC000 then return bank * 0x4000 + (a - 0x8000) end
      return (banks16 - 1) * 0x4000 + (a - 0xC000)
    end
  elseif self.mapper == 4 then -- MMC3: 8KB PRG banks
    local n8 = math.max(1, math.floor(self.prg_size / 0x2000))
    local last = n8 - 1
    local last2 = n8 - 2
    local r6 = self.mmc3_bank[7] % n8 -- R6 (1-based table: index 7)
    local r7 = self.mmc3_bank[8] % n8
    local slot
    if a < 0xA000 then
      slot = (self.mmc3_prg_mode == 0) and r6 or last2
    elseif a < 0xC000 then
      slot = r7
    elseif a < 0xE000 then
      slot = (self.mmc3_prg_mode == 0) and last2 or r6
    else
      slot = last
    end
    return slot * 0x2000 + band(a, 0x1FFF)
  elseif self.mapper == 7 or self.mapper == 79 then
    -- AxROM / NINA-03/06: 32KB switchable PRG at $8000-$FFFF
    local banks32 = math.max(1, math.floor(self.prg_size / 0x8000))
    local bank = self.prg_bank0 % banks32
    return bank * 0x8000 + band(a, 0x7FFF)
  end
  if self.prg_size > 0x4000 then return a - 0x8000 end
  return band(a - 0x8000, 0x3FFF)
end

function Cart:cpu_read(addr)
  addr = band(addr, 0xFFFF)
  if addr >= 0x6000 and addr < 0x8000 then
    return self.prg_ram[addr - 0x6000] or 0
  end
  if addr >= 0x8000 then
    local off = self:_prg_map(addr)
    if off then return self.prg[off] or 0 end
  end
  return 0
end

function Cart:cpu_write(addr, v)
  addr = band(addr, 0xFFFF)
  v = band(v, 0xFF)

  -- NINA-03/06 (mapper 79): control reg at $4100-style addresses in $4100-$5FFF.
  if self.mapper == 79 and band(addr, 0xE100) == 0x4100 then
    -- .... PCCC : 8KB CHR + 32KB PRG
    local chr8 = math.max(1, math.floor(self.chr_size / 0x2000))
    local banks32 = math.max(1, math.floor(self.prg_size / 0x8000))
    local c = band(v, 7) % chr8
    self.chr_bank0 = c * 2
    self.chr_bank1 = self.chr_bank0 + 1
    self.prg_bank0 = band(rshift(v, 3), 1) % banks32
    return
  end

  if addr >= 0x6000 and addr < 0x8000 then
    self.prg_ram[addr - 0x6000] = v
    return
  end
  if addr < 0x8000 then return end

  if self.mapper == 2 then
    local banks = math.max(1, math.floor(self.prg_size / 0x4000))
    self.prg_bank0 = v % banks
  elseif self.mapper == 3 then
    local banks = math.max(1, math.floor(self.chr_size / 0x2000))
    self.chr_bank0 = (v % banks) * 2
    self.chr_bank1 = self.chr_bank0 + 1
  elseif self.mapper == 1 then
    self:_mmc1_write(addr, v)
  elseif self.mapper == 4 then
    self:_mmc3_write(addr, v)
  elseif self.mapper == 7 then
    -- xxxM xPPP : 32KB PRG bank + single-screen CIRAM page (bit 4).
    local banks32 = math.max(1, math.floor(self.prg_size / 0x8000))
    self.prg_bank0 = band(v, 0x0F) % banks32
    self.mirror = band(v, 0x10) ~= 0 and 3 or 2
  end
end

function Cart:_mmc3_write(addr, v)
  local reg = band(addr, 0xE001)
  if reg == 0x8000 then
    self.mmc3_bank_select = band(v, 7)
    self.mmc3_prg_mode = band(v, 0x40) ~= 0 and 1 or 0
    self.mmc3_chr_mode = band(v, 0x80) ~= 0 and 1 or 0
  elseif reg == 0x8001 then
    local r = self.mmc3_bank_select
    if r <= 1 then
      v = band(v, 0xFE) -- 2KB CHR banks even
    end
    self.mmc3_bank[r + 1] = v
  elseif reg == 0xA000 then
    -- MMC3: 0=vertical, 1=horizontal. Our mirror: 0=H, 1=V.
    self.mirror = (band(v, 1) ~= 0) and 0 or 1
  elseif reg == 0xA001 then
    -- PRG RAM protect - ignore for now
  elseif reg == 0xC000 then
    self.mmc3_irq_latch = v
  elseif reg == 0xC001 then
    self.mmc3_irq_reload = true
  elseif reg == 0xE000 then
    self.mmc3_irq_enabled = false
    self.mmc3_irq_pending = false
    if self.cpu then
      self.cpu.mapper_irq = false
      self.cpu.irq = not not self.cpu.apu_irq
    end
  elseif reg == 0xE001 then
    self.mmc3_irq_enabled = true
  end
end

--- PPU A12 rising edge clocks the MMC3 scanline IRQ counter.
function Cart:a12_update(addr)
  if self.mapper ~= 4 then return end
  local a12 = band(addr, 0x1000) ~= 0 and 1 or 0
  if a12 == 1 and self.mmc3_a12 == 0 then
    self:_mmc3_clock_irq()
  end
  self.mmc3_a12 = a12
end

function Cart:_mmc3_clock_irq()
  local c = self.mmc3_irq_counter
  if c == 0 or self.mmc3_irq_reload then
    self.mmc3_irq_counter = self.mmc3_irq_latch
    self.mmc3_irq_reload = false
  else
    self.mmc3_irq_counter = c - 1
  end
  if self.mmc3_irq_counter == 0 and self.mmc3_irq_enabled then
    self.mmc3_irq_pending = true
    if self.cpu then
      self.cpu.mapper_irq = true
      self.cpu.irq = true
    end
  end
end

function Cart:_chr_map(addr)
  addr = band(addr, 0x1FFF)
  if self.mapper ~= 4 then
    local banks = math.max(1, math.floor(self.chr_size / 0x1000))
    if addr < 0x1000 then
      return (self.chr_bank0 % banks) * 0x1000 + addr
    end
    return (self.chr_bank1 % banks) * 0x1000 + (addr - 0x1000)
  end
  -- MMC3: 1KB banks via R0..R5
  local n1k = math.max(1, math.floor(self.chr_size / 0x400))
  local b = self.mmc3_bank
  local mode = self.mmc3_chr_mode
  local bank
  if mode == 0 then
    if addr < 0x800 then
      bank = band(b[1], 0xFE) + rshift(band(addr, 0x7FF), 10)
    elseif addr < 0x1000 then
      bank = band(b[2], 0xFE) + rshift(band(addr, 0x7FF), 10)
    elseif addr < 0x1400 then bank = b[3]
    elseif addr < 0x1800 then bank = b[4]
    elseif addr < 0x1C00 then bank = b[5]
    else bank = b[6]
    end
  else
    if addr < 0x400 then bank = b[3]
    elseif addr < 0x800 then bank = b[4]
    elseif addr < 0xC00 then bank = b[5]
    elseif addr < 0x1000 then bank = b[6]
    elseif addr < 0x1800 then
      bank = band(b[1], 0xFE) + rshift(band(addr, 0x7FF), 10)
    else
      bank = band(b[2], 0xFE) + rshift(band(addr, 0x7FF), 10)
    end
  end
  return (bank % n1k) * 0x400 + band(addr, 0x3FF)
end

function Cart:_mmc1_write(addr, v)
  if band(v, 0x80) ~= 0 then
    self.mmc1_bits = 0
    self.mmc1_shift = 0
    self.mmc1_ctrl = bor(self.mmc1_ctrl, 0x0C)
    return
  end
  self.mmc1_shift = bor(rshift(self.mmc1_shift, 1), lshift(band(v, 1), 4))
  self.mmc1_bits = self.mmc1_bits + 1
  if self.mmc1_bits < 5 then return end
  local data = self.mmc1_shift
  self.mmc1_bits = 0
  self.mmc1_shift = 0
  local reg = rshift(band(addr, 0x6000), 13)
  if reg == 0 then
    self.mmc1_ctrl = data
    local mir = band(data, 3)
    if mir == 0 then self.mirror = 2
    elseif mir == 1 then self.mirror = 3
    elseif mir == 2 then self.mirror = 1
    else self.mirror = 0 end
  elseif reg == 1 then
    self.mmc1_chr0 = data
    self:_mmc1_chr()
  elseif reg == 2 then
    self.mmc1_chr1 = data
    self:_mmc1_chr()
  else
    self.mmc1_prg = band(data, 0x0F)
  end
end

function Cart:_mmc1_chr()
  local chr_banks = math.max(1, math.floor(self.chr_size / 0x1000))
  if band(self.mmc1_ctrl, 0x10) ~= 0 then
    self.chr_bank0 = self.mmc1_chr0 % chr_banks
    self.chr_bank1 = self.mmc1_chr1 % chr_banks
  else
    local b = band(self.mmc1_chr0, 0x1E) % chr_banks
    self.chr_bank0 = b
    self.chr_bank1 = b + 1
  end
end

--- CHR read without clocking MMC3 A12 (scanline renderer / peeks).
function Cart:chr_read(addr)
  addr = band(addr, 0x1FFF)
  return self.chr[self:_chr_map(addr)] or 0
end

function Cart:ppu_read(addr)
  addr = band(addr, 0x1FFF)
  self:a12_update(addr)
  return self.chr[self:_chr_map(addr)] or 0
end

function Cart:ppu_write(addr, v)
  addr = band(addr, 0x1FFF)
  self:a12_update(addr)
  if not self.chr_ram then return end
  self.chr[self:_chr_map(addr)] = band(v, 0xFF)
end

function Cart:has_save_ram()
  return self.battery
end

function Cart:export_ram()
  local parts = {}
  for i = 0, 0x1FFF do parts[i + 1] = string.char(self.prg_ram[i] or 0) end
  return table.concat(parts)
end

function Cart:import_ram(data)
  if type(data) ~= "string" then return nil, "bad save" end
  for i = 1, math.min(#data, 0x2000) do
    self.prg_ram[i - 1] = data:byte(i)
  end
  return true
end

return Cart
