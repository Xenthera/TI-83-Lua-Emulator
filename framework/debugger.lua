-- Cross-machine debugger helpers: registers, memory peek, disassembly backends.

local bit = require("framework.util.bit")
local band, bor, rshift, lshift = bit.band, bit.bor, bit.rshift, bit.lshift

local Debugger = {}
Debugger.__index = Debugger

function Debugger.new(machine)
  return setmetatable({
    machine = machine,
    breakpoints = {},
    tracing = false,
    trace_log = {},
    max_trace = 256,
  }, Debugger)
end

function Debugger:cpu()
  return self.machine and self.machine:getCPU()
end

function Debugger:memory()
  return self.machine and self.machine:getMemory()
end

function Debugger:add_breakpoint(addr)
  self.breakpoints[band(addr, 0xFFFFFFFF)] = true
end

function Debugger:remove_breakpoint(addr)
  self.breakpoints[band(addr, 0xFFFFFFFF)] = nil
end

function Debugger:clear_breakpoints()
  self.breakpoints = {}
end

function Debugger:should_break()
  local m = self.machine
  if not m then return false end
  local pc = m.pc and m:pc()
  if not pc then
    local cpu = self:cpu()
    pc = cpu and (cpu.pc_u32 and cpu:pc_u32() or cpu.pc)
  end
  if type(pc) == "table" then
    pc = pc.lo or 0
  end
  return pc and self.breakpoints[band(pc, 0xFFFFFFFF)] or false
end

function Debugger:step()
  local m = self.machine
  if not m then return 0 end
  local cyc = m:step()
  if self.tracing then
    local line = self:disassemble_at(m:pc())
    self.trace_log[#self.trace_log + 1] = line
    if #self.trace_log > self.max_trace then
      table.remove(self.trace_log, 1)
    end
  end
  return cyc
end

function Debugger:registers()
  local cpu = self:cpu()
  if not cpu then return {} end
  if cpu.getRegisters then return cpu:getRegisters() end
  return {
    pc = cpu.pc, sp = cpu.sp, af = cpu.af, bc = cpu.bc,
    de = cpu.de, hl = cpu.hl, ix = cpu.ix, iy = cpu.iy,
  }
end

function Debugger:read_mem(addr, len)
  len = len or 16
  local mem = self:memory()
  local cpu = self:cpu()
  local out = {}
  for i = 0, len - 1 do
    local a = addr + i
    if mem and mem.read then
      out[i] = mem:read(a)
    elseif mem and mem.read8 then
      out[i] = mem:read8(a)
    elseif cpu and cpu.read8 then
      out[i] = cpu:read8(a)
    else
      out[i] = 0
    end
  end
  return out
end

--- Very small disassemblers for UI; not full ISA coverage.
function Debugger:disassemble_at(addr)
  local cpu = self:cpu()
  if not cpu then return string.format("%08X  ???", addr or 0) end
  if cpu.im ~= nil then
    return Debugger.disasm_z80(self, addr or cpu.pc)
  end
  return Debugger.disasm_m68k(self, addr or cpu.pc)
end

function Debugger.disasm_z80(self, addr)
  local b0 = self:read_mem(addr, 1)[0] or 0
  return string.format("%04X  %02X", band(addr, 0xFFFF), b0)
end

function Debugger.disasm_m68k(self, addr)
  local bytes = self:read_mem(addr, 2)
  local op = bor(lshift(bytes[0] or 0, 8), bytes[1] or 0)
  local mnemonic = "dc.w"
  if op == 0x4E71 then mnemonic = "nop"
  elseif op == 0x4E75 then mnemonic = "rts"
  elseif op == 0x4AFC then mnemonic = "illegal"
  elseif band(rshift(op, 12), 15) == 7 then mnemonic = "moveq"
  elseif band(rshift(op, 12), 15) == 6 then mnemonic = "bcc"
  elseif band(rshift(op, 14), 3) == 0 then mnemonic = "move"
  end
  return string.format("%08X  %04X  %s", addr, op, mnemonic)
end

function Debugger:perf(dt, cycles)
  return {
    cps = (dt and dt > 0) and (cycles / dt) or 0,
    cycles = cycles,
  }
end

return Debugger
