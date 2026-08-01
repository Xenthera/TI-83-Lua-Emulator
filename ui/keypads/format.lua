-- Shared calculator face layout (Love + ComputerCraft).
--
-- File shape (Lua module returning one table):
--   format = "ti-keypad-layout"
--   version = 2
--   machine = "ti83plus" | "ti84plus" | "ti89" | "ti92plus"
--   design_cols, design_rows   -- button grid inside panel
--   face_aspect               -- panel-only aspect (compat)
--   scene = { w, h }          -- full face design space (LCD + panel)
--   lcd = { x, y, w, h, radius, color, glass }
--   panel = { x, y, w, h, radius }  -- keypad plate rect in scene units
--   plate = { body, fkey_band, fkey_band_end, radius }
--   theme = { styles, legend_*, press }
--   buttons = {
--     { id, label, style, x, y, w, h, second?, alpha?, shift?, fkey?,
--       kind?, radius?, color?, label_color?, label_size?, legend_size?,
--       shape?, outline?, face_glyph? },
--   }
-- Button x/y/w/h are relative to panel (design_cols × design_rows).
-- radius is in design units (scaled by scene unit → pixels).
-- color is optional {r,g,b} override; nil uses theme.styles[style].
-- label_size / legend_size are font points at a reference design unit (~40px);
-- runtimes scale them with the keypad so the face looks identical at any size.
-- shape = "auto"|"rect"|"circle"  (auto: fkey/arrow → circle on TI-89)
-- outline = "auto"|"none"|"dark"|"light"|"custom"  (auto: shift → light on TI-89)
-- Optional outline overrides (nil = use preset for the mode):
--   outline_color {r,g,b}, outline_alpha 0..1,
--   outline_width / outline_inset as fractions of min(button_w, button_h)
-- face_glyph = "auto"|"text"|"arrow_up"|"arrow_down"|"arrow_left"|"arrow_right"
--              |"diamond"|"sto"|"backspace"
-- Legend glyph tokens (in second/shift/alpha): switch, deg, angle, #, inf_i, theta

local Format = {}

Format.FORMAT = "ti-keypad-layout"
Format.VERSION = 2

local MACHINES = {
  "ti83plus",
  "ti84plus",
  "ti89",
  "ti92plus",
}

-- LCD pixel aspect (height/width) for default scene seeding.
local LCD_ASPECT = {
  ti83plus = 64 / 96,
  ti84plus = 64 / 96,
  ti89 = 100 / 160,
  ti92plus = 128 / 240,
}

function Format.machines()
  return MACHINES
end

function Format.lcd_aspect(machine)
  return LCD_ASPECT[machine] or LCD_ASPECT.ti83plus
end

--- Force LCD rect height from width using the machine's pixel aspect (no letterbox slot).
function Format.snap_lcd_aspect(lcd, machine)
  lcd = lcd or {}
  local w = tonumber(lcd.w) or 1
  if w < 0.01 then w = 0.01 end
  lcd.w = w
  lcd.h = w * Format.lcd_aspect(machine)
  return lcd
end

function Format.default_path(root, machine)
  return (root or ".") .. "/ui/keypads/" .. machine .. ".lua"
end

local function copy_rgb(c)
  if type(c) ~= "table" then return nil end
  return { c[1] or 0, c[2] or 0, c[3] or 0 }
end

local function copy_rgb_def(c, def)
  return copy_rgb(c) or { def[1], def[2], def[3] }
end

local function rect_fields(src, defaults)
  src = src or {}
  defaults = defaults or {}
  return {
    x = tonumber(src.x) or defaults.x or 0,
    y = tonumber(src.y) or defaults.y or 0,
    w = tonumber(src.w) or defaults.w or 1,
    h = tonumber(src.h) or defaults.h or 1,
    radius = tonumber(src.radius) or defaults.radius or 0,
  }
end

function Format.default_scene(machine, design_cols, design_rows)
  machine = machine or "ti83plus"
  design_cols = tonumber(design_cols) or 5
  design_rows = tonumber(design_rows) or 13.2
  local lcd_h = design_cols * Format.lcd_aspect(machine)
  local gap = math.max(0.15, design_cols * 0.04)
  local lcd_w = design_cols
  -- TI-89 retail LCD is narrower than the key face.
  if machine == "ti89" then
    lcd_w = design_cols * 0.93
  end
  local lcd_x = (design_cols - lcd_w) * 0.5
  return {
    scene = { w = design_cols, h = lcd_h + gap + design_rows },
    lcd = {
      x = lcd_x,
      y = 0,
      w = lcd_w,
      h = lcd_h,
      radius = 0.08,
      color = { 0.08, 0.08, 0.09 },
      glass = { 0.12, 0.14, 0.12 },
    },
    panel = {
      x = 0,
      y = lcd_h + gap,
      w = design_cols,
      h = design_rows,
      radius = 0.06,
    },
  }
