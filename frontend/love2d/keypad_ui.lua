-- TI-83 Plus keypad under the LCD (fixed part of the calculator pane).

local KeypadUI = {}
KeypadUI.__index = KeypadUI

local PAD = 6

-- Face colors (approximate TI-83+)
local STYLE = {
  graph = { 0.16, 0.28, 0.48 },
  fn = { 0.18, 0.22, 0.30 },
  second = { 0.82, 0.72, 0.18 },
  alpha = { 0.22, 0.55, 0.30 },
  num = { 0.55, 0.56, 0.58 },
  op = { 0.16, 0.28, 0.48 },
  on = { 0.42, 0.14, 0.14 },
  enter = { 0.16, 0.28, 0.48 },
  arrow = { 0.18, 0.22, 0.30 },
}

local COL_2ND = { 0.92, 0.78, 0.18, 1 }
local COL_ALPHA = { 0.35, 0.85, 0.45, 1 }

-- Real TI-83+ face in design units (5 columns × stacked rows).
-- Fields: key, label, style, col, row, w, h, second, alpha
local KEYS = {
  { "yequ", "Y=", "graph", 0, 0, 1, 1, "STAT PLOT", nil },
  { "window", "WINDOW", "graph", 1, 0, 1, 1, "TBLSET", nil },
  { "zoom", "ZOOM", "graph", 2, 0, 1, 1, "FORMAT", nil },
  { "trace", "TRACE", "graph", 3, 0, 1, 1, "CALC", nil },
  { "graph", "GRAPH", "graph", 4, 0, 1, 1, "TABLE", nil },

  { "2nd", "2nd", "second", 0, 1.15, 1, 1, nil, nil },
  { "mode", "MODE", "fn", 1, 1.15, 1, 1, "QUIT", nil },
  { "del", "DEL", "fn", 2, 1.15, 1, 1, "INS", nil },
  { "up", "^", "arrow", 3.5, 1.0, 1, 0.85, nil, nil },

  { "alpha", "ALPHA", "alpha", 0, 2.3, 1, 1, "A-LOCK", nil },
  { "xt", "X,T,n", "fn", 1, 2.3, 1, 1, "LINK", nil },
  { "stat", "STAT", "fn", 2, 2.3, 1, 1, "LIST", nil },
  { "left", "<", "arrow", 3.0, 2.15, 0.9, 0.85, nil, nil },
  { "right", ">", "arrow", 4.1, 2.15, 0.9, 0.85, nil, nil },

  { "down", "v", "arrow", 3.5, 3.15, 1, 0.85, nil, nil },

  { "math", "MATH", "fn", 0, 4.2, 1, 1, "TEST", "A" },
  { "apps", "APPS", "fn", 1, 4.2, 1, 1, "ANGLE", "B" },
  { "prgm", "PRGM", "fn", 2, 4.2, 1, 1, "DRAW", "C" },
  { "vars", "VARS", "fn", 3, 4.2, 1, 1, "DISTR", nil },
  { "clear", "CLEAR", "fn", 4, 4.2, 1, 1, nil, nil },

  -- Green alpha legends match real TI-83+ / OS 1.19 (D on x^-1, O/P/Q/R on 7/8/9/×).
  { "recip", "x^-1", "op", 0, 5.35, 1, 1, "MATRIX", "D" },
  { "sin", "SIN", "fn", 1, 5.35, 1, 1, "SIN^-1", "E" },
  { "cos", "COS", "fn", 2, 5.35, 1, 1, "COS^-1", "F" },
  { "tan", "TAN", "fn", 3, 5.35, 1, 1, "TAN^-1", "G" },
  { "power", "^", "op", 4, 5.35, 1, 1, "pi", "H" },

  { "square", "x^2", "op", 0, 6.5, 1, 1, "sqrt", "I" },
  { "comma", ",", "op", 1, 6.5, 1, 1, "EE", "J" },
  { "lparen", "(", "op", 2, 6.5, 1, 1, "{", "K" },
  { "rparen", ")", "op", 3, 6.5, 1, 1, "}", "L" },
  { "div", "/", "op", 4, 6.5, 1, 1, "e", "M" },

  { "log", "LOG", "fn", 0, 7.65, 1, 1, "10^x", "N" },
  { "7", "7", "num", 1, 7.65, 1, 1, "u", "O" },
  { "8", "8", "num", 2, 7.65, 1, 1, "v", "P" },
  { "9", "9", "num", 3, 7.65, 1, 1, "w", "Q" },
  { "mul", "*", "op", 4, 7.65, 1, 1, "[", "R" },

  { "ln", "LN", "fn", 0, 8.8, 1, 1, "e^x", "S" },
  { "4", "4", "num", 1, 8.8, 1, 1, "L4", "T" },
  { "5", "5", "num", 2, 8.8, 1, 1, "L5", "U" },
  { "6", "6", "num", 3, 8.8, 1, 1, "L6", "V" },
  { "minus", "-", "op", 4, 8.8, 1, 1, "]", "W" },

  { "sto", "STO>", "fn", 0, 9.95, 1, 1, "RCL", "X" },
  { "1", "1", "num", 1, 9.95, 1, 1, "L1", "Y" },
  { "2", "2", "num", 2, 9.95, 1, 1, "L2", "Z" },
  { "3", "3", "num", 3, 9.95, 1, 1, "L3", "theta" },
  { "plus", "+", "op", 4, 9.95, 1, 1, "MEM", '"' },

  { "on", "ON", "on", 0, 11.1, 1, 1, "OFF", nil },
  { "0", "0", "num", 1, 11.1, 1, 1, "CATALOG", "spc" },
  { "dot", ".", "num", 2, 11.1, 1, 1, "i", ":" },
  { "neg", "(-)", "num", 3, 11.1, 1, 1, "ANS", "?" },
  { "enter", "ENTER", "enter", 4, 11.1, 1, 1.15, "ENTRY", "SOLVE" },
}

