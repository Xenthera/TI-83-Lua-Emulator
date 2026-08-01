local P = {
  id = "ti83plus_ws",
  remote_machine = "ti83plus",
  title = "TI-83+ (remote)",
  LcdView = require("frontends.computercraft.lcd_view"),
  KeypadView = require("frontends.computercraft.keypad_view"),
  Args = require("frontends.computercraft.args_ti83_ws"),
  prefs_file = "ti83_ws.prefs",
  default_theme = "classic",
  pad_scale = 0.75,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "TI-83+ (WebSocket): starting...",
}
return P
