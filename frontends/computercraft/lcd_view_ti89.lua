-- TI-89 Titanium LCD painter (160×100) for ComputerCraft via 2×3 sixtels.
-- Geometry only — no m68k LCD controller in the CC bundle.
local Painter = require("frontends.computercraft.lcd_painter")
return Painter.create(require("machines.ti89.lcd_geom"))
