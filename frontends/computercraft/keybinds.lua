-- Keyboard -> emulator button maps for CC hosts (Game Boy today).

local M = {}

-- Emulator buttons shown in the settings dialog (order).
M.GB_BUTTONS = { "up", "down", "left", "right", "a", "b", "select", "start" }

-- Default CC key name -> emu button (keys.getName style).
M.GB_DEFAULTS = {
  up = "up",
  down = "down",
  left = "left",
  right = "right",
  z = "a",
  x = "b",
  a = "a",
  s = "b",
  -- Start: CC:T uses "enter"; older/alternate names included.
  enter = "start",
  numPadEnter = "start",
  numpadEnter = "start",
  ["return"] = "start",
  leftShift = "select",
  rightShift = "select",
  space = "select",
}

local function copy_map(src)
  local out = {}
  for k, v in pairs(src or {}) do
    out[tostring(k)] = tostring(v)
  end
  return out
end

function M.defaults_for(profile_id)
  local id = tostring(profile_id or "")
  if id == "gameboy" or id == "gameboy_ws" or id == "gb"
      or id == "gameboy_gpu" or id == "gameboy_gpu_ws" or id == "gb_gpu" then
    return copy_map(M.GB_DEFAULTS)
  end
  return {}
end

function M.buttons_for(profile_id)
  local id = tostring(profile_id or "")
  if id == "gameboy" or id == "gameboy_ws" or id == "gb"
      or id == "gameboy_gpu" or id == "gameboy_gpu_ws" or id == "gb_gpu" then
    return M.GB_BUTTONS
  end
  return nil
end

--- Normalize a CC key name from key/key_up events.
function M.normalize_key(key_name, key_code)
  -- Prefer constants: LWJGL3 renumbered codes; getName can be nil on some hosts.
  if type(key_code) == "number" and type(keys) == "table" then
    if keys.enter and key_code == keys.enter then return "enter" end
    if keys.numPadEnter and key_code == keys.numPadEnter then return "enter" end
    if keys.numpadEnter and key_code == keys.numpadEnter then return "enter" end
  end
  if type(key_name) == "string" and key_name ~= "" then
    if key_name == "return" or key_name == "numPadEnter" or key_name == "numpadEnter" then
      return "enter"
    end
    return key_name
  end
  if type(key_code) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
    local n = keys.getName(key_code)
    if n and n ~= "" then
      if n == "return" or n == "numPadEnter" or n == "numpadEnter" then
        return "enter"
      end
      return n
    end
  end
  return nil
end

--- Build host_key -> emu_btn from prefs keybinds table + defaults.
-- prefs_keybinds may be { emu_btn = host_key } (settings UI form) or already inverted.
function M.build_map(profile_id, prefs_keybinds)
  local map = M.defaults_for(profile_id)
  local buttons = M.buttons_for(profile_id)
  if not buttons then return map end

  -- Prefer prefs as emu_btn -> host_key (one primary bind per button).
  if type(prefs_keybinds) == "table" then
    local looks_emu_first = false
    for k, _ in pairs(prefs_keybinds) do
      for _, b in ipairs(buttons) do
        if k == b then looks_emu_first = true break end
      end
      if looks_emu_first then break end
    end
    if looks_emu_first then
      -- Clear default host keys that collide with reassigned buttons.
      local assigned = {}
      for emu, host in pairs(prefs_keybinds) do
        if type(emu) == "string" and type(host) == "string" and host ~= "" then
          assigned[emu] = host
        end
      end
      -- Rebuild: start from defaults, then override per emu button.
      map = M.defaults_for(profile_id)
      for emu, host in pairs(assigned) do
        -- Remove any default entries that already map to this emu button.
        for hk, eb in pairs(map) do
          if eb == emu then map[hk] = nil end
        end
        map[host] = emu
      end
    else
      -- Already host -> emu
      for hk, eb in pairs(prefs_keybinds) do
        if type(hk) == "string" and type(eb) == "string" then
          map[hk] = eb
        end
      end
    end
  end
  return map
end

--- Invert host->emu into emu->host for the settings UI (first host wins).
function M.emu_to_host(host_map, buttons)
  local out = {}
  for _, b in ipairs(buttons or {}) do
    out[b] = ""
  end
  for host, emu in pairs(host_map or {}) do
    if out[emu] == "" then
      out[emu] = host
    end
  end
  return out
end

--- Resolve a host key event to an emu button (or nil).
function M.resolve(host_map, key_name, key_code)
  local k = M.normalize_key(key_name, key_code)
  if not k then return nil end
  return host_map and host_map[k] or nil
end

--- Enable Tom's Peripherals keyboard native key/key_up events.
-- Returns side/name or nil.
function M.enable_tm_keyboard()
  if type(peripheral) ~= "table" then return nil end
  local function try_wrap(name)
    local ok, p = pcall(peripheral.wrap, name)
    if not ok or type(p) ~= "table" then return nil end
    if type(p.setFireNativeEvents) == "function" then
      local sok = pcall(function() p.setFireNativeEvents(true) end)
      if sok then return name end
    end
    return nil
  end

  if type(peripheral.find) == "function" then
    for _, ty in ipairs({ "tm_keyboard", "keyboard" }) do
      local ok, p = pcall(peripheral.find, ty)
      if ok and type(p) == "table" and type(p.setFireNativeEvents) == "function" then
        local sok = pcall(function() p.setFireNativeEvents(true) end)
        if sok then
          local n = nil
          if type(peripheral.getName) == "function" then
            n = select(1, pcall(peripheral.getName, p))
          end
          return n or ty
        end
      end
    end
  end

  if type(peripheral.getNames) == "function" then
    for _, name in ipairs(peripheral.getNames()) do
      local t = peripheral.getType(name)
      if t == "tm_keyboard" or t == "keyboard" then
        local got = try_wrap(name)
        if got then return got end
      end
    end
  end
  return nil
end

return M
