-- TI project: on-disk .tc sources + thin project.tiproj manifest.
-- Packed .tiproj (embedded files) still loads and unpacks to a folder.

local M = {}

local FORMAT = "tiproj"
local VERSION = 1

local function encode_string(s)
  -- Avoid patterns with embedded NUL - Lua treats them as truncated ("missing ]").
  local out = {}
  for i = 1, #s do
    local c = s:sub(i, i)
    local b = c:byte()
    if c == "\\" then out[#out + 1] = "\\\\"
    elseif c == '"' then out[#out + 1] = '\\"'
    elseif c == "\n" then out[#out + 1] = "\\n"
    elseif c == "\r" then out[#out + 1] = "\\r"
    elseif c == "\t" then out[#out + 1] = "\\t"
    elseif b < 32 then out[#out + 1] = string.format("\\u%04x", b)
    else out[#out + 1] = c
    end
  end
  return '"' .. table.concat(out) .. '"'
end

local function encode(val)
  local t = type(val)
  if t == "nil" then
    return "null"
  elseif t == "boolean" then
    return val and "true" or "false"
  elseif t == "number" then
    return tostring(val)
  elseif t == "string" then
    return encode_string(val)
  elseif t == "table" then
    local is_arr = true
    local n = 0
    for k, _ in pairs(val) do
      n = n + 1
      if type(k) ~= "number" then is_arr = false break end
    end
    if is_arr and n == #val then
      local parts = {}
      for i = 1, #val do
        parts[i] = encode(val[i])
      end
      return "[" .. table.concat(parts, ",") .. "]"
    end
    local keys = {}
    for k, _ in pairs(val) do
      if type(k) == "string" then keys[#keys + 1] = k end
    end
    table.sort(keys)
    local parts = {}
    for _, k in ipairs(keys) do
      parts[#parts + 1] = encode_string(k) .. ":" .. encode(val[k])
    end
    return "{" .. table.concat(parts, ",") .. "}"
  end
  error("cannot encode " .. t)
end

local function decode(str)
  local i = 1
  local n = #str

  local function peek()
    return str:sub(i, i)
  end

  local function skip_ws()
    while i <= n and str:sub(i, i):match("%s") do
      i = i + 1
    end
  end

  local parse_value

  local function parse_string()
    if peek() ~= '"' then error("expected string at " .. i) end
    i = i + 1
    local out = {}
    while i <= n do
      local c = str:sub(i, i)
      if c == '"' then
        i = i + 1
        return table.concat(out)
      elseif c == "\\" then
        i = i + 1
        local e = str:sub(i, i)
        i = i + 1
        if e == "n" then out[#out + 1] = "\n"
        elseif e == "r" then out[#out + 1] = "\r"
        elseif e == "t" then out[#out + 1] = "\t"
        elseif e == '"' then out[#out + 1] = '"'
        elseif e == "\\" then out[#out + 1] = "\\"
        elseif e == "u" then
          local hex = str:sub(i, i + 3)
          i = i + 4
          out[#out + 1] = string.char(tonumber(hex, 16) % 256)
        else
          out[#out + 1] = e
        end
      else
        out[#out + 1] = c
        i = i + 1
      end
    end
    error("unterminated string")
  end

  local function parse_number()
    local s = i
    if peek() == "-" then i = i + 1 end
    while i <= n and str:sub(i, i):match("%d") do i = i + 1 end
    if peek() == "." then
      i = i + 1
      while i <= n and str:sub(i, i):match("%d") do i = i + 1 end
    end
    return tonumber(str:sub(s, i - 1))
  end

  local function parse_array()
    i = i + 1
    local arr = {}
    skip_ws()
    if peek() == "]" then i = i + 1 return arr end
    while true do
      arr[#arr + 1] = parse_value()
      skip_ws()
      if peek() == "]" then i = i + 1 return arr end
      if peek() ~= "," then error("expected , in array at " .. i) end
      i = i + 1
      skip_ws()
    end
  end

  local function parse_object()
    i = i + 1
    local obj = {}
    skip_ws()
    if peek() == "}" then i = i + 1 return obj end
    while true do
      skip_ws()
      local key = parse_string()
      skip_ws()
      if peek() ~= ":" then error("expected : at " .. i) end
      i = i + 1
      obj[key] = parse_value()
      skip_ws()
      if peek() == "}" then i = i + 1 return obj end
      if peek() ~= "," then error("expected , in object at " .. i) end
      i = i + 1
    end
  end

  parse_value = function()
    skip_ws()
    local c = peek()
    if c == '"' then return parse_string()
    elseif c == "{" then return parse_object()
    elseif c == "[" then return parse_array()
    elseif c == "t" and str:sub(i, i + 3) == "true" then i = i + 4 return true
    elseif c == "f" and str:sub(i, i + 4) == "false" then i = i + 5 return false
    elseif c == "n" and str:sub(i, i + 3) == "null" then i = i + 4 return nil
    elseif c == "-" or c:match("%d") then return parse_number()
    end
    error("unexpected JSON at " .. i)
  end

  local val = parse_value()
  skip_ws()
  return val
end

local function dirname(path)
  path = path:gsub("\\", "/")
  return path:match("^(.*)/[^/]+$") or "."
end

local function basename(path)
  path = path:gsub("\\", "/")
  return path:match("([^/]+)$") or path
end

local function join(a, b)
  if a:sub(-1) == "/" then return a .. b end
  return a .. "/" .. b
end

local function read_file(path)
  local f = io.open(path, "r")
  if not f then return nil end
  local s = f:read("*a")
  f:close()
  return s
end

local function is_windows()
  return package.config:sub(1, 1) == "\\"
end

local function write_file(path, body)
  local f, err = io.open(path, "w")
  if not f then return nil, err end
  f:write(body or "")
  if body and not body:match("\n$") then f:write("\n") end
  f:close()
  return true
end

local function ensure_dir(path)
  if is_windows() then
    local win = path:gsub("/", "\\"):gsub('"', "")
    os.execute(string.format('mkdir "%s" 2>nul', win))
  else
    os.execute(string.format('mkdir -p "%s"', path:gsub('"', '\\"')))
  end
end

local function list_tc_files(dir)
  local names = {}
  local p
  if is_windows() then
    local win = dir:gsub("/", "\\"):gsub('"', "")
    p = io.popen(string.format('dir /b "%s\\*.tc" 2>nul', win))
  else
    p = io.popen(string.format('ls -1 "%s" 2>/dev/null', dir:gsub('"', '\\"')))
  end
  if not p then return names end
  for raw in p:lines() do
    local line = raw:gsub("\r", "")
    if line:match("%.tc$") then
      names[#names + 1] = line
    end
  end
  p:close()
  table.sort(names)
  return names
end

function M.encode(doc)
  return encode(doc)
end

function M.decode(str)
  return decode(str)
end

function M.new(opts)
  opts = opts or {}
  return {
    format = FORMAT,
    version = VERSION,
    name = opts.name or "untitled",
    entry = opts.entry or "main.tc",
    files = opts.files or {
      ["main.tc"] = "// Tiny-C project\nvoid main() {\n  while (1) { halt(); }\n}\n",
    },
    dir = opts.dir,
  }
end

function M.validate(doc)
  if type(doc) ~= "table" then return nil, "not an object" end
  if doc.format ~= FORMAT then return nil, "not a tiproj (format)" end
  if type(doc.version) ~= "number" then return nil, "missing version" end
  if type(doc.entry) ~= "string" then return nil, "missing entry" end
  if type(doc.files) ~= "table" then doc.files = {} end
  return true
end

function M.load_string(str)
  local ok, doc = pcall(decode, str)
  if not ok then return nil, doc end
  local v, err = M.validate(doc)
  if not v then return nil, err end
  if type(doc.name) ~= "string" then doc.name = "untitled" end
  if type(doc.files) ~= "table" then doc.files = {} end
  return doc
end

--- Thin manifest for disk projects (no embedded sources).
function M.manifest_string(doc)
  local m = {
    format = FORMAT,
    version = VERSION,
    name = doc.name or "untitled",
    entry = doc.entry or "main.tc",
  }
  if doc.target then
    m.target = doc.target
  end
  if doc.app_name then
    m.app_name = doc.app_name
  end
  if doc.force_pages then
    m.force_pages = doc.force_pages
  end
  if doc.sign ~= nil then
    m.sign = doc.sign and true or false
  end
  return encode(m)
end

--- Read *.tc from project dir into doc.files (disk wins).
function M.reload_from_dir(doc, dir)
  dir = dir or doc.dir
  if not dir then return doc end
  doc.dir = dir
  local on_disk = list_tc_files(dir)
  if #on_disk == 0 and next(doc.files or {}) then
    return doc
  end
  local files = {}
  for _, name in ipairs(on_disk) do
    local body = read_file(join(dir, name))
    if body then files[name] = body end
  end
  -- keep any in-memory files not yet on disk (unsaved new tabs)
  for name, body in pairs(doc.files or {}) do
    if files[name] == nil then
      files[name] = body
    end
  end
  doc.files = files
  if not files[doc.entry] then
    -- pick first .tc if entry missing
    if on_disk[1] then doc.entry = on_disk[1] end
  end
  return doc
end

--- Write all sources + thin project.tiproj into dir.
function M.save_dir(dir, doc)
  ensure_dir(dir)
  doc.dir = dir
  for name, body in pairs(doc.files or {}) do
    if type(name) == "string" and name:match("%.tc$") then
      local ok, err = write_file(join(dir, name), body)
      if not ok then return nil, err end
    end
  end
  local man = M.manifest_string(doc)
  local ok, err = write_file(join(dir, "project.tiproj"), man)
  if not ok then return nil, err end
  return dir
end

--- Packed tiproj with embedded files (shareable single file).
function M.save_packed(path, doc)
  local packed = {
    format = FORMAT,
    version = VERSION,
    name = doc.name or "untitled",
    entry = doc.entry or "main.tc",
    files = doc.files or {},
  }
  local v, err = M.validate(packed)
  if not v then return nil, err end
  if type(packed.files[packed.entry]) ~= "string" then
    return nil, "entry file missing: " .. tostring(packed.entry)
  end
  local str = encode(packed)
  local ok, e = write_file(path, str)
  if not ok then return nil, e end
  return path
end

function M.dump_string(doc)
  -- prefer packed form when files present (tests / export)
  if doc.files and doc.files[doc.entry] then
    return encode({
      format = FORMAT,
      version = VERSION,
      name = doc.name or "untitled",
      entry = doc.entry,
      files = doc.files,
    })
  end
  return M.manifest_string(doc)
end

function M.save_file(path, doc)
  -- If path ends with project.tiproj inside a dir, save as directory project.
  local base = basename(path)
  if base == "project.tiproj" then
    return M.save_dir(dirname(path), doc)
  end
  -- Legacy/single-file packed save
  return M.save_packed(path, doc)
end

function M.load_file(path)
  local f, err = io.open(path, "r")
  if not f then return nil, err end
  local str = f:read("*a")
  f:close()
  return M.load_string(str)
end

--- Open a project directory or a .tiproj file.
-- Returns doc with .dir set; sources loaded from disk when available.
function M.open(path)
  path = path:gsub("\\", "/"):gsub("/+$", "")
  local dir, tiproj_path

  -- directory with manifest and/or .tc sources?
  local marker = join(path, "project.tiproj")
  local mf = io.open(marker, "r")
  local has_tc = io.open(join(path, "main.tc"), "r")
  if mf or has_tc then
    if mf then mf:close() end
    if has_tc then has_tc:close() end
    dir = path
    tiproj_path = mf and marker or nil
  elseif path:match("%.tiproj$") then
    tiproj_path = path
    local doc, err = M.load_file(path)
    if not doc then return nil, err end
    local parent = dirname(path)
    local base = basename(path):gsub("%.tiproj$", "")
    -- Prefer sibling folder projects/<name>/ if it exists
    local sibling = join(parent, base)
    if base ~= "project" then
      local sm = io.open(join(sibling, "project.tiproj"), "r")
        or io.open(join(sibling, "main.tc"), "r")
      if sm then
        sm:close()
        dir = sibling
      end
    end
    if not dir then
      -- Packed tiproj: unpack into projects/<name>/
      if doc.files and next(doc.files) then
        dir = join(parent, doc.name or base)
        M.save_dir(dir, doc)
      else
        dir = parent
        doc.dir = dir
        M.reload_from_dir(doc, dir)
        doc.manifest = tiproj_path
        return doc
      end
    end
    doc.dir = dir
    M.reload_from_dir(doc, dir)
    doc.manifest = join(dir, "project.tiproj")
    return doc
  else
    return nil, "not a project path: " .. path
  end

  local doc
  if tiproj_path then
    doc = M.load_file(tiproj_path)
  end
  if not doc then
    doc = M.new({ name = basename(dir), entry = "main.tc", files = {} })
  end
  doc.dir = dir
  M.reload_from_dir(doc, dir)
  if not doc.files[doc.entry] then
    return nil, "entry missing on disk: " .. tostring(doc.entry)
  end
  doc.manifest = join(dir, "project.tiproj")
  return doc
end

function M.compile_opts(doc, root)
  local opts = {
    root = root,
    files = doc.files,
    entry = doc.entry,
    name = doc.name,
  }
  if doc.target then
    opts.target = doc.target
  end
  if doc.app_name then
    opts.app_name = doc.app_name
  elseif doc.target == "app" and doc.name then
    opts.app_name = doc.name
  end
  if doc.force_pages then
    opts.force_pages = doc.force_pages
  end
  if doc.sign ~= nil then
    opts.sign = doc.sign and true or false
  end
  return opts
end

M.dirname = dirname
M.join = join

return M
