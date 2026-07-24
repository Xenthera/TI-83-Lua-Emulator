-- Scrollable stdlib / language reference panel for the IDE.

local Natives = require("lang.natives")

local Compendium = {}
Compendium.__index = Compendium

function Compendium.new()
  local self = setmetatable({}, Compendium)
  self.scroll = 0
  self.x, self.y, self.w, self.h = 0, 0, 100, 100
  self.line_h = 18
  self.entries = self:_build_entries()
  return self
end

function Compendium:sync_metrics()
  local font = love.graphics.getFont()
  if not font then return end
  self.line_h = math.max(16, math.ceil(font:getHeight() + 3))
  self.h1_h = self.line_h + 6
  self.h2_h = self.line_h + 4
end

function Compendium:_build_entries()
  local e = {}
  local function add(kind, text, color)
    e[#e + 1] = { kind = kind, text = text, color = color }
  end

  add("h1", "Tiny-C Stdlib", { 0.95, 0.9, 0.55, 1 })
  add("blank", "")
  add("h2", "Language", { 0.7, 0.85, 0.95, 1 })
  for _, note in ipairs(Natives.lang_notes()) do
    add("title", note.title, { 0.85, 0.75, 0.55, 1 })
    add("body", note.body, { 0.75, 0.78, 0.72, 1 })
    add("blank", "")
  end

  add("h2", "Native functions", { 0.7, 0.85, 0.95, 1 })
  add("blank", "")
  for _, item in ipairs(Natives.list()) do
    local name = item.name
    local info = item.info
    add("sig", Natives.signature(name), { 0.45, 0.90, 0.70, 1 })
    add("body", info.summary, { 0.86, 0.88, 0.84, 1 })
    if info.detail and info.detail ~= "" then
      add("detail", info.detail, { 0.60, 0.65, 0.60, 1 })
    end
    if info.example and info.example ~= "" then
      add("ex", "ex: " .. info.example, { 0.70, 0.80, 0.50, 1 })
    end
    add("blank", "")
  end

  add("h2", "stdlib/gfx.tc", { 0.7, 0.85, 0.95, 1 })
  add("body", '#include <stdlib/gfx.tc> - shapes built on draw_pixel.', { 0.75, 0.78, 0.72, 1 })
  add("blank", "")
  for _, item in ipairs(Natives.gfx_lib()) do
    local info = item.info
    add("sig", item.signature, { 0.45, 0.85, 0.90, 1 })
    add("body", info.summary, { 0.86, 0.88, 0.84, 1 })
    if info.example and info.example ~= "" then
      add("ex", "ex: " .. info.example, { 0.70, 0.80, 0.50, 1 })
    end
    add("blank", "")
  end

  add("h2", "Tips", { 0.7, 0.85, 0.95, 1 })
  add("body", "Build from the Tiny-C tab (F5). Generated ASM appears in the ASM tab.", { 0.75, 0.78, 0.72, 1 })
  add("body", "Click the LCD panel to send keypad keys; click an editor tab to type code.", { 0.75, 0.78, 0.72, 1 })
  add("body", "F8 / Step runs one Z80 instruction while paused.", { 0.75, 0.78, 0.72, 1 })
  return e
end

function Compendium:set_bounds(x, y, w, h)
  self.x, self.y, self.w, self.h = x, y, w, h
end

function Compendium:content_height()
  self:sync_metrics()
  local h = self.pad_top or 8
  local h1 = self.h1_h or 22
  local h2 = self.h2_h or 20
  for _, e in ipairs(self.entries) do
    if e.kind == "blank" then
      h = h + math.floor(self.line_h * 0.45)
    elseif e.kind == "h1" then
      h = h + h1
    elseif e.kind == "h2" then
      h = h + h2
    elseif e.kind == "detail" then
      h = h + self:_wrapped_h(e.text, self.w - 28) + 4
    else
      h = h + self:_wrapped_h(e.text, self.w - 28) + 2
    end
  end
  return h + 16
end

function Compendium:_wrapped_h(text, max_w)
  local font = love.graphics.getFont()
  if not font then return self.line_h end
  local _, lines = font:getWrap(text, math.max(40, max_w))
  return #lines * self.line_h
end

function Compendium:wheelmoved(_, y)
  local max_scroll = math.max(0, self:content_height() - self.h)
  self.scroll = self.scroll - y * 36
  if self.scroll < 0 then self.scroll = 0 end
  if self.scroll > max_scroll then self.scroll = max_scroll end
  return true
end

function Compendium:contains(mx, my)
  return mx >= self.x and my >= self.y and mx < self.x + self.w and my < self.y + self.h
end

function Compendium:draw()
  self:sync_metrics()
  love.graphics.setColor(0.11, 0.12, 0.14, 1)
  love.graphics.rectangle("fill", self.x, self.y, self.w, self.h, 4, 4)
  love.graphics.setColor(0.28, 0.32, 0.30, 1)
  love.graphics.rectangle("line", self.x + 0.5, self.y + 0.5, self.w - 1, self.h - 1, 4, 4)

  love.graphics.setScissor(self.x + 1, self.y + 1, self.w - 2, self.h - 2)
  local font = love.graphics.getFont()
  local y = self.y + 10 - self.scroll
  local x = self.x + 14
  local max_w = self.w - 28
  local h1 = self.h1_h or 22
  local h2 = self.h2_h or 20

  for _, e in ipairs(self.entries) do
    if e.kind == "blank" then
      y = y + math.floor(self.line_h * 0.45)
    else
      love.graphics.setColor(e.color)
      local prefix = ""
      if e.kind == "h1" then
        love.graphics.print(e.text, x, y)
        y = y + h1
      elseif e.kind == "h2" then
        love.graphics.print(e.text, x, y)
        y = y + h2
      else
        if e.kind == "title" then prefix = "* " end
        local text = prefix .. e.text
        local _, lines = font:getWrap(text, max_w)
        for _, line in ipairs(lines) do
          if y + self.line_h >= self.y and y <= self.y + self.h then
            love.graphics.print(line, x, y)
          end
          y = y + self.line_h
        end
        y = y + 2
      end
    end
  end

  love.graphics.setScissor()

  -- scroll hint
  local max_scroll = math.max(0, self:content_height() - self.h)
  if max_scroll > 0 then
    local track_h = self.h - 16
    local thumb_h = math.max(24, track_h * (self.h / (self.h + max_scroll)))
    local thumb_y = self.y + 8 + (track_h - thumb_h) * (self.scroll / max_scroll)
    love.graphics.setColor(0.25, 0.28, 0.26, 1)
    love.graphics.rectangle("fill", self.x + self.w - 8, self.y + 8, 4, track_h, 2, 2)
    love.graphics.setColor(0.45, 0.55, 0.48, 1)
    love.graphics.rectangle("fill", self.x + self.w - 8, thumb_y, 4, thumb_h, 2, 2)
  end
end

return Compendium
