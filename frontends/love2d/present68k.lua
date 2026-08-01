-- Minimal TI-89 / TI-92+ LCD presenter (variable geometry).

local Present = {}
Present.__index = Present

function Present.new(lcd_mod)
  local self = setmetatable({}, Present)
  self.w = lcd_mod.WIDTH or 160
  self.h = lcd_mod.HEIGHT or 100
  self.bpr = lcd_mod.BYTES_PER_ROW or math.floor(self.w / 8)
  self.image = nil
  self.id = nil
  return self
end

function Present:ensure()
  if self.image then return end
  local ok, img = pcall(love.image.newImageData, self.w, self.h)
  if ok then
    self.image = img
    self.id = love.graphics.newImage(img)
    self.id:setFilter("nearest", "nearest")
  end
end

function Present:present(fb, x, y, scale)
  self:ensure()
  if not self.image or not fb then return end
  scale = scale or 2
  for row = 0, self.h - 1 do
    for col = 0, self.w - 1 do
      local byte = fb[row * self.bpr + math.floor(col / 8)] or 0
      local bitn = 7 - (col % 8)
      local on = math.floor(byte / (2 ^ bitn)) % 2 == 1
      local g = on and 0.15 or 0.85
      self.image:setPixel(col, row, g, g, g * 0.9, 1)
    end
  end
  self.id:replacePixels(self.image)
  love.graphics.setColor(1, 1, 1, 1)
  love.graphics.draw(self.id, x or 0, y or 0, 0, scale, scale)
end

return Present
