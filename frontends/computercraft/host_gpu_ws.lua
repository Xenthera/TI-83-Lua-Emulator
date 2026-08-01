-- Tom's GPU face — thin WebSocket client (no local emu).
-- Profile supplies Face / LcdView / KeypadView / Args / remote_machine.

local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local ControlGui = require("frontends.computercraft.control_gui")
local Themes = require("frontends.computercraft.themes")
local Prefs = require("frontends.computercraft.prefs")
local Keybinds = require("frontends.computercraft.keybinds")
local SettingsDialog = require("frontends.computercraft.settings_dialog")
local SpeakerAudio = require("frontends.computercraft.speaker_audio")
local Remote = require("frontends.computercraft.ws.remote_machine")
local Protocol = require("bridge.protocol")

local M = {}

local function say(...)
  print(table.concat({ ... }, ""))
end

local function fail(msg)
  say("")
  say(tostring(msg))
  return nil, msg
end

local function now_ms()
  if os.epoch then return os.epoch("utc") end
  return os.clock() * 1000
end

function M.run(opts)
  opts = opts or {}
  local P = opts.profile
  if not P then
    return fail("host_gpu_ws: opts.profile required")
  end
  local Args = P.Args
  local Face = P.Face
  local LcdView = P.LcdView
  local KeypadView = P.KeypadView
  if not Args or not Face or not LcdView or not KeypadView then
    return fail("host_gpu_ws: profile needs Args, Face, LcdView, KeypadView")
  end

  if opts.args then
    local parsed, perr = Args.parse(opts.args)
    if not parsed then return fail(perr or Args.usage_text()) end
    if parsed.help then
      say(Args.usage_text())
      return true
    end
    opts.url = opts.url or parsed.url
    opts.rom = opts.rom or parsed.rom
    opts.gpu = opts.gpu or parsed.gpu
    opts.face_scale = opts.face_scale or parsed.face_scale
    if (not opts.rom or opts.rom == "") and parsed.positional and parsed.positional[1]
        and not tostring(parsed.positional[1]):match("^ws") then
      opts.rom = parsed.positional[1]
    end
  end

  if opts.help then
    say(Args.usage_text())
    return true
  end

  if not CC.is_cc() then
    return fail("Not running inside ComputerCraft / CC:Tweaked.")
  end

  local remote_id = Protocol.canonical_id(P.remote_machine or P.id) or "ti89"
  local url = opts.url or P.default_url or "ws://127.0.0.1:8765"
  say("Connecting to " .. url .. " (" .. remote_id .. ") ...")
  local machine, err = Remote.connect(url, remote_id, opts)
  if not machine then
    return fail(err or "WebSocket connect failed")
  end

  -- Optional: upload a local cart/ROM to the bridge (Game Boy).
  if opts.rom and opts.rom ~= "" then
    if remote_id ~= "gameboy" then
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
    if machine.send_ready then machine:send_ready() end
    if remote_id == "gameboy" and not machine.rom_loaded then
      say("Bridge has no cart yet -- start with --rom PATH to upload one.")
    end
  end

  local gpu, gpu_side = Gpu.resolve(opts)
  if not gpu then
    machine:close()
    return fail(gpu_side)
  end

  local res = 64 -- always setSize(64)
  local gw, gh, bw, bh = Gpu.setup(gpu, res)
  if not gw or gw < 1 or gh < 1 then
    machine:close()
    return fail("GPU empty / setup failed")
  end

  local prefs_file = P.prefs_file or "gpu_ws.prefs"
  local prefs = Prefs.load(prefs_file, P.default_theme)
  local theme_id = Themes.is_valid(opts.theme) and opts.theme
    or (Themes.is_valid(prefs.theme) and prefs.theme)
    or P.default_theme
    or "titanium"
  local paused = false
  local last_tick_ms = now_ms()
  local cycles_per_tick = opts.cycles_per_tick or 400000
  local profile_id = P.id or "gameboy_gpu_ws"

  local keybind_buttons = Keybinds.buttons_for(profile_id)
  local keybind_map = (P.enable_keybinds and keybind_buttons)
    and Keybinds.build_map(profile_id, prefs.keybinds) or nil
  local prefs_keybinds = nil
  if keybind_map and keybind_buttons then
    prefs_keybinds = Keybinds.emu_to_host(keybind_map, keybind_buttons)
  end
  local kb_held = {}

  local want_audio = remote_id == "gameboy" or P.enable_audio
  local audio = want_audio and SpeakerAudio.new({
    muted = prefs.muted and true or false,
  }) or nil
  if audio and not audio.speaker then
    say("No speaker attached - attach a speaker for GB audio.")
  end

  local function persist_prefs()
    prefs.theme = theme_id
    prefs.muted = audio and audio.muted or prefs.muted
    if prefs_keybinds then prefs.keybinds = prefs_keybinds end
    return Prefs.save(prefs, prefs_file)
  end

  local face_scale = math.max(1, math.floor(tonumber(opts.face_scale) or 1))
  local face = Face.new(gpu)
  local laid = face:layout(gw, gh, { scale = face_scale })
  if not laid or face.lcd_rect.w < 8 then
    machine:close()
    return fail(string.format("GPU screen too small: %dx%d", gw, gh))
  end
  local lcd = LcdView.new(gpu, face.lcd_rect)
  lcd:set_bounds(gw, gh)
  lcd:set_cell(face.lcd_cell or 2)
  local function apply_lcd_theme(id)
    if lcd.set_palette and Themes.gb_gpu_palette then
      lcd:set_palette(Themes.gb_gpu_palette(id))
    end
  end
  apply_lcd_theme(theme_id)
  local pad = KeypadView.new(gpu)
  pad:set_bounds(gw, gh)
  pad:layout(face.pad_rect.x, face.pad_rect.y, face.pad_rect.w, face.pad_rect.h)

  local function full_redraw(force_lcd)
    face:draw_chrome()
    pad:draw()
    machine:apply_pending_frame()
    if force_lcd or machine:display_dirty() then
      lcd:paint(machine:framebuffer(), machine:is_display_on())
      machine:clear_display_dirty()
    end
    Gpu.sync(gpu)
  end

  local function paint_lcd_only()
    machine:apply_pending_frame()
    if not machine:display_dirty() then return end
    lcd:paint(machine:framebuffer(), machine:is_display_on())
    machine:clear_display_dirty()
    Gpu.sync(gpu)
  end

  say(P.boot_label or "GPU face (remote): starting...")
  say(string.format("GPU %s  %dx%d  size=64  remote %s", tostring(gpu_side), gw, gh, url))
  full_redraw(true)

  local function flush_audio(budget)
    if not audio or not machine.take_audio then return end
    budget = budget or 1
    if budget > 2 then budget = 2 end
    for _ = 1, budget do
      if audio.needs_data and not audio:needs_data() then break end
      local pcm = machine:take_audio()
      if not pcm then break end
      audio:push_pcm(pcm)
    end
    if audio.trim_to then
      audio:trim_to(audio.play_samples or 4800)
    end
    audio:pump()
  end

  local function audio_critical()
    return audio and not audio.muted and audio.primed and audio.playing
      and audio.queued_samples < 1
  end

  local gui = ControlGui.new({
    monitors = {},
    cycles_per_tick = cycles_per_tick,
    paused = paused,
    gate_active = false,
    gate_hz = 20,
    theme = theme_id,
    show_settings = not not keybind_map,
    show_gate = false,
    show_mute = not not audio,
    muted = audio and audio.muted or false,
    file_filter = P.file_filter or {
      empty_hint = "(WS mode: pass --rom or click a .gb to upload)",
      classify = function(lower)
        if lower:match("%.gb$") then return "cart" end
        return nil
      end,
    },
    message = "KEYS=keybinds  SND=mute  |  GPU/WS  |  click CART to upload",
  })
  gui:draw()

  local held = nil
  local held_until = 0
  local HOLD_UI_MS = 120
  local ws_url = machine.url
  -- Steady ~15 fps — GPU shade paint is heavy; bursts feel worse than a lower rate.
  local paint_ms = 66
  local last_paint = now_ms()
  local tick = os.startTimer(0.05)

  local function sync_pad(name)
    pad:set_pressed(name)
    pad:draw()
    Gpu.sync(gpu)
  end

  local function release_held_ui()
    if not held then return end
    held = nil
    if not next(kb_held) then sync_pad(nil) end
  end

  local function press_key(key)
    if not key then return end
    if held == key or kb_held[key] then return end
    local ok, err = machine:tap_key(key)
    if not ok then
      say("key send failed: " .. tostring(err))
      return
    end
    held = key
    held_until = now_ms() + HOLD_UI_MS
    sync_pad(key)
  end

  local function kb_down(btn)
    if not btn or kb_held[btn] then return end
    kb_held[btn] = true
    if held == btn then held = nil; held_until = 0 end
    local ok, kerr = machine:set_key(btn, true)
    if not ok then
      kb_held[btn] = nil
      say("key send failed: " .. tostring(kerr))
      return
    end
    sync_pad(btn)
  end

  local function kb_up(btn)
    if not btn or not kb_held[btn] then return end
    kb_held[btn] = nil
    machine:set_key(btn, false)
    if not next(kb_held) and held ~= btn then sync_pad(nil) end
  end

  local function on_touch(x, y)
    x, y = tonumber(x), tonumber(y)
    if not x or not y then return end
    local key = pad:hit(x, y)
    if key then press_key(key) end
  end

  local function handle_gui(act)
    if not act or not act.action then return true end
    if act.action == "pause" then
      paused = act.paused
      if paused == nil then paused = true end
      machine:send({ t = paused and "pause" or "resume", v = Protocol.VERSION })
      gui:set_run_state({ paused = paused })
      gui:set_message(paused and "Paused (remote)" or "Running (remote)", true)
      gui:draw()
    elseif act.action == "step" then
      machine:step_instruction()
      paint_lcd_only()
      paused = true
      gui:set_run_state({ paused = true })
      gui:draw()
    elseif act.action == "mute" then
      if audio then
        audio:set_muted(act.muted)
        gui:set_muted(audio.muted)
        persist_prefs()
        gui:set_message(audio.muted and "Audio muted" or "Audio on (speaker)", true)
        gui:draw()
      end
    elseif act.action == "file" then
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
            full_redraw(true)
          end
        end
      else
        gui:set_message("WS mode: click a .gb cart to upload", false)
        gui:draw()
      end
    elseif act.action == "settings" then
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
        full_redraw(true)
      end
    elseif act.action == "redraw" then
      full_redraw(true)
      gui:draw()
    elseif act.action == "quit" then
      release_held_ui()
      machine:close()
      return false
    elseif act.action == "theme" then
      theme_id = act.theme or Themes.next(theme_id)
      apply_lcd_theme(theme_id)
      persist_prefs()
      gui:set_run_state({ theme = theme_id })
      gui:draw()
      full_redraw(true)
    end
    return true
  end

  while true do
    local ev, a, b, c, d = os.pullEventRaw()

    if ev == "timer" and a == tick then
      local t_now = now_ms()
      last_tick_ms = t_now
      if held and t_now >= held_until then release_held_ui() end
      -- LCD first when due; empty staging while playing is normal, not critical.
      local have_frame = machine:has_pending_frame() or machine:display_dirty()
      if have_frame and (t_now - last_paint) >= paint_ms then
        paint_lcd_only()
        last_paint = t_now
        flush_audio(1)
      else
        flush_audio(audio_critical() and 2 or 1)
      end
      tick = os.startTimer(0.05)

    elseif ev == "speaker_audio_empty" then
      if audio then audio:on_empty() end

    elseif ev == "websocket_message" then
      if not ws_url or a == ws_url or tostring(a):find(tostring(ws_url), 1, true) then
        machine:handle_raw(b, c)
      end

    elseif ev == "tm_monitor_touch" then
      if type(a) == "number" then on_touch(a, b) else on_touch(b, c) end
    elseif ev == "tm_monitor_mouse_click" then
      if type(a) == "number" then
        if (c or 1) == 1 then on_touch(a, b) end
      elseif type(b) == "number" then
        if (d or 1) == 1 then on_touch(b, c) end
      end
    elseif ev == "mouse_click" then
      local act = gui:click(b, c)
      if act and not handle_gui(act) then break end
      if gui.dirty_status or gui.gate_hz_editing then
        gui:draw_status_only()
      end
    elseif ev == "char" then
      if gui:gate_char(a) then
        gui:draw_status_only()
      end
    elseif ev == "key" then
      local key_name = a
      if type(a) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
        key_name = keys.getName(a) or a
      end
      local result = gui:gate_key(key_name, a)
      if result == "commit" then
        gui:commit_gate_edit()
        gui:draw_status_only()
      elseif result then
        gui:draw_status_only()
      elseif keybind_map and not c then
        local btn = Keybinds.resolve(keybind_map, key_name, a)
        if btn then kb_down(btn) end
      end
    elseif ev == "key_up" then
      if keybind_map then
        local key_name = a
        if type(a) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
          key_name = keys.getName(a) or a
        end
        local btn = Keybinds.resolve(keybind_map, key_name, a)
        if btn then kb_up(btn) end
      end
    elseif ev == "mouse_scroll" then
      if type(a) == "number" and gui.scroll_by then
        gui:scroll_by(a > 0 and 1 or -1)
        gui:draw()
      end
    elseif ev == "term_resize" then
      gui:draw()
    elseif ev == "websocket_closed" then
      say("WebSocket closed")
      break
    elseif ev == "terminate" then
      release_held_ui()
      machine:close()
      break
    end
  end

  return true
end

return M
