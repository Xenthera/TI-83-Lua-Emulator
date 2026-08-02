-- TI-83+ program (.8xp) / group (.8xg) parser + RAM/VAT injector.
--
-- Programs live in user RAM (PRGM menu), not flash archive. Inject after the
-- OS has initialized the VAT (homescreen), not before Machine:reset().
--
-- .8xg "grouped" GraphLink files are the same **TI83F* container with multiple
-- variable entries (usually several programs). We unpack programs into the VAT.

local Eightxp = {}

-- OS RAM equates (TI-83+)
local TEMP_MEM = 0x9820
local FP_BASE = 0x9822
local FPS = 0x9824
local OP_BASE = 0x9826
local OPS = 0x9828
local PTEMP = 0x982E
local PROG_PTR = 0x9830
local NEW_DATA_PTR = 0x9832
local IMATH_PTR1 = 0x84D3 -- iMathPtrs (5 words); free-gap bookkeeping for editors
local EDIT_TOP = 0x96F4 -- editTop/editCursor/editTail/editBtm
local USER_MEM = 0x9D95
local SYM_TABLE = 0xFE66
local FLAGS_IY = 0x89F0 -- standard OS IY base
local EDIT_FLAGS_OFF = 1 -- (IY+editFlags)
local EDIT_OPEN = 0x04 -- bit 2: edit buffer is open
local CLOSE_EDIT_SLAB = 0x3E -- CloseEditBuf parks FPS at editTop+this when empty

local TYPE_PROG = 0x05
local TYPE_PROT_PROG = 0x06
local TYPE_APPVAR = 0x15 -- WikiTI: AppVarObj = 15h
local TYPE_APPVAR_ALT = 0x14 -- GroupTemp / related
local TYPE_LIST = 0x01
local TYPE_GROUP = 0x17
-- BASIC program tokens use tListName (EBh) before custom list chars.
-- VAT / OP1 / FindSym use tVarLst (5Dh) + name + NUL (see ASMin28Days day 19).
local T_VAR_LST = 0x5D
local T_LIST_NAME = 0xEB -- only for TI-BASIC token streams, not VAT names

local function u16le(s, off)
  local a, b = s:byte(off, off + 1)
  return a + b * 256
end

local function read16(mmu, addr)
  return mmu:read(addr) + mmu:read(addr + 1) * 256
end

local function write16(mmu, addr, v)
  v = v % 65536
  mmu:write(addr, v % 256)
  mmu:write(addr + 1, math.floor(v / 256) % 256)
end

local function normalize_name(name)
  name = (name or ""):gsub("%z", ""):gsub("%s+$", "")
  if #name > 8 then
    name = name:sub(1, 8)
  end
  return name
end

--- Parse all variables from a GraphLink TI83F/TI83 file (.8xp / .8xg / etc.).
-- Returns array of { name, type, version, flag, data }.
function Eightxp.parse_vars(file_bytes)
  if type(file_bytes) ~= "string" or #file_bytes < 57 then
    return nil, "empty TI variable file"
  end
  local sig = file_bytes:sub(1, 8)
  if sig ~= "**TI83F*" and sig ~= "**TI83**" then
    return nil, "not a TI-83/83+ variable file (expected **TI83F*)"
  end

  -- Header is 55 bytes (0..54); data section starts at file offset 55.
  local pos = 56 -- Lua 1-based
  if pos + 2 > #file_bytes then
    return nil, "truncated variable file"
  end

  local vars = {}
  local data_end = #file_bytes - 2 -- exclude checksum
  while pos + 15 <= data_end + 1 do
    local hdr_len = u16le(file_bytes, pos) -- 0x0B or 0x0D
    if hdr_len ~= 0x0B and hdr_len ~= 0x0D then
      break
    end
    local var_len = u16le(file_bytes, pos + 2)
    local vtype = file_bytes:byte(pos + 4)
    local name = normalize_name(file_bytes:sub(pos + 5, pos + 12))
    local version, flag = 0, 0
    local data_pos
    if hdr_len == 0x0D then
      version = file_bytes:byte(pos + 13)
      flag = file_bytes:byte(pos + 14)
      data_pos = pos + 17
    else
      data_pos = pos + 15
    end
    local data = file_bytes:sub(data_pos, data_pos + var_len - 1)
    if #data < var_len then
      return nil, "truncated variable data for " .. tostring(name)
    end
    vars[#vars + 1] = {
      name = name,
      type = vtype,
      version = version,
      flag = flag,
      data = data,
    }
    pos = data_pos + var_len
  end

  if #vars == 0 then
    return nil, "no variables in file"
  end
  return vars
