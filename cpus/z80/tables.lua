-- Opcode metadata placeholders (lengths / nominal cycles for tooling).
-- The live interpreter uses values returned by opcodes.exec.

local M = {
  -- Common reference cycle counts for unprefixed ops (approx; conditional varies).
  NOP = 4,
  HALT = 4,
  DI = 4,
  EI = 4,
}

return M
