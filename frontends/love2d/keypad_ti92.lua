-- TI-92 Plus on-screen QWERTY keypad (landscape).
-- Button `key` names match machines.ti92plus.hw.keyboard (ticalc matrix).

local Keypad = {}
Keypad.__index = Keypad

local COL = {
  body = { 0.22, 0.24, 0.26 },
  key = { 0.36, 0.38, 0.40 },
  key_dark = { 0.16, 0.17, 0.18 },
  num = { 0.72, 0.74, 0.76 },
  second = { 0.90, 0.82, 0.20 },
  diamond = { 0.55, 0.85, 0.35 },
  white = { 0.96, 0.96, 0.97 },
  black = { 0.06, 0.06, 0.07 },
  orange = { 0.90, 0.48, 0.12 },
  legend2 = { 0.90, 0.82, 0.20 },
  legendd = { 0.55, 0.85, 0.35 },
  legend_alpha = { 0.96, 0.96, 0.97 },
}

local STYLE = {
  fn = COL.key_dark,
  letter = COL.key,
  num = COL.num,
  enter = COL.key_dark,
  arrow = COL.key_dark,
  second = COL.second,
  diamond = COL.diamond,
  shift = COL.key,
  on = COL.key_dark,
  fkey = COL.key_dark,
  op = COL.key_dark,
}

