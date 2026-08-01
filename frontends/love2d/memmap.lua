-- Memory panel: one pixel per byte, profiled per calculator.
-- Grid shape follows the parent column (not a fixed square): width-driven
-- columns, rows = ceil(mem_size / cols), then stretched to fill the panel.

local MemMap = {}
MemMap.__index = MemMap

local COLLAPSED_W = 18
local DEFAULT_EXPANDED_W = 340
local MIN_EXPANDED_W = 140
local MAX_EXPANDED_W = 900
local FOOTER_H = 22
local MIN_COLS = 32
local MAX_COLS = 1024
-- Left-edge grip: drag to resize; click (no drag) on toggle still opens/closes.
local DRAG_HIT = 8
local DRAG_THRESHOLD = 3

local function clamp01(x)
  if x < 0 then return 0 end
  if x > 1 then return 1 end
  return x
end

local function rgba(r, g, b)
  return string.char(r, g, b, 255)
end

local PROFILE = {}

PROFILE.ti83plus = {
  id = "ti83plus",
  title = "TI-83+",
  mem_size = 65536,
  addr_digits = 4,
  region_names = { "FLASH", "BANKA", "RAM8", "RAMC" },
  region_colors = {
    { 0.30, 0.50, 1.00 },
    { 0.80, 0.35, 1.00 },
    { 0.25, 0.95, 0.50 },
    { 1.00, 0.80, 0.25 },
  },
  bank_lines = { 0x4000, 0x8000, 0xC000 },
  region_of = function(addr)
    return math.floor(addr / 0x4000) % 4 + 1
  end,
  read = function(machine, addr)
    local mmu = machine.mmu
    if mmu and mmu.read then return mmu:read(addr) end
    return 0
  end,
  get_pc = function(cpu)
    return (cpu.pc or 0) % 65536
  end,
  get_sp = function(cpu)
    return (cpu.sp or 0) % 65536
  end,
  marker_in_view = function(addr)
    return addr >= 0 and addr < 65536
  end,
  sp_label = "SP",
}

PROFILE.ti89 = {
  id = "ti89",
  title = "TI-89 Ti",
  mem_size = 256 * 1024,
  addr_digits = 6,
  region_names = { "VEC", "RAM", "LCD", "RAM" },
  region_colors = {
    { 0.95, 0.35, 0.35 },
    { 0.30, 0.55, 0.95 },
    { 0.25, 0.90, 0.55 },
    { 0.55, 0.45, 0.85 },
  },
  bank_lines = { 0x10000, 0x20000, 0x30000 },
  region_of = function(addr)
    if addr < 0x120 then return 1 end
    if addr >= 0x4C00 and addr < 0x5C00 then return 3 end
    if addr < 0x10000 then return 2 end
    return 4
  end,
  read = function(machine, addr)
    local ram = machine.ram
    if ram and ram.read8 then return ram:read8(addr) end
    if ram and ram.bytes then return ram.bytes[addr % (ram.SIZE or 262144)] or 0 end
    return 0
  end,
  get_pc = function(cpu)
    return cpu.pc or 0
  end,
  get_sp = function(cpu)
    if cpu.get_a then return cpu:get_a(7) or 0 end
    if cpu.a and cpu.a[7] then return cpu.a[7] end
    return cpu.ssp or cpu.usp or 0
  end,
  marker_in_view = function(addr)
    return (addr % 0x1000000) < 0x40000
  end,
  view_addr = function(addr)
    return addr % 0x40000
  end,
  sp_label = "A7",
}

PROFILE.ti84plus = {
  id = "ti84plus",
  title = "TI-84+",
  mem_size = PROFILE.ti83plus.mem_size,
  addr_digits = PROFILE.ti83plus.addr_digits,
  region_names = PROFILE.ti83plus.region_names,
  region_colors = PROFILE.ti83plus.region_colors,
  bank_lines = PROFILE.ti83plus.bank_lines,
  region_of = PROFILE.ti83plus.region_of,
  read = PROFILE.ti83plus.read,
  get_pc = PROFILE.ti83plus.get_pc,
  get_sp = PROFILE.ti83plus.get_sp,
  marker_in_view = PROFILE.ti83plus.marker_in_view,
  sp_label = PROFILE.ti83plus.sp_label,
}

