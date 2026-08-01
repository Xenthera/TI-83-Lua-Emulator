-- Optional calculator chrome labels (non-core).

local Bezel = {}

function Bezel.draw_title()
  love.graphics.setColor(0.9, 0.92, 0.88, 1)
  love.graphics.print("TI-83 Plus", 16, 12)
  love.graphics.setColor(0.65, 0.7, 0.62, 1)
  love.graphics.print("Tab=2nd  Shift=Alpha  Space=ON  Esc=Mode", 16, 30)
end

return Bezel
