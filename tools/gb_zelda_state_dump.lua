-- Dump Zelda LA machine state around beach->title corruption.
-- No fixes; diagnostic only.

local Machine = require("machines.gameboy.machine")
local bit = require("framework.util.bit")
local band = bit.band

local ROM = "rom/gb/Legend of Zelda, The - Link's Awakening (U) (V1.2) [!].gb"
local OUT = "rom/gb/tests/out/zelda"
local CPF = 70224

local function ensure_dir(path)
  os.execute('mkdir "' .. path:gsub("/", "\\") .. '" 2>nul')
end
ensure_dir(OUT)

local function write_ppm(path, fb)
  local f = assert(io.open(path, "wb"))
  f:write("P6\n160 144\n255\n")
  local shades = {
    [0] = string.char(155, 188, 15),
    [1] = string.char(139, 172, 15),
    [2] = string.char(48, 98, 48),
    [3] = string.char(15, 56, 15),
  }
  for i = 0, 160 * 144 - 1 do
    f:write(shades[fb[i] or 0] or shades[0])
  end
  f:close()
end

local function dump_bin(path, bytes_fn, n)
  local f = assert(io.open(path, "wb"))
  for i = 0, n - 1 do f:write(string.char(bytes_fn(i))) end
  f:close()
end

local function sha_like(bytes_fn, n)
  local h = 2166136261
  for i = 0, n - 1 do
    h = band((h * 16777619) + bytes_fn(i), 0xFFFFFFFF)
  end
  return string.format("%08X", h)
end