PROFILE.ti92plus = {
  id = "ti92plus",
  title = "TI-92+",
  mem_size = 256 * 1024,
  addr_digits = 6,
  region_names = PROFILE.ti89.region_names,
  region_colors = PROFILE.ti89.region_colors,
  bank_lines = PROFILE.ti89.bank_lines,
  region_of = PROFILE.ti89.region_of,
  read = PROFILE.ti89.read,
  get_pc = PROFILE.ti89.get_pc,
  get_sp = PROFILE.ti89.get_sp,
  marker_in_view = PROFILE.ti89.marker_in_view,
  view_addr = PROFILE.ti89.view_addr,
  sp_label = "A7",
}

PROFILE.riscv64 = {
  id = "riscv64",
  title = "RV64",
  -- Sliding 256 KiB window (follows PC: low ROM/MMIO vs DRAM @ 0x80000000).
  mem_size = 256 * 1024,
  addr_digits = 8,
  region_names = { "ROM", "MMIO", "RAM" },
  region_colors = {
    { 0.25, 0.45, 0.70 },
    { 0.70, 0.35, 0.25 },
    { 0.30, 0.55, 0.35 },
  },
  bank_lines = { 0x10000, 0x20000, 0x30000 },
  -- refresh() sets MemMap.view_base; phys = view_base + index
  follow_pc = function(pc)
    pc = pc or 0
    if pc >= 0x80000000 then
      -- Align window to 256 KiB containing PC (DRAM).
      return pc - (pc % (256 * 1024))
    end
    if pc >= 0x0C000000 then
      return 0x0C000000 -- PLIC window
    end
    if pc >= 0x10000000 then
      return 0x10000000 -- UART / halt
    end
    if pc >= 0x02000000 then
      return 0x02000000 -- CLINT
    end
    return 0 -- firmware ROM
  end,
  region_of = function(addr)
    if addr >= 0x80000000 then return 3 end
    if addr >= 0x02000000 then return 2 end
    return 1
  end,
  read = function(machine, addr, view_base)
    local bus = machine.bus_dev
    if not (bus and bus.read8) then return 0 end
    local phys = (view_base or 0) + addr
    if phys < 0 then phys = phys + 0x100000000 end
    return bus:read8(phys % 0x100000000)
  end,
  -- refresh() passes cpu (same as other profiles), not machine.
  get_pc = function(cpu)
    if not cpu then return 0 end
    if cpu.pc_u32 then return tonumber(cpu:pc_u32()) or 0 end
    local pc = cpu.pc
    if type(pc) == "number" then return pc end
    if pc and pc.lo ~= nil then return tonumber(pc.lo) or 0 end
    return 0
  end,
  get_sp = function(cpu)
    if cpu and cpu.get_x then
      local sp = cpu:get_x(2)
      if sp and sp.lo ~= nil then return tonumber(sp.lo) or 0 end
    end
    return 0
  end,
  marker_in_view = function(addr, view_base, mem_size)
    view_base = view_base or 0
    mem_size = mem_size or (256 * 1024)
    return addr >= view_base and addr < view_base + mem_size
  end,
  view_addr = function(addr, view_base)
    return addr - (view_base or 0)
  end,
  sp_label = "x2/sp",
}

PROFILE.gameboy = {
  id = "gameboy",
  title = "DMG",
  mem_size = 0x10000,
  addr_digits = 4,
  region_names = { "ROM", "VRAM", "RAM", "OAM", "IO", "HRAM" },
  region_colors = {
    { 0.25, 0.45, 0.70 },
    { 0.55, 0.35, 0.65 },
    { 0.30, 0.55, 0.35 },
    { 0.70, 0.45, 0.20 },
    { 0.70, 0.35, 0.25 },
    { 0.40, 0.55, 0.55 },
  },
  bank_lines = { 0x4000, 0x8000, 0xA000, 0xC000, 0xFE00, 0xFF00, 0xFF80 },
  region_of = function(addr)
    if addr < 0x8000 then return 1 end
    if addr < 0xA000 then return 2 end
    if addr < 0xFE00 then return 3 end
    if addr < 0xFF00 then return 4 end
    if addr < 0xFF80 then return 5 end
    return 6
  end,
  read = function(machine, addr)
    if machine.mmu and machine.mmu.read then
      return machine.mmu:read(addr % 0x10000)
    end
    return 0
  end,
  get_pc = function(cpu)
    return cpu and (cpu.pc or 0) or 0
  end,
  get_sp = function(cpu)
    return cpu and (cpu.sp or 0) or 0
  end,
  marker_in_view = function(addr, _view_base, mem_size)
    return addr >= 0 and addr < (mem_size or 0x10000)
  end,
  sp_label = "SP",
}

