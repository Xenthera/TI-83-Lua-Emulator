-- TI-84 Plus LCD: same 96×64 geometry, higher-contrast glass than TI-83+.
-- Fills the glass rect using continuous scale from hardware WIDTH×HEIGHT.

local Lcd = require("machines.ti84plus.hw.lcd")

local Render = {}
Render.__index = Render

local COLOR_BG = { 0.58, 0.62, 0.52, 1 }
local COLOR_ON = { 0.06, 0.10, 0.08, 1 }

local function bit_test(byte, bitn)
  local mask = 2 ^ bitn
  return math.floor(byte / mask) % 2 == 1
end

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

function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then
    return
  end

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
  if not r then return 0, 0, 0, 0, 1 end
  return r.x, r.y, r.w, r.h, r.scale
end

return Render
