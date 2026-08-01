-- ComputerCraft-facing API for original Game Boy (bundle entry point).
--
--   local gb = dofile("gb_cc.lua")
--   gb.run({ rom = "tetris.gb" })
--
-- Shell:
--   gb_cc --help
--   gb_cc --rom tetris.gb

local Machine = require("machines.gameboy.machine")
local CC = require("frontends.computercraft.cc")
local LcdView = require("frontends.computercraft.lcd_view_gameboy")
local KeypadView = require("frontends.computercraft.keypad_view_gameboy")
local Host = require("frontends.computercraft.host")
local Args = require("frontends.computercraft.args_gameboy")
local Profile = require("frontends.computercraft.profile_gameboy")
local Geom = require("machines.gameboy.lcd_geom")

local api = {}

api.VERSION = "0.1.0"
api.MACHINE_ID = "gameboy"
api.LCD_WIDTH = Geom.WIDTH
api.LCD_HEIGHT = Geom.HEIGHT

api.CC = CC
api.Machine = Machine
api.LcdView = LcdView
api.KeypadView = KeypadView
api.Profile = Profile
api.new_lcd_painter = LcdView.new_painter
api.parse_args = Args.parse
api.usage_text = Args.usage_text

function api.new_machine()
  return Machine.new()
end

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

function api.run(opts)
  opts = opts or {}
  opts.profile = opts.profile or Profile
  return Host.run(opts)
end

return api
