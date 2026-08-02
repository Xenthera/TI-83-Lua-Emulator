-- RV64 console LCD presenter: 320x200 mono -> one GPU texture (not per-pixel rects).
--
-- Old path drew love.graphics.rectangle per lit pixel (~64k calls) and killed FPS.
-- New path: upload ImageData only when the framebuffer is dirty, then one draw().

local Lcd = require("machines.riscv64.hw.lcd")

local Render = {}
Render.__index = Render

local ON_R, ON_G, ON_B = 0.75, 0.85, 0.95
local OFF_R, OFF_G, OFF_B = 0.08, 0.09, 0.11
local BLANK = { 0.12, 0.14, 0.16, 1 }

function Render.new()
  local self = setmetatable({}, Render)
  self.width = Lcd.WIDTH
  self.height = Lcd.HEIGHT
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
  local w, h = self.width, self.height
  -- mapPixel is much faster than setPixel in a Lua loop on Love 11+.
  if img.mapPixel then
    img:mapPixel(function(x, y)
      if (fb[y * w + x] or 0) ~= 0 then
        return ON_R, ON_G, ON_B, 1
      end
      return OFF_R, OFF_G, OFF_B, 1
    end)
  else
    for y = 0, h - 1 do
      local base = y * w
      for x = 0, w - 1 do
        if (fb[base + x] or 0) ~= 0 then
          img:setPixel(x, y, ON_R, ON_G, ON_B, 1)
        else
          img:setPixel(x, y, OFF_R, OFF_G, OFF_B, 1)
        end
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
    love.graphics.setColor(OFF_R, OFF_G, OFF_B, 1)
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
