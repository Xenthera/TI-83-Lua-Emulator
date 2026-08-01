-- Unity-style property inspector for the face panel editor.
-- Selection-aware rows: number (arrows + drag scrub), text, enum, color picker.

local Inspector = {}
Inspector.__index = Inspector

-- Sentinel for multi-selection when field values differ (draw as "—").
Inspector.MIXED = {}

function Inspector.is_mixed(v)
  return v == Inspector.MIXED
end

local ROW_H = 22
local LABEL_W = 96
local GAP = 4
local ARROW_W = 14
local SWATCH_W = 22
local MIXED_TEXT = "—"

local COL = {
  bg = { 0.16, 0.17, 0.19 },
  field = { 0.10, 0.11, 0.13 },
  field_hi = { 0.14, 0.16, 0.20 },
  border = { 0.35, 0.38, 0.42 },
  text = { 0.90, 0.92, 0.94 },
  muted = { 0.55, 0.58, 0.62 },
  accent = { 0.35, 0.65, 0.95 },
  header = { 0.22, 0.24, 0.27 },
  arrow = { 0.28, 0.30, 0.34 },
}

local function clamp(v, a, b)
  if a and v < a then return a end
  if b and v > b then return b end
  return v
end

local function hit(r, x, y)
  return r and x >= r.x and y >= r.y and x < r.x + r.w and y < r.y + r.h
end

local function set_col(c, a)
  love.graphics.setColor(c[1], c[2], c[3], a or 1)
end

local function copy_rgb(c)
  if type(c) ~= "table" then return { 1, 1, 1 } end
  return { c[1] or 0, c[2] or 0, c[3] or 0 }
end

-- RGB 0..1 <-> HSV
local function rgb_to_hsv(r, g, b)
  local max = math.max(r, g, b)
  local min = math.min(r, g, b)
  local d = max - min
  local h = 0
  if d > 1e-6 then
    if max == r then
      h = ((g - b) / d) % 6
    elseif max == g then
      h = (b - r) / d + 2
    else
      h = (r - g) / d + 4
    end
    h = h / 6
    if h < 0 then h = h + 1 end
  end
  local s = (max <= 1e-6) and 0 or (d / max)
  return h, s, max
end

local function hsv_to_rgb(h, s, v)
  h = (h % 1) * 6
  local i = math.floor(h)
  local f = h - i
  local p = v * (1 - s)
  local q = v * (1 - f * s)
  local t = v * (1 - (1 - f) * s)
  if i == 0 then return v, t, p
  elseif i == 1 then return q, v, p
  elseif i == 2 then return p, v, t
  elseif i == 3 then return p, q, v
  elseif i == 4 then return t, p, v
  else return v, p, q end
end

function Inspector.new(opts)
  opts = opts or {}
  local self = setmetatable({}, Inspector)
  self.on_change = opts.on_change -- function(path, value, meta)
  self.on_begin_change = opts.on_begin_change -- undo push
  self.bounds = { x = 0, y = 0, w = 260, h = 400 }
  self.scroll = 0
  self.rows = {}
  self.focus = nil -- { id, kind="text"|"number" }
  self.edit_text = ""
  self.edit_sel_all = false -- Ctrl+A selection (single-line fields)
  self.scrub = nil
  self.picker = nil -- open color picker state
  self.dropdown = nil
  self.title = "Inspector"
  self.subtitle = ""
  return self
end

function Inspector:set_bounds(x, y, w, h)
  local b = self.bounds
  if b and b.x == x and b.y == y and b.w == w and b.h == h then
    return
  end
  self.bounds = { x = x, y = y, w = w, h = h }
  -- Keep focus / picker / dropdown; only refresh hit rects for the new size.
  if self.schema then
    self:_rebuild_rows()
  end
end

