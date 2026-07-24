-- Tiny-C AST -> Z80 assembly text
-- Locals/params/globals -> RAM slots at 0xC080+; string literals in ROM.

local Natives = require("lang.natives")

local function codegen(ast)
  local lines = {}
  local strings = {}
  local str_count = 0
  local label_count = 0
  local ram_next = 0xC080
  local slots = {}
  local current_fn = nil
  local fn_ret = "void"
  local funcs_by_name = {}
  local need_lcd = false
  local need_text = false
  local need_gfx = false
  local need_math = false
  local need_key = false

  for _, f in ipairs(ast.funcs) do
    funcs_by_name[f.name] = f
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

  local function alloc_slot_for(fn, name, typ)
    local key = fn and (fn .. "__" .. name) or name
    if slots[key] then
      return slots[key]
    end
    local size = (typ == "word") and 2 or 1
    local addr = ram_next
    ram_next = ram_next + size
    slots[key] = { addr = addr, typ = typ, key = key }
    return slots[key]
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
    strings[#strings + 1] = { lab = lab, value = s }
    return lab
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
      if e.name == "lcd_init" then
        need_lcd = true
        emit("    call lcd_init")
        return "void"
      elseif e.name == "lcd_clear" then
        need_lcd = true
        emit("    call lcd_clear")
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
        emit("    call draw_string")
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
        emit("    call draw_pixel")
        return "void"
      elseif e.name == "key_scan" then
        if #e.args ~= 0 then error("key_scan()") end
        need_key = true
        emit("    call key_scan")
        return "byte"
      elseif e.name == "key_wait" then
        if #e.args ~= 0 then error("key_wait()") end
        need_key = true
        emit("    call key_wait")
        return "byte"
      elseif e.name == "key_down" then
        if #e.args ~= 1 then error("key_down(code)") end
        need_key = true
        local tk = emit_expr(e.args[1])
        to_byte_in_a(tk)
        emit("    call key_down")
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
        emit("    call mul_q88")
        return "word"
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
    emit("    call " .. e.name)
    if fdef.ret == "void" then
      return "void"
    elseif fdef.ret == "word" then
      return "word"
    else
      return "byte"
    end
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
      local slot = slot_of(e.name, e.loc)
      if slot.typ == "word" then
        emit(string.format("    ld hl,(%s)", hex(slot.addr)))
        return "word"
      end
      emit(string.format("    ld a,(%s)", hex(slot.addr)))
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
        ["*"] = true, ["/"] = true, ["<<"] = true, [">>"] = true,
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
          emit("    call mul_u16")
          return "word"
        elseif op == "/" then
          error("division '/' not implemented yet")
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

  emit_stmt = function(s)
    if s.tag == "block" then
      for _, st in ipairs(s.stmts) do
        emit_stmt(st)
      end
    elseif s.tag == "vardecl" then
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
    elseif s.tag == "assign" then
      local slot = slot_of(s.name, s.loc)
      local t = emit_expr(s.expr)
      if slot.typ == "word" then
        to_word_in_hl(t)
        store_hl(slot)
      else
        to_byte_in_a(t)
        store_a(slot)
      end
    elseif s.tag == "exprstmt" then
      emit_expr(s.expr)
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
      emit("    ret")
    elseif s.tag == "if" then
      local t = emit_expr(s.cond)
      to_byte_in_a(t)
      local else_l = new_label("else")
      local end_l = new_label("endif")
      emit("    or a")
      emit("    jp z," .. (s.else_block and else_l or end_l))
      emit_stmt(s.then_block)
      if s.else_block then
        emit("    jp " .. end_l)
        emit(else_l .. ":")
        emit_stmt(s.else_block)
      end
      emit(end_l .. ":")
    elseif s.tag == "while" then
      local top = new_label("while")
      local end_l = new_label("wend")
      emit(top .. ":")
      local t = emit_expr(s.cond)
      to_byte_in_a(t)
      emit("    or a")
      emit("    jp z," .. end_l)
      emit_stmt(s.body)
      emit("    jp " .. top)
      emit(end_l .. ":")
    else
      error("bad stmt " .. tostring(s.tag))
    end
  end

  local function gather_locals(fn_name, block)
    for _, s in ipairs(block.stmts) do
      if s.tag == "vardecl" then
        alloc_slot_for(fn_name, s.name, s.typ)
      elseif s.tag == "block" then
        gather_locals(fn_name, s)
      elseif s.tag == "if" then
        gather_locals(fn_name, s.then_block)
        if s.else_block then
          gather_locals(fn_name, s.else_block)
        end
      elseif s.tag == "while" then
        gather_locals(fn_name, s.body)
      end
    end
  end

  for _, g in ipairs(ast.globals) do
    alloc_slot_for(nil, g.name, g.typ)
  end
  for _, f in ipairs(ast.funcs) do
    for _, p in ipairs(f.params) do
      alloc_slot_for(f.name, p.name, p.typ)
    end
    gather_locals(f.name, f.body)
  end

  if not funcs_by_name.main then
    error("program needs main()")
  end

  emit("; generated by Tiny-C compiler")
  emit("    org 0x0000")
  emit("    jp main")
  emit("")
  emit("    org 0x0038")
  emit("    ei")
  emit("    reti")
  emit("")
  emit("    org 0x0100")

  local function block_ends_with_return(block)
    if not block or not block.stmts or #block.stmts == 0 then
      return false
    end
    return block.stmts[#block.stmts].tag == "return"
  end

  for _, f in ipairs(ast.funcs) do
    if f.ret ~= "void" and f.ret ~= "byte" and f.ret ~= "word" then
      error("function '" .. f.name .. "' return type must be void, byte, or word")
    end
    current_fn = f.name
    fn_ret = f.ret
    emit("")
    emit(f.name .. ":")
    if f.name == "main" then
      if f.ret ~= "void" then
        error("main() must be void")
      end
      emit("    ld sp,0xFFFE")
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
    if not block_ends_with_return(f.body) then
      emit("    ret")
    end
  end

  -- Only link runtime pieces the program actually calls.
  if need_lcd or need_text or need_gfx or need_math or need_key then
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
  end
  if need_text then
    emit("")
    emit("font:")
    emit("    blob font8")
    emit("ascii_map:")
    emit("    blob ascii_map")
  end

  if #strings > 0 then
    emit("")
    for _, s in ipairs(strings) do
      emit(s.lab .. ":")
      emit(string.format('    db "%s",0', s.value))
    end
  end

  return table.concat(lines, "\n") .. "\n"
end

return { codegen = codegen }
