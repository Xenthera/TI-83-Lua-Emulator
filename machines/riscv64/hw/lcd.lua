-- Console LCD: render UART text into a mono framebuffer for the IDE.

local bit = require("framework.util.bit")
local band, lshift = bit.band, bit.lshift

local Lcd = {}
Lcd.__index = Lcd
Lcd.WIDTH = 320
Lcd.HEIGHT = 200
-- Thin 6x8 glyphs: ~53×25 cells on 320×200 (was 40×25 @ 8×8).
Lcd.CW = 6
Lcd.CH = 8
Lcd.COLS = math.floor(Lcd.WIDTH / Lcd.CW)
Lcd.ROWS = math.floor(Lcd.HEIGHT / Lcd.CH)

local FONT = require("machines.riscv64.hw.lcd_font")

local function draw_char(fb, col, row, ch)
  local glyph = FONT[ch]
  if not glyph then return end
  local x0 = col * Lcd.CW
  local y0 = row * Lcd.CH
  local cw, chh = Lcd.CW, Lcd.CH
  for r = 0, chh - 1 do
    local bits = glyph[r + 1] or 0
    for c = 0, cw - 1 do
      if band(bits, lshift(1, 7 - c)) ~= 0 then
        local x, y = x0 + c, y0 + r
        if x < Lcd.WIDTH and y < Lcd.HEIGHT then
          fb[y * Lcd.WIDTH + x] = 1
        end
      end
    end
  end
end

function Lcd.new()
  local self = setmetatable({}, Lcd)
  local n = Lcd.WIDTH * Lcd.HEIGHT
  self.fb = {}
  for i = 0, n - 1 do
    self.fb[i] = 0
  end
  self._dirty = true
  self.on = true
  return self
end

function Lcd:clear()
  for i = 0, Lcd.WIDTH * Lcd.HEIGHT - 1 do
    self.fb[i] = 0
  end
  self._dirty = true
end

function Lcd:render_text(text)
  self:clear()
  text = text or ""
  local lines = {}
  local cur = {}
  for i = 1, #text do
    local ch = text:byte(i)
    if ch == 10 then
      lines[#lines + 1] = table.concat(cur)
      cur = {}
    elseif ch ~= 13 then
      cur[#cur + 1] = string.char(ch)
    end
  end
  if #cur > 0 then
    lines[#lines + 1] = table.concat(cur)
  end
  local start = math.max(1, #lines - Lcd.ROWS + 1)
  local row = 0
  for li = start, #lines do
    local line = lines[li]
    local col = 0
    for i = 1, #line do
      if col >= Lcd.COLS then break end
      draw_char(self.fb, col, row, line:byte(i))
      col = col + 1
    end
    row = row + 1
    if row >= Lcd.ROWS then break end
  end
  self._dirty = true
end

function Lcd:framebuffer()
  return self.fb
end

function Lcd:dirty()
  return self._dirty
end

function Lcd:clear_dirty()
  self._dirty = false
end

function Lcd:is_on()
  return self.on
end

return Lcd
