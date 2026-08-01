-- Persistent prefs for the CC host (monitor roles, theme, gate, etc.).
-- Plain ASCII line file next to the running program: ti83.prefs

local CC = require("frontends.computercraft.cc")
local Themes = require("frontends.computercraft.themes")

local M = {}

M.FILENAME = "ti83.prefs"

local VALID_ROLE = {
  lcd = true,
  pad = true,
  mem = true,
  off = true,
}

local GATE_HZ_PRESETS = { 1, 5, 20, 60, 200, 1000 }

local function program_dir()
  if type(shell) == "table" and type(shell.getRunningProgram) == "function"
    and type(fs) == "table" and type(fs.getDir) == "function" then
    local prog = shell.getRunningProgram()
    if prog then
      local dir = fs.getDir(prog)
      if dir and dir ~= "" then
        return dir
      end
    end
  end
  return ""
end

function M.path(filename)
  filename = filename or M.FILENAME
  local dir = program_dir()
  if type(fs) == "table" and fs.combine then
    return fs.combine(dir, filename)
  end
  if dir == "" then
    return filename
  end
  return dir .. "/" .. filename
end

local function write_file(path, data)
  if type(fs) == "table" and fs.open then
    local h = fs.open(path, "w")
    if not h then
      return nil, "cannot write " .. tostring(path)
    end
    h.write(data)
    h.close()
    return true
  end
  local f, err = io.open(path, "w")
  if not f then
    return nil, err or "cannot write"
  end
  f:write(data)
  f:close()
  return true
end

--- Load prefs. Returns { monitors, theme, gate_hz, keybinds, path }.
-- keybinds: emu_button -> host_key (e.g. a -> z)
-- default_theme: used when the prefs file is missing / has no theme line.
function M.load(filename, default_theme)
  local path = M.path(filename)
  local out = {
    monitors = {},
    theme = (Themes.is_valid(default_theme) and default_theme) or "classic",
    gate_hz = 20,
    keybinds = {},
    muted = false,
    path = path,
  }
  local data = CC.read_file(path)
  if not data then
    return out
  end
  for raw in (data .. "\n"):gmatch("(.-)\n") do
    local line = raw:match("^%s*(.-)%s*$") or ""
    if line ~= "" and line:sub(1, 1) ~= "#" then
      local side, role = line:match("^monitor%s+(%S+)%s+(%S+)$")
      local theme = line:match("^theme%s+(%S+)$")
      local gate_hz = line:match("^gate_hz%s+(%d+)$")
      local muted = line:match("^muted%s+(%S+)$")
      local kb_btn, kb_key = line:match("^keybind%s+(%S+)%s+(%S+)$")
      if side and role then
        role = role:lower()
        if VALID_ROLE[role] then
          out.monitors[side] = role
        end
      elseif theme and Themes.is_valid(theme) then
        out.theme = theme
      elseif gate_hz then
        local n = tonumber(gate_hz)
        if n and n > 0 then
          out.gate_hz = math.min(1000000, math.floor(n))
        end
      elseif muted then
        local m = muted:lower()
        out.muted = (m == "1" or m == "true" or m == "yes" or m == "on")
      elseif kb_btn and kb_key then
        out.keybinds[kb_btn:lower()] = kb_key
      end
    end
  end
  return out
end

local function monitors_to_map(monitors)
  local map = {}
  if not monitors then
    return map
  end
  if monitors[1] and monitors[1].side then
    for _, m in ipairs(monitors) do
      if m.side and VALID_ROLE[m.role] then
        map[tostring(m.side)] = m.role
      end
    end
  else
    for side, role in pairs(monitors) do
      if VALID_ROLE[role] then
        map[tostring(side)] = role
      end
    end
  end
  return map
end

--- Save prefs. `opts` may include monitors, theme, gate_hz, keybinds.
-- keybinds: emu_button -> host_key
function M.save(opts, filename)
  opts = opts or {}
  local map = monitors_to_map(opts.monitors)
  local sides = {}
  for side in pairs(map) do
    sides[#sides + 1] = side
  end
  table.sort(sides)

  local theme = opts.theme or "classic"
  if not Themes.is_valid(theme) then
    theme = "classic"
  end
  local gate_hz = tonumber(opts.gate_hz) or 20
  if gate_hz < 1 then gate_hz = 1 end
  if gate_hz > 1000000 then gate_hz = 1000000 end
  gate_hz = math.floor(gate_hz)

  local lines = {
    "# ti83 emulator prefs - auto-saved",
    "# monitor <side> <lcd|pad|mem|off>",
    "# theme <" .. table.concat(Themes.ORDER, "|") .. ">",
    "# gate_hz <steps per second when Gate is on>",
    "# muted <true|false>  (GB speaker)",
    "# keybind <emu_button> <cc_key_name>",
  }
  for _, side in ipairs(sides) do
    lines[#lines + 1] = "monitor " .. side .. " " .. map[side]
  end
  lines[#lines + 1] = "theme " .. theme
  lines[#lines + 1] = "gate_hz " .. tostring(gate_hz)
  if opts.muted ~= nil then
    lines[#lines + 1] = "muted " .. (opts.muted and "true" or "false")
  end

  if type(opts.keybinds) == "table" then
    local btns = {}
    for btn, host in pairs(opts.keybinds) do
      if type(btn) == "string" and type(host) == "string" and host ~= "" then
        btns[#btns + 1] = btn
      end
    end
    table.sort(btns)
    for _, btn in ipairs(btns) do
      lines[#lines + 1] = "keybind " .. btn .. " " .. opts.keybinds[btn]
    end
  end
  lines[#lines + 1] = ""

  local path = M.path(filename)
  local ok, err = write_file(path, table.concat(lines, "\n"))
  if not ok then
    return nil, err
  end
  return path
end

--- Save monitor roles, preserving theme / gate_hz / keybinds already on disk.
function M.save_monitors(monitors, filename)
  local cur = M.load(filename)
  return M.save({
    monitors = monitors,
    theme = cur.theme,
    gate_hz = cur.gate_hz,
    keybinds = cur.keybinds,
    muted = cur.muted,
  }, filename)
end

function M.next_gate_hz(current)
  current = tonumber(current) or 20
  for i, hz in ipairs(GATE_HZ_PRESETS) do
    if hz == current then
      return GATE_HZ_PRESETS[(i % #GATE_HZ_PRESETS) + 1]
    end
  end
  -- Snap to nearest higher preset, or wrap.
  for _, hz in ipairs(GATE_HZ_PRESETS) do
    if hz > current then
      return hz
    end
  end
  return GATE_HZ_PRESETS[1]
end

M.VALID_ROLE = VALID_ROLE
M.GATE_HZ_PRESETS = GATE_HZ_PRESETS

return M
