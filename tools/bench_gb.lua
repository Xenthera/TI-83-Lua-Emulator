#!/usr/bin/env lua
-- Game Boy throughput bench.
--   luajit tools/bench_gb.lua [seconds] [rom]

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]bench_gb%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

if jit and jit.opt then
  jit.opt.start("maxtrace=8000", "maxrecord=16000", "minstitch=3", "maxmcode=40960")
end

local seconds = tonumber(arg[1]) or 2.0
local rom_path = arg[2] or (ROOT .. "/rom/gb/tobu.gb")

local Machine = require("machines.gameboy.machine")
local bitmod = require("framework.util.bit")

local m = Machine.new()
assert(m:load_rom_file(rom_path), "load failed: " .. tostring(rom_path))
m:reset()
m:run_cycles(70224 * 90) -- warmup / JIT

local t0 = os.clock()
local cycles = 0
local frames = 0
while os.clock() - t0 < seconds do
  cycles = cycles + m:run_cycles(70224)
  frames = frames + 1
end
local dt = os.clock() - t0

local mhz = (cycles / dt) / 1e6
local target = 4.194304
print(string.format("rom=%s  bit=%s  jit=%s", rom_path, bitmod.backend, tostring(jit and jit.version or "no")))
print(string.format("%.3fs  %d cycles  %d frames  %.2f MHz  (%.1f%% of 4.19MHz)",
  dt, cycles, frames, mhz, mhz / target * 100))
print(string.format("PC=%04X lcdc=%02X", m:pc(), m.ppu.lcdc))
