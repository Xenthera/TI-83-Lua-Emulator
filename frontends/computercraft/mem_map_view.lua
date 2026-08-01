-- Z80 address-space heatmap on a ComputerCraft monitor (sixtel / pixelbox_lite).
-- Four 16KB banks each use a 4-step CC color gradient (all 16 colors for data).
-- PC/SP markers: hollow rings + P/S glyphs drawn as characters after the canvas.

local CC = require("frontends.computercraft.cc")
local Pixelbox = require("frontends.computercraft.vendor.pixelbox_lite")

local M = {}
M.__index = M

-- Bank 0..3, shade 0..3 (dark/empty -> bright). Uses every CC color once.
local BANK_SHADES = {
  { "black", "gray", "lightGray", "white" },       -- Flash 0000-3FFF
  { "brown", "red", "orange", "yellow" },          -- Bank A 4000-7FFF
  { "green", "lime", "cyan", "lightBlue" },        -- Bank B 8000-BFFF
  { "purple", "magenta", "pink", "blue" },         -- RAM C000-FFFF
}

local function byte_shade(b)
  b = b or 0
  if b <= 0 then
    return 0
  elseif b <= 85 then
    return 1
  elseif b <= 170 then
    return 2
  end
  return 3
end

local function palette(C)
  local bank_color = {}
  for bi, shades in ipairs(BANK_SHADES) do
    bank_color[bi] = {}
    for si, name in ipairs(shades) do
      bank_color[bi][si] = C[name] or C.black
    end
  end
  return bank_color
end

M.BANK_SHADES = BANK_SHADES
M.byte_shade = byte_shade

local function stub_term(mon, C)
  return {
    getSize = function()
      return mon.getSize()
    end,
    getBackgroundColor = function()
      if mon.getBackgroundColor then
        return mon.getBackgroundColor()
      end
      return C.black
    end,
    setBackgroundColor = function(c)
      if mon.setBackgroundColor then
        mon.setBackgroundColor(c)
      end
    end,
    setCursorPos = function(x, y)
      mon.setCursorPos(x, y)
    end,
    blit = function(t, f, b)
      mon.blit(t, f, b)
    end,
    clear = function()
      if mon.clear then mon.clear() end
    end,
    setTextColor = function(c)
      if mon.setTextColor then mon.setTextColor(c) end
    end,
  }
end

function M.new(mon_or_side, opts)
  opts = opts or {}
  local mon, side
  if type(mon_or_side) == "string" then
    mon, side = CC.wrap_monitor(mon_or_side, "memmap")
  else
    mon, side = mon_or_side, opts.side
  end
  local self = setmetatable({}, M)
  self.mon = mon
  self.side = side
  self.text_scale = opts.text_scale
  if self.text_scale == nil then
    self.text_scale = 0.5
  end
  local C = CC.colors()
  self._bank_color = palette(C)
  self._C = C
  self._box = nil
  return self
end

function M:setup()
  local mon = self.mon
  if mon.setTextScale and self.text_scale ~= false then
    mon.setTextScale(self.text_scale)
  end
  mon.setBackgroundColor(self._C.black)
  mon.setTextColor(self._C.white)
  mon.clear()
  self._box = Pixelbox.new(stub_term(mon, self._C), self._C.black)
end

function M:rebind(mon)
  self.mon = mon
  self._box = nil
end

local function ensure_box(self)
  if self._box then
    local tw, th = self.mon.getSize()
    if self._box.term_width ~= tw or self._box.term_height ~= th then
      self._box.term = stub_term(self.mon, self._C)
      self._box:resize(tw, th, self._C.black)
    else
      self._box.term = stub_term(self.mon, self._C)
    end
    return self._box
  end
  self._box = Pixelbox.new(stub_term(self.mon, self._C), self._C.black)
  return self._box
end

--- Map a 16-bit address onto heatmap pixel (1-based x,y).
local function addr_to_pixel(addr, pw, ph, span)
  addr = addr % 65536
  local cells = pw * ph
  local idx = math.floor(addr / span)
  if idx >= cells then
    idx = cells - 1
  end
  local row = math.floor(idx / pw) -- 0-based
  local col = (idx % pw) + 1
  return col, row + 1
end

local function stamp_marker_chars(mon, tw, th, cx, cy, glyph, ring_bg, ring_fg, center_fg, data_bg)
  for dy = -1, 1 do
    for dx = -1, 1 do
      local col = cx + dx
      local row = cy + dy
      if col >= 1 and col <= tw and row >= 1 and row <= th then
        mon.setCursorPos(col, row)
        if dx == 0 and dy == 0 then
          mon.blit(glyph, center_fg, data_bg or ring_bg)
        else
          mon.blit(" ", ring_fg, ring_bg)
        end
      end
    end
  end
end

--- Paint 0000-FFFF via pixelbox (6× denser than 1 cell/sample).
function M:paint(mmu, opts)
  opts = opts or {}
  local mon = self.mon
  local tw, th = mon.getSize()
  if tw < 1 or th < 1 then
    return
  end

  local box = ensure_box(self)
  local pw, ph = box.width, box.height
  local cells = pw * ph
  local total = 65536
  local span = math.floor(total / cells)
  if span < 1 then span = 1 end

  local bank_color = self._bank_color
  local canvas = box.canvas
  local use_sep = pw >= 80
  local sep_c = bank_color[1][1]
  local addr = 0
  local prev_bank = -1

  for y = 1, ph do
    local scan = canvas[y]
    for x = 1, pw do
      local bank = math.floor(addr / 0x4000) % 4
      local b = mmu:read(addr)
      local shade = byte_shade(b)
      local is_sep = use_sep and prev_bank >= 0 and bank ~= prev_bank and x > 1
      if is_sep then
        scan[x] = sep_c
      else
        scan[x] = bank_color[bank + 1][shade + 1]
      end
      prev_bank = bank
      addr = addr + span
      if addr > 0xFFFF then
        addr = 0xFFFF
      end
    end
  end

  box:render()

  local markers = opts.markers
  if not markers then
    markers = {}
    if opts.pc then
      markers[#markers + 1] = { addr = opts.pc, glyph = "P", ring = "black" }
    end
    if opts.sp then
      markers[#markers + 1] = { addr = opts.sp, glyph = "S", ring = "white" }
    end
  end

  local blit_black = CC.to_blit(self._C.black)
  local blit_white = CC.to_blit(self._C.white)
  local fg_dark = blit_black
  local fg_light = blit_white

  for _, mkr in ipairs(markers) do
    if mkr and mkr.addr then
      local px, py = addr_to_pixel(mkr.addr, pw, ph, span)
      -- Character cell containing that sixtel pixel.
      local cx = math.floor((px - 1) / 2) + 1
      local cy = math.floor((py - 1) / 3) + 1
      local ring = mkr.ring or "black"
      local ring_bg, ring_fg, center_fg
      if ring == "white" then
        ring_bg, ring_fg, center_fg = blit_white, blit_black, fg_dark
      else
        ring_bg, ring_fg, center_fg = blit_black, blit_white, fg_light
      end
      local data_bg = CC.to_blit(canvas[py] and canvas[py][px] or self._C.black)
      stamp_marker_chars(
        mon, tw, th, cx, cy,
        mkr.glyph or "?", ring_bg, ring_fg, center_fg, data_bg
      )
    end
  end
end

return M
