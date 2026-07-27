-- Tiny-C AST -> Z80 assembly text
-- Locals/params/globals -> RAM slots at 0xC080+; string literals in ROM.

local Natives = require("lang.natives")

local function codegen(ast, opts)
  opts = opts or {}
  local no_crt = opts.no_crt == true
  local code_org = opts.code_org -- optional org for no_crt blobs
  local target_app = opts.target == "app" or opts.app == true
  local app_name = opts.app_name or opts.name or "TINYAPP"
  if type(app_name) ~= "string" or app_name == "" then
    app_name = "TINYAPP"
  end
  app_name = app_name:upper():gsub("[^A-Z0-9]", "")
  if #app_name > 8 then
    app_name = app_name:sub(1, 8)
  end
  if #app_name < 1 then
    app_name = "TINYAPP"
  end

  local lines = {}
  local strings = {}
  local str_count = 0
  local label_count = 0
  -- Bare-metal demos use 0xC080; Flash Apps use appBackUpScreen (WikiTI 9872h).
  local ram_next = target_app and 0x9872 or 0xC080
  local slots = {}
  local current_fn = nil
  local current_osabi = false
  local current_saveaf = false
  local current_osabi_push_bc = false
  local osabi_byte_param = nil -- param name shadowed in C (no RAM; safe for TI-OS)
  local osabi_reg_locals = {} -- name -> "d"|"e" for osabi byte locals
  local fn_ret = "void"
  local funcs_by_name = {}
  local need_lcd = false
  local need_text = false
  local need_gfx = false
  local need_math = false
  local need_arith = false
  local need_key = false
  local need_os = false
  local need_entropy = false
  local ram_limit = target_app and (0x9872 + 768) or (0xC080 + 0x3000)
  local break_stack = {}
  local continue_stack = {}
  local fn_pages = opts.fn_pages -- optional name -> page index
  local n_pages = opts.n_pages or 1
  if n_pages < 1 then n_pages = 1 end
  if n_pages > 14 then
    error("Flash App exceeds 14 archive pages (224KB max)")
  end
  local current_emit_page = 0
  local need_far = n_pages > 1
  local strings_by_page = {}

  for _, f in ipairs(ast.funcs) do
    funcs_by_name[f.name] = f
  end
  for _, e in ipairs(ast.externs or {}) do
    funcs_by_name[e.name] = {
      tag = "extern",
      ret = e.ret,
      name = e.name,
      params = e.params,
      extern = true,
    }
  end

  local function emit(s)
    lines[#lines + 1] = s
  end

  local function fail(loc_or_node, msg)
    local loc = loc_or_node
    if type(loc_or_node) == "table" and loc_or_node.tag then
      loc = loc_or_node.loc
    end
    if loc and loc.file and loc.line then
      error(string.format("%s:%d:%d: %s", loc.file, loc.line, loc.col or 1, msg))
    end
    error(msg)
  end

  local function new_label(prefix)
    label_count = label_count + 1
    return (prefix or "L") .. "_" .. label_count
  end

  local function hex(n)
    return string.format("0x%04X", n % 65536)
  end

  local function hex8(n)
    return string.format("0x%02X", n % 256)
  end

  local function alloc_slot_for(fn, name, typ, opts_slot)
    opts_slot = opts_slot or {}
    local key = fn and (fn .. "__" .. name) or name
    if slots[key] then
      return slots[key]
    end
    local count = opts_slot.count
    local dims = opts_slot.dims
    local elem = opts_slot.elem
    -- Initialized globals live in ROM (db blob), not app RAM.
    if opts_slot.rom_init then
      slots[key] = {
        addr = 0,
        label = "__tc_g_" .. name,
        typ = typ,
        key = key,
        count = count,
        dims = dims,
        elem = elem,
        rom_init = true,
      }
      return slots[key]
    end
    local size
    if count then
      local es = (typ == "word") and 2 or 1
      size = es * count
    else
      size = (typ == "word") and 2 or 1
    end
    local addr = ram_next
    ram_next = ram_next + size
    if ram_next > ram_limit then
      error(string.format(
        "out of Tiny-C RAM (need through 0x%04X, limit 0x%04X)%s",
        ram_next - 1, ram_limit - 1,
        target_app and " - appBackUpScreen is 768 bytes at 0x9872" or ""
      ))
    end
    slots[key] = {
      addr = addr,
      typ = typ,
      key = key,
      count = count,
      dims = dims,
      elem = elem,
      array_ptr = opts_slot.array_ptr,
    }
    return slots[key]
  end

  local function slot_base_imm(slot)
    if slot.label then
      return slot.label
    end
    return hex(slot.addr)
  end

  local function emit_hl_times_const(n)
    if n <= 1 then
      return
    end
    if n == 2 then
      emit("    add hl,hl")
      return
    end
    if n == 4 then
      emit("    add hl,hl")
      emit("    add hl,hl")
      return
    end
    if n == 5 then
      emit("    ld d,h")
      emit("    ld e,l")
      emit("    add hl,hl")
      emit("    add hl,hl")
      emit("    add hl,de")
      return
    end
    if n == 8 then
      emit("    add hl,hl")
      emit("    add hl,hl")
      emit("    add hl,hl")
      return
    end
    if n == 10 then
      emit("    ld d,h")
      emit("    ld e,l")
      emit("    add hl,hl")
      emit("    add hl,hl")
      emit("    add hl,de")
      emit("    add hl,hl")
      return
    end
    need_math = true
    emit(string.format("    ld de,%s", hex(n)))
    emit("    call mul_u16")
  end

  local function dims_stride(dims, from_idx)
    local p = 1
    for i = from_idx, #dims do
      p = p * dims[i]
    end
    return p
  end

  local function flatten_index_chain(e)
    local indices = {}
    local node = e
    while node.tag == "index" do
      table.insert(indices, 1, node.index)
      node = node.base
    end
    return node, indices
  end

  local function alloc_slot(name, typ)
    return alloc_slot_for(current_fn, name, typ)
  end

  local function slot_of(name, loc)
    if current_fn then
      local key = current_fn .. "__" .. name
      if slots[key] then
        return slots[key]
      end
    end
    if slots[name] then
      return slots[name]
    end
    fail(loc, "unknown variable '" .. name .. "'")
  end

  local function intern_string(s)
    str_count = str_count + 1
    local lab = "str_" .. str_count
    local p = current_emit_page or 0
    local ent = { lab = lab, value = s }
    strings[#strings + 1] = ent
    strings_by_page[p] = strings_by_page[p] or {}
    strings_by_page[p][#strings_by_page[p] + 1] = ent
    return lab
  end

  local function label_page(name)
    if fn_pages and fn_pages[name] ~= nil then
      return fn_pages[name]
    end
    return 0 -- CRT / libs live on page 0
  end

  local function emit_funcall(name)
    local dp = label_page(name)
    if (not target_app) or n_pages <= 1 or dp == current_emit_page then
      emit("    call " .. name)
    else
      need_far = true
      emit("    call __far_call")
      emit("    dw " .. name)
      emit(string.format("    db %d", dp))
    end
  end

  local function store_a(slot)
    emit(string.format("    ld (%s),a", hex(slot.addr)))
    if slot.typ == "word" then
      emit("    xor a")
      emit(string.format("    ld (%s),a", hex(slot.addr + 1)))
    end
  end

  local function store_hl(slot)
    if slot.typ == "word" then
      emit(string.format("    ld (%s),hl", hex(slot.addr)))
    else
      emit("    ld a,l")
      emit(string.format("    ld (%s),a", hex(slot.addr)))
    end
  end

  local function to_byte_in_a(t)
    if t == "word" or t == "string" then
      emit("    ld a,l")
    end
  end

  local function to_word_in_hl(t)
    if t == "byte" then
      emit("    ld l,a")
      emit("    ld h,0")
    end
  end

  local emit_expr
  local emit_stmt
  local emit_call

  local function emit_cmp(op)
    -- A and B set; leave A=1 if true else 0 (unsigned)
    local true_l = new_label("cmp_t")
    local done_l = new_label("cmp_d")
    if op == "==" then
      emit("    cp b")
      emit("    jr z," .. true_l)
    elseif op == "!=" then
      emit("    cp b")
      emit("    jr nz," .. true_l)
    elseif op == "<" then
      emit("    cp b")
      emit("    jr c," .. true_l)
    elseif op == ">" then
      -- A > B <=> B < A
      emit("    ld c,a")
      emit("    ld a,b")
      emit("    cp c")
      emit("    jr c," .. true_l)
    elseif op == "<=" then
      emit("    cp b")
      emit("    jr z," .. true_l)
      emit("    jr c," .. true_l)
    elseif op == ">=" then
      emit("    cp b")
      emit("    jr nc," .. true_l)
    else
      error("bad cmp " .. op)
    end
    emit("    xor a")
    emit("    jr " .. done_l)
    emit(true_l .. ":")
    emit("    ld a,1")
    emit(done_l .. ":")
  end

  local function emit_cmp_word(op)
    -- HL vs DE (unsigned); leave A=1 if true else 0. Preserves neither.
    local true_l = new_label("wcmp_t")
    local done_l = new_label("wcmp_d")
    if op == "==" then
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr z," .. true_l)
    elseif op == "!=" then
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr nz," .. true_l)
    elseif op == "<" then
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr c," .. true_l)
    elseif op == ">" then
      emit("    ex de,hl")
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr c," .. true_l)
    elseif op == "<=" then
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr z," .. true_l)
      emit("    jr c," .. true_l)
    elseif op == ">=" then
      emit("    or a")
      emit("    sbc hl,de")
      emit("    jr nc," .. true_l)
    else
      error("bad word cmp " .. op)
    end
    emit("    xor a")
    emit("    jr " .. done_l)
    emit(true_l .. ":")
    emit("    ld a,1")
    emit(done_l .. ":")
  end

  emit_call = function(e)
    if Natives.is_native(e.name) then
      -- Flash Apps may use LCD pixel natives (cards/UI). Bare-metal keypad only.
      if target_app and (e.name == "key_scan" or e.name == "key_wait" or e.name == "key_down") then
        error("'" .. e.name .. "' is bare-metal only; use os_get_key in Flash Apps")
      end
      if e.name == "os_clr_lcd" then
        if not target_app then error("os_clr_lcd requires target=app") end
        need_os = true
        emit_funcall("os_clr_lcd")
        return "void"
      elseif e.name == "os_home_up" then
        if not target_app then error("os_home_up requires target=app") end
        need_os = true
        emit_funcall("os_home_up")
        return "void"
      elseif e.name == "os_newline" then
        if not target_app then error("os_newline requires target=app") end
        need_os = true
        emit_funcall("os_newline")
        return "void"
      elseif e.name == "os_put_str" then
        if not target_app then error("os_put_str requires target=app") end
        if #e.args ~= 1 then error("os_put_str(str)") end
        need_os = true
        local t = emit_expr(e.args[1])
        if t ~= "string" and t ~= "word" then
          error("os_put_str: string literal required")
        end
        -- HL already holds string address from emit_expr for string literals
        emit_funcall("os_put_str")
        return "void"
      elseif e.name == "os_get_key" then
        if not target_app then error("os_get_key requires target=app") end
        if #e.args ~= 0 then error("os_get_key()") end
        need_os = true
        emit_funcall("os_get_key")
        return "byte"
      elseif e.name == "os_exit" then
        if not target_app then error("os_exit requires target=app") end
        need_os = true
        emit_funcall("os_exit")
        return "void"
      elseif e.name == "entropy" then
        if #e.args ~= 0 then error("entropy()") end
        need_entropy = true
        emit_funcall("entropy")
        return "word"
      elseif e.name == "lcd_init" then
        need_lcd = true
        emit_funcall("lcd_init")
        return "void"
      elseif e.name == "lcd_clear" then
        need_lcd = true
        emit_funcall("lcd_clear")
        return "void"
      elseif e.name == "halt" then
        emit("    halt")
        return "void"
      elseif e.name == "draw_string" then
        if #e.args ~= 3 then error("draw_string(col,row,str)") end
        need_lcd = true
        need_text = true
        local t0 = emit_expr(e.args[1])
        to_byte_in_a(t0)
        emit("    push af")
        local t1 = emit_expr(e.args[2])
        to_byte_in_a(t1)
        emit("    push af")
        local t2 = emit_expr(e.args[3])
        if t2 ~= "string" and t2 ~= "word" then
          error("draw_string: string literal required")
        end
        emit("    pop af")
        emit("    ld c,a")
        emit("    pop af")
        emit("    ld b,a")
        emit_funcall("draw_string")
        return "void"
      elseif e.name == "draw_pixel" then
        if #e.args ~= 2 then error("draw_pixel(x,y)") end
        need_lcd = true
        need_gfx = true
        local tx = emit_expr(e.args[1])
        to_byte_in_a(tx)
        emit("    push af")
        local ty = emit_expr(e.args[2])
        to_byte_in_a(ty)
        emit("    ld c,a")
        emit("    pop af")
        emit("    ld b,a")
        emit_funcall("draw_pixel")
        return "void"
      elseif e.name == "clear_pixel" then
        if #e.args ~= 2 then error("clear_pixel(x,y)") end
        need_lcd = true
        need_gfx = true
        local tx = emit_expr(e.args[1])
        to_byte_in_a(tx)
        emit("    push af")
        local ty = emit_expr(e.args[2])
        to_byte_in_a(ty)
        emit("    ld c,a")
        emit("    pop af")
        emit("    ld b,a")
        emit_funcall("clear_pixel")
        return "void"
      elseif e.name == "erase_rect" then
        if #e.args ~= 4 then error("erase_rect(x,y,w,h)") end
        need_lcd = true
        need_gfx = true
        local tx = emit_expr(e.args[1])
        to_byte_in_a(tx)
        emit("    push af")
        local ty = emit_expr(e.args[2])
        to_byte_in_a(ty)
        emit("    push af")
        local tw = emit_expr(e.args[3])
        to_byte_in_a(tw)
        emit("    push af")
        local th = emit_expr(e.args[4])
        to_byte_in_a(th)
        emit("    ld e,a")
        emit("    pop af")
        emit("    ld d,a")
        emit("    pop af")
        emit("    ld c,a")
        emit("    pop af")
        emit("    ld b,a")
        emit_funcall("erase_rect")
        return "void"
      elseif e.name == "key_scan" then
        if #e.args ~= 0 then error("key_scan()") end
        need_key = true
        emit_funcall("key_scan")
        return "byte"
      elseif e.name == "key_wait" then
        if #e.args ~= 0 then error("key_wait()") end
        need_key = true
        emit_funcall("key_wait")
        return "byte"
      elseif e.name == "key_down" then
        if #e.args ~= 1 then error("key_down(code)") end
        need_key = true
        local tk = emit_expr(e.args[1])
        to_byte_in_a(tk)
        emit_funcall("key_down")
        return "byte"
      elseif e.name == "poke" then
        if #e.args ~= 2 then error("poke(addr,val)") end
        local ta = emit_expr(e.args[1])
        to_word_in_hl(ta)
        emit("    push hl")
        local tv = emit_expr(e.args[2])
        to_byte_in_a(tv)
        emit("    pop hl")
        emit("    ld (hl),a")
        return "void"
      elseif e.name == "peek" then
        if #e.args ~= 1 then error("peek(addr)") end
        local ta = emit_expr(e.args[1])
        to_word_in_hl(ta)
        emit("    ld a,(hl)")
        return "byte"
      elseif e.name == "fmul" then
        if #e.args ~= 2 then error("fmul(a,b)") end
        need_math = true
        local ta = emit_expr(e.args[1])
        to_word_in_hl(ta)
        emit("    push hl")
        local tb = emit_expr(e.args[2])
        to_word_in_hl(tb)
        emit("    pop de")
        emit_funcall("mul_q88")
        return "word"
      elseif e.name == "in_port" then
        if #e.args ~= 1 then error("in_port(port)") end
        local port = e.args[1]
        if port.tag == "number" then
          emit(string.format("    in a,(%s)", hex8(port.value)))
        else
          local tp = emit_expr(port)
          to_byte_in_a(tp)
          emit("    ld c,a")
          emit("    in a,(c)")
        end
        return "byte"
      elseif e.name == "out_port" then
        if #e.args ~= 2 then error("out_port(port,val)") end
        local port, val = e.args[1], e.args[2]
        if port.tag == "number" then
          local tv = emit_expr(val)
          to_byte_in_a(tv)
          emit(string.format("    out (%s),a", hex8(port.value)))
        else
          local tv = emit_expr(val)
          to_byte_in_a(tv)
          emit("    push af")
          local tp = emit_expr(port)
          to_byte_in_a(tp)
          emit("    ld c,a")
          emit("    pop af")
          emit("    out (c),a")
        end
        return "void"
      end
      error("native " .. e.name)
    end

    local fdef = funcs_by_name[e.name]
    if not fdef then
      fail(e, "unknown function '" .. e.name .. "'")
    end
    if #e.args ~= #fdef.params then
      fail(e, e.name .. ": wrong number of arguments")
    end
    -- osabi / extern: byte arg in A (TI-OS style); else Tiny-C RAM slots
    if fdef.osabi or fdef.extern then
      if #e.args == 1 and fdef.params[1].typ == "byte" then
        local t = emit_expr(e.args[1])
        to_byte_in_a(t)
      elseif #e.args == 1 and fdef.params[1].typ == "word" then
        local t = emit_expr(e.args[1])
        to_word_in_hl(t)
      elseif #e.args > 1 then
        fail(e, e.name .. ": osabi/extern calls support 0-1 args")
      end
    else
      for i = 1, #e.args do
        local t = emit_expr(e.args[i])
        local p = fdef.params[i]
        local slot = alloc_slot_for(e.name, p.name, p.typ)
        if p.typ == "word" then
          to_word_in_hl(t)
          store_hl(slot)
        else
          to_byte_in_a(t)
          store_a(slot)
        end
      end
    end
    emit_funcall(e.name)
    if fdef.ret == "void" then
      return "void"
    elseif fdef.ret == "word" then
      return "word"
    else
      return "byte"
    end
  end

  -- Leave HL pointing at the indexed element; return element type (byte/word).
  local function emit_index_addr(e)
    local base, indices = flatten_index_chain(e)
    local elem_typ = "byte"
    local elem_size = 1

    if base.tag ~= "var" then
      if #indices ~= 1 then
        fail(e, "multi-dimensional index requires an array variable")
      end
      local tb = emit_expr(base)
      to_word_in_hl(tb)
      emit("    push hl")
      local ti = emit_expr(indices[1])
      to_word_in_hl(ti)
      emit("    pop de")
      emit("    add hl,de")
      return "byte"
    end

    local slot = slot_of(base.name, base.loc)
    local dims = nil
    local indirect = false

    if slot.count then
      elem_typ = slot.typ
      elem_size = (elem_typ == "word") and 2 or 1
      dims = slot.dims or { slot.count }
    elseif slot.typ == "word" or slot.array_ptr then
      elem_typ = slot.elem or "byte"
      elem_size = (elem_typ == "word") and 2 or 1
      dims = slot.dims
      indirect = true
    else
      fail(e, "cannot index non-array '" .. base.name .. "'")
    end

    if dims then
      if #indices > #dims then
        fail(e, "too many indices for array '" .. base.name .. "'")
      end
      emit("    ld hl,0")
      for k, idx_expr in ipairs(indices) do
        local stride = dims_stride(dims, k + 1)
        emit("    push hl")
        local ti = emit_expr(idx_expr)
        to_word_in_hl(ti)
        emit_hl_times_const(stride)
        emit("    pop de")
        emit("    add hl,de")
      end
      if elem_size == 2 then
        emit("    add hl,hl")
      end
    else
      if #indices ~= 1 then
        fail(e, "too many indices for array '" .. base.name .. "'")
      end
      local ti = emit_expr(indices[1])
      to_word_in_hl(ti)
      if elem_size == 2 then
        emit("    add hl,hl")
      end
    end

    if indirect then
      emit("    push hl")
      emit(string.format("    ld hl,(%s)", hex(slot.addr)))
      emit("    pop de")
      emit("    add hl,de")
    else
      emit(string.format("    ld de,%s", slot_base_imm(slot)))
      emit("    add hl,de")
    end
    return elem_typ
  end

  emit_expr = function(e)
    if e.tag == "number" then
      if e.value > 255 then
        emit(string.format("    ld hl,%s", hex(e.value)))
        return "word"
      end
      emit(string.format("    ld a,%s", hex8(e.value)))
      return "byte"
    elseif e.tag == "string" then
      local lab = intern_string(e.value)
      emit(string.format("    ld hl,%s", lab))
      return "string"
    elseif e.tag == "var" then
      if osabi_byte_param and e.name == osabi_byte_param then
        emit("    ld a,c")
        return "byte"
      end
      local reg = osabi_reg_locals[e.name]
      if reg then
        emit("    ld a," .. reg)
        return "byte"
      end
      local slot = slot_of(e.name, e.loc)
      -- Array name decays to base address (word).
      if slot.count then
        emit(string.format("    ld hl,%s", slot_base_imm(slot)))
        return "word"
      end
      if slot.typ == "word" then
        emit(string.format("    ld hl,(%s)", hex(slot.addr)))
        return "word"
      end
      emit(string.format("    ld a,(%s)", hex(slot.addr)))
      return "byte"
    elseif e.tag == "index" then
      local elem_typ = emit_index_addr(e)
      if elem_typ == "word" then
        emit("    ld e,(hl)")
        emit("    inc hl")
        emit("    ld d,(hl)")
        emit("    ex de,hl")
        return "word"
      end
      emit("    ld a,(hl)")
      return "byte"
    elseif e.tag == "unary" then
      local t = emit_expr(e.expr)
      if e.op == "-" then
        if t == "word" then
          emit("    xor a")
          emit("    sub l")
          emit("    ld l,a")
          emit("    ld a,0")
          emit("    sbc a,h")
          emit("    ld h,a")
          return "word"
        end
        emit("    ld b,a")
        emit("    xor a")
        emit("    sub b")
        return "byte"
      end
      error("bad unary " .. e.op)
    elseif e.tag == "binop" then
      local cmp = {
        ["=="] = true, ["!="] = true, ["<"] = true, [">"] = true,
        ["<="] = true, [">="] = true,
      }
      local force_word = {
        ["*"] = true, ["/"] = true, ["%"] = true, ["<<"] = true, [">>"] = true,
      }

      local function emit_word_arith(op)
        if op == "+" then
          emit("    add hl,de")
          return "word"
        elseif op == "-" then
          emit("    or a")
          emit("    sbc hl,de")
          return "word"
        elseif op == "&" then
          emit("    ld a,h")
          emit("    and d")
          emit("    ld h,a")
          emit("    ld a,l")
          emit("    and e")
          emit("    ld l,a")
          return "word"
        elseif op == "|" then
          emit("    ld a,h")
          emit("    or d")
          emit("    ld h,a")
          emit("    ld a,l")
          emit("    or e")
          emit("    ld l,a")
          return "word"
        elseif op == "^" then
          emit("    ld a,h")
          emit("    xor d")
          emit("    ld h,a")
          emit("    ld a,l")
          emit("    xor e")
          emit("    ld l,a")
          return "word"
        elseif op == "*" then
          need_math = true
          emit_funcall("mul_u16")
          return "word"
        elseif op == "/" then
          need_arith = true
          emit_funcall("udiv_u16")
          return "word"
        elseif op == "%" then
          need_arith = true
          emit_funcall("umod_u16")
          return "word"
        elseif op == "<<" then
          local loop_l = new_label("shl")
          local done_l = new_label("shl_d")
          emit("    ld b,e")
          emit("    ld a,b")
          emit("    or a")
          emit("    jr z," .. done_l)
          emit(loop_l .. ":")
          emit("    add hl,hl")
          emit("    djnz " .. loop_l)
          emit(done_l .. ":")
          return "word"
        elseif op == ">>" then
          local loop_l = new_label("shr")
          local done_l = new_label("shr_d")
          emit("    ld b,e")
          emit("    ld a,b")
          emit("    or a")
          emit("    jr z," .. done_l)
          emit(loop_l .. ":")
          emit("    srl h")
          emit("    rr l")
          emit("    djnz " .. loop_l)
          emit(done_l .. ":")
          return "word"
        end
        error("unsupported op " .. op)
      end

      local tl = emit_expr(e.left)

      if cmp[e.op] then
        if tl == "word" then
          to_word_in_hl(tl)
          emit("    push hl")
          local tr = emit_expr(e.right)
          to_word_in_hl(tr)
          emit("    ex de,hl")
          emit("    pop hl")
          emit_cmp_word(e.op)
        else
          to_byte_in_a(tl)
          emit("    push af")
          local tr = emit_expr(e.right)
          if tr == "word" then
            emit("    pop af")
            emit("    ld l,a")
            emit("    ld h,0")
            emit("    push hl")
            to_word_in_hl(tr)
            emit("    ex de,hl")
            emit("    pop hl")
            emit_cmp_word(e.op)
          else
            to_byte_in_a(tr)
            emit("    ld b,a")
            emit("    pop af")
            emit_cmp(e.op)
          end
        end
        return "byte"
      end

      if tl == "word" or force_word[e.op] then
        to_word_in_hl(tl)
        emit("    push hl")
        local tr = emit_expr(e.right)
        to_word_in_hl(tr)
        emit("    ex de,hl")
        emit("    pop hl")
        return emit_word_arith(e.op)
      end

      -- Immediate byte mask/logic: and/or/xor n (common for port & mask)
      if (e.op == "&" or e.op == "|" or e.op == "^")
          and e.right and e.right.tag == "number" and e.right.value <= 255 then
        to_byte_in_a(tl)
        local insn = ({ ["&"] = "and", ["|"] = "or", ["^"] = "xor" })[e.op]
        emit(string.format("    %s %s", insn, hex8(e.right.value)))
        return "byte"
      end

      to_byte_in_a(tl)
      emit("    push af")
      local tr = emit_expr(e.right)
      if tr == "word" then
        -- Right is already in HL (e.g. x + i*k). Do not clobber HL before using it.
        emit("    ex de,hl")
        emit("    pop af")
        emit("    ld l,a")
        emit("    ld h,0")
        return emit_word_arith(e.op)
      end
      to_byte_in_a(tr)
      emit("    ld b,a")
      emit("    pop af")
      if e.op == "+" then
        emit("    add a,b")
      elseif e.op == "-" then
        emit("    sub b")
      elseif e.op == "&" then
        emit("    and b")
      elseif e.op == "|" then
        emit("    or b")
      elseif e.op == "^" then
        emit("    xor b")
      else
        error("unsupported op " .. e.op)
      end
      return "byte"
    elseif e.tag == "call" then
      return emit_call(e)
    end
    error("bad expr " .. tostring(e.tag))
  end

  local function alloc_osabi_local(name, typ, loc)
    if typ ~= "byte" then
      fail(loc, "osabi locals must be byte (got " .. typ .. ")")
    end
    if osabi_reg_locals[name] then
      return osabi_reg_locals[name]
    end
    local n = 0
    for _ in pairs(osabi_reg_locals) do n = n + 1 end
    local reg = ({ "d", "e" })[n + 1]
    if not reg then
      fail(loc, "osabi supports at most 2 byte locals (D/E)")
    end
    osabi_reg_locals[name] = reg
    return reg
  end

  local function osabi_epilogue()
    if current_osabi_push_bc then
      emit("    pop bc")
    end
    if current_saveaf then
      emit("    pop af")
    end
  end

  -- Match (in_port(P) & M) == 0  or  != 0  -> port, mask, eq_zero
  local function match_inport_mask_cmp(cond)
    if not cond or cond.tag ~= "binop" then return nil end
    local eq_zero
    if cond.op == "==" then
      eq_zero = true
    elseif cond.op == "!=" then
      eq_zero = false
    else
      return nil
    end
    if not (cond.right and cond.right.tag == "number" and cond.right.value == 0) then
      return nil
    end
    local band = cond.left
    if not (band and band.tag == "binop" and band.op == "&") then return nil end
    if not (band.left and band.left.tag == "call" and band.left.name == "in_port"
        and #band.left.args == 1 and band.left.args[1].tag == "number"
        and band.right and band.right.tag == "number") then
      return nil
    end
    return band.left.args[1].value, band.right.value, eq_zero
  end

  emit_stmt = function(s)
    if s.tag == "block" then
      for _, st in ipairs(s.stmts) do
        emit_stmt(st)
      end
    elseif s.tag == "vardecl" then
      if s.count then
        if current_osabi then
          fail(s, "osabi cannot declare arrays")
        end
        local slot = alloc_slot_for(current_fn, s.name, s.typ, { count = s.count, dims = s.dims })
        if s.init_list then
          for i, v in ipairs(s.init_list) do
            emit(string.format("    ld a,%s", hex8(v)))
            emit(string.format("    ld (%s),a", hex(slot.addr + i - 1)))
          end
        end
      elseif current_osabi then
        alloc_osabi_local(s.name, s.typ, s.loc)
        if s.init then
          local t = emit_expr(s.init)
          to_byte_in_a(t)
          emit("    ld " .. osabi_reg_locals[s.name] .. ",a")
        end
      else
        local slot = alloc_slot(s.name, s.typ)
        if s.init then
          local t = emit_expr(s.init)
          if slot.typ == "word" then
            to_word_in_hl(t)
            store_hl(slot)
          else
            to_byte_in_a(t)
            store_a(slot)
          end
        end
      end
    elseif s.tag == "assign" then
      if current_osabi and osabi_reg_locals[s.name] then
        local t = emit_expr(s.expr)
        to_byte_in_a(t)
        emit("    ld " .. osabi_reg_locals[s.name] .. ",a")
      elseif current_osabi and osabi_byte_param and s.name == osabi_byte_param then
        local t = emit_expr(s.expr)
        to_byte_in_a(t)
        emit("    ld c,a")
      else
        local slot = slot_of(s.name, s.loc)
        if slot.count then
          fail(s, "cannot assign to array '" .. s.name .. "'")
        end
        local t = emit_expr(s.expr)
        if slot.typ == "word" then
          to_word_in_hl(t)
          store_hl(slot)
        else
          to_byte_in_a(t)
          store_a(slot)
        end
      end
    elseif s.tag == "index_assign" then
      local elem_typ = emit_index_addr(s.target)
      emit("    push hl")
      local t = emit_expr(s.expr)
      if elem_typ == "word" then
        to_word_in_hl(t)
        emit("    pop de")
        emit("    ex de,hl")
        emit("    ld (hl),e")
        emit("    inc hl")
        emit("    ld (hl),d")
      else
        to_byte_in_a(t)
        emit("    pop hl")
        emit("    ld (hl),a")
      end
    elseif s.tag == "exprstmt" then
      emit_expr(s.expr)
    elseif s.tag == "break" then
      if #break_stack == 0 then
        fail(s, "break outside loop")
      end
      emit("    jp " .. break_stack[#break_stack])
    elseif s.tag == "continue" then
      if #continue_stack == 0 then
        fail(s, "continue outside loop")
      end
      emit("    jp " .. continue_stack[#continue_stack])
    elseif s.tag == "return" then
      -- Z80 calling convention: byte in A, word in HL, void bare RET.
      if fn_ret == "void" then
        if s.expr then
          fail(s, "void function '" .. tostring(current_fn) .. "' cannot return a value")
        end
      else
        if not s.expr then
          fail(s, fn_ret .. " function '" .. tostring(current_fn) .. "' must return a value")
        end
        local t = emit_expr(s.expr)
        if fn_ret == "word" then
          to_word_in_hl(t)
        else
          to_byte_in_a(t)
        end
      end
      if current_osabi then
        osabi_epilogue()
      end
      emit("    ret")
    elseif s.tag == "if" then
      local port, mask, eq_zero = match_inport_mask_cmp(s.cond)
      local else_l = new_label("else")
      local end_l = new_label("endif")
      if port then
        emit(string.format("    in a,(%s)", hex8(port)))
        emit(string.format("    and %s", hex8(mask)))
        -- == 0 -> take then when Z; != 0 -> take then when NZ
        if eq_zero then
          emit("    jr nz," .. (s.else_block and else_l or end_l))
        else
          emit("    jr z," .. (s.else_block and else_l or end_l))
        end
      else
        local t = emit_expr(s.cond)
        to_byte_in_a(t)
        emit("    or a")
        emit("    jp z," .. (s.else_block and else_l or end_l))
      end
      emit_stmt(s.then_block)
      if s.else_block then
        emit("    jp " .. end_l)
        emit(else_l .. ":")
        emit_stmt(s.else_block)
      end
      emit(end_l .. ":")
    elseif s.tag == "while" then
      -- Peephole: while ((in_port(P) & M) == 0) {} -> tight LCD busy-wait
      local empty = s.body and s.body.stmts and #s.body.stmts == 0
      local port, mask, eq_zero = match_inport_mask_cmp(s.cond)
      local peep = empty and port and eq_zero
      if peep then
        local top = new_label("busy")
        emit(top .. ":")
        emit(string.format("    in a,(%s)", hex8(port)))
        emit(string.format("    and %s", hex8(mask)))
        emit("    jr z," .. top)
      else
        local top = new_label("while")
        local end_l = new_label("wend")
        emit(top .. ":")
        local t = emit_expr(s.cond)
        to_byte_in_a(t)
        emit("    or a")
        emit("    jp z," .. end_l)
        break_stack[#break_stack + 1] = end_l
        continue_stack[#continue_stack + 1] = top
        emit_stmt(s.body)
        break_stack[#break_stack] = nil
        continue_stack[#continue_stack] = nil
        emit("    jp " .. top)
        emit(end_l .. ":")
      end
    elseif s.tag == "for" then
      if s.init then
        emit_stmt(s.init)
      end
      local top = new_label("for")
      local cont = new_label("for_c")
      local end_l = new_label("for_e")
      emit(top .. ":")
      if s.cond then
        local t = emit_expr(s.cond)
        to_byte_in_a(t)
        emit("    or a")
        emit("    jp z," .. end_l)
      end
      break_stack[#break_stack + 1] = end_l
      continue_stack[#continue_stack + 1] = cont
      emit_stmt(s.body)
      break_stack[#break_stack] = nil
      continue_stack[#continue_stack] = nil
      emit(cont .. ":")
      if s.step then
        emit_stmt(s.step)
      end
      emit("    jp " .. top)
      emit(end_l .. ":")
    else
      error("bad stmt " .. tostring(s.tag))
    end
  end

  local function gather_locals(fn_name, block)
    for _, s in ipairs(block.stmts) do
      if s.tag == "vardecl" then
        alloc_slot_for(fn_name, s.name, s.typ, { count = s.count, dims = s.dims })
      elseif s.tag == "block" then
        gather_locals(fn_name, s)
      elseif s.tag == "if" then
        gather_locals(fn_name, s.then_block)
        if s.else_block then
          gather_locals(fn_name, s.else_block)
        end
      elseif s.tag == "while" then
        gather_locals(fn_name, s.body)
      elseif s.tag == "for" then
        if s.init and s.init.tag == "vardecl" then
          alloc_slot_for(fn_name, s.init.name, s.init.typ, {
            count = s.init.count, dims = s.init.dims,
          })
        end
        gather_locals(fn_name, s.body)
      end
    end
  end

  for _, g in ipairs(ast.globals) do
    if g.init_list then
      alloc_slot_for(nil, g.name, g.typ, {
        count = g.count, dims = g.dims, rom_init = true,
      })
    else
      alloc_slot_for(nil, g.name, g.typ, { count = g.count, dims = g.dims })
    end
  end
  for _, f in ipairs(ast.funcs) do
    for _, p in ipairs(f.params) do
      -- osabi byte params live in C, not RAM (TI-OS owns low RAM).
      if not (f.osabi and p.typ == "byte") then
        alloc_slot_for(f.name, p.name, p.typ, {
          array_ptr = p.array_decay,
          elem = p.elem,
          dims = p.dims,
        })
      end
    end
    if not f.osabi then
      gather_locals(f.name, f.body)
    end
  end

  if not no_crt and not funcs_by_name.main then
    error("program needs main()")
  end
  if target_app and no_crt then
    error("target=app cannot combine with no_crt")
  end

  emit("; generated by Tiny-C compiler")
  if target_app then
    if n_pages > 1 then
      emit("    page 0")
    end
    -- Flash App: page mapped at 0x4000. Minimal TLV header (WikiTI / z80 Heaven).
    emit("    org 0x4000")
    emit("    ; master field")
    emit("    db 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00")
    emit(string.format("    ; name (%d chars)", #app_name))
    emit(string.format("    db 0x80, 0x4%d", #app_name))
    do
      local parts = {}
      for i = 1, #app_name do
        parts[#parts + 1] = string.format("0x%02X", app_name:byte(i))
      end
      emit("    db " .. table.concat(parts, ", "))
    end
    emit("    db 0x80, 0x90          ; disable TI splash")
    emit(string.format("    db 0x80, 0x81, 0x%02X    ; %d page(s)", n_pages, n_pages))
    emit("    db 0x80, 0x12, 0x01, 0x04  ; signing key ID (83+)")
    emit("    db 0x03, 0x22, 0x09, 0x00  ; date stamp (empty)")
    emit("    db 0x02, 0x00              ; date stamp signature")
    emit("    db 0x80, 0x70              ; final field")
    emit("    ; execution starts here")
    if n_pages > 1 then
      need_far = true
      emit("    call __app_save_base")
    end
    emit("    jp main")
  elseif no_crt then
    if code_org then
      emit(string.format("    org %s", hex(code_org)))
    end
  else
    emit("    org 0x0000")
    emit("    jp main")
    emit("")
    emit("    org 0x0038")
    emit("    ei")
    emit("    reti")
    emit("")
    emit("    org 0x0100")
  end

  local function block_ends_with_return(block)
    if not block or not block.stmts or #block.stmts == 0 then
      return false
    end
    return block.stmts[#block.stmts].tag == "return"
  end

  local function emit_one_func(f)
    if f.ret ~= "void" and f.ret ~= "byte" and f.ret ~= "word" then
      error("function '" .. f.name .. "' return type must be void, byte, or word")
    end
    if no_crt and f.name == "main" then
      return
    end
    current_fn = f.name
    current_emit_page = label_page(f.name)
    current_osabi = f.osabi == true
    current_saveaf = f.saveaf == true
    current_osabi_push_bc = false
    osabi_byte_param = nil
    osabi_reg_locals = {}
    fn_ret = f.ret
    emit("")
    emit(f.name .. ":")
    if f.osabi then
      if f.saveaf then
        emit("    push af")
      end
      local need_bc = (#f.params == 1 and f.params[1].typ == "byte")
        or f.ret ~= "void"
        or (not f.saveaf)
      if f.saveaf and f.ret == "void" and #f.params == 0 then
        need_bc = false
      end
      current_osabi_push_bc = need_bc
      if current_osabi_push_bc then
        emit("    push bc")
      end
    end
    if f.osabi and #f.params == 1 and f.params[1].typ == "byte" then
      osabi_byte_param = f.params[1].name
      emit("    ld c,a")
    elseif f.osabi and #f.params == 1 and f.params[1].typ == "word" then
      local slot = alloc_slot_for(f.name, f.params[1].name, "word")
      store_hl(slot)
    end
    if f.name == "main" then
      if f.ret ~= "void" then
        error("main() must be void")
      end
      if not target_app then
        emit("    ld sp,0xFFFE")
      end
      for _, g in ipairs(ast.globals) do
        if g.init then
          local slot = slots[g.name]
          local t = emit_expr(g.init)
          if slot.typ == "word" then
            to_word_in_hl(t)
            store_hl(slot)
          else
            to_byte_in_a(t)
            store_a(slot)
          end
        end
      end
    end
    emit_stmt(f.body)
    if f.osabi then
      if not block_ends_with_return(f.body) then
        osabi_epilogue()
        emit("    ret")
      end
    elseif not block_ends_with_return(f.body) then
      if target_app and f.name == "main" then
        need_os = true
        emit_funcall("os_exit")
      else
        emit("    ret")
      end
    end
  end

  local function emit_rom_arrays()
    local any = false
    for _, g in ipairs(ast.globals) do
      if g.init_list then
        local slot = slots[g.name]
        if not any then
          emit("")
          any = true
        end
        emit(slot.label .. ":")
        local vals = g.init_list
        for i = 1, #vals, 16 do
          local parts = {}
          for j = i, math.min(i + 15, #vals) do
            parts[#parts + 1] = string.format("0x%02X", vals[j] % 256)
          end
          emit("    db " .. table.concat(parts, ", "))
        end
      end
    end
  end

  local function emit_strings_for_page(p)
    local list = strings_by_page[p]
    if not list or #list == 0 then return end
    emit("")
    for _, s in ipairs(list) do
      emit(s.lab .. ":")
      emit(string.format('    db "%s",0', s.value))
    end
  end

  local function emit_page0_libs()
    if need_far then
      emit("")
      emit('    include "asm/lib/app_far.asm"')
    end
    if need_os then
      emit("")
      emit('    include "asm/lib/os_bcall.asm"')
    end
    if need_arith then
      emit("")
      emit('    include "asm/lib/arith.asm"')
    end
    if need_lcd or need_text or need_gfx or need_math or need_key or need_entropy then
      emit("")
      if need_lcd then
        emit('    include "asm/lib/lcd.asm"')
      end
      if need_text then
        emit('    include "asm/lib/text.asm"')
      end
      if need_gfx then
        emit('    include "asm/lib/gfx.asm"')
      end
      if need_math then
        emit('    include "asm/lib/math.asm"')
      end
      if need_key then
        emit('    include "asm/lib/key.asm"')
      end
      if need_entropy then
        emit('    include "asm/lib/entropy.asm"')
      end
    end
    if need_text then
      emit("")
      emit("font:")
      emit("    blob font8")
      emit("ascii_map:")
      emit("    blob ascii_map")
    end
  end

  if target_app and n_pages > 1 then
    -- Emit functions grouped by flash page; libs + strings per page.
    for p = 0, n_pages - 1 do
      if p > 0 then
        emit("")
        emit(string.format("    page %d", p))
        emit("    org 0x4000")
      end
      current_emit_page = p
      for _, f in ipairs(ast.funcs) do
        if label_page(f.name) == p then
          emit_one_func(f)
        end
      end
      if p == 0 then
        emit_page0_libs()
        emit_rom_arrays()
      end
      emit_strings_for_page(p)
    end
  else
    for _, f in ipairs(ast.funcs) do
      emit_one_func(f)
    end
    emit_page0_libs()
    emit_rom_arrays()
    if #strings > 0 then
      emit("")
      for _, s in ipairs(strings) do
        emit(s.lab .. ":")
        emit(string.format('    db "%s",0', s.value))
      end
    end
  end

  return table.concat(lines, "\n") .. "\n"
end

return { codegen = codegen }
