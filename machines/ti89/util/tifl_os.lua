-- Extract a bootable AMS flash image from a TI-89/Titanium TIFL (.89u) file,
-- or pass through a raw ROM dump.

local M = {}

local function u32le(s, off)
  local a, b, c, d = s:byte(off, off + 3)
  return a + b * 256 + c * 65536 + d * 16777216
end

local function be32(s, off)
  local a, b, c, d = s:byte(off, off + 3)
  return ((a * 256 + b) * 256 + c) * 256 + d
end

local function is_vector_table(s, off)
  if off + 8 > #s then return false end
  local ssp = be32(s, off)
  local pc = be32(s, off + 4)
  -- Classic / Titanium stacks sit in low RAM; PC lands in flash.
  if ssp < 0x100 or ssp >= 0x200000 then return false end
  if pc % 2 ~= 0 then return false end
  -- Titanium (24-bit): flash @ $800000 -> PC often 0x008xxxxx
  -- Classic: flash @ $200000 -> PC often 0x002xxxxx
  if pc >= 0x800000 and pc < 0xC00000 then return true, ssp, pc end
  if pc >= 0x200000 and pc < 0x600000 then return true, ssp, pc end
  if pc >= 0x80000 and pc < 0xC00000 then return true, ssp, pc end -- 0x08xxxx Titanium trunc
  -- Synthetic / test images may reset into low RAM.
  if pc >= 0x100 and pc < 0x200000 then return true, ssp, pc end
  return false
end

--- Find AMS vector table inside TIFL payload (after license / product banner).
local function find_ams_offset(payload)
  -- Ti / GraphLink OS upgrades: license... then CCCCCCCC then SSP/PC.
  for i = 1, #payload - 15 do
    if payload:byte(i) == 0xCC and payload:byte(i + 1) == 0xCC
        and payload:byte(i + 2) == 0xCC and payload:byte(i + 3) == 0xCC then
      local ok = is_vector_table(payload, i + 4)
      if ok then return i + 4 end
    end
  end
  -- Fallback: scan for a plausible vector table.
  for i = 1, math.min(#payload - 8, 0x4000) do
    local ok = is_vector_table(payload, i)
    if ok then return i end
  end
  return nil
end

--- Returns raw_flash_bytes, meta
function M.extract_rom(file_bytes)
  if type(file_bytes) ~= "string" or #file_bytes < 16 then
    return nil, "empty rom"
  end

  -- Raw dump: already starts with a 68k vector table.
  local ok, ssp, pc = is_vector_table(file_bytes, 1)
  if ok then
    return file_bytes, {
      format = "raw",
      ssp = ssp,
      pc = pc,
      size = #file_bytes,
    }
  end

  if file_bytes:sub(1, 8) ~= "**TIFL**" then
    return nil, "not a raw TI-89 ROM dump or TIFL (.89u) OS upgrade"
  end

  local name_len = file_bytes:byte(17)
  if not name_len or name_len > 8 then name_len = 8 end
  local name = file_bytes:sub(18, 17 + name_len):gsub("%z", ""):gsub("%s+$", "")
  local device = file_bytes:byte(49)
  local dtype = file_bytes:byte(50)
  local data_len = u32le(file_bytes, 75)
  local data_start = 79 -- 1-based
  local avail = #file_bytes - data_start + 1
  if avail <= 0 then
    return nil, "TIFL header has no data"
  end
  if data_len <= 0 or data_len > avail then
    data_len = avail
  end
  -- Drop trailing 2-byte checksum when the claimed size leaves it hanging.
  if data_len + 2 <= avail and data_len == avail - 2 then
    -- checksum not included in size
  elseif data_len == avail and avail >= 2 then
    -- size includes everything; keep as-is
  end
  local payload = file_bytes:sub(data_start, data_start + data_len - 1)

  if dtype ~= 0x23 and dtype ~= 0x3E then
    -- Still try: some files mis-tag; only reject clear app packages.
    if dtype == 0x24 then
      return nil, string.format("TIFL is a Flash App (type 0x%02X), not an OS upgrade", dtype)
    end
  end

  local ams_at = find_ams_offset(payload)
  if not ams_at then
    return nil, "TIFL OS payload has no 68k vector table (need a ROM dump or .89u AMS)"
  end
  local image = payload:sub(ams_at)
  ok, ssp, pc = is_vector_table(image, 1)
  if not ok then
    return nil, "internal: AMS image vectors invalid"
  end
  return image, {
    format = "tifl_os",
    name = name,
    device = device,
    data_type = dtype,
    ssp = ssp,
    pc = pc,
    size = #image,
    ams_offset = ams_at - 1 + (data_start - 1),
  }
end

return M