--- Build rows from a schema list:
-- { id, label, type="number"|"text"|"enum"|"color"|"header"|"bool",
--   get=fn, set=fn, min, max, step, precision, options={...}, nullable=bool }
function Inspector:set_schema(title, subtitle, schema)
  self:commit()
  self.title = title or "Inspector"
  self.subtitle = subtitle or ""
  self.schema = schema or {}
  self.scroll = 0
  self.focus = nil
  self.picker = nil
  self.dropdown = nil
  self:_rebuild_rows()
end

function Inspector:_rebuild_rows()
  local b = self.bounds
  local x = b.x + 8
  local y = b.y + 44 - self.scroll
  local w = b.w - 16
  self.rows = {}
  for _, s in ipairs(self.schema or {}) do
    if s.type == "header" then
      local row = {
        id = s.id or s.label,
        type = "header",
        label = s.label,
        x = x, y = y, w = w, h = 20,
      }
      self.rows[#self.rows + 1] = row
      y = y + 24
    else
      local row = {
        id = s.id,
        type = s.type or "text",
        label = s.label,
        schema = s,
        x = x, y = y, w = w, h = ROW_H,
        label_rect = { x = x, y = y, w = LABEL_W, h = ROW_H },
        field_rect = { x = x + LABEL_W + 4, y = y, w = w - LABEL_W - 4, h = ROW_H },
      }
      if row.type == "number" then
        local fr = row.field_rect
        row.dec_rect = { x = fr.x, y = fr.y, w = ARROW_W, h = ROW_H }
        row.inc_rect = { x = fr.x + fr.w - ARROW_W, y = fr.y, w = ARROW_W, h = ROW_H }
        row.value_rect = {
          x = fr.x + ARROW_W,
          y = fr.y,
          w = fr.w - ARROW_W * 2,
          h = ROW_H,
        }
      elseif row.type == "color" then
        local fr = row.field_rect
        row.swatch_rect = { x = fr.x, y = fr.y + 2, w = SWATCH_W, h = ROW_H - 4 }
        row.value_rect = {
          x = fr.x + SWATCH_W + 4,
          y = fr.y,
          w = fr.w - SWATCH_W - 4,
          h = ROW_H,
        }
      elseif row.type == "enum" then
        row.value_rect = row.field_rect
      elseif row.type == "bool" then
        row.check_rect = { x = row.field_rect.x, y = y + 3, w = 16, h = 16 }
      else
        row.value_rect = row.field_rect
      end
      self.rows[#self.rows + 1] = row
      y = y + ROW_H + GAP
    end
  end
  self.content_h = math.max(0, y + self.scroll - (b.y + 44) + 8)
end

function Inspector:_get(s)
  if s.get then return s.get() end
  return nil
end

function Inspector:_set(s, value, skip_undo)
  if not skip_undo and self.on_begin_change then
    self.on_begin_change()
  end
  if s.set then s.set(value) end
  if self.on_change then self.on_change(s.id, value, s) end
end

function Inspector:_fmt_number(s, v)
  if v == nil then return "" end
  local p = s.precision
  if p == nil then
    p = (s.step and s.step < 1) and 3 or 0
  end
  if p <= 0 then
    return tostring(math.floor(v + (v >= 0 and 0.5 or -0.5)))
  end
  return string.format("%." .. p .. "f", v)
end

function Inspector:_parse_number(s, text)
  local n = tonumber(text)
  if not n then return nil end
  n = clamp(n, s.min, s.max)
  if s.step and s.step >= 1 and (not s.precision or s.precision <= 0) then
    n = math.floor(n + 0.5)
  end
  return n
end

local function clipboard_get()
  if love.system and love.system.getClipboardText then
    return love.system.getClipboardText() or ""
  end
  return ""
end

local function clipboard_set(text)
  if love.system and love.system.setClipboardText then
    love.system.setClipboardText(tostring(text or ""))
  end
end

function Inspector:commit()
  if not self.focus then return end
  local id = self.focus.id
  local row = self:_row_by_id(id)
  self.focus = nil
  local text = self.edit_text
  self.edit_text = ""
  self.edit_sel_all = false
  if not row or not row.schema then return end
  local s = row.schema
  if row.type == "number" then
    local n = self:_parse_number(s, text)
    if n ~= nil then self:_set(s, n) end
  elseif row.type == "text" or row.type == "enum" then
    if s.nullable and text == "" then
      self:_set(s, nil)
    else
      self:_set(s, text)
    end
  elseif row.type == "color" then
    -- typed as "r, g, b"
    local a, b, c = text:match("([%d%.%-]+)%s*,%s*([%d%.%-]+)%s*,%s*([%d%.%-]+)")
    if a then
      self:_set(s, {
        clamp(tonumber(a) or 0, 0, 1),
        clamp(tonumber(b) or 0, 0, 1),
        clamp(tonumber(c) or 0, 0, 1),
      })
    elseif s.nullable and text == "" then
      self:_set(s, nil)
    end
  end
end

function Inspector:begin_text_edit(row)
  self:commit()
  self.dropdown = nil
  local s = row.schema
  local v = self:_get(s)
  self.focus = { id = row.id, kind = row.type }
  self.edit_sel_all = false
  if Inspector.is_mixed(v) then
    -- Empty so the next typed/committed value replaces the mixed state.
    self.edit_text = ""
    return
  end
  if row.type == "number" then
    self.edit_text = self:_fmt_number(s, v)
  elseif row.type == "color" then
    if v then
      self.edit_text = string.format("%.3f, %.3f, %.3f", v[1], v[2], v[3])
    else
      self.edit_text = ""
    end
  else
    self.edit_text = v == nil and "" or tostring(v)
  end
end

function Inspector:_row_by_id(id)
  for _, r in ipairs(self.rows) do
    if r.id == id then return r end
  end
  return nil
end

function Inspector:_nudge(row, dir)
  local s = row.schema
  local step = s.step or 1
  if love.keyboard.isDown("lshift", "rshift") then step = step * 10 end
  if love.keyboard.isDown("lctrl", "rctrl") then step = step * 0.1 end
  local cur = self:_get(s)
  local v = Inspector.is_mixed(cur) and (s.min or 0) or (tonumber(cur) or 0)
  local n = clamp(v + dir * step, s.min, s.max)
  if s.precision == 0 or (s.step and s.step >= 1 and not s.precision) then
    n = math.floor(n + 0.5)
  end
  self:_set(s, n)
end

function Inspector:_open_picker(row)
  local s = row.schema
  local cur = self:_get(s)
  local rgb = copy_rgb((Inspector.is_mixed(cur) or not cur) and { 0.5, 0.5, 0.5 } or cur)
  local h, sv, v = rgb_to_hsv(rgb[1], rgb[2], rgb[3])
  local b = self.bounds
  local pw, ph = 200, 180
  local px = math.min(row.swatch_rect.x, b.x + b.w - pw - 8)
  local py = row.y + ROW_H + 4
  if py + ph > b.y + b.h then
    py = row.y - ph - 4
  end
  self.picker = {
    id = row.id,
    schema = s,
    h = h, s = sv, v = v,
    rgb = rgb,
    rect = { x = px, y = py, w = pw, h = ph },
    sv_rect = { x = px + 8, y = py + 8, w = 140, h = 120 },
    hue_rect = { x = px + 156, y = py + 8, w = 16, h = 120 },
    preview = { x = px + 8, y = py + 136, w = 40, h = 28 },
    ok = { x = px + 56, y = py + 140, w = 56, h = 22 },
    cancel = { x = px + 120, y = py + 140, w = 64, h = 22 },
  }
  if s.nullable then
    self.picker.clear = { x = px + 8, y = py + 168, w = 80, h = 0 } -- unused; use right-click
  end
end

function Inspector:_apply_picker_hsv()
  local p = self.picker
  if not p then return end
  local r, g, b = hsv_to_rgb(p.h, p.s, p.v)
  p.rgb = { r, g, b }
end

function Inspector:mousepressed(mx, my, button)
  -- Color picker on top
  if self.picker then
    local p = self.picker
    if hit(p.rect, mx, my) then
      if button ~= 1 then return true end
      if hit(p.sv_rect, mx, my) then
        if self.on_begin_change then self.on_begin_change() end
        self.scrub = { kind = "picker_sv" }
        local u = clamp((mx - p.sv_rect.x) / p.sv_rect.w, 0, 1)
        local v = 1 - clamp((my - p.sv_rect.y) / p.sv_rect.h, 0, 1)
        p.s, p.v = u, v
        self:_apply_picker_hsv()
        self:_set(p.schema, copy_rgb(p.rgb), true)
        return true
      end
      if hit(p.hue_rect, mx, my) then
        if self.on_begin_change then self.on_begin_change() end
        self.scrub = { kind = "picker_hue" }
        p.h = clamp((my - p.hue_rect.y) / p.hue_rect.h, 0, 1)
        self:_apply_picker_hsv()
        self:_set(p.schema, copy_rgb(p.rgb), true)
        return true
      end
      if hit(p.ok, mx, my) then
        self:_set(p.schema, copy_rgb(p.rgb))
        self.picker = nil
        return true
      end
      if hit(p.cancel, mx, my) then
        self.picker = nil
        return true
      end
      return true
    else
      self.picker = nil
      -- fall through
    end
  end

  if self.dropdown then
    local d = self.dropdown
    if hit(d.rect, mx, my) then
      for i, opt in ipairs(d.options) do
        local orr = {
          x = d.rect.x,
          y = d.rect.y + (i - 1) * 20,
          w = d.rect.w,
          h = 20,
        }
        if hit(orr, mx, my) then
          local value = opt
          if type(opt) == "table" then
            value = opt.id or opt.value or opt[1]
          end
          self:_set(d.schema, value)
          self.dropdown = nil
          return true
        end
      end
      return true
    else
      self.dropdown = nil
    end
  end

  if not hit(self.bounds, mx, my) then
    self:commit()
    return false
  end

  if button ~= 1 then return true end

  for _, row in ipairs(self.rows) do
    if row.type == "header" then
      -- skip
    elseif row.type == "number" and hit(row.label_rect, mx, my) then
      -- Unity-style drag scrub on label
      if self.on_begin_change then self.on_begin_change() end
      self:commit()
      local cur = self:_get(row.schema)
      self.scrub = {
        kind = "number",
        id = row.id,
        schema = row.schema,
        start_x = mx,
        start_v = Inspector.is_mixed(cur) and (row.schema.min or 0) or (tonumber(cur) or 0),
      }
      return true
    elseif row.type == "number" and hit(row.dec_rect, mx, my) then
      self:commit()
      self:_nudge(row, -1)
      return true
    elseif row.type == "number" and hit(row.inc_rect, mx, my) then
      self:commit()
      self:_nudge(row, 1)
      return true
    elseif row.type == "number" and hit(row.value_rect, mx, my) then
      self:begin_text_edit(row)
      return true
    elseif row.type == "color" and hit(row.swatch_rect, mx, my) then
      self:commit()
      self:_open_picker(row)
      return true
    elseif row.type == "color" and hit(row.value_rect, mx, my) then
      self:begin_text_edit(row)
      return true
    elseif row.type == "enum" and hit(row.value_rect, mx, my) then
      self:commit()
      local opts = row.schema.options or {}
      local h = #opts * 20
      self.dropdown = {
        schema = row.schema,
        options = opts,
        rect = {
          x = row.value_rect.x,
          y = row.value_rect.y + ROW_H,
          w = row.value_rect.w,
          h = h,
        },
      }
      return true
    elseif row.type == "bool" and (hit(row.check_rect, mx, my) or hit(row.label_rect, mx, my)) then
      self:commit()
      self:_set(row.schema, not self:_get(row.schema))
      return true
    elseif (row.type == "text" or row.type == "enum") and hit(row.value_rect, mx, my) then
      self:begin_text_edit(row)
      return true
    elseif hit(row, mx, my) and row.type ~= "header" then
      return true
    end
  end

  self:commit()
  return true
end

function Inspector:mousemoved(mx, my, dx, dy)
  if self.scrub then
    local s = self.scrub
    if s.kind == "number" then
      local step = s.schema.step or 0.05
      if love.keyboard.isDown("lshift", "rshift") then step = step * 10 end
      if love.keyboard.isDown("lctrl", "rctrl") then step = step * 0.1 end
      -- Cumulative from drag start (Unity-style scrub).
      local n = clamp(s.start_v + (mx - s.start_x) * step * 0.15, s.schema.min, s.schema.max)
      if s.schema.precision == 0 or (s.schema.step and s.schema.step >= 1 and not s.schema.precision) then
        n = math.floor(n + 0.5)
      elseif s.schema.precision then
        local m = 10 ^ s.schema.precision
        n = math.floor(n * m + 0.5) / m
      end
      self:_set(s.schema, n, true)
      return true
    elseif s.kind == "picker_sv" and self.picker then
      local p = self.picker
      p.s = clamp((mx - p.sv_rect.x) / p.sv_rect.w, 0, 1)
      p.v = 1 - clamp((my - p.sv_rect.y) / p.sv_rect.h, 0, 1)
      self:_apply_picker_hsv()
      self:_set(p.schema, copy_rgb(p.rgb), true)
      return true
    elseif s.kind == "picker_hue" and self.picker then
      local p = self.picker
      p.h = clamp((my - p.hue_rect.y) / p.hue_rect.h, 0, 1)
      self:_apply_picker_hsv()
      self:_set(p.schema, copy_rgb(p.rgb), true)
      return true
    end
  end
  return hit(self.bounds, mx, my) or (self.picker and hit(self.picker.rect, mx, my))
end

function Inspector:mousereleased(mx, my, button)
  if button == 1 and self.scrub then
    self.scrub = nil
    return true
  end
  return false
end

function Inspector:wheelmoved(wx, wy, mx, my)
  if self.picker and hit(self.picker.rect, mx, my) then return true end
  if not hit(self.bounds, mx, my) then return false end
  local max_scroll = math.max(0, self.content_h - (self.bounds.h - 52))
  self.scroll = clamp(self.scroll - wy * 24, 0, max_scroll)
  self:_rebuild_rows()
  return true
end

function Inspector:textinput(t)
  if not self.focus then return false end
  if love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui") then
    return true
  end
  if self.edit_sel_all then
    self.edit_text = t
    self.edit_sel_all = false
  else
    self.edit_text = self.edit_text .. t
  end
  return true
end

function Inspector:keypressed(key)
  if self.picker then
    if key == "escape" then
      self.picker = nil
      return true
    elseif key == "return" or key == "kpenter" then
      self:_set(self.picker.schema, copy_rgb(self.picker.rgb))
      self.picker = nil
      return true
    end
  end
  if not self.focus then return false end
  local ctrl = love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui")
  if ctrl and key == "a" then
    self.edit_sel_all = self.edit_text ~= ""
    return true
  elseif ctrl and key == "c" then
    if self.edit_text ~= "" then clipboard_set(self.edit_text) end
    return true
  elseif ctrl and key == "x" then
    if self.edit_text ~= "" then
      clipboard_set(self.edit_text)
      self.edit_text = ""
      self.edit_sel_all = false
    end
    return true
  elseif ctrl and key == "v" then
    local clip = clipboard_get()
    if clip ~= "" then
      if self.edit_sel_all or self.edit_text == "" then
        self.edit_text = clip
      else
        self.edit_text = self.edit_text .. clip
      end
      self.edit_sel_all = false
    end
    return true
  elseif key == "return" or key == "kpenter" then
    self:commit()
    return true
  elseif key == "escape" then
    self.focus = nil
    self.edit_text = ""
    self.edit_sel_all = false
    return true
  elseif key == "backspace" then
    if self.edit_sel_all then
      self.edit_text = ""
      self.edit_sel_all = false
    else
      self.edit_text = self.edit_text:sub(1, -2)
    end
    return true
  elseif key == "delete" then
    if self.edit_sel_all then
      self.edit_text = ""
      self.edit_sel_all = false
    end
    return true
  end
  return true
end

local function draw_edit_text(fr, text, sel_all)
  local font = love.graphics.getFont()
  local tx = fr.x + 6
  local ty = fr.y + 3
  if sel_all and text ~= "" then
    local tw = font:getWidth(text)
    set_col(COL.accent, 0.35)
    love.graphics.rectangle("fill", tx - 1, ty - 1, tw + 2, font:getHeight() + 2, 2, 2)
  end
  set_col(COL.text)
  love.graphics.print(text .. (sel_all and "" or "|"), tx, ty)
end

function Inspector:_draw_number(row)
  local s = row.schema
  local active = self.focus and self.focus.id == row.id
  local fr = row.field_rect
  set_col(COL.field)
  love.graphics.rectangle("fill", fr.x, fr.y, fr.w, fr.h, 3, 3)
  set_col(active and COL.accent or COL.border)
  love.graphics.rectangle("line", fr.x, fr.y, fr.w, fr.h, 3, 3)

  set_col(COL.arrow)
  love.graphics.rectangle("fill", row.dec_rect.x, row.dec_rect.y, row.dec_rect.w, row.dec_rect.h, 3, 3)
  love.graphics.rectangle("fill", row.inc_rect.x, row.inc_rect.y, row.inc_rect.w, row.inc_rect.h, 3, 3)
  set_col(COL.text)
  local font = love.graphics.getFont()
  love.graphics.print("<", row.dec_rect.x + 3, row.dec_rect.y + 3)
  love.graphics.print(">", row.inc_rect.x + 3, row.inc_rect.y + 3)

  local text
  if active then
    text = self.edit_text
    local vr = row.value_rect
    if self.edit_sel_all and text ~= "" then
      local tw = font:getWidth(text)
      set_col(COL.accent, 0.35)
      love.graphics.rectangle("fill", vr.x + (vr.w - tw) * 0.5 - 1, vr.y + 2, tw + 2, font:getHeight() + 2, 2, 2)
    end
    set_col(COL.text)
    local shown = text .. (self.edit_sel_all and "" or "|")
    local tw = font:getWidth(shown)
    love.graphics.print(shown, vr.x + (vr.w - tw) * 0.5, vr.y + 3)
  else
    local v = self:_get(s)
    text = Inspector.is_mixed(v) and MIXED_TEXT or self:_fmt_number(s, v)
    set_col(COL.text)
    local tw = font:getWidth(text)
    love.graphics.print(text, row.value_rect.x + (row.value_rect.w - tw) * 0.5, row.value_rect.y + 3)
  end
end

function Inspector:_draw_text(row)
  local active = self.focus and self.focus.id == row.id
  local fr = row.value_rect
  set_col(COL.field)
  love.graphics.rectangle("fill", fr.x, fr.y, fr.w, fr.h, 3, 3)
  set_col(active and COL.accent or COL.border)
  love.graphics.rectangle("line", fr.x, fr.y, fr.w, fr.h, 3, 3)
  if active then
    draw_edit_text(fr, self.edit_text, self.edit_sel_all)
  else
    set_col(COL.text)
    local v = self:_get(row.schema)
    local text
    if Inspector.is_mixed(v) then
      text = MIXED_TEXT
    else
      text = v == nil and "" or tostring(v)
    end
    love.graphics.print(text, fr.x + 6, fr.y + 3)
  end
end

function Inspector:_enum_label(schema, value)
  if Inspector.is_mixed(value) then return MIXED_TEXT end
  for _, opt in ipairs(schema.options or {}) do
    if type(opt) == "table" then
      local id = opt.id or opt.value or opt[1]
      if id == value then
        return opt.label or tostring(id)
      end
    elseif opt == value then
      return tostring(opt)
    end
  end
  return value == nil and "" or tostring(value)
end

function Inspector:_draw_enum(row)
  local fr = row.value_rect
  local active = self.focus and self.focus.id == row.id
  set_col(COL.field)
  love.graphics.rectangle("fill", fr.x, fr.y, fr.w, fr.h, 3, 3)
  set_col(active and COL.accent or COL.border)
  love.graphics.rectangle("line", fr.x, fr.y, fr.w, fr.h, 3, 3)
  if active then
    draw_edit_text(fr, self.edit_text, self.edit_sel_all)
  else
    set_col(COL.text)
    love.graphics.print(self:_enum_label(row.schema, self:_get(row.schema)), fr.x + 6, fr.y + 3)
  end
  set_col(COL.muted)
  love.graphics.print("▾", row.value_rect.x + row.value_rect.w - 14, row.value_rect.y + 3)
end

function Inspector:_draw_color(row)
  local s = row.schema
  local v = self:_get(s)
  local mixed = Inspector.is_mixed(v)
  local active = self.focus and self.focus.id == row.id
  local rgb = (not mixed and v) or { 0.25, 0.25, 0.25 }
  set_col(rgb)
  love.graphics.rectangle("fill", row.swatch_rect.x, row.swatch_rect.y, row.swatch_rect.w, row.swatch_rect.h, 3, 3)
  set_col(COL.border)
  love.graphics.rectangle("line", row.swatch_rect.x, row.swatch_rect.y, row.swatch_rect.w, row.swatch_rect.h, 3, 3)
  if mixed or not v then
    set_col(COL.muted)
    love.graphics.line(
      row.swatch_rect.x + 2, row.swatch_rect.y + 2,
      row.swatch_rect.x + row.swatch_rect.w - 2, row.swatch_rect.y + row.swatch_rect.h - 2
    )
  end

  local fr = row.value_rect
  set_col(COL.field)
  love.graphics.rectangle("fill", fr.x, fr.y, fr.w, fr.h, 3, 3)
  set_col(active and COL.accent or COL.border)
  love.graphics.rectangle("line", fr.x, fr.y, fr.w, fr.h, 3, 3)
  if active then
    draw_edit_text(fr, self.edit_text, self.edit_sel_all)
  else
    set_col(COL.text)
    local text
    if mixed then
      text = MIXED_TEXT
    elseif v then
      text = string.format("%.2f, %.2f, %.2f", v[1], v[2], v[3])
    else
      text = "(style)"
    end
    love.graphics.print(text, fr.x + 4, fr.y + 3)
  end
end

function Inspector:_draw_bool(row)
  local on = self:_get(row.schema)
  set_col(on and COL.accent or COL.field)
  love.graphics.rectangle("fill", row.check_rect.x, row.check_rect.y, row.check_rect.w, row.check_rect.h, 3, 3)
  set_col(COL.border)
  love.graphics.rectangle("line", row.check_rect.x, row.check_rect.y, row.check_rect.w, row.check_rect.h, 3, 3)
  if on then
    set_col(COL.text)
    love.graphics.print("✓", row.check_rect.x + 2, row.check_rect.y + 1)
  end
end

function Inspector:_draw_picker()
  local p = self.picker
  if not p then return end
  set_col({ 0.12, 0.13, 0.15 }, 0.98)
  love.graphics.rectangle("fill", p.rect.x, p.rect.y, p.rect.w, p.rect.h, 6, 6)
  set_col(COL.border)
  love.graphics.rectangle("line", p.rect.x, p.rect.y, p.rect.w, p.rect.h, 6, 6)

  -- SV square
  local sv = p.sv_rect
  for yi = 0, sv.h - 1, 2 do
    for xi = 0, sv.w - 1, 2 do
      local s = xi / sv.w
      local v = 1 - yi / sv.h
      local r, g, b = hsv_to_rgb(p.h, s, v)
      love.graphics.setColor(r, g, b, 1)
      love.graphics.rectangle("fill", sv.x + xi, sv.y + yi, 2, 2)
    end
  end
  set_col(COL.text)
  love.graphics.circle("line", sv.x + p.s * sv.w, sv.y + (1 - p.v) * sv.h, 5)

  -- Hue bar
  local hr = p.hue_rect
  for yi = 0, hr.h - 1, 2 do
    local r, g, b = hsv_to_rgb(yi / hr.h, 1, 1)
    love.graphics.setColor(r, g, b, 1)
    love.graphics.rectangle("fill", hr.x, hr.y + yi, hr.w, 2)
  end
  set_col(COL.text)
  love.graphics.rectangle("line", hr.x - 1, hr.y + p.h * hr.h - 2, hr.w + 2, 4)

  set_col(p.rgb)
  love.graphics.rectangle("fill", p.preview.x, p.preview.y, p.preview.w, p.preview.h, 3, 3)
  set_col(COL.border)
  love.graphics.rectangle("line", p.preview.x, p.preview.y, p.preview.w, p.preview.h, 3, 3)

  set_col(COL.accent)
  love.graphics.rectangle("fill", p.ok.x, p.ok.y, p.ok.w, p.ok.h, 3, 3)
  set_col(COL.arrow)
  love.graphics.rectangle("fill", p.cancel.x, p.cancel.y, p.cancel.w, p.cancel.h, 3, 3)
  set_col(COL.text)
  love.graphics.print("OK", p.ok.x + 18, p.ok.y + 3)
  love.graphics.print("Close", p.cancel.x + 12, p.cancel.y + 3)
end

function Inspector:draw()
  local b = self.bounds
  set_col(COL.bg)
  love.graphics.rectangle("fill", b.x, b.y, b.w, b.h)
  set_col(COL.header)
  love.graphics.rectangle("fill", b.x, b.y, b.w, 40)
  set_col(COL.text)
  love.graphics.print(self.title, b.x + 10, b.y + 6)
  set_col(COL.muted)
  love.graphics.print(self.subtitle, b.x + 10, b.y + 22)

  love.graphics.setScissor(b.x, b.y + 40, b.w, b.h - 40)
  for _, row in ipairs(self.rows) do
    if row.y + row.h >= b.y + 40 and row.y <= b.y + b.h then
      if row.type == "header" then
        set_col(COL.header)
        love.graphics.rectangle("fill", row.x, row.y, row.w, row.h, 3, 3)
        set_col(COL.accent)
        love.graphics.print(row.label, row.x + 6, row.y + 3)
      else
        -- Draggable number labels get a hint cursor look
        if row.type == "number" then
          set_col(COL.accent)
        else
          set_col(COL.muted)
        end
        love.graphics.print(row.label, row.label_rect.x, row.label_rect.y + 3)
        if row.type == "number" then
          self:_draw_number(row)
        elseif row.type == "color" then
          self:_draw_color(row)
        elseif row.type == "enum" then
          self:_draw_enum(row)
        elseif row.type == "bool" then
          self:_draw_bool(row)
        else
          self:_draw_text(row)
        end
      end
    end
  end
  love.graphics.setScissor()

  if self.dropdown then
    local d = self.dropdown
    set_col({ 0.12, 0.13, 0.15 })
    love.graphics.rectangle("fill", d.rect.x, d.rect.y, d.rect.w, d.rect.h, 3, 3)
    set_col(COL.border)
    love.graphics.rectangle("line", d.rect.x, d.rect.y, d.rect.w, d.rect.h, 3, 3)
    for i, opt in ipairs(d.options) do
      local y = d.rect.y + (i - 1) * 20
      set_col(COL.text)
      local text = opt
      if type(opt) == "table" then
        text = opt.label or opt.id or opt.value or opt[1]
      end
      love.graphics.print(tostring(text), d.rect.x + 6, y + 2)
    end
  end

  self:_draw_picker()
end

return Inspector
