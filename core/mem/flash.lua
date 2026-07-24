-- 512KB TI-83 Plus flash (32 x 16KB pages).

local PAGE_SIZE = 0x4000
local NUM_PAGES = 32
local SIZE = PAGE_SIZE * NUM_PAGES

local Flash = {}
Flash.__index = Flash

function Flash.new()
  local self = setmetatable({}, Flash)
  self.data = string.rep("\0", SIZE)
  self.bytes = {} -- mutable byte array mirror for fast access
  for i = 0, SIZE - 1 do
    self.bytes[i] = 0
  end
  return self
end

function Flash:load(bytes)
  assert(#bytes == SIZE, "flash dump must be 512KB")
  self.data = bytes
  for i = 0, SIZE - 1 do
    self.bytes[i] = bytes:byte(i + 1)
  end
end

function Flash:read(page, offset)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  return self.bytes[page * PAGE_SIZE + offset]
end

function Flash:write(page, offset, value)
  -- Milestone A: ignore program/erase; flash is read-only for OS boot.
  -- Kept as a hook for later flash programming support.
  return
end

function Flash:page_ptr(page)
  page = page % NUM_PAGES
  return page * PAGE_SIZE
end

Flash.PAGE_SIZE = PAGE_SIZE
Flash.NUM_PAGES = NUM_PAGES
Flash.SIZE = SIZE

return Flash
