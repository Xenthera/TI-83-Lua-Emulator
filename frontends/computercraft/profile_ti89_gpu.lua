-- ComputerCraft GPU profile: TI-89 Titanium on Tom's Peripherals bitmap monitors.
local CC = require("frontends.computercraft.cc")

local P = {
  id = "ti89_gpu",
  title = "TI-89 Titanium (GPU)",
  Machine = require("machines.ti89.machine"),
  Face = require("frontends.computercraft.face_gpu_ti89"),
  LcdView = require("frontends.computercraft.lcd_view_gpu_ti89"),
  KeypadView = require("frontends.computercraft.keypad_view_gpu_ti89"),
  Args = require("frontends.computercraft.args_ti89_gpu"),
  default_rom = "ti89.rom",
  prefs_file = "ti89_gpu.prefs",
  supports_8xk = false,
  supports_8xp = false,
  cycles_per_tick = 400000,
  default_theme = "titanium",
  gpu_size = 64, -- always 64 px per bitmap-monitor block

  boot_label = "TI-89 Titanium GPU bundle: starting...",
}

local ROM_CANDIDATES = {
  "ti89.rom",
  "ti89titanium.rom",
  "ti89hw2.rom",
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
  hint = hint .. "\n  Need a TI-89 Titanium AMS image (TIFL OS or raw flash dump)."
  hint = hint .. "\n  Tried: " .. table.concat(tried, ", ")
  if names and #names > 0 then
    hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
  end
  return nil, hint
end

function P.wake_os(_machine, _opts)
end

return P
