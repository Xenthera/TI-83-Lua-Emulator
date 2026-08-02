-- ComputerCraft argv parser for the TI-92 Plus bundle.

local M = {}

function M.usage_text()
  return [[NAME
    ti92_cc / test - TI-92 Plus emulator for ComputerCraft

SYNOPSIS
    test [OPTIONS] [lcd] [pad]
    ti92_cc [OPTIONS] [lcd] [pad]

DESCRIPTION
    Boots a TI-92 Plus AMS flash image (TIFL OS or raw dump).
    The LCD sits inside the QWERTY face - the first monitor is the
    whole calculator (keys + inset 240x128 glass). Extra monitors can
    show MEM or OFF. The computer screen is the control panel.

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        TI-92 Plus flash image (default: ti92plus.rom). Also accepts
        ti92p.rom / ti92.rom.

    face [mem]
        Initial monitor sides (default: first found = FACE).
        Toggle any monitor on the control panel anytime.

EXAMPLES
    test
    test --help
    test --rom ti92plus.rom
    test left

CONTROL PANEL
    Status bar     ||/> pause  >| step  G gate  Hz field  T theme
    Themes         gray, orig, hi, b/w, w/b, amber, ocean, candy
    Gate           when ON, run at N CPU instructions/sec
    Monitor chips  click cycles FACE -> MEM -> OFF
                   FACE = keypad with LCD in the middle (layout scene)
                   LCD glass needs >= 120x43 chars (240x128 @ 2x3 sixtels)
                   Use text scale 0.5 / a wide advanced monitor
                   MEM = low 64KB of RAM
    IDENTIFY / REFRESH / X as on the TI-83+ host

NOTES
    .8xk / .8xp install is TI-83+ only (not available here).
    Monitor roles are saved to ti92.prefs next to the program.
    Face layout is exported from ui/keypads/ti92plus.lua.
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
  -- Positional: face monitor first (also accepted as legacy lcd/pad names).
  opts.face = opts.positional[1]
  opts.lcd = opts.positional[1]
  opts.pad = opts.positional[2]
  if opts.positional[3] and not opts.rom then
    opts.rom = opts.positional[3]
  end
  return opts
end

function M.recover_misparsed(opts)
  local Base = require("frontends.computercraft.args")
  return Base.recover_misparsed(opts)
end

return M
