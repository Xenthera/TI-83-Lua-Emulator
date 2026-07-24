-- Paint the 96x64 TI LCD onto a wrapped ComputerCraft monitor (blit).
-- Uses the smallest text scale (0.5), 1:1 character cells, centered on a
-- black letterbox. Too-small monitors show a red error instead.

local Lcd = require("core.hw.lcd")
local CC = require("frontend.computercraft.cc")

local M = {}

M.TEXT_SCALE = 0.5
M.NEED_W = Lcd.WIDTH   -- 96
M.NEED_H = Lcd.HEIGHT  -- 64

local function bit_lit(byte, bitn)
  local mask = 2 ^ (7 - bitn)
  return math.floor(byte / mask) % 2 == 1
end

--- Apply smallest text scale and black clear. Call on attach / resize.
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
  mon.setBackgroundColor(C.black)
  mon.setTextColor(C.white)
  mon.clear()
  mon.setCursorPos(1, 1)
end

--- Layout for the current monitor size (after setup / setTextScale).
-- Returns:
--   ok=true,  mw, mh, x0, y0  — top-left of 96x64 window (1-based)
--   ok=false, mw, mh, need    — need is "96x64" string for the error line
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
  local x0 = math.floor((mw - M.NEED_W) / 2) + 1
  local y0 = math.floor((mh - M.NEED_H) / 2) + 1
  return {
    ok = true,
    mw = mw,
    mh = mh,
    x0 = x0,
    y0 = y0,
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
    if x < 1 then
      x = 1
    end
    mon.setCursorPos(x, y)
    mon.write(text:sub(1, lay.mw))
  end
  local mid = math.max(1, math.floor(lay.mh / 2))
  center_write(mid, msg)
  if lay.mh >= 2 then
    center_write(mid + 1, size)
  end
end

--- Paint framebuffer 1:1, centered, black borders. Or red "too small" message.
function M.paint(mon, fb, display_on, opts)
  opts = opts or {}
  local C = CC.colors()
  -- Lit pixels: dark green (colors.green). Off: lime LCD glass.
  local col_on = opts.on or C.green
  local col_off = opts.off or C.lime
  local col_border = opts.border or C.black
  if not display_on then
    col_on = col_off
  end

  local lay = M.layout(mon)
  if not lay.ok then
    paint_too_small(mon, lay)
    return false, lay
  end

  local bpr = Lcd.BYTES_PER_ROW
  local blit_on = CC.to_blit(col_on)
  local blit_off = CC.to_blit(col_off)
  local blit_border = CC.to_blit(col_border)
  local x0, y0 = lay.x0, lay.y0
  local x1 = x0 + M.NEED_W - 1
  local y1 = y0 + M.NEED_H - 1

  for cy = 1, lay.mh do
    local chars = {}
    local fg = {}
    local bg = {}
    local in_row = cy >= y0 and cy <= y1
    local ly = in_row and (cy - y0) or 0
    for cx = 1, lay.mw do
      local lit = false
      local border = true
      if in_row and cx >= x0 and cx <= x1 then
        border = false
        local lx = cx - x0
        if fb and display_on then
          local byte = fb[ly * bpr + math.floor(lx / 8)] or 0
          lit = bit_lit(byte, lx % 8)
        end
      end
      chars[cx] = " "
      if border then
        fg[cx] = blit_border
        bg[cx] = blit_border
      else
        fg[cx] = blit_off
        bg[cx] = lit and blit_on or blit_off
      end
    end
    mon.setCursorPos(1, cy)
    mon.blit(table.concat(chars), table.concat(fg), table.concat(bg))
  end
  return true, lay
end

return M
