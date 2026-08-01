-- TI-89 Titanium on-screen keypad (portrait), TI-83-style 5-column grid.
-- Physical face (retail Titanium / classic TI-89 arrangement):
--   Left col:  2nd, ◆, HOME, X, =, |, EE, STO, ON
--   Right col: CLEAR, ^, ÷, ×, −, +, ENTER
--   HOME MODE CATALOG ← CLEAR are one equal-sized row.
-- Legends from TI-89 Titanium AMS key-code tables.
-- Button `key` names match machines.ti89.hw.keyboard (89hw matrix).
-- Fields: key, label, style, col, row, w, h [, second, diamond, alpha]

local Keypad = {}
Keypad.__index = Keypad

local COL = {
  body = { 0.24, 0.26, 0.28 },
  body_inner = { 0.15, 0.16, 0.17 },
  silver = { 0.55, 0.57, 0.58 },
  key = { 0.38, 0.40, 0.42 },
  key_dark = { 0.17, 0.18, 0.19 },
  -- 2nd key / legends: light blue (Titanium face uses cool 2nd ink).
  second = { 0.45, 0.72, 0.95 },
  -- Diamond key / legends: light lime green.
  diamond = { 0.62, 0.92, 0.38 },
  alpha = { 0.93, 0.93, 0.95 },
  shift = { 0.42, 0.44, 0.46 }, -- gray face
  white = { 0.97, 0.97, 0.98 },
  black = { 0.05, 0.05, 0.06 },
  orange = { 0.90, 0.48, 0.12 },
  legend2 = { 0.55, 0.78, 0.98 },
  legendd = { 0.72, 0.95, 0.45 },
  legend_alpha = { 0.95, 0.95, 0.97 },
}

local STYLE = {
  fn = COL.key_dark,
  num = COL.key,
  enter = COL.key_dark,
  arrow = COL.key_dark,
  second = COL.second,
  diamond = COL.diamond,
  alpha = COL.alpha,
  shift = COL.shift,
  on = COL.key_dark,
  fkey = COL.key_dark,
}

