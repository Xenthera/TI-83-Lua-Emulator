-- Automatic Flash App page linker for Tiny-C.
-- Bin-packs functions into <=14 archive pages; codegen emits far calls.

local Codegen = require("lang.codegen")
local Assembler = require("asm.assembler")
local font8 = require("asm.font8")

local M = {}

local PAGE = 0x4000
local MAX_PAGES = 14
local PAGE0_BUDGET = PAGE - 400
local PAGE_BUDGET = PAGE - 16

local function ascii_map()
  local map = {}
  for i = 0, 255 do map[i + 1] = 0 end
  for i = 1, #font8.CHARSET do
    local ch = font8.CHARSET:sub(i, i)
    map[ch:byte() + 1] = i - 1
    local lower = ch:lower()
    if lower ~= ch then map[lower:byte() + 1] = i - 1 end
  end
  return map
end

local function assemble_text(root, asm_text, multipage)
  local path = root .. "/asm/generated/app_link_tmp.asm"
  local f = assert(io.open(path, "w"))
  f:write(asm_text)
  f:close()
  return pcall(Assembler.assemble_file, "asm/generated/app_link_tmp.asm", {
    root = root,
    blobs = { font8 = font8.blob(), ascii_map = ascii_map() },
    max_size = PAGE,
    addr_base = 0x4000,
    multipage = multipage == true,
  })
end

local function measure_sizes(ast, opts)
  local root = opts.root or "."
  local asm = Codegen.codegen(ast, {
    target = "app",
    app_name = opts.app_name or "TINYAPP",
    n_pages = 1,
    root = root,
  })
  local ok, result = assemble_text(root, asm, false)
  local sizes = {}
  if ok and result.symbols then
    local ordered = {}
    for _, f in ipairs(ast.funcs) do
      local addr = result.symbols[f.name]
      if addr then
        ordered[#ordered + 1] = { name = f.name, addr = addr }
      end
    end
    table.sort(ordered, function(a, b) return a.addr < b.addr end)
    local end_addr = 0x4000 + (result.size or 0)
    for i, ent in ipairs(ordered) do
      local nxt = (ordered[i + 1] and ordered[i + 1].addr) or end_addr
      sizes[ent.name] = math.max(16, nxt - ent.addr)
    end
    return sizes, result.size or #asm, true
  end
  -- Fallback: equal split estimate from source size
  local n = #ast.funcs
  if n < 1 then n = 1 end
  local each = math.floor((#asm) / n)
  if each < 64 then each = 64 end
  for _, f in ipairs(ast.funcs) do
    sizes[f.name] = each
  end
  return sizes, #asm, false
end

local function bin_pack(ast, sizes)
  local fn_pages = {}
  local page_used = { [0] = 0 }
  local n_pages = 1

  fn_pages.main = 0
  page_used[0] = sizes.main or 200

  local names = {}
  for _, f in ipairs(ast.funcs) do
    if f.name ~= "main" then
      names[#names + 1] = f.name
    end
  end
  table.sort(names, function(a, b)
    return (sizes[a] or 0) > (sizes[b] or 0)
  end)

  for _, name in ipairs(names) do
    local need = sizes[name] or 64
    if need > PAGE_BUDGET then
      error(string.format(
        "function '%s' is too large for one Flash App page (%d bytes)",
        name, need
      ))
    end
    local placed = false
    for p = 0, n_pages - 1 do
      local budget = (p == 0) and PAGE0_BUDGET or PAGE_BUDGET
      if (page_used[p] or 0) + need <= budget then
        fn_pages[name] = p
        page_used[p] = (page_used[p] or 0) + need
        placed = true
        break
      end
    end
    if not placed then
      if n_pages >= MAX_PAGES then
        error("Flash App exceeds 14 archive pages (224KB max)")
      end
      fn_pages[name] = n_pages
      page_used[n_pages] = need
      n_pages = n_pages + 1
    end
  end

  return fn_pages, n_pages
end

local function pad_empty_pages(asm, fn_pages, n_pages)
  for p = 1, n_pages - 1 do
    local has = false
    for _, pg in pairs(fn_pages) do
      if pg == p then has = true break end
    end
    if not has then
      asm = asm .. string.format(
        "\n    page %d\n    org 0x4000\npage%d_pad:\n    nop\n    ret\n",
        p, p
      )
    end
  end
  return asm
end

--- Compile AST to (possibly multipage) app assembly.
function M.link(ast, opts)
  opts = opts or {}
  local root = opts.root or "."

  if opts.force_pages and opts.force_pages > 1 then
    local n = opts.force_pages
    if n > MAX_PAGES then n = MAX_PAGES end
    local fn_pages = { main = 0 }
    local others = {}
    for _, f in ipairs(ast.funcs) do
      if f.name ~= "main" then
        others[#others + 1] = f.name
      end
    end
    for i, name in ipairs(others) do
      fn_pages[name] = 1 + ((i - 1) % (n - 1))
    end
    local asm = Codegen.codegen(ast, {
      target = "app",
      app_name = opts.app_name,
      fn_pages = fn_pages,
      n_pages = n,
      root = root,
      files = opts.files,
      entry = opts.entry,
    })
    asm = pad_empty_pages(asm, fn_pages, n)
    return asm, { fn_pages = fn_pages, n_pages = n }
  end

  local sizes, total, fitted = measure_sizes(ast, opts)
  local fn_pages, n_pages

  if fitted and total <= PAGE0_BUDGET then
    -- Single page; no far calls.
    local asm = Codegen.codegen(ast, {
      target = "app",
      app_name = opts.app_name,
      n_pages = 1,
      root = root,
      files = opts.files,
      entry = opts.entry,
    })
    return asm, { n_pages = 1, sizes = sizes }
  end

  fn_pages, n_pages = bin_pack(ast, sizes)

  local all_p0 = true
  for _, p in pairs(fn_pages) do
    if p ~= 0 then all_p0 = false break end
  end
  if all_p0 then
    local asm = Codegen.codegen(ast, {
      target = "app",
      app_name = opts.app_name,
      n_pages = 1,
      root = root,
      files = opts.files,
      entry = opts.entry,
    })
    return asm, { n_pages = 1, sizes = sizes }
  end

  local asm = Codegen.codegen(ast, {
    target = "app",
    app_name = opts.app_name,
    fn_pages = fn_pages,
    n_pages = n_pages,
    root = root,
    files = opts.files,
    entry = opts.entry,
  })
  return asm, { fn_pages = fn_pages, n_pages = n_pages, sizes = sizes }
end

function M.compile_app_source(src, filename, opts)
  opts = opts or {}
  local Preprocess = require("lang.preprocess")
  local Parser = require("lang.parser")
  local expanded = Preprocess.preprocess(src, filename or "<input>", opts)
  local ast = Parser.parse(expanded, filename or "<input>")
  return M.link(ast, opts)
end

M.MAX_PAGES = MAX_PAGES
M.PAGE = PAGE

return M
