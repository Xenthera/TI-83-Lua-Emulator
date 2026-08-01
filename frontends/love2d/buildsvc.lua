-- In-process build: Tiny-C and/or ASM -> 512KB ROM bytes (or .8xk Flash Apps).

local Compiler = require("lang.compiler")
local AppLink = require("lang.app_link")
local Assembler = require("asm.assembler")
local Eightxk = require("machines.ti83plus.util.eightxk")
local AppSign = require("machines.ti83plus.util.appsign")
local font8 = require("asm.font8")

local FLASH = 512 * 1024
local PAGE = 0x4000

local M = {}

-- Love2D caches require(); without this, IDE builds keep stale lang.* after edits
-- (e.g. new natives like clear_pixel → "unknown function").
local function reload_lang_modules()
  for name in pairs(package.loaded) do
    if type(name) == "string" and (name:match("^lang%.") or name == "machines.ti83plus.util.appsign") then
      package.loaded[name] = nil
    end
  end
  Compiler = require("lang.compiler")
  AppLink = require("lang.app_link")
  AppSign = require("machines.ti83plus.util.appsign")
end

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

local function read_base_rom(root)
  local path = root .. "/rom/ti83plus.rom"
  local f = io.open(path, "rb")
  if not f then return nil, path end
  local data = f:read("*a")
  f:close()
  if data and #data == FLASH then return data, path end
  return nil, path
end

-- TI-83+ page 0 starts with: in a,(0x02) / and 0x80
local function looks_like_ti_page0(result)
  return (result.bytes[0] or 0) == 0xDB
    and (result.bytes[1] or 0) == 0x02
    and (result.bytes[2] or 0) == 0xE6
    and (result.bytes[3] or 0) == 0x80
end

