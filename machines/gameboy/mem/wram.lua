-- Game Boy WRAM (8KB) + HRAM (127 bytes).

local Wram = {}
Wram.__index = Wram

function Wram.new()
  local self = setmetatable({ wram = {}, hram = {} }, Wram)
  self:clear()
  return self
end

function Wram:clear()
  for i = 0, 0x1FFF do self.wram[i] = 0 end
  for i = 0, 0x7E do self.hram[i] = 0 end
end

function Wram:read_wram(addr)
  return self.wram[addr % 0x2000] or 0
end

function Wram:write_wram(addr, v)
  self.wram[addr % 0x2000] = v % 256
end

function Wram:read_hram(addr)
  -- FF80-FFFE
  local off = (addr - 0xFF80) % 0x7F
  return self.hram[off] or 0
end

function Wram:write_hram(addr, v)
  local off = (addr - 0xFF80) % 0x7F
  self.hram[off] = v % 256
end

return Wram
