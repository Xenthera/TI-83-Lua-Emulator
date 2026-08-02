-- Bridge console status: LAN IPs, sim rate, clients.

local M = {}

local PREFERRED_PREFIX = "10.21.12."

local function trim(s)
  return (tostring(s or ""):gsub("^%s+", ""):gsub("%s+$", ""))
end

--- Collect IPv4 addresses from the host (best-effort).
function M.list_ipv4()
  local seen, ips = {}, {}
  local function add(ip)
    ip = trim(ip)
    if ip == "" or ip:match("^127%.") or ip == "0.0.0.0" then
      return
    end
    -- Skip APIPA / link-local noise.
    if ip:match("^169%.254%.") then
      return
    end
    if not ip:match("^%d+%.%d+%.%d+%.%d+$") then
      return
    end
    if not seen[ip] then
      seen[ip] = true
      ips[#ips + 1] = ip
    end
  end

  local is_win = package.config:sub(1, 1) == "\\"
  local cmds
  if is_win then
    cmds = {
      'powershell - NoProfile - Command "Get-NetIPAddress - AddressFamily IPv4 - ErrorAction SilentlyContinue | ForEach-Object { $_.IPAddress }"',
      "ipconfig",
    }
  else
    cmds = {
      "hostname - I 2>/dev/null",
      "ip -4 -o addr show 2>/dev/null",
      "ifconfig 2>/dev/null",
    }
  end

  for _, cmd in ipairs(cmds) do
    local ok, f = pcall(io.popen, cmd)
    if ok and f then
      local out = f:read("*a") or ""
      f:close()
      if out ~= "" then
        if is_win and cmd:find("ipconfig", 1, true) then
          for ip in out:gmatch("IPv4 Address[.%s]*:%s*(%d+%.%d+%.%d+%.%d+)") do
            add(ip)
          end
          -- Some locales / Win versions
          for ip in out:gmatch("IP Address[.%s]*:%s*(%d+%.%d+%.%d+%.%d+)") do
            add(ip)
          end
        else
          for ip in out:gmatch("(%d+%.%d+%.%d+%.%d+)") do
            add(ip)
          end
        end
      end
    end
    if #ips > 0 then break end
  end

  table.sort(ips, function(a, b)
    local ap = a:sub(1, #PREFERRED_PREFIX) == PREFERRED_PREFIX
    local bp = b:sub(1, #PREFERRED_PREFIX) == PREFERRED_PREFIX
    if ap ~= bp then return ap end
    return a < b
  end)
  return ips
end

function M.preferred_ips(ips)
  ips = ips or M.list_ipv4()
  local pref, other = {}, {}
  for _, ip in ipairs(ips) do
    if ip:sub(1, #PREFERRED_PREFIX) == PREFERRED_PREFIX then
      pref[#pref + 1] = ip
    else
      other[#other + 1] = ip
    end
  end
  return pref, other
end

function M.format_mhz(hz)
  if not hz or hz <= 0 then return "0.00 MHz" end
  if hz >= 1e6 then
    return string.format("%.2f MHz", hz / 1e6)
  end
  if hz >= 1e3 then
    return string.format("%.1f kHz", hz / 1e3)
  end
  return string.format("%.0f Hz", hz)
end

--- One-shot startup banner.
function M.print_banner(info)
  info = info or {}
  local ips = info.ips or M.list_ipv4()
  local pref, other = M.preferred_ips(ips)
  local port = tostring(info.port or 8765)
  local host = tostring(info.host or "*")
  local machine = tostring(info.machine or "?")
  local rom = tostring(info.rom or "?")
  local w = info.w or 0
  local h = info.h or 0
  local cpu_hz = info.cpu_hz or 0
  local fps = info.fps or 0
  local cycles = info.cycles or 0
  local backend = tostring(info.backend or "?")

  print("============================================================")
  print("  TI Emulator Bridge  (LuaJIT <-> ComputerCraft WebSocket)")
  print("============================================================")
  print(string.format("  Machine : %s", machine))
  print(string.format("  ROM     : %s", rom))
  print(string.format("  LCD     : %dx%d", w, h))
  print(string.format("  CPU     : %s nominal", M.format_mhz(cpu_hz)))
  local throttle = info.throttle
  local speed = tonumber(info.speed) or 1.0
  if throttle == false then
    print(string.format("  Pace    : UNTHROTTLED  max slice %d cycles  frames %d fps", cycles, fps))
  elseif speed ~= 1.0 then
    print(string.format(
      "  Pace    : realtime x%.2f (%s)  max slice %d  frames %d fps",
      speed, M.format_mhz(cpu_hz * speed), cycles, fps))
  else
    print(string.format(
      "  Pace    : realtime 1.0x  max slice %d cycles  frames %d fps",
      cycles, fps))
  end
  print(string.format("  Socket  : %s", backend))
  print(string.format("  Listen  : %s:%s", host, port))
  print("------------------------------------------------------------")
  if #pref > 0 then
    print(string.format("  LAN IP  : %s   <- 10.21.12 subnet (prefer for CC)", pref[1]))
    for i = 2, #pref do
      print(string.format("         : %s", pref[i]))
    end
  elseif #ips > 0 then
    print(string.format("  LAN IP  : %s   (no 10.21.12.* address found)", ips[1]))
  else
    print("  LAN IP  : (none detected -- check adapters / run ipconfig)")
  end
  for _, ip in ipairs(other) do
    print(string.format("         : %s", ip))
  end
  print("------------------------------------------------------------")
  local urls = {}
  if #pref > 0 then
    for _, ip in ipairs(pref) do
      urls[#urls + 1] = string.format("ws://%s:%s", ip, port)
    end
  end
  for _, ip in ipairs(other) do
    urls[#urls + 1] = string.format("ws://%s:%s", ip, port)
  end
  urls[#urls + 1] = string.format("ws://127.0.0.1:%s", port)
  print("  CC connect examples:")
  for i, u in ipairs(urls) do
    local mark = (i == 1 and #pref > 0) and "  * " or "    "
    print(string.format("%s%s", mark, u))
  end
  print("============================================================")
  print("  Status line updates ~1/s  |  Ctrl+C to stop")
  print("")
  io.stdout:flush()
  return ips
end

--- Compact one-line live status (call ~1 Hz).
function M.print_live(s)
  s = s or {}
  local line = string.format(
    "[bridge] clients=%d  sim=%s / %s (%s%%)  frames=%.1f/s  keys=%d%s  seq=%d",
    s.clients or 0,
    M.format_mhz(s.sim_hz or 0),
    M.format_mhz(s.cpu_hz or 0),
    string.format("%.0f", math.min(999, (s.realtime_pct or 0))),
    s.frame_fps or 0,
    s.keys or 0,
    s.paused and "  PAUSED" or "",
    s.seq or 0
  )
  -- Pad/truncate for cleaner overwrite on supporting terminals.
  if #line < 96 then
    line = line .. string.rep(" ", 96 - #line)
  else
    line = line:sub(1, 96)
  end
  io.stdout:write("\r" .. line)
  io.stdout:flush()
end

function M.newline()
  io.stdout:write("\n")
  io.stdout:flush()
end

return M
