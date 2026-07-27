-- Z80 disassembler targeting our assembler dialect (asm/assembler.lua).
-- Recursive code discovery + db/ds for data; byte-identical round-trip.

local Disasm = {}

local R8 = { "b", "c", "d", "e", "h", "l", "(hl)", "a" }
local RP = { "bc", "de", "hl", "sp" }
local RP2 = { "bc", "de", "hl", "af" }
local CC = { "nz", "z", "nc", "c", "po", "pe", "p", "m" }
local CC_JR = { "nz", "z", "nc", "c" }

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

local function s8(n)
  n = u8(n)
  return n >= 128 and (n - 256) or n
end

local function hex8(n)
  return string.format("0x%02X", u8(n))
end

local function hex16(n)
  return string.format("0x%04X", u16(n))
end

local function auto_label(addr)
  return string.format("L_%04X", u16(addr))
end

--- Pick a nicer symbol when several share one address.
local function prefer_name(a, b)
  if not a then return b end
  if not b then return a end
  -- Prefer non-loop body aliases when both exist.
  local a_loop = a:match("._loop$") or a:match("._row$") or a:match("._col$")
  local b_loop = b:match("._loop$") or b:match("._row$") or b:match("._col$")
  if a_loop and not b_loop then return b end
  if b_loop and not a_loop then return a end
  if #a ~= #b then return (#a < #b) and a or b end
  return (a < b) and a or b
end

--- Port/constant EQU (must not become a code label at that address).
local function is_equ_symbol(name, val)
  val = u16(val)
  if val >= 0x100 then return false end
  if name:match("_CMD$") or name:match("_DATA$") or name:match("^LCD_") then
    return true
  end
  -- All-caps short constants are treated as EQU, not locations.
  if name:match("^[A-Z][A-Z0-9_]*$") and #name >= 2 then
    return true
  end
  return false
end

--- Build addr->name (locations) and name->val (EQU) from { name = value }.
function Disasm.index_symbols(symbols)
  local by_addr = {}
  local equ = {} -- name -> value
  local equ_by_val = {} -- value -> name (for ports)
  if not symbols then return by_addr, equ, equ_by_val end
  for name, val in pairs(symbols) do
    if type(name) == "string" and type(val) == "number" then
      local a = u16(val)
      if is_equ_symbol(name, a) then
        equ[name] = a
        equ_by_val[a] = prefer_name(equ_by_val[a], name)
      else
        by_addr[a] = prefer_name(by_addr[a], name)
      end
    end
  end
  return by_addr, equ, equ_by_val
end

local function make_fmt(by_addr, equ_by_val, size, is_code, code_at, label_prefix, window_lo, window_hi)
  size = size or 0x10000
  label_prefix = label_prefix or ""
  window_lo = window_lo or 0
  window_hi = window_hi or size
  local function in_image(addr)
    return addr >= window_lo and addr < window_hi
  end
  local function lab(addr)
    addr = u16(addr)
    if by_addr[addr] then return by_addr[addr] end
    -- Targets outside this bank window / image stay numeric.
    if not in_image(addr) then return hex16(addr) end
    -- Branch into the middle of an already-decoded insn -> absolute, not a label.
    if is_code and is_code[addr] and code_at and not code_at[addr] then
      return hex16(addr)
    end
    return label_prefix .. auto_label(addr)
  end
  local function imm16(n)
    n = u16(n)
    if by_addr[n] then return by_addr[n] end
    -- Keep relocatable window addresses as labels when known, else hex.
    if in_image(n) and (is_code and is_code[n] or by_addr[n]) then
      return lab(n)
    end
    return hex16(n)
  end
  local function port8(n)
    n = u8(n)
    if equ_by_val and equ_by_val[n] then return equ_by_val[n] end
    return hex8(n)
  end
  return { lab = lab, imm16 = imm16, port8 = port8, by_addr = by_addr }
end

