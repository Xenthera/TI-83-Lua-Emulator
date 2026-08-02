-- Empty keypad chrome for the RV64 console machine (LCD-only face).

local Keypad = {}
Keypad.__index = Keypad
Keypad.DESIGN_COLS = 8
Keypad.DESIGN_ROWS = 1
Keypad.FACE_ASPECT = 0.125

function Keypad.new(opts)
  opts = opts or {}
  local self = setmetatable({
    layout_doc = opts.layout,
    panel = { x = 0, y = 0, w = 0, h = 0 },
    x = 0, y = 0, w = 0, h = 0,
    buttons = {},
    pressed = nil,
    hover = nil,
  }, Keypad)
  return self
end

function Keypad:layout(x, y, w, h)
  self.x, self.y, self.w, self.h = x, y, w, h
  self.panel = { x = x, y = y, w = w, h = h }
end

function Keypad:contains(mx, my)
  local p = self.panel
  return p.w > 0 and mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h
end

function Keypad:mousepressed(mx, my)
  if not self:contains(mx, my) then
    return false
  end
  -- No keys; swallow clicks on the chrome so they don't fall through.
  return true
end

function Keypad:mousemoved(_mx, _my)
  self.hover = nil
end

function Keypad:mousereleased()
  local k = self.pressed
  self.pressed = nil
  return k
end

function Keypad:draw()
  local p = self.panel
  if p.w <= 0 or p.h <= 0 then return end
  local body = { 0.14, 0.16, 0.20, 1 }
  if self.layout_doc and self.layout_doc.plate and self.layout_doc.plate.body then
    local b = self.layout_doc.plate.body
    body = { b[1], b[2], b[3], 1 }
  end
  love.graphics.setColor(body)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h, 4, 4)
  love.graphics.setColor(0.55, 0.60, 0.65, 1)
  local label = "RV64 console - type to UART (optional)"
  local font = love.graphics.getFont()
  if font then
    local tw = font:getWidth(label)
    love.graphics.print(label, p.x + math.max(4, (p.w - tw) / 2), p.y + math.max(2, (p.h - font:getHeight()) / 2))
  end
end

function Keypad:hit()
  return nil
end

function Keypad:set_pressed()
end

return Keypad