-- Design grid: QWERTY left (~11 cols) + nav/numpad right.
-- Fields: key, label, style, col, row, w, h
local KEYS = {
  -- F-row
  { "f1", "F1", "fkey", 0, 0, 1, 0.9 },
  { "f2", "F2", "fkey", 1, 0, 1, 0.9 },
  { "f3", "F3", "fkey", 2, 0, 1, 0.9 },
  { "f4", "F4", "fkey", 3, 0, 1, 0.9 },
  { "f5", "F5", "fkey", 4, 0, 1, 0.9 },
  { "f6", "F6", "fkey", 5, 0, 1, 0.9 },
  { "f7", "F7", "fkey", 6, 0, 1, 0.9 },
  { "f8", "F8", "fkey", 7, 0, 1, 0.9 },
  { "apps", "APPS", "fn", 8.2, 0, 1.3, 0.9 },
  { "mode", "MODE", "fn", 9.6, 0, 1.2, 0.9 },
  { "esc", "ESC", "fn", 11, 0, 1.2, 0.9 },
  { "up", "^", "arrow", 13.2, 0, 0.9, 0.9 },

  -- Modifiers + arrows
  { "2nd", "2nd", "second", 0, 1.05, 1.2, 0.9 },
  { "diamond", "◆", "diamond", 1.3, 1.05, 1.1, 0.9 },
  { "shift", "⇧", "shift", 2.5, 1.05, 1.1, 0.9 },
  { "hand", "HAND", "fn", 3.7, 1.05, 1.3, 0.9 },
  { "ln", "LN", "fn", 5.1, 1.05, 1.0, 0.9 },
  { "sin", "SIN", "fn", 6.2, 1.05, 1.0, 0.9 },
  { "cos", "COS", "fn", 7.3, 1.05, 1.0, 0.9 },
  { "tan", "TAN", "fn", 8.4, 1.05, 1.0, 0.9 },
  { "clear", "CLEAR", "fn", 9.5, 1.05, 1.3, 0.9 },
  { "2nd2", "2nd", "second", 10.9, 1.05, 1.2, 0.9 },
  { "left", "<", "arrow", 12.2, 1.05, 0.9, 0.9 },
  { "down", "v", "arrow", 13.2, 1.05, 0.9, 0.9 },
  { "right", ">", "arrow", 14.2, 1.05, 0.9, 0.9 },

  -- QWERTY
  { "q", "Q", "letter", 0, 2.15, 1, 0.95 },
  { "w", "W", "letter", 1, 2.15, 1, 0.95 },
  { "e", "E", "letter", 2, 2.15, 1, 0.95 },
  { "r", "R", "letter", 3, 2.15, 1, 0.95 },
  { "t", "T", "letter", 4, 2.15, 1, 0.95 },
  { "y", "Y", "letter", 5, 2.15, 1, 0.95 },
  { "u", "U", "letter", 6, 2.15, 1, 0.95 },
  { "i", "I", "letter", 7, 2.15, 1, 0.95 },
  { "o", "O", "letter", 8, 2.15, 1, 0.95 },
  { "p", "P", "letter", 9, 2.15, 1, 0.95 },
  { "7", "7", "num", 11.2, 2.15, 1, 0.95 },
  { "8", "8", "num", 12.3, 2.15, 1, 0.95 },
  { "9", "9", "num", 13.4, 2.15, 1, 0.95 },
  { "div", "/", "op", 14.5, 2.15, 0.9, 0.95 },

  { "a", "A", "letter", 0.4, 3.2, 1, 0.95 },
  { "s", "S", "letter", 1.4, 3.2, 1, 0.95 },
  { "d", "D", "letter", 2.4, 3.2, 1, 0.95 },
  { "f", "F", "letter", 3.4, 3.2, 1, 0.95 },
  { "g", "G", "letter", 4.4, 3.2, 1, 0.95 },
  { "h", "H", "letter", 5.4, 3.2, 1, 0.95 },
  { "j", "J", "letter", 6.4, 3.2, 1, 0.95 },
  { "k", "K", "letter", 7.4, 3.2, 1, 0.95 },
  { "l", "L", "letter", 8.4, 3.2, 1, 0.95 },
  { "theta", "θ", "letter", 9.4, 3.2, 1, 0.95 },
  { "4", "4", "num", 11.2, 3.2, 1, 0.95 },
  { "5", "5", "num", 12.3, 3.2, 1, 0.95 },
  { "6", "6", "num", 13.4, 3.2, 1, 0.95 },
  { "mul", "*", "op", 14.5, 3.2, 0.9, 0.95 },

  { "z", "Z", "letter", 0.9, 4.25, 1, 0.95 },
  { "x", "X", "letter", 1.9, 4.25, 1, 0.95 },
  { "c", "C", "letter", 2.9, 4.25, 1, 0.95 },
  { "v", "V", "letter", 3.9, 4.25, 1, 0.95 },
  { "b", "B", "letter", 4.9, 4.25, 1, 0.95 },
  { "n", "N", "letter", 5.9, 4.25, 1, 0.95 },
  { "m", "M", "letter", 6.9, 4.25, 1, 0.95 },
  { "equals", "=", "op", 8.0, 4.25, 1, 0.95 },
  { "backspace", "←", "fn", 9.1, 4.25, 1.2, 0.95 },
  { "1", "1", "num", 11.2, 4.25, 1, 0.95 },
  { "2", "2", "num", 12.3, 4.25, 1, 0.95 },
  { "3", "3", "num", 13.4, 4.25, 1, 0.95 },
  { "minus", "-", "op", 14.5, 4.25, 0.9, 0.95 },

  { "space", "SPACE", "fn", 1.5, 5.3, 4.5, 0.95 },
  { "lparen", "(", "op", 6.2, 5.3, 0.9, 0.95 },
  { "rparen", ")", "op", 7.2, 5.3, 0.9, 0.95 },
  { "comma", ",", "op", 8.2, 5.3, 0.9, 0.95 },
  { "power", "^", "op", 9.2, 5.3, 0.9, 0.95 },
  { "sto", "STO", "fn", 10.2, 5.3, 1.0, 0.95 },
  { "0", "0", "num", 11.2, 5.3, 1, 0.95 },
  { "dot", ".", "num", 12.3, 5.3, 1, 0.95 },
  { "neg", "(−)", "num", 13.4, 5.3, 1, 0.95 },
  { "plus", "+", "op", 14.5, 5.3, 0.9, 0.95 },

  { "on", "ON", "on", 0, 5.3, 1.3, 0.95 },
  { "enter", "ENTER", "enter", 11.2, 6.35, 2.2, 0.95 },
  { "enter2", "ENT2", "enter", 13.5, 6.35, 1.9, 0.95 },
  { "enter3", "ENTER", "enter", 10.0, 6.35, 1.0, 0.95 },
}