end

function Eightxp.is_program_type(vtype)
  return vtype == TYPE_PROG or vtype == TYPE_PROT_PROG
end

--- True if this type lives in the program VAT (progPtr..pTemp).
function Eightxp.is_prog_vat_type(vtype)
  return vtype == TYPE_PROG
    or vtype == TYPE_PROT_PROG
    or vtype == TYPE_APPVAR
    or vtype == TYPE_APPVAR_ALT
    or vtype == TYPE_LIST
end

--- Parse a GraphLink .8xp (or first program in a multi-var file).
-- Returns { name, type, version, data } where data is RAM image (size word + tokens).
function Eightxp.parse(file_bytes)
  local vars, err = Eightxp.parse_vars(file_bytes)
  if not vars then return nil, err end

  for _, v in ipairs(vars) do
    if Eightxp.is_program_type(v.type) then
      if #v.name == 0 then
        return nil, "program has empty name"
      end
      return v
    end
  end
  return nil, string.format(
    "no program in file (found type %02X); use .8xp/.8xg for PRGM",
    vars[1].type
  )
end

local function vat_entry_size(name_len)
  return 7 + name_len
end

local function is_named_prog_vat(vtype)
  vtype = vtype % 32
  return vtype == TYPE_PROG
    or vtype == TYPE_PROT_PROG
    or vtype == TYPE_APPVAR
    or vtype == TYPE_APPVAR_ALT
    or vtype == TYPE_LIST
    or vtype == TYPE_GROUP
end

--- Byte length of the VAT entry whose type byte is at `hl`.
local function entry_size_at(mmu, hl)
  local vtype = mmu:read(hl) % 32
  if is_named_prog_vat(vtype) then
    local nl = mmu:read(hl - 6)
    if nl > 10 then
      return nil
    end
    return vat_entry_size(nl)
  end
  -- Real / complex / matrix / equation / GDB / picture: fixed 9-byte entry.
  return 9
end

--- Exclusive end address of a RAM variable's data block (best-effort).
local function var_data_end(mmu, vtype, data_addr)
  vtype = vtype % 32
  if data_addr < USER_MEM or data_addr >= 0xFE00 then
    return nil
  end
  if vtype == 0x00 then -- Real
    return data_addr + 9
  elseif vtype == 0x0C then -- Complex
    return data_addr + 18
  elseif is_named_prog_vat(vtype) or vtype == 0x02 -- RealList done above; Matrix
      or vtype == 0x03 -- Equation
      or vtype == 0x04 -- String
      or vtype == 0x07 -- GDB
      or vtype == 0x08 then -- Picture
    local sz = read16(mmu, data_addr)
    if sz > 0x6000 then
      return nil
    end
    return data_addr + 2 + sz
  end
  return nil
end

--- Walk every VAT entry; `fn(hl, vtype, page, data, es)`.
local function for_each_vat(mmu, fn)
  local ptemp = read16(mmu, PTEMP)
  local hl = SYM_TABLE
  local guard = 0
  while hl > ptemp and guard < 512 do
    guard = guard + 1
    local es = entry_size_at(mmu, hl)
    if not es then
      break
    end
    local vtype = mmu:read(hl)
    local page = mmu:read(hl - 5)
    local data = mmu:read(hl - 3) + mmu:read(hl - 4) * 256
    fn(hl, vtype, page, data, es)
    hl = hl - es
  end
end

