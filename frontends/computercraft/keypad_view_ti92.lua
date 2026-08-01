-- TI-92 Plus keypad on a wrapped Advanced Monitor (monitor_touch -> key names).
-- Layout / legends / colors come from ui/keypads/ti92plus.lua (Love panel editor).

local CC = require("frontends.computercraft.cc")

local M = {}
M.__index = M

local DOC = require("ui.keypads.ti92plus")

local LABEL_ASCII = {
  ["◆"] = "<>",
  ["⇧"] = "^",
  ["θ"] = "th",
  ["←"] = "<-",
  ["(−)"] = "(-)",
  ["∞"] = "inf",
}

local LEGEND_SHORT = {
  WINDOW = "WIN",
  CATALOG = "CAT",
  ["VAR-LINK"] = "VARL",
  ["inf_i"] = "inf",
  ["a-lock"] = "a-lk",
  switch = "sw",
  theta = "th",
  angle = "ang",
  ENTRY = "ENT",
  CUSTOM = "CSTM",
  PASTE = "PST",
  COPY = "CPY",
  HOME = "HOME",
  HAND = "HAND",
}

local function ascii_label(s)
  if not s then return s end
  return LABEL_ASCII[s] or s
end

-- Build KEYS rows from the authored layout (second / shift / alpha).
local KEYS = {}
local DESIGN_W = tonumber(DOC.design_cols) or 15.5
local DESIGN_H = tonumber(DOC.design_rows) or 7.4
do
  local max_x, max_y = DESIGN_W, DESIGN_H
  for _, b in ipairs(DOC.buttons or {}) do
    if b.kind ~= "label" then
      local x2 = (tonumber(b.x) or 0) + (tonumber(b.w) or 1)
      local y2 = (tonumber(b.y) or 0) + (tonumber(b.h) or 1)
      if x2 > max_x then max_x = x2 end
      if y2 > max_y then max_y = y2 end
      KEYS[#KEYS + 1] = {
        b.id,
        ascii_label(b.label or b.id),
        b.style or "fn",
        tonumber(b.x) or 0,
        tonumber(b.y) or 0,
        tonumber(b.w) or 1,
        tonumber(b.h) or 1,
        b.second,
        b.shift,
        b.alpha,
        color = b.color,
        label_color = b.label_color,
        shape = b.shape,
      }
    end
  end
  DESIGN_W = max_x
  DESIGN_H = max_y
end

local FKEY_BAND_END = (DOC.plate and tonumber(DOC.plate.fkey_band_end)) or 0.9

local CC_SWATCH = {
  { "white", 0.96, 0.96, 0.97 },
  { "orange", 0.90, 0.48, 0.12 },
  { "magenta", 0.80, 0.20, 0.70 },
  { "lightBlue", 0.45, 0.72, 0.95 },
  { "yellow", 0.90, 0.82, 0.20 },
  { "lime", 0.55, 0.85, 0.35 },
  { "pink", 0.90, 0.55, 0.70 },
  { "gray", 0.36, 0.38, 0.40 },
  { "lightGray", 0.72, 0.74, 0.76 },
  { "cyan", 0.30, 0.70, 0.80 },
  { "purple", 0.50, 0.25, 0.70 },
  { "blue", 0.20, 0.33, 0.53 },
  { "brown", 0.45, 0.30, 0.18 },
  { "green", 0.25, 0.60, 0.25 },
  { "red", 0.80, 0.20, 0.15 },
  { "black", 0.10, 0.10, 0.11 },
}

local function nearest_cc(C, rgb)
  if not rgb then return nil end
  local r, g, b = rgb[1] or 0, rgb[2] or 0, rgb[3] or 0
  local best, best_d = "gray", 1e9
  for _, s in ipairs(CC_SWATCH) do
    local dr, dg, db = r - s[2], g - s[3], b - s[4]
    local d = dr * dr + dg * dg + db * db
    if d < best_d then
      best_d = d
      best = s[1]
    end
  end
  return C[best] or C.gray
