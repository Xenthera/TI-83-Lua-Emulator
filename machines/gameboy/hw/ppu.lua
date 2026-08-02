-- DMG PPU: scanline modes, BG/window/sprites, 160x144 framebuffer (shade 0-3).
-- Mode 3 paints pixels progressively so mid-scanline LCDC / scroll / WX writes
-- take effect (needed by demos like "Is That a Demo in Your Pocket?").

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local Ppu = {}
Ppu.__index = Ppu

Ppu.WIDTH = 160
Ppu.HEIGHT = 144

local MODE_HBLANK, MODE_VBLANK, MODE_OAM, MODE_VRAM = 0, 1, 2, 3
local CYCLES_OAM, CYCLES_VRAM = 80, 172 -- then HBlank to 456
local CYCLES_LINE = 456
local LY153_QUIRK = 4 -- LY reads as 0 after this many T-cycles on line 153
-- First BG pixel is pushed after fetcher warmup (~12 dots into mode 3).
local MODE3_PIXEL0 = CYCLES_OAM + 12

function Ppu.new(irq)
  local self = setmetatable({
    irq = irq,
    vram = {},
    oam = {},
    lcdc = 0x91,
    stat = 0x85,
    scy = 0, scx = 0,
    ly = 0, -- value visible at FF44 (may differ from _line on 153)
    _line = 0, -- true scanline 0..153
    lyc = 0,
    bgp = 0xFC,
    obp0 = 0xFF, obp1 = 0xFF,
    wy = 0, wx = 0,
    mode = MODE_OAM,
    line_cycles = 0,
    window_line = 0,
    line_rendered = false,
    fb = {},
    _linebuf = {},
    _bg_pri = {},
    _dirty = true,
    frame_ready = false,
    _stat_irq_line = false,
    _wy_triggered = false,
    _px = 0,
    _scx_delay = 0,
    _sprites = nil,
    _win_on_line = false,
    _mode3_started = false,
  }, Ppu)
  self:reset()
  return self
end

function Ppu:reset()
  for i = 0, 0x1FFF do self.vram[i] = 0 end
  for i = 0, 0x9F do self.oam[i] = 0 end
  self.lcdc = 0x91
  self.stat = 0x85
  self.scy, self.scx = 0, 0
  self.ly, self._line, self.lyc = 0, 0, 0
  self.bgp = 0xFC
  self.obp0, self.obp1 = 0xFF, 0xFF
  self.wy, self.wx = 0, 0
  self.mode = MODE_OAM
  self.line_cycles = 0
  self.window_line = 0
  self.line_rendered = false
  for i = 0, Ppu.WIDTH * Ppu.HEIGHT - 1 do self.fb[i] = 0 end
  self._dirty = true
  self.frame_ready = false
  self._stat_irq_line = false
  self._wy_triggered = false
  self._px = 0
  self._scx_delay = 0
  self._sprites = nil
  self._win_on_line = false
  self._mode3_started = false
end

function Ppu:lcd_on()
  return band(self.lcdc, 0x80) ~= 0
end

function Ppu:read_vram(addr)
  return self.vram[addr - 0x8000] or 0
end

function Ppu:write_vram(addr, v)
  if self:lcd_on() and self.mode == MODE_VRAM then return end
  self.vram[addr - 0x8000] = v % 256
end

function Ppu:read_oam(addr)
  if self:lcd_on() and (self.mode == MODE_OAM or self.mode == MODE_VRAM) then
    return 0xFF
  end
  return self.oam[addr - 0xFE00] or 0
end

function Ppu:write_oam(addr, v)
  if self:lcd_on() and (self.mode == MODE_OAM or self.mode == MODE_VRAM) then
    return
  end
  self.oam[addr - 0xFE00] = v % 256
end

