-- Keypad UI on a wrapped Advanced Monitor (monitor_touch -> key names).
-- Gray body with a black strip behind the F1-F5 row; blue graph/apps/arrows/div/mul/sub/add/ENTER;
-- black function/misc-op/ON keys; lightGray number pad; yellow 2nd; green ALPHA; lightBlue legends.

local CC = require("frontends.computercraft.cc")

local M = {}
M.__index = M

-- name, label, style, col, row, w, h, second, alpha [, fkey]
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

local DESIGN_W = 5
local DESIGN_H = 13.2
-- Top black faceplate ends here in design rows (graph/F-keys are [0,1); up @ 1.35).
local FKEY_BAND_END = 1.0

--- Map style -> { face_bg, face_fg } using CC palette (TI-83+ defaults).
local function style_colors_ti83(C, style, pressed)
  if pressed then
    return C.orange, C.black
  end
  if style == "second" then
    return C.yellow, C.black
  elseif style == "alpha" then
    return C.green, C.white
  elseif style == "fn" or style == "op" or style == "on" then
    -- Function / misc ops (x^-1, x^2, parens, ^, ON, ...) - black faces.
    return C.black, C.white
  elseif style == "num" then
    -- Number pad 0-9 . (-) - light gray.
    return C.lightGray, C.black
  elseif style == "graph" or style == "apps" or style == "arrow"
      or style == "blue_op" or style == "enter" then
    -- Blue: F1-F5 row, apps, arrows, div/mul/sub/add, ENTER.
    return C.blue, C.white
  end
  return C.lightGray, C.black
end

local function cc_named(C, name, fallback)
  if type(name) == "string" and C[name] then
    return C[name]
  end
  return fallback
end

--- @param mon_or_side wrapped monitor or peripheral side string
-- @param opts optional { text_scale=, side=, theme= }
-- theme: { body=, fkey_band=, legend_2nd=, legend_alpha=, legend_fkey=, style_colors=fn }
function M.new(mon_or_side, opts)
  opts = opts or {}
  local mon, side
  if CC.is_cc() then
    mon, side = CC.wrap_monitor(mon_or_side, "keypad")
  else
    mon = mon_or_side
    side = opts.side
  end
  if mon.setTextScale and opts.text_scale ~= false then
    mon.setTextScale(opts.text_scale or 0.5)
  end
  local theme = opts.theme or {}
  local self = setmetatable({
    mon = mon,
    side = side or opts.side,
    buttons = {},
    pressed = nil,
    theme = theme,
    style_colors = theme.style_colors or style_colors_ti83,
  }, M)
  self:relayout()
  return self
end

