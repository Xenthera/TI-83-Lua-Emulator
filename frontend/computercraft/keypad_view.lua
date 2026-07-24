-- Keypad UI on a wrapped Advanced Monitor (monitor_touch → key names).
-- Yellow = 2nd legends, green = alpha legends (above / on the top of each key).

local CC = require("frontend.computercraft.cc")

local M = {}
M.__index = M

-- name, label, col, row, w, h, second, alpha  (short names for CC cells)
local KEYS = {
  { "yequ", "Y=", 0, 0, 1, 1, "PLOT", nil },
  { "window", "WIN", 1, 0, 1, 1, "TBLSET", nil },
  { "zoom", "ZOOM", 2, 0, 1, 1, "FMT", nil },
  { "trace", "TRC", 3, 0, 1, 1, "CALC", nil },
  { "graph", "GRPH", 4, 0, 1, 1, "TABLE", nil },

  { "2nd", "2nd", 0, 1.25, 1, 1, nil, nil },
  { "mode", "MODE", 1, 1.25, 1, 1, "QUIT", nil },
  { "del", "DEL", 2, 1.25, 1, 1, "INS", nil },
  { "up", "^", 3.5, 1.1, 1, 0.9, nil, nil },

  { "alpha", "ALPHA", 0, 2.5, 1, 1, "A-LCK", nil },
  { "xt", "X,T", 1, 2.5, 1, 1, "LINK", nil },
  { "stat", "STAT", 2, 2.5, 1, 1, "LIST", nil },
  { "left", "<", 3.0, 2.35, 0.9, 0.9, nil, nil },
  { "right", ">", 4.1, 2.35, 0.9, 0.9, nil, nil },

  { "down", "v", 3.5, 3.4, 1, 0.9, nil, nil },

  { "math", "MATH", 0, 4.5, 1, 1, "TEST", "A" },
  { "apps", "APPS", 1, 4.5, 1, 1, "ANGLE", "B" },
  { "prgm", "PRGM", 2, 4.5, 1, 1, "DRAW", "C" },
  { "vars", "VARS", 3, 4.5, 1, 1, "DISTR", nil },
  { "clear", "CLR", 4, 4.5, 1, 1, nil, nil },

  { "recip", "x^-1", 0, 5.75, 1, 1, "MATRX", "D" },
  { "sin", "SIN", 1, 5.75, 1, 1, "SIN-1", "E" },
  { "cos", "COS", 2, 5.75, 1, 1, "COS-1", "F" },
  { "tan", "TAN", 3, 5.75, 1, 1, "TAN-1", "G" },
  { "power", "^", 4, 5.75, 1, 1, "pi", "H" },

  { "square", "x^2", 0, 7.0, 1, 1, "sqrt", "I" },
  { "comma", ",", 1, 7.0, 1, 1, "EE", "J" },
  { "lparen", "(", 2, 7.0, 1, 1, "{", "K" },
  { "rparen", ")", 3, 7.0, 1, 1, "}", "L" },
  { "div", "/", 4, 7.0, 1, 1, "e", "M" },

  { "log", "LOG", 0, 8.25, 1, 1, "10^x", "N" },
  { "7", "7", 1, 8.25, 1, 1, "u", "O" },
  { "8", "8", 2, 8.25, 1, 1, "v", "P" },
  { "9", "9", 3, 8.25, 1, 1, "w", "Q" },
  { "mul", "*", 4, 8.25, 1, 1, "[", "R" },

  { "ln", "LN", 0, 9.5, 1, 1, "e^x", "S" },
  { "4", "4", 1, 9.5, 1, 1, "L4", "T" },
  { "5", "5", 2, 9.5, 1, 1, "L5", "U" },
  { "6", "6", 3, 9.5, 1, 1, "L6", "V" },
  { "minus", "-", 4, 9.5, 1, 1, "]", "W" },

  { "sto", "STO", 0, 10.75, 1, 1, "RCL", "X" },
  { "1", "1", 1, 10.75, 1, 1, "L1", "Y" },
  { "2", "2", 2, 10.75, 1, 1, "L2", "Z" },
  { "3", "3", 3, 10.75, 1, 1, "L3", "th" },
  { "plus", "+", 4, 10.75, 1, 1, "MEM", '"' },

  { "on", "ON", 0, 12.0, 1, 1, "OFF", nil },
  { "0", "0", 1, 12.0, 1, 1, "CAT", "spc" },
  { "dot", ".", 2, 12.0, 1, 1, "i", ":" },
  { "neg", "(-)", 3, 12.0, 1, 1, "ANS", "?" },
  { "enter", "ENT", 4, 12.0, 1, 1.2, "ENTRY", "SOL" },
}

