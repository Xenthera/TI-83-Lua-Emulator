-- TI-84 Plus (SE-class) 16KB banked memory map.
--
-- Memory map mode 0 (port 04 bit0 = 0):
--   0000-3FFF: flash page 0 (fixed)
--   4000-7FFF: Bank A (port 06: flash 00-3F, or RAM with bit7)
--   8000-BFFF: Bank B (port 07)
--   C000-FFFF: RAM page from port 05 (00-07)
--
-- Mode 1 (boot): same pairing idea as TI-83+, with 64-page flash masks.

local bit = require("framework.util.bit")
local band = bit.band

local PAGE_SIZE = 0x4000
local FLASH_MASK = 0x3F
local RAM_MASK = 0x07

local Mmu = {}
Mmu.__index = Mmu

function Mmu.new(flash, ram)
  local self = setmetatable({}, Mmu)
  self.flash = flash
  self.ram = ram
  self.page_boot = 0
  self.page_bankA = 0
  self.page_bankB = 0
  self.bankA_is_ram = false
  self.bankB_is_ram = false
  self.ram_page = 0
  self.mem_mode = 0
  self.flash_unlocked = false
  self.r0_arr, self.r0_base = flash.bytes, 0
  self.r1_arr, self.r1_base = flash.bytes, 0
  self.r2_arr, self.r2_base = flash.bytes, 0
  self.r3_arr, self.r3_base = ram.bytes, 0
  self.w1_arr, self.w1_base, self.w1_ok = flash.bytes, 0, false
  self.w2_arr, self.w2_base, self.w2_ok = flash.bytes, 0, false
  self.w3_arr, self.w3_base, self.w3_ok = ram.bytes, 0, true
  self:_rebuild_map()
  return self
end

function Mmu:_rebuild_map()
  local fb = self.flash.bytes
  local rb = self.ram.bytes
  local PS = PAGE_SIZE
  local ram_pages = self.ram.NUM_PAGES or 8

  self.r0_arr = fb
  self.r0_base = band(self.page_boot, FLASH_MASK) * PS

  if self.mem_mode == 0 then
    if self.bankA_is_ram then
      self.r1_arr = rb
      self.r1_base = (self.page_bankA % ram_pages) * PS
      self.w1_arr = rb
      self.w1_base = self.r1_base
      self.w1_ok = true
    else
      self.r1_arr = fb
      self.r1_base = band(self.page_bankA, FLASH_MASK) * PS
      self.w1_ok = false
    end
    if self.bankB_is_ram then
      self.r2_arr = rb
      self.r2_base = (self.page_bankB % ram_pages) * PS
      self.w2_arr = rb
      self.w2_base = self.r2_base
      self.w2_ok = true
    else
      self.r2_arr = fb
      self.r2_base = band(self.page_bankB, FLASH_MASK) * PS
      self.w2_ok = false
    end
    self.r3_arr = rb
    self.r3_base = (band(self.ram_page, RAM_MASK) % ram_pages) * PS
    self.w3_arr = rb
    self.w3_base = self.r3_base
    self.w3_ok = true
  else
    if self.bankA_is_ram then
      self.r1_arr = rb
      self.r1_base = (self.page_bankA % ram_pages) * PS
      self.w1_arr = rb
      self.w1_base = self.r1_base
      self.w1_ok = true
      self.r2_arr = rb
      self.r2_base = self.r1_base
      self.w2_arr = rb
      self.w2_base = self.r1_base
      self.w2_ok = true
    else
      local even = band(self.page_bankA, 0x3E)
      self.r1_arr = fb
      self.r1_base = even * PS
      self.w1_ok = false
      self.r2_arr = fb
      self.r2_base = band(self.page_bankA, FLASH_MASK) * PS
      self.w2_ok = false
    end
    if self.bankB_is_ram then
      self.r3_arr = rb
      self.r3_base = (self.page_bankB % ram_pages) * PS
      self.w3_arr = rb
      self.w3_base = self.r3_base
      self.w3_ok = true
    else
      self.r3_arr = fb
      self.r3_base = band(self.page_bankB, FLASH_MASK) * PS
      self.w3_ok = false
    end
  end
