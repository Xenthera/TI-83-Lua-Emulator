-- Profile: Game Boy GPU face as WebSocket thin client (no local ROM/CPU).

local P = {
  id = "gameboy_gpu_ws",
  remote_machine = "gameboy",
  title = "Game Boy (GPU / remote)",
  Args = require("frontends.computercraft.args_gameboy_gpu_ws"),
  Face = require("frontends.computercraft.face_gpu_gameboy"),
  LcdView = require("frontends.computercraft.lcd_view_gpu_gameboy"),
  KeypadView = require("frontends.computercraft.keypad_view_gpu_gameboy"),
  prefs_file = "gameboy_gpu_ws.prefs",
  default_theme = "original",
  gpu_size = 64,
  cycles_per_tick = 70224 * 2,
  boot_label = "Game Boy GPU (WebSocket): starting...",
  default_url = "ws://127.0.0.1:8765",
  enable_audio = true,
  enable_keybinds = true,
  supports_cart = true,
  file_filter = {
    empty_hint = "(WS mode: pass --rom or click a .gb to upload)",
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
