-- RV64 custom board face: console LCD only (no physical keypad).
return {
  format = "ti-keypad-layout",
  version = 2,
  machine = "riscv64",
  design_cols = 8.0000,
  design_rows = 1.0000,
  face_aspect = 0.1250,
  scene = { w = 8.0000, h = 5.5000 },
  lcd = {
    x = 0.0000, y = 0.0000, w = 8.0000, h = 5.0000, radius = 0.0800,
    color = { 0.0600, 0.0700, 0.0900 },
    glass = { 0.1000, 0.1200, 0.1400 },
  },
  panel = {
    x = 0.0000, y = 5.1000, w = 8.0000, h = 0.4000, radius = 0.0400,
  },
  plate = {
    body = { 0.1400, 0.1600, 0.2000 },
    fkey_band = { 0.1000, 0.1100, 0.1300 },
    fkey_band_end = 0.0000,
    radius = 0.0400,
  },
  theme = {
    styles = {},
    label_size = 10,
    legend_size = 8,
    press = { 0.9000, 0.5500, 0.2000 },
  },
  buttons = {},
}
