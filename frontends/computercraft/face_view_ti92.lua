-- TI-92 Plus combined face for ComputerCraft: LCD sits inside the keypad
-- (same scene layout as Love / ui/keypads/ti92plus.lua). One monitor = face.

local CC = require("frontends.computercraft.cc")
local LcdGeom = require("machines.ti92plus.lcd_geom")

local M = {}
M.__index = M

local DOC = require("ui.keypads.ti92plus")

local LABEL_ASCII = {
  ["◆"] = "<>",
  ["⇧"] = "^",
  ["θ"] = "th",
  ["←"] = "<-",
  ["(−)"] = "(-)",
}

local LEGEND_SHORT = {
  WINDOW = "WIN", CATALOG = "CAT", ["VAR-LINK"] = "VARL",
  ["inf_i"] = "inf", ["a-lock"] = "a-lk", switch = "sw",
  theta = "th", angle = "ang", ENTRY = "ENT", CUSTOM = "CSTM",
  PASTE = "PST", COPY = "CPY",
}

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

local function ascii_label(s)
  if not s then return s end
  return LABEL_ASCII[s] or s
end

local function nearest_cc(C, rgb)
  if not rgb then return nil end
  local r, g, b = rgb[1] or 0, rgb[2] or 0, rgb[3] or 0
  local best, best_d = "gray", 1e9
  for _, s in ipairs(CC_SWATCH) do
    local dr, dg, db = r - s[2], g - s[3], b - s[4]
    local d = dr * dr + dg * dg + db * db
    if d < best_d then best_d, best = d, s[1] end
  end
  return C[best] or C.gray
end

local function short_legend(text)
  if not text then return nil end
  return ascii_label(LEGEND_SHORT[text] or text)
end

local DESIGN_COLS = tonumber(DOC.design_cols) or 15.5
local DESIGN_ROWS = tonumber(DOC.design_rows) or 7.4
local SCENE_W = (DOC.scene and tonumber(DOC.scene.w)) or 23.5
local SCENE_H = (DOC.scene and tonumber(DOC.scene.h)) or 18.2
local PANEL = DOC.panel or { x = 0, y = 0, w = SCENE_W, h = SCENE_H }
local LCD = DOC.lcd or { x = 0, y = 0, w = 1, h = 1 }

-- Native 2×3 sixtel resolution for 240×128 (one char = 2×3 FB pixels).
local LCD_NEED_W = math.ceil(LcdGeom.WIDTH / 2)  -- 120
local LCD_NEED_H = math.ceil(LcdGeom.HEIGHT / 3) -- 43
M.LCD_NEED_W = LCD_NEED_W
M.LCD_NEED_H = LCD_NEED_H

-- Isotropic key unit in scene design units (matches Love keypad_layouts.grid_unit).
local KEY_UNIT = math.min(
  (tonumber(PANEL.w) or SCENE_W) / DESIGN_COLS,
  (tonumber(PANEL.h) or SCENE_H) / DESIGN_ROWS
)

local KEYS = {}
for _, b in ipairs(DOC.buttons or {}) do
  if b.kind ~= "label" then
    KEYS[#KEYS + 1] = {
      id = b.id,
      label = ascii_label(b.label or b.id),
      style = b.style or "fn",
      x = tonumber(b.x) or 0,
      y = tonumber(b.y) or 0,
      w = tonumber(b.w) or 1,
      h = tonumber(b.h) or 1,
      second = b.second,
      shift = b.shift,
      alpha = b.alpha,
      color = b.color,
      label_color = b.label_color,
      shape = b.shape,
    }
  end
end

