#!/usr/bin/env lua
-- Throughput / hot-path microbench for TI-89 m68k (desktop).
-- Busy BRA.S loop in flash at $800400 (AMS-like fetch path).

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]bench_m68k%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Machine = require("machines.ti89.machine")
local bitmod = require("framework.util.bit")

local seconds = tonumber(arg[1]) or 1.5
local mode = arg[2] or "full" -- full | notick | norefresh | step | flashbytes

local function make_rom()
  local bytes = {}
  for i = 0, 0xFFFF do bytes[i] = 0 end
  local function poke16(addr, v)
    bytes[addr] = math.floor(v / 256) % 256
    bytes[addr + 1] = v % 256
  end
  local function poke32(addr, v)
    poke16(addr, math.floor(v / 65536) % 65536)
    poke16(addr + 2, v % 65536)
  end
  -- Reset vectors (copied into RAM $0 on load/reset).
  poke32(0, 0x00001000) -- SSP
  poke32(4, 0x00800400) -- PC in Titanium flash window
  -- Code in flash image at offset $400 → CPU addr $800400.
  poke16(0x400, 0x7001) -- MOVEQ #1,D0
  poke16(0x402, 0x60FE) -- BRA.S *
  local parts = {}
  for i = 0, 0xFFFF do parts[i + 1] = string.char(bytes[i]) end
  return table.concat(parts)
end

local m = Machine.new()
assert(m:load_rom_bytes(make_rom()))
m:reset()

if mode == "flashbytes" then
  -- Force materialize (memory-heavy; A/B only).
  local flash = m.flash
  if not flash.bytes then
    local data = flash.data
    local bytes = {}
    for i = 1, #data do bytes[i - 1] = data:byte(i) end
    flash.bytes = bytes
  end
elseif mode == "notick" then
  function m.bus.tick() end
elseif mode == "norefresh" then
  function m.lcd.refresh_from_ram() end
end

assert(m:pc() == 0x800400, string.format("bad pc %06X", m:pc()))
m:run_cycles(20000) -- warmup
assert(m:pc() == 0x800402 or m:pc() == 0x800400,
  string.format("left loop pc=%06X", m:pc()))

local t0 = os.clock()
local cycles = 0
if mode == "step" then
  local cpu = m.cpu
  while os.clock() - t0 < seconds do
    for _ = 1, 4000 do
      cycles = cycles + cpu:step()
    end
  end
else
  while os.clock() - t0 < seconds do
    cycles = cycles + m:run_cycles(200000)
  end
end
local dt = os.clock() - t0
local mhz = (cycles / dt) / 1e6
print(string.format("mode=%s  bit=%s  flash.bytes=%s",
  mode, bitmod.backend, tostring(m.flash.bytes ~= nil)))
print(string.format("%.3fs  %d cycles  %.2f MHz  (%.1f%% of 16MHz)",
  dt, cycles, mhz, mhz / 16 * 100))
print(string.format("PC=%06X", m:pc()))
