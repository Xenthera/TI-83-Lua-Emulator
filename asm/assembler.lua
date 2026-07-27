-- Minimal two-pass Z80 assembler for pipeline tests.
-- Supports: labels, ORG/EQU/DB/DW/DS/INCLUDE, common instructions.

local Assembler = {}

local REG8 = { b = 0, c = 1, d = 2, e = 3, h = 4, l = 5, ["(hl)"] = 6, a = 7 }
local RP = { bc = 0, de = 1, hl = 2, sp = 3 }
local RP2 = { bc = 0, de = 1, hl = 2, af = 3 }
local CC = { nz = 0, z = 1, nc = 2, c = 3, po = 4, pe = 5, p = 6, m = 7 }

local function trim(s)
  return (s:gsub("^%s+", ""):gsub("%s+$", ""))
end

local function strip_comment(line)
  local in_str = false
  for i = 1, #line do
    local ch = line:sub(i, i)
    if ch == '"' then
      in_str = not in_str
    elseif ch == ";" and not in_str then
      return trim(line:sub(1, i - 1))
    end
  end
  return trim(line)
end

local function parse_number(tok, symbols, pass)
  tok = trim(tok)
  if tok == "" then
    return nil, "empty number"
  end
  local neg = false
  if tok:sub(1, 1) == "-" then
    neg = true
    tok = tok:sub(2)
  end
  local n
  if tok:match("^0[xX]%x+$") then
    n = tonumber(tok:sub(3), 16)
  elseif tok:match("^%$%x+$") then
    n = tonumber(tok:sub(2), 16)
  elseif tok:match("^%x+[hH]$") then
    n = tonumber(tok:sub(1, -2), 16)
  elseif tok:match("^%d+$") then
    n = tonumber(tok, 10)
  elseif symbols[tok] ~= nil then
    n = symbols[tok]
  else
    -- case-insensitive label / EQU lookup
    local found
    local lower = tok:lower()
    for k, v in pairs(symbols) do
      if type(k) == "string" and k:lower() == lower then
        found = v
        break
      end
    end
    if found ~= nil then
      n = found
    elseif pass == 1 then
      n = 0 -- forward ref placeholder
    else
      return nil, "unknown symbol: " .. tok
    end
  end
  if n == nil then
    return nil, "bad number: " .. tok
  end
  if neg then
    n = -n
  end
  return n
end

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

--- Parse (ix), (iy+0x12), (iy-3) -> xy ("ix"|"iy"), disp u8; or nil.
local function parse_idx_mem(tok, symbols, passno)
  local inner = tok:match("^%((.+)%)$")
  if not inner then return nil end
  inner = trim(inner)
  local low = inner:lower()
  local xy
  if low:sub(1, 2) == "ix" then xy = "ix"
  elseif low:sub(1, 2) == "iy" then xy = "iy"
  else return nil end
  local rest = trim(inner:sub(3))
  if rest == "" then return xy, 0 end
  local sign, numstr = rest:match("^([+-])%s*(.+)$")
  if not sign then return nil end
  local n, e = parse_number(numstr, symbols, passno)
  if n == nil then return nil, e end
  if sign == "-" then n = -n end
  return xy, u8(n)
end

local function xy_prefix(xy)
  return xy == "ix" and 0xDD or 0xFD
end

local function xy_half(tok)
  tok = tok:lower()
  if tok == "ixh" then return "ix", 4 end
  if tok == "ixl" then return "ix", 5 end
  if tok == "iyh" then return "iy", 4 end
  if tok == "iyl" then return "iy", 5 end
  return nil
end

