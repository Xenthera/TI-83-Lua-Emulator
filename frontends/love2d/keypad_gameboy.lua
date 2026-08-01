-- Game Boy DMG on-screen controls: D-pad + A/B/Start/Select.

local Keypad = {}
Keypad.__index = Keypad
Keypad.DESIGN_COLS = 10
Keypad.DESIGN_ROWS = 4
Keypad.FACE_ASPECT = 0.55

local KEYS = {
  { key = "up", label = "▲", x = 1.5, y = 0.2, w = 1.2, h = 1.0 },
  { key = "left", label = "◀", x = 0.3, y = 1.2, w = 1.2, h = 1.0 },
  { key = "right", label = "▶", x = 2.7, y = 1.2, w = 1.2, h = 1.0 },
  { key = "down", label = "▼", x = 1.5, y = 2.2, w = 1.2, h = 1.0 },
  { key = "select", label = "SELECT", x = 4.4, y = 2.4, w = 1.6, h = 0.7 },
  { key = "start", label = "START", x = 6.2, y = 2.4, w = 1.6, h = 0.7 },
  { key = "b", label = "B", x = 7.2, y = 0.6, w = 1.3, h = 1.3 },
  { key = "a", label = "A", x = 8.6, y = 1.2, w = 1.3, h = 1.3 },
}

function Keypad.new(opts)
  opts = opts or {}
  local self = setmetatable({
    layout_doc = opts.layout,
    panel = { x = 0, y = 0, w = 0, h = 0 },
    x = 0, y = 0, w = 0, h = 0,
    buttons = {},
    pressed = nil,
    hover = nil,
    face_aspect = Keypad.FACE_ASPECT,
  }, Keypad)
  return self
end

function Keypad:layout(x, y, w, h)
  self.x, self.y, self.w, self.h = x, y, w, h
  self.panel = { x = x, y = y, w = w, h = h }
  local ux = w / Keypad.DESIGN_COLS
  local uy = h / Keypad.DESIGN_ROWS
  self.buttons = {}
  for _, k in ipairs(KEYS) do
    self.buttons[#self.buttons + 1] = {
      key = k.key,
      label = k.label,
      x = x + k.x * ux,
      y = y + k.y * uy,
      w = k.w * ux,
      h = k.h * uy,
    }
  end
end

function Keypad:hit_button(mx, my)
  for _, b in ipairs(self.buttons) do
    if mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h then
      return b
    end
  end
  return nil
end

function Keypad:contains(mx, my)
  local p = self.panel
  return p.w > 0 and mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h
end

function Keypad:mousepressed(mx, my)
  if not self:contains(mx, my) then
    return false
  end
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

function Keypad:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end
  love.graphics.setColor(0.55, 0.58, 0.62, 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h, 6, 6)

  local font = love.graphics.getFont()
  for _, b in ipairs(self.buttons) do
    local down = self.pressed == b.key
    local hot = self.hover == b.key
    if b.key == "a" or b.key == "b" then
      love.graphics.setColor(down and 0.45 or (hot and 0.55 or 0.50), 0.12, 0.18, 1)
    else
      love.graphics.setColor(down and 0.25 or (hot and 0.35 or 0.30), 0.30, 0.34, 1)
    end
    local rad = (b.key == "a" or b.key == "b") and math.min(b.w, b.h) / 2 or 4
    if b.key == "a" or b.key == "b" then
      love.graphics.circle("fill", b.x + b.w / 2, b.y + b.h / 2, rad)
    else
      love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, rad, rad)
    end
    love.graphics.setColor(0.95, 0.95, 0.92, 1)
    if font then
      local tw = font:getWidth(b.label)
      local th = font:getHeight()
      love.graphics.print(b.label, b.x + (b.w - tw) / 2, b.y + (b.h - th) / 2)
    end
  end
end

function Keypad:hit()
  return nil
end

function Keypad:set_pressed()
end

return Keypad
