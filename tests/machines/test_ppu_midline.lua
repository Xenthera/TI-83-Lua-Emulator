-- Mid-scanline LCDC tile-data select (bit 4): left pixels use one bank, right another.
-- Regression for demos like "Is That a Demo in Your Pocket?".

return function(ok)
  local Irq = require("machines.gameboy.hw.irq")
  local Ppu = require("machines.gameboy.hw.ppu")

  local irq = Irq.new()
  local ppu = Ppu.new(irq)
  ppu.lcdc = 0x91 -- LCD on, BG on, unsigned tile data ($8000)
  ppu.bgp = 0xE4 -- 0,1,2,3 identity-ish
  ppu.scy, ppu.scx = 0, 0
  ppu.wy, ppu.wx = 0, 0
  ppu._line = 0
  ppu.ly = 0
  ppu.line_cycles = 0
  ppu.mode = 2
  ppu._wy_triggered = true

  -- Tile map $9800: all tile id 0.
  for i = 0, 31 do
    ppu.vram[0x1800 + i] = 0
  end

  -- Unsigned tile 0 at $8000: solid color 3 (both bitplanes 0xFF).
  for r = 0, 7 do
    ppu.vram[r * 2] = 0xFF
    ppu.vram[r * 2 + 1] = 0xFF
  end

  -- Signed tile 0 at $9000 (0x1000 in VRAM index): solid color 1 (lo=0xFF, hi=0).
  for r = 0, 7 do
    ppu.vram[0x1000 + r * 2] = 0xFF
    ppu.vram[0x1000 + r * 2 + 1] = 0x00
  end

  -- Enter Mode 3 and paint the left half with unsigned tiles (color 3).
  ppu.line_cycles = 80
  ppu:_set_mode(3)
  ppu.line_cycles = 80 + 12 + 80 -- 80 pixels due
  ppu:_sync_mode3_paint()
  ok("midline painted left pixels", ppu._px == 80)
  ok("left uses unsigned tile (shade 3)", ppu._linebuf[0] == 3)
  ok("left mid uses unsigned tile", ppu._linebuf[40] == 3)

  -- Flip LCDC bit 4 -> signed addressing ($8800/$9000). Remaining pixels differ.
  ppu.lcdc = 0x81 -- LCD on, BG on, signed tile data
  ppu.line_cycles = 80 + 12 + 160
  ppu:_sync_mode3_paint()
  ok("midline painted full width", ppu._px == 160)
  ok("right uses signed tile (shade 1)", ppu._linebuf[120] == 1)
  ok("left half unchanged after LCDC flip", ppu._linebuf[10] == 3)

  -- Finish line and confirm framebuffer.
  ppu:_finish_line()
  ok("fb left shade 3", ppu.fb[10] == 3)
  ok("fb right shade 1", ppu.fb[120] == 1)

  -- Tick-interleaved path: mid-line LCDC write via write_io flushes paint.
  local p2 = Ppu.new(Irq.new())
  p2.lcdc = 0x91
  p2.bgp = 0xE4
  p2._wy_triggered = false
  for i = 0, 31 do p2.vram[0x1800 + i] = 0 end
  for r = 0, 7 do
    p2.vram[r * 2] = 0xFF
    p2.vram[r * 2 + 1] = 0xFF
    p2.vram[0x1000 + r * 2] = 0xFF
    p2.vram[0x1000 + r * 2 + 1] = 0x00
  end
  -- Advance through OAM (80) + warmup (12) + 40 pixels of Mode 3 time.
  p2:tick(80 + 12 + 40)
  -- Lazy paint: pixels appear when LCDC is written (or line finishes).
  p2:write_io(0xFF40, 0x81) -- flip to signed; flushes left pixels first
  ok("tick path flushed left px", p2._px >= 40)
  local left_shade = p2._linebuf[0]
  ok("tick path left shade after flush", left_shade == 3)
  p2:tick(200) -- rest of mode 3 + hblank
  ok("tick path left kept unsigned shade", p2.fb[0] == left_shade)
  ok("tick path right uses signed shade", p2.fb[100] == 1)
end