end

local function apply_text_scale(mon, preferred)
  if preferred == false then
    return false
  end
  -- TI-92 keypad always uses 0.5 so the full QWERTY face can fit.
  if mon.setTextScale then
    mon.setTextScale(0.5)
  end
  return 0.5
end

-- Blue accents match Love: F-keys, hand, arrows, enter, esc, apps.
-- Everything else dark gray; numpad stays light.
local BLUE_NAMES = { hand = true, esc = true, apps = true }

local function style_colors(C, style, pressed, face_rgb, ink_rgb, name)
  if pressed then
    return C.orange, C.black
  end
  local face = nearest_cc(C, face_rgb)
  local ink = nearest_cc(C, ink_rgb)
  -- Diamond ink must match legend green (layout teal nearest-maps to cyan).
  if style == "diamond" then
    return face or C.gray, (C.lime or C.green)
  end
  if face then
    return face, ink or C.white
  end
  if style == "num" then
    return C.lightGray, C.black
  end
  if style == "fkey" or style == "arrow" or style == "enter"
      or (name and BLUE_NAMES[name]) then
    return C.blue, C.white
  end
  if style == "second" then
    return C.gray, C.yellow
  end
  if style == "alpha" then
    return C.white, C.black
  end
  return C.gray, C.white
end

local function short_legend(text, max_len)
  if not text then return nil end
  text = ascii_label(LEGEND_SHORT[text] or text)
  -- Allow overflow when max_len omitted (CC clip at write time).
  if max_len and #text > max_len then
    return text:sub(1, max_len)
  end
  return text
end

function M.new(mon_or_side, opts)
  opts = opts or {}
  local mon, side
  if CC.is_cc() then
    mon, side = CC.wrap_monitor(mon_or_side, "keypad")
  else
    mon = mon_or_side
    side = opts.side
  end
  local scale = apply_text_scale(mon, opts.text_scale)
  local self = setmetatable({
    mon = mon,
    side = side or opts.side,
    text_scale = scale,
    buttons = {},
    pressed = nil,
  }, M)
  self:relayout()
  return self
end

function M:relayout()
  local mon = self.mon
  local mw, mh = mon.getSize()
  local cell_w = mw / DESIGN_W
  local cell_h = mh / DESIGN_H
  local gap_x = (cell_w >= 3.5) and 1 or 0
  local gap_y = (cell_h >= 2.2) and 1 or 0
  self.buttons = {}
  self.fkey_band_y1 = math.max(1, math.floor(FKEY_BAND_END * mh / DESIGN_H + 0.5))
  for _, k in ipairs(KEYS) do
    local name, label, style = k[1], k[2], k[3]
    local c, r, w, h = k[4], k[5], k[6], k[7]
    local second, diamond, alpha = k[8], k[9], k[10]
    local x0 = math.floor(c * cell_w) + 1
    local y0 = math.floor(r * cell_h) + 1
    local x1 = math.floor((c + w) * cell_w) - gap_x
    local y1 = math.floor((r + h) * cell_h) - gap_y
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end
    if x1 > mw then x1 = mw end
    if y1 > mh then y1 = mh end
    if x0 < 1 then x0 = 1 end

    local height = y1 - y0 + 1
    local need_legend = second or diamond or alpha
    local legend_y, face_y0, legend_on_face
    if height >= 3 and need_legend then
      legend_y = y0
      face_y0 = y0 + 1
      legend_on_face = false
    elseif need_legend then
      legend_y = nil
      face_y0 = y0
      legend_on_face = true
    elseif height >= 2 then
      -- No legend: inset face by 1 so it matches keys that reserve a legend row.
      legend_y = nil
      face_y0 = y0 + 1
      legend_on_face = false
    else
      legend_y = nil
      face_y0 = y0
      legend_on_face = false
    end

    -- Nudge pad arrows up one cell (down stays).
    if name == "up" or name == "left" or name == "right" then
      y0 = math.max(1, y0 - 1)
      y1 = math.max(y0, y1 - 1)
      face_y0 = math.max(1, face_y0 - 1)
      if legend_y then legend_y = math.max(1, legend_y - 1) end
    end

    self.buttons[#self.buttons + 1] = {
      name = name,
      label = label,
      style = style,
      second = second,
      diamond = diamond,
      alpha = alpha,
      color = k.color,
      label_color = k.label_color,
      shape = k.shape,
      x0 = x0, y0 = y0, x1 = x1, y1 = y1,
      legend_y = legend_y,
      face_y0 = face_y0,
      legend_on_face = legend_on_face,
    }
  end
