-- Tom's Peripherals GPU helpers (bitmap monitors).
-- Wiki: https://github.com/tom5454/Toms-Peripherals/wiki/GPUImpl
-- Soft-fail: wrap/resolve return nil, err_string (no throws).

local M = {}

--- Pack Love-style 0..1 RGB(+A) into ARGB.
-- Returns a *signed* 32-bit value. Tom's drawText/drawChar parse colors via
-- MathHelper.floor (not longValue); unsigned 0xAARRGGBB (>= 2^31) clamps to
-- Integer.MAX_VALUE and every glyph becomes a white square. Signed packing
-- preserves bits for both drawText and filledRectangle (toColor/longValue).
-- Note: pure white 0xFFFFFFFF == -1, which drawText treats as "no bg".
function M.argb(r, g, b, a)
  a = a or 1
  local A = math.floor(a * 255 + 0.5)
  local R = math.floor(r * 255 + 0.5)
  local G = math.floor(g * 255 + 0.5)
  local B = math.floor(b * 255 + 0.5)
  if A < 0 then A = 0 elseif A > 255 then A = 255 end
  if R < 0 then R = 0 elseif R > 255 then R = 255 end
  if G < 0 then G = 0 elseif G > 255 then G = 255 end
  if B < 0 then B = 0 elseif B > 255 then B = 255 end
  local c = A * 0x1000000 + R * 0x10000 + G * 0x100 + B
  if c >= 0x80000000 then
    c = c - 0x100000000
  end
  return c
end

