-- Minimal LuaSocket-compatible TCP API via LuaJIT FFI (no external DLL).
-- Covers the subset used by bridge/ws_server.lua + emu_session.lua.

local ffi = require("ffi")

local M = {}

local function now_clock()
  return os.clock()
end

if ffi.os == "Windows" then
  ffi.cdef[[
    typedef unsigned short u_short;
    typedef unsigned long  u_long;
    typedef uintptr_t SOCKET;
    typedef int BOOL;
    typedef unsigned int DWORD;
    typedef uint16_t WORD;

    typedef struct WSAData {
      WORD wVersion;
      WORD wHighVersion;
      char szDescription[257];
      char szSystemStatus[129];
      unsigned short iMaxSockets;
      unsigned short iMaxUdpDg;
      char *lpVendorInfo;
    } WSADATA;

    typedef struct in_addr {
      uint32_t s_addr;
    } IN_ADDR;

    typedef struct sockaddr {
      u_short sa_family;
      char sa_data[14];
    } SOCKADDR;

    typedef struct sockaddr_in {
      short sin_family;
      u_short sin_port;
      IN_ADDR sin_addr;
      char sin_zero[8];
    } SOCKADDR_IN;

    int WSAStartup(WORD wVersionRequested, WSADATA *lpWSAData);
    int WSACleanup(void);
    int WSAGetLastError(void);
    SOCKET socket(int af, int type, int protocol);
    int closesocket(SOCKET s);
    int bind(SOCKET s, const SOCKADDR *name, int namelen);
    int listen(SOCKET s, int backlog);
    SOCKET accept(SOCKET s, SOCKADDR *addr, int *addrlen);
    int connect(SOCKET s, const SOCKADDR *name, int namelen);
    int send(SOCKET s, const char *buf, int len, int flags);
    int recv(SOCKET s, char *buf, int len, int flags);
    int setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen);
    int ioctlsocket(SOCKET s, long cmd, u_long *argp);
    int getsockname(SOCKET s, SOCKADDR *name, int *namelen);
    u_short htons(u_short hostshort);
    u_short ntohs(u_short netshort);
    unsigned long inet_addr(const char *cp);
    char *inet_ntoa(IN_ADDR in);
    void Sleep(DWORD dwMilliseconds);
    int QueryPerformanceCounter(int64_t *lpPerformanceCount);
    int QueryPerformanceFrequency(int64_t *lpFrequency);
  ]]

  local ws2 = ffi.load("Ws2_32")
  local kernel = ffi.load("kernel32")
  local INVALID = ffi.cast("SOCKET", -1)
  local AF_INET, SOCK_STREAM, IPPROTO_TCP = 2, 1, 6
  local SOL_SOCKET, SO_REUSEADDR = 0xFFFF, 4
  local IPPROTO_TCP_LVL, TCP_NODELAY = 6, 1
  local FIONBIO = 0x8004667E
  local WSAEWOULDBLOCK = 10035
  local SOMAXCONN = 0x7fffffff

  do
    local data = ffi.new("WSADATA")
    local ver = 0x0202
    if ws2.WSAStartup(ver, data) ~= 0 then
      error("WSAStartup failed: " .. tostring(ws2.WSAGetLastError()))
    end
  end

  local qpc_freq
  do
    local f = ffi.new("int64_t[1]")
    if kernel.QueryPerformanceFrequency(f) ~= 0 then
      qpc_freq = tonumber(f[0])
    end
  end

  function M.gettime()
    if qpc_freq then
      local c = ffi.new("int64_t[1]")
      kernel.QueryPerformanceCounter(c)
      return tonumber(c[0]) / qpc_freq
    end
    return now_clock()
  end

  function M.sleep(sec)
    sec = tonumber(sec) or 0
    if sec < 0 then sec = 0 end
    kernel.Sleep(math.floor(sec * 1000 + 0.5))
  end

  local Sock = {}
  Sock.__index = Sock

  local function set_nonblock(fd, on)
    local mode = ffi.new("u_long[1]", on and 1 or 0)
    return ws2.ioctlsocket(fd, FIONBIO, mode) == 0
  end

  local function sockerr()
    local e = ws2.WSAGetLastError()
    if e == WSAEWOULDBLOCK then return "timeout" end
    if e == 0 then return "closed" end
    return "error " .. tostring(e)
  end

  function Sock:settimeout(t)
    self._timeout = t
    if t == 0 then
      set_nonblock(self.fd, true)
    else
      set_nonblock(self.fd, false)
    end
  end

  function Sock:setoption(name, value)
    if name == "tcp-nodelay" then
      local v = ffi.new("int[1]", value and 1 or 0)
      ws2.setsockopt(self.fd, IPPROTO_TCP_LVL, TCP_NODELAY, ffi.cast("const char *", v), ffi.sizeof(v))
    elseif name == "reuseaddr" then
      local v = ffi.new("int[1]", value and 1 or 0)
      ws2.setsockopt(self.fd, SOL_SOCKET, SO_REUSEADDR, ffi.cast("const char *", v), ffi.sizeof(v))
    end
    return 1
  end

  function Sock:getpeername()
    return nil
  end

  function Sock:getsockname()
    local addr = ffi.new("SOCKADDR_IN")
    local len = ffi.new("int[1]", ffi.sizeof(addr))
    if ws2.getsockname(self.fd, ffi.cast("SOCKADDR *", addr), len) ~= 0 then
      return nil
    end
    local ip = ffi.string(ws2.inet_ntoa(addr.sin_addr))
    local port = ws2.ntohs(addr.sin_port)
    return ip, port
  end

  function Sock:close()
    if self.fd and self.fd ~= INVALID then
      ws2.closesocket(self.fd)
      self.fd = INVALID
    end
  end

  function Sock:send(data)
    data = tostring(data or "")
    local n = #data
    if n == 0 then return 0 end
    local sent = 0
    local deadline = nil
    if self._timeout and self._timeout > 0 then
      deadline = M.gettime() + self._timeout
    end
    while sent < n do
      local r = ws2.send(self.fd, data:sub(sent + 1), n - sent, 0)
      if r > 0 then
        sent = sent + r
      else
        local err = sockerr()
        if err == "timeout" then
          if self._timeout == 0 then
            if sent > 0 then return sent end
            return nil, "timeout"
          end
          if deadline and M.gettime() >= deadline then
            return sent > 0 and sent or nil, "timeout"
          end
          M.sleep(0.001)
        else
          return sent > 0 and sent or nil, err
        end
      end
    end
    return sent
  end

  function Sock:receive(pattern)
    local want
    if type(pattern) == "number" then
      want = pattern
    elseif pattern == "*l" then
      -- line mode not needed for our WS path beyond handshake helper
      want = 1
    else
      want = 1
    end
    if want <= 0 then return "" end

    local buf = ffi.new("char[?]", want)
    local got = 0
    local chunks = {}
    local deadline = nil
    if self._timeout and self._timeout > 0 then
      deadline = M.gettime() + self._timeout
    end

    while got < want do
      local r = ws2.recv(self.fd, buf + got, want - got, 0)
      if r > 0 then
        got = got + r
      elseif r == 0 then
        local partial = ffi.string(buf, got)
        if got > 0 then return nil, "closed", partial end
        return nil, "closed"
      else
        local err = sockerr()
        if err == "timeout" then
          if self._timeout == 0 then
            local partial = got > 0 and ffi.string(buf, got) or ""
            if got > 0 then return nil, "timeout", partial end
            return nil, "timeout"
          end
          if deadline and M.gettime() >= deadline then
            local partial = got > 0 and ffi.string(buf, got) or ""
            return nil, "timeout", partial
          end
          M.sleep(0.001)
        else
          local partial = got > 0 and ffi.string(buf, got) or ""
          return nil, err, partial
        end
      end
    end
    return ffi.string(buf, want)
  end

  function Sock:accept()
    local addr = ffi.new("SOCKADDR_IN")
    local len = ffi.new("int[1]", ffi.sizeof(addr))
    local fd = ws2.accept(self.fd, ffi.cast("SOCKADDR *", addr), len)
    if fd == INVALID then
      return nil, sockerr()
    end
    local c = setmetatable({ fd = fd, _timeout = nil }, Sock)
    c:settimeout(0)
    return c
  end

  function M.bind(host, port)
    port = tonumber(port) or 0
    host = host or "*"
    local fd = ws2.socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
    if fd == INVALID then
      return nil, sockerr()
    end
    local sock = setmetatable({ fd = fd, _timeout = nil }, Sock)
    sock:setoption("reuseaddr", true)
    local addr = ffi.new("SOCKADDR_IN")
    addr.sin_family = AF_INET
    addr.sin_port = ws2.htons(port)
    if host == "*" or host == "0.0.0.0" then
      addr.sin_addr.s_addr = 0
    else
      addr.sin_addr.s_addr = ws2.inet_addr(host)
    end
    if ws2.bind(fd, ffi.cast("SOCKADDR *", addr), ffi.sizeof(addr)) ~= 0 then
      local e = sockerr()
      sock:close()
      return nil, e
    end
    if ws2.listen(fd, SOMAXCONN) ~= 0 then
      local e = sockerr()
      sock:close()
      return nil, e
    end
    return sock
  end

