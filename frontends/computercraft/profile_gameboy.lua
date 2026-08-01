-- ComputerCraft host profile: original Game Boy (DMG).

local CC = require("frontends.computercraft.cc")

local P = {
  id = "gameboy",
  title = "Game Boy",
  Machine = require("machines.gameboy.machine"),
  LcdView = require("frontends.computercraft.lcd_view_gameboy"),
  KeypadView = require("frontends.computercraft.keypad_view_gameboy"),
  MemMapView = require("frontends.computercraft.mem_map_view"),
  Args = require("frontends.computercraft.args_gameboy"),
  default_rom = "tetris.gb",
  prefs_file = "gameboy.prefs",
  supports_8xk = false,
  supports_8xp = false,
  supports_cart = true,
  -- Control panel file list (machine-specific; not TI .8xk/.8xp).
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
  -- Fallback slice (~2 frames). With audio, host.lua paces by wall dt
  -- toward 100% realtime so the speaker is not starved.
  cycles_per_tick = 70224 * 2,
  paint_fps = 12,
  default_theme = "original",
  pad_scale = 0.5,
  boot_label = "Game Boy bundle: starting...",
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

--- Load cart bytes. On success returns data, path_used (so .sav can sit beside the .gb).
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
  if data then return data, err end -- err is path_used here

  if path == P.default_rom then
    for _, cand in ipairs(ROM_CANDIDATES) do
      if cand ~= path then
        local d, used = try(cand)
        if d then return d, used end
      end
    end
    -- Any .gb in the computer directory
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

function P.mem_source(machine)
  return machine.mmu
end

function P.mem_paint_opts(machine)
  return {
    pc = machine.cpu.pc,
    sp = machine.cpu.sp,
  }
end

function P.wake_os(_machine, _opts)
  -- No OS wake; cart starts at post-boot PC=0x100.
end

return P
