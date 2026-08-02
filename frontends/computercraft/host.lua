-- ComputerCraft host: LCD + keypad monitors, computer control GUI.
-- One CPU slice per CC timer tick (timer itself is the yield).
-- Never nest pullEvent/sleep inside the timer handler.
-- Machine-specific bits come from opts.profile (default: TI-83+).

local bitutil = require("framework.util.bit")
local DefaultEightxk = require("machines.ti83plus.util.eightxk")
local DefaultEightxp = require("machines.ti83plus.util.eightxp")
local Eightxk = DefaultEightxk
local Eightxp = DefaultEightxp
local NVRAM = require("framework.nvram")
local CC = require("frontends.computercraft.cc")
local ControlGui = require("frontends.computercraft.control_gui")
local Prefs = require("frontends.computercraft.prefs")
local Themes = require("frontends.computercraft.themes")
local Keybinds = require("frontends.computercraft.keybinds")
local SettingsDialog = require("frontends.computercraft.settings_dialog")
local SpeakerAudio = require("frontends.computercraft.speaker_audio")
local DefaultProfile = require("frontends.computercraft.profile_ti83plus")

local M = {}

local function say(...)
  print(table.concat({ ... }, ""))
end

local function fail(msg)
  msg = tostring(msg)
  say("")
  -- Print line-by-line so multi-line ROM/monitor hints stay readable on CC.
  local first = true
  for line in (msg .. "\n"):gmatch("(.-)\n") do
    if first then
      say("ERROR: " .. line)
      first = false
    else
      say(line)
    end
  end
  return nil, msg
end

-- Yield only between major setup steps (not inside the event/timer loop).
local function cc_yield()
  if type(sleep) == "function" then
    sleep(0)
  elseif type(os) == "table" and type(os.queueEvent) == "function"
    and type(os.pullEvent) == "function" then
    os.queueEvent("ti_emu_yield")
    os.pullEvent("ti_emu_yield")
  end
end

local function now_ms()
  if os.epoch then
    local ok, t = pcall(os.epoch, "utc")
    if ok and type(t) == "number" then
      return t
    end
  end
  return math.floor((os.clock() or 0) * 1000)
end

M.parse_args = DefaultProfile.Args.parse
M.usage_text = DefaultProfile.Args.usage_text

local function normalize_list(list)
  if list == nil then return {} end
  if type(list) == "string" then return { list } end
  return list
end

