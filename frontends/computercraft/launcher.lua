-- ComputerCraft emulator launcher.
--
-- Deploy next to a frontends/ folder of bundled clients:
--   emu.lua
--   frontends/
--     ti83_cc.lua
--     ti83_cc_ws.lua
--     ti84_cc.lua
--     ti89_cc.lua
--     ti89_gpu_cc.lua
--     ti89_gpu_cc_ws.lua
--     ti92_cc.lua
--     gb_cc.lua
--     gb_gpu_cc.lua
--     gb_gpu_cc_ws.lua
--
-- Naming: {id}[_gpu]_cc[_ws].lua
-- Run:  emu

local TITLES = {
  ti83 = "TI-83+",
  ti84 = "TI-84+",
  ti89 = "TI-89",
  ti92 = "TI-92+",
  gb = "Game Boy",
  gameboy = "Game Boy",
}

local DEFAULT_ROM = {
  ti83 = "ti83plus.rom",
  ti84 = "ti84p.rom",
  ti89 = "ti89.rom",
  ti92 = "ti92p.rom",
  gb = "tetris.gb",
  gameboy = "tetris.gb",
}

--- File extensions offered by the ROM picker, keyed by machine id.
local ROM_EXTS = {
  ti83 = { ".rom", ".bin" },
  ti84 = { ".rom", ".bin" },
  ti89 = { ".89u", ".tib", ".rom", ".bin" },
  ti92 = { ".9xu", ".tib", ".rom", ".bin" },
  gb = { ".gb" },
  gameboy = { ".gb" },
}

local DEFAULT_URL = "ws://127.0.0.1:8765"
local PREFS_FILE = "emu.prefs"

local function colors()
  return _G.colors or {
    white = 1, orange = 2, magenta = 4, lightBlue = 8,
    yellow = 16, lime = 32, pink = 64, gray = 128,
    lightGray = 256, cyan = 512, purple = 1024, blue = 2048,
    brown = 4096, green = 8192, red = 16384, black = 32768,
  }
end

local function combine(a, b)
  if type(fs) == "table" and fs.combine then
    return fs.combine(a, b)
  end
  if a == "" or a == nil then return b end
  return tostring(a):gsub("/+$", "") .. "/" .. tostring(b):gsub("^/+", "")
end

local function program_dir()
  if type(shell) == "table" and shell.getRunningProgram then
    local prog = shell.getRunningProgram()
    if prog and type(fs) == "table" and fs.getDir then
      return fs.getDir(prog) or ""
    end
  end
  return ""
end

local function frontends_dir()
  return combine(program_dir(), "frontends")
end

local function list_dir(path)
  if type(fs) ~= "table" or not fs.list then
    return {}
  end
  if path ~= "" and fs.exists and not fs.exists(path) then
    return {}
  end
  local ok, names = pcall(fs.list, path == "" and "" or path)
  if not ok or type(names) ~= "table" then
    return {}
  end
  table.sort(names)
  return names
end

local function file_exists(path)
  return type(fs) == "table" and fs.exists and fs.exists(path)
end

--- Parse `{id}[_gpu]_cc[_ws].lua` → { id, gpu, ws, file } or nil.
--- (Lua patterns have no `(group)?`, so peel suffixes explicitly.)
local function parse_frontend_name(name)
  if type(name) ~= "string" then return nil end
  local lower = name:lower()
  if not lower:match("%.lua$") then return nil end
  local body = lower:sub(1, -5) -- strip .lua
  local ws = false
  if body:sub(-6) == "_cc_ws" then
    ws = true
    body = body:sub(1, -7)
  elseif body:sub(-3) == "_cc" then
    body = body:sub(1, -4)
  else
    return nil
  end
  local gpu = false
  if body:sub(-4) == "_gpu" then
    gpu = true
    body = body:sub(1, -5)
  end
  if body == "" or not body:match("^[%w%-]+$") then
    return nil
  end
  return {
    id = body,
    gpu = gpu,
    ws = ws,
    file = name,
  }
end

local function resolve_path(dir, file)
  return combine(dir, file)
end

