-- RV64I + u64 unit tests.

return function(ok)
  local U64 = require("cpus.riscv.u64")
  local Decode = require("cpus.riscv.decode")
  local RV64I = require("cpus.riscv.rv64i")
  local Machine = require("machines.riscv64.machine")
  local bit = require("framework.util.bit")
  local band, bor, lshift = bit.band, bit.bor, bit.lshift

  -- framework bit.bor only reliably takes 5 args — nest ORs.
  local function bor2(a, b) return bor(a, b) end
  local function bor3(a, b, c) return bor(bor(a, b), c) end
  local function bor4(a, b, c, d) return bor(bor(a, b), bor(c, d)) end
  local function bor6(a, b, c, d, e, f)
    return bor(bor3(a, b, c), bor3(d, e, f))
  end

  local function enc_i(imm, rs1, funct3, rd, opcode)
    imm = band(imm, 0xFFF)
    return bor6(lshift(imm, 20), lshift(rs1, 15), lshift(funct3, 12), lshift(rd, 7), opcode, 0)
  end

  local function enc_u(imm20, rd, opcode)
    return bor3(band(lshift(imm20, 12), 0xFFFFF000), lshift(rd, 7), opcode)
  end

  local function enc_r(funct7, rs2, rs1, funct3, rd, opcode)
    return bor6(
      lshift(funct7, 25), lshift(rs2, 20), lshift(rs1, 15),
      lshift(funct3, 12), lshift(rd, 7), opcode
    )
  end

  local function enc_b(imm, rs2, rs1, funct3)
    local u = imm
    if u < 0 then u = u + 0x2000 end
    u = band(u, 0x1FFF)
    local b12 = band(math.floor(u / 4096), 1)
    local b11 = band(math.floor(u / 2048), 1)
    local b10_5 = band(math.floor(u / 32), 0x3F)
    local b4_1 = band(math.floor(u / 2), 0xF)
    return bor(
      bor4(lshift(b12, 31), lshift(b10_5, 25), lshift(rs2, 20), lshift(rs1, 15)),
      bor4(lshift(funct3, 12), lshift(b4_1, 8), lshift(b11, 7), 0x63)
    )
  end

  local function enc_j(imm, rd)
    local u = imm
    if u < 0 then u = u + 0x200000 end
    u = band(u, 0x1FFFFF)
    local b20 = band(math.floor(u / 0x100000), 1)
    local b10_1 = band(math.floor(u / 2), 0x3FF)
    local b11 = band(math.floor(u / 0x800), 1)
    local b19_12 = band(math.floor(u / 0x1000), 0xFF)
    return bor6(
      lshift(b20, 31), lshift(b10_1, 21), lshift(b11, 20),
      lshift(b19_12, 12), lshift(rd, 7), 0x6F
    )
  end

  local function enc_s(imm, rs2, rs1, funct3)
    local u = imm
    if u < 0 then u = u + 0x1000 end
    u = band(u, 0xFFF)
    local hi = band(math.floor(u / 32), 0x7F)
    local lo = band(u, 0x1F)
    return bor6(
      lshift(hi, 25), lshift(rs2, 20), lshift(rs1, 15),
      lshift(funct3, 12), lshift(lo, 7), 0x23
    )
  end

  -- u64 basics
  do
    local a = U64.from_u32(0xFFFFFFFF)
    local b = U64.from_u32(1)
    local s = U64.add(a, b)
    ok("u64 add carry", s.hi == 1 and s.lo == 0)
    local d = U64.sub(s, b)
    ok("u64 sub", d.hi == 0 and d.lo == 0xFFFFFFFF)
    local sh = U64.sll(U64.from_u32(1), 32)
    ok("u64 sll 32", sh.hi == 1 and sh.lo == 0)
    ok("u64 ult", U64.ult(U64.from_u32(1), U64.from_u32(2)))
    ok("u64 slt neg", U64.slt(U64.from_i32(-1), U64.from_u32(1)))
  end

  -- decode ADDI
  do
    local insn = enc_i(5, 0, 0, 1, 0x13)
    local d = Decode.decode(insn)
    ok("decode addi opcode", d.opcode == 0x13)
    ok("decode addi rd", d.rd == 1)
    ok("decode addi imm", d.imm_i == 5)
  end

  local function mock_bus(mem)
    mem = mem or {}
    return {
      read8 = function(a)
        return mem[band(a, 0xFFFFFFFF)] or 0
      end,
      write8 = function(a, v)
        mem[band(a, 0xFFFFFFFF)] = band(v, 0xFF)
      end,
    }
  end

  local function put32(mem, addr, word)
    word = band(word, 0xFFFFFFFF)
    mem[addr] = band(word, 0xFF)
    mem[addr + 1] = band(rshift8(word, 8), 0xFF)
    mem[addr + 2] = band(rshift8(word, 16), 0xFF)
    mem[addr + 3] = band(rshift8(word, 24), 0xFF)
  end
  function rshift8(w, n)
    return math.floor(band(w, 0xFFFFFFFF) / (2 ^ n))
  end

  -- x0 hardwired; ADDI
  do
    local mem = {}
    put32(mem, 0, enc_i(42, 0, 0, 1, 0x13)) -- addi x1,x0,42
    put32(mem, 4, enc_i(1, 0, 0, 0, 0x13)) -- addi x0,x0,1 (ignored)
    local cpu = RV64I.new(mock_bus(mem))
    cpu:step()
    ok("addi x1", cpu:get_x(1).lo == 42 and cpu:get_x(1).hi == 0)
    cpu:step()
    ok("x0 stays 0", U64.is_zero(cpu:get_x(0)))
  end

  -- ADD / SUB
  do
    local mem = {}
    put32(mem, 0, enc_i(10, 0, 0, 1, 0x13))
    put32(mem, 4, enc_i(3, 0, 0, 2, 0x13))
    put32(mem, 8, enc_r(0, 2, 1, 0, 3, 0x33)) -- add x3,x1,x2
    put32(mem, 12, enc_r(0x20, 2, 1, 0, 4, 0x33)) -- sub x4,x1,x2
    local cpu = RV64I.new(mock_bus(mem))
    cpu:run_cycles(4)
    ok("add", cpu:get_x(3).lo == 13)
    ok("sub", cpu:get_x(4).lo == 7)
  end

  -- LUI / AUIPC
  do
    local mem = {}
    put32(mem, 0, enc_u(0x12345, 1, 0x37)) -- lui x1,0x12345
    put32(mem, 4, enc_u(1, 2, 0x17)) -- auipc x2,1 -> pc(4)+0x1000
    local cpu = RV64I.new(mock_bus(mem))
    cpu:step()
    ok("lui", cpu:get_x(1).lo == 0x12345000)
    cpu:step()
    ok("auipc", cpu:get_x(2).lo == 0x1004)
  end

  -- JAL
  do
    local mem = {}
    put32(mem, 0, enc_j(8, 1)) -- jal x1, +8
    put32(mem, 8, enc_i(1, 0, 0, 2, 0x13)) -- addi x2,x0,1
    local cpu = RV64I.new(mock_bus(mem))
    cpu:step()
    ok("jal link", cpu:get_x(1).lo == 4)
    ok("jal target", cpu.pc.lo == 8)
    cpu:step()
    ok("jal landed", cpu:get_x(2).lo == 1)
  end

  -- BEQ taken / not
  do
    local mem = {}
    put32(mem, 0, enc_i(5, 0, 0, 1, 0x13))
    put32(mem, 4, enc_i(5, 0, 0, 2, 0x13))
    put32(mem, 8, enc_b(8, 2, 1, 0)) -- beq x1,x2,+8 -> pc 16
    put32(mem, 12, enc_i(99, 0, 0, 3, 0x13)) -- should skip
    put32(mem, 16, enc_i(1, 0, 0, 4, 0x13))
    local cpu = RV64I.new(mock_bus(mem))
    cpu:run_cycles(4)
    ok("beq taken skip", cpu:get_x(3).lo == 0)
    ok("beq taken land", cpu:get_x(4).lo == 1)
  end

  -- LW / SW via RAM region on full machine
  do
    local m = Machine.new()
    -- Program at ROM 0:
    --   lui x1, 0x80000        ; x1 = 0x80000000
    --   addi x2, x0, 0x7B      ; 123
    --   sw x2, 0(x1)
    --   lw x3, 0(x1)
    --   addi x4, x0, 1
    --   sb x4, 0(x0) wait - halt via store to halt mmio
    local prog = {}
    local function emit(addr, word)
      put32(prog, addr, word)
    end
    emit(0, enc_u(0x80000, 1, 0x37))
    emit(4, enc_i(123, 0, 0, 2, 0x13))
    emit(8, enc_s(0, 2, 1, 2)) -- sw
    emit(12, enc_i(0, 1, 2, 3, 0x03)) -- lw x3,0(x1)
    emit(16, enc_i(1, 0, 0, 5, 0x13))
    -- store 1 to halt: lui x6,0x10000; addi x7,x0,1; sb x7,0x10(x6)
    emit(20, enc_u(0x10000, 6, 0x37))
    emit(24, enc_i(1, 0, 0, 7, 0x13))
    emit(28, enc_s(0x10, 7, 6, 0)) -- sb
    local bytes = {}
    for i = 0, 31 do bytes[i + 1] = string.char(prog[i] or 0) end
    m:load_rom_bytes(table.concat(bytes))
    m:run_cycles(20)
    ok("lw/sw ram", m.cpu:get_x(3).lo == 123)
    ok("halt mmio", m.cpu.halted == true or m.bus_dev.halted == true)
  end

  -- UART TX
  do
    local m = Machine.new()
    -- lui x1, 0x10000; addi x2,x0,'H'; sb x2,0(x1); addi x2,x0,'i'; sb x2,0(x1); halt
    local prog = {}
    put32(prog, 0, enc_u(0x10000, 1, 0x37))
    put32(prog, 4, enc_i(72, 0, 0, 2, 0x13)) -- 'H'
    put32(prog, 8, enc_s(0, 2, 1, 0))
    put32(prog, 12, enc_i(105, 0, 0, 2, 0x13)) -- 'i'
    put32(prog, 16, enc_s(0, 2, 1, 0))
    put32(prog, 20, enc_u(0x10000, 6, 0x37))
    put32(prog, 24, enc_i(1, 0, 0, 7, 0x13))
    put32(prog, 28, enc_s(0x10, 7, 6, 0))
    local bytes = {}
    for i = 0, 31 do bytes[i + 1] = string.char(prog[i] or 0) end
    m:load_rom_bytes(table.concat(bytes))
    m:run_cycles(20)
    ok("uart hi", m.uart:text() == "Hi")
  end

  ok("manager create", (function()
    local Manager = require("framework.manager")
    local m = Manager.create("riscv64")
    return m ~= nil and m.MACHINE_ID == "riscv64"
  end)())

  -- M extension: MUL
  do
    local mem = {}
    put32(mem, 0, enc_i(6, 0, 0, 1, 0x13)) -- addi x1,x0,6
    put32(mem, 4, enc_i(7, 0, 0, 2, 0x13)) -- addi x2,x0,7
    put32(mem, 8, enc_r(1, 2, 1, 0, 3, 0x33)) -- mul x3,x1,x2
    local cpu = RV64I.new(mock_bus(mem))
    cpu:run_cycles(3)
    ok("mul 6*7", cpu:get_x(3).lo == 42)
  end

  -- Zicsr + trap: csrw mtvec; ecall → handler; mret back
  -- Why: this is the heartbeat of SBI/Linux — ecall leaves U/S/M for firmware.
  do
    local mem = {}
    local Csr = require("cpus.riscv.csr")
    -- 0: lui x1,0; addi x1,x1,0x100 → x1=0x100 (handler)
    put32(mem, 0, enc_u(0, 1, 0x37))
    put32(mem, 4, enc_i(0x100, 1, 0, 1, 0x13))
    -- 8: csrrw x0, mtvec(0x305), x1
    put32(mem, 8, bor(
      bor(lshift(0x305, 20), lshift(1, 15)),
      bor(lshift(1, 12), bor(lshift(0, 7), 0x73))
    ))
    -- 12: ecall
    put32(mem, 12, 0x00000073)
    -- 16: addi x5,x0,1  (after mret)
    put32(mem, 16, enc_i(1, 0, 0, 5, 0x13))
    -- handler @ 0x100: mark x6=7; save mcause→x8; mepc+=4; mret
    -- (mepc points at ecall — firmware must skip it or you loop forever)
    put32(mem, 0x100, enc_i(7, 0, 0, 6, 0x13))
    put32(mem, 0x104, bor( -- csrrs x8, mcause, x0
      bor(lshift(0x342, 20), lshift(0, 15)),
      bor(lshift(2, 12), bor(lshift(8, 7), 0x73))
    ))
    put32(mem, 0x108, bor( -- csrrs x7, mepc, x0
      bor(lshift(0x341, 20), lshift(0, 15)),
      bor(lshift(2, 12), bor(lshift(7, 7), 0x73))
    ))
    put32(mem, 0x10C, enc_i(4, 7, 0, 7, 0x13)) -- addi x7,x7,4
    put32(mem, 0x110, bor( -- csrrw x0, mepc, x7
      bor(lshift(0x341, 20), lshift(7, 15)),
      bor(lshift(1, 12), 0x73)
    ))
    put32(mem, 0x114, 0x30200073) -- mret
    local cpu = RV64I.new(mock_bus(mem))
    -- Stop once mret has run the fall-through addi (before padding zeros trap).
    cpu:run_cycles(11)
    ok("ecall reached handler", cpu:get_x(6).lo == 7)
    ok("mret resumed", cpu:get_x(5).lo == 1)
    ok("mcause ecall M", cpu:get_x(8).lo == Csr.CAUSE_ECALL_M)
  end

  -- CSR readback mtvec
  do
    local mem = {}
    put32(mem, 0, enc_u(0, 1, 0x37))
    put32(mem, 4, enc_i(0x200, 1, 0, 1, 0x13))
    put32(mem, 8, bor(
      bor(lshift(0x305, 20), lshift(1, 15)),
      bor(lshift(1, 12), 0x73)
    ))
    -- csrrs x2, mtvec, x0  (read)
    put32(mem, 12, bor(
      bor(lshift(0x305, 20), lshift(0, 15)),
      bor(lshift(2, 12), bor(lshift(2, 7), 0x73))
    ))
    local cpu = RV64I.new(mock_bus(mem))
    cpu:run_cycles(4)
    ok("csrr mtvec", cpu:get_x(2).lo == 0x200)
  end

  -- S-mode: mret with MPP=S drops privilege; ecall from S → M (SBI path)
  do
    local Csr = require("cpus.riscv.csr")
    local mem = {}
    local function csrrw(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(1, 12), bor(lshift(rd, 7), 0x73)))
    end
    local function csrrs(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(2, 12), bor(lshift(rd, 7), 0x73)))
    end
    -- M setup @0:
    -- mtvec = 0x200 (M handler)
    put32(mem, 0, enc_i(0x200, 0, 0, 1, 0x13))
    put32(mem, 4, csrrw(0, 0x305, 1))
    -- mepc = 0x80 (S entry)
    put32(mem, 8, enc_i(0x80, 0, 0, 1, 0x13))
    put32(mem, 12, csrrw(0, 0x341, 1))
    -- mstatus.MPP = S (0x800). Cannot addi 0x800 — 12-bit imm sign-extends!
    put32(mem, 16, enc_i(1, 0, 0, 1, 0x13))       -- addi x1,x0,1
    put32(mem, 20, enc_i(11, 1, 1, 1, 0x13))      -- slli x1,x1,11 → 0x800
    put32(mem, 24, csrrs(0, 0x300, 1))
    put32(mem, 28, 0x30200073) -- mret → S @ 0x80
    -- S code @0x80: ecall (should trap to M, cause 9)
    put32(mem, 0x80, 0x00000073)
    -- M handler @0x200: addi x10,x0,99; csrrs x11,mcause,x0
    put32(mem, 0x200, enc_i(99, 0, 0, 10, 0x13))
    put32(mem, 0x204, csrrs(11, 0x342, 0))
    local cpu = RV64I.new(mock_bus(mem))
    cpu:run_cycles(11) -- stop after handler saves mcause (before padding zeros trap)
    ok("mret entered S then ecall to M", cpu:get_x(10).lo == 99)
    ok("ecall from S cause", cpu:get_x(11).lo == Csr.CAUSE_ECALL_S)
    ok("back in M after S ecall", cpu.csr.priv == Csr.PRIV_M)
  end

  -- Sv39: gigapage identity map, load through translation in S-mode
  do
    local Sv39 = require("cpus.riscv.sv39")
    local Csr = require("cpus.riscv.csr")
    local mem = {}
    local function csrrw(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(1, 12), bor(lshift(rd, 7), 0x73)))
    end
    local function csrrs(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(2, 12), bor(lshift(rd, 7), 0x73)))
    end
    -- Root page table @ PA 0x1000: level-2 leaf gigapage PPN=0 (VA==PA for low 1GiB)
    local pte = Sv39.make_pte(0, bor(bor(Sv39.PTE_R, Sv39.PTE_W), bor(Sv39.PTE_X, bor(Sv39.PTE_A, Sv39.PTE_D))))
    local pte_addr = 0x1000
    put32(mem, pte_addr, pte.lo)
    put32(mem, pte_addr + 4, pte.hi)
    -- Magic word at PA 0x6000
    put32(mem, 0x6000, 0xA1B2C3D4)
    -- M program: set satp, mtvec, mepc=0x80, MPP=S, mret
    -- satp value: MODE=8, PPN=1 (page 0x1000)
    local satp = Sv39.make_satp(1)
    -- load satp into x1 via two halves: lui/addi for lo, then csrw
    -- csrw satp uses x1 = satp.lo with hi in... need full 64. Use:
    --   lui x1, satp.lo>>12; addi ... messy. Set via Lua after building cpu for satp hi,
    --   or write with csrrw after building x1=lo and using a second CSR trick.
    -- Simplest for test: poke csr.satp from Lua after creating cpu, then run mret path only.
    put32(mem, 0, enc_i(0x200, 0, 0, 1, 0x13))
    put32(mem, 4, csrrw(0, 0x305, 1))
    put32(mem, 8, enc_i(0x80, 0, 0, 1, 0x13))
    put32(mem, 12, csrrw(0, 0x341, 1))
    put32(mem, 16, enc_i(1, 0, 0, 1, 0x13))
    put32(mem, 20, enc_i(11, 1, 1, 1, 0x13))
    put32(mem, 24, csrrs(0, 0x300, 1))
    put32(mem, 28, 0x30200073)
    -- S @0x80: lui x1, 6; lw x2, 0(x1)  → load VA 0x6000
    put32(mem, 0x80, enc_u(6, 1, 0x37))
    put32(mem, 0x84, enc_i(0, 1, 2, 2, 0x03)) -- lw x2,0(x1)
    put32(mem, 0x88, 0x00000073) -- ecall to stop in M
    put32(mem, 0x200, enc_i(1, 0, 0, 10, 0x13)) -- M handler marker
    local cpu = RV64I.new(mock_bus(mem))
    cpu.csr.satp = satp
    cpu:run_cycles(14)
    ok("sv39 load via gigapage", cpu:get_x(2).lo == 0xA1B2C3D4)
    ok("sv39 still trapped to M on ecall", cpu.csr.priv == Csr.PRIV_M)
  end

  -- CLINT timer: mtime advances; when >= mtimecmp and MIE/MTIE, trap
  do
    local Csr = require("cpus.riscv.csr")
    local m = Machine.new()
    m.cpu.csr.mtvec = U64.from_u32(0x100)
    -- Enable MIE + MTIE
    m.cpu.csr.mstatus = U64.from_u32(Csr.MSTATUS_MIE)
    m.cpu.csr.mie = U64.from_u32(lshift(1, Csr.INT_M_TIMER))
    m.clint.mtime = U64.from_u32(10)
    m.clint.mtimecmp = U64.from_u32(20)
    -- ROM: infinite nop loop via jal 0 (self) at 0 — actually jal to self
    local prog = {}
    put32(prog, 0, enc_j(0, 0)) -- jal x0, 0 tight loop
    put32(prog, 0x100, enc_i(55, 0, 0, 9, 0x13)) -- handler: addi x9,x0,55
    local bytes = {}
    for i = 0, 0x103 do bytes[i + 1] = string.char(prog[i] or 0) end
    m:load_rom_bytes(table.concat(bytes))
    -- restore interrupt enables after reset()
    m.cpu.csr.mtvec = U64.from_u32(0x100)
    m.cpu.csr.mstatus = U64.from_u32(Csr.MSTATUS_MIE)
    m.cpu.csr.mie = U64.from_u32(lshift(1, Csr.INT_M_TIMER))
    m.clint.mtime = U64.from_u32(10)
    m.clint.mtimecmp = U64.from_u32(20)
    -- Need a second 256-cycle slice after mtime crosses mtimecmp.
    m:run_cycles(300)
    ok("timer interrupt fired", m.cpu:get_x(9).lo == 55)
  end

  -- SBI legacy putchar from S-mode ecall
  do
    local m = Machine.new()
    -- Minimal: drop to S and ecall putchar('Z')
    -- a7=1 (legacy putchar), a0='Z'
    local mem = {}
    local function csrrw(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(1, 12), bor(lshift(rd, 7), 0x73)))
    end
    local function csrrs(rd, csr, rs1)
      return bor(bor(lshift(csr, 20), lshift(rs1, 15)), bor(lshift(2, 12), bor(lshift(rd, 7), 0x73)))
    end
    put32(mem, 0, enc_i(0x80, 0, 0, 1, 0x13))
    put32(mem, 4, csrrw(0, 0x341, 1)) -- mepc
    put32(mem, 8, enc_i(1, 0, 0, 1, 0x13))
    put32(mem, 12, enc_i(11, 1, 1, 1, 0x13))
    put32(mem, 16, csrrs(0, 0x300, 1)) -- MPP=S
    put32(mem, 20, 0x30200073) -- mret
    -- S: addi a0,x0,'Z'; addi a7,x0,1; ecall; ecall shutdown-ish via halt store
    put32(mem, 0x80, enc_i(90, 0, 0, 10, 0x13))
    put32(mem, 0x84, enc_i(1, 0, 0, 17, 0x13))
    put32(mem, 0x88, 0x00000073)
    put32(mem, 0x8C, enc_u(0x10000, 6, 0x37))
    put32(mem, 0x90, enc_i(1, 0, 0, 7, 0x13))
    put32(mem, 0x94, enc_s(0x10, 7, 6, 0))
    local bytes = {}
    for i = 0, 0x97 do bytes[i + 1] = string.char(mem[i] or 0) end
    m:load_rom_bytes(table.concat(bytes))
    m:run_cycles(40)
    ok("sbi putchar Z", m.uart:text():find("Z", 1, true) ~= nil)
  end
end
