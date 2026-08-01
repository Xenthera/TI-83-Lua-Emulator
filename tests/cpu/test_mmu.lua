return function(ok)
  local Flash = require("machines.ti83plus.mem.flash")
  local Ram = require("machines.ti83plus.mem.ram")
  local Mmu = require("machines.ti83plus.mem.mmu")

  local flash = Flash.new()
  for i = 0, flash.SIZE - 1 do flash.bytes[i] = 0 end
  flash.bytes[0] = 0xC3
  flash.bytes[0x4000] = 0xAB
  flash.data = string.rep("\0", flash.SIZE)

  local ram = Ram.new()
  local mmu = Mmu.new(flash, ram)
  mmu:reset()

  ok("boot page read", mmu:read(0x0000) == 0xC3)

  mmu:set_bankA(0x01)
  ok("bankA flash page1", mmu:read(0x4000) == 0xAB)

  mmu:set_bankA(0x40) -- RAM page 0 at 4000
  mmu:write(0x4000, 0x55)
  ok("bankA ram write", mmu:read(0x4000) == 0x55 and ram:read(0, 0) == 0x55)

  mmu:set_bankB(0x41) -- RAM page 1 (bit6 = RAM on 83+)
  mmu:write(0x8000, 0x66)
  ok("bankB ram1", ram:read(1, 0) == 0x66)

  -- Mode 1: Bank A appears at 8000 (boot path JP 80xx)
  flash.bytes[0x1F * 0x4000 + 0x0D5] = 0xC9 -- RET at page 1F:0D5
  mmu:set_mem_mode(0)
  mmu:set_bankA(0x1F)
  mmu:set_mem_mode(1)
  ok("mode1 bankA at 8000", mmu:read(0x80D5) == 0xC9)

  -- Mode 1: C000-FFFF is Bank B (not fixed RAM0). Map RAM page 0 there.
  mmu:set_bankB(0x40)
  mmu:write(0xC000, 0x77)
  ok("c000 write visible", mmu:read(0xC000) == 0x77 and ram:read(0, 0) == 0x77)
end