--- Scan frontends/ and group variants by machine id.
local function scan_frontends(dir)
  dir = dir or frontends_dir()
  local groups = {}
  local order = {}
  for _, name in ipairs(list_dir(dir)) do
    local full = combine(dir, name)
    if type(fs) == "table" and fs.isDir and fs.isDir(full) then
      -- skip subdirs
    else
      local meta = parse_frontend_name(name)
      if meta then
        local g = groups[meta.id]
        if not g then
          g = {
            id = meta.id,
            title = TITLES[meta.id] or meta.id:upper(),
            variants = {},
          }
          groups[meta.id] = g
          order[#order + 1] = meta.id
        end
        local key = (meta.gpu and "gpu" or "base") .. (meta.ws and "_ws" or "")
        g.variants[key] = {
          file = meta.file,
          path = full,
          gpu = meta.gpu,
          ws = meta.ws,
        }
        if meta.gpu then g.has_gpu = true end
        if meta.ws then g.has_ws = true end
        if meta.gpu and meta.ws then g.has_gpu_ws = true end
        if not meta.gpu and not meta.ws then g.has_base = true end
        if meta.gpu and not meta.ws then g.has_gpu_only = true end
        if not meta.gpu and meta.ws then g.has_ws_only = true end
      end
    end
  end
  table.sort(order, function(a, b)
    return (TITLES[a] or a) < (TITLES[b] or b)
  end)
  local list = {}
  for _, id in ipairs(order) do
    list[#list + 1] = groups[id]
  end
  return list, dir
end

local function pick_variant(group, want_gpu, want_ws)
  if not group then return nil, "no machine selected" end
  local key
  if want_gpu and want_ws then
    key = "gpu_ws"
  elseif want_gpu then
    key = "gpu"
  elseif want_ws then
    key = "base_ws"
  else
    key = "base"
  end
  -- normalize keys used in scan
  local map = {
    base = group.variants.base,
    gpu = group.variants.gpu,
    base_ws = group.variants.base_ws,
    gpu_ws = group.variants.gpu_ws,
  }
  local v = map[key]
  if v then return v end
  return nil, string.format(
    "%s has no %s%s build",
    group.title,
    want_gpu and "GPU" or "local",
    want_ws and "+WS" or ""
  )
end

local function default_machine_prefs(id)
  return {
    gpu = false,
    ws = false,
    rom = DEFAULT_ROM[id] or "",
    url = DEFAULT_URL,
  }
end

--- Per-machine slot: prefs.machines[id] = { gpu, ws, rom, url }
local function machine_prefs(prefs, id)
  if not id then return default_machine_prefs(nil) end
  if type(prefs.machines) ~= "table" then
    prefs.machines = {}
  end
  local slot = prefs.machines[id]
  if type(slot) ~= "table" then
    slot = default_machine_prefs(id)
    prefs.machines[id] = slot
  end
  if slot.gpu == nil then slot.gpu = false end
  if slot.ws == nil then slot.ws = false end
  if type(slot.rom) ~= "string" or slot.rom == "" then
    slot.rom = DEFAULT_ROM[id] or ""
  end
  if type(slot.url) ~= "string" or slot.url == "" then
    slot.url = DEFAULT_URL
  end
  return slot
end

local function load_prefs()
  local prefs = {
    machine = nil,
    machines = {},
  }
  if not file_exists(PREFS_FILE) then
    return prefs
  end
  local ok, data = pcall(function()
    local f = fs.open(PREFS_FILE, "r")
    if not f then return nil end
    local src = f.readAll()
    f.close()
    return textutils and textutils.unserialize(src) or nil
  end)
  if ok and type(data) == "table" then
    if data.machine then prefs.machine = data.machine end
    if type(data.machines) == "table" then
      prefs.machines = data.machines
    else
      -- Migrate legacy flat prefs into the selected machine's slot.
      local id = data.machine
      if id then
        local slot = default_machine_prefs(id)
        if data.gpu ~= nil then slot.gpu = not not data.gpu end
        if data.ws ~= nil then slot.ws = not not data.ws end
        if type(data.rom) == "string" then slot.rom = data.rom end
        if type(data.url) == "string" then slot.url = data.url end
        prefs.machines[id] = slot
      end
    end
  end
  return prefs
end

local function save_prefs(prefs)
  if type(fs) ~= "table" or not fs.open then return end
  if not (textutils and textutils.serialize) then return end
  local f = fs.open(PREFS_FILE, "w")
  if not f then return end
  f.write(textutils.serialize({
    machine = prefs.machine,
    machines = prefs.machines or {},
  }))
  f.close()
end

local function write_at(x, y, text, fg, bg)
  local C = colors()
  term.setCursorPos(x, y)
  if bg then term.setBackgroundColor(bg) end
  if fg then term.setTextColor(fg) end
  term.write(text)
end

local function fill_row(y, w, bg, fg, text)
  local C = colors()
  term.setCursorPos(1, y)
  term.setBackgroundColor(bg or C.black)
  term.setTextColor(fg or C.white)
  text = tostring(text or "")
  if #text < w then
    text = text .. string.rep(" ", w - #text)
  else
    text = text:sub(1, w)
  end
  term.write(text)
end

local function hit_add(hits, x1, y1, x2, y2, action, payload)
  hits[#hits + 1] = {
    x1 = x1, y1 = y1, x2 = x2, y2 = y2,
    action = action, payload = payload,
  }
end

local function hit_test(hits, x, y)
  for i = #hits, 1, -1 do
    local h = hits[i]
    if x >= h.x1 and x <= h.x2 and y >= h.y1 and y <= h.y2 then
      return h
    end
  end
  return nil
end

local function rom_exts_for(machine_id)
  return ROM_EXTS[machine_id] or { ".rom", ".bin", ".gb" }
end

local function match_rom_ext(name, exts)
  local lower = tostring(name or ""):lower()
  for _, ext in ipairs(exts) do
    if lower:sub(-#ext) == ext:lower() then
      return true
    end
  end
  return false
end

local function parent_dir(path)
  path = tostring(path or ""):gsub("/+$", "")
  if path == "" then return "" end
  if type(fs) == "table" and fs.getDir then
    local d = fs.getDir(path)
    if d == nil or d == "" then return "" end
    return d
  end
  local d = path:match("^(.*)[/\\][^/\\]+$")
  return d or ""
end

local function display_path(path)
  if path == nil or path == "" then return "/" end
  return "/" .. tostring(path):gsub("^/+", "")
end

--- List browse entries for `dir`: optional "..", then dirs, then matching files.
--- Each entry: { name, path, kind = "up"|"dir"|"file" }
local function list_rom_entries(dir, machine_id)
  dir = dir or ""
  local exts = rom_exts_for(machine_id)
  local dirs, files = {}, {}
  for _, name in ipairs(list_dir(dir)) do
    local full = (dir == "" or dir == nil) and name or combine(dir, name)
    local is_dir = type(fs) == "table" and fs.isDir and fs.isDir(full)
    if is_dir then
      dirs[#dirs + 1] = { name = name, path = full, kind = "dir" }
    elseif match_rom_ext(name, exts) then
      files[#files + 1] = { name = name, path = full, kind = "file" }
    end
  end
  table.sort(dirs, function(a, b) return a.name:lower() < b.name:lower() end)
  table.sort(files, function(a, b) return a.name:lower() < b.name:lower() end)

  local out = {}
  if dir ~= "" then
    out[#out + 1] = { name = "..", path = parent_dir(dir), kind = "up" }
  end
  for _, e in ipairs(dirs) do out[#out + 1] = e end
  for _, e in ipairs(files) do out[#out + 1] = e end
  return out, exts
end

-- Back-compat helper used by tests / module API.
local function list_rom_files(dir, machine_id)
  local entries, exts = list_rom_entries(dir, machine_id)
  local names = {}
  for _, e in ipairs(entries) do
    if e.kind == "file" then
      names[#names + 1] = e.name
    end
  end
  return names, exts
end

local function wait_key(prompt)
  prompt = prompt or "Press any key..."
  local C = colors()
  term.setBackgroundColor(C.black)
  term.setTextColor(C.yellow)
  print("")
  print(prompt)
  term.setTextColor(C.white)
  if type(os) == "table" and type(os.pullEvent) == "function" then
    while true do
      local e = { os.pullEvent() }
      if e[1] == "key" or e[1] == "mouse_click" or e[1] == "char" then
        break
      elseif e[1] == "terminate" then
        break
      end
    end
  end
end

--- Modal file picker with directory navigation.
--- Returns a path (relative to computer root) or nil if cancelled.
local function pick_rom_file(machine_id, current)
  local C = colors()
  local dir = program_dir()
  local focus_name = nil
  -- Open in the folder of the current selection when possible.
  if type(current) == "string" and current ~= "" then
    local cur_dir = parent_dir(current)
    local base = current:match("([^/\\]+)$") or current
    if cur_dir ~= "" or file_exists(current) or file_exists(combine(dir, current)) then
      if cur_dir ~= "" and (file_exists(cur_dir) or (type(fs) == "table" and fs.isDir and fs.isDir(cur_dir))) then
        dir = cur_dir
      elseif file_exists(combine(program_dir(), current)) then
        local full = combine(program_dir(), current)
        dir = parent_dir(full)
        base = full:match("([^/\\]+)$") or base
      end
      focus_name = base
    end
  end

  local entries, exts = list_rom_entries(dir, machine_id)
  local selected = 1
  for i, e in ipairs(entries) do
    if e.kind == "file" and (e.name == focus_name or e.path == current) then
      selected = i
      break
    end
  end
  local scroll = 0
  local hits = {}

  local function reload(keep_name)
    entries, exts = list_rom_entries(dir, machine_id)
    selected = 1
    if keep_name then
      for i, e in ipairs(entries) do
        if e.name == keep_name then
          selected = i
          break
        end
      end
    end
    scroll = 0
  end

  local function activate(idx)
    local e = entries[idx]
    if not e then return nil end
    if e.kind == "up" or e.kind == "dir" then
      dir = e.path or ""
      reload()
      return "nav"
    end
    -- file
    return e.path
  end

  local function draw()
    C = colors()
    local w, h = term.getSize()
    hits = {}
    term.setBackgroundColor(C.black)
    term.clear()
    fill_row(1, w, C.gray, C.white, " SELECT ROM / CART")
    write_at(math.max(1, w - 9), 1, " Cancel ", C.white, C.red)
    hit_add(hits, w - 9, 1, w, 1, "cancel")

    local ext_s = table.concat(exts, " ")
    local path_line = " " .. display_path(dir) .. "  [" .. ext_s .. "]"
    fill_row(2, w, C.black, C.lightGray, path_line)
    -- Click path header to go up one level (when not at root).
    if dir ~= "" then
      hit_add(hits, 1, 2, w, 2, "up")
    end

    local list_top = 4
    local list_bot = math.max(list_top, h - 3)
    local list_h = list_bot - list_top + 1
    local file_count, dir_count = 0, 0
    for _, e in ipairs(entries) do
      if e.kind == "file" then file_count = file_count + 1
      elseif e.kind == "dir" then dir_count = dir_count + 1 end
    end

    if file_count == 0 and dir_count == 0 then
      fill_row(list_top, w, C.black, C.red, " (no matching files here)")
      fill_row(list_top + 1, w, C.black, C.lightGray, " Enter a folder or copy a ROM here.")
      list_top = list_top + 3
      list_h = math.max(1, list_bot - list_top + 1)
    end

    if #entries == 0 then
      -- root and empty
    else
      if selected < 1 then selected = 1 end
      if selected > #entries then selected = #entries end
      if selected < scroll + 1 then scroll = selected - 1 end
      if selected > scroll + list_h then scroll = selected - list_h end
      if scroll < 0 then scroll = 0 end
      for row = 0, list_h - 1 do
        local idx = scroll + row + 1
        local y = list_top + row
        local ent = entries[idx]
        if not ent then
          fill_row(y, w, C.black, C.black, "")
        else
          local sel = idx == selected
          local bg = sel and C.blue or C.black
          local fg, label
          if ent.kind == "up" then
            fg = sel and C.white or C.yellow
            label = ".."
          elseif ent.kind == "dir" then
            fg = sel and C.white or C.cyan
            label = ent.name .. "/"
          else
            fg = sel and C.white or C.lightGray
            label = ent.name
          end
          fill_row(y, w, bg, fg, (sel and "> " or "  ") .. label)
          hit_add(hits, 1, y, w, y, "pick", idx)
        end
      end
    end

    fill_row(h - 1, w, C.black, C.gray, string.rep("-", w))
    local hint = string.format(
      " Enter=open/select  Backspace=up  Esc=cancel  (%d dir, %d file)",
      dir_count, file_count
    )
    fill_row(h, w, C.black, C.lime, hint)
    term.setCursorBlink(false)
  end

  draw()
  while true do
    local ev = { os.pullEvent() }
    local e = ev[1]
    if e == "terminate" then
      return nil
    elseif e == "term_resize" then
      draw()
    elseif e == "mouse_click" then
      local h = hit_test(hits, ev[3], ev[4])
      if h then
        if h.action == "cancel" then
          return nil
        elseif h.action == "up" then
          dir = parent_dir(dir)
          reload()
          draw()
        elseif h.action == "pick" then
          local result = activate(h.payload)
          if result == "nav" then
            draw()
          elseif result then
            return result
          end
        end
      end
    elseif e == "key" then
      local key = ev[2]
      if key == keys.up and selected > 1 then
        selected = selected - 1
        draw()
      elseif key == keys.down and selected < #entries then
        selected = selected + 1
        draw()
      elseif key == keys.backspace or key == keys.left then
        if dir ~= "" then
          dir = parent_dir(dir)
          reload()
          draw()
        end
      elseif (key == keys.enter or key == keys.numPadEnter or key == keys.right)
          and #entries > 0 then
        local result = activate(selected)
        if result == "nav" then
          draw()
        elseif result then
          return result
        end
      elseif key == keys.escape or key == keys.q then
        return nil
      end
    end
  end
end

local function launch_argv(group, want_gpu, want_ws, rom, url)
  local variant, err = pick_variant(group, want_gpu, want_ws)
  if not variant then
    return nil, err
  end
  if not file_exists(variant.path) then
    return nil, "missing " .. variant.path
  end

  local function resolve_rom(rom_path)
    if not rom_path or rom_path == "" then
      return nil
    end
    if not file_exists(rom_path) then
      local alt = combine(program_dir(), rom_path)
      if file_exists(alt) then
        return alt
      end
    end
    return rom_path
  end

  local argv = {}
  if want_ws then
    argv[#argv + 1] = "--url"
    argv[#argv + 1] = (url and url ~= "") and url or DEFAULT_URL
    -- Game Boy WS can upload a local cart to a ROM-less bridge.
    if group.id == "gb" or group.id == "gameboy" then
      local rom_path = resolve_rom(rom)
      if (not rom_path or rom_path == "") and DEFAULT_ROM[group.id] then
        rom_path = resolve_rom(DEFAULT_ROM[group.id])
      end
      if rom_path and rom_path ~= "" then
        argv[#argv + 1] = "--rom"
        argv[#argv + 1] = rom_path
      end
    end
  else
    local rom_path = rom
    if not rom_path or rom_path == "" then
      rom_path = DEFAULT_ROM[group.id]
    end
    rom_path = resolve_rom(rom_path)
    if rom_path and rom_path ~= "" then
      argv[#argv + 1] = "--rom"
      argv[#argv + 1] = rom_path
    end
  end
  return variant, argv
end

--- Run a frontend as a real shell program so the bundle's main-program
--- auto-start + argv (`local __bundle_args = { ... }`) work.
local function launch(group, want_gpu, want_ws, rom, url)
  local variant, argv = launch_argv(group, want_gpu, want_ws, rom, url)
  if not variant then
    return nil, argv -- argv is err string here
  end

  term.setBackgroundColor(colors().black)
  term.setTextColor(colors().white)
  term.clear()
  term.setCursorPos(1, 1)
  print("Launching " .. variant.file .. " ...")
  if #argv > 0 then
    print("  " .. table.concat(argv, " "))
  end
  print("")

  local unpack_fn = table.unpack or unpack

  -- Prefer shell.execute (verbatim args). shell.run concatenates + re-tokenises,
  -- which mangled flags like --rom into a stray "-" ("unknown flag: -").
  if type(shell) == "table"
      and (type(shell.execute) == "function" or type(shell.run) == "function") then
    -- variant.path is already rooted at the launcher's directory (absolute from
    -- the computer root). Do not shell.resolve() it — that prefixes cwd and
    -- breaks when the user has `cd`'d elsewhere.
    local prog = variant.path
    local runner = shell.execute or shell.run
    local ok = runner(prog, unpack_fn(argv))
    if not ok then
      -- Bundle prints the real ERROR: … before error(); leave it on screen.
      return nil, "Frontend exited with an error (see messages above)."
    end
    return true
  end

  -- Desktop / no-shell fallback: loadfile and call api.run with opts.
  local chunk, lerr = loadfile(variant.path)
  if not chunk then
    return nil, "loadfile failed: " .. tostring(lerr)
  end
  local ok, api = pcall(chunk, unpack_fn(argv))
  if not ok then
    return nil, "frontend error: " .. tostring(api)
  end
  if type(api) ~= "table" or type(api.run) ~= "function" then
    return nil, "frontend did not return api.run"
  end
  local opts = {
    profile = api.Profile,
    fps = 30,
    args = argv,
  }
  if want_ws then
    opts.url = (url and url ~= "") and url or DEFAULT_URL
    if group.id == "gb" or group.id == "gameboy" then
      opts.rom = rom
      if not opts.rom or opts.rom == "" then
        opts.rom = DEFAULT_ROM[group.id]
      end
    end
  else
    opts.rom = rom
    if not opts.rom or opts.rom == "" then
      opts.rom = DEFAULT_ROM[group.id]
    end
  end
  local ran, rerr = api.run(opts)
  if ran == nil then
    print("")
    print("ERROR: " .. tostring(rerr or "frontend run failed"))
    return nil, rerr or "frontend run failed"
  end
  return true
end

local function report_launch(g, pcall_ok, a, b)
  if not pcall_ok then
    return "Crash: " .. tostring(a), false
  end
  -- launch returns true on success, or nil, err on failure.
  if a == nil then
    return tostring(b or "launch failed"), false
  end
  return "Returned from " .. g.title, true
end

local function after_launch(message, message_ok)
  if not message_ok then
    local C = colors()
    term.setBackgroundColor(C.black)
    term.setTextColor(C.red)
    print("")
    print("--- launch failed ---")
    for line in (tostring(message) .. "\n"):gmatch("(.-)\n") do
      print(line)
    end
    term.setTextColor(C.white)
  end
  wait_key(message_ok and "Press any key to return to launcher..."
    or "Press any key to return to launcher (fix the error above)...")
end

local function run_ui()
  local C = colors()
  local prefs = load_prefs()
  local machines, dir = scan_frontends()
  local selected = 1
  for i, g in ipairs(machines) do
    if g.id == prefs.machine then
      selected = i
      break
    end
  end
  local want_gpu, want_ws, rom, url = false, false, "", DEFAULT_URL
  local editing = nil -- "rom" | "url"
  local edit_text = ""
  local message = "Select a machine, options, then Launch"
  local message_ok = true
  local hits = {}
  local scroll = 0

  local function current()
    return machines[selected]
  end

  --- Persist the in-memory GPU/WS/ROM/URL into the current machine's slot.
  local function store_current_slot()
    local g = current()
    if not g then return end
    local slot = machine_prefs(prefs, g.id)
    slot.gpu = not not want_gpu
    slot.ws = not not want_ws
    slot.rom = rom or ""
    slot.url = url or DEFAULT_URL
    prefs.machine = g.id
  end

  --- Load GPU/WS/ROM/URL from the selected machine's slot.
  local function load_current_slot()
    local g = current()
    if not g then
      want_gpu, want_ws, rom, url = false, false, "", DEFAULT_URL
      return
    end
    local slot = machine_prefs(prefs, g.id)
    want_gpu = not not slot.gpu
    want_ws = not not slot.ws
    rom = slot.rom or ""
    url = slot.url or DEFAULT_URL
  end

  local function sync_defaults()
    local g = current()
    if not g then return end
    if want_gpu and not g.has_gpu then want_gpu = false end
    if want_ws and not g.has_ws then want_ws = false end
    if want_gpu and want_ws and not g.has_gpu_ws then
      if g.has_gpu_only then want_ws = false
      elseif g.has_ws_only then want_gpu = false
      else want_gpu, want_ws = false, false end
    end
    -- If the plain local build is missing, fall back to any available variant.
    if not pick_variant(g, want_gpu, want_ws) then
      if g.has_base then
        want_gpu, want_ws = false, false
      elseif g.has_gpu_only then
        want_gpu, want_ws = true, false
      elseif g.has_ws_only then
        want_gpu, want_ws = false, true
      elseif g.has_gpu_ws then
        want_gpu, want_ws = true, true
      end
    end
    if (rom == "" or rom == nil) and not want_ws then
      rom = DEFAULT_ROM[g.id] or ""
    end
    store_current_slot()
  end

  load_current_slot()
  sync_defaults()

  local function draw()
    C = colors()
    local w, h = term.getSize()
    hits = {}
    term.setBackgroundColor(C.black)
    term.clear()

    fill_row(1, w, C.gray, C.white, " EMULATOR LAUNCHER")
    write_at(math.max(1, w - 5), 1, " X ", C.white, C.red)
    hit_add(hits, w - 5, 1, w, 1, "quit")

    fill_row(2, w, C.black, C.lightGray, " " .. dir .. "  (" .. #machines .. " machines)")

    local list_top = 4
    local list_bot = math.min(h - 8, list_top + math.max(3, #machines) - 1)
    if list_bot < list_top then list_bot = list_top end
    local list_h = list_bot - list_top + 1
    if selected < scroll + 1 then scroll = selected - 1 end
    if selected > scroll + list_h then scroll = selected - list_h end
    if scroll < 0 then scroll = 0 end

    fill_row(3, w, C.black, C.white, " Machines")
    if #machines == 0 then
      fill_row(list_top, w, C.black, C.red, " (no *_cc.lua in frontends/)")
    else
      for row = 0, list_h - 1 do
        local idx = scroll + row + 1
        local y = list_top + row
        local g = machines[idx]
        if not g then
          fill_row(y, w, C.black, C.black, "")
        else
          local sel = idx == selected
          local bg = sel and C.blue or C.black
          local fg = sel and C.white or C.lightGray
          local marks = {}
          if g.has_gpu then marks[#marks + 1] = "GPU" end
          if g.has_ws then marks[#marks + 1] = "WS" end
          local suffix = (#marks > 0) and ("  [" .. table.concat(marks, ",") .. "]") or ""
          local label = (sel and "> " or "  ") .. g.title .. suffix
          fill_row(y, w, bg, fg, label)
          hit_add(hits, 1, y, w, y, "select", idx)
        end
      end
    end

    local y = list_bot + 2
    fill_row(y - 1, w, C.black, C.gray, string.rep("-", w))

    -- Checkboxes
    local g = current()
    local gpu_on = want_gpu
    local ws_on = want_ws
    local gpu_en = g and g.has_gpu
    local ws_en = g and g.has_ws

    local gpu_label = (gpu_en and (gpu_on and "[X] GPU" or "[ ] GPU") or "[-] GPU")
    local ws_label = (ws_en and (ws_on and "[X] WS" or "[ ] WS") or "[-] WS")
    fill_row(y, w, C.black, C.white, "")
    write_at(2, y, gpu_label, gpu_en and C.white or C.gray, C.black)
    hit_add(hits, 2, y, 2 + #gpu_label - 1, y, "toggle_gpu")
    write_at(14, y, ws_label, ws_en and C.white or C.gray, C.black)
    hit_add(hits, 14, y, 14 + #ws_label - 1, y, "toggle_ws")

    local variant = g and select(1, pick_variant(g, want_gpu, want_ws))
    local vname = variant and variant.file or "(unavailable)"
    write_at(math.min(w - #vname, 28), y, vname, C.yellow, C.black)

    y = y + 1
    local ws_rom = want_ws and g and (g.id == "gb" or g.id == "gameboy")
    if want_ws then
      local label = " URL: "
      fill_row(y, w, C.black, C.white, "")
      write_at(1, y, label, C.lightGray, C.black)
      local field = (editing == "url") and (edit_text .. "_") or url
      if #field > w - #label then field = field:sub(-(w - #label)) end
      write_at(#label + 1, y, field, C.white, editing == "url" and C.gray or C.black)
      hit_add(hits, 1, y, w, y, "edit_url")
      if ws_rom then
        y = y + 1
      end
    end
    if (not want_ws) or ws_rom then
      local label = want_ws and " CART: " or " ROM: "
      local browse = " [...] "
      fill_row(y, w, C.black, C.white, "")
      write_at(1, y, label, C.lightGray, C.black)
      local field_w = math.max(8, w - #label - #browse)
      local field = (editing == "rom") and (edit_text .. "_") or rom
      if #field > field_w then field = field:sub(-(field_w)) end
      write_at(#label + 1, y, field .. string.rep(" ", field_w - #field),
        C.white, editing == "rom" and C.gray or C.black)
      hit_add(hits, 1, y, #label + field_w, y, "edit_rom")
      write_at(#label + field_w + 1, y, browse, C.black, C.orange)
      hit_add(hits, #label + field_w + 1, y, #label + field_w + #browse, y, "browse_rom")
    end

    y = y + 2
    local launch_l = " Launch "
    local refresh_l = " Refresh "
    write_at(2, y, launch_l, C.black, C.lime)
    hit_add(hits, 2, y, 2 + #launch_l - 1, y, "launch")
    write_at(3 + #launch_l, y, refresh_l, C.black, C.lightGray)
    hit_add(hits, 3 + #launch_l, y, 2 + #launch_l + #refresh_l, y, "refresh")

    y = y + 1
    fill_row(y, w, C.black, message_ok and C.lime or C.red, " " .. tostring(message))

    term.setBackgroundColor(C.black)
    term.setTextColor(C.white)
    if editing then
      term.setCursorBlink(true)
    else
      term.setCursorBlink(false)
      term.setCursorPos(1, h)
    end
  end

  local function begin_edit(which)
    editing = which
    edit_text = (which == "url") and url or rom
  end

  local function commit_edit()
    if editing == "url" then
      url = edit_text
    elseif editing == "rom" then
      rom = edit_text
    end
    editing = nil
    store_current_slot()
  end

  draw()

  local function quit_ui()
    store_current_slot()
    save_prefs(prefs)
  end

  while true do
    local ev = { os.pullEvent() }
    local e = ev[1]
    if e == "terminate" then
      quit_ui()
      break
    elseif e == "term_resize" then
      draw()
    elseif e == "mouse_click" then
      local x, y = ev[3], ev[4]
      if editing then
        commit_edit()
      end
      local h = hit_test(hits, x, y)
      if not h then
        -- ignore
      elseif h.action == "quit" then
        quit_ui()
        break
      elseif h.action == "select" then
        store_current_slot()
        selected = h.payload
        load_current_slot()
        sync_defaults()
        message = machines[selected].title
        message_ok = true
        draw()
      elseif h.action == "toggle_gpu" then
        local g = current()
        if g and g.has_gpu then
          want_gpu = not want_gpu
          if want_gpu and want_ws and not g.has_gpu_ws then
            message = "No GPU+WS build; pick one option"
            message_ok = false
            want_gpu = false
          else
            message_ok = true
            message = want_gpu and "GPU on" or "GPU off"
          end
          store_current_slot()
          draw()
        end
      elseif h.action == "toggle_ws" then
        local g = current()
        if g and g.has_ws then
          want_ws = not want_ws
          if want_gpu and want_ws and not g.has_gpu_ws then
            message = "No GPU+WS build; pick one option"
            message_ok = false
            want_ws = false
          else
            message_ok = true
            message = want_ws and "WebSocket on" or "WebSocket off"
          end
          store_current_slot()
          draw()
        end
      elseif h.action == "edit_rom" then
        begin_edit("rom")
        draw()
      elseif h.action == "browse_rom" then
        local g = current()
        local picked = pick_rom_file(g and g.id or "ti83", rom)
        if picked then
          rom = picked
          store_current_slot()
          message = "ROM: " .. picked
          message_ok = true
        else
          message = "ROM pick cancelled"
          message_ok = true
        end
        draw()
      elseif h.action == "edit_url" then
        begin_edit("url")
        draw()
      elseif h.action == "refresh" then
        store_current_slot()
        machines, dir = scan_frontends()
        if selected > #machines then selected = math.max(1, #machines) end
        load_current_slot()
        sync_defaults()
        message = "Rescanned " .. dir
        message_ok = true
        draw()
      elseif h.action == "launch" then
        local g = current()
        if not g then
          message = "No machine selected"
          message_ok = false
          draw()
        else
          store_current_slot()
          save_prefs(prefs)
          -- pcall preserves multiple returns: success → true / nil,err
          local ok, a, b = pcall(launch, g, want_gpu, want_ws, rom, url)
          message, message_ok = report_launch(g, ok, a, b)
          after_launch(message, message_ok)
          machines, dir = scan_frontends()
          load_current_slot()
          sync_defaults()
          draw()
        end
      end
    elseif e == "key" and editing then
      local key = ev[2]
      if key == keys.enter or key == keys.numPadEnter then
        commit_edit()
        draw()
      elseif key == keys.backspace then
        edit_text = edit_text:sub(1, -2)
        draw()
      elseif key == keys.delete then
        edit_text = ""
        draw()
      elseif key == keys.escape then
        editing = nil
        draw()
      end
    elseif e == "char" and editing then
      edit_text = edit_text .. ev[2]
      draw()
    elseif e == "key" and not editing then
      local key = ev[2]
      if key == keys.up then
        if selected > 1 then
          store_current_slot()
          selected = selected - 1
          load_current_slot()
          sync_defaults()
          draw()
        end
      elseif key == keys.down then
        if selected < #machines then
          store_current_slot()
          selected = selected + 1
          load_current_slot()
          sync_defaults()
          draw()
        end
      elseif key == keys.enter or key == keys.numPadEnter then
        -- synthesize launch
        local g = current()
        if g then
          store_current_slot()
          save_prefs(prefs)
          local ok, a, b = pcall(launch, g, want_gpu, want_ws, rom, url)
          message, message_ok = report_launch(g, ok, a, b)
          after_launch(message, message_ok)
          machines, dir = scan_frontends()
          load_current_slot()
          sync_defaults()
          draw()
        end
      elseif key == keys.r then
        local g = current()
        local ws_rom = want_ws and g and (g.id == "gb" or g.id == "gameboy")
        if (not want_ws) or ws_rom then
          local picked = pick_rom_file(g and g.id or "ti83", rom)
          if picked then
            rom = picked
            store_current_slot()
            message = (want_ws and "CART: " or "ROM: ") .. picked
            message_ok = true
          end
          draw()
        end
      elseif key == keys.g then
        -- toggle gpu
        local g = current()
        if g and g.has_gpu then
          want_gpu = not want_gpu
          store_current_slot()
          draw()
        end
      elseif key == keys.w then
        local g = current()
        if g and g.has_ws then
          want_ws = not want_ws
          store_current_slot()
          draw()
        end
      elseif key == keys.q then
        quit_ui()
        break
      end
    end
  end

  term.setBackgroundColor(C.black)
  term.setTextColor(C.white)
  term.clear()
  term.setCursorPos(1, 1)
  term.setCursorBlink(false)
end

-- Module API (desktop tests / require)
local M = {
  parse_frontend_name = parse_frontend_name,
  scan_frontends = scan_frontends,
  pick_variant = pick_variant,
  frontends_dir = frontends_dir,
  rom_exts_for = rom_exts_for,
  list_rom_files = list_rom_files,
  list_rom_entries = list_rom_entries,
  parent_dir = parent_dir,
  run = run_ui,
}

if type(shell) == "table" and type(shell.getRunningProgram) == "function" then
  local running = shell.getRunningProgram()
  local name = running
  if type(fs) == "table" and fs.getName then
    name = fs.getName(running)
  end
  name = tostring(name or ""):gsub("%.lua$", ""):lower()
  if name == "emu" or name == "launcher" then
    run_ui()
  end
end

return M
