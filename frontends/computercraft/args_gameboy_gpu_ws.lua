-- Argv for Game Boy GPU WebSocket thin client (parity with gb_cc_ws).

local M = {}

function M.usage_text()
  return [[NAME
    gb_gpu_cc_ws - Game Boy GPU face over WebSocket

SYNOPSIS
    gb_gpu_cc_ws --url ws://HOST:8765 [--rom PATH] [OPTIONS]

DESCRIPTION
    Thin ComputerCraft client: paints LCD+keypad on Tom's GPU bitmap
    monitors with classic DMG green shades and round controls.
    Emulation runs on the PC (LuaJIT bridge). Same control panel as
    gb_cc_ws (cart list, mute, keybinds).

OPTIONS
    -h, --help
    --url URL          WebSocket URL (default: ws://127.0.0.1:8765)
    --rom PATH         Upload a local .gb cart to the bridge
    --gpu NAME         GPU peripheral (default: first found)

CONTROL PANEL
    KEYS / SND / file list / pause / quit - same as gb_cc_ws

HOST
    bridge\run.cmd --machine gb --port 8765
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

function M.parse(args)
  args = args or {}
  local opts = { positional = {} }
  local i = 1
  while i <= #args do
    local a = args[i]
    if a == "-h" or a == "--help" then
      opts.help = true
    elseif a == "--url" then
      i = i + 1
      opts.url = args[i]
    elseif a == "--rom" then
      i = i + 1
      opts.rom = args[i]
    elseif a == "--gpu" then
      i = i + 1
      opts.gpu = args[i]
    elseif a == "--face-scale" or a == "--gpu-size" then
      i = i + 1
    else
      local url = take_eq("url", a)
      local rom = take_eq("rom", a)
      local gpu = take_eq("gpu", a)
      if url then opts.url = url
      elseif rom then opts.rom = rom
      elseif gpu then opts.gpu = gpu
      elseif looks_flag(a) then
        return nil, "unknown option: " .. tostring(a) .. "\n\n" .. M.usage_text()
      else
        opts.positional[#opts.positional + 1] = a
      end
    end
    i = i + 1
  end
  if not opts.url and opts.positional[1] and tostring(opts.positional[1]):match("^ws") then
    opts.url = opts.positional[1]
  elseif opts.positional[1] and not opts.rom then
    opts.rom = opts.positional[1]
  end
  opts.gpu_size = 64
  return opts
end

return M
