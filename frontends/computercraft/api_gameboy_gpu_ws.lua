-- ComputerCraft API: Game Boy GPU WebSocket thin client.

local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local LcdView = require("frontends.computercraft.lcd_view_gpu_gameboy")
local KeypadView = require("frontends.computercraft.keypad_view_gpu_gameboy")
local Host = require("frontends.computercraft.host_gpu_ws")
local Args = require("frontends.computercraft.args_gameboy_gpu_ws")
local Profile = require("frontends.computercraft.profile_gameboy_gpu_ws")
local Remote = require("frontends.computercraft.ws.remote_machine")
local Geom = require("machines.gameboy.lcd_geom")

local api = {}

api.VERSION = "0.1.0"
api.MACHINE_ID = "gameboy_gpu_ws"
api.LCD_WIDTH = Geom.WIDTH
api.LCD_HEIGHT = Geom.HEIGHT

api.CC = CC
api.Gpu = Gpu
api.Remote = Remote
api.LcdView = LcdView
api.KeypadView = KeypadView
api.Profile = Profile
api.parse_args = Args.parse
api.usage_text = Args.usage_text

function api.run(opts)
  opts = opts or {}
  opts.profile = opts.profile or Profile
  return Host.run(opts)
end

return api
