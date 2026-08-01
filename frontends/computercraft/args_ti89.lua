-- ComputerCraft argv parser for the TI-89 Titanium bundle.

local M = {}

function M.usage_text()
  return [[NAME
    ti89_cc / test - TI-89 Titanium emulator for ComputerCraft

SYNOPSIS
    test [OPTIONS] [lcd] [pad]
    ti89_cc [OPTIONS] [lcd] [pad]

DESCRIPTION
    Boots a TI-89 Titanium AMS flash image (TIFL OS or raw dump).
    Attach one or more advanced monitors; each can be toggled between
    LCD (160x100), keypad, memory map, or off. The computer screen is
    the control panel (pause / step / gate / theme).

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        TI-89 flash image (default: ti89.rom). Also accepts
        ti89titanium.rom.

    lcd pad
        Initial monitor sides (default: first found = LCD, others = PAD).
        Toggle any monitor on the control panel anytime.

EXAMPLES
    test
    test --help
    test --rom ti89titanium.rom
    test left right

CONTROL PANEL
    Status bar     ||/> pause  >| step  G gate  Hz field  T theme
    Themes         gray, orig, hi, b/w, w/b, amber, ocean, candy
    Gate           when ON, run at N CPU instructions/sec
    Monitor chips  click cycles LCD -> PAD -> MEM -> OFF
                   LCD needs ~80x34 at text scale 0.5 (2x3 sixtels)
                   MEM = low 64KB of Titanium RAM
    IDENTIFY / REFRESH / X as on the TI-83+ host

NOTES
    .8xk / .8xp install is TI-83+ only (not available here).
    Monitor roles are saved to ti89.prefs next to the program.
]]
end

local function looks_flag(s)
  return type(s) == "string" and s:sub(1, 1) == "-"
end

local function take_eq(flag, a)
  local prefix = "--" .. flag .. "="
  if type(a) == "string" and a:sub(1, #prefix) == prefix then
    return a:sub(#prefix + 1)
  end
  return nil
end

function M.looks_flag(s)
  return looks_flag(s)
end

function M.parse(args)
  args = args or {}
  local opts = {
    loadapp = {},
    loadprog = {},
    positional = {},
  }
  local i = 1
  while i <= #args do
    local a = args[i]
    if a == "-h" or a == "--help" then
      opts.help = true
    elseif a == "--rom" then
      i = i + 1
      opts.rom = args[i]
    else
      local rom = take_eq("rom", a)
      if rom then
        opts.rom = rom
      elseif looks_flag(a) then
        return nil, "unknown option: " .. tostring(a) .. "\n\n" .. M.usage_text()
      else
        opts.positional[#opts.positional + 1] = a
      end
    end
    i = i + 1
  end
  opts.lcd = opts.positional[1]
  opts.pad = opts.positional[2]
  if opts.positional[3] and not opts.rom then
    opts.rom = opts.positional[3]
  end
  return opts
end

function M.recover_misparsed(opts)
  -- Same idea as TI-83 args: flags mistakenly used as sides.
  local Base = require("frontends.computercraft.args")
  return Base.recover_misparsed(opts)
end

return M