Keypad.DESIGN_COLS = 15.5
Keypad.DESIGN_ROWS = 7.4
Keypad.FACE_ASPECT = 0.58 -- wide landscape keys under 240×128 LCD

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
  self.body = COL.body
  if opts.layout then
    self:reload_layout(opts.layout)
  end
  return self
end

function Keypad:reload_layout(doc)
  if not doc then return end
  local Layouts = require("keypad_layouts")
  -- TI-92 legends match TI-89 field order: second, shift/◆, alpha.
  self.keys = Layouts.to_legacy_rows(doc, "89")
  self.design_cols = doc.design_cols or Keypad.DESIGN_COLS
  self.design_rows = doc.design_rows or Keypad.DESIGN_ROWS
  self.face_aspect = doc.face_aspect or Keypad.FACE_ASPECT
  self.default_label_size = (doc.theme and doc.theme.label_size) or 12
  self.default_legend_size = (doc.theme and doc.theme.legend_size) or 9
  if doc.plate and doc.plate.body then self.body = doc.plate.body end
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
  local gap_x = math.max(1, unit * 0.06)
  local gap_y = math.max(1, unit * 0.08)
  local legend_h = math.max(3, unit * 0.26)
  local def_label = self.default_label_size or 12
  local def_legend = self.default_legend_size or 9

  for _, k in ipairs(self.keys or KEYS) do
    local kw = (k[6] or 1) * unit - gap_x
    local kh = (k[7] or 1) * unit - gap_y
    local cell_x = x + k[4] * unit + gap_x * 0.5
    local by = y + k[5] * unit + gap_y * 0.5
    local shape = k.shape or "auto"
    local circular = shape == "circle"
    local lh = legend_h
    local face_w = math.max(4, kw)
    local face_h = math.max(4, kh - legend_h)
    local bx = cell_x
    if circular then
      lh = math.max(3, math.min(legend_h * 0.7, unit * 0.2))
      local d = math.min(kw, math.max(4, kh - lh))
      face_w, face_h = d, d
      bx = cell_x + (kw - d) * 0.5
    end
    local btn_y = by + lh
    local rad_u = tonumber(k.radius) or 0.12
    self.buttons[#self.buttons + 1] = {
      key = k[1],
      label = k[2],
      style = k[3] or "fn",
      second = k[8],
      diamond_leg = k[9],
      alpha = k[10],
      label_size = Layouts.font_px(k.label_size, unit, def_label),
      legend_size = Layouts.font_px(k.legend_size, unit, def_legend),
      color = k.color,
      label_color = k.label_color,
      radius_u = rad_u,
      outline = k.outline or "auto",
      outline_color = k.outline_color,
      outline_alpha = k.outline_alpha,
      outline_width = k.outline_width,
      outline_inset = k.outline_inset,
      shape = shape,
      circular = circular,
      face_glyph = k.face_glyph or "auto",
      x = bx,
      y = btn_y,
      w = face_w,
      h = face_h,
      legend_x = cell_x,
      legend_w = math.max(4, kw),
      legend_y = by,
      legend_h = lh,
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
  local px = x + (w - tw) * 0.5
  if align == "left" then px = x + 1
  elseif align == "right" then px = x + w - tw - 1 end
  love.graphics.setColor(r, g, b, 1)
  love.graphics.print(draw, px, y + (h - th) * 0.5)
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

local function draw_sto_arrow(x, y, h, r, g, b)
  local s = h * 0.12
  love.graphics.setColor(r, g, b, 1)
  love.graphics.polygon("fill", x, y - s * 0.85, x + s, y, x, y + s * 0.85)
end

function Keypad:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end
  local body = self.body or COL.body
  love.graphics.setColor(body[1], body[2], body[3], 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h, 5, 5)

  local Layouts = require("keypad_layouts")
  for _, b in ipairs(self.buttons) do
    local face_px = b.label_size or 12
    local legend_px = b.legend_size or face_px
    local face_font = self:_font(face_px)
    local legend_font = self:_font(legend_px)

    if b.legend_h and b.legend_h > 0 and (b.second or b.diamond_leg or b.alpha) then
      local lx = b.legend_x or b.x
      local lw = b.legend_w or b.w
      local third = lw / 3
      local has_2 = b.second ~= nil
      local has_d = b.diamond_leg ~= nil
      local has_a = b.alpha ~= nil
      local triple = has_2 and has_d and has_a
      if b.second then
        local sw = triple and third or (((has_d or has_a) and (lw * 0.45)) or lw)
        draw_label(legend_font, b.second, lx, b.legend_y, sw, b.legend_h,
          COL.legend2[1], COL.legend2[2], COL.legend2[3], "left", true)
      end
      if b.diamond_leg then
        local dx = triple and (lx + third) or (has_2 and (lx + lw * 0.40) or lx)
        local dw = triple and third or ((has_2 and has_a and (lw * 0.30)) or (lw * 0.55))
        local dalign = (#tostring(b.diamond_leg) <= 1) and "center" or "left"
        draw_label(legend_font, b.diamond_leg, dx, b.legend_y, dw, b.legend_h,
          COL.legendd[1], COL.legendd[2], COL.legendd[3], dalign, true)
      end
      if b.alpha then
        local ax = triple and (lx + 2 * third) or (lx + lw * 0.45)
        local aw = triple and third or (lw * 0.55)
        draw_label(legend_font, b.alpha, ax, b.legend_y, aw, b.legend_h,
          COL.legend_alpha[1], COL.legend_alpha[2], COL.legend_alpha[3], "right", true)
      end
    end

    local base = b.color or STYLE[b.style] or STYLE.fn
    local pressed = self.pressed == b.key
    local hover = self.hover == b.key
    if pressed then
      love.graphics.setColor(COL.orange[1], COL.orange[2], COL.orange[3], 1)
    else
      local mul = hover and 1.1 or 1
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
    local outline_spec = Layouts.resolve_outline(b, b.style)
    local rad
    if b.circular then
      local d = math.min(b.w, b.h)
      rad = d * 0.5
      love.graphics.circle("fill", cx, cy, rad)
      Layouts.draw_outline(b.x, b.y, b.w, b.h, rad, true, outline_spec)
      lx, ly, lw, lh = cx - rad, cy - rad, d, d
    else
      if b.radius_u and self._design_unit then
        rad = math.max(0, b.radius_u * self._design_unit)
      else
        rad = math.min(b.w, b.h) * 0.22
      end
      rad = math.min(rad, b.w * 0.5, b.h * 0.5)
      love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, rad, rad)
      Layouts.draw_outline(b.x, b.y, b.w, b.h, rad, false, outline_spec)
    end

    local lr, lg, lb = COL.white[1], COL.white[2], COL.white[3]
    if b.label_color then
      lr, lg, lb = b.label_color[1], b.label_color[2], b.label_color[3]
    elseif b.color then
      if (b.color[1] + b.color[2] + b.color[3]) > 1.55 then
        lr, lg, lb = COL.black[1], COL.black[2], COL.black[3]
      end
    elseif b.style == "second" or b.style == "num" or b.style == "letter" then
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
      draw_arrow_glyph(cx, cy, math.min(lw, lh) * ((dir == "left") and 0.85 or 1), dir, lr, lg, lb)
    elseif glyph == "backspace" then
      draw_arrow_glyph(cx, cy, math.min(lw, lh) * 0.85, "left", lr, lg, lb)
    elseif glyph == "diamond" then
      draw_diamond_glyph(cx, cy, math.min(lw, lh), lr, lg, lb)
    elseif glyph == "sto" then
      local prev = love.graphics.getFont()
      love.graphics.setFont(face_font)
      local tw = face_font:getWidth("STO")
      local th = face_font:getHeight()
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
      draw_label(face_font, b.label, lx, ly, lw, lh, lr, lg, lb)
    end
  end
end

function Keypad.draw_shell(x, y, w, h)
  local rad = math.max(8, math.min(18, w * 0.03))
  love.graphics.setColor(COL.body[1], COL.body[2], COL.body[3], 1)
  love.graphics.rectangle("fill", x, y, w, h, rad, rad)
end

return Keypad
