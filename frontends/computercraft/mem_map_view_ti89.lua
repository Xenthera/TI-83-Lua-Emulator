-- TI-89 Titanium RAM heatmap for ComputerCraft (256KB physical RAM).
-- Reuses the TI-83+ painter grid, reading through a thin :read adapter.

local Base = require("frontends.computercraft.mem_map_view")
local M = {}
M.__index = M

local RAM_VIEW = 65536 -- show low 64KB window of the 256KB SRAM

function M.new(mon_or_side, opts)
  local self = setmetatable({}, M)
  self._view = Base.new(mon_or_side, opts)
  return self
end

function M:setup()
  return self._view:setup()
end

local function ram_adapter(machine)
  local ram = machine and machine.ram
  return {
    read = function(_, addr)
      if not ram then return 0 end
      if ram.read8 then return ram:read8(addr % RAM_VIEW) end
      local bytes = ram.bytes
      if bytes then return bytes[addr % (ram.SIZE or RAM_VIEW)] or 0 end
      return 0
    end,
  }
end

--- Paint RAM view. opts.pc / opts.sp should already be mapped into 0..FFFF when in view.
function M:paint(machine, opts)
  opts = opts or {}
  local src = ram_adapter(machine)
  return self._view:paint(src, opts)
end

--- Host helper: markers for A7 / PC when they land in the low 64KB RAM window.
function M.markers_for(machine)
  local cpu = machine and machine.cpu
  if not cpu then return {} end
  local pc = cpu.pc or 0
  local sp = 0
  if cpu.get_a then
    sp = cpu:get_a(7) or 0
  elseif cpu.a then
    sp = cpu.a[7] or 0
  end
  local out = {}
  if (pc % 0x1000000) < RAM_VIEW then
    out.pc = pc % RAM_VIEW
  end
  if (sp % 0x1000000) < 0x40000 then
    local a = sp % 0x40000
    if a < RAM_VIEW then out.sp = a end
  end
  return out
end

return M
