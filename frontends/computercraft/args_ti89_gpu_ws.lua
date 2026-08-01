-- Argv for TI-89 GPU WebSocket thin client.

local M = {}

function M.usage_text()
  return [[NAME
    ti89_gpu_cc_ws - TI-89 Titanium GPU face over WebSocket

SYNOPSIS
    ti89_gpu_cc_ws --url ws://HOST:8765 [OPTIONS]

DESCRIPTION
    Thin ComputerCraft client: paints LCD+keypad on Tom's GPU bitmap
    monitors. Emulation runs on the PC (LuaJIT bridge/main.lua).

    Requires: Tom's Peripherals GPU + bitmap monitors, CC:Tweaked HTTP
    websocket access to the host URL.

OPTIONS
    -h, --help
    --url URL          WebSocket URL (default: ws://127.0.0.1:8765)
    --gpu NAME         GPU peripheral (default: first found)
    --face-scale N     Optional layout hint

HOST
    tools\luajit\luajit.exe bridge\main.lua --machine ti89 --rom ti89.rom --port 8765
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
    elseif a == "--gpu" then
      i = i + 1
      opts.gpu = args[i]
    elseif a == "--face-scale" then
      i = i + 1
      opts.face_scale = tonumber(args[i])
    else
      local url = take_eq("url", a)
      local gpu = take_eq("gpu", a)
      local fsc = take_eq("face-scale", a)
      if url then opts.url = url
      elseif gpu then opts.gpu = gpu
      elseif fsc then opts.face_scale = tonumber(fsc)
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
  end
  return opts
end

return M
