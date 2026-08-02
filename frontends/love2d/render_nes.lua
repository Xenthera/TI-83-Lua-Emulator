-- NES LCD presenter: 256x240 palette indices -> RGB texture.

local Ppu = require("machines.nes.hw.ppu")
local Pal = require("machines.nes.palette")

local Render = {}
Render.__index = Render

-- Flat 8-bit component LUTs for FFI upload; float LUTs for mapPixel fallback.
local R8, G8, B8 = {}, {}, {}
local RF, GF, BF = {}, {}, {}
do
  local rgb = Pal.RGB
  for i = 0, 63 do
    local c = rgb[i] or rgb[0x0F]
    RF[i], GF[i], BF[i] = c[1], c[2], c[3]
    R8[i] = math.floor(c[1] * 255 + 0.5)
    G8[i] = math.floor(c[2] * 255 + 0.5)
    B8[i] = math.floor(c[3] * 255 + 0.5)
  end
end

local ffi_ok, ffi = pcall(require, "ffi")

function Render.new()
  local self = setmetatable({}, Render)
  self.width = Ppu.WIDTH
  self.height = Ppu.HEIGHT
  self.fb = nil
  self.display_on = true
  self.image = nil
  self.id = nil
  self._dirty_tex = true
  self._use_ffi = false
  return self
end

function Render:_ensure()
  if self.image then return true end
  local ok, img = pcall(love.image.newImageData, self.width, self.height)
  if not ok then return false end
  self.image = img
  self.id = love.graphics.newImage(img)
  self.id:setFilter("nearest", "nearest")
  self._use_ffi = false
  if ffi_ok and img.getFFIPointer then
    local pok, ptr = pcall(function()
      return ffi.cast("uint8_t*", img:getFFIPointer())
    end)
    if pok and ptr then
      self._ffi_ptr = ptr
      self._use_ffi = true
    end
  end
  return true
end

function Render:present(framebuffer, display_on)
  self.fb = framebuffer
  self.display_on = not not display_on
  self._dirty_tex = true
end

function Render:_upload()
  if not self._dirty_tex then return end
  self._dirty_tex = false
  if not self.display_on or not self.fb or not self:_ensure() then
    return
  end
  local fb = self.fb
  local n = self.width * self.height

  if self._use_ffi then
    local ptr = self._ffi_ptr
    local r8, g8, b8 = R8, G8, B8
    for i = 0, n - 1 do
      local idx = fb[i] or 0x0F
      if idx < 0 then idx = 0 elseif idx > 63 then idx = idx % 64 end
      local o = i * 4
      ptr[o] = r8[idx]
      ptr[o + 1] = g8[idx]
      ptr[o + 2] = b8[idx]
      ptr[o + 3] = 255
    end
  else
    local img = self.image
    local w = self.width
    local rf, gf, bf = RF, GF, BF
    if img.mapPixel then
      img:mapPixel(function(x, y)
        local idx = fb[y * w + x] or 0x0F
        if idx < 0 then idx = 0 elseif idx > 63 then idx = idx % 64 end
        return rf[idx], gf[idx], bf[idx], 1
      end)
    else
      for y = 0, self.height - 1 do
        local base = y * w
        for x = 0, w - 1 do
          local idx = fb[base + x] or 0x0F
          if idx < 0 then idx = 0 elseif idx > 63 then idx = idx % 64 end
          img:setPixel(x, y, rf[idx], gf[idx], bf[idx], 1)
        end
      end
    end
  end
  self.id:replacePixels(self.image)
end

function Render:draw(glass)
  if not glass or glass.w <= 0 or glass.h <= 0 then return end
  self:_upload()
  if not self.id then return end
  love.graphics.setColor(1, 1, 1, 1)
  love.graphics.draw(self.id, glass.x, glass.y, 0, glass.w / self.width, glass.h / self.height)
end

return Render
