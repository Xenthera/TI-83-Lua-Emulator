-- Scrollable stdlib / language reference panel for the IDE.
-- Layout: section headers + rounded entry cards with indented body text.

local Natives = require("lang.natives")

local Compendium = {}
Compendium.__index = Compendium

local COL = {
  panel_bg   = { 0.10, 0.11, 0.13, 1 },
  panel_edge = { 0.26, 0.30, 0.28, 1 },
  card_bg    = { 0.14, 0.15, 0.17, 1 },
  card_edge  = { 0.30, 0.34, 0.32, 1 },
  accent_lang = { 0.85, 0.72, 0.40, 1 },
  accent_nat  = { 0.40, 0.82, 0.62, 1 },
  accent_gfx  = { 0.45, 0.78, 0.88, 1 },
  accent_tip  = { 0.70, 0.65, 0.85, 1 },
  h1         = { 0.95, 0.90, 0.55, 1 },
  h2         = { 0.72, 0.86, 0.95, 1 },
  title      = { 0.92, 0.88, 0.78, 1 },
  sig        = { 0.55, 0.95, 0.75, 1 },
  body       = { 0.78, 0.80, 0.76, 1 },
  detail     = { 0.58, 0.62, 0.58, 1 },
  ex         = { 0.68, 0.78, 0.48, 1 },
  label      = { 0.50, 0.55, 0.52, 1 },
  scroll_tr  = { 0.22, 0.25, 0.23, 1 },
  scroll_th  = { 0.45, 0.55, 0.48, 1 },
}

function Compendium.new()
  local self = setmetatable({}, Compendium)
  self.scroll = 0
  self.x, self.y, self.w, self.h = 0, 0, 100, 100
  self.line_h = 18
  self.blocks = self:_build_blocks()
  return self
end

function Compendium:sync_metrics()
  local font = love.graphics.getFont()
  if not font then return end
  self.line_h = math.max(15, math.ceil(font:getHeight() + 2))
  self.h1_h = self.line_h + 8
  self.h2_h = self.line_h + 10
  self.pad_x = 12
  self.pad_y = 10
  self.card_pad = 10
  self.card_gap = 8
  self.indent = 12
  self.radius = 5
end

