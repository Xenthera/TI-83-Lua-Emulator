-- TI-89 LCD presenter: 160x100 with classic green-gray glass.
-- Fills the glass rect edge-to-edge using continuous scale from hardware size.

local Lcd = require("machines.ti89.hw.lcd")

local Render = {}
Render.__index = Render

local COLOR_BG = { 0.48, 0.58, 0.52, 1 }
local COLOR_ON = { 0.08, 0.14, 0.12, 1 }
local COLOR_OFF_GLASS = { 0.35, 0.40, 0.37, 1 }

local function bit_test(byte, bitn)
  return math.floor(byte / (2 ^ bitn)) % 2 == 1
end

--- Continuous cell size that fills (dw x dh) while keeping LCD aspect.
function Render.cell_for(dw, dh)
  return math.max(0.5, math.min(dw / Lcd.WIDTH, dh / Lcd.HEIGHT))
end

function Render.new()
  local self = setmetatable({}, Render)
  self.width = Lcd.WIDTH
  self.height = Lcd.HEIGHT
  self.bpr = Lcd.BYTES_PER_ROW
  self.fb = nil
  self.display_on = true
  self.scale = 3
  self._last_rect = nil
  return self
end

function Render:present(framebuffer, display_on)
  self.fb = framebuffer
  self.display_on = not not display_on
end

function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then
    return
  end

  local cell = glass.w / self.width
  local x0, y0 = glass.x, glass.y
  local dw, dh = glass.w, glass.h
  self.scale = cell

  if self.display_on then
    love.graphics.setColor(COLOR_BG)
  else
    love.graphics.setColor(COLOR_OFF_GLASS)
  end
  love.graphics.rectangle("fill", x0, y0, dw, dh)

  local fb = self.fb
  if fb and self.display_on then
    love.graphics.setColor(COLOR_ON)
    for row = 0, self.height - 1 do
      local py = y0 + row * cell
      for col = 0, self.bpr - 1 do
        local byte = fb[row * self.bpr + col] or 0
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
  if not r then return 0, 0, 0, 0, 1 end
  return r.x, r.y, r.w, r.h, r.scale
end

return Render
