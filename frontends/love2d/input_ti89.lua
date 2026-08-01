-- Host keyboard → TI-89 Titanium key names (matrix names).

local M = {}

local MAP = {
  ["return"] = "enter",
  ["kpenter"] = "enter",
  escape = "esc",
  backspace = "backspace",
  delete = "clear",
  up = "up",
  down = "down",
  left = "left",
  right = "right",
  home = "home",
  f1 = "f1", f2 = "f2", f3 = "f3", f4 = "f4", f5 = "f5",
  lshift = "shift", rshift = "shift",
  lctrl = "diamond", rctrl = "diamond",
  lalt = "alpha", ralt = "alpha",
  tab = "2nd",
  space = "on",
  ["="] = "equals",
  ["-"] = "minus",
  ["+"] = "plus",
  ["*"] = "mul",
  ["/"] = "div",
  ["("] = "lparen",
  [")"] = "rparen",
  [","] = "comma",
  ["."] = "dot",
  ["^"] = "power",
  ["|"] = "pipe",
  x = "x", y = "y", z = "z", t = "t",
}

for i = 0, 9 do MAP[tostring(i)] = tostring(i) end

function M.to_ti_key(scancode)
  return MAP[scancode]
end

return M
