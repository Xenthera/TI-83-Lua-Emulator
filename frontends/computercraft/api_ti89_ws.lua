local Host = require("frontends.computercraft.host_ws")
local Args = require("frontends.computercraft.args_ti89_ws")
local Profile = require("frontends.computercraft.profile_ti89_ws")
local Remote = require("frontends.computercraft.ws.remote_machine")

local api = {}
api.VERSION = "0.1.0"
api.MACHINE_ID = "ti89_ws"
api.Profile = Profile
api.Remote = Remote
api.parse_args = Args.parse
api.usage_text = Args.usage_text

function api.run(opts)
  opts = opts or {}
  opts.profile = opts.profile or Profile
  return Host.run(opts)
end

return api
