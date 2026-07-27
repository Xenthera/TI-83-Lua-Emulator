-- Z80 address-space heatmap on a ComputerCraft monitor.
-- Four 16KB banks each use a 4-step CC color gradient (all 16 colors for data).
-- PC/SP markers: hollow black/white rings with P/S center glyphs.

local CC = require("frontend.computercraft.cc")

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

--- Build bank_blit[bank+1][shade+1] and helpers from CC colors table.
local function palette(C)
  local bank_blit = {}
  local bank_color = {}
  for bi, shades in ipairs(BANK_SHADES) do
    bank_blit[bi] = {}
    bank_color[bi] = {}
    for si, name in ipairs(shades) do
      local c = C[name] or C.black
      bank_color[bi][si] = c
      bank_blit[bi][si] = CC.to_blit(c)
    end
  end
  return bank_blit, bank_color
end

-- Exported for tests.
M.BANK_SHADES = BANK_SHADES
M.byte_shade = byte_shade

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
  self._bank_blit, self._bank_color = palette(C)
  self._C = C
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
end

function M:rebind(mon)
  self.mon = mon
end

--- Map a 16-bit address onto heatmap cell (1-based col, 0-based map row).
local function addr_to_cell(addr, w, rows, span)
  addr = addr % 65536
  local cells = w * rows
  local idx = math.floor(addr / span)
  if idx >= cells then
    idx = cells - 1
  end
  local row = math.floor(idx / w)
  local col = (idx % w) + 1
  return col, row
end

--- Hollow 3x3 ring + center glyph. Ring uses ring_bg / ring_fg; center keeps data bg.
local function stamp_marker(grid_ch, grid_fg, grid_bg, w, rows, cx, cy, glyph, ring_bg, ring_fg, center_fg)
  for dy = -1, 1 do
    for dx = -1, 1 do
      local col = cx + dx
      local row = cy + dy
      if col >= 1 and col <= w and row >= 0 and row < rows then
        local i = row * w + col
        if dx == 0 and dy == 0 then
          grid_ch[i] = glyph
          grid_fg[i] = center_fg
          -- leave grid_bg (data color) alone
        else
          grid_ch[i] = " "
          grid_bg[i] = ring_bg
          grid_fg[i] = ring_fg
        end
      end
    end
  end
end

--- Paint 0000-FFFF: bank gradient by address, shade by byte value.
-- No top legend bar (full monitor is the map).
-- opts.markers: optional list of { addr=, glyph= } (defaults PC=P, SP=S).
-- opts.pc / opts.sp: convenience shortcuts when markers omitted.
function M:paint(mmu, opts)
  opts = opts or {}
  local mon = self.mon
  local w, h = mon.getSize()
  if w < 1 or h < 1 then
    return
  end

  -- Full-height map (no header). Clear first so a stale legend cannot linger.
  mon.setBackgroundColor(self._C.black)
  mon.clear()

  local rows = h
  local cells = w * rows
  local total = 65536
  local span = math.floor(total / cells)
  if span < 1 then span = 1 end

  local bank_blit = self._bank_blit
  local space = " "
  local fg_dark = CC.to_blit(self._C.black)
  local fg_light = CC.to_blit(self._C.white)
  local sep_bg = bank_blit[1][1] -- black
  local use_sep = w >= 40

  local grid_ch = {}
  local grid_fg = {}
  local grid_bg = {}
  local addr = 0
  local prev_bank = -1
  for row = 0, rows - 1 do
    for col = 1, w do
      local bank = math.floor(addr / 0x4000) % 4
      local b = mmu:read(addr)
      local shade = byte_shade(b)
      local i = row * w + col
      local is_sep = use_sep and prev_bank >= 0 and bank ~= prev_bank and col > 1
      if is_sep then
        grid_ch[i] = space
        grid_bg[i] = sep_bg
        grid_fg[i] = fg_light
      else
        grid_ch[i] = space
        grid_bg[i] = bank_blit[bank + 1][shade + 1]
        -- Readable FG if we later put a glyph on this cell.
        grid_fg[i] = (shade <= 1) and fg_light or fg_dark
      end
      prev_bank = bank
      addr = addr + span
      if addr > 0xFFFF then
        addr = 0xFFFF
      end
    end
  end

  local markers = opts.markers
  if not markers then
    markers = {}
    if opts.pc then
      markers[#markers + 1] = {
        addr = opts.pc,
        glyph = "P",
        ring = "black",
      }
    end
    if opts.sp then
      markers[#markers + 1] = {
        addr = opts.sp,
        glyph = "S",
        ring = "white",
      }
    end
  end

  local blit_black = CC.to_blit(self._C.black)
  local blit_white = CC.to_blit(self._C.white)

  for _, mkr in ipairs(markers) do
    if mkr and mkr.addr then
      local cx, cy = addr_to_cell(mkr.addr, w, rows, span)
      local ring = mkr.ring or "black"
      local ring_bg, ring_fg, center_fg
      if ring == "white" then
        ring_bg, ring_fg, center_fg = blit_white, blit_black, fg_dark
      else
        ring_bg, ring_fg, center_fg = blit_black, blit_white, fg_light
      end
      stamp_marker(
        grid_ch, grid_fg, grid_bg, w, rows, cx, cy,
        mkr.glyph or "?", ring_bg, ring_fg, center_fg
      )
    end
  end

  for row = 0, rows - 1 do
    local base = row * w
    local ch, fg, bg = {}, {}, {}
    for col = 1, w do
      local i = base + col
      ch[col] = grid_ch[i]
      fg[col] = grid_fg[i]
      bg[col] = grid_bg[i]
    end
    mon.setCursorPos(1, row + 1)
    mon.blit(table.concat(ch), table.concat(fg), table.concat(bg))
  end
end

return M
