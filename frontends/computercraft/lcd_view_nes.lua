-- NES LCD for ComputerCraft: 256x240 palette indices via pixelbox_lite.
-- Each NES color is quantized to the nearest of CC's 16 default colors.

local CC = require("frontends.computercraft.cc")
local Pixelbox = require("frontends.computercraft.vendor.pixelbox_lite")
local NesPal = require("machines.nes.palette")

local M = {}
M.PIXEL_W = 256
M.PIXEL_H = 240
-- Soft minimum: scaled paint still works on smaller monitors.
M.NEED_W = 40
M.NEED_H = 20
M.TEXT_SCALE = 0.5

-- Default CraftOS / CC:Tweaked monitor palette (sRGB 0..255).
local CC_RGB = {
  { "white", 240, 240, 240 },
  { "orange", 242, 178, 51 },
  { "magenta", 229, 127, 216 },
  { "lightBlue", 153, 178, 242 },
  { "yellow", 222, 222, 108 },
  { "lime", 127, 204, 25 },
  { "pink", 242, 178, 204 },
  { "gray", 76, 76, 76 },
  { "lightGray", 153, 153, 153 },
  { "cyan", 76, 153, 178 },
  { "purple", 178, 102, 229 },
  { "blue", 51, 102, 204 },
  { "brown", 127, 102, 76 },
  { "green", 87, 166, 78 },
  { "red", 204, 76, 76 },
  { "black", 17, 17, 17 },
}

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

--- Build NES index 0..63 -> CC colors.* LUT (nearest Euclidean RGB).
function M.build_lut(C)
  C = C or CC.colors()
  local entries = {}
  for _, e in ipairs(CC_RGB) do
    local name, r, g, b = e[1], e[2], e[3], e[4]
    local col = C[name]
    if col then
      entries[#entries + 1] = { col = col, r = r, g = g, b = b }
    end
  end
  local lut = {}
  for i = 0, 63 do
    local rgb = NesPal.rgb(i)
    local nr = (rgb[1] or 0) * 255
    local ng = (rgb[2] or 0) * 255
    local nb = (rgb[3] or 0) * 255
    local best, best_d = entries[1].col, 1e18
    for _, e in ipairs(entries) do
      local dr, dg, db = nr - e.r, ng - e.g, nb - e.b
      local d = dr * dr + dg * dg + db * db
      if d < best_d then
        best_d = d
        best = e.col
      end
    end
    lut[i] = best
  end
  return lut
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

--- Fit 256x240 into the monitor's sixtel canvas; returns draw size + origin.
function M.layout(mon)
  local mw, mh = mon.getSize()
  local max_w = mw * 2
  local max_h = mh * 3
  if mw < M.NEED_W or mh < M.NEED_H or max_w < 16 or max_h < 16 then
    return {
      ok = false, mw = mw, mh = mh,
      need = M.NEED_W .. "x" .. M.NEED_H,
      pixels = M.PIXEL_W .. "x" .. M.PIXEL_H,
    }
  end
  local scale = math.min(max_w / M.PIXEL_W, max_h / M.PIXEL_H)
  local dw = math.max(1, math.floor(M.PIXEL_W * scale + 1e-6))
  local dh = math.max(1, math.floor(M.PIXEL_H * scale + 1e-6))
  if dw > max_w then dw = max_w end
  if dh > max_h then dh = max_h end
  local ox = math.floor((max_w - dw) / 2)
  local oy = math.floor((max_h - dh) / 2)
  return {
    ok = true, mw = mw, mh = mh,
    dw = dw, dh = dh, ox = ox, oy = oy,
    need = M.NEED_W .. "x" .. M.NEED_H,
    pixels = M.PIXEL_W .. "x" .. M.PIXEL_H,
    scale = scale,
  }
end

local function paint_too_small(mon, lay)
  local C = CC.colors()
  mon.setBackgroundColor(C.black)
  mon.clear()
  mon.setTextColor(C.red)
  local msg = "monitor too small (needs ~" .. lay.need .. " chars for NES)"
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
    _lut = M.build_lut(C),
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
  self._lut = M.build_lut(C)
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
  self._lut = M.build_lut(self._C)
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
  local lut = self._lut
  local C = self._C
  local frame = self.opts.frame or C.black
  local pw, ph = M.PIXEL_W, M.PIXEL_H
  local dw, dh = lay.dw, lay.dh
  local ox, oy = lay.ox, lay.oy

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

  if on and fb then
    -- Nearest-neighbor scale into the fitted rect; each sample -> quantized CC color.
    for cy = 0, dh - 1 do
      local scan = canvas[oy + cy + 1]
      if scan then
        local fy = math.floor(cy * ph / dh)
        if fy >= ph then fy = ph - 1 end
        local row = fy * pw
        local base = ox
        for cx = 0, dw - 1 do
          local fx = math.floor(cx * pw / dw)
          if fx >= pw then fx = pw - 1 end
          local idx = fb[row + fx] or 0x0F
          if idx < 0 then idx = 0 elseif idx > 63 then idx = idx % 64 end
          scan[base + cx + 1] = lut[idx] or C.black
        end
      end
    end
  else
    local black = C.black
    for cy = 0, dh - 1 do
      local scan = canvas[oy + cy + 1]
      if scan then
        for cx = 0, dw - 1 do
          scan[ox + cx + 1] = black
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
