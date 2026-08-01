#!/usr/bin/env luajit
-- Generate rom/riscv64.bin — interactive S-mode UART console (pre-Linux).
--
-- Studio: select RV64 → see banner + "# " → focus LCD → type (echo).
-- Path exercised: M-mode UART print → mret to S → SBI putchar + UART RX.

local ROOT = arg[0]:match("(.+)[/\\]tools[/\\]") or "."
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local mem = {}
local function put32(addr, word)
  word = band(word, 0xFFFFFFFF)
  mem[addr + 0] = band(word, 0xFF)
  mem[addr + 1] = band(rshift(word, 8), 0xFF)
  mem[addr + 2] = band(rshift(word, 16), 0xFF)
  mem[addr + 3] = band(rshift(word, 24), 0xFF)
end

local function bor4(a, b, c, d)
  return bor(bor(a, b), bor(c, d))
end
local function bor6(a, b, c, d, e, f)
  return bor(bor4(a, b, c, d), bor(e, f))
end

local function enc_i(imm, rs1, funct3, rd, opcode)
  return bor6(lshift(band(imm, 0xFFF), 20), lshift(rs1, 15), lshift(funct3, 12), lshift(rd, 7), opcode, 0)
end
local function enc_u(imm20, rd, opcode)
  return bor(band(lshift(imm20, 12), 0xFFFFF000), bor(lshift(rd, 7), opcode))
end
local function enc_s(imm, rs2, rs1, funct3)
  local u = band(imm, 0xFFF)
  return bor6(lshift(band(rshift(u, 5), 0x7F), 25), lshift(rs2, 20), lshift(rs1, 15),
    lshift(funct3, 12), lshift(band(u, 0x1F), 7), 0x23)
end
local function enc_b(imm, rs2, rs1, funct3)
  local u = imm
  if u < 0 then u = u + 0x2000 end
  u = band(u, 0x1FFF)
  return bor(
    bor4(lshift(band(rshift(u, 12), 1), 31), lshift(band(rshift(u, 5), 0x3F), 25),
      lshift(rs2, 20), lshift(rs1, 15)),
    bor4(lshift(funct3, 12), lshift(band(rshift(u, 1), 0xF), 8),
      lshift(band(rshift(u, 11), 1), 7), 0x63)
  )
end
local function enc_j(imm, rd)
  local u = imm
  if u < 0 then u = u + 0x200000 end
  u = band(u, 0x1FFFFF)
  return bor6(
    lshift(band(rshift(u, 20), 1), 31), lshift(band(rshift(u, 1), 0x3FF), 21),
    lshift(band(rshift(u, 11), 1), 20), lshift(band(rshift(u, 12), 0xFF), 12),
    lshift(rd, 7), 0x6F)
end
local function csrrw(rd, csr, rs1)
  return bor6(lshift(csr, 20), lshift(rs1, 15), lshift(1, 12), lshift(rd, 7), 0x73, 0)
end
local function csrrs(rd, csr, rs1)
  return bor6(lshift(csr, 20), lshift(rs1, 15), lshift(2, 12), lshift(rd, 7), 0x73, 0)
end

--[[
Layout:
  0x000  M entry
  0x008  m_puts
  0x040  main_m
  0x200  S entry + s_puts + echo
  0x400  STR_M
  0x440  STR_S
]]

-- M entry
put32(0x000, enc_u(0x10000, 6, 0x37))       -- lui x6, UART
put32(0x004, enc_j(0x040 - 0x004, 0))       -- jal main_m

-- m_puts @ 0x008  (x5=str, ra=x1, uart=x6)
put32(0x008, enc_i(0, 5, 0, 7, 0x03))       -- lb x7,0(x5)
put32(0x00C, enc_b(0x020, 0, 7, 0))         -- beqz -> 0x02C
put32(0x010, enc_i(5, 6, 0, 8, 0x03))       -- lb x8,5(x6) LSR
put32(0x014, enc_i(0x20, 8, 7, 8, 0x13))    -- andi THRE
put32(0x018, enc_b(-8, 0, 8, 0))            -- beqz spin
put32(0x01C, enc_s(0, 7, 6, 0))             -- sb THR
put32(0x020, enc_i(1, 5, 0, 5, 0x13))
put32(0x024, enc_j(0x008 - 0x024, 0))
put32(0x028, 0x00000013)                   -- nop pad (beq target adjust)
put32(0x02C, enc_i(0, 1, 0, 0, 0x67))       -- ret jalr x0,0(x1)

-- Fix beq at 0x00C: from 0x00C to 0x02C is +0x20 — ok

