-- Modal keybind settings dialog for CC hosts (Game Boy).

local CC = require("frontends.computercraft.cc")
local Keybinds = require("frontends.computercraft.keybinds")

local M = {}

local function colors()
  return CC.colors()
end

local function fill_row(y, w, bg, fg, text)
  if not term then return end
  term.setBackgroundColor(bg)
  term.setTextColor(fg)
  term.setCursorPos(1, y)
  local s = tostring(text or "")
  if #s < w then
    s = s .. string.rep(" ", w - #s)
  elseif #s > w then
    s = s:sub(1, w)
  end
  term.write(s)
end

--- Run modal dialog.
-- opts: { buttons=, host_map=, title= }
-- Returns updated emu_btn -> host_key table, or nil if cancelled.
function M.run(opts)
  opts = opts or {}
  local buttons = opts.buttons or Keybinds.GB_BUTTONS
  local host_map = opts.host_map or Keybinds.GB_DEFAULTS
  local binds = Keybinds.emu_to_host(host_map, buttons)
  local title = opts.title or "Keybinds"
  local selected = 1
  local waiting = false
  local message = "Enter=rebind  R=clear  D=defaults  Q=save  X=cancel"
  local message_ok = true

  local function draw()
    local C = colors()
    local w, h = term.getSize()
    term.setBackgroundColor(C.black)
    term.clear()
    term.setCursorBlink(false)
    fill_row(1, w, C.gray, C.white, " " .. title)
    fill_row(2, w, C.black, C.lightGray, " Keyboard keys fire the same pad path as monitor taps.")

    local y0 = 4
    for i, btn in ipairs(buttons) do
      local y = y0 + i - 1
      if y >= h - 2 then break end
      local host = binds[btn] or ""
      if host == "" then host = "(none)" end
      local label = string.format("  %-8s  ->  %s", btn:upper(), host)
      local bg, fg = C.black, C.white
      if i == selected then
        if waiting then
          bg, fg = C.yellow, C.black
          label = string.format("  %-8s  ->  press a key...", btn:upper())
        else
          bg, fg = C.blue, C.white
        end
      end
      fill_row(y, w, bg, fg, label)
    end

    fill_row(h - 1, w, message_ok and C.black or C.red,
      message_ok and C.lime or C.white, " " .. message)
    fill_row(h, w, C.gray, C.black, " Up/Down  Enter rebind  R clear  D defaults  Q save  X cancel")
  end

  draw()
  while true do
    local ev = { os.pullEventRaw() }
    local e = ev[1]
    if e == "terminate" then
      return nil
    end

    if waiting then
      if e == "key" then
        local name = Keybinds.normalize_key(
          (type(keys) == "table" and keys.getName and keys.getName(ev[2])) or ev[2],
          ev[2])
        if name == "escape" then
          waiting = false
          message = "Rebind cancelled"
          message_ok = false
          draw()
        elseif name and name ~= "" then
          local btn = buttons[selected]
          for _, b2 in ipairs(buttons) do
            if binds[b2] == name then binds[b2] = "" end
          end
          binds[btn] = name
          waiting = false
          message = "Bound " .. btn:upper() .. " -> " .. name
          message_ok = true
          draw()
        end
      end
    else
      if e == "key" then
        local code = ev[2]
        local name = (type(keys) == "table" and keys.getName and keys.getName(code)) or ""
        if name == "up" then
          selected = math.max(1, selected - 1)
          draw()
        elseif name == "down" then
          selected = math.min(#buttons, selected + 1)
          draw()
        elseif name == "enter" or name == "numPadEnter" or name == "numpadEnter"
            or name == "return"
            or (type(keys) == "table" and keys.enter and code == keys.enter)
            or (type(keys) == "table" and keys.numPadEnter and code == keys.numPadEnter)
            or (type(keys) == "table" and keys.numpadEnter and code == keys.numpadEnter) then
          waiting = true
          message = "Press key for " .. buttons[selected]:upper() .. " (Esc cancel)"
          message_ok = true
          draw()
        elseif name == "r" then
          binds[buttons[selected]] = ""
          message = "Cleared " .. buttons[selected]:upper()
          message_ok = true
          draw()
        elseif name == "d" then
          local def = Keybinds.emu_to_host(Keybinds.defaults_for("gameboy"), buttons)
          for _, btn in ipairs(buttons) do
            binds[btn] = def[btn] or ""
          end
          message = "Restored defaults"
          message_ok = true
          draw()
        elseif name == "q" then
          return binds
        elseif name == "x" or name == "escape" then
          return nil
        end
      elseif e == "mouse_click" then
        local y = ev[4]
        local y0 = 4
        local idx = y - y0 + 1
        if idx >= 1 and idx <= #buttons then
          selected = idx
          waiting = true
          message = "Press key for " .. buttons[selected]:upper() .. " (Esc cancel)"
          message_ok = true
          draw()
        end
      end
    end
  end
end

return M
