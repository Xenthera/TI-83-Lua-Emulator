-- Behavior-based function naming for TI-83+ ROM pages.
-- Fingerprints port I/O / call graphs and returns assembler-style { name = addr }.

local Disasm = require("asm.disasm")

local Infer = {}

local PAGE = 0x4000

local function u8(n)
  n = n % 256
  if n < 0 then n = n + 256 end
  return n
end

local function u16(n)
  n = n % 65536
  if n < 0 then n = n + 65536 end
  return n
end

local RST_NAMES = {
  [0x00] = "rst00_boot",
  [0x08] = "rst08",
  [0x10] = "rst10",
  [0x18] = "rst18",
  [0x20] = "rst20",
  [0x28] = "rst28_bcall",
  [0x30] = "rst30",
  [0x38] = "rst38_isr",
}

local function default_seeds()
  local s = { 0x0000 }
  for a = 0x08, 0x38, 8 do
    s[#s + 1] = a
  end
  return s
end

--- Walk a function CFG from entry; collect I/O fingerprint.
-- Bound size so undecodable / data regions don't explode.
local function fingerprint_fn(read8, entry, size, max_insns)
  max_insns = max_insns or 64
  local outs, ins = {}, {}
  local out_count, in_count = {}, {}
  local calls = {}
  local ands, ors, ld_as, cps = {}, {}, {}, {}
  local saw_bit = {}
  local insn_n = 0
  local visited = {}
  local queue = { u16(entry) }

  while #queue > 0 and insn_n < max_insns do
    local a = table.remove(queue, 1)
    if visited[a] or a >= size then
      -- skip
    else
      visited[a] = true
      local insn = Disasm.decode(read8, a)
      if not insn then
        -- stop this path
      else
        insn_n = insn_n + 1
        if insn.out_port then
          local p = u8(insn.out_port)
          outs[p] = true
          out_count[p] = (out_count[p] or 0) + 1
        end
        if insn.in_port then
          local p = u8(insn.in_port)
          ins[p] = true
          in_count[p] = (in_count[p] or 0) + 1
        end
        if insn.and_imm then ands[u8(insn.and_imm)] = true end
        if insn.or_imm then ors[u8(insn.or_imm)] = true end
        if insn.ld_a then ld_as[u8(insn.ld_a)] = true end
        if insn.cp_imm then cps[u8(insn.cp_imm)] = true end
        if insn.bit_y then saw_bit[insn.bit_y] = true end
        if insn.call and insn.branch then
          calls[u16(insn.branch)] = true
        end

        -- Unconditional ret / reti ends this path
        if insn.ret and not insn.fallthrough then
          -- done
        else
          if insn.branch and not insn.call then
            -- jp/jr (possibly conditional)
            if not visited[u16(insn.branch)] then
              queue[#queue + 1] = u16(insn.branch)
            end
          end
          if insn.call and insn.branch then
            -- continue after call
          end
          if insn.fallthrough and not visited[u16(insn.fallthrough)] then
            queue[#queue + 1] = u16(insn.fallthrough)
          end
          -- Unconditional jp: no fallthrough already handled
        end
      end
    end
  end

  return {
    entry = u16(entry),
    outs = outs,
    ins = ins,
    out_count = out_count,
    in_count = in_count,
    calls = calls,
    ands = ands,
    ors = ors,
    ld_as = ld_as,
    cps = cps,
    saw_bit = saw_bit,
    insn_n = insn_n,
    body = visited,
  }
end

local function has_lcd_busy_pattern(fp)
  -- in a,(0x02); and 0x02; jr z,loop  OR bit 1,a
  if not fp.ins[0x02] then return false end
  if fp.ands[0x02] then return true end
  if fp.saw_bit[1] then return true end
  return false
end

local function only_ports(fp, list)
  local set = {}
  for _, p in ipairs(list) do set[p] = true end
  for p in pairs(fp.outs) do
    if not set[p] then return false end
  end
  for p in pairs(fp.ins) do
    if not set[p] then return false end
  end
  return true
end

local function assign_unique(used, base)
  if not used[base] then
    used[base] = true
    return base
  end
  local i = 2
  while used[base .. "_" .. i] do
    i = i + 1
  end
  local n = base .. "_" .. i
  used[n] = true
  return n
end

--- Classify a fingerprint into a base name (or nil).
local function classify_leaf(fp, named_addrs)
  -- LCD busy wait: in 02 + mask bit1, no outs (or trivial)
  if has_lcd_busy_pattern(fp) and not fp.outs[0x10] and not fp.outs[0x11]
      and not fp.outs[0x01] and fp.insn_n <= 16 then
    local outs_ok = true
    for p in pairs(fp.outs) do
      if p ~= 0x03 then outs_ok = false end
    end
    if outs_ok then
      return "lcd_busy_wait"
    end
  end

  -- Tiny LCD port stubs (pipeline-style lcd_cmd / lcd_data)
  if fp.outs[0x10] and only_ports(fp, { 0x10 }) and fp.insn_n <= 4 then
    return "lcd_cmd"
  end
  if fp.outs[0x11] and only_ports(fp, { 0x11 }) and fp.insn_n <= 4 then
    return "lcd_data"
  end

  -- LCD write cmd: out 10, often after busy wait call / inline wait
  if fp.outs[0x10] and not fp.outs[0x11] and not fp.outs[0x01] then
    local calls_wait = false
    for t in pairs(fp.calls) do
      if named_addrs[t] == "lcd_busy_wait" then calls_wait = true end
    end
    if calls_wait or has_lcd_busy_pattern(fp) then
      if fp.ors[0x80] and not fp.ors[0x20] then
        return "lcd_set_row"
      end
      if fp.ors[0x20] and not fp.ors[0x80] then
        return "lcd_set_col"
      end
      if fp.insn_n <= 24 then
        return "lcd_write_cmd"
      end
    elseif fp.insn_n <= 12 and only_ports(fp, { 0x10, 0x02 }) then
      return "lcd_write_cmd"
    end
  end

  -- LCD write data
  if fp.outs[0x11] and not fp.outs[0x10] and not fp.outs[0x01] then
    local calls_wait = false
    for t in pairs(fp.calls) do
      if named_addrs[t] == "lcd_busy_wait" then calls_wait = true end
    end
    if calls_wait or has_lcd_busy_pattern(fp) or only_ports(fp, { 0x11, 0x02 }) then
      if fp.insn_n <= 24 then
        return "lcd_write_data"
      end
    end
  end

  -- Fixed LCD command stubs: push af; ld a,N; call busy / inline wait; out (10),a; pop; ret
  if fp.outs[0x10] and not fp.outs[0x11] and not fp.outs[0x01]
      and fp.insn_n <= 16 and (fp.ld_as[0x05] or fp.ld_as[0x07] or fp.ld_as[0x02]) then
    local calls_wait = false
    for t in pairs(fp.calls) do
      local n = named_addrs[t]
      if n == "lcd_busy_wait" or (n and n:match("^lcd_busy_wait")) then
        calls_wait = true
      end
    end
    if calls_wait or has_lcd_busy_pattern(fp) then
      if fp.ld_as[0x07] and not fp.ld_as[0x05] then
        return "lcd_cmd_07"
      end
      if fp.ld_as[0x05] and not fp.ld_as[0x07] then
        return "lcd_cmd_05"
      end
    end
  end

  -- Keypad: port 01 in/out, no LCD
  if (fp.outs[0x01] or fp.ins[0x01]) and not fp.outs[0x10] and not fp.outs[0x11] then
    if fp.outs[0x01] and fp.ins[0x01] and fp.insn_n <= 64 then
      return "key_scan"
    elseif fp.outs[0x01] and not fp.ins[0x01] and only_ports(fp, { 0x01 }) and fp.insn_n <= 6 then
      return "key_group"
    elseif fp.ins[0x01] and not fp.outs[0x01] and only_ports(fp, { 0x01 }) and fp.insn_n <= 6 then
      return "key_read"
    end
  end

  -- MMU banking (tiny helpers: ld a,n / out (6|7),a / ret)
  if fp.outs[0x06] and only_ports(fp, { 0x06 }) and fp.insn_n <= 6 then
    return "mmu_set_bankA"
  end
  if fp.outs[0x07] and only_ports(fp, { 0x07 }) and fp.insn_n <= 6 then
    return "mmu_set_bankB"
  end
  -- Banked-page MMU helpers are often a bit larger (push/pop).
  if fp.outs[0x06] and not fp.outs[0x10] and not fp.outs[0x11] and not fp.outs[0x01]
      and fp.insn_n <= 12 and (only_ports(fp, { 0x06 }) or only_ports(fp, { 0x06, 0x02 })) then
    return "mmu_set_bankA"
  end
  if fp.outs[0x07] and not fp.outs[0x10] and not fp.outs[0x11] and not fp.outs[0x01]
      and fp.insn_n <= 12 and (only_ports(fp, { 0x07 }) or only_ports(fp, { 0x07, 0x02 })) then
    return "mmu_set_bankB"
  end

  -- Interrupt mask / status helpers
  if fp.outs[0x03] and only_ports(fp, { 0x03 }) and fp.insn_n <= 8 then
    return "int_mask_out"
  end
  if fp.ins[0x04] and only_ports(fp, { 0x04 }) and fp.insn_n <= 8 then
    return "int_status_in"
  end

  -- Link port stub leaves (host will no-op)
  if (fp.outs[0x00] or fp.ins[0x00]) and not fp.outs[0x10] and not fp.outs[0x01]
      and fp.insn_n <= 16 then
    if only_ports(fp, { 0x00 }) or only_ports(fp, { 0x00, 0x02 }) then
      return "link_io"
    end
  end

  return nil
end

local function call_count(call_names, ...)
  local n = 0
  for i = 1, select("#", ...) do
    n = n + (call_names[select(i, ...)] or 0)
  end
  return n
end

local function classify_wrapper(fp, named_addrs)
  local call_names = {}
  local ncalls = 0
  for t in pairs(fp.calls) do
    ncalls = ncalls + 1
    local n = named_addrs[t]
    if n then
      -- Strip _2 suffixes for matching
      local base = n:match("^(.-)_%d+$") or n
      call_names[base] = (call_names[base] or 0) + 1
      call_names[n] = (call_names[n] or 0) + 1
    end
  end
  if ncalls == 0 then return nil end

  local cmd_n = call_count(call_names, "lcd_write_cmd", "lcd_cmd")
  local data_n = call_count(call_names, "lcd_write_data", "lcd_data")

  -- lcd_set_xy: or 0x80 (row) + or 0x20 (col), only cmd helpers
  if cmd_n >= 2 and data_n == 0 and fp.ors[0x80] and fp.ors[0x20] and fp.insn_n <= 16 then
    return "lcd_set_xy"
  end

  local only_cmd = cmd_n > 0 and data_n == 0 and not fp.outs[0x01]
  if only_cmd and cmd_n >= 2 then
    local initish = fp.ld_as[0x01] or fp.ld_as[0x03] or fp.ld_as[0x05]
    if initish and fp.insn_n <= 40 and not fp.ors[0x80] then
      return "lcd_init"
    end
  end

  -- lcd_clear: cmd+data, Y-autoinc 0x07, 64 rows (cp 0x40), 12 cols
  if cmd_n > 0 and data_n > 0 and fp.insn_n <= 64 then
    if fp.ld_as[0x07] and fp.cps[0x40] then
      return "lcd_clear"
    end
    if fp.ld_as[0x07] and (fp.cps[0x0C] or fp.ld_as[0x0C]) then
      return "lcd_clear"
    end
    return "lcd_put"
  end

  -- draw_char: set_xy + data writes (glyph rows)
  local xy_n = call_count(call_names, "lcd_set_xy")
  if xy_n > 0 and data_n > 0 and cmd_n == 0 and fp.insn_n <= 48 then
    return "draw_char"
  end

  -- draw_string: walks HL, calls draw_char, column limit 12
  local ch_n = call_count(call_names, "draw_char")
  if ch_n > 0 and fp.cps[0x0C] and fp.insn_n <= 32 then
    return "draw_string"
  end

  return nil
end

local function is_text_byte(c)
  return (c >= 0x20 and c <= 0x7E) or c == 0
end

--- Name NUL-terminated ASCII blobs referenced by ld hl/de,nn in code.
local function infer_string_labels(read8, win_lo, win_hi, code_at, used, addr_name, symbols)
  local str_i = 1
  for addr, insn in pairs(code_at) do
    local text = insn.text or ""
    local target = text:match("^ld hl,(0x%x+)$") or text:match("^ld de,(0x%x+)$")
    if target then
      local a = tonumber(target)
      if a and a >= win_lo and a < win_hi and not addr_name[a] then
        local j = a
        local n = 0
        local ok = true
        while j < win_hi and n < 64 do
          local c = read8(j)
          if c == 0 then break end
          if not (c >= 0x20 and c <= 0x7E) then
            ok = false
            break
          end
          n = n + 1
          j = j + 1
        end
        if ok and n >= 3 and (j >= win_hi or read8(j) == 0) then
          local name = assign_unique(used, "str_" .. str_i)
          str_i = str_i + 1
          addr_name[a] = name
          symbols[name] = a
        end
      end
    end
  end
end

--- Name font / ascii_map tables from ld de/hl immediates in draw_char-like code.
local function infer_table_labels(read8, win_lo, win_hi, code_at, used, addr_name, symbols)
  for addr, insn in pairs(code_at) do
    local text = insn.text or ""
    local target = text:match("^ld de,(0x%x+)$") or text:match("^ld hl,(0x%x+)$")
    if target then
      local a = tonumber(target)
      if a and a >= win_lo and a < win_hi and not addr_name[a] then
        local run = 0
        local j = a
        while j < win_hi and not addr_name[j] do
          run = run + 1
          j = j + 1
          if run > 512 then break end
        end
        if run == 256 or (run >= 200 and run <= 256) then
          local name = assign_unique(used, "ascii_map")
          addr_name[a] = name
          symbols[name] = a
        elseif run >= 64 and run % 8 == 0 and run <= 400 then
          local name = assign_unique(used, "font")
          addr_name[a] = name
          symbols[name] = a
        end
      end
    end
  end
end

--- Infer names for one flash page (or flat image region).
-- opts:
--   size   address-space high bound (default 0x4000)
--   seeds  entry seeds
--   symbols existing { name = addr } - preserved (win on conflict)
--   window_lo / window_hi - bank window (e.g. 0x4000..0x8000 for pages >=1)
-- @return symbols { name = addr }, meta
function Infer.infer(read8, opts)
  opts = opts or {}
  local size = opts.size or PAGE
  local seeds = opts.seeds or default_seeds()
  local preserved = opts.symbols or {}
  local win_lo = opts.window_lo or 0
  local win_hi = opts.window_hi or size

  local function in_window(a)
    return a >= win_lo and a < win_hi
  end

  local code_at, _, labels, call_targets = Disasm.discover_code(read8, seeds, size, {
    window_lo = win_lo,
    window_hi = win_hi,
  })

  -- Function entries: call targets + RST vectors that have code
  local entries = {}
  for a in pairs(call_targets) do
    if in_window(a) then entries[a] = true end
  end
  -- Linear CALL harvest: recursive discovery misses targets behind IX/IY gaps.
  for addr = win_lo, win_hi - 3 do
    if read8(addr) == 0xCD then
      local t = read8(addr + 1) + read8(addr + 2) * 256
      if in_window(t) then
        entries[t] = true
        call_targets[t] = true
      end
    end
  end
  -- RST / boot seeds only apply to page-0 style windows
  if win_lo == 0 then
    for a, name in pairs(RST_NAMES) do
      if a < size and (code_at[a] or labels[a]) then
        entries[a] = true
      end
    end
    if code_at[0] then entries[0] = true end
  else
    if code_at[win_lo] then entries[win_lo] = true end
  end

  local fps = {}
  for a in pairs(entries) do
    fps[a] = fingerprint_fn(read8, a, win_hi)
  end

  local used = {}
  local addr_name = {} -- addr -> name
  local symbols = {}

  -- Preserve manual symbols
  for name, addr in pairs(preserved) do
    if type(name) == "string" and type(addr) == "number" then
      symbols[name] = u16(addr)
      addr_name[u16(addr)] = name
      used[name] = true
    end
  end

  -- RST vector names (if not preserved) - page0 only
  if win_lo == 0 then
    for a, name in pairs(RST_NAMES) do
      if a < size and entries[a] and not addr_name[a] then
        local n = assign_unique(used, name)
        addr_name[a] = n
        symbols[n] = a
      end
    end

    -- Heuristic: unconditional jp from 0x0000 -> main
    if not addr_name[0] or addr_name[0] == "rst00_boot" then
      local insn0 = Disasm.decode(read8, 0)
      if insn0 and insn0.text and insn0.text:match("^jp ") and insn0.branch
          and in_window(insn0.branch) then
        if not addr_name[insn0.branch] then
          local n = assign_unique(used, "main")
          addr_name[insn0.branch] = n
          symbols[n] = insn0.branch
        end
      end
    end
  end

  -- Pass 1: leaf classification (may need lcd_busy_wait before cmd)
  -- Sort by size ascending so small helpers name first
  local order = {}
  for a, fp in pairs(fps) do
    order[#order + 1] = a
  end
  table.sort(order, function(a, b)
    return fps[a].insn_n < fps[b].insn_n
  end)

  local function apply_pass(classifier)
    local changed = true
    local guard = 0
    while changed and guard < 4 do
      changed = false
      guard = guard + 1
      for _, a in ipairs(order) do
        if not addr_name[a] then
          local base = classifier(fps[a], addr_name)
          if base then
            local n = assign_unique(used, base)
            addr_name[a] = n
            symbols[n] = a
            changed = true
          end
        end
      end
    end
  end

  apply_pass(classify_leaf)
  apply_pass(classify_wrapper)

  -- Pattern-seed fixed LCD command stubs not reached by call-graph alone:
  --   F5 3E nn CD lo hi  = push af; ld a,nn; call lcd_busy_wait
  --   F5 3E nn 18 dd     = push af; ld a,nn; jr to that call
  local busy_addr = symbols["lcd_busy_wait"]
  if type(busy_addr) == "number" then
    local blo = busy_addr % 256
    local bhi = math.floor(busy_addr / 256) % 256
    local function name_cmd(a, imm)
      if addr_name[a] then return end
      local base = (imm == 0x07 and "lcd_cmd_07")
        or (imm == 0x05 and "lcd_cmd_05")
        or string.format("lcd_cmd_%02X", imm)
      local n = assign_unique(used, base)
      addr_name[a] = n
      symbols[n] = a
      entries[a] = true
      if not fps[a] then
        fps[a] = fingerprint_fn(read8, a, win_hi)
      end
    end
    for a = win_lo, win_hi - 6 do
      if read8(a) == 0xF5 and read8(a + 1) == 0x3E then
        local imm = read8(a + 2)
        if read8(a + 3) == 0xCD and read8(a + 4) == blo and read8(a + 5) == bhi then
          name_cmd(a, imm)
        elseif read8(a + 3) == 0x18 then
          local rel = read8(a + 4)
          if rel >= 128 then rel = rel - 256 end
          local tgt = u16(a + 5 + rel)
          if in_window(tgt) and read8(tgt) == 0xCD
              and read8(tgt + 1) == blo and read8(tgt + 2) == bhi then
            name_cmd(a, imm)
          end
        end
      end
    end
  end

  -- String / table xrefs (after code names so ld hl/de immediates rewrite on emit)
  infer_string_labels(read8, win_lo, win_hi, code_at, used, addr_name, symbols)
  infer_table_labels(read8, win_lo, win_hi, code_at, used, addr_name, symbols)

  return symbols, {
    entries = entries,
    fingerprints = fps,
    addr_name = addr_name,
    code_at = code_at,
  }
end

function Infer.infer_bytes(bytes, opts)
  opts = opts or {}
  local size = opts.size or PAGE
  local page = opts.page or 0
  local base = page * PAGE
  local read8
  if type(bytes) == "string" then
    read8 = function(addr)
      local off = base + addr
      if addr < 0 or addr >= size or off >= #bytes then return 0 end
      return bytes:byte(off + 1) or 0
    end
  else
    read8 = function(addr)
      return u8(bytes[base + addr] or 0)
    end
  end
  opts.size = size
  return Infer.infer(read8, opts)
end

return Infer