-- Real TI-89 Titanium face in design units (5 columns × stacked rows).
-- F-keys / arrows share one circle size; math pad is a tight 1×1 grid.
local FKEY_SIZE = 1.14 -- 5% under prior 1.20
local PITCH = 1.05 -- vertical step between equal rows (tighter than TI-83's 1.2)
local KEYS = {
  -- F1–F5: 2nd = F6–F8 (yellow, left); diamond = Y=/WINDOW/… (green, right)
  { "f1", "F1", "fkey", 0, 0, 1, FKEY_SIZE, "F6", "Y=", nil },
  { "f2", "F2", "fkey", 1, 0, 1, FKEY_SIZE, "F7", "WINDOW", nil },
  { "f3", "F3", "fkey", 2, 0, 1, FKEY_SIZE, "F8", "GRAPH", nil },
  { "f4", "F4", "fkey", 3, 0, 1, FKEY_SIZE, nil, "TblSet", nil },
  { "f5", "F5", "fkey", 4, 0, 1, FKEY_SIZE, nil, "TABLE", nil },

  -- Arrow cluster: glyphs drawn geometrically (Love default fonts lack ▲◀▶▼)
  { "up", "up", "arrow", 3.5, 1.22, 1, FKEY_SIZE, nil, nil, nil },
  { "left", "left", "arrow", 3.0, 2.05, 1, FKEY_SIZE, nil, nil, nil },
  { "right", "right", "arrow", 4.0, 2.05, 1, FKEY_SIZE, nil, nil, nil },
  { "down", "down", "arrow", 3.5, 2.88, 1, FKEY_SIZE, nil, nil, nil },

  -- Modifiers: diamond CUT / COPY / PASTE above 2nd / SHIFT / ESC
  { "2nd", "2nd", "second", 0, 1.85, 1, 1, nil, "CUT", nil },
  { "shift", "shift", "shift", 1, 1.85, 1, 1, nil, "COPY", nil },
  { "esc", "ESC", "fn", 2, 1.85, 1, 1, "QUIT", "PASTE", nil },

  { "diamond", "diamond", "diamond", 0, 2.90, 1, 1, nil, nil, nil },
  { "alpha", "ALPHA", "alpha", 1, 2.90, 1, 1, "a-lock", nil, nil },
  { "apps", "APPS", "fn", 2, 2.90, 1, 1, nil, nil, nil },

  -- HOME MODE CATALOG ← CLEAR  (AMS / Titanium face legends)
  { "home", "HOME", "fn", 0, 3.95, 1, 1, "CUSTOM", nil, nil },
  { "mode", "MODE", "fn", 1, 3.95, 1, 1, "switch", nil, nil }, -- 2nd: app-switch icon
  { "catalog", "CATALOG", "fn", 2, 3.95, 1, 1, "inf_i", nil, nil }, -- ∞ and i
  { "backspace", "bs", "fn", 3, 3.95, 1, 1, "INS", "DEL", nil }, -- face = ←
  { "clear", "CLEAR", "fn", 4, 3.95, 1, 1, nil, nil, nil },

  -- X Y Z T ^  (ASCII legends — no superscript / Greek tofu)
  { "x", "X", "fn", 0, 3.95 + PITCH, 1, 1, "LN", "e^x", nil },
  { "y", "Y", "fn", 1, 3.95 + PITCH, 1, 1, "SIN", "SIN-1", nil },
  { "z", "Z", "fn", 2, 3.95 + PITCH, 1, 1, "COS", "COS-1", nil },
  { "t", "T", "fn", 3, 3.95 + PITCH, 1, 1, "TAN", "TAN-1", nil },
  { "power", "^", "fn", 4, 3.95 + PITCH, 1, 1, "pi", "theta", nil },

  -- = ( ) , /   (= 2nd is # indirection)
  { "equals", "=", "fn", 0, 3.95 + 2 * PITCH, 1, 1, "#", nil, "a" },
  { "lparen", "(", "fn", 1, 3.95 + 2 * PITCH, 1, 1, "{", nil, "b" },
  { "rparen", ")", "fn", 2, 3.95 + 2 * PITCH, 1, 1, "}", nil, "c" },
  { "comma", ",", "fn", 3, 3.95 + 2 * PITCH, 1, 1, "[", nil, "d" },
  { "div", "/", "fn", 4, 3.95 + 2 * PITCH, 1, 1, "]", nil, "e" },

  -- | 7 8 9 *   (| 2nd is degree ¡)
  { "pipe", "|", "fn", 0, 3.95 + 3 * PITCH, 1, 1, "deg", nil, "f" },
  { "7", "7", "num", 1, 3.95 + 3 * PITCH, 1, 1, nil, nil, "g" },
  { "8", "8", "num", 2, 3.95 + 3 * PITCH, 1, 1, nil, nil, "h" },
  { "9", "9", "num", 3, 3.95 + 3 * PITCH, 1, 1, nil, nil, "i" },
  { "mul", "*", "fn", 4, 3.95 + 3 * PITCH, 1, 1, "sqrt", nil, "j" },

  -- EE 4 5 6 -   (EE 2nd is angle ∠)
  { "ee", "EE", "fn", 0, 3.95 + 4 * PITCH, 1, 1, "angle", nil, "k" },
  { "4", "4", "num", 1, 3.95 + 4 * PITCH, 1, 1, ":", nil, "l" },
  -- MATH / MEM / VAR-LINK / CHAR are 2nd (blue), not diamond.
  { "5", "5", "num", 2, 3.95 + 4 * PITCH, 1, 1, "MATH", nil, "m" },
  { "6", "6", "num", 3, 3.95 + 4 * PITCH, 1, 1, "MEM", nil, "n" },
  { "minus", "-", "fn", 4, 3.95 + 4 * PITCH, 1, 1, "VAR-LINK", nil, "o" },

  -- STO 1 2 3 +
  { "sto", "STO", "fn", 0, 3.95 + 5 * PITCH, 1, 1, "RCL", nil, "p" },
  { "1", "1", "num", 1, 3.95 + 5 * PITCH, 1, 1, '"', nil, "q" },
  { "2", "2", "num", 2, 3.95 + 5 * PITCH, 1, 1, nil, nil, "r" },
  { "3", "3", "num", 3, 3.95 + 5 * PITCH, 1, 1, nil, nil, "s" },
  { "plus", "+", "fn", 4, 3.95 + 5 * PITCH, 1, 1, "CHAR", nil, "u" },

  -- ON 0 . (-) ENTER
  { "on", "ON", "on", 0, 3.95 + 6 * PITCH, 1, 1, "OFF", nil, nil },
  { "0", "0", "num", 1, 3.95 + 6 * PITCH, 1, 1, "<", nil, "v" },
  { "dot", ".", "num", 2, 3.95 + 6 * PITCH, 1, 1, ">", nil, "w" },
  { "neg", "(-)", "num", 3, 3.95 + 6 * PITCH, 1, 1, "ANS", nil, "spc" },
  { "enter", "ENTER", "enter", 4, 3.95 + 6 * PITCH, 1, 1, "ENTRY", "~", nil },
}

Keypad.DESIGN_COLS = 5
Keypad.DESIGN_ROWS = 3.95 + 7 * PITCH + 0.05 -- last row start + key height + pad
Keypad.FACE_ASPECT = 1.62
Keypad.FKEY_BAND_END = FKEY_SIZE

--- Outer width from F1's left edge to F5's right edge (circular faces).
--- Matches Keypad:layout geometry so the LCD can align with the F-key band.
function Keypad.fkey_band_width(panel_w, panel_h)
  if not panel_w or panel_w < 40 or not panel_h or panel_h < 40 then
    return panel_w or 0
  end
  local Layouts = require("keypad_layouts")
  local unit = Layouts.grid_unit(panel_w, panel_h, Keypad.DESIGN_COLS, Keypad.DESIGN_ROWS)
  local gap_x = math.max(1.5, unit * 0.05)
  local gap_y = math.max(1.0, unit * 0.04)
  local legend_h = math.max(6, unit * 0.26)
  local kw = unit - gap_x
  local kh = FKEY_SIZE * unit - gap_y
  local lh = math.max(6, math.min(legend_h * 0.7, unit * 0.2))
  local face_h = math.max(10, kh - lh)
  local d = math.min(kw, face_h)
  -- F1 at col 0, F5 at col 4: span = 4 cells + one circle diameter.
  return 4 * unit + d
end

function Keypad.new(opts)
  opts = opts or {}
  local self = setmetatable({}, Keypad)
  self.panel = { x = 0, y = 0, w = 0, h = 0 }
  self.buttons = {}
  self.pressed = nil
  self.hover = nil
  self._font_cache = {}
  self.keys = KEYS
  self.design_cols = Keypad.DESIGN_COLS
  self.design_rows = Keypad.DESIGN_ROWS
  self.face_aspect = Keypad.FACE_ASPECT
  self.fkey_band_end = Keypad.FKEY_BAND_END
  self.body = COL.body
  self.fkey_band = COL.body_inner
  if opts.layout then
    self:reload_layout(opts.layout)
  end
  return self
end

function Keypad:reload_layout(doc)
  if not doc then return end
  local Layouts = require("keypad_layouts")
  self.keys = Layouts.to_legacy_rows(doc, "89")
  self.design_cols = doc.design_cols or Keypad.DESIGN_COLS
  self.design_rows = doc.design_rows or Keypad.DESIGN_ROWS
  self.face_aspect = doc.face_aspect or Keypad.FACE_ASPECT
  self.fkey_band_end = (doc.plate and doc.plate.fkey_band_end) or Keypad.FKEY_BAND_END
  self.default_label_size = (doc.theme and doc.theme.label_size) or 12
  self.default_legend_size = (doc.theme and doc.theme.legend_size) or 9
  if doc.plate then
    if doc.plate.body then self.body = doc.plate.body end
    if doc.plate.fkey_band then self.fkey_band = doc.plate.fkey_band end
  end
  if doc.theme and doc.theme.styles then
    for name, rgb in pairs(doc.theme.styles) do
      STYLE[name] = { rgb[1], rgb[2], rgb[3] }
    end
  end
  if doc.theme then
    if doc.theme.legend_2nd then COL.legend2 = doc.theme.legend_2nd end
    if doc.theme.legend_shift then COL.legendd = doc.theme.legend_shift end
    if doc.theme.legend_alpha then COL.legend_alpha = doc.theme.legend_alpha end
  end
end

function Keypad:_font(px)
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

function Keypad:layout(x, y, w, h)
  self.panel = { x = x, y = y, w = w, h = h }
  self.buttons = {}
  if w < 40 or h < 40 then return end

  local cols = self.design_cols or Keypad.DESIGN_COLS
  local rows = self.design_rows or Keypad.DESIGN_ROWS
  local Layouts = require("keypad_layouts")
  local unit = Layouts.grid_unit(w, h, cols, rows)
  self._design_unit = unit
  local gap_x = math.max(1, unit * 0.05)
  local gap_y = math.max(1, unit * 0.04)
  local legend_h = math.max(3, unit * 0.26)

  for _, k in ipairs(self.keys or KEYS) do
    local style = k[3] or "fn"
    local kw = (k[6] or 1) * unit - gap_x
    local kh = (k[7] or 1) * unit - gap_y
    local cell_x = x + k[4] * unit + gap_x * 0.5
    local by = y + k[5] * unit + gap_y * 0.5
    local circular = style == "fkey" or style == "arrow"
    local lh = circular and math.max(3, math.min(legend_h * 0.7, unit * 0.2)) or legend_h
    local face_h = circular and math.max(4, kh - lh) or math.max(4, kh - legend_h)
    local face_w = kw
    local bx = cell_x
    if circular then
      local d = math.min(kw, face_h)
      face_w, face_h = d, d
      bx = cell_x + (kw - d) * 0.5
    end
    local shape = k.shape or "auto"
    local want_circle = (shape == "circle")
      or (shape == "auto" and (style == "fkey" or style == "arrow"))
    if shape == "rect" then
      want_circle = false
      -- Rebuild as full cell face when forcing rect.
      face_w, face_h = kw, math.max(4, kh - (circular and lh or legend_h))
      bx = cell_x
    elseif want_circle and not circular then
      -- Force circle even if style wasn't fkey/arrow.
      local d = math.min(kw, math.max(4, kh - legend_h))
      face_w, face_h = d, d
      bx = cell_x + (kw - d) * 0.5
      lh = math.max(3, math.min(legend_h * 0.7, unit * 0.2))
    end
    local btn_y = by + ((want_circle or circular) and lh or legend_h)
    self.buttons[#self.buttons + 1] = {
      key = k[1],
      label = k[2],
      style = style,
      second = k[8],
      diamond_leg = k[9],
      alpha = k[10],
      label_size = Layouts.font_px(k.label_size, unit, self.default_label_size or 12),
      legend_size = Layouts.font_px(k.legend_size, unit, self.default_legend_size or 9),
      color = k.color,
      label_color = k.label_color,
      radius_u = tonumber(k.radius),
      shape = shape,
      outline = k.outline or "auto",
      outline_color = k.outline_color,
      outline_alpha = k.outline_alpha,
      outline_width = k.outline_width,
      outline_inset = k.outline_inset,
      face_glyph = k.face_glyph or "auto",
      circular = want_circle,
      x = bx,
      y = btn_y,
      w = math.max(10, face_w),
      h = math.max(10, face_h),
      -- Legends use the full cell (wider than circular F-key faces).
      legend_x = cell_x,
      legend_w = math.max(10, kw),
      legend_y = by,
      legend_h = (want_circle or circular) and lh or legend_h,
    }
  end
end

function Keypad:contains(mx, my)
  local p = self.panel
  return p.w > 0 and mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h
end

function Keypad:hit_button(mx, my)
  for _, b in ipairs(self.buttons) do
    if mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h then
      return b
    end
  end
  return nil
end

function Keypad:mousepressed(mx, my)
  if not self:contains(mx, my) then return false end
  local b = self:hit_button(mx, my)
  if b then
    self.pressed = b.key
    return true, "press", b.key
  end
  return true
end

function Keypad:mousemoved(mx, my)
  local b = self:hit_button(mx, my)
  self.hover = b and b.key or nil
end

function Keypad:mousereleased()
  local k = self.pressed
  self.pressed = nil
  return k
end

-- Face labels truncate; legends pass overflow=true so they may overlap neighbors.
local function draw_label(font, text, x, y, w, h, r, g, b, align, overflow)
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
  local px = x + (w - tw) / 2
  if align == "left" then px = x + 1
  elseif align == "right" then px = x + w - tw - 1 end
  love.graphics.setColor(r, g, b, 1)
  love.graphics.print(draw, px, y + (h - th) / 2)
  love.graphics.setFont(prev)
end

local function draw_arrow_glyph(cx, cy, size, dir, r, g, b)
  local s = size * 0.14
  love.graphics.setColor(r, g, b, 1)
  if dir == "up" then
    love.graphics.polygon("fill", cx, cy - s, cx - s * 0.85, cy + s * 0.55, cx + s * 0.85, cy + s * 0.55)
  elseif dir == "down" then
    love.graphics.polygon("fill", cx, cy + s, cx - s * 0.85, cy - s * 0.55, cx + s * 0.85, cy - s * 0.55)
  elseif dir == "left" then
    love.graphics.polygon("fill", cx - s, cy, cx + s * 0.55, cy - s * 0.85, cx + s * 0.55, cy + s * 0.85)
  elseif dir == "right" then
    love.graphics.polygon("fill", cx + s, cy, cx - s * 0.55, cy - s * 0.85, cx - s * 0.55, cy + s * 0.85)
  end
end

local function draw_diamond_glyph(cx, cy, size, r, g, b)
  local s = size * 0.18
  love.graphics.setColor(r, g, b, 1)
  love.graphics.polygon("fill", cx, cy - s, cx + s, cy, cx, cy + s, cx - s, cy)
end

-- Small filled right-triangle used after STO (matches arrow-key scale).
local function draw_sto_arrow(x, y, h, r, g, b)
  local s = h * 0.12
  love.graphics.setColor(r, g, b, 1)
  love.graphics.polygon("fill", x, y - s * 0.85, x + s, y, x, y + s * 0.85)
end

-- Custom theta: oval with a 45° stroke through the middle.
local function draw_theta_glyph(cx, cy, size, r, g, b)
  local rx = size * 0.17
  local ry = size * 0.22
  local reach = math.max(rx, ry) * 1.15
  local d = reach * 0.70710678 -- cos/sin 45°
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.0, size * 0.05))
  love.graphics.ellipse("line", cx, cy, rx, ry)
  love.graphics.line(cx - d, cy + d, cx + d, cy - d)
