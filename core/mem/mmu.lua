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
  return self
end

function Mmu:reset()
  self.page_boot = 0
  self.page_bankA = 0
  self.page_bankB = 0
  self.bankA_is_ram = false
  self.bankB_is_ram = false
  self.mem_mode = 0
  self.flash_unlocked = false
end

function Mmu:set_mem_mode(mode)
  self.mem_mode = band(mode, 1)
end

function Mmu:set_bankA(value)
  -- Port 06: bits 0-4 flash page; bit 6 = map RAM (83+ basic)
  self.bankA_is_ram = band(value, 0x40) ~= 0
  if self.bankA_is_ram then
    self.page_bankA = band(value, 0x01)
  else
    self.page_bankA = band(value, 0x1F)
  end
end

function Mmu:set_bankB(value)
  -- Port 07: same scheme as port 06 on 83+ basic
  self.bankB_is_ram = band(value, 0x40) ~= 0
  if self.bankB_is_ram then
    self.page_bankB = band(value, 0x01)
  else
    self.page_bankB = band(value, 0x1F)
  end
end

function Mmu:set_boot_page(page)
  self.page_boot = band(page, 0x1F)
end

local function read_bank(self, is_ram, page, offset)
  if is_ram then
    return self.ram:read(page, offset)
  end
  return self.flash:read(page, offset)
end

local function write_bank(self, is_ram, page, offset, value)
  if is_ram then
    self.ram:write(page, offset, value)
  elseif self.flash_unlocked then
    self.flash:write(page, offset, value)
  end
end

function Mmu:read(addr)
  addr = band(addr, 0xFFFF)
  local region = band(addr, 0xC000)
  local offset = band(addr, 0x3FFF)

  if self.mem_mode == 0 then
    if region == 0x0000 then
      return self.flash:read(self.page_boot, offset)
    elseif region == 0x4000 then
      return read_bank(self, self.bankA_is_ram, self.page_bankA, offset)
    elseif region == 0x8000 then
      return read_bank(self, self.bankB_is_ram, self.page_bankB, offset)
    else -- 0xC000
      return self.ram:read(0, offset)
    end
  end

  -- Mode 1 (boot): Bank A mirrored across 4000 and 8000
  if region == 0x0000 then
    return self.flash:read(self.page_boot, offset)
  elseif region == 0x4000 then
    local page = self.bankA_is_ram and self.page_bankA or band(self.page_bankA, 0x1E)
    return read_bank(self, self.bankA_is_ram, page, offset)
  elseif region == 0x8000 then
    return read_bank(self, self.bankA_is_ram, self.page_bankA, offset)
  else -- 0xC000 = Bank B
    return read_bank(self, self.bankB_is_ram, self.page_bankB, offset)
  end
end

function Mmu:write(addr, value)
  addr = band(addr, 0xFFFF)
  value = band(value, 0xFF)
  local region = band(addr, 0xC000)
  local offset = band(addr, 0x3FFF)

  if self.mem_mode == 0 then
    if region == 0x0000 then
      if self.flash_unlocked then
        self.flash:write(self.page_boot, offset, value)
      end
    elseif region == 0x4000 then
      write_bank(self, self.bankA_is_ram, self.page_bankA, offset, value)
    elseif region == 0x8000 then
      write_bank(self, self.bankB_is_ram, self.page_bankB, offset, value)
    else
      self.ram:write(0, offset, value)
    end
    return
  end

  if region == 0x0000 then
    if self.flash_unlocked then
      self.flash:write(self.page_boot, offset, value)
    end
  elseif region == 0x4000 then
    local page = self.bankA_is_ram and self.page_bankA or band(self.page_bankA, 0x1E)
    write_bank(self, self.bankA_is_ram, page, offset, value)
  elseif region == 0x8000 then
    write_bank(self, self.bankA_is_ram, self.page_bankA, offset, value)
  else
    write_bank(self, self.bankB_is_ram, self.page_bankB, offset, value)
  end
end

return Mmu
