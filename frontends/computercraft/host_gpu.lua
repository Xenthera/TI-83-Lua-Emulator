-- ComputerCraft host for Tom's Peripherals GPU (bitmap monitors).
-- Profile supplies Face / LcdView / KeypadView / Machine / Args.

local CC = require("frontends.computercraft.cc")
local Gpu = require("frontends.computercraft.gpu")
local ControlGui = require("frontends.computercraft.control_gui")
local Themes = require("frontends.computercraft.themes")
local Prefs = require("frontends.computercraft.prefs")
local Keybinds = require("frontends.computercraft.keybinds")
local SettingsDialog = require("frontends.computercraft.settings_dialog")
local SpeakerAudio = require("frontends.computercraft.speaker_audio")
local NVRAM = require("framework.nvram")

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
  if os.epoch then
    return os.epoch("utc")
  end
  return os.clock() * 1000
end

function M.run(opts)
  opts = opts or {}
  local P = opts.profile
  if not P then
    return fail("host_gpu: opts.profile required")
  end
  local Args = P.Args
  local Machine = P.Machine
  local Face = P.Face
  local LcdView = P.LcdView
  local KeypadView = P.KeypadView
  if not Args or not Machine or not Face or not LcdView or not KeypadView then
    return fail("host_gpu: profile needs Args, Machine, Face, LcdView, KeypadView")
  end

  if opts.args then
    local parsed, perr = Args.parse(opts.args)
    if not parsed then
      return fail(perr or Args.usage_text())
    end
    if parsed.help then
      say(Args.usage_text())
      return true
    end
    opts.rom = opts.rom or parsed.rom
    opts.gpu = opts.gpu or parsed.gpu
    opts.gpu_size = opts.gpu_size or parsed.gpu_size
    opts.face_scale = opts.face_scale or parsed.face_scale
  end

  if opts.help then
    say(Args.usage_text())
    return true
  end

  if not CC.is_cc() then
    return fail("Not running inside ComputerCraft / CC:Tweaked (no peripheral API).")
  end

  local rom_path = opts.rom or P.default_rom or "rom.bin"
  local bytes, rom_err_or_path
  if P.load_rom then
    bytes, rom_err_or_path = P.load_rom(rom_path)
  else
    bytes, rom_err_or_path = CC.read_file(rom_path)
  end
  if not bytes then
    return fail(rom_err_or_path or ("Cannot load ROM '" .. tostring(rom_path) .. "'"))
  end
  local cart_path = rom_path
  if type(rom_err_or_path) == "string" and rom_err_or_path ~= "" then
    cart_path = rom_err_or_path
  end

  local gpu, gpu_side = Gpu.resolve(opts)
  if not gpu then
    return fail(gpu_side) -- second return is err string from soft-fail resolve
  end

  local res = 64 -- always setSize(64); ignore --gpu-size
  local gw, gh, bw, bh, mult = Gpu.setup(gpu, res)
  if not gw then
    return fail(bw or "gpu.setup failed")
  end
  if gw < 1 or gh < 1 then
    local blocks = ""
    if bw and bh then
      blocks = string.format(" (%sx%s blocks", tostring(bw), tostring(bh))
      if mult then blocks = blocks .. ", mult=" .. tostring(mult) end
      blocks = blocks .. ")"
    end
    return fail(string.format(
      "GPU reports empty size: %dx%d px%s on '%s'\n"
        .. "  Call refresh / check bitmap monitors are attached to the GPU.\n"
        .. "  (Current --gpu-size=%s)",
      gw, gh, blocks, tostring(gpu_side), tostring(res)))
  end

  local cycles_per_tick = opts.cycles_per_tick or P.cycles_per_tick or 400000
  local prefs_file = P.prefs_file or "gpu.prefs"
  local prefs = Prefs.load(prefs_file, P.default_theme)
  local theme_id = Themes.is_valid(opts.theme) and opts.theme
    or (Themes.is_valid(prefs.theme) and prefs.theme)
    or P.default_theme
    or "titanium"
  local gate_hz = tonumber(opts.gate_hz) or tonumber(prefs.gate_hz) or 20
  if gate_hz < 1 then gate_hz = 1 end
  local paused = false
  local gate_active = false
  local gate_accum = 0
  local last_tick_ms = now_ms()
  local paint_ms = math.floor(1000 / (P.paint_fps or 12))
  if paint_ms < 40 then paint_ms = 40 end

  local keybind_buttons = Keybinds.buttons_for(P.id)
  local keybind_map = (P.enable_keybinds and keybind_buttons)
    and Keybinds.build_map(P.id, prefs.keybinds) or nil
  local prefs_keybinds = nil
  if keybind_map and keybind_buttons then
    prefs_keybinds = Keybinds.emu_to_host(keybind_map, keybind_buttons)
  end
  local kb_held = {}
  local audio -- assigned after machine load when enable_audio

  local machine = Machine.new()
  local load_opts = P.supports_cart and { path = cart_path } or nil
  local ok, err = machine:load_rom_bytes(bytes, load_opts)
  if not ok then
    return fail(err or "ROM load failed")
  end
  machine:reset()
  if machine.rom_data and machine.rom_data.loaded and machine.save_path then
    say("Restored cart save -> " .. tostring(machine.save_path))
  end

  local nvram_root = opts.nvram_root or "."
  local mid = machine.MACHINE_ID or P.id or "machine"
  if NVRAM.exists(nvram_root, mid) then
    local rok, rerr = NVRAM.load(nvram_root, machine)
    if rok then
      say("Restored battery memory (" .. tostring(mid) .. ")")
    else
      say("Battery restore skipped: " .. tostring(rerr))
    end
  end

  local function persist_battery(reason)
    if not machine then return end
    if machine.save_cart_save and machine.cart and machine.cart.has_save_ram
        and machine.cart:has_save_ram() then
      local cok, cpath = machine:save_cart_save()
      if cok then
        say("Cart save (" .. tostring(reason or "quit") .. ") -> " .. tostring(cpath))
      end
    end
    local sok, sdir = NVRAM.save(nvram_root, machine)
    if sok then
      say("Battery saved (" .. tostring(reason or "quit") .. ") -> " .. tostring(sdir))
    else
      say("Battery save failed: " .. tostring(sdir))
    end
  end

  local face_scale = math.max(1, math.floor(tonumber(opts.face_scale) or 1))
  local face = Face.new(gpu)
  local laid = face:layout(gw, gh, { scale = face_scale })
  if not laid or face.lcd_rect.w < 8 or face.pad_rect.w < 8 then
    return fail(string.format(
      "GPU screen too small: have %dx%d px (%sx%s blocks @ size %s)\n"
        .. "  Need about %dx%d px for this face.\n"
        .. "  Tip: more bitmap-monitor blocks, or setSize(64).",
      gw, gh, tostring(bw or "?"), tostring(bh or "?"), tostring(res),
      tonumber(face.need_w) or 0, tonumber(face.need_h) or 0))
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
    if force_lcd or machine:display_dirty() then
      lcd:paint(machine:framebuffer(), machine:is_display_on())
      machine:clear_display_dirty()
    end
    Gpu.sync(gpu)
  end

  local function paint_lcd_only()
    if not machine:display_dirty() then
      return
    end
    lcd:paint(machine:framebuffer(), machine:is_display_on())
    machine:clear_display_dirty()
    Gpu.sync(gpu)
  end

  -- Optional speaker (Game Boy / profiles with enable_audio).
  local AudioPcm = nil
  local apu_rate = nil
  local audio_drain_cap = 0
  local audio_pending_pcm, audio_pending_n = {}, 0
  local audio_chunk_target = 24000
  if P.enable_audio and machine.apu then
    AudioPcm = require("bridge.audio_pcm")
    local ApuMod = require("machines.gameboy.hw.apu")
    apu_rate = ApuMod.SAMPLE_RATE
    audio_drain_cap = math.floor(apu_rate / 15 * 2 + 0.5)
    audio_chunk_target = AudioPcm.CHUNK_SAMPLES or 24000
    audio = SpeakerAudio.new({ muted = false })
    if not audio.speaker then
      say("No speaker attached - GB audio needs a speaker peripheral.")
    end
  end

  local function persist_prefs()
    prefs.theme = theme_id
    prefs.gate_hz = gate_hz
    prefs.muted = false -- mute is session-only
    if prefs_keybinds then prefs.keybinds = prefs_keybinds end
    return Prefs.save(prefs, prefs_file)
  end

  local function flush_audio()
    if not audio or not machine.apu or not AudioPcm then return end
    local pending = machine.apu:samples_pending()
    if pending < 1 then
      audio:pump()
      return
    end
    if audio.muted then
      machine.apu:drain_samples(pending)
      audio_pending_pcm, audio_pending_n = {}, 0
      return
    end
    local cap = audio_drain_cap
    if audio.needs_data and audio:needs_data() and apu_rate then
      cap = math.max(cap, math.floor(apu_rate * 0.08))
    end
    if pending > cap and cap > 0 then
      machine.apu:drain_samples(pending - cap)
      pending = cap
    end
    local floats, n = machine.apu:drain_samples(pending)
    if n < 1 then return end
    local pcm = AudioPcm.resample_s8_table(floats, n, apu_rate, AudioPcm.SPEAKER_RATE)
    for i = 1, #pcm do
      audio_pending_n = audio_pending_n + 1
      audio_pending_pcm[audio_pending_n] = pcm[i]
    end
    while audio_pending_n >= audio_chunk_target do
      local chunk = {}
      for i = 1, audio_chunk_target do chunk[i] = audio_pending_pcm[i] end
      local rest_n = audio_pending_n - audio_chunk_target
      local rest = {}
      for i = 1, rest_n do rest[i] = audio_pending_pcm[audio_chunk_target + i] end
      audio_pending_pcm, audio_pending_n = rest, rest_n
      audio:push_pcm(chunk)
    end
    audio:pump()
  end

  say(P.boot_label or "GPU face: starting...")
  say(string.format(
    "GPU %s  %dx%d px  blocks=%sx%s  size=%s  LCD cell=%s",
    tostring(gpu_side), gw, gh,
    tostring(bw or "?"), tostring(bh or "?"),
    tostring(res), tostring(face.lcd_cell)))
  full_redraw(true)

  local gui = ControlGui.new({
    monitors = {},
    cycles_per_tick = cycles_per_tick,
    paused = paused,
    gate_active = gate_active,
    gate_hz = gate_hz,
    theme = theme_id,
    file_filter = P.file_filter,
    show_settings = not not keybind_map,
    show_mute = not not audio,
    muted = audio and audio.muted or false,
    message = "KEYS=keybinds  SND=mute  |  GPU face: touch LCD/keypad  |  click CART to load",
  })
  gui:draw()

  local emu_hz = Machine.CPU_HZ or machine.CPU_HZ or 16000000
  local held = nil
  local held_cycles = 0
  local key_hold_cycles = math.max(50000, cycles_per_tick)
  local on_hold_cycles = machine.min_on_hold_cycles
    or math.floor(emu_hz / 2)
  if on_hold_cycles < 500000 then
    on_hold_cycles = 500000
  end

  local function hold_budget_for(key)
    if key == "on" then return on_hold_cycles end
    return key_hold_cycles
  end

  local function release_held()
    if not held then return end
    machine:set_key(held, false)
    held = nil
    held_cycles = 0
    pad:set_pressed(nil)
    pad:draw()
    Gpu.sync(gpu)
  end

  local function sync_pad_pressed(name)
    pad:set_pressed(name)
    pad:draw()
    Gpu.sync(gpu)
  end

  local function press_key(key)
    if held == key or kb_held[key] then return end
    release_held()
    machine:set_key(key, true)
    held = key
    held_cycles = 0
    sync_pad_pressed(key)
    if not paused then
      local slice = math.min(cycles_per_tick, hold_budget_for(key))
      local ran = machine:run_cycles(slice)
      held_cycles = held_cycles + (ran or 0)
      machine.lcd._dirty = true
      paint_lcd_only()
      flush_audio()
      if held and held_cycles >= hold_budget_for(held) then
        release_held()
      end
    end
  end

  local function kb_down(btn)
    if not btn or kb_held[btn] then return end
    if held == btn then
      held = nil
      held_cycles = 0
    end
    kb_held[btn] = true
    machine:set_key(btn, true)
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

  local function advance_key_hold(ran)
    if not held then return end
    held_cycles = held_cycles + (ran or 0)
    if held_cycles >= hold_budget_for(held) then
      release_held()
    end
  end

  local function on_touch(x, y)
    x, y = tonumber(x), tonumber(y)
    if not x or not y then return end
    local key = pad:hit(x, y)
    if key then
      press_key(key)
    end
  end

  local function load_cart_file(file)
    if not file or not P.supports_cart then return end
    local data, err = CC.read_file(file.path)
    if not data then
      gui:set_message(tostring(err or "cannot read cart"), false)
      gui:draw()
      return
    end
    local ok_l, lerr = machine:load_rom_bytes(data, { path = file.path })
    if not ok_l then
      gui:set_message(tostring(lerr or "cart load failed"), false)
      gui:draw()
      return
    end
    release_held()
    for k in pairs(kb_held) do
      machine:set_key(k, false)
      kb_held[k] = nil
    end
    machine:reset()
    machine.lcd._dirty = true
    full_redraw(true)
    local msg = "Loaded " .. tostring(file.name) .. " (reset)"
    if machine.rom_data and machine.rom_data.loaded then msg = msg .. " +save" end
    gui:set_message(msg, true)
    gui:draw()
  end

  local function handle_gui(act)
    if not act or not act.action then return true end
    if act.action == "pause" then
      paused = not paused
      gui:set_run_state({ paused = paused })
      gui:set_message(paused and "Paused" or "Running", true)
      gui:draw()
    elseif act.action == "step" then
      local ran = machine:step_instruction()
      advance_key_hold(ran)
      machine.lcd._dirty = true
      paint_lcd_only()
      flush_audio()
      gui:set_run_state({ paused = true })
      paused = true
      gui:draw()
    elseif act.action == "gate" then
      gate_active = not gate_active
      gui:set_run_state({ gate_active = gate_active })
      gui:draw()
    elseif act.action == "gate_hz" then
      gate_hz = tonumber(act.hz) or gate_hz
      gui:set_run_state({ gate_hz = gate_hz })
      persist_prefs()
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
      load_cart_file(act.file)
    elseif act.action == "refresh" then
      if gui.refresh_files then gui:refresh_files() end
      gui:draw()
    elseif act.action == "settings" then
      if keybind_map and keybind_buttons then
        local result = SettingsDialog.run({
          title = "Game Boy Keybinds",
          buttons = keybind_buttons,
          host_map = keybind_map,
        })
        if result then
          prefs_keybinds = result
          keybind_map = Keybinds.build_map(P.id, prefs_keybinds)
          persist_prefs()
          gui:set_message("Keybinds saved", true)
        else
          gui:set_message("Keybinds unchanged", true)
        end
        gui:draw()
        full_redraw(true)
      end
    elseif act.action == "theme" then
      theme_id = act.theme or Themes.next(theme_id)
      apply_lcd_theme(theme_id)
      persist_prefs()
      gui:set_run_state({ theme = theme_id })
      gui:set_message("Theme: " .. theme_id, true)
      gui:draw()
      full_redraw(true)
    elseif act.action == "redraw" then
      full_redraw(true)
      gui:draw()
    elseif act.action == "quit" then
      release_held()
      persist_battery("quit")
      return false
    end
    return true
  end

  local acc_cycles = 0
  local report_t = now_ms()
  local last_paint = report_t
  local tick = os.startTimer(0)

  while true do
    local ev, a, b, c, d = os.pullEventRaw()

    if ev == "timer" and a == tick then
      local t_now = now_ms()
      local dt = (t_now - last_tick_ms) / 1000
      last_tick_ms = t_now
      if dt < 0 then dt = 0 end
      if dt > 0.25 then dt = 0.25 end

      if not paused then
        local ran = 0
        if gate_active then
          gate_accum = gate_accum + dt * math.max(1, gate_hz)
          local steps = math.floor(gate_accum)
          if steps > 5000 then steps = 5000 end
          gate_accum = gate_accum - steps
          for _ = 1, steps do
            ran = ran + machine:step_instruction()
          end
        elseif audio and not audio.muted then
          -- Match gb_cc: wall-clock budget so speaker is not starved.
          local budget = math.floor(emu_hz * dt + 0.5)
          local max_budget = math.floor(emu_hz * 0.1)
          if budget > max_budget then budget = max_budget end
          local min_rt = math.floor(emu_hz * 0.05 + 0.5)
          if budget < min_rt then budget = min_rt end
          if budget < 1 then budget = 1 end
          ran = machine:run_cycles(budget)
        else
          ran = machine:run_cycles(cycles_per_tick)
        end
        acc_cycles = acc_cycles + ran
        advance_key_hold(ran)
        flush_audio()
      end

      if (t_now - last_paint) >= paint_ms and machine:display_dirty() then
        paint_lcd_only()
        last_paint = t_now
      end

      if t_now - report_t >= 1000 then
        local elapsed = (t_now - report_t) / 1000
        if elapsed < 0.001 then elapsed = 0.001 end
        local mhz = (acc_cycles / elapsed) / 1e6
        local pct = (mhz * 1e6 / emu_hz) * 100
        gui:set_perf(mhz, pct, cycles_per_tick)
        gui:set_run_state({
          paused = paused,
          gate_active = gate_active,
          gate_hz = gate_hz,
          theme = theme_id,
        })
        gui:draw_status_only()
        acc_cycles = 0
        report_t = t_now
      end

      tick = os.startTimer(0)

    elseif ev == "speaker_audio_empty" then
      if audio then
        audio:on_empty()
        flush_audio()
      end

    elseif ev == "tm_monitor_touch" then
      if type(a) == "number" then
        on_touch(a, b)
      else
        on_touch(b, c)
      end

    elseif ev == "tm_monitor_mouse_click" then
      if type(a) == "number" then
        if (c or 1) == 1 then on_touch(a, b) end
      elseif type(b) == "number" then
        if (d or 1) == 1 then on_touch(b, c) end
      end

    elseif ev == "mouse_click" then
      local keep = handle_gui(gui:click(b, c))
      if keep == false then
        if term and term.clear then
          term.setBackgroundColor(CC.colors().black)
          term.clear()
          term.setCursorPos(1, 1)
        end
        say("Stopped.")
        return true
      end
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
        local hz = gui:commit_gate_edit()
        if hz then
          gate_hz = hz
          gate_accum = 0
          persist_prefs()
          gui:set_run_state({ gate_hz = gate_hz })
          gui:draw()
        else
          gui:draw_status_only()
        end
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
        if gui.gate_hz_editing and gui.commit_gate_edit then
          gui:commit_gate_edit()
        end
        gui:scroll_by(a > 0 and 1 or -1)
        gui:draw()
      end

    elseif ev == "term_resize" then
      gui:draw()

    elseif ev == "peripheral" or ev == "peripheral_detach" then
      local nw, nh, err = Gpu.setup(gpu, res)
      if not nw then
        say("GPU resize probe failed: " .. tostring(nh or err))
      elseif nw ~= gw or nh ~= gh then
        gw, gh = nw, nh
        face:layout(gw, gh, { scale = face_scale })
        lcd:set_glass(face.lcd_rect)
        lcd:set_cell(face.lcd_cell or 2)
        lcd:set_bounds(gw, gh)
        pad:set_bounds(gw, gh)
        pad:layout(face.pad_rect.x, face.pad_rect.y, face.pad_rect.w, face.pad_rect.h)
        full_redraw(true)
        gui:set_message(string.format("GPU resized to %dx%d", gw, gh), true)
        gui:draw()
      end
      if audio then audio:refresh() end

    elseif ev == "terminate" then
      release_held()
      persist_battery("terminate")
      return true
    end
  end
end

return M
