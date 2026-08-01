-- Socket backend for the bridge: prefer real LuaSocket, else LuaJIT FFI.
-- Always returns a LuaSocket-shaped module and registers package.loaded.socket.

local function load_backend()
  local ok, sock = pcall(require, "socket")
  if ok and type(sock) == "table" and sock.bind and sock.gettime then
    sock._backend = "luasocket"
    return sock
  end
  local ffi_ok, ffi_sock = pcall(require, "bridge.socket_ffi")
  if ffi_ok and type(ffi_sock) == "table" and ffi_sock.bind then
    ffi_sock._backend = "ffi"
    return ffi_sock
  end
  error("no socket backend (LuaSocket missing and FFI failed: "
    .. tostring(ffi_sock) .. ")")
end

local sock = load_backend()
package.loaded["socket"] = sock
package.loaded["bridge.socket"] = sock
return sock
