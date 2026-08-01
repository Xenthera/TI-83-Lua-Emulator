-- Shared CC LCD painter: 1bpp framebuffer → teletext sixtels (2×3 px / char).
-- Same \128-\159 encoding as pixelbox_lite; keypad monitors are unchanged.
-- No machine/CPU deps — only frontends.computercraft.cc.

local CC = require("frontends.computercraft.cc")

--- True if FB pixel (0-based x,y) is lit. Out-of-bounds → false (pad).
local function fb_lit(fb, bpr, width, height, x, y)
  if not fb or x < 0 or y < 0 or x >= width or y >= height then
    return false
  end
  local byte = fb[y * bpr + math.floor(x / 8)] or 0
  local mask = 2 ^ (7 - (x % 8))
  return (byte % (mask + mask) >= mask)
end

--- Pack six booleans into a sixtel char + fg/bg blit nybbles (CC teletext).
-- Pixel layout (cols L/R, rows top→bottom): p1 p2 / p3 p4 / p5 p6
local function pack_sixtel(p1, p2, p3, p4, p5, p6, blit_on, blit_off)
  local bg_on = not not p6
  local char = 128
  if (not not p1) ~= bg_on then char = char + 1 end
  if (not not p2) ~= bg_on then char = char + 2 end
  if (not not p3) ~= bg_on then char = char + 4 end
  if (not not p4) ~= bg_on then char = char + 8 end
  if (not not p5) ~= bg_on then char = char + 16 end
  if bg_on then
    return string.char(char), blit_off, blit_on
  end
  return string.char(char), blit_on, blit_off
end

--- Build one character-row (covers three FB rows starting at fb_y0).
local function encode_char_row(fb, bpr, width, height, fb_y0, blit_on, blit_off, chars_w)
  local ch, fg, bg = {}, {}, {}
  local y1, y2, y3 = fb_y0, fb_y0 + 1, fb_y0 + 2
  for cx = 0, chars_w - 1 do
    local x0 = cx * 2
    local c, f, b = pack_sixtel(
      fb_lit(fb, bpr, width, height, x0, y1),
      fb_lit(fb, bpr, width, height, x0 + 1, y1),
      fb_lit(fb, bpr, width, height, x0, y2),
      fb_lit(fb, bpr, width, height, x0 + 1, y2),
      fb_lit(fb, bpr, width, height, x0, y3),
      fb_lit(fb, bpr, width, height, x0 + 1, y3),
      blit_on, blit_off
    )
    ch[cx + 1] = c
    fg[cx + 1] = f
    bg[cx + 1] = b
  end
  return table.concat(ch), table.concat(fg), table.concat(bg)
end

--- Build an LCD view bound to { WIDTH, HEIGHT, BYTES_PER_ROW }.
local function create(Lcd)
  local M = {}
  M.PIXEL_W = Lcd.WIDTH
  M.PIXEL_H = Lcd.HEIGHT
  M.BPR = Lcd.BYTES_PER_ROW
  -- Sixtel: 2×3 framebuffer pixels per monitor character cell.
  M.NEED_W = math.ceil(Lcd.WIDTH / 2)
  M.NEED_H = math.ceil(Lcd.HEIGHT / 3)
  -- Keep 0.5 so physical monitor blocks shrink with sixtels.
  -- (Scale 1.0 halves cells/block and cancels the 2× width win.)
  M.TEXT_SCALE = 0.5

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
        pixels = M.PIXEL_W .. "x" .. M.PIXEL_H,
      }
    end
    return {
      ok = true,
      mw = mw,
      mh = mh,
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
    local msg = "monitor too small (needs " .. lay.need .. " sixtel)"
    local size = "now " .. tostring(lay.mw) .. "x" .. tostring(lay.mh)
    local px = lay.pixels and ("LCD " .. lay.pixels .. " @ 2x3") or nil
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
    if px and lay.mh >= 3 then
      center_write(mid + 2, px)
    end
  end

  local Painter = {}
  Painter.__index = Painter

  function M.new_painter(mon, opts)
    opts = opts or {}
    return setmetatable({
      mon = mon,
      opts = opts,
      lay = nil,
      blit_on = nil,
      blit_off = nil,
      last_ch = {},
      last_fg = {},
      last_bg = {},
      force = true,
      display_on = true,
    }, Painter)
  end

  function Painter:rebind(mon)
    self.mon = mon
    self.force = true
  end

  function Painter:_rebuild_colors()
    local C = CC.colors()
    local col_on = self.opts.on or C.green
    local col_off = self.opts.off or C.lime
    self.blit_on = CC.to_blit(col_on)
    self.blit_off = CC.to_blit(col_off)
    self.col_off = col_off
    self.last_ch, self.last_fg, self.last_bg = {}, {}, {}
    self.force = true
  end

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

  function Painter:paint(fb, display_on)
    local lay = self.lay or M.layout(self.mon)
    self.lay = lay
    if not lay.ok then
      paint_too_small(self.mon, lay)
      return false, lay, 0
    end

    if not self.blit_on then
      self:_rebuild_colors()
    end

    local on = not not display_on
    if on ~= self.display_on then
      self.display_on = on
      self.force = true
    end

    local mon = self.mon
    local blit_on, blit_off = self.blit_on, self.blit_off
    local last_ch, last_fg, last_bg = self.last_ch, self.last_fg, self.last_bg
    local force = self.force
    local x0, y0 = lay.x0, lay.y0
    local bpr = M.BPR
    local pw, ph = M.PIXEL_W, M.PIXEL_H
    local chars_w, chars_h = M.NEED_W, M.NEED_H
    local blitted = 0
    local use_fb = on and fb or nil

    for cy = 0, chars_h - 1 do
      local ch, fg, bg = encode_char_row(
        use_fb, bpr, pw, ph, cy * 3, blit_on, blit_off, chars_w
      )
      if force or last_ch[cy] ~= ch or last_fg[cy] ~= fg or last_bg[cy] ~= bg then
        mon.setCursorPos(x0, y0 + cy)
        mon.blit(ch, fg, bg)
        last_ch[cy], last_fg[cy], last_bg[cy] = ch, fg, bg
        blitted = blitted + 1
      end
    end
    self.force = false
    return true, lay, blitted
  end

  function M.paint(mon, fb, display_on, opts)
    local p = M.new_painter(mon, opts)
    local lay = p:setup()
    if not lay.ok then
      return false, lay
    end
    p.force = true
    return p:paint(fb, display_on)
  end

  M.Painter = Painter
  return M
end

return { create = create }
