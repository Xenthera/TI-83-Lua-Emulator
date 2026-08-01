-- ComputerCraft argv parser for the TI-89 Tom's Peripherals GPU bundle.

local M = {}

function M.usage_text()
  return [[NAME
    ti89_gpu_cc / test - TI-89 Titanium on Tom's Peripherals GPU

SYNOPSIS
    test [OPTIONS]
    ti89_gpu_cc [OPTIONS]

DESCRIPTION
    Boots a TI-89 Titanium AMS flash image and draws a Love-style
    calculator face (LCD above keypad) on Tom's bitmap monitors via
    a GPU peripheral. LCD pixels include gaps like a real panel.

    Requires the Tom's Peripherals mod (GPU + bitmap monitors).
    The computer terminal is the control panel (pause / step / gate).

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        TI-89 flash image (default: ti89.rom).

    --gpu NAME
        GPU peripheral name (default: first tm_gpu found).

    --gpu-size N
        Ignored (always 64 px per bitmap-monitor block).

EXAMPLES
    test --rom ti89titanium.rom

NOTES
    Tom's setSize(64) is forced (max per-block resolution).
    The calculator expands to fill monitor height (4px pad), centered
    horizontally. LCD cell scales with glass size (with pixel gaps).
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
    elseif a == "--gpu" then
      i = i + 1
      opts.gpu = args[i]
    elseif a == "--gpu-size" then
      i = i + 1
      opts.gpu_size = tonumber(args[i])
    elseif a == "--face-scale" then
      i = i + 1
      opts.face_scale = tonumber(args[i])
    else
      local rom = take_eq("rom", a)
      local gpu = take_eq("gpu", a)
      local gsz = take_eq("gpu-size", a)
      local fsc = take_eq("face-scale", a)
      if rom then
        opts.rom = rom
      elseif gpu then
        opts.gpu = gpu
      elseif gsz then
        opts.gpu_size = tonumber(gsz)
      elseif fsc then
        opts.face_scale = tonumber(fsc)
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
  return opts
end

function M.recover_misparsed(opts)
  return opts
end

return M
