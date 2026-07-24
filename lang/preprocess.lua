-- Tiny-C preprocessor: #include "..." and #include <...>

local M = {}

local function dirname(path)
  path = path:gsub("\\", "/")
  local d = path:match("^(.*)/[^/]+$")
  return d or ""
end

local function join(a, b)
  if a == "" or a == "." then return b end
  if b:match("^/") then return b end
  return (a .. "/" .. b):gsub("/+", "/")
end

local function norm(path)
  path = path:gsub("\\", "/"):gsub("/+", "/")
  local parts = {}
  for part in path:gmatch("[^/]+") do
    if part == ".." then
      if #parts > 0 and parts[#parts] ~= ".." then
        parts[#parts] = nil
      else
        parts[#parts + 1] = part
      end
    elseif part ~= "." then
      parts[#parts + 1] = part
    end
  end
  local out = table.concat(parts, "/")
  if path:sub(1, 1) == "/" then
    out = "/" .. out
  end
  return out
end

local function strip_bom(s)
  if s:sub(1, 3) == "\239\187\191" then
    return s:sub(4)
  end
  return s
end

--- Resolve and read an include path.
-- opts.files: optional map of virtual project files (tiproj)
-- opts.root: project / repo root for disk and <stdlib/...>
-- opts.read_file: optional custom reader(path) -> string|nil
local function resolve(path, kind, from_file, opts)
  local candidates = {}
  if kind == "quote" then
    local base = dirname(from_file)
    if base ~= "" then
      candidates[#candidates + 1] = norm(join(base, path))
    end
    candidates[#candidates + 1] = norm(path)
    if opts.root then
      candidates[#candidates + 1] = norm(join(opts.root, path))
    end
  else
    -- angle: stdlib / rooted includes
    candidates[#candidates + 1] = norm(path)
    if opts.root then
      candidates[#candidates + 1] = norm(join(opts.root, path))
    end
  end

  local files = opts.files or {}
  for _, cand in ipairs(candidates) do
    local rel = cand
    if opts.root and cand:sub(1, #opts.root + 1) == opts.root .. "/" then
      rel = cand:sub(#opts.root + 2)
    end
    if files[cand] then
      return files[cand], cand
    end
    if files[rel] then
      return files[rel], rel
    end
    if opts.read_file then
      local body = opts.read_file(cand)
      if body then return body, cand end
      if rel ~= cand then
        body = opts.read_file(rel)
        if body then return body, rel end
      end
    end
    local f = io.open(cand, "r")
    if f then
      local body = f:read("*a")
      f:close()
      return body, cand
    end
  end
  return nil, nil
end

local function expand(src, filename, opts, visited, depth)
  if depth > 32 then
    error("include depth exceeded in " .. tostring(filename))
  end
  src = strip_bom(src or "")
  filename = filename or "<input>"
  local key = norm(filename)
  if visited[key] then
    return ""
  end
  visited[key] = true

  local out = {}
  -- Keep lexer locations mapped to original files across includes.
  out[#out + 1] = string.format("#line 1 \"%s\"\n", filename)
  local line_no = 0
  for line in (src .. "\n"):gmatch("(.-)\n") do
    line_no = line_no + 1
    local qpath = line:match("^%s*#%s*include%s+\"([^\"]+)\"%s*$")
    local apath = line:match("^%s*#%s*include%s+<([^>]+)>%s*$")
    if qpath or apath then
      local path = qpath or apath
      local kind = qpath and "quote" or "angle"
      local body, resolved = resolve(path, kind, filename, opts)
      if not body then
        error(string.format("%s:%d: cannot open include '%s'", filename, line_no, path))
      end
      out[#out + 1] = expand(body, resolved, opts, visited, depth + 1)
      if out[#out] ~= "" and not out[#out]:match("\n$") then
        out[#out] = out[#out] .. "\n"
      end
      out[#out + 1] = string.format("#line %d \"%s\"\n", line_no + 1, filename)
    else
      out[#out + 1] = line
      out[#out + 1] = "\n"
    end
  end
  return table.concat(out)
end

function M.preprocess(src, filename, opts)
  opts = opts or {}
  return expand(src, filename or "<input>", opts, {}, 0)
end

M.dirname = dirname
M.join = join
M.norm = norm

return M
