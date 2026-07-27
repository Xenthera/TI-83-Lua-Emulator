-- Tiny-C lexer

local KEYWORDS = {
  ["void"] = true,
  ["byte"] = true,
  ["word"] = true,
  ["if"] = true,
  ["else"] = true,
  ["while"] = true,
  ["for"] = true,
  ["break"] = true,
  ["continue"] = true,
  ["return"] = true,
  ["extern"] = true,
  ["osabi"] = true,
  ["saveaf"] = true,
}

local function lex(src, filename)
  filename = filename or "<input>"
  local tokens = {}
  local i, line, col = 1, 1, 1
  local n = #src

  local function peek(k)
    k = k or 0
    return src:sub(i + k, i + k)
  end

  local function advance()
    local ch = peek()
    i = i + 1
    if ch == "\n" then
      line = line + 1
      col = 1
    else
      col = col + 1
    end
    return ch
  end

  local function add(kind, value, start_line, start_col)
    tokens[#tokens + 1] = {
      kind = kind,
      value = value,
      line = start_line,
      col = start_col,
      file = filename,
    }
  end

  while i <= n do
    local ch = peek()
    local sl, sc = line, col

    if ch == " " or ch == "\t" or ch == "\r" or ch == "\n" then
      advance()
    elseif ch == "#" then
      -- Preprocessor location marker: #line N "file"
      advance()
      local dir = {}
      while i <= n and peek():match("[%w]") do
        dir[#dir + 1] = advance()
      end
      if table.concat(dir) ~= "line" then
        error(string.format("%s:%d:%d: unexpected '#'", filename, sl, sc))
      end
      while i <= n and (peek() == " " or peek() == "\t") do
        advance()
      end
      local num = {}
      while i <= n and peek():match("%d") do
        num[#num + 1] = advance()
      end
      local nline = tonumber(table.concat(num))
      if not nline then
        error(string.format("%s:%d:%d: bad #line directive", filename, sl, sc))
      end
      while i <= n and (peek() == " " or peek() == "\t") do
        advance()
      end
      if peek() == '"' then
        advance()
        local fchars = {}
        while i <= n and peek() ~= '"' and peek() ~= "\n" do
          fchars[#fchars + 1] = advance()
        end
        if peek() == '"' then
          advance()
        end
        filename = table.concat(fchars)
      end
      while i <= n and peek() ~= "\n" do
        advance()
      end
      if peek() == "\n" then
        advance()
      end
      line = nline
      col = 1
    elseif ch == "/" and peek(1) == "/" then
      advance()
      advance()
      while i <= n and peek() ~= "\n" do
        advance()
      end
    elseif ch == "/" and peek(1) == "*" then
      advance()
      advance()
      while i <= n and not (peek() == "*" and peek(1) == "/") do
        advance()
      end
      if i <= n then
        advance()
        advance()
      end
    elseif ch == '"' then
      advance()
      local s = {}
      while i <= n and peek() ~= '"' do
        local c = advance()
        if c == "\\" then
          local e = advance()
          if e == "n" then s[#s + 1] = "\n"
          elseif e == "t" then s[#s + 1] = "\t"
          elseif e == "\\" then s[#s + 1] = "\\"
          elseif e == '"' then s[#s + 1] = '"'
          else s[#s + 1] = e end
        else
          s[#s + 1] = c
        end
      end
      if peek() ~= '"' then
        error(string.format("%s:%d:%d: unterminated string", filename, sl, sc))
      end
      advance()
      add("string", table.concat(s), sl, sc)
    elseif ch:match("[%a_]") then
      local id = {}
      while i <= n and peek():match("[%w_]") do
        id[#id + 1] = advance()
      end
      local name = table.concat(id)
      if KEYWORDS[name] then
        add("kw", name, sl, sc)
      else
        add("ident", name, sl, sc)
      end
    elseif ch:match("%d") then
      local num = {}
      if ch == "0" and (peek(1) == "x" or peek(1) == "X") then
        num[#num + 1] = advance()
        num[#num + 1] = advance()
        while i <= n and peek():match("%x") do
          num[#num + 1] = advance()
        end
        local text = table.concat(num)
        add("number", tonumber(text:sub(3), 16), sl, sc)
      else
        while i <= n and peek():match("%d") do
          num[#num + 1] = advance()
        end
        add("number", tonumber(table.concat(num), 10), sl, sc)
      end
    else
      local two = ch .. peek(1)
      if two == "==" or two == "!=" or two == "<=" or two == ">="
          or two == "<<" or two == ">>" then
        advance()
        advance()
        add("op", two, sl, sc)
      elseif ch:match("[(){};,=+%-%*/%%&|^<>%[%]]") then
        advance()
        add("op", ch, sl, sc)
      else
        error(string.format("%s:%d:%d: unexpected character %q", filename, sl, sc, ch))
      end
    end
  end

  add("eof", nil, line, col)
  return tokens
end

return { lex = lex }
