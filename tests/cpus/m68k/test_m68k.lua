return function(ok)
  local M68K = require("cpus.m68k.m68k")
  local bit = require("framework.util.bit")
  local band, bor, rshift, lshift = bit.band, bit.bor, bit.rshift, bit.lshift

  ok("bit bor varargs", bor(1, 2, 4, 8, 16) == 31)
  ok("bit flag clear", band(0x2004, bit.bnot(bor(1, 2, 4, 8, 16))) == 0x2000)

  local mem = {}
  for i = 0, 0xFFFF do mem[i] = 0 end

  local function bus()
    return {
      read8 = function(addr) return mem[band(addr, 0xFFFF)] or 0 end,
      write8 = function(addr, v) mem[band(addr, 0xFFFF)] = band(v, 0xFF) end,
    }
  end

  local function poke16(addr, v)
    mem[addr] = band(rshift(v, 8), 0xFF)
    mem[addr + 1] = band(v, 0xFF)
  end

  local function poke32(addr, v)
    poke16(addr, rshift(v, 16))
    poke16(addr + 2, band(v, 0xFFFF))
  end

  local function peek32(addr)
    return bor(lshift(mem[addr] or 0, 24), lshift(mem[addr + 1] or 0, 16),
      lshift(mem[addr + 2] or 0, 8), mem[addr + 3] or 0)
  end

  -- Reset vectors
  poke32(0, 0x1000) -- SSP
  poke32(4, 0x0400) -- PC

  local cpu = M68K.new(bus())
  ok("reset ssp", cpu.ssp == 0x1000, string.format("%08X", cpu.ssp))
  ok("reset pc", cpu.pc == 0x0400, string.format("%08X", cpu.pc))
  ok("reset supervisor", band(cpu.sr, 0x2000) ~= 0)

  -- MOVEQ #5,D0  (0x7005) then NOP
  poke16(0x0400, 0x7005)
  poke16(0x0402, 0x4E71)
  cpu.pc = 0x0400
  cpu:step()
  ok("moveq d0", cpu.d[0] == 5, tostring(cpu.d[0]))
  cpu:step()
  ok("nop advances", cpu.pc == 0x0404)

  -- ADD.L D0,D1 : D1=3, after moveq D0=5 -> D1=8
  cpu.d[1] = 3
  poke16(0x0404, 0xD280) -- ADD.L D0,D1
  cpu.pc = 0x0404
  cpu:step()
  ok("add.l d0,d1", cpu.d[1] == 8, tostring(cpu.d[1]))

  -- BRA.S +2 over a NOP to next
  poke16(0x0500, 0x6002) -- BRA.S *+4 (disp 2 from next word? disp relative to pc after op)
  -- After fetching 6002, pc=502; disp=2 -> pc=504
  poke16(0x0502, 0x4E71)
  poke16(0x0504, 0x7001)
  cpu.pc = 0x0500
  cpu:step()
  ok("bra taken", cpu.pc == 0x0504, string.format("%08X", cpu.pc))

  -- Illegal -> exception vector 4
  poke32(4 * 4, 0x0800) -- illegal handler
  poke16(0x0600, 0x4AFC)
  cpu.pc = 0x0600
  cpu.ssp = 0x1000
  cpu.sr = 0x2000
  cpu:step()
  ok("illegal vectors", cpu.pc == 0x0800, string.format("%08X", cpu.pc))

  -- TRAP #0
  poke32(32 * 4, 0x0900)
  poke16(0x0700, 0x4E40)
  cpu.pc = 0x0700
  cpu.ssp = 0x0F00
  cpu:step()
  ok("trap0 vectors", cpu.pc == 0x0900, string.format("%08X", cpu.pc))

  -- Privilege: MOVE to SR in user mode -> privilege violation (vector 8)
  poke32(8 * 4, 0x0A00)
  cpu.sr = 0x0000 -- user
  cpu.usp = 0x0E00
  poke16(0x0B00, 0x46FC) -- MOVE #imm,SR
  poke16(0x0B02, 0x2000)
  cpu.pc = 0x0B00
  cpu:step()
  ok("privilege violation", cpu.pc == 0x0A00, string.format("%08X", cpu.pc))

  -- IRQ level 5
  poke32((24 + 5) * 4, 0x0C00)
  cpu.sr = 0x2000 -- supervisor, interrupt mask 0
  cpu.ssp = 0x0D00
  cpu.pc = 0x0B10
  poke16(0x0B10, 0x4E71)
  cpu:interrupt(5)
  ok("irq5 vectors", cpu.pc == 0x0C00, string.format("%08X", cpu.pc))
  ok("irq5 mask", band(cpu.sr, 0x0700) == 0x0500, string.format("%04X", cpu.sr))

  -- get/set registers
  local regs = cpu:getRegisters()
  ok("getRegisters pc", regs.pc == cpu.pc)
  cpu:setRegisters({ d = { [0] = 0x12345678 }, pc = 0x1234 })
  ok("setRegisters d0", cpu.d[0] == 0x12345678)
  ok("setRegisters pc", cpu.pc == 0x1234)

  -- BTST #imm must not steal the following Bcc.W displacement (AMS boot desync)
  -- 0800 0000 = BTST #0,D0; 6600 0006 = BNE.W *+8; 7001 = MOVEQ #1,D0; 7002 = MOVEQ #2,D0
  cpu.sr = 0x2700
  cpu.d[0] = 0 -- bit0 clear -> Z set after BTST -> BNE not taken
  poke16(0x0D00, 0x0800)
  poke16(0x0D02, 0x0000)
  poke16(0x0D04, 0x6600)
  poke16(0x0D06, 0x0006)
  poke16(0x0D08, 0x7001)
  poke16(0x0D0A, 0x7002)
  cpu.pc = 0x0D00
  cpu:step() -- BTST
  ok("btst leaves bcc.w intact", cpu.pc == 0x0D04, string.format("%08X", cpu.pc))
  cpu:step() -- BNE.W not taken -> skip disp, land on MOVEQ #1
  ok("bne.w not taken pc", cpu.pc == 0x0D08, string.format("%08X", cpu.pc))
  cpu:step()
  ok("after bne executes moveq1", cpu.d[0] == 1, tostring(cpu.d[0]))

  -- CMPM.B (A1)+,(A0)+ must compare and post-inc both; not EOR into An.
  mem[0x2000] = 0x09
  mem[0x3000] = 0x09
  cpu:set_a(0, 0x2000)
  cpu:set_a(1, 0x3000)
  poke16(0x0E00, 0xB109) -- CMPM.B (A1)+,(A0)+
  cpu.pc = 0x0E00
  cpu.sr = 0x2000
  cpu:step()
  ok("cmpm equal sets Z", band(cpu.sr, 0x04) ~= 0, string.format("%04X", cpu.sr))
  ok("cmpm inc A0", cpu:get_a(0) == 0x2001, string.format("%08X", cpu:get_a(0)))
  ok("cmpm inc A1", cpu:get_a(1) == 0x3001, string.format("%08X", cpu:get_a(1)))
  mem[0x2001] = 0x01
  mem[0x3001] = 0x02
  poke16(0x0E02, 0xB109)
  cpu.pc = 0x0E02
  cpu:step()
  ok("cmpm unequal clears Z", band(cpu.sr, 0x04) == 0, string.format("%04X", cpu.sr))

  -- User-mode IRQ must preserve USP (Lua 0 is truthy; a[7] must not overwrite usp).
  poke32((24 + 5) * 4, 0x0C00)
  cpu.sr = 0x0000 -- user, IPL 0
  cpu.usp = 0x0E00
  cpu.ssp = 0x0D00
  cpu.pc = 0x0B20
  poke16(0x0B20, 0x4E71)
  cpu.a[7] = 0 -- poison unused slot
  cpu:interrupt(5)
  ok("user irq keeps usp", cpu.usp == 0x0E00, string.format("%08X", cpu.usp))
  ok("user irq uses ssp", cpu.ssp == 0x0D00 - 6, string.format("%08X", cpu.ssp))
  ok("user irq enters supervisor", band(cpu.sr, 0x2000) ~= 0)

  ------------------------------------------------------------------
  -- Foundational ISA coverage (privilege / frames / EA / flags)
  ------------------------------------------------------------------

  -- Line-A -> vector 10; stacked PC points at the faulting op.
  poke32(10 * 4, 0x0C80)
  cpu.sr = 0x2000
  cpu.ssp = 0x1000
  poke16(0x0F00, 0xA000)
  cpu.pc = 0x0F00
  cpu:step()
  ok("line_a vectors", cpu.pc == 0x0C80, string.format("%08X", cpu.pc))
  ok("line_a stacked pc", peek32(cpu.ssp + 2) == 0x0F00, string.format("%08X", peek32(cpu.ssp + 2)))

  -- JSR abs.L / RTS
  poke16(0x1000, 0x4EB9) -- JSR $00001200
  poke32(0x1002, 0x00001200)
  poke16(0x1200, 0x4E75) -- RTS
  cpu.sr = 0x2000
  cpu.ssp = 0x0F80
  cpu.pc = 0x1000
  cpu:step()
  ok("jsr lands", cpu.pc == 0x1200, string.format("%08X", cpu.pc))
  ok("jsr pushed ret", peek32(cpu.ssp) == 0x1006, string.format("%08X", peek32(cpu.ssp)))
  cpu:step()
  ok("rts returns", cpu.pc == 0x1006, string.format("%08X", cpu.pc))

  -- LINK A6,#-4 / UNLK A6
  cpu.ssp = 0x0F80
  cpu:set_a(6, 0xDEADBEEF)
  poke16(0x1300, 0x4E56) -- LINK A6,#-4
  poke16(0x1302, 0xFFFC)
  poke16(0x1304, 0x4E5E) -- UNLK A6
  cpu.pc = 0x1300
  cpu:step()
  ok("link a6=frame", cpu:get_a(6) == 0x0F7C, string.format("%08X", cpu:get_a(6)))
  ok("link sp locals", cpu.ssp == 0x0F78, string.format("%08X", cpu.ssp))
  ok("link saved a6", peek32(0x0F7C) == 0xDEADBEEF, string.format("%08X", peek32(0x0F7C)))
  cpu:step()
  ok("unlk restores a6", cpu:get_a(6) == 0xDEADBEEF, string.format("%08X", cpu:get_a(6)))
  ok("unlk restores sp", cpu.ssp == 0x0F80, string.format("%08X", cpu.ssp))

  -- ANDI #imm,SR drops supervisor -> A7 becomes USP
  cpu.sr = 0x2000
  cpu.ssp = 0x0F00
  cpu.usp = 0x0E00
  poke16(0x1400, 0x027C) -- ANDI #0x0000,SR (clear S)
  poke16(0x1402, 0x0000)
  cpu.pc = 0x1400
  cpu:step()
  ok("andi sr clears S", band(cpu.sr, 0x2000) == 0, string.format("%04X", cpu.sr))
  ok("andi sr a7 is usp", cpu:get_a(7) == 0x0E00, string.format("%08X", cpu:get_a(7)))
  ok("andi sr ssp preserved", cpu.ssp == 0x0F00, string.format("%08X", cpu.ssp))

  -- MOVE USP round-trip (supervisor)
  cpu.sr = 0x2700
  cpu.usp = 0
  cpu:set_a(0, 0x12345678)
  poke16(0x1410, 0x4E60) -- MOVE A0,USP
  poke16(0x1412, 0x4E68) -- MOVE USP,A0  (4E68 = MOVE USP,A0)
  cpu.pc = 0x1410
  cpu.d[0] = 0
  cpu:set_a(0, 0x12345678)
  cpu:step()
  ok("move an,usp", cpu.usp == 0x12345678, string.format("%08X", cpu.usp))
  cpu:set_a(0, 0)
  cpu:step()
  ok("move usp,an", cpu:get_a(0) == 0x12345678, string.format("%08X", cpu:get_a(0)))

  -- RTE restores SR/PC and returns to user
  poke32(32 * 4, 0x1500)
  cpu.sr = 0x0000
  cpu.usp = 0x0E40
  cpu.ssp = 0x0F40
  poke16(0x14A0, 0x4E40) -- TRAP #0
  poke16(0x1500, 0x4E73) -- RTE
  cpu.pc = 0x14A0
  cpu:step() -- trap
  ok("trap from user in S", band(cpu.sr, 0x2000) ~= 0)
  cpu:step() -- RTE
  ok("rte back to user", band(cpu.sr, 0x2000) == 0, string.format("%04X", cpu.sr))
  ok("rte pc", cpu.pc == 0x14A2, string.format("%08X", cpu.pc))
  ok("rte a7 usp", cpu:get_a(7) == 0x0E40, string.format("%08X", cpu:get_a(7)))

  -- STOP then IRQ resumes
  poke32((24 + 3) * 4, 0x1600)
  cpu.sr = 0x2000
  cpu.ssp = 0x0F20
  poke16(0x1550, 0x4E72) -- STOP
  poke16(0x1552, 0x2000) -- SR: supervisor, IPL 0
  poke16(0x1600, 0x4E71)
  cpu.pc = 0x1550
  cpu:step()
  ok("stop halts", cpu.stopped == true)
  local accepted = cpu:interrupt(3)
  ok("stop irq accepted", accepted == true)
  ok("stop cleared", cpu.stopped == false)
  ok("stop irq pc", cpu.pc == 0x1600, string.format("%08X", cpu.pc))

  -- IRQ masked when level <= IPL (unless level 7)
  cpu.sr = 0x2500 -- IPL 5
  cpu.pc = 0x1700
  poke16(0x1700, 0x4E71)
  ok("irq masked", cpu:interrupt(5) == false)
  ok("irq7 nmi-like", cpu:interrupt(7) == true)

  -- sleep_unmask bypasses IPL
  cpu.sr = 0x2700
  cpu.pc = 0x1710
  poke16(0x1710, 0x4E71)
  poke32((24 + 3) * 4, 0x1720)
  cpu.sleep_unmask = true
  ok("sleep unmask irq3", cpu:interrupt(3) == true)
  ok("sleep unmask cleared", cpu.sleep_unmask == false)

  -- MOVEM.L D0/D1,-(A7) predec bit order (mask bit15=D0, bit14=D1)
  cpu.sr = 0x2000
  cpu.ssp = 0x3000
  cpu.d[0] = 0x11111111
  cpu.d[1] = 0x22222222
  poke16(0x1800, 0x48E7) -- MOVEM.L <list>,-(A7)
  poke16(0x1802, 0xC000) -- bits 15,14 = D0,D1 in predec encoding
  cpu.pc = 0x1800
  cpu:step()
  ok("movem predec sp", cpu.ssp == 0x2FF8, string.format("%08X", cpu.ssp))
  ok("movem predec d0 lo", peek32(0x2FF8) == 0x11111111, string.format("%08X", peek32(0x2FF8)))
  ok("movem predec d1 hi", peek32(0x2FFC) == 0x22222222, string.format("%08X", peek32(0x2FFC)))

  -- MOVEM.L (A7)+,D0/D1
  poke16(0x1810, 0x4CDF) -- MOVEM.L (A7)+,<list>
  poke16(0x1812, 0x0003) -- D0,D1
  cpu.d[0], cpu.d[1] = 0, 0
  cpu.pc = 0x1810
  cpu:step()
  ok("movem postinc d0", cpu.d[0] == 0x11111111, string.format("%08X", cpu.d[0]))
  ok("movem postinc d1", cpu.d[1] == 0x22222222, string.format("%08X", cpu.d[1]))
  ok("movem postinc sp", cpu.ssp == 0x3000, string.format("%08X", cpu.ssp))

  -- EA: LEA d16(An), MOVE.W d16(An),d16(An)
  cpu:set_a(0, 0x2000)
  mem[0x2010] = 0x12
  mem[0x2011] = 0x34
  poke16(0x1900, 0x41E8) -- LEA $10(A0),A0
  poke16(0x1902, 0x0010)
  cpu.pc = 0x1900
  cpu:step()
  ok("lea d16(an)", cpu:get_a(0) == 0x2010, string.format("%08X", cpu:get_a(0)))

  cpu:set_a(1, 0x2100)
  -- MOVE.W (d16,A0),(d16,A1): 00 sz=11 dstReg=1 dstMode=5 srcMode=5 srcReg=0 -> 0x3368
  poke16(0x1910, 0x3368)
  poke16(0x1912, 0x0010)
  poke16(0x1914, 0x0020)
  cpu:set_a(0, 0x2000)
  cpu:set_a(1, 0x2100)
  mem[0x2010] = 0xAB
  mem[0x2011] = 0xCD
  cpu.pc = 0x1910
  cpu:step()
  ok("move d16(an) dest", mem[0x2120] == 0xAB and mem[0x2121] == 0xCD,
    string.format("%02X%02X", mem[0x2120] or 0, mem[0x2121] or 0))

  -- EA: abs.L
  poke16(0x1920, 0x2039) -- MOVE.L $00002200,D0
  poke32(0x1922, 0x00002200)
  poke32(0x2200, 0xCAFEBABE)
  cpu.pc = 0x1920
  cpu:step()
  ok("move abs.l", cpu.d[0] == 0xCAFEBABE, string.format("%08X", cpu.d[0]))

  -- EA: PC-relative LEA
  -- LEA $6(PC),A0 at 0x1930: after fetch op pc=1932, +ext -> after ext pc=1934, disp from 1932
  poke16(0x1930, 0x41FA) -- LEA d16(PC),A0
  poke16(0x1932, 0x0006) -- -> 0x1932+6 = 0x1938
  cpu.pc = 0x1930
  cpu:step()
  ok("lea pc-relative", cpu:get_a(0) == 0x1938, string.format("%08X", cpu:get_a(0)))

  -- ADD.B flags: 0x7F+1 -> V and N
  cpu.d[0] = 0x7F
  cpu.d[1] = 0x01
  poke16(0x1A00, 0xD001) -- ADD.B D1,D0
  cpu.pc = 0x1A00
  cpu.sr = 0x2000
  cpu:step()
  ok("add.b overflow V", band(cpu.sr, 0x02) ~= 0, string.format("%04X", cpu.sr))
  ok("add.b result", band(cpu.d[0], 0xFF) == 0x80, string.format("%02X", band(cpu.d[0], 0xFF)))

  -- SUB.B sets C when borrow
  cpu.d[0] = 0x00
  cpu.d[1] = 0x01
  poke16(0x1A10, 0x9001) -- SUB.B D1,D0
  cpu.pc = 0x1A10
  cpu.sr = 0x2000
  cpu:step()
  ok("sub.b carry", band(cpu.sr, 0x01) ~= 0, string.format("%04X", cpu.sr))
  ok("sub.b x", band(cpu.sr, 0x10) ~= 0, string.format("%04X", cpu.sr))

  -- LSL.W #1,D0 sets C/X from shifted-out bit; ROL must not touch X
  cpu.d[0] = 0x8000
  cpu.sr = 0x2000
  poke16(0x1B00, 0xE348) -- LSL.W #1,D0
  cpu.pc = 0x1B00
  cpu:step()
  ok("lsl result", band(cpu.d[0], 0xFFFF) == 0x0000, string.format("%04X", band(cpu.d[0], 0xFFFF)))
  ok("lsl sets C", band(cpu.sr, 0x01) ~= 0, string.format("%04X", cpu.sr))
  ok("lsl sets X", band(cpu.sr, 0x10) ~= 0, string.format("%04X", cpu.sr))

  cpu.d[0] = 0x8000
  cpu.sr = 0x2000 -- X clear
  poke16(0x1B10, 0xE358) -- ROL.W #1,D0
  cpu.pc = 0x1B10
  cpu:step()
  ok("rol result", band(cpu.d[0], 0xFFFF) == 0x0001, string.format("%04X", band(cpu.d[0], 0xFFFF)))
  ok("rol sets C", band(cpu.sr, 0x01) ~= 0, string.format("%04X", cpu.sr))
  ok("rol leaves X", band(cpu.sr, 0x10) == 0, string.format("%04X", cpu.sr))

  -- EXT.W: byte 0x80 -> word 0xFF80; N from word, not long (Dn high may be 0)
  cpu.d[0] = 0x00000080
  poke16(0x1C00, 0x4880) -- EXT.W D0
  cpu.pc = 0x1C00
  cpu.sr = 0x2000
  cpu:step()
  ok("ext.w value", band(cpu.d[0], 0xFFFF) == 0xFF80, string.format("%08X", cpu.d[0]))
  ok("ext.w sets N", band(cpu.sr, 0x08) ~= 0, string.format("%04X", cpu.sr))

  -- EORI to CCR
  cpu.sr = 0x2005 -- C+Z
  poke16(0x1C10, 0x0A3C)
  poke16(0x1C12, 0x0001) -- toggle C
  cpu.pc = 0x1C10
  cpu:step()
  ok("eori ccr", band(cpu.sr, 0x1F) == 0x04, string.format("%04X", cpu.sr))

  -- DBcc: DBF D0 always decrements and branches while D0 != -1
  cpu.d[0] = 1
  poke16(0x1D00, 0x51C8) -- DBF D0
  poke16(0x1D02, 0xFFFE) -- branch to self-ish: after fetch disp at 1D02, target=1D02+(-2)=1D00
  cpu.pc = 0x1D00
  cpu:step()
  ok("dbf decremented", band(cpu.d[0], 0xFFFF) == 0, string.format("%04X", band(cpu.d[0], 0xFFFF)))
  ok("dbf branched", cpu.pc == 0x1D00, string.format("%08X", cpu.pc))
  cpu:step()
  ok("dbf exhaust pc", cpu.pc == 0x1D04, string.format("%08X", cpu.pc))
  ok("dbf exhaust d0", band(cpu.d[0], 0xFFFF) == 0xFFFF, string.format("%04X", band(cpu.d[0], 0xFFFF)))

  -- MULU / DIVU / div0
  cpu.d[0] = 0x00000010
  cpu.d[1] = 0x00000003
  poke16(0x1E00, 0xC2C0) -- MULU D0,D1 -> 0x30
  cpu.pc = 0x1E00
  cpu:step()
  ok("mulu", cpu.d[1] == 0x30, string.format("%08X", cpu.d[1]))

  cpu.d[0] = 0x0000000A
  cpu.d[1] = 0x00000002
  poke16(0x1E10, 0x82C0) -- DIVU D0,D1 -> q=0 remainder wrong; DIVU Dn,Dm is DIVU ea,Dn
  -- DIVU D0,D1 encoding: 1000 001 011 000 000 = 82C0 -> Dn=1, ea=D0. Yes D1/D0.
  cpu.pc = 0x1E10
  cpu:step()
  ok("divu quot", band(cpu.d[1], 0xFFFF) == 0, string.format("%08X", cpu.d[1])) -- 2/10 = 0
  -- Better: 100/5
  cpu.d[0] = 5
  cpu.d[1] = 100
  poke16(0x1E20, 0x82C0)
  cpu.pc = 0x1E20
  cpu:step()
  ok("divu 100/5", band(cpu.d[1], 0xFFFF) == 20 and rshift(cpu.d[1], 16) == 0,
    string.format("%08X", cpu.d[1]))

  poke32(5 * 4, 0x1F00) -- div0 vector
  cpu.d[0] = 0
  cpu.d[1] = 1
  cpu.sr = 0x2000
  cpu.ssp = 0x0F60
  poke16(0x1E30, 0x82C0)
  cpu.pc = 0x1E30
  cpu:step()
  ok("div0 vectors", cpu.pc == 0x1F00, string.format("%08X", cpu.pc))

  -- Memory ASL.W (A0): one-bit shift in memory, must not clobber Dn
  cpu.d[0] = 0x55
  cpu:set_a(0, 0x2400)
  mem[0x2400] = 0x40
  mem[0x2401] = 0x00
  cpu.sr = 0x2000
  poke16(0x1E40, 0xE1D0) -- ASL.W (A0)
  cpu.pc = 0x1E40
  cpu:step()
  ok("mem asl value", mem[0x2400] == 0x80 and mem[0x2401] == 0x00,
    string.format("%02X%02X", mem[0x2400] or 0, mem[0x2401] or 0))
  ok("mem asl leaves d0", cpu.d[0] == 0x55, string.format("%08X", cpu.d[0]))
  ok("mem asl N", band(cpu.sr, 0x08) ~= 0, string.format("%04X", cpu.sr))

  -- ADDX.L D1,D0 with X set
  cpu.d[0] = 0x00000001
  cpu.d[1] = 0x00000001
  cpu.sr = 0x2010 -- X set
  poke16(0x1E50, 0xD181) -- ADDX.L D1,D0
  cpu.pc = 0x1E50
  cpu:step()
  ok("addx with x", cpu.d[0] == 0x00000003, string.format("%08X", cpu.d[0]))

  -- ADDX sticky Z: zero result does not set Z if Z was clear
  cpu.d[0] = 0
  cpu.d[1] = 0
  cpu.sr = 0x2000 -- Z clear, X clear
  poke16(0x1E60, 0xD181)
  cpu.pc = 0x1E60
  cpu:step()
  ok("addx sticky z clear", band(cpu.sr, 0x04) == 0, string.format("%04X", cpu.sr))
  ok("addx zero result", cpu.d[0] == 0)

  -- EXG D0,D1 / EXG D0,A0
  cpu.d[0], cpu.d[1] = 0xAAAA, 0xBBBB
  poke16(0x1E70, 0xC141) -- EXG D0,D1
  cpu.pc = 0x1E70
  cpu:step()
  ok("exg d0 d1", cpu.d[0] == 0xBBBB and cpu.d[1] == 0xAAAA,
    string.format("%08X %08X", cpu.d[0], cpu.d[1]))
  cpu:set_a(0, 0x1000)
  cpu.d[0] = 0x2222
  poke16(0x1E80, 0xC188) -- EXG D0,A0
  cpu.pc = 0x1E80
  cpu:step()
  ok("exg d0 a0", cpu.d[0] == 0x1000 and cpu:get_a(0) == 0x2222,
    string.format("%08X %08X", cpu.d[0], cpu:get_a(0)))

  -- ROXL.W #1,D0: shifts X into bit0
  cpu.d[0] = 0x0000
  cpu.sr = 0x2010 -- X set
  poke16(0x1E90, 0xE350) -- ROXL.W #1,D0
  cpu.pc = 0x1E90
  cpu:step()
  ok("roxl imports x", band(cpu.d[0], 0xFFFF) == 0x0001, string.format("%04X", band(cpu.d[0], 0xFFFF)))
  ok("roxl clears x from 0 msb", band(cpu.sr, 0x10) == 0, string.format("%04X", cpu.sr))

  -- ABCD D1,D0: 0x19+0x28 = 0x47 (BCD)
  cpu.d[0] = 0x19
  cpu.d[1] = 0x28
  cpu.sr = 0x2000
  poke16(0x1EA0, 0xC101) -- ABCD D1,D0
  cpu.pc = 0x1EA0
  cpu:step()
  ok("abcd reg", band(cpu.d[0], 0xFF) == 0x47, string.format("%02X", band(cpu.d[0], 0xFF)))
  ok("abcd no carry", band(cpu.sr, 0x11) == 0, string.format("%04X", cpu.sr))

  -- ABCD with decimal carry: 0x19+0x01+X -> 0x20 when X set from 9+1
  cpu.d[0] = 0x19
  cpu.d[1] = 0x01
  cpu.sr = 0x2000
  poke16(0x1EB0, 0xC101)
  cpu.pc = 0x1EB0
  cpu:step()
  ok("abcd adjust", band(cpu.d[0], 0xFF) == 0x20, string.format("%02X", band(cpu.d[0], 0xFF)))

  -- SBCD D1,D0: 0x40-0x13 = 0x27
  cpu.d[0] = 0x40
  cpu.d[1] = 0x13
  cpu.sr = 0x2000
  poke16(0x1EC0, 0x8101) -- SBCD D1,D0
  cpu.pc = 0x1EC0
  cpu:step()
  ok("sbcd reg", band(cpu.d[0], 0xFF) == 0x27, string.format("%02X", band(cpu.d[0], 0xFF)))

  -- SBCD must not smash An (was misdecoded as OR.B Dn,An)
  cpu:set_a(0, 0x2001)
  cpu:set_a(1, 0x2002)
  mem[0x2000] = 0x40
  mem[0x2001] = 0x13
  cpu.sr = 0x2000
  poke16(0x1ED0, 0x8109) -- SBCD -(A1),-(A0)
  cpu.pc = 0x1ED0
  cpu:step()
  ok("sbcd mem result", mem[0x2000] == 0x27, string.format("%02X", mem[0x2000] or 0))
  ok("sbcd preserves a high", cpu:get_a(0) == 0x2000 and cpu:get_a(1) == 0x2001,
    string.format("%08X %08X", cpu:get_a(0), cpu:get_a(1)))

  -- NBCD D0
  cpu.d[0] = 0x40
  cpu.sr = 0x2000
  poke16(0x1EE0, 0x4800) -- NBCD D0
  cpu.pc = 0x1EE0
  cpu:step()
  ok("nbcd", band(cpu.d[0], 0xFF) == 0x60, string.format("%02X", band(cpu.d[0], 0xFF)))

  -- CHK.W D1,D0 in range does not trap
  poke32(6 * 4, 0x1F00)
  poke16(0x1F00, 0x4E71)
  cpu.d[0] = 5
  cpu.d[1] = 10
  cpu.sr = 0x2000
  poke16(0x1EF0, 0x4181) -- CHK D1,D0
  cpu.pc = 0x1EF0
  cpu:step()
  ok("chk in range", cpu.pc == 0x1EF2, string.format("%08X", cpu.pc))

  -- CHK.W out of range -> vector 6
  cpu.d[0] = 15
  cpu.d[1] = 10
  cpu.sr = 0x2000
  cpu.ssp = 0x1000
  poke16(0x1EF0, 0x4181)
  cpu.pc = 0x1EF0
  cpu:step()
  ok("chk out of range", cpu.pc == 0x1F00, string.format("%08X", cpu.pc))

  -- MOVEP.L D0,(0,A0): write Dn bytes at even offsets
  cpu:set_a(0, 0x2200)
  cpu.d[0] = 0x11223344
  mem[0x2200], mem[0x2202], mem[0x2204], mem[0x2206] = 0, 0, 0, 0
  poke16(0x1F10, 0x01C8) -- MOVEP.L D0,(d16,A0)
  poke16(0x1F12, 0x0000)
  cpu.pc = 0x1F10
  cpu:step()
  ok("movep.l store", mem[0x2200] == 0x11 and mem[0x2202] == 0x22
    and mem[0x2204] == 0x33 and mem[0x2206] == 0x44,
    string.format("%02X %02X %02X %02X", mem[0x2200] or 0, mem[0x2202] or 0,
      mem[0x2204] or 0, mem[0x2206] or 0))

  -- MOVEP.W (0,A0),D1 loads odd-spaced bytes into low word
  mem[0x2200], mem[0x2202] = 0xAB, 0xCD
  cpu.d[1] = 0xFFFF0000
  poke16(0x1F20, 0x0308) -- MOVEP.W (d16,A0),D1
  poke16(0x1F22, 0x0000)
  cpu.pc = 0x1F20
  cpu:step()
  ok("movep.w load", band(cpu.d[1], 0xFFFFFFFF) == 0xFFFFABCD,
    string.format("%08X", cpu.d[1]))

  -- NEGX.B D0: 0 - 1 - X -> with X clear, result 0xFF and C/X set
  cpu.d[0] = 0x01
  cpu.sr = 0x2000
  poke16(0x1F30, 0x4000) -- NEGX.B D0
  cpu.pc = 0x1F30
  cpu:step()
  ok("negx.b", band(cpu.d[0], 0xFF) == 0xFF, string.format("%02X", band(cpu.d[0], 0xFF)))
  ok("negx.b carry", band(cpu.sr, 0x11) == 0x11, string.format("%04X", cpu.sr))

  -- NEGX.L sticky Z: zero result leaves Z clear if it was clear
  cpu.d[0] = 0
  cpu.sr = 0x2000 -- Z clear, X clear
  poke16(0x1F40, 0x4080) -- NEGX.L D0
  cpu.pc = 0x1F40
  cpu:step()
  ok("negx sticky z", band(cpu.sr, 0x04) == 0, string.format("%04X", cpu.sr))
  ok("negx zero", cpu.d[0] == 0)

  -- MOVE from CCR must not be misdecoded as CLR.L
  cpu.d[0] = 0x12345678
  cpu.sr = 0x2715
  poke16(0x1F50, 0x42C0) -- MOVE CCR,D0
  cpu.pc = 0x1F50
  cpu:step()
  ok("move from ccr", band(cpu.d[0], 0xFFFFFFFF) == 0x12340015,
    string.format("%08X", cpu.d[0]))
  ok("move from ccr flags", cpu.sr == 0x2715, string.format("%04X", cpu.sr))

  -- MULS with two negatives (u32 sign_extend must not be multiplied as unsigned)
  cpu.d[0] = 0xFFFF
  cpu.d[1] = 0xFFFF
  poke16(0x1F60, 0xC1C1) -- MULS D1,D0
  cpu.pc = 0x1F60
  cpu:step()
  ok("muls -1*-1", band(cpu.d[0], 0xFFFFFFFF) == 1, string.format("%08X", cpu.d[0]))

  cpu.d[0] = 0xFFFE
  cpu.d[1] = 3
  poke16(0x1F70, 0xC1C1)
  cpu.pc = 0x1F70
  cpu:step()
  ok("muls -2*3", band(cpu.d[0], 0xFFFFFFFF) == 0xFFFFFFFA,
    string.format("%08X", cpu.d[0]))

  -- DIVS overflow: -32768 / -1 does not fit in signed word
  cpu.d[0] = 0xFFFF8000
  cpu.d[1] = 0xFFFF
  cpu.sr = 0x2000
  poke16(0x1F80, 0x81C1) -- DIVS D1,D0
  cpu.pc = 0x1F80
  cpu:step()
  ok("divs overflow dn", band(cpu.d[0], 0xFFFFFFFF) == 0xFFFF8000,
    string.format("%08X", cpu.d[0]))
  ok("divs overflow V", band(cpu.sr, 0x02) ~= 0, string.format("%04X", cpu.sr))

  -- DIVS remainder takes sign of dividend
  cpu.d[0] = 0xFFFFFFFB -- -5
  cpu.d[1] = 2
  poke16(0x1F90, 0x81C1)
  cpu.pc = 0x1F90
  cpu:step()
  ok("divs -5/2", band(cpu.d[0], 0xFFFFFFFF) == 0xFFFFFFFE,
    string.format("%08X", cpu.d[0]))

  -- ASL.L #2: V set if MSB changes on any intermediate shift
  cpu.d[0] = 0x40000000
  cpu.sr = 0x2000
  poke16(0x1FA0, 0xE580) -- ASL.L #2,D0
  cpu.pc = 0x1FA0
  cpu:step()
  ok("asl #2 value", cpu.d[0] == 0)
  ok("asl #2 V", band(cpu.sr, 0x02) ~= 0, string.format("%04X", cpu.sr))
end
