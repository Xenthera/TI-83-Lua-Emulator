-- Love2D display backend: presents the 96x64 monochrome framebuffer.
-- Fills the glass rect using continuous scale from hardware WIDTH×HEIGHT.

local Lcd = require("machines.ti83plus.hw.lcd")

local Render = {}
Render.__index = Render

-- Classic green-gray LCD palette (frontend-only).
local COLOR_BG = { 0.52, 0.58, 0.48, 1 }
local COLOR_ON = { 0.12, 0.18, 0.12, 1 }

local function bit_test(byte, bitn)
  local mask = 2 ^ bitn
  return math.floor(byte / mask) % 2 == 1
end

--- Continuous cell size that fills (dw x dh) at hardware aspect.
function Render.cell_for(dw, dh)
  return math.max(0.5, math.min(dw / Lcd.WIDTH, dh / Lcd.HEIGHT))
end

function Render.new()
  local self = setmetatable({}, Render)
  self.width = Lcd.WIDTH
  self.height = Lcd.HEIGHT
  self.fb = nil
  self.display_on = true
  self.scale = 4
  self._last_rect = nil
  return self
end

function Render:present(framebuffer, display_on)
  self.fb = framebuffer
  self.display_on = not not display_on
end

--- Draw the LCD glass at an exact rect {x,y,w,h} (fills edge-to-edge, no letterbox).
function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then
    return
  end

  -- Uniform scale from hardware geometry; glass is aspect-locked by the layout.
  local cell = glass.w / self.width
  local x0, y0 = glass.x, glass.y
  local dw, dh = glass.w, glass.h
  self.scale = cell

  love.graphics.setColor(COLOR_BG)
  love.graphics.rectangle("fill", x0, y0, dw, dh)

  local fb = self.fb
  local bpr = Lcd.BYTES_PER_ROW
  if fb and self.display_on then
    love.graphics.setColor(COLOR_ON)
    for row = 0, self.height - 1 do
      local py = y0 + row * cell
      for col = 0, bpr - 1 do
        local byte = fb[row * bpr + col] or 0
        for bit = 0, 7 do
          if bit_test(byte, 7 - bit) then
            local lx = col * 8 + bit
            love.graphics.rectangle("fill", x0 + lx * cell, py, cell, cell)
          end
        end
      end
    end
  end

  self._last_rect = { x = x0, y = y0, w = dw, h = dh, scale = cell }
end

function Render:screen_rect()
  local r = self._last_rect
  if not r then
    return 0, 0, 0, 0, 1
  end
  return r.x, r.y, r.w, r.h, r.scale
end

return Render