end

-- MODE 2nd: app-switch icon (filled ► against a vertical bar).
local function draw_switch_glyph(cx, cy, size, r, g, b)
  local s = size * 0.28
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.2, size * 0.08))
  love.graphics.line(cx + s * 0.55, cy - s, cx + s * 0.55, cy + s)
  love.graphics.polygon(
    "fill",
    cx - s * 0.65, cy,
    cx + s * 0.35, cy - s * 0.75,
    cx + s * 0.35, cy + s * 0.75
  )
end

-- Degree ¡ : small open circle.
local function draw_degree_glyph(cx, cy, size, r, g, b)
  local rad = size * 0.12
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.0, size * 0.05))
  love.graphics.circle("line", cx, cy - size * 0.02, rad)
end

-- Angle ∠ : two rays from a vertex.
local function draw_angle_glyph(cx, cy, size, r, g, b)
  local s = size * 0.32
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.1, size * 0.07))
  love.graphics.line(cx - s * 0.85, cy + s * 0.55, cx - s * 0.15, cy + s * 0.55)
  love.graphics.line(cx - s * 0.15, cy + s * 0.55, cx + s * 0.75, cy - s * 0.65)
end

-- Infinity ∞ : sideways figure-eight (two touching ellipses).
local function draw_infinity_glyph(cx, cy, size, r, g, b)
  local rx = size * 0.16
  local ry = size * 0.12
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.0, size * 0.055))
  love.graphics.ellipse("line", cx - rx * 0.85, cy, rx, ry)
  love.graphics.ellipse("line", cx + rx * 0.85, cy, rx, ry)
