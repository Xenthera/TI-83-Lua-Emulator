-- ComputerCraft host profile: Nintendo Entertainment System.

local CC = require("frontends.computercraft.cc")
local bit = require("framework.util.bit")
local band = bit.band

local P = {
  id = "nes",
  title = "NES",
  Machine = require("machines.nes.machine"),
  LcdView = require("frontends.computercraft.lcd_view_nes"),
  KeypadView = require("frontends.computercraft.keypad_view_nes"),
  MemMapView = require("frontends.computercraft.mem_map_view"),
  Args = require("frontends.computercraft.args_nes"),
  default_rom = "game.nes",
  prefs_file = "nes.prefs",
  supports_8xk = false,
  supports_8xp = false,
  supports_cart = true,
  file_filter = {
    empty_hint = "(no .nes cartridges in this folder)",
    kind_order = { cart = 1 },
    kind_tag = {
      cart = { text = "CART", bg = "lime" },
    },
    classify = function(lower)
      if lower:match("%.nes$") then return "cart" end
      return nil
    end,
  },
  -- ~2 NTSC frames; host paces by wall clock when APU is present.
  cycles_per_tick = 29781 * 2,
  paint_fps = 12,
  default_theme = "original",
  pad_scale = 0.5,
  boot_label = "NES bundle: starting...",
  enable_keybinds = true,
  enable_audio = true,
}

local ROM_CANDIDATES = {
  "game.nes",
  "mario.nes",
  "smb.nes",
  "nes.nes",
}

function P.load_rom(path)
  local tried = {}
  local function try(p)
    tried[#tried + 1] = p
    local data, err = CC.read_file(p)
    if data and #data >= 16 then
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
        if low:match("%.nes$") then
          local d, used = try(name)
          if d then return d, used end
        end
      end
    end
  end

  local names = CC.list_dir("")
  local hint = err or ("cannot open cart " .. tostring(path))
  hint = hint .. "\n  Need an iNES .nes cartridge (e.g. mario.nes)."
  hint = hint .. "\n  Tried: " .. table.concat(tried, ", ")
  if names and #names > 0 then
    hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
  end
  return nil, hint
end

function P.mem_source(machine)
  local ram, cart, cpu = machine.ram, machine.cart, machine.cpu
  return {
    read = function(_, addr)
      addr = band(addr or 0, 0xFFFF)
      if addr < 0x2000 then
        return ram[band(addr, 0x7FF)] or 0
      end
      if addr >= 0x6000 and cart and cart.cpu_read then
        return cart:cpu_read(addr) or 0
      end
      if cpu and cpu.bus and cpu.bus.read then
        return cpu.bus.read(addr) or 0
      end
      return 0
    end,
  }
end

function P.mem_paint_opts(machine)
  return {
    pc = machine.cpu and machine.cpu.pc,
    sp = machine.cpu and machine.cpu.sp,
  }
end

function P.wake_os(_machine, _opts)
end

return P
