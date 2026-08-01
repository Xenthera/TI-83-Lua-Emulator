local M = {}

function M.usage_text()
  return [[NAME
    gb_cc_ws - Game Boy (DMG) advanced-monitor client over WebSocket

SYNOPSIS
    gb_cc_ws --url ws://HOST:8765 [--rom PATH] [--lcd SIDE] [--pad SIDE]

DESCRIPTION
    Thin CC client. Emulation runs on LuaJIT
    (bridge/main.lua --machine gameboy [--rom cart.gb]).
    LCD is 160x144 with 4 shades.

    If --rom is set, the cart is read on this computer and uploaded to the
    bridge over WebSocket (bridge may be started with no ROM).

    Audio: bridge streams PCM with LCD frames; play via a speaker
    peripheral. SND/MUT toggles mute on the control bar.

OPTIONS
    -h, --help
    --url URL
    --rom PATH
    --lcd SIDE
    --pad SIDE
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
end

function M.parse(args)
  args = args or {}
  local opts = { positional = {} }
  local i = 1
  while i <= #args do
    local a = args[i]
    if a == "-h" or a == "--help" then opts.help = true
    elseif a == "--url" then i = i + 1; opts.url = args[i]
    elseif a == "--rom" then i = i + 1; opts.rom = args[i]
    elseif a == "--lcd" then i = i + 1; opts.lcd = args[i]
    elseif a == "--pad" then i = i + 1; opts.pad = args[i]
    else
      local url, rom, lcd, pad =
        take_eq("url", a), take_eq("rom", a), take_eq("lcd", a), take_eq("pad", a)
      if url then opts.url = url
      elseif rom then opts.rom = rom
      elseif lcd then opts.lcd = lcd
      elseif pad then opts.pad = pad
      elseif looks_flag(a) then
        return nil, "unknown option: " .. tostring(a) .. "\n\n" .. M.usage_text()
      else
        opts.positional[#opts.positional + 1] = a
      end
    end
    i = i + 1
  end
  return opts
end

return M
