-- NES PPU (NTSC): scanline BG + sprites, loopy scroll, NMI on vblank.
-- Framebuffer: 256x240 palette indices (0-63).

local bit = require("framework.util.bit")
local band, bor, bxor, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.lshift, bit.rshift

local Ppu = {}
Ppu.__index = Ppu
Ppu.WIDTH = 256
Ppu.HEIGHT = 240
Ppu.DOTS_PER_LINE = 341
Ppu.LINES = 262

function Ppu.new(cart, cpu)
  local self = setmetatable({
    cart = cart,
    cpu = cpu,
    vram = {},
    oam = {},
    palette = {},
    ctrl = 0,
    mask = 0,
    status = 0,
    oam_addr = 0,
    v = 0, t = 0, x = 0, w = false,
    buffer = 0,
    scanline = 261, -- boot in pre-render
    cycle = 0,
    frame = 0,
    nmi_occurred = false,
    nmi_output = false,
    nmi_previous = false,
    nmi_delay = 0,
    nmi_suppress = false, -- $2002 read races with VBL set
    nmi_enabled_dots = 0, -- how long $2000.7 has been set
    open_bus = 0,         -- PPU data bus decay latch
    open_bus_decay = {},  -- per-bit CPU cycles until that bit decays (~600ms)
    _skip_idle = false,
    fb = {},
    _bg_opaque = {}, -- per-x: BG pixel nonzero
    _sp_filled = {}, -- per-x: sprite already painted this line
    _dirty = true,
    odd_frame = false,
    -- Scroll snapshot taken after copy_x (cycle 257) for the next scanline.
    _render_v = 0,
    _render_x = 0,
    -- Sprite 0 hit: PPU cycle this scanline when flag rises (nil if none).
    _s0_hit_at = nil,
  }, Ppu)
  self:reset()
  return self
end

function Ppu:reset()
  for i = 0, 0x7FF do self.vram[i] = 0 end
  for i = 0, 255 do self.oam[i] = 0 end
  for i = 0, 31 do self.palette[i] = 0 end
  self.ctrl, self.mask, self.status = 0, 0, 0
  self.oam_addr = 0
  self.v, self.t, self.x = 0, 0, 0
  self.w = false
  self.buffer = 0
  self.open_bus = 0
  for b = 0, 7 do self.open_bus_decay[b] = 0 end
  self.scanline = 261
  self.cycle = 0
  self.frame = 0
  self.nmi_occurred = false
  self.nmi_output = false
  self.nmi_previous = false
  self.nmi_delay = 0
  self.nmi_suppress = false
  self.nmi_enabled_dots = 0
  self._skip_idle = false
  for i = 0, Ppu.WIDTH * Ppu.HEIGHT - 1 do self.fb[i] = 0x0F end
  self._dirty = true
  self.odd_frame = false
  self._render_v = 0
  self._render_x = 0
  self._s0_hit_at = nil
end

local OPEN_BUS_DECAY = 1070000 -- ~600ms @ NTSC CPU

--- Refresh open-bus bits in `mask` (only those bits reset their decay timers).
function Ppu:_touch_open_bus(v, mask)
  mask = mask or 0xFF
  self.open_bus = bor(band(self.open_bus, bxor(0xFF, mask)), band(v, mask))
  for b = 0, 7 do
    if band(mask, lshift(1, b)) ~= 0 then
      self.open_bus_decay[b] = OPEN_BUS_DECAY
    end
  end
end

function Ppu:_decay_open_bus(cpu_cycles)
  local dec = self.open_bus_decay
  local bus = self.open_bus
  local changed = false
  for b = 0, 7 do
    local t = dec[b]
    if t and t > 0 then
      t = t - cpu_cycles
      if t <= 0 then
        dec[b] = 0
        bus = band(bus, bxor(0xFF, lshift(1, b)))
        changed = true
      else
        dec[b] = t
      end
    end
  end
  if changed then self.open_bus = bus end
end

function Ppu:set_cpu(cpu)
  self.cpu = cpu
end

local function palette_mirror(addr)
  addr = band(addr, 0x1F)
  if addr >= 0x10 and band(addr, 0x03) == 0 then
    return band(addr, 0x0F)
  end
  return addr
end

function Ppu:_nt_read(addr)
  addr = band(addr, 0x3FFF)
  if addr >= 0x3F00 then
    return self.palette[palette_mirror(addr)] or 0
  end
  if addr < 0x2000 then
    return self.cart:ppu_read(addr)
  end
  local m = self.cart:nt_mirror(addr)
  return self.vram[band(m, 0x7FF)] or 0