function Compendium:_build_blocks()
  local blocks = {}

  local function section(title)
    blocks[#blocks + 1] = { kind = "section", title = title }
  end

  local function card(opts)
    blocks[#blocks + 1] = {
      kind = "card",
      accent = opts.accent,
      eyebrow = opts.eyebrow,
      title = opts.title,
      lines = opts.lines or {},
    }
  end

  blocks[#blocks + 1] = { kind = "hero", title = "Tiny-C Stdlib" }

  section("Language")
  for _, note in ipairs(Natives.lang_notes()) do
    card({
      accent = COL.accent_lang,
      eyebrow = "LANGUAGE",
      title = note.title,
      lines = {
        { kind = "body", text = note.body },
      },
    })
  end

  section("Native functions")
  for _, item in ipairs(Natives.list()) do
    local info = item.info
    local lines = {
      { kind = "sig", text = Natives.signature(item.name) },
      { kind = "body", text = info.summary },
    }
    if info.detail and info.detail ~= "" then
      lines[#lines + 1] = { kind = "detail", text = info.detail }
    end
    if info.example and info.example ~= "" then
      lines[#lines + 1] = { kind = "ex", text = info.example }
    end
    card({
      accent = COL.accent_nat,
      eyebrow = "NATIVE",
      title = item.name,
      lines = lines,
    })
  end

  section("stdlib/gfx.tc")
  card({
    accent = COL.accent_gfx,
    eyebrow = "INCLUDE",
    title = "stdlib/gfx.tc",
    lines = {
      { kind = "body", text = '#include <stdlib/gfx.tc> — shapes built on draw_pixel / erase_rect.' },
    },
  })
  for _, item in ipairs(Natives.gfx_lib()) do
    local info = item.info
    local lines = {
      { kind = "sig", text = item.signature },
      { kind = "body", text = info.summary },
    }
    if info.example and info.example ~= "" then
      lines[#lines + 1] = { kind = "ex", text = info.example }
    end
    card({
      accent = COL.accent_gfx,
      eyebrow = "GFX",
      title = item.name or (item.signature:match("^[%w_]+") or "helper"),
      lines = lines,
    })
  end

  section("Tips")
  card({
    accent = COL.accent_tip,
    eyebrow = "WORKFLOW",
    title = "IDE shortcuts",
    lines = {
      { kind = "body", text = "Build from the Tiny-C tab (F5). Generated ASM appears in the ASM tab." },
      { kind = "body", text = "Click the LCD panel to send keypad keys; click an editor tab to type code." },
      { kind = "body", text = "F8 / Step runs one Z80 instruction while paused." },
    },
  })

  return blocks
end

function Compendium:set_bounds(x, y, w, h)
  self.x, self.y, self.w, self.h = x, y, w, h
end

function Compendium:_text_w()
  return math.max(40, self.w - self.pad_x * 2 - self.card_pad * 2 - 10)
end

function Compendium:_wrapped_h(text, max_w)
  local font = love.graphics.getFont()
  if not font then return self.line_h end
  local _, lines = font:getWrap(text, math.max(40, max_w))
  return #lines * self.line_h
end

function Compendium:_card_inner_h(card, text_w)
  local h = 0
  -- eyebrow + title
  h = h + self.line_h -- eyebrow
  h = h + self.line_h + 2 -- title
  for _, line in ipairs(card.lines) do
    local w = text_w
    if line.kind == "detail" or line.kind == "ex" then
      w = text_w - self.indent
    end
    if line.kind == "ex" then
      h = h + 4 -- label gap
      h = h + self.line_h -- "example" label
    end
    h = h + self:_wrapped_h(line.text, w) + 3
  end
  return h
end

function Compendium:content_height()
  self:sync_metrics()
  local h = self.pad_y
  local text_w = self:_text_w()
  for _, b in ipairs(self.blocks) do
    if b.kind == "hero" then
      h = h + self.h1_h + 4
    elseif b.kind == "section" then
      h = h + self.h2_h + 4
    elseif b.kind == "card" then
      h = h + self.card_pad * 2 + self:_card_inner_h(b, text_w) + self.card_gap
    end
  end
  return h + self.pad_y
end

function Compendium:wheelmoved(_, y)
  local max_scroll = math.max(0, self:content_height() - self.h)
  self.scroll = self.scroll - y * 40
  if self.scroll < 0 then self.scroll = 0 end
  if self.scroll > max_scroll then self.scroll = max_scroll end
  return true
end

function Compendium:contains(mx, my)
  return mx >= self.x and my >= self.y and mx < self.x + self.w and my < self.y + self.h
end

function Compendium:_print_wrapped(text, x, y, max_w, color)
  local font = love.graphics.getFont()
  love.graphics.setColor(color)
  local _, lines = font:getWrap(text, max_w)
  for _, line in ipairs(lines) do
    if y + self.line_h >= self.y and y <= self.y + self.h then
      love.graphics.print(line, x, y)
    end
    y = y + self.line_h
  end
  return y
end

function Compendium:_draw_card(b, x, y, card_w, text_w)
  local inner_h = self:_card_inner_h(b, text_w)
  local card_h = inner_h + self.card_pad * 2
  local r = self.radius

  -- skip if fully off-screen
  if y + card_h < self.y or y > self.y + self.h then
    return y + card_h + self.card_gap
  end

  love.graphics.setColor(COL.card_bg)
  love.graphics.rectangle("fill", x, y, card_w, card_h, r, r)
  love.graphics.setColor(COL.card_edge)
  love.graphics.rectangle("line", x + 0.5, y + 0.5, card_w - 1, card_h - 1, r, r)

  -- left accent bar
  love.graphics.setColor(b.accent)
  love.graphics.rectangle("fill", x, y + 4, 3, card_h - 8, 1, 1)

  local cx = x + self.card_pad + 4
  local cy = y + self.card_pad

  if b.eyebrow then
    love.graphics.setColor(COL.label)
    love.graphics.print(b.eyebrow, cx, cy)
    cy = cy + self.line_h
  end

  love.graphics.setColor(COL.title)
  love.graphics.print(b.title, cx, cy)
  cy = cy + self.line_h + 2

  for _, line in ipairs(b.lines) do
    local lx = cx
    local lw = text_w
    if line.kind == "detail" or line.kind == "ex" then
      lx = cx + self.indent
      lw = text_w - self.indent
    end
    if line.kind == "sig" then
      cy = self:_print_wrapped(line.text, lx, cy, lw, COL.sig)
    elseif line.kind == "body" then
      cy = self:_print_wrapped(line.text, lx, cy, lw, COL.body)
    elseif line.kind == "detail" then
      cy = self:_print_wrapped(line.text, lx, cy, lw, COL.detail)
    elseif line.kind == "ex" then
      cy = cy + 4
      love.graphics.setColor(COL.label)
      if cy + self.line_h >= self.y and cy <= self.y + self.h then
        love.graphics.print("example", lx, cy)
      end
      cy = cy + self.line_h
      cy = self:_print_wrapped(line.text, lx, cy, lw, COL.ex)
    end
    cy = cy + 3
  end

  return y + card_h + self.card_gap
end

function Compendium:draw()
  self:sync_metrics()
  love.graphics.setColor(COL.panel_bg)
  love.graphics.rectangle("fill", self.x, self.y, self.w, self.h, 4, 4)
  love.graphics.setColor(COL.panel_edge)
  love.graphics.rectangle("line", self.x + 0.5, self.y + 0.5, self.w - 1, self.h - 1, 4, 4)

  love.graphics.setScissor(self.x + 1, self.y + 1, self.w - 2, self.h - 2)

  local y = self.y + self.pad_y - self.scroll
  local x = self.x + self.pad_x
  local card_w = self.w - self.pad_x * 2 - 10
  local text_w = self:_text_w()

  for _, b in ipairs(self.blocks) do
    if b.kind == "hero" then
      love.graphics.setColor(COL.h1)
      if y + self.h1_h >= self.y and y <= self.y + self.h then
        love.graphics.print(b.title, x, y)
      end
      y = y + self.h1_h + 4
    elseif b.kind == "section" then
      love.graphics.setColor(COL.h2)
      if y + self.h2_h >= self.y and y <= self.y + self.h then
        love.graphics.print(b.title, x, y + 2)
        -- underline
        love.graphics.setColor(0.35, 0.42, 0.48, 1)
        love.graphics.rectangle("fill", x, y + self.line_h + 4, math.min(120, card_w), 1)
      end
      y = y + self.h2_h + 4
    elseif b.kind == "card" then
      y = self:_draw_card(b, x, y, card_w, text_w)
    end
  end

  love.graphics.setScissor()

  local max_scroll = math.max(0, self:content_height() - self.h)
  if max_scroll > 0 then
    local track_h = self.h - 16
    local thumb_h = math.max(24, track_h * (self.h / (self.h + max_scroll)))
    local thumb_y = self.y + 8 + (track_h - thumb_h) * (self.scroll / max_scroll)
    love.graphics.setColor(COL.scroll_tr)
    love.graphics.rectangle("fill", self.x + self.w - 8, self.y + 8, 4, track_h, 2, 2)
    love.graphics.setColor(COL.scroll_th)
    love.graphics.rectangle("fill", self.x + self.w - 8, thumb_y, 4, thumb_h, 2, 2)
  end
end

return Compendium
