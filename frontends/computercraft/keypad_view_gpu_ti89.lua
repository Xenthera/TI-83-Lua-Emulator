-- TI-89 keypad on Tom's Peripherals GPU (Love keypad_ti89 geometry / colors).

local Gpu = require("frontends.computercraft.gpu")

local M = {}
M.__index = M

local FKEY_SIZE = 1.14
local PITCH = 1.05

-- name, label, style, col, row, w, h, second, diamond, alpha
local KEYS = {
  { "f1", "F1", "fkey", 0, 0, 1, FKEY_SIZE, "F6", "Y=", nil },
  { "f2", "F2", "fkey", 1, 0, 1, FKEY_SIZE, "F7", "WINDOW", nil },
  { "f3", "F3", "fkey", 2, 0, 1, FKEY_SIZE, "F8", "GRAPH", nil },
  { "f4", "F4", "fkey", 3, 0, 1, FKEY_SIZE, nil, "TblSet", nil },
  { "f5", "F5", "fkey", 4, 0, 1, FKEY_SIZE, nil, "TABLE", nil },

  { "up", "up", "arrow", 3.5, 1.22, 1, FKEY_SIZE, nil, nil, nil },
  { "left", "left", "arrow", 3.0, 2.05, 1, FKEY_SIZE, nil, nil, nil },
  { "right", "right", "arrow", 4.0, 2.05, 1, FKEY_SIZE, nil, nil, nil },
  { "down", "down", "arrow", 3.5, 2.88, 1, FKEY_SIZE, nil, nil, nil },

  { "2nd", "2nd", "second", 0, 1.85, 1, 1, nil, "CUT", nil },
  { "shift", "shift", "shift", 1, 1.85, 1, 1, nil, "COPY", nil },
  { "esc", "ESC", "fn", 2, 1.85, 1, 1, "QUIT", "PASTE", nil },

  { "diamond", "diamond", "diamond", 0, 2.90, 1, 1, nil, nil, nil },
  { "alpha", "ALPHA", "alpha", 1, 2.90, 1, 1, "a-lock", nil, nil },
  { "apps", "APPS", "fn", 2, 2.90, 1, 1, nil, nil, nil },

  { "home", "HOME", "fn", 0, 3.95, 1, 1, "CUSTOM", nil, nil },
  { "mode", "MODE", "fn", 1, 3.95, 1, 1, "switch", nil, nil },
  { "catalog", "CATALOG", "fn", 2, 3.95, 1, 1, "inf_i", nil, nil },
  { "backspace", "bs", "fn", 3, 3.95, 1, 1, "INS", "DEL", nil },
  { "clear", "CLEAR", "fn", 4, 3.95, 1, 1, nil, nil, nil },

  { "x", "X", "fn", 0, 3.95 + PITCH, 1, 1, "LN", "e^x", nil },
  { "y", "Y", "fn", 1, 3.95 + PITCH, 1, 1, "SIN", "SIN-1", nil },
  { "z", "Z", "fn", 2, 3.95 + PITCH, 1, 1, "COS", "COS-1", nil },
  { "t", "T", "fn", 3, 3.95 + PITCH, 1, 1, "TAN", "TAN-1", nil },
  { "power", "^", "fn", 4, 3.95 + PITCH, 1, 1, "pi", "theta", nil },

  { "equals", "=", "fn", 0, 3.95 + 2 * PITCH, 1, 1, "#", nil, "a" },
  { "lparen", "(", "fn", 1, 3.95 + 2 * PITCH, 1, 1, "{", nil, "b" },
  { "rparen", ")", "fn", 2, 3.95 + 2 * PITCH, 1, 1, "}", nil, "c" },
  { "comma", ",", "fn", 3, 3.95 + 2 * PITCH, 1, 1, "[", nil, "d" },
  { "div", "/", "fn", 4, 3.95 + 2 * PITCH, 1, 1, "]", nil, "e" },

  { "pipe", "|", "fn", 0, 3.95 + 3 * PITCH, 1, 1, "deg", nil, "f" },
  { "7", "7", "num", 1, 3.95 + 3 * PITCH, 1, 1, nil, nil, "g" },
  { "8", "8", "num", 2, 3.95 + 3 * PITCH, 1, 1, nil, nil, "h" },
  { "9", "9", "num", 3, 3.95 + 3 * PITCH, 1, 1, nil, nil, "i" },
  { "mul", "*", "fn", 4, 3.95 + 3 * PITCH, 1, 1, "sqrt", nil, "j" },

  { "ee", "EE", "fn", 0, 3.95 + 4 * PITCH, 1, 1, "angle", nil, "k" },
  { "4", "4", "num", 1, 3.95 + 4 * PITCH, 1, 1, ":", nil, "l" },
  { "5", "5", "num", 2, 3.95 + 4 * PITCH, 1, 1, "MATH", nil, "m" },
  { "6", "6", "num", 3, 3.95 + 4 * PITCH, 1, 1, "MEM", nil, "n" },
  { "minus", "-", "fn", 4, 3.95 + 4 * PITCH, 1, 1, "VAR-LINK", nil, "o" },

  { "sto", "STO", "fn", 0, 3.95 + 5 * PITCH, 1, 1, "RCL", nil, "p" },
  { "1", "1", "num", 1, 3.95 + 5 * PITCH, 1, 1, '"', nil, "q" },
  { "2", "2", "num", 2, 3.95 + 5 * PITCH, 1, 1, nil, nil, "r" },
  { "3", "3", "num", 3, 3.95 + 5 * PITCH, 1, 1, nil, nil, "s" },
  { "plus", "+", "fn", 4, 3.95 + 5 * PITCH, 1, 1, "CHAR", nil, "u" },

  { "on", "ON", "on", 0, 3.95 + 6 * PITCH, 1, 1, "OFF", nil, nil },
  { "0", "0", "num", 1, 3.95 + 6 * PITCH, 1, 1, "<", nil, "v" },
  { "dot", ".", "num", 2, 3.95 + 6 * PITCH, 1, 1, ">", nil, "w" },
  { "neg", "(-)", "num", 3, 3.95 + 6 * PITCH, 1, 1, "ANS", nil, "spc" },
  { "enter", "ENTER", "enter", 4, 3.95 + 6 * PITCH, 1, 1, "ENTRY", "~", nil },
}

