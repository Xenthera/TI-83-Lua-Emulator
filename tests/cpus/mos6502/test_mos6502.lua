return function(ok)
  local CPU = require("cpus.mos6502.mos6502")
  local bit = require("framework.util.bit")
  local band = bit.band

  local mem = {}
  local function clear()
    for i = 0, 65535 do mem[i] = 0 end
  end
  local function bus()
    return {
      read = function(addr) return mem[addr % 65536] or 0 end,
      write = function(addr, v) mem[addr % 65536] = v % 256 end,
    }
  end
  local function load(bytes, at)
    at = at or 0
    for i = 1, #bytes do mem[at + i - 1] = bytes:byte(i) end
  end

  -- LDA #$42; STA $00; BRK-ish halt via JMP self
  clear()
  load(string.char(0xA9, 0x42, 0x85, 0x00, 0x4C, 0x04, 0x00), 0)
  mem[0xFFFC] = 0x00
  mem[0xFFFD] = 0x00
  local cpu = CPU.new(bus())
  cpu:power_on()
  for _ = 1, 10 do cpu:step() end
  ok("lda/sta", cpu.a == 0x42 and mem[0] == 0x42)

  -- ADC with carry
  clear()
  load(string.char(
    0xA9, 0xFF, -- LDA #$FF
    0x18,       -- CLC
    0x69, 0x01, -- ADC #$01
    0x4C, 0x05, 0x00 -- JMP self
  ), 0)
  mem[0xFFFC] = 0x00
  mem[0xFFFD] = 0x00
  cpu = CPU.new(bus())
  cpu:power_on()
  for _ = 1, 8 do cpu:step() end
  ok("adc wrap", cpu.a == 0 and cpu:flag(CPU.FLAG_C) and cpu:flag(CPU.FLAG_Z))

  -- JSR/RTS
  clear()
  load(string.char(
    0x20, 0x10, 0x00, -- JSR $0010
    0xA9, 0x99,
    0x4C, 0x05, 0x00
  ), 0)
  load(string.char(
    0xA9, 0x55,
    0x60
  ), 0x10)
  mem[0xFFFC] = 0x00
  mem[0xFFFD] = 0x00
  cpu = CPU.new(bus())
  cpu:power_on()
  for _ = 1, 30 do cpu:step() end
  ok("jsr/rts", cpu.a == 0x99)

  -- Indirect JMP page bug: JMP ($10FF) reads hi from $1000
  clear()
  mem[0x10FF] = 0x00
  mem[0x1000] = 0x20 -- bug target high
  mem[0x1100] = 0x30 -- correct would be this
  load(string.char(0x6C, 0xFF, 0x10), 0) -- JMP ($10FF)
  load(string.char(0xA9, 0xAA, 0x4C, 0x02, 0x20), 0x2000)
  mem[0xFFFC] = 0x00
  mem[0xFFFD] = 0x00
  cpu = CPU.new(bus())
  cpu:power_on()
  for _ = 1, 10 do cpu:step() end
  ok("jmp ind bug", cpu.a == 0xAA and cpu.pc >= 0x2000 and cpu.pc < 0x2100)

  -- PHP pushes B and U set on the stack copy
  clear()
  load(string.char(
    0x08, -- PHP
    0x68, -- PLA -> A = pushed status
    0x4C, 0x02, 0x00
  ), 0)
  mem[0xFFFC] = 0x00
  mem[0xFFFD] = 0x00
  cpu = CPU.new(bus())
  cpu:power_on()
  cpu:step() -- PHP
  cpu:step() -- PLA
  ok("php sets B+U", band(cpu.a, 0x30) == 0x30)
end