--- True once OS has initialized VAT pointers (homescreen-ish).
-- display_on alone is too early: both pointers sit at symTable (FE66) briefly.
function Eightxp.vat_ready(mmu, min_room)
  min_room = min_room or 16
  local progptr = read16(mmu, PROG_PTR)
  local ptemp = read16(mmu, PTEMP)
  local fps = read16(mmu, FPS)
  if progptr <= 0x8000 or ptemp <= 0x8000 or fps <= 0x8000 then
    return false
  end
  if progptr > SYM_TABLE or ptemp > SYM_TABLE then
    return false
  end
  -- Program VAT is non-empty after boot (L1-L6, etc.).
  if (progptr - ptemp) < min_room then
    return false
  end
  -- FPS is end of user data (or boot's compacted stack top). Must sit in user RAM.
  if fps < USER_MEM or fps > SYM_TABLE then
    return false
  end
  return true
end

--- Top of free RAM: OP stack / temp-VAT bottom (grows down toward FPS).
local function free_ram_top(mmu)
  local ops = read16(mmu, OPS)
  local ptemp = read16(mmu, PTEMP)
  if ops < 0x8000 then
    ops = ptemp
  end
  if ptemp < 0x8000 then
    ptemp = ops
  end
  return math.min(ops, ptemp)
end

--- First free byte in the lower user-RAM pool (after lists/reals/programs).
-- Boot may leave FPS compacted against the VAT with equations packed there;
-- after CreateVar-style claim, FPS itself is the user-data end.
function Eightxp.user_data_end(mmu)
  local fps = read16(mmu, FPS)
  local ptemp = read16(mmu, PTEMP)
  local stacks_compacted = fps + 0x40 >= ptemp
  local max_end = USER_MEM
  for_each_vat(mmu, function(_, vtype, page, data)
    if page ~= 0 then
      return
    end
    local e = var_data_end(mmu, vtype, data)
    if not e or e > fps then
      return
    end
    -- Only ignore the top cluster in boot's compacted-stack layout.
    if stacks_compacted and data >= fps - 0x200 then
      return
    end
    if e > max_end then
      max_end = e
    end
  end)
  if not stacks_compacted and fps > max_end and fps < ptemp then
    max_end = fps
  end
  return max_end
end

--- Lowest data address in the top-of-free-RAM cluster (equations, etc.), or FPS.
local function top_cluster_start(mmu)
  local fps = read16(mmu, FPS)
  local lo = fps
  for_each_vat(mmu, function(_, vtype, page, data)
    if page ~= 0 then
      return
    end
    if data >= fps - 0x200 and data < fps and data < lo then
      lo = data
    end
  end)
  return lo
end

--- Release the homescreen's empty edit buffer if `editOpen` is set.
--
-- After boot the OS often leaves editOpen with editTop..editBtm spanning the
-- free RAM gap (IsEditEmpty). Injecting into that gap and then PRGM-EDIT makes
-- the OS treat the program as an empty gap-buffer - blank editor despite valid
-- tokens. Mirrors the important parts of BCALL CloseEditBuf without calling ROM
-- (the BCALL trampoline is unsafe: CloseEditBuf reuses scrap RAM).
--
-- Two empty-edit shapes exist:
--   1) Boot / full-gap: editTop..editBtm is nearly all free RAM (~20KB+).
--      Keep FPS high and collapse edit/iMath to it. The old slab path moved
--      FPS down to editTop+0x3E, which stole the gap, smashed Y= / VAT math,
--      and printed garbage after the Y= menu briefly appeared.
--   2) Small CreateEdit slab (~0x3E): park FPS at editTop+CLOSE_EDIT_SLAB.
function Eightxp.release_homescreen_edit(mmu, iy)
  iy = iy or FLAGS_IY
  local ef_addr = (iy + EDIT_FLAGS_OFF) % 65536
  local ef = mmu:read(ef_addr)
  if math.floor(ef / EDIT_OPEN) % 2 == 0 then
    return false
  end

  local top = read16(mmu, EDIT_TOP)
  local cur = read16(mmu, EDIT_TOP + 2)
  local tail = read16(mmu, EDIT_TOP + 4)
  local btm = read16(mmu, EDIT_TOP + 6)
  local empty = top == cur and tail == btm

  -- Clear editOpen (bit 2).
  mmu:write(ef_addr, ef - EDIT_OPEN)

  if empty and top >= USER_MEM and top < SYM_TABLE then
    local span = (btm - top) % 65536
    local fps = read16(mmu, FPS)
    local ops = read16(mmu, OPS)

    if span > CLOSE_EDIT_SLAB * 4 then
      -- Full-gap empty edit (boot): reclaim by exposing free RAM under FPS.
      local park = fps
      if park < btm then
        park = btm
      end
      if park > ops then
        park = ops
      end
      write16(mmu, TEMP_MEM, park)
      write16(mmu, FP_BASE, park)
      write16(mmu, FPS, park)
      write16(mmu, IMATH_PTR1, park)
      write16(mmu, IMATH_PTR1 + 2, park)
      write16(mmu, IMATH_PTR1 + 4, park)
      write16(mmu, IMATH_PTR1 + 6, 0)
      for off = 0, 6, 2 do
        write16(mmu, EDIT_TOP + off, park)
      end
    else
      -- Small CreateEdit-style buffer.
      local slab = top + CLOSE_EDIT_SLAB
      if slab > ops - 32 then
        slab = math.max(top, ops - 32)
      end
      write16(mmu, TEMP_MEM, slab)
      write16(mmu, FP_BASE, slab)
      write16(mmu, FPS, slab)
      write16(mmu, IMATH_PTR1, top)
      write16(mmu, IMATH_PTR1 + 2, slab)
      write16(mmu, IMATH_PTR1 + 4, ops)
      write16(mmu, IMATH_PTR1 + 6, CLOSE_EDIT_SLAB)
      for off = 0, 6, 2 do
        write16(mmu, EDIT_TOP + off, slab)
      end
    end
  end
  return true
