-- ComputerCraft WebSocket client helpers (CC:Tweaked http.websocket).

local Protocol = require("bridge.protocol")

local M = {}

function M.connect(url, opts)
  opts = opts or {}
  if type(http) ~= "table" or type(http.websocket) ~= "function" then
    return nil, "http.websocket unavailable (need CC:Tweaked with HTTP enabled)"
  end
  url = url or opts.url
  if not url or url == "" then
    return nil, "WebSocket URL required (e.g. ws://127.0.0.1:8765)"
  end
  local ws, err = http.websocket(url)
  if not ws then
    return nil, "websocket connect failed: " .. tostring(err)
  end
  return {
    ws = ws,
    url = url,
    send = function(self, msg)
      local encoded = Protocol.encode(msg)
      local ok, a, b = pcall(function()
        return self.ws.send(encoded, false)
      end)
      if not ok then
        return nil, tostring(a)
      end
      -- CC:Tweaked may return false, err instead of throwing.
      if a == false then
        return nil, tostring(b or "websocket send failed")
      end
      return true
    end,
    --- Non-throwing receive. Returns msg | nil, err
    -- err is "timeout", "closed", or decode error — never confuses timeout with closed.
    receive = function(self, timeout)
      local ok, data, binary_or_err = pcall(function()
        return self.ws.receive(timeout)
      end)
      if not ok then
        return nil, "closed"
      end
      if data == nil then
        local why = tostring(binary_or_err or "")
        if why == "Timed out" or why:lower():find("timed out", 1, true) then
          return nil, "timeout"
        end
        return nil, "closed"
      end
      if binary_or_err == true then
        return nil, "unexpected binary frame"
      end
      return Protocol.decode(data)
    end,
    close = function(self)
      pcall(function() self.ws.close() end)
    end,
  }
end

--- Connect and complete hello handshake. Returns conn, hello_ok or nil, err.
function M.handshake(url, machine_id, opts)
  local conn, err = M.connect(url, opts)
  if not conn then return nil, err end
  local sok, serr = conn:send(Protocol.hello(machine_id, "display"))
  if not sok then
    conn:close()
    return nil, serr or "failed to send hello"
  end
  local deadline = (opts and opts.timeout) or 5
  local t0 = os.clock()
  while os.clock() - t0 < deadline do
    local msg, merr = conn:receive(0.5)
    if msg then
      if msg.t == "hello_ok" then
        return conn, msg
      elseif msg.t == "error" then
        conn:close()
        return nil, msg.msg or "server error"
      end
      -- Ignore early frames / state during handshake.
    elseif merr == "closed" then
      return nil, "connection closed during hello"
    end
  end
  conn:close()
  return nil, "hello timeout"
end

return M
