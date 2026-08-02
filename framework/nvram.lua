-- Battery-backed NVRAM: persist full machine savestates to disk.
-- Layout: <root>/saves/<machine_id>/{meta.lua, *.bin}
-- Binary blobs (flash, ram, lcd fb, ...) are .bin files; tables live in meta.lua.
-- Works on desktop (io) and ComputerCraft (fs).

local Path = require("framework.path")

local NVRAM = {}
NVRAM.VERSION = 1

local function join(root, ...)
  local base = tostring(root or "."):gsub("[/\\]+$", "")
  local parts = { base }
  for i = 1, select("#", ...) do
    parts[#parts + 1] = tostring(select(i, ...))
  end
  return table.concat(parts, "/")
end

local function has_fs()
  return type(fs) == "table" and type(fs.open) == "function"
end

local function write_bytes(path, data)
  data = data or ""
  if has_fs() then
    local h = fs.open(path, "wb")
    if not h then
      h = fs.open(path, "w")
    end
    if not h then
      return nil, "cannot write " .. tostring(path)
    end
    local ok, err = pcall(function()
      h.write(data)
    end)
    if not ok then
      -- Older binary handles only accept a byte number.
      for i = 1, #data do
        h.write(data:byte(i))
      end
    end
    h.close()
    return true
  end
  local f, err = io.open(path, "wb")
  if not f then return nil, err end
  f:write(data)
  f:close()
  return true
end

local function read_bytes(path)
  if has_fs() then
    if fs.exists and not fs.exists(path) then
      return nil, "file not found"
    end
    local h = fs.open(path, "rb")
    if not h then
      h = fs.open(path, "r")
    end
    if not h then
      return nil, "cannot open " .. tostring(path)
    end
    local data = h.readAll and h.readAll() or h.read("*a")
    h.close()
    if data == nil then
      return nil, "failed to read " .. tostring(path)
    end
    return data
  end
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local data = f:read("*a")
  f:close()
  return data
end

function NVRAM.dir(root, machine_id)
  return join(root, "saves", machine_id)
end

function NVRAM.exists(root, machine_id)
  local path = join(NVRAM.dir(root, machine_id), "meta.lua")
  if has_fs() and fs.exists then
    return fs.exists(path)
  end
  local f = io.open(path, "rb")
  if not f then return false end
  f:close()
  return true
end

local function encode_value(v, indent)
  local t = type(v)
  if t == "nil" then
    return "nil"
  elseif t == "boolean" then
    return v and "true" or "false"
  elseif t == "number" then
    if v ~= v then return "0/0" end -- NaN
    if v == math.huge then return "math.huge" end
    if v == -math.huge then return "-math.huge" end
    return string.format("%.17g", v)
  elseif t == "string" then
    return string.format("%q", v)
  elseif t == "table" then
    if v.__bin then
      return string.format("{ __bin = %q }", v.__bin)
    end
    local parts = {}
    local n = 0
    local is_array = true
    for k in pairs(v) do
      n = n + 1
      if type(k) ~= "number" or k < 1 or k ~= math.floor(k) then
        is_array = false
      end
    end
    if is_array and n > 0 then
      for i = 1, n do
        if v[i] == nil then
          is_array = false
          break
        end
      end
    end
    local ind = indent or ""
    local ind2 = ind .. "  "
    if is_array and n > 0 then
      parts[#parts + 1] = "{\n"
      for i = 1, n do
        parts[#parts + 1] = ind2 .. encode_value(v[i], ind2) .. ",\n"
      end
      parts[#parts + 1] = ind .. "}"
      return table.concat(parts)
    end
    parts[#parts + 1] = "{\n"
    local keys = {}
    for k in pairs(v) do keys[#keys + 1] = k end
    table.sort(keys, function(a, b)
      local ta, tb = type(a), type(b)
      if ta == tb then
        if ta == "number" then return a < b end
        return tostring(a) < tostring(b)
      end
      return ta < tb
    end)
    for _, k in ipairs(keys) do
      local key
      if type(k) == "string" and k:match("^[%a_][%w_]*$") then
        key = k
      elseif type(k) == "number" then
        key = "[" .. encode_value(k) .. "]"
      else
        key = "[" .. encode_value(tostring(k)) .. "]"
      end
      parts[#parts + 1] = ind2 .. key .. " = " .. encode_value(v[k], ind2) .. ",\n"
    end
    parts[#parts + 1] = ind .. "}"
    return table.concat(parts)
  end
  return "nil"
end

local function write_meta(path, doc)
  local body = "return " .. encode_value(doc, "") .. "\n"
  return write_bytes(path, body)
end

local function load_meta(path)
  local src, err = read_bytes(path)
  if not src then return nil, err end
  local chunk, cerr = (loadstring or load)(src, "@" .. path)
  if not chunk then return nil, cerr end
  local ok, doc = pcall(chunk)
  if not ok then return nil, doc end
  if type(doc) ~= "table" then return nil, "nvram meta root must be a table" end
  return doc
end

local function split_blobs(blobs)
  local meta = {}
  local bins = {}
  for k, v in pairs(blobs or {}) do
    if type(v) == "string" then
      local fname = tostring(k) .. ".bin"
      bins[fname] = v
      meta[k] = { __bin = fname }
    else
      meta[k] = v
    end
  end
  return meta, bins
end

local function join_blobs(meta_blobs, dir)
  local out = {}
  for k, v in pairs(meta_blobs or {}) do
    if type(v) == "table" and type(v.__bin) == "string" then
      local data, err = read_bytes(join(dir, v.__bin))
      if not data then
        return nil, "missing blob " .. tostring(k) .. ": " .. tostring(err)
      end
      out[k] = data
    else
      out[k] = v
    end
  end
  return out
end

local function blob_bytes(bins)
  local n = 0
  for _, data in pairs(bins) do
    n = n + #data
  end
  return n
end

--- Drop oversized flash on tight CC disks; RAM/CPU still resume the session.
local function maybe_drop_flash(root, dir, meta_blobs, bins)
  if not bins["flash.bin"] then
    return false
  end
  if not (has_fs() and fs.getFreeSpace) then
    return false
  end
  local probe = (fs.exists and fs.exists(dir) and dir) or tostring(root or ".")
  local free = fs.getFreeSpace(probe)
  if type(free) ~= "number" then
    return false
  end
  local need = blob_bytes(bins) + 8192
  if free >= need then
    return false
  end
  bins["flash.bin"] = nil
  meta_blobs.flash = nil
  return true
end

--- Save machine:saveState() under <root>/saves/<machine_id>/.
function NVRAM.save(root, machine)
  if not machine or not machine.saveState then
    return nil, "machine has no saveState"
  end
  local state, err = machine:saveState()
  if not state then return nil, err or "saveState failed" end
  local mid = state.machine_id or machine.MACHINE_ID or "unknown"
  local dir = NVRAM.dir(root, mid)
  Path.ensure_dir(join(root, "saves"))
  Path.ensure_dir(dir)

  local meta_blobs, bins = split_blobs(state.blobs)
  local dropped_flash = maybe_drop_flash(root, dir, meta_blobs, bins)

  for fname, data in pairs(bins) do
    local ok, werr = write_bytes(join(dir, fname), data)
    if not ok then
      -- Retry once without flash if a large image blew the disk.
      if fname == "flash.bin" or bins["flash.bin"] then
        bins["flash.bin"] = nil
        meta_blobs.flash = nil
        dropped_flash = true
        if fname ~= "flash.bin" then
          ok, werr = write_bytes(join(dir, fname), data)
        else
          ok = true
        end
      end
      if not ok then return nil, werr end
    end
  end

  local ok, werr = write_meta(join(dir, "meta.lua"), {
    format = "ti-nvram",
    version = NVRAM.VERSION,
    machine_id = mid,
    saved_at = os.time and os.time() or 0,
    flash_omitted = dropped_flash or nil,
    blobs = meta_blobs,
  })
  if not ok then return nil, werr end
  return true, dir
end

--- Load into an existing machine via loadState. Returns true, or nil, err.
function NVRAM.load(root, machine)
  if not machine or not machine.loadState then
    return nil, "machine has no loadState"
  end
  local mid = machine.MACHINE_ID
  if not mid then
    return nil, "machine has no MACHINE_ID"
  end
  local dir = NVRAM.dir(root, mid)
  local doc, err = load_meta(join(dir, "meta.lua"))
  if not doc then
    return nil, err or "no nvram"
  end
  if doc.format ~= "ti-nvram" then
    return nil, "unsupported nvram format"
  end
  if doc.version ~= NVRAM.VERSION then
    return nil, "unsupported nvram version"
  end
  if doc.machine_id ~= mid then
    return nil, "nvram machine mismatch"
  end

  local blobs, berr = join_blobs(doc.blobs, dir)
  if not blobs then return nil, berr end

  local SaveState = require("framework.savestate")
  local state = SaveState.new(doc.machine_id, blobs)
  return machine:loadState(state)
end

--- Convenience: save if machine present.
function NVRAM.save_if(root, machine)
  if not machine then return nil, "no machine" end
  return NVRAM.save(root, machine)
end

return NVRAM
