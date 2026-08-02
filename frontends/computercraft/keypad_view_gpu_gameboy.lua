-- Game Boy DMG keypad on Tom's GPU - cross D-pad, rounded-rect Select/Start, round A/B.
-- Layout proportions match a real DMG face (not a grid of rectangles).

local Gpu = require("frontends.computercraft.gpu")

local COL = {
  body = Gpu.argb(0.52, 0.52, 0.58),
  dpad = Gpu.argb(0.18, 0.18, 0.22),
  dpad_hi = Gpu.argb(0.28, 0.28, 0.32),
  action = Gpu.argb(0.62, 0.16, 0.38),
  action_hi = Gpu.argb(0.78, 0.28, 0.48),
  pill = Gpu.argb(0.38, 0.36, 0.48),
  pill_hi = Gpu.argb(0.55, 0.50, 0.65),
  label = Gpu.argb(0.95, 0.95, 0.92),
  pressed = Gpu.argb(0.90, 0.48, 0.12),
  ink = Gpu.argb(0.12, 0.10, 0.18),
}

local M = {}
M.__index = M

function M.new(gpu)
  return setmetatable({
    gpu = gpu,
    panel = { x = 0, y = 0, w = 0, h = 0 },
    buttons = {}, -- { key, kind, ...geometry, label }
    pressed = nil,
    max_w = nil,
    max_h = nil,
  }, M)
end

function M:set_bounds(max_w, max_h)
  self.max_w, self.max_h = max_w, max_h
end

function M:set_pressed(name)
  self.pressed = name
end

--- Accurate DMG control cluster inside the pad rect.
function M:layout(x, y, w, h)
  self.panel = { x = x, y = y, w = w, h = h }
  self.buttons = {}
  if w < 40 or h < 30 then return end

  local u = math.min(w, h)
  -- D-pad (plus) on the left
  local dpad_cx = x + w * 0.22
  local dpad_cy = y + h * 0.45
  local arm = math.max(6, u * 0.11)       -- arm thickness
  local reach = math.max(14, u * 0.22)    -- center to tip
  local half = arm * 0.5
  -- Four hit targets (overlap in center is fine - same as physical cross)
  local dpad = {
    { "up", dpad_cx - half, dpad_cy - reach, arm, reach },
    { "down", dpad_cx - half, dpad_cy, arm, reach },
    { "left", dpad_cx - reach, dpad_cy - half, reach, arm },
    { "right", dpad_cx, dpad_cy - half, reach, arm },
  }
  for _, d in ipairs(dpad) do
    self.buttons[#self.buttons + 1] = {
      key = d[1], kind = "rect", label = "",
      x = d[2], y = d[3], w = d[4], h = d[5],
    }
  end
  self._dpad = { cx = dpad_cx, cy = dpad_cy, arm = arm, reach = reach }

  -- Select / Start - rounded rects; START is wider so the label fits inside.
  local bh = math.max(10, u * 0.075)
  local br = math.max(3, math.floor(bh * 0.45))
  local pill_y = y + h * 0.78 - bh * 0.5
  local gap = math.max(12, u * 0.09)
  local sel_w = math.max(22, u * 0.15)
  local start_w = math.max(40, u * 0.26) -- ~5 glyph widths at scale 1
  local pair_w = sel_w + gap + start_w
  -- Keep the pair in the center band, left of A/B.
  local max_right = x + w * 0.66
  local sel_x = x + w * 0.50 - pair_w * 0.5
  if sel_x + pair_w > max_right then
    sel_x = max_right - pair_w
  end
  if sel_x < x + 2 then sel_x = x + 2 end
  local start_x = sel_x + sel_w + gap
  self.buttons[#self.buttons + 1] = {
    key = "select", kind = "rrect", label = "SEL",
    x = sel_x, y = pill_y, w = sel_w, h = bh, r = br,
  }
  self.buttons[#self.buttons + 1] = {
    key = "start", kind = "rrect", label = "START",
    x = start_x, y = pill_y, w = start_w, h = bh, r = br,
  }

  -- B / A - round magenta buttons (A sits lower-right of B, like a DMG)
  local ar = math.max(8, u * 0.115)
  self.buttons[#self.buttons + 1] = {
    key = "b", kind = "circle", label = "B",
    cx = x + w * 0.72, cy = y + h * 0.38, r = ar,
  }
  self.buttons[#self.buttons + 1] = {
    key = "a", kind = "circle", label = "A",
    cx = x + w * 0.88, cy = y + h * 0.52, r = ar,
  }