end

local DEFAULT_LABEL_SIZE = 12
local DEFAULT_LEGEND_SIZE = 9

local SHAPES = { auto = true, rect = true, circle = true }
local OUTLINES = { auto = true, none = true, dark = true, light = true, custom = true }
local FACE_GLYPHS = {
  auto = true, text = true,
  arrow_up = true, arrow_down = true, arrow_left = true, arrow_right = true,
  diamond = true, sto = true, backspace = true,
}

-- Preset outline metrics (width/inset are fractions of min(button_w, button_h)).
local OUTLINE_PRESETS = {
  dark = { width = 0.03, inset = 0.012, color = { 0.0, 0.0, 0.0 }, alpha = 0.40 },
  light = { width = 0.04, inset = 0.08, color = { 0.95, 0.95, 0.95 }, alpha = 0.95 },
  custom = { width = 0.04, inset = 0.08, color = { 1.0, 1.0, 1.0 }, alpha = 1.0 },
}

--- Resolve outline drawing params for a button. Returns nil when none/disabled.
-- style_for_auto: button style used when outline == "auto" (shift → light).
function Format.outline_resolved(b, style_for_auto)
  b = b or {}
  local mode = tostring(b.outline or "auto")
  if not OUTLINES[mode] then mode = "auto" end
  if mode == "auto" then
    mode = (style_for_auto == "shift") and "light" or "dark"
  end
  if mode == "none" then return nil end
  local preset = OUTLINE_PRESETS[mode] or OUTLINE_PRESETS.custom
  local color = copy_rgb(b.outline_color) or { preset.color[1], preset.color[2], preset.color[3] }
  local alpha = tonumber(b.outline_alpha)
  if alpha == nil then alpha = preset.alpha end
  local width = tonumber(b.outline_width)
  if width == nil then width = preset.width end
  local inset = tonumber(b.outline_inset)
  if inset == nil then inset = preset.inset end
  return {
    mode = mode,
    width = width,
    inset = inset,
    color = color,
    alpha = alpha,
  }
end

function Format.outline_preset(mode)
  return OUTLINE_PRESETS[mode] or OUTLINE_PRESETS.custom
end

function Format.normalize_button(b, theme_defaults)
  b = b or {}
  theme_defaults = theme_defaults or {}
  local color = copy_rgb(b.color)
  local label_size = tonumber(b.label_size)
  local legend_size = tonumber(b.legend_size)
  if not label_size then
    label_size = tonumber(theme_defaults.label_size) or DEFAULT_LABEL_SIZE
  end
  if not legend_size then
    legend_size = tonumber(theme_defaults.legend_size) or DEFAULT_LEGEND_SIZE
  end
  local shape = tostring(b.shape or "auto")
  if not SHAPES[shape] then shape = "auto" end
  local outline = tostring(b.outline or "auto")
  if not OUTLINES[outline] then outline = "auto" end
  local face_glyph = tostring(b.face_glyph or "auto")
  if not FACE_GLYPHS[face_glyph] then face_glyph = "auto" end
  return {
    id = tostring(b.id or b.key or ""),
    label = tostring(b.label or b.id or b.key or ""),
    style = tostring(b.style or "fn"),
    x = tonumber(b.x or b.col) or 0,
    y = tonumber(b.y or b.row) or 0,
    w = tonumber(b.w) or 1,
    h = tonumber(b.h) or 1,
    second = b.second,
    alpha = b.alpha,
    shift = b.shift or b.diamond,
    fkey = b.fkey,
    kind = (b.kind == "label") and "label" or "key",
    radius = tonumber(b.radius) or 0.12,
    color = color, -- nil => theme style
    label_color = copy_rgb(b.label_color), -- nil => auto ink from face/style
    label_size = math.floor(label_size + 0.5),
    legend_size = math.floor(legend_size + 0.5),
    shape = shape,
    outline = outline,
    outline_color = copy_rgb(b.outline_color),
    outline_alpha = tonumber(b.outline_alpha),
    outline_width = tonumber(b.outline_width),
    outline_inset = tonumber(b.outline_inset),
    face_glyph = face_glyph,
  }
end

