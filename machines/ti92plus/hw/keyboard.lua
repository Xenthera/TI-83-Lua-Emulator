-- TI-92 / TI-92+ / V200 QWERTY key matrix (ticalc.org kbd89.txt / FargoII).
-- $600018 is a 16-bit row mask (1 = row not scanned); bits 0–9 used.
-- $60001B returns COLUMNS (0 = key down on an unmasked row).
-- ON is outside the matrix (AI6 via $60001A), same ASIC family as TI-89.

local bit = require("framework.util.bit")
local band, bnot, lshift = bit.band, bit.bnot, bit.lshift

-- Col bit numbers match hardware: Bit0 = rightmost column in the docs table.
-- Source matrix (Row × Col Bit7..Bit0):
--  0: down right up left hand shift diamond 2nd
--  1: 3 2 1 F8 W S Z —
--  2: 6 5 4 F3 E D X —
--  3: 9 8 7 F7 R F C STO
--  4: , ) ( F2 T G V space
--  5: TAN COS SIN F6 Y H B /
--  6: P ENTER2 LN F1 U J N ^
--  7: * APPS CLEAR F5 I K M =
--  8: — ESC MODE + O L theta ←
--  9: (−) . 0 F4 Q A ENTER1 -
local KEY_MAP = {
  -- Row 0
  down = { row = 0, col = 7 },
  right = { row = 0, col = 6 },
  up = { row = 0, col = 5 },
  left = { row = 0, col = 4 },
  hand = { row = 0, col = 3 },
  grab = { row = 0, col = 3 },
  shift = { row = 0, col = 2 },
  diamond = { row = 0, col = 1 },
  ["2nd"] = { row = 0, col = 0 },
  -- Second face copy of 2nd (same matrix cell; used when the layout has two 2nd keys).
  ["2nd2"] = { row = 0, col = 0 },

  -- Row 1
  ["3"] = { row = 1, col = 7 },
  ["2"] = { row = 1, col = 6 },
  ["1"] = { row = 1, col = 5 },
  f8 = { row = 1, col = 4 },
  w = { row = 1, col = 3 },
  ["W"] = { row = 1, col = 3 },
  s = { row = 1, col = 2 },
  ["S"] = { row = 1, col = 2 },
  z = { row = 1, col = 1 },
  ["Z"] = { row = 1, col = 1 },

  -- Row 2
  ["6"] = { row = 2, col = 7 },
  ["5"] = { row = 2, col = 6 },
  ["4"] = { row = 2, col = 5 },
  f3 = { row = 2, col = 4 },
  e = { row = 2, col = 3 },
  ["E"] = { row = 2, col = 3 },
  d = { row = 2, col = 2 },
  ["D"] = { row = 2, col = 2 },
  x = { row = 2, col = 1 },
  ["X"] = { row = 2, col = 1 },

  -- Row 3
  ["9"] = { row = 3, col = 7 },
  ["8"] = { row = 3, col = 6 },
  ["7"] = { row = 3, col = 5 },
  f7 = { row = 3, col = 4 },
  r = { row = 3, col = 3 },
  ["R"] = { row = 3, col = 3 },
  f = { row = 3, col = 2 },
  ["F"] = { row = 3, col = 2 },
  c = { row = 3, col = 1 },
  ["C"] = { row = 3, col = 1 },
  sto = { row = 3, col = 0 },

  -- Row 4
  comma = { row = 4, col = 7 },
  [","] = { row = 4, col = 7 },
  rparen = { row = 4, col = 6 },
  [")"] = { row = 4, col = 6 },
  lparen = { row = 4, col = 5 },
  ["("] = { row = 4, col = 5 },
  f2 = { row = 4, col = 4 },
  t = { row = 4, col = 3 },
  ["T"] = { row = 4, col = 3 },
  g = { row = 4, col = 2 },
  ["G"] = { row = 4, col = 2 },
  v = { row = 4, col = 1 },
  ["V"] = { row = 4, col = 1 },
  space = { row = 4, col = 0 },

  -- Row 5
  tan = { row = 5, col = 7 },
  cos = { row = 5, col = 6 },
  sin = { row = 5, col = 5 },
  f6 = { row = 5, col = 4 },
  y = { row = 5, col = 3 },
  ["Y"] = { row = 5, col = 3 },
  h = { row = 5, col = 2 },
  ["H"] = { row = 5, col = 2 },
  b = { row = 5, col = 1 },
  ["B"] = { row = 5, col = 1 },
  div = { row = 5, col = 0 },
  ["/"] = { row = 5, col = 0 },

  -- Row 6
  p = { row = 6, col = 7 },
  ["P"] = { row = 6, col = 7 },
  enter2 = { row = 6, col = 6 },
  ln = { row = 6, col = 5 },
  f1 = { row = 6, col = 4 },
  u = { row = 6, col = 3 },
  ["U"] = { row = 6, col = 3 },
  j = { row = 6, col = 2 },
  ["J"] = { row = 6, col = 2 },
  n = { row = 6, col = 1 },
  ["N"] = { row = 6, col = 1 },
  power = { row = 6, col = 0 },
  ["^"] = { row = 6, col = 0 },

  -- Row 7
  mul = { row = 7, col = 7 },
  ["*"] = { row = 7, col = 7 },
  apps = { row = 7, col = 6 },
  clear = { row = 7, col = 5 },
  f5 = { row = 7, col = 4 },
  i = { row = 7, col = 3 },
  ["I"] = { row = 7, col = 3 },
  k = { row = 7, col = 2 },
  ["K"] = { row = 7, col = 2 },
  m = { row = 7, col = 1 },
  ["M"] = { row = 7, col = 1 },
  equals = { row = 7, col = 0 },
  ["="] = { row = 7, col = 0 },

  -- Row 8
  esc = { row = 8, col = 6 },
  mode = { row = 8, col = 5 },
  plus = { row = 8, col = 4 },
  ["+"] = { row = 8, col = 4 },
  o = { row = 8, col = 3 },
  ["O"] = { row = 8, col = 3 },
  l = { row = 8, col = 2 },
  ["L"] = { row = 8, col = 2 },
  theta = { row = 8, col = 1 },
  backspace = { row = 8, col = 0 },
  backspc = { row = 8, col = 0 },

  -- Row 9
  neg = { row = 9, col = 7 },
  ["(-)"] = { row = 9, col = 7 },
  dot = { row = 9, col = 6 },
  ["."] = { row = 9, col = 6 },
  ["0"] = { row = 9, col = 5 },
  f4 = { row = 9, col = 4 },
  q = { row = 9, col = 3 },
  ["Q"] = { row = 9, col = 3 },
  a = { row = 9, col = 2 },
  ["A"] = { row = 9, col = 2 },
  enter = { row = 9, col = 1 },
  enter1 = { row = 9, col = 1 },
  -- Third face copy of ENTER1 (same matrix cell; used when the layout has three Enter keys).
  enter3 = { row = 9, col = 1 },
  minus = { row = 9, col = 0 },
  ["-"] = { row = 9, col = 0 },

  on = { on = true },
}

local ROW_MASK_BITS = 0x03FF -- 10 rows

local Keyboard = {}
Keyboard.__index = Keyboard
Keyboard.KEY_MAP = KEY_MAP
Keyboard.ROWS = 10

function Keyboard.new()
  local self = setmetatable({}, Keyboard)
  self.down = {}
  self.row_mask = ROW_MASK_BITS
  self.on_pressed = false
  self.changed = false
  self.on_edge = false
  return self
end

function Keyboard:reset()
  self.down = {}
  self.row_mask = ROW_MASK_BITS
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
  self.row_mask = band(v, ROW_MASK_BITS)
end

function Keyboard:read()
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
