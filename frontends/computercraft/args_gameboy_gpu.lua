-- ComputerCraft argv parser for the Game Boy Tom's Peripherals GPU bundle.
-- Same control-panel interface as gb_cc (files / mute / keybinds / speaker).

local M = {}

function M.usage_text()
  return [[NAME
    gb_gpu_cc - Game Boy (DMG) on Tom's Peripherals GPU

SYNOPSIS
    gb_gpu_cc [OPTIONS]

DESCRIPTION
    Boots a DMG cartridge (.gb) and paints a Game Boy face (classic
    green LCD above round A/B, cross D-pad, Start/Select) on Tom's
    bitmap monitors via a GPU peripheral.

    Requires Tom's Peripherals (GPU + bitmap monitors). Optional
    speaker for audio. Computer terminal = control panel (same as gb_cc).

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        Cartridge image (default: tetris.gb; also tries common names
        or any *.gb in the computer directory).

    --gpu NAME
        GPU peripheral name (default: first tm_gpu found).

EXAMPLES
    gb_gpu_cc
    gb_gpu_cc --rom tetris.gb
    gb_gpu_cc --rom tetris.gb --gpu tm_gpu_0

CONTROL PANEL
    Status bar     ||/> pause  >| step  G gate  Hz field  T theme
    KEYS           remappable keyboard binds
    SND/MUT        speaker mute
    REFRESH        rescan .gb cartridges
    File list      click CART (.gb) to load and reset
    X              quit

NOTES
    GPU setSize(64) is always used (max per bitmap-monitor block).
    Keys: D-pad, A, B, Start, Select (touch face or keyboard).
    Audio via speaker peripheral when attached.
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
  local opts = { positional = {} }
  local i = 1
  while i <= #args do
    local a = args[i]
    if a == "-h" or a == "--help" then
      opts.help = true
    elseif a == "--rom" then
      i = i + 1
      opts.rom = args[i]
    elseif a == "--gpu" then
      i = i + 1
      opts.gpu = args[i]
    elseif a == "--gpu-size" or a == "--face-scale" then
      -- Accepted for parity; GPU size is always 64.
      i = i + 1
    else
      local rom = take_eq("rom", a)
      local gpu = take_eq("gpu", a)
      if rom then opts.rom = rom
      elseif gpu then opts.gpu = gpu
      elseif looks_flag(a) then
        return nil, "unknown option: " .. tostring(a) .. "\n\n" .. M.usage_text()
      else
        opts.positional[#opts.positional + 1] = a
      end
    end
    i = i + 1
  end
  if opts.positional[1] and not opts.rom then
    opts.rom = opts.positional[1]
  end
  if opts.positional[2] and not opts.gpu then
    opts.gpu = opts.positional[2]
  end
  opts.gpu_size = 64
  return opts
end

function M.recover_misparsed(opts)
  return opts
end

return M
