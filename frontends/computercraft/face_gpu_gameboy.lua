-- Game Boy face layout for Tom's GPU (LCD above D-pad / buttons).
-- Prefers a tall keypad band so round A/B + cross D-pad stay accurate.

local Gpu = require("frontends.computercraft.gpu")

return require("frontends.computercraft.face_gpu").make({
  width = 160,
  height = 144,
  brand = "GAME BOY",
  -- Reserve enough pad height for a real DMG control cluster.
  min_keys = 72,
  pad = 4,
  shell_color = Gpu.argb(0.55, 0.55, 0.62),
  brand_color = Gpu.argb(0.25, 0.22, 0.35),
  bg_color = Gpu.argb(0.22, 0.22, 0.26),
})
