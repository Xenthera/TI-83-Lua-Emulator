-- RV64I instruction field decode (little-endian 32-bit word already assembled).

local bit = require("framework.util.bit")
local band, bor, lshift, rshift = bit.band, bit.bor, bit.lshift, bit.rshift

local Decode = {}

local function sext(val, bits)
  local sign = lshift(1, bits - 1)
  if band(val, sign) ~= 0 then
    return val - lshift(1, bits)
  end
  return val
end

--- Decode into `dst` (reused each step) to avoid a table alloc per instruction.
function Decode.decode_into(dst, insn)
  insn = band(insn or 0, 0xFFFFFFFF)
  dst.insn = insn
  dst.opcode = band(insn, 0x7F)
  dst.rd = band(rshift(insn, 7), 0x1F)
  dst.funct3 = band(rshift(insn, 12), 0x7)
  dst.rs1 = band(rshift(insn, 15), 0x1F)
  dst.rs2 = band(rshift(insn, 20), 0x1F)
  dst.funct7 = band(rshift(insn, 25), 0x7F)

  -- I-immediate [31:20]
  dst.imm_i = sext(band(rshift(insn, 20), 0xFFF), 12)

  -- S-immediate
  dst.imm_s = sext(bor(lshift(band(rshift(insn, 25), 0x7F), 5), band(rshift(insn, 7), 0x1F)), 12)

  -- B-immediate
  dst.imm_b = sext(bor(
    bor(
      lshift(band(rshift(insn, 31), 1), 12),
      lshift(band(rshift(insn, 7), 1), 11)
    ),
    bor(
      lshift(band(rshift(insn, 25), 0x3F), 5),
      lshift(band(rshift(insn, 8), 0xF), 1)
    )
  ), 13)

  -- U-immediate (bits 31:12 set, low 12 zero)
  dst.imm_u = band(insn, 0xFFFFF000)

  -- J-immediate
  dst.imm_j = sext(bor(
    bor(
      lshift(band(rshift(insn, 31), 1), 20),
      lshift(band(rshift(insn, 12), 0xFF), 12)
    ),
    bor(
      lshift(band(rshift(insn, 20), 1), 11),
      lshift(band(rshift(insn, 21), 0x3FF), 1)
    )
  ), 21)

  dst.shamt = band(rshift(insn, 20), 0x3F) -- RV64 I-type shifts use 6 bits
  return dst
end

function Decode.decode(insn)
  return Decode.decode_into({}, insn)
end

Decode.sext = sext
return Decode
