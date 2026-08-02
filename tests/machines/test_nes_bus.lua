-- Minimal NES smoke: iNES parse, reset vector, NMI/vblank, BG render.

return function(ok)
  local Machine = require("machines.nes.machine")
  local bit = require("framework.util.bit")
  local band = bit.band

  -- Build a tiny NROM-128 (16KB PRG + 8KB CHR) iNES image.
  local function make_nrom(prg_code)
    local hdr = string.char(
      0x4E, 0x45, 0x53, 0x1A, -- NES\x1a
      1, -- 1 x 16KB PRG
      1, -- 1 x 8KB CHR
      0x00, -- mapper 0, horizontal
      0x00, 0, 0, 0, 0, 0, 0, 0, 0
    )
    local prg = {}
    for i = 1, 0x4000 do prg[i] = string.char(0x00) end
    -- Place code at $8000 (offset 0 in PRG)
    for i = 1, #prg_code do
      prg[i] = string.char(prg_code:byte(i))
    end
    -- Reset vector $FFFC -> $8000
    prg[0x3FFC + 1] = string.char(0x00)
    prg[0x3FFD + 1] = string.char(0x80)
    -- NMI vector $FFFA -> $8100
    prg[0x3FFA + 1] = string.char(0x00)
    prg[0x3FFB + 1] = string.char(0x81)
    -- IRQ
    prg[0x3FFE + 1] = string.char(0x00)
    prg[0x3FFF + 1] = string.char(0x80)

    -- NMI handler at $8100: just RTI
    prg[0x0100 + 1] = string.char(0x40)

    local chr = string.rep(string.char(0xFF), 0x2000) -- solid bitplanes
    return hdr .. table.concat(prg) .. chr
  end

  -- Write VRAM with rendering OFF (loopy must not mutate v mid-transfer).
  local parts = {
    string.char(0x78, 0xD8),                                   -- SEI CLD
    string.char(0xA9, 0x00, 0x8D, 0x00, 0x20),                 -- PPUCTRL=0
    string.char(0xA9, 0x00, 0x8D, 0x01, 0x20),                 -- PPUMASK=0
    string.char(0xA9, 0x3F, 0x8D, 0x06, 0x20),                 -- palette @$3F00
    string.char(0xA9, 0x00, 0x8D, 0x06, 0x20),
    string.char(0xA9, 0x21, 0x8D, 0x07, 0x20),
    string.char(0xA9, 0x20, 0x8D, 0x06, 0x20),                 -- tile @$2000
    string.char(0xA9, 0x00, 0x8D, 0x06, 0x20),
    string.char(0xA9, 0x01, 0x8D, 0x07, 0x20),
    string.char(0xA9, 0x1E, 0x8D, 0x01, 0x20),                 -- show BG+SP
    string.char(0xA9, 0x80, 0x8D, 0x00, 0x20),                 -- NMI on
  }
  local off = 0
  for _, p in ipairs(parts) do off = off + #p end
  -- JMP abs at `off`
  local lo = band(off, 0xFF)
  local hi = 0x80
  code = table.concat(parts) .. string.char(0x4C, lo, hi)

  local rom = make_nrom(code)
  ok("ines size", #rom == 16 + 0x4000 + 0x2000)

  local m = Machine.new()
  local lok, err = m:load_rom_bytes(rom, { path = "test.nes", skip_save = true })
  ok("load nrom", lok, err)
  ok("mapper 0", m.cart.mapper == 0)
  m:reset()
  ok("reset pc $8000", m:pc() == 0x8000)

  -- Run a few frames
  for _ = 1, 5 do
    m:run_cycles(m:cycles_per_frame())
  end
  ok("ran frames", m.total_cycles > 10000)
  ok("display dirty sometime", m.ppu.frame > 0)

  -- Palette / nametable writes should have stuck
  ok("palette written", (m.ppu.palette[0] or 0) == 0x21)
  ok("nametable tile", (m.ppu.vram[0] or 0) == 0x01)

  -- Controller
  m:set_key("a", true)
  m.joypad:write(1)
  m.joypad:write(0)
  local b = m.joypad:read(1)
  ok("joypad a bit", band(b, 1) == 1)

  -- Protocol wiring
  local Protocol = require("bridge.protocol")
  local info = Protocol.machine_info("nes")
  ok("protocol nes", info and info.w == 256 and info.h == 240 and info.fmt == "nes")
  ok("canonical famicom", Protocol.canonical_id("famicom") == "nes")

  -- AxROM (mapper 7): 32KB PRG banks + single-screen mirroring bit.
  -- After STA $8000, PC continues in the *new* bank - mirror code in both.
  do
    local hdr = string.char(
      0x4E, 0x45, 0x53, 0x1A,
      4, -- 64KB PRG (two 32KB AxROM banks)
      0, -- CHR RAM
      0x70, -- mapper 7
      0x00, 0, 0, 0, 0, 0, 0, 0, 0
    )
    local prg = {}
    for i = 1, 0x10000 do prg[i] = string.char(0x00) end
    -- Shared code at $8000 in both banks:
    --   LDA #$11 / STA $8000 / LDA $9000 / STA $00 / JMP $800A
    local code = {
      0xA9, 0x11,       -- LDA #$11 (bank 1 + single-screen page 1)
      0x8D, 0x00, 0x80, -- STA $8000
      0xAD, 0x00, 0x90, -- LDA $9000
      0x85, 0x00,       -- STA $00
      0x4C, 0x0A, 0x80, -- JMP $800A
    }
    for _, base in ipairs({ 0, 0x8000 }) do
      for i, b in ipairs(code) do
        prg[base + i] = string.char(b)
      end
      prg[base + 0x7FFC + 1] = string.char(0x00)
      prg[base + 0x7FFD + 1] = string.char(0x80)
      prg[base + 0x7FFA + 1] = string.char(0x00)
      prg[base + 0x7FFB + 1] = string.char(0x80)
      prg[base + 0x7FFE + 1] = string.char(0x00)
      prg[base + 0x7FFF + 1] = string.char(0x80)
    end
    -- Distinct markers at $9000 (offset $1000 in each 32KB bank)
    prg[0x1000 + 1] = string.char(0xB0) -- bank 0
    prg[0x8000 + 0x1000 + 1] = string.char(0x5A) -- bank 1

    local ax = hdr .. table.concat(prg)
    local m7 = Machine.new()
    local ok7, err7 = m7:load_rom_bytes(ax, { path = "axrom.nes", skip_save = true })
    ok("load axrom", ok7, err7)
    ok("mapper 7", m7.cart.mapper == 7)
    ok("axrom chr ram", m7.cart.chr_ram == true)
    m7:reset()
    ok("axrom mirror single0", m7.cart.mirror == 2)
    for _ = 1, 20 do m7:step_instruction() end
    ok("axrom banked to 1", m7.cart.prg_bank0 == 1)
    ok("axrom mirror single1", m7.cart.mirror == 3)
    ok("axrom read bank1 marker", m7.ram[0] == 0x5A)
  end

  -- NINA-03/06 (mapper 79): $4100 ....PCCC selects 8KB CHR / 32KB PRG.
  do
    local hdr = string.char(
      0x4E, 0x45, 0x53, 0x1A,
      2, -- 32KB PRG
      2, -- 16KB CHR (two 8KB banks)
      0x50, -- mapper low nibble 5 -> with flags7 becomes 79? use 0xF0|0x40 style
      0x40, -- mapper high = 4 -> mapper 0x45? Wait: (F0>>4)|(40&F0) needs low=0x0F for 79
      0, 0, 0, 0, 0, 0, 0, 0
    )
    -- Fix header: mapper 79 = 0x4F -> flags6 high nibble F, flags7 high nibble 4
    hdr = string.char(
      0x4E, 0x45, 0x53, 0x1A,
      2, 2,
      0xF0, -- mapper low = 15, vertical clear
      0x40, -- mapper high = 4 -> mapper 79
      0, 0, 0, 0, 0, 0, 0, 0
    )
    local prg = string.rep(string.char(0xEA), 0x8000)
    -- reset -> $8000 (RTI loop via JMP)
    local prg_t = {}
    for i = 1, 0x8000 do prg_t[i] = string.char(0xEA) end
    prg_t[1] = string.char(0x4C) -- JMP $8000
    prg_t[2] = string.char(0x00)
    prg_t[3] = string.char(0x80)
    prg_t[0x7FFC + 1] = string.char(0x00)
    prg_t[0x7FFD + 1] = string.char(0x80)
    prg_t[0x7FFA + 1] = string.char(0x00)
    prg_t[0x7FFB + 1] = string.char(0x80)
    prg_t[0x7FFE + 1] = string.char(0x00)
    prg_t[0x7FFF + 1] = string.char(0x80)
    -- Two 8KB CHR banks filled with distinct bytes
    local chr0 = string.rep(string.char(0x11), 0x2000)
    local chr1 = string.rep(string.char(0x22), 0x2000)
    local rom79 = hdr .. table.concat(prg_t) .. chr0 .. chr1
    local m79 = Machine.new()
    local ok79, err79 = m79:load_rom_bytes(rom79, { path = "nina.nes", skip_save = true })
    ok("load mapper79", ok79, err79)
    ok("mapper 79", m79.cart.mapper == 79)
    ok("m79 chr bank0 init", m79.cart:chr_read(0) == 0x11)
    m79.cart:cpu_write(0x4100, 0x01) -- CHR bank 1
    ok("m79 chr switched", m79.cart:chr_read(0) == 0x22)
    ok("m79 chr4k pair", m79.cart.chr_bank0 == 2 and m79.cart.chr_bank1 == 3)
  end
end
