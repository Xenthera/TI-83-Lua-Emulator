-- Paint the 96x64 TI LCD onto a wrapped ComputerCraft monitor (blit).
-- Fast path: letterbox once, then only blit dirty 96-wide LCD rows via a
-- precomputed byte->8-pixel blit LUT.

local Lcd = require("core.hw.lcd")
local CC = require("frontend.computercraft.cc")

local M = {}

M.TEXT_SCALE = 0.5
M.NEED_W = Lcd.WIDTH   -- 96
M.NEED_H = Lcd.HEIGHT  -- 64
M.BPR = Lcd.BYTES_PER_ROW

local SPACES96 = string.rep(" ", M.NEED_W)

local function build_byte_lut(blit_on, blit_off)
  local lut = {}
  for b = 0, 255 do
    local p0 = (b >= 128) and blit_on or blit_off
    local p1 = (b % 128 >= 64) and blit_on or blit_off
    local p2 = (b % 64 >= 32) and blit_on or blit_off
    local p3 = (b % 32 >= 16) and blit_on or blit_off
    local p4 = (b % 16 >= 8) and blit_on or blit_off
    local p5 = (b % 8 >= 4) and blit_on or blit_off
    local p6 = (b % 4 >= 2) and blit_on or blit_off
    local p7 = (b % 2 >= 1) and blit_on or blit_off
    lut[b] = p0 .. p1 .. p2 .. p3 .. p4 .. p5 .. p6 .. p7
  end
  return lut
end

--- Apply smallest text scale and frame clear. Call on attach / resize.
function M.setup(mon, opts)
  opts = opts or {}
  if mon.setTextScale then
    local scale = opts.text_scale
    if scale == nil then
      scale = M.TEXT_SCALE
    end
    if scale ~= false then
      mon.setTextScale(scale)
    end
  end
  local C = CC.colors()
  local frame = opts.frame or C.black
  mon.setBackgroundColor(frame)
  mon.setTextColor(C.white)
  mon.clear()
  mon.setCursorPos(1, 1)
end

function M.layout(mon)
  local mw, mh = mon.getSize()
  if mw < M.NEED_W or mh < M.NEED_H then
    return {
      ok = false,
      mw = mw,
      mh = mh,
      need = M.NEED_W .. "x" .. M.NEED_H,
    }
  end
  return {
    ok = true,
    mw = mw,
    mh = mh,
    x0 = math.floor((mw - M.NEED_W) / 2) + 1,
    y0 = math.floor((mh - M.NEED_H) / 2) + 1,
  }
end

local function paint_too_small(mon, lay)
  local C = CC.colors()
  mon.setBackgroundColor(C.black)
  mon.clear()
  local msg = "monitor too small (needs " .. lay.need .. ")"
  local size = "now " .. tostring(lay.mw) .. "x" .. tostring(lay.mh)
  mon.setTextColor(C.red)
  mon.setBackgroundColor(C.black)
  local function center_write(y, text)
    if y < 1 or y > lay.mh then
      return
    end
    local x = math.floor((lay.mw - #text) / 2) + 1
    if x < 1 then x = 1 end
    mon.setCursorPos(x, y)
    mon.write(text:sub(1, lay.mw))
  end
  local mid = math.max(1, math.floor(lay.mh / 2))
  center_write(mid, msg)
  if lay.mh >= 2 then
    center_write(mid + 1, size)
  end
end

--- Stateful painter: letterbox once, dirty-row LCD updates after that.
local Painter = {}
Painter.__index = Painter

function M.new_painter(mon, opts)
  opts = opts or {}
  local self = setmetatable({
    mon = mon,
    opts = opts,
    lay = nil,
    lut = nil,
    fg96 = nil,
    last_bg = {},
    force = true,
    display_on = true,
  }, Painter)
  return self
end

function Painter:rebind(mon)
  self.mon = mon
  self.force = true
end

function Painter:_rebuild_colors()
  local C = CC.colors()
  local col_on = self.opts.on or C.green
  local col_off = self.opts.off or C.lime
  local blit_on = CC.to_blit(col_on)
  local blit_off = CC.to_blit(col_off)
  self.lut = build_byte_lut(blit_on, blit_off)
  self.fg96 = string.rep(blit_off, M.NEED_W)
  self.bg_off96 = string.rep(blit_off, M.NEED_W)
  self.last_bg = {}
  self.force = true
end

--- Update on/off/frame colors (theme change) and force a full redraw.
function Painter:set_colors(opts)
  opts = opts or {}
  if opts.on ~= nil then self.opts.on = opts.on end
  if opts.off ~= nil then self.opts.off = opts.off end
  if opts.frame ~= nil then self.opts.frame = opts.frame end
  self:_rebuild_colors()
  if self.mon then
    local C = CC.colors()
    self.mon.setBackgroundColor(self.opts.frame or C.black)
    self.mon.clear()
    self.force = true
  end
end

function Painter:setup()
  M.setup(self.mon, self.opts)
  self.lay = M.layout(self.mon)
  self:_rebuild_colors()
  if not self.lay.ok then
    paint_too_small(self.mon, self.lay)
  end
  return self.lay
end

local function row_bg(lut, fb, row, bpr, bg_off)
  if not fb then
    return bg_off
  end
  local base = row * bpr
  -- 12 bytes -> 96 blit nibbles (one concat of 12 pre-made octets)
  return lut[fb[base] or 0]
    .. lut[fb[base + 1] or 0]
    .. lut[fb[base + 2] or 0]
    .. lut[fb[base + 3] or 0]
    .. lut[fb[base + 4] or 0]
    .. lut[fb[base + 5] or 0]
    .. lut[fb[base + 6] or 0]
    .. lut[fb[base + 7] or 0]
    .. lut[fb[base + 8] or 0]
    .. lut[fb[base + 9] or 0]
    .. lut[fb[base + 10] or 0]
    .. lut[fb[base + 11] or 0]
end

--- Paint LCD glass only (not the whole monitor). Returns ok, lay, rows_blitted.
function Painter:paint(fb, display_on)
  local lay = self.lay or M.layout(self.mon)
  self.lay = lay
  if not lay.ok then
    paint_too_small(self.mon, lay)
    return false, lay, 0
  end

  if not self.lut then
    self:_rebuild_colors()
  end

  local on = not not display_on
  if on ~= self.display_on then
    self.display_on = on
    self.force = true
  end

  local mon = self.mon
  local lut = self.lut
  local fg96 = self.fg96
  local bg_off = self.bg_off96
  local last = self.last_bg
  local force = self.force
  local x0, y0 = lay.x0, lay.y0
  local bpr = M.BPR
  local blitted = 0

  for row = 0, M.NEED_H - 1 do
    local bg
    if on then
      bg = row_bg(lut, fb, row, bpr, bg_off)
    else
      bg = bg_off
    end
    if force or last[row] ~= bg then
      mon.setCursorPos(x0, y0 + row)
      mon.blit(SPACES96, fg96, bg)
      last[row] = bg
      blitted = blitted + 1
    end
  end
  self.force = false
  return true, lay, blitted
end

--- One-shot paint (tests / simple callers). Uses a throwaway painter.
function M.paint(mon, fb, display_on, opts)
  local p = M.new_painter(mon, opts)
  local lay = p:setup()
  if not lay.ok then
    return false, lay
  end
  -- setup already cleared; force all LCD rows
  p.force = true
  return p:paint(fb, display_on)
end

M.Painter = Painter

return M
