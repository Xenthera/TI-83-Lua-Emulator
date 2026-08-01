return function(ok)
  local Z80 = require("cpus.z80.z80")

  local mem = {}
  for i = 0, 65535 do mem[i] = 0 end

  local function bus()
    return {
      read = function(addr) return mem[addr % 65536] end,
      write = function(addr, v) mem[addr % 65536] = v % 256 end,
      in_port = function() return 0xFF end,
      out_port = function() end,
      irq_pending = function() return false end,
      ack_irq = function() end,
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

  -- XOR A; INC A; HALT  -> A=1, Z clear
  for i = 0, 65535 do mem[i] = 0 end
  load(string.char(0xAF, 0x3C, 0x76))
  local cpu = Z80.new(bus())
  ok("xor/inc/halt", run_until_halt(cpu) and cpu:a() == 1)

  -- LD HL,nn; LD (HL),n; LD A,(HL)
  for i = 0, 65535 do mem[i] = 0 end
  load(string.char(
    0x21, 0x00, 0xC0, -- LD HL,$C000
    0x36, 0x42,       -- LD (HL),$42
    0x7E,             -- LD A,(HL)
    0x76
  ))
  cpu = Z80.new(bus())
  ok("ld hl / (hl)", run_until_halt(cpu) and cpu:a() == 0x42 and mem[0xC000] == 0x42)

  -- ADD HL,BC
  for i = 0, 65535 do mem[i] = 0 end
  load(string.char(
    0x01, 0x34, 0x12, -- LD BC,$1234
    0x21, 0x21, 0x43, -- LD HL,$4321
    0x09,             -- ADD HL,BC
    0x76
  ))
  cpu = Z80.new(bus())
  ok("add hl,bc", run_until_halt(cpu) and cpu.hl == 0x5555)

  -- LDIR
  for i = 0, 65535 do mem[i] = 0 end
  mem[0x1000] = 0x11
  mem[0x1001] = 0x22
  mem[0x1002] = 0x33
  load(string.char(
    0x21, 0x00, 0x10, -- LD HL,$1000
    0x11, 0x00, 0x20, -- LD DE,$2000
    0x01, 0x03, 0x00, -- LD BC,3
    0xED, 0xB0,       -- LDIR
    0x76
  ))
  cpu = Z80.new(bus())
  ok("ldir", run_until_halt(cpu, 100000)
    and mem[0x2000] == 0x11 and mem[0x2001] == 0x22 and mem[0x2002] == 0x33
    and cpu.bc == 0)

  -- CALL/RET
  for i = 0, 65535 do mem[i] = 0 end
  load(string.char(
    0xCD, 0x10, 0x00, -- CALL $0010
    0x3E, 0x99,       -- LD A,$99
    0x76
  ), 0)
  load(string.char(
    0x3E, 0x55, -- LD A,$55
    0xC9        -- RET
  ), 0x10)
  cpu = Z80.new(bus())
  ok("call/ret", run_until_halt(cpu) and cpu:a() == 0x99)

  -- DJNZ
  for i = 0, 65535 do mem[i] = 0 end
  load(string.char(
    0x06, 0x03, -- LD B,3
    0x3E, 0x00, -- LD A,0
    0x3C,       -- INC A
    0x10, 0xFD, -- DJNZ -3
    0x76
  ))
  cpu = Z80.new(bus())
  ok("djnz", run_until_halt(cpu) and cpu:a() == 3 and cpu:b() == 0)

  -- IM1 interrupt
  for i = 0, 65535 do mem[i] = 0 end
  local irq = false
  load(string.char(
    0xED, 0x56, -- IM 1
    0xFB,       -- EI
    0x00,       -- NOP (ei delay)
    0x76        -- HALT
  ))
  -- ISR at 0x38
  mem[0x38] = 0x3E -- LD A,$AA
  mem[0x39] = 0xAA
  mem[0x3A] = 0xC9 -- RET
  local b = bus()
  b.irq_pending = function() return irq end
  b.ack_irq = function() irq = false end
  cpu = Z80.new(b)
  cpu:step() -- IM 1
  cpu:step() -- EI (IFF on, IRQ suppressed for one instr)
  irq = true
  cpu:step() -- NOP runs (IRQ suppressed)
  cpu:step() -- IRQ accepted here (instead of HALT)
  for _ = 1, 20 do
    if cpu:a() == 0xAA then break end
    cpu:step()
  end
  ok("im1 irq", cpu:a() == 0xAA)

  -- IM2 interrupt (ED5E). Regression: ED5E was wrongly decoded as IM 1.
  for i = 0, 65535 do mem[i] = 0 end
  irq = false
  load(string.char(
    0x3E, 0x99,       -- LD A,$99
    0xED, 0x47,       -- LD I,A
    0xED, 0x5E,       -- IM 2
    0xFB,             -- EI
    0x00,             -- NOP
    0x76              -- HALT
  ))
  -- 257-byte vector table at $9900 filled with $9A → ISR at $9A9A
  for a = 0x9900, 0x9A00 do
    mem[a] = 0x9A
  end
  mem[0x9A9A] = 0x3E -- LD A,$BB
  mem[0x9A9B] = 0xBB
  mem[0x9A9C] = 0xC9 -- RET
  b = bus()
  b.irq_pending = function() return irq end
  b.ack_irq = function() irq = false end
  cpu = Z80.new(b)
  cpu:step() -- LD A,$99
  cpu:step() -- LD I,A
  cpu:step() -- IM 2
  ok("im2 mode set", cpu.im == 2)
  cpu:step() -- EI
  irq = true
  cpu:step() -- NOP (delay)
  cpu:step() -- IRQ → $9A9A
  for _ = 1, 20 do
    if cpu:a() == 0xBB then break end
    cpu:step()
  end
  ok("im2 irq", cpu:a() == 0xBB and cpu.im == 2)
end
