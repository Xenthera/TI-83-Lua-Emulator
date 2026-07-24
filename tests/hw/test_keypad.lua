return function(ok)
  local Keypad = require("core.hw.keypad")
  local kp = Keypad.new()

  kp:write_group(0xFF)
  ok("no select -> all high", kp:read() == 0xFF)

  kp:set_key("enter", true)
  kp:write_group(0xFD) -- group 1
  local v = kp:read()
  ok("enter clears bit0", v % 2 == 0)

  kp:set_key("enter", false)
  kp:write_group(0xFD)
  ok("enter release", kp:read() == 0xFF)

  kp:set_key("on", true)
  ok("on pressed flag", kp:is_on_pressed())
end