local function byte_rgb(profile, addr, val, heat)
  local idx = profile.region_of(addr)
  local base = profile.region_colors[idx] or profile.region_colors[1]
  local t = val / 255
  local lum = (val == 0) and 0.07 or (0.20 + t * 0.80)
  local band = ((val % 32) / 31) * 0.10
  local r = clamp01(base[1] * lum + band)
  local g = clamp01(base[2] * lum + band * 0.5)
  local b = clamp01(base[3] * lum)
  if heat and heat > 0 then
    local h = heat > 1 and 1 or heat
    r = r + (1.0 - r) * h
    g = g + (0.95 - g) * h
    b = b * (1 - h * 0.6)
  end
  return math.floor(r * 255 + 0.5), math.floor(g * 255 + 0.5), math.floor(b * 255 + 0.5)
end

local function fmt_addr(profile, addr)
  local n = profile.addr_digits or 4
  addr = addr % 0x100000000
  if n >= 8 then
    return string.format("%08X", addr)
  end
  if n >= 6 then
    return string.format("%06X", addr % 0x1000000)
  end
  return string.format("%04X", addr % 0x10000)
end

--- Pick column/row counts so the byte grid's aspect matches the panel, then
--- stretch-draw to fill. Returns map_w, map_h (map_w * map_h >= mem_size).
local function grid_for_panel(mem_size, avail_w, avail_h)
  avail_w = math.max(8, math.floor(avail_w))
  avail_h = math.max(8, math.floor(avail_h))
  mem_size = math.max(1, mem_size)

  local aspect = avail_w / avail_h
  local cols = math.floor(math.sqrt(mem_size * aspect) + 0.5)
  if cols < MIN_COLS then cols = MIN_COLS end
  if cols > MAX_COLS then cols = MAX_COLS end
  if cols > avail_w then cols = avail_w end
  if cols < 8 then cols = 8 end

  local rows = math.ceil(mem_size / cols)
  -- Prefer not exceeding panel pixel rows when the panel is short: widen cols.
  if rows > avail_h and avail_h >= 8 then
    cols = math.ceil(mem_size / avail_h)
    if cols < MIN_COLS then cols = MIN_COLS end
    if cols > MAX_COLS then cols = MAX_COLS end
    rows = math.ceil(mem_size / cols)
  end
  return cols, rows
end

function MemMap.new(machine_id)
  local self = setmetatable({}, MemMap)
  self.open = false
  self.image = nil
  self.accum = 0
  self.refresh_hz = 15
  self.needs_refresh = false
  self.hover_addr = nil
  self.hover_val = nil
  self.panel = { x = 0, y = 0, w = COLLAPSED_W, h = 0 }
  self.toggle = { x = 0, y = 0, w = COLLAPSED_W, h = 0 }
  self.scale_x = 1
  self.scale_y = 1
  self.prev_blob = nil
  self.heat = {}
  self.heat_decay = 1.6
  self.pc = 0
  self.sp = 0
  self.map_w = 256
  self.map_h = 256
  self.expanded_w = DEFAULT_EXPANDED_W
  self.max_expanded = MAX_EXPANDED_W
  self.dragging = false
  self._press_active = false
  self._press_toggle = false
  self._press_x = 0
  self._drag_origin_x = 0
  self._drag_origin_w = DEFAULT_EXPANDED_W
  self.hover_drag = false
  self:set_machine(machine_id or "ti83plus")
  return self
end

function MemMap:set_machine(id)
  local profile = PROFILE[id] or PROFILE.ti83plus
  if self.profile and self.profile.id == profile.id then
    return
  end
  self.profile = profile
  self.prev_blob = nil
  self.heat = {}
  self.image = nil
  self.hover_addr = nil
  self.hover_val = nil
  self.pc = 0
  self.sp = 0
  self.needs_refresh = true
  self.accum = 1
end

function MemMap:width()
  return self.open and self.expanded_w or COLLAPSED_W
end

function MemMap:clamp_expanded(w)
  local lo = MIN_EXPANDED_W
  local hi = self.max_expanded or MAX_EXPANDED_W
  if hi < lo then hi = lo end
  if w < lo then return lo end
  if w > hi then return hi end
  return math.floor(w + 0.5)
end

--- Set user width when open. Returns true if the value changed.
function MemMap:set_expanded_width(w)
  w = self:clamp_expanded(w)
  if w == self.expanded_w then return false end
  self.expanded_w = w
  return true
