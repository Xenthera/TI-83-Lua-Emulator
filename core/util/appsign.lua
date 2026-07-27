-- Sign TI-83+/84+ Flash Apps (.8xk) with RabbitSign (free key 0104).
-- Real calculators reject unsigned apps; the emulator accepts either.

local M = {}

local function is_executable(path)
  if type(path) ~= "string" or path == "" then return false end
  local f = io.open(path, "rb")
  if not f then return false end
  f:close()
  return true
end

local function which(cmd)
  local h = io.popen('command -v "' .. cmd .. '" 2>/dev/null')
  if not h then return nil end
  local line = h:read("*l")
  h:close()
  if line and line ~= "" and is_executable(line) then
    return line
  end
  return nil
end

--- Locate the rabbitsign binary.
-- Search order: opts.rabbitsign, $RABBITSIGN, tools/bin/rabbitsign, PATH.
function M.find_rabbitsign(root, opts)
  opts = opts or {}
  if type(opts.rabbitsign) == "string" and is_executable(opts.rabbitsign) then
    return opts.rabbitsign
  end
  local env = os.getenv("RABBITSIGN")
  if env and is_executable(env) then
    return env
  end
  root = root or "."
  local candidates = {
    root .. "/tools/bin/rabbitsign",
    root .. "/tools/bin/rabbitsign.exe",
  }
  for _, p in ipairs(candidates) do
    if is_executable(p) then return p end
  end
  return which("rabbitsign")
end

--- Optional on-disk key (builtin 0104 works without this).
function M.find_key(root, key_id)
  key_id = key_id or "0104"
  root = root or "."
  local path = root .. "/tools/keys/" .. key_id .. ".key"
  local f = io.open(path, "rb")
  if f then
    f:close()
    return path
  end
  return nil
end

local function shell_quote(s)
  return "'" .. tostring(s):gsub("'", "'\\''") .. "'"
end

local function run(cmd)
  local h = io.popen(cmd .. " 2>&1")
  if not h then
    return nil, "failed to run: " .. cmd
  end
  local out = h:read("*a") or ""
  local a, b, c = h:close()
  -- Lua 5.1 / LuaJIT: close -> true|nil (sometimes exit status as number)
  -- Lua 5.2+: close -> true|nil, "exit"|"signal", code
  local exit = 0
  if type(c) == "number" then
    exit = c
  elseif type(b) == "number" then
    exit = b
  elseif type(a) == "number" then
    exit = a
  elseif a == nil or a == false then
    exit = 1
  end
  return exit, out
end

--- Pull Intel HEX payload out of a TIFL .8xk (skip header + trailing checksum).
-- RabbitSign reads past the TIFL size and may treat the 2-byte checksum as hex;
-- if that checksum starts with 0x3A (':') signing fails with "invalid hex data".
local function intel_hex_from_app(data)
  if type(data) ~= "string" or #data < 80 then
    return nil, "app too small"
  end
  if data:sub(1, 8) == "**TIFL**" then
    local size = data:byte(75)
      + data:byte(76) * 256
      + data:byte(77) * 65536
      + data:byte(78) * 16777216
    if size < 16 or 78 + size > #data then
      return nil, "bad TIFL size field"
    end
    local hex = data:sub(79, 78 + size)
    if hex:sub(1, 1) ~= ":" then
      return nil, "TIFL payload is not Intel HEX"
    end
    return hex
  end
  -- Already plain hex
  local trimmed = data:match("^[\r\n%s]*(:.*)$") or data
  if trimmed:sub(1, 1) == ":" then
    return trimmed
  end
  return nil, "not a TIFL .8xk or Intel HEX file"
end

--- Sign GraphLink .8xk bytes. Returns signed bytes or nil, err.
-- opts: root, rabbitsign, key_id (default "0104"), key_file, force (default true)
function M.sign_bytes(xk_bytes, opts)
  opts = opts or {}
  if type(xk_bytes) ~= "string" or #xk_bytes < 16 then
    return nil, "invalid .8xk data"
  end
  local root = opts.root or "."
  local rs = M.find_rabbitsign(root, opts)
  if not rs then
    return nil,
      "rabbitsign not found (needed to sign apps for real calculators). "
        .. "Run: sh tools/install_rabbitsign.sh"
  end

  local hex, herr = intel_hex_from_app(xk_bytes)
  if not hex then
    return nil, herr
  end

  local key_id = opts.key_id or "0104"
  local key_file = opts.key_file or M.find_key(root, key_id)

  local tmp_dir = root .. "/dist"
  os.execute(string.format("mkdir -p %s", shell_quote(tmp_dir)))
  local in_path = tmp_dir .. "/.appsign_in.hex"
  local out_path = tmp_dir .. "/.appsign_out.8xk"

  local wf = io.open(in_path, "wb")
  if not wf then
    return nil, "cannot write temp " .. in_path
  end
  wf:write(hex)
  wf:close()
  os.remove(out_path)

  local args = { shell_quote(rs), "-g", "-q" }
  if opts.force ~= false then
    args[#args + 1] = "-f"
  end
  if opts.resign then
    args[#args + 1] = "-r"
  end
  if key_file then
    args[#args + 1] = "-k"
    args[#args + 1] = shell_quote(key_file)
  else
    args[#args + 1] = "-K"
    args[#args + 1] = shell_quote(key_id)
  end
  args[#args + 1] = "-o"
  args[#args + 1] = shell_quote(out_path)
  args[#args + 1] = shell_quote(in_path)

  local exit, out = run(table.concat(args, " "))
  local rf = io.open(out_path, "rb")
  local signed = rf and rf:read("*a") or nil
  if rf then rf:close() end
  os.remove(in_path)
  os.remove(out_path)

  if not signed or #signed < 16 then
    local detail = (out and out ~= "") and out or "no output file"
    return nil, "rabbitsign failed (exit " .. tostring(exit) .. "): " .. detail
  end
  if signed:sub(1, 8) ~= "**TIFL**" then
    return nil, "rabbitsign output is not a GraphLink .8xk"
  end
  return signed
end

--- True when RabbitSign is available for this root.
function M.available(root, opts)
  return M.find_rabbitsign(root, opts) ~= nil
end

return M
