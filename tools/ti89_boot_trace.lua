-- Trace TI-89 AMS boot: PC histogram, illegals, progress milestones.
package.path = "./?.lua;./?/init.lua;" .. package.path

local Machine = require("machines.ti89.machine")
local bit = require("framework.util.bit")
local band = bit.band

local rom = arg[1] or "rom/ti89.rom"
local max_steps = tonumber(arg[2]) or 5000000

local m = Machine.new()
local ok, meta = m:load_rom_file(rom)
if not ok then
  io.stderr:write("load failed: " .. tostring(meta) .. "\n")
  os.exit(1)
end
print(string.format("loaded %s format=%s patched=%s", rom, tostring(meta and meta.format), tostring(meta and meta.boot_link_patched)))
m:reset()
local cpu = m.cpu
print(string.format("reset PC=%06X SSP=%06X SR=%04X", cpu.pc, cpu.ssp, cpu.sr))

local hist = {}
local top_pcs = {}
local illegal_hits = {}
local line_a = 0
local line_f = 0
local exceptions = {}
local t0 = os.clock()
local steps = 0
local report_at = { 100000, 500000, 1000000, 2000000, 5000000, 10000000 }
local ri = 1

local orig_raise = cpu.raise_exception
function cpu:raise_exception(vector)
  exceptions[vector] = (exceptions[vector] or 0) + 1
  if vector == 4 then
    local pc = self.pc
    local op = self:read16(pc)
    illegal_hits[#illegal_hits + 1] = { pc = pc, op = op, steps = steps }
    if #illegal_hits <= 20 then
      print(string.format("ILLEGAL @%06X op=%04X steps=%d", pc, op, steps))
    end
  elseif vector == 10 then
    line_a = line_a + 1
  elseif vector == 11 then
    line_f = line_f + 1
  end
  return orig_raise(self, vector)
end

local function report(tag)
  local elapsed = os.clock() - t0
  local ips = steps / math.max(elapsed, 1e-6)
  -- top PC buckets
  local arr = {}
  for pc, c in pairs(hist) do
    arr[#arr + 1] = { pc = pc, c = c }
  end
  table.sort(arr, function(a, b) return a.c > b.c end)
  print(string.format("--- %s steps=%d cycles=%d elapsed=%.2fs ips=%.0f ---",
    tag, steps, m.total_cycles, elapsed, ips))
  print(string.format("PC=%06X SR=%04X A7=%06X A6=%06X A5=%06X A4=%06X D0=%08X D1=%08X",
    cpu.pc, cpu.sr, cpu:get_a(7), cpu:get_a(6), cpu:get_a(5), cpu:get_a(4), cpu.d[0], cpu.d[1]))
  print(string.format("LCD base=%06X on=%s dirty=%s", m.lcd.base, tostring(m.lcd.display_on), tostring(m.lcd._dirty)))
  print(string.format("exceptions: lineA=%d lineF=%d illegal=%d", line_a, line_f, #illegal_hits))
  local exs = {}
  for v, c in pairs(exceptions) do exs[#exs + 1] = string.format("%d:%d", v, c) end
  table.sort(exs)
  print("exc_counts: " .. table.concat(exs, " "))
  print("hot PCs:")
  for i = 1, math.min(8, #arr) do
    print(string.format("  %06X x%d", arr[i].pc, arr[i].c))
  end
  -- sample LCD fb non-zero
  local nz = 0
  for i = 0, 20 * 100 - 1 do
    if (m.lcd.fb[i] or 0) ~= 0 then nz = nz + 1 end
  end
  print(string.format("lcd fb non-zero bytes: %d / %d", nz, 20 * 100))
end

-- Sample histogram periodically; run in cycle batches for speed.
local sample_every = 32
while steps < max_steps do
  local pc = cpu.pc
  if steps % sample_every == 0 then
    local bucket = band(pc, 0xFFFFF0)
    hist[bucket] = (hist[bucket] or 0) + 1
  end
  local cyc = cpu:step()
  m.bus:tick(cyc)
  m.total_cycles = m.total_cycles + cyc
  steps = steps + 1
  if ri <= #report_at and steps >= report_at[ri] then
    m.lcd:refresh_from_ram(m.ram)
    report(string.format("@%d", report_at[ri]))
    ri = ri + 1
  end
  if #illegal_hits > 500 then
    print("abort: too many illegals")
    break
  end
end
m.lcd:refresh_from_ram(m.ram)

report("final")
print("done")
