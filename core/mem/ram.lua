-- 32KB TI-83 Plus RAM (2 x 16KB pages).

local PAGE_SIZE = 0x4000
local NUM_PAGES = 2
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
