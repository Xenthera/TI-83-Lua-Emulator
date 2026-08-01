-- ComputerCraft-facing API for Game Boy on Tom's Peripherals GPU.
--
--   local gb = dofile("gb_gpu_cc.lua")
--   gb.run({ rom = "tetris.gb" })
--
-- Shell:
--   gb_gpu_cc --help
--   gb_gpu_cc --rom tetris.gb --gpu tm_gpu_0

local Machine = require("machines.gameboy.machine")
local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local LcdView = require("frontends.computercraft.lcd_view_gpu_gameboy")
local KeypadView = require("frontends.computercraft.keypad_view_gpu_gameboy")
local Host = require("frontends.computercraft.host_gpu")
local Args = require("frontends.computercraft.args_gameboy_gpu")
local Profile = require("frontends.computercraft.profile_gameboy_gpu")
local Geom = require("machines.gameboy.lcd_geom")

local api = {}

api.VERSION = "0.1.0"
api.MACHINE_ID = "gameboy_gpu"
api.LCD_WIDTH = Geom.WIDTH
api.LCD_HEIGHT = Geom.HEIGHT

api.CC = CC
api.Gpu = Gpu
api.Machine = Machine
api.LcdView = LcdView
api.KeypadView = KeypadView
api.Profile = Profile
api.parse_args = Args.parse
api.usage_text = Args.usage_text

function api.new_machine()
  return Machine.new()
end

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

function api.run(opts)
  opts = opts or {}
  opts.profile = opts.profile or Profile
  return Host.run(opts)
end

return api
