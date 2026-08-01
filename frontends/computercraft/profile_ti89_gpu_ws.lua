-- Profile: TI-89 GPU face as WebSocket thin client (no local ROM/CPU).

local P = {
  id = "ti89_gpu_ws",
  remote_machine = "ti89",
  title = "TI-89 Titanium (GPU / remote)",
  Args = require("frontends.computercraft.args_ti89_gpu_ws"),
  Face = require("frontends.computercraft.face_gpu_ti89"),
  LcdView = require("frontends.computercraft.lcd_view_gpu_ti89"),
  KeypadView = require("frontends.computercraft.keypad_view_gpu_ti89"),
  prefs_file = "ti89_gpu_ws.prefs",
  default_theme = "titanium",
  cycles_per_tick = 400000,
  boot_label = "TI-89 Titanium GPU (WebSocket): starting...",
  default_url = "ws://127.0.0.1:8765",
}

return P