M.DESIGN_COLS = 5
M.DESIGN_ROWS = 3.95 + 7 * PITCH + 0.05
M.FACE_ASPECT = 1.62
M.FKEY_BAND_END = FKEY_SIZE

local COL = {
  body = Gpu.argb(0.05, 0.05, 0.06),
  key = Gpu.argb(0.38, 0.40, 0.42),
  -- Match non-GPU CC keypad: number pad is lightGray / off-white.
  key_num = Gpu.argb(0.78, 0.78, 0.80),
  key_dark = Gpu.argb(0.42, 0.44, 0.46), -- gray faces on black plate (CC look)
  second = Gpu.argb(0.45, 0.72, 0.95),
  diamond = Gpu.argb(0.62, 0.92, 0.38),
  alpha = Gpu.argb(0.93, 0.93, 0.95),
  shift = Gpu.argb(0.42, 0.44, 0.46),
  -- Avoid exact 0xFFFFFFFF (-1): drawText uses -1 as "no background".
  white = Gpu.argb(0.97, 0.97, 0.98),
  black = Gpu.argb(0.05, 0.05, 0.06),
  orange = Gpu.argb(0.90, 0.48, 0.12),
  legend2 = Gpu.argb(0.55, 0.78, 0.98),
  legendd = Gpu.argb(0.72, 0.95, 0.45),
  legend_alpha = Gpu.argb(0.95, 0.95, 0.97),
}

local STYLE = {
  fn = COL.key_dark,
  num = COL.key_num,
  enter = COL.key_dark,
  arrow = COL.key_dark,
  second = COL.second,
  diamond = COL.diamond,
  alpha = COL.alpha,
  shift = COL.shift,
  on = COL.key_dark,
  fkey = COL.key_dark,
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
  TblSet = "Tbl",
}

function M.fkey_band_width(panel_w, panel_h)
  if not panel_w or panel_w < 40 or not panel_h or panel_h < 40 then
    return panel_w or 0
  end
  local cell_w = panel_w / M.DESIGN_COLS
  local cell_h = panel_h / M.DESIGN_ROWS
  local gap_x = math.max(1.5, cell_w * 0.05)
  local gap_y = math.max(1.0, cell_h * 0.04)
  local legend_h = math.max(6, cell_h * 0.26)
  local kw = cell_w - gap_x
  local kh = FKEY_SIZE * cell_h - gap_y
  local lh = math.max(6, math.min(legend_h * 0.7, cell_h * 0.2))
  local face_h = math.max(10, kh - lh)
  local d = math.min(kw, face_h)
  return 4 * cell_w + d
end

local function short(text)
  if not text then return nil end
  return LEGEND_SHORT[text] or text
end

local function face_color(style, pressed)
  if pressed then return COL.orange end
  return STYLE[style] or STYLE.fn
end

local function label_color(style, pressed)
  if pressed then return COL.black end
  if style == "second" or style == "alpha" or style == "num" then
    return COL.black
  end
  return COL.white
end

local function fill_circle(gpu, cx, cy, r, color, mw, mh)
  r = math.max(2, math.floor(r + 0.5))
  local r2 = r * r
  for dy = -r, r do
    local y = cy + dy
    local span = math.floor(math.sqrt(r2 - dy * dy) + 0.5)
    if span >= 0 then
      Gpu.rect(gpu, cx - span, y, span * 2 + 1, 1, color, mw, mh)
    end
  end
