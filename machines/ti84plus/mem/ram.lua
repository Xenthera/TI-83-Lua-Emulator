-- TI-84 Plus RAM: SE-class ASIC exposes 8×16KB pages via ports 05/06/07.
-- Physical user RAM is still ~32KB; extra pages wrap for paging compatibility.

local PAGE_SIZE = 0x4000
local NUM_PAGES = 8
local SIZE = PAGE_SIZE * NUM_PAGES

local Ram = {}
Ram.__index = Ram

function Ram.new()
  local self = setmetatable({}, Ram)
  self.bytes = {}
  for i = 0, SIZE - 1 do
    self.bytes[i] = 0
  end
  return self
end

function Ram:read(page, offset)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  return self.bytes[page * PAGE_SIZE + offset]
end

function Ram:write(page, offset, value)
  page = page % NUM_PAGES
  offset = offset % PAGE_SIZE
  self.bytes[page * PAGE_SIZE + offset] = value % 256
end

function Ram:clear()
  for i = 0, SIZE - 1 do
    self.bytes[i] = 0
  end
end

Ram.PAGE_SIZE = PAGE_SIZE
Ram.NUM_PAGES = NUM_PAGES
Ram.SIZE = SIZE

return Ram
