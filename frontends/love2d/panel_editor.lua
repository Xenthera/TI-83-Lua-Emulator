-- Full-screen face editor: LCD + keypad panel + buttons (move/resize, radius, color).

local Format = require("ui.keypads.format")
local Catalog = require("ui.keypads.catalog")
local Inspector = require("panel_inspector")
local KeypadUI = require("keypad_ui")
local KeypadTI84 = require("keypad_ti84")
local KeypadTI89 = require("keypad_ti89")
local KeypadTI92 = require("keypad_ti92")

local PanelEditor = {}
PanelEditor.__index = PanelEditor

local HANDLE = 8
local SNAP_DEFAULT = 0.05
local MIN_SIZE = 0.25

local UI = {
  bg = { 0.12, 0.13, 0.15 },
  panel = { 0.16, 0.17, 0.19 },
  border = { 0.35, 0.38, 0.42 },
  text = { 0.90, 0.92, 0.94 },
  muted = { 0.55, 0.58, 0.62 },
  accent = { 0.35, 0.65, 0.95 },
  danger = { 0.85, 0.35, 0.30 },
  field = { 0.10, 0.11, 0.13 },
  sel = { 1.0, 0.75, 0.20 },
  grid = { 0.25, 0.28, 0.32, 0.55 },
  lcd_sel = { 0.45, 0.85, 1.0 },
  panel_sel = { 1.0, 0.75, 0.20 },
}

local MACHINES = { "ti83plus", "ti84plus", "ti89", "ti92plus" }
local MACHINE_LABEL = {
  ti83plus = "TI-83+",
  ti84plus = "TI-84+",
  ti89 = "TI-89 Ti",
  ti92plus = "TI-92+",
}

local function clamp(v, a, b)
  if v < a then return a end
  if v > b then return b end
  return v
end

local function snap(v, step)
  if not step or step <= 0 then return v end
  return math.floor(v / step + 0.5) * step
end

local function copy_doc(doc)
  return Format.normalize(doc)
end

local function hit_rect(r, x, y)
  return r and x >= r.x and y >= r.y and x < r.x + r.w and y < r.y + r.h
end

local function rects_overlap(ax, ay, aw, ah, bx, by, bw, bh)
  return ax < bx + bw and ax + aw > bx and ay < by + bh and ay + ah > by
end

function PanelEditor.new(opts)
  opts = opts or {}
  local self = setmetatable({}, PanelEditor)
  self.root = opts.root or "."
  self.machine = opts.machine or "ti83plus"
  self.on_close = opts.on_close
  self.on_saved = opts.on_saved
  self.snap = SNAP_DEFAULT
  self.show_grid = true
  -- Selection: { kind="lcd"|"panel" } or { kind="button", indices={...}, primary=n }
  self.selected = nil
  self.drag = nil
  self.palette_drag = nil
  self.box_select = nil -- { x0, y0, x1, y1, mode="replace"|"add" }
  self.measure = nil -- { ax, ay, bx, by, active } button-design snap units
  self.cursor_x, self.cursor_y = 0, 0
  self.status = ""
  self.status_t = 0
  self.undo = {}
  self.redo = {}
  self.docs = {}
  self.seeds = {}
  self.inspector = Inspector.new({
    on_begin_change = function()
      self:push_undo()
    end,
    on_change = function(id)
      if self.selected and (self.selected.kind == "lcd" or self.selected.kind == "panel") then
        if self.selected.kind == "panel" then
          self.doc.plate.radius = self.doc.panel.radius
          self.doc.face_aspect = self.doc.panel.h / math.max(0.01, self.doc.panel.w)
        end
        self:_grow_scene()
        self:_layout_canvas()
      end
      if self.selected and self.selected.kind == "button" then
        self:_rebuild_palette()
        if id == "id" then self:_rebuild_inspector() end
      end
      self._preview_dirty = true
    end,
  })
  self.symbol_target = "second" -- which legend field symbols insert into
  self._preview_kp = nil
  self._preview_machine = nil
  self._preview_dirty = true
  self:_load_all()
  self:set_machine(self.machine)
  self:layout(love.graphics.getDimensions())
  return self
end

function PanelEditor:_make_preview_keypad(id)
  local layout = self.doc
  if id == "ti89" then
    return KeypadTI89.new({ layout = layout })
  elseif id == "ti92plus" then
    return KeypadTI92.new({ layout = layout })
  elseif id == "ti84plus" then
    return KeypadTI84.new({ layout = layout })
  end
  return KeypadUI.new({ layout = layout })
end

function PanelEditor:_sync_preview()
  if self._preview_machine ~= self.machine or not self._preview_kp then
    self._preview_kp = self:_make_preview_keypad(self.machine)
    self._preview_machine = self.machine
    self._preview_dirty = true
  end
  if self._preview_dirty and self._preview_kp.reload_layout then
    self._preview_kp:reload_layout(self.doc)
    self._preview_dirty = false
  end
  local pr = self:_panel_screen()
  if pr and pr.w > 8 and pr.h > 8 then
    self._preview_kp:layout(pr.x, pr.y, pr.w, pr.h)
  end
end

function PanelEditor:_path(machine)
  return Format.default_path(self.root, machine)
end

function PanelEditor:_load_all()
  for _, mid in ipairs(MACHINES) do
    local path = self:_path(mid)
    local doc, err = Format.load(path)
    if doc then
      self.docs[mid] = doc
      self.seeds[mid] = copy_doc(doc)
    else
      self.status = "Missing " .. mid .. ": " .. tostring(err)
      self.docs[mid] = Format.normalize({ machine = mid, buttons = {} })
      self.seeds[mid] = copy_doc(self.docs[mid])
    end
  end
end

function PanelEditor:set_machine(mid)
  if not self.docs[mid] then return end
  self:commit_edit()
  self.machine = mid
  self.doc = self.docs[mid]
  self.selected = nil
  self.drag = nil
  self.palette_drag = nil
  self.box_select = nil
  self.measure = nil
  self._preview_kp = nil
  self._preview_machine = nil
  self._preview_dirty = true
  self.symbol_target = "second"
  self:_rebuild_palette()
  self:_rebuild_inspector()
  self:set_status("Editing " .. (MACHINE_LABEL[mid] or mid) .. " (live keypad preview)")
end

