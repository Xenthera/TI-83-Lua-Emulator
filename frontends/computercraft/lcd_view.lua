-- Paint a TI-83+ LCD (96×64) onto a ComputerCraft monitor via 2×3 sixtels.
local Painter = require("frontends.computercraft.lcd_painter")
local M = Painter.create(require("machines.ti83plus.lcd_geom"))
M.create = Painter.create
return M
