-- TI-83 Plus keypad under the LCD (fixed part of the calculator pane).
-- Colors match the ComputerCraft keypad (CC palette approximations).

local KeypadUI = {}
KeypadUI.__index = KeypadUI

local PAD = 6

-- Approximate CC:Tweaked palette (minecraft wool-ish).
local COL = {
  black = { 0.07, 0.07, 0.07 },
  gray = { 0.30, 0.30, 0.30 },
  lightGray = { 0.61, 0.61, 0.61 },
  blue = { 0.20, 0.25, 0.70 },
  yellow = { 0.87, 0.87, 0.15 },
  green = { 0.22, 0.55, 0.15 },
  lightBlue = { 0.40, 0.70, 0.90 },
  orange = { 0.85, 0.50, 0.15 },
  white = { 0.95, 0.95, 0.95 },
}

-- Face colors matching CC keypad_view styles.
local STYLE = {
  graph = COL.blue,
  apps = COL.blue,
  arrow = COL.blue,
  blue_op = COL.blue,
  enter = COL.blue,
  fn = COL.black,
  op = COL.black,
  on = COL.black,
  second = COL.yellow,
  alpha = COL.green,
  num = COL.lightGray,
}

local COL_2ND = { COL.yellow[1], COL.yellow[2], COL.yellow[3], 1 }
local COL_ALPHA = { COL.lightBlue[1], COL.lightBlue[2], COL.lightBlue[3], 1 }
local COL_FKEY = { COL.lightBlue[1], COL.lightBlue[2], COL.lightBlue[3], 1 }

-- Real TI-83+ face in design units (5 columns x stacked rows).
-- Fields: key, label, style, col, row, w, h, second, alpha [, fkey]
local KEYS = {
  { "yequ", "Y=", "graph", 0, 0, 1, 1, "STATPLOT", nil, "F1" },
  { "window", "WINDOW", "graph", 1, 0, 1, 1, "TBLSET", nil, "F2" },
  { "zoom", "ZOOM", "graph", 2, 0, 1, 1, "FORMAT", nil, "F3" },
  { "trace", "TRACE", "graph", 3, 0, 1, 1, "CALC", nil, "F4" },
  { "graph", "GRAPH", "graph", 4, 0, 1, 1, "TABLE", nil, "F5" },

  { "2nd", "2nd", "second", 0, 1.2, 1, 1, nil, nil },
  { "mode", "MODE", "fn", 1, 1.2, 1, 1, "QUIT", nil },
  { "del", "DEL", "fn", 2, 1.2, 1, 1, "INS", nil },
  { "up", "^", "arrow", 3.5, 1.35, 1, 0.85, nil, nil },

  { "alpha", "ALPHA", "alpha", 0, 2.4, 1, 1, "A-LOCK", nil },
  { "xt", "X,T,0,n", "fn", 1, 2.4, 1, 1, "LINK", nil },
  { "stat", "STAT", "fn", 2, 2.4, 1, 1, "LIST", nil },
  { "left", "<", "arrow", 3.0, 2.25, 0.9, 0.85, nil, nil },
  { "right", ">", "arrow", 4.1, 2.25, 0.9, 0.85, nil, nil },

  { "down", "v", "arrow", 3.5, 3.3, 1, 0.85, nil, nil },

  { "math", "MATH", "fn", 0, 4.4, 1, 1, "TEST", "A" },
  { "apps", "APPS", "apps", 1, 4.4, 1, 1, "ANGLE", "B" },
  { "prgm", "PRGM", "fn", 2, 4.4, 1, 1, "DRAW", "C" },
  { "vars", "VARS", "fn", 3, 4.4, 1, 1, "DISTR", nil },
  { "clear", "CLEAR", "fn", 4, 4.4, 1, 1, nil, nil },

  { "recip", "x^-1", "op", 0, 5.6, 1, 1, "MATRIX", "D" },
  { "sin", "SIN", "fn", 1, 5.6, 1, 1, "SIN^-1", "E" },
  { "cos", "COS", "fn", 2, 5.6, 1, 1, "COS^-1", "F" },
  { "tan", "TAN", "fn", 3, 5.6, 1, 1, "TAN^-1", "G" },
  { "power", "^", "op", 4, 5.6, 1, 1, "pi", "H" },

  { "square", "x^2", "op", 0, 6.8, 1, 1, "sqrt", "I" },
  { "comma", ",", "op", 1, 6.8, 1, 1, "EE", "J" },
  { "lparen", "(", "op", 2, 6.8, 1, 1, "{", "K" },
  { "rparen", ")", "op", 3, 6.8, 1, 1, "}", "L" },
  { "div", "/", "blue_op", 4, 6.8, 1, 1, "e", "M" },

  { "log", "LOG", "fn", 0, 8.0, 1, 1, "10^x", "N" },
  { "7", "7", "num", 1, 8.0, 1, 1, "u", "O" },
  { "8", "8", "num", 2, 8.0, 1, 1, "v", "P" },
  { "9", "9", "num", 3, 8.0, 1, 1, "w", "Q" },
  { "mul", "*", "blue_op", 4, 8.0, 1, 1, "[", "R" },

  { "ln", "LN", "fn", 0, 9.2, 1, 1, "e^x", "S" },
  { "4", "4", "num", 1, 9.2, 1, 1, "L4", "T" },
  { "5", "5", "num", 2, 9.2, 1, 1, "L5", "U" },
  { "6", "6", "num", 3, 9.2, 1, 1, "L6", "V" },
  { "minus", "-", "blue_op", 4, 9.2, 1, 1, "]", "W" },

  { "sto", "STO>", "fn", 0, 10.4, 1, 1, "RCL", "X" },
  { "1", "1", "num", 1, 10.4, 1, 1, "L1", "Y" },
  { "2", "2", "num", 2, 10.4, 1, 1, "L2", "Z" },
  { "3", "3", "num", 3, 10.4, 1, 1, "L3", "0" },
  { "plus", "+", "blue_op", 4, 10.4, 1, 1, "MEM", '"' },

  { "on", "ON", "on", 0, 11.7, 1, 1, "OFF", nil },
  { "0", "0", "num", 1, 11.7, 1, 1, "CATALOG", "spc" },
  { "dot", ".", "num", 2, 11.7, 1, 1, "i", ":" },
  { "neg", "(-)", "num", 3, 11.7, 1, 1, "ANS", "?" },
  { "enter", "ENTER", "enter", 4, 11.7, 1, 1.25, "ENTRY", "SOLVE" },
}

