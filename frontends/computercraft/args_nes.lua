-- ComputerCraft / bundle argv parser for NES.

local M = {}

function M.usage_text()
  return [[NAME
    nes_cc - NES emulator for ComputerCraft

SYNOPSIS
    nes_cc [OPTIONS] [lcd] [pad]

DESCRIPTION
    Boots an iNES cartridge (.nes). Attach one or more advanced monitors;
    each can be toggled between LCD and keypad (PAD). The computer
    screen is the control panel (pause / step / theme / quit).

    LCD uses pixelbox sixtels and quantizes the NES palette to CC's
    16 default colors. The frame scales to fit the monitor.

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        Cartridge image (default: game.nes; also tries mario.nes,
        smb.nes, or any *.nes in the computer directory).

    lcd pad
        Initial monitor sides (default: first found = LCD, others = PAD).

EXAMPLES
    nes_cc
    nes_cc --help
    nes_cc --rom mario.nes
    nes_cc left right

CONTROL PANEL
    Status bar     ||/> pause  >| step  G gate  Hz field  T theme
    Monitor chips  click cycles LCD -> PAD -> MEM -> OFF
    REFRESH        rescan .nes cartridges in this folder
    File list      click CART (.nes) to load and reset
    X              quit

NOTES
    Keys: D-pad, A, B, Start, Select (PAD monitor or touch).
    Audio via speaker peripheral when attached (SND/MUT).
    Monitor roles saved to nes.prefs.
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

local function is_nes(path)
  return type(path) == "string" and path:lower():match("%.nes$") ~= nil
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
    if a == nil then
      break
    elseif a == "-h" or a == "--help" then
      opts.help = true
    elseif a == "--rom" then
      i = i + 1
      if not args[i] then return nil, "--rom needs a path" end
      opts.rom = args[i]
    elseif take_eq("rom", a) then
      opts.rom = take_eq("rom", a)
      if opts.rom == "" then return nil, "--rom= needs a path" end
    elseif looks_flag(a) then
      return nil, "unknown flag: " .. a .. "\nTry: nes_cc --help"
    else
      opts.positional[#opts.positional + 1] = a
    end
    i = i + 1
  end

  local pos = {}
  local sides = {
    left = true, right = true, top = true, bottom = true, front = true, back = true,
  }
  for _, p in ipairs(opts.positional) do
    if is_nes(p) then
      if not opts.rom then opts.rom = p end
    else
      pos[#pos + 1] = p
    end
  end

  opts.lcd = pos[1]
  opts.pad = pos[2]
  if not opts.rom then
    local cand = pos[3]
    if cand and not sides[cand] then
      opts.rom = cand
    else
      opts.rom = "game.nes"
    end
  end
  return opts
end

function M.looks_flag(s)
  return looks_flag(s)
end

function M.recover_misparsed(opts)
  opts = opts or {}
  if not (looks_flag(opts.lcd) or looks_flag(opts.pad) or looks_flag(opts.rom)) then
    return nil
  end
  local argv = {}
  for _, key in ipairs({ "lcd", "pad", "rom" }) do
    if opts[key] ~= nil and opts[key] ~= "" then
      argv[#argv + 1] = opts[key]
    end
  end
  return M.parse(argv)
end

return M
