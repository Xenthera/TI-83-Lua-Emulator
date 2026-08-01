-- ComputerCraft host profile: TI-83 Plus.
local CC = require("frontends.computercraft.cc")
local romutil = require("machines.ti83plus.util.rom")

local P = {
  id = "ti83plus",
  title = "TI-83+",
  Machine = require("machines.ti83plus.machine"),
  LcdView = require("frontends.computercraft.lcd_view"),
  KeypadView = require("frontends.computercraft.keypad_view"),
  MemMapView = require("frontends.computercraft.mem_map_view"),
  Args = require("frontends.computercraft.args"),
  default_rom = "ti83plus.rom",
  prefs_file = "ti83.prefs",
  supports_8xk = true,
  supports_8xp = true,
  boot_label = "TI-83 bundle: starting...",
}

function P.load_rom(path)
  local data, err = CC.read_file(path)
  if not data then
    local names = CC.list_dir("")
    local hint = err or ("cannot open ROM " .. tostring(path))
    hint = hint .. "\n  Need a 512KB flash image named '" .. tostring(path) .. "'."
    hint = hint .. "\n  Copy rom/pipeline.rom (or ti83plus.rom) onto this computer."
    if names and #names > 0 then
      hint = hint .. "\n  Files here: " .. table.concat(names, ", ")
    else
      hint = hint .. "\n  (no files listed in the computer directory)"
    end
    return nil, hint
  end
  if #data ~= romutil.FLASH_SIZE then
    return nil, string.format(
      "ROM '%s' is %d bytes; expected %d (512KB TI-83+ dump).\n"
        .. "  Use rom/pipeline.rom from the repo, or a real ti83plus.rom dump.",
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