-- Crop to keypad+LCD content (skip empty scene chrome above the panel).
local CONTENT_X0 = tonumber(PANEL.x) or 0
local CONTENT_Y0 = tonumber(PANEL.y) or 0
local CONTENT_X1 = CONTENT_X0 + (tonumber(PANEL.w) or SCENE_W)
local CONTENT_Y1 = CONTENT_Y0 + (tonumber(PANEL.h) or SCENE_H)
do
  local lx = tonumber(LCD.x) or CONTENT_X0
  local ly = tonumber(LCD.y) or CONTENT_Y0
  local lw = tonumber(LCD.w) or 1
  local lh = lw * (LcdGeom.HEIGHT / LcdGeom.WIDTH)
  CONTENT_X0 = math.min(CONTENT_X0, lx)
  CONTENT_Y0 = math.min(CONTENT_Y0, ly)
  CONTENT_X1 = math.max(CONTENT_X1, lx + lw)
  CONTENT_Y1 = math.max(CONTENT_Y1, ly + lh)
  local px = tonumber(PANEL.x) or 0
  local py = tonumber(PANEL.y) or 0
  for _, k in ipairs(KEYS) do
    local x0 = px + k.x * KEY_UNIT
    local y0 = py + k.y * KEY_UNIT
    local x1 = px + (k.x + k.w) * KEY_UNIT
    local y1 = py + (k.y + k.h) * KEY_UNIT
    if x0 < CONTENT_X0 then CONTENT_X0 = x0 end
    if y0 < CONTENT_Y0 then CONTENT_Y0 = y0 end
    if x1 > CONTENT_X1 then CONTENT_X1 = x1 end
    if y1 > CONTENT_Y1 then CONTENT_Y1 = y1 end
  end
end
local CONTENT_W = math.max(0.01, CONTENT_X1 - CONTENT_X0)
local CONTENT_H = math.max(0.01, CONTENT_Y1 - CONTENT_Y0)

-- Blue accents match Love: F-keys, hand, arrows, enter, esc, apps.
-- Everything else dark gray; numpad stays light.
local BLUE_NAMES = { hand = true, esc = true, apps = true }

local function style_colors(C, style, pressed, face_rgb, ink_rgb, name)
  if pressed then return C.orange, C.black end
  local face = nearest_cc(C, face_rgb)
  local ink = nearest_cc(C, ink_rgb)
  -- Diamond ink must match legend green (layout teal nearest-maps to cyan).
  if style == "diamond" then
    return face or C.gray, (C.lime or C.green)
  end
  if face then return face, ink or C.white end
  if style == "num" then return C.lightGray, C.black end
  if style == "fkey" or style == "arrow" or style == "enter"
      or (name and BLUE_NAMES[name]) then
    return C.blue, C.white
  end
  if style == "second" then return C.gray, C.yellow end
  return C.gray, C.white
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

local function write_clipped(mon, x, y, text, fg, bg, x0, x1)
  if not text or text == "" or y < 1 then return end
  if x < x0 then x = x0 end
  if x > x1 then return end
  mon.setCursorPos(x, y)
  mon.setTextColor(fg)
  mon.setBackgroundColor(bg)
  mon.write(text:sub(1, x1 - x + 1))
end

local function fb_lit(fb, bpr, width, height, x, y)
  if not fb or x < 0 or y < 0 or x >= width or y >= height then
    return false
  end
  x, y = math.floor(x), math.floor(y)
  local byte = fb[y * bpr + math.floor(x / 8)] or 0
  local mask = 2 ^ (7 - (x % 8))
  return (byte % (mask + mask) >= mask)
end

local function pack_sixtel(p1, p2, p3, p4, p5, p6, blit_on, blit_off)
  local bg_on = not not p6
  local char = 128
  if (not not p1) ~= bg_on then char = char + 1 end
  if (not not p2) ~= bg_on then char = char + 2 end
  if (not not p3) ~= bg_on then char = char + 4 end
  if (not not p4) ~= bg_on then char = char + 8 end
  if (not not p5) ~= bg_on then char = char + 16 end
  if bg_on then
    return string.char(char), blit_off, blit_on
  end
  return string.char(char), blit_on, blit_off
end

--- TI-92 face always uses 0.5 so the QWERTY + inset LCD can fit.
local function apply_face_scale(mon)
  if not mon.setTextScale then
    return 0.5
  end
  mon.setTextScale(0.5)
  return 0.5
end