end

function MemMap:toggle_open()
  self.open = not self.open
  if self.open then
    self.needs_refresh = true
    self.accum = 1
  end
  return self.open
end

function MemMap:layout(x, y, h, max_expanded)
  if max_expanded then
    self.max_expanded = max_expanded
    self.expanded_w = self:clamp_expanded(self.expanded_w)
  end
  local w = self:width()
  self.panel = { x = x, y = y, w = w, h = h }
  self.toggle = { x = x, y = y, w = COLLAPSED_W, h = h }
  -- Drag grip sits on the outer (left) edge of the panel.
  self.drag_rect = {
    x = x - 2,
    y = y,
    w = DRAG_HIT + 2,
    h = h,
  }
  if not self.open then
    self.scale_x, self.scale_y = 1, 1
    self.img_x, self.img_y, self.img_w, self.img_h = x, y, 0, 0
    return
  end

  local profile = self.profile or PROFILE.ti83plus
  local avail_x = x + COLLAPSED_W
  local avail_y = y
  local avail_w = math.max(1, w - COLLAPSED_W)
  local avail_h = math.max(1, h - FOOTER_H)

  local map_w, map_h = grid_for_panel(profile.mem_size, avail_w, avail_h)
  if map_w ~= self.map_w or map_h ~= self.map_h then
    self.map_w = map_w
    self.map_h = map_h
    self.needs_refresh = true
  end

  -- Stretch to fill the column content area (non-square cells OK).
  self.scale_x = avail_w / map_w
  self.scale_y = avail_h / map_h
  self.img_w = avail_w
  self.img_h = avail_h
  self.img_x = avail_x
  self.img_y = avail_y
  self.footer_y = y + h - FOOTER_H
end

local function paint_cross(chunks, mem_size, map_w, map_pixels, addr, r, g, b)
  if addr < 0 or addr >= mem_size then return end
  local pix = rgba(r, g, b)
  local function put(a)
    if a >= 0 and a < mem_size and a < map_pixels then
      chunks[a + 1] = pix
    end
  end
  put(addr)
  put(addr - 1)
  put(addr + 1)
  put(addr - map_w)
  put(addr + map_w)
end

function MemMap:refresh(machine)
  if not machine or not machine.rom_loaded then
    self.needs_refresh = false
    return
  end

  local profile = self.profile or PROFILE.ti83plus
  local mem_size = profile.mem_size
  local map_w = self.map_w or 256
  local map_h = self.map_h or 256
  local map_pixels = map_w * map_h
  local cpu = machine.cpu
  local pc = profile.get_pc(cpu)
  local sp = profile.get_sp(cpu)
  self.pc = pc
  self.sp = sp

  local view_base = 0
  if profile.follow_pc then
    view_base = profile.follow_pc(pc) or 0
  elseif profile.view_base then
    view_base = profile.view_base
  end
  self.view_base = view_base

  local pc_mark = pc
  local sp_mark = sp
  if profile.view_addr then
    local minv = profile.marker_in_view
    if minv(pc, view_base, mem_size) then
      pc_mark = profile.view_addr(pc, view_base)
    else
      pc_mark = -1
    end
    if minv(sp, view_base, mem_size) then
      sp_mark = profile.view_addr(sp, view_base)
    else
      sp_mark = -1
    end
  end

  local prev = self.prev_blob
  local heat = self.heat
  local chunks = {}
  local snap = {}
  local read = profile.read
  local pad = rgba(12, 13, 16)

  for addr = 0, map_pixels - 1 do
    if addr < mem_size then
      local phys = view_base + addr
      local val = read(machine, addr, view_base) or 0
      snap[addr + 1] = string.char(val)
      local h = heat[addr]
      if prev and addr < #prev then
        local old = prev:byte(addr + 1)
        if old ~= val then
          h = 1
          heat[addr] = 1
        end
      end
      local r, g, b = byte_rgb(profile, phys, val, h)
      chunks[addr + 1] = rgba(r, g, b)
    else
      snap[addr + 1] = string.char(0)
      chunks[addr + 1] = pad
    end
  end

  self.prev_blob = table.concat(snap)

  paint_cross(chunks, mem_size, map_w, map_pixels, pc_mark, 40, 255, 255)
  paint_cross(chunks, mem_size, map_w, map_pixels, sp_mark, 255, 70, 220)

  local data = table.concat(chunks)
  local ok, id = pcall(love.image.newImageData, map_w, map_h, "rgba8", data)
  if ok then
    self.image = love.graphics.newImage(id)
    self.image:setFilter("nearest", "nearest")
  end
  self.needs_refresh = false