end

-- Indirection # on = : hash that reads as the Titanium "tick" mark.
local function draw_hash_glyph(cx, cy, size, r, g, b)
  local s = size * 0.28
  love.graphics.setColor(r, g, b, 1)
  love.graphics.setLineWidth(math.max(1.1, size * 0.07))
  love.graphics.line(cx - s * 0.25, cy - s, cx - s * 0.55, cy + s)
  love.graphics.line(cx + s * 0.55, cy - s, cx + s * 0.25, cy + s)
  love.graphics.line(cx - s * 0.85, cy - s * 0.25, cx + s * 0.85, cy - s * 0.45)
  love.graphics.line(cx - s * 0.85, cy + s * 0.45, cx + s * 0.85, cy + s * 0.25)
end

--- Draw a 2nd-function legend token (text or geometric).
local function draw_second_legend(font, token, x, y, w, h, r, g, b, align)
  if not token then return end
  local cx = x + w * 0.5
  local cy = y + h * 0.5
  if token == "switch" then
    draw_switch_glyph(cx, cy, h * 1.35, r, g, b)
  elseif token == "deg" then
    draw_degree_glyph(cx - w * 0.15, cy, h * 1.4, r, g, b)
  elseif token == "angle" then
    draw_angle_glyph(cx - w * 0.05, cy, h * 1.35, r, g, b)
  elseif token == "#" then
    draw_hash_glyph(cx - w * 0.15, cy, h * 1.2, r, g, b)
  elseif token == "inf_i" then
    -- CATALOG: ∞ then i (both yellow on Titanium)
    draw_infinity_glyph(x + w * 0.32, cy, h * 1.35, r, g, b)
    draw_label(font, "i", x + w * 0.55, y, w * 0.45, h, r, g, b, "left", true)
  else
    draw_label(font, token, x, y, w, h, r, g, b, align or "left", true)
  end