end

local function fill_round_rect(gpu, x, y, w, h, color, border, mw, mh)
  x, y = math.floor(x + 0.5), math.floor(y + 0.5)
  w, h = math.floor(w + 0.5), math.floor(h + 0.5)
  if w < 1 or h < 1 then return end
  local rad = math.max(1, math.floor(math.min(w, h) * 0.22))
  Gpu.rect(gpu, x + rad, y, w - rad * 2, h, color, mw, mh)
  Gpu.rect(gpu, x, y + rad, w, h - rad * 2, color, mw, mh)
  fill_circle(gpu, x + rad, y + rad, rad, color, mw, mh)
  fill_circle(gpu, x + w - rad - 1, y + rad, rad, color, mw, mh)
  fill_circle(gpu, x + rad, y + h - rad - 1, rad, color, mw, mh)
  fill_circle(gpu, x + w - rad - 1, y + h - rad - 1, rad, color, mw, mh)
  if border then
    local inset = math.max(1, math.floor(math.min(w, h) * 0.06))
    Gpu.outline(gpu, x + inset, y + inset, w - inset * 2, h - inset * 2, border, mw, mh)
  end
end

local function draw_arrow(gpu, cx, cy, size, dir, color, mw, mh)
  local s = math.max(4, math.floor(size * 0.28))
  if dir == "up" then
    for i = 0, s do
      Gpu.rect(gpu, cx - i, cy - s + i, i * 2 + 1, 1, color, mw, mh)
    end
  elseif dir == "down" then
    for i = 0, s do
      Gpu.rect(gpu, cx - i, cy + s - i, i * 2 + 1, 1, color, mw, mh)
    end
  elseif dir == "left" then
    for i = 0, s do
      Gpu.rect(gpu, cx - s + i, cy - i, 1, i * 2 + 1, color, mw, mh)
    end
  elseif dir == "right" then
    for i = 0, s do
      Gpu.rect(gpu, cx + s - i, cy - i, 1, i * 2 + 1, color, mw, mh)
    end
  end
end

local function draw_diamond(gpu, cx, cy, size, color, mw, mh)
  local s = math.max(3, math.floor(size * 0.28))
  for i = 0, s do
    Gpu.rect(gpu, cx - i, cy - s + i, i * 2 + 1, 1, color, mw, mh)
    Gpu.rect(gpu, cx - i, cy + s - i, i * 2 + 1, 1, color, mw, mh)
  end
end

local function text(gpu, x, y, str, fg, _bg, size)
  if not str or str == "" then return end
  size = size or 1
  if gpu.drawText then
    -- Always transparent bg: faces/legends are already painted; opaque bg
    -- via getInt also mishandles signed ARGB (bg > -1 check).
    pcall(gpu.drawText, math.max(1, math.floor(x)), math.max(1, math.floor(y)),
      str, fg, Gpu.TEXT_BG_NONE, size)
  end
end

function M.new(gpu)
  return setmetatable({
    gpu = gpu,
    panel = { x = 0, y = 0, w = 0, h = 0 },
    buttons = {},
    pressed = nil,
    face_px = 8,
    legend_px = 6,
    max_w = nil,
    max_h = nil,
  }, M)
end

function M:set_bounds(max_w, max_h)
  self.max_w, self.max_h = max_w, max_h
end

