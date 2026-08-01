local P = {
  id = "ti84plus_ws",
  remote_machine = "ti84plus",
  title = "TI-84+ (remote)",
  LcdView = require("frontends.computercraft.lcd_view"),
  KeypadView = require("frontends.computercraft.keypad_view_ti84"),
  Args = require("frontends.computercraft.args_ti84_ws"),
  prefs_file = "ti84_ws.prefs",
  default_theme = "classic",
  pad_scale = 0.75,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "TI-84+ (WebSocket): starting...",
}
return P
