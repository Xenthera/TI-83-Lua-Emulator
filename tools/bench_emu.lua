#!/usr/bin/env lua
-- Throughput benchmark for the Z80 core (desktop).
-- Uses a busy JP loop so HALT idle does not inflate MHz.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]bench_emu%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Machine = require("core.machine")
local bitmod = require("core.util.bit")

local seconds = tonumber(arg[1]) or 1.5
local mode = arg[2] or "busy" -- busy | rom
local rom_path = arg[3] or (ROOT .. "/rom/pipeline.rom")

local m = Machine.new()

if mode == "rom" then
  local f = assert(io.open(rom_path, "rb"))
  local bytes = f:read("*a")
  f:close()
  assert(m:load_rom_bytes(bytes))
else
  -- 512KB empty flash with a tight ALU loop at 0x0000.
  local FLASH = 512 * 1024
  local img = {}
  -- xor a; inc a; jp 0x0000
  img[1] = string.char(0xAF, 0x3C, 0xC3, 0x00, 0x00)
  img[2] = string.rep("\0", FLASH - 5)
  assert(m:load_rom_bytes(table.concat(img)))
end

m:reset()
m:run_cycles(50000) -- warmup

local t0 = os.clock()
local cycles = 0
while os.clock() - t0 < seconds do
  cycles = cycles + m:run_cycles(200000)
end
local dt = os.clock() - t0
local mhz = (cycles / dt) / 1e6
print(string.format("mode=%s  bit=%s", mode, bitmod.backend))
print(string.format("%.3fs  %d cycles  %.2f MHz  (%.1f%% of 6MHz)",
  dt, cycles, mhz, mhz / 6 * 100))
print(string.format("PC=%04X", m:pc()))