KeypadUI.DESIGN_COLS = 5
KeypadUI.DESIGN_ROWS = 13.2
-- Top black faceplate ends here in design rows (graph/F-keys are [0,1)).
KeypadUI.FKEY_BAND_END = 1.0
-- Key face height / width. Tall enough for 2nd/alpha legend strip + key face.
KeypadUI.FACE_ASPECT = 1.85

function KeypadUI.new()
  local self = setmetatable({}, KeypadUI)
  self.panel = { x = 0, y = 0, w = 0, h = 0 }
  self.buttons = {}
  self.pressed = nil
  self.hover = nil
  self.legend_font = nil
  return self
end

function KeypadUI:_legend_font()
  if self.legend_font then
    return self.legend_font
  end
  local ok, font = pcall(love.graphics.newFont, 10)
  if ok and font then
    font:setFilter("linear", "linear")
    self.legend_font = font
  else
    self.legend_font = love.graphics.getFont()
  end
  return self.legend_font
end

--- Layout keys into rect; width is the face width (matches LCD). Height fills proportionally.
function KeypadUI:layout(x, y, w, h)
  self.panel = { x = x, y = y, w = w, h = h }
  self.buttons = {}
  if w < 40 or h < 40 then
    return
  end

  local cell_w = w / KeypadUI.DESIGN_COLS
  local cell_h = h / KeypadUI.DESIGN_ROWS
  local face_x, face_y = x, y

  local gap_x = math.max(2, cell_w * 0.06)
  local gap_y = math.max(2, cell_h * 0.06)
  -- Reserve a readable strip for yellow 2nd / lightBlue alpha / F-key legends.
  local legend_h = math.max(12, math.min(18, cell_h * 0.34))

  for _, k in ipairs(KEYS) do
    local kw = (k[6] or 1) * cell_w - gap_x
    local kh = (k[7] or 1) * cell_h - gap_y
    local bx = face_x + k[4] * cell_w + gap_x * 0.5
    local by = face_y + k[5] * cell_h + gap_y * 0.5
    local btn_h = math.max(12, kh - legend_h)
    local btn_y = by + legend_h
    self.buttons[#self.buttons + 1] = {
      key = k[1],
      label = k[2],
      style = k[3] or "fn",
      second = k[8],
      alpha = k[9],
      fkey = k[10],
      x = bx,
      y = btn_y,
      w = math.max(12, kw),
      h = btn_h,
      legend_y = by,
      legend_h = legend_h,
    }
  end
end

function KeypadUI:contains(mx, my)
  local p = self.panel
  return p.w > 0 and mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h
end

function KeypadUI:hit_button(mx, my)
  for _, b in ipairs(self.buttons) do
    if mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h then
      return b
    end
  end
  return nil
end

function KeypadUI:mousepressed(mx, my)
  if not self:contains(mx, my) then
    return false
  end
  local b = self:hit_button(mx, my)
  if b then
    self.pressed = b.key
    return true, "press", b.key
  end
  return true
end

