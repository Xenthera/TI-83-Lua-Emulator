-- Sparse page RAM for the custom RV64 board (mapped at 0x8000_0000).

local bit = require("framework.util.bit")
local band = bit.band

local PAGE = 0x1000 -- 4KB
local Ram = {}
Ram.__index = Ram
Ram.BASE = 0x80000000
Ram.SIZE = 64 * 1024 * 1024 -- 64MB window (sparse pages; only touched pages allocate)
Ram.PAGE = PAGE

local ensure_page
local read8_page
local write8_page

do
  local ok, ffi = pcall(require, "ffi")
  if ok and ffi and ffi.typeof then
    pcall(ffi.cdef, [[typedef uint8_t rv_ram_page[4096];]])
    local page_t = ffi.typeof("rv_ram_page")
    ensure_page = function(self, page)
      local p = self.pages[page]
      if not p then
        p = page_t()
        self.pages[page] = p
      end
      return p
    end
    read8_page = function(p, off)
      return p[off]
    end
    write8_page = function(p, off, value)
      p[off] = value
    end
  else
    ensure_page = function(self, page)
      local p = self.pages[page]
      if not p then
        p = {}
        self.pages[page] = p
      end
      return p
    end
    read8_page = function(p, off)
      return p[off] or 0
    end
    write8_page = function(p, off, value)
      p[off] = value
    end
  end
end

function Ram.new(size)
  local self = setmetatable({}, Ram)
  self.size = size or Ram.SIZE
  self.pages = {}
  return self
end

local function page_off(offset)
  return math.floor(offset / PAGE), offset % PAGE
end

function Ram:ensure(page)
  return ensure_page(self, page)
end

function Ram:read8(offset)
  if offset < 0 or offset >= self.size then
    return 0
  end
  local page, off = page_off(offset)
  local p = self.pages[page]
  if not p then return 0 end
  return read8_page(p, off)
end

function Ram:write8(offset, value)
  if offset < 0 or offset >= self.size then
    return
  end
  local page, off = page_off(offset)
  write8_page(ensure_page(self, page), off, band(value, 0xFF))
end

--- Aligned little-endian word helpers (avoid 4× find/page lookups in the CPU).
function Ram:read32(offset)
  if offset < 0 or offset + 3 >= self.size then
    return 0
  end
  local page, off = page_off(offset)
  if off <= PAGE - 4 then
    local p = self.pages[page]
    if not p then return 0 end
    local b0 = read8_page(p, off)
    local b1 = read8_page(p, off + 1)
    local b2 = read8_page(p, off + 2)
    local b3 = read8_page(p, off + 3)
    return b0 + b1 * 256 + b2 * 65536 + b3 * 16777216
  end
  -- Rare page-crossing word
  local b0 = self:read8(offset)
  local b1 = self:read8(offset + 1)
  local b2 = self:read8(offset + 2)
  local b3 = self:read8(offset + 3)
  return b0 + b1 * 256 + b2 * 65536 + b3 * 16777216
end

function Ram:write32(offset, value)
  value = band(value, 0xFFFFFFFF)
  if offset < 0 or offset + 3 >= self.size then
    return
  end
  local page, off = page_off(offset)
  if off <= PAGE - 4 then
    local p = ensure_page(self, page)
    write8_page(p, off, band(value, 0xFF))
    write8_page(p, off + 1, band(math.floor(value / 256), 0xFF))
    write8_page(p, off + 2, band(math.floor(value / 65536), 0xFF))
    write8_page(p, off + 3, band(math.floor(value / 16777216), 0xFF))
    return
  end
  self:write8(offset, value)
  self:write8(offset + 1, math.floor(value / 256))
  self:write8(offset + 2, math.floor(value / 65536))
  self:write8(offset + 3, math.floor(value / 16777216))
end

function Ram:clear()
  self.pages = {}
end

return Ram
