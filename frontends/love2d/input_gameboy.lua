-- Keyboard → Game Boy button names (machines.gameboy.hw.joypad).

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
  return_ = "start", -- Love uses "return"
  ["return"] = "start",
  enter = "start",
  rshift = "select",
  lshift = "select",
  space = "select",
}

function Input.to_gb_key(key)
  return MAP[key]
end

function Input.apply(machine, key, down)
  local gb = MAP[key]
  if gb and machine then
    machine:set_key(gb, down)
    return true
  end
  return false
end

return Input
