-- LCD glass themes for the ComputerCraft monitor painter.
-- "on" = lit TI pixel (bit set), "off" = unlit glass, "frame" = letterbox.

local CC = require("frontends.computercraft.cc")

local M = {}

--- Ordered for status-bar cycling.
M.ORDER = {
  "classic",
  "titanium",
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
    -- TI-89 Titanium glass (Love render_ti89): dark ink on sage-ish glass.
    titanium = {
      id = "titanium",
      label = "ti89",
      on = colors.black,
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

--- Game Boy GPU: true RGB 4-shade ramp for Tom's bitmap monitors.
-- Shade 0 = lightest, 3 = darkest (DMG convention). Also returns bezel/off.
function M.gb_gpu_palette(id)
  local Gpu = require("frontends.computercraft.gpu")
  local function rgba(r, g, b)
    return Gpu.argb(r, g, b)
  end
  local function ramp(r0, g0, b0, r3, g3, b3)
    local function mix(t)
      return rgba(
        r0 + (r3 - r0) * t,
        g0 + (g3 - g0) * t,
        b0 + (b3 - b0) * t)
    end
    return {
      [0] = mix(0),
      [1] = mix(1 / 3),
      [2] = mix(2 / 3),
      [3] = mix(1),
      bezel = rgba(r3 * 0.55 + 0.05, g3 * 0.55 + 0.05, b3 * 0.55 + 0.05),
      off = rgba(r0 * 0.45, g0 * 0.45, b0 * 0.45),
    }
  end

  -- Hand-tuned ramps (not pure lerps) where a theme has a signature look.
  local pals = {
    -- Classic DMG greens (Love2D / historical default).
    original = {
      [0] = rgba(0.61, 0.73, 0.06),
      [1] = rgba(0.42, 0.55, 0.05),
      [2] = rgba(0.22, 0.35, 0.04),
      [3] = rgba(0.06, 0.14, 0.02),
      bezel = rgba(0.12, 0.16, 0.04),
      off = rgba(0.08, 0.12, 0.04),
    },
    -- Soft gray glass (TI-83-ish).
    classic = ramp(0.78, 0.80, 0.82, 0.14, 0.15, 0.18),
    -- Sage / titanium glass.
    titanium = ramp(0.72, 0.78, 0.70, 0.10, 0.16, 0.14),
    -- High-contrast lime paper.
    contrast = {
      [0] = rgba(0.70, 0.95, 0.35),
      [1] = rgba(0.40, 0.70, 0.18),
      [2] = rgba(0.12, 0.28, 0.08),
      [3] = rgba(0.02, 0.06, 0.02),
      bezel = rgba(0.05, 0.08, 0.04),
      off = rgba(0.08, 0.14, 0.05),
    },
    -- Black ink on white.
    paper = ramp(0.96, 0.96, 0.94, 0.08, 0.08, 0.10),
    -- Bright phosphor on black (inverted CRT).
    phosphor = ramp(0.04, 0.06, 0.05, 0.75, 0.95, 0.70),
    amber = ramp(0.55, 0.38, 0.08, 0.12, 0.05, 0.02),
    ocean = ramp(0.55, 0.85, 0.90, 0.04, 0.10, 0.28),
    candy = ramp(0.98, 0.75, 0.90, 0.35, 0.05, 0.40),
  }
  if type(id) == "string" and pals[id] then
    return pals[id]
  end
  return pals.original
end

return M