function M:relayout()
  local mon = self.mon
  local mw, mh = mon.getSize()
  local cell_w = mw / DESIGN_W
  local cell_h = mh / DESIGN_H
  -- Gutters between keys; legends live in the top strip of each key slot.
  local gap_x, gap_y = 1, 1
  self.buttons = {}
  self.fkey_band_y1 = math.max(1, math.floor(FKEY_BAND_END * mh / DESIGN_H + 0.5))
  for _, k in ipairs(KEYS) do
    local name, label, style = k[1], k[2], k[3]
    local c, r, w, h = k[4], k[5], k[6], k[7]
    local second, alpha, fkey = k[8], k[9], k[10]
    local x0 = math.floor(c * cell_w) + 1
    local y0 = math.floor(r * cell_h) + 1
    local x1 = math.floor((c + w) * cell_w) - gap_x
    local y1 = math.floor((r + h) * cell_h) - gap_y
    -- F-key row: 1-cell black trim on the outer left/right (symmetric).
    -- Default gap_x already insets the right of each key; without this the
    -- first key sits on x=1 and the left trim is missing (one-off).
    if fkey then
      if c <= 0 then
        x0 = 2
      end
      if c + w >= DESIGN_W then
        x1 = mw - 1
      end
    end
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end
    if x1 > mw then x1 = mw end
    if y1 > mh then y1 = mh end
    if x0 < 1 then x0 = 1 end
    if fkey and y1 > self.fkey_band_y1 then
      self.fkey_band_y1 = y1
    end

    local height = y1 - y0 + 1
    local need_legend = second or alpha or fkey
    local legend_y, face_y0, legend_on_face
    if height >= 2 then
      -- Dedicated row above the key face for F-keys / 2nd / alpha.
      legend_y = y0
      face_y0 = y0 + 1
      legend_on_face = false
    elseif need_legend then
      -- Tiny monitors: paint abbreviated legends on the face row itself.
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
      alpha = alpha,
      fkey = fkey,
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
  local theme = self.theme or {}
  local body = cc_named(C, theme.body, C.gray) -- faceplate below the F-key header
  local fkey_bg = cc_named(C, theme.fkey_band, C.black)
  local second_fg = cc_named(C, theme.legend_2nd, C.yellow)
  local alpha_fg = cc_named(C, theme.legend_alpha, C.lightBlue or C.cyan)
  local fkey_fg = cc_named(C, theme.legend_fkey, C.lightBlue or C.cyan)
  local style_colors = self.style_colors or style_colors_ti83

  -- Black trim: full width, top row through F-key bottoms (never shrink below keys).
  local fkey_band_y1 = self.fkey_band_y1 or 1
  if fkey_band_y1 > mh then
    fkey_band_y1 = mh
  end
  if fkey_band_y1 < 1 then
    fkey_band_y1 = 1
  end

  mon.setBackgroundColor(body)
  mon.clear()
  -- Paint black AFTER clear so top-left / top-right are exactly flush to (1,1)/(mw,*).
  fill_rect(mon, 1, 1, mw, fkey_band_y1, fkey_bg)

  for _, b in ipairs(self.buttons) do
    local face_bg, face_fg = style_colors(C, b.style, b.name == self.pressed)
    local lx0, lx1 = b.x0, b.x1
    local width = lx1 - lx0 + 1
    local legend_bg = b.fkey and fkey_bg or body

    local function paint_legends(y, bg)
      if not (b.fkey or b.second or b.alpha) then
        return
      end
      fill_rect(mon, lx0, y, lx1, y, bg)

      -- Top graph row: 2nd name left, F1-F5 on the right.
      if b.fkey then
        local fk = tostring(b.fkey)
        if b.second then
          local left = tostring(b.second)
          local room = math.max(1, width - #fk - 1)
          left = left:sub(1, room)
          write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
          write_clipped(mon, lx1 - #fk + 1, y, fk, fkey_fg, bg, lx0, lx1)
        else
          write_clipped(mon, lx1 - #fk + 1, y, fk, fkey_fg, bg, lx0, lx1)
        end
        return
      end

      local sep = 1
      if b.second and b.alpha and width >= 3 then
        local left = tostring(b.second)
        local right = tostring(b.alpha)
        local room_left = math.max(1, width - #right - sep)
        left = left:sub(1, room_left)
        write_clipped(mon, lx0, y, left, second_fg, bg, lx0, lx1)
        local ax = lx1 - #right + 1
        if ax < lx0 + #left + sep then
          ax = lx0 + #left + sep
        end
        write_clipped(mon, ax, y, right, alpha_fg, bg, lx0, lx1)
      elseif b.second then
        write_clipped(mon, lx0, y, b.second, second_fg, bg, lx0, lx1)
      elseif b.alpha then
        local right = tostring(b.alpha)
        write_clipped(mon, lx1 - #right + 1, y, right, alpha_fg, bg, lx0, lx1)
      end
    end

    if b.legend_y then
      paint_legends(b.legend_y, legend_bg)
    end
    fill_rect(mon, b.x0, b.face_y0, b.x1, b.y1, face_bg)
    local face_w = b.x1 - b.x0 + 1
    local face_h = b.y1 - b.face_y0 + 1

    if b.legend_on_face and (b.fkey or b.second or b.alpha) and face_h == 1 then
      if b.fkey then
        local fk = tostring(b.fkey)
        local left = b.second and tostring(b.second) or ""
        if left ~= "" then
          local room = math.max(1, face_w - #fk - 1)
          left = left:sub(1, room)
          write_clipped(mon, b.x0, b.face_y0, left, second_fg, face_bg, b.x0, b.x1)
        end
        write_clipped(mon, b.x1 - #fk + 1, b.face_y0, fk, fkey_fg, face_bg, b.x0, b.x1)
      else
        local left = b.second and tostring(b.second):sub(1, math.max(1, math.floor(face_w / 2))) or ""
        local right = b.alpha and tostring(b.alpha) or ""
        if left ~= "" then
          write_clipped(mon, b.x0, b.face_y0, left, second_fg, face_bg, b.x0, b.x1)
        end
        if right ~= "" then
          write_clipped(mon, b.x1 - #right + 1, b.face_y0, right, alpha_fg, face_bg, b.x0, b.x1)
        end
        local mid = b.label
        local room = face_w - #left - #right - ((left ~= "" and right ~= "") and 1 or 0)
        if room > 0 then
          if #mid > room then mid = mid:sub(1, room) end
          local mx = b.x0 + #left + ((left ~= "" and 1) or 0)
          if mx + #mid - 1 > b.x1 - #right then
            mx = math.max(b.x0, b.x1 - #right - #mid + 1)
          end
          write_clipped(mon, mx, b.face_y0, mid, face_fg, face_bg, b.x0, b.x1)
        end
      end
    else
      local label = b.label
      if #label > face_w then
        label = label:sub(1, face_w)
      end
      local lx = math.floor((b.x0 + b.x1 - #label) / 2)
      local ly = b.face_y0 + math.floor((face_h - 1) / 2)
      if lx < b.x0 then lx = b.x0 end
      if ly < b.face_y0 then ly = b.face_y0 end
      mon.setCursorPos(lx, ly)
      mon.setTextColor(face_fg)
      mon.setBackgroundColor(face_bg)
      mon.write(label)
    end
  end
end

--- Hit-test monitor cell (1-based). Returns key name or nil.
-- Legends are part of the key hit target (same as pressing the key).
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
