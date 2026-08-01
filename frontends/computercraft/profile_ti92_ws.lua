local P = {
  id = "ti92plus_ws",
  remote_machine = "ti92plus",
  title = "TI-92 Plus (remote)",
  LcdView = require("frontends.computercraft.lcd_view_ti92"),
  KeypadView = require("frontends.computercraft.keypad_view_ti92"),
  Args = require("frontends.computercraft.args_ti92_ws"),
  prefs_file = "ti92_ws.prefs",
  default_theme = "titanium",
  pad_scale = 0.5,
  lcd_scale = 0.5,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "TI-92 Plus (WebSocket): starting...",
}
return P