end

--- After planting variable bytes in the free gap, claim them like CreateVar:
-- move FPS/tempMem down to the new user-data end and collapse the idle edit /
-- iMath free-span so PRGM EDIT cannot DelMem the whole gap (which was wiping
-- injected programs and leaving VAT data pointers pointing at ROM gibberish).
-- `newest_data_addr`/`data_len` must be passed for the var just written: until
-- FPS advances, user_data_end() ignores anything past the old FPS.
local function claim_allocated_user_ram(mmu, newest_data_addr, data_len)
  local data_end = Eightxp.user_data_end(mmu)
  if newest_data_addr and data_len and data_len > 0 then
    local end2 = newest_data_addr + data_len
    if end2 > data_end then
      data_end = end2
    end
  end
  write16(mmu, TEMP_MEM, data_end)
  write16(mmu, FP_BASE, data_end)
  write16(mmu, FPS, data_end)
  local newest = newest_data_addr or data_end
  write16(mmu, NEW_DATA_PTR, newest)
  write16(mmu, IMATH_PTR1, newest)
  write16(mmu, IMATH_PTR1 + 2, data_end)
  write16(mmu, IMATH_PTR1 + 4, data_end)
  for off = 0, 6, 2 do
    write16(mmu, EDIT_TOP + off, data_end)
  end
end

