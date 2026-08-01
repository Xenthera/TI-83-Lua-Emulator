local P = {
  id = "gameboy_ws",
  remote_machine = "gameboy",
  title = "Game Boy (remote)",
  LcdView = require("frontends.computercraft.lcd_view_gameboy"),
  KeypadView = require("frontends.computercraft.keypad_view_gameboy"),
  Args = require("frontends.computercraft.args_gameboy_ws"),
  prefs_file = "gameboy_ws.prefs",
  default_theme = "original",
  pad_scale = 0.5,
  lcd_scale = 0.5,
  default_url = "ws://127.0.0.1:8765",
  boot_label = "Game Boy (WebSocket): starting...",
  enable_keybinds = true,
  enable_audio = true,
  supports_cart = true,
  role_cycle = { "lcd", "pad", "off" },
  file_filter = {
    empty_hint = "(no .gb cartridges in this folder)",
    kind_order = { cart = 1 },
    kind_tag = {
      cart = { text = "CART", bg = "lime" },
    },
    classify = function(lower)
      if lower:match("%.gb$") then return "cart" end
      return nil
    end,
  },
}
return P
