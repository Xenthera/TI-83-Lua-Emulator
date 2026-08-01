return function(ok)
  local L = require("frontends.computercraft.launcher")

  local function check(name, id, gpu, ws)
    local m = L.parse_frontend_name(name)
    ok("parse " .. name, m ~= nil)
    if m then
      ok(name .. " id", m.id == id)
      ok(name .. " gpu", m.gpu == gpu)
      ok(name .. " ws", m.ws == ws)
    end
  end

  check("ti83_cc.lua", "ti83", false, false)
  check("ti83_cc_ws.lua", "ti83", false, true)
  check("ti89_gpu_cc.lua", "ti89", true, false)
  check("ti89_gpu_cc_ws.lua", "ti89", true, true)
  check("gb_cc.lua", "gb", false, false)
  ok("reject 8xk", L.parse_frontend_name("app.8xk") == nil)
  ok("reject random", L.parse_frontend_name("readme.txt") == nil)

  local group = {
    id = "ti89",
    title = "TI-89",
    has_base = true,
    has_gpu = true,
    has_ws = true,
    has_gpu_ws = true,
    variants = {
      base = { file = "ti89_cc.lua" },
      gpu = { file = "ti89_gpu_cc.lua" },
      base_ws = { file = "ti89_cc_ws.lua" },
      gpu_ws = { file = "ti89_gpu_cc_ws.lua" },
    },
  }
  ok("pick base", L.pick_variant(group, false, false).file == "ti89_cc.lua")
  ok("pick gpu", L.pick_variant(group, true, false).file == "ti89_gpu_cc.lua")
  ok("pick ws", L.pick_variant(group, false, true).file == "ti89_cc_ws.lua")
  ok("pick gpu+ws", L.pick_variant(group, true, true).file == "ti89_gpu_cc_ws.lua")

  local bare = {
    id = "gb",
    title = "Game Boy",
    variants = { base = { file = "gb_cc.lua" } },
  }
  local v, err = L.pick_variant(bare, true, false)
  ok("missing gpu nil", v == nil)
  ok("missing gpu err", type(err) == "string")

  -- parent_dir used by ROM browser
  if L.parent_dir then
    ok("parent_dir nested", L.parent_dir("rom/gb/a.gb") == "rom/gb"
      or L.parent_dir("rom/gb/a.gb") == "rom\\gb")
    ok("parent_dir root file", L.parent_dir("a.gb") == "")
  end
end
