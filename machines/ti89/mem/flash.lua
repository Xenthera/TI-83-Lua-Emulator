-- TI-89 Titanium Flash ROM (4MB HW3; classic 2MB dumps are padded).
-- Sharp LH28F320BFHE-style command FSM (ID, CFI, word program, erase, status).
-- Commands are word-oriented ($1010/$5050/$9898/$FFFF); bus should call write16.

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local Flash = {}
Flash.__index = Flash

local MANUF_ID = 0x89
local DEVICE_ID = 0xB5 -- AMS accepts this as 4MB-class Titanium flash
local STATUS_READY = 0x80

-- CFI query table for LH28F320 bottom-parameter, 4MB, x16.
-- Indexed by *word* offset; values appear on DQ7-0 (odd bytes read as 00).
-- Region 0: 8 × 8KB parameter blocks; region 1: 63 × 64KB main blocks.
local CFI = {
  [0x10] = 0x51, [0x11] = 0x52, [0x12] = 0x59, -- "QRY"
  [0x13] = 0x01, [0x14] = 0x00, -- Intel/Sharp primary command set
  [0x15] = 0x35, [0x16] = 0x00, -- primary extended query at word 0x35
  [0x17] = 0x00, [0x18] = 0x00,
  [0x19] = 0x00, [0x1A] = 0x00,
  [0x1B] = 0x27, -- Vcc min (×100 mV)
  [0x1C] = 0x36, -- Vcc max
  [0x1D] = 0x00, -- Vpp min
  [0x1E] = 0x00, -- Vpp max
  [0x1F] = 0x04, -- typical word-write timeout 2^n µs
  [0x20] = 0x00,
  [0x21] = 0x0A, -- typical block-erase timeout 2^n ms
  [0x22] = 0x00,
  [0x23] = 0x04, -- max word-write timeout multiplier
  [0x24] = 0x00,
  [0x25] = 0x04, -- max block-erase timeout multiplier
  [0x26] = 0x00,
  [0x27] = 0x16, -- device size 2^22 = 4MB
  [0x28] = 0x01, [0x29] = 0x00, -- x16 interface
  [0x2A] = 0x00, [0x2B] = 0x00,
  [0x2C] = 0x02, -- two erase-block regions
  -- Region 0: 8 × 8KB
  [0x2D] = 0x07, [0x2E] = 0x00,
  [0x2F] = 0x20, [0x30] = 0x00, -- 0x20 × 256 = 8KB
  -- Region 1: 63 × 64KB
  [0x31] = 0x3E, [0x32] = 0x00,
  [0x33] = 0x00, [0x34] = 0x01, -- 0x100 × 256 = 64KB
  -- Minimal primary extended query ("PRI")
  [0x35] = 0x50, [0x36] = 0x52, [0x37] = 0x49,
  [0x38] = 0x31, [0x39] = 0x31,
}

local function make_ff(size)
  return string.rep("\255", size)
end

function Flash.new(size)
  local self = setmetatable({}, Flash)
  self.size = size or (4 * 1024 * 1024)
  self.data = make_ff(self.size)
  self.bytes = nil -- full materialize (program/erase only; avoid on CC)
  self.pages = {} -- sparse 64KB page cache for reads (CC-friendly)
  self.mode = "read" -- read | id | cfi | status | prog_data | erase_confirm
  self.status = STATUS_READY
  return self
end

local PAGE = 0x10000

--- Materialize one 64KB page from the compact string image.
-- Avoids a 4MB Lua table (OOM on ComputerCraft) while matching TI-83+ array reads
-- for the hot working set.
local function ensure_page(self, page)
  local pages = self.pages
  local p = pages[page]
  if p then return p end
  local data = self.data
  local base = page * PAGE -- 0-based byte offset
  p = {}
  -- string.byte is 1-based; pull a whole page in one call when possible.
  local chunk = data:sub(base + 1, base + PAGE)
  for i = 1, #chunk do
    p[i - 1] = chunk:byte(i)
  end
  for i = #chunk, PAGE - 1 do
    p[i] = 0xFF
  end
  pages[page] = p
  return p
end

local function ensure_bytes(self)
  if self.bytes then return end
  local data = self.data
  local bytes = {}
  for i = 1, #data do
    bytes[i - 1] = data:byte(i)
  end
  self.bytes = bytes
  self.pages = {} -- full table supersedes page cache
end