end

function MemMap:update(dt, machine)
  if not self.open then return end

  local decay = dt * self.heat_decay
  if decay > 0 then
    for addr, h in pairs(self.heat) do
      h = h - decay
      if h <= 0.02 then
        self.heat[addr] = nil
      else
        self.heat[addr] = h
      end
    end
  end

  if self.needs_refresh then
    self:refresh(machine)
    self.accum = 0
    return
  end
  self.accum = self.accum + dt
  if self.accum >= 1 / self.refresh_hz then
    self.accum = 0
    self:refresh(machine)
  end
end

function MemMap:addr_at(mx, my)
  if not self.open or self.img_w <= 0 then return nil end
  if mx < self.img_x or my < self.img_y
      or mx >= self.img_x + self.img_w or my >= self.img_y + self.img_h then
    return nil
  end
  local profile = self.profile or PROFILE.ti83plus
  local px = math.floor((mx - self.img_x) / self.scale_x)
  local py = math.floor((my - self.img_y) / self.scale_y)
  if px < 0 or py < 0 or px >= self.map_w or py >= self.map_h then return nil end
  local addr = py * self.map_w + px
  if addr >= profile.mem_size then return nil end
  return addr
end

function MemMap:hit_toggle(mx, my)
  local t = self.toggle
  return mx >= t.x and my >= t.y and mx < t.x + t.w and my < t.y + t.h
end

function MemMap:hit_drag(mx, my)
  if not self.open then return false end
  local d = self.drag_rect
  if not d then return false end
  return mx >= d.x and my >= d.y and mx < d.x + d.w and my < d.y + d.h
end

function MemMap:contains(mx, my)
  local p = self.panel
  if mx >= p.x and my >= p.y and mx < p.x + p.w and my < p.y + p.h then
    return true
  end
  return self:hit_drag(mx, my)
end

--- Returns handled, action ("toggle"|"resize"|"press"|"panel"|nil).
function MemMap:mousepressed(mx, my)
  if self.open and (self:hit_drag(mx, my) or self:hit_toggle(mx, my)) then
    -- Defer toggle vs resize until move/release (drag left edge to widen).
    self._press_active = true
    self._press_toggle = true -- click without drag → toggle
    self._press_x = mx
    self._drag_origin_x = mx
    self._drag_origin_w = self.expanded_w
    self.dragging = false
    return true, "press"
  end
  if self:hit_toggle(mx, my) then
    self:toggle_open()
    return true, "toggle"
  end
  if self:contains(mx, my) then
    return true, "panel"
  end
  return false, nil
end

--- Returns handled, action ("resize"|nil). When action is resize, caller should re-layout.
function MemMap:mousemoved(mx, my, machine)
  self.hover_drag = self:hit_drag(mx, my) or self.dragging

  if self._press_active then
    if not self.dragging and math.abs(mx - self._press_x) >= DRAG_THRESHOLD then
      self.dragging = true
      self._press_toggle = false
    end
    if self.dragging then
      -- Panel is docked on the right: drag grip left → wider.
      local nw = self._drag_origin_w + (self._drag_origin_x - mx)
      self:set_expanded_width(nw)
      return true, "resize"
    end
    return true, nil
  end

  if not self.open then
    self.hover_addr = nil
    self.hover_val = nil
    return false, nil
  end
  local idx = self:addr_at(mx, my)
  local profile = self.profile or PROFILE.ti83plus
  local view_base = self.view_base or 0
  if idx and machine and machine.rom_loaded then
    -- idx is offset in the current view window; footer shows physical address.
    self.hover_addr = view_base + idx
    self.hover_val = profile.read(machine, idx, view_base) or 0
  else
    self.hover_addr = nil
    self.hover_val = nil
  end
  return false, nil
end

--- Returns handled, action ("toggle"|"resize"|nil).
function MemMap:mousereleased(_mx, _my)
  if not self._press_active and not self.dragging then
    return false, nil
  end
  local was_dragging = self.dragging
  local want_toggle = self._press_toggle and not was_dragging
  self.dragging = false
  self._press_active = false
  self._press_toggle = false
  if was_dragging then
    return true, "resize"
  end
  if want_toggle then
    self:toggle_open()
    return true, "toggle"
  end
  return true, nil
end