function Ppu:read_io(reg)
  if reg == 0xFF40 then return self.lcdc
  elseif reg == 0xFF41 then
    local v = band(self.stat, 0xFC)
    v = bor(v, band(self.mode, 3))
    if self.ly == self.lyc then v = bor(v, 4) end
    return v
  elseif reg == 0xFF42 then return self.scy
  elseif reg == 0xFF43 then return self.scx
  elseif reg == 0xFF44 then return self.ly
  elseif reg == 0xFF45 then return self.lyc
  elseif reg == 0xFF47 then return self.bgp
  elseif reg == 0xFF48 then return self.obp0
  elseif reg == 0xFF49 then return self.obp1
  elseif reg == 0xFF4A then return self.wy
  elseif reg == 0xFF4B then return self.wx
  end
  return 0xFF
end

--- Flush progressive Mode-3 pixels before a mid-line visual register change.
function Ppu:_flush_mode3_before_mutate()
  if self._line < 144 and not self.line_rendered and self.line_cycles >= CYCLES_OAM then
    self:_sync_mode3_paint()
  end
end

function Ppu:write_io(reg, v)
  v = v % 256
  if reg == 0xFF40 then
    self:_flush_mode3_before_mutate()
    local was = self:lcd_on()
    self.lcdc = v
    if was and not self:lcd_on() then
      self.ly, self._line = 0, 0
      self.line_cycles = 0
      self.mode = MODE_HBLANK
      self.window_line = 0
      self.line_rendered = false
      self._stat_irq_line = false
      self._wy_triggered = false
      self._px = 0
      self._mode3_started = false
      self._sprite_count = 0
    elseif (not was) and self:lcd_on() then
      -- LCD enable is phase-locked so the enabling write's M-cycle counts, and
      -- LY advances between Blargg delay 109 and 110 (oam_bug/1-lcd_sync).
      self.ly, self._line = 0, 0
      self.line_cycles = 4
      self.mode = MODE_OAM
      self.line_rendered = false
      self._wy_triggered = (self.wy == 0)
      self._px = 0
      self._mode3_started = false
      self._sprite_count = 0
      self:_update_stat_irq()
    end
  elseif reg == 0xFF41 then
    self.stat = bor(band(v, 0x78), band(self.stat, 0x07))
    self:_update_stat_irq()
  elseif reg == 0xFF42 then
    self:_flush_mode3_before_mutate()
    self.scy = v
  elseif reg == 0xFF43 then
    self:_flush_mode3_before_mutate()
    self.scx = v
  elseif reg == 0xFF44 then -- LY read-only
  elseif reg == 0xFF45 then
    self.lyc = v
    self:_update_stat_irq()
  elseif reg == 0xFF46 then
    -- DMA handled by MMU
  elseif reg == 0xFF47 then
    self:_flush_mode3_before_mutate()
    self.bgp = v
  elseif reg == 0xFF48 then self.obp0 = v
  elseif reg == 0xFF49 then self.obp1 = v
  elseif reg == 0xFF4A then
    self:_flush_mode3_before_mutate()
    self.wy = v
  elseif reg == 0xFF4B then
    self:_flush_mode3_before_mutate()
    self.wx = v
  end
end

function Ppu:_set_mode(mode)
  if self.mode == mode then return end
  self.mode = mode
  self:_update_stat_irq()
end

function Ppu:_stat_condition()
  local stat = self.stat
  if band(stat, 0x40) ~= 0 and self.ly == self.lyc then return true end
  if band(stat, 0x08) ~= 0 and self.mode == MODE_HBLANK then return true end
  if band(stat, 0x10) ~= 0 and self.mode == MODE_VBLANK then return true end
  if band(stat, 0x20) ~= 0 and self.mode == MODE_OAM then return true end
  return false
end

function Ppu:_update_stat_irq()
  local cond = self:_stat_condition()
  if cond and not self._stat_irq_line then
    self.irq:request(0x02)
  end
  self._stat_irq_line = cond
end

local function palette4(pal)
  return {
    [0] = band(pal, 3),
    band(rshift(pal, 2), 3),
    band(rshift(pal, 4), 3),
    band(rshift(pal, 6), 3),
  }