--- Decode one instruction at `addr`.
-- fmt (optional): { lab, imm16, port8 } for name recovery
-- @return table|nil { size, text, fallthrough, branch, call }
function Disasm.decode(read8, addr, fmt)
  addr = u16(addr)
  fmt = fmt or make_fmt({})
  local lab, imm16, port8 = fmt.lab, fmt.imm16, fmt.port8

  local function b(off)
    return u8(read8(u16(addr + off)))
  end

  local op = b(0)

  local function ok(size, text, opts)
    opts = opts or {}
    local fall = opts.fallthrough
    if fall == nil and not opts.no_fallthrough then
      fall = u16(addr + size)
    end
    return {
      size = size,
      text = text,
      fallthrough = fall,
      branch = opts.branch,
      call = opts.call or false,
      ret = opts.ret or false,
      out_port = opts.out_port,
      in_port = opts.in_port,
      ld_a = opts.ld_a,
      and_imm = opts.and_imm,
      or_imm = opts.or_imm,
      bit_y = opts.bit_y,
      bit_reg = opts.bit_reg,
      cp_imm = opts.cp_imm,
    }
  end

  if op == 0x00 then return ok(1, "nop")
  elseif op == 0x08 then return ok(1, "ex af,af'")
  elseif op == 0x07 then return ok(1, "rlca")
  elseif op == 0x0F then return ok(1, "rrca")
  elseif op == 0x17 then return ok(1, "rla")
  elseif op == 0x1F then return ok(1, "rra")
  elseif op == 0x27 then return ok(1, "daa")
  elseif op == 0x2F then return ok(1, "cpl")
  elseif op == 0x37 then return ok(1, "scf")
  elseif op == 0x3F then return ok(1, "ccf")
  elseif op == 0x76 then return ok(1, "halt")
  elseif op == 0xD9 then return ok(1, "exx")
  elseif op == 0xE3 then return ok(1, "ex (sp),hl")
  elseif op == 0xEB then return ok(1, "ex de,hl")
  elseif op == 0xF3 then return ok(1, "di")
  elseif op == 0xFB then return ok(1, "ei")
  elseif op == 0xE9 then return ok(1, "jp (hl)", { no_fallthrough = true })
  elseif op == 0xF9 then return ok(1, "ld sp,hl")
  elseif op == 0xC9 then return ok(1, "ret", { no_fallthrough = true, ret = true })
  end

  if op == 0x10 then
    local t = u16(addr + 2 + s8(b(1)))
    return ok(2, "djnz " .. lab(t), { branch = t })
  end
  if op == 0x18 then
    local t = u16(addr + 2 + s8(b(1)))
    return ok(2, "jr " .. lab(t), { branch = t, no_fallthrough = true })
  end
  if op >= 0x20 and op <= 0x38 and (op % 8) == 0 then
    local cc = CC_JR[math.floor((op - 0x20) / 8) + 1]
    local t = u16(addr + 2 + s8(b(1)))
    return ok(2, "jr " .. cc .. "," .. lab(t), { branch = t })
  end

  if (op % 16) == 0x01 and op <= 0x31 then
    local r = RP[math.floor(op / 16) + 1]
    local n = b(1) + b(2) * 256
    return ok(3, "ld " .. r .. "," .. imm16(n))
  end
  if (op % 16) == 0x09 and op <= 0x39 then
    return ok(1, "add hl," .. RP[math.floor(op / 16) + 1])
  end
  if (op % 16) == 0x03 and op <= 0x33 then
    return ok(1, "inc " .. RP[math.floor(op / 16) + 1])
  end
  if (op % 16) == 0x0B and op <= 0x3B then
    return ok(1, "dec " .. RP[math.floor(op / 16) + 1])
  end
  if op == 0x02 then return ok(1, "ld (bc),a")
  elseif op == 0x0A then return ok(1, "ld a,(bc)")
  elseif op == 0x12 then return ok(1, "ld (de),a")
  elseif op == 0x1A then return ok(1, "ld a,(de)")
  elseif op == 0x22 then
    local n = b(1) + b(2) * 256
    return ok(3, "ld (" .. imm16(n) .. "),hl")
  elseif op == 0x2A then
    local n = b(1) + b(2) * 256
    return ok(3, "ld hl,(" .. imm16(n) .. ")")
  elseif op == 0x32 then
    local n = b(1) + b(2) * 256
    return ok(3, "ld (" .. imm16(n) .. "),a")
  elseif op == 0x3A then
    local n = b(1) + b(2) * 256
    return ok(3, "ld a,(" .. imm16(n) .. ")")
  end

  if (op % 8) == 0x04 and op < 0x40 then
    return ok(1, "inc " .. R8[math.floor(op / 8) + 1])
  end
  if (op % 8) == 0x05 and op < 0x40 then
    return ok(1, "dec " .. R8[math.floor(op / 8) + 1])
  end
  if (op % 8) == 0x06 and op < 0x40 then
    local r = R8[math.floor(op / 8) + 1]
    local n = b(1)
    return ok(2, "ld " .. r .. "," .. hex8(n), r == "a" and { ld_a = n } or nil)
  end

  if op >= 0x40 and op <= 0x7F and op ~= 0x76 then
    local d = R8[math.floor((op - 0x40) / 8) + 1]
    local s = R8[(op % 8) + 1]
    return ok(1, "ld " .. d .. "," .. s)
  end

  local ALU = { "add a,", "adc a,", "sub ", "sbc a,", "and ", "xor ", "or ", "cp " }
  if op >= 0x80 and op <= 0xBF then
    return ok(1, ALU[math.floor((op - 0x80) / 8) + 1] .. R8[(op % 8) + 1])
  end
  if op == 0xC6 then return ok(2, "add a," .. hex8(b(1)))
  elseif op == 0xCE then return ok(2, "adc a," .. hex8(b(1)))
  elseif op == 0xD6 then return ok(2, "sub " .. hex8(b(1)))
  elseif op == 0xDE then return ok(2, "sbc a," .. hex8(b(1)))
  elseif op == 0xE6 then
    local n = b(1)
    return ok(2, "and " .. hex8(n), { and_imm = n })
  elseif op == 0xEE then return ok(2, "xor " .. hex8(b(1)))
  elseif op == 0xF6 then
    local n = b(1)
    return ok(2, "or " .. hex8(n), { or_imm = n })
  elseif op == 0xFE then
    local n = b(1)
    return ok(2, "cp " .. hex8(n), { cp_imm = n })
  end

  if (op % 8) == 0x00 and op >= 0xC0 and op <= 0xF8 then
    return ok(1, "ret " .. CC[math.floor((op - 0xC0) / 8) + 1], { ret = true })
  end
  if (op % 16) == 0x01 and op >= 0xC1 and op <= 0xF1 then
    return ok(1, "pop " .. RP2[math.floor((op - 0xC1) / 16) + 1])
  end
  if (op % 16) == 0x05 and op >= 0xC5 and op <= 0xF5 then
    return ok(1, "push " .. RP2[math.floor((op - 0xC5) / 16) + 1])
  end
  if op == 0xC3 then
    local t = b(1) + b(2) * 256
    return ok(3, "jp " .. lab(t), { branch = t, no_fallthrough = true })
  end
  if (op % 8) == 0x02 and op >= 0xC2 and op <= 0xFA then
    local cc = CC[math.floor((op - 0xC2) / 8) + 1]
    local t = b(1) + b(2) * 256
    return ok(3, "jp " .. cc .. "," .. lab(t), { branch = t })
  end
  if op == 0xCD then
    local t = b(1) + b(2) * 256
    return ok(3, "call " .. lab(t), { branch = t, call = true })
  end
  if (op % 8) == 0x04 and op >= 0xC4 and op <= 0xFC then
    local cc = CC[math.floor((op - 0xC4) / 8) + 1]
    local t = b(1) + b(2) * 256
    return ok(3, "call " .. cc .. "," .. lab(t), { branch = t, call = true })
  end
  if (op % 8) == 0x07 and op >= 0xC7 then
    local n = op - 0xC7
    return ok(1, "rst " .. hex8(n), { branch = n, call = true })
  end

  if op == 0xD3 then
    local p = b(1)
    return ok(2, "out (" .. port8(p) .. "),a", { out_port = p })
  elseif op == 0xDB then
    local p = b(1)
    return ok(2, "in a,(" .. port8(p) .. ")", { in_port = p })
  end

  if op == 0xCB then
    local cb = b(1)
    local x = math.floor(cb / 64)
    local y = math.floor(cb / 8) % 8
    local z = cb % 8
    local r = R8[z + 1]
    if x == 0 then
      local rot = ({ "rlc", "rrc", "rl", "rr", "sla", "sra", "sll", "srl" })[y + 1]
      return ok(2, rot .. " " .. r)
    elseif x == 1 then
      return ok(2, "bit " .. y .. "," .. r, { bit_y = y, bit_reg = r })
    elseif x == 2 then
      return ok(2, "res " .. y .. "," .. r)
    else
      return ok(2, "set " .. y .. "," .. r)
    end
  end

  if op == 0xED then
    local ed = b(1)
    if ed == 0x44 then return ok(2, "neg")
    elseif ed == 0x45 then return ok(2, "retn", { no_fallthrough = true, ret = true })
    elseif ed == 0x4D then return ok(2, "reti", { no_fallthrough = true, ret = true })
    elseif ed == 0x46 then return ok(2, "im 0")
    elseif ed == 0x56 then return ok(2, "im 1")
    elseif ed == 0x5E then return ok(2, "im 2")
    elseif ed == 0x67 then return ok(2, "rrd")
    elseif ed == 0x6F then return ok(2, "rld")
    elseif ed == 0xA0 then return ok(2, "ldi")
    elseif ed == 0xA8 then return ok(2, "ldd")
    elseif ed == 0xB0 then return ok(2, "ldir")
    elseif ed == 0xB8 then return ok(2, "lddr")
    elseif ed == 0xA1 then return ok(2, "cpi")
    elseif ed == 0xA9 then return ok(2, "cpd")
    elseif ed == 0xB1 then return ok(2, "cpir")
    elseif ed == 0xB9 then return ok(2, "cpdr")
    elseif ed == 0xA2 then return ok(2, "ini")
    elseif ed == 0xAA then return ok(2, "ind")
    elseif ed == 0xB2 then return ok(2, "inir")
    elseif ed == 0xBA then return ok(2, "indr")
    elseif ed == 0xA3 then return ok(2, "outi")
    elseif ed == 0xAB then return ok(2, "outd")
    elseif ed == 0xB3 then return ok(2, "otir")
    elseif ed == 0xBB then return ok(2, "otdr")
    end
    if ed == 0x47 then return ok(2, "ld i,a")
    elseif ed == 0x4F then return ok(2, "ld r,a")
    elseif ed == 0x57 then return ok(2, "ld a,i")
    elseif ed == 0x5F then return ok(2, "ld a,r")
    end
    -- ED 42/52/62/72 = sbc hl,rp ; ED 4A/5A/6A/7A = adc hl,rp
    if ed >= 0x42 and ed <= 0x72 and ((ed - 0x42) % 16) == 0 then
      return ok(2, "sbc hl," .. RP[math.floor((ed - 0x42) / 16) + 1])
    end
    if ed >= 0x4A and ed <= 0x7A and ((ed - 0x4A) % 16) == 0 then
      return ok(2, "adc hl," .. RP[math.floor((ed - 0x4A) / 16) + 1])
    end
    if ed == 0x43 then
      local n = b(2) + b(3) * 256
      return ok(4, "ld (" .. imm16(n) .. "),bc")
    elseif ed == 0x53 then
      local n = b(2) + b(3) * 256
      return ok(4, "ld (" .. imm16(n) .. "),de")
    elseif ed == 0x73 then
      local n = b(2) + b(3) * 256
      return ok(4, "ld (" .. imm16(n) .. "),sp")
    elseif ed == 0x4B then
      local n = b(2) + b(3) * 256
      return ok(4, "ld bc,(" .. imm16(n) .. ")")
    elseif ed == 0x5B then
      local n = b(2) + b(3) * 256
      return ok(4, "ld de,(" .. imm16(n) .. ")")
    elseif ed == 0x7B then
      local n = b(2) + b(3) * 256
      return ok(4, "ld sp,(" .. imm16(n) .. ")")
    end
    -- IN r,(c) / OUT (c),r  (ED 40+8*r / ED 41+8*r); IN (c)=ED70; OUT (c),0=ED71
    if ed >= 0x40 and ed <= 0x79 then
      local y = math.floor((ed - 0x40) / 8)
      local z = (ed - 0x40) % 8
      if z == 0 and y <= 7 then
        if y == 6 then return ok(2, "in (c)") end
        return ok(2, "in " .. R8[y + 1] .. ",(c)")
      elseif z == 1 and y <= 7 then
        if y == 6 then return ok(2, "out (c),0") end
        return ok(2, "out (c)," .. R8[y + 1])
      end
    end
    -- Unknown ED xx: keep both bytes as data (second byte is not a standalone op).
    return ok(2, "db " .. hex8(op) .. "," .. hex8(ed))
  end

  if op == 0xDD or op == 0xFD then
    local xy = op == 0xDD and "ix" or "iy"
    local function idx(d)
      local sd = s8(d)
      if sd == 0 then return "(" .. xy .. ")" end
      if sd > 0 then return string.format("(%s+0x%02X)", xy, sd) end
      return string.format("(%s-0x%02X)", xy, -sd)
    end
    local function half(i)
      if i == 4 then return xy .. "h" end
      if i == 5 then return xy .. "l" end
      return R8[i + 1]
    end
    local op2 = b(1)

    -- DD CB d op / FD CB d op
    if op2 == 0xCB then
      local d = b(2)
      local cb = b(3)
      local x = math.floor(cb / 64)
      local y = math.floor(cb / 8) % 8
      local z = cb % 8
      local mem = idx(d)
      if x == 0 then
        local rot = ({ "rlc", "rrc", "rl", "rr", "sla", "sra", "sll", "srl" })[y + 1]
        -- Prefer memory form (TI-OS style); z!=6 is undocumented writeback
        return ok(4, rot .. " " .. mem)
      elseif x == 1 then
        return ok(4, "bit " .. y .. "," .. mem, { bit_y = y })
      elseif x == 2 then
        return ok(4, "res " .. y .. "," .. mem)
      else
        return ok(4, "set " .. y .. "," .. mem)
      end
    end

    -- add xy,rp
    if op2 == 0x09 then return ok(2, "add " .. xy .. ",bc")
    elseif op2 == 0x19 then return ok(2, "add " .. xy .. ",de")
    elseif op2 == 0x29 then return ok(2, "add " .. xy .. "," .. xy)
    elseif op2 == 0x39 then return ok(2, "add " .. xy .. ",sp")
    end

    if op2 == 0x21 then
      local n = b(2) + b(3) * 256
      return ok(4, "ld " .. xy .. "," .. imm16(n))
    elseif op2 == 0x22 then
      local n = b(2) + b(3) * 256
      return ok(4, "ld (" .. imm16(n) .. ")," .. xy)
    elseif op2 == 0x2A then
      local n = b(2) + b(3) * 256
      return ok(4, "ld " .. xy .. ",(" .. imm16(n) .. ")")
    elseif op2 == 0x23 then return ok(2, "inc " .. xy)
    elseif op2 == 0x2B then return ok(2, "dec " .. xy)
    elseif op2 == 0x24 then return ok(2, "inc " .. xy .. "h")
    elseif op2 == 0x25 then return ok(2, "dec " .. xy .. "h")
    elseif op2 == 0x26 then return ok(3, "ld " .. xy .. "h," .. hex8(b(2)))
    elseif op2 == 0x2C then return ok(2, "inc " .. xy .. "l")
    elseif op2 == 0x2D then return ok(2, "dec " .. xy .. "l")
    elseif op2 == 0x2E then return ok(3, "ld " .. xy .. "l," .. hex8(b(2)))
    elseif op2 == 0x34 then return ok(3, "inc " .. idx(b(2)))
    elseif op2 == 0x35 then return ok(3, "dec " .. idx(b(2)))
    elseif op2 == 0x36 then return ok(4, "ld " .. idx(b(2)) .. "," .. hex8(b(3)))
    elseif op2 == 0xE1 then return ok(2, "pop " .. xy)
    elseif op2 == 0xE5 then return ok(2, "push " .. xy)
    elseif op2 == 0xE3 then return ok(2, "ex (sp)," .. xy)
    elseif op2 == 0xE9 then return ok(2, "jp (" .. xy .. ")", { no_fallthrough = true })
    elseif op2 == 0xF9 then return ok(2, "ld sp," .. xy)
    end

    -- ld r,(xy+d) / ld (xy+d),r / ld r,xyh (undocumented)
    if op2 >= 0x40 and op2 <= 0x7F and op2 ~= 0x76 then
      local dst = math.floor((op2 - 0x40) / 8)
      local src = op2 % 8
      if src == 6 then
        local dest = (dst == 4 or dst == 5) and half(dst) or R8[dst + 1]
        return ok(3, "ld " .. dest .. "," .. idx(b(2)))
      elseif dst == 6 then
        local srcn = (src == 4 or src == 5) and half(src) or R8[src + 1]
        return ok(3, "ld " .. idx(b(2)) .. "," .. srcn)
      elseif dst == 4 or dst == 5 or src == 4 or src == 5 then
        return ok(2, "ld " .. half(dst) .. "," .. half(src))
      end
      -- Redundant DD/FD before plain ld r,r - peel prefix, continue.
      return ok(1, "db " .. hex8(op))
    end

    -- ALU A,(xy+d)
    local alu_mem = {
      [0x86] = "add a,", [0x8E] = "adc a,", [0x96] = "sub ", [0x9E] = "sbc a,",
      [0xA6] = "and ", [0xAE] = "xor ", [0xB6] = "or ", [0xBE] = "cp ",
    }
    if alu_mem[op2] then
      return ok(3, alu_mem[op2] .. idx(b(2)))
    end
    -- ALU A,xyh/xyl
    if op2 >= 0x80 and op2 <= 0xBF then
      local y = math.floor((op2 - 0x80) / 8)
      local z = op2 % 8
      if z == 4 or z == 5 then
        local name = ({ "add a,", "adc a,", "sub ", "sbc a,", "and ", "xor ", "or ", "cp " })[y + 1]
        return ok(2, name .. half(z))
      end
    end

    -- Unknown/redundant IX/IY prefix - peel one byte so discovery continues.
    return ok(1, "db " .. hex8(op))
  end

  return nil
