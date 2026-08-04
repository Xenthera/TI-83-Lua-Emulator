-- Mini IDE: disk-backed projects (*.tc + project.tiproj), ASM, stdlib, build/play.

local Editor = require("editor")
local BuildSvc = require("buildsvc")
local Compendium = require("compendium")
local Dialog = require("dialog")
local Tiproj = require("lang.tiproj")
local MemMap = require("memmap")
local KeypadUI = require("keypad_ui")
local KeypadTI84 = require("keypad_ti84")
local KeypadTI89 = require("keypad_ti89")
local KeypadTI92 = require("keypad_ti92")
local KeypadRV64 = require("keypad_riscv64")
local KeypadGB = require("keypad_gameboy")
local KeypadLayouts = require("keypad_layouts")
local PanelEditor = require("panel_editor")
local MachineMod = require("machines.ti83plus.machine")
local Lcd83 = require("machines.ti83plus.hw.lcd")
local Lcd89 = require("machines.ti89.hw.lcd")
local Lcd92 = require("machines.ti92plus.hw.lcd")
local LcdRV64 = require("machines.riscv64.hw.lcd")
local LcdGB = require("machines.gameboy.hw.ppu")
local LcdNES = require("machines.nes.hw.ppu")
local Eightxk = require("machines.ti83plus.util.eightxk")
local Eightxp = require("machines.ti83plus.util.eightxp")

local Ide = {}
Ide.__index = Ide

local CALC_PAD = 8
local CALC_STATS_H = 20 -- footer for FPS/PC overlay
local CALC_GAP_RATIO = 0.04 -- gap between LCD and keys, relative to face width
-- Leave headroom so the face (esp. TI-89 shell/bezel) stays inside the column.
local CALC_FACE_FIT = 0.90

function Ide:_lcd_module()
  if self.machine_id == "ti89" then
    return Lcd89
  end
  if self.machine_id == "ti92plus" then
    return Lcd92
  end
  if self.machine_id == "riscv64" then
    return LcdRV64
  end
  if self.machine_id == "gameboy" then
    return LcdGB
  end
  if self.machine_id == "nes" then
    return LcdNES
  end
  return Lcd83
end

function Ide:_key_face_aspect()
  local kp = self.keypad_ui
  if kp and kp.face_aspect then
    return kp.face_aspect
  end
  if self.machine_id == "ti89" then
    return KeypadTI89.FACE_ASPECT
  end
  if self.machine_id == "ti92plus" then
    return KeypadTI92.FACE_ASPECT
  end
  return KeypadUI.FACE_ASPECT
end

function Ide:_load_keypad_layout(id)
  local doc = KeypadLayouts.load(self.root, id)
  self.keypad_layout = doc
  return doc
end

function Ide:_make_keypad(id)
  local layout = self:_load_keypad_layout(id)
  if id == "ti89" then
    return KeypadTI89.new({ layout = layout })
  elseif id == "ti92plus" then
    return KeypadTI92.new({ layout = layout })
  elseif id == "ti84plus" then
    return KeypadTI84.new({ layout = layout })
  elseif id == "riscv64" then
    return KeypadRV64.new({ layout = layout })
  elseif id == "gameboy" or id == "nes" then
    -- Same 8-button layout (A/B/Start/Select + D-pad).
    -- Prefer gameboy scene metrics if a dedicated nes layout is missing.
    if id == "nes" and (not layout or not layout.scene) then
      layout = self:_load_keypad_layout("gameboy") or layout
    end
    return KeypadGB.new({ layout = layout })
  end
  return KeypadUI.new({ layout = layout })
end

--- Place LCD + keypad from a scene layout (design units -> pixels).
function Ide:_layout_from_scene(cr, avail_w, avail_h)
  local doc = self.keypad_layout
  if not doc or not doc.scene or not doc.lcd or not doc.panel then
    return false
  end
  local sw, sh = doc.scene.w, doc.scene.h
  if sw < 0.1 or sh < 0.1 then
    return false
  end
  local unit = math.min(avail_w / sw, avail_h / sh)
  local face_w, face_h = sw * unit, sh * unit
  local x0 = cr.x + math.floor((cr.w - face_w) / 2)
  local y0 = cr.y + CALC_PAD
    + math.floor((cr.h - CALC_PAD * 2 - CALC_STATS_H - face_h) / 2)
  self.face_shell = { x = x0, y = y0, w = face_w, h = face_h }
  self._brand_gap = 0
  self.lcd_chrome = doc.lcd
  -- Glass size follows hardware pixel aspect so the presenter can fill with no borders.
  local Lcd = self:_lcd_module()
  local lw = doc.lcd.w * unit
  local lh = lw * (Lcd.HEIGHT / Lcd.WIDTH)
  self.lcd_rect = {
    x = x0 + doc.lcd.x * unit,
    y = y0 + doc.lcd.y * unit,
    w = lw,
    h = lh,
  }
  self._lcd_unit = unit
  self.keypad_ui:layout(
    x0 + doc.panel.x * unit,
    y0 + doc.panel.y * unit,
    doc.panel.w * unit,
    doc.panel.h * unit
  )
  return true
end

function Ide:open_panel_editor()
  self.panel_editor = PanelEditor.new({
    root = self.root,
    machine = self.machine_id or "ti83plus",
    on_close = function()
      self.panel_editor = nil
      self:reload_keypad_from_disk()
      self:layout(love.graphics.getDimensions())
      self:log("Panel editor closed")
    end,
    on_saved = function(machine)
      if machine == self.machine_id then
        self:reload_keypad_from_disk()
        self:layout(love.graphics.getDimensions())
      end
      self:log("Keypad layout saved: " .. machine)
    end,
  })
  self.running = false
  self:log("Panel editor - drag keys, resize handles, edit legends, Save writes ui/keypads/")
end

function Ide:reload_keypad_from_disk()
  local id = self.machine_id or "ti83plus"
  local layout = self:_load_keypad_layout(id)
  if self.keypad_ui and self.keypad_ui.reload_layout and layout then
    self.keypad_ui:reload_layout(layout)
  else
    self.keypad_ui = self:_make_keypad(id)
  end
end

function Ide:_draw_lcd_chrome()
  local chrome = self.lcd_chrome
  local lr = self.lcd_rect
  if not chrome or not lr or lr.w <= 0 then return end
  local unit = self._lcd_unit or 1
  local rad = math.max(0, (chrome.radius or 0) * unit)
  local bezel = chrome.color or { 0.08, 0.08, 0.09 }
  local glass = chrome.glass or bezel
  -- Outer bezel sits outside the glass; framebuffer fills lcd_rect with no letterbox.
  local pad = math.max(2, unit * 0.1)
  love.graphics.setColor(bezel[1], bezel[2], bezel[3], 1)
  love.graphics.rectangle("fill", lr.x - pad, lr.y - pad, lr.w + pad * 2, lr.h + pad * 2, rad, rad)
  love.graphics.setColor(glass[1], glass[2], glass[3], 1)
  love.graphics.rectangle("fill", lr.x, lr.y, lr.w, lr.h, math.max(0, rad - pad * 0.5), math.max(0, rad - pad * 0.5))
end

