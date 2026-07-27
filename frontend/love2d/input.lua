-- Map Love2D keyboard scancodes -> TI-83 Plus key names.
-- Letter keys target the physical keys that carry those green ALPHA legends,
-- so Shift (ALPHA) + R presses x and types R.

local MAP = {
  ["return"] = "enter",
  kpenter = "enter",
  backspace = "del",
  delete = "del",
  escape = "mode",
  up = "up",
  down = "down",
  left = "left",
  right = "right",
  ["."] = "dot",
  [","] = "comma",
  ["-"] = "minus",
  ["="] = "plus",
  ["/"] = "div",
  ["*"] = "mul",
  ["^"] = "power",
  ["("] = "lparen",
  [")"] = "rparen",
  ["0"] = "0",
  ["1"] = "1",
  ["2"] = "2",
  ["3"] = "3",
  ["4"] = "4",
  ["5"] = "5",
  ["6"] = "6",
  ["7"] = "7",
  ["8"] = "8",
  ["9"] = "9",

  -- A-Z -> keys with matching ALPHA legends (TI-83+ / OS 1.19).
  a = "math",
  b = "apps",
  c = "prgm",
  d = "recip",
  e = "sin",
  f = "cos",
  g = "tan",
  h = "power",
  i = "square",
  j = "comma",
  k = "lparen",
  l = "rparen",
  m = "div",
  n = "log",
  o = "7",
  p = "8",
  q = "9",
  r = "mul",
  s = "ln",
  t = "4",
  u = "5",
  v = "6",
  w = "minus",
  x = "sto",
  y = "1",
  z = "2",

  tab = "2nd",
  lshift = "alpha",
  rshift = "alpha",
  space = "on",
  ["'"] = "sto",
  ["["] = "square",
  ["]"] = "recip",
}

for i = 0, 9 do
  MAP["kp" .. i] = tostring(i)
end
MAP["kp."] = "dot"
MAP["kp+"] = "plus"
MAP["kp-"] = "minus"
MAP["kp*"] = "mul"
MAP["kp/"] = "div"

local Input = {}

function Input.map_key(key)
  return MAP[key]
end

function Input.apply(machine, key, down)
  local name = MAP[key]
  if name then
    machine:set_key(name, down)
    return true
  end
  return false
end

return Input
