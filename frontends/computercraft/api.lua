-- ComputerCraft-facing API (bundle entry point).
--
--   local ti83 = dofile("ti83_cc.lua")
--   ti83.run({
--     rom = "ti83plus.rom",
--     loadapp = { "MyApp.8xk" },
--     loadprog = { "HELLO.8xp" },
--   })
--
-- Shell:
--   test --help
--   test --loadapp MyApp.8xk --loadprog HELLO.8xp

local Machine = require("machines.ti83plus.machine")
local Eightxk = require("machines.ti83plus.util.eightxk")
local Eightxp = require("machines.ti83plus.util.eightxp")
local CC = require("frontends.computercraft.cc")
local LcdView = require("frontends.computercraft.lcd_view")
local KeypadView = require("frontends.computercraft.keypad_view")
local Host = require("frontends.computercraft.host")
local Args = require("frontends.computercraft.args")
local Profile = require("frontends.computercraft.profile_ti83plus")

local api = {}

api.VERSION = "0.5.0"
api.MACHINE_ID = "ti83plus"
api.LCD_WIDTH = 96
api.LCD_HEIGHT = 64

api.CC = CC
api.Machine = Machine
api.LcdView = LcdView
api.KeypadView = KeypadView
api.Profile = Profile
api.Eightxk = Eightxk
api.Eightxp = Eightxp
api.new_lcd_painter = LcdView.new_painter
api.parse_args = Args.parse
api.usage_text = Args.usage_text
api.inject_8xk = Eightxk.inject
api.inject_8xk_many = Eightxk.inject_many
api.inject_8xp = Eightxp.inject
api.inject_8xp_many = Eightxp.inject_many
api.inject_8xg = Eightxp.inject_file
api.parse_ti_vars = Eightxp.parse_vars

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
  opts = opts or {}
  opts.profile = opts.profile or Profile
  return Host.run(opts)
end

return api
