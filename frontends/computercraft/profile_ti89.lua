-- ComputerCraft host profile: TI-89 Titanium.
local CC = require("frontends.computercraft.cc")
local MemMap89 = require("frontends.computercraft.mem_map_view_ti89")

local P = {
  id = "ti89",
  title = "TI-89 Titanium",
  Machine = require("machines.ti89.machine"),
  LcdView = require("frontends.computercraft.lcd_view_ti89"),
  KeypadView = require("frontends.computercraft.keypad_view_ti89"),
  MemMapView = MemMap89,
  Args = require("frontends.computercraft.args_ti89"),
  default_rom = "ti89.rom",
  prefs_file = "ti89.prefs",
  supports_8xk = false,
  supports_8xp = false,
  -- Heavier per-op than Z80; larger slices cut CC timer/yield overhead.
  cycles_per_tick = 400000,
  default_theme = "titanium",
  -- Prefer larger keypad glyphs; view auto-falls back if the monitor is tight.
  pad_scale = 0.75,
  boot_label = "TI-89 Titanium bundle: starting...",
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

  -- Fall back to common names when default path missing.
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

function P.mem_source(machine)
  return machine -- mem_map_view_ti89:paint expects the machine
end

function P.mem_paint_opts(machine)
  return MemMap89.markers_for(machine)
end

function P.wake_os(_machine, _opts)
  -- AMS boots itself; no TI-83-style homescreen poke.
end

return P