KeypadUI.DESIGN_COLS = 5
KeypadUI.DESIGN_ROWS = 12.4
-- Key face height / width. Below 1:1 cell ratio so buttons aren't overly tall.
KeypadUI.FACE_ASPECT = 1.7

function KeypadUI.new()
  local self = setmetatable({}, KeypadUI)
  self.panel = { x = 0, y = 0, w = 0, h = 0 }
  self.buttons = {}
  self.pressed = nil
  self.hover = nil
  return self
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
  local gap_y = math.max(2, cell_h * 0.08)
  local legend_h = math.max(9, math.min(14, cell_h * 0.22))

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

local function draw_label(font, text, x, y, w, h, r, g, b, a)
  if not text or text == "" then return end
  local tw = font:getWidth(text)
  local th = font:getHeight()
  local scale = 1
  if tw > w - 2 then
    scale = (w - 2) / tw
  end
  if th * scale > h then
    scale = math.min(scale, h / th)
  end
  love.graphics.setColor(r, g, b, a or 1)
  love.graphics.print(text, x + (w - tw * scale) / 2, y + (h - th * scale) / 2, 0, scale, scale)
end

function KeypadUI:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end

  -- No separate pane chrome — parent calculator face provides the body.
  local font = love.graphics.getFont()

  for _, b in ipairs(self.buttons) do
    local ly, lh = b.legend_y, b.legend_h
    if b.second then
      draw_label(font, b.second, b.x, ly, b.w * 0.58, lh, COL_2ND[1], COL_2ND[2], COL_2ND[3], 1)
    end
    if b.alpha then
      local ax = b.x + b.w * 0.42
      draw_label(font, b.alpha, ax, ly, b.w * 0.58, lh, COL_ALPHA[1], COL_ALPHA[2], COL_ALPHA[3], 1)
    end

    local base = STYLE[b.style] or STYLE.fn
    local pressed = self.pressed == b.key
    local hover = self.hover == b.key
    local mul = pressed and 1.35 or (hover and 1.15 or 1)
    love.graphics.setColor(
      math.min(1, base[1] * mul),
      math.min(1, base[2] * mul),
      math.min(1, base[3] * mul),
      1
    )
    local radius = math.min(4, b.h * 0.25)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, radius, radius)
    love.graphics.setColor(0.08, 0.08, 0.08, 0.45)
    love.graphics.rectangle("line", b.x, b.y, b.w, b.h, radius, radius)

    if b.style == "second" then
      draw_label(font, b.label, b.x, b.y, b.w, b.h, 0.12, 0.10, 0.05, 1)
    elseif b.style == "alpha" then
      draw_label(font, b.label, b.x, b.y, b.w, b.h, 0.95, 0.98, 0.92, 1)
    elseif b.style == "num" then
      draw_label(font, b.label, b.x, b.y, b.w, b.h, 0.12, 0.12, 0.12, 1)
    elseif b.style == "on" then
      draw_label(font, b.label, b.x, b.y, b.w, b.h, 0.95, 0.85, 0.75, 1)
    else
      draw_label(font, b.label, b.x, b.y, b.w, b.h, 0.94, 0.96, 0.92, 1)
    end
  end
end

return KeypadUI