--- Transparent bg for drawText/drawChar (Tom's sentinel: bg > -1 draws bg).
M.TEXT_BG_NONE = -1

function M.rgb_table(t)
  return M.argb(t[1], t[2], t[3], t[4] or 1)
end

function M.is_gpu(name)
  if type(name) ~= "string" or not peripheral or not peripheral.isPresent then
    return false
  end
  if not peripheral.isPresent(name) then
    return false
  end
  local t = peripheral.getType(name)
  if t == "tm_gpu" or t == "gpu" then
    return true
  end
  -- Network names are often tm_gpu_0.
  return type(t) == "string" and t:find("gpu", 1, true) ~= nil
end

--- Find attached GPU peripherals. Returns list of { side=, gpu= }.
function M.find_gpus()
  local out = {}
  if not peripheral or not peripheral.getNames then
    return out
  end
  for _, name in ipairs(peripheral.getNames()) do
    if M.is_gpu(name) then
      local g = peripheral.wrap(name)
      if g and g.getSize and g.sync then
        out[#out + 1] = { side = name, gpu = g }
      end
    end
  end
  return out
end

--- Short inventory of attached peripherals (for error hints).
function M.peripheral_summary()
  if not peripheral or not peripheral.getNames then
    return "(no peripheral API)"
  end
  local names = peripheral.getNames()
  if not names or #names == 0 then
    return "(none attached)"
  end
  local parts = {}
  for _, name in ipairs(names) do
    parts[#parts + 1] = name .. "=" .. tostring(peripheral.getType(name))
  end
  return table.concat(parts, ", ")
end

--- Wrap by name, or accept an already-wrapped GPU.
-- Returns gpu, side  or  nil, err
function M.wrap(spec, label)
  label = label or "gpu"
  if type(spec) == "table" then
    if type(spec.getSize) ~= "function" or type(spec.sync) ~= "function" then
      return nil, label .. ": expected a Tom's Peripherals GPU (getSize/sync)"
    end
    local side = nil
    if peripheral and peripheral.getName then
      local ok, name = pcall(peripheral.getName, spec)
      if ok then side = name end
    end
    return spec, side
  end
  if type(spec) ~= "string" then
    return nil, label .. ": expected peripheral name or wrapped GPU (got "
      .. type(spec) .. ")"
  end
  if not peripheral or not peripheral.isPresent then
    return nil, label .. ": no peripheral API (not ComputerCraft?)"
  end
  if not peripheral.isPresent(spec) then
    return nil, label .. ": no peripheral on '" .. spec .. "'\n"
      .. "  Attached: " .. M.peripheral_summary()
  end
  if not M.is_gpu(spec) then
    return nil, label .. ": '" .. spec .. "' is "
      .. tostring(peripheral.getType(spec)) .. ", not a GPU\n"
      .. "  Attached: " .. M.peripheral_summary()
  end
  local g = peripheral.wrap(spec)
  if not g then
    return nil, label .. ": peripheral.wrap('" .. spec .. "') failed"
  end
  if type(g.getSize) ~= "function" or type(g.sync) ~= "function" then
    return nil, label .. ": '" .. spec .. "' wrapped but missing getSize/sync"
  end
  return g, spec
end

--- Resolve GPU from opts.gpu or first found.
-- Returns gpu, side  or  nil, err
function M.resolve(opts)
  opts = opts or {}
  if opts.gpu then
    return M.wrap(opts.gpu, "gpu")
  end
  local found = M.find_gpus()
  if #found == 0 then
    return nil,
      "no Tom's Peripherals GPU found\n"
        .. "  Attach a GPU next to bitmap monitors (needs Tom's Peripherals mod).\n"
        .. "  Or pass --gpu <name>.\n"
        .. "  Attached: " .. M.peripheral_summary()
  end
  return found[1].gpu, found[1].side
end

--- refreshSize + optional setSize, then return pixel w,h (+ block meta if any).
-- Returns w,h,...  or  nil, nil, err when getSize fails / zero size.
function M.setup(gpu, resolution)
  if not gpu then
    return nil, nil, "gpu: nil peripheral"
  end
  if gpu.refreshSize then
    pcall(gpu.refreshSize)
  end
  if resolution and gpu.setSize then
    pcall(gpu.setSize, resolution)
  end
  local ok, w, h, bw, bh, mult = pcall(function()
    return gpu.getSize()
  end)
  if not ok then
    return nil, nil, "gpu.getSize failed: " .. tostring(w)
  end
  w = tonumber(w) or 0
  h = tonumber(h) or 0
  return w, h, bw, bh, mult
end

--- Tom's GPU pixel coords are 1-based (createWindow(1,1,w,h)).
-- Clamp a rect into 1..max_w, 1..max_h and draw; never throws.
function M.rect(gpu, x, y, w, h, color, max_w, max_h)
  if not gpu or not gpu.filledRectangle then
    return
  end
  x = math.floor((tonumber(x) or 0) + 0.5)
  y = math.floor((tonumber(y) or 0) + 0.5)
  w = math.floor((tonumber(w) or 0) + 0.5)
  h = math.floor((tonumber(h) or 0) + 0.5)
  if w < 1 or h < 1 then
    return
  end
  max_w = tonumber(max_w)
  max_h = tonumber(max_h)
  if not max_w or not max_h or max_w < 1 or max_h < 1 then
    local ok, gw, gh = pcall(function() return gpu.getSize() end)
    if ok then
      max_w, max_h = tonumber(gw) or 0, tonumber(gh) or 0
    else
      return
    end
  end
  if max_w < 1 or max_h < 1 then
    return
  end
  local x2 = x + w - 1
  local y2 = y + h - 1
  if x < 1 then x = 1 end
  if y < 1 then y = 1 end
  if x2 > max_w then x2 = max_w end
  if y2 > max_h then y2 = max_h end
  if x2 < x or y2 < y then
    return
  end
  pcall(gpu.filledRectangle, x, y, x2 - x + 1, y2 - y + 1, color)
end

--- Outline rect, clamped (no throw).
function M.outline(gpu, x, y, w, h, color, max_w, max_h)
  if not gpu or not gpu.rectangle then
    return
  end
  x = math.floor((tonumber(x) or 0) + 0.5)
  y = math.floor((tonumber(y) or 0) + 0.5)
  w = math.floor((tonumber(w) or 0) + 0.5)
  h = math.floor((tonumber(h) or 0) + 0.5)
  if w < 1 or h < 1 then
    return
  end
  max_w = tonumber(max_w)
  max_h = tonumber(max_h)
  if not max_w or not max_h then
    local ok, gw, gh = pcall(function() return gpu.getSize() end)
    if ok then
      max_w, max_h = tonumber(gw) or 0, tonumber(gh) or 0
    else
      return
    end
  end
  local x2 = x + w - 1
  local y2 = y + h - 1
  if x < 1 then x = 1 end
  if y < 1 then y = 1 end
  if x2 > max_w then x2 = max_w end
  if y2 > max_h then y2 = max_h end
  if x2 < x or y2 < y then
    return
  end
  pcall(gpu.rectangle, x, y, x2 - x + 1, y2 - y + 1, color)
end

--- Filled circle (scanline). cx/cy may be fractional.
function M.circle(gpu, cx, cy, r, color, max_w, max_h)
  if not gpu then return end
  r = math.max(1, math.floor((tonumber(r) or 0) + 0.5))
  cx = math.floor((tonumber(cx) or 0) + 0.5)
  cy = math.floor((tonumber(cy) or 0) + 0.5)
  local r2 = r * r
  for dy = -r, r do
    local span = math.floor(math.sqrt(r2 - dy * dy) + 0.5)
    if span >= 0 then
      M.rect(gpu, cx - span, cy + dy, span * 2 + 1, 1, color, max_w, max_h)
    end
  end
end

--- Filled axis-aligned ellipse.
function M.ellipse(gpu, cx, cy, rx, ry, color, max_w, max_h)
  if not gpu then return end
  rx = math.max(1, math.floor((tonumber(rx) or 0) + 0.5))
  ry = math.max(1, math.floor((tonumber(ry) or 0) + 0.5))
  cx = math.floor((tonumber(cx) or 0) + 0.5)
  cy = math.floor((tonumber(cy) or 0) + 0.5)
  local rx2 = rx * rx
  local ry2 = ry * ry
  if rx2 < 1 or ry2 < 1 then return end
  for dy = -ry, ry do
    local t = 1 - (dy * dy) / ry2
    if t >= 0 then
      local span = math.floor(math.sqrt(t * rx2) + 0.5)
      M.rect(gpu, cx - span, cy + dy, span * 2 + 1, 1, color, max_w, max_h)
    end
  end
end

--- Axis-aligned rounded rectangle (scanline; radius clamped to half-min side).
function M.rounded_rect(gpu, x, y, w, h, radius, color, max_w, max_h)
  if not gpu then return end
  x = math.floor((tonumber(x) or 0) + 0.5)
  y = math.floor((tonumber(y) or 0) + 0.5)
  w = math.floor((tonumber(w) or 0) + 0.5)
  h = math.floor((tonumber(h) or 0) + 0.5)
  if w < 1 or h < 1 then return end
  local r = math.floor((tonumber(radius) or 0) + 0.5)
  if r < 1 then
    M.rect(gpu, x, y, w, h, color, max_w, max_h)
    return
  end
  local max_r = math.floor(math.min(w, h) * 0.5)
  if r > max_r then r = max_r end
  local r2 = r * r
  -- Middle band (full width)
  if h > r * 2 then
    M.rect(gpu, x, y + r, w, h - r * 2, color, max_w, max_h)
  end
  -- Top / bottom bands with rounded corners
  for dy = 0, r - 1 do
    local span = math.floor(math.sqrt(r2 - (r - 1 - dy) * (r - 1 - dy)) + 0.5)
    local inset = r - span
    local rw = w - inset * 2
    if rw > 0 then
      M.rect(gpu, x + inset, y + dy, rw, 1, color, max_w, max_h)
      M.rect(gpu, x + inset, y + h - 1 - dy, rw, 1, color, max_w, max_h)
    end
  end
end

--- Clear the full GPU buffer (prefers fill()).
function M.fill(gpu, color)
  if not gpu then
    return
  end
  if gpu.fill then
    local ok = pcall(gpu.fill, color)
    if ok then
      return
    end
  end
  local ok, w, h = pcall(function() return gpu.getSize() end)
  if ok then
    M.rect(gpu, 1, 1, w, h, color, w, h)
  end
end

function M.sync(gpu)
  if gpu and gpu.sync then
    pcall(gpu.sync)
  end
end

return M
