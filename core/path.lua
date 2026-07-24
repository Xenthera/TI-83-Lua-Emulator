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

return { setup = setup }
