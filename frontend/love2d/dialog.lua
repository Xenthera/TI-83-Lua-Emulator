-- Native file dialogs: macOS osascript, Windows PowerShell, Linux zenity.
-- Returns nil on cancel/fail.

local M = {}

local function trim(s)
  return (s:gsub("^%s+", ""):gsub("%s+$", ""):gsub("\r", ""))
end

local function popen_read(cmd)
  local f = io.popen(cmd)
  if not f then return nil end
  local out = f:read("*a")
  f:close()
  if not out then return nil end
  out = trim(out)
  if out == "" then return nil end
  return out
end

local function os_name()
  if love and love.system then
    return love.system.getOS()
  end
  return nil
end

local function is_macos()
  return os_name() == "OS X"
end

local function is_windows()
  return os_name() == "Windows"
end

local function ps_quote(s)
  return "'" .. tostring(s):gsub("'", "''") .. "'"
end

--- Run a short PowerShell script that prints one path (or nothing).
local function win_ps_path(script_body)
  local dir = os.getenv("TEMP") or os.getenv("TMP") or "."
  local tmp = string.format("%s\\ti83_dlg_%d_%d.ps1", dir, os.time(), math.random(100000, 999999))
  local f = io.open(tmp, "wb")
  if not f then return nil end
  f:write(script_body)
  f:close()
  local out = popen_read(string.format(
    'powershell -NoProfile -STA -ExecutionPolicy Bypass -File "%s"',
    tmp
  ))
  os.remove(tmp)
  return out
end

