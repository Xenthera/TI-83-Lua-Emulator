-- TI-83 Plus keypad matrix (active-low groups via port 01).

local bit = require("core.util.bit")
local band, bnot, lshift = bit.band, bit.bnot, bit.lshift

-- Named keys -> (group, bit). Groups match WikiTI / common emulator layouts.
local KEY_MAP = {
  down = { group = 0, bit = 0 },
  left = { group = 0, bit = 1 },
  right = { group = 0, bit = 2 },
  up = { group = 0, bit = 3 },

  enter = { group = 1, bit = 0 },
  plus = { group = 1, bit = 1 },
  minus = { group = 1, bit = 2 },
  mul = { group = 1, bit = 3 },
  div = { group = 1, bit = 4 },
  power = { group = 1, bit = 5 },
  clear = { group = 1, bit = 6 },

  neg = { group = 2, bit = 0 },
  ["3"] = { group = 2, bit = 1 },
  ["6"] = { group = 2, bit = 2 },
  ["9"] = { group = 2, bit = 3 },
  rparen = { group = 2, bit = 4 },
  tan = { group = 2, bit = 5 },
  vars = { group = 2, bit = 6 },

  dot = { group = 3, bit = 0 },
  ["2"] = { group = 3, bit = 1 },
  ["5"] = { group = 3, bit = 2 },
  ["8"] = { group = 3, bit = 3 },
  lparen = { group = 3, bit = 4 },
  cos = { group = 3, bit = 5 },
  prgm = { group = 3, bit = 6 },
  stat = { group = 3, bit = 7 },

  ["0"] = { group = 4, bit = 0 },
  ["1"] = { group = 4, bit = 1 },
  ["4"] = { group = 4, bit = 2 },
  ["7"] = { group = 4, bit = 3 },
  comma = { group = 4, bit = 4 },
  sin = { group = 4, bit = 5 },
  apps = { group = 4, bit = 6 },
  xt = { group = 4, bit = 7 },

  on = { group = 5, bit = 0 },
  sto = { group = 5, bit = 1 },
  ln = { group = 5, bit = 2 },
  log = { group = 5, bit = 3 },
  square = { group = 5, bit = 4 },
  recip = { group = 5, bit = 5 },
  math = { group = 5, bit = 6 },
  alpha = { group = 5, bit = 7 },

  graph = { group = 6, bit = 0 },
  trace = { group = 6, bit = 1 },
  zoom = { group = 6, bit = 2 },
  window = { group = 6, bit = 3 },
  yequ = { group = 6, bit = 4 },
  ["2nd"] = { group = 6, bit = 5 },
  mode = { group = 6, bit = 6 },
  del = { group = 6, bit = 7 },
}

local Keypad = {}
Keypad.__index = Keypad
Keypad.KEY_MAP = KEY_MAP

function Keypad.new()
  local self = setmetatable({}, Keypad)
  self.keys = {}
  for g = 0, 7 do
    self.keys[g] = {}
  end
  self.group_mask = 0xFF
  self.on_pressed = false
  -- ASIC polls ON edge only when this is set (avoids per-instruction checks).
  self.input_dirty = true
  return self
end

function Keypad:reset()
  for g = 0, 7 do
    self.keys[g] = {}
  end
  self.group_mask = 0xFF
  self.on_pressed = false
  self.input_dirty = true
end

function Keypad:set_key(name, down)
  local info = KEY_MAP[name]
  if not info then
    return false
  end
  if name == "on" then
    self.on_pressed = not not down
  end
  self.keys[info.group][info.bit] = not not down
  self.input_dirty = true
  return true
end

function Keypad:set_key_matrix(group, bitn, down)
  if group < 0 or group > 7 or bitn < 0 or bitn > 7 then
    return
  end
  self.keys[group][bitn] = not not down
  if group == 5 and bitn == 0 then
    self.on_pressed = not not down
  end
  self.input_dirty = true
end

function Keypad:write_group(value)
  self.group_mask = band(value, 0xFF)
end

function Keypad:read()
  local result = 0xFF
  for g = 0, 7 do
    if band(self.group_mask, lshift(1, g)) == 0 then
      for b = 0, 7 do
        if self.keys[g][b] then
          result = band(result, band(bnot(lshift(1, b)), 0xFF))
        end
      end
    end
  end
  return result
end

function Keypad:is_on_pressed()
  return self.on_pressed
end

return Keypad
