-- ComputerCraft API: TI-89 GPU WebSocket thin client.

local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local LcdView = require("frontends.computercraft.lcd_view_gpu_ti89")
local KeypadView = require("frontends.computercraft.keypad_view_gpu_ti89")
local Host = require("frontends.computercraft.host_gpu_ws")
local Args = require("frontends.computercraft.args_ti89_gpu_ws")
local Profile = require("frontends.computercraft.profile_ti89_gpu_ws")
local Remote = require("frontends.computercraft.ws.remote_machine")

local api = {}

api.VERSION = "0.1.0"
api.MACHINE_ID = "ti89_gpu_ws"
api.LCD_WIDTH = LcdView.WIDTH
api.LCD_HEIGHT = LcdView.HEIGHT

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