function PanelEditor:_select(sel)
  self:commit_edit()
  if sel and sel.kind == "button" then
    local i = sel.i or (sel.indices and sel.indices[1])
    if not i then
      self.selected = nil
    else
      local indices = sel.indices
      if not indices then indices = { i } end
      self.selected = {
        kind = "button",
        indices = indices,
        primary = sel.primary or indices[#indices] or i,
      }
    end
  else
    self.selected = sel
  end
  self:_rebuild_inspector()
end

function PanelEditor:_button_indices()
  local sel = self.selected
  if not sel or sel.kind ~= "button" then return {} end
  return sel.indices or {}
end

function PanelEditor:_selected_buttons()
  local out = {}
  for _, i in ipairs(self:_button_indices()) do
    local b = self.doc.buttons[i]
    if b then out[#out + 1] = b end
  end
  return out
end

function PanelEditor:_primary_button_index()
  local sel = self.selected
  if not sel or sel.kind ~= "button" then return nil end
  return sel.primary or sel.indices[#sel.indices]
end

function PanelEditor:_is_button_selected(i)
  for _, j in ipairs(self:_button_indices()) do
    if j == i then return true end
  end
  return false
end

function PanelEditor:_select_button(i, mode)
  self:commit_edit()
  mode = mode or "replace"
  if mode == "replace" or not self.selected or self.selected.kind ~= "button" then
    self.selected = { kind = "button", indices = { i }, primary = i }
  else
    local indices = self.selected.indices
    local found
    for k, v in ipairs(indices) do
      if v == i then found = k break end
    end
    if mode == "toggle" then
      if found then
        table.remove(indices, found)
        if #indices == 0 then
          self.selected = nil
        else
          self.selected.primary = indices[#indices]
        end
      else
        indices[#indices + 1] = i
        self.selected.primary = i
      end
    else -- add
      if not found then indices[#indices + 1] = i end
      self.selected.primary = i
    end
  end
  self:_rebuild_inspector()
end

function PanelEditor:_select_buttons_in_rect(x0, y0, x1, y1, mode)
  self:commit_edit()
  local rx, ry = math.min(x0, x1), math.min(y0, y1)
  local rw, rh = math.abs(x1 - x0), math.abs(y1 - y0)
  local hits = {}
  for i = 1, #self.doc.buttons do
    local r = self:_button_screen(i)
    if r and r.w > 0 and r.h > 0 and rects_overlap(rx, ry, rw, rh, r.x, r.y, r.w, r.h) then
      hits[#hits + 1] = i
    end
  end
  mode = mode or "replace"
  if mode == "add" and self.selected and self.selected.kind == "button" then
    local seen = {}
    for _, i in ipairs(self.selected.indices) do seen[i] = true end
    for _, i in ipairs(hits) do
      if not seen[i] then
        self.selected.indices[#self.selected.indices + 1] = i
        seen[i] = true
      end
    end
    if #hits > 0 then
      self.selected.primary = hits[#hits]
    end
  elseif #hits == 0 then
    self.selected = nil
  else
    self.selected = { kind = "button", indices = hits, primary = hits[#hits] }
  end
  self:_rebuild_inspector()
  if #hits > 0 then
    self:set_status(string.format("Box-selected %d button%s", #hits, #hits == 1 and "" or "s"))
  end
end

local function values_equal(a, b)
  if a == b then return true end
  if type(a) ~= type(b) then return false end
  if type(a) == "table" then
    if a[1] ~= nil or b[1] ~= nil then
      return math.abs((a[1] or 0) - (b[1] or 0)) < 1e-4
        and math.abs((a[2] or 0) - (b[2] or 0)) < 1e-4
        and math.abs((a[3] or 0) - (b[3] or 0)) < 1e-4
    end
  end
  return false
end

function PanelEditor:_multi_get(key, map)
  local buttons = self:_selected_buttons()
  if #buttons == 0 then return nil end
  local first = map and map(buttons[1]) or buttons[1][key]
  for i = 2, #buttons do
    local v = map and map(buttons[i]) or buttons[i][key]
    if not values_equal(first, v) then
      return Inspector.MIXED
    end
  end
  return first
end

function PanelEditor:_multi_set(key, value, map_set)
  for _, b in ipairs(self:_selected_buttons()) do
    if map_set then
      map_set(b, value)
    else
      b[key] = value
    end
  end
end

function PanelEditor:_multi_num(key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "number",
    min = opts.min,
    max = opts.max,
    step = opts.step or 0.05,
    precision = opts.precision,
    get = function() return self:_multi_get(key) end,
    set = function(v) self:_multi_set(key, v) end,
  }
end

function PanelEditor:_multi_text(key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "text",
    nullable = opts.nullable,
    get = function() return self:_multi_get(key) end,
    set = function(v)
      if opts.nullable and (v == "" or v == nil) then
        self:_multi_set(key, nil)
      else
        self:_multi_set(key, v)
      end
    end,
  }
end

function PanelEditor:_multi_color(key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "color",
    nullable = opts.nullable,
    get = function() return self:_multi_get(key) end,
    set = function(v) self:_multi_set(key, v) end,
  }
end

function PanelEditor:_multi_enum(key, label, options, map)
  return {
    id = key,
    label = label,
    type = "enum",
    options = options,
    get = function() return self:_multi_get(key, map) end,
    set = function(v) self:_multi_set(key, v) end,
  }
end

function PanelEditor:_rebuild_palette()
  local used = {}
  for _, b in ipairs(self.doc.buttons) do
    if b.kind ~= "label" and b.id ~= "" then
      used[b.id] = true
    end
  end
  local ids = Catalog.key_ids(self.machine)
  self.palette = {}
  for _, id in ipairs(ids) do
    if not used[id] then
      self.palette[#self.palette + 1] = id
    end
  end
end

function PanelEditor:set_status(msg)
  self.status = tostring(msg or "")
  self.status_t = 3
end

function PanelEditor:push_undo()
  self.undo[#self.undo + 1] = Format.encode(self.doc)
  if #self.undo > 40 then table.remove(self.undo, 1) end
  self.redo = {}
end

function PanelEditor:do_undo()
  if #self.undo == 0 then return end
  self.redo[#self.redo + 1] = Format.encode(self.doc)
  local raw = table.remove(self.undo)
  local chunk = loadstring and loadstring(raw) or load(raw)
  if chunk then
    self.doc = Format.normalize(chunk())
    self.docs[self.machine] = self.doc
    self.selected = nil
    self._preview_dirty = true
    self:_rebuild_palette()
    self:_layout_canvas()
    self:_rebuild_inspector()
  end
end

function PanelEditor:do_redo()
  if #self.redo == 0 then return end
  self.undo[#self.undo + 1] = Format.encode(self.doc)
  local raw = table.remove(self.redo)
  local chunk = loadstring and loadstring(raw) or load(raw)
  if chunk then
    self.doc = Format.normalize(chunk())
    self.docs[self.machine] = self.doc
    self.selected = nil
    self._preview_dirty = true
    self:_rebuild_palette()
    self:_layout_canvas()
    self:_rebuild_inspector()
  end
end

function PanelEditor:layout(ww, wh)
  -- Ide:draw calls this every frame - avoid rebuilding the inspector schema
  -- (that clears focus, dropdowns, and the color picker).
  local size_changed = self.ww ~= ww or self.wh ~= wh
  self.ww, self.wh = ww, wh
  local top = 44
  local bottom = 28
  local left_w = 196
  local right_w = 280
  self.toolbar = { x = 0, y = 0, w = ww, h = top }
  self.status_bar = { x = 0, y = wh - bottom, w = ww, h = bottom }
  local left_h = wh - top - bottom
  local keys_h = math.floor(left_h * 0.52)
  self.palette_rect = { x = 0, y = top, w = left_w, h = keys_h }
  self.symbol_rect = { x = 0, y = top + keys_h, w = left_w, h = left_h - keys_h }
  self.props_rect = { x = ww - right_w, y = top, w = right_w, h = wh - top - bottom }
  self.canvas_outer = {
    x = left_w,
    y = top,
    w = ww - left_w - right_w,
    h = wh - top - bottom,
  }
  self:_layout_canvas()
  if size_changed then
    self:_layout_toolbar_hits()
  end
  self.inspector:set_bounds(self.props_rect.x, self.props_rect.y, self.props_rect.w, self.props_rect.h)
end

function PanelEditor:_layout_canvas()
  local outer = self.canvas_outer
  local pad = 24
  local sw = self.doc.scene.w
  local sh = self.doc.scene.h
  local avail_w = outer.w - pad * 2
  local avail_h = outer.h - pad * 2
  local unit = math.min(avail_w / sw, avail_h / sh)
  local face_w, face_h = sw * unit, sh * unit
  self.unit = unit
  self.scene_rect = {
    x = outer.x + (outer.w - face_w) * 0.5,
    y = outer.y + (outer.h - face_h) * 0.5,
    w = face_w,
    h = face_h,
  }
  -- compat alias used by older call sites
  self.face = self.scene_rect
  -- Isotropic key grid (matches live keypad); plate aspect does not stretch keys.
  local Layouts = require("keypad_layouts")
  local gu = Layouts.grid_unit(
    self.doc.panel.w * unit,
    self.doc.panel.h * unit,
    self.doc.design_cols or 5,
    self.doc.design_rows or 13
  )
  self.cell_w = gu
  self.cell_h = gu
  self.key_unit = gu / unit -- key unit in scene design units
end

function PanelEditor:_layout_toolbar_hits()
  local y = 8
  local h = 28
  local x = 10
  local hits = {}
  local function btn(id, label, w)
    hits[#hits + 1] = { id = id, label = label, x = x, y = y, w = w, h = h }
    x = x + w + 6
  end
  for _, mid in ipairs(MACHINES) do
    btn("mach_" .. mid, MACHINE_LABEL[mid], 72)
  end
  x = x + 8
  btn("save", "Save", 56)
  btn("reload", "Reload", 64)
  btn("reset", "Reset", 56)
  btn("undo", "Undo", 52)
  btn("redo", "Redo", 52)
  btn("grid", self.show_grid and "Grid:on" or "Grid:off", 72)
  btn("snap", string.format("Snap:%.2f", self.snap), 78)
  btn("sel_lcd", "LCD", 48)
  btn("sel_panel", "Panel", 56)
  btn("add_label", "+ Label", 70)
  btn("delete", "Delete", 60)
  btn("close", "Close", 56)
  self.tool_hits = hits
end

function PanelEditor:_num(obj, key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "number",
    min = opts.min,
    max = opts.max,
    step = opts.step or 0.05,
    precision = opts.precision,
    get = function() return obj[key] end,
    set = function(v) obj[key] = v end,
  }
end

function PanelEditor:_text(obj, key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "text",
    nullable = opts.nullable,
    get = function() return obj[key] end,
    set = function(v) obj[key] = (v == "" and opts.nullable) and nil or v end,
  }
end

function PanelEditor:_color(obj, key, label, opts)
  opts = opts or {}
  return {
    id = key,
    label = label,
    type = "color",
    nullable = opts.nullable,
    get = function() return obj[key] end,
    set = function(v) obj[key] = v end,
  }
end

function PanelEditor:_append_legend_theme_fields(schema)
  schema[#schema + 1] = {
    id = "theme_legend_size", label = "Legend pt", type = "number",
    step = 1, precision = 0,
    get = function() return self.doc.theme.legend_size end,
    set = function(v)
      self.doc.theme.legend_size = v
      for _, b in ipairs(self.doc.buttons) do b.legend_size = v end
    end,
  }
  schema[#schema + 1] = self:_color(self.doc.theme, "legend_2nd", "2nd ink")
  schema[#schema + 1] = self:_color(self.doc.theme, "legend_shift", "Shift/◆ ink")
  schema[#schema + 1] = self:_color(self.doc.theme, "legend_alpha", "Alpha ink")
  schema[#schema + 1] = self:_color(self.doc.theme, "legend_fkey", "F-key ink")
end

function PanelEditor:_rebuild_inspector()
  if not self.inspector or not self.doc then return end
  local sel = self.selected
  local schema = {}
  local title, subtitle = "Inspector", "Select LCD, panel, or key"

  local function header(label)
    schema[#schema + 1] = { type = "header", label = label }
  end

  if not sel then
    header("Scene")
    schema[#schema + 1] = self:_num(self.doc.scene, "w", "Width", { min = 1, step = 0.1, precision = 3 })
    schema[#schema + 1] = self:_num(self.doc.scene, "h", "Height", { min = 1, step = 0.1, precision = 3 })
    header("Defaults")
    schema[#schema + 1] = {
      id = "theme_label_size", label = "Label pt", type = "number",
      step = 1, precision = 0,
      get = function() return self.doc.theme.label_size end,
      set = function(v)
        self.doc.theme.label_size = v
        for _, b in ipairs(self.doc.buttons) do b.label_size = v end
      end,
    }
    header("Legend colors")
    self:_append_legend_theme_fields(schema)
    title = "Scene"
    subtitle = "No selection"
  elseif sel.kind == "lcd" then
    local L = self.doc.lcd
    local aspect = Format.lcd_aspect(self.machine)
    title = "LCD"
    subtitle = "Aspect locked to hardware pixels"
    header("Transform")
    schema[#schema + 1] = self:_num(L, "x", "X", { step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_num(L, "y", "Y", { step = 0.05, precision = 3 })
    schema[#schema + 1] = {
      id = "w", label = "Width", type = "number",
      min = MIN_SIZE, step = 0.05, precision = 3,
      get = function() return L.w end,
      set = function(v)
        L.w = v
        Format.snap_lcd_aspect(L, self.machine)
      end,
    }
    schema[#schema + 1] = {
      id = "h", label = "Height", type = "number",
      min = MIN_SIZE, step = 0.05, precision = 3,
      get = function() return L.h end,
      set = function(v)
        if v < MIN_SIZE then v = MIN_SIZE end
        L.h = v
        L.w = v / aspect
        if L.w < MIN_SIZE then
          L.w = MIN_SIZE
          Format.snap_lcd_aspect(L, self.machine)
        end
      end,
    }
    schema[#schema + 1] = self:_num(L, "radius", "Radius", { min = 0, step = 0.01, precision = 3 })
    header("Appearance")
    schema[#schema + 1] = self:_color(L, "color", "Bezel")
    schema[#schema + 1] = self:_color(L, "glass", "Glass")
  elseif sel.kind == "panel" then
    local P = self.doc.panel
    local plate = self.doc.plate
    title = "Panel"
    subtitle = "Keypad plate"
    header("Transform")
    schema[#schema + 1] = self:_num(P, "x", "X", { step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_num(P, "y", "Y", { step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_num(P, "w", "Width", { min = MIN_SIZE, step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_num(P, "h", "Height", { min = MIN_SIZE, step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_num(P, "radius", "Radius", { min = 0, step = 0.01, precision = 3 })
    header("Plate")
    schema[#schema + 1] = self:_color(plate, "body", "Body")
    schema[#schema + 1] = self:_color(plate, "fkey_band", "F-key band")
    schema[#schema + 1] = self:_num(plate, "fkey_band_end", "Band end", { min = 0, step = 0.1, precision = 2 })
    header("Text defaults")
    schema[#schema + 1] = {
      id = "theme_label_size", label = "Label pt", type = "number",
      step = 1, precision = 0,
      get = function() return self.doc.theme.label_size end,
      set = function(v)
        self.doc.theme.label_size = v
        for _, b in ipairs(self.doc.buttons) do b.label_size = v end
      end,
    }
    header("Legend colors")
    self:_append_legend_theme_fields(schema)
  elseif sel.kind == "button" then
    local buttons = self:_selected_buttons()
    if #buttons == 0 then
      self.inspector:set_schema("Inspector", "Missing button", {})
      return
    end
    local multi = #buttons > 1
    local b0 = buttons[1]
    title = multi and "Buttons" or ((b0.kind == "label") and "Label" or "Button")
    if multi then
      subtitle = string.format("%d selected", #buttons)
    else
      subtitle = (b0.id ~= "" and b0.id) or "(unnamed)"
    end
    local styles = Catalog.styles(self.machine)
    header("Identity")
    if not multi then
      schema[#schema + 1] = self:_multi_text("id", "Key ID")
    end
    schema[#schema + 1] = self:_multi_text("label", "Face")
    schema[#schema + 1] = self:_multi_enum("style", "Style", styles)
    schema[#schema + 1] = self:_multi_enum("kind", "Kind", { "key", "label" })
    header("Legends")
    schema[#schema + 1] = self:_multi_text("second", "2nd", { nullable = true })
    schema[#schema + 1] = self:_multi_text("alpha", "Alpha", { nullable = true })
    schema[#schema + 1] = self:_multi_text("shift", "Shift/◆", { nullable = true })
    schema[#schema + 1] = self:_multi_text("fkey", "F-key", { nullable = true })
    header("Appearance")
    schema[#schema + 1] = self:_multi_color("color", "Face", { nullable = true })
    schema[#schema + 1] = self:_multi_color("label_color", "Ink", { nullable = true })
    schema[#schema + 1] = self:_multi_enum("shape", "Shape", Catalog.SHAPES, function(b)
      return b.shape or "auto"
    end)
    schema[#schema + 1] = self:_multi_enum("outline", "Outline", Catalog.OUTLINES, function(b)
      return b.outline or "auto"
    end)
    local function outline_metric(key)
      return {
        id = key,
        label = (key == "outline_width" and "Stroke")
          or (key == "outline_inset" and "Inset")
          or "Alpha",
        type = "number",
        step = (key == "outline_alpha") and 0.05 or 0.005,
        precision = 3,
        get = function()
          return self:_multi_get(key, function(b)
            if b[key] ~= nil then return b[key] end
            local mode = b.outline or "auto"
            if mode == "auto" then
              mode = (b.style == "shift") and "light" or "dark"
            end
            if mode == "none" then return 0 end
            local preset = Format.outline_preset(mode)
            if key == "outline_width" then return preset.width end
            if key == "outline_inset" then return preset.inset end
            return preset.alpha
          end)
        end,
        set = function(v) self:_multi_set(key, v) end,
      }
    end
    schema[#schema + 1] = outline_metric("outline_width")
    schema[#schema + 1] = outline_metric("outline_inset")
    schema[#schema + 1] = {
      id = "outline_color",
      label = "Stroke color",
      type = "color",
      nullable = true,
      get = function()
        return self:_multi_get("outline_color", function(b)
          if b.outline_color then return b.outline_color end
          local mode = b.outline or "auto"
          if mode == "auto" then
            mode = (b.style == "shift") and "light" or "dark"
          end
          if mode == "none" then return nil end
          local preset = Format.outline_preset(mode)
          return { preset.color[1], preset.color[2], preset.color[3] }
        end)
      end,
      set = function(v) self:_multi_set("outline_color", v) end,
    }
    schema[#schema + 1] = outline_metric("outline_alpha")
    schema[#schema + 1] = self:_multi_enum("face_glyph", "Face glyph", Catalog.FACE_GLYPHS, function(b)
      return b.face_glyph or "auto"
    end)
    schema[#schema + 1] = self:_multi_num("label_size", "Label pt", { step = 1, precision = 0 })
    schema[#schema + 1] = self:_multi_num("legend_size", "Legend pt", { step = 1, precision = 0 })
    schema[#schema + 1] = self:_multi_num("radius", "Radius", { step = 0.01, precision = 3 })
    header("Transform")
    schema[#schema + 1] = self:_multi_num("x", "X", { step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_multi_num("y", "Y", { step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_multi_num("w", "Width", { min = MIN_SIZE, step = 0.05, precision = 3 })
    schema[#schema + 1] = self:_multi_num("h", "Height", { min = MIN_SIZE, step = 0.05, precision = 3 })
  end

  self.inspector:set_schema(title, subtitle, schema)
end

function PanelEditor:insert_symbol(token)
  local buttons = self:_selected_buttons()
  if #buttons == 0 then
    self:set_status("Select a button, then click a symbol")
    return
  end
  local field = self.symbol_target or "second"
  if field == "face_glyph" then
    local known = {
      diamond = true, sto = true, backspace = true,
      arrow_up = true, arrow_down = true, arrow_left = true, arrow_right = true,
    }
    local map = {
      diamond = "diamond", sto = "sto", backspace = "backspace",
      up = "arrow_up", down = "arrow_down", left = "arrow_left", right = "arrow_right",
    }
    local glyph = known[token] and token or (map[token] or "text")
    self:push_undo()
    for _, b in ipairs(buttons) do b.face_glyph = glyph end
    self._preview_dirty = true
    self:set_status(string.format("Face glyph -> %s (%d)", glyph, #buttons))
    return
  end
  if field ~= "second" and field ~= "alpha" and field ~= "shift" and field ~= "fkey" and field ~= "label" then
    field = "second"
  end
  self:push_undo()
  local value = (token == nil or token == "") and nil or token
  for _, b in ipairs(buttons) do b[field] = value end
  self._preview_dirty = true
  if value == nil then
    self:set_status(string.format("%s cleared (%d)", field, #buttons))
  else
    self:set_status(string.format("%s -> %s (%d)", field, value, #buttons))
  end
end

function PanelEditor:scene_to_screen(x, y, w, h)
  local s = self.scene_rect
  local u = self.unit
  return {
    x = s.x + x * u,
    y = s.y + y * u,
    w = w * u,
    h = h * u,
  }
end

function PanelEditor:screen_to_scene(mx, my)
  local s = self.scene_rect
  local u = self.unit
  return (mx - s.x) / u, (my - s.y) / u
end

function PanelEditor:_lcd_screen()
  local L = self.doc.lcd
  return self:scene_to_screen(L.x, L.y, L.w, L.h)
end

function PanelEditor:_panel_screen()
  local P = self.doc.panel
  return self:scene_to_screen(P.x, P.y, P.w, P.h)
end

function PanelEditor:_button_screen(i)
  local b = self.doc.buttons[i]
  if not b then return nil end
  -- Prefer live keypad face rects so selection matches WYSIWYG pixels.
  if self._preview_kp and b.kind ~= "label" then
    for _, pb in ipairs(self._preview_kp.buttons or {}) do
      if pb.key == b.id then
        if pb.legend_y and pb.legend_h then
          local top = pb.legend_y
          local bottom = pb.y + pb.h
          local left = pb.legend_x or pb.x
          local width = pb.legend_w or pb.w
          return { x = left, y = top, w = width, h = bottom - top }
        end
        return { x = pb.x, y = pb.y, w = pb.w, h = pb.h }
      end
    end
  end
  local P = self.doc.panel
  local ku = self.key_unit or math.min(
    P.w / math.max(0.01, self.doc.design_cols or 5),
    P.h / math.max(0.01, self.doc.design_rows or 13)
  )
  local bx = P.x + b.x * ku
  local by = P.y + b.y * ku
  local bw = b.w * ku
  local bh = b.h * ku
  return self:scene_to_screen(bx, by, bw, bh)
end

function PanelEditor:screen_to_button_design(mx, my)
  local P = self.doc.panel
  local sx, sy = self:screen_to_scene(mx, my)
  local ku = self.key_unit or math.min(
    P.w / math.max(0.01, self.doc.design_cols or 5),
    P.h / math.max(0.01, self.doc.design_rows or 13)
  )
  if ku < 1e-6 then return 0, 0 end
  return (sx - P.x) / ku, (sy - P.y) / ku
end

function PanelEditor:button_design_to_screen(dx, dy)
  local P = self.doc.panel
  local ku = self.key_unit or math.min(
    P.w / math.max(0.01, self.doc.design_cols or 5),
    P.h / math.max(0.01, self.doc.design_rows or 13)
  )
  local r = self:scene_to_screen(P.x + dx * ku, P.y + dy * ku, 0, 0)
  return r.x, r.y
end

function PanelEditor:_alt_down()
  return love.keyboard.isDown("lalt", "ralt")
end

function PanelEditor:_snap_mouse_button(mx, my)
  local dx, dy = self:screen_to_button_design(mx, my)
  return snap(dx, self.snap), snap(dy, self.snap)
end

function PanelEditor:_measure_delta(m)
  if not m then return 0, 0, 0 end
  local ddx = m.bx - m.ax
  local ddy = m.by - m.ay
  return ddx, ddy, math.sqrt(ddx * ddx + ddy * ddy)
end

function PanelEditor:_selected_rect()
  local sel = self.selected
  if not sel then return nil end
  if sel.kind == "lcd" then return self:_lcd_screen() end
  if sel.kind == "panel" then return self:_panel_screen() end
  if sel.kind == "button" then
    return self:_button_screen(self:_primary_button_index())
  end
  return nil
end

function PanelEditor:_selected_geom()
  local sel = self.selected
  if not sel then return nil end
  if sel.kind == "lcd" then return self.doc.lcd end
  if sel.kind == "panel" then return self.doc.panel end
  if sel.kind == "button" then
    return self.doc.buttons[self:_primary_button_index()]
  end
  return nil
end

function PanelEditor:_hit_button(mx, my)
  for i = #self.doc.buttons, 1, -1 do
    local r = self:_button_screen(i)
    if r and hit_rect(r, mx, my) then
      return i
    end
  end
  return nil
end

function PanelEditor:_handles(r)
  local hs = HANDLE
  local cx = r.x + r.w * 0.5
  local cy = r.y + r.h * 0.5
  return {
    nw = { x = r.x - hs * 0.5, y = r.y - hs * 0.5, w = hs, h = hs },
    n = { x = cx - hs * 0.5, y = r.y - hs * 0.5, w = hs, h = hs },
    ne = { x = r.x + r.w - hs * 0.5, y = r.y - hs * 0.5, w = hs, h = hs },
    e = { x = r.x + r.w - hs * 0.5, y = cy - hs * 0.5, w = hs, h = hs },
    se = { x = r.x + r.w - hs * 0.5, y = r.y + r.h - hs * 0.5, w = hs, h = hs },
    s = { x = cx - hs * 0.5, y = r.y + r.h - hs * 0.5, w = hs, h = hs },
    sw = { x = r.x - hs * 0.5, y = r.y + r.h - hs * 0.5, w = hs, h = hs },
    w = { x = r.x - hs * 0.5, y = cy - hs * 0.5, w = hs, h = hs },
  }
end

function PanelEditor:_hit_handle(mx, my)
  local r = self:_selected_rect()
  if not r then return nil end
  for name, hr in pairs(self:_handles(r)) do
    if hit_rect(hr, mx, my) then return name end
  end
  return nil
end

function PanelEditor:_palette_item_rect(i)
  local pr = self.palette_rect
  local row_h = 22
  local y0 = pr.y + 36 - (self.palette_scroll or 0)
  return {
    x = pr.x + 8,
    y = y0 + (i - 1) * row_h,
    w = pr.w - 16,
    h = row_h - 2,
  }
end

function PanelEditor:_hit_palette(mx, my)
  if not hit_rect(self.palette_rect, mx, my) then return nil end
  for i = 1, #self.palette do
    local r = self:_palette_item_rect(i)
    if hit_rect(r, mx, my) then return i end
  end
  return nil
end

local SYMBOL_TARGETS = {
  { id = "second", label = "2nd" },
  { id = "shift", label = "◆/shift" },
  { id = "alpha", label = "α" },
  { id = "fkey", label = "F" },
  { id = "label", label = "face" },
  { id = "face_glyph", label = "glyph" },
}

function PanelEditor:_symbol_target_rects()
  local sr = self.symbol_rect
  if not sr then return {} end
  local out = {}
  local x = sr.x + 6
  local y = sr.y + 22
  local gap = 3
  for _, t in ipairs(SYMBOL_TARGETS) do
    local w = 28
    if t.id == "second" then w = 30
    elseif t.id == "shift" then w = 46
    elseif t.id == "face_glyph" then w = 40
    elseif t.id == "label" then w = 34
    end
    if x + w > sr.x + sr.w - 6 then
      x = sr.x + 6
      y = y + 18
    end
    out[#out + 1] = { id = t.id, label = t.label, x = x, y = y, w = w, h = 16 }
    x = x + w + gap
  end
  return out
end

function PanelEditor:_symbol_item_rect(i)
  local sr = self.symbol_rect
  local row_h = 20
  local header = 62
  local y0 = sr.y + header - (self.symbol_scroll or 0)
  return {
    x = sr.x + 8,
    y = y0 + (i - 1) * row_h,
    w = sr.w - 16,
    h = row_h - 2,
  }
end

function PanelEditor:_hit_symbol(mx, my)
  local sr = self.symbol_rect
  if not sr or not hit_rect(sr, mx, my) then return nil end
  for _, t in ipairs(self:_symbol_target_rects()) do
    if hit_rect(t, mx, my) then
      return { kind = "target", id = t.id }
    end
  end
  local list = self:_symbol_list()
  for i, sym in ipairs(list) do
    local r = self:_symbol_item_rect(i)
    if hit_rect(r, mx, my) and r.y + r.h > sr.y + 58 and r.y < sr.y + sr.h then
      return { kind = "symbol", token = sym.token or sym.id }
    end
  end
  return nil
end

function PanelEditor:_grow_scene()
  local d = self.doc
  local max_x = math.max(d.lcd.x + d.lcd.w, d.panel.x + d.panel.w)
  local max_y = math.max(d.lcd.y + d.lcd.h, d.panel.y + d.panel.h)
  d.scene.w = math.max(d.scene.w, max_x)
  d.scene.h = math.max(d.scene.h, max_y)
end

function PanelEditor:commit_edit()
  if self.inspector then
    self.inspector:commit()
  end
end

function PanelEditor:save()
  self:commit_edit()
  self:_grow_scene()
  local path = self:_path(self.machine)
  local ok, err = Format.save(path, self.doc)
  if ok then
    self.seeds[self.machine] = copy_doc(self.doc)
    self:set_status("Saved " .. path)
    if self.on_saved then self.on_saved(self.machine, path) end
  else
    self:set_status("Save failed: " .. tostring(err))
  end
end

function PanelEditor:reload()
  self:commit_edit()
  local path = self:_path(self.machine)
  local doc, err = Format.load(path)
  if not doc then
    self:set_status("Reload failed: " .. tostring(err))
    return
  end
  self:push_undo()
  self.doc = doc
  self.docs[self.machine] = doc
  self:_select(nil)
  self._preview_dirty = true
  self:_rebuild_palette()
  self:_layout_canvas()
  self:set_status("Reloaded " .. path)
end

function PanelEditor:reset_seed()
  self:commit_edit()
  self:push_undo()
  self.doc = copy_doc(self.seeds[self.machine])
  self.docs[self.machine] = self.doc
  self:_select(nil)
  self._preview_dirty = true
  self:_rebuild_palette()
  self:_layout_canvas()
  self:set_status("Reset to last loaded/saved layout")
end

function PanelEditor:delete_selected()
  local indices = self:_button_indices()
  if #indices == 0 then
    self:set_status("Only buttons/labels can be deleted (LCD/panel are fixed parts)")
    return
  end
  self:push_undo()
  table.sort(indices, function(a, b) return a > b end)
  for _, i in ipairs(indices) do
    table.remove(self.doc.buttons, i)
  end
  self:_select(nil)
  self._preview_dirty = true
  self:_rebuild_palette()
  self:set_status(#indices == 1 and "Deleted button" or ("Deleted " .. #indices .. " buttons"))
end

function PanelEditor:add_label()
  self:push_undo()
  local b = Format.normalize_button({
    id = "label_" .. tostring(#self.doc.buttons + 1),
    label = "Label",
    style = "fn",
    x = 0.5, y = 0.5, w = 2, h = 0.6,
    kind = "label",
    radius = 0,
    label_size = self.doc.theme.label_size,
    legend_size = self.doc.theme.legend_size,
  }, self.doc.theme)
  self.doc.buttons[#self.doc.buttons + 1] = b
  self._preview_dirty = true
  self:_select_button(#self.doc.buttons, "replace")
  self:set_status("Added decorative label")
end

function PanelEditor:select_all_buttons()
  local indices = {}
  for i = 1, #self.doc.buttons do
    indices[#indices + 1] = i
  end
  if #indices == 0 then
    self:set_status("No buttons to select")
    return
  end
  self:commit_edit()
  self.selected = {
    kind = "button",
    indices = indices,
    primary = indices[#indices],
  }
  self:_rebuild_inspector()
  self:set_status(string.format("Selected %d buttons (Shift/Ctrl+click to adjust)", #indices))
end

function PanelEditor:place_key(id, dx, dy)
  self:push_undo()
  local cat = Catalog.for_machine(self.machine)
  local b = Format.normalize_button({
    id = id,
    label = Catalog.default_label(self.machine, id),
    style = (cat.styles and cat.styles[1]) or "fn",
    x = snap(dx, self.snap),
    y = snap(dy, self.snap),
    w = 1, h = 1,
    kind = "key",
    radius = 0.12,
    label_size = self.doc.theme.label_size,
    legend_size = self.doc.theme.legend_size,
  }, self.doc.theme)
  if id == "2nd" or id == "2nd2" then b.style = "second"
  elseif id == "alpha" then b.style = "alpha"
  elseif id == "diamond" then b.style = "diamond"
  elseif id == "shift" then b.style = "shift"
  elseif id == "enter" or id == "enter2" or id == "enter3" then b.style = "enter"
  elseif id == "on" then b.style = "on"
  elseif id:match("^f%d") then b.style = (self.machine == "ti83plus" or self.machine == "ti84plus") and "graph" or "fkey"
  elseif id:match("^%d$") then b.style = "num"
  end
  self.doc.buttons[#self.doc.buttons + 1] = b
  self._preview_dirty = true
  self:_select_button(#self.doc.buttons, "replace")
  self:_rebuild_palette()
end

function PanelEditor:update(dt)
  if self.status_t > 0 then
    self.status_t = self.status_t - dt
  end
  -- Keep finished measure overlay while Alt is held; clear when released.
  if self.measure and not self.measure.active and not self:_alt_down() then
    self.measure = nil
  end
end

function PanelEditor:_begin_geom_drag(mode, handle, mx, my)
  local g = self:_selected_geom()
  if not g then return end
  self:push_undo()
  local sx, sy = self:screen_to_scene(mx, my)
  if self.selected.kind == "button" then
    local dx, dy = self:screen_to_button_design(mx, my)
    local indices = {}
    for _, i in ipairs(self:_button_indices()) do indices[#indices + 1] = i end
    local starts = {}
    for _, i in ipairs(indices) do
      local b = self.doc.buttons[i]
      if b then starts[i] = { x = b.x, y = b.y, w = b.w, h = b.h } end
    end
    local primary = self:_primary_button_index()
    self.drag = {
      mode = mode,
      handle = handle,
      kind = "button",
      indices = indices,
      primary = primary,
      starts = starts,
      origin_mouse = { x = dx, y = dy },
      start = { x = g.x, y = g.y, w = g.w, h = g.h },
      offx = dx - g.x,
      offy = dy - g.y,
    }
  else
    self.drag = {
      mode = mode,
      handle = handle,
      kind = self.selected.kind,
      start = { x = g.x, y = g.y, w = g.w, h = g.h },
      offx = sx - g.x,
      offy = sy - g.y,
    }
  end
end

function PanelEditor:mousepressed(mx, my, button)
  if self.inspector:mousepressed(mx, my, button) then
    return true
  end
  if button ~= 1 then return true end
  self:commit_edit()
  self:_sync_preview()

  for _, b in ipairs(self.tool_hits or {}) do
    if hit_rect(b, mx, my) then
      self:_toolbar(b.id)
      return true
    end
  end

  local pi = self:_hit_palette(mx, my)
  if pi then
    self.palette_drag = { id = self.palette[pi], ox = mx, oy = my }
    return true
  end

  local sym = self:_hit_symbol(mx, my)
  if sym then
    if sym.kind == "target" then
      self.symbol_target = sym.id
      self:set_status("Symbols insert into " .. sym.id)
    else
      self:insert_symbol(sym.token)
    end
    return true
  end

  if hit_rect(self.scene_rect, mx, my) or hit_rect(self.canvas_outer, mx, my) then
    -- Alt+drag measures snap-grid distance (takes priority over edit).
    if self:_alt_down() then
      local sx, sy = self:_snap_mouse_button(mx, my)
      self.measure = { ax = sx, ay = sy, bx = sx, by = sy, active = true }
      return true
    end
    local handle = self:_hit_handle(mx, my)
    if handle then
      self:_begin_geom_drag("resize", handle, mx, my)
      return true
    end
    local shift = love.keyboard.isDown("lshift", "rshift")
    local ctrl = love.keyboard.isDown("lctrl", "rctrl")
    local i = self:_hit_button(mx, my)
    if i then
      local already = self:_is_button_selected(i)
      if ctrl then
        self:_select_button(i, "toggle")
      elseif shift then
        self:_select_button(i, "add")
      elseif not already then
        self:_select_button(i, "replace")
      else
        -- Keep multi-selection; make clicked button primary for handles.
        self.selected.primary = i
      end
      if self.selected and self.selected.kind == "button" then
        self:_begin_geom_drag("move", nil, mx, my)
      end
      return true
    end
    -- Shift+drag on empty canvas draws a button selection box.
    if shift then
      self.box_select = {
        x0 = mx, y0 = my, x1 = mx, y1 = my,
        mode = ctrl and "add" or "replace",
      }
      return true
    end
    -- LCD is drawn above keys; prefer it when the screen overlaps the panel.
    if hit_rect(self:_lcd_screen(), mx, my) then
      self:_select({ kind = "lcd" })
      self:_begin_geom_drag("move", nil, mx, my)
      return true
    end
    if hit_rect(self:_panel_screen(), mx, my) then
      self:_select({ kind = "panel" })
      self:_begin_geom_drag("move", nil, mx, my)
      return true
    end
    self:_select(nil)
    return true
  end
  return true
end

function PanelEditor:_toolbar(id)
  if id:sub(1, 5) == "mach_" then
    self:set_machine(id:sub(6))
    self:_layout_canvas()
    self:_layout_toolbar_hits()
  elseif id == "save" then
    self:save()
  elseif id == "reload" then
    self:reload()
  elseif id == "reset" then
    self:reset_seed()
  elseif id == "undo" then
    self:do_undo()
  elseif id == "redo" then
    self:do_redo()
  elseif id == "grid" then
    self.show_grid = not self.show_grid
    self:_layout_toolbar_hits()
  elseif id == "snap" then
    local steps = { 0, 0.05, 0.1, 0.25, 0.5, 1 }
    local idx = 1
    for i, s in ipairs(steps) do
      if math.abs(s - self.snap) < 1e-6 then idx = i break end
    end
    self.snap = steps[(idx % #steps) + 1]
    self:_layout_toolbar_hits()
  elseif id == "sel_lcd" then
    self:_select({ kind = "lcd" })
    self:set_status("LCD selected - drag/resize; use inspector for color/radius")
  elseif id == "sel_panel" then
    self:_select({ kind = "panel" })
    self:set_status("Panel selected - drag/resize; use inspector for plate colors")
  elseif id == "add_label" then
    self:add_label()
  elseif id == "delete" then
    self:delete_selected()
  elseif id == "close" then
    self:commit_edit()
    if self.on_close then self.on_close() end
  end
end

function PanelEditor:_apply_drag(mx, my)
  if not self.drag then return end
  local d = self.drag
  if d.kind == "button" then
    local dx, dy = self:screen_to_button_design(mx, my)
    if d.mode == "move" then
      local ox = d.origin_mouse and d.origin_mouse.x or dx
      local oy = d.origin_mouse and d.origin_mouse.y or dy
      local ddx, ddy = dx - ox, dy - oy
      for _, i in ipairs(d.indices or {}) do
        local b = self.doc.buttons[i]
        local s = d.starts and d.starts[i]
        if b and s then
          b.x = snap(s.x + ddx, self.snap)
          b.y = snap(s.y + ddy, self.snap)
        end
      end
    else
      -- Resize applies to the primary button only.
      local b = self.doc.buttons[d.primary]
      if not b then return end
      local s, h = d.start, d.handle
      local x1, y1, x2, y2 = s.x, s.y, s.x + s.w, s.y + s.h
      if h:find("w") then x1 = snap(dx, self.snap) end
      if h:find("e") then x2 = snap(dx, self.snap) end
      if h:find("n") then y1 = snap(dy, self.snap) end
      if h:find("s") then y2 = snap(dy, self.snap) end
      if x2 - x1 < MIN_SIZE then
        if h:find("w") then x1 = x2 - MIN_SIZE else x2 = x1 + MIN_SIZE end
      end
      if y2 - y1 < MIN_SIZE then
        if h:find("n") then y1 = y2 - MIN_SIZE else y2 = y1 + MIN_SIZE end
      end
      b.x, b.y, b.w, b.h = x1, y1, x2 - x1, y2 - y1
    end
    self._preview_dirty = true
    return
  end

  local g = (d.kind == "lcd") and self.doc.lcd or self.doc.panel
  local sx, sy = self:screen_to_scene(mx, my)
  if d.mode == "move" then
    g.x = snap(sx - d.offx, self.snap)
    g.y = snap(sy - d.offy, self.snap)
  else
    local s, h = d.start, d.handle
    local x1, y1, x2, y2 = s.x, s.y, s.x + s.w, s.y + s.h
    if h:find("w") then x1 = snap(sx, self.snap) end
    if h:find("e") then x2 = snap(sx, self.snap) end
    if h:find("n") then y1 = snap(sy, self.snap) end
    if h:find("s") then y2 = snap(sy, self.snap) end
    if x2 - x1 < MIN_SIZE then
      if h:find("w") then x1 = x2 - MIN_SIZE else x2 = x1 + MIN_SIZE end
    end
    if y2 - y1 < MIN_SIZE then
      if h:find("n") then y1 = y2 - MIN_SIZE else y2 = y1 + MIN_SIZE end
    end
    g.x, g.y, g.w, g.h = x1, y1, x2 - x1, y2 - y1
    if d.kind == "lcd" then
      -- Keep WIDTH×HEIGHT hardware aspect so the live LCD never letterboxes.
      local aspect = Format.lcd_aspect(self.machine)
      local width_driven = h:find("e") or h:find("w") or not (h:find("n") or h:find("s"))
      if width_driven then
        Format.snap_lcd_aspect(g, self.machine)
        if h:find("n") then
          g.y = y2 - g.h
        else
          g.y = y1
        end
        if h:find("w") then
          g.x = x2 - g.w
        else
          g.x = x1
        end
      else
        g.h = math.max(MIN_SIZE, g.h)
        g.w = g.h / aspect
        if g.w < MIN_SIZE then
          g.w = MIN_SIZE
          Format.snap_lcd_aspect(g, self.machine)
        end
        if h:find("n") then
          g.y = y2 - g.h
        else
          g.y = y1
        end
        if h:find("w") then
          g.x = x2 - g.w
        else
          g.x = x1
        end
      end
    end
  end
  if d.kind == "panel" then
    self.doc.face_aspect = self.doc.panel.h / math.max(0.01, self.doc.panel.w)
    self.doc.plate.radius = self.doc.panel.radius
    self._preview_dirty = true
  end
  self:_grow_scene()
  self:_layout_canvas()
end

function PanelEditor:mousemoved(mx, my, dx, dy)
  self.cursor_x, self.cursor_y = mx, my
  if self.measure and self.measure.active then
    local sx, sy = self:_snap_mouse_button(mx, my)
    self.measure.bx, self.measure.by = sx, sy
    return true
  end
  if self.inspector:mousemoved(mx, my, dx, dy) then
    return true
  end
  if self.palette_drag then
    self.palette_drag.mx = mx
    self.palette_drag.my = my
    return true
  end
  if self.box_select then
    self.box_select.x1 = mx
    self.box_select.y1 = my
    return true
  end
  if not self.drag then return false end
  self:_apply_drag(mx, my)
  return true
end

function PanelEditor:mousereleased(mx, my, button)
  if self.inspector:mousereleased(mx, my, button) then
    return true
  end
  if button ~= 1 then return true end
  if self.palette_drag then
    local id = self.palette_drag.id
    if hit_rect(self:_panel_screen(), mx, my) then
      local dx, dy = self:screen_to_button_design(mx, my)
      self:place_key(id, dx - 0.5, dy - 0.5)
      self:set_status("Placed " .. id)
    else
      self:set_status("Drop keys onto the keypad panel")
    end
    self.palette_drag = nil
    return true
  end
  if self.box_select then
    local b = self.box_select
    b.x1, b.y1 = mx, my
    local dragged = math.abs(b.x1 - b.x0) >= 3 or math.abs(b.y1 - b.y0) >= 3
    if dragged then
      self:_select_buttons_in_rect(b.x0, b.y0, b.x1, b.y1, b.mode)
    end
    self.box_select = nil
    return true
  end
  if self.measure and self.measure.active then
    local sx, sy = self:_snap_mouse_button(mx, my)
    self.measure.bx, self.measure.by = sx, sy
    self.measure.active = false
    local ddx, ddy, dist = self:_measure_delta(self.measure)
    self:set_status(string.format(
      "Measure  Δx=%.2f  Δy=%.2f  dist=%.2f  (from %.2f,%.2f -> %.2f,%.2f)",
      ddx, ddy, dist, self.measure.ax, self.measure.ay, self.measure.bx, self.measure.by))
    if not self:_alt_down() then
      self.measure = nil
    end
    return true
  end
  self.drag = nil
  return true
end

function PanelEditor:_symbol_list()
  if self.symbol_target == "face_glyph" then
    local list = {}
    for _, g in ipairs(Catalog.FACE_GLYPHS or {}) do
      if g.id ~= "auto" and g.id ~= "text" then
        list[#list + 1] = { token = g.id, label = g.label }
      end
    end
    return list
  end
  return Catalog.LEGEND_SYMBOLS or {}
end

function PanelEditor:wheelmoved(wx, wy)
  local mx, my = love.mouse.getPosition()
  if self.inspector:wheelmoved(wx, wy, mx, my) then
    return true
  end
  if hit_rect(self.palette_rect, mx, my) then
    self.palette_scroll = clamp((self.palette_scroll or 0) - wy * 22, 0, math.max(0, #self.palette * 22 - 100))
    return true
  end
  if self.symbol_rect and hit_rect(self.symbol_rect, mx, my) then
    local n = #self:_symbol_list()
    self.symbol_scroll = clamp((self.symbol_scroll or 0) - wy * 20, 0, math.max(0, n * 20 - 80))
    return true
  end
  return false
end

function PanelEditor:textinput(t)
  if self.inspector:textinput(t) then
    return true
  end
  return false
end

function PanelEditor:keypressed(key)
  if self.inspector:keypressed(key) then
    return true
  end

  local ctrl = love.keyboard.isDown("lctrl", "rctrl")
  if ctrl and key == "s" then
    self:save()
    return true
  elseif ctrl and key == "z" then
    self:do_undo()
    return true
  elseif ctrl and key == "y" then
    self:do_redo()
    return true
  elseif ctrl and key == "a" then
    self:select_all_buttons()
    return true
  elseif key == "delete" or key == "backspace" then
    self:delete_selected()
    return true
  elseif key == "escape" then
    if self.selected then
      self:_select(nil)
      return true
    end
    if self.on_close then self.on_close() end
    return true
  elseif key == "tab" then
    local idx = 1
    for i, mid in ipairs(MACHINES) do
      if mid == self.machine then idx = i break end
    end
    self:set_machine(MACHINES[(idx % #MACHINES) + 1])
    self:_layout_canvas()
    self:_layout_toolbar_hits()
    return true
  elseif key == "l" then
    self:_select({ kind = "lcd" })
    return true
  elseif key == "p" then
    self:_select({ kind = "panel" })
    return true
  end
  return false
end

local function set_col(c, a)
  love.graphics.setColor(c[1], c[2], c[3], a or 1)
end

function PanelEditor:_draw_snap_marker(dx, dy, filled)
  local sx, sy = self:button_design_to_screen(dx, dy)
  local s = 5
  if filled then
    set_col(UI.accent, 0.35)
    love.graphics.rectangle("fill", sx - s, sy - s, s * 2, s * 2)
  end
  set_col(UI.accent, 0.95)
  love.graphics.setLineWidth(1.5)
  love.graphics.rectangle("line", sx - s + 0.5, sy - s + 0.5, s * 2 - 1, s * 2 - 1)
  love.graphics.setLineWidth(1)
  return sx, sy
end

function PanelEditor:_style_color(style)
  local styles = self.doc.theme.styles or {}
  return styles[style] or { 0.35, 0.35, 0.38 }
end

function PanelEditor:_draw_selection(r, col)
  if not r then return end
  set_col(col or UI.sel)
  love.graphics.setLineWidth(2)
  love.graphics.rectangle("line", r.x - 1, r.y - 1, r.w + 2, r.h + 2)
  love.graphics.setLineWidth(1)
  for _, hr in pairs(self:_handles(r)) do
    love.graphics.rectangle("fill", hr.x, hr.y, hr.w, hr.h)
  end
end

function PanelEditor:_font(px)
  px = math.max(6, math.floor((tonumber(px) or 12) + 0.5))
  self._font_cache = self._font_cache or {}
  local cached = self._font_cache[px]
  if cached then return cached end
  local ok, font = pcall(love.graphics.newFont, px)
  if ok and font then
    font:setFilter("linear", "linear")
    self._font_cache[px] = font
    return font
  end
  return love.graphics.getFont()
end

function PanelEditor:_draw_symbol_panel()
  local sr = self.symbol_rect
  if not sr then return end
  set_col({ 0.14, 0.15, 0.17 })
  love.graphics.rectangle("fill", sr.x, sr.y, sr.w, sr.h)
  set_col(UI.border)
  love.graphics.line(sr.x, sr.y, sr.x + sr.w, sr.y)
  set_col(UI.text)
  love.graphics.print("Symbols -> " .. (self.symbol_target or "second"), sr.x + 8, sr.y + 6)
  for _, t in ipairs(self:_symbol_target_rects()) do
    if t.id == self.symbol_target then
      set_col(UI.accent)
    else
      set_col({ 0.22, 0.24, 0.27 })
    end
    love.graphics.rectangle("fill", t.x, t.y, t.w, t.h, 3, 3)
    set_col(UI.text)
    love.graphics.print(t.label, t.x + 3, t.y + 2)
  end
  love.graphics.setScissor(sr.x, sr.y + 58, sr.w, sr.h - 62)
  for i, sym in ipairs(self:_symbol_list()) do
    local r = self:_symbol_item_rect(i)
    set_col({ 0.20, 0.22, 0.25 })
    love.graphics.rectangle("fill", r.x, r.y, r.w, r.h, 3, 3)
    set_col(UI.text)
    love.graphics.print(sym.label or sym.token, r.x + 6, r.y + 2)
  end
  love.graphics.setScissor()
end

function PanelEditor:draw()
  local ww, wh = self.ww, self.wh
  self:_sync_preview()

  set_col(UI.bg)
  love.graphics.rectangle("fill", 0, 0, ww, wh)

  set_col(UI.panel)
  love.graphics.rectangle("fill", 0, 0, ww, self.toolbar.h)
  for _, b in ipairs(self.tool_hits or {}) do
    local on = b.id == ("mach_" .. self.machine)
      or (b.id == "sel_lcd" and self.selected and self.selected.kind == "lcd")
      or (b.id == "sel_panel" and self.selected and self.selected.kind == "panel")
    if on then
      set_col(UI.accent)
    elseif b.id == "close" or b.id == "delete" then
      set_col(UI.danger)
    else
      set_col({ 0.22, 0.24, 0.27 })
    end
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
    set_col(UI.text)
    local font = love.graphics.getFont()
    local tw = font:getWidth(b.label)
    love.graphics.print(b.label, b.x + (b.w - tw) * 0.5, b.y + 6)
  end

  set_col(UI.panel)
  love.graphics.rectangle("fill", self.palette_rect.x, self.palette_rect.y, self.palette_rect.w, self.palette_rect.h)
  set_col(UI.text)
  love.graphics.print("Available keys", self.palette_rect.x + 8, self.palette_rect.y + 10)
  set_col(UI.muted)
  love.graphics.print("drop on panel", self.palette_rect.x + 8, self.palette_rect.y + 24)
  love.graphics.setScissor(self.palette_rect.x, self.palette_rect.y + 34, self.palette_rect.w, self.palette_rect.h - 40)
  for i, id in ipairs(self.palette) do
    local r = self:_palette_item_rect(i)
    set_col({ 0.20, 0.22, 0.25 })
    love.graphics.rectangle("fill", r.x, r.y, r.w, r.h, 3, 3)
    set_col(UI.text)
    love.graphics.print(id, r.x + 6, r.y + 3)
  end
  love.graphics.setScissor()
  self:_draw_symbol_panel()

  set_col({ 0.10, 0.11, 0.12 })
  love.graphics.rectangle("fill", self.canvas_outer.x, self.canvas_outer.y, self.canvas_outer.w, self.canvas_outer.h)

  -- scene bounds
  local s = self.scene_rect
  set_col({ 0.14, 0.15, 0.16 })
  love.graphics.rectangle("fill", s.x, s.y, s.w, s.h)
  set_col(UI.border)
  love.graphics.rectangle("line", s.x, s.y, s.w, s.h)

  -- Live keypad first; LCD draws on top (TI-92 places the screen between keys).
  local pr = self:_panel_screen()
  if self._preview_kp then
    self._preview_kp:draw()
  end

  if self.show_grid and pr then
    set_col(UI.grid)
    local cols = self.doc.design_cols
    local rows = self.doc.design_rows
    local cw = self.cell_w or (pr.w / math.max(0.01, cols))
    local ch = self.cell_h or cw
    local grid_w = cols * cw
    local grid_h = rows * ch
    for c = 0, math.ceil(cols) do
      local x = pr.x + c * cw
      love.graphics.line(x, pr.y, x, pr.y + grid_h)
    end
    for r = 0, math.ceil(rows) do
      local y = pr.y + r * ch
      love.graphics.line(pr.x, y, pr.x + grid_w, y)
    end
  end

  -- LCD glass fills its rect at hardware aspect (bezel drawn outside).
  local lr = self:_lcd_screen()
  local L = self.doc.lcd
  local lrad = math.max(0, (L.radius or 0) * self.unit)
  local pad = math.max(2, self.unit * 0.1)
  set_col(L.color)
  love.graphics.rectangle("fill", lr.x - pad, lr.y - pad, lr.w + pad * 2, lr.h + pad * 2, lrad, lrad)
  set_col(L.glass or L.color)
  love.graphics.rectangle("fill", lr.x, lr.y, lr.w, lr.h,
    math.max(0, lrad - pad * 0.5), math.max(0, lrad - pad * 0.5))
  set_col(UI.muted)
  love.graphics.print("LCD", lr.x + 6, lr.y + 4)

  if self.selected then
    if self.selected.kind == "lcd" then
      self:_draw_selection(lr, UI.lcd_sel)
    elseif self.selected.kind == "panel" then
      self:_draw_selection(pr, UI.panel_sel)
    elseif self.selected.kind == "button" then
      local primary = self:_primary_button_index()
      for _, i in ipairs(self:_button_indices()) do
        local r = self:_button_screen(i)
        if i == primary then
          self:_draw_selection(r, UI.sel)
        elseif r then
          set_col(UI.sel, 0.85)
          love.graphics.setLineWidth(1.5)
          love.graphics.rectangle("line", r.x - 1, r.y - 1, r.w + 2, r.h + 2)
          love.graphics.setLineWidth(1)
        end
      end
    end
  end

  if self.box_select then
    local b = self.box_select
    local x, y = math.min(b.x0, b.x1), math.min(b.y0, b.y1)
    local w, h = math.abs(b.x1 - b.x0), math.abs(b.y1 - b.y0)
    set_col(UI.accent, 0.18)
    love.graphics.rectangle("fill", x, y, w, h)
    set_col(UI.accent, 0.95)
    love.graphics.setLineWidth(1.5)
    love.graphics.rectangle("line", x + 0.5, y + 0.5, math.max(0, w - 1), math.max(0, h - 1))
    love.graphics.setLineWidth(1)
  end

  local alt = self:_alt_down()
  if self.measure then
    local m = self.measure
    local ax, ay = self:_draw_snap_marker(m.ax, m.ay, true)
    local bx, by = self:_draw_snap_marker(m.bx, m.by, true)
    set_col(UI.accent, 0.9)
    love.graphics.setLineWidth(1.5)
    love.graphics.line(ax, ay, bx, by)
    love.graphics.setLineWidth(1)
    local ddx, ddy, dist = self:_measure_delta(m)
    local label = string.format("Δx %.2f  Δy %.2f  d %.2f", ddx, ddy, dist)
    local font = self:_font(12)
    love.graphics.setFont(font)
    local tw = font:getWidth(label)
    local lx = (ax + bx) * 0.5 - tw * 0.5
    local ly = (ay + by) * 0.5 - 18
    set_col(UI.panel, 0.85)
    love.graphics.rectangle("fill", lx - 4, ly - 2, tw + 8, 16, 3, 3)
    set_col(UI.text)
    love.graphics.print(label, lx, ly)
  elseif alt and self.scene_rect then
    local sx, sy = self:_snap_mouse_button(self.cursor_x, self.cursor_y)
    self:_draw_snap_marker(sx, sy, true)
    local font = self:_font(11)
    love.graphics.setFont(font)
    local label = string.format("%.2f, %.2f", sx, sy)
    local px, py = self:button_design_to_screen(sx, sy)
    set_col(UI.panel, 0.85)
    love.graphics.rectangle("fill", px + 8, py - 18, font:getWidth(label) + 8, 15, 3, 3)
    set_col(UI.muted)
    love.graphics.print(label, px + 12, py - 16)
  end

  if self.palette_drag and self.palette_drag.mx then
    set_col(UI.accent, 0.85)
    love.graphics.rectangle("fill", self.palette_drag.mx - 30, self.palette_drag.my - 12, 60, 24, 4, 4)
    set_col(UI.text)
    love.graphics.print(self.palette_drag.id, self.palette_drag.mx - 26, self.palette_drag.my - 8)
  end

  self.inspector:draw()

  set_col(UI.panel)
  love.graphics.rectangle("fill", 0, self.status_bar.y, ww, self.status_bar.h)
  set_col(UI.muted)
  local path = self:_path(self.machine)
  local nsel = #self:_button_indices()
  local msg = string.format(
    "%s  |  live preview  |  %d buttons%s  |  Alt measure  Shift-drag box  Shift/Ctrl+click  Ctrl+A all  Ctrl+S save",
    path, #self.doc.buttons, nsel > 0 and ("  |  " .. nsel .. " selected") or "")
  if self.status_t > 0 and self.status ~= "" then
    msg = self.status .. "   -   " .. msg
  end
  love.graphics.print(msg, 10, self.status_bar.y + 6)
end

return PanelEditor
