-- TI-89 LCD on Tom's GPU: true 1x1 GPU pixels (optional gap matrix).
-- Default cell=2 → each lit TI pixel is a 1x1 rect with 1px substrate gap.

local Lcd = require("machines.ti89.lcd_geom")
local Gpu = require("frontends.computercraft.gpu")

local M = {}
M.__index = M

M.WIDTH = Lcd.WIDTH
M.HEIGHT = Lcd.HEIGHT
M.BYTES_PER_ROW = Lcd.BYTES_PER_ROW

local COLOR_BG = Gpu.argb(0.48, 0.58, 0.52)
local COLOR_ON = Gpu.argb(0.08, 0.14, 0.12)
local COLOR_BEZEL = Gpu.argb(0.42, 0.44, 0.46)
local COLOR_BEZEL_INNER = Gpu.argb(0.22, 0.24, 0.25)
local COLOR_OFF_GLASS = Gpu.argb(0.35, 0.40, 0.37)

local function bit_test(byte, bitn)
  return math.floor(byte / (2 ^ bitn)) % 2 == 1
end

function M.new(gpu, glass)
  return setmetatable({
    gpu = gpu,
    glass = glass or { x = 0, y = 0, w = 0, h = 0 },
    cell = 2,
    max_w = nil,
    max_h = nil,
    last = nil,
  }, M)
end

function M:set_glass(glass)
  self.glass = glass
  self.last = nil
end

function M:set_bounds(max_w, max_h)
  self.max_w, self.max_h = max_w, max_h
end

function M:set_cell(cell)
  self.cell = math.max(1, math.floor(tonumber(cell) or 2))
  self.last = nil
end

--- Paint framebuffer. Lit body = cell-1, always a 1px gap between dots.
function M:paint(fb, display_on)
  local gpu = self.gpu
  local glass = self.glass
  if not gpu or not glass or glass.w < 4 or glass.h < 4 then
    return
  end
  local mw, mh = self.max_w, self.max_h
  local cell = self.cell or 1
  if cell < 1 then cell = 1 end
  -- 1px gap between adjacent lit pixels: draw (cell-1)x(cell-1) in each cell.
  local pix = (cell >= 2) and (cell - 1) or 1
  local dw = Lcd.WIDTH * cell
  local dh = Lcd.HEIGHT * cell
  local x0 = math.floor(glass.x + (glass.w - dw) / 2)
  local y0 = math.floor(glass.y + (glass.h - dh) / 2)

  local bz_outer = math.max(2, math.floor(cell * 1.2 + 0.5))
  local bz_inner = math.max(1, math.floor(cell * 0.5 + 0.5))

  Gpu.rect(gpu, x0 - bz_outer, y0 - bz_outer, dw + bz_outer * 2, dh + bz_outer * 2,
    COLOR_BEZEL, mw, mh)
  Gpu.rect(gpu, x0 - bz_inner, y0 - bz_inner, dw + bz_inner * 2, dh + bz_inner * 2,
    COLOR_BEZEL_INNER, mw, mh)

  local glass_col = display_on and COLOR_BG or COLOR_OFF_GLASS
  Gpu.rect(gpu, x0, y0, dw, dh, glass_col, mw, mh)

  if fb and display_on then
    local bpr = Lcd.BYTES_PER_ROW
    for row = 0, Lcd.HEIGHT - 1 do
      local py = y0 + row * cell
      for col = 0, bpr - 1 do
        local byte = fb[row * bpr + col] or 0
        if byte ~= 0 then
          for bit = 0, 7 do
            if bit_test(byte, 7 - bit) then
              local lx = col * 8 + bit
              Gpu.rect(gpu, x0 + lx * cell, py, pix, pix, COLOR_ON, mw, mh)
            end
          end
        end
      end
    end
  end

  self.last = { x = x0, y = y0, w = dw, h = dh, cell = cell }
end

return M
