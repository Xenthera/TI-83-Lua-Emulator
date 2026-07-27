-- Native file dialogs when available (macOS osascript / zenity); nil on cancel/fail.

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

local function is_macos()
  return love and love.system and love.system.getOS() == "OS X"
end

function M.choose_open_tiproj()
  if is_macos() then
    -- Prefer choosing project.tiproj inside a project folder (sources are siblings).
    return popen_read([[osascript -e 'try' -e 'POSIX path of (choose file with prompt "Open project.tiproj (or packed .tiproj)" of type {"tiproj","public.json","json"})' -e 'on error' -e 'return ""' -e 'end try']])
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
  return popen_read(string.format(
    [[zenity --file-selection --save --confirm-overwrite --filename='%s' --title='Save TI project' 2>/dev/null]],
    default_name
  ))
end

function M.choose_open_rom()
  if is_macos() then
    return popen_read([[osascript -e 'try' -e 'POSIX path of (choose file with prompt "Load 512KB TI-83+ ROM" of type {"rom","bin","public.data"})' -e 'on error' -e 'return ""' -e 'end try']])
  end
  return popen_read([[zenity --file-selection --file-filter='ROM dumps | *.rom *.bin' --title='Load TI-83+ ROM' 2>/dev/null]])
end

--- Pick a TI variable file (.8xk app / .8xp program / .8xg group).
-- kind: "app" | "prog" | "group"
-- default_dir: optional folder to open in the dialog
function M.choose_open_8x(kind, default_dir)
  kind = kind or "prog"
  local prompt, filter_zenity, title, ext_list
  if kind == "app" then
    prompt = "Load TI-83+ Flash App (.8xk)"
    filter_zenity = "Flash Apps | *.8xk *.8XK"
    title = "Load Flash App"
    ext_list = '{"8xk","8XK"}'
  elseif kind == "group" then
    prompt = "Load TI-83+ Group (.8xg)"
    filter_zenity = "Groups | *.8xg *.8XG"
    title = "Load Group"
    ext_list = '{"8xg","8XG"}'
  else
    prompt = "Load TI-83+ Program (.8xp)"
    filter_zenity = "Programs | *.8xp *.8XP"
    title = "Load Program"
    ext_list = '{"8xp","8XP"}'
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
  return popen_read(string.format(
    [[zenity --file-selection --save --confirm-overwrite --filename='%s' --title='Export Flash App' 2>/dev/null]],
    default_name
  ))
end

return M
