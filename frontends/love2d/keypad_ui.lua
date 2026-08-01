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

-- Face colors matching CC keypad_view styles (TI-83+ defaults).
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

local DEFAULT_THEME = {
  col = COL,
  style = STYLE,
  body = COL.gray,
  fkey_band = COL.black,
  legend_2nd = COL_2ND,
  legend_alpha = COL_ALPHA,
  legend_fkey = COL_FKEY,
  press = COL.orange,
}

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

--- opts.theme overrides body / key / legend colors (see DEFAULT_THEME / keypad_ti84).
--- opts.layout is a ti-keypad-layout doc (from ui/keypads/<machine>.lua).
function KeypadUI.new(opts)
  opts = opts or {}
  local theme = opts.theme or DEFAULT_THEME
  local self = setmetatable({}, KeypadUI)
  self.panel = { x = 0, y = 0, w = 0, h = 0 }
  self.buttons = {}
  self.pressed = nil
  self.hover = nil
  self.legend_font = nil
  self._font_cache = {}
  self.col = theme.col or DEFAULT_THEME.col
  self.style = theme.style or DEFAULT_THEME.style
  self.body = theme.body or DEFAULT_THEME.body
  self.fkey_band = theme.fkey_band or DEFAULT_THEME.fkey_band
  self.legend_2nd = theme.legend_2nd or DEFAULT_THEME.legend_2nd
  self.legend_alpha = theme.legend_alpha or DEFAULT_THEME.legend_alpha
  self.legend_fkey = theme.legend_fkey or DEFAULT_THEME.legend_fkey
  self.press_col = theme.press or DEFAULT_THEME.press
  self.default_label_size = 12
  self.default_legend_size = 9
  self.keys = KEYS
  self.decor = {}
  self.design_cols = KeypadUI.DESIGN_COLS
  self.design_rows = KeypadUI.DESIGN_ROWS
  self.fkey_band_end = KeypadUI.FKEY_BAND_END
  self.face_aspect = KeypadUI.FACE_ASPECT
  self.panel_radius_u = 0
  self.layout_doc = nil
  self:_apply_layout(opts.layout)
  return self
end

function KeypadUI:_apply_layout(doc)
  if not doc then
    return
  end
  local Layouts = require("keypad_layouts")
  self.keys = Layouts.to_legacy_rows(doc, "83")
  self.decor = Layouts.decor_labels(doc)
  self.design_cols = doc.design_cols or KeypadUI.DESIGN_COLS
  self.design_rows = doc.design_rows or KeypadUI.DESIGN_ROWS
  self.fkey_band_end = (doc.plate and doc.plate.fkey_band_end) or KeypadUI.FKEY_BAND_END
  self.face_aspect = doc.face_aspect or KeypadUI.FACE_ASPECT
  self.layout_doc = doc
  local theme = Layouts.theme_for_keypad_ui(doc)
  if theme then
    if theme.style and next(theme.style) then self.style = theme.style end
    if theme.body then self.body = theme.body end
    if theme.fkey_band then self.fkey_band = theme.fkey_band end
    if theme.legend_2nd then self.legend_2nd = theme.legend_2nd end
    if theme.legend_alpha then self.legend_alpha = theme.legend_alpha end
    if theme.legend_fkey then self.legend_fkey = theme.legend_fkey end
    if theme.press then self.press_col = theme.press end
    if theme.label_size then self.default_label_size = theme.label_size end
    if theme.legend_size then self.default_legend_size = theme.legend_size end
    self.panel_radius_u = theme.panel_radius or 0
    if theme.col then
      for k, v in pairs(theme.col) do self.col[k] = v end
    end
  end
end

function KeypadUI:reload_layout(doc)
  self:_apply_layout(doc)
end

function KeypadUI:_font(px)
  px = math.max(1, math.floor((tonumber(px) or 12) + 0.5))
  self._font_cache = self._font_cache or {}
  local cached = self._font_cache[px]
  if cached then return cached end
  local ok, font = pcall(love.graphics.newFont, px)
  if ok and font then
    font:setFilter("linear", "linear")
    self._font_cache[px] = font
    return font
  end
  return love.graphics.getFont()
end

function KeypadUI:_legend_font()
  return self:_font(self.default_legend_size or 9)
end