end

function Keypad:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end

  local band = self.fkey_band or COL.body_inner
  love.graphics.setColor(band[1], band[2], band[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h, 6, 6)

  for _, b in ipairs(self.buttons) do
    -- label_size / legend_size are already scaled to screen px in :layout.
    local face_px = b.label_size or 12
    local legend_px = b.legend_size or face_px
    local face_font = self:_font(face_px)
    local legend_font = self:_font(legend_px)
    local num_font = self:_font(math.max(face_px, math.floor(face_px * 1.25 + 0.5)))

    if b.legend_h > 0 and (b.second or b.diamond_leg or b.alpha) then
      local lx = b.legend_x or b.x
      local lw = b.legend_w or b.w
      -- No per-key legend wipe: plate already fills the strip; legends may overlap.
      if b.style == "fkey" then
        -- F-row: 2nd (F6–F8) inset-left; diamond right on F1–F3, centered on F4–F5
        local inset = lw * 0.12
        if b.second then
          draw_label(legend_font, b.second, lx + inset, b.legend_y, lw * 0.40, b.legend_h,
            COL.legend2[1], COL.legend2[2], COL.legend2[3], "left", true)
        end
        if b.diamond_leg then
          local center_green = (b.key == "f4" or b.key == "f5")
          if center_green then
            draw_label(legend_font, b.diamond_leg, lx, b.legend_y, lw, b.legend_h,
              COL.legendd[1], COL.legendd[2], COL.legendd[3], "center", true)
          else
            draw_label(legend_font, b.diamond_leg, lx + lw * 0.40, b.legend_y, lw * 0.60 - inset, b.legend_h,
              COL.legendd[1], COL.legendd[2], COL.legendd[3], "right", true)
          end
        end
      else
        local third = lw / 3
        local has_2 = b.second ~= nil
        local has_d = b.diamond_leg ~= nil
        local has_a = b.alpha ~= nil
        -- When 2nd + diamond + alpha share a strip, keep equal slots so
        -- single-char green legends ([ ] !) are not covered by neighbors.
        local triple = has_2 and has_d and has_a
        if b.second then
          local sw = triple and third
            or ((b.second == "inf_i" or b.second == "CUSTOM") and (lw * 0.62) or (third + 2))
          draw_second_legend(legend_font, b.second, lx, b.legend_y, sw, b.legend_h,
            COL.legend2[1], COL.legend2[2], COL.legend2[3], "left")
        end
        if b.diamond_leg then
          if b.diamond_leg == "theta" then
            local tcx = lx + third + third * 0.45
            local tcy = b.legend_y + b.legend_h * 0.5
            draw_theta_glyph(tcx, tcy, b.legend_h * 1.25,
              COL.legendd[1], COL.legendd[2], COL.legendd[3])
          else
            local dx = triple and (lx + third) or (lx + third - 1)
            local dw = triple and third or (third + 2)
            local dalign = (#b.diamond_leg <= 1) and "center" or "left"
            draw_label(legend_font, b.diamond_leg, dx, b.legend_y, dw, b.legend_h,
              COL.legendd[1], COL.legendd[2], COL.legendd[3], dalign, true)
          end
        end
        if b.alpha then
          local ax = triple and (lx + 2 * third) or (lx + 2 * third - 2)
          local aw = triple and third or (third + 2)
          draw_label(legend_font, b.alpha, ax, b.legend_y, aw, b.legend_h,
            COL.legend_alpha[1], COL.legend_alpha[2], COL.legend_alpha[3], "right", true)
        end
      end
    end

    local base = b.color or STYLE[b.style] or STYLE.fn
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

    local lx, ly, lw, lh = b.x, b.y, b.w, b.h
    local cx = b.x + b.w * 0.5
    local cy = b.y + b.h * 0.5
    local Layouts = require("keypad_layouts")
    local outline_spec = Layouts.resolve_outline(b, b.style)
    local circular = b.circular
    local radius
    if circular then
      local d = math.min(b.w, b.h)
      local r = d * 0.5
      love.graphics.circle("fill", cx, cy, r)
      Layouts.draw_outline(b.x, b.y, b.w, b.h, r, true, outline_spec)
      lx, ly, lw, lh = cx - r, cy - r, d, d
    else
      if b.radius_u and self._design_unit then
        radius = math.max(0, b.radius_u * self._design_unit)
      else
        radius = math.min(b.w, b.h) * 0.42
      end
      radius = math.min(radius, b.w * 0.5, b.h * 0.5)
      love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, radius, radius)
      Layouts.draw_outline(b.x, b.y, b.w, b.h, radius, false, outline_spec)
    end

    local lr, lg, lb = COL.white[1], COL.white[2], COL.white[3]
    if b.label_color then
      lr, lg, lb = b.label_color[1], b.label_color[2], b.label_color[3]
    elseif b.color then
      if (b.color[1] + b.color[2] + b.color[3]) > 1.55 then
        lr, lg, lb = COL.black[1], COL.black[2], COL.black[3]
      end
    elseif b.style == "second" or b.style == "alpha" or b.style == "num" then
      lr, lg, lb = COL.black[1], COL.black[2], COL.black[3]
    end
    if pressed and not b.label_color then
      lr, lg, lb = COL.black[1], COL.black[2], COL.black[3]
    end

    local glyph = b.face_glyph or "auto"
    if glyph == "auto" then
      if b.style == "arrow" then
        glyph = "arrow_" .. tostring(b.key)
      elseif b.style == "shift" then
        glyph = "arrow_up"
      elseif b.style == "diamond" then
        glyph = "diamond"
      elseif b.key == "backspace" then
        glyph = "backspace"
      elseif b.key == "sto" then
        glyph = "sto"
      else
        glyph = "text"
      end
    end

    if glyph == "arrow_up" or glyph == "arrow_down" or glyph == "arrow_left" or glyph == "arrow_right" then
      local dir = glyph:sub(7)
      if glyph == "arrow_up" and b.style == "shift" then
        local ar, ag, ab = COL.white[1], COL.white[2], COL.white[3]
        if pressed then ar, ag, ab = COL.black[1], COL.black[2], COL.black[3] end
        draw_arrow_glyph(cx, cy, math.min(lw, lh) * 0.9, dir, ar, ag, ab)
      else
        draw_arrow_glyph(cx, cy, math.min(lw, lh) * ((glyph == "backspace" or dir == "left") and 0.85 or 1), dir, lr, lg, lb)
      end
    elseif glyph == "backspace" then
      draw_arrow_glyph(cx, cy, math.min(lw, lh) * 0.85, "left", lr, lg, lb)
    elseif glyph == "diamond" then
      draw_diamond_glyph(cx, cy, math.min(lw, lh), lr, lg, lb)
    elseif glyph == "sto" then
      local font = face_font
      local prev = love.graphics.getFont()
      love.graphics.setFont(font)
      local tw = font:getWidth("STO")
      local th = font:getHeight()
      local scale = 1
      if tw > lw * 0.62 then scale = (lw * 0.62) / tw end
      if th * scale > lh * 0.85 then scale = math.min(scale, (lh * 0.85) / th) end
      local total_w = tw * scale + math.min(lw, lh) * 0.14
      local tx = cx - total_w * 0.5
      local ty = cy - th * scale * 0.5
      love.graphics.setColor(lr, lg, lb, 1)
      love.graphics.print("STO", tx, ty, 0, scale, scale)
      love.graphics.setFont(prev)
      draw_sto_arrow(tx + tw * scale + math.min(lw, lh) * 0.04, cy, math.min(lw, lh), lr, lg, lb)
    else
      local font = (b.style == "num") and num_font or face_font
      draw_label(font, b.label, lx, ly, lw, lh, lr, lg, lb)
    end
  end
end

function Keypad.draw_shell(x, y, w, h)
  local rad = math.max(10, math.min(22, w * 0.045))
  local inset = math.max(3, w * 0.012)
  love.graphics.setColor(COL.body[1], COL.body[2], COL.body[3], 1)
  love.graphics.rectangle("fill", x, y, w, h, rad, rad)
  love.graphics.setColor(0.07, 0.07, 0.08, 0.5)
  love.graphics.rectangle("fill", x + inset, y + inset, w - inset * 2, h - inset * 2, rad * 0.85, rad * 0.85)
  love.graphics.setColor(COL.silver[1], COL.silver[2], COL.silver[3], 0.22)
  love.graphics.rectangle("line", x + inset * 0.5, y + inset * 0.5, w - inset, h - inset, rad * 0.92, rad * 0.92)
end

Keypad.COLORS = COL
return Keypad
