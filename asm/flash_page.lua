-- TI-83+ flash page view helpers for flat recovery.
-- Page 0 maps at 0x0000; other pages map in the 0x4000 bank window.

local Flash = {}

Flash.PAGE = 0x4000
Flash.BANK = 0x4000

function Flash.is_blank(slice)
  if not slice or #slice == 0 then return true end
  for i = 1, #slice do
    local b = slice:byte(i)
    if b ~= 0xFF and b ~= 0x00 then
      return false
    end
  end
  -- All 0x00 or 0xFF - treat as non-code for recovery.
  local first = slice:byte(1)
  for i = 2, math.min(#slice, 64) do
    if slice:byte(i) ~= first then return false end
  end
  return true
end

local function dedupe_seeds(list)
  local seen, out = {}, {}
  for _, a in ipairs(list) do
    a = a % 65536
    if not seen[a] then
      seen[a] = true
      out[#out + 1] = a
    end
  end
  return out
end

--- Scan full ROM for TI banked trampoline sites: call 2B07/2B3C ; .dw dest ; .db page
-- Returns map: page -> { cpu_addr, ... } (dest in 0x4000..0x7FFF, page &= 0x1F).
function Flash.scan_banked_targets(rom)
  local by_page = {}
  if type(rom) ~= "string" or #rom < 6 then return by_page end
  for i = 1, #rom - 5 do
    local b0, b1, b2 = rom:byte(i), rom:byte(i + 1), rom:byte(i + 2)
    if b0 == 0xCD and (b1 == 0x07 or b1 == 0x3C) and b2 == 0x2B then
      local dest = rom:byte(i + 3) + rom:byte(i + 4) * 256
      local page = rom:byte(i + 5) % 32
      if dest >= Flash.BANK and dest < Flash.BANK + Flash.PAGE then
        local list = by_page[page]
        if not list then
          list = {}
          by_page[page] = list
        end
        list[#list + 1] = dest
      end
    end
  end
  for page, list in pairs(by_page) do
    by_page[page] = dedupe_seeds(list)
  end
  return by_page
end

--- Build a CPU-address view of one 16KB flash slice.
-- page 0 -> addresses 0x0000..0x3FFF
-- page N -> addresses 0x4000..0x7FFF (ASIC bank window)
-- opts.extra_seeds: additional CPU addresses to treat as code entries
function Flash.view(slice, page, opts)
  page = page or 0
  opts = opts or {}
  local PAGE, BANK = Flash.PAGE, Flash.BANK
  if #slice < PAGE then
    slice = slice .. string.rep("\0", PAGE - #slice)
  end

  if page == 0 then
    local seeds = {
      0x0000, 0x0008, 0x0010, 0x0018, 0x0020, 0x0028, 0x0030, 0x0038,
      -- OS present: boot jp z,0x0053 -> jp 0x0A6C cold start -> HALT @ 0x0AAD
      0x0053, 0x0A6C, 0x0AAE, 0x0B8D,
    }
    for _, a in ipairs(opts.extra_seeds or {}) do
      seeds[#seeds + 1] = a
    end
    seeds = dedupe_seeds(seeds)
    return {
      page = 0,
      slice = slice,
      size = PAGE,
      window_lo = 0,
      window_hi = PAGE,
      seeds = { 0x0000, 0x0038, 0x0053, 0x0A6C },
      infer_seeds = seeds,
      read8 = function(addr)
        if addr < 0 or addr >= PAGE then return 0 end
        return slice:byte(addr + 1) or 0
      end,
    }
  end

  -- Priority seeds first so the 256-cap never drops trampoline entries.
  local seeds = {}
  for _, a in ipairs(opts.extra_seeds or {}) do
    if a >= BANK and a < BANK + PAGE then
      seeds[#seeds + 1] = a
    end
  end
  seeds[#seeds + 1] = BANK
  -- Boot continuation lands at CPU 0x80D5 in mem-mode 1 (= offset 0x0D5 -> 0x40D5).
  seeds[#seeds + 1] = BANK + 0x0D5
  seeds[#seeds + 1] = BANK + 0x0E3
  -- Common mem-mode-1 bank entry (jp 0x8100 -> offset 0x100).
  seeds[#seeds + 1] = BANK + 0x100
  -- Power-on LCD path (from Lua boot smoke): page 0x19 -> 0x41A0, page 6 -> 0x4D15.
  if page == 0x19 then seeds[#seeds + 1] = BANK + 0x01A0 end
  if page == 0x06 then
    seeds[#seeds + 1] = BANK + 0x0D15
    seeds[#seeds + 1] = BANK + 0x0D0E -- banked from page0 @ 3EEB
  end
  -- Homescreen glyph blit (Lua smoke: pixels at 5DF9/5698 on page 1)
  if page == 0x01 then
    seeds[#seeds + 1] = BANK + 0x1DF9
    seeds[#seeds + 1] = BANK + 0x1E6A
    seeds[#seeds + 1] = BANK + 0x15C6
    seeds[#seeds + 1] = BANK + 0x1698
    seeds[#seeds + 1] = BANK + 0x15B8
  end
  -- CALL/JP targets into bank windows (0x4000 and mem-mode-1 0x8000)
  for off = 0, PAGE - 3 do
    local op = slice:byte(off + 1)
    if op == 0xCD or op == 0xC3 then
      local t = slice:byte(off + 2) + slice:byte(off + 3) * 256
      if t >= BANK and t < BANK + PAGE then
        seeds[#seeds + 1] = t
      elseif t >= 0x8000 and t < 0xC000 then
        seeds[#seeds + 1] = BANK + (t - 0x8000)
      end
    end
  end
  -- Light pointer-table harvest at page head (common OS pattern)
  for off = 0, math.min(0x200, PAGE - 2), 2 do
    local t = slice:byte(off + 1) + slice:byte(off + 2) * 256
    if t >= BANK and t < BANK + PAGE then
      seeds[#seeds + 1] = t
    end
  end
  seeds = dedupe_seeds(seeds)
  -- Cap runaway tables (trampoline extras already occupy the front)
  if #seeds > 512 then
    local trimmed = {}
    for i = 1, 512 do trimmed[i] = seeds[i] end
    seeds = trimmed
  end

  return {
    page = page,
    slice = slice,
    size = BANK + PAGE,
    window_lo = BANK,
    window_hi = BANK + PAGE,
    seeds = seeds,
    infer_seeds = seeds,
    read8 = function(addr)
      if addr < BANK or addr >= BANK + PAGE then return 0 end
      return slice:byte(addr - BANK + 1) or 0
    end,
  }
end

return Flash
