-- Keyboard -> NES button names.

local Input = {}

local MAP = {
  up = "up",
  down = "down",
  left = "left",
  right = "right",
  z = "a",
  x = "b",
  a = "a",
  s = "b",
  j = "a",
  k = "b",
  ["return"] = "start",
  enter = "start",
  rshift = "select",
  lshift = "select",
  space = "select",
}

function Input.apply(machine, key, down)
  local n = MAP[key]
  if n and machine then
    machine:set_key(n, down)
    return true
  end
  return false
end

return Input
