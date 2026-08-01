-- Advanced-monitor thin WebSocket host.
-- Multi-monitor LCD + keypad (no MEM). CPU runs on the LuaJIT bridge.

local CC = require("frontends.computercraft.cc")
local ControlGui = require("frontends.computercraft.control_gui")
local Themes = require("frontends.computercraft.themes")
local Prefs = require("frontends.computercraft.prefs")
local Keybinds = require("frontends.computercraft.keybinds")
local SettingsDialog = require("frontends.computercraft.settings_dialog")
local SpeakerAudio = require("frontends.computercraft.speaker_audio")
local Remote = require("frontends.computercraft.ws.remote_machine")
local Protocol = require("bridge.protocol")

local M = {}

-- WS clients: LCD + keypad only (no memory map).
local WS_ROLE_CYCLE = { "lcd", "pad", "off" }

local function say(...)
  print(table.concat({ ... }, ""))
end

local function fail(msg)
  say("")
  say("ERROR: " .. tostring(msg))
  return nil, msg
end

local function now_ms()
  if os.epoch then return os.epoch("utc") end
  return os.clock() * 1000
end

function M.run(opts)
  opts = opts or {}
  local P = opts.profile
  if not P then return fail("host_ws: profile required") end
  local Args = P.Args
  local LcdView = P.LcdView
  local KeypadView = P.KeypadView
  local role_cycle = P.role_cycle or WS_ROLE_CYCLE

  if opts.args and Args then
    local parsed, perr = Args.parse(opts.args)
    if not parsed then return fail(perr or (Args.usage_text and Args.usage_text()) or "bad args") end
    if parsed.help then
      say(Args.usage_text())
      return true
    end
    opts.url = opts.url or parsed.url
    opts.rom = opts.rom or parsed.rom
    opts.lcd = opts.lcd or parsed.lcd
    opts.pad = opts.pad or parsed.pad
    opts.theme = opts.theme or parsed.theme
    if (not opts.rom or opts.rom == "") and parsed.positional and parsed.positional[1] then
      opts.rom = parsed.positional[1]
    end
  end

  if not CC.is_cc() then
    return fail("Not running inside ComputerCraft / CC:Tweaked.")
  end

  local machine_id = Protocol.canonical_id(P.remote_machine or P.id or "ti89")
  local audio -- speaker sink (assigned after connect; GB)

  local url = opts.url or P.default_url or "ws://127.0.0.1:8765"
  say("Connecting to " .. url .. " (" .. machine_id .. ") ...")
  local machine, err = Remote.connect(url, machine_id, opts)
  if not machine then return fail(err) end

  -- Optional: upload a local cart/ROM to the bridge (Game Boy).
  if opts.rom and opts.rom ~= "" then
    if machine_id ~= "gameboy" then
      machine:close()
      return fail("--rom upload over WS is only supported for gameboy")
    end
    say("Reading ROM " .. tostring(opts.rom) .. " ...")
    local data, rerr = CC.read_file(opts.rom)
    if not data then
      machine:close()
      return fail(rerr or ("cannot read " .. tostring(opts.rom)))
    end
    local base = tostring(opts.rom):match("([^/\\]+)$") or tostring(opts.rom)
    say(string.format("Uploading %s (%d bytes) ...", base, #data))
    local ok_up, uerr = machine:load_rom_bytes(data, base)
    if not ok_up then
      machine:close()
      return fail(uerr or "ROM upload failed")
    end
    say("ROM loaded on bridge.")
  else
    -- Allow LCD frames (bridge holds them after hello until ready).
    machine:send_ready()
    if machine_id == "gameboy" and not machine.rom_loaded then
      say("Bridge has no cart yet -- start with --rom PATH to upload one.")
    end
  end

  local prefs = Prefs.load(P.prefs_file or "ti_ws.prefs", P.default_theme)
  local theme_id = Themes.is_valid(opts.theme) and opts.theme
    or (Themes.is_valid(prefs.theme) and prefs.theme)
    or P.default_theme
    or "classic"

  local profile_id = P.id or machine_id
  local keybind_buttons = Keybinds.buttons_for(profile_id)
  local keybind_map = keybind_buttons
    and Keybinds.build_map(profile_id, prefs.keybinds) or nil
  local prefs_keybinds = prefs.keybinds or {}
  if keybind_map and keybind_buttons and not next(prefs_keybinds) then
    prefs_keybinds = Keybinds.emu_to_host(keybind_map, keybind_buttons)
  end
  local kb_held = {}

  local tm_kb = Keybinds.enable_tm_keyboard()
  if tm_kb then
    say("tm_keyboard native events ON (" .. tostring(tm_kb) .. ")")
  end

  -- views[side] = { side=, mon=, role=, painter=, pad= }
  local views = {}
  local view_order = {}
  local monitor_aliases = {}
  local any_lcd, any_pad = false, false
  local identify_on = false
  local remembered = prefs.monitors or {}

  local function recompute_roles()
    any_lcd, any_pad = false, false
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        if v.role == "lcd" then
          any_lcd = true
        elseif v.role == "pad" then
          any_pad = true
        end
      end
    end
  end

  local function gui_monitor_list()
    local list = {}
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        list[#list + 1] = { side = side, role = v.role }
      end
    end
    return list
  end

  local function remember_alias(side_name, preferred)
    if side_name and preferred and side_name ~= preferred then
      monitor_aliases[side_name] = preferred
    end
  end

  local function rebuild_aliases()
    monitor_aliases = {}
    local names = peripheral.getNames()
    for _, name in ipairs(names) do
      if peripheral.getType(name) == "monitor" and CC.is_side_name(name) then
        local preferred = CC.canonical_monitor_name(name, names)
        if preferred and preferred ~= name then
          remember_alias(name, preferred)
        end
      end
    end
  end

  local function resolve_view(name)
    local key = monitor_aliases[name] or name
    local v = views[key]
    if v then return v, key end
    v = views[name]
    if v then return v, name end
    return nil, nil
  end

  local function lcd_painter_opts()
    local t = Themes.painter_opts and Themes.painter_opts(theme_id) or {}
    local o = {}
    for k, v in pairs(t) do o[k] = v end
    o.text_scale = opts.lcd_scale or P.lcd_scale or LcdView.TEXT_SCALE or 0.5
    return o
  end

  local function bind_view(v)
    v.painter = nil
    v.pad = nil
    if v.role == "lcd" then
      v.painter = LcdView.new_painter(v.mon, lcd_painter_opts())
      local lay = v.painter:setup()
      if lay and lay.ok then
        v.painter.force = true
      else
        say(string.format(
          "warn: LCD %s too small (have %sx%s)",
          tostring(v.side),
          tostring(lay and lay.mw), tostring(lay and lay.mh)))
      end
    elseif v.role == "pad" then
      v.pad = KeypadView.new(v.mon, {
        side = v.side,
        text_scale = opts.pad_scale or P.pad_scale,
      })
      v.pad.side = v.side
      v.pad:draw()
    else
      local C = CC.colors()
      if v.mon.setTextScale then v.mon.setTextScale(1) end
      v.mon.setBackgroundColor(C.black)
      v.mon.setTextColor(C.gray)
      v.mon.clear()
      v.mon.setCursorPos(1, 1)
      v.mon.write("OFF")
    end
  end

  local function add_monitor(side, role)
    if views[side] then return views[side] end
    if not peripheral.isPresent(side) or peripheral.getType(side) ~= "monitor" then
      return nil
    end
    local mon = peripheral.wrap(side)
    if not mon then return nil end
    -- Map native "mem" prefs to off for WS.
    if role == "mem" or role == "face" then
      role = (role == "face") and "lcd" or "off"
    end
    local v = { side = side, mon = mon, role = role or "pad" }
    views[side] = v
    view_order[#view_order + 1] = side
    bind_view(v)
    recompute_roles()
    return v
  end

  local function remove_monitor(side)
    if not views[side] then return end
    views[side] = nil
    local next_order = {}
    for _, s in ipairs(view_order) do
      if s ~= side then next_order[#next_order + 1] = s end
    end
    view_order = next_order
    recompute_roles()
  end

  local function persist_prefs()
    for _, m in ipairs(gui_monitor_list()) do
      remembered[m.side] = m.role
    end
    prefs.monitors = remembered
    prefs.theme = theme_id
    prefs.keybinds = prefs_keybinds
    prefs.muted = audio and audio.muted or prefs.muted
    Prefs.save({
      monitors = remembered,
      theme = theme_id,
      gate_hz = prefs.gate_hz,
      keybinds = prefs_keybinds,
      muted = prefs.muted,
    }, P.prefs_file or "ti_ws.prefs")
  end

  local function persist_monitors()
    return persist_prefs()
  end

  local function toggle_monitor(side)
    local v = views[side]
    if not v then return end
    v.role = ControlGui.next_role(v.role, role_cycle)
    remembered[side] = v.role
    bind_view(v)
    recompute_roles()
    persist_monitors()
  end

  local function seed_monitors()
    rebuild_aliases()
    local found = CC.find_monitors()
    if #found == 0 then
      return fail("no monitors attached (need at least one)")
    end

    local forced = {}
    local function force_role(spec, role)
      if not spec or spec == "" then return end
      local okw, _, side = pcall(CC.wrap_monitor, spec, role)
      if okw and side then
        forced[CC.canonical_monitor_name(side) or side] = role
      else
        forced[CC.canonical_monitor_name(spec) or spec] = role
      end
    end
    if opts.lcd then force_role(opts.lcd, "lcd") end
    if opts.pad then force_role(opts.pad, "pad") end

    for i, f in ipairs(found) do
      local role = forced[f.side] or remembered[f.side]
      if not role then
        for name, r in pairs(remembered) do
          if name ~= f.side and CC.is_side_name(name) and CC.monitors_same(name, f.side) then
            role = r
            break
          end
        end
      end
      if not role then
        role = (i == 1) and "lcd" or "pad"
      end
      if role == "mem" then role = "off" end
      if role == "face" then role = "lcd" end
      remembered[f.side] = role
      add_monitor(f.side, role)
    end
    persist_monitors()
    return true
  end

  local seeded, serr = seed_monitors()
  if not seeded then
    machine:close()
    return fail(serr or "monitor setup failed")
  end

  local function apply_theme(id)
    if not Themes.is_valid(id) then return end
    theme_id = id
    local t = Themes.painter_opts and Themes.painter_opts(theme_id) or {}
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v and v.painter and v.painter.set_colors then
        v.painter:set_colors(t)
        v.painter.force = true
      end
    end
    machine._dirty = true
    if machine.lcd then machine.lcd._dirty = true end
  end

  local function paint_identify_monitor(v)
    if not v or not v.mon then return end
    local C = CC.colors()
    local mon = v.mon
    if mon.setTextScale then mon.setTextScale(1) end
    mon.setBackgroundColor(C.black)
    mon.setTextColor(C.yellow)
    mon.clear()
    local w, h = mon.getSize()
    local label = tostring(v.side)
    local x = math.max(1, math.floor((w - #label) / 2) + 1)
    local y = math.max(1, math.floor(h / 2))
    mon.setCursorPos(x, y)
    mon.write(label)
  end

  local function paint_views(force_lcd)
    if identify_on then
      for _, side in ipairs(view_order) do
        paint_identify_monitor(views[side])
      end
      return
    end
    machine:apply_pending_frame()
    local need_lcd = force_lcd or machine:display_dirty()
    if need_lcd and any_lcd then
      local fb = machine:framebuffer()
      local on = machine:is_display_on()
      for _, side in ipairs(view_order) do
        local v = views[side]
        if v and v.painter then
          v.painter:paint(fb, on)
        end
      end
      machine:clear_display_dirty()
    elseif machine:display_dirty() and not any_lcd then
      machine:clear_display_dirty()
    end
  end

  local function sync_pad_pressed(name)
    if not any_pad then return end
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v and v.pad and v.pad.set_pressed then
        v.pad:set_pressed(name)
        v.pad:draw()
      end
    end
  end

  local want_audio = machine_id == "gameboy" or P.enable_audio
  audio = want_audio and SpeakerAudio.new({
    muted = prefs.muted and true or false,
  }) or nil
  if audio and not audio.speaker then
    say("No speaker attached - attach a speaker for GB audio.")
  end

  local gui = ControlGui.new({
    monitors = gui_monitor_list(),
    cycles_per_tick = 0,
    paused = false,
    gate_active = false,
    gate_hz = 20,
    theme = theme_id,
    show_settings = not not keybind_map,
    show_gate = false, -- gate is local CC pacing; not used over WS
    show_mute = not not audio,
    muted = audio and audio.muted or false,
    message = string.format(
      "KEYS=keybinds  SND=mute  |  %d mon  lcd=%s pad=%s",
      #view_order, tostring(any_lcd), tostring(any_pad)
    ),
    -- Prefer profile cart filter (GB); else a WS-only hint.
    file_filter = P.file_filter or {
      empty_hint = "(WS mode: pass --rom or click a cart to upload)",
      classify = function() return nil end,
    },
  })
  -- Never print() after gui:draw — CC scrolls the term and desyncs hitboxes
  -- (X button + monitor chips become unclickable).
  gui:draw()
  paint_views(true)

  -- Decode at most `budget` WS PCM chunks (never on speaker_audio_empty).
  local function flush_audio(budget)
    if not audio or not machine.take_audio then return end
    budget = budget or 1
    if budget > 2 then budget = 2 end
    for _ = 1, budget do
      if not audio:needs_data() then break end
      local pcm = machine:take_audio()
      if not pcm then break end
      audio:push_pcm(pcm)
    end
    -- Drop backlog so sound tracks the newest frame (coalesced video).
    if audio.trim_to then
      audio:trim_to(audio.play_samples or 4800)
    end
    audio:pump()
  end

  local function audio_critical()
    return audio and not audio.muted and audio.primed and audio.playing
      and audio.queued_samples < 1
  end

  local held, held_until = nil, 0
  local HOLD_UI_MS = 120
  -- ~15 fps steady; wake on pending WS frames (dirty is only set after apply).
  local paint_ms, last_paint = 66, now_ms()
  local tick = os.startTimer(0.05)
  local ws_url = machine.url

  local function release_held_ui()
    if not held then return end
    held = nil
    if not next(kb_held) then
      sync_pad_pressed(nil)
    end
  end

  local function press_key(key)
    if not key then return end
    if held == key or kb_held[key] then return end
    local ok, kerr = machine:tap_key(key)
    if not ok then
      say("key send failed: " .. tostring(kerr))
      return
    end
    held = key
    held_until = now_ms() + HOLD_UI_MS
    sync_pad_pressed(key)
  end

  local function kb_down(btn)
    if not btn or kb_held[btn] then return end
    kb_held[btn] = true
    if held == btn then
      held = nil
      held_until = 0
    end
    local ok, kerr = machine:set_key(btn, true)
    if not ok then
      say("key send failed: " .. tostring(kerr))
      kb_held[btn] = nil
      return
    end
    sync_pad_pressed(btn)
  end

  local function kb_up(btn)
    if not btn or not kb_held[btn] then return end
    kb_held[btn] = nil
    machine:set_key(btn, false)
    if not next(kb_held) and held ~= btn then
      sync_pad_pressed(nil)
    end
  end

  while true do
    local ev, a, b, c = os.pullEventRaw()
    if ev == "timer" and a == tick then
      local t = now_ms()
      if held and t >= held_until then release_held_ui() end
      -- LCD first when a frame is due — never let an empty speaker queue
      -- starve paints (that is the normal state while a buffer is playing).
      local have_frame = machine:has_pending_frame()
        or machine:display_dirty()
        or identify_on
      if have_frame and (t - last_paint) >= paint_ms then
        paint_views(false)
        last_paint = t
        flush_audio(1)
      else
        flush_audio(audio_critical() and 2 or 1)
      end
      tick = os.startTimer(0.05)
    elseif ev == "websocket_message" then
      if not ws_url or a == ws_url or tostring(a) == tostring(ws_url) then
        -- Stash only — never unpack PCM here (delays speaker_audio_empty).
        machine:handle_raw(b, c)
      end
    elseif ev == "speaker_audio_empty" then
      -- Instant play of already-staged PCM only (no decode on this event).
      if audio then audio:on_empty() end
    elseif ev == "websocket_closed" then
      say("WebSocket closed")
      release_held_ui()
      machine:close()
      break
    elseif ev == "monitor_touch" then
      local v = resolve_view(a)
      if v and v.role == "pad" and v.pad then
        local key
        if v.pad.on_touch then
          key = v.pad:on_touch(a, b, c)
        else
          key = v.pad:hit(b, c)
        end
        if key then press_key(key) end
      end
    elseif ev == "monitor_resize" then
      local v = resolve_view(a)
      if v and (v.role == "lcd" or v.role == "pad") then
        bind_view(v)
        if v.role == "lcd" then
          machine._dirty = true
          if machine.lcd then machine.lcd._dirty = true end
          paint_views(true)
        end
      end
    elseif ev == "peripheral" then
      local ptype = peripheral.getType(a)
      if ptype == "tm_keyboard" or ptype == "keyboard" then
        local name = Keybinds.enable_tm_keyboard()
        if name then
          gui:set_message("tm_keyboard native events ON", true)
          gui:draw()
        end
      elseif ptype == "monitor" then
        rebuild_aliases()
        local preferred = CC.prefer_monitor_name and CC.prefer_monitor_name(a) or a
        local canonical = CC.canonical_monitor_name(a)
        if canonical then remember_alias(a, canonical) end
        preferred = canonical or preferred
        if not views[preferred] then
          -- Drop duplicate side-name views for the same panel.
          for side, v in pairs(views) do
            if side ~= preferred and CC.monitors_same(side, preferred) then
              remembered[preferred] = remembered[preferred] or v.role
              remove_monitor(side)
            end
          end
          local role = remembered[preferred] or remembered[a] or "pad"
          if role == "mem" then role = "off" end
          if role == "face" then role = "lcd" end
          add_monitor(preferred, role)
          persist_monitors()
          gui:set_monitors(gui_monitor_list())
          gui:set_message("Attached " .. preferred, true)
          gui:draw()
          if identify_on then
            paint_identify_monitor(views[preferred])
          elseif views[preferred] and views[preferred].role == "lcd" then
            paint_views(true)
          end
        end
      end
    elseif ev == "peripheral_detach" then
      monitor_aliases[a] = nil
      local v = views[a]
      if v then
        remembered[a] = v.role
        remove_monitor(a)
      else
        for side, vv in pairs(views) do
          if CC.monitors_same(side, a) then
            remembered[side] = vv.role
            remove_monitor(side)
            break
          end
        end
      end
      -- Prefer surviving alias for the same panel.
      for _, f in ipairs(CC.find_monitors()) do
        if not views[f.side] then
          local role = remembered[f.side] or "pad"
          if role == "mem" then role = "off" end
          add_monitor(f.side, role)
        end
      end
      persist_monitors()
      gui:set_monitors(gui_monitor_list())
      gui:draw()
      if #view_order == 0 then
        release_held_ui()
        machine:close()
        return fail("all monitors detached")
      end
      paint_views(true)
    elseif ev == "mouse_click" then
      local act = gui:click(b, c)
      if act and act.action == "quit" then
        release_held_ui()
        persist_monitors()
        machine:close()
        if term and term.setCursorBlink then term.setCursorBlink(false) end
        if term and term.clear then
          term.setBackgroundColor(CC.colors().black)
          term.clear()
          term.setCursorPos(1, 1)
        end
        say("Stopped.")
        break
      elseif act and act.action == "toggle" then
        toggle_monitor(act.side)
        local v = views[act.side]
        gui:set_monitors(gui_monitor_list())
        if v then
          gui:set_message(string.format("%s -> %s", act.side, v.role:upper()), true)
        else
          gui:set_message(tostring(act.side) .. " toggled", true)
        end
        gui:draw()
        paint_views(true)
      elseif act and act.action == "identify" then
        identify_on = not not act.on
        gui:set_message(identify_on
          and "Identify ON - side name on each monitor"
          or "Identify OFF", true)
        gui:draw()
        if identify_on then
          for _, side in ipairs(view_order) do
            paint_identify_monitor(views[side])
          end
        else
          for _, side in ipairs(view_order) do
            bind_view(views[side])
          end
          paint_views(true)
        end
      elseif act and act.action == "pause" then
        local paused = act.paused
        machine:send({ t = paused and "pause" or "resume", v = Protocol.VERSION })
        gui:set_run_state({ paused = paused })
        gui:set_message(paused and "Paused (remote)" or "Running (remote)", true)
        gui:draw()
      elseif act and act.action == "mute" then
        if audio then
          audio:set_muted(act.muted)
          gui:set_muted(audio.muted)
          persist_prefs()
          gui:set_message(audio.muted and "Audio muted" or "Audio on (speaker)", true)
          gui:draw()
        end
      elseif act and act.action == "step" then
        machine:step_instruction()
        paint_views(true)
      elseif act and act.action == "redraw" then
        paint_views(true)
        gui:draw()
      elseif act and act.action == "theme" then
        apply_theme(act.theme or theme_id)
        gui:set_run_state({ theme = theme_id })
        persist_prefs()
        gui:draw()
        paint_views(true)
      elseif act and act.action == "settings" then
        if keybind_map and keybind_buttons then
          local result = SettingsDialog.run({
            title = "Game Boy Keybinds",
            buttons = keybind_buttons,
            host_map = keybind_map,
          })
          if result then
            prefs_keybinds = result
            keybind_map = Keybinds.build_map(profile_id, prefs_keybinds)
            persist_prefs()
            gui:set_message("Keybinds saved", true)
          else
            gui:set_message("Keybinds unchanged", true)
          end
          gui:draw()
          paint_views(true)
        end
      elseif act and act.action == "file" then
        local file = act.file
        if file and (file.kind == "cart" or (file.name and tostring(file.name):lower():match("%.gb$"))) then
          local path = file.path or file.name
          gui:set_message("Uploading " .. tostring(file.name) .. "...", true)
          gui:draw()
          local data, rerr = CC.read_file(path)
          if not data then
            gui:set_message(tostring(rerr or "cannot read cart"), false)
            gui:draw()
          else
            local ok_up, uerr = machine:load_rom_bytes(data, file.name, { quiet = true })
            if not ok_up then
              gui:set_message(tostring(uerr or "ROM upload failed"), false)
              gui:draw()
            else
              gui:set_message("Loaded " .. tostring(file.name), true)
              gui:draw()
              paint_views(true)
            end
          end
        else
          gui:set_message("WS mode: click a .gb cart to upload", false)
          gui:draw()
        end
      elseif gui.dirty_status or gui.dirty then
        gui:draw()
      end
    elseif ev == "char" then
      if gui:gate_char(a) then
        gui:draw_status_only()
      end
    elseif ev == "key" then
      -- a=keycode, b=is_held (repeat). Only the first press starts a hold.
      local key_name = a
      if type(a) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
        key_name = keys.getName(a) or a
      end
      if gui.gate_hz_editing then
        local result = gui:gate_key(key_name, a)
        if result == "commit" then
          gui:commit_gate_edit()
          gui:draw_status_only()
        elseif result then
          gui:draw_status_only()
        end
      elseif keybind_map and b ~= true then
        local btn = Keybinds.resolve(keybind_map, key_name, a)
        if btn then
          kb_down(btn)
        end
      end
    elseif ev == "key_up" then
      if keybind_map and not gui.gate_hz_editing then
        local key_name = a
        if type(a) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
          key_name = keys.getName(a) or a
        end
        local btn = Keybinds.resolve(keybind_map, key_name, a)
        if btn then
          kb_up(btn)
        end
      end
    elseif ev == "mouse_scroll" then
      if type(a) == "number" and gui.scroll_by then
        gui:scroll_by(a > 0 and 1 or -1)
        gui:draw()
      end
    elseif ev == "term_resize" then
      gui:draw()
    elseif ev == "terminate" then
      release_held_ui()
      persist_monitors()
      machine:close()
      break
    end
  end
  return true
end

return M
