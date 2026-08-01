-- Generic calculator face layout for Tom's GPU (LCD above keypad).
-- Usage: return require("frontends.computercraft.face_gpu").make({ ... })

local Gpu = require("frontends.computercraft.gpu")

local DEFAULT_SHELL = Gpu.argb(0.18, 0.19, 0.20)
local DEFAULT_BRAND = Gpu.argb(0.75, 0.78, 0.80)
local DEFAULT_BG = Gpu.argb(0.08, 0.08, 0.09)

local function make(opts)
  opts = opts or {}
  local WIDTH = assert(opts.width, "face_gpu: width")
  local HEIGHT = assert(opts.height, "face_gpu: height")
  local BRAND = opts.brand or ""
  local MIN_KEYS = opts.min_keys or 40
  local PAD = opts.pad or 4
  local COLOR_SHELL = opts.shell_color or DEFAULT_SHELL
  local COLOR_BRAND = opts.brand_color or DEFAULT_BRAND
  local COLOR_BG = opts.bg_color or DEFAULT_BG

  local M = {}
  M.__index = M
  M.WIDTH = WIDTH
  M.HEIGHT = HEIGHT

  function M.new(gpu)
    return setmetatable({
      gpu = gpu,
      lcd_rect = { x = 0, y = 0, w = 0, h = 0 },
      pad_rect = { x = 0, y = 0, w = 0, h = 0 },
      shell = { x = 0, y = 0, w = 0, h = 0 },
      lcd_cell = 1,
      gw = 0,
      gh = 0,
    }, M)
  end

  function M:layout(gw, gh, _opts)
    self.gw, self.gh = gw, gh
    local avail_w = gw - PAD * 2
    local avail_h = gh - PAD * 2
    if avail_w < 40 or avail_h < 80 then
      self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
      self.pad_rect = { x = 0, y = 0, w = 0, h = 0 }
      self.need_w, self.need_h = 48, 100
      return false
    end

    local brand = math.max(8, math.floor(avail_h * 0.045 + 0.5))
    local shell = math.max(4, math.floor(avail_h * 0.018 + 0.5))
    local gap = math.max(3, math.floor(avail_h * 0.015 + 0.5))
    local chrome = brand + shell * 2
    local body_h = avail_h - chrome
    if body_h < HEIGHT + MIN_KEYS + gap then
      self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
      self.pad_rect = { x = 0, y = 0, w = 0, h = 0 }
      self.need_w = chrome + WIDTH + PAD * 2
      self.need_h = chrome + HEIGHT + MIN_KEYS + gap + PAD * 2
      return false
    end

    local max_by_w = math.max(1, math.floor((avail_w - shell * 2) / WIDTH))
    local max_by_h = math.max(1, math.floor((body_h - gap - MIN_KEYS) / HEIGHT))
    local cell = math.min(max_by_w, max_by_h)
    if cell < 1 then cell = 1 end

    local glass_w = cell * WIDTH
    local glass_h = cell * HEIGHT
    local keys_h = body_h - gap - glass_h
    while cell > 1 and keys_h < MIN_KEYS do
      cell = cell - 1
      glass_w = cell * WIDTH
      glass_h = cell * HEIGHT
      keys_h = body_h - gap - glass_h
    end
    if keys_h < 24 then
      self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
      self.pad_rect = { x = 0, y = 0, w = 0, h = 0 }
      return false
    end

    local face_w = glass_w
    self.lcd_cell = cell
    local stack_h = glass_h + gap + keys_h
    local total_h = stack_h + chrome
    local x0 = 1 + PAD + math.floor((avail_w - face_w) / 2)
    local y0 = 1 + PAD + shell + brand
    if x0 < 1 then x0 = 1 end
    if y0 < 1 then y0 = 1 end

    self.shell = {
      x = x0 - shell,
      y = y0 - shell - brand,
      w = face_w + shell * 2,
      h = total_h,
    }
    self.brand_gap = brand
    self.need_w = math.ceil(face_w + shell * 2 + PAD * 2)
    self.need_h = math.ceil(total_h + PAD * 2)
    self.lcd_rect = { x = x0, y = y0, w = glass_w, h = glass_h }
    self.pad_rect = {
      x = x0,
      y = y0 + glass_h + gap,
      w = face_w,
      h = keys_h,
    }
    return true
  end

  function M:draw_chrome()
    local gpu = self.gpu
    local s = self.shell
    if not gpu or not s or s.w < 4 then return end
    local mw, mh = self.gw, self.gh
    Gpu.fill(gpu, COLOR_BG)
    Gpu.rect(gpu, s.x, s.y, s.w, s.h, COLOR_SHELL, mw, mh)
    if BRAND ~= "" and self.brand_gap and self.brand_gap > 6 and gpu.drawText then
      local label = BRAND
      local tw = #label * 6
      if gpu.getTextLength then
        local ok, len = pcall(gpu.getTextLength, label, 1)
        if ok then tw = tonumber(len) or tw end
      end
      local tx = math.floor(s.x + (s.w - tw) * 0.5)
      local ty = math.floor(s.y + (self.brand_gap - 8) * 0.5)
      if tx < 1 then tx = 1 end
      if ty < 1 then ty = 1 end
      pcall(gpu.drawText, tx, ty, label, COLOR_BRAND, Gpu.TEXT_BG_NONE, 1)
    end
  end

  return M
end

return { make = make }
