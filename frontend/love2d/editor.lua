-- Rich multiline editor: selection, syntax highlight, auto-indent.

local Editor = {}
Editor.__index = Editor

local COLORS = {
  bg = { 0.12, 0.13, 0.15, 1 },
  gutter = { 0.35, 0.38, 0.40, 1 },
  line_hl = { 0.18, 0.22, 0.28, 1 },
  sel = { 0.25, 0.40, 0.55, 0.55 },
  caret = { 0.95, 0.85, 0.45, 1 },
  text = { 0.86, 0.88, 0.84, 1 },
  kw = { 0.78, 0.55, 0.90, 1 },
  type = { 0.45, 0.75, 0.95, 1 },
  native = { 0.40, 0.85, 0.70, 1 },
  number = { 0.95, 0.70, 0.40, 1 },
  string = { 0.70, 0.85, 0.45, 1 },
  comment = { 0.45, 0.50, 0.45, 1 },
  punct = { 0.70, 0.72, 0.68, 1 },
  label = { 0.90, 0.75, 0.40, 1 },
  instr = { 0.55, 0.75, 0.95, 1 },
  dir = { 0.90, 0.55, 0.55, 1 },
  reg = { 0.95, 0.60, 0.55, 1 },
}

local TC_KW = {
  void = true, byte = true, word = true,
  ["if"] = true, ["else"] = true, ["while"] = true, ["return"] = true,
}
local TC_TYPES = { void = true, byte = true, word = true }
local TC_NATIVE = {
  lcd_init = true, lcd_clear = true, draw_string = true, draw_pixel = true,
  key_scan = true, key_wait = true, key_down = true,
  poke = true, peek = true, fmul = true, halt = true,
}

local ASM_DIR = {
  org = true, equ = true, db = true, dw = true, ds = true,
  blob = true, include = true,
}
local ASM_REG = {
  a = true, b = true, c = true, d = true, e = true, h = true, l = true,
  af = true, bc = true, de = true, hl = true, sp = true, ix = true, iy = true,
  i = true, r = true,
  nz = true, z = true, nc = true, po = true, pe = true, p = true, m = true,
}

local function pos_le(r1, c1, r2, c2)
  return r1 < r2 or (r1 == r2 and c1 <= c2)
end

function Editor.new(lang)
  local self = setmetatable({}, Editor)
  self.lines = { "" }
  self.cx, self.cy = 1, 1
  self.anchor = nil -- {r, c} when selecting
  self.scroll = 0
  self.focused = false
  self.dragging = false
  self.x, self.y, self.w, self.h = 0, 0, 100, 100
  self.line_h = 18
  self.gutter = 52
  self.pad = 6
  self.blink = 0
  self.dirty = false
  self.lang = lang or "tc" -- "tc" | "asm"
  self.token_cache = {} -- row -> tokens
  self.cache_gen = 0
  self.undo_stack = {}
  self.redo_stack = {}
  self.undo_coalesce = nil
  self.undo_coalesce_t = 0
  self._suppress_undo = false
  self.undo_limit = 200
  self.undo_coalesce_sec = 0.8
  return self
end

local function copy_lines(lines)
  local out = {}
  for i = 1, #lines do
    out[i] = lines[i]
  end
  return out
end

function Editor:_snapshot()
  local anchor = nil
  if self.anchor then
    anchor = { r = self.anchor.r, c = self.anchor.c }
  end
  return {
    lines = copy_lines(self.lines),
    cx = self.cx,
    cy = self.cy,
    scroll = self.scroll,
    anchor = anchor,
    dirty = self.dirty,
  }
end

function Editor:_restore(snap)
  self.lines = copy_lines(snap.lines)
  self.cx, self.cy = snap.cx, snap.cy
  self.scroll = snap.scroll or 0
  if snap.anchor then
    self.anchor = { r = snap.anchor.r, c = snap.anchor.c }
  else
    self.anchor = nil
  end
  self.dirty = snap.dirty and true or false
  self.token_cache = {}
  self.undo_coalesce = nil
  self:_clamp()
end