--- Grow program VAT downward by `entry_sz`.
-- Boot often leaves FPS compacted against the VAT (MemChk free≈0) with a large
-- unused gap below; in that mode we shift the top cluster with the VAT.
-- After CreateVar-style claim, FPS sits at the user-data end - only the VAT
-- itself moves, and FPS is left alone for claim_allocated_user_ram.
-- Returns address where the new entry's type byte should be written (ProgPtr).
local function open_prog_vat_entry(mmu, entry_sz)
  local progptr = read16(mmu, PROG_PTR)
  local ptemp = read16(mmu, PTEMP)
  local fps = read16(mmu, FPS)
  local ops = read16(mmu, OPS)
  if entry_sz < 8 or progptr <= ptemp then
    return nil, "VAT bounds invalid"
  end

  local data_end = Eightxp.user_data_end(mmu)
  local free_top = free_ram_top(mmu)
  if free_top - data_end < entry_sz + 32 then
    return nil, "not enough free RAM for VAT entry"
  end

  -- FPS wedged near pTemp => boot compacted-stack layout.
  local stacks_compacted = fps + 0x40 >= ptemp

  if stacks_compacted then
    local top_lo = top_cluster_start(mmu)
    local move_lo = math.min(top_lo, ptemp + 1)
    for a = move_lo, progptr do
      mmu:write(a - entry_sz, mmu:read(a))
    end

    -- Symbol-VAT entries stay put; retarget data that rode the shift.
    do
      local hl = SYM_TABLE
      local guard = 0
      while hl > progptr and guard < 512 do
        guard = guard + 1
        local es = entry_size_at(mmu, hl)
        if not es then
          break
        end
        local page = mmu:read(hl - 5)
        if page == 0 then
          local data = mmu:read(hl - 3) + mmu:read(hl - 4) * 256
          if data >= move_lo and data < fps then
            local nd = data - entry_sz
            mmu:write(hl - 3, nd % 256)
            mmu:write(hl - 4, math.floor(nd / 256) % 256)
          end
        end
        hl = hl - es
      end
    end

    local new_ptemp = ptemp - entry_sz
    local new_fps = fps - entry_sz
    write16(mmu, PTEMP, new_ptemp)
    write16(mmu, FPS, new_fps)

    local function bump_down(addr)
      local cur = read16(mmu, addr)
      if cur >= new_fps and cur <= fps then
        write16(mmu, addr, cur - entry_sz)
      end
    end
    bump_down(TEMP_MEM)
    bump_down(FP_BASE)
    bump_down(OP_BASE)
    bump_down(OPS)
    if read16(mmu, TEMP_MEM) > new_fps then
      write16(mmu, TEMP_MEM, new_fps)
    end
    if read16(mmu, FP_BASE) > new_fps then
      write16(mmu, FP_BASE, new_fps)
    end
  else
    -- Only the program-VAT block moves; free gap below is untouched.
    local move_lo = ptemp + 1
    for a = move_lo, progptr do
      mmu:write(a - entry_sz, mmu:read(a))
    end
    local new_ptemp = ptemp - entry_sz
    write16(mmu, PTEMP, new_ptemp)
    if ops == ptemp then
      write16(mmu, OPS, new_ptemp)
    end
    if read16(mmu, OP_BASE) == ptemp then
      write16(mmu, OP_BASE, new_ptemp)
    end
  end

  -- ProgPtr unchanged: new entry occupies the hole at the old ProgPtr.
  return progptr
end

--- Inject one already-parsed variable into the program VAT.
-- opts.iy: OS IY flags base (default 0x89F0). opts.skip_release: skip edit close.
function Eightxp.inject_var(mmu, prog, opts)
  opts = opts or {}
  if type(prog) ~= "table" or type(prog.data) ~= "string" then
    return nil, "invalid variable"
  end
  -- raw_name: keep binary VAT names (e.g. list tVarLst + chars + NUL) intact.
  local name = prog.raw_name and prog.name or normalize_name(prog.name)
  if #name == 0 then
    return nil, "variable has empty name"
  end
  if not Eightxp.is_prog_vat_type(prog.type) then
    return nil, string.format(
      "type %02X (%s) not supported for VAT inject yet",
      prog.type or 0, name
    )
  end

  if not opts.skip_release then
    Eightxp.release_homescreen_edit(mmu, opts.iy)
  end

  local nl = #name
  local entry_sz = vat_entry_size(nl)
  if not Eightxp.vat_ready(mmu, 8) then
    return nil, "VAT not ready; cannot install " .. name
  end

  local need = #prog.data
  local data_addr = Eightxp.user_data_end(mmu)
  local free_top = free_ram_top(mmu)
  -- Payload lives in the free gap; VAT entry claims a few more bytes later.
  if data_addr + need + entry_sz + 32 > free_top then
    return nil, "not enough RAM for " .. name
  end

  for i = 1, need do
    mmu:write(data_addr + i - 1, prog.data:byte(i))
  end

  local vat_hl, oerr = open_prog_vat_entry(mmu, entry_sz)
  if not vat_hl then
    return nil, oerr or ("VAT open failed for " .. name)
  end

  local hl = vat_hl
  mmu:write(hl, prog.type)
  mmu:write(hl - 1, 0) -- T2
  mmu:write(hl - 2, prog.version or 0)
  mmu:write(hl - 3, data_addr % 256) -- DAL
  mmu:write(hl - 4, math.floor(data_addr / 256) % 256) -- DAH
  mmu:write(hl - 5, 0) -- flash page 0 = RAM
  mmu:write(hl - 6, nl)
  for i = 1, nl do
    mmu:write(hl - 6 - i, name:byte(i))
  end

  claim_allocated_user_ram(mmu, data_addr, need)

  return {
    name = name,
    type = prog.type,
    data_addr = data_addr,
    data_len = need,
    vat = vat_hl,
  }