function Flash:load(data)
  if type(data) ~= "string" then return nil, "rom must be a string" end
  if #data < 0x10000 then return nil, "rom too small" end
  if #data > self.size then
    data = data:sub(1, self.size)
  elseif #data < self.size then
    data = data .. make_ff(self.size - #data)
  end
  self.data = data
  self.bytes = nil
  self.pages = {}
  self._page_i = nil
  self._page_p = nil
  self.mode = "read"
  self.status = STATUS_READY
  return true
end

local function cfi_byte(byte_addr)
  -- Even byte = CFI[word]; odd byte = 0x00 in x16 mode.
  if byte_addr % 2 == 1 then return 0x00 end
  return CFI[rshift(byte_addr, 1)] or 0x00
end

function Flash:read8(addr)
  addr = addr % self.size
  local mode = self.mode
  if mode == "id" then
    local a = addr % 4
    if a == 1 then return MANUF_ID end
    if a == 3 then return DEVICE_ID end
    return 0x00
  end
  if mode == "cfi" then
    -- Respond with the same table for any probe base (low address bits).
    return cfi_byte(addr % 0x200)
  end
  if mode == "status" or mode == "prog_data" or mode == "erase_confirm" then
    return self.status
  end
  if self.bytes then
    return self.bytes[addr] or 0xFF
  end
  local p = ensure_page(self, math.floor(addr / PAGE))
  return p[addr % PAGE] or 0xFF
end

--- Word fetch for the bus hot path (read mode only). Returns hi*256+lo.
-- Keeps a sticky last-page pointer so tight loops avoid repeated page lookups.
function Flash:read16_data(foff)
  foff = foff % self.size
  if self.bytes then
    local bytes = self.bytes
    return (bytes[foff] or 0xFF) * 256 + (bytes[foff + 1] or 0xFF)
  end
  local page = math.floor(foff / PAGE)
  local o = foff - page * PAGE
  local p = self._page_p
  if self._page_i ~= page then
    p = ensure_page(self, page)
    self._page_i = page
    self._page_p = p
  end
  if o ~= PAGE - 1 then
    return (p[o] or 0xFF) * 256 + (p[o + 1] or 0xFF)
  end
  local p2 = ensure_page(self, page + 1)
  return (p[o] or 0xFF) * 256 + (p2[0] or 0xFF)
end

local function program_word(self, addr, value)
  ensure_bytes(self)
  addr = band(addr, 0xFFFFFFFE) % self.size
  local hi = rshift(value, 8)
  local lo = band(value, 0xFF)
  self.bytes[addr] = band(self.bytes[addr] or 0xFF, hi)
  self.bytes[addr + 1] = band(self.bytes[addr + 1] or 0xFF, lo)
  self.status = STATUS_READY
  self.mode = "status"
end

-- LH28F320 bottom-parameter geometry (Titanium BFHE):
--   8 × 8KB at $00000–$0FFFF, then 64KB main blocks.
local function sector_base_and_size(addr)
  addr = addr % (4 * 1024 * 1024)
  if addr < 0x10000 then
    local base = addr - (addr % 0x2000)
    return base, 0x2000
  end
  local base = addr - (addr % 0x10000)
  return base, 0x10000
end

local function erase_sector(self, addr)
  ensure_bytes(self)
  local base, size = sector_base_and_size(addr)
  for i = base, base + size - 1 do
    self.bytes[i] = 0xFF
  end
  self.status = STATUS_READY
  self.mode = "status"
end

function Flash:write16(addr, value)
  addr = addr % self.size
  value = band(value, 0xFFFF)
  local mode = self.mode
  local cmd = band(value, 0xFF)

  if mode == "prog_data" then
    program_word(self, addr, value)
    return
  end

  if mode == "erase_confirm" then
    if cmd == 0xD0 then
      erase_sector(self, addr)
    else
      self.mode = "read"
    end
    return
  end

  if cmd == 0x90 then
    self.mode = "id"
  elseif cmd == 0x98 then
    self.mode = "cfi"
  elseif cmd == 0x10 or cmd == 0x40 then
    self.mode = "prog_data"
  elseif cmd == 0x20 then
    self.mode = "erase_confirm"
  elseif cmd == 0x70 then
    self.mode = "status"
  elseif cmd == 0x50 then
    self.status = STATUS_READY
    self.mode = "status"
  elseif cmd == 0xFF or cmd == 0xF0 then
    self.mode = "read"
  end
end

-- Odd byte writes: treat as duplicated-byte Sharp word at aligned address.
function Flash:write8(addr, value)
  local v = band(value, 0xFF)
  self:write16(addr - (addr % 2), bor(lshift(v, 8), v))
end

function Flash:poke8(addr, value)
  ensure_bytes(self)
  self.bytes[addr % self.size] = value % 256
end

--- Compact flash image for NVRAM / savestate (prefer live bytes over stale data).
function Flash:dump()
  if not self.bytes then
    return self.data
  end
  local size = self.size
  local bytes = self.bytes
  local CHUNK = 8192
  local parts = {}
  for base = 0, size - 1, CHUNK do
    local n = math.min(CHUNK, size - base)
    local chars = {}
    for i = 0, n - 1 do
      chars[i + 1] = string.char(bytes[base + i] or 0xFF)
    end
    parts[#parts + 1] = table.concat(chars)
  end
  local data = table.concat(parts)
  self.data = data
  return data
end

return Flash
