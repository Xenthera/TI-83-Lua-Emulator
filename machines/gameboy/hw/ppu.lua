-- DMG PPU: scanline modes, BG/window/sprites, 160x144 framebuffer (shade 0-3).

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

function Ppu:write_io(reg, v)
  v = v % 256
  if reg == 0xFF40 then
    local was = self:lcd_on()
    self.lcdc = v
    if was and not self:lcd_on() then
      self.ly, self._line = 0, 0
      self.line_cycles = 0
      self.mode = MODE_HBLANK
      self.window_line = 0
      self.line_rendered = false
      self._stat_irq_line = false
    elseif (not was) and self:lcd_on() then
      -- LCD enable is phase-locked so the enabling write's M-cycle counts, and
      -- LY advances between Blargg delay 109 and 110 (oam_bug/1-lcd_sync).
      -- Access-then-tick: start at 4, write adds 4 → line_cycles=8 at instr end;
      -- LY read after delay 109 still sees 0, after delay 110 sees 1.
      self.ly, self._line = 0, 0
      self.line_cycles = 4
      self.mode = MODE_OAM
      self.line_rendered = false
      self:_update_stat_irq()
    end
  elseif reg == 0xFF41 then
    self.stat = bor(band(v, 0x78), band(self.stat, 0x07))
    self:_update_stat_irq()
  elseif reg == 0xFF42 then self.scy = v
  elseif reg == 0xFF43 then self.scx = v
  elseif reg == 0xFF44 then -- LY read-only
  elseif reg == 0xFF45 then
    self.lyc = v
    self:_update_stat_irq()
  elseif reg == 0xFF46 then
    -- DMA handled by MMU
  elseif reg == 0xFF47 then self.bgp = v
  elseif reg == 0xFF48 then self.obp0 = v
  elseif reg == 0xFF49 then self.obp1 = v
  elseif reg == 0xFF4A then self.wy = v
  elseif reg == 0xFF4B then self.wx = v
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

local function tile_data_addr(signed, tile_id)
  if not signed then
    return tile_id * 16
  end
  if tile_id >= 128 then
    return 0x1000 + (tile_id - 256) * 16
  end
  return 0x1000 + tile_id * 16
end

local function blit_tile_row(line, bg_pri, x, px, lo, hi, pal)
  while x < 160 and px < 8 do
    local bitn = 7 - px
    local c = bor(band(rshift(lo, bitn), 1), lshift(band(rshift(hi, bitn), 1), 1))
    line[x] = pal[c]
    bg_pri[x] = c ~= 0
    x = x + 1
    px = px + 1
  end
  return x
end

function Ppu:_render_line()
  local y = self._line
  if y >= 144 then return end
  local line = self._linebuf
  local bg_pri = self._bg_pri
  local vram = self.vram
  local lcdc = self.lcdc
  for x = 0, 159 do
    line[x] = 0
    bg_pri[x] = false
  end

  local signed = band(lcdc, 0x10) == 0
  local bgp_lut = palette4(self.bgp)

  if band(lcdc, 0x01) ~= 0 then
    local map = band(lcdc, 0x08) ~= 0 and 0x1C00 or 0x1800
    local sy = band(y + self.scy, 0xFF)
    local map_row = map + rshift(sy, 3) * 32
    local row = band(sy, 7) * 2
    local scx = self.scx
    local x = 0
    while x < 160 do
      local sx = band(x + scx, 0xFF)
      local px = band(sx, 7)
      local tile = vram[map_row + rshift(sx, 3)] or 0
      local addr = tile_data_addr(signed, tile) + row
      local lo = vram[addr] or 0
      local hi = vram[addr + 1] or 0
      x = blit_tile_row(line, bg_pri, x, px, lo, hi, bgp_lut)
    end
  end

  if band(lcdc, 0x20) ~= 0 and band(lcdc, 0x01) ~= 0
      and self.wy <= y and self.wx <= 166 then
    local map = band(lcdc, 0x40) ~= 0 and 0x1C00 or 0x1800
    local wy = self.window_line
    local map_row = map + rshift(wy, 3) * 32
    local row = band(wy, 7) * 2
    local wx0 = self.wx - 7
    local started = false
    local x = 0
    if wx0 > 0 then x = wx0 end
    if x < 0 then x = 0 end
    while x < 160 do
      local wx = x - wx0
      if wx >= 0 then
        started = true
        local px = band(wx, 7)
        local tile = vram[map_row + rshift(wx, 3)] or 0
        local addr = tile_data_addr(signed, tile) + row
        local lo = vram[addr] or 0
        local hi = vram[addr + 1] or 0
        x = blit_tile_row(line, bg_pri, x, px, lo, hi, bgp_lut)
      else
        x = x + 1
      end
    end
    if started then
      self.window_line = self.window_line + 1
    end
  end

  if band(lcdc, 0x02) ~= 0 then
    local tall = band(lcdc, 0x04) ~= 0
    local h = tall and 16 or 8
    local oam = self.oam
    local sprites = {}
    for i = 0, 39 do
      local base = i * 4
      local sy = (oam[base] or 0) - 16
      if y >= sy and y < sy + h then
        sprites[#sprites + 1] = {
          sx = (oam[base + 1] or 0) - 8,
          sy = sy,
          tile = oam[base + 2] or 0,
          attr = oam[base + 3] or 0,
          i = i,
        }
        if #sprites >= 10 then break end
      end
    end
    table.sort(sprites, function(a, b)
      if a.sx ~= b.sx then return a.sx > b.sx end
      return a.i > b.i
    end)
    for si = 1, #sprites do
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
          local col = flip and (7 - px) or px
          local bitn = 7 - col
          local c = bor(band(rshift(lo, bitn), 1), lshift(band(rshift(hi, bitn), 1), 1))
          if c ~= 0 and not (behind and bg_pri[x]) then
            line[x] = pal[c]
          end
        end
      end
    end
  end

  local fb = self.fb
  local base = y * 160
  for x = 0, 159 do
    fb[base + x] = line[x]
  end
  self._dirty = true
end

function Ppu:_enter_line(new_line)
  self._line = new_line
  self.line_rendered = false
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
    -- Should not be called with >153; wrap handled by caller.
    self.ly = 0
    self.window_line = 0
    self._line = 0
    self:_set_mode(MODE_OAM)
  elseif new_line == 0 then
    -- Coming from line 153: LY already reads 0; keep it. Reset window.
    self.ly = 0
    self.window_line = 0
    self:_set_mode(MODE_OAM)
  else
    self.ly = new_line
    if new_line < 144 then
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
      -- Hit the LY=153→0 quirk boundary.
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

    if mode == MODE_HBLANK and line < 144 and not self.line_rendered then
      self:_render_line()
      self.line_rendered = true
    end

    line_cyc = line_cyc + step
    left = left - step

    -- LY=153 quirk: after 4 T-cycles, LY reads as 0 (LYC=0 can fire here in VBlank).
    if line == 153 and self.ly == 153 and line_cyc >= LY153_QUIRK then
      self.ly = 0
      self:_update_stat_irq()
    end

    if line_cyc >= CYCLES_LINE then
      if line < 144 and not self.line_rendered then
        self:_render_line()
        self.line_rendered = true
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
