#!/usr/bin/env lua
-- One-shot: flat all-pages disasm + Tiny-C recovery project.
--
--   lua tools/os_recover_all.lua
--   lua tools/os_recover_all.lua rom/ti83plus.rom

local function detect_root()
  if arg and arg[0] then
    local r = arg[0]:match("(.+)[/\\]tools[/\\]os_recover_all%.lua$")
    if r then return r end
  end
  return "."
end

local ROOT = detect_root()
local rom = arg[1] or (ROOT .. "/rom/ti83plus.rom")

local function run(cmd)
  io.stdout:write("-> " .. cmd .. "\n")
  local ok = os.execute(cmd)
  -- Lua 5.1/5.2/5.3+ exit status differences
  if ok == true or ok == 0 then return end
  if type(ok) == "number" and ok == 0 then return end
  io.stderr:write("command failed: " .. cmd .. "\n")
  os.exit(1)
end

run(string.format(
  'lua "%s/tools/disasm_all_pages.lua" "%s" -o "%s/rom/ti83plus_all_dis.asm" --json "%s/rom/ti83plus_all_index.json"',
  ROOT, rom, ROOT, ROOT
))
run(string.format(
  'lua "%s/tools/asm_to_tc.lua" "%s" -o "%s/projects/os83_port"',
  ROOT, rom, ROOT
))
io.stdout:write("\nOS recovery complete.\n")
io.stdout:write("  ASM:  rom/ti83plus_all_dis.asm\n")
io.stdout:write("  Tiny-C: projects/os83_port/ (clean/ + gen/)\n")