function M.new(mon_or_side, opts)
  opts = opts or {}
  local mon, side
  if CC.is_cc() then
    mon, side = CC.wrap_monitor(mon_or_side, "face")
  else
    mon = mon_or_side
    side = opts.side
  end
  local scale = apply_face_scale(mon)
  local self = setmetatable({
    mon = mon,
    side = side or opts.side,
    text_scale = scale,
    buttons = {},
    pressed = nil,
    lcd_rect = { x0 = 1, y0 = 1, x1 = 1, y1 = 1 },
    lcd_too_small = false,
    blit_on = nil,
    blit_off = nil,
    last_ch = {},
    last_fg = {},
    last_bg = {},
    force_lcd = true,
  }, M)
  self:relayout()
  return self
end

function M:set_lcd_colors(opts)
  opts = opts or {}
  local C = CC.colors()
  self.blit_on = CC.to_blit(opts.on or C.green)
  self.blit_off = CC.to_blit(opts.off or C.lime)
  self.last_ch, self.last_fg, self.last_bg = {}, {}, {}
  self.force_lcd = true
end

function M:relayout()
  local mon = self.mon
  -- Face always stays at 0.5 (host may recreate; keep it sticky on resize).
  if mon.setTextScale then
    mon.setTextScale(0.5)
    self.text_scale = 0.5
  end
  local mw, mh = mon.getSize()
  -- Map content box (panel+keys+LCD) to the full monitor — fill width and height.
  local sx = mw / CONTENT_W
  local sy = mh / CONTENT_H
  local px = tonumber(PANEL.x) or 0
  local py = tonumber(PANEL.y) or 0

  local function scene_to_cell_x(scene_x)
    return (scene_x - CONTENT_X0) * sx
  end
  local function scene_to_cell_y(scene_y)
    return (scene_y - CONTENT_Y0) * sy
  end

  local lx = tonumber(LCD.x) or 0
  local ly = tonumber(LCD.y) or 0
  local lw = math.max(0.01, tonumber(LCD.w) or 1)
  local lh = lw * (LcdGeom.HEIGHT / LcdGeom.WIDTH)

  -- Integer sixtel scale (1x, 2x, …) that fits the monitor; never below 1x if possible.
  local max_scale = math.max(1, math.min(
    math.floor(mw / LCD_NEED_W),
    math.floor(mh / LCD_NEED_H)
  ))
  local fit_scale = math.max(1, math.min(
    math.floor((lw * sx) / LCD_NEED_W),
    math.floor((lh * sy) / LCD_NEED_H)
  ))
  local scale = math.max(1, math.min(max_scale, math.max(fit_scale, 1)))
  local lcd_w = LCD_NEED_W * scale
  local lcd_h = LCD_NEED_H * scale
  self.lcd_too_small = (mw < LCD_NEED_W) or (mh < LCD_NEED_H)
  if self.lcd_too_small then
    lcd_w = math.max(2, mw)
    lcd_h = math.max(2, math.floor(lcd_w * LcdGeom.HEIGHT / LcdGeom.WIDTH * 3 / 2 + 0.5))
    if lcd_h > mh then lcd_h = mh end
  end

  -- Center the glass on the authored LCD center within the content mapping.
  local center_x = scene_to_cell_x(lx + lw * 0.5)
  local center_y = scene_to_cell_y(ly + lh * 0.5)
  local lcd_x0 = math.floor(center_x - lcd_w * 0.5) + 1
  local lcd_y0 = math.floor(center_y - lcd_h * 0.5) + 1
  if lcd_x0 < 1 then lcd_x0 = 1 end
  if lcd_y0 < 1 then lcd_y0 = 1 end
  if lcd_x0 + lcd_w - 1 > mw then lcd_x0 = math.max(1, mw - lcd_w + 1) end
  if lcd_y0 + lcd_h - 1 > mh then lcd_y0 = math.max(1, mh - lcd_h + 1) end

  self.lcd_rect = {
    x0 = lcd_x0,
    y0 = lcd_y0,
    x1 = lcd_x0 + lcd_w - 1,
    y1 = lcd_y0 + lcd_h - 1,
    w = lcd_w,
    h = lcd_h,
    scale = scale,
  }
  self.force_lcd = true
  self.last_ch, self.last_fg, self.last_bg = {}, {}, {}

  self.buttons = {}
  for _, k in ipairs(KEYS) do
    local sx0 = px + k.x * KEY_UNIT
    local sy0 = py + k.y * KEY_UNIT
    local sx1 = px + (k.x + k.w) * KEY_UNIT
    local sy1 = py + (k.y + k.h) * KEY_UNIT
    local x0 = math.max(1, math.floor(scene_to_cell_x(sx0)) + 1)
    local y0 = math.max(1, math.floor(scene_to_cell_y(sy0)) + 1)
    local x1 = math.min(mw, math.floor(scene_to_cell_x(sx1)))
    local y1 = math.min(mh, math.floor(scene_to_cell_y(sy1)))
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end

    local height = y1 - y0 + 1
    local need_legend = k.second or k.shift or k.alpha
    local legend_y, face_y0
    if height >= 3 and need_legend then
      legend_y = y0
      face_y0 = y0 + 1
    elseif height >= 2 then
      -- No legend: inset face by 1 so it matches keys that reserve a legend row.
      legend_y = nil
      face_y0 = y0 + 1
    else
      legend_y = nil
      face_y0 = y0
    end

    -- Nudge pad arrows up one cell (down stays).
    if k.id == "up" or k.id == "left" or k.id == "right" then
      y0 = math.max(1, y0 - 1)
      y1 = math.max(y0, y1 - 1)
      face_y0 = math.max(1, face_y0 - 1)
      if legend_y then legend_y = math.max(1, legend_y - 1) end
    end

    self.buttons[#self.buttons + 1] = {
      name = k.id,
      label = k.label,
      style = k.style,
      second = k.second,
      diamond = k.shift,
      alpha = k.alpha,
      color = k.color,
      label_color = k.label_color,
      shape = k.shape,
      x0 = x0, y0 = y0, x1 = x1, y1 = y1,
      legend_y = legend_y,
      face_y0 = face_y0,
    }
  end