function MemMap:draw()
  local p = self.panel
  local profile = self.profile or PROFILE.ti83plus
  love.graphics.setColor(0.12, 0.13, 0.15, 1)
  love.graphics.rectangle("fill", p.x, p.y, p.w, p.h)
  love.graphics.setColor(0.25, 0.28, 0.26, 1)
  love.graphics.line(p.x, p.y, p.x, p.y + p.h)

  local mx, my = love.mouse.getPosition()
  local hot = self:hit_toggle(mx, my) and not self.dragging
  love.graphics.setColor(hot and 0.28 or 0.18, hot and 0.32 or 0.2, hot and 0.28 or 0.2, 1)
  love.graphics.rectangle("fill", self.toggle.x, self.toggle.y, self.toggle.w, self.toggle.h)

  -- Resize grip accent on the left edge when open.
  if self.open then
    local grip_hot = self.hover_drag or self.dragging
    love.graphics.setColor(
      grip_hot and 0.55 or 0.30,
      grip_hot and 0.70 or 0.36,
      grip_hot and 0.55 or 0.32,
      grip_hot and 0.95 or 0.70
    )
    love.graphics.rectangle("fill", p.x, p.y, 3, p.h)
    -- Grip dots
    local cy = p.y + p.h * 0.5
    love.graphics.setColor(0.75, 0.82, 0.72, grip_hot and 1 or 0.55)
    for i = -2, 2 do
      love.graphics.rectangle("fill", p.x + 5, cy + i * 5 - 1, 2, 2)
    end
  end

  love.graphics.setColor(0.75, 0.8, 0.72, 1)
  local label = self.open and ">" or "<"
  local font = love.graphics.getFont()
  local fh = font:getHeight()
  love.graphics.print(label, self.toggle.x + (self.toggle.w - font:getWidth(label)) / 2, p.y + p.h / 2 - fh / 2)
  if not self.open then
    love.graphics.print("M", self.toggle.x + 4, p.y + 40)
    love.graphics.print("E", self.toggle.x + 4, p.y + 40 + fh)
    love.graphics.print("M", self.toggle.x + 4, p.y + 40 + fh * 2)
    return
  end

  if self.image then
    love.graphics.setColor(1, 1, 1, 1)
    love.graphics.draw(self.image, self.img_x, self.img_y, 0, self.scale_x, self.scale_y)
  end

  love.graphics.setColor(1, 1, 1, 0.20)
  local banks = profile.bank_lines
  if type(banks) == "function" then banks = banks() end
  if type(banks) == "table" then
    for _, bank in ipairs(banks) do
      local by = math.floor(bank / self.map_w) * self.scale_y
      if by >= 0 and by <= self.img_h then
        love.graphics.line(self.img_x, self.img_y + by, self.img_x + self.img_w, self.img_y + by)
      end
    end
  end

  local fy = self.footer_y or (p.y + p.h - FOOTER_H)
  love.graphics.setColor(0.10, 0.11, 0.12, 0.92)
  love.graphics.rectangle("fill", p.x + COLLAPSED_W, fy, p.w - COLLAPSED_W, FOOTER_H)
  love.graphics.setColor(0.55, 0.6, 0.55, 1)
  local sp_lab = profile.sp_label or "SP"
  if self.hover_addr and self.hover_val ~= nil then
    local a = self.hover_addr
    local reg = profile.region_names[profile.region_of(a)] or "?"
    love.graphics.print(string.format(
      "%s=%02X %s  PC=%s %s=%s",
      fmt_addr(profile, a), self.hover_val, reg,
      fmt_addr(profile, self.pc), sp_lab, fmt_addr(profile, self.sp)
    ), p.x + COLLAPSED_W + 6, fy + 3)
  else
    local base = self.view_base or 0
    if base ~= 0 then
      love.graphics.print(string.format(
        "%s @%s  %d×%d  PC=%s %s=%s",
        profile.title, fmt_addr(profile, base), self.map_w, self.map_h,
        fmt_addr(profile, self.pc), sp_lab, fmt_addr(profile, self.sp)
      ), p.x + COLLAPSED_W + 6, fy + 3)
    else
      love.graphics.print(string.format(
        "%s  %d×%d  PC=%s %s=%s",
        profile.title, self.map_w, self.map_h,
        fmt_addr(profile, self.pc), sp_lab, fmt_addr(profile, self.sp)
      ), p.x + COLLAPSED_W + 6, fy + 3)
    end
  end
end

return MemMap