local function split_args(s)
  local args, cur, depth, in_str = {}, "", 0, false
  for i = 1, #s do
    local ch = s:sub(i, i)
    if ch == '"' then
      in_str = not in_str
      cur = cur .. ch
    elseif in_str then
      cur = cur .. ch
    elseif ch == "(" then
      depth = depth + 1
      cur = cur .. ch
    elseif ch == ")" then
      depth = depth - 1
      cur = cur .. ch
    elseif ch == "," and depth == 0 then
      args[#args + 1] = trim(cur)
      cur = ""
    else
      cur = cur .. ch
    end
  end
  if trim(cur) ~= "" then
    args[#args + 1] = trim(cur)
  end
  return args
end

local function is_reg8(t)
  return REG8[t:lower()] ~= nil
end

local function emit_bytes(out, pc, ...)
  for i = 1, select("#", ...) do
    out[pc] = u8(select(i, ...))
    pc = pc + 1
  end
  return pc
end

local function assemble_file(path, opts)
  opts = opts or {}
  local root = opts.root or "."
  local symbols = opts.symbols or {}
  local symbol_pages = opts.symbol_pages or {}
  local blobs = opts.blobs or {} -- name -> array of bytes (0-255)
  local max_size = opts.max_size or 0x4000
  -- addr_base: assemble at absolute orgs (e.g. 0x4000 for Flash Apps) while
  -- storing a 0-based page image of length max_size.
  local addr_base = opts.addr_base or 0
  local multipage = opts.multipage == true
  local pages_raw = {} -- page_index -> raw byte table
  local page_sizes = {} -- page_index -> high-water size
  local cur_page = 0
  local used_page_dir = false

  local function ensure_page(p)
    if not pages_raw[p] then
      local raw = {}
      for i = 0, max_size - 1 do
        raw[i] = 0
      end
      pages_raw[p] = raw
      page_sizes[p] = 0
    end
    return pages_raw[p]
  end

  ensure_page(0)
  local raw = pages_raw[0]

  local out = setmetatable({}, {
    __index = function(_, pc)
      local idx = pc - addr_base
      if idx < 0 or idx >= max_size then
        return 0
      end
      return raw[idx]
    end,
    __newindex = function(_, pc, v)
      local idx = pc - addr_base
      if idx < 0 or idx >= max_size then
        error(string.format("address 0x%04X outside page image [0x%04X..0x%04X) (page %d)",
          pc, addr_base, addr_base + max_size, cur_page))
      end
      raw[idx] = v
      if idx + 1 > (page_sizes[cur_page] or 0) then
        page_sizes[cur_page] = idx + 1
      end
    end,
  })

  local function switch_page(p)
    cur_page = p
    raw = ensure_page(p)
  end

  local function read_lines(file, seen)
    seen = seen or {}
    local abs = file
    if not file:match("^/") and not file:match("^%a:") then
      abs = root .. "/" .. file
    end
    abs = abs:gsub("\\", "/")
    if seen[abs] then
      error("include loop: " .. abs)
    end
    seen[abs] = true
    local f, err = io.open(abs, "r")
    if not f then
      error("cannot open " .. abs .. ": " .. tostring(err))
    end
    local lines = {}
    local ln = 0
    for line in f:lines() do
      ln = ln + 1
      local s = strip_comment(line)
      if s:lower():match("^include%s+") then
        local inc = s:match('^include%s+"([^"]+)"') or s:match("^include%s+(%S+)")
        local nested = read_lines(inc, seen)
        for _, item in ipairs(nested) do
          lines[#lines + 1] = item
        end
      else
        lines[#lines + 1] = { file = abs, line = ln, text = s }
      end
    end
    f:close()
    return lines
  end

  local source = read_lines(path)

  local function pass(passno)
    local pc = 0
    for _, item in ipairs(source) do
      local s = item.text
      if s == "" then
        -- skip
      else
        local label, rest = s:match("^([%w_%.]+)%s*:%s*(.*)$")
        if label then
          if passno == 1 then
            symbols[label] = pc
            symbol_pages[label] = cur_page
          end
          s = trim(rest or "")
        end
        if s == "" then
          -- label only
        else
          local dir, darg = s:match("^%.(%w+)%s*(.*)$")
          if not dir then
            dir, darg = s:match("^(%w+)%s+(.*)$")
            local upper = dir and dir:upper()
            if upper == "ORG" or upper == "EQU" or upper == "DB" or upper == "DW"
              or upper == "DS" or upper == "BLOB" or upper == "PAGE" then
              dir = upper:lower()
            else
              dir = nil
            end
          else
            dir = dir:lower()
            darg = trim(darg or "")
          end

          if dir == "page" then
            local n, e = parse_number(trim(darg), symbols, passno)
            if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
            if n < 0 or n > 31 then
              error(item.file .. ":" .. item.line .. ": page out of range")
            end
            used_page_dir = true
            multipage = true
            switch_page(n)
            pc = addr_base
            if addr_base == 0 then
              pc = 0x4000
              addr_base = 0x4000
            end
          elseif dir == "org" then
            local n, e = parse_number(trim(darg), symbols, passno)
            if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
            pc = u16(n)
          elseif dir == "equ" then
            -- LABEL: EQU n  already captured label; or EQU via prior label form
            local n, e = parse_number(trim(darg), symbols, passno)
            if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
            if label then
              symbols[label] = u16(n)
            end
          elseif dir == "db" then
            local args = split_args(darg)
            for _, a in ipairs(args) do
              if a:sub(1, 1) == '"' and a:sub(-1) == '"' then
                local str = a:sub(2, -2)
                for i = 1, #str do
                  if passno == 2 then out[pc] = str:byte(i) end
                  pc = pc + 1
                end
              else
                local n, e = parse_number(a, symbols, passno)
                if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
                if passno == 2 then out[pc] = u8(n) end
                pc = pc + 1
              end
            end
          elseif dir == "dw" then
            for _, a in ipairs(split_args(darg)) do
              local n, e = parse_number(a, symbols, passno)
              if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
              n = u16(n)
              if passno == 2 then
                out[pc] = n % 256
                out[pc + 1] = math.floor(n / 256) % 256
              end
              pc = pc + 2
            end
          elseif dir == "ds" then
            local n, e = parse_number(trim(darg), symbols, passno)
            if n == nil then error(item.file .. ":" .. item.line .. ": " .. e) end
            pc = pc + n
          elseif dir == "blob" then
            local name = trim(darg)
            local blob = blobs[name]
            if not blob then
              error(item.file .. ":" .. item.line .. ": unknown blob " .. name)
            end
            for i = 1, #blob do
              if passno == 2 then out[pc] = blob[i] end
              pc = pc + 1
            end
          else
            -- instruction
            local ok, new_pc = pcall(function()
              return emit_instr(s, out, pc, symbols, passno)
            end)
            if not ok then
              error(item.file .. ":" .. item.line .. ": " .. tostring(new_pc))
            end
            pc = new_pc
          end
        end
        local sz = pc - addr_base
        if sz > (page_sizes[cur_page] or 0) then
          page_sizes[cur_page] = sz
        end
      end
    end
    return pc
  end

  function emit_instr(s, out, pc, symbols, passno)
    local mnem, argstr = s:match("^([%w]+)%s*(.*)$")
    if not mnem then
      error("bad instruction: " .. s)
    end
    mnem = mnem:lower()
    argstr = trim(argstr or "")
    local args = argstr ~= "" and split_args(argstr) or {}

    local function need(n)
      if #args < n then error(mnem .. " needs " .. n .. " args") end
    end
    local function imm8(a)
      local n, e = parse_number(a, symbols, passno)
      if not n then error(e) end
      return u8(n)
    end
    local function imm16(a)
      local n, e = parse_number(a, symbols, passno)
      if not n then error(e) end
      return u16(n)
    end
    local function disp(target)
      local n, e = parse_number(target, symbols, passno)
      if not n then error(e) end
      local rel = n - (pc + 2)
      if passno == 2 and (rel < -128 or rel > 127) then
        error("JR/DJNZ out of range (" .. rel .. ")")
      end
      return u8(rel)
    end
    local function put(...)
      if passno == 2 then
        pc = emit_bytes(out, pc, ...)
      else
        pc = pc + select("#", ...)
      end
      return pc
    end

    if mnem == "nop" then return put(0x00)
    elseif mnem == "halt" then return put(0x76)
    elseif mnem == "di" then return put(0xF3)
    elseif mnem == "ei" then return put(0xFB)
    elseif mnem == "ret" then
      if #args == 0 then return put(0xC9) end
      local cc = CC[args[1]:lower()]
      if not cc then error("bad cc") end
      return put(0xC0 + cc * 8)
    elseif mnem == "reti" then return put(0xED, 0x4D)
    elseif mnem == "retn" then return put(0xED, 0x45)
    elseif mnem == "im" then
      need(1)
      local n = imm8(args[1])
      if n == 0 then return put(0xED, 0x46)
      elseif n == 1 then return put(0xED, 0x56)
      elseif n == 2 then return put(0xED, 0x5E)
      else error("IM 0/1/2") end
    elseif mnem == "exx" then return put(0xD9)
    elseif mnem == "ex" then
      need(2)
      local a, b = args[1]:lower(), args[2]:lower()
      if a == "de" and b == "hl" then return put(0xEB)
      elseif a == "af" and b == "af'" then return put(0x08)
      elseif a == "(sp)" and b == "hl" then return put(0xE3)
      elseif a == "(sp)" and b == "ix" then return put(0xDD, 0xE3)
      elseif a == "(sp)" and b == "iy" then return put(0xFD, 0xE3)
      else error("unsupported EX") end
    elseif mnem == "push" then
      need(1)
      local t = args[1]:lower()
      if t == "ix" then return put(0xDD, 0xE5) end
      if t == "iy" then return put(0xFD, 0xE5) end
      local r = RP2[t]
      if not r then error("PUSH rp") end
      return put(0xC5 + r * 16)
    elseif mnem == "pop" then
      need(1)
      local t = args[1]:lower()
      if t == "ix" then return put(0xDD, 0xE1) end
      if t == "iy" then return put(0xFD, 0xE1) end
      local r = RP2[t]
      if not r then error("POP rp") end
      return put(0xC1 + r * 16)
    elseif mnem == "djnz" then
      need(1)
      return put(0x10, disp(args[1]))
    elseif mnem == "jr" then
      if #args == 1 then
        return put(0x18, disp(args[1]))
      end
      need(2)
      local cc = CC[args[1]:lower()]
      if cc == nil or cc > 3 then error("JR cc") end
      return put(0x20 + cc * 8, disp(args[2]))
    elseif mnem == "jp" then
      if #args == 1 then
        local t = args[1]:lower()
        if t == "(hl)" then return put(0xE9) end
        if t == "(ix)" then return put(0xDD, 0xE9) end
        if t == "(iy)" then return put(0xFD, 0xE9) end
        local n = imm16(args[1])
        return put(0xC3, n % 256, math.floor(n / 256))
      end
      need(2)
      local cc = CC[args[1]:lower()]
      if not cc then error("JP cc") end
      local n = imm16(args[2])
      return put(0xC2 + cc * 8, n % 256, math.floor(n / 256))
    elseif mnem == "call" then
      if #args == 1 then
        local n = imm16(args[1])
        return put(0xCD, n % 256, math.floor(n / 256))
      end
      need(2)
      local cc = CC[args[1]:lower()]
      local n = imm16(args[2])
      return put(0xC4 + cc * 8, n % 256, math.floor(n / 256))
    elseif mnem == "rst" then
      need(1)
      local n = imm8(args[1])
      if n % 8 ~= 0 or n > 0x38 then error("RST") end
      return put(0xC7 + n)
    elseif mnem == "out" then
      need(2)
      local p, r = args[1], args[2]:lower()
      local pl = p:lower()
      if pl == "(c)" then
        if r == "0" then return put(0xED, 0x71) end
        if not is_reg8(r) or r == "(hl)" then error("OUT (c),r") end
        return put(0xED, 0x41 + REG8[r] * 8)
      end
      if pl:match("^%(%d") or pl:match("^%(%$") or pl:match("^%(0x") or pl:match("^%([%w_]+%)$") then
        local inner = p:match("^%((.+)%)$")
        if r ~= "a" then error("OUT (n),A") end
        return put(0xD3, imm8(inner))
      end
      error("OUT form")
    elseif mnem == "in" then
      need(1)
      -- bare "in (c)" (ED 70)
      if #args == 1 and args[1]:lower() == "(c)" then
        return put(0xED, 0x70)
      end
      need(2)
      local r, p = args[1]:lower(), args[2]
      local pl = p:lower()
      if pl == "(c)" then
        if not is_reg8(r) or r == "(hl)" then error("IN r,(c)") end
        return put(0xED, 0x40 + REG8[r] * 8)
      end
      if r == "a" then
        local inner = p:match("^%((.+)%)$")
        return put(0xDB, imm8(inner))
      end
      error("IN form")
    elseif mnem == "inc" then
      need(1)
      local t = args[1]:lower()
      if t == "ix" then return put(0xDD, 0x23) end
      if t == "iy" then return put(0xFD, 0x23) end
      local hx, hi = xy_half(t)
      if hx then return put(xy_prefix(hx), 0x04 + hi * 8) end
      local xy, d = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0x34, d) end
      if RP[t] then return put(0x03 + RP[t] * 16) end
      if is_reg8(t) then return put(0x04 + REG8[t] * 8) end
      error("INC")
    elseif mnem == "dec" then
      need(1)
      local t = args[1]:lower()
      if t == "ix" then return put(0xDD, 0x2B) end
      if t == "iy" then return put(0xFD, 0x2B) end
      local hx, hi = xy_half(t)
      if hx then return put(xy_prefix(hx), 0x05 + hi * 8) end
      local xy, d = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0x35, d) end
      if RP[t] then return put(0x0B + RP[t] * 16) end
      if is_reg8(t) then return put(0x05 + REG8[t] * 8) end
      error("DEC")
    elseif mnem == "add" then
      need(2)
      local d, s = args[1]:lower(), args[2]
      if d == "a" then
        local xy, disp = parse_idx_mem(s, symbols, passno)
        if xy then return put(xy_prefix(xy), 0x86, disp) end
        local hx, hi = xy_half(s)
        if hx then return put(xy_prefix(hx), 0x80 + hi) end
        local sl = s:lower()
        if is_reg8(sl) then return put(0x80 + REG8[sl]) end
        return put(0xC6, imm8(s))
      elseif d == "hl" then
        local r = RP[s:lower()]
        if not r then error("ADD HL,rp") end
        return put(0x09 + r * 16)
      elseif d == "ix" or d == "iy" then
        local sl = s:lower()
        local pref = xy_prefix(d)
        if sl == "bc" then return put(pref, 0x09) end
        if sl == "de" then return put(pref, 0x19) end
        if sl == d then return put(pref, 0x29) end
        if sl == "sp" then return put(pref, 0x39) end
        error("ADD IX/IY,rp")
      end
      error("ADD")
    elseif mnem == "adc" then
      need(2)
      local d = args[1]:lower()
      if d == "hl" then
        local r = RP[args[2]:lower()]
        if not r then error("ADC HL,rp") end
        return put(0xED, 0x4A + r * 16)
      end
      if d ~= "a" then error("ADC A,") end
      local xy, disp = parse_idx_mem(args[2], symbols, passno)
      if xy then return put(xy_prefix(xy), 0x8E, disp) end
      local hx, hi = xy_half(args[2])
      if hx then return put(xy_prefix(hx), 0x88 + hi) end
      local sl = args[2]:lower()
      if is_reg8(sl) then return put(0x88 + REG8[sl]) end
      return put(0xCE, imm8(args[2]))
    elseif mnem == "sub" then
      need(1)
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0x96, disp) end
      local hx, hi = xy_half(args[1])
      if hx then return put(xy_prefix(hx), 0x90 + hi) end
      local sl = args[1]:lower()
      if is_reg8(sl) then return put(0x90 + REG8[sl]) end
      return put(0xD6, imm8(args[1]))
    elseif mnem == "sbc" then
      need(2)
      local d = args[1]:lower()
      if d == "hl" then
        local r = RP[args[2]:lower()]
        if not r then error("SBC HL,rp") end
        return put(0xED, 0x42 + r * 16)
      end
      if d ~= "a" then error("SBC A,") end
      local xy, disp = parse_idx_mem(args[2], symbols, passno)
      if xy then return put(xy_prefix(xy), 0x9E, disp) end
      local hx, hi = xy_half(args[2])
      if hx then return put(xy_prefix(hx), 0x98 + hi) end
      local sl = args[2]:lower()
      if is_reg8(sl) then return put(0x98 + REG8[sl]) end
      return put(0xDE, imm8(args[2]))
    elseif mnem == "daa" then
      return put(0x27)
    elseif mnem == "cpl" then
      return put(0x2F)
    elseif mnem == "scf" then
      return put(0x37)
    elseif mnem == "ccf" then
      return put(0x3F)
    elseif mnem == "neg" then
      return put(0xED, 0x44)
    elseif mnem == "rld" then
      return put(0xED, 0x6F)
    elseif mnem == "rrd" then
      return put(0xED, 0x67)
    elseif mnem == "ldi" then
      return put(0xED, 0xA0)
    elseif mnem == "ldd" then
      return put(0xED, 0xA8)
    elseif mnem == "ldir" then
      return put(0xED, 0xB0)
    elseif mnem == "lddr" then
      return put(0xED, 0xB8)
    elseif mnem == "cpi" then
      return put(0xED, 0xA1)
    elseif mnem == "cpd" then
      return put(0xED, 0xA9)
    elseif mnem == "cpir" then
      return put(0xED, 0xB1)
    elseif mnem == "cpdr" then
      return put(0xED, 0xB9)
    elseif mnem == "ini" then
      return put(0xED, 0xA2)
    elseif mnem == "ind" then
      return put(0xED, 0xAA)
    elseif mnem == "inir" then
      return put(0xED, 0xB2)
    elseif mnem == "indr" then
      return put(0xED, 0xBA)
    elseif mnem == "outi" then
      return put(0xED, 0xA3)
    elseif mnem == "outd" then
      return put(0xED, 0xAB)
    elseif mnem == "otir" then
      return put(0xED, 0xB3)
    elseif mnem == "otdr" then
      return put(0xED, 0xBB)
    elseif mnem == "rlca" then
      return put(0x07)
    elseif mnem == "rrca" then
      return put(0x0F)
    elseif mnem == "rla" then
      return put(0x17)
    elseif mnem == "rra" then
      return put(0x1F)
    elseif mnem == "sla" or mnem == "sra" or mnem == "srl" or mnem == "sll"
        or mnem == "rlc" or mnem == "rrc" or mnem == "rl" or mnem == "rr" then
      need(1)
      local y = ({ rlc = 0, rrc = 1, rl = 2, rr = 3, sla = 4, sra = 5, sll = 6, srl = 7 })[mnem]
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xCB, disp, y * 8 + 6) end
      local r = REG8[args[1]:lower()]
      if r == nil then error(mnem .. " r") end
      return put(0xCB, y * 8 + r)
    elseif mnem == "bit" or mnem == "res" or mnem == "set" then
      need(2)
      local b = imm8(args[1])
      if b > 7 then error(mnem .. " bit 0-7") end
      local base = ({ bit = 0x40, res = 0x80, set = 0xC0 })[mnem]
      local xy, disp = parse_idx_mem(args[2], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xCB, disp, base + b * 8 + 6) end
      local r = REG8[args[2]:lower()]
      if r == nil then error(mnem .. " r") end
      return put(0xCB, base + b * 8 + r)
    elseif mnem == "and" then
      need(1)
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xA6, disp) end
      local hx, hi = xy_half(args[1])
      if hx then return put(xy_prefix(hx), 0xA0 + hi) end
      local sl = args[1]:lower()
      if is_reg8(sl) then return put(0xA0 + REG8[sl]) end
      return put(0xE6, imm8(args[1]))
    elseif mnem == "xor" then
      need(1)
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xAE, disp) end
      local hx, hi = xy_half(args[1])
      if hx then return put(xy_prefix(hx), 0xA8 + hi) end
      local sl = args[1]:lower()
      if is_reg8(sl) then return put(0xA8 + REG8[sl]) end
      return put(0xEE, imm8(args[1]))
    elseif mnem == "or" then
      need(1)
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xB6, disp) end
      local hx, hi = xy_half(args[1])
      if hx then return put(xy_prefix(hx), 0xB0 + hi) end
      local sl = args[1]:lower()
      if is_reg8(sl) then return put(0xB0 + REG8[sl]) end
      return put(0xF6, imm8(args[1]))
    elseif mnem == "cp" then
      need(1)
      local xy, disp = parse_idx_mem(args[1], symbols, passno)
      if xy then return put(xy_prefix(xy), 0xBE, disp) end
      local hx, hi = xy_half(args[1])
      if hx then return put(xy_prefix(hx), 0xB8 + hi) end
      local sl = args[1]:lower()
      if is_reg8(sl) then return put(0xB8 + REG8[sl]) end
      return put(0xFE, imm8(args[1]))
    elseif mnem == "ld" then
      need(2)
      local d, s = args[1], args[2]
      local dl, sl = d:lower(), s:lower()

      -- LD xy,nn / LD (nn),xy / LD xy,(nn)
      if dl == "ix" or dl == "iy" then
        local pref = xy_prefix(dl)
        local sm = s:match("^%((.+)%)$")
        if sm and not parse_idx_mem(s, symbols, passno) then
          local n = imm16(sm)
          return put(pref, 0x2A, n % 256, math.floor(n / 256))
        end
        local n = imm16(s)
        return put(pref, 0x21, n % 256, math.floor(n / 256))
      end
      local dm_xy = d:match("^%((.+)%)$")
      if dm_xy and (sl == "ix" or sl == "iy") then
        local n = imm16(dm_xy)
        return put(xy_prefix(sl), 0x22, n % 256, math.floor(n / 256))
      end
      if dl == "sp" and (sl == "ix" or sl == "iy") then
        return put(xy_prefix(sl), 0xF9)
      end

      -- LD r,(xy+d) / LD (xy+d),r / LD (xy+d),n
      local dxy, ddisp = parse_idx_mem(d, symbols, passno)
      local sxy, sdisp = parse_idx_mem(s, symbols, passno)
      if dxy then
        if is_reg8(sl) then return put(xy_prefix(dxy), 0x70 + REG8[sl], ddisp) end
        return put(xy_prefix(dxy), 0x36, ddisp, imm8(s))
      end
      if sxy and is_reg8(dl) then
        return put(xy_prefix(sxy), 0x46 + REG8[dl] * 8, sdisp)
      end

      -- Half registers ixh/ixl/iyh/iyl
      local dhx, dhi = xy_half(dl)
      local shx, shi = xy_half(sl)
      if dhx and shx and dhx == shx then
        return put(xy_prefix(dhx), 0x40 + dhi * 8 + shi)
      end
      if dhx and is_reg8(sl) and REG8[sl] ~= 6 then
        return put(xy_prefix(dhx), 0x40 + dhi * 8 + REG8[sl])
      end
      if shx and is_reg8(dl) and REG8[dl] ~= 6 then
        return put(xy_prefix(shx), 0x40 + REG8[dl] * 8 + shi)
      end
      if dhx then
        return put(xy_prefix(dhx), 0x06 + dhi * 8, imm8(s))
      end

      -- LD I/R (must precede LD r,n - "r"/"i" are not imm symbols)
      if dl == "i" and sl == "a" then return put(0xED, 0x47) end
      if dl == "r" and sl == "a" then return put(0xED, 0x4F) end
      if dl == "a" and sl == "i" then return put(0xED, 0x57) end
      if dl == "a" and sl == "r" then return put(0xED, 0x5F) end

      -- LD r,r / LD r,n / LD r,(HL)
      if is_reg8(dl) then
        if is_reg8(sl) then return put(0x40 + REG8[dl] * 8 + REG8[sl]) end
        if sl == "(bc)" and dl == "a" then return put(0x0A) end
        if sl == "(de)" and dl == "a" then return put(0x1A) end
        local m = s:match("^%((.+)%)$")
        if m and dl == "a" and not is_reg8("(" .. m:lower() .. ")") then
          if m:lower() ~= "hl" and m:lower() ~= "bc" and m:lower() ~= "de" then
            local n = imm16(m)
            return put(0x3A, n % 256, math.floor(n / 256))
          end
        end
        return put(0x06 + REG8[dl] * 8, imm8(s))
      end

      -- LD (HL),r / n
      if dl == "(hl)" then
        if is_reg8(sl) then return put(0x70 + REG8[sl]) end
        return put(0x36, imm8(s))
      end
      if dl == "(bc)" and sl == "a" then return put(0x02) end
      if dl == "(de)" and sl == "a" then return put(0x12) end

      local dm = d:match("^%((.+)%)$")
      if dm and (sl == "a" or sl == "hl" or sl == "de" or sl == "bc" or sl == "sp") then
        local n = imm16(dm)
        if sl == "a" then
          return put(0x32, n % 256, math.floor(n / 256))
        elseif sl == "hl" then
          return put(0x22, n % 256, math.floor(n / 256))
        elseif sl == "de" then
          return put(0xED, 0x53, n % 256, math.floor(n / 256))
        elseif sl == "bc" then
          return put(0xED, 0x43, n % 256, math.floor(n / 256))
        else
          return put(0xED, 0x73, n % 256, math.floor(n / 256))
        end
      end
      local sm = s:match("^%((.+)%)$")
      if sm and (dl == "hl" or dl == "de" or dl == "bc" or dl == "sp") then
        local n = imm16(sm)
        if dl == "hl" then
          return put(0x2A, n % 256, math.floor(n / 256))
        elseif dl == "de" then
          return put(0xED, 0x5B, n % 256, math.floor(n / 256))
        elseif dl == "bc" then
          return put(0xED, 0x4B, n % 256, math.floor(n / 256))
        else
          return put(0xED, 0x7B, n % 256, math.floor(n / 256))
        end
      end

      if dl == "sp" and sl == "hl" then return put(0xF9) end
      if dl == "sp" and sl == "ix" then return put(0xDD, 0xF9) end
      if dl == "sp" and sl == "iy" then return put(0xFD, 0xF9) end

      if RP[dl] then
        local n = imm16(s)
        return put(0x01 + RP[dl] * 16, n % 256, math.floor(n / 256))
      end

      error("unsupported LD " .. d .. "," .. s)
    else
      error("unknown mnemonic: " .. mnem)
    end
  end

  pass(1)
  local end_pc = pass(2)
  local size = end_pc - addr_base
  if size < 0 then
    size = 0
  end
  if size > max_size then
    size = max_size
  end
  -- Prefer high-water mark from writes when using page directive.
  if used_page_dir and page_sizes[cur_page] and page_sizes[cur_page] > size then
    size = page_sizes[cur_page]
  end

  local result = {
    bytes = pages_raw[0] or raw,
    size = page_sizes[0] or size,
    end_pc = end_pc,
    addr_base = addr_base,
    symbols = symbols,
    symbol_pages = symbol_pages,
    multipage = multipage or used_page_dir,
  }

  if result.multipage then
    local pages = {}
    local max_p = 0
    for p, _ in pairs(pages_raw) do
      if p > max_p then max_p = p end
    end
    for p = 0, max_p do
      local pr = pages_raw[p]
      if pr then
        local psz = page_sizes[p] or 0
        pages[p] = { bytes = pr, size = psz }
      end
    end
    result.pages = pages
    result.n_pages = max_p + 1
    -- Legacy flat fields describe page 0.
    result.bytes = pages[0] and pages[0].bytes or result.bytes
    result.size = pages[0] and pages[0].size or result.size
  end

  return result
end

function Assembler.assemble_file(path, opts)
  return assemble_file(path, opts)
end

function Assembler.to_string(bytes, size)
  local t = {}
  for i = 0, size - 1 do
    t[#t + 1] = string.char(bytes[i] or 0)
  end
  return table.concat(t)
end

return Assembler
