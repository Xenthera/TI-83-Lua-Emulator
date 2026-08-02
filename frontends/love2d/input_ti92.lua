-- Host keyboard -> TI-92 Plus QWERTY matrix names.

local M = {}

local MAP = {
  ["return"] = "enter",
  ["kpenter"] = "enter2",
  escape = "esc",
  backspace = "backspace",
  delete = "clear",
  up = "up",
  down = "down",
  left = "left",
  right = "right",
  home = "apps",
  f1 = "f1", f2 = "f2", f3 = "f3", f4 = "f4",
  f5 = "f5", f6 = "f6", f7 = "f7", f8 = "f8",
  lshift = "shift", rshift = "shift",
  lctrl = "diamond", rctrl = "diamond",
  lalt = "hand", ralt = "hand",
  tab = "2nd",
  space = "space",
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
  ["kp+"] = "plus",
  ["kp-"] = "minus",
  ["kp*"] = "mul",
  ["kp/"] = "div",
  ["kp."] = "dot",
}

for i = 0, 9 do
  MAP[tostring(i)] = tostring(i)
  MAP["kp" .. i] = tostring(i)
end

-- Letter keys -> lowercase matrix names (a-z).
for c = string.byte("a"), string.byte("z") do
  local ch = string.char(c)
  MAP[ch] = ch
end

function M.to_ti_key(scancode)
  return MAP[scancode]
end

return M
