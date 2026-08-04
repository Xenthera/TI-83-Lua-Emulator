-- Pixel-art machine launcher: cards from Manager.list(), Esc returns here from IDE.

local Launcher = {}
Launcher.__index = Launcher

local DISPLAY = {
  ti83plus = "TI-83+",
  ti84plus = "TI-84+",
  ti89 = "TI-89 Ti",
  ti92plus = "TI-92+",
  riscv64 = "RV64",
  gameboy = "Game Boy",
  nes = "NES",
}

local COLORS = {
  bg = { 0.08, 0.09, 0.12, 1 },
  grid = { 0.14, 0.16, 0.20, 1 },
  card = { 0.16, 0.18, 0.24, 1 },
  card_hi = { 0.22, 0.28, 0.38, 1 },
  border = { 0.35, 0.55, 0.75, 1 },
  border_hi = { 0.55, 0.85, 1.0, 1 },
  title = { 0.92, 0.94, 0.98, 1 },
  sub = { 0.55, 0.62, 0.70, 1 },
  accent = { 0.40, 0.85, 0.55, 1 },
  pixel = { 0.30, 0.75, 0.45, 1 },
}

local function label_for(id)
  if DISPLAY[id] then return DISPLAY[id] end
  return id:gsub("_", " "):gsub("(%a)([%w]*)", function(a, b)
    return a:upper() .. b
  end)
end

function Launcher.new(root, manager)
  local self = setmetatable({
    root = root,
    manager = manager,
    cards = {},
    hover = nil,
    selected = nil,
    scroll = 0,
    title = "RETRO EMULATOR STUDIO",
    subtitle = "Select a machine",
    hardware_line = "",
  }, Launcher)
  self:refresh()
  return self
end

