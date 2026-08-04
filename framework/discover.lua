-- Directory discovery for machines and shared hardware under a project ROOT.

local Discover = {}

local function norm(path)
  if not path or path == "" then return path end
  path = path:gsub("\\", "/")
  if path:sub(-1) == "/" then
    path = path:sub(1, -2)
  end
  return path
end

local function file_exists(path)
  local f = io.open(path, "rb")
  if not f then return false end
  f:close()
  return true
end

local function is_dir(path)
  if not path or path == "" then return false end
  local sep = package.config:sub(1, 1)
  local p
  if sep == "\\" then
    p = io.popen('if exist "' .. path:gsub("/", "\\") .. '\\." (echo ok)')
  else
    p = io.popen('test -d "' .. path:gsub('"', '\\"') .. '" && echo ok')
  end
  if not p then return false end
  local out = p:read("*l")
  p:close()
  return out == "ok"
end

--- List immediate subdirectory names under `dir` (not full paths).
function Discover.list_subdirs(dir)
  dir = norm(dir)
  local names = {}
  if not dir then return names end
  local sep = package.config:sub(1, 1)
  local p
  if sep == "\\" then
    local win = dir:gsub("/", "\\")
    p = io.popen('dir /b /ad "' .. win .. '" 2>nul')
  else
    p = io.popen('ls -1 "' .. dir:gsub('"', '\\"') .. '" 2>/dev/null')
  end
  if not p then return names end
  local listing = p:read("*a") or ""
  p:close()
  local seen = {}
  for name in listing:gmatch("[^\r\n]+") do
    name = name:match("([^/\\]+)$") or name
    if name ~= "" and name ~= "." and name ~= ".." and not seen[name] then
      -- On *nix, ls lists files too; keep only dirs that look like machine/cpu folders
      -- or always include and let callers filter by machine.lua.
      seen[name] = true
      names[#names + 1] = name
    end
  end
  table.sort(names)
  return names
end

--- Resolve project root: hint, package.path entries, or cwd.
function Discover.project_root(hint)
  hint = norm(hint)
  if hint and is_dir(hint .. "/machines") then
    return hint
  end
  for entry in string.gmatch(package.path, "[^;]+") do
    local base = entry:match("^(.*)[/\\]%?%.lua$")
    if base then
      base = norm(base)
      if is_dir(base .. "/machines") then
        return base
      end
    end
  end
  local cwd = norm((os.getenv("PWD") or os.getenv("CD") or "."))
  if is_dir(cwd .. "/machines") then
    return cwd
  end
  return hint or cwd or "."
end

-- Known machine ids when filesystem scan finds nothing (CC bundles / preload-only).
local FALLBACK_MACHINES = {
  "ti83plus", "ti84plus", "ti89", "ti92plus", "riscv64", "gameboy", "nes",
}

local function register_factory(Manager, mid)
  Manager.register(mid, function(opts)
    local mod = require("machines." .. mid .. ".machine")
    return mod.new(opts or {})
  end)
end

--- Register every `machines/<id>/machine.lua` as a lazy Manager factory.
function Discover.register_machines(Manager, root)
  root = Discover.project_root(root)
  local machines_dir = root .. "/machines"
  local ids = {}
  for _, id in ipairs(Discover.list_subdirs(machines_dir)) do
    local modpath = machines_dir .. "/" .. id .. "/machine.lua"
    if file_exists(modpath) then
      register_factory(Manager, id)
      ids[#ids + 1] = id
    end
  end
  if #ids == 0 then
    for _, mid in ipairs(FALLBACK_MACHINES) do
      register_factory(Manager, mid)
      ids[#ids + 1] = mid
    end
  end
  table.sort(ids)
  return ids, root
end

--- Catalog shared CPUs and per-machine hw/mem folders (inventory only).
function Discover.catalog_hardware(root)
  root = Discover.project_root(root)
  local catalog = {
    root = root,
    cpus = {},
    machine_hw = {},
    machine_mem = {},
  }
  for _, id in ipairs(Discover.list_subdirs(root .. "/cpus")) do
    catalog.cpus[#catalog.cpus + 1] = {
      id = id,
      path = "cpus/" .. id,
    }
  end
  for _, mid in ipairs(Discover.list_subdirs(root .. "/machines")) do
    local hw = root .. "/machines/" .. mid .. "/hw"
    local mem = root .. "/machines/" .. mid .. "/mem"
    if is_dir(hw) then
      local sep = package.config:sub(1, 1)
      local p
      if sep == "\\" then
        p = io.popen('dir /b "' .. hw:gsub("/", "\\") .. '\\*.lua" 2>nul')
      else
        p = io.popen('ls -1 "' .. hw:gsub('"', '\\"') .. '"/*.lua 2>/dev/null')
      end
      local files = {}
      if p then
        local listing = p:read("*a") or ""
        p:close()
        for name in listing:gmatch("[^\r\n]+") do
          name = name:match("([^/\\]+)$") or name
          local stem = name:match("^(.*)%.lua$")
          if stem then files[#files + 1] = stem end
        end
      end
      table.sort(files)
      catalog.machine_hw[mid] = files
    end
    if is_dir(mem) then
      local files = {}
      local sep = package.config:sub(1, 1)
      local p
      if sep == "\\" then
        p = io.popen('dir /b "' .. mem:gsub("/", "\\") .. '\\*.lua" 2>nul')
      else
        p = io.popen('ls -1 "' .. mem:gsub('"', '\\"') .. '"/*.lua 2>/dev/null')
      end
      if p then
        local listing = p:read("*a") or ""
        p:close()
        for name in listing:gmatch("[^\r\n]+") do
          name = name:match("([^/\\]+)$") or name
          local stem = name:match("^(.*)%.lua$")
          if stem then files[#files + 1] = stem end
        end
      end
      table.sort(files)
      catalog.machine_mem[mid] = files
    end
  end
  return catalog
end

return Discover
