-- Tiny-C recursive-descent parser -> AST

local Lexer = require("lang.lexer")

local function parse(src, filename)
  local tokens = Lexer.lex(src, filename)
  local pos = 1

  local function at()
    return tokens[pos]
  end

  local function err(msg)
    local t = at()
    error(string.format("%s:%d:%d: %s", t.file or filename, t.line, t.col, msg))
  end

  local function loc_of(t)
    t = t or at()
    return { file = t.file or filename, line = t.line, col = t.col }
  end

  local function with_loc(node, t)
    node.loc = loc_of(t)
    return node
  end

  local function peek_kind()
    return at().kind
  end

  local function match_kw(name)
    local t = at()
    return t.kind == "kw" and t.value == name
  end

  local function match_op(op)
    local t = at()
    return t.kind == "op" and t.value == op
  end

  local function consume_kw(name)
    if not match_kw(name) then
      err("expected '" .. name .. "'")
    end
    pos = pos + 1
  end

  local function consume_op(op)
    if not match_op(op) then
      err("expected '" .. op .. "'")
    end
    pos = pos + 1
  end

  local function consume_ident()
    local t = at()
    if t.kind ~= "ident" then
      err("expected identifier")
    end
    pos = pos + 1
    return t.value
  end

  local parse_expr
  local parse_stmt
  local parse_block

  local function parse_type()
    if match_kw("void") or match_kw("byte") or match_kw("word") then
      local t = at().value
      pos = pos + 1
      return t
    end
    err("expected type")
  end

  local function parse_primary()
    local t = at()
    if t.kind == "number" then
      pos = pos + 1
      return with_loc({ tag = "number", value = t.value }, t)
    elseif t.kind == "string" then
      pos = pos + 1
      return with_loc({ tag = "string", value = t.value }, t)
    elseif t.kind == "ident" then
      local name = t.value
      pos = pos + 1
      if match_op("(") then
        pos = pos + 1
        local args = {}
        if not match_op(")") then
          args[#args + 1] = parse_expr()
          while match_op(",") do
            pos = pos + 1
            args[#args + 1] = parse_expr()
          end
        end
        consume_op(")")
        return with_loc({ tag = "call", name = name, args = args }, t)
      end
      return with_loc({ tag = "var", name = name }, t)
    elseif match_op("(") then
      pos = pos + 1
      local e = parse_expr()
      consume_op(")")
      return e
    end
    err("expected expression")
  end

  local function parse_postfix()
    local e = parse_primary()
    while match_op("[") do
      local t = at()
      pos = pos + 1
      local idx = parse_expr()
      consume_op("]")
      e = with_loc({ tag = "index", base = e, index = idx }, t)
    end
    return e
  end

  local function parse_unary()
    if match_op("-") then
      local t = at()
      pos = pos + 1
      return with_loc({ tag = "unary", op = "-", expr = parse_unary() }, t)
    end
    return parse_postfix()
  end

  local function parse_binop_level(next_fn, ops)
    local left = next_fn()
    while at().kind == "op" and ops[at().value] do
      local t = at()
      local op = t.value
      pos = pos + 1
      local right = next_fn()
      left = with_loc({ tag = "binop", op = op, left = left, right = right }, t)
    end
    return left
  end

  local function parse_mul()
    return parse_binop_level(parse_unary, { ["*"] = true, ["/"] = true, ["%"] = true })
  end

  local function parse_shift()
    return parse_binop_level(parse_mul, { ["<<"] = true, [">>"] = true })
  end

  local function parse_add()
    return parse_binop_level(parse_shift, { ["+"] = true, ["-"] = true })
  end

  local function parse_bit()
    return parse_binop_level(parse_add, { ["&"] = true, ["|"] = true, ["^"] = true })
  end

  local function parse_cmp()
    return parse_binop_level(parse_bit, {
      ["=="] = true, ["!="] = true,
      ["<"] = true, [">"] = true,
      ["<="] = true, [">="] = true,
    })
  end

  parse_expr = parse_cmp

  parse_block = function()
    consume_op("{")
    local stmts = {}
    while not match_op("}") and peek_kind() ~= "eof" do
      stmts[#stmts + 1] = parse_stmt()
    end
    consume_op("}")
    return { tag = "block", stmts = stmts }
  end

  -- Returns count, dims (dims is nil for non-arrays).
  local function parse_array_dims()
    local dims = {}
    while match_op("[") do
      pos = pos + 1
      if at().kind ~= "number" then
        err("array size must be a constant integer")
      end
      local n = at().value
      if n < 1 or n > 65535 then
        err("array size out of range")
      end
      pos = pos + 1
      consume_op("]")
      dims[#dims + 1] = n
    end
    if #dims == 0 then
      return nil, nil
    end
    local count = 1
    for _, d in ipairs(dims) do
      count = count * d
      if count > 65535 then
        err("array too large")
      end
    end
    return count, dims
  end

  local function parse_const_int()
    local neg = false
    if match_op("-") then
      pos = pos + 1
      neg = true
    end
    if at().kind ~= "number" then
      err("array initializer must be a constant integer")
    end
    local n = at().value
    pos = pos + 1
    if neg then
      n = -n
    end
    return n
  end

  -- Nested braces flatten into a single list of integers.
  local function parse_init_list()
    consume_op("{")
    local vals = {}
    if match_op("}") then
      pos = pos + 1
      return vals
    end
    while true do
      if match_op("{") then
        local nested = parse_init_list()
        for _, v in ipairs(nested) do
          vals[#vals + 1] = v
        end
      else
        local n = parse_const_int()
        if n < 0 then
          n = n % 256
        end
        if n > 255 then
          err("array initializer byte out of range")
        end
        vals[#vals + 1] = n
      end
      if match_op("}") then
        pos = pos + 1
        break
      end
      consume_op(",")
      if match_op("}") then
        pos = pos + 1
        break
      end
    end
    return vals
  end

  local function parse_var_init(count)
    local init = nil
    local init_list = nil
    if match_op("=") then
      pos = pos + 1
      if match_op("{") then
        if not count then
          err("brace initializer requires an array")
        end
        init_list = parse_init_list()
        if #init_list > count then
          err("too many initializers for array")
        end
        while #init_list < count do
          init_list[#init_list + 1] = 0
        end
      else
        if count then
          err("array declaration needs a brace initializer { ... }")
        end
        init = parse_expr()
      end
    end
    return init, init_list
  end

  parse_stmt = function()
    if match_kw("if") then
      local t = at()
      pos = pos + 1
      consume_op("(")
      local cond = parse_expr()
      consume_op(")")
      local then_b = parse_block()
      local else_b = nil
      if match_kw("else") then
        pos = pos + 1
        else_b = parse_block()
      end
      return with_loc({ tag = "if", cond = cond, then_block = then_b, else_block = else_b }, t)
    elseif match_kw("while") then
      local t = at()
      pos = pos + 1
      consume_op("(")
      local cond = parse_expr()
      consume_op(")")
      local body = parse_block()
      return with_loc({ tag = "while", cond = cond, body = body }, t)
    elseif match_kw("for") then
      local t = at()
      pos = pos + 1
      consume_op("(")
      local init = nil
      if not match_op(";") then
        if match_kw("byte") or match_kw("word") then
          local typ = parse_type()
          local name = consume_ident()
          local count, dims = parse_array_dims()
          local init_e, init_list = parse_var_init(count)
          init = with_loc({
            tag = "vardecl", typ = typ, name = name, init = init_e,
            init_list = init_list, count = count, dims = dims,
          }, t)
        else
          local e = parse_expr()
          if e.tag == "var" and match_op("=") then
            pos = pos + 1
            init = with_loc({ tag = "assign", name = e.name, expr = parse_expr() }, e.loc)
          elseif e.tag == "index" and match_op("=") then
            pos = pos + 1
            init = with_loc({ tag = "index_assign", target = e, expr = parse_expr() }, e.loc)
          else
            err("for-init must be declaration or assignment")
          end
        end
      end
      consume_op(";")
      local cond = nil
      if not match_op(";") then
        cond = parse_expr()
      else
        cond = with_loc({ tag = "number", value = 1 }, t)
      end
      consume_op(";")
      local step = nil
      if not match_op(")") then
        local e = parse_expr()
        if e.tag == "var" and match_op("=") then
          pos = pos + 1
          step = with_loc({ tag = "assign", name = e.name, expr = parse_expr() }, e.loc)
        elseif e.tag == "index" and match_op("=") then
          pos = pos + 1
          step = with_loc({ tag = "index_assign", target = e, expr = parse_expr() }, e.loc)
        else
          step = with_loc({ tag = "exprstmt", expr = e }, e.loc)
        end
      end
      consume_op(")")
      local body = parse_block()
      return with_loc({
        tag = "for", init = init, cond = cond, step = step, body = body,
      }, t)
    elseif match_kw("break") then
      local t = at()
      pos = pos + 1
      consume_op(";")
      return with_loc({ tag = "break" }, t)
    elseif match_kw("continue") then
      local t = at()
      pos = pos + 1
      consume_op(";")
      return with_loc({ tag = "continue" }, t)
    elseif match_kw("return") then
      local t = at()
      pos = pos + 1
      local expr = nil
      if not match_op(";") then
        expr = parse_expr()
      end
      consume_op(";")
      return with_loc({ tag = "return", expr = expr }, t)
    elseif match_kw("byte") or match_kw("word") then
      local t = at()
      local typ = parse_type()
      local name = consume_ident()
      local count, dims = parse_array_dims()
      local init, init_list = parse_var_init(count)
      consume_op(";")
      return with_loc({
        tag = "vardecl", typ = typ, name = name, init = init,
        init_list = init_list, count = count, dims = dims,
      }, t)
    elseif match_op("{") then
      return parse_block()
    else
      local e = parse_expr()
      if e.tag == "var" and match_op("=") then
        pos = pos + 1
        local rhs = parse_expr()
        consume_op(";")
        return with_loc({ tag = "assign", name = e.name, expr = rhs }, e.loc)
      elseif e.tag == "index" and match_op("=") then
        pos = pos + 1
        local rhs = parse_expr()
        consume_op(";")
        return with_loc({ tag = "index_assign", target = e, expr = rhs }, e.loc)
      end
      consume_op(";")
      return with_loc({ tag = "exprstmt", expr = e }, e.loc)
    end
  end

  local function parse_param()
    local typ = parse_type()
    if typ == "void" then
      err("void parameter not allowed")
    end
    local name = consume_ident()
    -- byte name[] / byte name[N][M] -> decay to word base address
    if match_op("[") then
      pos = pos + 1
      local dims = {}
      if match_op("]") then
        pos = pos + 1
      else
        if at().kind ~= "number" then
          err("array size must be a constant integer")
        end
        dims[#dims + 1] = at().value
        pos = pos + 1
        consume_op("]")
      end
      while match_op("[") do
        pos = pos + 1
        if at().kind ~= "number" then
          err("array size must be a constant integer")
        end
        dims[#dims + 1] = at().value
        pos = pos + 1
        consume_op("]")
      end
      local p = { typ = "word", name = name, array_decay = true, elem = typ }
      if #dims > 0 then
        p.dims = dims
      end
      return p
    end
    return { typ = typ, name = name }
  end

  local function parse_param_list()
    local params = {}
    if not match_op(")") then
      if match_kw("void") then
        pos = pos + 1
      else
        params[#params + 1] = parse_param()
        while match_op(",") do
          pos = pos + 1
          params[#params + 1] = parse_param()
        end
      end
    end
    consume_op(")")
    return params
  end

  local function parse_function()
    local ret = parse_type()
    local name = consume_ident()
    consume_op("(")
    local params = parse_param_list()
    local osabi = false
    local saveaf = false
    if match_kw("osabi") then
      pos = pos + 1
      osabi = true
      if match_kw("saveaf") then
        pos = pos + 1
        saveaf = true
      end
    end
    local body = parse_block()
    return {
      tag = "func",
      ret = ret,
      name = name,
      params = params,
      body = body,
      osabi = osabi,
      saveaf = saveaf,
    }
  end

  local function parse_extern()
    local t = at()
    consume_kw("extern")
    local ret = parse_type()
    local name = consume_ident()
    consume_op("(")
    local params = parse_param_list()
    consume_op(";")
    return with_loc({
      tag = "extern",
      ret = ret,
      name = name,
      params = params,
    }, t)
  end

  local funcs = {}
  local externs = {}
  local globals = {}
  while peek_kind() ~= "eof" do
    if match_kw("extern") then
      externs[#externs + 1] = parse_extern()
    else
      if at().kind == "ident" then
        local name = at().value
        local nxt = tokens[pos + 1]
        if nxt and nxt.kind == "op" and nxt.value == "(" then
          err("function '" .. name .. "' needs a return type: void/byte/word " .. name .. "(...)")
        end
      end
      local save = pos
      parse_type()
      consume_ident()
      if match_op("(") then
        pos = save
        funcs[#funcs + 1] = parse_function()
      else
        pos = save
        local typ = parse_type()
        if typ == "void" then
          err("void global not allowed")
        end
        local name = consume_ident()
        local count, dims = parse_array_dims()
        local init, init_list = parse_var_init(count)
        consume_op(";")
        globals[#globals + 1] = {
          tag = "global", typ = typ, name = name, init = init,
          init_list = init_list, count = count, dims = dims,
        }
      end
    end
  end

  return { tag = "program", globals = globals, funcs = funcs, externs = externs }
end

return { parse = parse }
