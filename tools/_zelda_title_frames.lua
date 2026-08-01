-- Dump Zelda frames around beach→title, and sample SCX-per-line via LYC chain.
local Machine = require("machines.gameboy.machine")

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

local ppu = m.ppu
local CPF = 70224

local function write_ppm(path, fb)
  local f = assert(io.open(path, "wb"))
  f:write("P6\n160 144\n255\n")
  local shades = { [0] = {155, 188, 15}, {139, 172, 15}, {48, 98, 48}, {15, 56, 15} }
  for i = 0, 160 * 144 - 1 do
    local s = shades[fb[i] or 0] or shades[0]
    f:write(string.char(s[1], s[2], s[3]))
  end
  f:close()
end

-- Also record SCX at each visible line by sampling at HBlank render time
local scx_lines = {}
local orig_render = ppu._render_line
function ppu:_render_line()
  local y = self._line
  if y < 144 then
    scx_lines[y] = self.scx
  end
  return orig_render(self)
end

print("warming 18s...")
for _ = 1, 18 * 60 do m:run_cycles(CPF) end

for sec = 18, 42 do
  for _ = 1, 60 do m:run_cycles(CPF) end
  scx_lines = {}
  m:run_cycles(CPF) -- one instrumented frame
  -- summarize unique SCX bands
  local bands, last, start = {}, nil, 0
  for y = 0, 143 do
    local s = scx_lines[y]
    if s ~= last then
      if last ~= nil then
        bands[#bands + 1] = string.format("%d-%d:%02X", start, y - 1, last)
      end
      start, last = y, s
    end
  end
  if last ~= nil then
    bands[#bands + 1] = string.format("%d-143:%02X", start, last)
  end
  local path = string.format("rom/gb/_title_t%02d.ppm", sec)
  write_ppm(path, ppu.fb)
  print(string.format("t=%02ds scy=%d lyc=%d lcdc=%02X bgp=%02X bands=%s",
    sec, ppu.scy, ppu.lyc, ppu.lcdc, ppu.bgp, table.concat(bands, " ")))
end
