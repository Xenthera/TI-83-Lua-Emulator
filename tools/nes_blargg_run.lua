-- Headless NES test-ROM runner (blargg $6000 protocol + older screen-code heuristics).
-- Usage:
--   luajit tools/nes_blargg_run.lua <rom.nes> [--frames N] [--suite path]
--   luajit tools/nes_blargg_run.lua --suite tools/nes-test-roms/instr_test-v5/rom_singles

package.path = "?.lua;?/init.lua;" .. (package.path or "")

local Machine = require("machines.nes.machine")
local bit = require("framework.util.bit")
local band = bit.band

local args = { ... }
local frames_cap = 1200 -- ~20s NTSC
local suite_dir = nil
local roms = {}

local i = 1
while i <= #args do
  local a = args[i]
  if a == "--frames" then
    i = i + 1
    frames_cap = tonumber(args[i]) or frames_cap
  elseif a == "--suite" then
    i = i + 1
    suite_dir = args[i]
  elseif a:sub(1, 1) ~= "-" then
    roms[#roms + 1] = a
  end
  i = i + 1
end

local function list_nes(dir)
  local out = {}
  local cmd
  if package.config:sub(1, 1) == "\\" then
    cmd = string.format('cmd /c "dir /b /s "%s\\*.nes""', dir:gsub("/", "\\"))
  else
    cmd = string.format('find "%s" -name "*.nes" | sort', dir)
  end
  local p = io.popen(cmd)
  if not p then return out end
  for line in p:lines() do
    line = line:gsub("\r", "")
    if line ~= "" then out[#out + 1] = line end
  end
  p:close()
  table.sort(out)
  return out
end

if suite_dir then
  for _, r in ipairs(list_nes(suite_dir)) do
    roms[#roms + 1] = r
  end
end

if #roms == 0 then
  io.stderr:write("usage: nes_blargg_run.lua <rom.nes>|--suite dir [--frames N]\n")
  os.exit(2)
end

-- Peek without CPU:read - that ticks the PPU/APU under cycle-accurate timing.
local function read8(m, addr)
  return m.cpu.bus.read(band(addr, 0xFFFF))
end

local function blargg_magic(m)
  return read8(m, 0x6001) == 0xDE
    and read8(m, 0x6002) == 0xB0
    and read8(m, 0x6003) == 0x61
end

local function blargg_text(m)
  local t = {}
  for a = 0x6004, 0x6004 + 0x1FF do
    local c = read8(m, a)
    if c == 0 then break end
    if c >= 32 and c < 127 then
      t[#t + 1] = string.char(c)
    elseif c == 10 or c == 13 then
      t[#t + 1] = "\n"
    else
      t[#t + 1] = "."
    end
  end
  return table.concat(t):gsub("%s+$", "")
end

-- Older Blargg ROMs put a result digit in nametable; crude scan for "Passed" / digit.
local function nametable_ascii(m)
  local vram = m.ppu.vram
  local chars = {}
  for i = 0, 0x3BF do
    local t = vram[i] or 0
    -- Common blargg font: tiles $00 space, ASCII-ish starting ~$10/$20 depending on CHR.
    -- Many of his tests use tiles where '0'..'9' and letters are at ASCII codepoints.
    if t >= 0x20 and t < 0x7F then
      chars[#chars + 1] = string.char(t)
    else
      chars[#chars + 1] = " "
    end
  end
  return table.concat(chars)
end

local function run_rom(path)
  local m = Machine.new()
  local ok, err = m:load_rom_file(path, { skip_save = true })
  if not ok then
    return { status = "error", msg = tostring(err) }
  end
  m:reset()

  local cpf = m:cycles_per_frame()
  local saw_magic = false
  local last_status = -1
  local reset_needed = false

  for frame = 1, frames_cap do
    m:run_cycles(cpf)

    if blargg_magic(m) then
      saw_magic = true
      local st = read8(m, 0x6000)
      if st ~= last_status then
        last_status = st
      end
      if st == 0x81 then
        -- Test requests RESET
        if not reset_needed then
          reset_needed = true
          m.cpu:power_on()
        end
      elseif st < 0x80 then
        local text = blargg_text(m)
        if st == 0 then
          return { status = "pass", code = 0, msg = text, frames = frame }
        else
          return { status = "fail", code = st, msg = text, frames = frame }
        end
      end
    end
  end

  if saw_magic then
    return {
      status = "timeout",
      code = last_status,
      msg = blargg_text(m),
      frames = frames_cap,
    }
  end

  -- Heuristic for older blargg tests: ASCII nametable ("Passed") or "$01" result.
  local nt = nametable_ascii(m)
  if nt:find("Passed") or nt:find("PASSED") then
    return { status = "pass", code = 1, msg = "nametable:Passed", frames = frames_cap, heuristic = true }
  end
  -- Many 2005-era ROMs print "$01" for pass (code 1) and "$0N" for failure.
  local code = nt:match("%$0*([0-9]+)") or nt:match("Code%s*(%d+)")
  if code then
    local n = tonumber(code)
    if n == 1 then
      return { status = "pass", code = 1, msg = "nametable:$01", frames = frames_cap, heuristic = true }
    elseif n and n > 1 then
      return {
        status = "fail",
        code = n,
        msg = "nametable:$" .. code,
        frames = frames_cap,
        heuristic = true,
      }
    end
  end
  local fail_digit = nt:match("[Ff][Aa][Ii][Ll][Ee][Dd]:?%s*#?(%d+)")
    or nt:match("FAILED:?%s*#?(%d+)")
  if fail_digit then
    return {
      status = "fail",
      code = tonumber(fail_digit),
      msg = "nametable:" .. nt:match("%S.+%S") or "fail",
      frames = frames_cap,
      heuristic = true,
    }
  end

  return {
    status = "unknown",
    msg = "no blargg $6000 magic; PC=$" .. string.format("%04X", m:pc()),
    frames = frames_cap,
    pc = m:pc(),
    sl = m.ppu.scanline,
    cy = m.ppu.cycle,
  }
end

local passed, failed, other = 0, 0, 0
local results = {}

for _, path in ipairs(roms) do
  local short = path:gsub(".*[\\/]nes%-test%-roms[\\/]", ""):gsub("\\", "/")
  io.write(string.format("RUN  %s ... ", short))
  io.flush()
  local r = run_rom(path)
  r.path = short
  results[#results + 1] = r
  if r.status == "pass" then
    passed = passed + 1
    print(string.format("PASS  (%d frames) %s", r.frames or 0, (r.msg or ""):gsub("\n", " | ")))
  elseif r.status == "fail" then
    failed = failed + 1
    print(string.format("FAIL  code=%s (%d frames)\n  %s",
      tostring(r.code), r.frames or 0, (r.msg or ""):gsub("\n", "\n  ")))
  else
    other = other + 1
    print(string.format("%s  %s", string.upper(r.status), r.msg or ""))
  end
end

print(string.format("\n== summary: %d pass, %d fail, %d other / %d ==",
  passed, failed, other, #roms))
os.exit(failed > 0 and 1 or (other > 0 and 3 or 0))
