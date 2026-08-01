-- Minimal RFC6455 WebSocket server (text + binary frames).
-- Uses bridge.socket (LuaSocket or LuaJIT FFI -- no manual install).

local Sha1 = require("bridge.sha1")
local socket = require("bridge.socket")

local M = {}

local function now()
  local socket = package.loaded.socket
  if socket and socket.gettime then
    return socket.gettime()
  end
  return os.clock()
end

local function band8(a, b)
  local res, p = 0, 1
  for _ = 1, 8 do
    if (a % 2 == 1) and (b % 2 == 1) then res = res + p end
    a, b, p = math.floor(a / 2), math.floor(b / 2), p * 2
  end
  return res
end

local function bxor8(a, b)
  local res, p = 0, 1
  for _ = 1, 8 do
    if (a % 2) ~= (b % 2) then res = res + p end
    a, b, p = math.floor(a / 2), math.floor(b / 2), p * 2
  end
  return res
end

local function unmask(payload, mask)
  local m1, m2, m3, m4 = mask:byte(1, 4)
  local m = { m1, m2, m3, m4 }
  local out = {}
  local n = #payload
  for i = 1, n do
    out[i] = string.char(bxor8(payload:byte(i), m[((i - 1) % 4) + 1]))
  end
  return table.concat(out)
end