end

--- OAM scan at Mode 3 entry (end of Mode 2). Max 10 sprites / line.
-- Reuses a fixed sprite slot table to avoid per-line allocations.
function Ppu:_scan_sprites()
  local y = self._line
  local tall = band(self.lcdc, 0x04) ~= 0
  local h = tall and 16 or 8
  local oam = self.oam
  local slots = self._sprite_slots
  if not slots then
    slots = {}
    for i = 1, 10 do
      slots[i] = { sx = 0, sy = 0, tile = 0, attr = 0, i = 0 }
    end
    self._sprite_slots = slots
  end
  local n = 0
  for i = 0, 39 do
    local base = i * 4
    local sy = (oam[base] or 0) - 16
    if y >= sy and y < sy + h then
      n = n + 1
      local sp = slots[n]
      sp.sx = (oam[base + 1] or 0) - 8
      sp.sy = sy
      sp.tile = oam[base + 2] or 0
      sp.attr = oam[base + 3] or 0
      sp.i = i
      if n >= 10 then break end
    end
  end
  self._sprite_count = n
  -- Insertion sort by X then OAM index (n ≤ 10).
  for i = 2, n do
    local key = slots[i]
    local j = i - 1
    while j >= 1 do
      local s = slots[j]
      if s.sx < key.sx or (s.sx == key.sx and s.i < key.i) then break end
      slots[j + 1] = s
      j = j - 1
    end
    slots[j + 1] = key
  end
  self._sprites = slots
end

function Ppu:_begin_mode3()
  if self._mode3_started then return end
  self._mode3_started = true
  self._px = 0
  self._win_on_line = false
  self._scx_delay = band(self.scx, 7)
  -- No linebuf clear: every pixel 0..159 is written before sprite composite.
  self:_scan_sprites()
end

--- How many BG/window pixels should be visible given current line_cycles.
function Ppu:_mode3_pixels_due()
  local c = self.line_cycles - MODE3_PIXEL0 - (self._scx_delay or 0)
  if c < 0 then return 0 end
  if c > 160 then return 160 end
  return c
end

--- Paint BG/window pixels x ∈ [_px, x_end) with live LCDC/scroll/WX/BGP.
-- Hot path: tile-row cache + inlined pixel extract (Zelda-class titles).
function Ppu:_render_pixels_to(x_end)
  if x_end > 160 then x_end = 160 end
  local x = self._px
  if x >= x_end then return end

  local y = self._line
  local vram = self.vram
  local line = self._linebuf
  local bg_pri = self._bg_pri
  local scy = self.scy
  local wx_reg, wy_trig = self.wx, self._wy_triggered
  local win_line = self.window_line
  local win_on = false

  local pal = self.bgp
  local lut = {
    [0] = band(pal, 3),
    band(rshift(pal, 2), 3),
    band(rshift(pal, 4), 3),
    band(rshift(pal, 6), 3),
  }

  -- Tile-row cache (invalidated when map cell / addressing mode changes).
  local cache_key = -1
  local lo, hi = 0, 0

  while x < x_end do
    local lcdc = self.lcdc
    -- Live BGP (mid-line palette writes are rare but cheap to re-latch).
    if self.bgp ~= pal then
      pal = self.bgp
      lut[0] = band(pal, 3)
      lut[1] = band(rshift(pal, 2), 3)
      lut[2] = band(rshift(pal, 4), 3)
      lut[3] = band(rshift(pal, 6), 3)
    end

    if band(lcdc, 0x01) == 0 then
      line[x] = lut[0]
      bg_pri[x] = false
      cache_key = -1
      x = x + 1
    else
      local signed = band(lcdc, 0x10) == 0
      local use_win = false
      if band(lcdc, 0x20) ~= 0 and wy_trig and wx_reg <= 166 then
        if x >= (wx_reg - 7) then use_win = true end
      end

      local sx_bit, map_index, row
      if use_win then
        win_on = true
        local map = band(lcdc, 0x40) ~= 0 and 0x1C00 or 0x1800
        local wx = x - (wx_reg - 7)
        if wx < 0 then wx = 0 end
        map_index = map + rshift(win_line, 3) * 32 + rshift(wx, 3)
        row = band(win_line, 7) * 2
        sx_bit = band(wx, 7)
      else
        local map = band(lcdc, 0x08) ~= 0 and 0x1C00 or 0x1800
        local sy = band(y + scy, 0xFF)
        -- scx may change mid-line; re-read each pixel.
        local sx = band(x + self.scx, 0xFF)
        map_index = map + rshift(sy, 3) * 32 + rshift(sx, 3)
        row = band(sy, 7) * 2
        sx_bit = band(sx, 7)
      end

      local key = map_index * 32 + row + (signed and 16 or 0)
      if key ~= cache_key then
        cache_key = key
        local tile = vram[map_index] or 0
        local addr
        if not signed then
          addr = tile * 16 + row
        elseif tile >= 128 then
          addr = 0x1000 + (tile - 256) * 16 + row
        else
          addr = 0x1000 + tile * 16 + row
        end
        lo = vram[addr] or 0
        hi = vram[addr + 1] or 0
      end

      local bitn = 7 - sx_bit
      local c = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
      line[x] = lut[c]
      bg_pri[x] = c ~= 0
      x = x + 1
    end
  end

  if win_on then self._win_on_line = true end
  self._px = x
