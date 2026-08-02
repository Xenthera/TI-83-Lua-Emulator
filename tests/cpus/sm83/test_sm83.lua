return function(ok)
  local SM83 = require("cpus.sm83.sm83")
  local bit = require("framework.util.bit")
  local band = bit.band

  local mem = {}
  local function clear()
    for i = 0, 65535 do mem[i] = 0 end
  end

  local function bus()
    return {
      read = function(addr) return mem[addr % 65536] end,
      write = function(addr, v) mem[addr % 65536] = v % 256 end,
    }
  end

  local function load(bytes, at)
    at = at or 0
    for i = 1, #bytes do
      mem[at + i - 1] = bytes:byte(i)
    end
  end

  local function run_until_halt(cpu, max_steps)
    max_steps = max_steps or 10000
    for _ = 1, max_steps do
      if cpu.halted then return true end
      cpu:step()
    end
    return false
  end

  -- XOR A; INC A; HALT -> A=1
  clear()
  load(string.char(0xAF, 0x3C, 0x76))
  local cpu = SM83.new(bus())
  ok("xor/inc/halt", run_until_halt(cpu) and cpu.a == 1)

  -- LD HL,nn; LD (HL),n; LD A,(HL)
  clear()
  load(string.char(
    0x21, 0x00, 0xC0,
    0x36, 0x42,
    0x7E,
    0x76
  ))
  cpu = SM83.new(bus())
  ok("ld hl / (hl)", run_until_halt(cpu) and cpu.a == 0x42 and mem[0xC000] == 0x42)

  -- ADD HL,BC
  clear()
  load(string.char(
    0x01, 0x34, 0x12,
    0x21, 0x21, 0x43,
    0x09,
    0x76
  ))
  cpu = SM83.new(bus())
  ok("add hl,bc", run_until_halt(cpu) and cpu:hl() == 0x5555)

  -- CALL/RET
  clear()
  load(string.char(
    0xCD, 0x10, 0x00,
    0x3E, 0x99,
    0x76
  ), 0)
  load(string.char(
    0x3E, 0x55,
    0xC9
  ), 0x10)
  cpu = SM83.new(bus())
  ok("call/ret", run_until_halt(cpu) and cpu.a == 0x99)

  -- LDH (n),A / LDH A,(n)
  clear()
  load(string.char(
    0x3E, 0xAB,
    0xE0, 0x80,
    0xAF,
    0xF0, 0x80,
    0x76
  ))
  cpu = SM83.new(bus())
  ok("ldh roundtrip", run_until_halt(cpu) and cpu.a == 0xAB and mem[0xFF80] == 0xAB)

  -- CB SWAP / BIT
  clear()
  load(string.char(
    0x3E, 0xF0,
    0xCB, 0x37, -- SWAP A
    0xCB, 0x7F, -- BIT 7,A
    0x76
  ))
  cpu = SM83.new(bus())
  ok("cb swap/bit", run_until_halt(cpu) and cpu.a == 0x0F and cpu:flag_z())

  -- JR NZ
  clear()
  load(string.char(
    0x06, 0x03, -- LD B,3
    0x3E, 0x00, -- LD A,0
    0x3C,       -- INC A
    0x05,       -- DEC B
    0x20, 0xFC, -- JR NZ,-4
    0x76
  ))
  cpu = SM83.new(bus())
  ok("jr nz loop", run_until_halt(cpu) and cpu.a == 3 and cpu.b == 0)

  -- PUSH/POP AF (low nibble cleared)
  clear()
  load(string.char(
    0x3E, 0x12,
    0xF6, 0x0F, -- OR $0F
    0xF5,
    0xAF,
    0xF1,
    0x76
  ))
  cpu = SM83.new(bus())
  ok("push/pop af", run_until_halt(cpu) and cpu.a == 0x1F and band(cpu.f, 0x0F) == 0)

  -- Interrupt accept
  clear()
  mem[0xFFFF] = 0x01
  mem[0xFF0F] = 0x01
  load(string.char(0x00, 0x76), 0)
  load(string.char(0x3E, 0x77, 0x76), 0x40)
  cpu = SM83.new(bus())
  cpu.ime = true
  cpu.pc = 0
  cpu.sp = 0xFFFE
  local saw = false
  for _ = 1, 20 do
    cpu:step()
    if cpu.a == 0x77 then saw = true; break end
  end
  ok("irq vblank", saw and mem[0xFF0F] == 0 and not cpu.ime)

  -- EI delay: interrupt after next insn
  clear()
  mem[0xFFFF] = 0x01
  mem[0xFF0F] = 0x01
  load(string.char(
    0xFB,       -- EI
    0x3E, 0x11, -- LD A,$11
    0x00,
    0x76
  ), 0)
  load(string.char(0x3E, 0x22, 0x76), 0x40)
  cpu = SM83.new(bus())
  cpu.pc = 0
  cpu.sp = 0xFFFE
  for _ = 1, 30 do
    if cpu.halted then break end
    cpu:step()
  end
  ok("ei delay", cpu.a == 0x22)

  -- ADD SP,e
  clear()
  load(string.char(
    0x31, 0xFF, 0x00, -- LD SP,$00FF
    0xE8, 0x01,       -- ADD SP,1
    0x76
  ))
  cpu = SM83.new(bus())
  ok("add sp,e", run_until_halt(cpu) and cpu.sp == 0x0100 and cpu:flag_c())

  -- EI+HALT with pending IRQ: HALT bug must not double-fetch the ISR prologue.
  -- Tobu Tobu Girl dies if PUSH HL at $0050 runs twice and RETI returns into WRAM.
  clear()
  mem[0xFFFF] = 0x04 -- timer
  mem[0xFF0F] = 0x04
  load(string.char(
    0x21, 0x34, 0x12, -- LD HL,$1234
    0xFB,             -- EI
    0x76,             -- HALT (IME still 0 -> sets halt_bug; IME enables after)
    0x00,             -- would be duplicated if no IRQ; IRQ should clear halt_bug
    0x76
  ), 0)
  load(string.char(
    0xE5, -- PUSH HL
    0xE1, -- POP HL
    0xD9  -- RETI
  ), 0x50)
  cpu = SM83.new(bus())
  cpu.pc = 0
  cpu.sp = 0xFFFE
  local returned = false
  for _ = 1, 40 do
    cpu:step()
    -- RETI must land on the NOP after HALT ($0005), not WRAM / a double-pushed junk addr.
    if cpu.pc == 0x0005 and not cpu.halt_bug and cpu.ime then
      returned = true
      break
    end
  end
  ok("ei+halt irq clears halt_bug", returned and cpu.sp == 0xFFFE and cpu:hl() == 0x1234)
end
