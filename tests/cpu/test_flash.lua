return function(ok)
  local Flash = require("machines.ti83plus.mem.flash")
  local Ram = require("machines.ti83plus.mem.ram")
  local Mmu = require("machines.ti83plus.mem.mmu")

  local function unlock(mmu)
    mmu.flash_unlocked = true
  end

  local function amd_program(mmu, z80_addr, value)
    -- Classic AMD byte program. Unlock uses bottom-12-bit addresses.
    mmu:write(0x0AAA, 0xAA)
    mmu:write(0x0555, 0x55)
    mmu:write(0x0AAA, 0xA0)
    mmu:write(z80_addr, value)
  end

  -- Fill archive-ish page 0x08 with 0xFF so we can program bits down.
  local flash = Flash.new()
  for i = 0, flash.SIZE - 1 do
    flash.bytes[i] = 0xFF
  end
  -- Keep a recognizable byte on page 0 for identity checks.
  flash.bytes[0] = 0xC3

  local ram = Ram.new()
  local mmu = Mmu.new(flash, ram)
  mmu:reset()

  -- Locked: writes ignored
  flash.bytes[0x0AAA] = 0xFF
  mmu:write(0x0AAA, 0x00)
  ok("locked write ignored", flash.bytes[0x0AAA] == 0xFF)

  unlock(mmu)

  -- Program a byte on page 0 at offset 0x100
  amd_program(mmu, 0x0100, 0xA5)
  ok("program byte", flash.bytes[0x0100] == 0xA5)
  ok("cmd idle after program", flash.cmd_state == 0 and not flash.override_reads)

  -- Can only clear bits: programming 0xFF over 0xA5 stays 0xA5
  amd_program(mmu, 0x0100, 0xFF)
  ok("program cannot set bits", flash.bytes[0x0100] == 0xA5)

  -- Program via bank A mapping (page 8 at 4000h)
  mmu:set_bankA(0x08)
  mmu:write(0x4AAA, 0xAA)
  mmu:write(0x4555, 0x55)
  mmu:write(0x4AAA, 0xA0)
  mmu:write(0x4100, 0x3C)
  local abs = 0x08 * 0x4000 + 0x100
  ok("program via bankA", flash.bytes[abs] == 0x3C)

  -- Sector erase: put pattern across pages 8-11, erase via page 8
  for p = 8, 11 do
    for o = 0, 0x3FFF, 0x100 do
      flash.bytes[p * 0x4000 + o] = 0x00
    end
  end
  flash.bytes[12 * 0x4000] = 0x00 -- next sector sentinel
  mmu:write(0x4AAA, 0xAA)
  mmu:write(0x4555, 0x55)
  mmu:write(0x4AAA, 0x80)
  mmu:write(0x4AAA, 0xAA)
  mmu:write(0x4555, 0x55)
  mmu:write(0x4000, 0x30) -- erase sector containing page 8
  ok("erase cleared page8", flash.bytes[8 * 0x4000] == 0xFF)
  ok("erase cleared page11", flash.bytes[11 * 0x4000 + 0x100] == 0xFF)
  ok("erase spared next sector", flash.bytes[12 * 0x4000] == 0x00)

  -- Boot sector erase refused (pages 0x1C-0x1F)
  flash.bytes[0x1C * 0x4000] = 0x55
  mmu:set_bankA(0x1C)
  mmu:write(0x4AAA, 0xAA)
  mmu:write(0x4555, 0x55)
  mmu:write(0x4AAA, 0x80)
  mmu:write(0x4AAA, 0xAA)
  mmu:write(0x4555, 0x55)
  mmu:write(0x4000, 0x30)
  ok("boot sector erase blocked", flash.bytes[0x1C * 0x4000] == 0x55)

  -- Autoselect manufacturer / device
  mmu:set_bankA(0x00)
  mmu:write(0x0AAA, 0xAA)
  mmu:write(0x0555, 0x55)
  mmu:write(0x0AAA, 0x90)
  ok("autoselect mfg", mmu:read(0x0000) == 0x01)
  ok("autoselect device", mmu:read(0x0002) == 0x23)
  mmu:write(0x0000, 0xF0)
  ok("reset exits autoselect", mmu:read(0x0000) == 0xC3)

  -- Mid-sequence read aborts
  mmu:write(0x0AAA, 0xAA)
  ok("unlock1 active", flash.override_reads == true)
  local _ = mmu:read(0x0000)
  ok("read aborts unlock", flash.cmd_state == 0 and not flash.override_reads)

  -- Locking clears command state
  mmu:write(0x0AAA, 0xAA)
  mmu.flash_unlocked = false
  flash:reset_cmd()
  ok("manual reset_cmd", not flash.override_reads)
end
