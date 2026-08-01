-- TI-92 Plus LCD painter (240×128) for ComputerCraft via 2×3 sixtels.
local Painter = require("frontends.computercraft.lcd_painter")
return Painter.create(require("machines.ti92plus.lcd_geom"))
