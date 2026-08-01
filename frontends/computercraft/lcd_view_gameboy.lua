-- Game Boy DMG LCD for ComputerCraft: 160×144 shades 0–3 via pixelbox.
-- Palette: white, lightGray, gray, black.

local CC = require("frontends.computercraft.cc")
local Pixelbox = require("frontends.computercraft.vendor.pixelbox_lite")
local Geom = require("machines.gameboy.lcd_geom")

local M = {}
M.PIXEL_W = Geom.WIDTH
M.PIXEL_H = Geom.HEIGHT
M.NEED_W = math.ceil(Geom.WIDTH / 2)
M.NEED_H = math.ceil(Geom.HEIGHT / 3)
M.TEXT_SCALE = 0.5

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

local function shade_palette(C)
  return {
    [0] = C.white,
    [1] = C.lightGray,
    [2] = C.gray,
    [3] = C.black,
  }
end

function M.setup(mon, opts)
  opts = opts or {}
  if mon.setTextScale then
    local scale = opts.text_scale
    if scale == nil then scale = M.TEXT_SCALE end
    if scale ~= false then mon.setTextScale(scale) end
  end
  local C = CC.colors()
  mon.setBackgroundColor(opts.frame or C.black)
  mon.setTextColor(C.white)
  mon.clear()
  mon.setCursorPos(1, 1)
end

function M.layout(mon)
  local mw, mh = mon.getSize()
  if mw < M.NEED_W or mh < M.NEED_H then
    return {
      ok = false, mw = mw, mh = mh,
      need = M.NEED_W .. "x" .. M.NEED_H,
      pixels = M.PIXEL_W .. "x" .. M.PIXEL_H,
    }
  end
  return {
    ok = true, mw = mw, mh = mh,
    x0 = math.floor((mw - M.NEED_W) / 2) + 1,
    y0 = math.floor((mh - M.NEED_H) / 2) + 1,
    need = M.NEED_W .. "x" .. M.NEED_H,
    pixels = M.PIXEL_W .. "x" .. M.PIXEL_H,
  }
end

local function paint_too_small(mon, lay)
  local C = CC.colors()
  mon.setBackgroundColor(C.black)
  mon.clear()
  mon.setTextColor(C.red)
  local msg = "monitor too small (needs " .. lay.need .. " for 4-shade GB)"
  local mid = math.max(1, math.floor(lay.mh / 2))
  local x = math.max(1, math.floor((lay.mw - #msg) / 2) + 1)
  mon.setCursorPos(x, mid)
  mon.write(msg:sub(1, lay.mw))
end

local Painter = {}
Painter.__index = Painter

function M.new_painter(mon, opts)
  opts = opts or {}
  local C = CC.colors()
  return setmetatable({
    mon = mon,
    opts = opts,
    lay = nil,
    _C = C,
    _shade = shade_palette(C),
    _box = nil,
    _framed = false,
    force = true,
    display_on = true,
  }, Painter)
end

function Painter:rebind(mon)
  self.mon = mon
  self._box = nil
  self._framed = false
  self.force = true
end

function Painter:_ensure_box()
  local mon = self.mon
  local C = self._C
  local frame = self.opts.frame or C.black
  if self._box then
    local tw, th = mon.getSize()
    if self._box.term_width ~= tw or self._box.term_height ~= th then
      self._box.term = stub_term(mon, C)
      self._box:resize(tw, th, frame)
      self._framed = false
    else
      self._box.term = stub_term(mon, C)
    end
    return self._box
  end
  self._box = Pixelbox.new(stub_term(mon, C), frame)
  self._framed = false
  return self._box
end

function Painter:set_colors(opts)
  opts = opts or {}
  if opts.frame ~= nil then self.opts.frame = opts.frame end
  local C = CC.colors()
  self._C = C
  self._shade = shade_palette(C)
  self._box = nil
  self._framed = false
  self.force = true
  if self.mon then
    self.mon.setBackgroundColor(self.opts.frame or C.black)
    self.mon.clear()
  end
end

function Painter:setup()
  M.setup(self.mon, self.opts)
  self.lay = M.layout(self.mon)
  self._C = CC.colors()
  self._shade = shade_palette(self._C)
  self._box = nil
  self._framed = false
  if not self.lay.ok then
    paint_too_small(self.mon, self.lay)
  end
  return self.lay
end

function Painter:paint(fb, display_on)
  local lay = self.lay or M.layout(self.mon)
  self.lay = lay
  if not lay.ok then
    paint_too_small(self.mon, lay)
    return false, lay, 0
  end

  local on = not not display_on
  local box = self:_ensure_box()
  local canvas = box.canvas
  local shade = self._shade
  local C = self._C
  local frame = self.opts.frame or C.black
  local pw, ph = M.PIXEL_W, M.PIXEL_H
  local x0, y0 = lay.x0, lay.y0

  -- Letterbox once (not every frame).
  if not self._framed then
    local tw, th = box.term_width, box.term_height
    for y = 1, th * 3 do
      local scan = canvas[y]
      if scan then
        for x = 1, tw * 2 do
          scan[x] = frame
        end
      end
    end
    self._framed = true
  end

  local ox = (x0 - 1) * 2
  local oy = (y0 - 1) * 3
  local bw = box.width

  if on and fb then
    for fy = 0, ph - 1 do
      local scan = canvas[oy + fy + 1]
      if scan then
        local row = fy * pw
        local base = ox
        for fx = 0, pw - 1 do
          local s = fb[row + fx] or 0
          if s > 3 then s = 3 elseif s < 0 then s = 0 end
          scan[base + fx + 1] = shade[s]
        end
      end
    end
  else
    local black = C.black
    for fy = 0, ph - 1 do
      local scan = canvas[oy + fy + 1]
      if scan then
        for fx = 0, pw - 1 do
          scan[ox + fx + 1] = black
        end
      end
    end
  end

  box:render()
  self.force = false
  self.display_on = on
  return true, lay, 1
end

function M.paint(mon, fb, display_on, opts)
  local p = M.new_painter(mon, opts)
  local lay = p:setup()
  if not lay.ok then return false, lay end
  p.force = true
  return p:paint(fb, display_on)
end

M.Painter = Painter
return M
