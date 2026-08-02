-- TI-89 key matrix (classic 89hw / TIGCC layout).
-- $600018 bits6-0 mask ROWS (1 = row not scanned).
-- $60001B returns COLUMNS (0 = key down on an unmasked row).

local bit = require("framework.util.bit")
local band, bnot, lshift = bit.band, bit.bnot, bit.lshift

-- { row, col } - row = mask bit at $600018, col = data bit at $60001B
local KEY_MAP = {
  -- Row 0
  up = { row = 0, col = 0 },
  left = { row = 0, col = 1 },
  down = { row = 0, col = 2 },
  right = { row = 0, col = 3 },
  ["2nd"] = { row = 0, col = 4 },
  shift = { row = 0, col = 5 },
  diamond = { row = 0, col = 6 },
  alpha = { row = 0, col = 7 },

  -- Row 1
  enter = { row = 1, col = 0 },
  plus = { row = 1, col = 1 },
  minus = { row = 1, col = 2 },
  mul = { row = 1, col = 3 },
  div = { row = 1, col = 4 },
  power = { row = 1, col = 5 },
  clear = { row = 1, col = 6 },
  f5 = { row = 1, col = 7 },

  -- Row 2
  neg = { row = 2, col = 0 },
  ["3"] = { row = 2, col = 1 },
  ["6"] = { row = 2, col = 2 },
  ["9"] = { row = 2, col = 3 },
  comma = { row = 2, col = 4 },
  [","] = { row = 2, col = 4 },
  t = { row = 2, col = 5 },
  ["T"] = { row = 2, col = 5 },
  backspace = { row = 2, col = 6 },
  backspc = { row = 2, col = 6 },
  f4 = { row = 2, col = 7 },

  -- Row 3
  dot = { row = 3, col = 0 },
  ["."] = { row = 3, col = 0 },
  ["2"] = { row = 3, col = 1 },
  ["5"] = { row = 3, col = 2 },
  ["8"] = { row = 3, col = 3 },
  rparen = { row = 3, col = 4 },
  [")"] = { row = 3, col = 4 },
  z = { row = 3, col = 5 },
  ["Z"] = { row = 3, col = 5 },
  catalog = { row = 3, col = 6 },
  f3 = { row = 3, col = 7 },

  -- Row 4
  ["0"] = { row = 4, col = 0 },
  ["1"] = { row = 4, col = 1 },
  ["4"] = { row = 4, col = 2 },
  ["7"] = { row = 4, col = 3 },
  lparen = { row = 4, col = 4 },
  ["("] = { row = 4, col = 4 },
  y = { row = 4, col = 5 },
  ["Y"] = { row = 4, col = 5 },
  mode = { row = 4, col = 6 },
  f2 = { row = 4, col = 7 },

  -- Row 5
  apps = { row = 5, col = 0 },
  sto = { row = 5, col = 1 },
  ee = { row = 5, col = 2 },
  pipe = { row = 5, col = 3 },
  ["|"] = { row = 5, col = 3 },
  equals = { row = 5, col = 4 },
  ["="] = { row = 5, col = 4 },
  x = { row = 5, col = 5 },
  ["X"] = { row = 5, col = 5 },
  home = { row = 5, col = 6 },
  f1 = { row = 5, col = 7 },

  -- Row 6
  esc = { row = 6, col = 0 },

  on = { on = true },
}

local Keyboard = {}
Keyboard.__index = Keyboard
Keyboard.KEY_MAP = KEY_MAP

function Keyboard.new()
  local self = setmetatable({}, Keyboard)
  self.down = {}
  self.row_mask = 0x7F
  self.on_pressed = false
  self.changed = false
  self.on_edge = false
  return self
end

function Keyboard:reset()
  self.down = {}
  self.row_mask = 0x7F
  self.on_pressed = false
  self.changed = false
  self.on_edge = false
end

function Keyboard:set_key(name, is_down)
  local info = KEY_MAP[name]
  if not info then return false end
  is_down = not not is_down
  if info.on then
    if self.on_pressed ~= is_down then
      self.on_pressed = is_down
      self.on_edge = true
    end
    return true
  end
  local idx = info.row * 8 + info.col
  if self.down[idx] ~= is_down then
    self.down[idx] = is_down
    self.changed = true
  end
  return true
end

function Keyboard:write_mask(v)
  self.row_mask = band(v, 0x7F)
end

function Keyboard:read()
  -- Active-low columns for keys on unmasked rows.
  local cols = 0xFF
  for key, pressed in pairs(self.down) do
    if pressed then
      local row = math.floor(key / 8)
      local col = key % 8
      if band(self.row_mask, lshift(1, row)) == 0 then
        cols = band(cols, band(bnot(lshift(1, col)), 0xFF))
      end
    end
  end
  return cols
end

function Keyboard:read_on()
  return self.on_pressed and 0 or 2
end

return Keyboard
