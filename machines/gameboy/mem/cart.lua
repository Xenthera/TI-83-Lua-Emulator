-- Game Boy cartridge ROM + MBC0 / MBC1 / MBC3 banking.

local bit = require("framework.util.bit")
local band, bor, lshift = bit.band, bit.bor, bit.lshift

local Cart = {}
Cart.__index = Cart

function Cart.new()
  return setmetatable({
    rom = {},
    rom_size = 0,
    ram = {},
    ram_size = 0,
    mbc = 0, -- 0=none, 1=MBC1, 3=MBC3
    rom_bank = 1,
    ram_bank = 0, -- MBC1: 2-bit; MBC3: RAM 0-3 or RTC reg 0x08-0x0C
    ram_enable = false,
    mode = 0, -- MBC1 banking mode only
    rtc = { s = 0, m = 0, h = 0, dl = 0, dh = 0 },
    rtc_latch = 0,
    title = "",
    cart_type = 0,
    _banks = 1,
    _rom0_base = 0,
    _romx_base = 0x4000,
  }, Cart)
end

function Cart:reset_banks()
  self.rom_bank = 1
  self.ram_bank = 0
  self.ram_enable = false
  self.mode = 0
  self.rtc_latch = 0
  self:_recalc()
end

function Cart:_recalc()
  local banks = math.max(1, math.floor(self.rom_size / 0x4000))
  self._banks = banks

  if self.mbc == 3 then
    local bank = band(self.rom_bank, 0x7F)
    if bank == 0 then bank = 1 end
    self._romx_base = (bank % banks) * 0x4000
    self._rom0_base = 0
    return
  end

  -- MBC1 (and ROM-only uses bank 1 / base 0)
  local bank = band(self.rom_bank, 0x1F)
  if bank == 0 then bank = 1 end
  if self.mbc == 1 then
    bank = bor(bank, lshift(self.ram_bank % 4, 5))
  end
  bank = bank % banks
  self._romx_base = bank * 0x4000
  if self.mbc == 1 and self.mode == 1 then
    self._rom0_base = (((self.ram_bank % 4) * 0x20) % banks) * 0x4000
  else
    self._rom0_base = 0
  end
end