end

local function fill_rect(mon, x0, y0, x1, y1, bg)
  if y1 < y0 or x1 < x0 then return end
  mon.setBackgroundColor(bg)
  local line = string.rep(" ", x1 - x0 + 1)
  for y = y0, y1 do
    mon.setCursorPos(x0, y)
    mon.write(line)
  end
end

local function fill_round_rect_face(mon, x0, y0, x1, y1, face_bg)
  if y1 < y0 or x1 < x0 then return end
  local w = x1 - x0 + 1
  local h = y1 - y0 + 1
  if w <= 2 or h <= 1 then
    fill_rect(mon, x0, y0, x1, y1, face_bg)
    return
  end
  for y = y0, y1 do
    for x = x0, x1 do
      local at_corner = (x == x0 or x == x1) and (y == y0 or y == y1)
      if not at_corner then
        mon.setCursorPos(x, y)
        mon.setBackgroundColor(face_bg)
        mon.write(" ")
      end
    end
  end
end

local function fill_circle_face(mon, x0, y0, x1, y1, face_bg)
  if y1 < y0 or x1 < x0 then return end
  local w = x1 - x0 + 1
  local h = y1 - y0 + 1
  if w <= 1 and h <= 1 then
    fill_rect(mon, x0, y0, x1, y1, face_bg)
    return
  end
  local cx = (x0 + x1) * 0.5
  local cy = (y0 + y1) * 0.5
  local rx = math.max(0.55, w * 0.5)
  local ry = math.max(0.55, h * 0.5)
  for y = y0, y1 do
    for x = x0, x1 do
      local dx = (x - cx) / rx
      local dy = (y - cy) / ry
      if dx * dx + dy * dy <= 1.08 * 1.08 then
        mon.setCursorPos(x, y)
        mon.setBackgroundColor(face_bg)
        mon.write(" ")
      end
    end
  end
end

local function write_clipped(mon, x, y, text, fg, bg, x0, x1)
  if not text or text == "" or y < 1 then return end
  if x < x0 then x = x0 end
  if x > x1 then return end
  mon.setCursorPos(x, y)
  mon.setTextColor(fg)
  mon.setBackgroundColor(bg)
  mon.write(text:sub(1, x1 - x + 1))
end

