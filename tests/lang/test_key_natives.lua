return function(ok)
  local Compiler = require("lang.compiler")
  local Assembler = require("asm.assembler")
  local Machine = require("core.machine")
  local romutil = require("core.util.rom")

  local src = [[
void main() {
  byte k;
  k = key_scan();
  k = key_down(0x09);
  k = key_wait();
  while (1) { halt(); }
}
]]
  local okc, asm = pcall(Compiler.compile_source, src, "key_natives.tc", { root = "." })
  ok("key natives compile", okc, okc and nil or tostring(asm))
  if okc then
    ok("includes key.asm", asm:find('include "asm/lib/key.asm"') ~= nil)
    ok("emits key_scan", asm:find("call key_scan") ~= nil)
    ok("emits key_down", asm:find("call key_down") ~= nil)
    ok("emits key_wait", asm:find("call key_wait") ~= nil)
  end

  local harness = [[
    org 0x0000
    di
    jp start
    org 0x0100
start:
    call key_scan
    ld (0xC000),a
    halt
    include "asm/lib/key.asm"
]]
  local path = "asm/generated/_key_scan_harness.asm"
  local f = assert(io.open(path, "w"))
  f:write(harness)
  f:close()

  local oka, r = pcall(Assembler.assemble_file, path, { root = ".", max_size = 0x2000 })
  ok("key_scan harness assembles", oka, oka and nil or tostring(r))
  if not oka then
    return
  end

  local FLASH = romutil.FLASH_SIZE
  local function flash_from_asm(result)
    local bytes = Assembler.to_string(result.bytes, result.size)
    return bytes .. string.rep("\0", FLASH - #bytes)
  end

  local m = Machine.new()
  assert(m:load_rom_bytes(flash_from_asm(r)))

  local function run_until_halt(max_steps)
    for _ = 1, max_steps do
      if m.cpu.halted then
        return true
      end
      m:step_instruction()
    end
    return m.cpu.halted
  end

  local function poke_result(v)
    m.mmu:write(0xC000, v)
  end

  local function peek_result()
    return m.mmu:read(0xC000)
  end

  local function run_scan()
    m.cpu.halted = false
    m.cpu.pc = 0x0100
    poke_result(0xFF)
    return run_until_halt(100000)
  end

  m.keypad:reset()
  ok("idle runs", run_scan())
  ok("idle scancode 0", peek_result() == 0, tostring(peek_result()))

  local cases = {
    { "enter", 0x09 },
    { "down", 0x01 },
    { "left", 0x02 },
    { "right", 0x03 },
    { "up", 0x04 },
    { "clear", 0x0F },
  }
  for _, c in ipairs(cases) do
    m.keypad:reset()
    m.keypad:set_key(c[1], true)
    ok(c[1] .. " runs", run_scan())
    ok(c[1] .. " scancode", peek_result() == c[2],
      string.format("got 0x%02X want 0x%02X", peek_result(), c[2]))
  end

  -- key_down harness
  local down_asm = [[
    org 0x0000
    di
    jp start
    org 0x0100
start:
    ld a,0x09
    call key_down
    ld (0xC000),a
    halt
    include "asm/lib/key.asm"
]]
  f = assert(io.open("asm/generated/_key_down_harness.asm", "w"))
  f:write(down_asm)
  f:close()
  local okd, rd = pcall(Assembler.assemble_file, "asm/generated/_key_down_harness.asm",
    { root = ".", max_size = 0x2000 })
  ok("key_down harness assembles", okd, okd and nil or tostring(rd))
  if not okd then
    return
  end
  assert(m:load_rom_bytes(flash_from_asm(rd)))

  m.keypad:reset()
  m.keypad:set_key("enter", true)
  m.cpu.halted = false
  m.cpu.pc = 0x0100
  poke_result(0xFF)
  ok("key_down held runs", run_until_halt(100000))
  ok("key_down enter=1", peek_result() == 1, tostring(peek_result()))

  m.keypad:set_key("enter", false)
  m.cpu.halted = false
  m.cpu.pc = 0x0100
  poke_result(0xFF)
  ok("key_down released runs", run_until_halt(100000))
  ok("key_down enter=0", peek_result() == 0, tostring(peek_result()))

  -- Demo project compiles
  local okp, asmp = pcall(Compiler.compile_file, "projects/keys/main.tc", { root = "projects/keys" })
  ok("keys project compiles", okp, okp and nil or tostring(asmp))
end
