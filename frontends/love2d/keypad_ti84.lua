-- TI-84 Plus keypad: same layout as TI-83+, retail color coding.
-- Guidebook: 2nd legends blue, alpha green; light number keys; gray math ops.

local KeypadUI = require("keypad_ui")

local COL = {
  black = { 0.10, 0.11, 0.13 },
  body = { 0.18, 0.22, 0.30 }, -- charcoal-blue case
  fkey_band = { 0.12, 0.14, 0.18 },
  white = { 0.96, 0.96, 0.97 },
  cream = { 0.93, 0.93, 0.94 },
  lightGray = { 0.78, 0.80, 0.84 },
  graph = { 0.72, 0.76, 0.82 },
  blue = { 0.22, 0.48, 0.82 }, -- 2nd key face
  green = { 0.20, 0.58, 0.32 }, -- alpha key face
  legend_blue = { 0.35, 0.62, 0.95 },
  legend_green = { 0.35, 0.78, 0.45 },
  orange = { 0.90, 0.55, 0.20 },
  dark = { 0.16, 0.18, 0.22 },
}

local STYLE = {
  graph = COL.graph,
  apps = COL.graph,
  arrow = COL.dark,
  blue_op = COL.cream,
  enter = COL.cream,
  fn = COL.dark,
  op = COL.dark,
  on = COL.dark,
  second = COL.blue,
  alpha = COL.green,
  num = COL.white,
}

local KeypadTI84 = {}
KeypadTI84.__index = KeypadTI84
KeypadTI84.DESIGN_COLS = KeypadUI.DESIGN_COLS
KeypadTI84.DESIGN_ROWS = KeypadUI.DESIGN_ROWS
KeypadTI84.FKEY_BAND_END = KeypadUI.FKEY_BAND_END
KeypadTI84.FACE_ASPECT = KeypadUI.FACE_ASPECT

function KeypadTI84.new(opts)
  opts = opts or {}
  return KeypadUI.new({
    layout = opts.layout,
    theme = {
      col = COL,
      style = STYLE,
      body = COL.body,
      fkey_band = COL.fkey_band,
      legend_2nd = { COL.legend_blue[1], COL.legend_blue[2], COL.legend_blue[3], 1 },
      legend_alpha = { COL.legend_green[1], COL.legend_green[2], COL.legend_green[3], 1 },
      legend_fkey = { COL.legend_blue[1], COL.legend_blue[2], COL.legend_blue[3], 1 },
      press = COL.orange,
    },
  })
end

return KeypadTI84
