-- Machine-like facade over a bridge WebSocket connection.
-- Frames are stashed (not decoded) until apply time so keypad events aren't starved.

local Protocol = require("bridge.protocol")
local B64 = require("bridge.b64")

local Remote = {}
Remote.__index = Remote

Remote.CPU_HZ = 16000000
-- Match native CC host: ~one full timer slice of held key.
Remote.TAP_HOLD = 400000
-- Raw bytes per load_rom chunk. Keep small so CC can yield between sends
-- without dropping the websocket (1MB carts are ~128 chunks at 8KiB).
Remote.ROM_CHUNK = 8 * 1024
-- Soft cap on queued audio pieces (~3x 100 ms chunks). Drop oldest only on flood.
Remote.AUDIO_Q_MAX = 4

local function now_s()
  if type(os) == "table" and type(os.epoch) == "function" then
    return os.epoch("utc") / 1000
  end
  return os.clock()
end

-- Yield one tick WITHOUT discarding websocket_message events.
-- sleep(0) / pullEvent("timer") filters and drops WS messages, which is why
-- load_rom_ok was lost when the bridge acked during an upload yield.
local function yield_keep_ws(self)
  if type(os) ~= "table" or type(os.pullEventRaw) ~= "function" then
    -- Non-CC fallback: drain then brief sleep.
    if self and self.poll then self:poll(0) end
    if type(sleep) == "function" then sleep(0) end
    return
  end
  os.queueEvent("ti_bridge_yield")
  while true do
    local ev, a, b, c = os.pullEventRaw()
    if ev == "ti_bridge_yield" then
      return
    elseif ev == "websocket_message" then
      if self and self.handle_raw then
        self:handle_raw(b, c)
      end
    elseif ev == "websocket_closed" then
      if self then self._alive = false end
      return
    elseif ev == "terminate" then
      error("Terminated", 0)
    end
    -- Other events (timers, redstone, ...) are discarded during upload only.
  end
end

