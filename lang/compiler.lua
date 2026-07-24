-- Tiny-C public API

local Parser = require("lang.parser")
local Codegen = require("lang.codegen")
local Preprocess = require("lang.preprocess")

local M = {}

function M.compile_source(src, filename, opts)
  opts = opts or {}
  filename = filename or "<input>"
  local expanded = Preprocess.preprocess(src, filename, opts)
  local ast = Parser.parse(expanded, filename)
  return Codegen.codegen(ast)
end

function M.compile_file(path, opts)
  opts = opts or {}
  local f, err = io.open(path, "r")
  if not f then
    return nil, err
  end
  local src = f:read("*a")
  f:close()
  if not opts.root then
    local dir = path:gsub("\\", "/"):match("^(.*)/[^/]+$")
    opts.root = dir
  end
  local ok, result = pcall(M.compile_source, src, path, opts)
  if not ok then
    return nil, result
  end
  return result
end

function M.compile_to_file(src_path, out_path, opts)
  local asm, err = M.compile_file(src_path, opts)
  if not asm then
    return nil, err
  end
  local f, e = io.open(out_path, "w")
  if not f then
    return nil, e
  end
  f:write(asm)
  f:close()
  return out_path
end

return M