--- Install .8xk Flash Apps into a ROM image (offline TI-Link).
function M.install_apps(rom_bytes, loadapp_paths)
  loadapp_paths = normalize_list(loadapp_paths)
  if #loadapp_paths == 0 then
    return rom_bytes, {}
  end
  local out = rom_bytes
  local metas = {}
  for i, path in ipairs(loadapp_paths) do
    local data, err = CC.read_file(path)
    if not data then
      return nil, "cannot read --loadapp '" .. tostring(path) .. "': " .. tostring(err)
    end
    local next_rom, meta = Eightxk.inject(out, data, { yield = cc_yield })
    if not next_rom then
      return nil, string.format("app #%d (%s): %s", i, tostring(path), tostring(meta))
    end
    out = next_rom
    metas[#metas + 1] = meta
    cc_yield()
  end
  return out, metas
end

--- Install .8xp programs or .8xg groups into live RAM/VAT (after homescreen).
function M.install_progs(machine, loadprog_paths)
  loadprog_paths = normalize_list(loadprog_paths)
  if #loadprog_paths == 0 then
    return {}
  end
  if not Eightxp.vat_ready(machine.mmu) then
    return nil, "VAT not ready yet - wait until the homescreen is up, then retry"
  end
  local prog_bytes = {}
  for _, path in ipairs(loadprog_paths) do
    local data, err = CC.read_file(path)
    if not data then
      return nil, "cannot read '" .. tostring(path) .. "': " .. tostring(err)
    end
    prog_bytes[#prog_bytes + 1] = data
  end
  return Eightxp.inject_many(machine.mmu, prog_bytes, { iy = machine.cpu.iy })
end

--- Install one .8xk into live flash archive bytes.
-- opts.yield: cooperative yield callback (prefer coroutine.yield from host job).
-- Caller should machine:reset() after success so the OS re-scans the archive.
function M.install_app_live(machine, path, opts)
  opts = opts or {}
  local data, err = CC.read_file(path)
  if not data then
    return nil, "cannot read '" .. tostring(path) .. "': " .. tostring(err)
  end
  return Eightxk.inject_flash(machine.mmu.flash.bytes, data, {
    yield = opts.yield,
  })
end

--- Blocking host loop. Ctrl+T / terminate exits cleanly.
-- opts.profile: machine profile (default TI-83+). See profile_ti83plus / profile_ti84plus / profile_ti89.
function M.run(opts)
  opts = opts or {}
  local P = opts.profile or DefaultProfile
  local Machine = P.Machine
  local LcdView = P.LcdView
  local KeypadView = P.KeypadView
  local MemMapView = P.MemMapView
  local Args = P.Args or DefaultProfile.Args
  -- Profile may supply machine-specific .8xk/.8xp helpers (e.g. TI-84 1MB flash).
  Eightxk = P.Eightxk or DefaultEightxk
  Eightxp = P.Eightxp or DefaultEightxp

  if opts.args then
    local parsed, perr = Args.parse(opts.args)
    if not parsed then
      return fail(perr)
    end
    if parsed.help then
      say(Args.usage_text())
      return true
    end
    opts.lcd = opts.lcd or parsed.lcd
    opts.pad = opts.pad or parsed.pad
    opts.rom = opts.rom or parsed.rom
    if not opts.loadapp or (type(opts.loadapp) == "table" and #opts.loadapp == 0) then
      opts.loadapp = parsed.loadapp
    end
    if not opts.loadprog or (type(opts.loadprog) == "table" and #opts.loadprog == 0) then
      opts.loadprog = parsed.loadprog
    end
  end

  if Args.looks_flag and (
      Args.looks_flag(opts.lcd) or Args.looks_flag(opts.pad) or Args.looks_flag(opts.rom)
    ) then
    local recovered, rerr = Args.recover_misparsed(opts)
    if not recovered then
      return fail(
        "got flag as monitor/ROM ("
          .. tostring(opts.lcd)
          .. "). Re-copy dist/test.lua, or run:\n"
          .. "  test --help\n"
          .. tostring(rerr or "")
      )
    end
    opts.lcd, opts.pad, opts.rom = recovered.lcd, recovered.pad, recovered.rom
    opts.loadapp = recovered.loadapp
    opts.loadprog = recovered.loadprog
  end

  if not CC.is_cc() then
    if opts.frames and opts._machine then
      local m = opts._machine
      for _ = 1, opts.frames do
        m:run_cycles(opts.cycles_per_tick or 200000)
      end
      return m
    end
    return fail("not running inside ComputerCraft (no peripheral API)")
  end

  local rom_path = opts.rom or P.default_rom or "ti83plus.rom"
  local emu_hz = opts.hz or Machine.CPU_HZ or 6000000
  local cycles_per_tick = opts.cycles_per_tick or P.cycles_per_tick or 200000
  local paint_fps = opts.paint_fps or P.paint_fps or 10
  local paint_ms = math.floor(1000 / paint_fps)

  -- On success some profiles (GB) return data, path_used for sidecar .sav paths.
  local bytes, rom_err_or_path = P.load_rom(rom_path)
  if not bytes then
    return fail(rom_err_or_path)
  end
  local cart_path = rom_path
  if type(rom_err_or_path) == "string" and rom_err_or_path ~= "" then
    cart_path = rom_err_or_path
  end
  cc_yield()

  local loadapp = normalize_list(opts.loadapp)
  if #loadapp > 0 then
    if not P.supports_8xk then
      return fail(P.title .. " does not support .8xk Flash App install")
    end
    local injected, metas = M.install_apps(bytes, loadapp)
    if not injected then
      return fail(metas)
    end
    bytes = injected
    cc_yield()
  end

  -- Multi-monitor roles: lcd | pad | mem | off (click cycles).
  -- TI-92 (combined_face): face | mem | off - LCD is painted inside the keypad.
  -- views[side] = { side=, mon=, role=, painter=, pad=, face=, memmap= }
  local views = {}
  local view_order = {} -- stable side order for GUI chips
  local FaceView = P.FaceView
  local role_cycle = P.role_cycle
  local combined_face = not not (P.combined_face and FaceView)
  -- Side name -> preferred modem/network name when both refer to one display.
  local monitor_aliases = {}
  -- Cached role presence so the timer path never scans monitors.
  local any_lcd, any_mem, any_pad, any_face = false, false, false, false

  local function recompute_roles()
    any_lcd, any_mem, any_pad, any_face = false, false, false, false
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        if v.role == "lcd" then
          any_lcd = true
        elseif v.role == "mem" then
          any_mem = true
        elseif v.role == "pad" then
          any_pad = true
        elseif v.role == "face" then
          any_face = true
          any_lcd = true -- face includes the LCD
          any_pad = true -- face includes the keypad
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

  -- Resolve side/modem aliases to the registered view (modem name preferred).
  local function resolve_view(name)
    local key = monitor_aliases[name] or name
    local v = views[key]
    if v then
      return v, key
    end
    v = views[name]
    if v then
      return v, name
    end
    return nil, nil
  end

  -- Seed prefs early so theme is available when binding LCD painters.
  local prefs = Prefs.load(P.prefs_file, P.default_theme)
  local theme_id = Themes.is_valid(opts.theme) and opts.theme
    or (Themes.is_valid(prefs.theme) and prefs.theme)
    or P.default_theme
    or "classic"
  local gate_hz = tonumber(opts.gate_hz) or tonumber(prefs.gate_hz) or 20
  if gate_hz < 1 then gate_hz = 1 end
  local paused = false
  local gate_active = false
  local gate_accum = 0
  local last_tick_ms = now_ms()
  local machine -- assigned after ROM load / monitor seed
  local audio -- GB speaker sink (optional)

  local function lcd_painter_opts()
    local t = Themes.painter_opts(theme_id)
    local o = {}
    for k, v in pairs(opts) do
      o[k] = v
    end
    o.on = t.on
    o.off = t.off
    o.frame = t.frame
    return o
  end

  local function bind_view(v)
    v.painter = nil
    v.pad = nil
    v.face = nil
    v.memmap = nil
    if v.role == "face" and FaceView then
      v.face = FaceView.new(v.mon, {
        side = v.side,
        text_scale = opts.pad_scale or P.pad_scale,
      })
      v.face.side = v.side
      v.face:set_lcd_colors(lcd_painter_opts())
      v.face:draw_keys()
      v.face.force_lcd = true
    elseif v.role == "lcd" then
      v.painter = LcdView.new_painter(v.mon, lcd_painter_opts())
      v.painter:setup()
      v.painter.force = true
    elseif v.role == "pad" then
      v.pad = KeypadView.new(v.mon, {
        side = v.side,
        text_scale = opts.pad_scale or P.pad_scale,
      })
      v.pad.side = v.side
      v.pad:draw()
    elseif v.role == "mem" then
      v.memmap = MemMapView.new(v.mon, { side = v.side, text_scale = opts.mem_scale })
      v.memmap:setup()
    else
      -- off: stop all rendering on this monitor
      local C = CC.colors()
      if v.mon.setTextScale then
        v.mon.setTextScale(1)
      end
      v.mon.setBackgroundColor(C.black)
      v.mon.setTextColor(C.gray)
      v.mon.clear()
      v.mon.setCursorPos(1, 1)
      v.mon.write("OFF")
    end
  end

  local function apply_theme(id)
    if not Themes.is_valid(id) then
      return
    end
    theme_id = id
    local t = Themes.painter_opts(theme_id)
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v and v.painter then
        v.painter:set_colors(t)
      elseif v and v.face and v.face.set_lcd_colors then
        v.face:set_lcd_colors(t)
        v.face.force_lcd = true
      end
    end
    if machine and machine.lcd then
      machine.lcd._dirty = true
    end
  end

  local function add_monitor(side, role)
    if views[side] then
      return views[side]
    end
    if not peripheral.isPresent(side) or peripheral.getType(side) ~= "monitor" then
      return nil
    end
    local mon = peripheral.wrap(side)
    if not mon then
      return nil
    end
    local default_role = combined_face and "face" or "pad"
    local v = { side = side, mon = mon, role = role or default_role }
    views[side] = v
    view_order[#view_order + 1] = side
    bind_view(v)
    recompute_roles()
    return v
  end

  local function remove_monitor(side)
    if not views[side] then
      return
    end
    views[side] = nil
    local next_order = {}
    for _, s in ipairs(view_order) do
      if s ~= side then
        next_order[#next_order + 1] = s
      end
    end
    view_order = next_order
    recompute_roles()
  end

  -- Roles remembered across attach/detach/reload (side -> role).
  local remembered = prefs.monitors or {}

  local keybind_buttons = Keybinds.buttons_for(P.id)
  local keybind_map = keybind_buttons
    and Keybinds.build_map(P.id, prefs.keybinds) or nil
  local prefs_keybinds = prefs.keybinds or {}
  if keybind_map and keybind_buttons and not next(prefs_keybinds) then
    prefs_keybinds = Keybinds.emu_to_host(keybind_map, keybind_buttons)
  end
  local kb_held = {} -- emu button -> true (keyboard sustained hold)

  local function persist_prefs()
    for _, m in ipairs(gui_monitor_list()) do
      remembered[m.side] = m.role
    end
    local path, err = Prefs.save({
      monitors = remembered,
      theme = theme_id,
      gate_hz = gate_hz,
      keybinds = prefs_keybinds,
      muted = audio and audio.muted or prefs.muted,
    }, P.prefs_file)
    return path, err
  end

  local tm_kb = Keybinds.enable_tm_keyboard()
  if tm_kb then
    say("tm_keyboard native events ON (" .. tostring(tm_kb) .. ")")
  end

  local function persist_monitors()
    return persist_prefs()
  end

  local function toggle_monitor(side)
    local v = views[side]
    if not v then
      return
    end
    v.role = ControlGui.next_role(v.role, role_cycle)
    remembered[side] = v.role
    bind_view(v)
    recompute_roles()
    persist_monitors()
  end

  do
    local found = CC.find_monitors()
    if #found == 0 then
      return fail("no monitors attached (need at least one)")
    end
    local forced = {}
    local function force_role(spec, role)
      local okw, _, side = pcall(CC.wrap_monitor, spec, role)
      if okw and side then
        forced[CC.canonical_monitor_name(side) or side] = role
      elseif type(spec) == "string" then
        forced[CC.canonical_monitor_name(spec) or spec] = role
      end
    end
    if combined_face then
      if opts.face or opts.lcd then
        force_role(opts.face or opts.lcd, "face")
      end
      if opts.pad then
        force_role(opts.pad, "mem")
      end
    else
      if opts.lcd then
        force_role(opts.lcd, "lcd")
      end
      if opts.pad then
        force_role(opts.pad, "pad")
      end
    end
    for i, f in ipairs(found) do
      local role = forced[f.side] or remembered[f.side]
      if not role then
        -- Role may have been saved under a side alias of this modem name.
        for name, r in pairs(remembered) do
          if name ~= f.side and CC.is_side_name(name) and CC.monitors_same(name, f.side) then
            role = r
            break
          end
        end
      end
      if not role then
        if combined_face then
          role = (i == 1) and "face" or "mem"
        else
          role = (i == 1) and "lcd" or "pad"
        end
      end
      -- Migrate old TI-92 prefs (lcd/pad) to face.
      if combined_face and (role == "lcd" or role == "pad") then
        role = "face"
      end
      remembered[f.side] = role
      add_monitor(f.side, role)
    end
    rebuild_aliases()
    persist_monitors()
  end

  machine = Machine.new()
  local load_opts = nil
  if P.supports_cart then
    load_opts = { path = cart_path }
  end
  local ok, err = machine:load_rom_bytes(bytes, load_opts)
  if not ok then
    return fail(err or "ROM load failed")
  end
  machine:reset()
  if machine.rom_data and machine.rom_data.loaded and machine.save_path then
    say("Restored cart save -> " .. tostring(machine.save_path))
  end

  -- Battery-backed flash/RAM (and full soft state) across host restarts.
  local nvram_root = opts.nvram_root or "."
  if NVRAM.exists(nvram_root, machine.MACHINE_ID or P.id) then
    local rok, rerr = NVRAM.load(nvram_root, machine)
    if rok then
      say("Restored battery memory (" .. tostring(machine.MACHINE_ID or P.id) .. ")")
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

  local AudioPcm = nil
  local apu_rate = nil
  local audio_drain_cap = 0
  if machine.apu then
    AudioPcm = require("bridge.audio_pcm")
    local ApuMod = require("machines.gameboy.hw.apu")
    apu_rate = ApuMod.SAMPLE_RATE
    audio_drain_cap = math.floor(apu_rate / 15 * 2 + 0.5)
    audio = SpeakerAudio.new({ muted = not not prefs.muted })
    if not audio.speaker then
      say("No speaker attached - GB audio needs a speaker peripheral.")
    end
  end

  local audio_pending_pcm = {} -- accumulate toward SpeakerAudio.PREFILL_SAMPLES
  local audio_pending_n = 0
  local audio_chunk_target = AudioPcm and (AudioPcm.CHUNK_SAMPLES or 24000) or 24000

  local function flush_audio()
    if not audio or not machine or not machine.apu or not AudioPcm then return end
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
    -- When the speaker queue is low, drain more APU so we can stage the next chunk.
    local cap = audio_drain_cap
    if audio:needs_data() and apu_rate then
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
      for i = 1, audio_chunk_target do
        chunk[i] = audio_pending_pcm[i]
      end
      local rest_n = audio_pending_n - audio_chunk_target
      local rest = {}
      for i = 1, rest_n do
        rest[i] = audio_pending_pcm[audio_chunk_target + i]
      end
      audio_pending_pcm, audio_pending_n = rest, rest_n
      audio:push_pcm(chunk)
    end
    audio:pump()
  end

  local function audio_starving()
    return audio and not audio.muted and audio.primed and #audio.queue < 1
  end

  local fb_buf = {}
  cc_yield()

  local gui = ControlGui.new({
    monitors = gui_monitor_list(),
    cycles_per_tick = cycles_per_tick,
    paused = paused,
    gate_active = gate_active,
    gate_hz = gate_hz,
    theme = theme_id,
    file_filter = P.file_filter,
    show_settings = not not keybind_map,
    show_mute = not not audio,
    muted = audio and audio.muted or false,
    message = combined_face
      and "Click monitor to cycle FACE / MEM / OFF. Click files to load."
      or "Click monitor to cycle LCD / PAD / MEM / OFF. Click files to load.",
  })
  local loadprog_hint = normalize_list(opts.loadprog)
  if #loadprog_hint > 0 then
    gui:set_message("Hint: click " .. tostring(loadprog_hint[1]) .. " after homescreen", true)
  elseif prefs.path then
    gui:set_message("Monitor layout: " .. tostring(prefs.path), true)
  elseif combined_face then
    gui:set_message("TI-92 face: LCD is drawn inside the keypad", true)
  end
  gui:draw()

  local identify_on = false
  local paint_views -- forward decl (identify restore calls it)

  local function paint_identify_monitor(v)
    local mon = v.mon
    if not mon then
      return
    end
    local C = CC.colors()
    -- Scale 1 = large, readable characters on advanced monitors.
    if mon.setTextScale then
      mon.setTextScale(1)
    end
    mon.setBackgroundColor(C.black)
    mon.setTextColor(C.yellow)
    mon.clear()
    local mw, mh = mon.getSize()
    local name = tostring(v.side or "?")
    if #name > mw then
      name = name:sub(1, mw)
    end
    local role = string.upper(tostring(v.role or "?"))
    local sub = "(" .. role .. ")"
    if #sub > mw then
      sub = sub:sub(1, mw)
    end
    local y = math.max(1, math.floor((mh - 1) / 2))
    local x = math.max(1, math.floor((mw - #name) / 2) + 1)
    mon.setCursorPos(x, y)
    mon.write(name)
    if y + 1 <= mh then
      local sx = math.max(1, math.floor((mw - #sub) / 2) + 1)
      mon.setCursorPos(sx, y + 1)
      mon.setTextColor(C.white)
      mon.write(sub)
    end
  end

  local function paint_identify_all()
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        paint_identify_monitor(v)
      end
    end
  end

  local function restore_views_after_identify()
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        bind_view(v)
      end
    end
    recompute_roles()
    machine.lcd._dirty = true
    paint_views()
  end

  paint_views = function()
    if identify_on then
      paint_identify_all()
      if machine:display_dirty() then
        machine:clear_display_dirty()
      end
      return
    end

    -- No visible surface: drop dirty flag cheaply and return.
    if not any_lcd and not any_mem then
      if machine:display_dirty() then
        machine:clear_display_dirty()
      end
      return
    end

    local need_lcd = any_lcd and machine:display_dirty()
    local fb, on
    if need_lcd or any_face then
      fb = machine:framebuffer(fb_buf)
      on = machine:is_display_on()
    end
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v then
        if v.face then
          if need_lcd then
            v.face:paint_lcd(fb, on)
          end
        elseif need_lcd and v.painter then
          v.painter:paint(fb, on)
        elseif any_mem and v.memmap then
          v.memmap:paint(P.mem_source(machine), P.mem_paint_opts(machine))
        end
      end
    end
    if need_lcd then
      machine:clear_display_dirty()
    elseif machine:display_dirty() and not any_lcd then
      machine:clear_display_dirty()
    end
  end

  local function sync_pad_pressed(name)
    if not any_pad then
      return
    end
    local fb, on
    if any_face then
      fb = machine:framebuffer(fb_buf)
      on = machine:is_display_on()
    end
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v and v.face then
        v.face:set_pressed(name)
        v.face:draw(fb, on)
      elseif v and v.pad then
        v.pad:set_pressed(name)
        v.pad:draw()
      end
    end
  end

  -- Keypad hold is timed in *emulated* cycles, not wall-clock ticks, so Gate
  -- (slow instruction rate) still delivers a full keypress to TI-OS.
  -- ON must stay down ~0.5s of calc time or power-on from HALT fails.
  local held = nil
  local held_cycles = 0
  local key_hold_cycles = cycles_per_tick
  if key_hold_cycles < 50000 then
    key_hold_cycles = 50000
  end
  local on_hold_cycles = machine.min_on_hold_cycles or math.floor((Machine.CPU_HZ or 6000000) / 2)
  if on_hold_cycles < 500000 then
    on_hold_cycles = 500000
  end

  local function hold_budget_for(key)
    if key == "on" then
      return on_hold_cycles
    end
    return key_hold_cycles
  end

  local function release_held()
    if not held then
      return
    end
    local was = held
    machine:set_key(held, false)
    held = nil
    held_cycles = 0
    sync_pad_pressed(nil)
    -- Homescreen needs the boot editOpen gap for the entry line; do not
    -- CloseEditBuf on ON wake (that causes ERR:MEMORY on Enter).
  end

  -- Declared before press_key so the install guard closes over this local
  -- (a later `local install` would make press_key read the global instead).
  -- File installs run as a timer job (never inside mouse_click, never nest pullEvent).
  -- .8xk uses a coroutine so Intel-HEX parse can yield between ticks; then cold-reset.
  local install = nil

  local function press_key(key)
    if install then
      return -- never run Z80 / mutate keypad while flash/VAT inject is in flight
    end
    if held == key then
      return
    end
    release_held()
    machine:set_key(key, true)
    held = key
    held_cycles = 0
    sync_pad_pressed(key)
    -- Pump a slice immediately so the ON edge is latched before the next
    -- timer tick (and LCD dirty is visible without needing a MEM monitor).
    if not paused then
      local slice = math.min(cycles_per_tick, hold_budget_for(key))
      local ran = machine:run_cycles(slice)
      held_cycles = held_cycles + (ran or 0)
      machine.lcd._dirty = true
      if any_lcd or any_mem then
        paint_views()
      end
      if held and held_cycles >= hold_budget_for(held) then
        release_held()
      end
    end
  end

  -- Keyboard path: hold while key is down (same set_key path as pad taps).
  local function kb_down(btn)
    if not btn or install then return end
    if kb_held[btn] then return end
    kb_held[btn] = true
    -- Cancel timed pad-tap hold on the same button so key_up owns release.
    if held == btn then
      held = nil
      held_cycles = 0
    end
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
    if not held then
      return
    end
    held_cycles = held_cycles + (ran or 0)
    if held_cycles >= hold_budget_for(held) then
      release_held()
    end
  end

  --- After cold-reset, hold ON like Love2D so TI-OS reaches the homescreen.
  --- Stops early once VAT looks ready (avoids a fixed 28M-cycle crawl on CC).
  local function wake_os_after_reset()
    release_held()
    if P.wake_os then
      local slice = cycles_per_tick * 5
      if slice < 500000 then slice = 500000 end
      if slice > 2000000 then slice = 2000000 end
      P.wake_os(machine, {
        yield = cc_yield,
        slice = slice,
      })
    end
    machine.lcd._dirty = true
  end

  local function queue_file_load(file)
    if not file then
      return
    end
    if file.kind == "cart" then
      if not P.supports_cart then
        gui:set_message(P.title .. ": cartridge load not supported", false)
        gui:draw()
        return
      end
    elseif file.kind == "app" and not P.supports_8xk then
      gui:set_message(P.title .. ": .8xk not supported", false)
      gui:draw()
      return
    elseif (file.kind == "prog" or file.kind == "group") and not P.supports_8xp then
      gui:set_message(P.title .. ": .8xp/.8xg not supported", false)
      gui:draw()
      return
    end
    if install then
      gui:set_message("Install already in progress...", false)
      gui:draw()
      return
    end
    install = { kind = file.kind, file = file, phase = "start" }
    local verb = (file.kind == "cart") and "Loading" or "Installing"
    gui:set_message(verb .. " " .. tostring(file.name) .. "...", true)
    gui:draw()
  end

  local function finish_app_install(meta)
    local pages = {}
    for _, p in ipairs(meta.placed or {}) do
      pages[#pages + 1] = string.format("%02X", p.physical)
    end
    -- Writing archive under a live OS crashes it; cold-boot so VAT/APPS rescan.
    release_held()
    machine:reset()
    for _, side in ipairs(view_order) do
      local v = views[side]
      if v and v.painter then
        v.painter.force = true
      end
    end
    gui:set_message(string.format(
      "Installed %s -> page %s  (restarting...)",
      meta.name or install.file.name, table.concat(pages, ",")
    ), true)
    gui:draw()
    wake_os_after_reset()
    machine.lcd._dirty = true
    gui:set_message(string.format(
      "Installed %s -> page %s  (calc restarted)",
      meta.name or install.file.name, table.concat(pages, ",")
    ), true)
    gui:draw()
    paint_views()
  end

  local function step_install()
    if not install then
      return
    end
    if install.kind == "cart" then
      local data, err = CC.read_file(install.file.path)
      if not data then
        gui:set_message(tostring(err), false)
        install = nil
        gui:draw()
        return
      end
      local ok, lerr = machine:load_rom_bytes(data, { path = install.file.path })
      if not ok then
        gui:set_message(tostring(lerr or "cart load failed"), false)
        install = nil
        gui:draw()
        return
      end
      release_held()
      machine:reset()
      for _, side in ipairs(view_order) do
        local v = views[side]
        if v and v.painter then
          v.painter.force = true
        end
      end
      machine.lcd._dirty = true
      local msg = "Loaded " .. tostring(install.file.name) .. " (reset)"
      if machine.rom_data and machine.rom_data.loaded and machine.save_path then
        msg = msg .. " +save"
      end
      gui:set_message(msg, true)
      install = nil
      gui:draw()
      paint_views()
      return
    end
    if install.kind == "prog" or install.kind == "group" then
      local metas, perr = M.install_progs(machine, { install.file.path })
      if not metas then
        gui:set_message(tostring(perr), false)
      else
        local names = {}
        for _, meta in ipairs(metas) do
          names[#names + 1] = meta.name
        end
        if #metas == 1 then
          local meta = metas[1]
          gui:set_message(string.format(
            "Loaded %s -> %04X (%d bytes)  PRGM menu",
            meta.name or install.file.name, meta.data_addr, meta.data_len
          ), true)
        elseif metas.blackjack_setup then
          gui:set_message(
            "Blackjack ready: PRGM -> BLACKJ83 (setup lists preloaded)",
            true
          )
        else
          gui:set_message(string.format(
            "Ungrouped %d vars: %s  (PRGM menu)",
            #metas, table.concat(names, ", ")
          ), true)
        end
        machine.lcd._dirty = true
      end
      install = nil
      gui:draw()
      return
    end

    -- .8xk Flash App
    if install.phase == "start" then
      local data, err = CC.read_file(install.file.path)
      if not data then
        gui:set_message(tostring(err), false)
        install = nil
        gui:draw()
        return
      end
      install.data = data
      install.co = coroutine.create(function()
        local function y()
          coroutine.yield()
        end
        return Eightxk.inject_flash(machine.mmu.flash.bytes, install.data, { yield = y })
      end)
      install.phase = "inject"
      return
    end

    if install.phase == "inject" then
      local ok, r1, r2 = coroutine.resume(install.co)
      if not ok then
        gui:set_message("Install error: " .. tostring(r1), false)
        install = nil
        gui:draw()
        return
      end
      if coroutine.status(install.co) ~= "dead" then
        return -- yielded; continue next tick
      end
      local meta, aerr = r1, r2
      install.co = nil
      if not meta then
        gui:set_message(tostring(aerr), false)
        install = nil
        gui:draw()
        return
      end
      finish_app_install(meta)
      install = nil
    end
  end

  local function handle_gui_action(act)
    if not act then
      return true
    end
    if act.action == "quit" then
      persist_battery("quit")
      return false
    elseif act.action == "toggle" then
      toggle_monitor(act.side)
      local v = views[act.side]
      gui:set_monitors(gui_monitor_list())
      if v then
        gui:set_message(string.format("%s -> %s", act.side, v.role:upper()), true)
      end
      machine.lcd._dirty = true
      gui:draw()
      paint_views()
    elseif act.action == "identify" then
      identify_on = not not act.on
      if identify_on then
        gui:set_message("Identify ON - side name centered on each monitor", true)
        gui:draw()
        paint_identify_all()
      else
        gui:set_message("Identify OFF", true)
        gui:draw()
        restore_views_after_identify()
      end
    elseif act.action == "file" then
      queue_file_load(act.file)
    elseif act.action == "pause" then
      paused = not not act.paused
      gate_accum = 0
      gui:set_run_state({ paused = paused })
      gui:set_message(paused and "Paused" or "Running", true)
      gui:draw()
    elseif act.action == "mute" then
      if audio then
        audio:set_muted(act.muted)
        gui:set_muted(audio.muted)
        persist_prefs()
        gui:set_message(audio.muted and "Audio muted" or "Audio on (speaker)", true)
        gui:draw()
      end
    elseif act.action == "step" then
      paused = true
      gui:set_run_state({ paused = true })
      local cyc = machine:step_instruction()
      machine.lcd._dirty = true
      paint_views()
      gui:set_message(string.format(
        "Step  PC=%04X  +%d cyc", machine.cpu.pc, cyc or 0
      ), true)
      gui:draw()
    elseif act.action == "gate" then
      gate_active = not not act.on
      gate_accum = 0
      gui:set_run_state({ gate_active = gate_active })
      gui:set_message(gate_active
        and string.format("Gate ON  %d step/s", gate_hz)
        or "Gate OFF  (realtime)", true)
      gui:draw()
    elseif act.action == "gate_hz" then
      if act.hz then
        gate_hz = act.hz
        gate_accum = 0
        gui:set_run_state({ gate_hz = gate_hz })
        persist_prefs()
        gui:set_message(string.format(
          "Gate %s  %d step/s", gate_active and "ON" or "OFF", gate_hz
        ), true)
      end
      gui:draw()
    elseif act.action == "gate_edit" then
      gui:draw_status_only()
    elseif act.action == "theme" then
      apply_theme(act.theme or Themes.next(theme_id))
      gui:set_run_state({ theme = theme_id })
      persist_prefs()
      local t = Themes.get(theme_id)
      gui:set_message("Theme: " .. t.id .. " (" .. t.label .. ")", true)
      gui:draw()
      paint_views()
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
        paint_views()
      end
    elseif act.action == "redraw" then
      gui:draw()
    end
    return true
  end

  local function refresh_side(side)
    local v = views[side]
    if not v then
      return
    end
    if peripheral.isPresent(side) then
      v.mon = peripheral.wrap(side) or v.mon
    end
    if identify_on then
      paint_identify_monitor(v)
      return
    end
    bind_view(v)
    if v.role == "lcd" or v.role == "face" then
      machine.lcd._dirty = true
      paint_views()
    elseif v.role == "mem" then
      paint_views()
    end
  end

  -- Combined face: paint inset LCD once keys are on screen.
  if any_face then
    machine.lcd._dirty = true
    paint_views()
  end

  local acc_cycles = 0
  local report_t = now_ms()
  local last_paint = report_t
  local tick = os.startTimer(0)

  while true do
    local ev, a, b, c = os.pullEventRaw()

    if ev == "timer" and a == tick then
      local t_now = now_ms()
      local dt = (t_now - last_tick_ms) / 1000
      last_tick_ms = t_now
      if dt < 0 then dt = 0 end
      if dt > 0.25 then dt = 0.25 end

      if install then
        -- Pause Z80 while installing so we never mutate flash under a live OS
        -- without an immediate reset, and so parse can span multiple ticks.
        step_install()
      elseif not paused then
        local ran = 0
        if gate_active then
          gate_accum = gate_accum + dt * math.max(1, gate_hz)
          local steps = math.floor(gate_accum)
          if steps > 5000 then
            steps = 5000
          end
          gate_accum = gate_accum - steps
          for _ = 1, steps do
            ran = ran + machine:step_instruction()
          end
        else
          -- Wall-clock budget. Fixed cycles_per_tick (~2 GB frames) was only
          -- ~67% realtime, so the APU under-produced vs speaker 48 kHz -> gaps.
          local budget = math.floor(emu_hz * dt + 0.5)
          local max_budget = math.floor(emu_hz * 0.1) -- hitch catch-up cap
          if budget > max_budget then budget = max_budget end
          if audio and not audio.muted then
            -- Keep near 100% when audio is live; fall back to a 50ms slice.
            local min_rt = math.floor(emu_hz * 0.05 + 0.5)
            if budget < min_rt then budget = min_rt end
          else
            if budget < 1 then budget = cycles_per_tick end
            if budget > cycles_per_tick * 2 then budget = cycles_per_tick * 2 end
          end
          if budget < 1 then budget = 1 end
          ran = machine:run_cycles(budget)
        end
        acc_cycles = acc_cycles + ran
        advance_key_hold(ran)
        flush_audio()
      end

      -- Only spend paint budget when something visible needs it.
      -- Skip a frame if the speaker has no staged chunk (paint stalls -> gaps).
      if identify_on then
        -- Static name overlay; redrawn on toggle/resize, not every tick.
        if machine:display_dirty() then
          machine:clear_display_dirty()
        end
      elseif not any_lcd and not any_mem then
        if machine:display_dirty() then
          machine:clear_display_dirty()
        end
      elseif not audio_starving()
        and (t_now - last_paint) >= paint_ms
        and ((any_lcd and machine:display_dirty()) or any_mem) then
        paint_views()
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
        -- Produce/stage the following chunk immediately after refill play.
        flush_audio()
      end

    elseif ev == "mouse_click" then
      local prev_hz = gate_hz
      local keep = handle_gui_action(gui:click(b, c))
      if gui.gate_hz ~= gate_hz then
        gate_hz = gui.gate_hz
        gate_accum = 0
        persist_prefs()
      elseif prev_hz ~= gate_hz then
        persist_prefs()
      end
      if not keep then
        release_held()
        if term and term.setCursorBlink then
          term.setCursorBlink(false)
        end
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
      -- CC key events pass a numeric code; resolve to keys.* name ("backspace", ...).
      local key_name = a
      if type(a) == "number" and type(keys) == "table" and type(keys.getName) == "function" then
        key_name = keys.getName(a) or a
      end
      if gui.gate_hz_editing then
        local result = gui:gate_key(key_name, a)
        if result == "commit" then
          local hz = gui:commit_gate_edit()
          if hz then
            gate_hz = hz
            gate_accum = 0
            gui:set_run_state({ gate_hz = gate_hz })
            persist_prefs()
            gui:set_message(string.format(
              "Gate %s  %d step/s", gate_active and "ON" or "OFF", gate_hz
            ), true)
            gui:draw()
          else
            gui:draw_status_only()
          end
        elseif result then
          gui:draw_status_only()
        end
      elseif keybind_map and b ~= true then
        -- b=is_held: ignore key-repeat; hold until key_up.
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
      if type(a) == "number" then
        if gui.gate_hz_editing then
          gui:commit_gate_edit()
        end
        gui:scroll_by(a > 0 and 1 or -1)
        gui:draw()
      end

    elseif ev == "term_resize" then
      gui:draw()

    elseif ev == "monitor_touch" then
      if install then
        -- ignore pad during install (Z80 must stay paused across HEX yields)
      else
        local v, side = resolve_view(a)
        if v and v.face then
          local key = v.face:on_touch(side, b, c)
          if key then
            press_key(key)
          end
        elseif v and v.pad then
          local key = v.pad:on_touch(side, b, c)
          if key then
            press_key(key)
          end
        end
      end

    elseif ev == "monitor_resize" then
      local v, side = resolve_view(a)
      if v then
        refresh_side(side)
        if v.role == "lcd" or v.role == "mem" or v.role == "face" then
          paint_views()
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
        -- Side + modem alias of the same block: keep modem, drop/ignore side.
        local preferred = CC.prefer_monitor_name(a)
        if not preferred then
          local canonical = CC.canonical_monitor_name(a)
          if canonical then
            remember_alias(a, canonical)
          end
          gui:set_message("Ignored side alias " .. tostring(a) .. " (using modem)", true)
          gui:draw()
        elseif views[preferred] then
          rebuild_aliases()
          refresh_side(preferred)
        else
          -- Modem name appeared while a side view already wraps that display.
          for side, v in pairs(views) do
            if side ~= preferred and CC.monitors_same(side, preferred) then
              remembered[preferred] = remembered[preferred] or v.role
              remove_monitor(side)
            end
          end
          local role = remembered[preferred] or remembered[a] or "pad"
          add_monitor(preferred, role)
          rebuild_aliases()
          persist_monitors()
          gui:set_monitors(gui_monitor_list())
          gui:set_message("Monitor attached: " .. tostring(preferred) .. " (" .. role .. ")", true)
          gui:draw()
          if identify_on and views[preferred] then
            paint_identify_monitor(views[preferred])
          end
        end
      end

    elseif ev == "peripheral_detach" then
      monitor_aliases[a] = nil
      if views[a] then
        -- Only the registered name (usually modem) removes the view.
        -- Side-alias detach is ignored so the modem view keeps working.
        local role = views[a].role
        remembered[a] = role
        remove_monitor(a)
        -- Modem gone but block still on a side: adopt the side name.
        for _, f in ipairs(CC.find_monitors()) do
          if not views[f.side] then
            remembered[f.side] = remembered[f.side] or role
            add_monitor(f.side, remembered[f.side])
          end
        end
        rebuild_aliases()
        persist_monitors()
        gui:set_monitors(gui_monitor_list())
        gui:set_message("Monitor detached: " .. tostring(a), true)
        gui:draw()
        if next(views) == nil then
          return fail("all monitors detached")
        end
      else
        rebuild_aliases()
      end

    elseif ev == "terminate" then
      release_held()
      persist_battery("terminate")
      if term and term.clear then
        term.setBackgroundColor(CC.colors().black)
        term.clear()
        term.setCursorPos(1, 1)
      end
      say("Stopped.")
      return true
    end
  end
end

return M
