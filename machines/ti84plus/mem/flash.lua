-- 1MB TI-84 Plus flash (64 × 16KB pages), AMD/Fujitsu 29LV800-style commands.
-- Boot/cert live in the top sector (pages 0x3C-0x3F). Port $14 unlock via MMU.

local bit = require("framework.util.bit")
local band = bit.band

local PAGE_SIZE = 0x4000
local NUM_PAGES = 64
local SIZE = PAGE_SIZE * NUM_PAGES

local ST_READY = 0
local ST_UNLOCK1 = 1
local ST_UNLOCK2 = 2
local ST_PROGRAM = 3
local ST_ERASE1 = 4
local ST_ERASE2 = 5
local ST_ERASE3 = 6
local ST_AUTOSELECT = 7

-- Fujitsu MBM29LV800-class IDs (common in 84+ dumps / emulators)
local MFG_ID = 0x04
local DEV_ID = 0xDA

local Flash = {}
Flash.__index = Flash

function Flash.new()
  local self = setmetatable({}, Flash)
  self.data = string.rep("\0", SIZE)
  self.bytes = {}
  for i = 0, SIZE - 1 do
    self.bytes[i] = 0
  end
  self.cmd_state = ST_READY
  self.override_reads = false
  return self
end

function Flash:load(bytes)
  assert(#bytes == SIZE, "flash dump must be 1MB")
  self.data = bytes
  for i = 0, SIZE - 1 do
    self.bytes[i] = bytes:byte(i + 1)
  end
  self:reset_cmd()
end

function Flash:reset_cmd()
  self.cmd_state = ST_READY
  self.override_reads = false
end

local function set_state(self, st)
  self.cmd_state = st
  self.override_reads = (st ~= ST_READY)
end

local function abs_index(page, offset)
  return (page % NUM_PAGES) * PAGE_SIZE + (offset % PAGE_SIZE)
end

local function addr12(offset)
  return band(offset, 0x0FFF)
end

local function sector_start(page)
  return band(page % NUM_PAGES, 0x3C)
end

local function program_byte(self, page, offset, value)
  local i = abs_index(page, offset)
  self.bytes[i] = band(self.bytes[i], band(value, 0xFF))
end

local function erase_sector(self, page)
  local start = sector_start(page)
  -- Refuse boot / certificate sector (pages 0x3C-0x3F).
  if start >= 0x3C then
    return
  end
  local base = start * PAGE_SIZE
  local bytes = self.bytes
  for i = base, base + 4 * PAGE_SIZE - 1 do
    bytes[i] = 0xFF
  end
end

function Flash:read(page, offset)
  return self.bytes[abs_index(page, offset)]
end

function Flash:cmd_read(page, offset)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  if self.cmd_state == ST_AUTOSELECT then
    local a = band(offset, 0xFF)
    if a == 0x00 then
      return MFG_ID
    elseif a == 0x02 then
      return DEV_ID
    elseif a == 0x04 then
      return 0x00
    end
    return 0x00
  end
  if self.cmd_state ~= ST_READY then
    set_state(self, ST_READY)
  end
  return self.bytes[abs_index(page, offset)]
end

function Flash:write(page, offset, value)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  value = band(value, 0xFF)
  local a12 = addr12(offset)
  local st = self.cmd_state

  if value == 0xF0 then
    set_state(self, ST_READY)
    return
  end

  if st == ST_PROGRAM then
    program_byte(self, page, offset, value)
    set_state(self, ST_READY)
    return
  end

  if st == ST_READY or st == ST_AUTOSELECT then
    if a12 == 0x0AAA and value == 0xAA then
      set_state(self, ST_UNLOCK1)
    elseif st == ST_AUTOSELECT then
      -- stay
    else
      set_state(self, ST_READY)
    end
    return
  end

  if st == ST_UNLOCK1 then
    if a12 == 0x0555 and value == 0x55 then
      set_state(self, ST_UNLOCK2)
    else
      set_state(self, ST_READY)
    end
    return
  end

  if st == ST_UNLOCK2 then
    if a12 == 0x0AAA then
      if value == 0xA0 then
        set_state(self, ST_PROGRAM)
        return
      elseif value == 0x80 then
        set_state(self, ST_ERASE1)
        return
      elseif value == 0x90 then
        set_state(self, ST_AUTOSELECT)
        return
      end
    end
    set_state(self, ST_READY)
    return
  end

  if st == ST_ERASE1 then
    if a12 == 0x0AAA and value == 0xAA then
      set_state(self, ST_ERASE2)
    else
      set_state(self, ST_READY)
    end
    return
  end

  if st == ST_ERASE2 then
    if a12 == 0x0555 and value == 0x55 then
      set_state(self, ST_ERASE3)
    else
      set_state(self, ST_READY)
    end
    return
  end

  if st == ST_ERASE3 then
    if value == 0x30 then
      erase_sector(self, page)
    end
    set_state(self, ST_READY)
    return
  end

  set_state(self, ST_READY)
end

function Flash:page_ptr(page)
  page = page % NUM_PAGES
  return page * PAGE_SIZE
end

Flash.PAGE_SIZE = PAGE_SIZE
Flash.NUM_PAGES = NUM_PAGES
Flash.SIZE = SIZE

return Flash