end

function Ppu:_composite_sprites()
  if band(self.lcdc, 0x02) == 0 then return end
  local y = self._line
  local tall = band(self.lcdc, 0x04) ~= 0
  local h = tall and 16 or 8
  local vram = self.vram
  local line = self._linebuf
  local bg_pri = self._bg_pri
  local sprites = self._sprites
  local n = self._sprite_count or (sprites and #sprites) or 0
  if n == 0 or not sprites then return end
  -- Draw back-to-front so earlier OAM / lower X ends on top (DMG priority).
  for si = n, 1, -1 do
    local sp = sprites[si]
    local row = y - sp.sy
    local attr = sp.attr
    if band(attr, 0x40) ~= 0 then row = h - 1 - row end
    local tile = sp.tile
    if tall then
      tile = band(tile, 0xFE)
      if row >= 8 then
        tile = bor(tile, 1)
        row = row - 8
      end
    end
    local addr = tile * 16 + row * 2
    local lo = vram[addr] or 0
    local hi = vram[addr + 1] or 0
    local pal = palette4(band(attr, 0x10) ~= 0 and self.obp1 or self.obp0)
    local behind = band(attr, 0x80) ~= 0
    local flip = band(attr, 0x20) ~= 0
    local sx = sp.sx
    for px = 0, 7 do
      local x = sx + px
      if x >= 0 and x < 160 then
        local bitn = flip and px or (7 - px)
        local c = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
        if c ~= 0 and not (behind and bg_pri[x]) then
          line[x] = pal[c]
        end
      end
    end
  end
end

function Ppu:_finish_line()
  local y = self._line
  if y >= 144 or self.line_rendered then return end
  self:_begin_mode3()
  self:_render_pixels_to(160)
  self:_composite_sprites()
  if self._win_on_line then
    self.window_line = self.window_line + 1
  end
  local fb = self.fb
  local base = y * 160
  local line = self._linebuf
  for x = 0, 159 do
    fb[base + x] = line[x]
  end
  self.line_rendered = true
  self._dirty = true
end

--- Advance progressive Mode-3 paint to match current line_cycles.
function Ppu:_sync_mode3_paint()
  local y = self._line
  if y >= 144 or self.line_rendered then return end
  if self.line_cycles < CYCLES_OAM then return end
  self:_begin_mode3()
  local due = self:_mode3_pixels_due()
  if self.line_cycles >= CYCLES_OAM + CYCLES_VRAM then
    due = 160
  end
  if due > self._px then
    self:_render_pixels_to(due)
  end
end

function Ppu:_enter_line(new_line)
  self._line = new_line
  self.line_rendered = false
  self._px = 0
  self._mode3_started = false
  self._sprites = nil
  self._sprite_count = 0
  self._win_on_line = false
  if new_line == 144 then
    self.ly = 144
    self.irq:request(0x01)
    -- DMG quirk: VBlank entry also pulses mode-2 STAT.
    self.mode = MODE_OAM
    self:_update_stat_irq()
    self:_set_mode(MODE_VBLANK)
    self.frame_ready = true
    self._dirty = true
  elseif new_line == 153 then
    -- LY reads as 153 for 4 T-cycles, then 0 for the rest of the line.
    self.ly = 153
    self:_set_mode(MODE_VBLANK)
  elseif new_line > 153 then
    self.ly = 0
    self.window_line = 0
    self._wy_triggered = false
    self._line = 0
    self:_set_mode(MODE_OAM)
  elseif new_line == 0 then
    -- Coming from line 153: LY already reads 0; keep it. Reset window.
    self.ly = 0
    self.window_line = 0
    self._wy_triggered = (self.wy == 0)
    self:_set_mode(MODE_OAM)
  else
    self.ly = new_line
    if new_line < 144 then
      if self.wy == new_line then
        self._wy_triggered = true
      end
      self:_set_mode(MODE_OAM)
    else
      self:_set_mode(MODE_VBLANK)
    end
  end
  self:_update_stat_irq()
end

function Ppu:tick(cycles)
  if band(self.lcdc, 0x80) == 0 then return end
  local left = cycles
  local line_cyc = self.line_cycles
  local line = self._line
  local hblank_at = CYCLES_OAM + CYCLES_VRAM

  while left > 0 do
    local into = line_cyc
    local boundary = CYCLES_LINE
    if line < 144 then
      if into < CYCLES_OAM then
        boundary = CYCLES_OAM
      elseif into < hblank_at then
        boundary = hblank_at
      end
    elseif line == 153 and into < LY153_QUIRK then
      boundary = LY153_QUIRK
    end

    local step = left
    local remain = boundary - into
    if remain <= 0 then remain = CYCLES_LINE - into end
    if step > remain then step = remain end
    if step < 1 then step = 1 end

    local mode
    if line >= 144 then
      mode = MODE_VBLANK
    elseif into < CYCLES_OAM then
      mode = MODE_OAM
    elseif into < hblank_at then
      mode = MODE_VRAM
    else
      mode = MODE_HBLANK
    end

    if mode ~= self.mode then
      self:_set_mode(mode)
    end

    line_cyc = line_cyc + step
    left = left - step
    self.line_cycles = line_cyc

    -- Mode-3 pixels are painted lazily: on mid-line register writes (see
    -- write_io) or when the line finishes. Avoids per-M-cycle paint cost.

    if mode == MODE_HBLANK or (line < 144 and line_cyc >= hblank_at) then
      if line < 144 and not self.line_rendered then
        self:_finish_line()
      end
    end

    -- LY=153 quirk: after 4 T-cycles, LY reads as 0 (LYC=0 can fire here in VBlank).
    if line == 153 and self.ly == 153 and line_cyc >= LY153_QUIRK then
      self.ly = 0
      self:_update_stat_irq()
    end

    if line_cyc >= CYCLES_LINE then
      if line < 144 and not self.line_rendered then
        self:_finish_line()
      end
      line_cyc = line_cyc - CYCLES_LINE
      self.line_cycles = line_cyc

      if line >= 153 then
        self:_enter_line(0)
        line = 0
      else
        line = line + 1
        self:_enter_line(line)
      end
    end
  end

  self.line_cycles = line_cyc
  self._line = line
end

function Ppu:framebuffer()
  return self.fb
end

return Ppu