function KeypadUI:mousemoved(mx, my)
  local b = self:hit_button(mx, my)
  self.hover = b and b.key or nil
end

function KeypadUI:mousereleased()
  local k = self.pressed
  self.pressed = nil
  return k
end

local function draw_label(font, text, x, y, w, h, r, g, b, a, align)
  if not text or text == "" then return end
  local prev = love.graphics.getFont()
  love.graphics.setFont(font)
  local tw = font:getWidth(text)
  local th = font:getHeight()
  local scale = 1
  if tw > w - 2 then
    scale = (w - 2) / tw
  end
  if th * scale > h then
    scale = math.min(scale, h / th)
  end
  -- Prefer truncating legend text over shrinking below ~70%.
  local draw = text
  if scale < 0.7 and #text > 1 then
    scale = 0.7
    while #draw > 1 and font:getWidth(draw) * scale > w - 2 do
      draw = draw:sub(1, -2)
    end
    tw = font:getWidth(draw)
  end
  local px
  if align == "left" then
    px = x + 1
  elseif align == "right" then
    px = x + w - tw * scale - 1
  else
    px = x + (w - tw * scale) / 2
  end
  love.graphics.setColor(r, g, b, a or 1)
  love.graphics.print(draw, px, y + (h - th * scale) / 2, 0, scale, scale)
  love.graphics.setFont(prev)
end

local function label_rgb(style)
  if style == "second" or style == "num" then
    return COL.black[1], COL.black[2], COL.black[3]
  end
  return COL.white[1], COL.white[2], COL.white[3]
end

function KeypadUI:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end

  -- Gray body + black F-key trim (matches CC keypad_view).
  love.graphics.setColor(COL.gray[1], COL.gray[2], COL.gray[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h)
  local band_h = p.h * (KeypadUI.FKEY_BAND_END / KeypadUI.DESIGN_ROWS)
  love.graphics.setColor(COL.black[1], COL.black[2], COL.black[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, band_h)

  local font = love.graphics.getFont()
  local legend_font = self:_legend_font()

  for _, b in ipairs(self.buttons) do
    local ly, lh = b.legend_y, b.legend_h
    local on_fkey_band = b.fkey ~= nil
    if b.second or b.alpha or b.fkey then
      if on_fkey_band then
        love.graphics.setColor(COL.black[1], COL.black[2], COL.black[3], 1)
      else
        love.graphics.setColor(COL.gray[1], COL.gray[2], COL.gray[3], 1)
      end
      love.graphics.rectangle("fill", b.x, ly, b.w, lh)
    end

    -- Top graph row: yellow 2nd left, lightBlue F1-F5 right (CC order).
    if b.fkey then
      if b.second then
        draw_label(legend_font, b.second, b.x, ly, b.w * 0.62, lh, COL_2ND[1], COL_2ND[2], COL_2ND[3], 1, "left")
      end
      draw_label(legend_font, b.fkey, b.x, ly, b.w, lh, COL_FKEY[1], COL_FKEY[2], COL_FKEY[3], 1, "right")
    elseif b.second and b.alpha then
      draw_label(legend_font, b.second, b.x, ly, b.w * 0.62, lh, COL_2ND[1], COL_2ND[2], COL_2ND[3], 1, "left")
      draw_label(legend_font, b.alpha, b.x + b.w * 0.38, ly, b.w * 0.62, lh, COL_ALPHA[1], COL_ALPHA[2], COL_ALPHA[3], 1, "right")
    elseif b.second then
      draw_label(legend_font, b.second, b.x, ly, b.w, lh, COL_2ND[1], COL_2ND[2], COL_2ND[3], 1, "left")
    elseif b.alpha then
      draw_label(legend_font, b.alpha, b.x, ly, b.w, lh, COL_ALPHA[1], COL_ALPHA[2], COL_ALPHA[3], 1, "right")
    end

    local base = STYLE[b.style] or STYLE.fn
    local pressed = self.pressed == b.key
    local hover = self.hover == b.key
    if pressed then
      love.graphics.setColor(COL.orange[1], COL.orange[2], COL.orange[3], 1)
    else
      local mul = hover and 1.12 or 1
      love.graphics.setColor(
        math.min(1, base[1] * mul),
        math.min(1, base[2] * mul),
        math.min(1, base[3] * mul),
        1
      )
    end
    local radius = math.min(4, b.h * 0.25)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, radius, radius)
    love.graphics.setColor(0.05, 0.05, 0.05, 0.55)
    love.graphics.rectangle("line", b.x, b.y, b.w, b.h, radius, radius)

    local lr, lg, lb = label_rgb(b.style)
    if pressed then
      lr, lg, lb = COL.black[1], COL.black[2], COL.black[3]
    end
    draw_label(font, b.label, b.x, b.y, b.w, b.h, lr, lg, lb, 1)
  end
end

return KeypadUI
