-- TI-89 Titanium keypad on a wrapped Advanced Monitor (monitor_touch -> key names).
-- Key names match machines.ti89.hw.keyboard. Layout / legends / colors mirror Love keypad_ti89.

local CC = require("frontends.computercraft.cc")

local M = {}
M.__index = M

local FKEY = 1.14
local PITCH = 1.05
-- name, label, style, col, row, w, h, second, diamond, alpha
-- (same field order as frontends/love2d/keypad_ti89.lua)
local KEYS = {
  { "f1", "F1", "fkey", 0, 0, 1, FKEY, "F6", "Y=", nil },
  { "f2", "F2", "fkey", 1, 0, 1, FKEY, "F7", "WINDOW", nil },
  { "f3", "F3", "fkey", 2, 0, 1, FKEY, "F8", "GRAPH", nil },
  { "f4", "F4", "fkey", 3, 0, 1, FKEY, nil, "TblSet", nil },
  { "f5", "F5", "fkey", 4, 0, 1, FKEY, nil, "TABLE", nil },

  { "up", "^", "arrow", 3.5, 1.22, 1, FKEY, nil, nil, nil },
  { "left", "<", "arrow", 3.0, 2.05, 1, FKEY, nil, nil, nil },
  { "right", ">", "arrow", 4.0, 2.05, 1, FKEY, nil, nil, nil },
  { "down", "v", "arrow", 3.5, 2.88, 1, FKEY, nil, nil, nil },

  { "2nd", "2nd", "second", 0, 1.85, 1, 1, nil, "CUT", nil },
  { "shift", "shift", "shift", 1, 1.85, 1, 1, nil, "COPY", nil },
  { "esc", "ESC", "fn", 2, 1.85, 1, 1, "QUIT", "PASTE", nil },

  { "diamond", "<>", "diamond", 0, 2.90, 1, 1, nil, nil, nil },
  { "alpha", "ALPHA", "alpha", 1, 2.90, 1, 1, "a-lock", nil, nil },
  { "apps", "APPS", "fn", 2, 2.90, 1, 1, nil, nil, nil },

  { "home", "HOME", "fn", 0, 3.95, 1, 1, "CUSTOM", nil, nil },
  { "mode", "MODE", "fn", 1, 3.95, 1, 1, "switch", nil, nil },
  { "catalog", "CATALOG", "fn", 2, 3.95, 1, 1, "inf_i", nil, nil },
  { "backspace", "<-", "fn", 3, 3.95, 1, 1, "INS", "DEL", nil },
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
  -- MATH / MEM / VAR-LINK / CHAR are 2nd (blue), not diamond.
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

-- Shorten a few face/legend strings for CC cell width when needed at paint time.
local LEGEND_SHORT = {
  WINDOW = "WIN",
  CATALOG = "CAT",
  ["VAR-LINK"] = "VARL",
  ["VARL"] = "VARL",
  ["inf_i"] = "inf",
  ["a-lock"] = "a-lk",
  switch = "sw",
  theta = "th",
  angle = "ang",
  ENTRY = "ENT",
  CUSTOM = "CSTM",
  PASTE = "PST",
  COPY = "CPY",
}

local DESIGN_W = 5
local DESIGN_H = 3.95 + 7 * PITCH + 0.05
local FKEY_BAND_END = FKEY

--- Prefer larger text; fall back if the monitor can't fit ~2 cells per design row.
local function apply_text_scale(mon, preferred)
  if not mon.setTextScale then
    return preferred or 0.75
  end
  if preferred == false then
    return false
  end
  local want = tonumber(preferred) or 0.75
  -- Largest-first so we keep text readable when the monitor allows it.
  local candidates = { want, 1.0, 0.75, 0.5 }
  local seen = {}
  local best = 0.5
  for _, s in ipairs(candidates) do
    if s and not seen[s] then
      seen[s] = true
      mon.setTextScale(s)
      local mw, mh = mon.getSize()
      if mw / DESIGN_W >= 2.2 and mh / DESIGN_H >= 1.7 then
        best = s
        break
      end
    end
  end
  mon.setTextScale(best)
  return best
end

--- Map style -> { face_bg, face_fg } matching Love keypad_ti89 STYLE/COL.
local function style_colors(C, style, pressed)
  if pressed then
    return C.orange, C.black
  end
  if style == "second" then
    return C.lightBlue or C.cyan, C.black
  elseif style == "diamond" then
    return C.lime or C.green, C.black
  elseif style == "alpha" then
    return C.white, C.black
  elseif style == "shift" then
    return C.gray, C.white
  elseif style == "num" then
    return C.lightGray, C.black
  elseif style == "fn" or style == "op" or style == "on"
      or style == "fkey" or style == "arrow" or style == "enter" then
    -- Love: dark key faces with white labels (ops/enter/arrows are dark, not blue).
    return C.black, C.white
  end
  return C.lightGray, C.black
end

local function short_legend(text, max_len)
  if not text then return nil end
  text = LEGEND_SHORT[text] or text
  if max_len and #text > max_len then
    return text:sub(1, max_len)
  end
  return text
end

--- @param mon_or_side wrapped monitor or peripheral side string
-- @param opts optional { text_scale=, side= }
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
  -- Shrink gutters when cells are tight so faces keep more room for labels.
  local gap_x = (cell_w >= 4) and 1 or 0
  local gap_y = (cell_h >= 2.4) and 1 or 0
  self.buttons = {}
  self.fkey_band_y1 = math.max(1, math.floor(FKEY_BAND_END * mh / DESIGN_H + 0.5))
  for _, k in ipairs(KEYS) do
    local name, label, style = k[1], k[2], k[3]
    local c, r, w, h = k[4], k[5], k[6], k[7]
    local second, diamond, alpha = k[8], k[9], k[10]
    local is_fkey = style == "fkey"
    local x0 = math.floor(c * cell_w) + 1
    local y0 = math.floor(r * cell_h) + 1
    local x1 = math.floor((c + w) * cell_w) - gap_x
    local y1 = math.floor((r + h) * cell_h) - gap_y
    if is_fkey then
      if c <= 0 then x0 = 2 end
      if c + w >= DESIGN_W then x1 = mw - 1 end
    end
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end
    if x1 > mw then x1 = mw end
    if y1 > mh then y1 = mh end
    if x0 < 1 then x0 = 1 end
    -- Tighten the arrow cluster by one cell toward the center.
    if style == "arrow" then
      if name == "up" then
        y0, y1 = y0 + 1, y1 + 1
      elseif name == "down" then
        y0, y1 = y0 - 1, y1 - 1
      elseif name == "left" then
        x0, x1 = x0 + 1, x1 + 1
      elseif name == "right" then
        x0, x1 = x0 - 1, x1 - 1
      end
      if x0 < 1 then local d = 1 - x0; x0, x1 = x0 + d, x1 + d end
      if x1 > mw then local d = x1 - mw; x0, x1 = x0 - d, x1 - d end
      if y0 < 1 then local d = 1 - y0; y0, y1 = y0 + d, y1 + d end
      if y1 > mh then local d = y1 - mh; y0, y1 = y0 - d, y1 - d end
    end
    if is_fkey and y1 > self.fkey_band_y1 then
      self.fkey_band_y1 = y1
    end

    local height = y1 - y0 + 1
    local need_legend = second or diamond or alpha
    local legend_y, face_y0, legend_on_face
    -- Need height >= 3 before stealing a row for legends, so the face stays readable.
    if height >= 3 and need_legend then
      legend_y = y0
      face_y0 = y0 + 1
      legend_on_face = false
    elseif need_legend then
      legend_y = nil
      face_y0 = y0
      legend_on_face = true
    else
      legend_y = nil
      face_y0 = y0
      legend_on_face = false
    end

    self.buttons[#self.buttons + 1] = {
      name = name,
      label = label,
      style = style,
      second = second,
      diamond = diamond,
      alpha = alpha,
      fkey = is_fkey,
      x0 = x0, y0 = y0, x1 = x1, y1 = y1,
      legend_y = legend_y,
      face_y0 = face_y0,
      legend_on_face = legend_on_face,
    }
  end
end

local function fill_rect(mon, x0, y0, x1, y1, bg)
  if y1 < y0 or x1 < x0 then
    return
  end
  mon.setBackgroundColor(bg)
  local line = string.rep(" ", x1 - x0 + 1)
  for y = y0, y1 do
    mon.setCursorPos(x0, y)
    mon.write(line)
  end
end

--- Paint a circular key face (F-keys / arrows). Face should already be square-ish.
local function fill_circle_face(mon, x0, y0, x1, y1, face_bg, border_bg)
  if y1 < y0 or x1 < x0 then
    return
  end
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
  local outer2 = 1.08 * 1.08
  local inner = border_bg and 0.70 or 0
  local inner2 = inner * inner
  for y = y0, y1 do
    for x = x0, x1 do
      local dx = (x - cx) / rx
      local dy = (y - cy) / ry
      local d2 = dx * dx + dy * dy
      if d2 <= outer2 then
        local bg = face_bg
        if border_bg and d2 > inner2 then
          bg = border_bg
        end
        mon.setCursorPos(x, y)
        mon.setBackgroundColor(bg)
        mon.write(" ")
      end
    end
  end
end

--- Wide key face: full width/height with corner cutouts (rounded rect).
-- Optional border_bg paints an outer rim (SHIFT white outline).
local function fill_round_rect_face(mon, x0, y0, x1, y1, face_bg, border_bg)
  if y1 < y0 or x1 < x0 then
    return
  end
  local w = x1 - x0 + 1
  local h = y1 - y0 + 1
  if w <= 2 or h <= 1 then
    if border_bg and w >= 3 then
      fill_rect(mon, x0, y0, x1, y1, border_bg)
      fill_rect(mon, x0 + 1, y0, x1 - 1, y1, face_bg)
    else
      fill_rect(mon, x0, y0, x1, y1, face_bg)
    end
    return
  end
  for y = y0, y1 do
    for x = x0, x1 do
      local at_corner = (x == x0 or x == x1) and (y == y0 or y == y1)
      if at_corner then
        -- leave plate behind for rounded look
      else
        local on_rim = false
        if border_bg then
          on_rim = (x == x0 or x == x1 or y == y0 or y == y1)
          if (y == y0 or y == y1) and (x == x0 + 1 or x == x1 - 1) then
            on_rim = true
          end
          if (x == x0 or x == x1) and (y == y0 + 1 or y == y1 - 1) then
            on_rim = true
          end
        end
        mon.setCursorPos(x, y)
        mon.setBackgroundColor((on_rim and border_bg) or face_bg)
        mon.write(" ")
      end
    end
  end
end

local function write_clipped(mon, x, y, text, fg, bg, x0, x1)
  if not text or text == "" or y < 1 then
    return
  end
  if x < x0 then x = x0 end
  if x > x1 then
    return
  end
  mon.setCursorPos(x, y)
  mon.setTextColor(fg)
  mon.setBackgroundColor(bg)
  mon.write(text:sub(1, x1 - x + 1))
end

function M:draw()
  local C = CC.colors()
  local mon = self.mon
  local mw, mh = mon.getSize()
  local body = C.black
  local fkey_bg = C.black
  -- Love legend2 / legendd / legend_alpha → CC lightBlue / lime / white.
  local second_fg = C.lightBlue or C.cyan
  local diamond_fg = C.lime or C.green
  local alpha_fg = C.white

  local fkey_band_y1 = self.fkey_band_y1 or 1
  if fkey_band_y1 > mh then fkey_band_y1 = mh end
  if fkey_band_y1 < 1 then fkey_band_y1 = 1 end

  mon.setBackgroundColor(body)
  mon.clear()
  fill_rect(mon, 1, 1, mw, fkey_band_y1, fkey_bg)

  for _, b in ipairs(self.buttons) do
    local face_bg, face_fg = style_colors(C, b.style, b.name == self.pressed)
    local lx0, lx1 = b.x0, b.x1
    local width = lx1 - lx0 + 1
    local legend_bg = b.fkey and fkey_bg or body

    local function paint_legends(y, bg)
      if not (b.second or b.diamond or b.alpha) then
        return
      end
      fill_rect(mon, lx0, y, lx1, y, bg)

      -- F-row: 2nd (F6–F8) left lightBlue; diamond (Y=/WINDOW/…) right lime.
      if b.fkey then
        local left = short_legend(b.second, math.max(1, width - 1))
        local right = short_legend(b.diamond, math.max(1, width - 1))
        if left and right and width >= 3 then
          local room = math.max(1, width - #right - 1)
          left = left:sub(1, room)
          write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
          write_clipped(mon, lx1 - #right + 1, y, right, diamond_fg, bg, lx0, lx1)
        elseif left then
          write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
        elseif right then
          -- F4/F5: diamond-only legends centered-ish on the right half.
          write_clipped(mon, lx1 - #right + 1, y, right, diamond_fg, bg, lx0, lx1)
        end
        return
      end

      local left = short_legend(b.second)
      local mid = short_legend(b.diamond)
      local right = short_legend(b.alpha)
      local n = (left and 1 or 0) + (mid and 1 or 0) + (right and 1 or 0)
      if n == 0 then return end

      if n == 3 then
        -- Always reserve a mid slot for diamond ([ ] !) even on tight keys.
        local third = math.max(1, math.floor(width / 3))
        local l = left:sub(1, third)
        local m = mid:sub(1, math.max(1, width - 2 * third))
        local r = right:sub(1, third)
        write_clipped(mon, lx0, y, l, second_fg, bg, lx0, lx1)
        write_clipped(mon, lx0 + #l, y, m, diamond_fg, bg, lx0, lx1)
        write_clipped(mon, lx1 - #r + 1, y, r, alpha_fg, bg, lx0, lx1)
      elseif n == 2 and width >= 2 then
        local parts = {}
        if left then parts[#parts + 1] = { left, second_fg } end
        if mid then parts[#parts + 1] = { mid, diamond_fg } end
        if right then parts[#parts + 1] = { right, alpha_fg } end
        local a, acol = parts[1][1], parts[1][2]
        local c, ccol = parts[2][1], parts[2][2]
        local room = math.max(1, width - #c - 1)
        a = a:sub(1, room)
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
      paint_legends(b.legend_y, legend_bg)
    end

    local face_x0, face_x1 = b.x0, b.x1
    local face_y0, face_y1 = b.face_y0, b.y1
    local face_w = face_x1 - face_x0 + 1
    local face_h = face_y1 - face_y0 + 1
    local circular = b.style == "fkey" or b.style == "arrow"
    if circular then
      -- Square the face so F-keys / arrows read as circles, not ovals.
      if face_w > face_h and face_h >= 1 then
        local d = face_h
        local mid = math.floor((face_x0 + face_x1) / 2)
        face_x0 = mid - math.floor((d - 1) / 2)
        face_x1 = face_x0 + d - 1
        if face_x0 < b.x0 then face_x0 = b.x0; face_x1 = b.x0 + d - 1 end
        if face_x1 > b.x1 then face_x1 = b.x1; face_x0 = b.x1 - d + 1 end
        face_w = face_x1 - face_x0 + 1
      elseif face_h > face_w and face_w >= 1 then
        local d = face_w
        local mid = math.floor((face_y0 + face_y1) / 2)
        face_y0 = mid - math.floor((d - 1) / 2)
        face_y1 = face_y0 + d - 1
        if face_y0 < b.face_y0 then face_y0 = b.face_y0; face_y1 = b.face_y0 + d - 1 end
        if face_y1 > b.y1 then face_y1 = b.y1; face_y0 = b.y1 - d + 1 end
        face_h = face_y1 - face_y0 + 1
      end
    end

    local border = (b.style == "shift") and C.white or nil
    -- Formerly black keys: gray faces on black plate, no outline.
    if face_bg == C.black then
      face_bg = C.gray
    end
    if circular then
      fill_circle_face(mon, face_x0, face_y0, face_x1, face_y1, face_bg, border)
    else
      -- Normal keys: full cell width, rounded corners.
      fill_round_rect_face(mon, face_x0, face_y0, face_x1, face_y1, face_bg, border)
    end

    local face_label = b.label
    if face_label == "CATALOG" and face_w < 7 then
      face_label = "CAT"
    elseif face_label == "WINDOW" and face_w < 6 then
      face_label = "WIN"
    end

    if b.legend_on_face and (b.second or b.diamond or b.alpha) and face_h == 1 then
      local left = short_legend(b.second, math.max(1, math.floor(face_w / 3)))
      local mid = short_legend(b.diamond, math.max(1, math.floor(face_w / 3)))
      local right = short_legend(b.alpha, math.max(1, math.floor(face_w / 3)))
      if b.fkey then
        left = short_legend(b.second, math.max(1, face_w - 1))
        right = short_legend(b.diamond, math.max(1, face_w - 1))
        mid = nil
      end
      -- Prefer legends over the face glyph when all three modifiers share one row.
      if left and mid and right and face_w >= 3 then
        local l = left:sub(1, 1)
        local r = right:sub(1, 1)
        local m = mid:sub(1, math.max(1, face_w - 2))
        write_clipped(mon, face_x0, face_y0, l, second_fg, face_bg, face_x0, face_x1)
        write_clipped(mon, face_x0 + 1, face_y0, m, diamond_fg, face_bg, face_x0, face_x1)
        write_clipped(mon, face_x1 - #r + 1, face_y0, r, alpha_fg, face_bg, face_x0, face_x1)
      else
        if left then
          write_clipped(mon, face_x0, face_y0, left, second_fg, face_bg, face_x0, face_x1)
        end
        if right then
          write_clipped(mon, face_x1 - #right + 1, face_y0, right,
            b.fkey and diamond_fg or alpha_fg, face_bg, face_x0, face_x1)
        end
        if mid and not b.fkey then
          write_clipped(mon, face_x0 + (left and #left or 0) + 1, face_y0, mid,
            diamond_fg, face_bg, face_x0, face_x1)
        end
        local room = face_w
          - (left and #left or 0)
          - (right and #right or 0)
          - ((left and right) and 1 or 0)
        if room > 0 and not b.fkey and not mid then
          local mid_face = face_label
          if #mid_face > room then mid_face = mid_face:sub(1, room) end
          local mx = face_x0 + (left and #left or 0) + ((left and 1) or 0)
          write_clipped(mon, mx, face_y0, mid_face, face_fg, face_bg, face_x0, face_x1)
        end
      end
    else
      local label = face_label
      if b.style == "shift" then
        label = "^"
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
