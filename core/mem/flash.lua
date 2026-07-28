-- 512KB TI-83 Plus flash (32 x 16KB pages) with AMD AM29F-style commands.
--
-- Port $14 unlock is enforced by the MMU; this module accepts command cycles
-- once unlocked. Program/erase complete instantly (OS status polls succeed on
-- the first read). See WikiTI: 83Plus:OS:Raw Flash Commands.

local bit = require("core.util.bit")
local band = bit.band

local PAGE_SIZE = 0x4000
local NUM_PAGES = 32
local SIZE = PAGE_SIZE * NUM_PAGES

-- Command FSM
local ST_READY = 0
local ST_UNLOCK1 = 1 -- saw AA @ xxxAAA
local ST_UNLOCK2 = 2 -- saw 55 @ xxx555
local ST_PROGRAM = 3 -- next write programs a byte
local ST_ERASE1 = 4 -- saw 80 after unlock; need AA
local ST_ERASE2 = 5 -- saw AA; need 55
local ST_ERASE3 = 6 -- saw 55; need 30 @ sector
local ST_AUTOSELECT = 7

-- Autoselect IDs: AMD manufacturer, 512K 5V device (classic TI-83+)
local MFG_ID = 0x01
local DEV_ID = 0x23

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
  -- When true, MMU must route flash reads through :cmd_read (abort / IDs).
  self.override_reads = false
  return self
end

function Flash:load(bytes)
  assert(#bytes == SIZE, "flash dump must be 512KB")
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

--- Low 12 address bits used by AMD command decoding.
local function addr12(offset)
  return band(offset, 0x0FFF)
end

--- 64 KiB sector start page (4 x 16 KiB). Matches TI archive layout.
local function sector_start(page)
  return band(page % NUM_PAGES, 0x1C)
end

local function program_byte(self, page, offset, value)
  local i = abs_index(page, offset)
  -- NOR flash: can only clear bits (1 -> 0) without a prior erase.
  self.bytes[i] = band(self.bytes[i], band(value, 0xFF))
end

local function erase_sector(self, page)
  local start = sector_start(page)
  -- Refuse to erase the last sector (boot / certificate pages 0x1C-0x1F).
  if start >= 0x1C then
    return
  end
  local base = start * PAGE_SIZE
  local bytes = self.bytes
  for i = base, base + 4 * PAGE_SIZE - 1 do
    bytes[i] = 0xFF
  end
end

--- Normal array read (no command side effects). Used by MMU fast path.
function Flash:read(page, offset)
  return self.bytes[abs_index(page, offset)]
end

--- Flash read while a command is in progress (autoselect / abort pending unlock).
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
      return 0x00 -- sector not write-protected
    end
    return 0x00
  end
  -- Any read mid-sequence aborts the command (AMD behavior).
  if self.cmd_state ~= ST_READY then
    set_state(self, ST_READY)
  end
  return self.bytes[abs_index(page, offset)]
end

--- Memory-mapped flash write (MMU calls this only when port $14 unlocked).
function Flash:write(page, offset, value)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  value = band(value, 0xFF)
  local a12 = addr12(offset)
  local st = self.cmd_state

  -- Software reset exits most modes.
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
      -- stay in autoselect until F0 / new unlock
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
