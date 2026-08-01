-- ComputerCraft host profile: TI-84 Plus.
local CC = require("frontends.computercraft.cc")
local romutil = require("machines.ti84plus.util.rom")

local P = {
  id = "ti84plus",
  title = "TI-84+",
  Machine = require("machines.ti84plus.machine"),
  LcdView = require("frontends.computercraft.lcd_view"),
  KeypadView = require("frontends.computercraft.keypad_view_ti84"),
  MemMapView = require("frontends.computercraft.mem_map_view"),
  Args = require("frontends.computercraft.args_ti84"),
  Eightxk = require("machines.ti84plus.util.eightxk"),
  Eightxp = require("machines.ti84plus.util.eightxp"),
  default_rom = "ti84plus.rom",
  prefs_file = "ti84.prefs",
  supports_8xk = true,
  supports_8xp = true,
  boot_label = "TI-84+ bundle: starting...",
}

local ROM_CANDIDATES = {
  "ti84plus.rom",
  "ti84p.rom",
  "ti84.rom",
}

local function try_read(path)
  local data, err = CC.read_file(path)
  if data then return data end
  return nil, err
end

function P.load_rom(path)
  path = path or P.default_rom
  local data, err = try_read(path)
  if not data and path == P.default_rom then
    for _, cand in ipairs(ROM_CANDIDATES) do
      if cand ~= path then
        data = try_read(cand)
        if data then
          path = cand
          break
        end
      end
    end
  end
  if not data then
    local names = CC.list_dir("")
    local hint = err or ("cannot open ROM " .. tostring(path))
    hint = hint .. "\n  Need a 1MB flash image named 'ti84plus.rom' (or ti84p.rom / ti84.rom)."
    hint = hint .. "\n  Copy a TI-84 Plus dump onto this computer."
    if names and #names > 0 then
      hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
    else
      hint = hint .. "\n  (no files listed in the computer directory)"
    end
    return nil, hint
  end
  if #data ~= romutil.FLASH_SIZE then
    return nil, string.format(
      "ROM '%s' is %d bytes; expected %d (1MB TI-84+ dump).\n"
        .. "  Use a real ti84plus.rom / ti84p.rom dump (not a 512KB TI-83+ image).",
      tostring(path), #data, romutil.FLASH_SIZE
    )
  end
  local validated, verr = romutil.validate(data)
  if not validated then
    return nil, verr or "ROM validate failed"
  end
  return validated
end

function P.mem_source(machine)
  return machine.mmu
end

function P.mem_paint_opts(machine)
  return {
    pc = machine.cpu.pc,
    sp = machine.cpu.sp,
  }
end

function P.wake_os(machine, opts)
  if machine.wake_os then
    return machine:wake_os(opts)
  end
end

return P