-- main_m @ 0x040
put32(0x040, enc_u(0, 5, 0x37))
put32(0x044, enc_i(0x400, 5, 0, 5, 0x13))   -- x5 = STR_M
put32(0x048, enc_j(0x008 - 0x048, 1))       -- jal m_puts
put32(0x04C, enc_u(0, 5, 0x37))
put32(0x050, enc_i(0x200, 5, 0, 5, 0x13))   -- mepc = S
put32(0x054, csrrw(0, 0x341, 5))
put32(0x058, enc_i(1, 0, 0, 5, 0x13))
put32(0x05C, enc_i(11, 5, 1, 5, 0x13))      -- 1<<11 = MPP.S
put32(0x060, csrrs(0, 0x300, 5))
put32(0x064, 0x30200073)                   -- mret

-- S entry @ 0x200
put32(0x200, enc_u(0x10000, 6, 0x37))
put32(0x204, enc_u(0, 5, 0x37))
put32(0x208, enc_i(0x440, 5, 0, 5, 0x13))   -- STR_S
put32(0x20C, enc_j(0x220 - 0x20C, 1))       -- jal s_puts
put32(0x210, enc_j(0x280 - 0x210, 0))       -- echo loop

-- s_puts @ 0x220 (SBI putchar)
put32(0x220, enc_i(0, 5, 0, 7, 0x03))
put32(0x224, enc_b(0x020, 0, 7, 0))         -- beqz -> 0x244
put32(0x228, enc_i(0, 7, 0, 10, 0x13))      -- a0 = ch
put32(0x22C, enc_i(1, 0, 0, 17, 0x13))      -- a7 = 1
put32(0x230, 0x00000073)                   -- ecall
put32(0x234, enc_i(1, 5, 0, 5, 0x13))
put32(0x238, enc_j(0x220 - 0x238, 0))
put32(0x23C, 0x00000013)
put32(0x240, 0x00000013)
put32(0x244, enc_i(0, 1, 0, 0, 0x67))       -- ret

-- echo @ 0x280 — idle with WFI (like 68k STOP), not a busy poll burn.
put32(0x280, enc_i(5, 6, 0, 7, 0x03))       -- LSR
put32(0x284, enc_i(1, 7, 7, 7, 0x13))       -- DR?
put32(0x288, enc_b(12, 0, 7, 1))            -- bnez -> 0x294 (have char)
put32(0x28C, 0x10500073)                   -- wfi
put32(0x290, enc_j(0x280 - 0x290, 0))       -- retry poll
put32(0x294, enc_i(0, 6, 0, 7, 0x03))       -- RBR
put32(0x298, enc_i(13, 0, 0, 8, 0x13))      -- \r
put32(0x29C, enc_b(0x01C, 8, 7, 0))         -- -> 0x2B8
put32(0x2A0, enc_i(10, 0, 0, 8, 0x13))      -- \n
put32(0x2A4, enc_b(0x014, 8, 7, 0))         -- -> 0x2B8
put32(0x2A8, enc_i(0, 7, 0, 10, 0x13))
put32(0x2AC, enc_i(1, 0, 0, 17, 0x13))
put32(0x2B0, 0x00000073)
put32(0x2B4, enc_j(0x280 - 0x2B4, 0))
-- newline prompt
put32(0x2B8, enc_i(10, 0, 0, 10, 0x13))
put32(0x2BC, enc_i(1, 0, 0, 17, 0x13))
put32(0x2C0, 0x00000073)
put32(0x2C4, enc_i(35, 0, 0, 10, 0x13))     -- #
put32(0x2C8, enc_i(1, 0, 0, 17, 0x13))
put32(0x2CC, 0x00000073)
put32(0x2D0, enc_i(32, 0, 0, 10, 0x13))     -- space
put32(0x2D4, enc_i(1, 0, 0, 17, 0x13))
put32(0x2D8, 0x00000073)
put32(0x2DC, enc_j(0x280 - 0x2DC, 0))

local function putstr(addr, s)
  for i = 1, #s do
    mem[addr + i - 1] = s:byte(i)
  end
  mem[addr + #s] = 0
end
putstr(0x400, "[M] RV64 custom bring-up\n")
putstr(0x440, "[S] console - focus LCD & type\n# ")

local max = 0x480
local bytes = {}
for i = 0, max do
  bytes[i + 1] = string.char(mem[i] or 0)
end
local out = table.concat(bytes)

local function ensure_dir(path)
  local sep = package.config:sub(1, 1)
  if sep == "\\" then
    os.execute('mkdir "' .. path:gsub("/", "\\") .. '" 2>nul')
  else
    os.execute("mkdir -p '" .. path .. "'")
  end
end

local function write_path(path)
  local f = assert(io.open(path, "wb"))
  f:write(out)
  f:close()
  print("wrote " .. path .. " (" .. #out .. " bytes)")
end

ensure_dir(ROOT .. "/rom")
ensure_dir(ROOT .. "/rom/riscv64")
write_path(ROOT .. "/rom/riscv64.bin")
write_path(ROOT .. "/rom/riscv64/console.bin")
print("Studio: RV64 → focus LCD → type")
