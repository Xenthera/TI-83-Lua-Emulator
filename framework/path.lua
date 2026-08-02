-- Ensure project-root-relative requires work from any cwd / Love2D source dir.
local function setup(root)
  if not root or root == "" then
    return
  end
  if root:sub(-1) == "/" or root:sub(-1) == "\\" then
    root = root:sub(1, -2)
  end
  local tmpl = root .. "/?.lua;" .. root .. "/?/init.lua;"
  if not package.path:find(root, 1, true) then
    package.path = tmpl .. package.path
  end
end

local function is_windows()
  return (package.config:sub(1, 1) == "\\")
    or (type(jit) == "table" and tostring(jit.os or ""):lower() == "windows")
end

--- Create a directory (and parents). Uses ComputerCraft fs when present.
local function ensure_dir(path)
  if not path or path == "" then
    return
  end
  -- CraftOS / CC:Tweaked: os.execute is not a shell mkdir.
  if type(fs) == "table" and fs.makeDir then
    local p = tostring(path):gsub("\\", "/")
    if fs.exists and fs.exists(p) then
      return
    end
    fs.makeDir(p)
    return
  end
  if is_windows() then
    local win = path:gsub("/", "\\")
    os.execute('mkdir "' .. win:gsub('"', '') .. '" 2>nul')
  else
    os.execute('mkdir - p "' .. path:gsub('"', '\\"') .. '"')
  end
end

return { setup = setup, ensure_dir = ensure_dir, is_windows = is_windows }