end

local function is_pad_or_text_byte(c)
  return c == 0xFF
    or (c >= 0x30 and c <= 0x39)
    or (c >= 0x41 and c <= 0x5A)
    or (c >= 0x61 and c <= 0x7A)
    or c == 0x20 or c == 0x21 or c == 0x2C or c == 0x2E
    or c == 0x3F or c == 0x2D or c == 0x5F or c == 0x27
end

--- Mark obvious padding / C-strings so linear sweep does not eat them as code.
local function mark_force_data(read8, size)
  local force = {}
  local i = 0
  while i < size do
    local c = read8(i)
    if c == 0 then
      local j = i
      while j < size and read8(j) == 0 do
        j = j + 1
      end
      if j - i >= 8 then
        for k = i, j - 1 do force[k] = true end
      end
      i = j
    elseif c == 0xFF then
      local j = i
      while j < size and read8(j) == 0xFF do
        j = j + 1
      end
      if j - i >= 2 then
        for k = i, j - 1 do force[k] = true end
      end
      i = j
    elseif is_pad_or_text_byte(c) and c ~= 0xFF then
      local j = i
      while j < size and is_pad_or_text_byte(read8(j)) and read8(j) ~= 0xFF do
        j = j + 1
      end
      if j - i >= 3 and j < size and read8(j) == 0 then
        for k = i, j do force[k] = true end
        i = j + 1
      else
        i = i + 1
      end
    else
      i = i + 1
    end
  end
  return force
