-- Computer terminal control panel for the CC host.
-- Status bar (perf + pause/step/gate/theme), monitor toggles, file list.

local CC = require("frontends.computercraft.cc")
local Themes = require("frontends.computercraft.themes")

local M = {}
M.__index = M

local GATE_HZ_PRESETS = { 1, 5, 20, 60, 200, 1000 }

local ROLE_ORDER = { "lcd", "pad", "mem", "off" }
local ROLE_LABEL = {
  lcd = "LCD",
  pad = "PAD",
  face = "FACE",
  mem = "MEM",
  off = "OFF",
}

--- cycle: optional list like { "face", "mem", "off" } (TI-92 combined face).
function M.next_role(role, cycle)
  cycle = cycle or ROLE_ORDER
  for i, r in ipairs(cycle) do
    if r == role then
      return cycle[(i % #cycle) + 1]
    end
  end
  return cycle[1]
end

local function clamp(v, lo, hi)
  if v < lo then return lo end
  if v > hi then return hi end
  return v
end

local function term_size()
  if term and term.getSize then
    return term.getSize()
  end
  return 51, 19
end

local function col()
  return CC.colors()
end

local function fill_row(y, w, bg, fg, text)
  text = text or ""
  if #text > w then
    text = text:sub(1, w)
  end
  text = text .. string.rep(" ", w - #text)
  term.setCursorPos(1, y)
  term.setBackgroundColor(bg)
  term.setTextColor(fg)
  term.write(text)
end

local function write_at(x, y, text, bg, fg)
  term.setCursorPos(x, y)
  term.setBackgroundColor(bg)
  term.setTextColor(fg)
  term.write(text)
end

--- Word-wrap `text` into lines of at most `width` characters.
function M.wrap_text(text, width)
  text = tostring(text or "")
  width = math.max(1, width or 40)
  if text == "" then
    return { "" }
  end
  local lines = {}
  for paragraph in (text .. "\n"):gmatch("(.-)\n") do
    if paragraph == "" then
      lines[#lines + 1] = ""
    else
      local line = ""
      for word in paragraph:gmatch("%S+") do
        if #word > width then
          if line ~= "" then
            lines[#lines + 1] = line
            line = ""
          end
          local i = 1
          while i <= #word do
            lines[#lines + 1] = word:sub(i, i + width - 1)
            i = i + width
          end
        elseif line == "" then
          line = word
        elseif #line + 1 + #word <= width then
          line = line .. " " .. word
        else
          lines[#lines + 1] = line
          line = word
        end
      end
      if line ~= "" then
        lines[#lines + 1] = line
      end
    end
  end
  if #lines == 0 then
    lines[1] = ""
  end
  return lines
end

--- Directory containing the running program ("" = computer root).
function M.program_dir()
  if type(shell) == "table" and type(shell.getRunningProgram) == "function"
    and type(fs) == "table" and type(fs.getDir) == "function" then
    local prog = shell.getRunningProgram()
    if prog then
      local dir = fs.getDir(prog)
      if dir == nil or dir == "" then
        return ""
      end
      return dir
    end
  end
  return ""
end

--- Default TI-83+/84+ installables (profiles may override via file_filter).
M.DEFAULT_FILE_FILTER = {
  empty_hint = "(no .8xk / .8xp / .8xg in this folder)",
  kind_order = { app = 1, group = 2, prog = 3 },
  kind_tag = {
    app = { text = "APP ", bg = "yellow" },
    group = { text = "GRP ", bg = "pink" },
    prog = { text = "PRGM", bg = "lime" },
  },
  classify = function(lower)
    if lower:match("%.8xk$") then return "app" end
    if lower:match("%.8xg$") then return "group" end
    if lower:match("%.8xp$") then return "prog" end
    return nil
  end,
}

--- List machine-specific files in dir (non-recursive).
--- filter: profile.file_filter or DEFAULT_FILE_FILTER
function M.scan_files(dir, filter)
  filter = filter or M.DEFAULT_FILE_FILTER
  dir = dir or M.program_dir()
  local names = CC.list_dir(dir) or {}
  local out = {}
  local classify = filter.classify or M.DEFAULT_FILE_FILTER.classify
  for _, name in ipairs(names) do
    local kind = classify(name:lower())
    if kind then
      local path = name
      if dir ~= "" and type(fs) == "table" and fs.combine then
        path = fs.combine(dir, name)
      elseif dir ~= "" then
        path = dir .. "/" .. name
      end
      out[#out + 1] = { name = name, path = path, kind = kind }
    end
  end
  local kind_order = filter.kind_order or M.DEFAULT_FILE_FILTER.kind_order
  table.sort(out, function(a, b)
    local ka, kb = kind_order[a.kind] or 9, kind_order[b.kind] or 9
    if ka ~= kb then
      return ka < kb
    end
    return a.name:lower() < b.name:lower()
  end)
  return out
end

function M.new(opts)
  opts = opts or {}
  local self = setmetatable({}, M)
  self.dir = opts.dir or M.program_dir()
  self.file_filter = opts.file_filter or M.DEFAULT_FILE_FILTER
  self.files = M.scan_files(self.dir, self.file_filter)
  self.scroll = 0
  self.perf_mhz = 0
  self.perf_pct = 0
  self.cycles_per_tick = opts.cycles_per_tick or 200000
  -- Run controls (status bar)
  self.paused = not not opts.paused
  self.gate_active = not not opts.gate_active
  self.gate_hz = tonumber(opts.gate_hz) or 20
  if self.gate_hz < 1 then self.gate_hz = 1 end
  self.gate_hz_text = tostring(self.gate_hz)
  self.gate_hz_editing = false
  self.gate_hz_cursor = #self.gate_hz_text -- 0-based insert index
  self.gate_hz_field_w = 7 -- visible digit cells (fits 1000000)
  self.gate_hz_field_x = nil
  self.theme = Themes.is_valid(opts.theme) and opts.theme or "classic"
  -- { { side=, role="lcd"|"pad"|"mem"|"off" }, ... }
  self.monitors = opts.monitors or {}
  self.message = opts.message or "Click monitor: LCD / PAD / MEM / OFF"
  self.message_ok = true
  self.msg_max_lines = opts.msg_max_lines or 3
  self.identify = not not opts.identify
  self.show_settings = not not opts.show_settings
  self.show_mute = not not opts.show_mute
  self.muted = not not opts.muted
  -- Gate Hz is local-only; WS remotes can hide it to keep the quit chip visible.
  if opts.show_gate == nil then
    self.show_gate = true
  else
    self.show_gate = not not opts.show_gate
  end
  self.hits = {}
  self.dirty = true
  return self
end

function M:set_muted(m)
  self.muted = not not m
  self.dirty_status = true
end

function M:set_perf(mhz, pct, cycles_per_tick)
  self.perf_mhz = mhz or 0
  self.perf_pct = pct or 0
  if cycles_per_tick then
    self.cycles_per_tick = cycles_per_tick
  end
  self.dirty_status = true
end

function M:set_run_state(opts)
  opts = opts or {}
  if opts.paused ~= nil then self.paused = not not opts.paused end
  if opts.gate_active ~= nil then self.gate_active = not not opts.gate_active end
  if opts.gate_hz ~= nil and not self.gate_hz_editing then
    local n = tonumber(opts.gate_hz) or self.gate_hz
    if n < 1 then n = 1 end
    if n > 1000000 then n = 1000000 end
    self.gate_hz = math.floor(n)
    self.gate_hz_text = tostring(self.gate_hz)
    self.gate_hz_cursor = #self.gate_hz_text
  end
  if opts.theme ~= nil and Themes.is_valid(opts.theme) then
    self.theme = opts.theme
  end
  self.dirty_status = true
end

local function clamp_gate_hz(n)
  n = math.floor(tonumber(n) or 0)
  if n < 1 then return 1 end
  if n > 1000000 then return 1000000 end
  return n
end

function M:begin_gate_edit(cursor_x)
  self.gate_hz_editing = true
  self.gate_hz_text = tostring(self.gate_hz)
  if cursor_x and self.gate_hz_field_x then
    local rel = cursor_x - self.gate_hz_field_x
    self.gate_hz_cursor = clamp(rel, 0, #self.gate_hz_text)
  else
    self.gate_hz_cursor = #self.gate_hz_text
  end
  self.dirty_status = true
end

function M:cancel_gate_edit()
  if not self.gate_hz_editing then
    return false
  end
  self.gate_hz_editing = false
  self.gate_hz_text = tostring(self.gate_hz)
  self.gate_hz_cursor = #self.gate_hz_text
  self.dirty_status = true
  return true
end

--- Commit edit. Returns new hz if changed, false if cancelled/invalid kept old, nil if not editing.
function M:commit_gate_edit()
  if not self.gate_hz_editing then
    return nil
  end
  local n = tonumber(self.gate_hz_text)
  self.gate_hz_editing = false
  if n and n > 0 then
    local hz = clamp_gate_hz(n)
    local changed = hz ~= self.gate_hz
    self.gate_hz = hz
    self.gate_hz_text = tostring(hz)
    self.gate_hz_cursor = #self.gate_hz_text
    self.dirty_status = true
    return changed and hz or false
  end
  self.gate_hz_text = tostring(self.gate_hz)
  self.gate_hz_cursor = #self.gate_hz_text
  self.dirty_status = true
  return false
end

function M:place_term_cursor()
  if not term or not term.setCursorBlink then
    return
  end
  if self.gate_hz_editing and self.gate_hz_field_x and self.y_status then
    local fw = self.gate_hz_field_w_drawn or self.gate_hz_field_w
    local cx = self.gate_hz_field_x + self.gate_hz_cursor
    local max_x = self.gate_hz_field_x + fw - 1
    if cx > max_x + 1 then
      cx = max_x + 1
    end
    term.setCursorPos(cx, self.y_status)
    term.setCursorBlink(true)
  else
    term.setCursorBlink(false)
  end
end

--- Handle a typed character while editing. Returns true if consumed.
function M:gate_char(ch)
  if not self.gate_hz_editing then
    return false
  end
  ch = tostring(ch or "")
  if #ch ~= 1 or not ch:match("%d") then
    return true
  end
  if #self.gate_hz_text >= 7 then
    return true
  end
  local i = self.gate_hz_cursor
  self.gate_hz_text = self.gate_hz_text:sub(1, i) .. ch .. self.gate_hz_text:sub(i + 1)
  self.gate_hz_cursor = i + 1
  self.dirty_status = true
  return true
end

--- Handle a key while editing. `key` is a name ("backspace") and/or numeric CC code.
-- Returns "commit"|true|false.
function M:gate_key(key, code)
  if not self.gate_hz_editing then
    return false
  end
  local name = key
  if type(name) == "number" then
    code = name
    name = nil
  end
  if (not name or name == "") and type(code) == "number"
      and type(keys) == "table" and type(keys.getName) == "function" then
    name = keys.getName(code)
  end
  name = tostring(name or "")

  local function is_key(want)
    if name == want then
      return true
    end
    if type(code) == "number" and type(keys) == "table" and keys[want] == code then
      return true
    end
    return false
  end

  if is_key("enter") or is_key("numPadEnter") then
    return "commit"
  elseif is_key("escape") then
    self:cancel_gate_edit()
    return true
  elseif is_key("backspace") then
    local i = self.gate_hz_cursor
    if i > 0 then
      self.gate_hz_text = self.gate_hz_text:sub(1, i - 1) .. self.gate_hz_text:sub(i + 1)
      self.gate_hz_cursor = i - 1
      self.dirty_status = true
    end
    return true
  elseif is_key("delete") then
    local i = self.gate_hz_cursor
    if i < #self.gate_hz_text then
      self.gate_hz_text = self.gate_hz_text:sub(1, i) .. self.gate_hz_text:sub(i + 2)
      self.dirty_status = true
    end
    return true
  elseif is_key("left") then
    if self.gate_hz_cursor > 0 then
      self.gate_hz_cursor = self.gate_hz_cursor - 1
      self.dirty_status = true
    end
    return true
  elseif is_key("right") then
    if self.gate_hz_cursor < #self.gate_hz_text then
      self.gate_hz_cursor = self.gate_hz_cursor + 1
      self.dirty_status = true
    end
    return true
  elseif is_key("home") then
    self.gate_hz_cursor = 0
    self.dirty_status = true
    return true
  elseif name == "end" or (type(code) == "number" and type(keys) == "table" and keys["end"] == code) then
    self.gate_hz_cursor = #self.gate_hz_text
    self.dirty_status = true
    return true
  end
  return true -- consume other keys while editing
end

function M:set_monitors(list)
  self.monitors = list or {}
  self.dirty = true
end

function M:set_message(msg, ok)
  self.message = tostring(msg or "")
  self.message_ok = ok ~= false
  self.dirty = true
end

function M:refresh_files()
  self.files = M.scan_files(self.dir, self.file_filter)
  self.scroll = 0
  self.dirty = true
end

local function hit_add(hits, x1, y1, x2, y2, action, payload)
  hits[#hits + 1] = {
    x1 = x1, y1 = y1, x2 = x2, y2 = y2,
    action = action, payload = payload,
  }
end

local function hit_at(hits, x, y)
  for i = #hits, 1, -1 do
    local h = hits[i]
    if x >= h.x1 and x <= h.x2 and y >= h.y1 and y <= h.y2 then
      return h
    end
  end
  return nil
end

local function short_side(side)
  side = tostring(side or "?")
  if #side > 10 then
    return side:sub(1, 9) .. ">"
  end
  return side
end

local function role_tag(role)
  return ROLE_LABEL[role] or "LCD"
end

local function role_color(C, role)
  if role == "pad" then return C.orange end
  if role == "face" then return C.orange end
  if role == "mem" then return C.purple end
  if role == "off" then return C.gray end
  return C.cyan
end

function M:layout()
  local w, h = term_size()
  self.w, self.h = w, h
  self.y_status = 1

  local msg_width = math.max(1, w - 1)
  local wrapped = M.wrap_text(self.message, msg_width)
  local msg_lines = #wrapped
  if msg_lines > self.msg_max_lines then
    msg_lines = self.msg_max_lines
    -- mark truncation on last kept line
    local last = wrapped[msg_lines]
    if #last >= msg_width then
      wrapped[msg_lines] = last:sub(1, msg_width - 1) .. ">"
    else
      wrapped[msg_lines] = last .. ">"
    end
  end
  self.msg_lines = {}
  for i = 1, msg_lines do
    self.msg_lines[i] = wrapped[i]
  end
  if #self.msg_lines == 0 then
    self.msg_lines[1] = ""
  end

  self.y_msg0 = 2
  self.y_msg1 = self.y_msg0 + #self.msg_lines - 1
  self.y_mon_label = self.y_msg1 + 1
  self.y_mon0 = self.y_mon_label + 1

  local x, rows = 2, 1
  for _, m in ipairs(self.monitors) do
    local label = string.format(" %s:%s ", short_side(m.side), role_tag(m.role))
    local need = #label + 1
    if x + need - 1 > w - 1 and x > 2 then
      rows = rows + 1
      x = 2
    end
    x = x + need
  end
  if #self.monitors == 0 then
    rows = 1
  end
  self.mon_rows = rows
  self.y_mon1 = self.y_mon0 + rows - 1
  self.y_sep = self.y_mon1 + 1
  self.y_files_label = self.y_sep + 1
  self.y_files0 = self.y_files_label + 1
  self.y_files1 = math.max(self.y_files0, h - 1)
  self.list_h = math.max(1, self.y_files1 - self.y_files0 + 1)
  local max_scroll = math.max(0, #self.files - self.list_h)
  self.scroll = clamp(self.scroll, 0, max_scroll)
end

function M:draw_status()
  local C = col()
  local w = self.w
  local y = self.y_status
  fill_row(y, w, C.gray, C.white, "")

  -- Quit + KEYS own the right edge so they are never clipped by SND/theme.
  local quit_w = (w >= 12) and 3 or 0
  local keys_w = (self.show_settings and w >= 18) and 6 or 0 -- " KEYS "
  local left_max = w - quit_w - keys_w

  -- Left: pause / step / mute / gate / theme
  local x = 1
  local function btn(label, bg, fg, action, payload)
    if x > left_max then
      return
    end
    if x + #label - 1 > left_max then
      label = label:sub(1, math.max(1, left_max - x + 1))
    end
    if #label < 1 then
      return
    end
    write_at(x, y, label, bg, fg)
    hit_add(self.hits, x, y, x + #label - 1, y, action, payload)
    x = x + #label
  end

  if self.paused then
    btn(" > ", C.lime, C.black, "pause")
  else
    btn(" || ", C.orange, C.black, "pause")
  end
  btn(" >| ", C.lightBlue, C.black, "step")

  if self.show_mute then
    if self.muted then
      btn(" MUT ", C.red, C.white, "mute")
    else
      btn(" SND ", C.lime, C.black, "mute")
    end
  end

  if self.show_gate then
    if self.gate_active then
      btn(" G ", C.yellow, C.black, "gate")
    else
      btn(" G ", C.lightGray, C.black, "gate")
    end

    -- Gate Hz number field (shrink width before hiding so it stays visible).
    local fw = self.gate_hz_field_w
    local room = left_max - x - 4 -- leave room for theme
    if room < fw then
      fw = math.max(3, room)
    end
    local text = self.gate_hz_editing and self.gate_hz_text or tostring(self.gate_hz)
    if #text > fw then
      text = text:sub(1, fw)
    end
    local field = text .. string.rep(" ", fw - #text)
    local field_bg = self.gate_hz_editing and C.white
      or (self.gate_active and C.yellow or C.lightGray)
    local field_fg = C.black
    if fw >= 3 and x + fw - 1 <= left_max then
      self.gate_hz_field_w_drawn = fw
      self.gate_hz_field_x = x
      write_at(x, y, field, field_bg, field_fg)
      hit_add(self.hits, x, y, x + fw - 1, y, "gate_hz")
      x = x + fw
      if x <= left_max then
        write_at(x, y, " ", C.gray, C.white)
        x = x + 1
      end
    else
      self.gate_hz_field_x = nil
      self.gate_hz_field_w_drawn = nil
    end
  else
    self.gate_hz_field_x = nil
    self.gate_hz_field_w_drawn = nil
  end

  local theme = Themes.get(self.theme)
  local tlabel = " T:" .. (theme.label or self.theme) .. " "
  if x + #tlabel <= left_max then
    btn(tlabel, C.purple, C.white, "theme")
  else
    btn(" T ", C.purple, C.white, "theme")
  end

  -- Right cluster: perf | KEYS | X  (KEYS reserved so it never disappears)
  local right = string.format("%.2fMHz %.0f%% ", self.perf_mhz, self.perf_pct)
  if w >= 40 then
    right = string.format("%.2f MHz  %.0f%%  %dk ",
      self.perf_mhz, self.perf_pct, math.floor(self.cycles_per_tick / 1000))
  end
  local right_x = w - #right - quit_w - keys_w + 1
  if right_x < x + 1 then
    right = string.format("%.1fM ", self.perf_mhz)
    right_x = w - #right - quit_w - keys_w + 1
  end
  if right_x < x + 1 then
    right = ""
    right_x = w - quit_w - keys_w + 1
  end
  if right ~= "" and right_x >= 1 and right_x + #right - 1 <= left_max then
    write_at(right_x, y, right, C.gray, C.white)
  end
  if keys_w > 0 then
    local kx = w - quit_w - keys_w + 1
    write_at(kx, y, " KEYS ", C.cyan, C.black)
    hit_add(self.hits, kx, y, kx + keys_w - 1, y, "settings")
  end
  if quit_w > 0 then
    write_at(w - 2, y, " X ", C.red, C.white)
    hit_add(self.hits, w - 2, y, w, y, "quit")
  end
end

function M:draw_message()
  local C = col()
  local w = self.w
  local msg_bg = self.message_ok and C.black or C.red
  local msg_fg = self.message_ok and C.lightGray or C.white
  for i, line in ipairs(self.msg_lines) do
    fill_row(self.y_msg0 + i - 1, w, msg_bg, msg_fg, " " .. line)
  end
end

function M:draw_monitors()
  local C = col()
  local w = self.w
  local id_label = " IDENTIFY "
  local id_w = #id_label
  local mon_title = " MONITORS"
  if #mon_title + id_w + 1 > w then
    mon_title = " MONS"
  end
  fill_row(self.y_mon_label, w, C.black, C.white, mon_title)
  -- Identify toggle: paints side names on every monitor.
  if w >= id_w then
    local id_x = w - id_w + 1
    if self.identify then
      write_at(id_x, self.y_mon_label, id_label, C.yellow, C.black)
    else
      write_at(id_x, self.y_mon_label, id_label, C.gray, C.white)
    end
    hit_add(self.hits, id_x, self.y_mon_label, w, self.y_mon_label, "identify")
  end

  for y = self.y_mon0, self.y_mon1 do
    fill_row(y, w, C.black, C.black, "")
  end

  if #self.monitors == 0 then
    write_at(2, self.y_mon0, "(no monitors)", C.black, C.gray)
    return
  end

  local x, y = 2, self.y_mon0
  for _, m in ipairs(self.monitors) do
    local role = m.role or "lcd"
    local label = string.format(" %s:%s ", short_side(m.side), role_tag(role))
    if x + #label - 1 > w - 1 and x > 2 then
      y = y + 1
      x = 2
      if y > self.y_mon1 then
        break
      end
    end
    local bg = role_color(C, role)
    local fg = (role == "off") and C.lightGray or C.black
    write_at(x, y, label, bg, fg)
    hit_add(self.hits, x, y, x + #label - 1, y, "toggle", m.side)
    x = x + #label + 1
  end
end

function M:draw()
  if not term or not term.clear then
    return
  end
  self:layout()
  local C = col()
  local w, h = self.w, self.h
  self.hits = {}

  term.setBackgroundColor(C.black)
  term.clear()

  self:draw_status()
  self:draw_message()
  self:draw_monitors()

  fill_row(self.y_sep, w, C.black, C.gray, string.rep("-", w))

  local dir_shown = self.dir
  if dir_shown == "" then dir_shown = "/" end
  local refresh_label = " REFRESH "
  local refresh_w = #refresh_label
  local flabel = " FILES " .. dir_shown
  if #flabel + refresh_w > w then
    flabel = flabel:sub(1, math.max(1, w - refresh_w))
  end
  fill_row(self.y_files_label, w, C.black, C.white, flabel)
  if w >= refresh_w then
    local rx = w - refresh_w + 1
    write_at(rx, self.y_files_label, refresh_label, C.gray, C.white)
    hit_add(self.hits, rx, self.y_files_label, w, self.y_files_label, "refresh")
  end

  local filter = self.file_filter or M.DEFAULT_FILE_FILTER
  if #self.files == 0 then
    local hint = filter.empty_hint or M.DEFAULT_FILE_FILTER.empty_hint
    fill_row(self.y_files0, w, C.black, C.gray, " " .. hint)
  else
    local kind_tag = filter.kind_tag or M.DEFAULT_FILE_FILTER.kind_tag
    local default_tag = kind_tag.prog or { text = "FILE", bg = "lime" }
    for row = 0, self.list_h - 1 do
      local idx = self.scroll + row + 1
      local y = self.y_files0 + row
      local f = self.files[idx]
      if not f then
        fill_row(y, w, C.black, C.black, "")
      else
        local meta = kind_tag[f.kind] or default_tag
        local tag = meta.text or "FILE"
        local tag_bg = C[meta.bg] or C.lime
        local name = f.name
        local room = w - 7
        if #name > room then
          name = name:sub(1, room - 1) .. ">"
        end
        fill_row(y, w, C.black, C.white, "")
        write_at(1, y, " " .. tag .. " ", tag_bg, C.black)
        write_at(7, y, name, C.black, C.white)
        hit_add(self.hits, 1, y, w, y, "file", f)
      end
    end
  end

  if self.scroll > 0 then
    write_at(w, self.y_files0, "^", C.lightGray, C.black)
    hit_add(self.hits, w, self.y_files0, w, self.y_files0, "scroll", -1)
  end
  if self.scroll + self.list_h < #self.files then
    write_at(w, self.y_files1, "v", C.lightGray, C.black)
    hit_add(self.hits, w, self.y_files1, w, self.y_files1, "scroll", 1)
  end

  self.dirty = false
  self.dirty_status = false
  term.setBackgroundColor(C.black)
  term.setTextColor(C.white)
  if self.gate_hz_editing then
    self:place_term_cursor()
  else
    term.setCursorBlink(false)
    term.setCursorPos(1, h)
  end
end

local STATUS_ACTIONS = {
  quit = true,
  pause = true,
  step = true,
  mute = true,
  gate = true,
  gate_hz = true,
  theme = true,
  settings = true,
}

function M:draw_status_only()
  if not term then return end
  self:layout()
  local kept = {}
  for _, h in ipairs(self.hits) do
    if not STATUS_ACTIONS[h.action] then
      kept[#kept + 1] = h
    end
  end
  self.hits = kept
  self:draw_status()
  self.dirty_status = false
  self:place_term_cursor()
end

function M:click(x, y)
  local h = hit_at(self.hits, x, y)

  -- While editing, clicks outside the field only unfocus (absorb the click).
  if self.gate_hz_editing then
    if h and h.action == "gate_hz" then
      local rel = x - (self.gate_hz_field_x or x)
      self.gate_hz_cursor = clamp(rel, 0, #self.gate_hz_text)
      self.dirty_status = true
      return { action = "gate_edit" }
    end
    local hz = self:commit_gate_edit()
    if hz then
      return { action = "gate_hz", hz = hz, on = self.gate_active, absorbed = true }
    end
    return { action = "gate_edit", editing = false, absorbed = true }
  end

  if not h then
    return nil
  end
  if h.action == "scroll" then
    self.scroll = self.scroll + (h.payload or 0)
    self.dirty = true
    return { action = "redraw" }
  elseif h.action == "refresh" then
    self:refresh_files()
    return { action = "redraw" }
  elseif h.action == "toggle" then
    return { action = "toggle", side = h.payload }
  elseif h.action == "identify" then
    self.identify = not self.identify
    self.dirty = true
    return { action = "identify", on = self.identify }
  elseif h.action == "file" then
    return { action = "file", file = h.payload }
  elseif h.action == "pause" then
    self.paused = not self.paused
    self.dirty_status = true
    return { action = "pause", paused = self.paused }
  elseif h.action == "step" then
    return { action = "step" }
  elseif h.action == "mute" then
    self.muted = not self.muted
    self.dirty_status = true
    return { action = "mute", muted = self.muted }
  elseif h.action == "gate" then
    self.gate_active = not self.gate_active
    self.dirty_status = true
    return { action = "gate", on = self.gate_active, hz = self.gate_hz }
  elseif h.action == "gate_hz" then
    self:begin_gate_edit(x)
    return { action = "gate_edit", editing = true }
  elseif h.action == "theme" then
    self.theme = Themes.next(self.theme)
    self.dirty_status = true
    return { action = "theme", theme = self.theme }
  elseif h.action == "settings" then
    return { action = "settings" }
  elseif h.action == "quit" then
    return { action = "quit" }
  end
  return nil
end

function M:scroll_by(delta)
  self.scroll = self.scroll + delta
  self.dirty = true
end

M.ROLE_ORDER = ROLE_ORDER
M.ROLE_LABEL = ROLE_LABEL
M.GATE_HZ_PRESETS = GATE_HZ_PRESETS

return M
