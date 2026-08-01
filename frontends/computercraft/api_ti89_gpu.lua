-- ComputerCraft-facing API for TI-89 Titanium on Tom's Peripherals GPU.
--
--   local ti89 = dofile("ti89_gpu_cc.lua")
--   ti89.run({ rom = "ti89.rom" })
--
-- Shell:
--   test --help
--   ti89_gpu_cc --rom ti89titanium.rom --gpu tm_gpu_0

local Machine = require("machines.ti89.machine")
local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local LcdView = require("frontends.computercraft.lcd_view_gpu_ti89")
local KeypadView = require("frontends.computercraft.keypad_view_gpu_ti89")
local Host = require("frontends.computercraft.host_gpu")
local Args = require("frontends.computercraft.args_ti89_gpu")
local Profile = require("frontends.computercraft.profile_ti89_gpu")

local api = {}

api.VERSION = "0.1.0"
api.MACHINE_ID = "ti89_gpu"
api.LCD_WIDTH = LcdView.WIDTH
api.LCD_HEIGHT = LcdView.HEIGHT

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
