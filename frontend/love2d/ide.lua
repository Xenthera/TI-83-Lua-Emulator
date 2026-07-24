-- Mini IDE: disk-backed projects (*.tc + project.tiproj), ASM, stdlib, build/play.

local Editor = require("editor")
local BuildSvc = require("buildsvc")
local Compendium = require("compendium")
local Dialog = require("dialog")
local Tiproj = require("lang.tiproj")
local MemMap = require("memmap")
local KeypadUI = require("keypad_ui")
local MachineMod = require("core.machine")
local Lcd = require("core.hw.lcd")

local Ide = {}
Ide.__index = Ide

local CALC_PAD = 8
local CALC_STATS_H = 20 -- footer for FPS/PC overlay
local CALC_GAP_RATIO = 0.04 -- gap between LCD and keys, relative to face width

--- Screen + keys share one aspect (normal width). Uniformly scale to fill height.
function Ide:_layout_calculator_face()
  local cr = self.calc_rect
  if not cr or cr.w < 40 or cr.h < 40 then
    self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
    return
  end

  local avail_w = cr.w - CALC_PAD * 2
  local avail_h = cr.h - CALC_PAD * 2 - CALC_STATS_H
  if avail_w < 48 or avail_h < 80 then
    self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
    return
  end

  -- Unit face at width=1: LCD + gap + keys (same width throughout).
  local screen_aspect = Lcd.HEIGHT / Lcd.WIDTH
  local key_aspect = KeypadUI.FACE_ASPECT
  local unit_h = screen_aspect + CALC_GAP_RATIO + key_aspect

  -- Scale so the stack fills available height; clamp if column is too narrow.
  local face_w = avail_h / unit_h
  if face_w > avail_w then
    face_w = avail_w
  end

  -- Prefer integer LCD pixel cells (crisp), still respecting bounds.
  local cell = math.max(3, math.floor(face_w / Lcd.WIDTH))
  local function stack_for(c)
    local w = c * Lcd.WIDTH
    local sh = c * Lcd.HEIGHT
    local gap = math.max(4, w * CALC_GAP_RATIO)
    local kh = w * key_aspect
    return w, sh, gap, kh, sh + gap + kh
  end
  local face_w, screen_h, gap, keys_h, total_h = stack_for(cell)
  while cell > 3 and (face_w > avail_w + 0.5 or total_h > avail_h + 0.5) do
    cell = cell - 1
    face_w, screen_h, gap, keys_h, total_h = stack_for(cell)
  end

  -- If there's leftover height after cell snap, scale the whole stack up uniformly.
  if total_h < avail_h - 1 and face_w < avail_w then
    local s = math.min(avail_h / total_h, avail_w / face_w)
    face_w = face_w * s
    screen_h = screen_h * s
    gap = gap * s
    keys_h = keys_h * s
    total_h = screen_h + gap + keys_h
  end

  local x0 = cr.x + math.floor((cr.w - face_w) / 2)
  local y0 = cr.y + CALC_PAD + math.floor((avail_h - total_h) / 2)

  self.lcd_rect = {
    x = x0,
    y = y0,
    w = face_w,
    h = screen_h,
  }
  self.keypad_ui:layout(x0, y0 + screen_h + gap, face_w, keys_h)
end

local STATUS_GAP = 12

local function ui_metrics()
  local font = love.graphics.getFont()
  local fh = font and math.ceil(font:getHeight()) or 14
  local toolbar_h = math.max(42, fh + 24)
  local tab_h = math.max(28, fh + 12)
  local file_tab_h = math.max(24, fh + 10)
  local console_footer = math.max(18, fh + 6)
  local console_h = math.max(110, fh * 6 + console_footer + 28)
  local btn_h = math.max(24, fh + 10)
  return {
    fh = fh,
    font = font,
    toolbar_h = toolbar_h,
    tab_h = tab_h,
    file_tab_h = file_tab_h,
    console_h = console_h,
    console_footer = console_footer,
    btn_h = btn_h,
    btn_y = math.floor((toolbar_h - btn_h) / 2),
  }
end

function Ide.new(root)
  local self = setmetatable({}, Ide)
  self.root = root
  self.tab = "tc" -- "tc" | "asm" | "docs"
  self.running = false
  self.status = "Ready"
  self.status_kind = "info"
  self.console = {}
  self.console_sel = nil -- { a = {r,c}, b = {r,c} } in display-line coords
  self.console_dragging = false
  self.console_view = nil -- layout cache for hit-testing
  self.buttons = {}
  self.tc_editor = Editor.new("tc")
  self.asm_editor = Editor.new("asm")
  self.docs = Compendium.new()
  self.memmap = MemMap.new()
  self.keypad_ui = KeypadUI.new()
  self.focus = "editor" -- editor | docs | lcd | console | mem | gate_hz
  self.project_dir = nil
  self.project = nil
  self.open_file = nil
  -- Run gate: when active, Play advances at gate_hz instructions/sec; else realtime 6 MHz.
  self.gate_active = false
  self.gate_hz = 20
  self.gate_hz_text = "20"
  self.gate_accum = 0
  self.cycle_accum = 0
  self.gate_check = { x = 0, y = 0, w = 0, h = 0 }
  self.gate_field = { x = 0, y = 0, w = 0, h = 0 }
  -- Last successful Build output (512KB flash image), for Export ROM.
  self.last_built_rom = nil
  self.last_built_name = nil
  self:_load_default_project()
  return self
end