function M:layout(x, y, w, h)
  self.panel = { x = x, y = y, w = w, h = h }
  self.buttons = {}
  if w < 40 or h < 40 then return end

  local cell_w = w / M.DESIGN_COLS
  local cell_h = h / M.DESIGN_ROWS
  local gap_x = math.max(1.5, cell_w * 0.05)
  local gap_y = math.max(1.0, cell_h * 0.04)
  local legend_h = math.max(6, cell_h * 0.26)
  self.face_px = math.max(6, math.floor(cell_h * 0.22 + 0.5))
  self.legend_px = math.max(5, math.floor(cell_h * 0.14 + 0.5))
  -- Tom's drawText size is a multiplier; keep glyphs at true 1x1 pixel scale.
  self.text_size = 1

  -- Arrow cluster / diamond face are a bit smaller than the full cell.
  local ARROW_FACE = 0.82
  local DIAMOND_FACE = 0.82

  for _, k in ipairs(KEYS) do
    local style = k[3] or "fn"
    local kw = (k[6] or 1) * cell_w - gap_x
    local kh = (k[7] or 1) * cell_h - gap_y
    local cell_x = x + k[4] * cell_w + gap_x * 0.5
    local by = y + k[5] * cell_h + gap_y * 0.5
    local circular = style == "fkey" or style == "arrow"
    local lh = circular and math.max(6, math.min(legend_h * 0.7, cell_h * 0.2)) or legend_h
    local face_h = circular and math.max(10, kh - lh) or math.max(10, kh - legend_h)
    local face_w = kw
    local bx = cell_x
    if circular then
      local d = math.min(kw, face_h)
      if style == "arrow" then
        d = d * ARROW_FACE
      end
      face_w, face_h = d, d
      bx = cell_x + (kw - d) * 0.5
    elseif style == "diamond" then
      face_w = kw * DIAMOND_FACE
      face_h = face_h * DIAMOND_FACE
      bx = cell_x + (kw - face_w) * 0.5
    end
    local btn_y = by + (circular and lh or legend_h)
    if style == "diamond" then
      btn_y = by + legend_h + (kh - legend_h - face_h) * 0.5
    elseif style == "arrow" then
      btn_y = by + lh + ((kh - lh) - face_h) * 0.5
    end
    self.buttons[#self.buttons + 1] = {
      key = k[1],
      label = k[2],
      style = style,
      second = k[8],
      diamond_leg = k[9],
      alpha = k[10],
      x = bx,
      y = btn_y,
      w = math.max(10, face_w),
      h = math.max(10, face_h),
      legend_x = cell_x,
      legend_w = math.max(10, kw),
      legend_y = by,
      legend_h = circular and lh or legend_h,
      circular = circular,
    }
  end
end

function M:hit(mx, my)
  for _, b in ipairs(self.buttons) do
    if mx >= b.x and mx < b.x + b.w and my >= b.y and my < b.y + b.h then
      return b.key
    end
  end
  return nil
end

function M:set_pressed(name)
  self.pressed = name
end

--- Draw keypad into GPU buffer. Does not sync.
function M:draw()
  local gpu = self.gpu
  local p = self.panel
  if not gpu or p.w < 4 or p.h < 4 then return end
  local mw, mh = self.max_w, self.max_h

  Gpu.rect(gpu, p.x, p.y, p.w, p.h, COL.body, mw, mh)

  for _, b in ipairs(self.buttons) do
    local pressed = self.pressed == b.key
    local fc = face_color(b.style, pressed)
    local lc = label_color(b.style, pressed)

    -- Legends
    if b.legend_h > 2 and (b.second or b.diamond_leg or b.alpha) then
      local lx, ly, lw = b.legend_x, b.legend_y, b.legend_w
      local third = lw / 3
      local sz = self.text_size or 1
      if b.style == "fkey" then
        if b.second then
          text(gpu, lx + 2, ly, short(b.second), COL.legend2, COL.body, sz)
        end
        if b.diamond_leg then
          local t = short(b.diamond_leg)
          text(gpu, lx + lw - (#t * self.legend_px * 0.55) - 2, ly, t, COL.legendd, COL.body, sz)
        end
      else
        if b.second then
          text(gpu, lx + 1, ly, short(b.second), COL.legend2, COL.body, sz)
        end
        if b.diamond_leg then
          text(gpu, lx + third, ly, short(b.diamond_leg), COL.legendd, COL.body, sz)
        end
        if b.alpha then
          local t = short(b.alpha)
          text(gpu, lx + lw - (#t * self.legend_px * 0.55) - 1, ly, t, COL.legend_alpha, COL.body, sz)
        end
      end
    end

    local cx = b.x + b.w * 0.5
    local cy = b.y + b.h * 0.5
    if b.circular then
      fill_circle(gpu, math.floor(cx), math.floor(cy), math.min(b.w, b.h) * 0.5, fc, mw, mh)
    else
      local border = (b.style == "shift") and COL.white or nil
      fill_round_rect(gpu, b.x, b.y, b.w, b.h, fc, border, mw, mh)
    end

    local sz = self.text_size or 1
    if b.style == "arrow" or b.key == "backspace" then
      local dir = b.key == "backspace" and "left" or b.key
      draw_arrow(gpu, math.floor(cx), math.floor(cy), math.min(b.w, b.h), dir, lc, mw, mh)
    elseif b.style == "shift" then
      draw_arrow(gpu, math.floor(cx), math.floor(cy), math.min(b.w, b.h) * 0.9, "up", COL.white, mw, mh)
    elseif b.style == "diamond" then
      draw_diamond(gpu, math.floor(cx), math.floor(cy), math.min(b.w, b.h), lc, mw, mh)
    else
      local label = b.label
      if label == "bs" then label = "<-" end
      if label == "CATALOG" and b.w < 48 then label = "CAT" end
      if label == "WINDOW" and b.w < 40 then label = "WIN" end
      local tw = #label * self.face_px * 0.55
      text(gpu, math.floor(cx - tw * 0.5), math.floor(cy - self.face_px * 0.4),
        label, lc, fc, sz)
    end
  end
end

return M
