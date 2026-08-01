-- Generic 1bpp LCD painter for Tom's GPU.
-- Usage: return require("frontends.computercraft.lcd_view_gpu_1bpp").make(geom, colors?)

local Gpu = require("frontends.computercraft.gpu")

local function bit_test(byte, bitn)
  return math.floor(byte / (2 ^ bitn)) % 2 == 1
end

local function make(geom, colors)
  assert(geom and geom.WIDTH and geom.HEIGHT and geom.BYTES_PER_ROW)
  colors = colors or {}
  local COLOR_BG = colors.bg or Gpu.argb(0.48, 0.58, 0.52)
  local COLOR_ON = colors.on or Gpu.argb(0.08, 0.14, 0.12)
  local COLOR_BEZEL = colors.bezel or Gpu.argb(0.42, 0.44, 0.46)
  local COLOR_BEZEL_INNER = colors.bezel_inner or Gpu.argb(0.22, 0.24, 0.25)
  local COLOR_OFF_GLASS = colors.off or Gpu.argb(0.35, 0.40, 0.37)

  local M = {}
  M.__index = M
  M.WIDTH = geom.WIDTH
  M.HEIGHT = geom.HEIGHT
  M.BYTES_PER_ROW = geom.BYTES_PER_ROW

  function M.new(gpu, glass)
    return setmetatable({
      gpu = gpu,
      glass = glass or { x = 0, y = 0, w = 0, h = 0 },
      cell = 2,
      max_w = nil,
      max_h = nil,
    }, M)
  end

  function M:set_glass(glass)
    self.glass = glass
  end

  function M:set_bounds(max_w, max_h)
    self.max_w, self.max_h = max_w, max_h
  end

  function M:set_cell(cell)
    self.cell = math.max(1, math.floor(tonumber(cell) or 2))
  end

  function M:paint(fb, display_on)
    local gpu = self.gpu
    local glass = self.glass
    if not gpu or not glass or glass.w < 4 or glass.h < 4 then
      return
    end
    local mw, mh = self.max_w, self.max_h
    local cell = self.cell or 1
    if cell < 1 then cell = 1 end
    local pix = (cell >= 2) and (cell - 1) or 1
    local dw = geom.WIDTH * cell
    local dh = geom.HEIGHT * cell
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
      local bpr = geom.BYTES_PER_ROW
      for row = 0, geom.HEIGHT - 1 do
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
  end

  return M
end

return { make = make }