end

local function hit_circle(b, mx, my)
  local dx, dy = mx - b.cx, my - b.cy
  return dx * dx + dy * dy <= (b.r + 1) * (b.r + 1)
end

local function hit_rrect(b, mx, my)
  return mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h
end

local function hit_rect(b, mx, my)
  return mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h
end

function M:hit(mx, my)
  for i = #self.buttons, 1, -1 do
    local b = self.buttons[i]
    if b.kind == "circle" and hit_circle(b, mx, my) then
      return b.key
    elseif b.kind == "rrect" and hit_rrect(b, mx, my) then
      return b.key
    elseif b.kind == "rect" and hit_rect(b, mx, my) then
      return b.key
    end
  end
  return nil
end

local function draw_label(gpu, cx, cy, text, color)
  if not gpu.drawText or not text or text == "" then return end
  local tw = #text * 5
  if gpu.getTextLength then
    local ok, len = pcall(gpu.getTextLength, text, 1)
    if ok then tw = tonumber(len) or tw end
  end
  local tx = math.floor(cx - tw * 0.5)
  local ty = math.floor(cy - 3)
  pcall(gpu.drawText, math.max(1, tx), math.max(1, ty), text, color, Gpu.TEXT_BG_NONE, 1)
end

function M:draw()
  local gpu = self.gpu
  local p = self.panel
  if not gpu or not p or p.w < 4 then return end
  local mw, mh = self.max_w, self.max_h
  Gpu.rect(gpu, p.x, p.y, p.w, p.h, COL.body, mw, mh)

  -- D-pad cross (plain rects - no circle end-caps)
  local d = self._dpad
  if d then
    local pressed_dpad = self.pressed == "up" or self.pressed == "down"
      or self.pressed == "left" or self.pressed == "right"
    local face = pressed_dpad and COL.pressed or COL.dpad
    local cx, cy, arm, reach = d.cx, d.cy, d.arm, d.reach
    local half = arm * 0.5
    Gpu.rect(gpu, cx - half, cy - reach, arm, reach * 2, face, mw, mh)
    Gpu.rect(gpu, cx - reach, cy - half, reach * 2, arm, face, mw, mh)
    -- Center nub (square, not circle)
    local nub = math.max(2, arm * 0.55)
    Gpu.rect(gpu, cx - nub * 0.5, cy - nub * 0.5, nub, nub,
      pressed_dpad and COL.pressed or COL.dpad_hi, mw, mh)
  end

  for _, b in ipairs(self.buttons) do
    local down = self.pressed == b.key
    if b.kind == "circle" then
      local face = down and COL.pressed or COL.action
      Gpu.circle(gpu, b.cx, b.cy, b.r, face, mw, mh)
      Gpu.circle(gpu, b.cx, b.cy, b.r * 0.72, down and COL.pressed or COL.action_hi, mw, mh)
      draw_label(gpu, b.cx, b.cy, b.label, COL.label)
    elseif b.kind == "rrect" then
      local face = down and COL.pressed or COL.pill
      Gpu.rounded_rect(gpu, b.x, b.y, b.w, b.h, b.r, face, mw, mh)
      draw_label(gpu, b.x + b.w * 0.5, b.y + b.h * 0.5, b.label,
        down and COL.ink or COL.label)
    end
  end
end

return M
