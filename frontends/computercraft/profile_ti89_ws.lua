local P = {
  id = "ti89_ws",
  remote_machine = "ti89",
  title = "TI-89 Titanium (remote)",
  LcdView = require("frontends.computercraft.lcd_view_ti89"),
  KeypadView = require("frontends.computercraft.keypad_view_ti89"),
  Args = require("frontends.computercraft.args_ti89_ws"),
  prefs_file = "ti89_ws.prefs",
  default_theme = "titanium",
  pad_scale = 0.75,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "TI-89 Titanium (WebSocket): starting...",
}
return P
