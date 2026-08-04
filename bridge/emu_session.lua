-- LuaJIT emu session: run machine, serve WebSocket clients.

local Protocol = require("bridge.protocol")
local WsServer = require("bridge.ws_server")
local Status = require("bridge.status")

local M = {}

local FACTORIES = {
  ti83plus = function()
    return require("machines.ti83plus.machine").new(),
      require("machines.ti83plus.hw.lcd")
  end,
  ti84plus = function()
    return require("machines.ti84plus.machine").new(),
      require("machines.ti84plus.hw.lcd")
  end,
  ti89 = function()
    return require("machines.ti89.machine").new(),
      require("machines.ti89.hw.lcd")
  end,
  ti92plus = function()
    return require("machines.ti92plus.machine").new(),
      require("machines.ti92plus.hw.lcd")
  end,
  gameboy = function()
    return require("machines.gameboy.machine").new(),
      require("machines.gameboy.hw.ppu")
  end,
  nes = function(opts)
    return require("machines.nes.machine").new(opts or {}),
      require("machines.nes.hw.ppu")
  end,
}

function M.run(opts)
  opts = opts or {}
  local machine_id = Protocol.canonical_id(opts.machine or "ti89")
  local info = Protocol.machine_info(machine_id)
  if not info then
    return nil, "unknown machine: " .. tostring(machine_id)
  end
  local factory = FACTORIES[machine_id]
  if not factory then
    return nil, "no factory for " .. machine_id
  end

  local ok_sock, sock_or_err = pcall(require, "bridge.socket")
  if not ok_sock then
    return nil,
      "socket backend failed: " .. tostring(sock_or_err) .. "\n"
        .. "  Need LuaJIT with FFI (Windows/Linux). See bridge/README.md"
  end
  local socket = sock_or_err

  local machine = factory(opts)
  local rom_path = opts.rom
  local rom_name = nil
  local save_dir = opts.save_dir or ("saves/" .. machine_id)
  if rom_path and rom_path ~= "" then
    local ok, err = machine:load_rom_file(rom_path)
    if not ok then
      return nil, err or ("ROM load failed: " .. tostring(rom_path))
    end
    rom_name = tostring(rom_path):match("([^/\\]+)$") or tostring(rom_path)
    if machine.rom_data and machine.rom_data.loaded then
      print("cart save loaded: " .. tostring(machine.save_path))
      io.stdout:flush()
    end
  elseif machine_id ~= "gameboy" and machine_id ~= "nes" then
    return nil, "--rom PATH required (optional only for gameboy/nes)"
  end
  machine:reset()

  local port = tonumber(opts.port) or 8765
  local host = opts.host or "*"
  local target_fps = tonumber(opts.fps) or 15
  local throttle = opts.throttle ~= false -- realtime by default; --no-throttle disables
  local speed = tonumber(opts.speed) or 1.0
  if speed <= 0 then speed = 1.0 end
  -- At most one queued tap while a key is already held (prevents spam doubles).
  local pending_tap = nil

  local srv
  local serr
  srv, serr = WsServer.listen({
    host = host,
    port = port,
    on_client = function(client, server)
      Status.newline()
      local n = #(server or srv).clients
      print(string.format(
        "client connected  peer=%s  (%d total)",
        tostring(client.peer or "?"), n))
      io.stdout:flush()
    end,
  })
  if not srv then
    return nil, serr
  end

  local cpu_hz = machine.CPU_HZ or machine._cpu_hz
    or (machine.cpu and machine.cpu.CPU_HZ) or 6000000
  -- Max cycles per loop iteration (responsiveness). Default ~8ms of guest time.
  local max_slice = tonumber(opts.cycles) or math.max(2048, math.floor(cpu_hz / 120))
  -- Default key-hold length ~1/60s of guest cycles.
  local default_hold = math.max(max_slice, math.floor(cpu_hz / 60))
  local target_hz = cpu_hz * speed
  -- Drop catch-up beyond 100ms (same window as Love2D).
  local max_lag_cycles = math.floor(target_hz * 0.1)

  if machine_id == "nes" and machine.apu then
    print("NES APU synth: " .. tostring(machine.apu.synth or "classic")
      .. "  (--apu-hq / --apu classic|hq)")
    io.stdout:flush()
  end

  Status.print_banner({
    machine = machine_id,
    rom = rom_name or rom_path or "(none -- wait for CC load_rom)",
    w = info.w,
    h = info.h,
    port = srv.port,
    host = srv.host,
    cpu_hz = cpu_hz,
    fps = target_fps,
    cycles = max_slice,
    throttle = throttle,
    speed = speed,
    backend = socket._backend or "?",
  })

  local paused = false
  local seq = 0
  local nbytes = info.bpr * info.h
  local last_frame = 0
  local frame_interval = 1 / target_fps
  local held_keys = {}
  -- Realtime pacing: guest cycles owed vs wall clock.
  local sim_origin = socket.gettime()
  local sim_cycles = 0
  -- Live stats (windowed ~1s).
  local stat_t0 = socket.gettime()
  local stat_cycles = 0
  local stat_frames = 0
  local frames_pushed_total = 0
  -- In-progress CC ROM upload: { name, size, n, parts, got }
  local rom_upload = nil
  -- Hold LCD frames after hello / during upload so load_rom_ok is not
  -- buried behind a TCP backlog of 30KB shade frames (reconnect stall).
  local hold_frames = false
  local hold_frames_until = nil

  local function set_hold_frames(on, ttl_s)
    hold_frames = not not on
    if hold_frames then
      hold_frames_until = socket.gettime() + (ttl_s or 20)
    else
      hold_frames_until = nil
    end
  end

  local function reset_throttle_clock()
    sim_origin = socket.gettime()
    sim_cycles = 0
  end

  local function hello_info()
    local h = {
      id = info.id,
      w = info.w,
      h = info.h,
      bpr = info.bpr,
      fmt = info.fmt,
      rom_loaded = not not machine.rom_loaded,
    }
    if rom_name then h.rom = rom_name end
    return h
  end

  local function gb_cart_title(bytes)
    if type(bytes) ~= "string" or #bytes < 0x144 then return nil end
    local t = bytes:sub(0x135, 0x144) -- cart title at 0x134..0x143
    t = t:gsub("%z.*$", ""):gsub("[^%w %-%_]", ""):gsub("^%s+", ""):gsub("%s+$", "")
    if t == "" then return nil end
    return t
  end

  local function send_msg(client, msg)
    return client:send_text(Protocol.encode(msg))
  end

  local function broadcast(msg)
    srv:broadcast_text(Protocol.encode(msg))
  end

  local function broadcast_audio_bin(bin)
    if srv.broadcast_binary then
      srv:broadcast_binary(bin)
    else
      -- Fallback (should not happen with current ws_server).
      for _, c in ipairs(srv.clients or {}) do
        if not c.closed then c:send_binary(bin) end
      end
    end
  end

  local AudioPcm = nil
  local apu_rate = nil
  local audio_chunk = 0
  local audio_pending = "" -- accumulated s8 PCM waiting for a full chunk
  local audio_seq = 0
  if (machine_id == "gameboy" or machine_id == "nes") and machine.apu then
    AudioPcm = require("bridge.audio_pcm")
    if machine_id == "nes" then
      apu_rate = machine.apu.SAMPLE_RATE or require("machines.nes.hw.apu").SAMPLE_RATE
    else
      apu_rate = machine.apu.SAMPLE_RATE or require("machines.gameboy.hw.apu").SAMPLE_RATE
    end
    audio_chunk = AudioPcm.CHUNK_SAMPLES or 8000
  end

  local function discard_apu()
    if machine.apu then
      local n = machine.apu:samples_pending()
      if n > 0 then machine.apu:drain_samples(n) end
    end
    audio_pending = ""
  end

  --- Drain APU into audio_pending; emit full chunks over WS (not tied to LCD).
  -- Prefer continuous realtime playback over aggressive drop/catch-up (that
  -- sounds like sped-up audio with pauses when the CC speaker underruns).
  local function flush_audio_chunks(force)
    if not AudioPcm or not machine.apu or hold_frames then return end
    local pending = machine.apu:samples_pending()
    if pending > 0 then
      -- Soft cap ~200 ms in the APU ring (only drop on large backlog).
      local max_keep = math.floor(apu_rate * 0.20)
      if pending > max_keep then
        machine.apu:drain_samples(pending - max_keep) -- drop oldest
        pending = max_keep
      end
      local floats, n = machine.apu:drain_samples(pending)
      if n > 0 then
        local bin = AudioPcm.resample_s8(floats, n, apu_rate, AudioPcm.SPEAKER_RATE)
        if bin and #bin > 0 then
          audio_pending = audio_pending .. bin
        end
      end
    end
    local max_pend = AudioPcm.MAX_PENDING_BYTES or (audio_chunk * 3)
    if #audio_pending > max_pend then
      local drop = #audio_pending - max_pend
      drop = drop - (drop % math.max(1, audio_chunk))
      if drop < 1 then drop = #audio_pending - max_pend end
      if drop > 0 then
        audio_pending = audio_pending:sub(drop + 1)
      end
    end
    while #audio_pending >= audio_chunk do
      local chunk = audio_pending:sub(1, audio_chunk)
      audio_pending = audio_pending:sub(audio_chunk + 1)
      audio_seq = audio_seq + 1
      broadcast_audio_bin(Protocol.audio_binary(audio_seq, AudioPcm.SPEAKER_RATE, chunk))
    end
    if force and #audio_pending > 0 then
      audio_seq = audio_seq + 1
      broadcast_audio_bin(Protocol.audio_binary(audio_seq, AudioPcm.SPEAKER_RATE, audio_pending))
      audio_pending = ""
    end
    return false
  end

  --- Push LCD frame only (audio is flushed separately).
  local function push_frame(force)
    if hold_frames then
      discard_apu()
      return
    end
    if not force and not machine:display_dirty() then
      return
    end
    seq = seq + 1
    local fb = machine:framebuffer()
    -- Binary frames: no JSON/b64 tax on CC (fallback JSON if binary send missing).
    if srv.broadcast_binary and Protocol.frame_binary then
      broadcast_audio_bin(Protocol.frame_binary(
        seq, machine:is_display_on(), fb, nbytes))
    else
      local msg = Protocol.frame(seq, machine:is_display_on(), fb, nbytes)
      msg.w = info.w
      msg.h = info.h
      msg.bpr = info.bpr
      broadcast(msg)
    end
    machine:clear_display_dirty()
    stat_frames = stat_frames + 1
    frames_pushed_total = frames_pushed_total + 1
  end

  local function finish_rom_upload(client, data, name)
    if machine_id ~= "gameboy" and machine_id ~= "nes" then
      send_msg(client, Protocol.error_msg("load_rom: only supported for gameboy/nes"))
      return
    end
    local min_sz = (machine_id == "nes") and 16 or 0x150
    if type(data) ~= "string" or #data < min_sz then
      send_msg(client, Protocol.error_msg("load_rom: cart too small"))
      return
    end
    local default_name = (machine_id == "nes") and "cart.nes" or "cart.gb"
    -- Basename-only uploads store .sav under saves/<machine>/ (ROM stays read-only).
    local ok, err = machine:load_rom_bytes(data, {
      path = name or rom_name or default_name,
      save_dir = save_dir,
    })
    if not ok then
      send_msg(client, Protocol.error_msg("load_rom: " .. tostring(err or "failed")))
      return
    end
    rom_name = name or rom_name or default_name
    rom_path = rom_name
    held_keys = {}
    pending_tap = nil
    machine:reset()
    reset_throttle_clock()
    local title = (machine_id == "gameboy") and gb_cart_title(data)
      or (machine.rom_data and machine.rom_data.title)
    Status.newline()
    print(string.format(
      "ROM loaded via WS  name=%s  size=%d%s%s",
      tostring(rom_name), #data,
      title and ("  title=" .. title) or "",
      (machine.rom_data and machine.rom_data.loaded)
        and ("  save=" .. tostring(machine.save_path)) or ""))
    io.stdout:flush()
    -- Keep frames held until client sends ready (ack must go out alone).
    set_hold_frames(true, 20)
    local ok_msg = Protocol.load_rom_ok({ name = rom_name, size = #data, title = title })
    local sok, serr = send_msg(client, ok_msg)
    if not sok then
      Status.newline()
      print("warn: load_rom_ok send failed: " .. tostring(serr))
      io.stdout:flush()
    end
    send_msg(client, Protocol.state({
      paused = paused,
      rom_loaded = true,
      rom = rom_name,
      title = title,
    }))
    if machine.lcd then machine.lcd._dirty = true end
    last_frame = socket.gettime() + 0.5
  end

  local function report_status()
    local now = socket.gettime()
    local dt = now - stat_t0
    if dt < 1.0 then return end
    local sim_hz = stat_cycles / dt
    local frame_fps = stat_frames / dt
    local pct = (cpu_hz > 0) and ((sim_hz / cpu_hz) * 100) or 0
    Status.print_live({
      clients = #srv.clients,
      sim_hz = sim_hz,
      cpu_hz = cpu_hz,
      realtime_pct = pct,
      frame_fps = frame_fps,
      keys = #held_keys,
      paused = paused,
      seq = seq,
    })
    stat_t0 = now
    stat_cycles = 0
    stat_frames = 0
  end

  local function release_named(name)
    machine:set_key(name, false)
    for i = #held_keys, 1, -1 do
      if held_keys[i].name == name then
        table.remove(held_keys, i)
      end
    end
  end

  local function any_held()
    return #held_keys > 0
  end

  --- Timed pad tap (auto-release after `hold` emu cycles).
  local function press_named(name, hold)
    release_named(name)
    machine:set_key(name, true)
    hold = tonumber(hold) or default_hold
    if hold < max_slice then hold = max_slice end
    held_keys[#held_keys + 1] = { name = name, remain = hold }
  end

  --- Keyboard / sustained hold until explicit key-up (remain = nil).
  local function hold_named(name)
    if not name or name == "" then return end
    -- Replace any prior timed/sustained entry for this button.
    for i = #held_keys, 1, -1 do
      if held_keys[i].name == name then
        table.remove(held_keys, i)
      end
    end
    machine:set_key(name, true)
    held_keys[#held_keys + 1] = { name = name, remain = nil }
  end

  local function advance_holds(ran)
    ran = ran or 0
    if ran <= 0 or #held_keys == 0 then return end
    local keep = {}
    for _, h in ipairs(held_keys) do
      if h.remain == nil then
        -- Sustained (keyboard): keep until key-up message.
        keep[#keep + 1] = h
      else
        h.remain = h.remain - ran
        if h.remain <= 0 then
          machine:set_key(h.name, false)
        else
          keep[#keep + 1] = h
        end
      end
    end
    held_keys = keep
  end

  local function accept_tap(name, hold)
    if not name or name == "" then return end
    if any_held() then
      -- Replace queue with latest key only (one in flight).
      pending_tap = { name = name, hold = hold }
      return
    end
    press_named(name, hold)
  end

  local function flush_pending_tap()
    if pending_tap and not any_held() then
      local t = pending_tap
      pending_tap = nil
      press_named(t.name, t.hold)
    end
  end

  local function handle_client_msg(client, text)
    local msg, derr = Protocol.decode(text)
    if not msg then
      send_msg(client, Protocol.error_msg(derr or "bad json"))
      return
    end
    local t = msg.t
    if t == "hello" then
      local want = msg.machine or machine_id
      if want == "ti89_gpu" then want = "ti89" end
      Status.newline()
      print(string.format(
        "client hello  machine=%s role=%s  peer=%s",
        tostring(msg.machine or "?"), tostring(msg.role or "?"),
        tostring(client.peer or "?")))
      io.stdout:flush()
      if want ~= machine_id then
        send_msg(client, Protocol.error_msg(
          "machine mismatch: host=" .. machine_id .. " client=" .. tostring(msg.machine)))
        return
      end
      -- Hold frames until client says ready (reconnect + cart upload path).
      set_hold_frames(true, 20)
      send_msg(client, Protocol.hello_ok(hello_info()))
      send_msg(client, Protocol.state({
        paused = paused,
        rom_loaded = not not machine.rom_loaded,
        rom = rom_name,
      }))
      -- Do NOT push LCD on hello: a 30KB shade frame (or a flood) fills the
      -- TCP window and load_rom_ok never reaches CC on reupload.
      if machine.lcd then machine.lcd._dirty = true end
    elseif t == "ready" then
      set_hold_frames(false)
      if machine.rom_loaded and machine.lcd then
        machine.lcd._dirty = true
      end
      last_frame = 0
    elseif t == "load_rom_begin" then
      set_hold_frames(true, 60)
      if not rom_upload then
        rom_upload = {
          client = client,
          name = msg.name and tostring(msg.name) or "cart.gb",
          size = tonumber(msg.size) or 0,
          n = 0,
          parts = {},
          got = 0,
          begin_only = true,
        }
      end
      Status.newline()
      print(string.format(
        "ROM upload begin (hold frames)  name=%s size=%s",
        tostring(msg.name or "?"), tostring(msg.size or "?")))
      io.stdout:flush()
    elseif t == "load_rom" then
      if machine_id ~= "gameboy" and machine_id ~= "nes" then
        send_msg(client, Protocol.error_msg("load_rom: only supported for gameboy/nes"))
        return
      end
      local B64 = require("bridge.b64")
      local i = tonumber(msg.i) or 0
      local n = tonumber(msg.n) or 1
      local size = tonumber(msg.size) or 0
      local name = msg.name and tostring(msg.name)
        or ((machine_id == "nes") and "cart.nes" or "cart.gb")
      if n < 1 or i < 0 or i >= n then
        send_msg(client, Protocol.error_msg("load_rom: bad chunk index"))
        return
      end
      if size <= 0 or size > (8 * 1024 * 1024) then
        send_msg(client, Protocol.error_msg("load_rom: bad size"))
        return
      end
      local chunk = B64.decode(tostring(msg.b64 or ""))
      if type(chunk) ~= "string" then
        send_msg(client, Protocol.error_msg("load_rom: bad b64"))
        rom_upload = nil
        return
      end
      if n == 1 then
        if size > 0 and #chunk ~= size then
          send_msg(client, Protocol.error_msg(string.format(
            "load_rom: size mismatch got=%d want=%d", #chunk, size)))
          return
        end
        rom_upload = nil
        finish_rom_upload(client, chunk, name)
        return
      end
      -- Chunk 0 always starts a fresh transfer (clears stale state after disconnect).
      if i == 0 or not rom_upload or rom_upload.client ~= client
          or rom_upload.name ~= name or rom_upload.size ~= size or rom_upload.n ~= n then
        if i ~= 0 then
          send_msg(client, Protocol.error_msg("load_rom: unexpected chunk (restart from 0)"))
          rom_upload = nil
          return
        end
        rom_upload = {
          client = client,
          name = name,
          size = size,
          n = n,
          parts = {},
          got = 0,
        }
        Status.newline()
        print(string.format("ROM upload begin  name=%s size=%d chunks=%d", name, size, n))
        io.stdout:flush()
      end
      if not rom_upload.parts[i + 1] then
        rom_upload.parts[i + 1] = chunk
        rom_upload.got = rom_upload.got + 1
      else
        rom_upload.parts[i + 1] = chunk
      end
      if (rom_upload.got % 16) == 0 or rom_upload.got >= n then
        Status.newline()
        print(string.format("ROM upload  %d/%d chunks", rom_upload.got, n))
        io.stdout:flush()
      end
      if rom_upload.got >= n then
        local parts = {}
        for ci = 1, n do
          if not rom_upload.parts[ci] then
            send_msg(client, Protocol.error_msg("load_rom: missing chunk " .. (ci - 1)))
            rom_upload = nil
            return
          end
          parts[ci] = rom_upload.parts[ci]
        end
        local data = table.concat(parts)
        rom_upload = nil
        if #data ~= size then
          send_msg(client, Protocol.error_msg(string.format(
            "load_rom: size mismatch got=%d want=%d", #data, size)))
          return
        end
        finish_rom_upload(client, data, name)
      end
    elseif t == "load_rom_abort" then
      rom_upload = nil
    elseif t == "tap" then
      accept_tap(msg.name, msg.hold or default_hold)
    elseif t == "key" then
      -- down=true: sustained hold (keyboard). down=false: release.
      -- Timed pad clicks use t="tap", not this path.
      if msg.name and msg.name ~= "" then
        if msg.down then
          hold_named(msg.name)
          pending_tap = nil -- cancel queued tap; keyboard owns the button
        else
          release_named(msg.name)
          flush_pending_tap()
        end
      end
    elseif t == "pause" then
      paused = true
      Status.newline()
      print("paused")
      io.stdout:flush()
      broadcast(Protocol.state({ paused = true }))
    elseif t == "resume" then
      paused = false
      reset_throttle_clock()
      Status.newline()
      print("resumed")
      io.stdout:flush()
      broadcast(Protocol.state({ paused = false }))
    elseif t == "step" then
      paused = true
      if machine.step_instruction then
        machine:step_instruction()
      end
      if machine.lcd then machine.lcd._dirty = true end
      push_frame(true)
      broadcast(Protocol.state({ paused = true }))
    elseif t == "reset" then
      held_keys = {}
      pending_tap = nil
      machine:reset()
      reset_throttle_clock()
      if machine.lcd then machine.lcd._dirty = true end
      Status.newline()
      print("reset")
      io.stdout:flush()
      push_frame(true)
    elseif t == "ping" then
      send_msg(client, { t = "pong", v = Protocol.VERSION })
    end
  end

  while true do
    srv:accept()
    local dropped = srv:prune()
    if dropped and dropped > 0 then
      -- Drop in-flight cart transfer if the uploader left.
      if rom_upload and (not rom_upload.client or rom_upload.client.closed) then
        Status.newline()
        print("ROM upload aborted (client gone)")
        io.stdout:flush()
        rom_upload = nil
      end
    end

    for _, c in ipairs(srv.clients) do
      while true do
        local payload, kind = c:poll()
        if not payload then
          break
        end
        if kind == "text" or kind == "binary" then
          handle_client_msg(c, payload)
        end
      end
    end

    local now = socket.gettime()
    local sleep_s = 0.001
    -- Pause emu + frames while a cart is uploading so the ack is not
    -- stuck behind a flood of LCD frames (reconnect / reupload stall).
    local uploading = rom_upload ~= nil
    if hold_frames and hold_frames_until and now >= hold_frames_until then
      set_hold_frames(false)
      if machine.lcd then machine.lcd._dirty = true end
    end

    if paused or not machine.rom_loaded or uploading then
      -- Idle until a cart arrives (GB) or upload finishes.
      sleep_s = uploading and 0.001 or 0.01
    elseif throttle then
      local due = math.floor((now - sim_origin) * target_hz)
      local lag = due - sim_cycles
      if lag > max_lag_cycles then
        -- Hitch / debugger pause: drop excess debt instead of fast-forwarding.
        sim_cycles = due - max_lag_cycles
        lag = max_lag_cycles
      end
      if lag > 0 then
        local slice = lag
        if slice > max_slice then slice = max_slice end
        local ran = machine:run_cycles(slice) or 0
        if ran <= 0 then
          -- Halted: still advance the clock so we do not spin.
          ran = slice
        end
        sim_cycles = sim_cycles + ran
        stat_cycles = stat_cycles + ran
        advance_holds(ran)
        flush_pending_tap()
        -- If more work is owed, keep polling sockets without a long sleep.
        sleep_s = (lag > max_slice) and 0 or 0.0005
      else
        -- Ahead of schedule: sleep until the next cycles are due.
        local ahead = (sim_cycles / target_hz) - (now - sim_origin)
        if ahead < 0.0005 then ahead = 0.0005 end
        if ahead > 0.005 then ahead = 0.005 end
        sleep_s = ahead
      end
    else
      -- Unthrottled: run max_slice as fast as possible.
      local ran = machine:run_cycles(max_slice) or 0
      stat_cycles = stat_cycles + ran
      advance_holds(ran)
      flush_pending_tap()
      sleep_s = 0
    end

    now = socket.gettime()
    if hold_frames or uploading then
      -- Keep APU ring from growing while LCD/audio are held.
      discard_apu()
    else
      local audio_heavy = false
      if machine.rom_loaded then
        -- Audio chunks are independent of LCD dirty / frame interval.
        audio_heavy = flush_audio_chunks(false)
      end
      -- When the audio backlog is heavy, skip LCD so PCM keeps flowing.
      if machine.rom_loaded and not audio_heavy
          and (now - last_frame) >= frame_interval then
        push_frame(false)
        last_frame = now
      end
    end

    report_status()
    if sleep_s > 0 then
      socket.sleep(sleep_s)
    end
  end
end

return M