local DESIGN_W = 5
local DESIGN_H = 13.4

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
  if mon.setTextScale and opts.text_scale ~= false then
    mon.setTextScale(opts.text_scale or 0.5)
  end
  local self = setmetatable({
    mon = mon,
    side = side or opts.side,
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
  -- Leave a 1-cell gutter between adjacent keys so alpha / 2nd legends don't collide.
  local gap_x, gap_y = 1, 0
  self.buttons = {}
  for _, k in ipairs(KEYS) do
    local name, label, c, r, w, h = k[1], k[2], k[3], k[4], k[5], k[6]
    local second, alpha = k[7], k[8]
    local x0 = math.floor(c * cell_w) + 1
    local y0 = math.floor(r * cell_h) + 1
    local x1 = math.floor((c + w) * cell_w)
    local y1 = math.floor((r + h) * cell_h)
    -- Shrink right/bottom edge to create gutters (keep at least 1x1).
    x1 = x1 - gap_x
    y1 = y1 - gap_y
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end
    if x1 > mw then x1 = mw end
    if y1 > mh then y1 = mh end
    local tall = (y1 - y0 + 1) >= 3
    local mid = (y1 - y0 + 1) >= 2
    -- Legend row sits above the face when we have height; else share the top line.
    local legend_y = nil
    local face_y0 = y0
    if tall then
      legend_y = y0
      face_y0 = y0 + 1
    elseif mid and (second or alpha) then
      legend_y = y0
      face_y0 = y0 + 1
    end
    self.buttons[#self.buttons + 1] = {
      name = name,
      label = label,
      second = second,
      alpha = alpha,
      x0 = x0, y0 = y0, x1 = x1, y1 = y1,
      legend_y = legend_y,
      face_y0 = face_y0,
    }
  end
end

local function fill_rect(mon, x0, y0, x1, y1, bg, fg)
  if y1 < y0 or x1 < x0 then
    return
  end
  mon.setBackgroundColor(bg)
  mon.setTextColor(fg)
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
  local maxw = x1 - x0 + 1
  if maxw < 1 then
    return
  end
  if x < x0 then x = x0 end
  mon.setCursorPos(x, y)
  mon.setTextColor(fg)
  mon.setBackgroundColor(bg)
  mon.write(text:sub(1, x1 - x + 1))
end

function M:draw()
  local C = CC.colors()
  local mon = self.mon
  mon.setBackgroundColor(C.gray)
  mon.clear()

  for _, b in ipairs(self.buttons) do
    local bg = C.lightGray
    if b.name == self.pressed then
      bg = C.yellow
    elseif b.name == "enter" or b.name == "2nd" then
      bg = C.blue
    elseif b.name == "on" then
      bg = C.red
    elseif b.name == "alpha" then
      bg = C.green
    end

    -- Legend strip (above face): gray bg, yellow 2nd + green alpha.
    -- Inset 1 cell from each side and keep a gap between the two legends.
    if b.legend_y then
      fill_rect(mon, b.x0, b.legend_y, b.x1, b.legend_y, C.gray, C.white)
      local lx0 = b.x0
      local lx1 = b.x1
      local width = lx1 - lx0 + 1
      local sep = 1
      if b.second and b.alpha and width >= 4 then
        local left = tostring(b.second)
        local right = tostring(b.alpha)
        local room_left = math.max(1, width - #right - sep)
        left = left:sub(1, room_left)
        write_clipped(mon, lx0, b.legend_y, left, C.yellow, C.gray, lx0, lx1)
        local ax = lx1 - #right + 1
        if ax < lx0 + #left + sep then
          ax = lx0 + #left + sep
        end
        write_clipped(mon, ax, b.legend_y, right, C.lime, C.gray, lx0, lx1)
      elseif b.second then
        write_clipped(mon, lx0, b.legend_y, b.second, C.yellow, C.gray, lx0, lx1)
      elseif b.alpha then
        local right = tostring(b.alpha)
        write_clipped(mon, lx1 - #right + 1, b.legend_y, right, C.lime, C.gray, lx0, lx1)
      end
    end

    fill_rect(mon, b.x0, b.face_y0, b.x1, b.y1, bg, C.black)
    local lx = math.floor((b.x0 + b.x1 - #b.label) / 2)
    local ly = math.floor((b.face_y0 + b.y1) / 2)
    if lx < b.x0 then lx = b.x0 end
    if ly < b.face_y0 then ly = b.face_y0 end
    mon.setCursorPos(lx, ly)
    mon.setTextColor(C.black)
    mon.setBackgroundColor(bg)
    mon.write(b.label:sub(1, b.x1 - b.x0 + 1))
  end
end

--- Hit-test monitor cell (1-based). Returns key name or nil.
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