function Ide:_sorted_files()
  local names = {}
  if not self.project then return names end
  for name, _ in pairs(self.project.files) do
    names[#names + 1] = name
  end
  table.sort(names)
  return names
end

function Ide:_sync_editor_to_project()
  if self.project and self.open_file then
    self.project.files[self.open_file] = self.tc_editor:get_text()
  end
end

--- Pull *.tc from disk (so external / AI edits apply), keep current editor buffer.
function Ide:_reload_disk_sources()
  if not self.project or not self.project.dir then return end
  local cur = self.open_file
  local cur_text = self.tc_editor:get_text()
  Tiproj.reload_from_dir(self.project, self.project.dir)
  if cur and cur_text and self.tc_editor.dirty then
    self.project.files[cur] = cur_text
  elseif cur and self.project.files[cur] then
    self.tc_editor:set_text(self.project.files[cur])
    self.tc_editor.dirty = false
  end
end

function Ide:_open_project_file(name, line, col)
  if not self.project or not self.project.files[name] then return false end
  self:_sync_editor_to_project()
  self.open_file = name
  self.tc_editor:set_text(self.project.files[name])
  self.tc_editor.dirty = false
  self.tab = "tc"
  self.focus = "editor"
  self.tc_editor.focused = true
  self.asm_editor.focused = false
  if line then
    self.tc_editor:goto_line(line, col or 1)
  end
  return true
end

--- Parse "file:line:col:" or "file:line:" from compiler/assembler errors.
function Ide:_parse_error_loc(err)
  local text = tostring(err or "")
  -- Prefer Tiny-C / project sources over Lua stack frames.
  local file, line, col = text:match("([%w%._%-%/]+%.tc):(%d+):(%d+)")
  if not file then
    file, line = text:match("([%w%._%-%/]+%.tc):(%d+)")
  end
  if not file then
    file, line, col = text:match("([%w%._%-%/]+%.asm):(%d+):(%d+)")
  end
  if not file then
    file, line = text:match("([%w%._%-%/]+%.asm):(%d+)")
  end
  if not file then
    return nil
  end
  return {
    file = file,
    line = tonumber(line),
    col = tonumber(col) or 1,
  }
end

function Ide:_goto_error(err)
  local loc = self:_parse_error_loc(err)
  if not loc then return false end
  local base = loc.file:match("([^/]+)$") or loc.file

  if base:match("%.asm$") then
    self.tab = "asm"
    self.focus = "editor"
    self.asm_editor.focused = true
    self.tc_editor.focused = false
    self.asm_editor:goto_line(loc.line, loc.col)
    return true
  end

  if self.project then
    if self.project.files[base] then
      return self:_open_project_file(base, loc.line, loc.col)
    end
    if self.project.files[loc.file] then
      return self:_open_project_file(loc.file, loc.line, loc.col)
    end
    for name in pairs(self.project.files) do
      if name == base or name:sub(-#base) == base or name:match("/" .. base .. "$") then
        return self:_open_project_file(name, loc.line, loc.col)
      end
    end
  end

  self.tab = "tc"
  self.focus = "editor"
  self.tc_editor.focused = true
  self.asm_editor.focused = false
  self.tc_editor:goto_line(loc.line, loc.col)
  return true
end

-- Love2D fonts require valid UTF-8; never pass torn multi-byte sequences.
local function sanitize_utf8(s)
  s = tostring(s or "")
  local out = {}
  local i, n = 1, #s
  while i <= n do
    local c = s:byte(i)
    if not c then
      break
    elseif c < 0x80 then
      out[#out + 1] = (c < 32 and c ~= 9) and "?" or string.char(c)
      i = i + 1
    elseif c >= 0xC2 and c <= 0xDF and i + 1 <= n then
      local c2 = s:byte(i + 1)
      if c2 and c2 >= 0x80 and c2 <= 0xBF then
        out[#out + 1] = s:sub(i, i + 1)
        i = i + 2
      else
        out[#out + 1] = "?"
        i = i + 1
      end
    elseif c >= 0xE0 and c <= 0xEF and i + 2 <= n then
      local c2, c3 = s:byte(i + 1, i + 2)
      if c2 and c3 and c2 >= 0x80 and c2 <= 0xBF and c3 >= 0x80 and c3 <= 0xBF then
        out[#out + 1] = s:sub(i, i + 2)
        i = i + 3
      else
        out[#out + 1] = "?"
        i = i + 1
      end
    elseif c >= 0xF0 and c <= 0xF4 and i + 3 <= n then
      local c2, c3, c4 = s:byte(i + 1, i + 3)
      if c2 and c3 and c4
          and c2 >= 0x80 and c2 <= 0xBF
          and c3 >= 0x80 and c3 <= 0xBF
          and c4 >= 0x80 and c4 <= 0xBF then
        out[#out + 1] = s:sub(i, i + 3)
        i = i + 4
      else
        out[#out + 1] = "?"
        i = i + 1
      end
    else
      out[#out + 1] = "?"
      i = i + 1
    end
  end
  return table.concat(out)
end

local function utf8_chars(s)
  local chars = {}
  for ch in s:gmatch("[%z\1-\127\194-\244][\128-\191]*") do
    chars[#chars + 1] = ch
  end
  return chars
end

local function wrap_text_lines(text, max_w, font)
  font = font or love.graphics.getFont()
  max_w = math.max(20, max_w or 100)
  local out = {}
  for paragraph in (sanitize_utf8(text) .. "\n"):gmatch("(.-)\n") do
    if paragraph == "" then
      out[#out + 1] = ""
    else
      local chars = utf8_chars(paragraph)
      local i, n = 1, #chars
      while i <= n do
        local chunk = ""
        while i <= n do
          local trial = chunk .. chars[i]
          if chunk ~= "" and font:getWidth(trial) > max_w then
            break
          end
          chunk = trial
          i = i + 1
          if font:getWidth(chunk) >= max_w then
            break
          end
        end
        if chunk == "" then
          chunk = chars[i] or "?"
          i = i + 1
        end
        out[#out + 1] = chunk
      end
    end
  end
  if #out == 0 then out[1] = "" end
  return out
end

local function cons_pos_le(r1, c1, r2, c2)
  return r1 < r2 or (r1 == r2 and c1 <= c2)
end

function Ide:_console_display(font, wrap_w)
  local display = {}
  for _, entry in ipairs(self.console) do
    local text, kind
    if type(entry) == "table" then
      text, kind = entry.text, entry.kind
    else
      text, kind = entry, "info"
    end
    local wrapped = wrap_text_lines(text, wrap_w, font)
    for _, wl in ipairs(wrapped) do
      display[#display + 1] = { text = wl, kind = kind }
    end
  end
  return display
end

function Ide:_console_refresh_view()
  local cr = self.console_rect
  if not cr then return nil end
  local m = self.ui or {}
  local font = m.font or love.graphics.getFont()
  local fh = m.fh or (font and font:getHeight()) or 14
  local CONSOLE_FOOTER_H = m.console_footer or 18
  local header_h = fh + 8
  local log_bottom = cr.y + cr.h - CONSOLE_FOOTER_H
  local line_h = math.max(16, fh + 2)
  local text_x = cr.x + 8
  local wrap_w = math.max(40, cr.w - 16)
  local display = self:_console_display(font, wrap_w)
  local max_lines = math.max(1, math.floor((log_bottom - (cr.y + header_h)) / line_h))
  local start = math.max(1, #display - max_lines + 1)
  self.console_view = {
    font = font,
    lines = display,
    text_x = text_x,
    top = cr.y + header_h,
    line_h = line_h,
    wrap_w = wrap_w,
    start = start,
    max_lines = max_lines,
    log_bottom = log_bottom,
    header_h = header_h,
  }
  return self.console_view
end

function Ide:_console_pos_at(mx, my)
  local v = self.console_view or self:_console_refresh_view()
  if not v or #v.lines == 0 then return nil end
  if my < v.top or my >= v.log_bottom then return nil end
  local row = v.start + math.floor((my - v.top) / v.line_h)
  if row < 1 then row = 1 end
  if row > #v.lines then row = #v.lines end
  local text = v.lines[row].text or ""
  local col = 1
  if mx <= v.text_x then
    col = 1
  else
    local font = v.font
    col = #text + 1
    for i = 1, #text do
      local w = font:getWidth(text:sub(1, i))
      if v.text_x + w >= mx then
        -- pick closer edge
        local prev = font:getWidth(text:sub(1, i - 1))
        if mx - (v.text_x + prev) < (v.text_x + w) - mx then
          col = i
        else
          col = i + 1
        end
        break
      end
    end
  end
  return { r = row, c = col }
end

function Ide:_console_sel_range()
  local s = self.console_sel
  if not s or not s.a or not s.b then return nil end
  local ar, ac, br, bc = s.a.r, s.a.c, s.b.r, s.b.c
  if not cons_pos_le(ar, ac, br, bc) then
    ar, ac, br, bc = br, bc, ar, ac
  end
  if ar == br and ac == bc then return nil end
  return ar, ac, br, bc
end

function Ide:_console_selected_text()
  local v = self.console_view or self:_console_refresh_view()
  if not v then return "" end
  local ar, ac, br, bc = self:_console_sel_range()
  if not ar then
    -- no selection: copy all console entries
    local parts = {}
    for _, entry in ipairs(self.console) do
      parts[#parts + 1] = type(entry) == "table" and entry.text or tostring(entry)
    end
    return table.concat(parts, "\n")
  end
  local lines = v.lines
  if ar == br then
    return (lines[ar].text or ""):sub(ac, bc - 1)
  end
  local parts = { (lines[ar].text or ""):sub(ac) }
  for r = ar + 1, br - 1 do
    parts[#parts + 1] = lines[r].text or ""
  end
  parts[#parts + 1] = (lines[br].text or ""):sub(1, bc - 1)
  return table.concat(parts, "\n")
end

function Ide:_console_copy()
  local text = self:_console_selected_text()
  if text and text ~= "" then
    love.system.setClipboardText(text)
    self.status = string.format("Copied %d chars", #text)
    self.status_kind = "info"
    return true
  end
  return false
end

function Ide:_console_select_all()
  local v = self.console_view or self:_console_refresh_view()
  if not v or #v.lines == 0 then return end
  local last = v.lines[#v.lines]
  self.console_sel = {
    a = { r = 1, c = 1 },
    b = { r = #v.lines, c = #(last.text or "") + 1 },
  }
end

function Ide:load_project(path)
  local doc, err = Tiproj.open(path)
  if not doc then
    self:log("Open fail: " .. tostring(err))
    return false
  end
  self.project = doc
  self.project_dir = doc.dir
  self.open_file = doc.entry
  self.tc_editor:set_text(doc.files[doc.entry] or "")
  self.tc_editor.dirty = false
  self.tab = "tc"
  self:log("Opened " .. (doc.dir or path) .. " (" .. doc.name .. ")")
  return true
end

function Ide:_ensure_demo_project()
  local dir = self.root .. "/projects/shapes"
  local main = io.open(dir .. "/main.tc", "r")
  if main then
    main:close()
    return dir
  end
  local doc = Tiproj.new({
    name = "shapes",
    entry = "main.tc",
    files = {
      ["main.tc"] = '#include <stdlib/gfx.tc>\n#include "banner.tc"\n\nvoid main() {\n  lcd_init();\n  lcd_clear();\n  draw_banner();\n  draw_rect(8, 20, 80, 36);\n  draw_line(10, 22, 86, 54);\n  fill_rect(40, 30, 16, 12);\n  poke(0xC001, 0xA5);\n  while (1) { halt(); }\n}\n',
      ["banner.tc"] = 'void draw_banner() {\n  draw_string(0, 0, "GFX DEMO");\n}\n',
    },
  })
  Tiproj.save_dir(dir, doc)
  return dir
end

function Ide:_load_default_project()
  local path = self:_ensure_demo_project()
  if not self:load_project(path) then
    local tc = '// Tiny-C\nvoid main() {\n  lcd_init();\n  lcd_clear();\n  draw_string(0, 0, "HI");\n  while (1) { halt(); }\n}\n'
    local dir = self.root .. "/projects/untitled"
    self.project = Tiproj.new({ name = "untitled", entry = "main.tc", files = { ["main.tc"] = tc } })
    Tiproj.save_dir(dir, self.project)
    self.project_dir = dir
    self.open_file = "main.tc"
    self.tc_editor:set_text(tc)
  end
  local asm_f = io.open(self.root .. "/asm/generated/hello.asm", "r")
  if asm_f then
    self.asm_editor:set_text(asm_f:read("*a"))
    asm_f:close()
  else
    self.asm_editor:set_text("; Build Tiny-C to generate ASM\n")
  end
end

function Ide:log(msg, kind)
  kind = kind or "info"
  local text = sanitize_utf8(msg)
  self.console[#self.console + 1] = { text = text, kind = kind }
  if #self.console > 200 then
    table.remove(self.console, 1)
  end
  self.status = text
  self.status_kind = kind
end

function Ide:log_error(msg)
  self:log(msg, "error")
end

function Ide:active_editor()
  if self.tab == "asm" then return self.asm_editor end
  return self.tc_editor
end

function Ide:is_docs()
  return self.tab == "docs"
end

function Ide:layout(ww, wh)
  local m = ui_metrics()
  self.ui = m
  local TOOLBAR_H = m.toolbar_h
  local TAB_H = m.tab_h
  local FILE_TAB_H = m.file_tab_h
  local CONSOLE_H = m.console_h
  local font = m.font

  -- Left: editor + console. Mid: one calculator face (LCD + keys). Right: memmap.
  local side_w = self.memmap:width()
  local split = math.floor((ww - side_w) * 0.55)
  local mid_w = ww - side_w - split
  local file_h = (self.tab == "tc" and self.project) and FILE_TAB_H or 0
  local calc_h = wh - TOOLBAR_H -- calculator column ignores console

  self.toolbar = { x = 0, y = 0, w = ww, h = TOOLBAR_H }
  self.tabs = { x = 0, y = TOOLBAR_H, w = split, h = TAB_H }
  self.file_tabs = { x = 0, y = TOOLBAR_H + TAB_H, w = split, h = file_h }
  self.editor_rect = {
    x = 0,
    y = TOOLBAR_H + TAB_H + file_h,
    w = split,
    h = wh - TOOLBAR_H - TAB_H - file_h - CONSOLE_H,
  }
  self.calc_rect = {
    x = split,
    y = TOOLBAR_H,
    w = mid_w,
    h = calc_h,
  }
  self:_layout_calculator_face()
  local side_x = ww - side_w
  self.side_rect = { x = side_x, y = TOOLBAR_H, w = side_w, h = calc_h }
  self.memmap:layout(side_x, TOOLBAR_H, calc_h)
  -- Console sits only under the code window (left column).
  self.console_rect = {
    x = 0,
    y = wh - CONSOLE_H,
    w = split,
    h = CONSOLE_H,
  }
  local r = self.editor_rect
  self.tc_editor:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)
  self.asm_editor:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)
  self.docs:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)

  local by = m.btn_y
  local bh = m.btn_h
  local function make_btns(start_x, specs)
    local bx = start_x
    local list = {}
    for _, spec in ipairs(specs) do
      local id, label = spec[1], spec[2]
      local tw = font and font:getWidth(label) or (#label * 8)
      local w = math.max(44, math.ceil(tw + 18))
      list[#list + 1] = { id = id, label = label, x = bx, y = by, w = w, h = bh }
      bx = bx + w + 6
    end
    return list, bx
  end

  -- Editor column: project / ROM tools.
  local editor_btns, editor_end = make_btns(10, {
    { "build", "Build" },
    { "os", "Boot OS" },
    { "load_rom", "Load ROM" },
    { "export_rom", "Export" },
    { "open", "Open" },
    { "save", "Save" },
  })
  -- Calculator column: run controls + memmap toggle.
  local calc_btns, calc_end = make_btns(self.calc_rect.x + 8, {
    { "play", self.running and "Pause" or "Play" },
    { "step", "Step" },
    { "reset", "Reset" },
    { "mem", self.memmap.open and "Mem >" or "Mem <" },
  })
  self.editor_buttons = editor_btns
  self.calc_buttons = calc_btns
  self.buttons = {}
  for _, b in ipairs(editor_btns) do
    self.buttons[#self.buttons + 1] = b
  end
  for _, b in ipairs(calc_btns) do
    self.buttons[#self.buttons + 1] = b
  end

  -- Main tabs sized to labels
  local tx = 8
  local function mtab(id, label)
    local tw = font and font:getWidth(label) or 56
    local w = math.ceil(tw + 20)
    local t = { id = id, label = label, x = tx, w = w }
    tx = tx + w + 4
    return t
  end
  self.tab_hits = {
    mtab("tab_tc", "Tiny-C"),
    mtab("tab_asm", "ASM"),
    mtab("tab_docs", "Stdlib"),
  }

  -- File tabs
  self.file_tab_hits = {}
  if file_h > 0 then
    local fx = 8
    for _, name in ipairs(self:_sorted_files()) do
      local tw = font and font:getWidth(name) or (#name * 8)
      local w = math.max(48, math.ceil(tw + 16))
      self.file_tab_hits[#self.file_tab_hits + 1] = { name = name, x = fx, w = w }
      fx = fx + w + 4
    end
  end

  -- Gate controls sit with Play/Step on the calculator toolbar.
  local gx = calc_end + 8
  local check = math.max(14, math.floor(m.fh * 0.95))
  self.gate_check = {
    x = gx,
    y = by + math.floor((bh - check) / 2),
    w = check,
    h = check,
  }
  gx = gx + check + 6
  self.gate_label_x = gx
  local gate_w = font and font:getWidth("Gate") or 32
  gx = gx + gate_w + 8
  local field_w = math.max(48, (font and font:getWidth("0000000") or 56) + 12)
  local field_h = math.max(20, m.fh + 6)
  self.gate_field = {
    x = gx,
    y = by + math.floor((bh - field_h) / 2),
    w = field_w,
    h = field_h,
  }
  gx = gx + field_w + 6
  self.gate_hz_label_x = gx
  local hz_w = font and font:getWidth("Hz") or 16
  self.gate_end_x = gx + hz_w

  -- Status fills leftover space in the editor toolbar strip.
  self.status_x = editor_end + STATUS_GAP
  self.status_max_x = self.calc_rect.x - 8
end

function Ide:hit_gate(mx, my)
  local c = self.gate_check
  if mx >= c.x and my >= c.y and mx < c.x + c.w and my < c.y + c.h then
    return "gate_check"
  end
  -- also toggle when clicking "Gate" label
  if my >= c.y - 2 and my < c.y + 18 and mx >= self.gate_label_x and mx < self.gate_field.x then
    return "gate_check"
  end
  local f = self.gate_field
  if mx >= f.x and my >= f.y and mx < f.x + f.w and my < f.y + f.h then
    return "gate_hz"
  end
  return nil
end

function Ide:apply_gate_hz_text()
  local n = tonumber(self.gate_hz_text)
  if n and n > 0 then
    self.gate_hz = math.min(1000000, math.floor(n))
    self.gate_hz_text = tostring(self.gate_hz)
  else
    self.gate_hz_text = tostring(self.gate_hz)
  end
end

--- Run emulator for one frame. Returns cycles (approx) consumed.
function Ide:run_emu(dt, machine, on_present)
  if not machine.rom_loaded or not self.running then
    return 0
  end
  if self.gate_active then
    local hz = math.max(1, self.gate_hz)
    self.gate_accum = self.gate_accum + dt * hz
    local steps = math.floor(self.gate_accum)
    if steps <= 0 then
      return 0
    end
    if steps > 5000 then
      steps = 5000 -- safety cap per frame
    end
    self.gate_accum = self.gate_accum - steps
    local ran = 0
    for _ = 1, steps do
      ran = ran + machine:step_instruction()
    end
    self.memmap.needs_refresh = true
    if on_present then on_present() end
    return ran
  end

  -- Realtime: ~6 MHz wall-clock (cursor blink / key debounce match hardware).
  local hz = MachineMod.CPU_HZ
  if dt < 0 then dt = 0 end
  if dt > 0.1 then dt = 0.1 end -- avoid huge catch-up after a hitch
  self.cycle_accum = self.cycle_accum + hz * dt
  local budget = math.floor(self.cycle_accum)
  if budget <= 0 then
    return 0
  end
  -- Cap one frame of catch-up (~50 ms of calc time).
  local max_budget = math.floor(hz / 20)
  if budget > max_budget then
    budget = max_budget
    self.cycle_accum = 0
  else
    self.cycle_accum = self.cycle_accum - budget
  end
  local ran = 0
  while ran < budget do
    local chunk = budget - ran
    if chunk > 4000 then chunk = 4000 end
    ran = ran + machine:run_cycles(chunk)
  end
  return ran
end

function Ide:hit_button(mx, my)
  local gid = self:hit_gate(mx, my)
  if gid then return gid end
  for _, b in ipairs(self.buttons) do
    if mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h then
      return b.id
    end
  end
  if self.tabs and my >= self.tabs.y and my < self.tabs.y + self.tabs.h then
    for _, t in ipairs(self.tab_hits or {}) do
      if mx >= t.x and mx < t.x + t.w then return t.id end
    end
  end
  if self.tab == "tc" and self.project and self.file_tabs and self.file_tabs.h > 0
      and my >= self.file_tabs.y and my < self.file_tabs.y + self.file_tabs.h then
    for _, t in ipairs(self.file_tab_hits or {}) do
      if mx >= t.x and mx < t.x + t.w then
        return "file:" .. t.name
      end
    end
  end
  return nil
end

--- Load real TI-83+ flash dump and start the calculator OS.
function Ide:boot_os(machine, on_loaded)
  local path = self.root .. "/rom/ti83plus.rom"
  self:log("Booting TI-83+ OS from " .. path .. " ...")
  local ok, err = machine:load_rom_file(path)
  if not ok then
    self:log_error("OS BOOT FAIL: " .. tostring(err))
    return false
  end
  machine:reset()
  self.running = true
  self.focus = "lcd"
  self.tc_editor.focused = false
  self.asm_editor.focused = false
  -- Boot ends in soft power-off (EI/HALT). Hold ON through the OS debounce
  -- (~0x1016 port-4 polls) so the wake handler accepts the keypress.
  machine:run_cycles(5 * 1000 * 1000)
  if machine.cpu.halted then
    self:log("OS at power-off HALT — holding ON to wake ...")
  end
  machine:set_key("on", true)
  machine:run_cycles(3 * 1000 * 1000)
  machine:set_key("on", false)
  machine:run_cycles(20 * 1000 * 1000)
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  local nz = 0
  local fb = machine:framebuffer()
  for i = 0, 12 * 64 - 1 do
    if (fb[i] or 0) ~= 0 then nz = nz + 1 end
  end
  self:log(string.format(
    "OS running  PC=%04X  display=%s  fb_nz=%d  (click LCD for keys)",
    machine:pc(), tostring(machine:is_display_on()), nz
  ))
  if on_loaded then on_loaded() end
  return true
end

function Ide:build(machine, on_loaded)
  local mode = (self.tab == "asm") and "asm" or "tc"
  self:log("Building (" .. mode .. ")...")
  local rom, err, asm
  if mode == "tc" then
    self:_sync_editor_to_project()
    -- Disk is source of truth: pick up AI / external edits, then keep dirty buffer.
    self:_reload_disk_sources()
    if self.project and self.project.dir then
      Tiproj.save_dir(self.project.dir, self.project)
    end
    local entry = self.project and self.project.entry or "main.tc"
    local src = self.project and self.project.files[entry] or self.tc_editor:get_text()
    local opts = {
      root = self.root,
      files = self.project and self.project.files or nil,
      entry = entry,
    }
    rom, err, asm = BuildSvc.build_tc(self.root, src, opts)
    if asm then
      self.asm_editor:set_text(asm)
      self:log("Tiny-C -> ASM ok (" .. #asm .. " chars)")
    end
  else
    rom, err = BuildSvc.build_asm(self.root, self.asm_editor:get_text())
  end
  if not rom then
    self:log_error("BUILD FAIL: " .. tostring(err))
    self:_goto_error(err)
    return false
  end
  local path = BuildSvc.write_rom(self.root, rom)
  self.last_built_rom = rom
  local proj = self.project and self.project.name
  self.last_built_name = (proj and (proj .. ".rom")) or "pipeline.rom"
  local ok, load_err = machine:load_rom_bytes(rom)
  if not ok then
    ok, load_err = machine:load_rom_file(path)
  end
  if not ok then
    self:log_error("LOAD FAIL: " .. tostring(load_err))
    return false
  end
  machine:reset()
  machine:run_cycles(800000)
  self.running = true
  self.tc_editor.dirty = false
  self.asm_editor.dirty = false
  self:log(string.format("Build OK -> %s  PC=%04X  (Export to save a copy)", path, machine:pc()))
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  if on_loaded then on_loaded() end
  return true
end

--- Load a 512KB flash dump into the emulator (does not compile).
function Ide:load_rom(machine, on_loaded)
  local path = Dialog.choose_open_rom()
  if not path then
    self:log("Load ROM cancelled")
    return false
  end
  self:log("Loading ROM " .. path .. " ...")
  local ok, err = machine:load_rom_file(path)
  if not ok then
    self:log_error("LOAD ROM FAIL: " .. tostring(err))
    return false
  end
  machine:reset()
  self.running = true
  self.focus = "lcd"
  self.tc_editor.focused = false
  self.asm_editor.focused = false
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  local base = path:match("([^/\\]+)$") or path
  self:log(string.format(
    "ROM loaded  %s  PC=%04X  (Play to run; Space=ON for TI-OS)",
    base, machine:pc()
  ))
  if on_loaded then on_loaded() end
  return true
end

--- Write the latest Build output to a user-chosen path.
function Ide:export_rom()
  local bytes = self.last_built_rom
  if not bytes then
    local fallback = self.root .. "/rom/pipeline.rom"
    local f = io.open(fallback, "rb")
    if f then
      bytes = f:read("*a")
      f:close()
      if bytes and #bytes == 512 * 1024 then
        self:log("Exporting last pipeline.rom (no in-session Build yet)")
      else
        bytes = nil
      end
    end
  end
  if not bytes or #bytes ~= 512 * 1024 then
    self:log_error("EXPORT FAIL: nothing to export — Build first")
    return false
  end
  local default_name = self.last_built_name or "pipeline.rom"
  local path = Dialog.choose_save_rom(default_name)
  if not path then
    self:log("Export cancelled")
    return false
  end
  local f, err = io.open(path, "wb")
  if not f then
    self:log_error("EXPORT FAIL: " .. tostring(err))
    return false
  end
  f:write(bytes)
  f:close()
  self:log(string.format("Exported ROM (%d bytes) -> %s", #bytes, path))
  return true
end

function Ide:save()
  if self.tab == "docs" then
    self:log("Stdlib tab is read-only")
    return
  end
  if self.tab == "asm" then
    local path = self.root .. "/asm/generated/ide.asm"
    local f = assert(io.open(path, "w"))
    f:write(self.asm_editor:get_text())
    f:close()
    self.asm_editor.dirty = false
    self:log("Saved " .. path)
    return
  end
  self:_sync_editor_to_project()
  if not self.project_dir then
    local name = self.project and self.project.name or "untitled"
    self.project_dir = self.root .. "/projects/" .. name
  end
  local ok, err = Tiproj.save_dir(self.project_dir, self.project)
  if not ok then
    self:log("Save fail: " .. tostring(err))
    return
  end
  self.tc_editor.dirty = false
  self:log("Saved " .. self.project_dir .. "/*.tc")
end

function Ide:open()
  local path = Dialog.choose_open_tiproj()
  if not path then
    path = self.root .. "/projects/shapes"
    self:log("No dialog - opening " .. path)
  end
  self:load_project(path)
end

function Ide:toggle_play()
  self.running = not self.running
  self:log(self.running and "Playing" or "Paused")
end

function Ide:step(machine, on_loaded)
  if not machine.rom_loaded then
    self:log("Step: no ROM loaded")
    return
  end
  self.running = false
  local pc0 = machine:pc()
  local cyc = machine:step_instruction()
  self.memmap:refresh(machine)
  self:log(string.format("Step +%d cyc  PC=%04X -> %04X", cyc, pc0, machine:pc()))
  if on_loaded then on_loaded() end
end

function Ide:mousepressed(mx, my, machine, on_loaded)
  if self.focus == "gate_hz" and self:hit_gate(mx, my) ~= "gate_hz" then
    self:apply_gate_hz_text()
  end

  do
    local handled, kind, key = self.keypad_ui:mousepressed(mx, my)
    if handled then
      if kind == "press" and key then
        machine:set_key(key, true)
        self.focus = "lcd"
        self.tc_editor.focused = false
        self.asm_editor.focused = false
      end
      return true
    end
  end

  if self.memmap:mousepressed(mx, my) then
    if self.memmap.open then
      self.memmap:refresh(machine)
      self:log("Memory map open")
    else
      self:log("Memory map closed")
    end
    self.focus = "mem"
    return true
  end

  local id = self:hit_button(mx, my)
  if id == "build" then
    self:build(machine, on_loaded)
    return true
  elseif id == "os" then
    self:boot_os(machine, on_loaded)
    return true
  elseif id == "load_rom" then
    self:load_rom(machine, on_loaded)
    return true
  elseif id == "export_rom" then
    self:export_rom()
    return true
  elseif id == "play" then
    self:toggle_play()
    return true
  elseif id == "step" then
    self:step(machine, on_loaded)
    return true
  elseif id == "reset" then
    if machine.rom_loaded then
      self.running = false
      machine:reset()
      self.memmap:refresh(machine)
      self:log(string.format("Reset (cold)  PC=%04X", machine:pc()))
      if on_loaded then on_loaded() end
    end
    return true
  elseif id == "save" then
    self:save()
    return true
  elseif id == "open" then
    self:open()
    return true
  elseif id == "mem" then
    self.memmap:toggle_open()
    if self.memmap.open then
      self.memmap:refresh(machine)
    end
    self:log(self.memmap.open and "Memory map open" or "Memory map closed")
    return true
  elseif id == "gate_check" then
    self.gate_active = not self.gate_active
    self.gate_accum = 0
    self:log(self.gate_active
      and string.format("Gate ON  %d step/s", self.gate_hz)
      or "Gate OFF  (realtime 6 MHz)")
    return true
  elseif id == "gate_hz" then
    self.focus = "gate_hz"
    self.tc_editor.focused = false
    self.asm_editor.focused = false
    return true
  elseif id == "tab_tc" then
    self.tab = "tc"
    self.tc_editor.focused = true
    self.asm_editor.focused = false
    self.focus = "editor"
    return true
  elseif id == "tab_asm" then
    self.tab = "asm"
    self.asm_editor.focused = true
    self.tc_editor.focused = false
    self.focus = "editor"
    return true
  elseif id == "tab_docs" then
    self.tab = "docs"
    self.tc_editor.focused = false
    self.asm_editor.focused = false
    self.focus = "docs"
    return true
  elseif id and id:sub(1, 5) == "file:" then
    self:_open_project_file(id:sub(6))
    return true
  end

  if self:is_docs() then
    if self.docs:contains(mx, my) then
      self.focus = "docs"
      return true
    end
  else
    local ed = self:active_editor()
    local shift = love.keyboard.isDown("lshift", "rshift")
    if ed:mousepressed(mx, my, shift) then
      self.focus = "editor"
      self.console_sel = nil
      self.console_dragging = false
      return true
    end
  end

  local ed = self:active_editor()
  local cr_calc = self.calc_rect
  if cr_calc and mx >= cr_calc.x and my >= cr_calc.y
      and mx < cr_calc.x + cr_calc.w and my < cr_calc.y + cr_calc.h then
    self.focus = "lcd"
    ed.focused = false
    self.console_sel = nil
    self.console_dragging = false
    return true
  end

  local cr = self.console_rect
  if mx >= cr.x and my >= cr.y and mx < cr.x + cr.w and my < cr.y + cr.h then
    self.focus = "console"
    ed.focused = false
    self:_console_refresh_view()
    local pos = self:_console_pos_at(mx, my)
    if pos then
      self.console_sel = { a = { r = pos.r, c = pos.c }, b = { r = pos.r, c = pos.c } }
      self.console_dragging = true
    else
      self.console_sel = nil
      self.console_dragging = false
    end
    return true
  end
  self.console_dragging = false
  return false
end

function Ide:mousemoved(mx, my, machine)
  self.memmap:mousemoved(mx, my, machine)
  self.keypad_ui:mousemoved(mx, my)
  if self.console_dragging and self.focus == "console" then
    local pos = self:_console_pos_at(mx, my)
    if pos and self.console_sel then
      self.console_sel.b = { r = pos.r, c = pos.c }
    end
    return true
  end
  if self:is_docs() then return false end
  return self:active_editor():mousemoved(mx, my)
end

function Ide:mousereleased(machine)
  local key = self.keypad_ui:mousereleased()
  if key and machine then
    machine:set_key(key, false)
  end
  if self.console_dragging then
    self.console_dragging = false
    -- collapse empty selection
    if self.console_sel and self.console_sel.a and self.console_sel.b
        and self.console_sel.a.r == self.console_sel.b.r
        and self.console_sel.a.c == self.console_sel.b.c then
      self.console_sel = nil
    end
    return true
  end
  if self:is_docs() then return false end
  return self:active_editor():mousereleased()
end

function Ide:keypressed(key, machine, on_loaded)
  if self.focus == "gate_hz" then
    if key == "return" or key == "kpenter" or key == "escape" then
      self:apply_gate_hz_text()
      self.focus = "editor"
      return true
    elseif key == "backspace" then
      self.gate_hz_text = self.gate_hz_text:sub(1, -2)
      return true
    end
  end

  local ctrl = love.keyboard.isDown("lctrl") or love.keyboard.isDown("rctrl")
      or love.keyboard.isDown("lgui") or love.keyboard.isDown("rgui")
  local shift = love.keyboard.isDown("lshift") or love.keyboard.isDown("rshift")

  if key == "f5" then
    self:build(machine, on_loaded)
    return true
  elseif key == "f6" then
    self:toggle_play()
    return true
  elseif key == "f7" then
    self.memmap:toggle_open()
    if self.memmap.open then
      self.memmap:refresh(machine)
    end
    self:log(self.memmap.open and "Memory map open" or "Memory map closed")
    return true
  elseif key == "f8" then
    self:step(machine, on_loaded)
    return true
  elseif key == "f9" then
    self:load_rom(machine, on_loaded)
    return true
  elseif key == "f10" then
    self:export_rom()
    return true
  elseif ctrl and key == "s" then
    self:save()
    return true
  elseif ctrl and key == "o" then
    if shift then
      self:load_rom(machine, on_loaded)
    else
      self:open()
    end
    return true
  elseif ctrl and key == "e" then
    self:export_rom()
    return true
  elseif ctrl and key == "b" then
    self:build(machine, on_loaded)
    return true
  end

  if self.focus == "console" then
    local ctrl = love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui")
    if ctrl and key == "c" then
      self:_console_copy()
      return true
    elseif ctrl and key == "a" then
      self:_console_select_all()
      return true
    elseif key == "escape" then
      self.console_sel = nil
      return true
    end
    return true
  end

  if self.focus == "editor" and not self:is_docs() then
    return self:active_editor():keypressed(key)
  end
  return false
end

function Ide:textinput(t)
  if self.focus == "gate_hz" then
    if t:match("^%d$") and #self.gate_hz_text < 7 then
      self.gate_hz_text = self.gate_hz_text .. t
    end
    return
  end
  if self.focus == "editor" and not self:is_docs() then
    self:active_editor():textinput(t)
  end
end

function Ide:wheelmoved(x, y)
  if self:is_docs() then
    if self.docs:contains(love.mouse.getX(), love.mouse.getY()) or self.focus == "docs" then
      return self.docs:wheelmoved(x, y)
    end
  elseif self.focus == "editor" then
    return self:active_editor():wheelmoved(x, y)
  end
  return false
end

function Ide:update(dt, machine)
  if not self:is_docs() then
    self:active_editor():update(dt)
  end
  self.memmap:update(dt, machine)
  for _, b in ipairs(self.buttons) do
    if b.id == "play" then
      b.label = self.running and "Pause" or "Play"
    elseif b.id == "mem" then
      b.label = self.memmap.open and "Mem >" or "Mem <"
    end
  end
end

local function draw_btn(b, hot, font, fh)
  love.graphics.setColor(hot and 0.32 or 0.22, hot and 0.38 or 0.26, hot and 0.34 or 0.24, 1)
  love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
  love.graphics.setColor(0.85, 0.88, 0.82, 1)
  local tw = font:getWidth(b.label)
  love.graphics.print(b.label, b.x + (b.w - tw) / 2, b.y + (b.h - fh) / 2)
end

function Ide:draw()
  local ww, wh = love.graphics.getDimensions()
  self:layout(ww, wh)
  local m = self.ui or ui_metrics()
  local font = m.font or love.graphics.getFont()
  local fh = m.fh
  local TOOLBAR_H = m.toolbar_h
  local TAB_H = m.tab_h
  local FILE_TAB_H = m.file_tab_h
  local CONSOLE_FOOTER_H = m.console_footer

  love.graphics.setColor(0.16, 0.17, 0.19, 1)
  love.graphics.rectangle("fill", 0, 0, ww, TOOLBAR_H)
  local mx, my = love.mouse.getPosition()
  for _, b in ipairs(self.buttons) do
    local hot = mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h
    draw_btn(b, hot, font, fh)
  end

  -- Gate checkbox + Hz field
  local gc = self.gate_check
  love.graphics.setColor(0.22, 0.26, 0.24, 1)
  love.graphics.rectangle("fill", gc.x, gc.y, gc.w, gc.h, 2, 2)
  love.graphics.setColor(0.55, 0.65, 0.55, 1)
  love.graphics.rectangle("line", gc.x + 0.5, gc.y + 0.5, gc.w - 1, gc.h - 1, 2, 2)
  if self.gate_active then
    love.graphics.setColor(0.45, 0.85, 0.55, 1)
    love.graphics.rectangle("fill", gc.x + 3, gc.y + 3, gc.w - 6, gc.h - 6, 1, 1)
  end
  local text_y = math.floor((TOOLBAR_H - fh) / 2)
  love.graphics.setColor(self.gate_active and 0.85 or 0.55, self.gate_active and 0.9 or 0.6, 0.7, 1)
  love.graphics.print("Gate", self.gate_label_x, text_y)
  local gf = self.gate_field
  local field_hot = self.focus == "gate_hz"
  love.graphics.setColor(field_hot and 0.18 or 0.12, field_hot and 0.22 or 0.14, field_hot and 0.18 or 0.14, 1)
  love.graphics.rectangle("fill", gf.x, gf.y, gf.w, gf.h, 3, 3)
  love.graphics.setColor(field_hot and 0.55 or 0.35, field_hot and 0.7 or 0.45, field_hot and 0.55 or 0.4, 1)
  love.graphics.rectangle("line", gf.x + 0.5, gf.y + 0.5, gf.w - 1, gf.h - 1, 3, 3)
  love.graphics.setColor(0.9, 0.92, 0.85, 1)
  love.graphics.print(self.gate_hz_text, gf.x + 6, gf.y + (gf.h - fh) / 2)
  love.graphics.setColor(0.55, 0.6, 0.55, 1)
  love.graphics.print("Hz", self.gate_hz_label_x, text_y)

  -- Status sits after editor tools; clipped so it never runs into the calc toolbar.
  local status_x = self.status_x or 360
  local status_max = self.status_max_x or (self.calc_rect and self.calc_rect.x - 8) or (ww - 10)
  local status_w = math.max(0, status_max - status_x)
  if status_w > 8 then
    local proj = self.project_dir and self.project_dir:match("([^/]+)$") or "(no project)"
    local status = proj .. "  -  " .. (self.status or "")
    love.graphics.setScissor(status_x, 0, status_w, TOOLBAR_H)
    if self.status_kind == "error" then
      love.graphics.setColor(0.95, 0.35, 0.32, 1)
    else
      love.graphics.setColor(0.55, 0.6, 0.55, 1)
    end
    love.graphics.print(status, status_x, text_y)
    love.graphics.setScissor()
  end

  love.graphics.setColor(0.14, 0.15, 0.17, 1)
  love.graphics.rectangle("fill", self.tabs.x, self.tabs.y, self.tabs.w, self.tabs.h)
  for _, t in ipairs(self.tab_hits or {}) do
    local active = (t.id == "tab_tc" and self.tab == "tc")
      or (t.id == "tab_asm" and self.tab == "asm")
      or (t.id == "tab_docs" and self.tab == "docs")
    love.graphics.setColor(active and 0.22 or 0.16, active and 0.28 or 0.18, active and 0.24 or 0.18, 1)
    love.graphics.rectangle("fill", t.x, self.tabs.y + 2, t.w, TAB_H - 4, 3, 3)
    love.graphics.setColor(active and 0.95 or 0.65, active and 0.9 or 0.7, 0.7, 1)
    local tw = font:getWidth(t.label)
    love.graphics.print(t.label, t.x + (t.w - tw) / 2, self.tabs.y + (TAB_H - fh) / 2)
  end

  if self.tab == "tc" and self.project and self.file_tabs.h > 0 then
    love.graphics.setColor(0.12, 0.13, 0.14, 1)
    love.graphics.rectangle("fill", self.file_tabs.x, self.file_tabs.y, self.file_tabs.w, self.file_tabs.h)
    for _, t in ipairs(self.file_tab_hits or {}) do
      local active = t.name == self.open_file
      love.graphics.setColor(active and 0.28 or 0.18, active and 0.32 or 0.2, active and 0.26 or 0.2, 1)
      love.graphics.rectangle("fill", t.x, self.file_tabs.y + 2, t.w, FILE_TAB_H - 4, 2, 2)
      love.graphics.setColor(active and 0.95 or 0.6, active and 0.92 or 0.65, 0.7, 1)
      love.graphics.print(t.name, t.x + 8, self.file_tabs.y + (FILE_TAB_H - fh) / 2)
    end
  end

  if not self:is_docs() then
    local ed = self:active_editor()
    if ed.dirty then
      love.graphics.setColor(0.9, 0.6, 0.3, 1)
      love.graphics.print("*", self.tabs.w - 20, self.tabs.y + (TAB_H - fh) / 2)
    end
  end

  love.graphics.setColor(0.11, 0.12, 0.13, 1)
  love.graphics.rectangle("fill", self.editor_rect.x, self.editor_rect.y, self.editor_rect.w, self.editor_rect.h)
  if self:is_docs() then
    self.docs:set_bounds(self.editor_rect.x + 4, self.editor_rect.y + 4, self.editor_rect.w - 8, self.editor_rect.h - 8)
    self.docs:draw()
  else
    local ed = self:active_editor()
    ed:set_bounds(self.editor_rect.x + 4, self.editor_rect.y + 4, self.editor_rect.w - 8, self.editor_rect.h - 8)
    ed:draw()
  end

  local cr = self.console_rect
  love.graphics.setColor(0.08, 0.09, 0.10, 1)
  love.graphics.rectangle("fill", cr.x, cr.y, cr.w, cr.h)
  love.graphics.setColor(0.3, 0.32, 0.3, 1)
  love.graphics.line(cr.x, cr.y, cr.x + cr.w, cr.y)
  love.graphics.setColor(0.55, 0.7, 0.55, 1)
  love.graphics.print("Console", cr.x + 8, cr.y + 4)

  local v = self:_console_refresh_view()
  local header_h = v.header_h
  local log_bottom = v.log_bottom
  local line_h = v.line_h
  local text_x = v.text_x
  local display = v.lines
  local start = v.start
  love.graphics.setScissor(cr.x, cr.y + header_h, cr.w, math.max(0, log_bottom - (cr.y + header_h)))
  local ar, ac, br, bc = self:_console_sel_range()
  local ly = cr.y + header_h
  for i = start, #display do
    local row = display[i]
    local text = row.text or ""
    -- selection highlight
    if ar and i >= ar and i <= br then
      local sc = (i == ar) and ac or 1
      local ec = (i == br) and bc or (#text + 1)
      if ec > sc then
        local x0 = text_x + font:getWidth(text:sub(1, sc - 1))
        local x1 = text_x + font:getWidth(text:sub(1, ec - 1))
        if i < br then
          x1 = math.max(x1, text_x + font:getWidth(text) + 4)
        end
        love.graphics.setColor(0.25, 0.45, 0.70, 0.55)
        love.graphics.rectangle("fill", x0, ly, math.max(2, x1 - x0), line_h)
      end
    end
    if row.kind == "error" then
      love.graphics.setColor(0.95, 0.35, 0.32, 1)
    else
      love.graphics.setColor(0.75, 0.78, 0.72, 1)
    end
    love.graphics.print(text, text_x, ly)
    ly = ly + line_h
  end
  love.graphics.setScissor()

  love.graphics.setColor(0.22, 0.24, 0.22, 1)
  love.graphics.line(cr.x, log_bottom, cr.x + cr.w, log_bottom)
  love.graphics.setColor(0.4, 0.45, 0.4, 1)
  local hint = self.focus == "console"
      and "Console  drag=select  Ctrl+A/C  Esc clear"
      or "Editor: F5 Build  F9 Load ROM  F10 Export  Ctrl+O  |  Calc: F6 Play  F8 Step"
  love.graphics.print(
    hint,
    cr.x + 8, log_bottom + math.max(1, (CONSOLE_FOOTER_H - fh) / 2)
  )

  self.memmap:draw()
  self:draw_calculator()
end

function Ide:draw_calculator()
  local cr = self.calc_rect
  if not cr or cr.w <= 0 then return end

  -- Plain column backdrop — no separate calculator body pane.
  love.graphics.setColor(0.11, 0.12, 0.13, 1)
  love.graphics.rectangle("fill", cr.x, cr.y, cr.w, cr.h)
  self.keypad_ui:draw()
end

function Ide:lcd_panel()
  return self.lcd_rect
end

function Ide:calc_panel()
  return self.calc_rect
end

return Ide
