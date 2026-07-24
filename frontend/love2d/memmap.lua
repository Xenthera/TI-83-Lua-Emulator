-- Memory panel: one pixel per byte (64KB as 256x256).
-- Uniform scale (square pixels), region tint, write heat, PC/SP markers.

local MemMap = {}
MemMap.__index = MemMap

local MEM_SIZE = 65536
local MAP_W = 256
local MAP_H = 256

local COLLAPSED_W = 18
local EXPANDED_W = 340
local FOOTER_H = 18

local REGION = {
  { 0.30, 0.50, 1.00 }, -- FLASH
  { 0.80, 0.35, 1.00 }, -- BANKA
  { 0.25, 0.95, 0.50 }, -- RAM8
  { 1.00, 0.80, 0.25 }, -- RAMC
}
local REGION_NAME = { "FLASH", "BANKA", "RAM8", "RAMC" }

local function clamp01(x)
  if x < 0 then return 0 end
  if x > 1 then return 1 end
  return x
end

local function byte_rgb(addr, val, heat)
  local reg = math.floor(addr / 0x4000) % 4
  local base = REGION[reg + 1]
  local t = val / 255
  local lum = (val == 0) and 0.07 or (0.20 + t * 0.80)
  local band = ((val % 32) / 31) * 0.10
  local r = clamp01(base[1] * lum + band)
  local g = clamp01(base[2] * lum + band * 0.5)
  local b = clamp01(base[3] * lum)
  if heat and heat > 0 then
    local h = heat > 1 and 1 or heat
    r = r + (1.0 - r) * h
    g = g + (0.95 - g) * h
    b = b * (1 - h * 0.6)
  end
  return math.floor(r * 255 + 0.5), math.floor(g * 255 + 0.5), math.floor(b * 255 + 0.5)
end

local function rgba(r, g, b)
  return string.char(r, g, b, 255)
end

function MemMap.new()
  local self = setmetatable({}, MemMap)
  self.open = false
  self.w = MAP_W
  self.h = MAP_H
  self.image = nil
  self.accum = 0
  self.refresh_hz = 15
  self.needs_refresh = false
  self.hover_addr = nil
  self.hover_val = nil
  self.panel = { x = 0, y = 0, w = COLLAPSED_W, h = 0 }
  self.toggle = { x = 0, y = 0, w = COLLAPSED_W, h = 0 }
  self.scale = 1
  self.prev_blob = nil
  self.heat = {}
  self.heat_decay = 1.6
  self.pc = 0
  self.sp = 0
  return self
end

function MemMap:width()
  return self.open and EXPANDED_W or COLLAPSED_W
end

function MemMap:toggle_open()
  self.open = not self.open
  if self.open then
    self.needs_refresh = true
    self.accum = 1
  end
  return self.open
end

function MemMap:layout(x, y, h)
  local w = self:width()
  self.panel = { x = x, y = y, w = w, h = h }
  self.toggle = { x = x, y = y, w = COLLAPSED_W, h = h }
  if not self.open then
    self.scale = 1
    self.img_x, self.img_y, self.img_w, self.img_h = x, y, 0, 0
    return
  end

  local avail_x = x + COLLAPSED_W
  local avail_y = y
  local avail_w = w - COLLAPSED_W
  local avail_h = math.max(1, h - FOOTER_H)

  -- Uniform scale so pixels stay square (not stretched flat).
  local scale = math.min(avail_w / MAP_W, avail_h / MAP_H)
  if scale < 0.5 then scale = 0.5 end
  self.scale = scale
  self.w = MAP_W
  self.h = MAP_H
  self.img_w = MAP_W * scale
  self.img_h = MAP_H * scale
  self.img_x = avail_x + (avail_w - self.img_w) / 2
  self.img_y = avail_y + (avail_h - self.img_h) / 2
  self.footer_y = y + h - FOOTER_H
end

local function paint_cross(chunks, addr, r, g, b)
  if addr < 0 or addr >= MEM_SIZE then return end
  local pix = rgba(r, g, b)
  local function put(a)
    if a >= 0 and a < MEM_SIZE then chunks[a + 1] = pix end
  end
  put(addr)
  put(addr - 1)
  put(addr + 1)
  put(addr - MAP_W)
  put(addr + MAP_W)
end

function MemMap:refresh(machine)
  if not machine or not machine.rom_loaded then
    self.needs_refresh = false
    return
  end

  local mmu = machine.mmu
  local pc = machine.cpu.pc % MEM_SIZE
  local sp = machine.cpu.sp % MEM_SIZE
  self.pc = pc
  self.sp = sp

  local prev = self.prev_blob
  local heat = self.heat
  local chunks = {}
  local snap = {}

  for addr = 0, MEM_SIZE - 1 do
    local val = mmu:read(addr)
    snap[addr + 1] = string.char(val)
    local h = heat[addr]
    if prev then
      local old = prev:byte(addr + 1)
      if old ~= val then
        h = 1
        heat[addr] = 1
      end
    end
    local r, g, b = byte_rgb(addr, val, h)
    chunks[addr + 1] = rgba(r, g, b)
  end

  self.prev_blob = table.concat(snap)

  paint_cross(chunks, pc, 40, 255, 255)
  paint_cross(chunks, sp, 255, 70, 220)

  local data = table.concat(chunks)
  local ok, id = pcall(love.image.newImageData, MAP_W, MAP_H, "rgba8", data)
  if ok then
    self.image = love.graphics.newImage(id)
    self.image:setFilter("nearest", "nearest")
  end
  self.needs_refresh = false
