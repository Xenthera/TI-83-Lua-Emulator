-- TI-84 Plus keypad for ComputerCraft - Love/retail color coding.
-- Light graph row, APPS black+purple, dark fn, white nums/arrows/+-*/ENTER,
-- blue 2nd, green ALPHA.

local Base = require("frontends.computercraft.keypad_view")

local M = {}

local function style_colors(C, style, pressed)
  if pressed then
    return C.orange, C.black
  end
  if style == "second" then
    return C.blue, C.white
  elseif style == "alpha" then
    return C.green, C.white
  elseif style == "apps" then
    return C.black, (C.purple or C.magenta)
  elseif style == "fn" or style == "op" or style == "on" then
    return C.black, C.white
  elseif style == "num" or style == "arrow"
      or style == "blue_op" or style == "enter" then
    return C.white, C.black
  elseif style == "graph" then
    return C.lightGray, C.black
  end
  return C.lightGray, C.black
end

local THEME = {
  body = "gray",
  fkey_band = "black",
  -- Love: 2nd legends blue, alpha green (not TI-83 yellow / lightBlue).
  legend_2nd = "lightBlue",
  legend_alpha = "lime",
  legend_fkey = "lightBlue",
  style_colors = style_colors,
}

function M.new(mon_or_side, opts)
  opts = opts or {}
  opts.theme = opts.theme or THEME
  return Base.new(mon_or_side, opts)
end

return M