local function push_audio_item(self, item)
  local q = self._audio_q
  q[#q + 1] = item
  while #q > Remote.AUDIO_Q_MAX do
    table.remove(q, 1)
  end
end

function Remote.connect(url, machine_id, opts)
  local Client = require("frontends.computercraft.ws.client")
  local conn, hello = Client.handshake(url, machine_id, opts)
  if not conn then
    return nil, hello
  end
  local info = Protocol.machine_info(machine_id) or {
    w = hello.w, h = hello.h, bpr = hello.bpr, id = machine_id,
  }
  local nbytes = (hello.bpr or info.bpr) * (hello.h or info.h)
  local rom_loaded = true
  if hello.rom_loaded ~= nil then
    rom_loaded = not not hello.rom_loaded
  end
  local self = setmetatable({
    conn = conn,
    url = conn.url,
    machine_id = machine_id,
    w = hello.w or info.w,
    h = hello.h or info.h,
    bpr = hello.bpr or info.bpr,
    fmt = hello.fmt or info.fmt,
    nbytes = nbytes,
    _fb = {},
    _dirty = true,
    _on = true,
    _paused = false,
    _alive = true,
    _pending_frame = nil, -- latest raw JSON frame string (coalesced)
    _audio_q = {}, -- FIFO: binary pcm string | JSON string | { _pcm = table }
    rom_loaded = rom_loaded,
    rom_name = hello.rom,
    lcd = { _dirty = true },
    total_cycles = 0,
    min_on_hold_cycles = math.floor(Remote.CPU_HZ / 2),
  }, Remote)
  for i = 0, nbytes - 1 do
    self._fb[i] = 0
  end
  self:poll(0.05)
  self:apply_pending_frame()
  return self
end

function Remote:handle_msg(msg)
  if type(msg) ~= "table" or not msg.t then return end
  local t = msg.t
  if t == "frame" then
    -- Decode immediately only if caller already parsed (poll path).
    Protocol.decode_frame_fb(msg, self._fb)
    self._on = msg.on ~= false
    self._dirty = true
    self.lcd._dirty = true
  elseif t == "audio" then
    -- Prefer handle_raw stash; if we get a parsed msg, re-encode is wasteful
    -- so decode immediately only as a fallback.
    local pcm = Protocol.decode_audio_pcm(msg)
    if pcm and #pcm > 0 then
      push_audio_item(self, { _pcm = pcm })
    end
  elseif t == "state" then
    if msg.paused ~= nil then self._paused = msg.paused end
    if msg.rom_loaded ~= nil then self.rom_loaded = not not msg.rom_loaded end
    if msg.rom ~= nil then self.rom_name = msg.rom end
    -- Only accept state-ack after all chunks were sent (avoids hello state races).
    if self._await_load_rom and self._load_rom_sent and msg.rom_loaded == true then
      self._load_rom_result = { ok = true, msg = msg }
    end
  elseif t == "load_rom_ok" then
    self.rom_loaded = true
    if msg.name then self.rom_name = msg.name end
    if self._await_load_rom then
      self._load_rom_result = { ok = true, msg = msg }
    end
  elseif t == "error" then
    print("bridge error: " .. tostring(msg.msg))
    if self._await_load_rom then
      local m = tostring(msg.msg or "")
      if m:find("load_rom", 1, true) then
        self._load_rom_result = { ok = false, err = m }
      end
    end
  end
end

function Remote:send_ready()
  return self:send(Protocol.ready())
end

--- Upload a cart/ROM to the bridge (chunked base64). Game Boy / NES.
-- opts.quiet: do not print progress (avoids scrolling an on-screen control GUI).
function Remote:load_rom_bytes(bytes, name, opts)
  local min_sz = (self.machine_id == "nes") and 16 or 0x150
  if type(bytes) ~= "string" or #bytes < min_sz then
    return nil, string.format("ROM too small (need >= %d bytes)", min_sz)
  end
  opts = opts or {}
  local quiet = not not opts.quiet
  name = name or ((self.machine_id == "nes") and "cart.nes" or "cart.gb")
  local size = #bytes
  local chunk_n = Remote.ROM_CHUNK
  local n = math.floor((size + chunk_n - 1) / chunk_n)
  if n < 1 then n = 1 end

  local function log(msg)
    if not quiet then print(msg) end
  end

  -- Ask bridge to stop LCD frames before we push ~64 chunk messages.
  self:send(Protocol.load_rom_begin({ name = name, size = size }))
  -- Drop any queued frames / hello leftovers.
  self:poll(0)
  yield_keep_ws(self)
  self:poll(0)

  self._await_load_rom = true
  self._load_rom_sent = false
  self._load_rom_result = nil

  local function take_result()
    local r = self._load_rom_result
    if not r then return end
    self._await_load_rom = false
    self._load_rom_sent = false
    self._load_rom_result = nil
    if r.ok then
      return true, r.msg
    end
    return false, r.err or "load_rom failed"
  end

  local function finish_ok(msg)
    self:send_ready()
    return true, msg
  end

  for i = 0, n - 1 do
    local from = i * chunk_n + 1
    local chunk = bytes:sub(from, from + chunk_n - 1)
    local ok, err = self:send(Protocol.load_rom_chunk({
      name = name,
      size = size,
      i = i,
      n = n,
      b64 = B64.encode(chunk),
    }))
    if not ok then
      self._await_load_rom = false
      self._load_rom_sent = false
      self._load_rom_result = nil
      return nil, err or "send failed"
    end
    -- Yield without sleep(0): filtered timer pulls discard websocket_message.
    yield_keep_ws(self)
    if not self._alive then
      self._await_load_rom = false
      self._load_rom_sent = false
      self._load_rom_result = nil
      return nil, "closed"
    end
    if (i % 16) == 15 or i == n - 1 then
      log(string.format("  upload %d/%d", i + 1, n))
    end
    local rok, rerr = take_result()
    if rok == false then
      return nil, rerr
    end
    if rok == true then
      return finish_ok(rerr)
    end
  end

  self._load_rom_sent = true
  log("  upload complete, waiting for bridge ack...")

  do
    local rok, rerr = take_result()
    if rok == true then return finish_ok(rerr) end
    if rok == false then return nil, rerr end
  end

  local deadline = now_s() + 60
  while now_s() < deadline do
    local rok, rerr = take_result()
    if rok == true then
      return finish_ok(rerr)
    end
    if rok == false then
      return nil, rerr
    end
    -- Prefer event-queue drain (same path that delivered mid-upload acks).
    if type(os) == "table" and type(os.pullEventRaw) == "function" then
      local timer = os.startTimer(0.5)
      while true do
        local ev, a, b, c = os.pullEventRaw()
        if ev == "timer" and a == timer then
          break
        elseif ev == "websocket_message" then
          self:handle_raw(b, c)
          local tr, te = take_result()
          if tr == true then return finish_ok(te) end
          if tr == false then return nil, te end
        elseif ev == "websocket_closed" then
          self._alive = false
          self._await_load_rom = false
          self._load_rom_sent = false
          self._load_rom_result = nil
          return nil, "closed"
        elseif ev == "terminate" then
          error("Terminated", 0)
        end
      end
    else
      local msg, err = self.conn:receive(0.5)
      if msg then
        if msg.t == "frame" then
          self._pending_frame = msg
        else
          self:handle_msg(msg)
        end
      elseif err == "closed" then
        self._alive = false
        self._await_load_rom = false
        self._load_rom_sent = false
        self._load_rom_result = nil
        return nil, "closed"
      end
    end
  end
  self._await_load_rom = false
  self._load_rom_sent = false
  self._load_rom_result = nil
  return nil, "load_rom timeout"
end

--- Fast path for websocket_message: stash frames/audio WITHOUT full JSON parse.
function Remote:handle_raw(data, is_binary)
  if type(data) ~= "string" then return end

  -- Detect binary by magic even if CC omits/mis-sets the isBinary flag.
  if (is_binary or (Protocol.is_frame_binary and Protocol.is_frame_binary(data))
      or Protocol.is_audio_binary(data)) then
    if Protocol.is_frame_binary and Protocol.is_frame_binary(data) then
      self._pending_frame = data
      return
    end
    if Protocol.is_audio_binary(data) then
      local pcm_bin = Protocol.decode_audio_binary(data)
      if pcm_bin and #pcm_bin > 0 then
        push_audio_item(self, { _bin = pcm_bin })
      end
      return
    end
    if is_binary then return end
  end

  -- Legacy JSON LCD: keep newest only. Hosts wake on has_pending_frame().
  if data:find('"t":"frame"', 1, true) then
    self._pending_frame = data
    return
  end
  -- Legacy JSON audio (older bridges).
  if data:find('"t":"audio"', 1, true) then
    push_audio_item(self, data)
    return
  end
  local msg = Protocol.decode(data)
  if msg then
    if msg.t == "frame" then
      self._pending_frame = data
    elseif msg.t == "audio" then
      push_audio_item(self, data)
    else
      self:handle_msg(msg)
    end
  end
end

function Remote:has_pending_frame()
  return self._pending_frame ~= nil
end

function Remote:apply_pending_frame()
  local raw = self._pending_frame
  if not raw then return false end
  self._pending_frame = nil
  if type(raw) == "table" then
    self:handle_msg(raw)
    return true
  end
  if type(raw) == "string" then
    -- Binary EFRM (preferred) or JSON b64 fast-path - avoid full JSON decode.
    if Protocol.is_frame_binary and Protocol.is_frame_binary(raw) then
      local ok, on = Protocol.decode_frame_binary(raw, self._fb)
      if ok then
        self._on = on ~= false
        self._dirty = true
        if self.lcd then self.lcd._dirty = true end
        return true
      end
      return false
    end
    if Protocol.decode_frame_raw then
      local ok, on = Protocol.decode_frame_raw(raw, self._fb)
      if ok then
        self._on = on ~= false
        self._dirty = true
        if self.lcd then self.lcd._dirty = true end
        return true
      end
    end
    local msg = Protocol.decode(raw)
    if msg and msg.t == "frame" then
      self:handle_msg(msg)
      return true
    end
  end
  return false
end

function Remote:poll(timeout)
  timeout = timeout or 0
  while true do
    local msg, err = self.conn:receive(timeout)
    if msg then
      if msg.t == "frame" then
        self._pending_frame = msg -- table; apply later
      else
        self:handle_msg(msg)
      end
      timeout = 0
    elseif err == "timeout" then
      return nil
    elseif err == "closed" then
      self._alive = false
      return "closed"
    else
      return err
    end
  end
end

--- Pop and decode at most one audio chunk to a PCM table (lazy).
function Remote:take_audio()
  local q = self._audio_q
  if not q or #q < 1 then return nil end
  local item = table.remove(q, 1)
  if type(item) == "table" and item._pcm then
    return item._pcm
  end
  if type(item) == "table" and type(item._bin) == "string" then
    local AudioPcm = require("bridge.audio_pcm")
    return AudioPcm.unpack_s8(item._bin)
  end
  if type(item) ~= "string" then return nil end
  -- Legacy JSON+b64 path.
  local pcm = Protocol.decode_audio_raw(item)
  if pcm and #pcm > 0 then return pcm end
  return nil
end

function Remote:audio_pending()
  local q = self._audio_q
  return q and #q > 0
end

function Remote:send(msg)
  if not self._alive then return nil, "closed" end
  local ok, err = self.conn:send(msg)
  if not ok then
    self._alive = false
    return nil, err
  end
  return true
end

function Remote:tap_key(key, hold)
  hold = hold or Remote.TAP_HOLD
  return self:send(Protocol.tap(key, hold))
end

function Remote:set_key(key, down)
  return self:send(Protocol.key(key, down))
end

function Remote:set_paused(p)
  return self:send({ t = p and "pause" or "resume", v = Protocol.VERSION })
end

function Remote:reset()
  return self:send({ t = "reset", v = Protocol.VERSION })
end

function Remote:step_instruction()
  return self:send({ t = "step", v = Protocol.VERSION })
end

function Remote:framebuffer()
  return self._fb
end

function Remote:display_dirty()
  return self._dirty
end

function Remote:clear_display_dirty()
  self._dirty = false
  self.lcd._dirty = false
end

function Remote:is_display_on()
  return self._on
end

function Remote:run_cycles(_n)
  return 0
end

function Remote:close()
  self._alive = false
  if self.conn then self.conn:close() end
end

return Remote
