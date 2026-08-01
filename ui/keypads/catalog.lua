-- Available HW key IDs + style names per machine (palette for the panel editor).

local Catalog = {}

local STYLES_83 = {
  "graph", "apps", "arrow", "blue_op", "enter", "fn", "op", "on", "second", "alpha", "num",
}

local STYLES_89 = {
  "fkey", "arrow", "second", "diamond", "alpha", "shift", "fn", "num", "enter", "on",
}

local STYLES_92 = {
  "fkey", "letter", "num", "fn", "op", "second", "diamond", "shift", "arrow", "enter", "on",
}

-- Insertable legend / face tokens for the panel editor symbol palette.
Catalog.LEGEND_SYMBOLS = {
  { token = "", label = "(clear field)" },
  { token = "switch", label = "app-switch ▶|" },
  { token = "deg", label = "degree °" },
  { token = "angle", label = "angle ∠" },
  { token = "#", label = "hash #" },
  { token = "inf_i", label = "∞ i" },
  { token = "theta", label = "theta θ" },
  { token = "pi", label = "π (pi)" },
  { token = "sqrt", label = "√ (sqrt)" },
  { token = "e^x", label = "e^x" },
  { token = "SIN-1", label = "SIN⁻¹" },
  { token = "COS-1", label = "COS⁻¹" },
  { token = "TAN-1", label = "TAN⁻¹" },
  { token = "LN", label = "LN" },
  { token = "RCL", label = "RCL" },
  { token = "ANS", label = "ANS" },
  { token = "ENTRY", label = "ENTRY" },
  { token = "CUSTOM", label = "CUSTOM" },
  { token = "QUIT", label = "QUIT" },
  { token = "INS", label = "INS" },
  { token = "DEL", label = "DEL" },
  { token = "OFF", label = "OFF" },
  { token = "STATPLOT", label = "STATPLOT" },
  { token = "TBLSET", label = "TBLSET" },
  { token = "A-LOCK", label = "A-LOCK" },
}

Catalog.FACE_GLYPHS = {
  { id = "auto", label = "Auto (from style/key)" },
  { id = "text", label = "Text label" },
  { id = "arrow_up", label = "▲ Up" },
  { id = "arrow_down", label = "▼ Down" },
  { id = "arrow_left", label = "◀ Left" },
  { id = "arrow_right", label = "▶ Right" },
  { id = "diamond", label = "◆ Diamond" },
  { id = "sto", label = "STO ▶" },
  { id = "backspace", label = "◀ Backspace" },
}

Catalog.SHAPES = {
  { id = "auto", label = "Auto" },
  { id = "rect", label = "Rounded rect" },
  { id = "circle", label = "Circle" },
}

Catalog.OUTLINES = {
  { id = "auto", label = "Auto" },
  { id = "none", label = "None" },
  { id = "dark", label = "Dark" },
  { id = "light", label = "Light (shift)" },
  { id = "custom", label = "Custom" },
}

-- Default face labels when dragging a bare key from the palette.
local LABELS_83 = {
  yequ = "Y=", window = "WINDOW", zoom = "ZOOM", trace = "TRACE", graph = "GRAPH",
  ["2nd"] = "2nd", mode = "MODE", del = "DEL", up = "^", down = "v", left = "<", right = ">",
  alpha = "ALPHA", xt = "X,T,0,n", stat = "STAT", math = "MATH", apps = "APPS",
  prgm = "PRGM", vars = "VARS", clear = "CLEAR", recip = "x^-1", sin = "SIN", cos = "COS",
  tan = "TAN", power = "^", square = "x^2", comma = ",", lparen = "(", rparen = ")",
  div = "/", log = "LOG", ln = "LN", sto = "STO>", mul = "*", minus = "-", plus = "+",
  on = "ON", enter = "ENTER", neg = "(-)", dot = ".",
  ["0"] = "0", ["1"] = "1", ["2"] = "2", ["3"] = "3", ["4"] = "4",
  ["5"] = "5", ["6"] = "6", ["7"] = "7", ["8"] = "8", ["9"] = "9",
}

