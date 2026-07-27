-- TI-83+ Flash App (.8xk) -> ROM archive injector.
--
-- Mimics "TI-Link install" offline: parse GraphLink TIFL + Intel HEX, then
-- place app pages into the user archive (pages 0x08..0x15) growing downward,
-- the same way the OS stores Flash Apps. No link protocol / flash program.

local PAGE = 0x4000
local FLASH_SIZE = 512 * 1024
local ARCHIVE_LO = 0x08
local ARCHIVE_HI = 0x15 -- TI-83+ last archive page

local Eightxk = {
  PAGE = PAGE,
  FLASH_SIZE = FLASH_SIZE,
  ARCHIVE_LO = ARCHIVE_LO,
  ARCHIVE_HI = ARCHIVE_HI,
}

local function u32le(s, off)
  local a, b, c, d = s:byte(off, off + 3)
  return a + b * 256 + c * 65536 + d * 16777216
end

local function page_offset(page)
  return page * PAGE
end

local function is_blank_page(rom, page)
  local off = page_offset(page)
  if off + PAGE > #rom then return false end
  for i = off + 1, off + PAGE do
    if rom:byte(i) ~= 0xFF then return false end
  end
  return true
end

local function write_page(rom, page, data)
  if #data ~= PAGE then
    return nil, string.format("page image must be %d bytes, got %d", PAGE, #data)
  end
  local off = page_offset(page)
  if off + PAGE > #rom then
    return nil, "page out of range"
  end
  return rom:sub(1, off) .. data .. rom:sub(off + PAGE + 1)
end

local function new_page_buf()
  return string.rep("\255", PAGE)
end

local function poke_page(buf, offset, bytes)
  if offset < 0 or offset >= PAGE then return buf end
  local n = #bytes
  if offset + n > PAGE then n = PAGE - offset end
  if n <= 0 then return buf end
  return buf:sub(1, offset) .. bytes:sub(1, n) .. buf:sub(offset + n + 1)
end

local function hex_nibble(c)
  if c >= 48 and c <= 57 then return c - 48 end -- 0-9
  if c >= 65 and c <= 70 then return c - 55 end -- A-F
  if c >= 97 and c <= 102 then return c - 87 end -- a-f
  return nil
end

local function parse_hex_byte(s, i)
  local hi = hex_nibble(s:byte(i))
  local lo = hex_nibble(s:byte(i + 1))
  if not hi or not lo then return nil end
  return hi * 16 + lo
end

--- Decode Intel HEX (ASCII) into map: flash_page -> 16KB image (0xFF-filled).
function Eightxk.parse_intel_hex(hex, opts)
  opts = opts or {}
  local yield_fn = opts.yield
  if type(hex) ~= "string" or #hex == 0 then
    return nil, "empty intel hex"
  end
  local pages = {} -- page -> buf
  local cur_page = nil
  local line_no = 0

  for line in hex:gmatch("[^\r\n]+") do
    line_no = line_no + 1
    if yield_fn and line_no % 32 == 0 then
      yield_fn()
    end
    line = line:match("^%s*(.-)%s*$") or line
    if line ~= "" then
      if line:sub(1, 1) ~= ":" then
        return nil, string.format("intel hex line %d: missing ':'", line_no)
      end
      -- : NN AAAA TT DD... CC  (byte pairs start at index 2)
      local count = parse_hex_byte(line, 2)
      local addr_hi = parse_hex_byte(line, 4)
      local addr_lo = parse_hex_byte(line, 6)
      local typ = parse_hex_byte(line, 8)
      if not count or not addr_hi or not addr_lo or not typ then
        return nil, string.format("intel hex line %d: bad header", line_no)
      end
      local addr = addr_hi * 256 + addr_lo
      local data_at = 10 -- first data nibble pair
      local need = data_at + count * 2 + 1 -- last checksum nibble index
      if #line < need then
        return nil, string.format("intel hex line %d: truncated", line_no)
      end
      local data = {}
      local sum = count + addr_hi + addr_lo + typ
      for i = 1, count do
        local b = parse_hex_byte(line, data_at + (i - 1) * 2)
        if not b then
          return nil, string.format("intel hex line %d: bad data", line_no)
        end
        data[i] = b
        sum = sum + b
      end
      local csum = parse_hex_byte(line, data_at + count * 2)
      if not csum then
        return nil, string.format("intel hex line %d: bad checksum", line_no)
      end
      if ((sum + csum) % 256) ~= 0 then
        return nil, string.format("intel hex line %d: checksum mismatch", line_no)
      end

      if typ == 0x00 then
        if cur_page == nil then
          return nil, string.format("intel hex line %d: data before page record", line_no)
        end
        local off = addr
        if addr >= 0x4000 and addr < 0x8000 then
          off = addr - 0x4000
        elseif addr >= PAGE then
          off = addr % PAGE
        end
        local parts = {}
        for i = 1, #data do parts[i] = string.char(data[i]) end
        pages[cur_page] = poke_page(pages[cur_page] or new_page_buf(), off, table.concat(parts))
      elseif typ == 0x01 then
        break
      elseif typ == 0x02 then
        -- TI flash page number (2 bytes). Example: :02 0000 02 001D xx
        if count < 2 then
          return nil, string.format("intel hex line %d: short page record", line_no)
        end
        cur_page = data[1] * 256 + data[2]
        if not pages[cur_page] then
          pages[cur_page] = new_page_buf()
        end
      else
        -- ignore other record types
      end
    end
  end

  local n = 0
  for _ in pairs(pages) do n = n + 1 end
  if n == 0 then
    return nil, "intel hex contained no flash pages"
  end
  return pages
end

--- Extract application Intel-HEX payload from a .8xk (TIFL) or raw HEX string.
-- Returns hex_ascii, meta
function Eightxk.extract_hex(file_bytes)
  if type(file_bytes) ~= "string" or #file_bytes < 4 then
    return nil, "empty .8xk"
  end

  -- Already Intel HEX?
  local trimmed = file_bytes:match("^%s*(.-)%s*$") or file_bytes
  if trimmed:sub(1, 1) == ":" then
    return trimmed, { format = "hex", name = nil }
  end

  -- Multi-part TIFL: walk concatenated headers, prefer data type 0x24 (application).
  -- Note: many older .8xk files have a bogus/wrong 32-bit size field; fall back to EOF.
  local pos = 1
  local best_hex, best_meta
  while pos + 77 <= #file_bytes do
    local sig = file_bytes:sub(pos, pos + 7)
    if sig ~= "**TIFL**" then
      if pos == 1 then
        return nil, "not a TIFL (.8xk) or Intel HEX file"
      end
      break
    end
    local name_len = file_bytes:byte(pos + 16)
    if name_len > 8 then name_len = 8 end
    local name = file_bytes:sub(pos + 17, pos + 16 + name_len):gsub("%z", "")
    -- Trim trailing spaces from 8-char name fields ("Bubble  " -> "Bubble")
    name = name:gsub("%s+$", "")
    local device = file_bytes:byte(pos + 48)
    local dtype = file_bytes:byte(pos + 49)
    local data_len = u32le(file_bytes, pos + 74)
    local data_start = pos + 78
    local avail = #file_bytes - data_start + 1
    if avail <= 0 then
      return nil, "TIFL header has no data"
    end
    -- Claimed length may be wrong (e.g. bubapp.8xk reports ~16M). Clamp to file.
    if data_len <= 0 or data_len > avail then
      data_len = avail
    end
    local payload = file_bytes:sub(data_start, data_start + data_len - 1)
    -- Drop trailing 2-byte binary checksum when present after ASCII Intel HEX.
    if #payload >= 2 and payload:sub(1, 1) == ":" then
      local last = payload:byte(#payload)
      local prev = payload:byte(#payload - 1)
      -- HEX lines end with 0-9A-F / CR / LF; binary csum bytes often aren't.
      local function is_hex_text_byte(b)
        return (b >= 48 and b <= 57) or (b >= 65 and b <= 70) or (b >= 97 and b <= 102)
          or b == 58 or b == 13 or b == 10 or b == 32
      end
      if not is_hex_text_byte(last) or not is_hex_text_byte(prev) then
        payload = payload:sub(1, #payload - 2)
      end
    end
    if payload:sub(1, 1) ~= ":" then
      return nil, "TIFL payload is not Intel HEX"
    end
    local meta = {
      format = "tifl",
      name = name,
      device = device,
      data_type = dtype,
    }
    if dtype == 0x24 or (not best_hex and dtype ~= 0x3E and dtype ~= 0x25) then
      best_hex, best_meta = payload, meta
      if dtype == 0x24 then
        break
      end
    end
    -- Advance past this part (payload + optional checksum).
    pos = data_start + data_len
    if pos <= #file_bytes and pos + 1 <= #file_bytes then
      -- skip binary checksum if we consumed exact claimed length with room
      local b1, b2 = file_bytes:byte(pos), file_bytes:byte(pos + 1)
      if b1 and b2 and not ((b1 == 42 and b2 == 42) -- next **TIFL**
        or b1 == 58) then -- next ':'
        pos = pos + 2
      end
    end
  end

  if not best_hex then
    return nil, "TIFL file has no application payload"
  end
  return best_hex, best_meta
end

--- Order page images for archive placement: [base, page1, ...] (base has 0x80 header).
function Eightxk.order_pages(page_map)
  local ids = {}
  for p in pairs(page_map) do
    ids[#ids + 1] = p
  end
  table.sort(ids)
  local lo, hi = ids[1], ids[#ids]
  for p = lo, hi do
    if not page_map[p] then
      return nil, string.format("app pages not contiguous (%02X..%02X missing %02X)", lo, hi, p)
    end
  end
  local ordered = {}
  local base = page_map[hi]
  if base and base:byte(1) == 0x80 then
    for p = hi, lo, -1 do
      ordered[#ordered + 1] = { logical = p, data = page_map[p] }
    end
  else
    for p = lo, hi do
      ordered[#ordered + 1] = { logical = p, data = page_map[p] }
    end
  end
  if ordered[1].data:byte(1) ~= 0x80 then
    return nil, "app base page does not start with 0x80 (invalid Flash App header)"
  end
  return ordered
end

local function find_slot(rom, n_pages)
  for top = ARCHIVE_HI, ARCHIVE_LO + n_pages - 1, -1 do
    local ok = true
    for p = top - n_pages + 1, top do
      if not is_blank_page(rom, p) then
        ok = false
        break
      end
    end
    if ok then return top end
  end
  return nil
end

--- Inject one .8xk (or Intel HEX) into a 512KB ROM image.
-- opts.force: overwrite non-blank archive pages (still stays in 8..15)
-- Returns new_rom, meta
function Eightxk.inject(rom, app_bytes, opts)
  opts = opts or {}
  if type(rom) ~= "string" or #rom ~= FLASH_SIZE then
    return nil, string.format("ROM must be %d bytes", FLASH_SIZE)
  end
  local hex, emeta = Eightxk.extract_hex(app_bytes)
  if not hex then return nil, emeta end
  local page_map, err = Eightxk.parse_intel_hex(hex, { yield = opts.yield })
  if not page_map then return nil, err end
  local ordered, oerr = Eightxk.order_pages(page_map)
  if not ordered then return nil, oerr end

  local n = #ordered
  local top = find_slot(rom, n)
  if not top then
    if opts.force then
      top = ARCHIVE_HI
      for p = ARCHIVE_HI - n + 1, ARCHIVE_HI do
        rom = select(1, write_page(rom, p, new_page_buf()))
      end
    else
      return nil, string.format(
        "archive full: need %d free page(s) in %02X..%02X",
        n, ARCHIVE_LO, ARCHIVE_HI
      )
    end
  end

  local placed = {}
  local out = rom
  for i, ent in ipairs(ordered) do
    local phys = top - i + 1
    local w, werr = write_page(out, phys, ent.data)
    if not w then return nil, werr end
    out = w
    placed[#placed + 1] = { logical = ent.logical, physical = phys }
  end

  return out, {
    name = emeta and emeta.name,
    pages = n,
    placed = placed,
    top = top,
  }
end

--- Inject many apps in order (each grows downward into free archive).
function Eightxk.inject_many(rom, app_list, opts)
  local out = rom
  local metas = {}
  for i, app in ipairs(app_list or {}) do
    local next_rom, meta = Eightxk.inject(out, app, opts)
    if not next_rom then
      return nil, string.format("app #%d: %s", i, tostring(meta))
    end
    out = next_rom
    metas[#metas + 1] = meta
  end
  return out, metas
end

local function is_blank_page_bytes(bytes, page)
  local off = page_offset(page)
  for i = 0, PAGE - 1 do
    if (bytes[off + i] or 0) ~= 0xFF then
      return false
    end
  end
  return true
end

local function write_page_bytes(bytes, page, data)
  if #data ~= PAGE then
    return nil, string.format("page image must be %d bytes, got %d", PAGE, #data)
  end
  local off = page_offset(page)
  for i = 1, PAGE do
    bytes[off + i - 1] = data:byte(i)
  end
  return true
end

local function find_slot_bytes(bytes, n_pages)
  for top = ARCHIVE_HI, ARCHIVE_LO + n_pages - 1, -1 do
    local ok = true
    for p = top - n_pages + 1, top do
      if not is_blank_page_bytes(bytes, p) then
        ok = false
        break
      end
    end
    if ok then return top end
  end
  return nil
end

--- Inject a Flash App into a live 0-based flash byte array (e.g. mmu.flash.bytes).
function Eightxk.inject_flash(flash_bytes, app_bytes, opts)
  opts = opts or {}
  if type(flash_bytes) ~= "table" then
    return nil, "flash_bytes must be a byte table"
  end
  local hex, emeta = Eightxk.extract_hex(app_bytes)
  if not hex then return nil, emeta end
  local page_map, err = Eightxk.parse_intel_hex(hex, { yield = opts.yield })
  if not page_map then return nil, err end
  local ordered, oerr = Eightxk.order_pages(page_map)
  if not ordered then return nil, oerr end

  local n = #ordered
  local top = find_slot_bytes(flash_bytes, n)
  if not top then
    return nil, string.format(
      "archive full: need %d free page(s) in %02X..%02X",
      n, ARCHIVE_LO, ARCHIVE_HI
    )
  end

  local placed = {}
  local yield_fn = opts.yield
  for i, ent in ipairs(ordered) do
    local phys = top - i + 1
    local okw, werr = write_page_bytes(flash_bytes, phys, ent.data)
    if not okw then return nil, werr end
    placed[#placed + 1] = { logical = ent.logical, physical = phys }
    if yield_fn then
      yield_fn()
    end
  end

  return {
    name = emeta and emeta.name,
    pages = n,
    placed = placed,
    top = top,
  }
end

local function hex_byte(b)
  return string.format("%02X", b % 256)
end

local function hex_record(addr, typ, data)
  local n = #data
  local sum = n + math.floor(addr / 256) + (addr % 256) + typ
  local body = ""
  for i = 1, n do
    local b = data:byte(i)
    sum = sum + b
    body = body .. hex_byte(b)
  end
  local csum = (-sum) % 256
  return string.format(":%02X%04X%02X%s%s\r\n", n, addr, typ, body, hex_byte(csum))
end

local function normalize_app_name(name)
  name = tostring(name or "TESTAPP"):upper():gsub("[^A-Z0-9]", "")
  if name == "" then
    name = "TESTAPP"
  end
  if #name > 8 then
    name = name:sub(1, 8)
  end
  return name
end

--- Minimal valid Flash App TLV header (WikiTI / z80 Heaven).
-- Execution begins immediately after the final field.
-- n_pages: archive page count (1..14 on TI-83+).
function Eightxk.build_app_header(name, n_pages)
  name = normalize_app_name(name)
  n_pages = tonumber(n_pages) or 1
  if n_pages < 1 then n_pages = 1 end
  if n_pages > 14 then n_pages = 14 end
  return string.char(0x80, 0x0F, 0x00, 0x00, 0x00, 0x00)
    .. string.char(0x80, 0x40 + #name)
    .. name
    .. string.char(0x80, 0x90) -- disable splash
    .. string.char(0x80, 0x81, n_pages % 256)
    .. string.char(0x80, 0x12, 0x01, 0x04) -- key ID
    .. string.char(0x03, 0x22, 0x09, 0x00) -- date stamp
    .. string.char(0x02, 0x00) -- date stamp signature
    .. string.char(0x80, 0x70) -- final field
end

local function bytes_table_to_string(page_bytes, opts)
  opts = opts or {}
  local t = {}
  local n = opts.size
  if not n then
    n = 0
    for i = 0, PAGE - 1 do
      if page_bytes[i] ~= nil then
        n = i + 1
      end
    end
    if n == 0 then
      for i = 1, PAGE do
        if page_bytes[i] ~= nil then
          n = i
        end
      end
    end
  end
  if page_bytes[0] ~= nil then
    for i = 0, n - 1 do
      t[#t + 1] = string.char((page_bytes[i] or 0) % 256)
    end
  else
    for i = 1, n do
      t[#t + 1] = string.char((page_bytes[i] or 0) % 256)
    end
  end
  return table.concat(t)
end

local function emit_page_hex(logical_page, data)
  local hex = hex_record(0x0000, 0x02, string.char(0x00, logical_page % 256))
  local CHUNK = 32
  for off = 0, #data - 1, CHUNK do
    local chunk = data:sub(off + 1, math.min(off + CHUNK, #data))
    hex = hex .. hex_record(0x4000 + off, 0x00, chunk)
  end
  return hex
end

local function wrap_tifl(name, hex)
  name = normalize_app_name(name)
  local name_pad = name .. string.rep("\0", 8 - #name)
  -- TIFL header is exactly 78 bytes (see tilp flash file format).
  local hdr = "**TIFL**" -- 0..7
    .. string.char(0x01, 0x00) -- 8..9 revision
    .. string.char(0x00) -- 10 flags
    .. string.char(0x00) -- 11 object type
    .. string.char(0x01, 0x01, 0x20, 0x26) -- 12..15 date
    .. string.char(#name) -- 16
    .. name_pad -- 17..24
    .. string.rep("\0", 23) -- 25..47
    .. string.char(0x73, 0x24) -- 48 device, 49 data type (app)
    .. string.rep("\0", 24) -- 50..73
  local size = #hex
  hdr = hdr
    .. string.char(size % 256, math.floor(size / 256) % 256,
      math.floor(size / 65536) % 256, math.floor(size / 16777216) % 256) -- 74..77
  if #hdr ~= 78 then
    return nil, "internal: bad TIFL header size " .. tostring(#hdr)
  end

  local sum = 0
  for i = 1, #hex do
    sum = sum + hex:byte(i)
  end
  local csum = string.char(sum % 256, math.floor(sum / 256) % 256)
  return hdr .. hex .. csum
end

--- Pack one or more <=16KB page images into a .8xk.
-- page_bytes:
--   string                         -> single page
--   { "page0", "page1", ... }      -> multi-page (1-based or array of strings)
--   assembler result { pages = { [0]={bytes,size}, ... }, n_pages = N }
--   byte table (0- or 1-based)     -> single page
function Eightxk.pack_app(page_bytes, opts)
  opts = opts or {}
  local name = normalize_app_name(opts.name or "TINYAPP")
  local pages = {}

  if type(page_bytes) == "string" then
    pages[1] = page_bytes
  elseif type(page_bytes) == "table" then
    if page_bytes.pages then
      local n = page_bytes.n_pages or 0
      if n == 0 then
        for p, _ in pairs(page_bytes.pages) do
          if type(p) == "number" and p + 1 > n then n = p + 1 end
        end
      end
      for i = 0, n - 1 do
        local pg = page_bytes.pages[i]
        if not pg then
          return nil, "missing assembler page " .. tostring(i)
        end
        if type(pg) == "string" then
          pages[#pages + 1] = pg
        else
          pages[#pages + 1] = bytes_table_to_string(pg.bytes or pg, { size = pg.size })
        end
      end
    elseif type(page_bytes[1]) == "string" then
      for i = 1, #page_bytes do
        pages[i] = page_bytes[i]
      end
    else
      pages[1] = bytes_table_to_string(page_bytes, opts)
    end
  else
    return nil, "page_bytes must be string, page list, or byte table"
  end

  if #pages == 0 then
    return nil, "empty page image"
  end
  if #pages > 14 then
    return nil, "too many pages (max 14 on TI-83+ archive)"
  end

  for i, data in ipairs(pages) do
    if #data == 0 then
      return nil, "empty page image at page " .. tostring(i - 1)
    end
    if #data > PAGE then
      return nil, string.format("page %d too large (%d > %d)", i - 1, #data, PAGE)
    end
  end
  if pages[1]:byte(1) ~= 0x80 then
    return nil, "page 0 missing Flash App header (expected 0x80)"
  end

  local hex = ""
  for i, data in ipairs(pages) do
    hex = hex .. emit_page_hex(i - 1, data)
  end
  hex = hex .. hex_record(0x0000, 0x01, "")
  return wrap_tifl(name, hex)
end

--- Build a minimal synthetic .8xk (TIFL + Intel HEX) for tests.
-- HEX uses absolute archive page numbers (base_page downward) so parse/inject
-- tests can assert physical placement; TLV header page count matches n_pages.
function Eightxk.make_synthetic(opts)
  opts = opts or {}
  local name = normalize_app_name(opts.name or "TESTAPP")
  local n_pages = opts.pages or 1
  local base_page = opts.base_page or 0x15

  local hex = ""
  for i = 0, n_pages - 1 do
    local page = base_page - i
    hex = hex .. hex_record(0x0000, 0x02, string.char(0, page))
    local payload
    if i == 0 then
      payload = Eightxk.build_app_header(name, n_pages) .. string.char(0xC9)
    else
      payload = string.char(0x00) .. string.rep("A", 15)
    end
    hex = hex .. hex_record(0x4000, 0x00, payload)
  end
  hex = hex .. hex_record(0x0000, 0x01, "")
  return wrap_tifl(name, hex)
end

return Eightxk
