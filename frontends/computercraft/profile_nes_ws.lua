local P = {
  id = "nes_ws",
  remote_machine = "nes",
  title = "NES (remote)",
  LcdView = require("frontends.computercraft.lcd_view_nes"),
  KeypadView = require("frontends.computercraft.keypad_view_nes"),
  Args = require("frontends.computercraft.args_nes_ws"),
  prefs_file = "nes_ws.prefs",
  default_theme = "original",
  pad_scale = 0.5,
  lcd_scale = 0.5,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "NES (WebSocket): starting...",
  enable_keybinds = true,
  enable_audio = true,
  supports_cart = true,
  role_cycle = { "lcd", "pad", "off" },
  file_filter = {
    empty_hint = "(no .nes cartridges in this folder)",
    kind_order = { cart = 1 },
    kind_tag = {
      cart = { text = "CART", bg = "lime" },
    },
    classify = function(lower)
      if lower:match("%.nes$") then return "cart" end
      return nil
    end,
  },
}
return P
