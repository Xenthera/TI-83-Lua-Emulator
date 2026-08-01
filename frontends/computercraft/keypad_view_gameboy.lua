-- Game Boy DMG keypad on a ComputerCraft advanced monitor.

local CC = require("frontends.computercraft.cc")

local M = {}
M.__index = M

-- name, label, style, col, row, w, h
local KEYS = {
  { "up", "^", "arrow", 1.5, 0.2, 1.2, 1.0 },
  { "left", "<", "arrow", 0.3, 1.2, 1.2, 1.0 },
  { "right", ">", "arrow", 2.7, 1.2, 1.2, 1.0 },
  { "down", "v", "arrow", 1.5, 2.2, 1.2, 1.0 },
  { "select", "SEL", "fn", 4.4, 2.4, 1.6, 0.8 },
  { "start", "START", "fn", 6.2, 2.4, 1.6, 0.8 },
  { "b", "B", "action", 7.2, 0.6, 1.3, 1.3 },
  { "a", "A", "action", 8.6, 1.2, 1.3, 1.3 },
}

local DESIGN_W = 10
local DESIGN_H = 4

local function style_colors(C, style, pressed)
  if pressed then
    return C.orange, C.black
  end
  if style == "action" then
    return C.red, C.white
  elseif style == "arrow" then
    return C.gray, C.white
  end
  return C.lightGray, C.black
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
  local gap_x, gap_y = 1, 1
  self.buttons = {}
  for _, k in ipairs(KEYS) do
    local name, label, style = k[1], k[2], k[3]
    local c, r, w, h = k[4], k[5], k[6], k[7]
    local x0 = math.floor(c * cell_w) + 1
    local y0 = math.floor(r * cell_h) + 1
    local x1 = math.floor((c + w) * cell_w) - gap_x
    local y1 = math.floor((r + h) * cell_h) - gap_y
    if x1 < x0 then x1 = x0 end
    if y1 < y0 then y1 = y0 end
    if x1 > mw then x1 = mw end
    if y1 > mh then y1 = mh end
    if x0 < 1 then x0 = 1 end
    if y0 < 1 then y0 = 1 end
    self.buttons[#self.buttons + 1] = {
      name = name, label = label, style = style,
      x0 = x0, y0 = y0, x1 = x1, y1 = y1,
    }
  end
end

local function fill_rect(mon, x0, y0, x1, y1, bg)
  if y1 < y0 or x1 < x0 then return end
  local blank = string.rep(" ", x1 - x0 + 1)
  mon.setBackgroundColor(bg)
  for y = y0, y1 do
    mon.setCursorPos(x0, y)
    mon.write(blank)
  end
end

function M:draw()
  local mon = self.mon
  local C = CC.colors()
  mon.setBackgroundColor(C.lightGray)
  mon.clear()
  for _, b in ipairs(self.buttons) do
    local pressed = self.pressed == b.name
    local bg, fg = style_colors(C, b.style, pressed)
    fill_rect(mon, b.x0, b.y0, b.x1, b.y1, bg)
    mon.setTextColor(fg)
    mon.setBackgroundColor(bg)
    local label = b.label
    local tw = #label
    local bw = b.x1 - b.x0 + 1
    local bh = b.y1 - b.y0 + 1
    local tx = b.x0 + math.max(0, math.floor((bw - tw) / 2))
    local ty = b.y0 + math.max(0, math.floor((bh - 1) / 2))
    mon.setCursorPos(tx, ty)
    mon.write(label:sub(1, bw))
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
