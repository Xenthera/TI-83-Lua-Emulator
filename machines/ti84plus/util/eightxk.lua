-- .8xk helpers; ROM image size is 1MB on TI-84 Plus (see machines.ti84plus.util.rom).
local Eightxk = require("machines.ti83plus.util.eightxk")
local FLASH_SIZE = 1024 * 1024

local M = {}
for k, v in pairs(Eightxk) do
  M[k] = v
end
M.FLASH_SIZE = FLASH_SIZE

function M.inject(rom, app_bytes, opts)
  if type(rom) == "string" and #rom == FLASH_SIZE then
    -- Archive inject on 83+ helper expects 512KB; operate on low 512KB mirror and
    -- leave the upper half (boot/cert/extra archive) intact.
    local low = rom:sub(1, 512 * 1024)
    local high = rom:sub(512 * 1024 + 1)
    local out, err = Eightxk.inject(low, app_bytes, opts)
    if not out then return nil, err end
    return out .. high
  end
  return Eightxk.inject(rom, app_bytes, opts)
end

return M