local function page0_bytes(result)
  local t = {}
  for i = 0, PAGE - 1 do
    t[#t + 1] = string.char(result.bytes[i] or 0)
  end
  return table.concat(t)
end

--- Build a 512KB flash image from an assembled <=16KB result.
-- Full TI page-0 sources are spliced into rom/ti83plus.rom (pages 1-31 kept).
-- Tiny demos are zero-padded (legacy pipeline behavior).
-- @return flash_bytes, info { spliced=bool, base=path|nil }
local function flash_from_result(result, root)
  local page0 = page0_bytes(result)
  local base, base_path = read_base_rom(root)
  if base and result.size >= 0x3E00 and looks_like_ti_page0(result) then
    return page0 .. base:sub(PAGE + 1), {
      spliced = true,
      base = base_path,
      page0 = PAGE,
    }
  end

  local chunks = { page0 }
  local remain = FLASH - PAGE
  local BLOCK = 16384
  while remain > 0 do
    local n = math.min(BLOCK, remain)
    chunks[#chunks + 1] = string.rep("\0", n)
    remain = remain - n
  end
  return table.concat(chunks), { spliced = false }
end

local function assemble_path(root, rel, opts)
  opts = opts or {}
  local aopts = {
    root = root,
    blobs = { font8 = font8.blob(), ascii_map = ascii_map() },
    max_size = opts.max_size or PAGE,
    addr_base = opts.addr_base,
    multipage = opts.multipage,
  }
  return pcall(Assembler.assemble_file, rel, aopts)
end

local function page_string(result)
  local t = {}
  local n = result.size or 0
  if n > PAGE then
    n = PAGE
  end
  for i = 0, n - 1 do
    t[#t + 1] = string.char(result.bytes[i] or 0)
  end
  return table.concat(t)
end

--- Total assembled machine-code bytes and page count from an assemble result.
local function code_stats(result, fallback_pages)
  local n_pages = fallback_pages or 1
  local code_bytes = 0
  if result and result.multipage and result.pages then
    n_pages = result.n_pages or n_pages
    for _, pg in pairs(result.pages) do
      code_bytes = code_bytes + (pg.size or 0)
    end
  elseif result then
    code_bytes = result.size or 0
    if result.n_pages then
      n_pages = result.n_pages
    end
  end
  return code_bytes, n_pages
end

function M.code_stats(result, fallback_pages)
  return code_stats(result, fallback_pages)
end

--- Build a Flash App .8xk from Tiny-C (target=app).
-- Automatically multipage-links when the program does not fit in 16KB.
-- @return eightxk_bytes, err, asm, result, info
function M.build_tc_app(root, tc_source, opts)
  reload_lang_modules()
  opts = opts or {}
  opts.root = opts.root or root
  opts.target = "app"
  opts.app_name = opts.app_name or opts.name or "TINYAPP"
  local entry = opts.entry or "ide.tc"

  local pack = { asm = nil, meta = nil }
  local ok, err = pcall(function()
    pack.asm, pack.meta = AppLink.compile_app_source(tc_source, entry, opts)
  end)
  if not ok then
    return nil, tostring(err)
  end
  local asm = pack.asm
  local meta = pack.meta or { n_pages = 1 }

  local asm_path = root .. "/asm/generated/app.asm"
  local f = assert(io.open(asm_path, "w"))
  f:write(asm)
  f:close()

  local multipage = (meta.n_pages or 1) > 1
  local ok2, result = assemble_path(root, "asm/generated/app.asm", {
    max_size = PAGE,
    addr_base = 0x4000,
    multipage = multipage,
  })
  if not ok2 then
    return nil, tostring(result), asm
  end

  local xk, xerr
  if result.multipage and result.pages then
    xk, xerr = Eightxk.pack_app(result, { name = opts.app_name })
  else
    local page = page_string(result)
    xk, xerr = Eightxk.pack_app(page, { name = opts.app_name, size = #page })
  end
  if not xk then
    return nil, tostring(xerr), asm, result
  end

  -- Real TI-83+/84+ need a Rabin signature (free key 0104). Emulator accepts either.
  -- opts.sign=false skips; opts.sign=true requires RabbitSign; nil = sign when available.
  local want_sign
  if opts.sign == false then
    want_sign = false
  elseif opts.sign == true then
    want_sign = true
  else
    want_sign = AppSign.available(root, opts)
  end
  local signed = false
  if want_sign then
    local sxk, serr = AppSign.sign_bytes(xk, {
      root = root,
      rabbitsign = opts.rabbitsign,
      key_id = opts.key_id or "0104",
      key_file = opts.key_file,
    })
    if not sxk then
      return nil, tostring(serr), asm, result
    end
    xk = sxk
    signed = true
  end

  local code_bytes, n_pages = code_stats(result, meta.n_pages or 1)
  return xk, nil, asm, result, {
    app = true,
    name = opts.app_name,
    n_pages = n_pages,
    size = code_bytes,
    code_bytes = code_bytes,
    page_bytes = PAGE,
    signed = signed,
  }
end

local function looks_like_flash_app(src)
  if type(src) ~= "string" then return false end
  -- Flash App BCALL natives require target=app.
  return src:find("os_clr_lcd", 1, true)
    or src:find("os_put_str", 1, true)
    or src:find("os_get_key", 1, true)
    or src:find("os_home_up", 1, true)
    or src:find("os_newline", 1, true)
    or src:find("os_exit", 1, true)
end

--- opts: entry filename, files VFS map, root already set by caller
-- opts.target: "app" | "bare" | nil (nil => infer from os_* natives)
function M.build_tc(root, tc_source, opts)
  opts = opts or {}
  opts.root = opts.root or root
  if opts.target == "app" or opts.app == true then
    return M.build_tc_app(root, tc_source, opts)
  elseif opts.target ~= "bare" and looks_like_flash_app(tc_source) then
    -- Infer Flash App when tiproj/CLI omitted target but source uses os_*.
    opts.target = "app"
    opts.app_name = opts.app_name or opts.name or "TINYAPP"
    return M.build_tc_app(root, tc_source, opts)
  end
  -- Reload so new natives/codegen apply without restarting Love.
  reload_lang_modules()
  local entry = opts.entry or "ide.tc"
  local ok, asm_or_err = pcall(Compiler.compile_source, tc_source, entry, opts)
  if not ok then
    return nil, tostring(asm_or_err)
  end
  local asm = asm_or_err
  local asm_path = root .. "/asm/generated/ide.asm"
  local f = assert(io.open(asm_path, "w"))
  f:write(asm)
  f:close()

  local ok2, result = assemble_path(root, "asm/generated/ide.asm")
  if not ok2 then
    return nil, tostring(result), asm
  end
  local rom, info = flash_from_result(result, root)
  return rom, nil, asm, result, info
end

function M.build_asm(root, asm_source)
  local asm_path = root .. "/asm/generated/ide.asm"
  local f = assert(io.open(asm_path, "w"))
  f:write(asm_source)
  f:close()

  local ok, result = assemble_path(root, "asm/generated/ide.asm")
  if not ok then
    return nil, tostring(result)
  end
  local rom, info = flash_from_result(result, root)
  return rom, nil, result, info
end

function M.write_rom(root, bytes)
  local path = root .. "/rom/pipeline.rom"
  local f = assert(io.open(path, "wb"))
  f:write(bytes)
  f:close()
  return path
end

--- Also write a dedicated reassembled OS image when splicing.
function M.write_os_rom(root, bytes)
  local path = root .. "/rom/ti83plus_reasm.rom"
  local f = assert(io.open(path, "wb"))
  f:write(bytes)
  f:close()
  return path
end

return M