end

--- Discover code in [0, size). Optional opts:
--   window_lo, window_hi - only treat this CPU range as this image (bank window).
function Disasm.discover_code(read8, seeds, size, opts)
  opts = opts or {}
  local win_lo = opts.window_lo or 0
  local win_hi = opts.window_hi or size
  if win_lo < 0 then win_lo = 0 end
  if win_hi > size then win_hi = size end

  local code_at = {}
  local is_code = {}
  local labels = {}
  local call_targets = {}
  local queue = {}
  -- force_data only inside the window (mark_force_data is 0..size based)
  local force_data = mark_force_data(read8, size)

  local function in_window(a)
    return a >= win_lo and a < win_hi
  end

  local function enqueue(a)
    a = u16(a)
    if not in_window(a) then return end
    if force_data[a] then return end
    if code_at[a] or is_code[a] then return end
    queue[#queue + 1] = a
  end

  local function accept(a)
    if not in_window(a) or force_data[a] or code_at[a] or is_code[a] then
      return false
    end
    local insn = Disasm.decode(read8, a)
    if not insn or a + insn.size > win_hi then return false end
    for i = 0, insn.size - 1 do
      if is_code[a + i] or force_data[a + i] then return false end
    end
    code_at[a] = insn
    for i = 0, insn.size - 1 do
      is_code[a + i] = true
    end
    if insn.branch then
      local t = u16(insn.branch)
      if in_window(t) then
        labels[t] = true
      end
      if insn.call and in_window(t) then
        call_targets[t] = true
      end
      enqueue(insn.branch)
    end
    if insn.fallthrough then
      enqueue(insn.fallthrough)
    end
    return true
  end

  local function drain()
    local qi = 1
    while qi <= #queue do
      local a = queue[qi]
      qi = qi + 1
      accept(a)
    end
  end

  for _, s in ipairs(seeds) do
    local a = u16(s)
    if in_window(a) then
      labels[a] = true
      enqueue(a)
    end
  end
  drain()

  -- Linear sweep inside the window only.
  local addr = win_lo
  while addr < win_hi do
    if is_code[addr] or force_data[addr] then
      addr = addr + 1
    elseif accept(addr) then
      drain()
      addr = addr + (code_at[addr] and code_at[addr].size or 1)
    else
      addr = addr + 1
    end
  end

  return code_at, is_code, labels, call_targets
end

-- Tight charset so font glyphs (printable bytes + 0x00 pad) are not quoted.
local function is_text_char(c)
  return (c >= 0x30 and c <= 0x39) -- 0-9
    or (c >= 0x41 and c <= 0x5A) -- A-Z
    or (c >= 0x61 and c <= 0x7A) -- a-z
    or c == 0x20 or c == 0x21 or c == 0x2C or c == 0x2E -- space ! , .
    or c == 0x3F or c == 0x2D or c == 0x5F or c == 0x27 -- ? - _ '
end

local function emit_label(lines, addr, label_at, name_of)
  if label_at[addr] then
    lines[#lines + 1] = name_of(addr) .. ":"
  end
end

local function try_string(read8, i, to, label_at, name_of)
  if not is_text_char(read8(i)) then return nil end
  local j = i
  local chars = {}
  while j < to and is_text_char(read8(j)) do
    if j > i and label_at[j] then return nil end
    chars[#chars + 1] = string.char(read8(j))
    j = j + 1
  end
  if #chars < 3 or j >= to or read8(j) ~= 0 or label_at[j] then
    return nil
  end
  return j + 1, '    db "' .. table.concat(chars) .. '",0'
end

--- Emit data [from, to) with labels, quoted C-strings, and ds for zero runs.
local function emit_data(lines, read8, from, to, label_at, name_of)
  local i = from
  while i < to do
    emit_label(lines, i, label_at, name_of)

    local next_i, str_line = try_string(read8, i, to, label_at, name_of)
    if next_i then
      lines[#lines + 1] = str_line
      i = next_i
    elseif read8(i) == 0 then
      local j = i
      while j < to and read8(j) == 0 and not (j > i and label_at[j]) do
        j = j + 1
      end
      local n = j - i
      if n >= 8 then
        lines[#lines + 1] = "    ds " .. tostring(n)
        i = j
      else
        local chunk = {}
        for _ = i, j - 1 do
          chunk[#chunk + 1] = hex8(0)
        end
        lines[#lines + 1] = "    db " .. table.concat(chunk, ",")
        i = j
      end
    else
      local chunk = {}
      local j = i
      while j < to and #chunk < 16 do
        if j > i and label_at[j] then break end
        if read8(j) == 0 then
          local z = j
          while z < to and read8(z) == 0 and not label_at[z] do
            z = z + 1
          end
          if (z - j) >= 8 then break end
        end
        if j > i then
          local _, peek = try_string(read8, j, to, label_at, name_of)
          if peek then break end
        end
        chunk[#chunk + 1] = hex8(read8(j))
        j = j + 1
      end
      if #chunk == 0 then
        lines[#lines + 1] = "    db " .. hex8(read8(i))
        i = i + 1
      else
        lines[#lines + 1] = "    db " .. table.concat(chunk, ",")
        i = j
      end
    end
  end
end

--- Disassemble a byte region into assembler source.
-- opts:
--   size      bytes to cover (required)
--   seeds     entry points (default {0, 0x38})
--   org       starting org (default 0)
--   symbols   { name = addr_or_value } from assembler (name recovery)
function Disasm.disassemble(read8, opts)
  opts = opts or {}
  local size = opts.size or 0x4000
  local seeds = opts.seeds or { 0x0000, 0x0038 }
  local base_org = opts.org or 0
  local label_prefix = opts.label_prefix or ""
  local skip_header = opts.skip_header == true
  local skip_equ = opts.skip_equ == true
  local header_comment = opts.header_comment
  local window_lo = opts.window_lo or 0
  local window_hi = opts.window_hi or size
  local by_addr, equ, equ_by_val = Disasm.index_symbols(opts.symbols)
  -- Prefix location symbols (not EQU) for multi-page flat listings.
  if label_prefix ~= "" then
    local prefixed = {}
    for addr, name in pairs(by_addr) do
      if name:sub(1, #label_prefix) ~= label_prefix then
        prefixed[addr] = label_prefix .. name
      else
        prefixed[addr] = name
      end
    end
    by_addr = prefixed
  end
  local code_at, is_code, labels = Disasm.discover_code(read8, seeds, size, {
    window_lo = window_lo,
    window_hi = window_hi,
  })
  local fmt = make_fmt(
    by_addr, equ_by_val, size, is_code, code_at, label_prefix, window_lo, window_hi
  )

  -- Location symbols become labels (EQU ports stay out of by_addr).
  for addr, _ in pairs(by_addr) do
    if addr >= window_lo and addr < window_hi then
      labels[addr] = true
    end
  end

  local function name_of(addr)
    return fmt.lab(addr)
  end

  -- Re-decode code with names for emission text
  for addr, insn in pairs(code_at) do
    local named = Disasm.decode(read8, addr, fmt)
    if named then
      insn.text = named.text
    end
  end

  local lines = {}
  if not skip_header then
    lines[#lines + 1] = "; disassembled automatically - round-trip with asm/assembler.lua"
  end
  if header_comment then
    lines[#lines + 1] = header_comment
  end
  local emit_org = base_org
  if opts.org == nil and window_lo > 0 then
    emit_org = window_lo
  end
  if not opts.skip_org then
    lines[#lines + 1] = string.format("    org %s", hex16(emit_org))
  end

  -- Emit EQU lines for port/constant symbols
  if not skip_equ then
    local equs = {}
    for name, val in pairs(equ) do
      equs[#equs + 1] = { name = name, val = val }
    end
    table.sort(equs, function(a, b) return a.val < b.val or (a.val == b.val and a.name < b.name) end)
    for _, e in ipairs(equs) do
      lines[#lines + 1] = string.format("%s: equ %s", e.name, hex8(e.val))
    end
    if #equs > 0 then
      lines[#lines + 1] = ""
    end
  end

  local label_at = {}
  for a, v in pairs(labels) do
    -- Skip labels that land mid-instruction (would be unassemblable).
    if v and a >= window_lo and a < window_hi and (code_at[a] or not is_code[a]) then
      label_at[a] = true
    end
  end

  local addr = window_lo
  while addr < window_hi do
    -- org over long zero gaps with no labels
    if not is_code[addr] and read8(addr) == 0 and not label_at[addr] then
      local gap_end = addr
      while gap_end < window_hi and not is_code[gap_end] and read8(gap_end) == 0 and not label_at[gap_end] do
        gap_end = gap_end + 1
      end
      if gap_end > addr + 3 and (label_at[gap_end] or is_code[gap_end] or gap_end >= window_hi) then
        if gap_end < window_hi then
          lines[#lines + 1] = string.format("    org %s", hex16(gap_end))
        end
        addr = gap_end
      end
    end

    if addr >= window_hi then break end

    if code_at[addr] then
      if label_at[addr] then
        lines[#lines + 1] = name_of(addr) .. ":"
      end
      lines[#lines + 1] = "    " .. code_at[addr].text
      addr = addr + code_at[addr].size
    else
      local run_end = addr
      while run_end < window_hi and not is_code[run_end] do
        run_end = run_end + 1
      end
      local z = addr
      while z < run_end and read8(z) == 0 and not label_at[z] do
        z = z + 1
      end
      if z == run_end and (run_end - addr) > 3 then
        if run_end < window_hi then
          lines[#lines + 1] = string.format("    org %s", hex16(run_end))
        end
        addr = run_end
      else
        emit_data(lines, read8, addr, run_end, label_at, name_of)
        addr = run_end
      end
    end
  end

  lines[#lines + 1] = ""
  return table.concat(lines, "\n"), {
    code_at = code_at,
    labels = labels,
    names = by_addr,
    size = size,
    is_code = is_code,
    window_lo = window_lo,
    window_hi = window_hi,
  }
end

function Disasm.disassemble_bytes(bytes, opts)
  opts = opts or {}
  local size = opts.size
  local read8
  if type(bytes) == "string" then
    size = size or #bytes
    read8 = function(addr)
      if addr < 0 or addr >= size then return 0 end
      return bytes:byte(addr + 1) or 0
    end
  else
    size = size or 0
    if not opts.size then
      local max = 0
      for k in pairs(bytes) do
        if type(k) == "number" and k >= max then max = k + 1 end
      end
      size = max
    end
    read8 = function(addr)
      return u8(bytes[addr] or 0)
    end
  end
  opts.size = size
  return Disasm.disassemble(read8, opts)
end

--- Load a simple symbol map file: "NAME HEXADDR" or "HEXADDR NAME" per line.
function Disasm.load_map_file(path)
  local f, err = io.open(path, "r")
  if not f then return nil, err end
  local symbols = {}
  for line in f:lines() do
    line = line:match("^([^;]*)") or line
    line = line:gsub("^%s+", ""):gsub("%s+$", "")
    if line ~= "" then
      local n, a = line:match("^([%w_%.]+)%s+[Dd]?%s*(0x%x+)$")
      if not n then n, a = line:match("^([%w_%.]+)%s+(%$%x+)$") end
      if not n then n, a = line:match("^([%w_%.]+)%s+(%x+)$") end
      if not n then
        a, n = line:match("^(0x%x+)%s+([%w_%.]+)$")
      end
      if n and a then
        if a:sub(1, 1) == "$" then a = "0x" .. a:sub(2) end
        if not a:match("^0[xX]") then a = "0x" .. a end
        symbols[n] = tonumber(a)
      end
    end
  end
  f:close()
  return symbols
end

return Disasm