end

function MemMap:update(dt, machine)
  if not self.open then return end

  local decay = dt * self.heat_decay
  if decay > 0 then
    for addr, h in pairs(self.heat) do
      h = h - decay
      if h <= 0.02 then
        self.heat[addr] = nil
      else
        self.heat[addr] = h
      end
    end
  end

  if self.needs_refresh then
    self:refresh(machine)
    self.accum = 0
    return
  end
  self.accum = self.accum + dt
  if self.accum >= 1 / self.refresh_hz then
    self.accum = 0
    self:refresh(machine)
  end
end

function MemMap:addr_at(mx, my)
  if not self.open or self.img_w <= 0 then return nil end
  if mx < self.img_x or my < self.img_y
      or mx >= self.img_x + self.img_w or my >= self.img_y + self.img_h then
    return nil
  end
  local px = math.floor((mx - self.img_x) / self.scale)
  local py = math.floor((my - self.img_y) / self.scale)
  if px < 0 or py < 0 or px >= MAP_W or py >= MAP_H then return nil end
  return py * MAP_W + px
end

function MemMap:hit_toggle(mx, my)
  local t = self.toggle
  return mx >= t.x and my >= t.y and mx < t.x + t.w and my < t.y + t.h
end

function MemMap:contains(mx, my)
  local p = self.panel
  return mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h
end

function MemMap:mousepressed(mx, my)
  if self:hit_toggle(mx, my) then
    self:toggle_open()
    return true
  end
  return self:contains(mx, my)
end

function MemMap:mousemoved(mx, my, machine)
  if not self.open then
    self.hover_addr = nil
    self.hover_val = nil
    return
  end
  self.hover_addr = self:addr_at(mx, my)
  if self.hover_addr and machine and machine.rom_loaded then
    self.hover_val = machine.mmu:read(self.hover_addr)
  else
    self.hover_val = nil
  end
end

function MemMap:draw()
  local p = self.panel
  love.graphics.setColor(0.12, 0.13, 0.15, 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h)
  love.graphics.setColor(0.25, 0.28, 0.26, 1)
  love.graphics.line(p.x, p.y, p.x, p.y + p.h)

  local hot = self:hit_toggle(love.mouse.getPosition())
  love.graphics.setColor(hot and 0.28 or 0.18, hot and 0.32 or 0.2, hot and 0.28 or 0.2, 1)
  love.graphics.rectangle("fill", self.toggle.x, self.toggle.y, self.toggle.w, self.toggle.h)
  love.graphics.setColor(0.75, 0.8, 0.72, 1)
  local label = self.open and ">" or "<"
  local font = love.graphics.getFont()
  local fh = font:getHeight()
  love.graphics.print(label, self.toggle.x + (self.toggle.w - font:getWidth(label)) / 2, p.y + p.h / 2 - fh / 2)
  if not self.open then
    love.graphics.print("M", self.toggle.x + 4, p.y + 40)
    love.graphics.print("E", self.toggle.x + 4, p.y + 40 + fh)
    love.graphics.print("M", self.toggle.x + 4, p.y + 40 + fh * 2)
    return
  end

  if self.image then
    love.graphics.setColor(1, 1, 1, 1)
    love.graphics.draw(self.image, self.img_x, self.img_y, 0, self.scale, self.scale)
  end

  -- 16KB bank lines
  love.graphics.setColor(1, 1, 1, 0.20)
  for _, bank in ipairs({ 0x4000, 0x8000, 0xC000 }) do
    local by = math.floor(bank / MAP_W) * self.scale
    love.graphics.line(self.img_x, self.img_y + by, self.img_x + self.img_w, self.img_y + by)
  end

  local fy = self.footer_y or (p.y + p.h - FOOTER_H)
  love.graphics.setColor(0.10, 0.11, 0.12, 0.92)
  love.graphics.rectangle("fill", p.x + COLLAPSED_W, fy, p.w - COLLAPSED_W, FOOTER_H)
  love.graphics.setColor(0.55, 0.6, 0.55, 1)
  if self.hover_addr and self.hover_val then
    local a = self.hover_addr
    local reg = REGION_NAME[math.floor(a / 0x4000) % 4 + 1]
    love.graphics.print(string.format(
      "%04X = %02X  %s  PC=%04X SP=%04X",
      a, self.hover_val, reg, self.pc, self.sp
    ), p.x + COLLAPSED_W + 6, fy + 2)
  else
    love.graphics.print(string.format(
      "256x256  1B/px  PC=%04X SP=%04X",
      self.pc, self.sp
    ), p.x + COLLAPSED_W + 6, fy + 2)
  end
end

return MemMap