function M:draw()
  local C = CC.colors()
  local mon = self.mon
  local mw, mh = mon.getSize()
  local body = C.gray
  local second_fg = C.yellow
  local diamond_fg = C.lime or C.green
  local alpha_fg = C.white

  -- Theme legend colors when present.
  local theme = DOC.theme or {}
  if theme.legend_2nd then second_fg = nearest_cc(C, theme.legend_2nd) or second_fg end
  if theme.legend_shift then diamond_fg = nearest_cc(C, theme.legend_shift) or diamond_fg end
  if theme.legend_alpha then alpha_fg = nearest_cc(C, theme.legend_alpha) or alpha_fg end
  if DOC.plate and DOC.plate.body then
    body = nearest_cc(C, DOC.plate.body) or body
  end

  mon.setBackgroundColor(body)
  mon.clear()

  for _, b in ipairs(self.buttons) do
    local face_bg, face_fg = style_colors(C, b.style, b.name == self.pressed, b.color, b.label_color, b.name)
    local lx0, lx1 = b.x0, b.x1
    local width = lx1 - lx0 + 1

    local function paint_legends(y, bg)
      if not (b.second or b.diamond or b.alpha) then return end
      local left = short_legend(b.second)
      local mid = short_legend(b.diamond)
      local right = short_legend(b.alpha)
      local n = (left and 1 or 0) + (mid and 1 or 0) + (right and 1 or 0)
      if n == 0 then return end
      if n == 3 then
        local third = math.max(1, math.floor(width / 3))
        write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
        write_clipped(mon, lx0 + third, y, mid, diamond_fg, bg, lx0, lx1)
        write_clipped(mon, lx1 - #right + 1, y, right, alpha_fg, bg, lx0, lx1)
      elseif n == 2 then
        local parts = {}
        if left then parts[#parts + 1] = { left, second_fg } end
        if mid then parts[#parts + 1] = { mid, diamond_fg } end
        if right then parts[#parts + 1] = { right, alpha_fg } end
        local a, acol = parts[1][1], parts[1][2]
        local c, ccol = parts[2][1], parts[2][2]
        write_clipped(mon, lx0, y, a, acol, bg, lx0, lx1)
        write_clipped(mon, lx1 - #c + 1, y, c, ccol, bg, lx0, lx1)
      elseif left then
        write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
      elseif mid then
        write_clipped(mon, lx0, y, mid, diamond_fg, bg, lx0, lx1)
      elseif right then
        write_clipped(mon, lx1 - #right + 1, y, right, alpha_fg, bg, lx0, lx1)
      end
    end

    if b.legend_y then
      paint_legends(b.legend_y, body)
    end

    local face_x0, face_x1 = b.x0, b.x1
    local face_y0, face_y1 = b.face_y0, b.y1
    local face_w = face_x1 - face_x0 + 1
    local face_h = face_y1 - face_y0 + 1
    local circular = b.shape == "circle"
      or (b.shape == "auto" and (b.style == "arrow"))
    if circular and face_w > 0 and face_h > 0 then
      local d = math.min(face_w, face_h)
      local mid = math.floor((face_x0 + face_x1) / 2)
      face_x0 = mid - math.floor((d - 1) / 2)
      face_x1 = face_x0 + d - 1
      face_w = d
      fill_circle_face(mon, face_x0, face_y0, face_x1, face_y1, face_bg)
    else
      if face_bg == C.black then face_bg = C.gray end
      fill_round_rect_face(mon, face_x0, face_y0, face_x1, face_y1, face_bg)
    end

    if b.legend_on_face and (b.second or b.diamond or b.alpha) and face_h == 1 then
      paint_legends(face_y0, face_bg)
    else
      local label = b.label or ""
      if b.style == "shift" and (label == "" or label == "⇧") then
        label = "^"
      elseif b.style == "diamond" and (label == "" or label == "◆") then
        label = "<>"
      end
      if #label > face_w then
        label = label:sub(1, face_w)
      end
      local lx = math.floor((face_x0 + face_x1 - #label) / 2)
      local ly = face_y0 + math.floor((face_h - 1) / 2)
      if lx < face_x0 then lx = face_x0 end
      if ly < face_y0 then ly = face_y0 end
      mon.setCursorPos(lx, ly)
      mon.setTextColor(face_fg)
      mon.setBackgroundColor(face_bg)
      mon.write(label)
    end
  end
end

function M:hit(x, y)
  for _, b in ipairs(self.buttons) do
    if x >= b.x0 and x <= b.x1 and y >= b.y0 and y <= b.y1 then
      return b.name
    end
  end
  return nil
end

function M:on_touch(side, x, y)
  if self.side and side ~= self.side then
    return nil
  end
  return self:hit(x, y)
end

function M:set_pressed(name)
  self.pressed = name
end

return M