--- Layout keys into rect; width is the face width (matches LCD). Height fills proportionally.
function KeypadUI:layout(x, y, w, h)
  self.panel = { x = x, y = y, w = w, h = h }
  self.buttons = {}
  if w < 40 or h < 40 then
    return
  end

  local cols = self.design_cols or KeypadUI.DESIGN_COLS
  local rows = self.design_rows or KeypadUI.DESIGN_ROWS
  local Layouts = require("keypad_layouts")
  -- Isotropic unit: key size ignores plate aspect (plate is just a backdrop).
  local unit = Layouts.grid_unit(w, h, cols, rows)
  self._design_unit = unit
  local face_x, face_y = x, y

  local gap_x = math.max(1, unit * 0.06)
  local gap_y = math.max(1, unit * 0.06)
  local legend_h = math.max(3, unit * 0.34)

  local def_label = self.default_label_size or 12
  local def_legend = self.default_legend_size or 9
  for _, k in ipairs(self.keys or KEYS) do
    local kw = (k[6] or 1) * unit - gap_x
    local kh = (k[7] or 1) * unit - gap_y
    local bx = face_x + k[4] * unit + gap_x * 0.5
    local by = face_y + k[5] * unit + gap_y * 0.5
    local btn_h = math.max(4, kh - legend_h)
    local btn_y = by + legend_h
    local btn_w = math.max(4, kw)
    local shape = k.shape or "auto"
    if shape == "circle" then
      local d = math.min(btn_w, btn_h)
      bx = bx + (btn_w - d) * 0.5
      btn_w, btn_h = d, d
    end
    local rad_u = tonumber(k.radius) or 0.12
    local radius = math.max(0, rad_u * unit)
    if shape == "circle" then
      radius = btn_w * 0.5
    end
    self.buttons[#self.buttons + 1] = {
      key = k[1],
      label = k[2],
      style = k[3] or "fn",
      second = k[8],
      alpha = k[9],
      fkey = k[10],
      color = k.color,
      label_color = k.label_color,
      radius = radius,
      label_size = Layouts.font_px(k.label_size, unit, def_label),
      legend_size = Layouts.font_px(k.legend_size, unit, def_legend),
      outline = k.outline or "auto",
      outline_color = k.outline_color,
      outline_alpha = k.outline_alpha,
      outline_width = k.outline_width,
      outline_inset = k.outline_inset,
      shape = shape,
      face_glyph = k.face_glyph or "auto",
      x = bx,
      y = btn_y,
      w = btn_w,
      h = btn_h,
      legend_y = by,
      legend_h = legend_h,
      legend_x = face_x + k[4] * unit + gap_x * 0.5,
      legend_w = math.max(4, (k[6] or 1) * unit - gap_x),
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

-- Face labels truncate; legends pass overflow=true so they may overlap neighbors.
local function draw_label(font, text, x, y, w, h, r, g, b, a, align, overflow)
  if not text or text == "" then return end
  local prev = love.graphics.getFont()
  love.graphics.setFont(font)
  local draw = text
  local tw = font:getWidth(draw)
  local th = font:getHeight()
  if not overflow and tw > w - 2 and #draw > 1 then
    while #draw > 1 and font:getWidth(draw) > w - 2 do
      draw = draw:sub(1, -2)
    end
    tw = font:getWidth(draw)
  end
  local px
  if align == "left" then
    px = x + 1
  elseif align == "right" then
    px = x + w - tw - 1
  else
    px = x + (w - tw) / 2
  end
  love.graphics.setColor(r, g, b, a or 1)
  love.graphics.print(draw, px, y + (h - th) / 2)
  love.graphics.setFont(prev)
end

local function label_rgb(self, style)
  local col = self.col
  local face = self.style[style]
  -- Light faces (nums, cream ops, yellow 2nd, gray graph) get dark glyphs.
  if face and (face[1] + face[2] + face[3]) > 1.55 then
    return col.black[1], col.black[2], col.black[3]
  end
  return col.white[1], col.white[2], col.white[3]
end

local function draw_arrow_glyph(cx, cy, size, dir, r, g, b)
  local s = size * 0.32
  love.graphics.setColor(r, g, b, 1)
  if dir == "up" then
    love.graphics.polygon("fill", cx, cy - s, cx - s, cy + s * 0.6, cx + s, cy + s * 0.6)
  elseif dir == "down" then
    love.graphics.polygon("fill", cx, cy + s, cx - s, cy - s * 0.6, cx + s, cy - s * 0.6)
  elseif dir == "left" then
    love.graphics.polygon("fill", cx - s, cy, cx + s * 0.6, cy - s, cx + s * 0.6, cy + s)
  else
    love.graphics.polygon("fill", cx + s, cy, cx - s * 0.6, cy - s, cx - s * 0.6, cy + s)
  end
end

function KeypadUI:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end

  local body, band = self.body, self.fkey_band
  local rows = self.design_rows or KeypadUI.DESIGN_ROWS
  local cols = self.design_cols or KeypadUI.DESIGN_COLS
  local Layouts = require("keypad_layouts")
  local unit = self._design_unit or Layouts.grid_unit(p.w, p.h, cols, rows)
  local plate_r = math.max(0, (self.panel_radius_u or 0) * unit)
  love.graphics.setColor(body[1], body[2], body[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h, plate_r, plate_r)
  local band_end = self.fkey_band_end or KeypadUI.FKEY_BAND_END
  local band_h = p.h * (band_end / rows)
  love.graphics.setColor(band[1], band[2], band[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, band_h, plate_r, plate_r)

  local L2, LA, LF = self.legend_2nd, self.legend_alpha, self.legend_fkey
  local press = self.press_col

  for _, d in ipairs(self.decor or {}) do
    local dx = p.x + d.x * unit
    local dy = p.y + d.y * unit
    local dw = d.w * unit
    local dh = d.h * unit
    local lr, lg, lb = label_rgb(self, d.style)
    if d.label_color then
      lr, lg, lb = d.label_color[1], d.label_color[2], d.label_color[3]
    end
    local dfont = self:_font(Layouts.font_px(d.label_size, unit, self.default_label_size or 12))
    draw_label(dfont, d.label, dx, dy, dw, dh, lr, lg, lb, 1)
  end

  for _, b in ipairs(self.buttons) do
    local ly, lh = b.legend_y, b.legend_h
    -- label_size / legend_size are already scaled to screen px in :layout.
    local legend_font = self:_font(b.legend_size or Layouts.font_px(nil, unit, self.default_legend_size or 9))
    local face_font = self:_font(b.label_size or Layouts.font_px(nil, unit, self.default_label_size or 12))
    -- No per-key legend wipe: plate already fills the strip; legends may overlap.
    if b.fkey then
      if b.second then
        draw_label(legend_font, b.second, b.x, ly, b.w * 0.62, lh, L2[1], L2[2], L2[3], 1, "left", true)
      end
      draw_label(legend_font, b.fkey, b.x, ly, b.w, lh, LF[1], LF[2], LF[3], 1, "right", true)
    elseif b.second and b.alpha then
      draw_label(legend_font, b.second, b.x, ly, b.w * 0.62, lh, L2[1], L2[2], L2[3], 1, "left", true)
      draw_label(legend_font, b.alpha, b.x + b.w * 0.38, ly, b.w * 0.62, lh, LA[1], LA[2], LA[3], 1, "right", true)
    elseif b.second then
      draw_label(legend_font, b.second, b.x, ly, b.w, lh, L2[1], L2[2], L2[3], 1, "left", true)
    elseif b.alpha then
      draw_label(legend_font, b.alpha, b.x, ly, b.w, lh, LA[1], LA[2], LA[3], 1, "right", true)
    end

    local base = b.color or self.style[b.style] or self.style.fn
    local pressed = self.pressed == b.key
    local hover = self.hover == b.key
    if pressed then
      love.graphics.setColor(press[1], press[2], press[3], 1)
    else
      local mul = hover and 1.12 or 1
      love.graphics.setColor(
        math.min(1, base[1] * mul),
        math.min(1, base[2] * mul),
        math.min(1, base[3] * mul),
        1
      )
    end
    local radius = b.radius
    if not radius then
      radius = math.min(4, b.h * 0.25)
    end
    radius = math.min(radius, b.w * 0.5, b.h * 0.5)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, radius, radius)
    Layouts.draw_outline(b.x, b.y, b.w, b.h, radius, b.shape == "circle", Layouts.resolve_outline(b, b.style))

    local lr, lg, lb
    if b.label_color then
      lr, lg, lb = b.label_color[1], b.label_color[2], b.label_color[3]
    elseif b.color then
      if (b.color[1] + b.color[2] + b.color[3]) > 1.55 then
        lr, lg, lb = self.col.black[1], self.col.black[2], self.col.black[3]
      else
        lr, lg, lb = self.col.white[1], self.col.white[2], self.col.white[3]
      end
    else
      lr, lg, lb = label_rgb(self, b.style)
    end
    if pressed and not b.label_color then
      lr, lg, lb = self.col.black[1], self.col.black[2], self.col.black[3]
    end
    local glyph = b.face_glyph or "auto"
    -- 83/84 keep text labels by default; set face_glyph explicitly for icons.
    if glyph == "arrow_up" or glyph == "arrow_down" or glyph == "arrow_left" or glyph == "arrow_right" then
      local cx, cy = b.x + b.w * 0.5, b.y + b.h * 0.5
      draw_arrow_glyph(cx, cy, math.min(b.w, b.h), glyph:sub(7), lr, lg, lb)
    else
      draw_label(face_font, b.label, b.x, b.y, b.w, b.h, lr, lg, lb, 1)
    end
  end
end

return KeypadUI