local function read_line(sock, deadline)
  local buf = {}
  while true do
    if deadline and now() > deadline then
      return nil, "timeout"
    end
    local chunk, err, partial = sock:receive(1)
    if not chunk then
      if partial and #partial > 0 then
        buf[#buf + 1] = partial
      end
      return nil, err or "closed"
    end
    buf[#buf + 1] = chunk
    local n = #buf
    if n >= 2 and buf[n - 1] == "\r" and buf[n] == "\n" then
      table.remove(buf)
      table.remove(buf)
      return table.concat(buf)
    end
  end
end

local function handshake(sock)
  sock:settimeout(10)
  local line, err = read_line(sock)
  if not line then return nil, err or "no request line" end
  if not line:match("^GET ") then
    return nil, "not a GET upgrade"
  end
  local headers = {}
  while true do
    line, err = read_line(sock)
    if not line then return nil, err end
    if line == "" then break end
    local k, v = line:match("^([^:]+):%s*(.*)$")
    if k then
      headers[k:lower()] = v
    end
  end
  local key = headers["sec-websocket-key"]
  if not key or (headers["upgrade"] or ""):lower() ~= "websocket" then
    return nil, "missing websocket headers"
  end
  local accept = Sha1.ws_accept(key)
  local resp = table.concat({
    "HTTP/1.1 101 Switching Protocols\r\n",
    "Upgrade: websocket\r\n",
    "Connection: Upgrade\r\n",
    "Sec-WebSocket-Accept: ", accept, "\r\n",
    "\r\n",
  })
  local ok, werr = sock:send(resp)
  if not ok then return nil, werr end
  sock:settimeout(0)
  return true
end

local function send_frame(sock, opcode, payload)
  payload = payload or ""
  local len = #payload
  local hdr
  if len < 126 then
    hdr = string.char(0x80 + opcode, len)
  elseif len < 65536 then
    hdr = string.char(0x80 + opcode, 126, math.floor(len / 256), len % 256)
  else
    return nil, "payload too large"
  end
  return sock:send(hdr .. payload)
end

local Client = {}
Client.__index = Client

-- Complete a WebSocket frame even if the TCP window is full.
-- Nonblocking (timeout=0) short-sends corrupt framing and drop acks.
function Client:send_text(s)
  local prev = self.sock._timeout
  self.sock:settimeout(5)
  local r, err = send_frame(self.sock, 0x1, s)
  self.sock:settimeout(prev or 0)
  if r == nil then return nil, err end
  return true
end

function Client:send_binary(s)
  local prev = self.sock._timeout
  self.sock:settimeout(5)
  local r, err = send_frame(self.sock, 0x2, s)
  self.sock:settimeout(prev or 0)
  if r == nil then return nil, err end
  return true
end

function Client:close()
  pcall(send_frame, self.sock, 0x8, "")
  pcall(function() self.sock:close() end)
  self.closed = true
end

--- Pull available TCP bytes into the client receive buffer.
function Client:_fill_rx()
  -- Large enough for a ~12KB load_rom chunk JSON in one or few reads.
  local chunk, err, partial = self.sock:receive(65536)
  if chunk and #chunk > 0 then
    self.rx = (self.rx or "") .. chunk
    return true
  end
  if partial and #partial > 0 then
    self.rx = (self.rx or "") .. partial
    if err == "timeout" then return true end
    return true, err
  end
  if err == "timeout" then
    return false, "timeout"
  end
  return false, err or "closed"
end

--- Try to parse one complete WS frame from self.rx. Does not consume TCP.
-- Returns opcode, payload | nil, err ("timeout" = need more data).
function Client:_take_frame()
  local buf = self.rx or ""
  if #buf < 2 then return nil, nil, "timeout" end
  local b1, b2 = buf:byte(1, 2)
  local opcode = band8(b1, 0x0F)
  local masked = band8(b2, 0x80) ~= 0
  local len = band8(b2, 0x7F)
  local off = 2
  if len == 126 then
    if #buf < off + 2 then return nil, nil, "timeout" end
    len = buf:byte(off + 1) * 256 + buf:byte(off + 2)
    off = off + 2
  elseif len == 127 then
    if #buf < off + 8 then return nil, nil, "timeout" end
    len = 0
    for i = 1, 8 do
      len = len * 256 + buf:byte(off + i)
    end
    off = off + 8
  end
  -- Cap absurd lengths (ROM chunks are ~12KB JSON).
  if len > (2 * 1024 * 1024) then
    return nil, nil, "frame too large"
  end
  local need = off + (masked and 4 or 0) + len
  if #buf < need then return nil, nil, "timeout" end
  local mask
  if masked then
    mask = buf:sub(off + 1, off + 4)
    off = off + 4
  end
  local payload = buf:sub(off + 1, off + len)
  self.rx = buf:sub(need + 1)
  if mask then
    payload = unmask(payload, mask)
  end
  return opcode, payload
end

function Client:poll()
  if self.closed then return nil, "closed" end
  -- Parse any complete frame already buffered before reading more TCP.
  local opcode, payload, err = self:_take_frame()
  if not opcode and err == "timeout" then
    local got, ferr = self:_fill_rx()
    if ferr and ferr ~= "timeout" and not got then
      self.closed = true
      return nil, ferr or "closed"
    end
    opcode, payload, err = self:_take_frame()
  end
  if not opcode then
    if err == "timeout" then return nil, "timeout" end
    self.closed = true
    return nil, err or "closed"
  end
  if opcode == 0x8 then
    self:close()
    return nil, "closed"
  elseif opcode == 0x9 then
    local prev = self.sock._timeout
    self.sock:settimeout(2)
    send_frame(self.sock, 0xA, payload) -- pong
    self.sock:settimeout(prev or 0)
    return nil, "ping"
  elseif opcode == 0xA then
    return nil, "pong"
  elseif opcode == 0x1 or opcode == 0x2 then
    return payload, opcode == 0x2 and "binary" or "text"
  end
  return nil, "opcode"
end

--- Start listening. opts: { host=, port=, on_client=function(client) }
function M.listen(opts)
  opts = opts or {}
  local host = opts.host or "*"
  local port = tonumber(opts.port) or 8765
  local server, err = socket.bind(host == "*" and "*" or host, port)
  if not server then
    return nil, "bind failed: " .. tostring(err)
  end
  server:settimeout(0)
  local addr, p = server:getsockname()
  return {
    server = server,
    host = addr,
    port = p,
    clients = {},
    accept = function(self)
      local sock = self.server:accept()
      if not sock then return nil end
      sock:setoption("tcp-nodelay", true)
      local ok, herr = handshake(sock)
      if not ok then
        pcall(function() sock:close() end)
        return nil, herr
      end
      local peer = "?"
      local okp, peer_ip, peer_port = pcall(function()
        return sock:getpeername()
      end)
      if okp and peer_ip then
        peer = tostring(peer_ip)
        if peer_port then
          peer = peer .. ":" .. tostring(peer_port)
        end
      end
      local c = setmetatable({ sock = sock, closed = false, peer = peer, rx = "" }, Client)
      self.clients[#self.clients + 1] = c
      if opts.on_client then opts.on_client(c, self) end
      return c
    end,
    prune = function(self)
      local keep = {}
      local dropped = 0
      for _, c in ipairs(self.clients) do
        if not c.closed then
          keep[#keep + 1] = c
        else
          dropped = dropped + 1
        end
      end
      if dropped > 0 then
        io.stdout:write("\n")
        print(string.format("client disconnected  (%d total)", #keep))
        io.stdout:flush()
      end
      self.clients = keep
      return dropped
    end,
    broadcast_text = function(self, s)
      for _, c in ipairs(self.clients) do
        if not c.closed then
          local ok = c:send_text(s)
          if not ok then c.closed = true end
        end
      end
    end,
    broadcast_binary = function(self, s)
      for _, c in ipairs(self.clients) do
        if not c.closed then
          local ok = c:send_binary(s)
          if not ok then c.closed = true end
        end
      end
    end,
    close = function(self)
      for _, c in ipairs(self.clients) do c:close() end
      pcall(function() self.server:close() end)
    end,
  }
end

return M
