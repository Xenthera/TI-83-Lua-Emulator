-- ComputerCraft-facing API (bundle entry point).
--
--   local ti83 = dofile("ti83_cc.lua")
--   local lcd = peripheral.wrap("left")
--   local pad = peripheral.wrap("right")
--   ...
--   ti83.run({ lcd = "left", pad = "right", rom = "ti83plus.rom" })

local Machine = require("core.machine")
local CC = require("frontend.computercraft.cc")
local LcdView = require("frontend.computercraft.lcd_view")
local KeypadView = require("frontend.computercraft.keypad_view")
local Host = require("frontend.computercraft.host")

local api = {}

api.VERSION = "0.2.0"
api.LCD_WIDTH = 96
api.LCD_HEIGHT = 64

api.CC = CC
api.Machine = Machine
api.LcdView = LcdView
api.KeypadView = KeypadView

function api.new_machine()
  return Machine.new()
end

--- peripheral.wrap / find helpers
api.wrap_monitor = CC.wrap_monitor
api.find_monitors = CC.find_monitors
api.resolve_monitors = CC.resolve_monitors

function api.read_rom_file(path)
  return CC.read_file(path)
end

function api.load_rom(machine, bytes)
  machine = machine or Machine.new()
  local ok, err = machine:load_rom_bytes(bytes)
  if not ok then
    return nil, err
  end
  return machine
end

function api.run_frame(machine, fps)
  return machine:run_cycles(machine:cycles_per_frame(fps or 60))
end

--- Paint LCD monitor if dirty. `monitor` = wrapped or side string.
function api.present(machine, monitor, opts)
  if not machine:display_dirty() and not (opts and opts.force) then
    return false
  end
  local mon = monitor
  if type(monitor) == "string" then
    mon = select(1, CC.wrap_monitor(monitor, "lcd"))
  end
  LcdView.paint(mon, machine:framebuffer(), machine:is_display_on(), opts)
  machine:clear_display_dirty()
  return true
end

api.paint_lcd = LcdView.paint
api.setup_lcd = LcdView.setup

--- Full host: wraps peripherals, pulls monitor_touch / timer / terminate.
function api.run(opts)
  return Host.run(opts)
end

return api