end

function M:_in_lcd(x, y)
  local r = self.lcd_rect
  return x >= r.x0 and x <= r.x1 and y >= r.y0 and y <= r.y1
end

function M:paint_lcd(fb, display_on)
  if not self.blit_on then
    self:set_lcd_colors({})
  end
  local r = self.lcd_rect
  local cw, ch = r.w, r.h
  if cw < 2 or ch < 1 then return false end

  local mon = self.mon
  local blit_on, blit_off = self.blit_on, self.blit_off
  local pw, ph, bpr = LcdGeom.WIDTH, LcdGeom.HEIGHT, LcdGeom.BYTES_PER_ROW
  local use_fb = display_on and fb or nil
  local force = self.force_lcd
  local last_ch, last_fg, last_bg = self.last_ch, self.last_fg, self.last_bg
  local blitted = 0
  -- Native (or integer) sixtel scale: each char is exactly 2×3 FB pixels / scale.
  local native = (cw % LCD_NEED_W == 0) and (ch % LCD_NEED_H == 0)
    and (cw / LCD_NEED_W == ch / LCD_NEED_H)
  local cell_scale = native and (cw / LCD_NEED_W) or nil

  for cy = 0, ch - 1 do
    local chars, fgs, bgs = {}, {}, {}
    for cx = 0, cw - 1 do
      local function sample(ix, iy)
        local fx, fy
        if cell_scale then
          -- Exact sixtel lattice (scale 1 = 2×3 px/char).
          fx = (cx * 2 + ix) / cell_scale
          fy = (cy * 3 + iy) / cell_scale
        else
          fx = (cx + (ix + 0.5) / 2) * pw / cw
          fy = (cy + (iy + 0.5) / 3) * ph / ch
        end
        return fb_lit(use_fb, bpr, pw, ph, fx, fy)
      end
      local c, f, b = pack_sixtel(
        sample(0, 0), sample(1, 0),
        sample(0, 1), sample(1, 1),
        sample(0, 2), sample(1, 2),
        blit_on, blit_off
      )
      chars[cx + 1] = c
      fgs[cx + 1] = f
      bgs[cx + 1] = b
    end
    local row_ch = table.concat(chars)
    local row_fg = table.concat(fgs)
    local row_bg = table.concat(bgs)
    if force or last_ch[cy] ~= row_ch or last_fg[cy] ~= row_fg or last_bg[cy] ~= row_bg then
      mon.setCursorPos(r.x0, r.y0 + cy)
      mon.blit(row_ch, row_fg, row_bg)
      last_ch[cy], last_fg[cy], last_bg[cy] = row_ch, row_fg, row_bg
      blitted = blitted + 1
    end
  end
  self.force_lcd = false
  return true, blitted
