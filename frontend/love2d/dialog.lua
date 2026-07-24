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

return M
