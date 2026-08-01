-- DMG LCD presenter: 160x144 shades 0-3 → classic green palette texture.

local Ppu = require("machines.gameboy.hw.ppu")

local Render = {}
Render.__index = Render

-- Approximate original DMG greens (shade 0 = lightest)
local SHADE = {
  [0] = { 0.61, 0.73, 0.06 },
  [1] = { 0.42, 0.55, 0.05 },
  [2] = { 0.22, 0.35, 0.04 },
  [3] = { 0.06, 0.14, 0.02 },
}
local BLANK = { 0.08, 0.12, 0.04, 1 }

function Render.new()
  local self = setmetatable({}, Render)
  self.width = Ppu.WIDTH
  self.height = Ppu.HEIGHT
  self.fb = nil
  self.display_on = true
  self._last_rect = nil
  self.image = nil
  self.id = nil
  self._dirty_tex = true
  return self
end

function Render:_ensure()
  if self.image then return true end
  local ok, img = pcall(love.image.newImageData, self.width, self.height)
  if not ok then return false end
  self.image = img
  self.id = love.graphics.newImage(img)
  self.id:setFilter("nearest", "nearest")
  return true
end

function Render:present(framebuffer, display_on)
  self.fb = framebuffer
  self.display_on = not not display_on
  self._dirty_tex = true
end

function Render:_upload()
  if not self._dirty_tex then return end
  self._dirty_tex = false
  if not self.display_on or not self.fb or not self:_ensure() then
    return
  end
  local fb = self.fb
  local img = self.image
  local w = self.width
  if img.mapPixel then
    img:mapPixel(function(x, y)
      local s = fb[y * w + x] or 0
      if s < 0 then s = 0 elseif s > 3 then s = 3 end
      local c = SHADE[s]
      return c[1], c[2], c[3], 1
    end)
  else
    for y = 0, self.height - 1 do
      local base = y * w
      for x = 0, w - 1 do
        local s = fb[base + x] or 0
        if s < 0 then s = 0 elseif s > 3 then s = 3 end
        local c = SHADE[s]
        img:setPixel(x, y, c[1], c[2], c[3], 1)
      end
    end
  end
  self.id:replacePixels(img)
end

function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then
    return
  end
  local x0, y0, dw, dh = glass.x, glass.y, glass.w, glass.h
  local cell = dw / self.width

  if not self.display_on then
    love.graphics.setColor(BLANK)
    love.graphics.rectangle("fill", x0, y0, dw, dh)
    self._last_rect = { x = x0, y = y0, w = dw, h = dh, scale = cell }
    return
  end

  self:_upload()
  if self.id then
    love.graphics.setColor(1, 1, 1, 1)
    love.graphics.draw(self.id, x0, y0, 0, dw / self.width, dh / self.height)
  else
    love.graphics.setColor(SHADE[0][1], SHADE[0][2], SHADE[0][3], 1)
    love.graphics.rectangle("fill", x0, y0, dw, dh)
  end

  self._last_rect = { x = x0, y = y0, w = dw, h = dh, scale = cell }
end

function Render:screen_rect()
  local r = self._last_rect
  if not r then return 0, 0, 0, 0, 1 end
  return r.x, r.y, r.w, r.h, r.scale
end

return Render
