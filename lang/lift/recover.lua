-- Mechanical Z80 page -> Tiny-C recovery dialect.
-- Goal: readable portable source scaffold, NOT compile-back to TI-83.
-- Uses goto/labels and hw_* helpers; refine / rename by hand later.

local Disasm = require("asm.disasm")
local Infer = require("asm.infer_names")
local Flash = require("asm.flash_page")

local Recover = {}

local PAGE = Flash.PAGE

local PORT_NAME = {
  [0x00] = "PORT_LINK",
  [0x01] = "PORT_KEYPAD",
  [0x02] = "PORT_STATUS",
  [0x03] = "PORT_INTMASK",
  [0x04] = "PORT_INTACK",
  [0x05] = "PORT_ASYN",
  [0x06] = "PORT_MMU_A",
  [0x07] = "PORT_MMU_B",
  [0x10] = "PORT_LCD_CMD",
  [0x11] = "PORT_LCD_DATA",
  [0x20] = "PORT_SE_STATUS",
}

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

local function hex8(n)
  return string.format("0x%02X", u8(n))
end

local function hex16(n)
  return string.format("0x%04X", u16(n))
end

local function port_expr(p)
  p = u8(p)
  return PORT_NAME[p] or hex8(p)
end

local function sanitize_fn(name)
  if not name or name == "" then return "fn_unknown" end
  name = name:gsub("[^A-Za-z0-9_]", "_")
  if name:match("^[0-9]") then name = "f_" .. name end
  return name
end

local function label_for(addr, prefix, by_addr)
  addr = u16(addr)
  if by_addr[addr] then
    return sanitize_fn(prefix .. by_addr[addr])
  end
  return sanitize_fn(prefix .. string.format("L_%04X", addr))
end

-- Internal goto labels (avoid clashing with the C function name).
local function goto_lab(addr, prefix, by_addr)
  return "lab_" .. label_for(addr, prefix, by_addr)
end

local function in_win(a, lo, hi)
  return a >= lo and a < hi
end

--- Collect function entries: call targets + inferred names + seeds.
local function collect_entries(read8, size, symbols, seeds, win_lo, win_hi)
  win_lo = win_lo or 0
  win_hi = win_hi or size
  local _, _, _, call_targets = Disasm.discover_code(read8, seeds, size, {
    window_lo = win_lo,
    window_hi = win_hi,
  })
  local entries = {}
  for a in pairs(call_targets) do
    if in_win(a, win_lo, win_hi) then entries[a] = true end
  end
  for addr = win_lo, win_hi - 3 do
    if read8(addr) == 0xCD then
      local t = read8(addr + 1) + read8(addr + 2) * 256
      if in_win(t, win_lo, win_hi) then entries[t] = true end
    end
  end
  local by_addr = {}
  for name, addr in pairs(symbols or {}) do
    if type(name) == "string" and type(addr) == "number" and in_win(addr, win_lo, win_hi) then
      by_addr[u16(addr)] = name
      entries[u16(addr)] = true
    end
  end
  for _, s in ipairs(seeds) do
    if in_win(s, win_lo, win_hi) then entries[u16(s)] = true end
  end
  return entries, by_addr
end

