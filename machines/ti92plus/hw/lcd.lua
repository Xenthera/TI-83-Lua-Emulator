-- TI-92 Plus LCD: physical panel = full logical VRAM 240×128 (30 bytes/row).
-- Same HW2 ASIC snoop window as TI-89 ($4C00–$5BFF default); glass shows all of it.

local bit = require("framework.util.bit")
local band = bit.band

local WIDTH, HEIGHT = 240, 128
local BPR = 30 -- 240/8
local FB_SIZE = BPR * HEIGHT -- 3840 ≤ 4KB snoop window

local Lcd = {}
Lcd.__index = Lcd
Lcd.WIDTH = WIDTH
Lcd.HEIGHT = HEIGHT
Lcd.BYTES_PER_ROW = BPR
Lcd.LOGICAL_WIDTH = WIDTH
Lcd.LOGICAL_HEIGHT = HEIGHT

local SNOOP_BASES = { [0] = 0x4C00, [1] = 0x5C00, [2] = 0x6C00, [3] = 0x7C00 }

function Lcd.new()
  local self = setmetatable({}, Lcd)
  self.fb = {}
  for i = 0, 0xFFF do self.fb[i] = 0 end
  self.base = 0x4C00
  self.snoop_sel = 0
  self.snoop_base = 0x4C00
  -- $600012/$013 reset → 240×128
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

function Lcd:set_base_div8(v)
  self.base = ((v or 0) % 0x10000) * 8
end

function Lcd:set_snoop_range(v)
  self.snoop_sel = (v or 0) % 4
  self.snoop_base = SNOOP_BASES[self.snoop_sel] or 0x4C00
  self._dirty = true
end

function Lcd:logical_row_bytes()
  local n = band(self.width_reg or 0x31, 0x3F)
  local bpr = (64 - n) * 2
  if bpr < BPR then bpr = BPR end
  if bpr > BPR then bpr = BPR end
  return bpr
end

function Lcd:logical_height()
  local h = 256 - band(self.height_reg or 0x80, 0xFF)
  if h < 1 then h = HEIGHT end
  if h > HEIGHT then h = HEIGHT end
  return h
end

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

--- Full 240×128 panel (unlike TI-89 which crops to 160×100).
function Lcd:framebuffer(out)
  out = out or {}
  local src_bpr = self:logical_row_bytes()
  local fb = self.fb
  for row = 0, HEIGHT - 1 do
    local src = row * src_bpr
    local dst = row * BPR
    for col = 0, BPR - 1 do
      out[dst + col] = fb[src + col] or 0
    end
  end
  return out
end

function Lcd:dirty() return self._dirty end
function Lcd:clear_dirty() self._dirty = false end
function Lcd:is_display_on() return self.display_on end

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