else
  -- POSIX (Linux / macOS)
  ffi.cdef[[
    typedef uint16_t sa_family_t;
    typedef uint16_t in_port_t;
    typedef uint32_t in_addr_t;
    typedef long ssize_t;
    typedef unsigned int socklen_t;

    typedef struct in_addr { in_addr_t s_addr; } in_addr;
    typedef struct sockaddr {
      sa_family_t sa_family;
      char sa_data[14];
    } sockaddr;
    typedef struct sockaddr_in {
      sa_family_t sin_family;
      in_port_t sin_port;
      struct in_addr sin_addr;
      char sin_zero[8];
    } sockaddr_in;

    int socket(int domain, int type, int protocol);
    int bind(int sockfd, const sockaddr *addr, socklen_t addrlen);
    int listen(int sockfd, int backlog);
    int accept(int sockfd, sockaddr *addr, socklen_t *addrlen);
    ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    int close(int fd);
    int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    int fcntl(int fd, int cmd, ...);
    int getsockname(int sockfd, sockaddr *addr, socklen_t *addrlen);
    uint16_t htons(uint16_t hostshort);
    uint16_t ntohs(uint16_t netshort);
    in_addr_t inet_addr(const char *cp);
    char *inet_ntoa(struct in_addr in);
    int usleep(unsigned usec);
    int gettimeofday(struct timeval *tv, void *tz);
    typedef struct timeval { long tv_sec; long tv_usec; } timeval;
  ]]

  local C = ffi.C
  local AF_INET, SOCK_STREAM = 2, 1
  local SOL_SOCKET, SO_REUSEADDR = 1, 2
  local IPPROTO_TCP, TCP_NODELAY = 6, 1
  local F_GETFL, F_SETFL, O_NONBLOCK = 3, 4, 0x800
  if ffi.os == "OSX" then O_NONBLOCK = 0x0004 end

  function M.gettime()
    local tv = ffi.new("timeval")
    C.gettimeofday(tv, nil)
    return tonumber(tv.tv_sec) + tonumber(tv.tv_usec) / 1e6
  end

  function M.sleep(sec)
    sec = tonumber(sec) or 0
    if sec <= 0 then return end
    C.usleep(math.floor(sec * 1e6))
  end

  local Sock = {}
  Sock.__index = Sock

  local function set_nonblock(fd, on)
    local flags = C.fcntl(fd, F_GETFL, 0)
    if on then
      C.fcntl(fd, F_SETFL, bit_or(flags, O_NONBLOCK))
    else
      C.fcntl(fd, F_SETFL, bit_and(flags, bit_not(O_NONBLOCK)))
    end
  end

  function bit_or(a, b)
    local r, p = 0, 1
    for _ = 1, 32 do
      local aa, bb = a % 2, b % 2
      if aa == 1 or bb == 1 then r = r + p end
      a, b, p = math.floor(a / 2), math.floor(b / 2), p * 2
    end
    return r
  end
  function bit_and(a, b)
    local r, p = 0, 1
    for _ = 1, 32 do
      local aa, bb = a % 2, b % 2
      if aa == 1 and bb == 1 then r = r + p end
      a, b, p = math.floor(a / 2), math.floor(b / 2), p * 2
    end
    return r
  end
  function bit_not(a)
    return 4294967295 - a
  end

  function Sock:settimeout(t)
    self._timeout = t
    set_nonblock(self.fd, t == 0 or (t and t > 0))
    -- For positive timeout we still use nonblock + deadline loop.
    if t and t ~= 0 then set_nonblock(self.fd, true) end
    if t == nil then set_nonblock(self.fd, false) end
  end

  function Sock:setoption(name, value)
    if name == "tcp-nodelay" then
      local v = ffi.new("int[1]", value and 1 or 0)
      C.setsockopt(self.fd, IPPROTO_TCP, TCP_NODELAY, v, ffi.sizeof(v))
    elseif name == "reuseaddr" then
      local v = ffi.new("int[1]", value and 1 or 0)
      C.setsockopt(self.fd, SOL_SOCKET, SO_REUSEADDR, v, ffi.sizeof(v))
    end
    return 1
  end

  function Sock:getsockname()
    local addr = ffi.new("sockaddr_in")
    local len = ffi.new("socklen_t[1]", ffi.sizeof(addr))
    if C.getsockname(self.fd, ffi.cast("sockaddr *", addr), len) ~= 0 then
      return nil
    end
    return ffi.string(C.inet_ntoa(addr.sin_addr)), C.ntohs(addr.sin_port)
  end

  function Sock:close()
    if self.fd and self.fd >= 0 then
      C.close(self.fd)
      self.fd = -1
    end
  end

  function Sock:send(data)
    data = tostring(data or "")
    local n = #data
    local sent = 0
    local deadline = (self._timeout and self._timeout > 0) and (M.gettime() + self._timeout) or nil
    while sent < n do
      local r = C.send(self.fd, data:sub(sent + 1), n - sent, 0)
      if r > 0 then
        sent = sent + tonumber(r)
      else
        if self._timeout == 0 then
          return sent > 0 and sent or nil, "timeout"
        end
        if deadline and M.gettime() >= deadline then
          return sent > 0 and sent or nil, "timeout"
        end
        M.sleep(0.001)
      end
    end
    return sent
  end

  function Sock:receive(pattern)
    local want = type(pattern) == "number" and pattern or 1
    local buf = ffi.new("char[?]", want)
    local got = 0
    local deadline = (self._timeout and self._timeout > 0) and (M.gettime() + self._timeout) or nil
    while got < want do
      local r = C.recv(self.fd, buf + got, want - got, 0)
      if r > 0 then
        got = got + tonumber(r)
      elseif r == 0 then
        local partial = ffi.string(buf, got)
        return nil, "closed", partial
      else
        if self._timeout == 0 then
          local partial = got > 0 and ffi.string(buf, got) or ""
          return nil, "timeout", partial
        end
        if deadline and M.gettime() >= deadline then
          local partial = got > 0 and ffi.string(buf, got) or ""
          return nil, "timeout", partial
        end
        M.sleep(0.001)
      end
    end
    return ffi.string(buf, want)
  end

  function Sock:accept()
    local addr = ffi.new("sockaddr_in")
    local len = ffi.new("socklen_t[1]", ffi.sizeof(addr))
    local fd = C.accept(self.fd, ffi.cast("sockaddr *", addr), len)
    if fd < 0 then return nil, "timeout" end
    local c = setmetatable({ fd = fd, _timeout = nil }, Sock)
    c:settimeout(0)
    return c
  end

  function M.bind(host, port)
    port = tonumber(port) or 0
    host = host or "*"
    local fd = C.socket(AF_INET, SOCK_STREAM, 0)
    if fd < 0 then return nil, "socket" end
    local sock = setmetatable({ fd = fd, _timeout = nil }, Sock)
    sock:setoption("reuseaddr", true)
    local addr = ffi.new("sockaddr_in")
    addr.sin_family = AF_INET
    addr.sin_port = C.htons(port)
    if host == "*" or host == "0.0.0.0" then
      addr.sin_addr.s_addr = 0
    else
      addr.sin_addr.s_addr = C.inet_addr(host)
    end
    if C.bind(fd, ffi.cast("sockaddr *", addr), ffi.sizeof(addr)) ~= 0 then
      sock:close()
      return nil, "bind"
    end
    if C.listen(fd, 128) ~= 0 then
      sock:close()
      return nil, "listen"
    end
    return sock
  end
end

return M
