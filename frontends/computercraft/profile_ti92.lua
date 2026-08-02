-- ComputerCraft host profile: TI-92 Plus.
local CC = require("frontends.computercraft.cc")
local MemMap92 = require("frontends.computercraft.mem_map_view_ti92")

local P = {
  id = "ti92plus",
  title = "TI-92 Plus",
  Machine = require("machines.ti92plus.machine"),
  LcdView = require("frontends.computercraft.lcd_view_ti92"),
  KeypadView = require("frontends.computercraft.keypad_view_ti92"),
  -- LCD is physically inside the keypad - one monitor shows the whole face.
  FaceView = require("frontends.computercraft.face_view_ti92"),
  combined_face = true,
  role_cycle = { "face", "mem", "off" },
  MemMapView = MemMap92,
  Args = require("frontends.computercraft.args_ti92"),
  default_rom = "ti92plus.rom",
  prefs_file = "ti92.prefs",
  supports_8xk = false,
  supports_8xp = false,
  cycles_per_tick = 400000,
  default_theme = "titanium",
  -- Face + keypad always use text scale 0.5 (forced in FaceView / KeypadView).
  pad_scale = 0.5,
  boot_label = "TI-92 Plus bundle: starting...",
}

local ROM_CANDIDATES = {
  "ti92plus.rom",
  "ti92p.rom",
  "ti92.rom",
  "ti92plus.tib",
}

function P.load_rom(path)
  local tried = {}
  local function try(p)
    tried[#tried + 1] = p
    local data, err = CC.read_file(p)
    if data and #data > 0 then
      return data
    end
    return nil, err
  end

  local data, err = try(path)
  if data then return data end

  if path == P.default_rom then
    for _, cand in ipairs(ROM_CANDIDATES) do
      if cand ~= path then
        local d = try(cand)
        if d then return d end
      end
    end
  end

  local names = CC.list_dir("")
  local hint = err or ("cannot open ROM " .. tostring(path))
  hint = hint .. "\n  Need a TI-92 Plus AMS image (TIFL OS or raw flash dump)."
  hint = hint .. "\n  Tried: " .. table.concat(tried, ", ")
  if names and #names > 0 then
    hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
  end
  return nil, hint
end

function P.mem_source(machine)
  return machine
end

function P.mem_paint_opts(machine)
  return MemMap92.markers_for(machine)
end

function P.wake_os(_machine, _opts)
end

return P