function Format.normalize(doc)
  doc = doc or {}
  local machine = tostring(doc.machine or "ti83plus")
  local design_cols = tonumber(doc.design_cols) or 5
  local design_rows = tonumber(doc.design_rows) or 13.2
  local defaults = Format.default_scene(machine, design_cols, design_rows)

  local plate = doc.plate or {}
  local theme = doc.theme or {}
  local scene = doc.scene or defaults.scene
  local lcd_src = doc.lcd or defaults.lcd
  local panel_src = doc.panel or defaults.panel

  local lcd = rect_fields(lcd_src, defaults.lcd)
  lcd.color = copy_rgb_def(lcd_src.color, defaults.lcd.color)
  lcd.glass = copy_rgb_def(lcd_src.glass, defaults.lcd.glass)
  Format.snap_lcd_aspect(lcd, machine)

  local panel = rect_fields(panel_src, defaults.panel)

  -- Keep scene large enough to contain lcd + panel.
  local scene_w = tonumber(scene.w) or defaults.scene.w
  local scene_h = tonumber(scene.h) or defaults.scene.h
  scene_w = math.max(scene_w, lcd.x + lcd.w, panel.x + panel.w, 1)
  scene_h = math.max(scene_h, lcd.y + lcd.h, panel.y + panel.h, 1)

  local styles = {}
  for name, rgb in pairs(theme.styles or {}) do
    styles[name] = copy_rgb(rgb) or { 0.3, 0.3, 0.3 }
  end

  local theme_sizes = {
    label_size = math.floor((tonumber(theme.label_size) or DEFAULT_LABEL_SIZE) + 0.5),
    legend_size = math.floor((tonumber(theme.legend_size) or DEFAULT_LEGEND_SIZE) + 0.5),
  }

  local buttons = {}
  for i, b in ipairs(doc.buttons or doc.keys or {}) do
    buttons[i] = Format.normalize_button(b, theme_sizes)
  end

  return {
    format = Format.FORMAT,
    version = Format.VERSION,
    machine = machine,
    design_cols = design_cols,
    design_rows = design_rows,
    face_aspect = tonumber(doc.face_aspect) or (design_rows / design_cols),
    scene = { w = scene_w, h = scene_h },
    lcd = lcd,
    panel = panel,
    plate = {
      body = copy_rgb_def(plate.body, { 0.30, 0.30, 0.30 }),
      fkey_band = copy_rgb_def(plate.fkey_band, { 0.07, 0.07, 0.07 }),
      fkey_band_end = tonumber(plate.fkey_band_end) or 1.0,
      radius = tonumber(plate.radius) or panel.radius or 0,
    },
    theme = {
      styles = styles,
      label_size = theme_sizes.label_size,
      legend_size = theme_sizes.legend_size,
      legend_2nd = copy_rgb_def(theme.legend_2nd, { 0.87, 0.87, 0.15 }),
      legend_alpha = copy_rgb_def(theme.legend_alpha, { 0.40, 0.70, 0.90 }),
      legend_shift = copy_rgb_def(theme.legend_shift, { 0.62, 0.92, 0.38 }),
      legend_fkey = copy_rgb_def(theme.legend_fkey, { 0.40, 0.70, 0.90 }),
      press = copy_rgb_def(theme.press, { 0.85, 0.50, 0.15 }),
    },
    buttons = buttons,
  }
end

local function encode_rgb(c)
  if not c then return "nil" end
  return string.format("{ %.4f, %.4f, %.4f }", c[1] or 0, c[2] or 0, c[3] or 0)
end

local function encode_str(s)
  if s == nil then return "nil" end
  return string.format("%q", tostring(s))
end