--- Screen + keys share one aspect (normal width). Uniformly scale to fill height.
function Ide:_layout_calculator_face()
  local cr = self.calc_rect
  if not cr or cr.w < 40 or cr.h < 40 then
    self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
    return
  end

  local avail_w = (cr.w - CALC_PAD * 2) * CALC_FACE_FIT
  local avail_h = (cr.h - CALC_PAD * 2 - CALC_STATS_H) * CALC_FACE_FIT
  if avail_w < 48 or avail_h < 80 then
    self.lcd_rect = { x = 0, y = 0, w = 0, h = 0 }
    return
  end

  if self:_layout_from_scene(cr, avail_w, avail_h) then
    return
  end

  local Lcd = self:_lcd_module()
  local key_aspect = self:_key_face_aspect()
  local screen_aspect = Lcd.HEIGHT / Lcd.WIDTH
  local is_ti89 = self.machine_id == "ti89"

  local face_w, screen_h, gap, keys_h, total_h, lcd_w

  if is_ti89 then
    -- Keypad sets face width; LCD is narrower - F1 left edge to F5 right edge.
    local function stack_for_w(w)
      local kh = w * key_aspect
      local lw = KeypadTI89.fkey_band_width(w, kh)
      local sh = lw * screen_aspect
      local g = math.max(4, w * CALC_GAP_RATIO)
      return lw, sh, g, kh, sh + g + kh
    end
    -- Estimate unit height with LCD ≈ 0.93 of face (F-key circles are height-limited).
    local unit_h = screen_aspect * 0.93 + CALC_GAP_RATIO + key_aspect
    face_w = avail_h / unit_h
    if face_w > avail_w then face_w = avail_w end
    lcd_w, screen_h, gap, keys_h, total_h = stack_for_w(face_w)
    if total_h < avail_h - 1 and face_w < avail_w then
      local s = math.min(avail_h / total_h, avail_w / face_w)
      face_w = face_w * s
      lcd_w, screen_h, gap, keys_h, total_h = stack_for_w(face_w)
    end
  else
    -- TI-83+: LCD + keys share one width; prefer integer LCD cells.
    local unit_h = screen_aspect + CALC_GAP_RATIO + key_aspect
    face_w = avail_h / unit_h
    if face_w > avail_w then face_w = avail_w end
    local cell = math.max(2, math.floor(face_w / Lcd.WIDTH))
    local function stack_for(c)
      local w = c * Lcd.WIDTH
      local sh = c * Lcd.HEIGHT
      local g = math.max(4, w * CALC_GAP_RATIO)
      local kh = w * key_aspect
      return w, sh, g, kh, sh + g + kh
    end
    face_w, screen_h, gap, keys_h, total_h = stack_for(cell)
    while cell > 2 and (face_w > avail_w + 0.5 or total_h > avail_h + 0.5) do
      cell = cell - 1
      face_w, screen_h, gap, keys_h, total_h = stack_for(cell)
    end
    if total_h < avail_h - 1 and face_w < avail_w then
      local s = math.min(avail_h / total_h, avail_w / face_w)
      face_w = face_w * s
      screen_h = screen_h * s
      gap = gap * s
      keys_h = keys_h * s
      total_h = screen_h + gap + keys_h
    end
    lcd_w = face_w
  end

  -- TI-89: shell margin + brand strip above the LCD, both proportional to face width.
  -- Shell extends outside the key/LCD stack - include it in the height budget.
  local shell = 0
  local brand_gap = 0
  if is_ti89 then
    shell = math.max(6, face_w * 0.03)
    brand_gap = math.max(12, face_w * 0.055)
    local chrome_h = brand_gap + shell * 2
    if total_h + chrome_h > avail_h and total_h > 0 then
      local s = (avail_h - chrome_h) / total_h
      if s > 0.5 and s < 1 then
        face_w = face_w * s
        local kh = face_w * key_aspect
        lcd_w = KeypadTI89.fkey_band_width(face_w, kh)
        screen_h = lcd_w * screen_aspect
        gap = math.max(4, face_w * CALC_GAP_RATIO)
        keys_h = kh
        total_h = screen_h + gap + keys_h
        shell = math.max(6, face_w * 0.03)
        brand_gap = math.max(12, face_w * 0.055)
      end
    end
  end
  local chrome_h = brand_gap + shell * 2
  local x0 = cr.x + math.floor((cr.w - face_w) / 2)
  local y0 = cr.y + CALC_PAD
    + math.floor((cr.h - CALC_PAD * 2 - CALC_STATS_H - total_h - chrome_h) / 2)
    + shell + brand_gap
  self.face_shell = {
    x = x0 - shell,
    y = y0 - shell - brand_gap,
    w = face_w + shell * 2,
    h = total_h + shell * 2 + brand_gap,
  }
  self._brand_gap = brand_gap

  local lcd_x = x0 + (face_w - lcd_w) * 0.5
  self.lcd_rect = {
    x = lcd_x,
    y = y0,
    w = lcd_w,
    h = screen_h,
  }
  self.keypad_ui:layout(x0, y0 + screen_h + gap, face_w, keys_h)
end

local STATUS_GAP = 12
local GROUP_GAP = 14
local BTN_GAP = 5

