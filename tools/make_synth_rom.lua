#!/usr/bin/env lua
-- Build a synthetic 512KB firmware that exercises LCD + keypad + interrupts.
-- Not a TI OS - used for bring-up without proprietary ROMs.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]make_synth_rom%.lua$") or "."
local FLASH = 512 * 1024
local rom = {}
for i = 0, FLASH - 1 do
  rom[i] = 0
end

local pc = 0
local function here()
  return pc
end
local function emit(...)
  for i = 1, select("#", ...) do
    local b = select(i, ...)
    rom[pc] = b % 256
    pc = pc + 1
  end
end
local function emit16(w)
  emit(w % 256, math.floor(w / 256) % 256)
end
local function jr_to(target)
  local at = pc
  emit(0x18, 0x00)
  local after = pc
  local dist = target - after
  if dist < -128 or dist > 127 then
    error(string.format("JR out of range (%d)", dist))
  end
  rom[at + 1] = dist % 256
end

-- Reset: JP $0100
pc = 0x0000
emit(0xC3)
emit16(0x0100)

-- IRQ $0038: INC ($C000); EI; RETI
pc = 0x0038
emit(0x3A, 0x00, 0xC0) -- LD A,($C000)
emit(0x3C)             -- INC A
emit(0x32, 0x00, 0xC0) -- LD ($C000),A
emit(0xFB)             -- EI
emit(0xED, 0x4D)       -- RETI

-- Main
pc = 0x0100
emit(0xED, 0x56)       -- IM 1
emit(0xFB)             -- EI
emit(0x3E, 0x0B)       -- LD A,$0B
emit(0xD3, 0x03)       -- OUT (3),A  interrupt mask
emit(0x3E, 0x10)       -- LD A,$10
emit(0xD3, 0x04)       -- OUT (4),A  timer bits

-- LCD on, auto X, Y=0, X=0
emit(0x3E, 0x0C) emit(0xD3, 0x10)
emit(0x3E, 0x02) emit(0xD3, 0x10)
emit(0x3E, 0x40) emit(0xD3, 0x10)
emit(0x3E, 0x20) emit(0xD3, 0x10)

-- Top bar: 12 x 0xFF
emit(0x06, 12)
local bar = here()
emit(0x3E, 0xFF)
emit(0xD3, 0x11)
emit(0x10, 0xFA) -- DJNZ bar

-- Checker at Y=2
emit(0x3E, 0x42) emit(0xD3, 0x10)
emit(0x3E, 0x20) emit(0xD3, 0x10)
emit(0x06, 12)
emit(0x3E, 0xAA)
emit(0xD3, 0x11)
emit(0x10, 0xFA)

-- Ready magic $C001 = $42
emit(0x3E, 0x42)
emit(0x32, 0x01, 0xC0)

-- Poll keypad group 1 for Enter (active-low bit0)
local poll = here()
emit(0x3E, 0xFD) emit(0xD3, 0x01) -- select group 1
emit(0xDB, 0x01)                   -- IN A,(1)
emit(0xE6, 0x01)                   -- AND 1
emit(0x20, 0x11)                   -- JR NZ, idle (bit set = not pressed)
emit(0x3E, 0x99)                   -- pressed path
emit(0x32, 0x02, 0xC0)             -- LD ($C002),A
emit(0x3E, 0x44) emit(0xD3, 0x10) -- Y=4
emit(0x3E, 0x20) emit(0xD3, 0x10) -- X=0
emit(0x3E, 0xFF) emit(0xD3, 0x11) -- data
local idle = here()
emit(0x00) -- NOP (IRQ window)
jr_to(poll)

local chunks = {}
for i = 0, FLASH - 1 do
  chunks[#chunks + 1] = string.char(rom[i])
end
local path = ROOT .. "/rom/synth.rom"
local f = assert(io.open(path, "wb"))
f:write(table.concat(chunks))
f:close()
print("Wrote " .. path)
