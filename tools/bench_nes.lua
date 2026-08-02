#!/usr/bin/env lua
-- NES throughput bench.
--   luajit tools/bench_nes.lua [seconds] [rom]

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]bench_nes%.lua$") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

if jit and jit.opt then
  jit.opt.start("maxtrace=8000", "maxrecord=16000", "minstitch=3", "maxmcode=40960")
end

local seconds = tonumber(arg[1]) or 2.0
local rom_path = arg[2]
  or (ROOT .. "/tools/nes-test-roms/ppu_vbl_nmi/rom_singles/05-nmi_timing.nes")

local Machine = require("machines.nes.machine")
local bitmod = require("framework.util.bit")

local CPF = 29780 -- approx NTSC CPU cycles/frame
local TARGET = 1.789773

local m = Machine.new()
assert(m:load_rom_file(rom_path, { skip_save = true }), "load failed: " .. tostring(rom_path))
m:reset()
m:run_cycles(CPF * 90) -- warmup / JIT

local t0 = os.clock()
local cycles = 0
local frames = 0
while os.clock() - t0 < seconds do
  cycles = cycles + m:run_cycles(CPF)
  frames = frames + 1
end
local dt = os.clock() - t0

local mhz = (cycles / dt) / 1e6
print(string.format("rom=%s  bit=%s  jit=%s", rom_path, bitmod.backend, tostring(jit and jit.version or "no")))
print(string.format("%.3fs  %d cycles  %d frames  %.2f MHz  (%.1f%% of 1.79MHz)  ~%.0f fps-eq",
  dt, cycles, frames, mhz, mhz / TARGET * 100, (cycles / dt) / CPF))
print(string.format("PC=%04X sl=%d cy=%d", m:pc(), m.ppu.scanline, m.ppu.cycle))