local function ui_metrics()
  local font = love.graphics.getFont()
  local fh = font and math.ceil(font:getHeight()) or 14
  local label_h = math.max(12, fh - 1)
  local btn_h = math.max(22, fh + 8)
  local row_pad = 4
  -- Two-row toolbar: group label + buttons per row.
  local row_h = label_h + 2 + btn_h
  local toolbar_h = row_pad + row_h + 4 + row_h + row_pad
  local tab_h = math.max(28, fh + 12)
  local file_tab_h = math.max(24, fh + 10)
  local console_footer = math.max(18, fh + 6)
  local console_h = math.max(110, fh * 6 + console_footer + 28)
  return {
    fh = fh,
    font = font,
    toolbar_h = toolbar_h,
    tab_h = tab_h,
    file_tab_h = file_tab_h,
    console_h = console_h,
    console_footer = console_footer,
    btn_h = btn_h,
    label_h = label_h,
    row_pad = row_pad,
    row_h = row_h,
    row1_label_y = row_pad,
    row1_btn_y = row_pad + label_h + 2,
    row2_label_y = row_pad + row_h + 4,
    row2_btn_y = row_pad + row_h + 4 + label_h + 2,
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
  self.machine_id = "ti83plus"
  self.memmap = MemMap.new(self.machine_id)
  self.keypad_ui = self:_make_keypad("ti83plus")
  self.panel_editor = nil
  self.on_select_machine = nil -- set by main.lua: function(id)
  self.on_home = nil -- set by main.lua: return to machine launcher
  self.focus = "editor" -- editor | docs | lcd | console | mem | gate_hz
  self.project_dir = nil
  self.project = nil
  self.open_file = nil
  -- Run gate: when active, Play advances at gate_hz instructions/sec; else realtime CPU_HZ.
  self.gate_active = false
  self.gate_hz = 20
  self.gate_hz_text = "20"
  self.gate_hz_sel_all = false
  self.gate_accum = 0
  self.cycle_accum = 0
  self.gate_check = { x = 0, y = 0, w = 0, h = 0 }
  self.gate_field = { x = 0, y = 0, w = 0, h = 0 }
  -- Last successful Build output (512KB flash image), for Export ROM.
  self.last_built_rom = nil
  self.last_built_name = nil
  self.last_built_os = false
  -- Last Flash App .8xk bytes (for Export App).
  self.last_built_xk = nil
  self.last_built_xk_name = nil
  self.toolbar_groups = {}
  -- External edit watch: content fingerprints of project.tiproj + *.tc
  self._disk_sigs = nil
  self._disk_poll_t = 0
  self:_load_default_project()
  return self
end

--- Tiny-C / ASM / Flash App studio is only wired for Z80 TI calcs.
function Ide:tinyc_supported(id)
  id = id or self.machine_id or "ti83plus"
  return id == "ti83plus" or id == "ti84plus"
end

--- File-dialog profile + Inject button label for the active machine's ROM/cart.
function Ide:rom_open_profile()
  local id = self.machine_id or "ti83plus"
  local root = self.root or "."
  -- Filters are machine-specific only (no "All files") so browse stays typed.
  if id == "gameboy" then
    return {
      title = "Load Game Boy ROM",
      prompt = "Load Game Boy cart (.gb)",
      filter_win = "Game Boy ROMs (*.gb)|*.gb;*.GB",
      filter_zenity = "Game Boy ROMs | *.gb *.GB",
      mac_types = '{"gb","GB","public.data"}',
      default_ext = "gb",
      default_dir = root .. "/rom/gb",
      button = ".gb",
    }
  elseif id == "nes" then
    return {
      title = "Load NES ROM",
      prompt = "Load NES cart (.nes)",
      filter_win = "NES ROMs (*.nes)|*.nes;*.NES",
      filter_zenity = "NES ROMs | *.nes *.NES",
      mac_types = '{"nes","NES","public.data"}',
      default_ext = "nes",
      default_dir = root .. "/rom/nes",
      button = ".nes",
    }
  elseif id == "riscv64" then
    return {
      title = "Load RV64 firmware",
      prompt = "Load RV64 firmware (.bin)",
      filter_win = "RV64 firmware (*.bin)|*.bin;*.BIN",
      filter_zenity = "RV64 firmware | *.bin *.BIN",
      mac_types = '{"bin","BIN","public.data"}',
      default_ext = "bin",
      default_dir = root .. "/rom/riscv64",
      button = ".bin",
    }
  elseif id == "ti89" then
    return {
      title = "Load TI-89 ROM / OS",
      prompt = "Load TI-89 ROM or OS (.89u / .tib / .rom)",
      filter_win = "TI-89 OS/ROM (*.89u;*.tib;*.rom;*.bin)|*.89u;*.89U;*.tib;*.TIB;*.rom;*.ROM;*.bin;*.BIN",
      filter_zenity = "TI-89 OS/ROM | *.89u *.tib *.rom *.bin",
      mac_types = '{"89u","89U","tib","TIB","rom","bin","public.data"}',
      default_ext = "89u",
      default_dir = root .. "/rom",
      button = ".89u",
    }
  elseif id == "ti92plus" then
    return {
      title = "Load TI-92+ ROM / OS",
      prompt = "Load TI-92+ ROM or OS (.9xu / .tib / .rom)",
      filter_win = "TI-92+ OS/ROM (*.9xu;*.tib;*.rom;*.bin)|*.9xu;*.9XU;*.tib;*.TIB;*.rom;*.ROM;*.bin;*.BIN",
      filter_zenity = "TI-92+ OS/ROM | *.9xu *.tib *.rom *.bin",
      mac_types = '{"9xu","9XU","tib","TIB","rom","bin","public.data"}',
      default_ext = "9xu",
      default_dir = root .. "/rom",
      button = ".9xu",
    }
  elseif id == "ti84plus" then
    return {
      title = "Load TI-84+ ROM",
      prompt = "Load TI-84 Plus ROM (.rom / .bin)",
      filter_win = "TI-84+ ROMs (*.rom;*.bin)|*.rom;*.ROM;*.bin;*.BIN",
      filter_zenity = "TI-84+ ROMs | *.rom *.bin",
      mac_types = '{"rom","bin","public.data"}',
      default_ext = "rom",
      default_dir = root .. "/rom",
      button = "ROM",
    }
  end
  return {
    title = "Load TI-83+ ROM",
    prompt = "Load TI-83 Plus ROM (.rom / .bin)",
    filter_win = "TI-83+ ROMs (*.rom;*.bin)|*.rom;*.ROM;*.bin;*.BIN",
    filter_zenity = "TI-83+ ROMs | *.rom *.bin",
    mac_types = '{"rom","bin","public.data"}',
    default_ext = "rom",
    default_dir = root .. "/rom",
    button = "ROM",
  }
end

function Ide:inject_button_specs()
  local id = self.machine_id or "ti83plus"
  local rom_label = self:rom_open_profile().button or "ROM"
  if id == "ti83plus" or id == "ti84plus" then
    return {
      { "load_rom", rom_label },
      { "load_app", ".8xk" },
      { "load_prgm", ".8xp" },
      { "load_grp", ".8xg" },
    }
  end
  -- Other machines: ROM/cart/firmware load only (no TI-83 var inject yet).
  return {
    { "load_rom", rom_label },
  }
end

--- Switch calculator chrome (keypad + layout metrics). Does not create the machine.
function Ide:set_machine_ui(id)
  if id ~= "ti83plus" and id ~= "ti84plus" and id ~= "ti89"
      and id ~= "ti92plus" and id ~= "riscv64" and id ~= "gameboy"
      and id ~= "nes" then
    return
  end
  if self.machine_id == id then
    return
  end
  self.machine_id = id
  self.keypad_ui = self:_make_keypad(id)
  if self.memmap then
    self.memmap:set_machine(id)
  end
  self.running = false
  if not self:tinyc_supported() then
    self.tab = "idle"
    self.tc_editor.focused = false
    self.asm_editor.focused = false
    if self.focus == "editor" or self.focus == "docs" then
      self.focus = "lcd"
    end
  elseif self.tab == "idle" then
    self.tab = "tc"
  end
  if love and love.graphics then
    self:layout(love.graphics.getDimensions())
  end
end

--- Current Tiny-C build target: "app" or "bare".
function Ide:build_target()
  if self.project and self.project.target == "app" then
    return "app"
  end
  return "bare"
end

function Ide:set_build_target(target)
  if not self.project then
    self:log_error("No project open")
    return
  end
  if target == "app" then
    self.project.target = "app"
    if not self.project.app_name or self.project.app_name == "" then
      local n = (self.project.name or "TINYAPP"):upper():gsub("[^A-Z0-9]", "")
      if #n > 8 then n = n:sub(1, 8) end
      if n == "" then n = "TINYAPP" end
      self.project.app_name = n
    end
    if self.project.sign == nil then
      self.project.sign = true
    end
    self:log("Target: Flash App (.8xk)  name=" .. tostring(self.project.app_name)
      .. (self.project.sign and "  sign=on" or "  sign=off"))
  else
    self.project.target = nil
    self:log("Target: Bare-metal ROM")
  end
  if self.project.dir then
    Tiproj.save_dir(self.project.dir, self.project)
    self:_remember_disk_sigs()
  end
end

function Ide:sign_enabled()
  if self:build_target() ~= "app" then return false end
  if self.project and self.project.sign == false then return false end
  return true
end

function Ide:set_sign_enabled(on)
  if not self.project then
    self:log_error("No project open")
    return
  end
  if self:build_target() ~= "app" then
    self:log_error("Sign only applies to Flash App target")
    return
  end
  self.project.sign = on and true or false
  self:log(on and "Sign: on (real calc / key 0104)" or "Sign: off (emulator only)")
  if self.project.dir then
    Tiproj.save_dir(self.project.dir, self.project)
    self:_remember_disk_sigs()
  end
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

local function read_file_raw(path)
  local f = io.open(path, "rb")
  if not f then return nil end
  local data = f:read("*a")
  f:close()
  return data
end

local function content_sig(data)
  if data == nil then return nil end
  -- cheap fingerprint: length + ends (enough for small .tc sources)
  local n = #data
  if n <= 96 then
    return tostring(n) .. ":" .. data
  end
  return string.format("%d:%s:%s", n, data:sub(1, 48), data:sub(-48))
end

--- Snapshot tiproj + all *.tc currently on disk in the project folder.
function Ide:_scan_project_disk()
  local dir = self.project and self.project.dir
  if not dir then return nil end
  local snap = { tiproj = nil, files = {} }
  local man_path = Tiproj.join(dir, "project.tiproj")
  snap.tiproj = content_sig(read_file_raw(man_path))
  -- Prefer tiproj listing; also pick up new files via reload helper.
  local tmp = { files = {}, dir = dir, entry = self.project.entry or "main.tc" }
  Tiproj.reload_from_dir(tmp, dir)
  for name, body in pairs(tmp.files or {}) do
    snap.files[name] = content_sig(body)
  end
  return snap, tmp.files
end

function Ide:_remember_disk_sigs()
  local snap = self:_scan_project_disk()
  self._disk_sigs = snap
end

local function sigs_differ(a, b)
  if a == nil or b == nil then return a ~= b end
  if a.tiproj ~= b.tiproj then return true end
  local keys = {}
  for k in pairs(a.files or {}) do keys[k] = true end
  for k in pairs(b.files or {}) do keys[k] = true end
  for k in pairs(keys) do
    if (a.files and a.files[k]) ~= (b.files and b.files[k]) then
      return true
    end
  end
  return false
end

--- Apply tiproj manifest fields from disk without dropping open buffers yet.
function Ide:_reload_tiproj_manifest()
  if not self.project or not self.project.dir then return false end
  local path = Tiproj.join(self.project.dir, "project.tiproj")
  local doc = Tiproj.load_file(path)
  if not doc then return false end
  self.project.name = doc.name or self.project.name
  self.project.entry = doc.entry or self.project.entry
  self.project.target = doc.target
  self.project.app_name = doc.app_name
  self.project.sign = doc.sign
  self.project.force_pages = doc.force_pages
  return true
end

--- Pull project.tiproj + *.tc from disk (disk wins). Used by watch + Build.
-- @param quiet if true, skip console log when nothing useful changed
function Ide:_reload_disk_sources(quiet)
  if not self.project or not self.project.dir then return false end
  local prev_open = self.open_file
  local prev_cy = self.tc_editor.cy
  local prev_cx = self.tc_editor.cx
  local before = self._disk_sigs
  local snap, files = self:_scan_project_disk()
  if not snap then return false end
  if before and not sigs_differ(before, snap) then
    return false
  end

  self:_reload_tiproj_manifest()
  self.project.files = files or {}
  Tiproj.reload_from_dir(self.project, self.project.dir)

  -- File tabs: keep open file if it still exists; else fall back to entry.
  if prev_open and self.project.files[prev_open] then
    self.open_file = prev_open
  else
    self.open_file = self.project.entry
  end
  if self.open_file and self.project.files[self.open_file] then
    self.tc_editor:set_text(self.project.files[self.open_file])
    self.tc_editor.dirty = false
    if prev_cy then
      self.tc_editor:goto_line(prev_cy, prev_cx or 1)
    end
  end

  self._disk_sigs = snap
  if not quiet then
    local n = 0
    for _ in pairs(self.project.files or {}) do n = n + 1 end
    self:log(string.format("Project reloaded from disk (%d .tc)", n))
  end
  return true
end

--- Poll for external edits (Cursor/AI/other editors). Call on focus + timer.
function Ide:poll_project_disk()
  if not self.project or not self.project.dir then return end
  local snap = self:_scan_project_disk()
  if not snap then return end
  if not self._disk_sigs then
    self._disk_sigs = snap
    return
  end
  if sigs_differ(self._disk_sigs, snap) then
    self:_reload_disk_sources(false)
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
  self:_remember_disk_sigs()
  local tgt = (doc.target == "app") and ("app/" .. tostring(doc.app_name or doc.name)) or "bare"
  self:log("Opened " .. (doc.dir or path) .. " (" .. doc.name .. ")  target=" .. tgt)
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

function Ide:studio_idle()
  return not self:tinyc_supported()
end

function Ide:layout(ww, wh)
  local m = ui_metrics()
  self.ui = m
  local TOOLBAR_H = m.toolbar_h
  local studio = self:tinyc_supported()
  local TAB_H = studio and m.tab_h or 0
  local FILE_TAB_H = m.file_tab_h
  local CONSOLE_H = m.console_h
  local font = m.font

  -- Left: editor + console (TI-83+/84+ Tiny-C studio only).
  -- Mid: calculator face. Right: memmap (user-draggable).
  local max_side = math.max(140, math.floor(ww * 0.55))
  local side_w = self.memmap:width()
  if side_w > max_side then
    self.memmap:set_expanded_width(max_side)
    side_w = self.memmap:width()
  end
  local avail = ww - side_w
  local split = studio and math.floor(avail * 0.55) or 0
  local mid_w = avail - split
  local file_h = (studio and self.tab == "tc" and self.project) and FILE_TAB_H or 0
  local console_h = studio and CONSOLE_H or 0
  local calc_h = wh - TOOLBAR_H -- calculator column ignores console

  self.toolbar = { x = 0, y = 0, w = ww, h = TOOLBAR_H }
  self.tabs = { x = 0, y = TOOLBAR_H, w = split, h = TAB_H }
  self.file_tabs = { x = 0, y = TOOLBAR_H + TAB_H, w = split, h = file_h }
  self.editor_rect = {
    x = 0,
    y = TOOLBAR_H + TAB_H + file_h,
    w = split,
    h = studio and (wh - TOOLBAR_H - TAB_H - file_h - console_h) or 0,
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
  self.memmap:layout(side_x, TOOLBAR_H, calc_h, max_side)
  -- Console sits only under the code window (left column).
  self.console_rect = {
    x = 0,
    y = wh - console_h,
    w = split,
    h = console_h,
  }
  local r = self.editor_rect
  if studio and r.w > 0 and r.h > 0 then
    self.tc_editor:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)
    self.asm_editor:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)
    self.docs:set_bounds(r.x + 4, r.y + 4, r.w - 8, r.h - 8)
  end

  local bh = m.btn_h
  local tgt = self:build_target()
  local export_label = (tgt == "app") and "Export .8xk" or "Export ROM"
  local groups = {}
  local all_btns = {}

  local function add_group(label, btn_y, label_y, start_x, specs)
    local bx = start_x
    local first_x = bx
    for _, spec in ipairs(specs) do
      local id, text, style = spec[1], spec[2], spec[3]
      local tw = font and font:getWidth(text) or (#text * 8)
      local w = math.max(40, math.ceil(tw + 16))
      local b = {
        id = id,
        label = text,
        x = bx,
        y = btn_y,
        w = w,
        h = bh,
        style = style, -- "seg" | "seg_on" | nil
      }
      all_btns[#all_btns + 1] = b
      bx = bx + w + BTN_GAP
    end
    local end_x = bx - BTN_GAP
    groups[#groups + 1] = {
      label = label,
      x = first_x,
      y = label_y,
      w = math.max(0, end_x - first_x),
    }
    return end_x + GROUP_GAP
  end

  -- Row 1: Tiny-C studio (TI-83+/84+ only) + shared inject / OS tooling
  local x1 = 10
  if studio then
    x1 = add_group("Project", m.row1_btn_y, m.row1_label_y, x1, {
      { "open", "Open" },
      { "save", "Save" },
    })
    local sign_on = self:sign_enabled()
    x1 = add_group("Target", m.row1_btn_y, m.row1_label_y, x1, {
      { "target_bare", "Bare", tgt == "bare" and "seg_on" or "seg" },
      { "target_app", "App", tgt == "app" and "seg_on" or "seg" },
      { "sign", "Sign", tgt ~= "app" and "disabled" or (sign_on and "seg_on" or "seg") },
    })
    local can_inject = self:_has_built_xk()
    x1 = add_group("Build", m.row1_btn_y, m.row1_label_y, x1, {
      { "build", "Build" },
      { "export", export_label },
      { "inject_xk", "Inject .8xk", (not can_inject) and "disabled" or nil },
    })
  end
  local editor_end = x1

  -- Row 2: inject into running machine (+ TI-83/84 OS tooling)
  local x2 = 10
  x2 = add_group("Inject", m.row2_btn_y, m.row2_label_y, x2, self:inject_button_specs())
  if studio then
    x2 = add_group("OS", m.row2_btn_y, m.row2_label_y, x2, {
      { "os", "Boot OS" },
      { "load_p0", "Load P0" },
    })
  end

  -- Calculator column (right): home to launcher + run controls on row 1
  local calc_x = self.calc_rect.x + 8
  local mid = self.machine_id or "ti83plus"
  calc_x = add_group("Machine", m.row1_btn_y, m.row1_label_y, calc_x, {
    { "home", "Home" },
    { "mach_label", mid, "disabled" },
  })
  calc_x = add_group("Run", m.row1_btn_y, m.row1_label_y, calc_x, {
    { "play", self.running and "Pause" or "Play" },
    { "step", "Step" },
    { "reset", "Reset" },
    { "mem", self.memmap.open and "Mem >" or "Mem <" },
    { "panel", "Panel" },
  })
  local calc_end = calc_x

  self.toolbar_groups = groups
  self.buttons = all_btns
  self.editor_buttons = all_btns
  self.calc_buttons = {}

  -- Main tabs sized to labels (Tiny-C studio only)
  local tx = 8
  local function mtab(id, label)
    local tw = font and font:getWidth(label) or 56
    local w = math.ceil(tw + 20)
    local t = { id = id, label = label, x = tx, w = w }
    tx = tx + w + 4
    return t
  end
  if studio then
    self.tab_hits = {
      mtab("tab_tc", "Tiny-C"),
      mtab("tab_asm", "ASM"),
      mtab("tab_docs", "Stdlib"),
    }
  else
    self.tab_hits = {}
  end

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

  -- Gate controls on row 2 of the calculator column.
  local check = math.max(14, math.floor(m.fh * 0.95))
  local gate_w = font and font:getWidth("Gate") or 32
  local field_w = math.max(56, (font and font:getWidth("0000000") or 56) + 16)
  local field_h = math.max(22, m.fh + 8)
  local hz_w = font and font:getWidth("Hz") or 16
  local gate_block = check + 6 + gate_w + 8 + field_w + 6 + hz_w
  local gx = self.calc_rect.x + 8
  local max_end = ww - 8
  if gx + gate_block > max_end then
    gx = math.max(self.calc_rect.x + 8, max_end - gate_block)
  end
  -- Prefer sitting after Run group when there is room.
  if calc_end + gate_block + 8 <= max_end then
    gx = calc_end
  end
  self.gate_check = {
    x = gx,
    y = m.row2_btn_y + math.floor((bh - check) / 2),
    w = check,
    h = check,
  }
  gx = gx + check + 6
  self.gate_label_x = gx
  gx = gx + gate_w + 8
  self.gate_field = {
    x = gx,
    y = m.row2_btn_y + math.floor((bh - field_h) / 2),
    w = field_w,
    h = field_h,
  }
  gx = gx + field_w + 6
  self.gate_hz_label_x = gx
  self.gate_end_x = gx + hz_w
  self.gate_text_y = m.row2_btn_y + math.floor((bh - m.fh) / 2)

  -- Status on row 1: after Build (studio) or after Machine/Run (emulator-only).
  if studio then
    self.status_x = editor_end + STATUS_GAP
    self.status_max_x = math.min(self.calc_rect.x - 8, ww - 8)
  else
    self.status_x = calc_end + STATUS_GAP
    self.status_max_x = (self.side_rect and self.side_rect.x or ww) - 8
  end
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
  self.gate_hz_sel_all = false
end

--- Run emulator for one frame. Returns cycles (approx) consumed.
function Ide:run_emu(dt, machine, on_present)
  if self.panel_editor or not machine.rom_loaded or not self.running then
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

  -- Realtime: match the active machine's CPU clock (6/15 MHz Z80, ~16 MHz 89).
  local hz = machine._cpu_hz or machine.CPU_HZ or MachineMod.CPU_HZ
  if dt < 0 then dt = 0 end
  if dt > 0.1 then dt = 0.1 end -- avoid huge catch-up after a hitch
  self.cycle_accum = self.cycle_accum + hz * dt
  local budget = math.floor(self.cycle_accum)
  if budget <= 0 then
    return 0
  end
  -- Cap catch-up to the same 100ms window as dt (not 50ms). A 50ms cap with
  -- ~12 FPS makes the speed meter top out around 60% even when ungated.
  local max_budget = math.floor(hz * 0.1)
  if budget > max_budget then
    budget = max_budget
    self.cycle_accum = 0
  else
    self.cycle_accum = self.cycle_accum - budget
  end
  local ran = 0
  while ran < budget do
    local chunk = budget - ran
    if chunk > 65536 then chunk = 65536 end
    local got = machine:run_cycles(chunk)
    if not got or got <= 0 then
      -- Halted / idle: do not spin forever waiting to fill the budget.
      break
    end
    ran = ran + got
  end
  return ran
end

function Ide:hit_button(mx, my)
  local gid = self:hit_gate(mx, my)
  if gid then return gid end
  for _, b in ipairs(self.buttons) do
    if b.style ~= "disabled"
        and mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h then
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

--- Soft power-off HALT then hold ON to wake TI-OS (stops early at homescreen VAT).
function Ide:_wake_os(machine)
  if machine.cpu.halted then
    self:log("OS at power-off HALT - holding ON to wake ...")
  end
  machine:wake_os({ slice = 1000000 })
  -- Do NOT CloseEditBuf here: boot leaves editOpen over the free-RAM gap so
  -- the homescreen entry line can grow. Releasing it causes ERR:MEMORY on
  -- Enter. .8xp inject calls Eightxp.release_homescreen_edit itself.
  local nz = 0
  local fb = machine:framebuffer()
  for i = 0, 12 * 64 - 1 do
    if (fb[i] or 0) ~= 0 then nz = nz + 1 end
  end
  return nz
end

--- Load real TI-83+ flash dump and start the calculator OS.
-- Prefers the last Build that spliced page 0 into the stock ROM.
function Ide:boot_os(machine, on_loaded)
  local ok, err
  local label
  if self.last_built_rom and self.last_built_os and #self.last_built_rom == 512 * 1024 then
    label = "last Build (page0 splice)"
    self:log("Booting TI-83+ OS from " .. label .. " ...")
    ok, err = machine:load_rom_bytes(self.last_built_rom)
  else
    local path = self.root .. "/rom/ti83plus.rom"
    label = path
    self:log("Booting TI-83+ OS from " .. path .. " ...")
    ok, err = machine:load_rom_file(path)
  end
  if not ok then
    self:log_error("OS BOOT FAIL: " .. tostring(err))
    return false
  end
  machine:reset()
  self.running = true
  self.focus = "lcd"
  self.tc_editor.focused = false
  self.asm_editor.focused = false
  local nz = self:_wake_os(machine)
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  self:log(string.format(
    "OS running  PC=%04X  display=%s  fb_nz=%d  (%s)",
    machine:pc(), tostring(machine:is_display_on()), nz, label
  ))
  if on_loaded then on_loaded() end
  return true
end

--- Load page-0 disassembly into the ASM editor (paste-ready for Build).
function Ide:load_page0_disasm()
  local path = self.root .. "/rom/ti83plus_p0_dis.asm"
  local f = io.open(path, "r")
  if not f then
    self:log_error("LOAD P0 FAIL: missing " .. path .. " - run: lua tools/reasm_ti_page0.lua")
    return false
  end
  local src = f:read("*a")
  f:close()
  self.tab = "asm"
  self.asm_editor:set_text(src)
  self.asm_editor.focused = true
  self.tc_editor.focused = false
  self:log(string.format("Loaded page0 disasm (%d chars, %d lines) - Build to assemble+boot",
    #src, #self.asm_editor.lines))
  return true
end

function Ide:build(machine, on_loaded)
  local mode = (self.tab == "asm") and "asm" or "tc"
  self:log("Building (" .. mode .. ")...")
  local rom, err, asm, result, info
  if mode == "tc" then
    -- Disk wins (AI/external edits). Unsaved IDE buffer is discarded if disk changed.
    self:_reload_disk_sources(true)
    self:_sync_editor_to_project()
    if self.project and self.project.dir then
      Tiproj.save_dir(self.project.dir, self.project)
      self:_remember_disk_sigs()
    end
    local entry = self.project and self.project.entry or "main.tc"
    local src = self.project and self.project.files[entry] or self.tc_editor:get_text()
    local opts = Tiproj.compile_opts(self.project or { entry = entry, files = {} }, self.root)
    opts.root = self.root
    opts.files = self.project and self.project.files or opts.files
    opts.entry = entry
    -- Honor explicit Bare/App target toggle from the toolbar.
    if self:build_target() == "app" then
      opts.target = "app"
      opts.app_name = opts.app_name
        or (self.project and self.project.app_name)
        or (self.project and self.project.name)
        or "TINYAPP"
      -- Honor Sign toolbar / tiproj.sign (default on for App).
      if self.project and self.project.sign == false then
        opts.sign = false
      else
        opts.sign = true
      end
    else
      opts.target = "bare"
      opts.app = nil
    end
    rom, err, asm, result, info = BuildSvc.build_tc(self.root, src, opts)
    if asm then
      self.asm_editor:set_text(asm)
      self:log("Tiny-C -> ASM ok (" .. #asm .. " chars)")
    end
  else
    rom, err, result, info = BuildSvc.build_asm(self.root, self.asm_editor:get_text())
  end
  if not rom then
    self:log_error("BUILD FAIL: " .. tostring(err))
    self:_goto_error(err)
    return false
  end

  -- Flash App .8xk: write file, inject into stock ROM, reset+wake (APPS menu).
  if info and info.app then
    local proj = self.project and self.project.name or "app"
    local app_name = info.name or proj
    local xk_path = self.root .. "/dist/" .. tostring(app_name) .. ".8xk"
    do
      local dist = (self.root .. "/dist"):gsub("/", "\\")
      if package.config:sub(1, 1) == "\\" then
        os.execute(string.format('mkdir "%s" 2>nul', dist))
      else
        os.execute(string.format('mkdir - p "%s/dist"', self.root))
      end
      local wf = assert(io.open(xk_path, "wb"))
      wf:write(rom)
      wf:close()
    end
    local base = assert(io.open(self.root .. "/rom/ti83plus.rom", "rb"))
    local base_bytes = base:read("*a")
    base:close()
    local Eightxk = require("machines.ti83plus.util.eightxk")
    local injected, imeta = Eightxk.inject(base_bytes, rom)
    if not injected then
      self:log_error("APP INJECT FAIL: " .. tostring(imeta))
      return false
    end
    local path = BuildSvc.write_rom(self.root, injected)
    self.last_built_xk = rom
    self.last_built_xk_name = app_name .. ".8xk"
    self.last_built_rom = injected
    self.last_built_os = true
    self.last_built_name = app_name .. ".8xk"
    local ok, load_err = machine:load_rom_bytes(injected)
    if not ok then
      ok, load_err = machine:load_rom_file(path)
    end
    if not ok then
      self:log_error("LOAD FAIL: " .. tostring(load_err))
      return false
    end
    machine:reset()
    self.running = true
    self.tc_editor.dirty = false
    self.asm_editor.dirty = false
    self.focus = "lcd"
    self.tc_editor.focused = false
    self.asm_editor.focused = false
    local nz = self:_wake_os(machine)
    local page = imeta and imeta.placed and imeta.placed[1] and imeta.placed[1].physical
    local code = info.code_bytes or info.size or 0
    local pages = info.n_pages or 1
    local page_sz = info.page_bytes or 16384
    self:log(string.format(
      "Build OK (Flash App %s%s) - %d bytes code across %d page%s (%d bytes/page) -> %s  injected page %s  display=%s fb_nz=%d  APPS menu",
      app_name, (info.signed and ", signed 0104" or ", unsigned"),
      code, pages, pages == 1 and "" or "s", page_sz,
      xk_path, page and string.format("%02X", page) or "?",
      tostring(machine:is_display_on()), nz
    ))
    if on_loaded then on_loaded(true) end
    return true
  end

  local path = BuildSvc.write_rom(self.root, rom)
  self.last_built_rom = rom
  self.last_built_os = info and info.spliced or false
  local proj = self.project and self.project.name
  if self.last_built_os then
    BuildSvc.write_os_rom(self.root, rom)
    self.last_built_name = "ti83plus_reasm.rom"
  else
    self.last_built_name = (proj and (proj .. ".rom")) or "pipeline.rom"
  end
  local ok, load_err = machine:load_rom_bytes(rom)
  if not ok then
    ok, load_err = machine:load_rom_file(path)
  end
  if not ok then
    self:log_error("LOAD FAIL: " .. tostring(load_err))
    return false
  end
  machine:reset()
  self.running = true
  self.tc_editor.dirty = false
  self.asm_editor.dirty = false
  if self.last_built_os then
    self.focus = "lcd"
    self.tc_editor.focused = false
    self.asm_editor.focused = false
    local nz = self:_wake_os(machine)
    self:log(string.format(
      "Build OK (TI page0 splice) -> %s  PC=%04X  display=%s  fb_nz=%d",
      path, machine:pc(), tostring(machine:is_display_on()), nz
    ))
  else
    machine:run_cycles(800000)
    local code = (info and (info.code_bytes or info.size))
      or (result and result.size) or 0
    self:log(string.format(
      "Build OK -> %s  %d bytes code  PC=%04X  (Export to save a copy)",
      path, code, machine:pc()
    ))
  end
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  if on_loaded then on_loaded() end
  return true
end

--- Load a machine ROM / cart / firmware (does not compile).
function Ide:load_rom(machine, on_loaded)
  local profile = self:rom_open_profile()
  local path = Dialog.choose_open_rom(profile)
  if not path then
    self:log("Load ROM cancelled")
    return false
  end
  self:log("Loading " .. path .. " ...")
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
  local mid = self.machine_id or "ti83plus"
  if mid == "gameboy" then
    local title = machine.cart and machine.cart.title or ""
    local sav = ""
    if machine.rom_data and machine.rom_data.loaded and machine.save_path then
      sav = "  save=" .. tostring(machine.save_path)
    elseif machine.cart and machine.cart.has_save_ram and machine.cart:has_save_ram()
        and machine.save_path then
      sav = "  save->" .. tostring(machine.save_path)
    end
    self:log(string.format(
      "Cart loaded  %s%s%s",
      base, (title ~= "" and (" (" .. title .. ")") or ""), sav
    ))
  elseif mid == "nes" then
    local mapper = machine.cart and machine.cart.mapper
    self:log(string.format(
      "NES cart loaded  %s%s",
      base, mapper and (" (mapper " .. tostring(mapper) .. ")") or ""
    ))
  elseif mid == "riscv64" then
    self:log(string.format("Firmware loaded  %s  PC=%X", base, machine:pc()))
  elseif mid == "ti89" or mid == "ti92plus" then
    self:log(string.format("ROM loaded  %s  PC=$%06X", base, machine:pc()))
  else
    self:log(string.format(
      "ROM loaded  %s  PC=%04X  (Play to run; Space=ON for TI-OS)",
      base, machine:pc()
    ))
  end
  if on_loaded then on_loaded() end
  return true
end

local function read_file_bytes(path)
  local f, err = io.open(path, "rb")
  if not f then
    return nil, err
  end
  local data = f:read("*a")
  f:close()
  if not data or data == "" then
    return nil, "empty file"
  end
  return data
end

function Ide:_has_built_xk()
  local bytes = self.last_built_xk
  if type(bytes) == "string" and #bytes >= 80 and bytes:sub(1, 8) == "**TIFL**" then
    return true
  end
  local path = self:_built_xk_fallback_path()
  if not path then return false end
  local f = io.open(path, "rb")
  if not f then return false end
  local magic = f:read(8)
  f:close()
  return magic == "**TIFL**"
end

function Ide:_built_xk_fallback_path()
  local name = self.last_built_xk_name
  if not name then
    local n = (self.project and (self.project.app_name or self.project.name)) or nil
    if not n then return nil end
    n = tostring(n):upper():gsub("[^A-Z0-9]", "")
    if n == "" then return nil end
    if #n > 8 then n = n:sub(1, 8) end
    name = n .. ".8xk"
  end
  return self.root .. "/dist/" .. name
end

--- Shared live-archive inject path used by file picker and Build -> Inject .8xk.
function Ide:_inject_xk_bytes(machine, data, label, on_loaded)
  if not machine.rom_loaded then
    self:log_error("INJECT APP: Boot OS (or Load ROM) first")
    return false
  end
  if type(data) ~= "string" or #data < 80 or data:sub(1, 8) ~= "**TIFL**" then
    self:log_error("INJECT APP FAIL: not a .8xk (missing TIFL header)")
    return false
  end
  label = label or "app"
  self:log("Installing Flash App " .. label .. " ...")
  local meta, aerr = Eightxk.inject_flash(machine.mmu.flash.bytes, data)
  if not meta then
    self:log_error("INJECT APP FAIL: " .. tostring(aerr))
    return false
  end
  machine:reset()
  self.running = true
  self.focus = "lcd"
  self.tc_editor.focused = false
  self.asm_editor.focused = false
  local nz = self:_wake_os(machine)
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  local pages = {}
  for _, p in ipairs(meta.placed or {}) do
    pages[#pages + 1] = string.format("%02X", p.physical)
  end
  self:log(string.format(
    "App %s installed -> page %s  (reset)  display=%s fb_nz=%d  APPS menu",
    meta.name or label, table.concat(pages, ","),
    tostring(machine:is_display_on()), nz
  ))
  if on_loaded then on_loaded() end
  return true
end

--- Inject a .8xk Flash App into live archive, then reset so OS rescans APPS.
function Ide:load_app(machine, on_loaded)
  if not machine.rom_loaded then
    self:log_error("LOAD APP: Boot OS (or Load ROM) first")
    return false
  end
  local path = Dialog.choose_open_8x("app", self.root .. "/rom")
  if not path then
    self:log("Load App cancelled")
    return false
  end
  local data, err = read_file_bytes(path)
  if not data then
    self:log_error("LOAD APP FAIL: " .. tostring(err))
    return false
  end
  local base = path:match("([^/\\]+)$") or path
  return self:_inject_xk_bytes(machine, data, base, on_loaded)
end

--- Inject the project's last built .8xk (same path as Inject .8xk file picker).
function Ide:inject_built_app(machine, on_loaded)
  local data = self.last_built_xk
  local label = self.last_built_xk_name or "built.8xk"
  if type(data) ~= "string" or #data < 80 or data:sub(1, 8) ~= "**TIFL**" then
    local path = self:_built_xk_fallback_path()
    if path then
      local bytes, err = read_file_bytes(path)
      if bytes then
        data = bytes
        label = path:match("([^/\\]+)$") or path
        self.last_built_xk = bytes
        self.last_built_xk_name = label
      else
        self:log_error("INJECT FAIL: Build an App first (" .. tostring(err) .. ")")
        return false
      end
    else
      self:log_error("INJECT FAIL: Build an App first")
      return false
    end
  end
  return self:_inject_xk_bytes(machine, data, label, on_loaded)
end

--- Inject .8xp / .8xg into live RAM/VAT (homescreen must be up).
function Ide:load_ti_var(machine, kind, on_loaded)
  kind = kind or "prog"
  if not machine.rom_loaded then
    self:log_error("LOAD " .. kind:upper() .. ": Boot OS first")
    return false
  end
  if not Eightxp.vat_ready(machine.mmu) then
    self:log_error("LOAD " .. kind:upper() .. ": VAT not ready - Boot OS and wait for homescreen, then retry")
    return false
  end
  local default_dir = (kind == "group")
      and (self.root .. "/rom/games")
      or (self.root .. "/rom/basic_tests")
  local path = Dialog.choose_open_8x(kind, default_dir)
  if not path then
    self:log(string.format("Load %s cancelled", kind == "group" and "GRP" or "PRGM"))
    return false
  end
  local data, err = read_file_bytes(path)
  if not data then
    self:log_error("LOAD FAIL: " .. tostring(err))
    return false
  end
  local base = path:match("([^/\\]+)$") or path
  self:log(string.format("Injecting %s %s ...", kind, base))
  local metas, ierr = Eightxp.inject_file(machine.mmu, data, { iy = machine.cpu.iy })
  if not metas then
    self:log_error("LOAD FAIL: " .. tostring(ierr))
    return false
  end
  machine.lcd._dirty = true
  if self.memmap.open then
    self.memmap:refresh(machine)
  end
  self.focus = "lcd"
  self.tc_editor.focused = false
  self.asm_editor.focused = false
  if metas.blackjack_setup then
    self:log("Blackjack ready: PRGM -> BLACKJ83 (setup lists preloaded)")
  elseif #metas == 1 then
    local meta = metas[1]
    self:log(string.format(
      "Loaded %s -> %04X (%d bytes)  PRGM menu",
      meta.name or base, meta.data_addr, meta.data_len
    ))
  else
    local names = {}
    for _, meta in ipairs(metas) do
      names[#names + 1] = meta.name
    end
    self:log(string.format(
      "Ungrouped %d vars: %s  (PRGM menu)",
      #metas, table.concat(names, ", ")
    ))
  end
  if on_loaded then on_loaded() end
  return true
end

function Ide:load_prgm(machine, on_loaded)
  return self:load_ti_var(machine, "prog", on_loaded)
end

function Ide:load_grp(machine, on_loaded)
  return self:load_ti_var(machine, "group", on_loaded)
end

--- Write the latest Build ROM (512KB) to a user-chosen path.
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
    self:log_error("EXPORT FAIL: nothing to export - Build a bare-metal ROM first")
    return false
  end
  local default_name = self.last_built_name or "pipeline.rom"
  if default_name:match("%.8[xX][kK]$") then
    default_name = "pipeline.rom"
  end
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

--- Write the latest Flash App .8xk to a user-chosen path.
function Ide:export_app()
  local bytes = self.last_built_xk
  local default_name = self.last_built_xk_name
  if not bytes then
    local name = (self.project and (self.project.app_name or self.project.name)) or "app"
    name = tostring(name):upper():gsub("[^A-Z0-9]", "")
    if name == "" then name = "APP" end
    if #name > 8 then name = name:sub(1, 8) end
    local fallback = self.root .. "/dist/" .. name .. ".8xk"
    local f = io.open(fallback, "rb")
    if f then
      bytes = f:read("*a")
      f:close()
      default_name = name .. ".8xk"
      self:log("Exporting " .. fallback .. " (no in-session App Build yet)")
    end
  end
  if not bytes or #bytes < 80 or bytes:sub(1, 8) ~= "**TIFL**" then
    self:log_error("EXPORT FAIL: nothing to export - Build a Flash App first")
    return false
  end
  default_name = default_name or "app.8xk"
  local path = Dialog.choose_save_8xk(default_name)
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
  self:log(string.format("Exported Flash App (%d bytes) -> %s", #bytes, path))
  return true
end

--- Export based on current Bare / App target.
function Ide:export_current()
  if self:build_target() == "app" then
    return self:export_app()
  end
  return self:export_rom()
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
  self:_remember_disk_sigs()
  self:log("Saved " .. self.project_dir .. "/*.tc")
end

function Ide:open()
  local path = Dialog.choose_open_tiproj(self.root .. "/projects")
  if not path then
    self:log("Open cancelled")
    return
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
  if self.panel_editor then
    return self.panel_editor:mousepressed(mx, my, 1)
  end
  if self.focus == "gate_hz" and self:hit_gate(mx, my) ~= "gate_hz" then
    self:apply_gate_hz_text()
  end

  do
    local lr = self.lcd_rect
    local on_lcd = lr and lr.w > 0
      and mx >= lr.x and my >= lr.y and mx < lr.x + lr.w and my < lr.y + lr.h
    -- LCD is drawn above the keypad; clicks on the screen must not hit keys under it.
    if not on_lcd then
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
  end

  do
    local handled, action = self.memmap:mousepressed(mx, my)
    if handled then
      self.focus = "mem"
      if action == "toggle" then
        self:layout(love.graphics.getDimensions())
        if self.memmap.open then
          self.memmap:refresh(machine)
        end
        self:log(self.memmap.open and "Memory map open" or "Memory map closed")
      end
      return true
    end
  end

  local id = self:hit_button(mx, my)
  if id == "build" then
    self:build(machine, on_loaded)
    return true
  elseif id == "target_bare" then
    self:set_build_target("bare")
    return true
  elseif id == "target_app" then
    self:set_build_target("app")
    return true
  elseif id == "sign" then
    if self:build_target() == "app" then
      self:set_sign_enabled(not self:sign_enabled())
    end
    return true
  elseif id == "export" or id == "export_rom" then
    self:export_current()
    return true
  elseif id == "inject_xk" then
    self:inject_built_app(machine, on_loaded)
    return true
  elseif id == "os" then
    self:boot_os(machine, on_loaded)
    return true
  elseif id == "load_p0" then
    self:load_page0_disasm()
    return true
  elseif id == "load_rom" then
    self:load_rom(machine, on_loaded)
    return true
  elseif id == "load_app" then
    self:load_app(machine, on_loaded)
    return true
  elseif id == "load_prgm" then
    self:load_prgm(machine, on_loaded)
    return true
  elseif id == "load_grp" then
    self:load_grp(machine, on_loaded)
    return true
  elseif id == "home" then
    if self.on_home then
      self.on_home()
    end
    return true
  elseif id == "mach_label" then
    return true
  elseif id == "panel" then
    if self.machine_id == "riscv64" then
      self:log("RV64 has no keypad panel (console LCD only)")
      return true
    end
    if self.machine_id == "gameboy" or self.machine_id == "nes" then
      self:log("This machine uses a fixed on-screen pad (no panel editor)")
      return true
    end
    self:open_panel_editor()
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
    self:layout(love.graphics.getDimensions())
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
      or "Gate OFF  (realtime)")
    return true
  elseif id == "gate_hz" then
    self.focus = "gate_hz"
    self.gate_hz_sel_all = false
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

  if not self:studio_idle() then
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
  if self.panel_editor then
    return self.panel_editor:mousemoved(mx, my)
  end
  local _, mem_action = self.memmap:mousemoved(mx, my, machine)
  if mem_action == "resize" or self.memmap.dragging then
    local ww, wh = love.graphics.getDimensions()
    self:layout(ww, wh)
    if self.memmap.open and self.memmap.needs_refresh then
      self.memmap:refresh(machine)
    end
    return true
  end
  do
    local lr = self.lcd_rect
    local on_lcd = lr and lr.w > 0
      and mx >= lr.x and my >= lr.y and mx < lr.x + lr.w and my < lr.y + lr.h
    if on_lcd then
      -- Clear key hover when the pointer is over the screen stack.
      self.keypad_ui:mousemoved(-1, -1)
    else
      self.keypad_ui:mousemoved(mx, my)
    end
  end
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
  if self.panel_editor then
    local mx, my = love.mouse.getPosition()
    return self.panel_editor:mousereleased(mx, my, 1)
  end
  do
    local handled, action = self.memmap:mousereleased()
    if handled then
      local ww, wh = love.graphics.getDimensions()
      self:layout(ww, wh)
      if action == "toggle" then
        if self.memmap.open then
          self.memmap:refresh(machine)
        end
        self:log(self.memmap.open and "Memory map open" or "Memory map closed")
      elseif self.memmap.open and self.memmap.needs_refresh then
        self.memmap:refresh(machine)
      end
      -- fall through so keypad/editor release still runs
    end
  end
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
  if self.panel_editor then
    return self.panel_editor:keypressed(key)
  end
  if self.focus == "gate_hz" then
    local ctrl = love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui")
    if ctrl and key == "a" then
      self.gate_hz_sel_all = self.gate_hz_text ~= ""
      return true
    elseif ctrl and key == "c" then
      if self.gate_hz_text ~= "" then love.system.setClipboardText(self.gate_hz_text) end
      return true
    elseif ctrl and key == "x" then
      if self.gate_hz_text ~= "" then
        love.system.setClipboardText(self.gate_hz_text)
        self.gate_hz_text = ""
        self.gate_hz_sel_all = false
      end
      return true
    elseif ctrl and key == "v" then
      local clip = (love.system.getClipboardText() or ""):gsub("%D", "")
      if clip ~= "" then
        if self.gate_hz_sel_all or self.gate_hz_text == "" then
          self.gate_hz_text = clip:sub(1, 7)
        else
          self.gate_hz_text = (self.gate_hz_text .. clip):sub(1, 7)
        end
        self.gate_hz_sel_all = false
      end
      return true
    elseif key == "return" or key == "kpenter" or key == "escape" then
      self:apply_gate_hz_text()
      self.focus = "editor"
      self.gate_hz_sel_all = false
      return true
    elseif key == "backspace" or key == "delete" then
      if self.gate_hz_sel_all then
        self.gate_hz_text = ""
        self.gate_hz_sel_all = false
      elseif key == "backspace" then
        self.gate_hz_text = self.gate_hz_text:sub(1, -2)
      end
      return true
    end
    return true
  end

  local ctrl = love.keyboard.isDown("lctrl") or love.keyboard.isDown("rctrl")
      or love.keyboard.isDown("lgui") or love.keyboard.isDown("rgui")
  local shift = love.keyboard.isDown("lshift") or love.keyboard.isDown("rshift")

  if key == "f5" then
    if self:tinyc_supported() then
      self:build(machine, on_loaded)
    end
    return true
  elseif key == "f6" then
    self:toggle_play()
    return true
  elseif key == "f7" then
    self.memmap:toggle_open()
    self:layout(love.graphics.getDimensions())
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
    if self:tinyc_supported() then
      self:export_current()
    end
    return true
  elseif ctrl and key == "s" then
    if self:tinyc_supported() then
      self:save()
    end
    return true
  elseif ctrl and key == "o" then
    if shift then
      self:load_rom(machine, on_loaded)
    elseif self:tinyc_supported() then
      self:open()
    end
    return true
  elseif ctrl and key == "e" then
    if self:tinyc_supported() then
      self:export_current()
    end
    return true
  elseif ctrl and key == "b" then
    if self:tinyc_supported() then
      self:build(machine, on_loaded)
    end
    return true
  elseif ctrl and key == "t" then
    if self:tinyc_supported() then
      self:set_build_target(self:build_target() == "app" and "bare" or "app")
    end
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

  if self.focus == "editor" and not self:is_docs() and not self:studio_idle() then
    return self:active_editor():keypressed(key)
  end
  return false
end

function Ide:textinput(t)
  if self.panel_editor then
    self.panel_editor:textinput(t)
    return
  end
  if self.focus == "gate_hz" then
    if love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui") then return end
    if t:match("^%d$") then
      if self.gate_hz_sel_all then
        self.gate_hz_text = t
        self.gate_hz_sel_all = false
      elseif #self.gate_hz_text < 7 then
        self.gate_hz_text = self.gate_hz_text .. t
      end
    end
    return
  end
  if self.focus == "editor" and not self:is_docs() and not self:studio_idle() then
    self:active_editor():textinput(t)
  end
end

function Ide:wheelmoved(x, y)
  if self.panel_editor then
    return self.panel_editor:wheelmoved(x, y)
  end
  if self:studio_idle() then
    return false
  end
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
  if self.panel_editor then
    self.panel_editor:update(dt)
    return
  end
  if not self:is_docs() and not self:studio_idle() then
    self:active_editor():update(dt)
  end
  self._disk_poll_t = (self._disk_poll_t or 0) + dt
  if self._disk_poll_t >= 0.4 then
    self._disk_poll_t = 0
    if self:tinyc_supported() then
      self:poll_project_disk()
    end
  end
  self.memmap:update(dt, machine)
  local tgt = self:build_target()
  local can_inject = self:_has_built_xk()
  local studio = self:tinyc_supported()
  for _, b in ipairs(self.buttons) do
    if b.id == "play" then
      b.label = self.running and "Pause" or "Play"
    elseif b.id == "mem" then
      b.label = self.memmap.open and "Mem >" or "Mem <"
    elseif studio and b.id == "export" then
      b.label = (tgt == "app") and "Export .8xk" or "Export ROM"
    elseif studio and b.id == "inject_xk" then
      b.style = can_inject and nil or "disabled"
    elseif studio and b.id == "target_bare" then
      b.style = (tgt == "bare") and "seg_on" or "seg"
    elseif studio and b.id == "target_app" then
      b.style = (tgt == "app") and "seg_on" or "seg"
    elseif studio and b.id == "sign" then
      if tgt ~= "app" then
        b.style = "disabled"
      else
        b.style = self:sign_enabled() and "seg_on" or "seg"
      end
    end
  end
end

local function draw_btn(b, hot, font, fh)
  local style = b.style
  if style == "disabled" then
    love.graphics.setColor(0.17, 0.18, 0.17, 1)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
    love.graphics.setColor(0.38, 0.40, 0.38, 1)
  elseif style == "seg_on" then
    love.graphics.setColor(hot and 0.38 or 0.30, hot and 0.48 or 0.40, hot and 0.32 or 0.26, 1)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
    love.graphics.setColor(0.55, 0.65, 0.35, 1)
    love.graphics.rectangle("line", b.x + 0.5, b.y + 0.5, b.w - 1, b.h - 1, 4, 4)
    love.graphics.setColor(0.95, 0.96, 0.85, 1)
  elseif style == "seg" then
    love.graphics.setColor(hot and 0.26 or 0.18, hot and 0.28 or 0.20, hot and 0.26 or 0.20, 1)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
    love.graphics.setColor(0.35, 0.40, 0.35, 1)
    love.graphics.rectangle("line", b.x + 0.5, b.y + 0.5, b.w - 1, b.h - 1, 4, 4)
    love.graphics.setColor(0.85, 0.88, 0.82, 1)
  else
    love.graphics.setColor(hot and 0.32 or 0.22, hot and 0.38 or 0.26, hot and 0.34 or 0.24, 1)
    love.graphics.rectangle("fill", b.x, b.y, b.w, b.h, 4, 4)
    love.graphics.setColor(0.85, 0.88, 0.82, 1)
  end
  local tw = font:getWidth(b.label)
  love.graphics.print(b.label, b.x + (b.w - tw) / 2, b.y + (b.h - fh) / 2)
end

function Ide:draw()
  if self.panel_editor then
    local ww, wh = love.graphics.getDimensions()
    self.panel_editor:layout(ww, wh)
    self.panel_editor:draw()
    return
  end
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

  -- Group captions + light separators between clusters.
  for i, g in ipairs(self.toolbar_groups or {}) do
    love.graphics.setColor(0.45, 0.50, 0.45, 1)
    love.graphics.print(g.label, g.x, g.y)
    if i > 1 then
      local prev = self.toolbar_groups[i - 1]
      -- Only draw a divider when groups share a row (same label y).
      if prev and prev.y == g.y and g.x > prev.x + prev.w + 4 then
        local dx = math.floor((prev.x + prev.w + g.x) / 2)
        love.graphics.setColor(0.28, 0.30, 0.28, 1)
        love.graphics.line(dx, g.y, dx, g.y + (m.row_h or 28) - 2)
      end
    end
  end

  local mx, my = love.mouse.getPosition()
  for _, b in ipairs(self.buttons) do
    local hot = mx >= b.x and my >= b.y and mx < b.x + b.w and my < b.y + b.h
    draw_btn(b, hot, font, fh)
  end

  -- Gate checkbox + Hz number field (high-contrast so it reads as an input).
  local gc = self.gate_check
  love.graphics.setColor(0.28, 0.30, 0.28, 1)
  love.graphics.rectangle("fill", gc.x, gc.y, gc.w, gc.h, 2, 2)
  love.graphics.setColor(0.75, 0.82, 0.70, 1)
  love.graphics.rectangle("line", gc.x + 0.5, gc.y + 0.5, gc.w - 1, gc.h - 1, 2, 2)
  if self.gate_active then
    love.graphics.setColor(0.95, 0.85, 0.25, 1)
    love.graphics.rectangle("fill", gc.x + 3, gc.y + 3, gc.w - 6, gc.h - 6, 1, 1)
  end
  local text_y = self.gate_text_y or math.floor((TOOLBAR_H - fh) / 2)
  love.graphics.setColor(self.gate_active and 0.98 or 0.82, self.gate_active and 0.92 or 0.85, 0.55, 1)
  love.graphics.print("Gate", self.gate_label_x, text_y)
  local gf = self.gate_field
  local field_hot = self.focus == "gate_hz"
  if field_hot then
    love.graphics.setColor(1.0, 1.0, 0.92, 1)
  elseif self.gate_active then
    love.graphics.setColor(0.98, 0.90, 0.35, 1)
  else
    love.graphics.setColor(0.92, 0.93, 0.88, 1)
  end
  love.graphics.rectangle("fill", gf.x, gf.y, gf.w, gf.h, 3, 3)
  love.graphics.setColor(field_hot and 0.25 or 0.35, field_hot and 0.45 or 0.40, 0.20, 1)
  love.graphics.rectangle("line", gf.x + 0.5, gf.y + 0.5, gf.w - 1, gf.h - 1, 3, 3)
  local gtx = gf.x + 6
  local gty = gf.y + (gf.h - fh) / 2
  if field_hot and self.gate_hz_sel_all and self.gate_hz_text ~= "" then
    love.graphics.setColor(0.35, 0.55, 0.85, 0.45)
    love.graphics.rectangle("fill", gtx - 1, gty - 1, font:getWidth(self.gate_hz_text) + 2, fh + 2, 2, 2)
  end
  love.graphics.setColor(0.10, 0.12, 0.10, 1)
  love.graphics.print(self.gate_hz_text, gtx, gty)
  if field_hot and not self.gate_hz_sel_all then
    local cx = gtx + font:getWidth(self.gate_hz_text)
    if (love.timer.getTime() % 1.0) < 0.55 then
      love.graphics.rectangle("fill", cx, gf.y + 4, 2, gf.h - 8)
    end
  end
  love.graphics.setColor(0.75, 0.78, 0.70, 1)
  love.graphics.print("Hz", self.gate_hz_label_x, text_y)

  -- Status sits after Build group on row 1; clipped so it never runs into the calc toolbar.
  local status_x = self.status_x or 360
  local status_max = self.status_max_x or (self.calc_rect and self.calc_rect.x - 8) or (ww - 10)
  local status_w = math.max(0, status_max - status_x)
  if status_w > 8 then
    local status
    if self:tinyc_supported() then
      local proj = self.project_dir and self.project_dir:match("([^/]+)$") or "(no project)"
      local tgt = self:build_target()
      local tgt_s = (tgt == "app")
        and ("app:" .. tostring(self.project and self.project.app_name or "?"))
        or "bare"
      status = proj .. " [" .. tgt_s .. "]  " .. (self.status or "")
    else
      local names = {
        ti89 = "TI-89", ti92plus = "TI-92+", riscv64 = "RV64",
        gameboy = "Game Boy", nes = "NES",
      }
      local mid = self.machine_id or "?"
      status = (names[mid] or mid) .. "  " .. (self.status or "")
    end
    local status_y = m.row1_btn_y + math.floor((m.btn_h - fh) / 2)
    love.graphics.setScissor(status_x, 0, status_w, TOOLBAR_H)
    if self.status_kind == "error" then
      love.graphics.setColor(0.95, 0.35, 0.32, 1)
    else
      love.graphics.setColor(0.55, 0.6, 0.55, 1)
    end
    love.graphics.print(status, status_x, status_y)
    love.graphics.setScissor()
  end

  if self.tabs.h > 0 then
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
  end

  if self.editor_rect.w > 0 and self.editor_rect.h > 0 then
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
  end

  local cr = self.console_rect
  if cr.w > 0 and cr.h > 0 then
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
        or "F5 Build  Ctrl+T Bare/App  F10 Export  Ctrl+O Open  |  F6 Play  F8 Step  F9 Load ROM"
    love.graphics.print(
      hint,
      cr.x + 8, log_bottom + math.max(1, (CONSOLE_FOOTER_H - fh) / 2)
    )
  end

  self.memmap:draw()
  self:draw_calculator()
end

function Ide:draw_calculator()
  local cr = self.calc_rect
  if not cr or cr.w <= 0 then return end

  -- Plain column backdrop
  love.graphics.setColor(0.11, 0.12, 0.13, 1)
  love.graphics.rectangle("fill", cr.x, cr.y, cr.w, cr.h)

  -- Retail shell chrome only when not using an authored scene layout.
  if not self.keypad_layout then
    if self.machine_id == "ti89" and self.face_shell then
      local s = self.face_shell
      KeypadTI89.draw_shell(s.x, s.y, s.w, s.h)
    elseif self.machine_id == "ti92plus" and self.face_shell then
      local s = self.face_shell
      KeypadTI92.draw_shell(s.x, s.y, s.w, s.h)
      local lr = self.lcd_rect
      if lr and lr.w > 0 then
        local brand_px = math.max(9, math.floor(lr.w * 0.048 + 0.5))
        if not self._brand_font or self._brand_px ~= brand_px then
          self._brand_px = brand_px
          local ok, f = pcall(love.graphics.newFont, brand_px)
          self._brand_font = (ok and f) or love.graphics.getFont()
          if ok and f then f:setFilter("linear", "linear") end
        end
        local font = self._brand_font
        local prev = love.graphics.getFont()
        love.graphics.setFont(font)
        love.graphics.setColor(0.75, 0.76, 0.78, 1)
        local label = "TI-89 Titanium"
        local tw = font:getWidth(label)
        local th = font:getHeight()
        local gap = self._brand_gap or (th + 4)
        local by = lr.y - gap + (gap - th) * 0.5
        love.graphics.print(label, lr.x + (lr.w - tw) / 2, by)
        love.graphics.setFont(prev)
      end
    end
  end

  -- Keys first; LCD chrome (and framebuffer in love.draw) sit on top so
  -- machines like TI-92 can place the screen between key rows.
  self.keypad_ui:draw()
  self:_draw_lcd_chrome()
end

function Ide:lcd_panel()
  return self.lcd_rect
end

function Ide:calc_panel()
  return self.calc_rect
end

return Ide