function Cart:load(bytes)
  if type(bytes) ~= "string" or #bytes < 0x150 then
    return nil, "cart too small"
  end
  local rom = {}
  for i = 1, #bytes do
    rom[i - 1] = bytes:byte(i)
  end
  local size = #bytes
  if size < 0x8000 then
    for i = size, 0x7FFF do rom[i] = 0xFF end
    size = 0x8000
  end
  self.rom = rom
  self.rom_size = size

  local cart_type = rom[0x0147] or 0
  self.cart_type = cart_type
  if cart_type == 0x00 then
    self.mbc = 0
  elseif cart_type >= 0x01 and cart_type <= 0x03 then
    self.mbc = 1
  elseif cart_type >= 0x0F and cart_type <= 0x13 then
    self.mbc = 3
  elseif cart_type >= 0x19 and cart_type <= 0x1E then
    -- MBC5 not implemented; 7-bit ROM bank is close enough for many titles
    self.mbc = 3
  else
    -- Unknown: prefer MBC3-style 7-bit ROM bank (safe for >512KB carts)
    self.mbc = (size > 0x80000) and 3 or 1
  end

  local ram_code = rom[0x0149] or 0
  local ram_sizes = { [0] = 0, [1] = 2048, [2] = 8192, [3] = 32768, [4] = 131072, [5] = 65536 }
  self.ram_size = ram_sizes[ram_code] or 0
  -- MBC3 with battery often reports RAM; ensure at least one bank if type implies RAM
  if self.ram_size == 0 and (cart_type == 0x10 or cart_type == 0x12 or cart_type == 0x13) then
    self.ram_size = 8192
  end
  self.ram = {}
  for i = 0, math.max(self.ram_size, 1) - 1 do
    self.ram[i] = 0
  end

  local t = {}
  for i = 0x0134, 0x0143 do
    local c = rom[i] or 0
    if c == 0 then break end
    if c >= 32 and c < 127 then t[#t + 1] = string.char(c) end
  end
  self.title = table.concat(t)
  self:reset_banks()
  return true
end

-- Cartridge types with battery-backed RAM (and/or RTC).
local BATTERY_TYPES = {
  [0x03] = true, -- MBC1+RAM+BATTERY
  [0x06] = true, -- MBC2+BATTERY
  [0x09] = true, -- ROM+RAM+BATTERY
  [0x0F] = true, -- MBC3+TIMER+BATTERY
  [0x10] = true, -- MBC3+TIMER+RAM+BATTERY
  [0x13] = true, -- MBC3+RAM+BATTERY
  [0x1B] = true, -- MBC5+RAM+BATTERY
  [0x1E] = true, -- MBC5+RUMBLE+RAM+BATTERY
}

--- True when the cart header exposes external RAM worth persisting.
function Cart:has_save_ram()
  return (self.ram_size or 0) > 0
end

function Cart:has_battery()
  return not not BATTERY_TYPES[self.cart_type or 0]
end

--- Pack cartridge SRAM into a binary string (emulator .sav body).
function Cart:export_ram()
  local n = self.ram_size or 0
  if n <= 0 then return "" end
  local parts = {}
  local ram = self.ram
  for i = 0, n - 1 do
    parts[i + 1] = string.char(ram[i] or 0)
  end
  return table.concat(parts)
end

--- Load cartridge SRAM from a binary string (truncates/pads to ram_size).
function Cart:import_ram(data)
  local n = self.ram_size or 0
  if n <= 0 then
    return nil, "cart has no external RAM"
  end
  if type(data) ~= "string" then
    return nil, "save data must be a string"
  end
  local ram = self.ram
  local copy = #data
  if copy > n then copy = n end
  for i = 1, copy do
    ram[i - 1] = data:byte(i)
  end
  return true
end

function Cart:_ram_offset(addr)
  local off = addr - 0xA000
  if self.mbc == 3 then
    local rb = self.ram_bank
    if rb <= 3 then
      off = off + rb * 0x2000
    else
      return nil -- RTC mapped
    end
  elseif self.mbc == 1 then
    if self.mode == 1 then
      off = off + (self.ram_bank % 4) * 0x2000
    end
  end
  if off < 0 or off >= self.ram_size then return nil end
  return off
end

function Cart:_read_rtc()
  local r = self.rtc
  local reg = self.ram_bank
  if reg == 0x08 then return r.s
  elseif reg == 0x09 then return r.m
  elseif reg == 0x0A then return r.h
  elseif reg == 0x0B then return r.dl
  elseif reg == 0x0C then return r.dh
  end
  return 0xFF
end

function Cart:_write_rtc(v)
  local r = self.rtc
  local reg = self.ram_bank
  v = band(v, 0xFF)
  if reg == 0x08 then r.s = band(v, 0x3F)
  elseif reg == 0x09 then r.m = band(v, 0x3F)
  elseif reg == 0x0A then r.h = band(v, 0x1F)
  elseif reg == 0x0B then r.dl = v
  elseif reg == 0x0C then r.dh = band(v, 0xC1)
  end
end

function Cart:read(addr)
  if addr < 0x4000 then
    return self.rom[self._rom0_base + addr] or 0xFF
  elseif addr < 0x8000 then
    return self.rom[self._romx_base + (addr - 0x4000)] or 0xFF
  elseif addr < 0xC000 then
    if not self.ram_enable then return 0xFF end
    if self.mbc == 3 and self.ram_bank >= 0x08 then
      return self:_read_rtc()
    end
    if self.ram_size == 0 then return 0xFF end
    local off = self:_ram_offset(addr)
    if off == nil then return 0xFF end
    return self.ram[off] or 0xFF
  end
  return 0xFF
end

function Cart:write(addr, v)
  if self.mbc == 0 then return end
  v = band(v, 0xFF)

  if addr < 0x2000 then
    self.ram_enable = band(v, 0x0F) == 0x0A
    return
  end

  if addr < 0x4000 then
    if self.mbc == 3 then
      local bank = band(v, 0x7F)
      if bank == 0 then bank = 1 end
      self.rom_bank = bank
    else
      local bank = band(v, 0x1F)
      if bank == 0 then bank = 1 end
      self.rom_bank = bank
    end
    self:_recalc()
    return
  end

  if addr < 0x6000 then
    if self.mbc == 3 then
      self.ram_bank = v -- 0-3 RAM, 08-0C RTC
    else
      self.ram_bank = band(v, 0x03)
      self:_recalc()
    end
    return
  end

  if addr < 0x8000 then
    if self.mbc == 3 then
      -- RTC latch: 0 then 1. Stub - keep frozen zeros.
      self.rtc_latch = v
    else
      self.mode = band(v, 0x01)
      self:_recalc()
    end
    return
  end

  if addr >= 0xA000 and addr < 0xC000 then
    if not self.ram_enable then return end
    if self.mbc == 3 and self.ram_bank >= 0x08 then
      self:_write_rtc(v)
      return
    end
    if self.ram_size == 0 then return end
    local off = self:_ram_offset(addr)
    if off ~= nil then
      self.ram[off] = v
    end
  end
end

return Cart
