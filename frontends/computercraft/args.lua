-- ComputerCraft / bundle argv parser.

local M = {}

function M.usage_text()
  return [[NAME
    ti83_cc / test - TI-83 Plus emulator for ComputerCraft

SYNOPSIS
    test [OPTIONS] [lcd] [pad]
    ti83_cc [OPTIONS] [lcd] [pad]

DESCRIPTION
    Boots a 512KB TI-83+ flash dump. Attach one or more advanced monitors;
    each can be toggled between LCD display and keypad independently
    (multiple LCDs and/or keypads are fine). The computer screen is a
    control panel: perf status bar, per-monitor toggles, and a clickable
    list of .8xk / .8xp files next to the program.

OPTIONS
    -h, --help
        Show this help and exit.

    --rom PATH
        512KB TI-83+ flash image (default: ti83plus.rom).

    --loadapp PATH
        Install a Flash App (.8xk) into archive pages before boot.
        Repeatable. Also accepts bare PATH ending in .8xk.
        You can also click .8xk files in the control panel after start.

    --loadprog PATH
        Hint only (shown in the status message). After homescreen, click the
        .8xp / .8xg in the file list (or pass bare PATH ending in .8xp/.8xg).

    lcd pad
        Initial monitor sides (default: first found = LCD, others = PAD).
        Toggle any monitor on the control panel anytime.

EXAMPLES
    test
    test --help
    test --loadapp bubapp.8xk
    test left right

CONTROL PANEL
    Status bar     ||/> pause  >| step  G gate  Hz field  T theme
                   click Hz to type (Enter commit, Esc cancel)
                   plus MHz / %% realtime (messages wrap)
    Themes         gray (real LCD), orig, hi, b/w, w/b, amber, ocean, candy
    Gate           when ON, run at N Z80 instructions/sec instead of realtime
    Monitor chips  click cycles LCD -> PAD -> MEM -> OFF
                   MEM = 64KB color memory map (all 16 CC colors)
                   OFF = blank monitor, no rendering
    IDENTIFY       center each monitor's side name (large text)
    REFRESH        rescan .8xk / .8xp / .8xg files
    File list      click APP (.8xk), PRGM (.8xp), or GRP (.8xg) to install
    X              quit

NOTES
    .8xk = Flash App (APPS) - install restarts the calculator so the OS
           rescans the archive (safe; live poke without reset crashes).
    .8xp = Program (PRGM) - needs homescreen / VAT ready.
    .8xg = Group - unpacks contained programs into PRGM (like Ungroup).
    .8xv = AppVar (not listed yet)
    Monitor roles are saved to ti83.prefs next to the program.
]]
end

local function is_8xk(path)
  return type(path) == "string" and path:lower():match("%.8xk$") ~= nil
end

local function is_8xp(path)
  return type(path) == "string" and path:lower():match("%.8xp$") ~= nil
end

local function is_8xg(path)
  return type(path) == "string" and path:lower():match("%.8xg$") ~= nil
end

local function looks_flag(s)
  return type(s) == "string" and s:sub(1, 1) == "-"
end

local function take_eq(flag, a)
  local prefix = "--" .. flag .. "="
  if type(a) == "string" and a:sub(1, #prefix) == prefix then
    return a:sub(#prefix + 1)
  end
  return nil
end

--- Parse shell/bundle args into host opts fields.
function M.parse(args)
  args = args or {}
  local opts = {
    loadapp = {},
    loadprog = {},
    positional = {},
  }
  local i = 1
  while i <= #args do
    local a = args[i]
    if a == nil then
      break
    elseif a == "-h" or a == "--help" then
      opts.help = true
    elseif a == "--rom" then
      i = i + 1
      if not args[i] then return nil, "--rom needs a path" end
      opts.rom = args[i]
    elseif take_eq("rom", a) then
      opts.rom = take_eq("rom", a)
      if opts.rom == "" then return nil, "--rom= needs a path" end
    elseif a == "--loadapp" then
      i = i + 1
      if not args[i] then return nil, "--loadapp needs a .8xk path" end
      opts.loadapp[#opts.loadapp + 1] = args[i]
    elseif take_eq("loadapp", a) then
      local path = take_eq("loadapp", a)
      if not path or path == "" then return nil, "--loadapp= needs a .8xk path" end
      opts.loadapp[#opts.loadapp + 1] = path
    elseif a == "--loadprog" then
      i = i + 1
      if not args[i] then return nil, "--loadprog needs a .8xp/.8xg path" end
      opts.loadprog[#opts.loadprog + 1] = args[i]
    elseif take_eq("loadprog", a) then
      local path = take_eq("loadprog", a)
      if not path or path == "" then return nil, "--loadprog= needs a .8xp/.8xg path" end
      opts.loadprog[#opts.loadprog + 1] = path
    elseif is_8xk(a) then
      opts.loadapp[#opts.loadapp + 1] = a
    elseif is_8xp(a) or is_8xg(a) then
      opts.loadprog[#opts.loadprog + 1] = a
    elseif looks_flag(a) then
      return nil, "unknown flag: " .. a .. "\nTry: test --help"
    else
      opts.positional[#opts.positional + 1] = a
    end
    i = i + 1
  end

  local pos = {}
  local sides = {
    left = true, right = true, top = true, bottom = true, front = true, back = true,
  }
  for _, p in ipairs(opts.positional) do
    if looks_flag(p) then
      return nil, "unexpected flag in positionals: " .. p
    elseif is_8xk(p) then
      opts.loadapp[#opts.loadapp + 1] = p
    elseif is_8xp(p) or is_8xg(p) then
      opts.loadprog[#opts.loadprog + 1] = p
    elseif type(p) == "string" and p:lower():match("%.rom$") then
      if not opts.rom then opts.rom = p end
    else
      pos[#pos + 1] = p
    end
  end

  opts.lcd = pos[1]
  opts.pad = pos[2]
  if not opts.rom then
    local cand = pos[3]
    if cand and not sides[cand] then
      opts.rom = cand
    else
      opts.rom = "ti83plus.rom"
    end
  end
  return opts
end

function M.looks_flag(s)
  return looks_flag(s)
end

function M.recover_misparsed(opts)
  opts = opts or {}
  if not (looks_flag(opts.lcd) or looks_flag(opts.pad) or looks_flag(opts.rom)) then
    return nil
  end
  local argv = {}
  for _, key in ipairs({ "lcd", "pad", "rom" }) do
    if opts[key] ~= nil and opts[key] ~= "" then
      argv[#argv + 1] = opts[key]
    end
  end
  return M.parse(argv)
end

return M