local function snapshot(m, tag, frame)
  local ppu, cart, irq, mmu = m.ppu, m.cart, m.irq, m.mmu
  local path = string.format("%s/%s", OUT, tag)
  ensure_dir(path)
  write_ppm(path .. "/fb.ppm", ppu.fb)
  dump_bin(path .. "/vram.bin", function(i) return ppu.vram[i] or 0 end, 0x2000)
  dump_bin(path .. "/map9800.bin", function(i) return ppu.vram[0x1800 + i] or 0 end, 0x400)
  dump_bin(path .. "/map9C00.bin", function(i) return ppu.vram[0x1C00 + i] or 0 end, 0x400)
  dump_bin(path .. "/oam.bin", function(i) return ppu.oam[i] or 0 end, 0xA0)

  -- SCX bands for one frame
  local scx_lines = {}
  local orig = ppu._render_line
  function ppu:_render_line()
    if self._line < 144 then scx_lines[self._line] = self.scx end
    return orig(self)
  end
  m:run_cycles(CPF)
  ppu._render_line = orig

  local bands, last, start = {}, nil, 0
  for y = 0, 143 do
    local s = scx_lines[y]
    if s ~= last then
      if last ~= nil then bands[#bands + 1] = string.format("%d-%d:%02X", start, y - 1, last) end
      start, last = y, s
    end
  end
  if last ~= nil then bands[#bands + 1] = string.format("%d-143:%02X", start, last) end

  local f = assert(io.open(path .. "/regs.txt", "w"))
  f:write(string.format("frame=%d tag=%s\n", frame, tag))
  f:write(string.format("LCDC=%02X STAT=%02X SCY=%02X SCX=%02X LY=%02X LYC=%02X\n",
    ppu.lcdc, ppu.stat, ppu.scy, ppu.scx, ppu.ly, ppu.lyc))
  f:write(string.format("BGP=%02X OBP0=%02X OBP1=%02X WY=%02X WX=%02X\n",
    ppu.bgp, ppu.obp0, ppu.obp1, ppu.wy, ppu.wx))
  f:write(string.format("mode=%d line_cycles=%d _line=%d\n", ppu.mode, ppu.line_cycles, ppu._line))
  f:write(string.format("IE=%02X IF=%02X IME=%s\n", irq.ie, irq.iff, tostring(m.cpu.ime)))
  f:write(string.format("rom_bank=%s ram_bank=%s mbc=%s mode=%s\n",
    tostring(cart.rom_bank), tostring(cart.ram_bank), tostring(cart.mbc), tostring(cart.mode)))
  f:write(string.format("PC=%04X SP=%04X\n", m.cpu.pc, m.cpu.sp))
  f:write(string.format("LCDC.4 tile unsigned=%s  LCDC.3 map9C00=%s  LCDC.0 bg=%s  LCDC.5 win=%s  LCDC.1 obj=%s\n",
    tostring(band(ppu.lcdc, 0x10) ~= 0),
    tostring(band(ppu.lcdc, 0x08) ~= 0),
    tostring(band(ppu.lcdc, 0x01) ~= 0),
    tostring(band(ppu.lcdc, 0x20) ~= 0),
    tostring(band(ppu.lcdc, 0x02) ~= 0)))
  f:write(string.format("vram_hash=%s map9800_hash=%s map9C00_hash=%s oam_hash=%s fb_hash=%s\n",
    sha_like(function(i) return ppu.vram[i] or 0 end, 0x2000),
    sha_like(function(i) return ppu.vram[0x1800 + i] or 0 end, 0x400),
    sha_like(function(i) return ppu.vram[0x1C00 + i] or 0 end, 0x400),
    sha_like(function(i) return ppu.oam[i] or 0 end, 0xA0),
    sha_like(function(i) return ppu.fb[i] or 0 end, 160 * 144)))
  f:write("scx_bands=" .. table.concat(bands, " ") .. "\n")
  f:close()

  print(string.format("snap %s frame=%d scx=%02X lyc=%02X ie=%02X bands=%s",
    tag, frame, ppu.scx, ppu.lyc, irq.ie, table.concat(bands, " ")))
  return {
    vram = sha_like(function(i) return ppu.vram[i] or 0 end, 0x2000),
    lcdc = ppu.lcdc, scx = ppu.scx, scy = ppu.scy, lyc = ppu.lyc, ie = irq.ie,
    bank = cart.rom_bank, bands = table.concat(bands, " "),
  }
end

local m = Machine.new()
assert(m:load_rom_file(ROM))
m:reset()

-- Track SCX band activity + IE
local frame = 0
local function advance(n)
  for _ = 1, n do
    m:run_cycles(CPF)
    frame = frame + 1
  end
end

print("warming to 18s (beach)...")
advance(18 * 60)
local s_beach = snapshot(m, "01_beach", frame)

print("to 23s (title appearing)...")
advance(5 * 60)
local s_title = snapshot(m, "02_title_wave", frame)

print("to 38s (wave still running)...")
advance(15 * 60)
local s_wave = snapshot(m, "03_title_wave_late", frame)

-- Step frame-by-frame until LYC chain dies (SCX flat + IE loses STAT)
print("hunting freeze...")
local s_pre, s_post
for i = 1, 180 do
  local ie_before = m.irq.ie
  local scx_before = m.ppu.scx
  m:run_cycles(CPF)
  frame = frame + 1
  if band(ie_before, 0x02) ~= 0 and band(m.irq.ie, 0x02) == 0 then
    print(string.format("IE STAT cleared at frame %d scx %02X->%02X lyc=%02X pc=%04X",
      frame, scx_before, m.ppu.scx, m.ppu.lyc, m.cpu.pc))
    s_post = snapshot(m, "05_post_ie_clear", frame)
    break
  end
  if i == 1 then s_pre = snapshot(m, "04_pre_hunt", frame) end
end

local cmp = assert(io.open(OUT .. "/compare.txt", "w"))
cmp:write("Zelda LA beach->title state comparison\n\n")
local function write_s(label, s)
  if not s then cmp:write(label .. ": (missing)\n"); return end
  cmp:write(string.format("%s: lcdc=%02X scx=%02X scy=%02X lyc=%02X ie=%02X bank=%s vram=%s\n  bands=%s\n",
    label, s.lcdc, s.scx, s.scy, s.lyc, s.ie, tostring(s.bank), s.vram, s.bands))
end
write_s("beach", s_beach)
write_s("title_wave", s_title)
write_s("wave_late", s_wave)
write_s("pre_hunt", s_pre)
write_s("post_ie_clear", s_post)
cmp:write("\nInterpretation guide:\n")
cmp:write("1) If vram hash changes across wave->freeze while LCDC tile mode stable -> graphics load / banking / CPU path\n")
cmp:write("2) If vram hash identical but scx bands collapse -> STAT/LYC/IE timing (render inputs wrong)\n")
cmp:write("3) If LCDC.4 flips unexpectedly -> tile addressing mode bug or game state corruption\n")
cmp:close()
print("wrote " .. OUT .. "/compare.txt")