--- Walk CFG from entry until ret / leaving the function.
local function collect_fn_body(read8, entry, win_lo, win_hi, entries, max_insns)
  max_insns = max_insns or 1024
  local addrs = {}
  local visited = {}
  local skip = {} -- addresses to treat as data (bcall words after RST 28)
  local queue = { u16(entry) }
  while #queue > 0 and #addrs < max_insns do
    local a = table.remove(queue, 1)
    if visited[a] or skip[a] or not in_win(a, win_lo, win_hi) then
      -- skip
    elseif a ~= entry and entries[a] then
      -- don't inline into another function
    else
      visited[a] = true
      local insn = Disasm.decode(read8, a)
      if insn then
        addrs[#addrs + 1] = a
        local text = insn.text or ""
        -- TI-OS: rst 28h ; .dw romcall - two data bytes follow
        if text == "rst 0x28" or (insn.call and insn.branch == 0x28) then
          skip[a + 1] = true
          skip[a + 2] = true
          local n = a + 3
          if in_win(n, win_lo, win_hi) and (n == entry or not entries[n]) then
            queue[#queue + 1] = n
          end
        -- TI-OS banked call/jump trampolines: call 2B07/2B3C ; .dw addr ; .db page
        elseif insn.call and (insn.branch == 0x2B07 or insn.branch == 0x2B3C) then
          skip[a + 3] = true
          skip[a + 4] = true
          skip[a + 5] = true
          local n = a + 6
          if insn.branch == 0x2B07
              and in_win(n, win_lo, win_hi)
              and (n == entry or not entries[n]) then
            queue[#queue + 1] = n
          end
          -- 2B3C is a banked jump (does not return)
        else
          if insn.branch then
            local t = u16(insn.branch)
            if in_win(t, win_lo, win_hi) and (t == entry or not entries[t]) then
              queue[#queue + 1] = t
            end
          end
          if insn.fallthrough then
            local n = u16(insn.fallthrough)
            if in_win(n, win_lo, win_hi) and (n == entry or not entries[n]) then
              queue[#queue + 1] = n
            end
          end
        end
      end
    end
  end
  table.sort(addrs)
  return addrs, visited
end

-- Inferred names that have curated portable implementations in clean/*.tc
local CURATED = {
  key_scan = "key_scan",
  lcd_busy_wait = "lcd_busy_wait",
  lcd_write_cmd = "lcd_write_cmd",
  lcd_write_data = "lcd_write_data",
  -- Named T6A04 ops (1:1 with cmd bytes 0x05 / 0x07)
  lcd_cmd_07 = "lcd_op_inc_y_up",
  lcd_cmd_05 = "lcd_op_inc_x_up",
  mmu_set_bankA = "mmu_set_bank_a",
  mmu_set_bankB = "mmu_set_bank_b",
  link_io = "link_io_stub",
}

local function parse_cc(text)
  -- "jr z,lab" / "jp nz,lab" / "ret c" / "call nc,lab"
  local cc = text:match("^jr%s+([a-z]+),")
    or text:match("^jp%s+([a-z]+),")
    or text:match("^ret%s+([a-z]+)$")
    or text:match("^call%s+([a-z]+),")
  if cc and cc ~= "hl" then return cc end
  return nil
end

local function emit_insn(insn, ctx)
  local lines = {}
  local function add(s) lines[#lines + 1] = s end
  local text = insn.text or ""
  local terminal = false -- ret / goto / jp - no shared-tail fallthrough

  local function finish()
    if not terminal and insn.fallthrough then
      local n = u16(insn.fallthrough)
      if ctx.entries[n] and n ~= ctx.entry then
        add(label_for(n, ctx.prefix, ctx.by_addr) .. "();")
        add("return;")
      end
    end
    return lines
  end

  if insn.in_port then
    if u8(insn.in_port) == 0x00 then
      add("a = link_in(); /* stub */")
    else
      add(string.format("a = hw_in(%s);", port_expr(insn.in_port)))
    end
    return finish()
  end
  if insn.out_port then
    local p = u8(insn.out_port)
    if p == 0x00 then
      add("link_out(a); /* stub */")
    elseif p == 0x06 then
      add("mmu_set_bank_a(a);")
    elseif p == 0x07 then
      add("mmu_set_bank_b(a);")
    elseif p == 0x10 then
      -- Port 10 -> LCD command dispatcher (named ops underneath).
      add("lcd_write_cmd(); /* ti_lcd_command(a) */")
    elseif p == 0x11 then
      add("lcd_write_data(); /* ti_lcd_op_write(a) */")
    else
      add(string.format("hw_out(%s, a);", port_expr(p)))
    end
    return finish()
  end

  if insn.ret then
    local cc = parse_cc(text)
    if cc then
      add(string.format("if (flag_%s()) return;", cc))
      -- conditional ret still falls through
    else
      add("return;")
      terminal = true
    end
    return finish()
  end

  local function local_addr(t)
    local lo = ctx.win_lo or 0
    local hi = ctx.win_hi or ctx.size or 0
    return t >= lo and t < hi
  end

  -- TI-OS BCALL via RST 28
  if text == "rst 0x28" or (insn.call and insn.branch == 0x28) then
    local id = 0
    if ctx.read8 then
      id = ctx.read8(ctx.addr + 1) + ctx.read8(ctx.addr + 2) * 256
    end
    add(string.format("os_bcall(%s);", hex16(id)))
    return finish()
  end

  if insn.call and insn.branch then
    local t = u16(insn.branch)
    local cc = parse_cc(text)
    if t == 0x28 then
      -- handled above when text matches; keep fallback
      add("os_bcall(0x0000); /* rst28 */")
    elseif (t == 0x2B07 or t == 0x2B3C) and ctx.read8 and ctx.addr then
      -- call 2B07/2B3C ; .dw dest ; .db page  - TI banked call/jump
      local dest = ctx.read8(ctx.addr + 3) + ctx.read8(ctx.addr + 4) * 256
      local page = ctx.read8(ctx.addr + 5)
      add(string.format("mmu_set_bank_a(%s); /* banked trampoline */", hex8(page)))
      add(string.format("os_banked_call(%s);", hex16(dest)))
      if t == 0x2B3C then
        add("return; /* banked jump */")
        terminal = true
      else
        -- Continue after the 3 inline argument bytes, not at +3 (data).
        insn.fallthrough = ctx.addr + 6
      end
      return finish()
    elseif not local_addr(t) then
      local xref = ctx.cross and ctx.cross[t]
      if xref then
        if cc then
          add(string.format("if (flag_%s()) %s();", cc, xref))
        else
          add(xref .. "();")
        end
      elseif t < 0x4000 then
        local n = (ctx.cross and ctx.cross[t])
          or ("p00_" .. (ctx.cross_raw and ctx.cross_raw[t] or string.format("L_%04X", t)))
        if cc then
          add(string.format("if (flag_%s()) %s();", cc, n))
        else
          add(n .. "();")
        end
      elseif t >= 0x4000 and t < 0x8000 then
        add(string.format("os_banked_call(%s); /* bank window */", hex16(t)))
      else
        add(string.format("/* call %s - RAM/other */", hex16(t)))
      end
    else
      local name = label_for(t, ctx.prefix, ctx.by_addr)
      if cc then
        add(string.format("if (flag_%s()) %s();", cc, name))
      else
        add(name .. "();")
      end
    end
    return finish()
  end

  -- jp / jr (branch set, not call)
  if insn.branch and not insn.call and text:match("^j[pr]%s") then
    local t = u16(insn.branch)
    local cc = parse_cc(text)
    if not local_addr(t) then
      -- Bank windows: 0x4000-7FFF (mode0 A/B) and 0x8000-BFFF (mode1 bank A).
      if t >= 0x4000 and t < 0xC000 then
        if cc then
          add(string.format("if (flag_%s()) { os_banked_call(%s); return; }", cc, hex16(t)))
        else
          add(string.format("os_banked_call(%s);", hex16(t)))
          add("return;")
          terminal = true
        end
      elseif t < 0x4000 then
        -- Boot/OS vectors live in page0 (e.g. jp z,0x0053 -> OS cold start).
        local n = (ctx.cross and ctx.cross[t])
          or ("p00_" .. (ctx.cross_raw and ctx.cross_raw[t] or string.format("L_%04X", t)))
        if cc then
          add(string.format("if (flag_%s()) { %s(); return; }", cc, n))
        else
          add(n .. "();")
          add("return;")
          terminal = true
        end
      else
        add(string.format("/* %s - other page/RAM */", text))
        if not cc then terminal = true end
      end
    elseif ctx.entries[t] and t ~= ctx.entry then
      local name = label_for(t, ctx.prefix, ctx.by_addr)
      if cc then
        add(string.format("if (flag_%s()) { %s(); return; }", cc, name))
      else
        add(name .. "();")
        add("return;")
        terminal = true
      end
    elseif ctx.in_body and ctx.in_body[t] then
      local lab = goto_lab(t, ctx.prefix, ctx.by_addr)
      if cc then
        add(string.format("if (flag_%s()) goto %s;", cc, lab))
      else
        add("goto " .. lab .. ";")
        terminal = true
      end
    else
      -- Not in CFG body (truncated walk) - fall back to named call.
      local name = label_for(t, ctx.prefix, ctx.by_addr)
      if cc then
        add(string.format("if (flag_%s()) { %s(); return; }", cc, name))
      else
        add(name .. "();")
        add("return;")
        terminal = true
      end
    end
    return finish()
  end

  if text:match("^djnz%s") and insn.branch then
    local t = u16(insn.branch)
    add("b = (uint8_t)(b - 1);")
    if local_addr(t) and ctx.entries[t] and t ~= ctx.entry then
      add(string.format("if (b != 0) { %s(); return; }", label_for(t, ctx.prefix, ctx.by_addr)))
    elseif local_addr(t) and ctx.in_body and ctx.in_body[t] then
      add("if (b != 0) goto " .. goto_lab(t, ctx.prefix, ctx.by_addr) .. ";")
    elseif local_addr(t) then
      -- Target not in this body - treat as tail call to that address's function.
      add(string.format("if (b != 0) { %s(); return; }", label_for(t, ctx.prefix, ctx.by_addr)))
    else
      add(string.format("if (b != 0) { /* djnz %s */ }", hex16(t)))
    end
    return finish()
  end

  if insn.ld_a ~= nil then
    add(string.format("a = %s;", hex8(insn.ld_a)))
    return finish()
  end
  if insn.and_imm ~= nil then
    add(string.format("a = a & %s;", hex8(insn.and_imm)))
    add("flag_logic(a);")
    return finish()
  end
  if insn.or_imm ~= nil then
    add(string.format("a = a | %s;", hex8(insn.or_imm)))
    add("flag_logic(a);")
    return finish()
  end
  if insn.cp_imm ~= nil then
    add(string.format("flag_cmp(a, %s);", hex8(insn.cp_imm)))
    return finish()
  end

  local dst, src = text:match("^ld%s+([abcdehl]),([abcdehl])$")
  if dst and src then
    add(string.format("%s = %s;", dst, src))
    return finish()
  end
  dst = text:match("^ld%s+([abcdehl]),0x(%x+)$")
  if dst then
    local imm = text:match(",(0x%x+)$")
    add(string.format("%s = %s;", dst, imm))
    return finish()
  end

  -- ld r,(hl) / ld (hl),r
  dst = text:match("^ld%s+([abcdehl]),%(hl%)$")
  if dst then
    add(string.format("%s = mem_read8(hl());", dst))
    return finish()
  end
  src = text:match("^ld%s+%(hl%),([abcdehl])$")
  if src then
    add(string.format("mem_write8(hl(), %s);", src))
    return finish()
  end
  if text:match("^ld%s+%(hl%),0x%x+$") then
    local imm = text:match(",(0x%x+)$")
    add(string.format("mem_write8(hl(), %s);", imm))
    return finish()
  end
  if text == "inc (hl)" then
    add("mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));")
    return finish()
  end
  if text == "dec (hl)" then
    add("mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));")
    return finish()
  end

  -- ld r,(ix+d) / ld r,(iy+d) / ld (ix+d),r / and (ix)/(iy) with d=0
  do
    local r, xy, off = text:match("^ld%s+([abcdehl]),%((i[xy])%+(0x%x+)%)$")
    if r and xy and off then
      add(string.format("%s = mem_read8((uint16_t)(%s + %s));", r, xy, off))
      return finish()
    end
    r, xy = text:match("^ld%s+([abcdehl]),%((i[xy])%)$")
    if r and xy then
      add(string.format("%s = mem_read8(%s);", r, xy))
      return finish()
    end
    xy, off, r = text:match("^ld%s+%((i[xy])%+(0x%x+)%),([abcdehl])$")
    if xy and off and r then
      add(string.format("mem_write8((uint16_t)(%s + %s), %s);", xy, off, r))
      return finish()
    end
    xy, r = text:match("^ld%s+%((i[xy])%),([abcdehl])$")
    if xy and r then
      add(string.format("mem_write8(%s, %s);", xy, r))
      return finish()
    end
  end

  if text == "push ix" then add("cpu_push16(ix);") return finish() end
  if text == "push iy" then add("cpu_push16(iy);") return finish() end
  if text == "pop ix" then add("ix = cpu_pop16();") return finish() end
  if text == "pop iy" then add("iy = cpu_pop16();") return finish() end
  if text == "inc ix" then add("ix = (uint16_t)(ix + 1);") return finish() end
  if text == "dec ix" then add("ix = (uint16_t)(ix - 1);") return finish() end
  if text == "inc iy" then add("iy = (uint16_t)(iy + 1);") return finish() end
  if text == "dec iy" then add("iy = (uint16_t)(iy - 1);") return finish() end

  if text == "jp (hl)" then
    add("os_jp_hl();")
    add("return;")
    terminal = true
    return finish()
  end
  if text == "jp (ix)" then
    add("os_jp_ix();")
    add("return;")
    terminal = true
    return finish()
  end
  if text == "jp (iy)" then
    add("os_jp_iy();")
    add("return;")
    terminal = true
    return finish()
  end

  -- ld a,(nn) / ld (nn),a
  local nn = text:match("^ld%s+a,%((0x%x+)%)$")
  if nn then
    add(string.format("a = mem_read8(%s);", nn))
    return finish()
  end
  nn = text:match("^ld%s+%((0x%x+)%),a$")
  if nn then
    add(string.format("mem_write8(%s, a);", nn))
    return finish()
  end

  -- ld hl,(nn) / ld (nn),hl
  nn = text:match("^ld%s+hl,%((0x%x+)%)$")
  if nn then
    add(string.format("set_hl(mem_read16(%s));", nn))
    return finish()
  end
  nn = text:match("^ld%s+%((0x%x+)%),hl$")
  if nn then
    add(string.format("mem_write16(%s, hl());", nn))
    return finish()
  end

  -- ld a,(bc|de) / ld (bc|de),a  (Lua patterns have no | alternation)
  do
    local rr = text:match("^ld%s+a,%((%l%l)%)$")
    if rr == "bc" or rr == "de" then
      add(string.format("a = mem_read8(%s());", rr))
      return finish()
    end
    rr = text:match("^ld%s+%((%l%l)%),a$")
    if rr == "bc" or rr == "de" then
      add(string.format("mem_write8(%s(), a);", rr))
      return finish()
    end
  end

  if text == "push af" then add("cpu_push_af();") return finish() end
  if text == "push bc" then add("cpu_push_bc();") return finish() end
  if text == "push de" then add("cpu_push_de();") return finish() end
  if text == "push hl" then add("cpu_push_hl();") return finish() end
  if text == "pop af" then add("cpu_pop_af();") return finish() end
  if text == "pop bc" then add("cpu_pop_bc();") return finish() end
  if text == "pop de" then add("cpu_pop_de();") return finish() end
  if text == "pop hl" then add("cpu_pop_hl();") return finish() end

  if text == "nop" or text == "di" or text == "ei" then
    add(string.format("/* %s */", text))
    return finish()
  end
  if text == "halt" then
    add("halt();")
    return finish()
  end

  local inc = text:match("^inc%s+([abcdehl])$")
  if inc then
    add(string.format("%s = (uint8_t)(%s + 1);", inc, inc))
    return finish()
  end
  local dec = text:match("^dec%s+([abcdehl])$")
  if dec then
    add(string.format("%s = (uint8_t)(%s - 1);", dec, dec))
    return finish()
  end

  do
    local rr = text:match("^inc%s+(%w+)$")
    if rr == "bc" or rr == "de" or rr == "hl" or rr == "sp" then
      if rr == "sp" then
        add("sp = (uint16_t)(sp + 1);")
      else
        add(string.format("set_%s((uint16_t)(%s() + 1));", rr, rr))
      end
      return finish()
    end
    rr = text:match("^dec%s+(%w+)$")
    if rr == "bc" or rr == "de" or rr == "hl" or rr == "sp" then
      if rr == "sp" then
        add("sp = (uint16_t)(sp - 1);")
      else
        add(string.format("set_%s((uint16_t)(%s() - 1));", rr, rr))
      end
      return finish()
    end
  end

  if text == "xor a" or text == "sub a" then
    add("a = 0;")
    add("flag_logic(a);")
    return finish()
  end
  local xorr = text:match("^xor%s+([abcdehl])$")
  if xorr then
    add(string.format("a = a ^ %s;", xorr))
    add("flag_logic(a);")
    return finish()
  end
  local orr = text:match("^or%s+([abcdehl])$")
  if orr then
    add(string.format("a = a | %s;", orr))
    add("flag_logic(a);")
    return finish()
  end
  local andr = text:match("^and%s+([abcdehl])$")
  if andr then
    add(string.format("a = a & %s;", andr))
    add("flag_logic(a);")
    return finish()
  end
  if text == "cpl" then
    add("a = a ^ 0xFF;")
    return finish()
  end
  local add_r = text:match("^add%s+a,([abcdehl])$")
  if add_r then
    add(string.format("a = (uint8_t)(a + %s);", add_r))
    return finish()
  end
  if text:match("^add%s+a,0x%x+$") then
    local imm = text:match(",(0x%x+)$")
    add(string.format("a = (uint8_t)(a + %s);", imm))
    return finish()
  end
  local sub_r = text:match("^sub%s+([abcdehl])$")
  if sub_r then
    add(string.format("a = (uint8_t)(a - %s);", sub_r))
    return finish()
  end
  if text:match("^sub%s+0x%x+$") then
    local imm = text:match(" (0x%x+)$")
    add(string.format("a = (uint8_t)(a - %s);", imm))
    return finish()
  end
  local cp_r = text:match("^cp%s+([abcdehl])$")
  if cp_r then
    add(string.format("flag_cmp(a, %s);", cp_r))
    return finish()
  end

  do
    local rp, imm = text:match("^ld%s+(%w+),(0x%x+)$")
    if imm and (rp == "bc" or rp == "de" or rp == "hl" or rp == "sp") then
      if rp == "sp" then
        add(string.format("sp = %s;", imm))
      else
        add(string.format("set_%s(%s);", rp, imm))
      end
      return finish()
    end
  end
  if text == "ld sp,hl" then
    add("sp = hl();")
    return finish()
  end
  if text == "ld hl,sp" then
    add("set_hl(sp);")
    return finish()
  end
  if text == "ld sp,ix" then
    add("sp = ix;")
    return finish()
  end
  if text == "ld sp,iy" then
    add("sp = iy;")
    return finish()
  end

  nn = text:match("^ld%s+%((0x%x+)%),sp$")
  if nn then
    add(string.format("mem_write16(%s, sp);", nn))
    return finish()
  end
  nn = text:match("^ld%s+sp,%((0x%x+)%)$")
  if nn then
    add(string.format("sp = mem_read16(%s);", nn))
    return finish()
  end
  local rp, nn2 = text:match("^ld%s+(%l%l),%((0x%x+)%)$")
  if nn2 and (rp == "bc" or rp == "de") then
    add(string.format("set_%s(mem_read16(%s));", rp, nn2))
    return finish()
  end
  nn2, rp = text:match("^ld%s+%((0x%x+)%),(%l%l)$")
  if nn2 and (rp == "bc" or rp == "de") then
    add(string.format("mem_write16(%s, %s());", nn2, rp))
    return finish()
  end

  do
    local xy, imm = text:match("^ld%s+(i[xy]),(0x%x+)$")
    if xy and imm then
      add(string.format("%s = %s;", xy, imm))
      return finish()
    end
  end

  do
    local rp = text:match("^add%s+hl,(%w+)$")
    if rp == "bc" or rp == "de" or rp == "hl" or rp == "sp" then
      if rp == "sp" then
        add("set_hl((uint16_t)(hl() + sp));")
      else
        add(string.format("set_hl((uint16_t)(hl() + %s()));", rp))
      end
      return finish()
    end
  end

  if text == "add ix,sp" then
    add("cpu_add_ix_sp();")
    return finish()
  end
  if text == "add iy,sp" then
    add("cpu_add_iy_sp();")
    return finish()
  end
  do
    local xy, rp = text:match("^add%s+(i[xy]),(%w+)$")
    if xy and rp then
      add(string.format("/* add %s,%s */", xy, rp))
      return finish()
    end
  end

  if text == "im 0" or text == "im 1" or text == "im 2" then
    add(string.format("/* %s */", text))
    return finish()
  end

  if text == "ex de,hl" then
    add("cpu_ex_de_hl();")
    return finish()
  end
  if text == "exx" then
    add("cpu_exx();")
    return finish()
  end
  if text == "ex af,af'" or text == "ex af,af'" then
    add("cpu_ex_af();")
    return finish()
  end

  -- bit/set/res on registers
  local bitn, bitr = text:match("^bit%s+(%d+),([abcdehl])$")
  if bitn and bitr then
    add(string.format("flag_set_z((%s & (1u << %s)) == 0);", bitr, bitn))
    return finish()
  end
  local setn, setr = text:match("^set%s+(%d+),([abcdehl])$")
  if setn and setr then
    add(string.format("%s = (uint8_t)(%s | (1u << %s));", setr, setr, setn))
    return finish()
  end
  local resn, resr = text:match("^res%s+(%d+),([abcdehl])$")
  if resn and resr then
    add(string.format("%s = (uint8_t)(%s & ~(1u << %s));", resr, resr, resn))
    return finish()
  end

  -- bit/set/res (hl) / (iy+d) / (ix+d) - TI-OS flag bytes live here
  do
    local n = text:match("^bit%s+(%d+),%(hl%)$")
    if n then
      add(string.format("flag_set_z((mem_read8(hl()) & (1u << %s)) == 0);", n))
      return finish()
    end
    n = text:match("^set%s+(%d+),%(hl%)$")
    if n then
      add(string.format(
        "mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << %s)));", n
      ))
      return finish()
    end
    n = text:match("^res%s+(%d+),%(hl%)$")
    if n then
      add(string.format(
        "mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << %s)));", n
      ))
      return finish()
    end
    local xy, off
    n, xy, off = text:match("^bit%s+(%d+),%((i[xy])%+(0x%x+)%)$")
    if n and xy and off then
      add(string.format(
        "flag_set_z((mem_read8((uint16_t)(%s + %s)) & (1u << %s)) == 0);",
        xy, off, n
      ))
      return finish()
    end
    n, xy, off = text:match("^set%s+(%d+),%((i[xy])%+(0x%x+)%)$")
    if n and xy and off then
      add(string.format(
        "mem_write8((uint16_t)(%s + %s), (uint8_t)(mem_read8((uint16_t)(%s + %s)) | (1u << %s)));",
        xy, off, xy, off, n
      ))
      return finish()
    end
    n, xy, off = text:match("^res%s+(%d+),%((i[xy])%+(0x%x+)%)$")
    if n and xy and off then
      add(string.format(
        "mem_write8((uint16_t)(%s + %s), (uint8_t)(mem_read8((uint16_t)(%s + %s)) & ~(1u << %s)));",
        xy, off, xy, off, n
      ))
      return finish()
    end
  end

  if text:match("^bit%s+") or text:match("^set%s+") or text:match("^res%s+") then
    add(string.format("/* %s */", text))
    return finish()
  end
  if text == "rla" then add("cpu_rla();") return finish() end
  if text == "rra" then add("cpu_rra();") return finish() end
  if text == "rlca" then add("cpu_rlca();") return finish() end
  if text == "rrca" then add("cpu_rrca();") return finish() end
  if text == "ld a,i" then add("cpu_ld_a_i();") return finish() end
  if text == "cp (hl)" then add("cpu_cp_hl();") return finish() end
  if text == "ldi" then add("cpu_ldi();") return finish() end
  if text == "sbc hl,bc" then add("cpu_sbc_hl_bc();") return finish() end
  if text == "sbc hl,de" then add("cpu_sbc_hl_de();") return finish() end
  if text == "sbc hl,hl" then add("cpu_sbc_hl_hl();") return finish() end
  if text == "sbc hl,sp" then add("cpu_sbc_hl_sp();") return finish() end

  do
    local nn = text:match("^ld%s+de,%((0x%x+)%)$")
    if nn then
      add(string.format("set_de(mem_read16(%s));", nn))
      return finish()
    end
    nn = text:match("^ld%s+%((0x%x+)%),de$")
    if nn then
      add(string.format("mem_write16(%s, de());", nn))
      return finish()
    end
    nn = text:match("^ld%s+bc,%((0x%x+)%)$")
    if nn then
      add(string.format("set_bc(mem_read16(%s));", nn))
      return finish()
    end
  end

  if text == "ldir" then
    add("while (bc() != 0) { cpu_ldi(); }")
    return finish()
  end
  if text:match("^outi") or text:match("^ini") or text == "otir" or text == "indr" then
    add(string.format("/* %s */", text))
    return finish()
  end

  -- and/or/xor/cp immediate (when not folded into insn fields)
  if text:match("^and%s+0x%x+$") then
    local v = text:match("(0x%x+)$")
    add(string.format("a = a & %s;", v))
    add("flag_logic(a);")
    return finish()
  end
  if text:match("^or%s+0x%x+$") then
    local v = text:match("(0x%x+)$")
    add(string.format("a = a | %s;", v))
    add("flag_logic(a);")
    return finish()
  end
  if text:match("^xor%s+0x%x+$") then
    local v = text:match("(0x%x+)$")
    add(string.format("a = a ^ %s;", v))
    add("flag_logic(a);")
    return finish()
  end

  add(string.format("/* %s */", text))
  return finish()
end

function Recover.hw_prelude()
  return [[
// Hardware abstraction for recovered TI-OS Tiny-C.
// Implement these on each host; link/MMU are intentionally soft stubs.

// Port numbers (match TI-83+ ASIC)
// PORT_LINK=0x00 PORT_KEYPAD=0x01 PORT_STATUS=0x02
// PORT_INTMASK=0x03 PORT_MMU_A=0x06 PORT_MMU_B=0x07
// PORT_LCD_CMD=0x10 PORT_LCD_DATA=0x11 PORT_SE_STATUS=0x20

byte PORT_LINK;
byte PORT_KEYPAD;
byte PORT_STATUS;
byte PORT_INTMASK;
byte PORT_INTACK;
byte PORT_ASYN;
byte PORT_MMU_A;
byte PORT_MMU_B;
byte PORT_LCD_CMD;
byte PORT_LCD_DATA;
byte PORT_SE_STATUS;

void hw_init_ports() {
  PORT_LINK = 0x00;
  PORT_KEYPAD = 0x01;
  PORT_STATUS = 0x02;
  PORT_INTMASK = 0x03;
  PORT_INTACK = 0x04;
  PORT_ASYN = 0x05;
  PORT_MMU_A = 0x06;
  PORT_MMU_B = 0x07;
  PORT_LCD_CMD = 0x10;
  PORT_LCD_DATA = 0x11;
  PORT_SE_STATUS = 0x20;
}

byte hw_in(byte port);
void hw_out(byte port, byte val);

byte link_in();
void link_out(byte v);
void mmu_set_bank_a(byte page);
void mmu_set_bank_b(byte page);

byte flag_z();
byte flag_nz();
byte flag_c();
byte flag_nc();
byte flag_pe();
byte flag_po();
byte flag_p();
byte flag_m();
void flag_cmp(byte left, byte right);
void flag_logic(byte result);
void flag_set_z(byte v);

byte mem_read8(word addr);
void mem_write8(word addr, byte v);
word mem_read16(word addr);
void mem_write16(word addr, word v);
word hl();
word bc();
word de();
void set_hl(word v);
void set_bc(word v);
void set_de(word v);
word sp;
void cpu_push_af();
void cpu_push_bc();
void cpu_push_de();
void cpu_push_hl();
void cpu_pop_af();
void cpu_pop_bc();
void cpu_pop_de();
void cpu_pop_hl();
void cpu_ex_de_hl();
void cpu_exx();
void cpu_ex_af();
void halt();

/* TI-OS RST 28h ROM calls - stub on host ports */
void os_bcall(word id);

/* Call into another flash page mapped at 0x4000 */
void os_banked_call(word cpu_addr);

void link_io_stub();
]]
end

function Recover.hw_prelude_c()
  return [[
/* Auto-generated note: host implements ti_cpu.h + ti_hw_api.h + ti_mem.h */
]]
end

local function base_infer_name(name)
  if not name then return nil end
  -- strip trailing _2 uniqueness suffixes for curated match
  local base = name:match("^(.-)_%d+$") or name
  return base
end

--- Recover one flash page.
-- opts.dialect: "tc" (Tiny-C, default) or "c" (ISO C, global Z80 regs)
-- opts.page selects bank window (0 -> 0x0000, else -> 0x4000).
-- opts.cross: cpu_addr -> fully-qualified call name (usually page0)
-- opts.cross_raw: cpu_addr -> unprefixed inferred name on page0
-- opts.curated: if false, don't collapse known leaves to clean/* calls
function Recover.page_to_tc(bytes, opts)
  opts = opts or {}
  local dialect = opts.dialect or "tc"
  local is_c = dialect == "c"
  local page = opts.page or 0
  local prefix = opts.prefix or string.format("p%02d_", page)
  local infer = opts.infer ~= false
  local max_fns = opts.max_fns
  local use_curated = opts.curated ~= false
  local cross = opts.cross or {}
  local cross_raw = opts.cross_raw or {}

  local slice = bytes
  if type(bytes) ~= "string" then
    local t = {}
    for i = 0, PAGE - 1 do t[i + 1] = string.char(bytes[i] or 0) end
    slice = table.concat(t)
  end

  local view = Flash.view(slice, page, { extra_seeds = opts.extra_seeds })
  local read8 = view.read8
  local size = view.size
  local win_lo, win_hi = view.window_lo, view.window_hi

  local symbols = {}
  if infer then
    symbols = select(1, Infer.infer(read8, {
      size = size,
      seeds = view.infer_seeds,
      window_lo = win_lo,
      window_hi = win_hi,
    }))
  end

  local entries, by_addr = collect_entries(
    read8, size, symbols, view.infer_seeds, win_lo, win_hi
  )
  local entry_list = {}
  for a in pairs(entries) do
    entry_list[#entry_list + 1] = a
  end
  table.sort(entry_list)
  if max_fns and #entry_list > max_fns then
    local trimmed = {}
    for i = 1, max_fns do trimmed[i] = entry_list[i] end
    entry_list = trimmed
    local keep = {}
    for _, a in ipairs(entry_list) do keep[a] = true end
    entries = keep
  end

  local lines
  if is_c then
    lines = {
      string.format("/* Recovered from flash page %d (mechanical ASM->C) */", page),
      string.format(
        "/* cpu window %s..%s prefix=%s */",
        hex16(win_lo), hex16(win_hi - 1), prefix
      ),
      "#include \"ti_cpu.h\"",
      "#include \"ti_hw_api.h\"",
      "#include \"ti_mem.h\"",
      "",
    }
  else
    lines = {
      string.format("// Recovered from flash page %d (mechanical lift)", page),
      string.format(
        "// cpu window %s..%s prefix=%s",
        hex16(win_lo), hex16(win_hi - 1), prefix
      ),
      "#include \"hw.tc\"",
      "",
    }
  end

  for _, entry in ipairs(entry_list) do
    lines[#lines + 1] = "void " .. label_for(entry, prefix, by_addr) .. "(void);"
  end
  lines[#lines + 1] = ""

  local fn_count = 0
  local curated_n = 0
  local fmt = {
    lab = function(addr)
      addr = u16(addr)
      if by_addr[addr] then return prefix .. by_addr[addr] end
      if in_win(addr, win_lo, win_hi) then
        return prefix .. string.format("L_%04X", addr)
      end
      return hex16(addr)
    end,
    imm16 = hex16,
    port8 = port_expr,
  }

  for _, entry in ipairs(entry_list) do
    local fname = label_for(entry, prefix, by_addr)
    local raw_name = by_addr[entry]
    local curated = use_curated and raw_name and CURATED[base_infer_name(raw_name)]

    local flash_off = entry - win_lo
    lines[#lines + 1] = string.format(
      "/* flash page %d cpu %s (offset %s) */", page, hex16(entry), hex16(flash_off)
    )
    lines[#lines + 1] = "void " .. fname .. "(void) {"

    -- 0x25A2: Z80 "call" helper pops return addr from SP then jp (hl).
    -- Under C ABI that return lives on the native stack - emit a safe body.
    if is_c and entry == 0x25A2 then
      lines[#lines + 1] = "  /* C-ABI stack switch (Z80 pop-retaddr/jp hl omitted) */"
      lines[#lines + 1] = "  cpu_push_hl();"
      lines[#lines + 1] = "  b = a;"
      lines[#lines + 1] = "  a = hw_in(PORT_MMU_A);"
      lines[#lines + 1] = "  cpu_push_af();"
      lines[#lines + 1] = "  a = b;"
      lines[#lines + 1] = "  set_hl(mem_read16(0x86DE));"
      lines[#lines + 1] = "  cpu_push_hl();"
      lines[#lines + 1] = "  set_bc(mem_read16(0x9822));"
      lines[#lines + 1] = "  set_hl(mem_read16(0x9824));"
      lines[#lines + 1] = "  a = a | a;"
      lines[#lines + 1] = "  flag_logic(a);"
      lines[#lines + 1] = "  cpu_sbc_hl_bc();"
      lines[#lines + 1] = "  cpu_push_hl();"
      lines[#lines + 1] = "  set_bc(mem_read16(0x9826));"
      lines[#lines + 1] = "  set_hl(mem_read16(0x9828));"
      lines[#lines + 1] = "  cpu_sbc_hl_bc();"
      lines[#lines + 1] = "  cpu_push_hl();"
      lines[#lines + 1] = "  mem_write16(0x86DE, sp);"
      lines[#lines + 1] = "}"
      lines[#lines + 1] = ""
      fn_count = fn_count + 1
    elseif curated then
      curated_n = curated_n + 1
      lines[#lines + 1] = "  /* CURATED -> " .. curated .. " */"
      if curated == "key_scan" then
        if not is_c then lines[#lines + 1] = "  byte a;" end
        lines[#lines + 1] = "  a = key_scan(a);"
      elseif curated == "mmu_set_bank_a" or curated == "mmu_set_bank_b" then
        if not is_c then lines[#lines + 1] = "  byte a;" end
        lines[#lines + 1] = "  " .. curated .. "(a);"
      elseif curated == "link_io_stub" then
        lines[#lines + 1] = "  link_io_stub();"
      else
        lines[#lines + 1] = "  " .. curated .. "();"
      end
      lines[#lines + 1] = "}"
      lines[#lines + 1] = ""
      fn_count = fn_count + 1
    else
      local body_addrs, visited = collect_fn_body(
        read8, entry, win_lo, win_hi, entries, opts.max_insns_per_fn or 1024
      )
      local need_label = {}
      for _, a in ipairs(body_addrs) do
        local insn = Disasm.decode(read8, a)
        if insn and insn.branch and insn.branch ~= 0x28 then
          local t = u16(insn.branch)
          if visited[t] and (not entries[t] or t == entry) then
            need_label[t] = true
          end
        end
      end

      -- Shared epilogue tails (e.g. ISR 0x0080) get pulled into callees via
      -- backward edges. Sorted emission would run that tail first and return
      -- before the real entry - always enter at the true entry address.
      if #body_addrs > 0 and body_addrs[1] ~= entry then
        need_label[entry] = true
      end

      if not is_c then
        lines[#lines + 1] = "  byte a;"
        lines[#lines + 1] = "  byte b;"
        lines[#lines + 1] = "  byte c;"
        lines[#lines + 1] = "  byte d;"
        lines[#lines + 1] = "  byte e;"
        lines[#lines + 1] = "  byte h;"
        lines[#lines + 1] = "  byte l;"
      end

      if #body_addrs > 0 and body_addrs[1] ~= entry then
        lines[#lines + 1] = "  goto " .. goto_lab(entry, prefix, by_addr) .. ";"
      end

      for _, a in ipairs(body_addrs) do
        if need_label[a] then
          lines[#lines + 1] = "  " .. goto_lab(a, prefix, by_addr) .. ": ;"
        end
        local insn = Disasm.decode(read8, a, fmt)
        if insn then
          local ctx = {
            prefix = prefix,
            by_addr = by_addr,
            size = win_hi,
            win_lo = win_lo,
            win_hi = win_hi,
            entries = entries,
            entry = entry,
            read8 = read8,
            addr = a,
            cross = cross,
            cross_raw = cross_raw,
            dialect = dialect,
            in_body = visited,
          }
          for _, ln in ipairs(emit_insn(insn, ctx)) do
            -- Tiny-C has no uint8_t - strip casts
            if not is_c then
              ln = ln:gsub("%(uint8_t%)", "")
              ln = ln:gsub("%(uint16_t%)", "")
            end
            lines[#lines + 1] = "  " .. ln
          end
        end
      end

      lines[#lines + 1] = "}"
      lines[#lines + 1] = ""
      fn_count = fn_count + 1
    end
  end

  return table.concat(lines, "\n"), {
    functions = fn_count,
    curated = curated_n,
    entries = #entry_list,
    page = page,
    window_lo = win_lo,
    by_addr = by_addr,
    dialect = dialect,
  }
end

function Recover.page_to_c(bytes, opts)
  opts = opts or {}
  opts.dialect = "c"
  return Recover.page_to_tc(bytes, opts)
end

Recover.CURATED = CURATED

return Recover