--- kind: "open" | "save"
local function win_file_dialog(kind, opts)
  opts = opts or {}
  local lines = {
    "Add-Type -AssemblyName System.Windows.Forms",
    "$owner = New-Object System.Windows.Forms.Form",
    "$owner.TopMost = $true",
    "$owner.ShowInTaskbar = $false",
    "$owner.WindowState = 'Minimized'",
  }
  if kind == "save" then
    lines[#lines + 1] = "$d = New-Object System.Windows.Forms.SaveFileDialog"
    lines[#lines + 1] = "$d.OverwritePrompt = $true"
    lines[#lines + 1] = "$d.AddExtension = $true"
  else
    lines[#lines + 1] = "$d = New-Object System.Windows.Forms.OpenFileDialog"
  end
  if opts.filter then
    lines[#lines + 1] = "$d.Filter = " .. ps_quote(opts.filter)
  end
  if opts.title then
    lines[#lines + 1] = "$d.Title = " .. ps_quote(opts.title)
  end
  if opts.default_name then
    lines[#lines + 1] = "$d.FileName = " .. ps_quote(opts.default_name)
  end
  if opts.default_ext then
    lines[#lines + 1] = "$d.DefaultExt = " .. ps_quote(opts.default_ext)
  end
  if opts.default_dir and opts.default_dir ~= "" then
    local ddir = opts.default_dir:gsub("/", "\\")
    lines[#lines + 1] = string.format(
      "if (Test-Path -LiteralPath %s) { $d.InitialDirectory = %s }",
      ps_quote(ddir), ps_quote(ddir)
    )
  end
  lines[#lines + 1] =
    "if ($d.ShowDialog($owner) -eq [System.Windows.Forms.DialogResult]::OK) { Write-Output $d.FileName }"
  lines[#lines + 1] = "$owner.Dispose()"
  return win_ps_path(table.concat(lines, "\r\n"))
end

function M.choose_open_tiproj(default_dir)
  if is_macos() then
    -- Prefer choosing project.tiproj inside a project folder (sources are siblings).
    return popen_read([[osascript -e 'try' -e 'POSIX path of (choose file with prompt "Open project.tiproj (or packed .tiproj)" of type {"tiproj","public.json","json"})' -e 'on error' -e 'return ""' -e 'end try']])
  end
  if is_windows() then
    return win_file_dialog("open", {
      filter = "TI Project (*.tiproj)|*.tiproj|All files (*.*)|*.*",
      title = "Open TI project",
      default_dir = default_dir,
    })
  end
  return popen_read([[zenity --file-selection --file-filter='TI Project | *.tiproj' --title='Open TI project' 2>/dev/null]])
end

function M.choose_save_tiproj(default_name)
  default_name = default_name or "project.tiproj"
  if is_macos() then
    local path = popen_read(string.format(
      [[osascript -e 'try' -e 'POSIX path of (choose file name with prompt "Save TI project" default name "%s")' -e 'on error' -e 'return ""' -e 'end try']],
      default_name:gsub('"', "")
    ))
    if path and not path:match("%.tiproj$") then
      path = path .. ".tiproj"
    end
    return path
  end
  if is_windows() then
    local path = win_file_dialog("save", {
      filter = "TI Project (*.tiproj)|*.tiproj|All files (*.*)|*.*",
      title = "Save TI project",
      default_name = default_name,
      default_ext = "tiproj",
    })
    if path and not path:match("%.tiproj$") then
      path = path .. ".tiproj"
    end
    return path
  end
  return popen_read(string.format(
    [[zenity --file-selection --save --confirm-overwrite --filename='%s' --title='Save TI project' 2>/dev/null]],
    default_name
  ))
end

function M.choose_open_rom()
  if is_macos() then
    return popen_read([[osascript -e 'try' -e 'POSIX path of (choose file with prompt "Load 512KB TI-83+ ROM" of type {"rom","bin","public.data"})' -e 'on error' -e 'return ""' -e 'end try']])
  end
  if is_windows() then
    return win_file_dialog("open", {
      filter = "ROM dumps (*.rom;*.bin)|*.rom;*.bin|All files (*.*)|*.*",
      title = "Load TI-83+ ROM",
    })
  end
  return popen_read([[zenity --file-selection --file-filter='ROM dumps | *.rom *.bin' --title='Load TI-83+ ROM' 2>/dev/null]])
end

--- Pick a TI variable file (.8xk app / .8xp program / .8xg group).
-- kind: "app" | "prog" | "group"
-- default_dir: optional folder to open in the dialog
function M.choose_open_8x(kind, default_dir)
  kind = kind or "prog"
  local prompt, filter_zenity, filter_win, title, ext_list, default_ext
  if kind == "app" then
    prompt = "Load TI-83+ Flash App (.8xk)"
    filter_zenity = "Flash Apps | *.8xk *.8XK"
    filter_win = "Flash Apps (*.8xk)|*.8xk;*.8XK|All files (*.*)|*.*"
    title = "Load Flash App"
    ext_list = '{"8xk","8XK"}'
    default_ext = "8xk"
  elseif kind == "group" then
    prompt = "Load TI-83+ Group (.8xg)"
    filter_zenity = "Groups | *.8xg *.8XG"
    filter_win = "Groups (*.8xg)|*.8xg;*.8XG|All files (*.*)|*.*"
    title = "Load Group"
    ext_list = '{"8xg","8XG"}'
    default_ext = "8xg"
  else
    prompt = "Load TI-83+ Program (.8xp)"
    filter_zenity = "Programs | *.8xp *.8XP"
    filter_win = "Programs (*.8xp)|*.8xp;*.8XP|All files (*.*)|*.*"
    title = "Load Program"
    ext_list = '{"8xp","8XP"}'
    default_ext = "8xp"
  end

  prompt = prompt:gsub('"', "")
  title = title:gsub('"', "")
  default_dir = default_dir and default_dir:gsub('"', "") or nil

  if is_macos() then
    local choose
    if default_dir and default_dir ~= "" then
      choose = string.format(
        [[POSIX path of (choose file with prompt "%s" of type %s default location (POSIX file "%s"))]],
        prompt, ext_list, default_dir
      )
    else
      choose = string.format(
        [[POSIX path of (choose file with prompt "%s" of type %s)]],
        prompt, ext_list
      )
    end
    return popen_read(string.format(
      [[osascript -e 'try' -e '%s' -e 'on error' -e 'return ""' -e 'end try']],
      choose:gsub("'", "'\\''")
    ))
  end

  if is_windows() then
    return win_file_dialog("open", {
      filter = filter_win,
      title = title,
      default_dir = default_dir,
      default_ext = default_ext,
    })
  end

  if default_dir and default_dir ~= "" then
    return popen_read(string.format(
      [[zenity --file-selection --filename='%s/' --file-filter='%s' --title='%s' 2>/dev/null]],
      default_dir:gsub("'", "'\\''"), filter_zenity, title
    ))
  end
  return popen_read(string.format(
    [[zenity --file-selection --file-filter='%s' --title='%s' 2>/dev/null]],
    filter_zenity, title
  ))
end

function M.choose_save_rom(default_name)
  default_name = default_name or "pipeline.rom"
  if is_macos() then
    local path = popen_read(string.format(
      [[osascript -e 'try' -e 'POSIX path of (choose file name with prompt "Export ROM" default name "%s")' -e 'on error' -e 'return ""' -e 'end try']],
      default_name:gsub('"', "")
    ))
    if path and not path:match("%.rom$") and not path:match("%.bin$") then
      path = path .. ".rom"
    end
    return path
  end
  if is_windows() then
    local path = win_file_dialog("save", {
      filter = "ROM dumps (*.rom;*.bin)|*.rom;*.bin|All files (*.*)|*.*",
      title = "Export ROM",
      default_name = default_name,
      default_ext = "rom",
    })
    if path and not path:match("%.rom$") and not path:match("%.bin$") then
      path = path .. ".rom"
    end
    return path
  end
  return popen_read(string.format(
    [[zenity --file-selection --save --confirm-overwrite --filename='%s' --title='Export ROM' 2>/dev/null]],
    default_name
  ))
end

--- Save dialog for Flash App .8xk
function M.choose_save_8xk(default_name)
  default_name = default_name or "app.8xk"
  if is_macos() then
    local path = popen_read(string.format(
      [[osascript -e 'try' -e 'POSIX path of (choose file name with prompt "Export Flash App (.8xk)" default name "%s")' -e 'on error' -e 'return ""' -e 'end try']],
      default_name:gsub('"', "")
    ))
    if path and not path:match("%.8[xX][kK]$") then
      path = path .. ".8xk"
    end
    return path
  end
  if is_windows() then
    local path = win_file_dialog("save", {
      filter = "Flash Apps (*.8xk)|*.8xk|All files (*.*)|*.*",
      title = "Export Flash App",
      default_name = default_name,
      default_ext = "8xk",
    })
    if path and not path:match("%.8[xX][kK]$") then
      path = path .. ".8xk"
    end
    return path
  end
  return popen_read(string.format(
    [[zenity --file-selection --save --confirm-overwrite --filename='%s' --title='Export Flash App' 2>/dev/null]],
    default_name
  ))
end

return M
