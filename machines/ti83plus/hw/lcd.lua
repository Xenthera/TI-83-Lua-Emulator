-- Toshiba T6A04 LCD controller (TI-83 Plus): 96x64 visible, 120x64 internal.
-- Command set matches WikiTI 83Plus:Ports:10.
-- TI docs: X = row, Y = column. We keep x=column, y=row in code.
--
-- Data reads use an output latch: after the pointer is set via the command
-- port, the first data read is a dummy (returns the previous latch) and loads
-- the new location. Successive reads then return real data as the pointer
-- auto-increments (WikiTI 83Plus:Ports:11).

local bit = require("framework.util.bit")
local band, bor, bnot, lshift, rshift = bit.band, bit.bor, bit.bnot, bit.lshift, bit.rshift
local Geom = require("machines.ti83plus.lcd_geom")

local WIDTH = Geom.WIDTH
local HEIGHT = Geom.HEIGHT
local INTERNAL_WIDTH = 120
local BYTES_PER_ROW = Geom.BYTES_PER_ROW -- visible (96/8)
local INT_BPR = 15 -- internal (120/8)
local FB_SIZE = BYTES_PER_ROW * HEIGHT
local INT_FB_SIZE = INT_BPR * HEIGHT

local Lcd = {}
Lcd.__index = Lcd
Lcd.WIDTH = WIDTH
Lcd.HEIGHT = HEIGHT
Lcd.BYTES_PER_ROW = BYTES_PER_ROW

local function bnot_u8(v)
  return band(bnot(v), 0xFF)
end

function Lcd.new()
  local self = setmetatable({}, Lcd)
  self.fb = {} -- internal 120x64 packed, row-major 15 bytes/row
  for i = 0, INT_FB_SIZE - 1 do
    self.fb[i] = 0
  end
  self.x = 0 -- column (TI "Y")
  self.y = 0 -- row (TI "X")
  self.z = 0
  self.contrast = 0x3F
  self.display_on = false
  self.bits8 = true
  self.inc_col = false -- false = X/row, true = Y/column
  self.inc_up = true
  self.busy_cycles = 0
  self.read_reg = 0 -- T6A04 output latch
  self._dirty = true
  return self
end

function Lcd:reset()
  for i = 0, INT_FB_SIZE - 1 do
    self.fb[i] = 0
  end
  self.x = 0
  self.y = 0
  self.z = 0
  self.contrast = 0x3F
  self.display_on = false
  self.bits8 = true
  self.inc_col = false
  self.inc_up = true
  self.busy_cycles = 0
  self.read_reg = 0
  self._dirty = true
end

function Lcd:tick(cycles)
  local busy = self.busy_cycles
  if busy > 0 then
    busy = busy - cycles
    self.busy_cycles = busy > 0 and busy or 0
  end
end

function Lcd:status()
  local s = 0
  if self.inc_up then s = bor(s, 0x01) end
  if self.inc_col then s = bor(s, 0x02) end
  if self.display_on then s = bor(s, 0x20) end
  if self.bits8 then s = bor(s, 0x40) end
  if self.busy_cycles > 0 then s = bor(s, 0x80) end
  return s
end

local function set_busy(self, n)
  self.busy_cycles = n
end

local function max_col(self)
  return self.bits8 and 14 or 19
end

local function advance(self)
  if self.inc_col then
    local wrap = max_col(self)
    if self.inc_up then
      self.x = self.x + 1
      if self.x > wrap then
        self.x = 0
      end
    else
      self.x = self.x - 1
      if self.x < 0 then
        self.x = wrap
      end
    end
  else
    if self.inc_up then
      self.y = band(self.y + 1, 0x3F)
    else
      self.y = band(self.y - 1, 0x3F)
    end
  end
end

local function set_pixel(self, px, row, on)
  if px < 0 or px >= INTERNAL_WIDTH or row < 0 or row > 63 then
    return
  end
  local byte_i = math.floor(px / 8)
  local bitn = 7 - (px % 8) -- MSB = leftmost
  local idx = row * INT_BPR + byte_i
  local mask = lshift(1, bitn)
  if on then
    self.fb[idx] = bor(self.fb[idx], mask)
  else
    self.fb[idx] = band(self.fb[idx], bnot_u8(mask))
  end
