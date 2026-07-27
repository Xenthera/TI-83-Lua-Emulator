-- LCD glass themes for the ComputerCraft monitor painter.
-- "on" = lit TI pixel (bit set), "off" = unlit glass, "frame" = letterbox.

local CC = require("frontend.computercraft.cc")

local M = {}

--- Ordered for status-bar cycling.
M.ORDER = {
  "classic",
  "original",
  "contrast",
  "paper",
  "phosphor",
  "amber",
  "ocean",
  "candy",
}

local function C()
  return CC.colors()
end

--- Resolve theme id -> { id, label, on, off, frame }.
function M.get(id)
  local colors = C()
  local defs = {
    -- Closest CC match to a real TI-83+ LCD: dark gray ink on light gray glass.
    classic = {
      id = "classic",
      label = "gray",
      on = colors.gray,
      off = colors.lightGray,
      frame = colors.gray,
    },
    -- Bright green pixels on lime glass.
    original = {
      id = "original",
      label = "orig",
      on = colors.green,
      off = colors.lime,
      frame = colors.black,
    },
    -- High contrast: dark ink on lime glass.
    contrast = {
      id = "contrast",
      label = "hi",
      on = colors.black,
      off = colors.lime,
      frame = colors.black,
    },
    -- Black on white.
    paper = {
      id = "paper",
      label = "b/w",
      on = colors.black,
      off = colors.white,
      frame = colors.lightGray,
    },
    -- White on black.
    phosphor = {
      id = "phosphor",
      label = "w/b",
      on = colors.white,
      off = colors.black,
      frame = colors.black,
    },
    amber = {
      id = "amber",
      label = "ambr",
      on = colors.orange,
      off = colors.brown,
      frame = colors.black,
    },
    ocean = {
      id = "ocean",
      label = "ocean",
      on = colors.cyan,
      off = colors.blue,
      frame = colors.black,
    },
    candy = {
      id = "candy",
      label = "candy",
      on = colors.pink,
      off = colors.purple,
      frame = colors.black,
    },
  }
  return defs[id] or defs.classic
end

function M.is_valid(id)
  if type(id) ~= "string" then
    return false
  end
  for _, name in ipairs(M.ORDER) do
    if name == id then
      return true
    end
  end
  return false
end

function M.next(id)
  local idx = 1
  for i, name in ipairs(M.ORDER) do
    if name == id then
      idx = i
      break
    end
  end
  return M.ORDER[(idx % #M.ORDER) + 1]
end

--- Painter opts fragment: { on=, off=, frame= }.
function M.painter_opts(id)
  local t = M.get(id)
  return { on = t.on, off = t.off, frame = t.frame }
end

return M
