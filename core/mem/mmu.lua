-- TI-83 Plus 16KB banked memory map (non-SE).
--
-- Memory map mode 0 (port 04 bit0 = 0), normal OS operation:
--   0000-3FFF: flash page 0 (fixed)
--   4000-7FFF: Bank A (port 06: flash 00-1F, or RAM with bit6)
--   8000-BFFF: Bank B (port 07: flash 00-1F, or RAM with bit6)
--   C000-FFFF: RAM page 0 (fixed)
--
-- Memory map mode 1 (port 04 bit0 = 1), used briefly at boot:
--   0000-3FFF: flash page 0
--   4000-7FFF: Bank A even page (port 06 & ~1)
--   8000-BFFF: Bank A (port 06)          -- boot code JP 80D5 lands here
--   C000-FFFF: Bank B (port 07)

local bit = require("core.util.bit")
local band, bor = bit.band, bit.bor

local PAGE_SIZE = 0x4000

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
  self.mem_mode = 0
  self.flash_unlocked = false
  -- Cached region maps: arr[base + offset] for offset in 0..3FFF
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

  self.r0_arr = fb
  self.r0_base = self.page_boot * PS

  if self.mem_mode == 0 then
    if self.bankA_is_ram then
      self.r1_arr = rb
      self.r1_base = self.page_bankA * PS
      self.w1_arr = rb
      self.w1_base = self.r1_base
      self.w1_ok = true
    else
      self.r1_arr = fb
      self.r1_base = self.page_bankA * PS
      self.w1_ok = false
    end
    if self.bankB_is_ram then
      self.r2_arr = rb
      self.r2_base = self.page_bankB * PS
      self.w2_arr = rb
      self.w2_base = self.r2_base
      self.w2_ok = true
    else
      self.r2_arr = fb
      self.r2_base = self.page_bankB * PS
      self.w2_ok = false
    end
    self.r3_arr = rb
    self.r3_base = 0
    self.w3_arr = rb
    self.w3_base = 0
    self.w3_ok = true
  else
    -- Mode 1 (boot)
    if self.bankA_is_ram then
      self.r1_arr = rb
      self.r1_base = self.page_bankA * PS
      self.w1_arr = rb
      self.w1_base = self.r1_base
      self.w1_ok = true
      self.r2_arr = rb
      self.r2_base = self.page_bankA * PS
      self.w2_arr = rb
      self.w2_base = self.r2_base
      self.w2_ok = true
    else
      local even = band(self.page_bankA, 0x1E)
      self.r1_arr = fb
      self.r1_base = even * PS
      self.w1_ok = false
      self.r2_arr = fb
      self.r2_base = self.page_bankA * PS
      self.w2_ok = false
    end
    if self.bankB_is_ram then
      self.r3_arr = rb
      self.r3_base = self.page_bankB * PS
      self.w3_arr = rb
      self.w3_base = self.r3_base
      self.w3_ok = true
    else
      self.r3_arr = fb
      self.r3_base = self.page_bankB * PS
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
  self.mem_mode = 0
  self.flash_unlocked = false
  self:_rebuild_map()
end

function Mmu:set_mem_mode(mode)
  self.mem_mode = band(mode, 1)
  self:_rebuild_map()
end

function Mmu:set_bankA(value)
  self.bankA_is_ram = band(value, 0x40) ~= 0
  if self.bankA_is_ram then
    self.page_bankA = band(value, 0x01)
  else
    self.page_bankA = band(value, 0x1F)
  end
  self:_rebuild_map()
end

function Mmu:set_bankB(value)
  self.bankB_is_ram = band(value, 0x40) ~= 0
  if self.bankB_is_ram then
    self.page_bankB = band(value, 0x01)
  else
    self.page_bankB = band(value, 0x1F)
  end
  self:_rebuild_map()
end

function Mmu:set_boot_page(page)
  self.page_boot = band(page, 0x1F)
  self:_rebuild_map()
end

function Mmu:read(addr)
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
    -- Flash page (boot): ignore unless unlocked (still a no-op today).
    return
  elseif region == 0x4000 then
    if self.w1_ok then
      self.w1_arr[self.w1_base + off] = value
    end
  elseif region == 0x8000 then
    if self.w2_ok then
      self.w2_arr[self.w2_base + off] = value
    end
  else
    if self.w3_ok then
      self.w3_arr[self.w3_base + off] = value
    end
  end
end

return Mmu
