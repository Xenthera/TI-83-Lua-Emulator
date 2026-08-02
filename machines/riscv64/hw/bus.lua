-- Generic MMIO bus: devices register (base, size) ranges.
-- CPU never hardcodes peripherals - only read/write through the bus.
--
-- First matching region wins (register higher-priority devices first).
-- Overlaps are intentional for cases like halt sitting next to UART.

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local Bus = {}
Bus.__index = Bus

-- Canonical board bases (documentation + machine wiring).
Bus.ROM_BASE = 0x00000000
Bus.CLINT_BASE = 0x02000000
Bus.PLIC_BASE = 0x0C000000
Bus.UART_BASE = 0x10000000
Bus.HALT_ADDR = 0x10000010
Bus.RAM_BASE = 0x80000000
Bus.FW_BASE = 0x80000000       -- OpenSBI / firmware DRAM link address
Bus.KERNEL_BASE = 0x80200000   -- Linux Image (OpenSBI jump default)
Bus.DTB_BASE = 0x82000000

function Bus.new()
  return setmetatable({
    regions = {},
    halted = false,
    _by_name = {},
    _ram = nil,
    _ram_base = 0,
    _ram_end = 0,
    _rom = nil,
    _rom_base = 0,
    _rom_end = 0,
  }, Bus)
end

--- Register a device window.
--- dev must provide read8(offset) / write8(offset [, value]).
--- Optional: reset(), name for lookup.
function Bus:map(name, base, size, dev)
  assert(type(base) == "number" and type(size) == "number" and size > 0, "bad map range")
  assert(dev and (dev.read8 or dev.write8), "device needs read8/write8")
  local region = {
    name = name or "?",
    base = band(base, 0xFFFFFFFF),
    size = size,
    dev = dev,
  }
  self.regions[#self.regions + 1] = region
  self._by_name[region.name] = region
  if name == "ram" then
    self._ram = dev
    self._ram_base = region.base
    self._ram_end = region.base + size
  elseif name == "rom" then
    self._rom = dev
    self._rom_base = region.base
    self._rom_end = region.base + size
  end
  return region
end

function Bus:unmap_all()
  self.regions = {}
  self._by_name = {}
  self._ram, self._rom = nil, nil
  self._ram_base, self._ram_end = 0, 0
  self._rom_base, self._rom_end = 0, 0
end

function Bus:device(name)
  local r = self._by_name[name]
  return r and r.dev or nil
end

function Bus:find(addr)
  addr = band(addr, 0xFFFFFFFF)
  for i = 1, #self.regions do
    local r = self.regions[i]
    if addr >= r.base and addr < r.base + r.size then
      return r, addr - r.base
    end
  end
  return nil, 0
end

function Bus:reset()
  self.halted = false
  local seen = {}
  for i = 1, #self.regions do
    local d = self.regions[i].dev
    if d and d.reset and not seen[d] then
      seen[d] = true
      d:reset()
    end
  end
end

function Bus:read8(addr)
  addr = band(addr, 0xFFFFFFFF)
  local ram = self._ram
  if ram and addr >= self._ram_base and addr < self._ram_end then
    return ram:read8(addr - self._ram_base)
  end
  local rom = self._rom
  if rom and addr >= self._rom_base and addr < self._rom_end then
    return rom:read8(addr - self._rom_base)
  end
  local r, off = self:find(addr)
  if not r or not r.dev.read8 then
    return 0
  end
  return band(r.dev:read8(off) or 0, 0xFF)
end

function Bus:write8(addr, value)
  value = band(value, 0xFF)
  addr = band(addr, 0xFFFFFFFF)
  local ram = self._ram
  if ram and addr >= self._ram_base and addr < self._ram_end then
    ram:write8(addr - self._ram_base, value)
    return
  end
  local r, off = self:find(addr)
  if not r or not r.dev.write8 then
    return
  end
  r.dev:write8(off, value)
end

function Bus:read16(addr)
  local lo = self:read8(addr)
  local hi = self:read8(band(addr + 1, 0xFFFFFFFF))
  return bor(lo, lshift(hi, 8))
end

function Bus:write16(addr, value)
  value = band(value, 0xFFFF)
  self:write8(addr, band(value, 0xFF))
  self:write8(band(addr + 1, 0xFFFFFFFF), band(rshift(value, 8), 0xFF))
end

function Bus:read32(addr)
  addr = band(addr, 0xFFFFFFFF)
  local ram = self._ram
  if ram and addr >= self._ram_base and addr + 3 < self._ram_end and ram.read32 then
    return ram:read32(addr - self._ram_base)
  end
  local rom = self._rom
  if rom and addr >= self._rom_base and addr + 3 < self._rom_end and rom.read32 then
    return rom:read32(addr - self._rom_base)
  end
  local b0 = self:read8(addr)
  local b1 = self:read8(band(addr + 1, 0xFFFFFFFF))
  local b2 = self:read8(band(addr + 2, 0xFFFFFFFF))
  local b3 = self:read8(band(addr + 3, 0xFFFFFFFF))
  return bor(bor(b0, lshift(b1, 8)), bor(lshift(b2, 16), lshift(b3, 24)))
end

function Bus:write32(addr, value)
  value = band(value, 0xFFFFFFFF)
  addr = band(addr, 0xFFFFFFFF)
  local ram = self._ram
  if ram and addr >= self._ram_base and addr + 3 < self._ram_end and ram.write32 then
    ram:write32(addr - self._ram_base, value)
    return
  end
  self:write8(addr, band(value, 0xFF))
  self:write8(band(addr + 1, 0xFFFFFFFF), band(rshift(value, 8), 0xFF))
  self:write8(band(addr + 2, 0xFFFFFFFF), band(rshift(value, 16), 0xFF))
  self:write8(band(addr + 3, 0xFFFFFFFF), band(rshift(value, 24), 0xFF))
end

return Bus
