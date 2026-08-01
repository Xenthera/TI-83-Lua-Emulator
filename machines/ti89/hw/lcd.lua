-- TI-89 / Titanium LCD.
--
-- Physical panel (what the user sees): 160×100.
-- Logical VRAM (shared ASIC with 92+/V200): 240×128, 30 bytes/row.
-- Hardware shows the upper-left 160×100 of that buffer; the trailing 80
-- pixels/line and bottom 28 lines are real memory but not on the glass.
-- HW2+/Titanium: 4KB controller RAM snoops writes to $4C00–$5BFF (default).

local bit = require("framework.util.bit")
local band = bit.band
local Geom = require("machines.ti89.lcd_geom")

local WIDTH, HEIGHT = Geom.WIDTH, Geom.HEIGHT
local PHYS_BPR = Geom.BYTES_PER_ROW -- 160/8
local LOG_BPR_DEFAULT = 30 -- 240/8

local Lcd = {}
Lcd.__index = Lcd
Lcd.WIDTH = WIDTH
Lcd.HEIGHT = HEIGHT
Lcd.BYTES_PER_ROW = PHYS_BPR
Lcd.LOGICAL_WIDTH = Geom.LOGICAL_WIDTH
Lcd.LOGICAL_HEIGHT = Geom.LOGICAL_HEIGHT

local SNOOP_BASES = { [0] = 0x4C00, [1] = 0x5C00, [2] = 0x6C00, [3] = 0x7C00 }

function Lcd.new()
  local self = setmetatable({}, Lcd)
  self.fb = {}
  for i = 0, 0xFFF do self.fb[i] = 0 end
  self.base = 0x4C00
  self.snoop_sel = 0
  self.snoop_base = 0x4C00
  -- $600012/$013 reset value $3180 → 240×128 logical VRAM
  self.width_reg = 0x31
  self.height_reg = 0x80
  self.contrast = 0xFF
  self.display_on = true
  self._dirty = true
  return self
end

function Lcd:reset()
  for i = 0, 0xFFF do self.fb[i] = 0 end
  self.base = 0x4C00
  self.snoop_sel = 0
  self.snoop_base = 0x4C00
  self.width_reg = 0x31
  self.height_reg = 0x80
  self._dirty = true
  self.display_on = true
end

-- HW1 only; ignored for display on HW2+/Titanium.
function Lcd:set_base_div8(v)
  self.base = ((v or 0) % 0x10000) * 8
end

function Lcd:set_snoop_range(v)
  self.snoop_sel = (v or 0) % 4
  self.snoop_base = SNOOP_BASES[self.snoop_sel] or 0x4C00
  self._dirty = true
end

--- Logical bytes per row from $600012: (64-n)*2 bytes = (64-n)*16 pixels.
function Lcd:logical_row_bytes()
  local n = band(self.width_reg or 0x31, 0x3F)
  local bpr = (64 - n) * 2
  if bpr < PHYS_BPR then bpr = PHYS_BPR end
  if bpr > LOG_BPR_DEFAULT then bpr = LOG_BPR_DEFAULT end
  return bpr
end

function Lcd:logical_height()
  local h = 256 - band(self.height_reg or 0x80, 0xFF)
  if h < 1 then h = HEIGHT end
  if h > 128 then h = 128 end
  return h
end

--- HW2+ snoop: every write into the selected 4KB window updates LCD memory.
function Lcd:snoop_write(addr, value)
  local base = self.snoop_base
  if addr >= base and addr < base + 0x1000 then
    self.fb[addr - base] = value % 256
    self._dirty = true
  end
end

function Lcd:getFramebuffer()
  return self.fb
end

--- Physical panel view: 160×100, 20 bytes/row (for Love2D / tools).
-- Maps logical VRAM (typically 30 bytes/row) the same way the glass does:
-- each visible row is the first 160 pixels of that logical line.
function Lcd:framebuffer(out)
  out = out or {}
  local src_bpr = self:logical_row_bytes()
  local fb = self.fb
  for row = 0, HEIGHT - 1 do
    local src = row * src_bpr
    local dst = row * PHYS_BPR
    for col = 0, PHYS_BPR - 1 do
      out[dst + col] = fb[src + col] or 0
    end
  end
  return out
end

function Lcd:dirty() return self._dirty end
function Lcd:clear_dirty() self._dirty = false end
function Lcd:is_display_on() return self.display_on end

-- Fallback sync from RAM (savestate / tools). Prefer snoop during run.
function Lcd:refresh_from_ram(ram)
  if not ram then return end
  local base = self.snoop_base or 0x4C00
  local fb = self.fb
  local bytes = ram.bytes
  local need = math.min(0x1000, self:logical_row_bytes() * self:logical_height())
  if bytes then
    local size = ram.SIZE
    for i = 0, need - 1 do
      fb[i] = bytes[(base + i) % size] or 0
    end
  else
    for i = 0, need - 1 do
      fb[i] = ram:read8(base + i)
    end
  end
  self._dirty = true
end

return Lcd
