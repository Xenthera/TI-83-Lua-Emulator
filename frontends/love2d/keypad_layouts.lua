-- Load ui/keypads/<machine>.lua into Love keypad widgets.

local Format = require("ui.keypads.format")

local M = {}

-- Authored label_size / legend_size are points at this design-unit reference.
-- Fonts scale with the keypad unit so the calculator looks identical at any size.
M.FONT_REF_UNIT = 40

--- Isotropic design unit (px or scene units): button size is independent of plate aspect.
-- A 1×1 key is always square; stretching the panel background does not stretch keys.
function M.grid_unit(panel_w, panel_h, cols, rows)
  cols = math.max(0.01, tonumber(cols) or 1)
  rows = math.max(0.01, tonumber(rows) or 1)
  panel_w = tonumber(panel_w) or 0
  panel_h = tonumber(panel_h) or 0
  if panel_w <= 0 or panel_h <= 0 then return 0 end
  return math.min(panel_w / cols, panel_h / rows)
end

function M.font_px(authored, unit, fallback)
  local pts = tonumber(authored) or fallback or 12
  local u = tonumber(unit) or M.FONT_REF_UNIT
  local scale = u / M.FONT_REF_UNIT
  return math.max(1, math.floor(pts * scale + 0.5))
end

--- Resolve outline for a layout key / runtime button (nil ⇒ no stroke).
function M.resolve_outline(b, style)
  return Format.outline_resolved({
    outline = b.outline,
    outline_color = b.outline_color,
    outline_alpha = b.outline_alpha,
    outline_width = b.outline_width,
    outline_inset = b.outline_inset,
  }, style or b.style)
end

--- Draw a key outline. `circular` uses a circle; otherwise a rounded rect.
function M.draw_outline(x, y, w, h, radius, circular, spec)
  if not spec or not love or not love.graphics then return end
  local m = math.min(w, h)
  if m <= 0 then return end
  local inset = (spec.inset or 0) * m
  local width = (spec.width or 0.03) * m
  if width <= 0 then return end
  local c = spec.color or { 0, 0, 0 }
  local a = spec.alpha
  if a == nil then a = 1 end
  love.graphics.setColor(c[1], c[2], c[3], a)
  love.graphics.setLineWidth(width)
  if circular then
    local cx = x + w * 0.5
    local cy = y + h * 0.5
    local r = m * 0.5 - inset
    if r > 0.5 then
      love.graphics.circle("line", cx, cy, r)
    end
  else
    local iw = w - inset * 2
    local ih = h - inset * 2
    if iw > 0.5 and ih > 0.5 then
      local ir = math.max(0, (radius or 0) - inset * 0.35)
      ir = math.min(ir, iw * 0.5, ih * 0.5)
      love.graphics.rectangle("line", x + inset, y + inset, iw, ih, ir, ir)
    end
  end
  love.graphics.setLineWidth(1)
end

function M.path(root, machine)
  return Format.default_path(root, machine)
end

function M.load(root, machine)
  local path = M.path(root, machine)
  local doc, err = Format.load(path)
  if not doc then return nil, err, path end
  return doc, nil, path
end

--- Convert layout buttons into KEYS-shaped rows (array + named extras).
-- mode "83": second, alpha, fkey
-- mode "89": second, shift(diamond ink), alpha
function M.to_legacy_rows(doc, mode)
  mode = mode or "83"
  local rows = {}
  for _, b in ipairs((doc and doc.buttons) or {}) do
    if b.kind ~= "label" then
      local row
      if mode == "89" then
        row = {
          b.id, b.label, b.style, b.x, b.y, b.w, b.h, b.second, b.shift, b.alpha,
        }
      else
        row = {
          b.id, b.label, b.style, b.x, b.y, b.w, b.h, b.second, b.alpha, b.fkey,
        }
      end
      row.radius = b.radius
      row.color = b.color
      row.label_color = b.label_color
      row.label_size = b.label_size
      row.legend_size = b.legend_size
      row.shape = b.shape
      row.outline = b.outline
      row.outline_color = b.outline_color
      row.outline_alpha = b.outline_alpha
      row.outline_width = b.outline_width
      row.outline_inset = b.outline_inset
      row.face_glyph = b.face_glyph
      rows[#rows + 1] = row
    end
  end
  return rows
end

function M.decor_labels(doc)
  local out = {}
  for _, b in ipairs((doc and doc.buttons) or {}) do
    if b.kind == "label" then
      out[#out + 1] = {
        label = b.label or "",
        style = b.style or "fn",
        x = b.x, y = b.y, w = b.w, h = b.h,
        radius = b.radius,
        color = b.color,
        label_color = b.label_color,
        label_size = b.label_size,
        legend_size = b.legend_size,
        shape = b.shape,
        outline = b.outline,
        outline_color = b.outline_color,
        outline_alpha = b.outline_alpha,
        outline_width = b.outline_width,
        outline_inset = b.outline_inset,
        face_glyph = b.face_glyph,
      }
    end
  end
  return out
end

function M.theme_for_keypad_ui(doc)
  if not doc then return nil end
  local styles = {}
  for name, rgb in pairs(doc.theme.styles or {}) do
    styles[name] = { rgb[1], rgb[2], rgb[3] }
  end
  local function rgba(c)
    return { c[1], c[2], c[3], 1 }
  end
  return {
    style = styles,
    body = doc.plate.body,
    fkey_band = doc.plate.fkey_band,
    legend_2nd = rgba(doc.theme.legend_2nd),
    legend_alpha = rgba(doc.theme.legend_alpha),
    legend_fkey = rgba(doc.theme.legend_fkey),
    press = doc.theme.press,
    label_size = doc.theme.label_size or 12,
    legend_size = doc.theme.legend_size or 9,
    panel_radius = (doc.panel and doc.panel.radius) or (doc.plate and doc.plate.radius) or 0,
    col = {
      black = { 0.07, 0.07, 0.07 },
      white = { 0.95, 0.95, 0.95 },
      gray = doc.plate.body,
    },
  }
end

return M
