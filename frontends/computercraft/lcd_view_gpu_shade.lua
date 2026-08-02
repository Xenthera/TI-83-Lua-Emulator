-- Shade (0-3) LCD painter for Tom's GPU (Game Boy DMG).
-- Usage: return require("frontends.computercraft.lcd_view_gpu_shade").make(geom [, opts])
-- opts.palette: optional { [0]=argb, ... [3]=argb, bezel=, off= }

local Gpu = require("frontends.computercraft.gpu")

-- Classic DMG LCD greens (match Love2D render_gameboy / theme "original").
local DMG_SHADE = {
  [0] = Gpu.argb(0.61, 0.73, 0.06), -- lightest
  [1] = Gpu.argb(0.42, 0.55, 0.05),
  [2] = Gpu.argb(0.22, 0.35, 0.04),
  [3] = Gpu.argb(0.06, 0.14, 0.02), -- darkest
  bezel = Gpu.argb(0.12, 0.16, 0.04),
  off = Gpu.argb(0.08, 0.12, 0.04),
}

local function copy_palette(src)
  src = src or DMG_SHADE
  return {
    [0] = src[0] or DMG_SHADE[0],
    [1] = src[1] or DMG_SHADE[1],
    [2] = src[2] or DMG_SHADE[2],
    [3] = src[3] or DMG_SHADE[3],
    bezel = src.bezel or DMG_SHADE.bezel,
    off = src.off or DMG_SHADE.off,
  }
end

local function make(geom, opts)
  assert(geom and geom.WIDTH and geom.HEIGHT)
  opts = opts or {}
  local default_pal = copy_palette(opts.palette)
  local M = {}
  M.__index = M
  M.WIDTH = geom.WIDTH
  M.HEIGHT = geom.HEIGHT

  function M.new(gpu, glass)
    return setmetatable({
      gpu = gpu,
      glass = glass or { x = 0, y = 0, w = 0, h = 0 },
      cell = 1,
      max_w = nil,
      max_h = nil,
      shade = copy_palette(default_pal),
      _bez_drawn = false,
      _x0 = 0,
      _y0 = 0,
      _dw = 0,
      _dh = 0,
    }, M)
  end

  function M:set_glass(glass)
    self.glass = glass
    self._bez_drawn = false
  end
  function M:set_bounds(max_w, max_h) self.max_w, self.max_h = max_w, max_h end
  function M:set_cell(cell)
    self.cell = math.max(1, math.floor(tonumber(cell) or 1))
    self._bez_drawn = false
  end

  --- Apply a 4-shade RGB palette (theme change). Forces bezel redraw.
  function M:set_palette(pal)
    self.shade = copy_palette(pal)
    self._bez_drawn = false
  end

  function M:paint(fb, display_on)
    local gpu = self.gpu
    local glass = self.glass
    if not gpu or not glass or glass.w < 4 then return end
    local mw, mh = self.max_w, self.max_h
    local cell = self.cell or 1
    local dw = geom.WIDTH * cell
    local dh = geom.HEIGHT * cell
    local x0 = math.floor(glass.x + (glass.w - dw) / 2)
    local y0 = math.floor(glass.y + (glass.h - dh) / 2)
    local fill = gpu.filledRectangle
    local pal = self.shade or DMG_SHADE
    local bezel = pal.bezel or DMG_SHADE.bezel
    local off = pal.off or DMG_SHADE.off

    if not self._bez_drawn or self._x0 ~= x0 or self._y0 ~= y0
        or self._dw ~= dw or self._dh ~= dh then
      Gpu.rect(gpu, x0 - 2, y0 - 2, dw + 4, dh + 4, bezel, mw, mh)
      self._bez_drawn = true
      self._x0, self._y0, self._dw, self._dh = x0, y0, dw, dh
    end
    if not display_on or not fb then
      Gpu.rect(gpu, x0, y0, dw, dh, off, mw, mh)
      return
    end

    local W = geom.WIDTH
    local H = geom.HEIGHT
    if fill and cell == 1 then
      for row = 0, H - 1 do
        local py = y0 + row
        local base = row * W
        local run_s = fb[base] or 0
        if run_s > 3 then run_s = 3 elseif run_s < 0 then run_s = 0 end
        local run_x = 0
        local run_w = 1
        for col = 1, W - 1 do
          local s = fb[base + col] or 0
          if s > 3 then s = 3 elseif s < 0 then s = 0 end
          if s == run_s then
            run_w = run_w + 1
          else
            pcall(fill, x0 + run_x, py, run_w, 1, pal[run_s])
            run_s = s
            run_x = col
            run_w = 1
          end
        end
        pcall(fill, x0 + run_x, py, run_w, 1, pal[run_s])
      end
    else
      for row = 0, H - 1 do
        local py = y0 + row * cell
        local base = row * W
        local run_s = fb[base] or 0
        if run_s > 3 then run_s = 3 elseif run_s < 0 then run_s = 0 end
        local run_x = 0
        local run_w = 1
        for col = 1, W - 1 do
          local s = fb[base + col] or 0
          if s > 3 then s = 3 elseif s < 0 then s = 0 end
          if s == run_s then
            run_w = run_w + 1
          else
            Gpu.rect(gpu, x0 + run_x * cell, py, run_w * cell, cell, pal[run_s], mw, mh)
            run_s = s
            run_x = col
            run_w = 1
          end
        end
        Gpu.rect(gpu, x0 + run_x * cell, py, run_w * cell, cell, pal[run_s], mw, mh)
      end
    end
  end

  return M
end

return { make = make, DMG_SHADE = DMG_SHADE }