-- Extra palette IDs that share a matrix cell with another key (allowed duplicates).
local EXTRA_SAME_POS = {
  ["2nd2"] = true,
  enter3 = true,
}

local function key_name_score(name)
  -- Prefer canonical ids over UPPERCASE / punctuation aliases in KEY_MAP.
  if name == "2nd" or name == "2nd2" then return 0 end
  if name:match("^[a-z][a-z0-9_]*$") or name:match("^[0-9]$") then return 0 end
  if name:match("^[A-Z]$") then return 3 end
  return 2
end

local function keys_from_map(mod_path)
  local ok, mod = pcall(require, mod_path)
  if not ok or not mod or not mod.KEY_MAP then return {} end
  local names = {}
  for name in pairs(mod.KEY_MAP) do
    names[#names + 1] = name
  end
  table.sort(names, function(a, b)
    local sa, sb = key_name_score(a), key_name_score(b)
    if sa ~= sb then return sa < sb end
    return a < b
  end)
  local out, seen = {}, {}
  for _, name in ipairs(names) do
    local info = mod.KEY_MAP[name]
    local pos = info.on and "on" or (tostring(info.row) .. ":" .. tostring(info.col))
    if EXTRA_SAME_POS[name] then
      out[#out + 1] = name
    elseif not seen[pos] then
      seen[pos] = true
      out[#out + 1] = name
    end
  end
  return out
end

Catalog.MACHINES = {
  ti83plus = {
    title = "TI-83+",
    styles = STYLES_83,
    legend_fields = { "second", "alpha", "fkey" },
    default_label = LABELS_83,
    keys = function()
      return keys_from_map("machines.ti83plus.hw.keypad")
    end,
  },
  ti84plus = {
    title = "TI-84+",
    styles = STYLES_83,
    legend_fields = { "second", "alpha", "fkey" },
    default_label = LABELS_83,
    keys = function()
      -- Shares HW matrix with TI-83+ (wrapper module may not export KEY_MAP).
      local ids = keys_from_map("machines.ti84plus.hw.keypad")
      if #ids == 0 then
        ids = keys_from_map("machines.ti83plus.hw.keypad")
      end
      return ids
    end,
  },
  ti89 = {
    title = "TI-89 Ti",
    styles = STYLES_89,
    legend_fields = { "second", "shift", "alpha" }, -- shift = diamond ink
    default_label = {
      f1 = "F1", f2 = "F2", f3 = "F3", f4 = "F4", f5 = "F5",
      ["2nd"] = "2nd", diamond = "diamond", alpha = "ALPHA", shift = "shift",
      home = "HOME", mode = "MODE", catalog = "CATALOG", clear = "CLEAR",
      enter = "ENTER", on = "ON", esc = "ESC", apps = "APPS",
      up = "up", down = "down", left = "left", right = "right",
    },
    keys = function()
      return keys_from_map("machines.ti89.hw.keyboard")
    end,
  },
  ti92plus = {
    title = "TI-92+",
    styles = STYLES_92,
    legend_fields = { "second", "shift", "alpha" },
    default_label = {
      ["2nd"] = "2nd", ["2nd2"] = "2nd",
      diamond = "◆", shift = "⇧", hand = "HAND",
      up = "^", down = "v", left = "<", right = ">",
      enter = "ENTER", enter2 = "ENTER", enter3 = "ENTER", on = "ON",
      backspace = "←", sto = "STO", theta = "θ",
    },
    keys = function()
      return keys_from_map("machines.ti92plus.hw.keyboard")
    end,
  },
}

function Catalog.for_machine(id)
  return Catalog.MACHINES[id] or Catalog.MACHINES.ti83plus
end

function Catalog.styles(id)
  return Catalog.for_machine(id).styles
end

function Catalog.key_ids(id)
  return Catalog.for_machine(id).keys()
end

function Catalog.default_label(id, key)
  local cat = Catalog.for_machine(id)
  if cat.default_label and cat.default_label[key] then
    return cat.default_label[key]
  end
  return key
end

return Catalog
