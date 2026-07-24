-- ComputerCraft host: wrapped LCD monitor + wrapped keypad monitor.
--
--   local ti83 = dofile("ti83_cc.lua")
--   ti83.run({
--     lcd = "left",           -- peripheral side (or omit to auto-find)
--     pad = "right",
--     rom = "ti83plus.rom",
--     fps = 30,
--   })

local Machine = require("core.machine")
local romutil = require("core.util.rom")
local CC = require("frontend.computercraft.cc")
local LcdView = require("frontend.computercraft.lcd_view")
local KeypadView = require("frontend.computercraft.keypad_view")

local M = {}

local function say(...)
  print(table.concat({ ... }, ""))
end

local function fail(msg)
  say("")
  say("ERROR: " .. tostring(msg))
  return nil, msg
end

local function load_rom(path)
  local data, err = CC.read_file(path)
  if not data then
    local names = CC.list_dir("")
    local hint = err or ("cannot open ROM " .. tostring(path))
    hint = hint .. "\n  Need a 512KB flash image named '" .. tostring(path) .. "'."
    hint = hint .. "\n  Copy rom/pipeline.rom (or ti83plus.rom) onto this computer."
    if names and #names > 0 then
      hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
    else
      hint = hint .. "\n  (no files listed in the computer directory)"
    end
    return nil, hint
  end
  if #data ~= romutil.FLASH_SIZE then
    return nil, string.format(
      "ROM '%s' is %d bytes; expected %d (512KB TI-83+ dump).\n"
        .. "  Use rom/pipeline.rom from the repo, or a real ti83plus.rom dump.",
      tostring(path), #data, romutil.FLASH_SIZE
    )
  end
  local validated, verr = romutil.validate(data)
  if not validated then
    return nil, verr or "ROM validate failed"
  end
  return validated
end

--- Blocking host loop on a CC computer. Ctrl+T / terminate exits cleanly.
-- Returns true on clean quit, or nil, err on startup failure (after printing).
function M.run(opts)
  opts = opts or {}

  if term and term.clear and term.setCursorPos then
    term.clear()
    term.setCursorPos(1, 1)
  end
  say("TI-83+ emulator (ComputerCraft)")
  say("--------------------------------")

  if not CC.is_cc() then
    if opts.frames and opts._machine then
      local m = opts._machine
      for _ = 1, opts.frames do
        m:run_cycles(m:cycles_per_frame(opts.fps or 30))
      end
      return m
    end
    return fail("not running inside ComputerCraft (no peripheral API)")
  end

  local rom_path = opts.rom or "ti83plus.rom"
  local fps = opts.fps or 30
  local frame_dt = 1 / fps

  say("Looking for ROM: " .. rom_path)
  local bytes, rom_err = load_rom(rom_path)
  if not bytes then
    return fail(rom_err)
  end
  say("ROM OK (" .. #bytes .. " bytes)")

  say("Resolving monitors...")
  local ok_mons, mons_or_err = pcall(CC.resolve_monitors, opts)
  if not ok_mons then
    return fail(mons_or_err)
  end
  local mons = mons_or_err
  local lcd, lcd_side = mons.lcd, mons.lcd_side
  local pad_mon, pad_side = mons.pad, mons.pad_side
  say("  lcd = " .. tostring(lcd_side))
  say("  pad = " .. tostring(pad_side))

  local machine = Machine.new()
  local ok, err = machine:load_rom_bytes(bytes)
  if not ok then
    return fail(err or "ROM load failed")
  end
  machine:reset()
  say("Machine ready @" .. fps .. " fps")
  say("Touch the keypad monitor. Ctrl+T to quit.")
  say("")

  LcdView.setup(lcd, opts)
  local lay_ok, lay = LcdView.paint(lcd, machine:framebuffer(), machine:is_display_on(), opts)
  if lay_ok then
    say(string.format(
      "LCD window %dx%d centered at (%d,%d) on %dx%d (scale %.1f)",
      LcdView.NEED_W, LcdView.NEED_H, lay.x0, lay.y0, lay.mw, lay.mh, LcdView.TEXT_SCALE
    ))
  else
    say("LCD monitor too small — need " .. tostring(lay and lay.need or "96x64")
      .. " chars at text scale " .. tostring(LcdView.TEXT_SCALE))
    say("  (add more advanced monitor blocks; resize is detected live)")
  end

  local pad = KeypadView.new(pad_mon, { side = pad_side, text_scale = opts.pad_scale })
  pad.side = pad_side or pad.side
  pad:draw()

  local function refresh_lcd()
    -- Re-apply scale in case the peripheral was replaced / resized.
    if peripheral.isPresent(lcd_side) then
      lcd = peripheral.wrap(lcd_side) or lcd
    end
    LcdView.setup(lcd, opts)
    LcdView.paint(lcd, machine:framebuffer(), machine:is_display_on(), opts)
    machine:clear_display_dirty()
  end

  local held = nil

  local function release_held()
    if not held then
      return
    end
    machine:set_key(held, false)
    held = nil
    pad:set_pressed(nil)
    pad:draw()
  end

  local function press_key(key)
    release_held()
    machine:set_key(key, true)
    held = key
    pad:set_pressed(key)
    pad:draw()
  end

  while true do
    local timer = os.startTimer(frame_dt)
    while true do
      local ev, a, b, c = os.pullEventRaw()
      if ev == "timer" and a == timer then
        break
      elseif ev == "monitor_touch" then
        local key = pad:on_touch(a, b, c)
        if key then
          press_key(key)
        end
      elseif ev == "monitor_resize" then
        if a == lcd_side then
          say("LCD monitor resized — relayout")
          refresh_lcd()
        elseif a == pad_side then
          if peripheral.isPresent(pad_side) then
            pad_mon = peripheral.wrap(pad_side) or pad_mon
            pad.mon = pad_mon
          end
          pad:relayout()
          pad:draw()
        end
      elseif ev == "peripheral" then
        -- New block / reattach: if it's our LCD side, relayout.
        if a == lcd_side then
          say("LCD peripheral attached — relayout")
          refresh_lcd()
        elseif a == pad_side then
          pad_mon = peripheral.wrap(pad_side) or pad_mon
          pad.mon = pad_mon
          pad:relayout()
          pad:draw()
        end
      elseif ev == "peripheral_detach" then
        if a == lcd_side or a == pad_side then
          if not peripheral.isPresent(lcd_side) or not peripheral.isPresent(pad_side) then
            return fail("monitor detached (" .. tostring(a) .. ")")
          end
        end
      elseif ev == "terminate" then
        release_held()
        if term and term.clear then
          term.clear()
          term.setCursorPos(1, 1)
        end
        say("Stopped.")
        return true
      end
    end

    machine:run_cycles(machine:cycles_per_frame(fps))
    release_held()
    if machine:display_dirty() then
      LcdView.paint(lcd, machine:framebuffer(), machine:is_display_on(), opts)
      machine:clear_display_dirty()
    end
  end
end

return M
