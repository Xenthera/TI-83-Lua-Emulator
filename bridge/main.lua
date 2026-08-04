#!/usr/bin/env luajit
-- LuaJIT WebSocket emu host.
--
--   tools\luajit\luajit.exe bridge\main.lua --machine ti89 --rom rom\ti89.rom --port 8765

local ROOT = arg[0]:match("(.+)[/\\]bridge[/\\]main%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path
-- Prefer LuaSocket next to luajit.exe
local lj = ROOT .. "/tools/luajit"
package.cpath = lj .. "/?.dll;" .. lj .. "/?/?.dll;" .. package.cpath

-- OpenResty-style JIT limits: large opcode tables / PPU loops need headroom.
if jit and jit.opt then
  jit.opt.start("maxtrace=8000", "maxrecord=16000", "minstitch=3", "maxmcode=40960")
end

local function usage()
  io.stderr:write([[
Usage: luajit bridge/main.lua --machine ID [--rom PATH] [--port 8765] [--host *]

  Machines: ti83plus, ti84plus, ti89, ti92plus, gameboy, nes
  (aliases: ti83, ti84, ti92, gb, famicom)

  Runs the emulator on LuaJIT and serves LCD/key over WebSocket for thin
    ComputerCraft clients (dist/*_cc_ws.lua).

  --rom is required for TI machines. For gameboy/gb and nes it is optional:
  the bridge can idle until a client uploads a cart via load_rom.

  Speed (default: realtime 1.0x guest CPU clock):
    --speed N       run at Nx realtime (e.g. 0.5, 2)
    --no-throttle   run as fast as the host allows
    --cycles N      max guest cycles per loop slice (default ~CPU_HZ/120)
    --fps N         LCD push rate to CC (default 30)

  NES audio (optional):
    --apu-hq        modern PolyBLEP synth (still CPU-register driven)
    --apu classic   hardware-faithful APU render (default)

]])
  os.exit(1)
end

local opts = {
  machine = "ti89",
  port = 8765,
  host = "*",
  fps = 30,
  throttle = true,
  speed = 1.0,
}
local i = 1
while i <= #arg do
  local a = arg[i]
  if a == "-h" or a == "--help" then
    usage()
  elseif a == "--machine" then
    i = i + 1
    opts.machine = arg[i]
  elseif a == "--rom" then
    i = i + 1
    opts.rom = arg[i]
  elseif a == "--port" then
    i = i + 1
    opts.port = tonumber(arg[i])
  elseif a == "--host" then
    i = i + 1
    opts.host = arg[i]
  elseif a == "--fps" then
    i = i + 1
    opts.fps = tonumber(arg[i])
  elseif a == "--cycles" then
    i = i + 1
    opts.cycles = tonumber(arg[i])
  elseif a == "--speed" then
    i = i + 1
    opts.speed = tonumber(arg[i]) or 1.0
  elseif a == "--no-throttle" then
    opts.throttle = false
  elseif a == "--apu-hq" then
    opts.apu_synth = "hq"
  elseif a == "--apu" then
    i = i + 1
    opts.apu_synth = arg[i]
  elseif a:sub(1, 1) == "-" then
    io.stderr:write("unknown option: " .. a .. "\n")
    usage()
  else
    opts.rom = opts.rom or a
  end
  i = i + 1
end

do
  local Protocol = require("bridge.protocol")
  local mid = Protocol.canonical_id(opts.machine or "ti89")
  if (not opts.rom or opts.rom == "") and mid ~= "gameboy" and mid ~= "nes" then
    usage()
  end
end

local Session = require("bridge.emu_session")
local ok, err = Session.run(opts)
if not ok then
  io.stderr:write("ERROR: " .. tostring(err) .. "\n")
  os.exit(1)
end
