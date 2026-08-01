-- Generic rectangular GPU keypad from a KEYS table.
-- KEYS entry: { name, label, style, col, row, w, h }
-- Usage: return require("...keypad_view_gpu").make({ keys=, cols=, rows=, styles? })

local Gpu = require("frontends.computercraft.gpu")

local DEFAULT_STYLE = {
  fn = Gpu.argb(0.25, 0.26, 0.28),
  num = Gpu.argb(0.78, 0.78, 0.80),
  enter = Gpu.argb(0.30, 0.40, 0.70),
  arrow = Gpu.argb(0.35, 0.36, 0.38),
  second = Gpu.argb(0.85, 0.72, 0.15),
  alpha = Gpu.argb(0.35, 0.70, 0.35),
  on = Gpu.argb(0.20, 0.20, 0.22),
  graph = Gpu.argb(0.55, 0.58, 0.62),
  apps = Gpu.argb(0.15, 0.15, 0.18),
  op = Gpu.argb(0.30, 0.32, 0.35),
  blue_op = Gpu.argb(0.30, 0.40, 0.70),
  action = Gpu.argb(0.75, 0.20, 0.20),
  fkey = Gpu.argb(0.35, 0.36, 0.38),
}

local PRESSED = Gpu.argb(0.90, 0.48, 0.12)
local WHITE = Gpu.argb(0.97, 0.97, 0.98)
local BLACK = Gpu.argb(0.05, 0.05, 0.06)
local BODY = Gpu.argb(0.12, 0.12, 0.14)

local function make(cfg)
  cfg = cfg or {}
  local KEYS = assert(cfg.keys, "keypad_view_gpu: keys")
  local COLS = cfg.cols or 5
  local ROWS = cfg.rows or 12
  local STYLES = cfg.styles or DEFAULT_STYLE

  local M = {}
  M.__index = M
  M.DESIGN_COLS = COLS
  M.DESIGN_ROWS = ROWS

  function M.new(gpu)
    return setmetatable({
      gpu = gpu,
      panel = { x = 0, y = 0, w = 0, h = 0 },
      buttons = {},
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

  function M:layout(x, y, w, h)
    self.panel = { x = x, y = y, w = w, h = h }
    self.buttons = {}
    if w < 20 or h < 20 then return end
    local cell_w = w / COLS
    local cell_h = h / ROWS
    local gap_x = math.max(1, cell_w * 0.06)
    local gap_y = math.max(1, cell_h * 0.06)
    for _, k in ipairs(KEYS) do
      local kw = (k[6] or 1) * cell_w - gap_x
      local kh = (k[7] or 1) * cell_h - gap_y
      local bx = x + (k[4] or 0) * cell_w + gap_x * 0.5
      local by = y + (k[5] or 0) * cell_h + gap_y * 0.5
      self.buttons[#self.buttons + 1] = {
        key = k[1],
        label = k[2],
        style = k[3] or "fn",
        x = bx, y = by,
        w = math.max(6, kw),
        h = math.max(6, kh),
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

  function M:draw()
    local gpu = self.gpu
    local p = self.panel
    if not gpu or not p or p.w < 4 then return end
    local mw, mh = self.max_w, self.max_h
    Gpu.rect(gpu, p.x, p.y, p.w, p.h, BODY, mw, mh)
    for _, b in ipairs(self.buttons) do
      local pressed = self.pressed == b.key
      local face = pressed and PRESSED or (STYLES[b.style] or STYLES.fn)
      local fg = (b.style == "num" or b.style == "second" or b.style == "alpha")
        and BLACK or WHITE
      if pressed then fg = BLACK end
      Gpu.rect(gpu, b.x, b.y, b.w, b.h, face, mw, mh)
      if gpu.drawText and b.label and b.label ~= "" then
        local label = b.label
        if #label > 6 then label = label:sub(1, 6) end
        local tx = math.floor(b.x + 2)
        local ty = math.floor(b.y + math.max(1, (b.h - 6) / 2))
        pcall(gpu.drawText, math.max(1, tx), math.max(1, ty), label, fg, Gpu.TEXT_BG_NONE, 1)
      end
    end
  end

  return M
end

return { make = make, DEFAULT_STYLE = DEFAULT_STYLE }