function Launcher:refresh()
  local ids = self.manager.list()
  self.cards = {}
  for _, id in ipairs(ids) do
    local icon_path = self.root .. "/machines/" .. id .. "/icon.png"
    local icon = nil
    local f = io.open(icon_path, "rb")
    if f then
      local data = f:read("*a")
      f:close()
      if data and #data > 8 then
        local ok_fd, fd = pcall(love.filesystem.newFileData, data, id .. ".png")
        if ok_fd and fd then
          local ok_img, img = pcall(love.graphics.newImage, fd)
          if ok_img and img then
            img:setFilter("nearest", "nearest")
            icon = img
          end
        end
      end
    end
    self.cards[#self.cards + 1] = {
      id = id,
      label = label_for(id),
      icon = icon,
    }
  end
  local hw = self.manager._hardware
  if hw and hw.cpus then
    local names = {}
    for _, c in ipairs(hw.cpus) do
      names[#names + 1] = c.id
    end
    self.hardware_line = #names > 0
      and ("CPUs: " .. table.concat(names, ", "))
      or ""
  else
    self.hardware_line = ""
  end
end

function Launcher:layout(ww, wh)
  ww = ww or love.graphics.getWidth()
  wh = wh or love.graphics.getHeight()
  local pad = 24
  local cols = math.max(2, math.min(4, math.floor((ww - pad * 2) / 160)))
  local card_w = math.floor((ww - pad * 2 - (cols - 1) * 12) / cols)
  local card_h = math.floor(card_w * 0.85)
  card_h = math.max(100, math.min(140, card_h))
  local top = 88
  for i, card in ipairs(self.cards) do
    local col = (i - 1) % cols
    local row = math.floor((i - 1) / cols)
    card.x = pad + col * (card_w + 12)
    card.y = top + row * (card_h + 12) - self.scroll
    card.w = card_w
    card.h = card_h
  end
  self._cols = cols
  self._card_h = card_h
  self._ww = ww
  self._wh = wh
  local rows = math.ceil(#self.cards / cols)
  self._content_h = top + rows * (card_h + 12) + 40
end

function Launcher:card_at(x, y)
  for _, card in ipairs(self.cards) do
    if x >= card.x and x <= card.x + card.w
        and y >= card.y and y <= card.y + card.h
        and card.y + card.h > 70 and card.y < (self._wh or 0) then
      return card
    end
  end
  return nil
end

function Launcher:mousemoved(x, y)
  local c = self:card_at(x, y)
  self.hover = c and c.id or nil
end

function Launcher:mousepressed(x, y)
  local c = self:card_at(x, y)
  if c then
    self.selected = c.id
    return c.id
  end
  return nil
end

function Launcher:wheelmoved(_, y)
  if not y or y == 0 then return end
  local max_scroll = math.max(0, (self._content_h or 0) - (self._wh or 0))
  self.scroll = math.max(0, math.min(max_scroll, self.scroll - y * 32))
  self:layout(self._ww, self._wh)
end

function Launcher:keypressed(key)
  if #self.cards == 0 then return nil end
  local idx = 1
  for i, c in ipairs(self.cards) do
    if c.id == (self.hover or self.selected) then
      idx = i
      break
    end
  end
  local cols = self._cols or 3
  if key == "right" then
    idx = math.min(#self.cards, idx + 1)
  elseif key == "left" then
    idx = math.max(1, idx - 1)
  elseif key == "down" then
    idx = math.min(#self.cards, idx + cols)
  elseif key == "up" then
    idx = math.max(1, idx - cols)
  elseif key == "return" or key == "space" then
    return self.cards[idx].id
  else
    return nil
  end
  self.hover = self.cards[idx].id
  return nil
end

local function draw_pixel_icon(x, y, s)
  love.graphics.setColor(COLORS.pixel)
  -- Simple 8x8 console glyph
  local px = {
    "00111100",
    "01000010",
    "10100101",
    "10000001",
    "10100101",
    "10011001",
    "01000010",
    "00111100",
  }
  for row, bits in ipairs(px) do
    for col = 1, #bits do
      if bits:sub(col, col) == "1" then
        love.graphics.rectangle("fill", x + (col - 1) * s, y + (row - 1) * s, s, s)
      end
    end
  end
end

function Launcher:draw()
  local ww = love.graphics.getWidth()
  local wh = love.graphics.getHeight()
  self:layout(ww, wh)

  love.graphics.clear(COLORS.bg)
  -- Subtle pixel grid
  love.graphics.setColor(COLORS.grid)
  for gx = 0, ww, 8 do
    love.graphics.line(gx, 0, gx, wh)
  end
  for gy = 0, wh, 8 do
    love.graphics.line(0, gy, ww, gy)
  end

  love.graphics.setColor(COLORS.title)
  love.graphics.print(self.title, 24, 20)
  love.graphics.setColor(COLORS.sub)
  love.graphics.print(self.subtitle .. "  ·  Esc returns here", 24, 44)
  if self.hardware_line ~= "" then
    love.graphics.print(self.hardware_line, 24, 62)
  end

  if #self.cards == 0 then
    love.graphics.setColor(COLORS.accent)
    love.graphics.print("No machines found under machines/*/machine.lua", 24, 100)
    return
  end

  for _, card in ipairs(self.cards) do
    local hi = card.id == self.hover or card.id == self.selected
    love.graphics.setColor(hi and COLORS.card_hi or COLORS.card)
    love.graphics.rectangle("fill", card.x, card.y, card.w, card.h, 4, 4)
    love.graphics.setColor(hi and COLORS.border_hi or COLORS.border)
    love.graphics.setLineWidth(hi and 3 or 2)
    love.graphics.rectangle("line", card.x + 1, card.y + 1, card.w - 2, card.h - 2, 4, 4)
    love.graphics.setLineWidth(1)

    local ix = card.x + math.floor(card.w / 2) - 32
    local iy = card.y + 16
    if card.icon then
      local iw, ih = card.icon:getDimensions()
      local scale = math.min(64 / iw, 48 / ih)
      love.graphics.setColor(1, 1, 1, 1)
      love.graphics.draw(card.icon, ix, iy, 0, scale, scale)
    else
      draw_pixel_icon(ix + 8, iy + 4, 6)
    end

    love.graphics.setColor(COLORS.title)
    local lw = love.graphics.getFont():getWidth(card.label)
    love.graphics.print(card.label, card.x + math.floor((card.w - lw) / 2), card.y + card.h - 28)
  end
end

return Launcher