function Editor:_clear_history()
  self.undo_stack = {}
  self.redo_stack = {}
  self.undo_coalesce = nil
  self.undo_coalesce_t = 0
end

--- Record pre-edit state. Same coalesce group within undo_coalesce_sec merges.
function Editor:_record_undo(group)
  if self._suppress_undo then return end
  local now = love.timer.getTime()
  if group and self.undo_coalesce == group
      and (now - self.undo_coalesce_t) < self.undo_coalesce_sec then
    return
  end
  self.undo_coalesce = group
  self.undo_coalesce_t = now
  self.undo_stack[#self.undo_stack + 1] = self:_snapshot()
  if #self.undo_stack > self.undo_limit then
    table.remove(self.undo_stack, 1)
  end
  self.redo_stack = {}
end

function Editor:undo()
  if #self.undo_stack == 0 then return false end
  local cur = self:_snapshot()
  local prev = table.remove(self.undo_stack)
  self.redo_stack[#self.redo_stack + 1] = cur
  self:_restore(prev)
  self.blink = 0
  return true
end

function Editor:redo()
  if #self.redo_stack == 0 then return false end
  local cur = self:_snapshot()
  local nexts = table.remove(self.redo_stack)
  self.undo_stack[#self.undo_stack + 1] = cur
  self:_restore(nexts)
  self.blink = 0
  return true
end

function Editor:sync_metrics()
  local font = love.graphics.getFont()
  if not font then return end
  local fh = font:getHeight()
  self.line_h = math.max(16, math.ceil(fh + 4))
  local digits = math.max(3, #tostring(#self.lines))
  self.gutter = math.ceil(font:getWidth(string.rep("0", digits)) + 18)
end

function Editor:set_lang(lang)
  self.lang = lang
  self.token_cache = {}
end

function Editor:set_text(text)
  self.lines = {}
  text = text:gsub("\r\n", "\n"):gsub("\r", "\n")
  if text == "" then
    self.lines = { "" }
  else
    for line in (text .. "\n"):gmatch("(.-)\n") do
      self.lines[#self.lines + 1] = line
    end
    if #self.lines == 0 then self.lines = { "" } end
  end
  self.cx, self.cy = 1, 1
  self.anchor = nil
  self.scroll = 0
  self.dirty = false
  self.token_cache = {}
  self:_clear_history()
  self:_clamp()
end

function Editor:get_text()
  return table.concat(self.lines, "\n")
end

function Editor:goto_line(line, col)
  self.cy = tonumber(line) or 1
  self.cx = tonumber(col) or 1
  self.anchor = nil
  self.blink = 0
  self:_clamp()
  local vis = self:visible_rows()
  self.scroll = math.max(0, self.cy - math.floor(vis / 2) - 1)
  self:_clamp()
end

function Editor:set_bounds(x, y, w, h)
  self.x, self.y, self.w, self.h = x, y, w, h
  self:sync_metrics()
end

function Editor:visible_rows()
  return math.max(1, math.floor((self.h - self.pad * 2) / self.line_h))
end

function Editor:_invalidate(row)
  if row then
    self.token_cache[row] = nil
  else
    self.token_cache = {}
  end
end

function Editor:_clamp()
  if self.cy < 1 then self.cy = 1 end
  if self.cy > #self.lines then self.cy = #self.lines end
  local line = self.lines[self.cy] or ""
  if self.cx < 1 then self.cx = 1 end
  if self.cx > #line + 1 then self.cx = #line + 1 end
  local vis = self:visible_rows()
  if self.cy - 1 < self.scroll then
    self.scroll = self.cy - 1
  elseif self.cy - self.scroll > vis then
    self.scroll = self.cy - vis
  end
  if self.scroll < 0 then self.scroll = 0 end
end

function Editor:has_selection()
  if not self.anchor then return false end
  return not (self.anchor.r == self.cy and self.anchor.c == self.cx)
end

function Editor:sel_range()
  if not self:has_selection() then return nil end
  local ar, ac = self.anchor.r, self.anchor.c
  local br, bc = self.cy, self.cx
  if not pos_le(ar, ac, br, bc) then
    ar, ac, br, bc = br, bc, ar, ac
  end
  return ar, ac, br, bc
end

function Editor:clear_selection()
  self.anchor = nil
end

function Editor:_set_anchor_here()
  self.anchor = { r = self.cy, c = self.cx }
end

function Editor:get_selected_text()
  local ar, ac, br, bc = self:sel_range()
  if not ar then return "" end
  if ar == br then
    return self.lines[ar]:sub(ac, bc - 1)
  end
  local parts = { self.lines[ar]:sub(ac) }
  for r = ar + 1, br - 1 do
    parts[#parts + 1] = self.lines[r]
  end
  parts[#parts + 1] = self.lines[br]:sub(1, bc - 1)
  return table.concat(parts, "\n")
end

function Editor:delete_selection()
  local ar, ac, br, bc = self:sel_range()
  if not ar then return false end
  if ar == br then
    local line = self.lines[ar]
    self.lines[ar] = line:sub(1, ac - 1) .. line:sub(bc)
    self:_invalidate(ar)
  else
    local first = self.lines[ar]:sub(1, ac - 1)
    local last = self.lines[br]:sub(bc)
    for _ = ar + 1, br do
      table.remove(self.lines, ar + 1)
    end
    self.lines[ar] = first .. last
    self:_invalidate()
  end
  self.cy, self.cx = ar, ac
  self.anchor = nil
  self.dirty = true
  self:_clamp()
  return true
end

function Editor:_leading_ws(line)
  local ws = line:match("^(%s*)") or ""
  return ws
end

function Editor:_indent_of(line)
  return #(line:match("^(%s*)") or "")
end

function Editor:contains(mx, my)
  return mx >= self.x and my >= self.y and mx < self.x + self.w and my < self.y + self.h
end

function Editor:_pos_from_mouse(mx, my)
  self:sync_metrics()
  local font = love.graphics.getFont()
  local row = math.floor((my - self.y - self.pad) / self.line_h) + self.scroll + 1
  if row < 1 then row = 1 end
  if row > #self.lines then row = #self.lines end
  local line = self.lines[row]
  local tx = mx - self.x - self.pad - self.gutter
  local col = 1
  for i = 0, #line do
    local w = font:getWidth(line:sub(1, i))
    local next_w = (i < #line) and font:getWidth(line:sub(1, i + 1)) or (w + 1)
    if tx < (w + next_w) / 2 then
      col = i + 1
      break
    end
    col = i + 2
  end
  if col > #line + 1 then col = #line + 1 end
  return row, col
end

function Editor:mousepressed(mx, my, shift)
  if not self:contains(mx, my) then
    return false
  end
  self.focused = true
  local row, col = self:_pos_from_mouse(mx, my)
  self.undo_coalesce = nil
  if shift then
    if not self.anchor then
      self.anchor = { r = self.cy, c = self.cx }
    end
    self.cy, self.cx = row, col
  else
    self.cy, self.cx = row, col
    self.anchor = { r = row, c = col } -- drag extends from here
  end
  self.dragging = true
  self.blink = 0
  self:_clamp()
  return true
end

function Editor:mousemoved(mx, my)
  if not self.dragging then return false end
  local row, col = self:_pos_from_mouse(mx, my)
  self.cy, self.cx = row, col
  self:_clamp()
  self.blink = 0
  return true
end

function Editor:mousereleased()
  if self.dragging then
    self.dragging = false
    -- collapse empty selection
    if self.anchor and self.anchor.r == self.cy and self.anchor.c == self.cx then
      self.anchor = nil
    end
    return true
  end
  return false
end

function Editor:textinput(t)
  if not self.focused then return end
  self:_record_undo("type")
  if self:has_selection() then
    self._suppress_undo = true
    self:delete_selection()
    self._suppress_undo = false
  end
  -- auto-outdent when typing } as the first non-ws on the line (Tiny-C)
  if self.lang == "tc" and t == "}" then
    local line = self.lines[self.cy]
    local before = line:sub(1, self.cx - 1)
    local after = line:sub(self.cx)
    if before:match("^%s*$") then
      local indent = before
      if #indent >= 2 then indent = indent:sub(1, -3) end
      self.lines[self.cy] = indent .. "}" .. after
      self.cx = #indent + 2
      self:_invalidate(self.cy)
      self.dirty = true
      self.blink = 0
      return
    end
  end
  local line = self.lines[self.cy]
  self.lines[self.cy] = line:sub(1, self.cx - 1) .. t .. line:sub(self.cx)
  self.cx = self.cx + #t
  self:_invalidate(self.cy)
  self.dirty = true
  self.blink = 0
end

function Editor:_move(key, shift)
  self.undo_coalesce = nil
  if shift then
    if not self.anchor then self:_set_anchor_here() end
  else
    self.anchor = nil
  end
  local line = self.lines[self.cy]
  if key == "left" then
    if self.cx > 1 then self.cx = self.cx - 1
    elseif self.cy > 1 then self.cy = self.cy - 1; self.cx = #self.lines[self.cy] + 1 end
  elseif key == "right" then
    if self.cx <= #line then self.cx = self.cx + 1
    elseif self.cy < #self.lines then self.cy = self.cy + 1; self.cx = 1 end
  elseif key == "up" then
    self.cy = self.cy - 1
  elseif key == "down" then
    self.cy = self.cy + 1
  elseif key == "home" then
    -- smart home: first non-ws, then 0
    local indent = #(line:match("^(%s*)") or "")
    if self.cx ~= indent + 1 and indent > 0 then
      self.cx = indent + 1
    else
      self.cx = 1
    end
  elseif key == "end" then
    self.cx = #line + 1
  elseif key == "pageup" then
    self.cy = self.cy - self:visible_rows()
  elseif key == "pagedown" then
    self.cy = self.cy + self:visible_rows()
  end
  self:_clamp()
end

function Editor:keypressed(key)
  if not self.focused then return false end
  local shift = love.keyboard.isDown("lshift", "rshift")
  local ctrl = love.keyboard.isDown("lctrl", "rctrl", "lgui", "rgui")
  local line = self.lines[self.cy]
  self.blink = 0

  if ctrl and key == "a" then
    self.anchor = { r = 1, c = 1 }
    self.cy = #self.lines
    self.cx = #self.lines[self.cy] + 1
    return true
  elseif ctrl and key == "z" then
    if shift then
      self:redo()
    else
      self:undo()
    end
    return true
  elseif ctrl and key == "y" then
    self:redo()
    return true
  elseif ctrl and key == "c" then
    if self:has_selection() then
      love.system.setClipboardText(self:get_selected_text())
    end
    return true
  elseif ctrl and key == "x" then
    if self:has_selection() then
      love.system.setClipboardText(self:get_selected_text())
      self:_record_undo("cut")
      self:delete_selection()
    end
    return true
  elseif ctrl and key == "v" then
    local clip = love.system.getClipboardText() or ""
    if clip ~= "" then
      self:_record_undo("paste")
      self._suppress_undo = true
      if self:has_selection() then self:delete_selection() end
      self._suppress_undo = false
      -- insert multiline
      local parts = {}
      clip = clip:gsub("\r\n", "\n"):gsub("\r", "\n")
      for part in (clip .. "\n"):gmatch("(.-)\n") do
        parts[#parts + 1] = part
      end
      if #parts == 0 then return true end
      local left = self.lines[self.cy]:sub(1, self.cx - 1)
      local right = self.lines[self.cy]:sub(self.cx)
      if #parts == 1 then
        self.lines[self.cy] = left .. parts[1] .. right
        self.cx = #left + #parts[1] + 1
        self:_invalidate(self.cy)
      else
        self.lines[self.cy] = left .. parts[1]
        for i = 2, #parts - 1 do
          table.insert(self.lines, self.cy + i - 1, parts[i])
        end
        table.insert(self.lines, self.cy + #parts - 1, parts[#parts] .. right)
        self.cy = self.cy + #parts - 1
        self.cx = #parts[#parts] + 1
        self:_invalidate()
      end
      self.dirty = true
      self:_clamp()
    end
    return true
  end

  if key == "backspace" then
    if self:has_selection() or self.cx > 1 or self.cy > 1 then
      self:_record_undo("backspace")
    end
    if self:has_selection() then
      self:delete_selection()
    elseif self.cx > 1 then
      self.lines[self.cy] = line:sub(1, self.cx - 2) .. line:sub(self.cx)
      self.cx = self.cx - 1
      self:_invalidate(self.cy)
      self.dirty = true
    elseif self.cy > 1 then
      local prev = self.lines[self.cy - 1]
      self.cx = #prev + 1
      self.lines[self.cy - 1] = prev .. line
      table.remove(self.lines, self.cy)
      self.cy = self.cy - 1
      self:_invalidate()
      self.dirty = true
    end
  elseif key == "delete" then
    if self:has_selection() or self.cx <= #line or self.cy < #self.lines then
      self:_record_undo("delete")
    end
    if self:has_selection() then
      self:delete_selection()
    elseif self.cx <= #line then
      self.lines[self.cy] = line:sub(1, self.cx - 1) .. line:sub(self.cx + 1)
      self:_invalidate(self.cy)
      self.dirty = true
    elseif self.cy < #self.lines then
      self.lines[self.cy] = line .. self.lines[self.cy + 1]
      table.remove(self.lines, self.cy + 1)
      self:_invalidate()
      self.dirty = true
    end
  elseif key == "return" or key == "kpenter" then
    self:_record_undo("return")
    self._suppress_undo = true
    if self:has_selection() then self:delete_selection(); line = self.lines[self.cy] end
    self._suppress_undo = false
    local left = line:sub(1, self.cx - 1)
    local right = line:sub(self.cx)
    local indent = self:_leading_ws(left)
    -- increase indent after { or : (tc block / asm nicety)
    local trimmed = left:match("^(.-)%s*$") or left
    if self.lang == "tc" and trimmed:sub(-1) == "{" then
      indent = indent .. "  "
    end
    -- if right starts with }, keep it less indented on its own - leave as-is
    self.lines[self.cy] = left
    table.insert(self.lines, self.cy + 1, indent .. right)
    self.cy = self.cy + 1
    self.cx = #indent + 1
    self.anchor = nil
    self:_invalidate()
    self.dirty = true
  elseif key == "tab" then
    self:_record_undo("indent")
    if self:has_selection() then
      local ar, _, br, _ = self:sel_range()
      for r = ar, br do
        local ln = self.lines[r]
        if shift then
          if ln:sub(1, 2) == "  " then
            self.lines[r] = ln:sub(3)
          elseif ln:sub(1, 1) == "\t" then
            self.lines[r] = ln:sub(2)
          end
        else
          self.lines[r] = "  " .. ln
        end
      end
      self:_invalidate()
      self.dirty = true
    else
      if shift then
        local ln = self.lines[self.cy]
        if ln:sub(1, 2) == "  " then
          self.lines[self.cy] = ln:sub(3)
          self.cx = math.max(1, self.cx - 2)
          self:_invalidate(self.cy)
          self.dirty = true
        end
      else
        self._suppress_undo = true
        self:textinput("  ")
        self._suppress_undo = false
      end
    end
  elseif key == "left" or key == "right" or key == "up" or key == "down"
      or key == "home" or key == "end" or key == "pageup" or key == "pagedown" then
    -- if moving without shift and have selection, collapse to edge first for left/right
    if not shift and self:has_selection() and (key == "left" or key == "right") then
      local ar, ac, br, bc = self:sel_range()
      if key == "left" then self.cy, self.cx = ar, ac else self.cy, self.cx = br, bc end
      self.anchor = nil
      self:_clamp()
    else
      self:_move(key, shift)
    end
  else
    return false
  end
  self:_clamp()
  return true
end

function Editor:wheelmoved(_, y)
  if not self.focused and not self:contains(love.mouse.getX(), love.mouse.getY()) then
    return false
  end
  self.scroll = self.scroll - y * 3
  local max_scroll = math.max(0, #self.lines - self:visible_rows())
  if self.scroll < 0 then self.scroll = 0 end
  if self.scroll > max_scroll then self.scroll = max_scroll end
  return true
end

function Editor:update(dt)
  self.blink = self.blink + dt
  if self.blink > 1.0 then self.blink = 0 end
end

-- Tokenizer ---------------------------------------------------------------

local function push_tok(tokens, kind, text)
  if text and #text > 0 then
    tokens[#tokens + 1] = { kind = kind, text = text }
  end
end

function Editor:_tokenize_tc(line)
  local tokens = {}
  local i, n = 1, #line
  while i <= n do
    local ch = line:sub(i, i)
    if ch:match("%s") then
      local j = i
      while j <= n and line:sub(j, j):match("%s") do j = j + 1 end
      push_tok(tokens, "text", line:sub(i, j - 1))
      i = j
    elseif ch == "/" and line:sub(i + 1, i + 1) == "/" then
      push_tok(tokens, "comment", line:sub(i))
      break
    elseif ch == '"' then
      local j = i + 1
      while j <= n do
        if line:sub(j, j) == "\\" then
          j = j + 2
        elseif line:sub(j, j) == '"' then
          j = j + 1
          break
        else
          j = j + 1
        end
      end
      push_tok(tokens, "string", line:sub(i, j - 1))
      i = j
    elseif ch:match("%d") then
      local j = i
      if ch == "0" and line:sub(i + 1, i + 1):match("[xX]") then
        j = i + 2
        while j <= n and line:sub(j, j):match("%x") do j = j + 1 end
      else
        while j <= n and line:sub(j, j):match("%d") do j = j + 1 end
      end
      push_tok(tokens, "number", line:sub(i, j - 1))
      i = j
    elseif ch:match("[%a_]") then
      local j = i
      while j <= n and line:sub(j, j):match("[%w_]") do j = j + 1 end
      local word = line:sub(i, j - 1)
      local kind = "text"
      if TC_TYPES[word] then kind = "type"
      elseif TC_KW[word] then kind = "kw"
      elseif TC_NATIVE[word] then kind = "native"
      end
      push_tok(tokens, kind, word)
      i = j
    else
      push_tok(tokens, "punct", ch)
      i = i + 1
    end
  end
  return tokens
end

function Editor:_tokenize_asm(line)
  local tokens = {}
  local i, n = 1, #line
  -- full-line comment
  local trimmed = line:match("^%s*(.*)$") or line
  if trimmed:sub(1, 1) == ";" then
    push_tok(tokens, "text", line:match("^(%s*)") or "")
    push_tok(tokens, "comment", line:sub(#(line:match("^(%s*)") or "") + 1))
    return tokens
  end

  while i <= n do
    local ch = line:sub(i, i)
    if ch:match("%s") then
      local j = i
      while j <= n and line:sub(j, j):match("%s") do j = j + 1 end
      push_tok(tokens, "text", line:sub(i, j - 1))
      i = j
    elseif ch == ";" then
      push_tok(tokens, "comment", line:sub(i))
      break
    elseif ch == '"' then
      local j = i + 1
      while j <= n and line:sub(j, j) ~= '"' do j = j + 1 end
      if j <= n then j = j + 1 end
      push_tok(tokens, "string", line:sub(i, j - 1))
      i = j
    elseif ch:match("[%d$]") or (ch == "0" and line:sub(i + 1, i + 1):match("[xX]")) then
      local j = i
      if ch == "$" then
        j = i + 1
        while j <= n and line:sub(j, j):match("%x") do j = j + 1 end
      elseif line:sub(i, i + 1):match("0[xX]") then
        j = i + 2
        while j <= n and line:sub(j, j):match("%x") do j = j + 1 end
      else
        while j <= n and line:sub(j, j):match("[%w]") do j = j + 1 end
      end
      push_tok(tokens, "number", line:sub(i, j - 1))
      i = j
    elseif ch:match("[%a_.]") then
      local j = i
      while j <= n and line:sub(j, j):match("[%w_.]") do j = j + 1 end
      local word = line:sub(i, j - 1)
      local low = word:lower()
      -- label if ends with : (include colon)
      if line:sub(j, j) == ":" then
        push_tok(tokens, "label", word .. ":")
        i = j + 1
      elseif ASM_DIR[low] then
        push_tok(tokens, "dir", word)
        i = j
      elseif ASM_REG[low] then
        push_tok(tokens, "reg", word)
        i = j
      else
        -- instruction if at line start or right after a label:
        local before = line:sub(1, i - 1)
        if before:match("^%s*$") or before:match("^%s*[%w_.]+%s*:%s*$") then
          push_tok(tokens, "instr", word)
        else
          push_tok(tokens, "text", word)
        end
        i = j
      end
    else
      push_tok(tokens, "punct", ch)
      i = i + 1
    end
  end
  return tokens
end

function Editor:_tokens_for(row)
  local cached = self.token_cache[row]
  if cached then return cached end
  local line = self.lines[row] or ""
  local toks
  if self.lang == "asm" then
    toks = self:_tokenize_asm(line)
  else
    toks = self:_tokenize_tc(line)
  end
  self.token_cache[row] = toks
  return toks
end

local function color_for(kind)
  return COLORS[kind] or COLORS.text
end

function Editor:draw()
  self:sync_metrics()
  local font = love.graphics.getFont()
  love.graphics.setColor(COLORS.bg)
  love.graphics.rectangle("fill", self.x, self.y, self.w, self.h, 4, 4)
  love.graphics.setColor(self.focused and 0.35 or 0.22, self.focused and 0.45 or 0.25, 0.30, 1)
  love.graphics.setLineWidth(self.focused and 2 or 1)
  love.graphics.rectangle("line", self.x + 0.5, self.y + 0.5, self.w - 1, self.h - 1, 4, 4)

  love.graphics.setScissor(self.x + 1, self.y + 1, self.w - 2, self.h - 2)
  local vis = self:visible_rows()
  local ar, ac, br, bc = self:sel_range()

  for i = 0, vis do
    local row = self.scroll + i + 1
    if row > #self.lines then break end
    local ly = self.y + self.pad + i * self.line_h
    local line = self.lines[row]

    -- gutter
    love.graphics.setColor(COLORS.gutter)
    love.graphics.printf(tostring(row), self.x + 2, ly, self.gutter - 8, "right")

    -- current line
    if row == self.cy and self.focused then
      love.graphics.setColor(COLORS.line_hl)
      love.graphics.rectangle("fill", self.x + self.gutter, ly - 1, self.w - self.gutter - 4, self.line_h)
    end

    -- selection background
    if ar and row >= ar and row <= br then
      local sc = (row == ar) and ac or 1
      local ec = (row == br) and bc or (#line + 1)
      local x1 = self.x + self.pad + self.gutter + font:getWidth(line:sub(1, sc - 1))
      local x2 = self.x + self.pad + self.gutter + font:getWidth(line:sub(1, ec - 1))
      if x2 <= x1 then x2 = x1 + 4 end -- empty line caret width
      love.graphics.setColor(COLORS.sel)
      love.graphics.rectangle("fill", x1, ly - 1, x2 - x1, self.line_h)
    end

    -- highlighted tokens
    local tx = self.x + self.pad + self.gutter
    for _, tok in ipairs(self:_tokens_for(row)) do
      local c = color_for(tok.kind)
      love.graphics.setColor(c)
      love.graphics.print(tok.text, tx, ly)
      tx = tx + font:getWidth(tok.text)
    end
  end

  -- caret
  if self.focused and self.blink < 0.5 and not self:has_selection() then
    local line = self.lines[self.cy] or ""
    local prefix = line:sub(1, self.cx - 1)
    local cx = self.x + self.pad + self.gutter + font:getWidth(prefix)
    local cy = self.y + self.pad + (self.cy - 1 - self.scroll) * self.line_h
    if cy >= self.y and cy < self.y + self.h then
      love.graphics.setColor(COLORS.caret)
      love.graphics.rectangle("fill", cx, cy, 2, self.line_h - 2)
    end
  end
  love.graphics.setScissor()
end

-- back-compat for old click() API
function Editor:click(mx, my)
  return self:mousepressed(mx, my, false)
end

return Editor