end

--- Pack a non-negative integer as a 9-byte TI-83+ real (sign/exp + 7 BCD + pad).
function Eightxp.ti_real(n)
  n = math.floor(tonumber(n) or 0)
  if n == 0 then
    return string.rep("\0", 9)
  end
  if n < 0 then
    return nil, "ti_real: negative not supported"
  end
  local exp = 0
  local v = n
  while v >= 10 do
    v = math.floor(v / 10)
    exp = exp + 1
  end
  -- Build 14-digit BCD mantissa (7 bytes) for n * 10^-exp (= v.frac)
  local digits = string.format("%d", n)
  digits = digits .. string.rep("0", 14 - #digits)
  digits = digits:sub(1, 14)
  local bytes = { 0x80 + exp }
  for i = 1, 7 do
    local d1 = tonumber(digits:sub(i * 2 - 1, i * 2 - 1)) or 0
    local d2 = tonumber(digits:sub(i * 2, i * 2)) or 0
    bytes[#bytes + 1] = d1 * 16 + d2
  end
  bytes[#bytes + 1] = 0
  return string.char(unpack(bytes))
end

--- Build RAM image for a custom named list ʟ`name` with `n` real elements.
-- fill: number (every element) or 9-byte real string. Default 0.
-- VAT name is tVarLst + up to 5 chars + NUL (FindSym will not see tListName/EBh).
function Eightxp.make_named_list(name, n, fill)
  name = normalize_name(name)
  if #name == 0 or #name > 5 then
    return nil, "list name must be 1..5 chars"
  end
  n = n or 0
  if n < 0 or n > 999 then
    return nil, "list dim out of range"
  end
  local elem
  if fill == nil then
    elem = string.rep("\0", 9)
  elseif type(fill) == "string" and #fill == 9 then
    elem = fill
  else
    local r, err = Eightxp.ti_real(fill)
    if not r then
      return nil, err
    end
    elem = r
  end
  local data = string.char(n % 256, math.floor(n / 256) % 256)
    .. string.rep(elem, n)
  return {
    name = string.char(T_VAR_LST) .. name .. "\0",
    raw_name = true,
    type = TYPE_LIST,
    version = 0,
    data = data,
  }
end

--- Tiny safe TI-BASIC program body (ClrHome) used to replace crashy setup progs.
function Eightxp.make_stub_program(name)
  name = normalize_name(name or "STUB")
  local tokens = string.char(0x97, 0x3F) -- ClrHome :
  local data = string.char(#tokens % 256, math.floor(#tokens / 256) % 256) .. tokens
  return {
    name = name,
    type = TYPE_PROG,
    version = 0,
    data = data,
  }
end

--- Prebuilt ʟBJ83 for blackjack: dim 102 so BLACKJ83 never InsertMem-grows.
-- 1..99 / unused slots = 1000, [100]=0 (mode), [101]=1 (game#), [102]=1000.
function Eightxp.make_blackjack_list()
  local n = 102
  local thousand = assert(Eightxp.ti_real(1000))
  local one = assert(Eightxp.ti_real(1))
  local zero = string.rep("\0", 9)
  local parts = { string.char(n % 256, math.floor(n / 256) % 256) }
  for i = 1, n do
    if i == 100 then
      parts[#parts + 1] = zero
    elseif i == 101 then
      parts[#parts + 1] = one
    else
      parts[#parts + 1] = thousand
    end
  end
  return {
    name = string.char(T_VAR_LST) .. "BJ83" .. "\0",
    raw_name = true,
    type = TYPE_LIST,
    version = 0,
    data = table.concat(parts),
  }
end

--- BJSETUP replacement: mark setup complete without InsertMem growth loop.
-- BLACKJ83 gates on ʟBJS83(1)≠0 after `1->dim(ʟBJS83)` (preserves existing value).
function Eightxp.make_bjsetup_stub()
  -- 1->dim(ʟBJS83):1->ʟBJS83(1):ClrHome:Disp "OK"
  local tokens = string.char(
    0x31, 0x04, 0xB5, 0xEB, 0x42, 0x4A, 0x53, 0x38, 0x33, 0x11, 0x3F,
    0x31, 0x04, 0xEB, 0x42, 0x4A, 0x53, 0x38, 0x33, 0x10, 0x31, 0x11, 0x3F,
    0x97, 0x3F,
    0xDE, 0x2A, 0x4F, 0x4B, 0x2A, 0x3F
  )
  local data = string.char(#tokens % 256, math.floor(#tokens / 256) % 256) .. tokens
  return {
    name = "BJSETUP",
    type = TYPE_PROG,
    version = 0,
    data = data,
  }
end

--- Write one program from a .8xp (first program only) into live machine RAM/VAT.
function Eightxp.inject(mmu, file_bytes, opts)
  opts = opts or {}
  local prog, err = Eightxp.parse(file_bytes)
  if not prog then return nil, err end
  return Eightxp.inject_var(mmu, prog, opts)
end

--- Install all program-VAT entries from a .8xp/.8xg file.
-- Returns metas array. Skipped non-program-VAT types are listed in metas.skipped.
--
-- Blackjack-style groups: real BJSETUP grows ʟBJ83 via InsertMem stores and
-- clears RAM on this emu. We stub BJSETUP, pre-create ʟBJ83 (dim 102) and
-- ʟBJS83(1)=1 - BLACKJ83 indexes up to ʟBJ83(102) and gates on the flag.
function Eightxp.inject_file(mmu, file_bytes, opts)
  opts = opts or {}
  local vars, err = Eightxp.parse_vars(file_bytes)
  if not vars then return nil, err end

  if not opts.skip_release then
    Eightxp.release_homescreen_edit(mmu, opts.iy)
  end

  local has_bjsetup, has_blackj = false, false
  for _, v in ipairs(vars) do
    if v.name == "BJSETUP" then has_bjsetup = true end
    if v.name == "BLACKJ83" then has_blackj = true end
  end
  local blackjack = has_bjsetup and has_blackj

  local metas = {}
  local skipped = {}
  local installed = 0
  local iopts = { iy = opts.iy, skip_release = true }
  for _, v in ipairs(vars) do
    local item = v
    if blackjack and v.name == "BJSETUP" and Eightxp.is_program_type(v.type) then
      item = Eightxp.make_bjsetup_stub()
    end
    if Eightxp.is_prog_vat_type(item.type) then
      local meta, ierr = Eightxp.inject_var(mmu, item, iopts)
      if not meta then
        return nil, ierr
      end
      metas[#metas + 1] = meta
      installed = installed + 1
    else
      skipped[#skipped + 1] = {
        name = v.name,
        type = v.type,
      }
    end
  end

  if blackjack then
    -- Match BJSETUP side effects, plus slots BLACKJ83 touches without InsertMem:
    -- 1..100 money, 101 game#, 102 scratch (literals go up to 102).
    local flag = Eightxp.make_named_list("BJS83", 1, 1)
    local fmeta, ferr = Eightxp.inject_var(mmu, flag, iopts)
    if not fmeta then
      return nil, "blackjack flag list: " .. tostring(ferr)
    end
    metas[#metas + 1] = fmeta
    local list = Eightxp.make_blackjack_list()
    local lmeta, lerr = Eightxp.inject_var(mmu, list, iopts)
    if not lmeta then
      return nil, "blackjack list: " .. tostring(lerr)
    end
    metas[#metas + 1] = lmeta
    installed = installed + 2
    metas.blackjack_setup = true
  end

  if installed == 0 then
    return nil, "no programs/appvars/lists to install in file"
  end
  local last = metas[#metas]
  if last then
    claim_allocated_user_ram(mmu, last.data_addr, last.data_len)
  end
  metas.skipped = skipped
  metas.count = installed
  return metas
end

function Eightxp.inject_many(mmu, file_list, opts)
  opts = opts or {}
  Eightxp.release_homescreen_edit(mmu, opts.iy)
  local metas = {}
  local fopts = { iy = opts.iy, skip_release = true }
  for i, bytes in ipairs(file_list or {}) do
    local batch, err = Eightxp.inject_file(mmu, bytes, fopts)
    if not batch then
      return nil, string.format("file #%d: %s", i, tostring(err))
    end
    for _, m in ipairs(batch) do
      metas[#metas + 1] = m
    end
  end
  return metas
end

--- Build a minimal TI-BASIC .8xp for tests (program that is just empty / one byte).
function Eightxp.make_synthetic(opts)
  opts = opts or {}
  local name = opts.name or "DEMO"
  if #name > 8 then name = name:sub(1, 8) end
  local tokens = opts.tokens or string.char(0x3F) -- newline / empty-ish
  local prog_len = #tokens
  local var_data = string.char(prog_len % 256, math.floor(prog_len / 256) % 256) .. tokens
  local var_len = #var_data
  local name_pad = name .. string.rep("\0", 8 - #name)

  local entry = string.char(0x0D, 0x00)
    .. string.char(var_len % 256, math.floor(var_len / 256) % 256)
    .. string.char(TYPE_PROG)
    .. name_pad
    .. string.char(0x00, 0x00) -- ver, flag
    .. string.char(var_len % 256, math.floor(var_len / 256) % 256)
    .. var_data

  local data_section_len = #entry
  local comment = (opts.comment or "eightxp test") .. string.rep("\0", 42)
  comment = comment:sub(1, 42)
  local hdr = "**TI83F*" -- 8
    .. string.char(0x1A, 0x0A, 0x00) -- 3 -> 11
    .. comment -- 42 -> 53
    .. string.char(data_section_len % 256, math.floor(data_section_len / 256) % 256) -- 55
  assert(#hdr == 55)

  local body = hdr .. entry
  local sum = 0
  for i = 56, #body do
    sum = sum + body:byte(i)
  end
  return body .. string.char(sum % 256, math.floor(sum / 256) % 256)
end

--- Build a synthetic multi-program .8xg-style file for tests.
function Eightxp.make_synthetic_group(opts)
  opts = opts or {}
  local names = opts.names or { "PROG1", "PROG2" }
  local parts = {}
  for _, name in ipairs(names) do
    if #name > 8 then name = name:sub(1, 8) end
    local tokens = string.char(0x3F)
    local var_data = string.char(#tokens % 256, 0) .. tokens
    local var_len = #var_data
    local name_pad = name .. string.rep("\0", 8 - #name)
    parts[#parts + 1] = string.char(0x0D, 0x00)
      .. string.char(var_len % 256, math.floor(var_len / 256) % 256)
      .. string.char(TYPE_PROG)
      .. name_pad
      .. string.char(0x00, 0x00)
      .. string.char(var_len % 256, math.floor(var_len / 256) % 256)
      .. var_data
  end
  local entry = table.concat(parts)
  local comment = (opts.comment or "grouped test") .. string.rep("\0", 42)
  comment = comment:sub(1, 42)
  local hdr = "**TI83F*"
    .. string.char(0x1A, 0x0A, 0x00)
    .. comment
    .. string.char(#entry % 256, math.floor(#entry / 256) % 256)
  local body = hdr .. entry
  local sum = 0
  for i = 56, #body do
    sum = sum + body:byte(i)
  end
  return body .. string.char(sum % 256, math.floor(sum / 256) % 256)
end

Eightxp.TYPE_PROG = TYPE_PROG
Eightxp.TYPE_PROT_PROG = TYPE_PROT_PROG
Eightxp.PROG_PTR = PROG_PTR
Eightxp.USER_MEM = USER_MEM

return Eightxp