--- Serialize a normalized layout to a Lua module string.
function Format.encode(doc)
  doc = Format.normalize(doc)
  local lines = {
    "-- Auto-generated face layout (ti-keypad-layout v2).",
    "-- Edit with Love2D Panel Editor or by hand. Readable by ComputerCraft.",
    "return {",
    string.format("  format = %q,", Format.FORMAT),
    string.format("  version = %d,", doc.version),
    string.format("  machine = %q,", doc.machine),
    string.format("  design_cols = %.4f,", doc.design_cols),
    string.format("  design_rows = %.4f,", doc.design_rows),
    string.format("  face_aspect = %.4f,", doc.face_aspect),
    string.format("  scene = { w=%.4f, h=%.4f },", doc.scene.w, doc.scene.h),
    "  lcd = {",
    string.format("    x=%.4f, y=%.4f, w=%.4f, h=%.4f, radius=%.4f,",
      doc.lcd.x, doc.lcd.y, doc.lcd.w, doc.lcd.h, doc.lcd.radius),
    string.format("    color = %s,", encode_rgb(doc.lcd.color)),
    string.format("    glass = %s,", encode_rgb(doc.lcd.glass)),
    "  },",
    "  panel = {",
    string.format("    x=%.4f, y=%.4f, w=%.4f, h=%.4f, radius=%.4f,",
      doc.panel.x, doc.panel.y, doc.panel.w, doc.panel.h, doc.panel.radius),
    "  },",
    "  plate = {",
    string.format("    body = %s,", encode_rgb(doc.plate.body)),
    string.format("    fkey_band = %s,", encode_rgb(doc.plate.fkey_band)),
    string.format("    fkey_band_end = %.4f,", doc.plate.fkey_band_end),
    string.format("    radius = %.4f,", doc.plate.radius),
    "  },",
    "  theme = {",
    "    styles = {",
  }
  local style_names = {}
  for name in pairs(doc.theme.styles or {}) do
    style_names[#style_names + 1] = name
  end
  table.sort(style_names)
  for _, name in ipairs(style_names) do
    lines[#lines + 1] = string.format("      [%q] = %s,", name, encode_rgb(doc.theme.styles[name]))
  end
  lines[#lines + 1] = "    },"
  lines[#lines + 1] = string.format("    label_size = %d,", doc.theme.label_size or DEFAULT_LABEL_SIZE)
  lines[#lines + 1] = string.format("    legend_size = %d,", doc.theme.legend_size or DEFAULT_LEGEND_SIZE)
  lines[#lines + 1] = string.format("    legend_2nd = %s,", encode_rgb(doc.theme.legend_2nd))
  lines[#lines + 1] = string.format("    legend_alpha = %s,", encode_rgb(doc.theme.legend_alpha))
  lines[#lines + 1] = string.format("    legend_shift = %s,", encode_rgb(doc.theme.legend_shift))
  lines[#lines + 1] = string.format("    legend_fkey = %s,", encode_rgb(doc.theme.legend_fkey))
  lines[#lines + 1] = string.format("    press = %s,", encode_rgb(doc.theme.press))
  lines[#lines + 1] = "  },"
  lines[#lines + 1] = "  buttons = {"
  for _, b in ipairs(doc.buttons) do
    local ow = b.outline_width ~= nil and string.format("%.4f", b.outline_width) or "nil"
    local oi = b.outline_inset ~= nil and string.format("%.4f", b.outline_inset) or "nil"
    local oa = b.outline_alpha ~= nil and string.format("%.4f", b.outline_alpha) or "nil"
    lines[#lines + 1] = string.format(
      "    { id=%q, label=%q, style=%q, x=%.4f, y=%.4f, w=%.4f, h=%.4f, second=%s, alpha=%s, shift=%s, fkey=%s, kind=%q, radius=%.4f, color=%s, label_color=%s, label_size=%d, legend_size=%d, shape=%q, outline=%q, outline_color=%s, outline_alpha=%s, outline_width=%s, outline_inset=%s, face_glyph=%q },",
      b.id, b.label, b.style, b.x, b.y, b.w, b.h,
      encode_str(b.second), encode_str(b.alpha), encode_str(b.shift), encode_str(b.fkey),
      b.kind, b.radius or 0, encode_rgb(b.color), encode_rgb(b.label_color),
      b.label_size or DEFAULT_LABEL_SIZE, b.legend_size or DEFAULT_LEGEND_SIZE,
      b.shape or "auto", b.outline or "auto",
      encode_rgb(b.outline_color), oa, ow, oi,
      b.face_glyph or "auto"
    )
  end
  lines[#lines + 1] = "  },"
  lines[#lines + 1] = "}"
  lines[#lines + 1] = ""
  return table.concat(lines, "\n")
end

function Format.save(path, doc)
  local f, err = io.open(path, "wb")
  if not f then return nil, err end
  f:write(Format.encode(doc))
  f:close()
  return true
end

function Format.load(path)
  local chunk, err = loadfile(path)
  if not chunk then return nil, err end
  local ok, doc = pcall(chunk)
  if not ok then return nil, doc end
  if type(doc) ~= "table" then return nil, "layout root must be a table" end
  return Format.normalize(doc)
end

--- Convert legacy positional KEYS rows into layout buttons.
-- row: { key, label, style, col, row, w, h, second?, alpha_or_diamond?, fkey_or_alpha? }
-- mode: "83" (second, alpha, fkey) | "89" (second, diamond, alpha)
function Format.from_legacy_keys(rows, mode)
  mode = mode or "83"
  local buttons = {}
  for _, r in ipairs(rows or {}) do
    local b = {
      id = r[1],
      label = r[2],
      style = r[3],
      x = r[4],
      y = r[5],
      w = r[6],
      h = r[7],
      kind = "key",
      radius = 0.12,
    }
    if mode == "89" then
      b.second = r[8]
      b.shift = r[9]
      b.alpha = r[10]
    else
      b.second = r[8]
      b.alpha = r[9]
      b.fkey = r[10]
    end
    buttons[#buttons + 1] = Format.normalize_button(b)
  end
  return buttons
end

return Format