end

local function get_pixel(self, px, row)
  if px < 0 or px >= INTERNAL_WIDTH or row < 0 or row > 63 then
    return false
  end
  local byte_i = math.floor(px / 8)
  local bitn = 7 - (px % 8)
  local idx = row * INT_BPR + byte_i
  return band(self.fb[idx], lshift(1, bitn)) ~= 0
end

local function peek(self, col, row)
  if row < 0 or row > 63 then
    return 0
  end
  if self.bits8 then
    if col >= 0 and col <= 14 then
      return self.fb[row * INT_BPR + col]
    end
    return 0
  end
  if col < 0 or col > 19 then
    return 0
  end
  local value = 0
  local base = col * 6
  for i = 0, 5 do
    if get_pixel(self, base + i, row) then
      value = bor(value, lshift(1, 5 - i))
    end
  end
  return value
end

local function poke(self, col, row, value)
  if row < 0 or row > 63 then
    return false
  end
  if self.bits8 then
    if col >= 0 and col <= 14 then
      self.fb[row * INT_BPR + col] = value
      return true
    end
    return false
  end
  if col < 0 or col > 19 then
    return false
  end
  local base = col * 6
  for i = 0, 5 do
    local on = band(value, lshift(1, 5 - i)) ~= 0
    set_pixel(self, base + i, row, on)
  end
  return true
end

function Lcd:command(cmd)
  cmd = band(cmd, 0xFF)
  set_busy(self, 60)

  if cmd == 0x00 then
    self.bits8 = false
  elseif cmd == 0x01 then
    self.bits8 = true
  elseif cmd == 0x02 then
    self.display_on = false
    self._dirty = true
  elseif cmd == 0x03 then
    self.display_on = true
    self._dirty = true
  elseif cmd == 0x04 then
    self.inc_col = false
    self.inc_up = false
  elseif cmd == 0x05 then
    self.inc_col = false
    self.inc_up = true
  elseif cmd == 0x06 then
    self.inc_col = true
    self.inc_up = false
  elseif cmd == 0x07 then
    self.inc_col = true
    self.inc_up = true
  elseif cmd >= 0x08 and cmd <= 0x1F then
    -- power / mirror / test - ignore
  elseif cmd >= 0x20 and cmd <= 0x3F then
    self.x = band(cmd, 0x1F)
    -- pointer change leaves read_reg stale (dummy read required)
  elseif cmd >= 0x40 and cmd <= 0x7F then
    self.z = band(cmd, 0x3F)
    self._dirty = true
  elseif cmd >= 0x80 and cmd <= 0xBF then
    self.y = band(cmd, 0x3F)
    -- pointer change leaves read_reg stale (dummy read required)
  else
    self.contrast = band(cmd, 0x3F)
    self._dirty = true
  end
end

function Lcd:data_write(value)
  value = band(value, 0xFF)
  set_busy(self, 60)

  if poke(self, self.x, self.y, value) then
    self._dirty = true
  end

  advance(self)
end

function Lcd:data_read()
  set_busy(self, 60)
  -- Return previous latch, then load current cell and advance (T6A04).
  local value = self.read_reg
  self.read_reg = peek(self, self.x, self.y)
  advance(self)
  return value
end

function Lcd:dirty()
  return self._dirty
end

function Lcd:clear_dirty()
  self._dirty = false
end

function Lcd:is_display_on()
  return self.display_on
end

-- Visible 96x64 as 12 bytes/row (MSB leftmost), with Z scroll.
-- Writes into `out` when provided (0-based indices) to avoid realloc on hot paths.
function Lcd:framebuffer(out)
  out = out or {}
  for row = 0, HEIGHT - 1 do
    local src_row = band(row + self.z, 0x3F)
    local dst = row * BYTES_PER_ROW
    local src = src_row * INT_BPR
    for col = 0, BYTES_PER_ROW - 1 do
      out[dst + col] = self.fb[src + col]
    end
  end
  return out
end

function Lcd:framebuffer_size()
  return FB_SIZE
end

return Lcd