end

function Ppu:_nt_write(addr, v)
  addr = band(addr, 0x3FFF)
  v = band(v, 0xFF)
  if addr >= 0x3F00 then
    self.palette[palette_mirror(addr)] = band(v, 0x3F)
    return
  end
  if addr < 0x2000 then
    self.cart:ppu_write(addr, v)
    return
  end
  local m = self.cart:nt_mirror(addr)
  self.vram[band(m, 0x7FF)] = v
end

--- @param ctrl_write boolean|nil  true when rising edge comes from $2000 write
function Ppu:_nmi_change(ctrl_write)
  local nmi = self.nmi_output and self.nmi_occurred and not self.nmi_suppress
  if nmi and not self.nmi_previous then
    if ctrl_write then
      -- Enable while VBL already set: short delay + one-insn defer (04 #11, 07).
      self.nmi_delay = 2
      self._nmi_defer_insn = true
    elseif self.nmi_enabled_dots < 20 then
      -- Just-enabled then VBL during next few insns (05-nmi_timing).
      self.nmi_delay = 5
      self._nmi_defer_insn = false
    else
      -- Enabled slightly longer before VBL (06/08 suppress/off windows).
      self.nmi_delay = 2
      self._nmi_defer_insn = false
    end
  elseif not nmi then
    -- Cancel not-yet-delivered delay. Keep cpu.nmi_edge if already latched.
    self.nmi_delay = 0
  end
  self.nmi_previous = nmi
end

function Ppu:read_reg(reg)
  reg = band(reg, 7)
  if reg == 2 then -- PPUSTATUS
    -- Race: reading on the VBL-set dot suppresses the flag + NMI.
    if self.scanline == 241 and self.cycle == 1 then
      self.nmi_suppress = true
      self.nmi_occurred = false
      self.status = band(self.status, 0x7F)
      self.nmi_delay = 0
      self:_nmi_change()
    end
    local v = bor(band(self.status, 0xE0), band(self.open_bus, 0x1F))
    -- Clear vblank; sprite0/overflow stay until pre-render.
    -- Cancels pending PPU NMI delay; CPU latch (if already edged) stays.
    self.status = band(self.status, 0x7F)
    self.nmi_occurred = false
    self.nmi_delay = 0
    self:_nmi_change()
    self.w = false
    -- Low 5 bits are open bus (not refreshed); high 3 refresh open bus.
    self:_touch_open_bus(v, 0xE0)
    return v
  elseif reg == 4 then -- OAMDATA
    local v = self.oam[self.oam_addr] or 0
    -- Attribute bytes (byte 2 of each sprite): bits 2-4 unread -> 0
    if band(self.oam_addr, 3) == 2 then
      v = band(v, 0xE3)
    end
    self:_touch_open_bus(v, 0xFF)
    return v
  elseif reg == 7 then
    local addr = band(self.v, 0x3FFF)
    if self.cart and self.cart.a12_update then
      self.cart:a12_update(addr)
    end
    local val = self.buffer
    if addr >= 0x3F00 then
      val = bor(band(self:_nt_read(addr), 0x3F), band(self.open_bus, 0xC0))
      self.buffer = self:_nt_read(band(addr - 0x1000, 0x3FFF))
      self:_touch_open_bus(val, 0x3F)
    else
      self.buffer = self:_nt_read(addr)
      self:_touch_open_bus(val, 0xFF)
    end
    local inc = band(self.ctrl, 0x04) ~= 0 and 32 or 1
    self.v = band(self.v + inc, 0x7FFF)
    -- Address bus follows V; $0FFF-$1000 raises A12 (blargg 3-A12_clocking).
    if self.cart and self.cart.a12_update then
      self.cart:a12_update(self.v)
    end
    return val
  end
  -- $2000/$2001/$2003/$2005/$2006 read as open bus
  return self.open_bus
end

function Ppu:write_reg(reg, v)
  reg = band(reg, 7)
  v = band(v, 0xFF)
  self:_touch_open_bus(v, 0xFF)
  if reg == 0 then -- PPUCTRL
    self.ctrl = v
    self.t = bor(band(self.t, 0xF3FF), lshift(band(v, 3), 10))
    self.nmi_output = band(v, 0x80) ~= 0
    self:_nmi_change(true)
  elseif reg == 1 then
    self.mask = v
  elseif reg == 3 then
    self.oam_addr = v
  elseif reg == 4 then
    self.oam[self.oam_addr] = v
    self.oam_addr = band(self.oam_addr + 1, 0xFF)
  elseif reg == 5 then -- PPUSCROLL
    if not self.w then
      self.t = bor(band(self.t, 0xFFE0), rshift(v, 3))
      self.x = band(v, 7)
      self.w = true
    else
      self.t = bor(
        band(self.t, 0x8C1F),
        lshift(band(v, 7), 12),
        lshift(rshift(v, 3), 5)
      )
      self.w = false
    end
  elseif reg == 6 then -- PPUADDR
    if not self.w then
      self.t = bor(band(self.t, 0x80FF), lshift(band(v, 0x3F), 8))
      self.w = true
    else
      self.t = bor(band(self.t, 0xFF00), v)
      self.v = self.t
      self.w = false
      -- MMC3 A12 can be clocked by PPUADDR alone.
      if self.cart and self.cart.a12_update then
        self.cart:a12_update(self.v)
      end
    end
  elseif reg == 7 then
    if self.cart and self.cart.a12_update then
      self.cart:a12_update(self.v)
    end
    self:_nt_write(self.v, v)
    local inc = band(self.ctrl, 0x04) ~= 0 and 32 or 1
    self.v = band(self.v + inc, 0x7FFF)
    if self.cart and self.cart.a12_update then
      self.cart:a12_update(self.v)
    end
  end
end

function Ppu:oam_dma_write(page, cpu_read)
  local base = lshift(band(page, 0xFF), 8)
  for i = 0, 255 do
    self.oam[band(self.oam_addr + i, 0xFF)] = cpu_read(base + i)
  end
end

local function rendering_on(self)
  return band(self.mask, 0x18) ~= 0
end

function Ppu:_inc_h()
  -- Increment coarse X (loopy)
  if band(self.v, 0x001F) == 31 then
    self.v = bxor(band(self.v, 0xFFE0), 0x0400)
  else
    self.v = self.v + 1
  end
end

function Ppu:_inc_v()
  -- Increment fine Y / coarse Y
  if band(self.v, 0x7000) ~= 0x7000 then
    self.v = self.v + 0x1000
  else
    self.v = band(self.v, 0x8FFF)
    local y = band(rshift(self.v, 5), 0x1F)
    if y == 29 then
      y = 0
      self.v = bxor(self.v, 0x0800)
    elseif y == 31 then
      y = 0
    else
      y = y + 1
    end
    self.v = bor(band(self.v, 0xFC1F), lshift(y, 5))
  end
end

function Ppu:_copy_h()
  self.v = bor(band(self.v, 0xFBE0), band(self.t, 0x041F))
end

function Ppu:_copy_v()
  self.v = bor(band(self.v, 0x841F), band(self.t, 0x7BE0))
end

--- Opaque BG pixel at screen x using the current scanline scroll snapshot.
function Ppu:_bg_opaque_at(x)
  if x < 0 or x >= 256 then return false end
  local left_bg = band(self.mask, 0x02) ~= 0
  if x < 8 and not left_bg then return false end
  local v = self._render_v
  local fine_x = self._render_x
  local fine_y = rshift(band(v, 0x7000), 12)
  local coarse_y = band(rshift(v, 5), 0x1F)
  local nt_y = band(v, 0x0800)
  local bg_pt = band(self.ctrl, 0x10) ~= 0 and 0x1000 or 0
  local pix = x + fine_x
  local total_x = band(v, 0x1F) + rshift(pix, 3)
  local coarse_x = band(total_x, 0x1F)
  local nt_x = band(v, 0x0400)
  if total_x > 31 then nt_x = bxor(nt_x, 0x0400) end
  local fine = band(pix, 7)
  local nt_addr = 0x2000 + nt_y + nt_x + lshift(coarse_y, 5) + coarse_x
  local tile = self:_nt_read(nt_addr)
  local taddr = bg_pt + tile * 16 + fine_y
  local lo = self.cart:chr_read(taddr)
  local hi = self.cart:chr_read(taddr + 8)
  local bitn = 7 - fine
  local p = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
  return p ~= 0
end

--- First screen X where sprite 0 overlaps opaque BG on scanline y, or nil.
function Ppu:_find_s0_hit_x(y)
  if band(self.status, 0x40) ~= 0 then return nil end
  if band(self.mask, 0x18) ~= 0x18 then return nil end -- need BG + sprites
  local oam = self.oam
  local ybyte = oam[0] or 0
  if ybyte >= 239 then return nil end -- no hit when Y>=239 (incl. Y=255)
  local oy = ybyte + 1
  local row = y - oy
  local tall = band(self.ctrl, 0x20) ~= 0
  local h = tall and 16 or 8
  if row < 0 or row >= h then return nil end

  local tile = oam[1] or 0
  local attr = oam[2] or 0
  local ox = oam[3] or 0
  local flip_v = band(attr, 0x80) ~= 0
  local flip_h = band(attr, 0x40) ~= 0
  local left_sp = band(self.mask, 0x04) ~= 0
  local sp_pt = band(self.ctrl, 0x08) ~= 0 and 0x1000 or 0

  local prow = row
  if flip_v then prow = h - 1 - row end
  local taddr
  if tall then
    local bank = band(tile, 1) * 0x1000
    local top = band(tile, 0xFE)
    if prow >= 8 then
      top = top + 1
      prow = prow - 8
    end
    taddr = bank + top * 16 + prow
  else
    taddr = sp_pt + tile * 16 + prow
  end
  local lo = self.cart:chr_read(taddr)
  local hi = self.cart:chr_read(taddr + 8)

  for px = 0, 7 do
    local x = ox + px
    if x >= 0 and x < 255 and (x >= 8 or left_sp) then
      local bitn = flip_h and px or (7 - px)
      local p = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
      if p ~= 0 and self:_bg_opaque_at(x) then
        return x
      end
    end
  end
  return nil
end

--- Paint one scanline using scroll snapshot (v/fine_x at post-copy_x).
function Ppu:_render_scanline(y)
  if y < 0 or y >= 240 then return end
  local fb = self.fb
  local base = y * 256
  local bg_opaque = self._bg_opaque
  local sp_filled = self._sp_filled
  local show_bg = band(self.mask, 0x08) ~= 0
  local show_sp = band(self.mask, 0x10) ~= 0
  local left_bg = band(self.mask, 0x02) ~= 0
  local left_sp = band(self.mask, 0x04) ~= 0
  local backdrop = band(self.palette[0] or 0x0F, 0x3F)

  for x = 0, 255 do
    fb[base + x] = backdrop
    bg_opaque[x] = false
    sp_filled[x] = false
  end

  -- ---- Background ----
  if show_bg then
    local v = self._render_v
    local fine_x = self._render_x
    local fine_y = rshift(band(v, 0x7000), 12)
    local coarse_y = band(rshift(v, 5), 0x1F)
    local nt_y = band(v, 0x0800)
    local bg_pt = band(self.ctrl, 0x10) ~= 0 and 0x1000 or 0
    local cart = self.cart
    local pal = self.palette

    -- Walk tiles across the line (33 max to cover fine_x).
    local tile_x = 0
    local pix = -fine_x
    local base_cx = band(v, 0x1F)
    local base_ntx = band(v, 0x0400)
    while pix < 256 do
      local total_x = base_cx + tile_x
      local coarse_x = band(total_x, 0x1F)
      local nt_x = base_ntx
      if total_x > 31 then
        nt_x = bxor(nt_x, 0x0400)
      end

      local nt_addr = 0x2000 + nt_y + nt_x + lshift(coarse_y, 5) + coarse_x
      local tile = self:_nt_read(nt_addr)
      local atr_addr = 0x23C0 + nt_y + nt_x
        + lshift(rshift(coarse_y, 2), 3)
        + rshift(coarse_x, 2)
      local attr = self:_nt_read(atr_addr)
      local ashift = bor(lshift(band(coarse_y, 2), 1), band(coarse_x, 2))
      local apal = band(rshift(attr, ashift), 3)

      local taddr = bg_pt + tile * 16 + fine_y
      local lo = cart:chr_read(taddr)
      local hi = cart:chr_read(taddr + 8)

      for b = 0, 7 do
        local x = pix + b
        if x >= 0 and x < 256 and (x >= 8 or left_bg) then
          local bitn = 7 - b
          local p = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
          if p ~= 0 then
            fb[base + x] = band(pal[apal * 4 + p] or 0, 0x3F)
            bg_opaque[x] = true
          end
        end
      end
      pix = pix + 8
      tile_x = tile_x + 1
      if tile_x > 33 then break end
    end
  end

  -- ---- Sprites ----
  -- Overflow evaluation uses raw OAM Y and runs if BG or sprites are enabled.
  -- Drawing uses Y+1 (one-line delay) and only when sprites are enabled.
  local render_any = band(self.mask, 0x18) ~= 0
  if render_any then
    local tall = band(self.ctrl, 0x20) ~= 0
    local h = tall and 16 or 8
    local oam = self.oam
    local found = 0
    local spr = 0
    while spr < 64 do
      local ybyte = oam[spr * 4] or 0
      local erow = y - ybyte
      if erow >= 0 and erow < h then
        if found < 8 then
          found = found + 1
          spr = spr + 1
        else
          self.status = bor(self.status, 0x20)
          break
        end
      elseif found == 8 then
        -- Obscure bug: n and m both increment; m wraps 0..3 without
        -- an extra sprite bump (blargg sprite_overflow 4.Obscure).
        local n, m = spr, 0
        while true do
          m = m + 1
          n = n + 1
          if m == 4 then m = 0 end
          if n >= 64 then break end
          local addr = n * 4 + m
          local yb = oam[addr] or 0
          local r = y - yb
          if r >= 0 and r < h then
            self.status = bor(self.status, 0x20)
            break
          end
        end
        break
      else
        spr = spr + 1
      end
    end
  end

  if show_sp then
    local tall = band(self.ctrl, 0x20) ~= 0
    local h = tall and 16 or 8
    local sp_pt = band(self.ctrl, 0x08) ~= 0 and 0x1000 or 0
    local cart = self.cart
    local pal = self.palette
    local oam = self.oam
    local count = 0

    for i = 0, 63 do
      local oy = (oam[i * 4] or 0) + 1
      local row = y - oy
      if row >= 0 and row < h then
        count = count + 1
        if count > 8 then break end

        local tile = oam[i * 4 + 1] or 0
        local attr = oam[i * 4 + 2] or 0
        local ox = oam[i * 4 + 3] or 0
        local flip_v = band(attr, 0x80) ~= 0
        local flip_h = band(attr, 0x40) ~= 0
        local behind = band(attr, 0x20) ~= 0
        local apal = bor(4, band(attr, 3))

        local prow = row
        if flip_v then prow = h - 1 - row end

        local taddr
        if tall then
          local bank = band(tile, 1) * 0x1000
          local top = band(tile, 0xFE)
          if prow >= 8 then
            top = top + 1
            prow = prow - 8
          end
          taddr = bank + top * 16 + prow
        else
          taddr = sp_pt + tile * 16 + prow
        end

        local lo = cart:chr_read(taddr)
        local hi = cart:chr_read(taddr + 8)

        for px = 0, 7 do
          local x = ox + px
          if x >= 0 and x < 256 and (x >= 8 or left_sp) then
            local bitn = flip_h and px or (7 - px)
            local p = band(rshift(lo, bitn), 1) + band(rshift(hi, bitn), 1) * 2
            if p ~= 0 then
              -- Sprite 0 hit is latched mid-scanline in _tick_one_dot (not here).
              if not sp_filled[x] then
                if not (behind and bg_opaque[x]) then
                  fb[base + x] = band(pal[apal * 4 + p] or 0, 0x3F)
                end
                sp_filled[x] = true
              end
            end
          end
        end
      end
    end
  end
end

function Ppu:_blank_scanline(y)
  if y < 0 or y >= 240 then return end
  local fb = self.fb
  local base = y * 256
  local c = band(self.palette[0] or 0x0F, 0x3F)
  for x = 0, 255 do fb[base + x] = c end
end

--- Earliest cycle >= cy on this scanline that needs per-dot work (or 341 = line end).
local function next_event_cycle(sl, cy, render, s0_at)
  local best = 341
  local function consider(e)
    if e >= cy and e < best then best = e end
  end
  if sl == 241 or sl == 261 then consider(1) end
  if sl >= 0 and sl < 240 then
    consider(0) -- schedule sprite-0 hit eval
    consider(256)
    if s0_at then consider(s0_at) end
  end
  if render and (sl < 240 or sl == 261) then
    consider(10)
    consider(256)
    consider(257)
    consider(266)
    consider(330)
    if sl == 261 then
      -- loopy copy_v every dot in [280,304]
      if cy >= 280 and cy <= 304 then
        return cy
      end
      consider(280)
      consider(338)
      consider(339)
    end
  elseif sl == 261 then
    consider(338)
    consider(339)
  end
  return best
end

--- One PPU dot (hot events only; idle dots are bulk-skipped in tick).
function Ppu:_tick_one_dot()
  if self.nmi_output then
    self.nmi_enabled_dots = self.nmi_enabled_dots + 1
  else
    self.nmi_enabled_dots = 0
  end
  local delay = self.nmi_delay
  if delay > 0 then
    delay = delay - 1
    self.nmi_delay = delay
    if delay == 0 and self.nmi_output and self.nmi_occurred
      and not self.nmi_suppress and self.cpu then
      self.cpu:trigger_nmi()
      if self._nmi_defer_insn then
        self.cpu.nmi_defer_once = true
        self._nmi_defer_insn = false
      end
    end
  end

  local sl = self.scanline
  local cy = self.cycle
  local render = band(self.mask, 0x18) ~= 0

  -- Sprite 0: evaluate at dot 0; flag rises when the overlapping pixel is drawn (x+1).
  if sl >= 0 and sl < 240 and cy == 0 then
    local hx = self:_find_s0_hit_x(sl)
    self._s0_hit_at = hx and (hx + 1) or nil
  end
  if self._s0_hit_at and cy == self._s0_hit_at then
    self.status = bor(self.status, 0x40)
    self._s0_hit_at = nil
  end

  if render and (sl < 240 or sl == 261) then
    -- MMC3 A12 at 4+6 / 260+6 / 324+6 (tick-after alignment).
    local cart = self.cart
    if cart and cart.a12_update then
      if cy == 10 or cy == 330 then
        cart:a12_update(band(self.ctrl, 0x10) ~= 0 and 0x1000 or 0)
      elseif cy == 266 then
        cart:a12_update(band(self.ctrl, 0x08) ~= 0 and 0x1000 or 0)
      end
    end
    if cy == 256 then
      self:_inc_v()
    elseif cy == 257 then
      self:_copy_h()
      self._render_v = self.v
      self._render_x = self.x
    elseif sl == 261 and cy >= 280 and cy <= 304 then
      self:_copy_v()
      if cy == 304 then
        self._render_v = self.v
        self._render_x = self.x
      end
    end
  end

  if sl >= 0 and sl < 240 and cy == 256 then
    if render then
      self:_render_scanline(sl)
    else
      self:_blank_scanline(sl)
    end
  end

  if sl == 241 and cy == 1 then
    if not self.nmi_suppress then
      self.status = bor(self.status, 0x80)
      self.nmi_occurred = true
      self:_nmi_change()
    end
    self._dirty = true
  elseif sl == 261 and cy == 1 then
    self.status = band(self.status, 0x1F)
    self.nmi_occurred = false
    self.nmi_suppress = false
    self._s0_hit_at = nil
    self:_nmi_change()
  end

  if sl == 261 and cy == 338 then
    self._skip_idle = self.odd_frame and render
  end
  if sl == 261 and cy == 339 and self._skip_idle then
    cy = 341
  else
    cy = cy + 1
  end
  if cy >= 341 then
    cy = 0
    sl = sl + 1
    if sl == 262 then
      sl = 0
      self.frame = self.frame + 1
      self.odd_frame = not self.odd_frame
    end
  end
  self.scanline = sl
  self.cycle = cy
end

--- Advance PPU by `cpu_cycles` (3 dots each). Idle stretches skip in bulk.
function Ppu:tick(cpu_cycles)
  if cpu_cycles <= 0 then return end
  self:_decay_open_bus(cpu_cycles)
  local dots = cpu_cycles * 3
  while dots > 0 do
    if self.nmi_delay > 0 then
      self:_tick_one_dot()
      dots = dots - 1
    else
      local sl = self.scanline
      local cy = self.cycle
      local render = band(self.mask, 0x18) ~= 0
      local ev = next_event_cycle(sl, cy, render, self._s0_hit_at)
      local span = ev - cy
      if span <= 0 then
        self:_tick_one_dot()
        dots = dots - 1
      else
        if span > dots then span = dots end
        if self.nmi_output then
          self.nmi_enabled_dots = self.nmi_enabled_dots + span
        else
          self.nmi_enabled_dots = 0
        end
        cy = cy + span
        if cy >= 341 then
          cy = cy - 341
          sl = sl + 1
          if sl == 262 then
            sl = 0
            self.frame = self.frame + 1
            self.odd_frame = not self.odd_frame
          end
        end
        self.scanline = sl
        self.cycle = cy
        dots = dots - span
      end
    end
  end
end

function Ppu:framebuffer()
  return self.fb
end

return Ppu
