-- ComputerCraft GPU profile: original Game Boy on Tom's Peripherals bitmap monitors.

local CC = require("frontends.computercraft.cc")

local P = {
  id = "gameboy_gpu",
  title = "Game Boy (GPU)",
  Machine = require("machines.gameboy.machine"),
  Face = require("frontends.computercraft.face_gpu_gameboy"),
  LcdView = require("frontends.computercraft.lcd_view_gpu_gameboy"),
  KeypadView = require("frontends.computercraft.keypad_view_gpu_gameboy"),
  Args = require("frontends.computercraft.args_gameboy_gpu"),
  default_rom = "tetris.gb",
  prefs_file = "gameboy_gpu.prefs",
  supports_8xk = false,
  supports_8xp = false,
  supports_cart = true,
  file_filter = {
    empty_hint = "(no .gb cartridges in this folder)",
    kind_order = { cart = 1 },
    kind_tag = {
      cart = { text = "CART", bg = "lime" },
    },
    classify = function(lower)
      if lower:match("%.gb$") then return "cart" end
      return nil
    end,
  },
  cycles_per_tick = 70224 * 2,
  paint_fps = 12,
  default_theme = "original",
  gpu_size = 64,
  boot_label = "Game Boy GPU bundle: starting...",
  enable_keybinds = true,
  enable_audio = true,
}

local ROM_CANDIDATES = {
  "tetris.gb",
  "testris.gb",
  "gameboy.gb",
  "dmg.gb",
  "gameboy_test.gb",
}

--- Load cart bytes. On success returns data, path_used.
function P.load_rom(path)
  local tried = {}
  local function try(p)
    tried[#tried + 1] = p
    local data, err = CC.read_file(p)
    if data and #data >= 0x150 then
      return data, p
    end
    return nil, err
  end

  local data, err = try(path)
  if data then return data, err end

  if path == P.default_rom then
    for _, cand in ipairs(ROM_CANDIDATES) do
      if cand ~= path then
        local d, used = try(cand)
        if d then return d, used end
      end
    end
    local names = CC.list_dir("")
    if names then
      for _, name in ipairs(names) do
        local low = tostring(name):lower()
        if low:match("%.gb$") then
          local d, used = try(name)
          if d then return d, used end
        end
      end
    end
  end

  local names = CC.list_dir("")
  local hint = err or ("cannot open cart " .. tostring(path))
  hint = hint .. "\n  Need a DMG .gb cartridge (e.g. tetris.gb)."
  hint = hint .. "\n  Tried: " .. table.concat(tried, ", ")
  if names and #names > 0 then
    hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
  end
  return nil, hint
end

function P.wake_os(_machine, _opts)
end

return P
