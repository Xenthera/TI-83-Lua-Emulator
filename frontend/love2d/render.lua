-- Love2D display backend: presents the 96x64 monochrome framebuffer
-- with a hairline gap between virtual pixels (LCD matrix feel).

local Lcd = require("core.hw.lcd")

local Render = {}
Render.__index = Render

-- Classic green-gray LCD palette (frontend-only).
-- Off pixels match the gap substrate; only lit pixels stand out.
local COLOR_BG = { 0.52, 0.58, 0.48, 1 }
local COLOR_ON = { 0.12, 0.18, 0.12, 1 }
local COLOR_BEZEL = { 0.62, 0.66, 0.58, 1 }

-- Sub-pixel inset per side -> ~0.5px total gap (smaller than a full screen px).
local PIXEL_INSET = 0.25

local function bit_test(byte, bitn)
  local mask = 2 ^ bitn
  return math.floor(byte / mask) % 2 == 1
end

--- Integer pixel cell size that fits a glass rect of size (dw x dh).
function Render.cell_for(dw, dh)
  local cell = math.min(math.floor(dw / Lcd.WIDTH), math.floor(dh / Lcd.HEIGHT))
  return math.max(2, cell)
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

--- Draw the LCD glass at an exact rect {x,y,w,h} (no surrounding pane fill).
function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then
    return
  end

  local cell = Render.cell_for(glass.w, glass.h)
  local inset = math.min(PIXEL_INSET, cell * 0.2)
  local pix = cell - inset * 2
  local dw = self.width * cell
  local dh = self.height * cell
  local x0 = glass.x + math.floor((glass.w - dw) / 2)
  local y0 = glass.y + math.floor((glass.h - dh) / 2)
  self.scale = cell

  -- Outer LCD bezel inset within the glass slot.
  love.graphics.setColor(COLOR_BEZEL)
  love.graphics.rectangle("fill", x0 - 3, y0 - 3, dw + 6, dh + 6, 3, 3)

  -- Background fills gaps + off pixels; only lit bodies are drawn on top.
  love.graphics.setColor(COLOR_BG)
  love.graphics.rectangle("fill", x0, y0, dw, dh)

  local fb = self.fb
  local bpr = Lcd.BYTES_PER_ROW
  if fb and self.display_on then
    love.graphics.setColor(COLOR_ON)
    for row = 0, self.height - 1 do
      local py_px = y0 + row * cell + inset
      for col = 0, bpr - 1 do
        local byte = fb[row * bpr + col] or 0
        for bit = 0, 7 do
          if bit_test(byte, 7 - bit) then
            local lx = col * 8 + bit
            love.graphics.rectangle("fill", x0 + lx * cell + inset, py_px, pix, pix)
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
