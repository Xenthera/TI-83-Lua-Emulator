function love.conf(t)
  t.identity = "retro-emulator-studio"
  t.window.title = "Retro Emulator Studio - TI-83 Plus"
  t.window.width = 1280
  t.window.height = 720
  t.window.minwidth = 900
  t.window.minheight = 500
  t.window.resizable = true
  -- Retina / HiDPI: full pixel density + automatic DPI-scaled units
  t.window.highdpi = true
  t.window.usedpiscale = true
  t.console = true
  t.modules.joystick = false
  t.modules.physics = false
  t.modules.touch = false
end