end

function Mmu:reset()
  self.page_boot = 0
  self.page_bankA = 0
  self.page_bankB = 0
  self.bankA_is_ram = false
  self.bankB_is_ram = false
  self.ram_page = 0
  self.mem_mode = 0
  self.flash_unlocked = false
  if self.flash.reset_cmd then
    self.flash:reset_cmd()
  end
  self:_rebuild_map()
end

function Mmu:_flash_at(addr)
  local off = band(addr, 0x3FFF)
  local region = band(addr, 0xC000)
  if region == 0x0000 then
    return band(self.page_boot, FLASH_MASK), off
  elseif region == 0x4000 then
    if self.bankA_is_ram then return nil end
    if self.mem_mode == 1 then
      return band(self.page_bankA, 0x3E), off
    end
    return band(self.page_bankA, FLASH_MASK), off
  elseif region == 0x8000 then
    if self.mem_mode == 0 then
      if self.bankB_is_ram then return nil end
      return band(self.page_bankB, FLASH_MASK), off
    end
    if self.bankA_is_ram then return nil end
    return band(self.page_bankA, FLASH_MASK), off
  else
    if self.mem_mode == 0 then return nil end
    if self.bankB_is_ram then return nil end
    return band(self.page_bankB, FLASH_MASK), off
  end
end

function Mmu:set_mem_mode(mode)
  self.mem_mode = band(mode, 1)
  self:_rebuild_map()
end

function Mmu:set_ram_page(page)
  self.ram_page = band(page, RAM_MASK)
  self:_rebuild_map()
end

function Mmu:set_bankA(value)
  -- SE/84+: bit7 = RAM (not bit6 as on plain 83+)
  self.bankA_is_ram = band(value, 0x80) ~= 0
  if self.bankA_is_ram then
    self.page_bankA = band(value, RAM_MASK)
  else
    self.page_bankA = band(value, FLASH_MASK)
  end
  self:_rebuild_map()
end

function Mmu:set_bankB(value)
  self.bankB_is_ram = band(value, 0x80) ~= 0
  if self.bankB_is_ram then
    self.page_bankB = band(value, RAM_MASK)
  else
    self.page_bankB = band(value, FLASH_MASK)
  end
  self:_rebuild_map()
end

function Mmu:set_boot_page(page)
  self.page_boot = band(page, FLASH_MASK)
  self:_rebuild_map()
end

function Mmu:read(addr)
  local flash = self.flash
  if flash.override_reads then
    local page, off = self:_flash_at(addr)
    if page then
      return flash:cmd_read(page, off)
    end
  end
  local off = band(addr, 0x3FFF)
  local region = band(addr, 0xC000)
  if region == 0x0000 then
    return self.r0_arr[self.r0_base + off]
  elseif region == 0x4000 then
    return self.r1_arr[self.r1_base + off]
  elseif region == 0x8000 then
    return self.r2_arr[self.r2_base + off]
  else
    return self.r3_arr[self.r3_base + off]
  end
end

function Mmu:write(addr, value)
  value = band(value, 0xFF)
  local off = band(addr, 0x3FFF)
  local region = band(addr, 0xC000)
  if region == 0x0000 then
    if self.flash_unlocked then
      self.flash:write(band(self.page_boot, FLASH_MASK), off, value)
    end
    return
  elseif region == 0x4000 then
    if self.w1_ok then
      self.w1_arr[self.w1_base + off] = value
    elseif self.flash_unlocked then
      local page = self:_flash_at(addr)
      if page then
        self.flash:write(page, off, value)
      end
    end
  elseif region == 0x8000 then
    if self.w2_ok then
      self.w2_arr[self.w2_base + off] = value
    elseif self.flash_unlocked then
      local page = self:_flash_at(addr)
      if page then
        self.flash:write(page, off, value)
      end
    end
  else
    if self.w3_ok then
      self.w3_arr[self.w3_base + off] = value
    elseif self.flash_unlocked then
      local page = self:_flash_at(addr)
      if page then
        self.flash:write(page, off, value)
      end
    end
  end
end

return Mmu