end

function M:draw_keys()
  local C = CC.colors()
  local mon = self.mon
  local body = C.gray
  local second_fg = C.yellow
  local diamond_fg = C.lime or C.green
  local alpha_fg = C.white
  local theme = DOC.theme or {}
  if theme.legend_2nd then second_fg = nearest_cc(C, theme.legend_2nd) or second_fg end
  if theme.legend_shift then diamond_fg = nearest_cc(C, theme.legend_shift) or diamond_fg end
  if theme.legend_alpha then alpha_fg = nearest_cc(C, theme.legend_alpha) or alpha_fg end
  if DOC.plate and DOC.plate.body then
    body = nearest_cc(C, DOC.plate.body) or body
  end

  mon.setBackgroundColor(body)
  mon.clear()

  if self.lcd_too_small then
    mon.setTextColor(C.red)
    mon.setBackgroundColor(C.black)
    local msg = string.format("FACE needs >= %dx%d (sixtel LCD)", LCD_NEED_W, LCD_NEED_H)
    mon.setCursorPos(1, 1)
    mon.write(msg:sub(1, select(1, mon.getSize())))
  end

  -- Bezel under the glass.
  local r = self.lcd_rect
  local bezel = nearest_cc(C, LCD.color) or C.black
  fill_rect(mon, r.x0, r.y0, r.x1, r.y1, bezel)

  for _, b in ipairs(self.buttons) do
    local face_bg, face_fg = style_colors(C, b.style, b.name == self.pressed, b.color, b.label_color, b.name)
    local lx0, lx1 = b.x0, b.x1
    local width = lx1 - lx0 + 1

    if b.legend_y and (b.second or b.diamond or b.alpha) then
      local left = short_legend(b.second)
      local mid = short_legend(b.diamond)
      local right = short_legend(b.alpha)
      if left then write_clipped(mon, lx0, b.legend_y, left, second_fg, body, lx0, lx1) end
      if mid then
        local mx = lx0 + math.floor(width / 3)
        write_clipped(mon, mx, b.legend_y, mid, diamond_fg, body, lx0, lx1)
      end
      if right then
        write_clipped(mon, lx1 - #right + 1, b.legend_y, right, alpha_fg, body, lx0, lx1)
      end
    end

    local face_y0, face_y1 = b.face_y0, b.y1
    if face_bg == C.black then face_bg = C.gray end
    fill_rect(mon, b.x0, face_y0, b.x1, face_y1, face_bg)

    local label = b.label or ""
    local face_w = b.x1 - b.x0 + 1
    local face_h = face_y1 - face_y0 + 1
    if #label > face_w then label = label:sub(1, face_w) end
    local lx = math.floor((b.x0 + b.x1 - #label) / 2)
    local ly = face_y0 + math.floor((face_h - 1) / 2)
    if lx < b.x0 then lx = b.x0 end
    if ly < face_y0 then ly = face_y0 end
    mon.setCursorPos(lx, ly)
    mon.setTextColor(face_fg)
    mon.setBackgroundColor(face_bg)
    mon.write(label)
  end

  self.force_lcd = true
end

--- Full face redraw: keys + LCD.
function M:draw(fb, display_on)
  self:draw_keys()
  if fb ~= nil then
    self:paint_lcd(fb, display_on)
  end
end

function M:hit(x, y)
  if self:_in_lcd(x, y) then
    return nil
  end
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
