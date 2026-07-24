-- ComputerCraft environment helpers (peripheral / fs / os / colors).
-- Expects a real CC:Tweaked (or CC) computer when used in-game.

local M = {}

function M.is_cc()
  return type(peripheral) == "table"
    and type(peripheral.wrap) == "function"
    and type(os) == "table"
    and type(os.pullEventRaw) == "function"
end

--- Return true if `side` is a present monitor peripheral.
function M.is_monitor(side)
  return peripheral.isPresent(side) and peripheral.getType(side) == "monitor"
end

--- Wrap a monitor by side/network name, or accept an already-wrapped monitor.
-- Returns wrapped, side_name.
function M.wrap_monitor(spec, label)
  label = label or "monitor"
  if type(spec) == "table" then
    if type(spec.getSize) ~= "function" or type(spec.blit) ~= "function" then
      error(label .. ": expected a wrapped monitor (getSize/blit)")
    end
    local side = nil
    if peripheral.getName then
      local ok, name = pcall(peripheral.getName, spec)
      if ok then
        side = name
      end
    end
    return spec, side
  end

  if type(spec) ~= "string" then
    error(label .. ": expected peripheral side string or wrapped monitor")
  end
  if not peripheral.isPresent(spec) then
    error(label .. ": no peripheral on '" .. spec .. "'")
  end
  if peripheral.getType(spec) ~= "monitor" then
    error(label .. ": '" .. spec .. "' is " .. tostring(peripheral.getType(spec))
      .. ", not monitor")
  end
  local mon = peripheral.wrap(spec)
  if not mon then
    error(label .. ": peripheral.wrap('" .. spec .. "') failed")
  end
  return mon, spec
end

--- Find attached monitors. Returns list of { side=, mon= }.
function M.find_monitors()
  local out = {}
  for _, side in ipairs(peripheral.getNames()) do
    if peripheral.getType(side) == "monitor" then
      out[#out + 1] = { side = side, mon = peripheral.wrap(side) }
    end
  end
  return out
end

--- Pick LCD + keypad monitors from opts or by discovery.
-- opts.lcd / opts.pad: side string or wrapped monitor.
-- If omitted, first two monitors from peripheral.getNames() are used.
function M.resolve_monitors(opts)
  opts = opts or {}
  local lcd, lcd_side, pad, pad_side

  if opts.lcd then
    lcd, lcd_side = M.wrap_monitor(opts.lcd, "lcd")
  end
  if opts.pad then
    pad, pad_side = M.wrap_monitor(opts.pad, "pad")
  end

  if not lcd or not pad then
    local found = M.find_monitors()
    if not lcd then
      if #found < 1 then
        error("lcd: no monitor found (attach one or pass lcd = \"left\")")
      end
      lcd, lcd_side = found[1].mon, found[1].side
    end
    if not pad then
      local pick = nil
      for i = 1, #found do
        if found[i].side ~= lcd_side then
          pick = found[i]
          break
        end
      end
      if not pick then
        error("pad: need a second monitor (or pass pad = \"right\")")
      end
      pad, pad_side = pick.mon, pick.side
    end
  end

  if lcd_side and pad_side and lcd_side == pad_side then
    error("lcd and pad resolve to the same monitor '" .. lcd_side .. "'")
  end

  return {
    lcd = lcd,
    lcd_side = lcd_side,
    pad = pad,
    pad_side = pad_side,
  }
end

--- Read a whole file (ROM). Uses CC fs when available.
-- Returns data, err. err is a human-readable string.
function M.read_file(path)
  path = tostring(path or "")
  if path == "" then
    return nil, "empty file path"
  end

  if type(fs) == "table" and fs.open then
    if fs.exists and not fs.exists(path) then
      return nil, "file not found: " .. path
    end
    local h = fs.open(path, "rb")
    if not h then
      h = fs.open(path, "r")
    end
    if not h then
      return nil, "cannot open " .. path
    end
    local data = h.readAll()
    h.close()
    if data == nil then
      return nil, "failed to read " .. path
    end
    return data
  end

  local f, err = io.open(path, "rb")
  if not f then
    return nil, "cannot open " .. path .. (err and (": " .. tostring(err)) or "")
  end
  local data = f:read("*a")
  f:close()
  if not data then
    return nil, "failed to read " .. path
  end
  return data
end

--- Short directory listing for error hints (CC only).
function M.list_dir(path)
  path = path or ""
  if type(fs) ~= "table" or not fs.list then
    return nil
  end
  local ok, names = pcall(fs.list, path)
  if not ok or type(names) ~= "table" then
    return nil
  end
  table.sort(names)
  return names
end

--- CC colors table (or a desktop stand-in for tests).
function M.colors()
  if type(colors) == "table" then
    return colors
  end
  return {
    white = 1, orange = 2, magenta = 4, lightBlue = 8,
    yellow = 16, lime = 32, pink = 64, gray = 128,
    lightGray = 256, cyan = 512, purple = 1024, blue = 2048,
    brown = 4096, green = 8192, red = 16384, black = 32768,
    toBlit = function(c)
      local hex = "0123456789abcdef"
      local n = 0
      local v = c
      while v > 1 do
        v = math.floor(v / 2)
        n = n + 1
      end
      return hex:sub(n + 1, n + 1)
    end,
  }
end

function M.to_blit(color)
  local C = M.colors()
  if C.toBlit then
    return C.toBlit(color)
  end
  return "0"
end

return M
