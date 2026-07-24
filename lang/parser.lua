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

  local function parse_unary()
    if match_op("-") then
      local t = at()
      pos = pos + 1
      return with_loc({ tag = "unary", op = "-", expr = parse_unary() }, t)
    end
    return parse_primary()
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
    return parse_binop_level(parse_unary, { ["*"] = true, ["/"] = true })
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
      local init = nil
      if match_op("=") then
        pos = pos + 1
        init = parse_expr()
      end
      consume_op(";")
      return with_loc({ tag = "vardecl", typ = typ, name = name, init = init }, t)
    elseif match_op("{") then
      return parse_block()
    else
      local e = parse_expr()
      if e.tag == "var" and match_op("=") then
        pos = pos + 1
        local rhs = parse_expr()
        consume_op(";")
        return with_loc({ tag = "assign", name = e.name, expr = rhs }, e.loc)
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
    return { typ = typ, name = name }
  end

  local function parse_function()
    local ret = parse_type()
    local name = consume_ident()
    consume_op("(")
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
    local body = parse_block()
    return { tag = "func", ret = ret, name = name, params = params, body = body }
  end

  local funcs = {}
  local globals = {}
  while peek_kind() ~= "eof" do
    -- Require an explicit return/storage type (void/byte/word) — matches Z80
    -- results in A (byte) or HL (word); no untyped defs.
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
      local init = nil
      if match_op("=") then
        pos = pos + 1
        init = parse_expr()
      end
      consume_op(";")
      globals[#globals + 1] = { tag = "global", typ = typ, name = name, init = init }
    end
  end

  return { tag = "program", globals = globals, funcs = funcs }
end

return { parse = parse }
