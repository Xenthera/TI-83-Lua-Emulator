-- TI-89 Titanium memory bus (HW3-class): RAM, 4MB flash, $600000/$700000/$710000 I/O.
-- Flash is visible at $800000 (Titanium) and mirrored at $200000 (classic dumps).

local bit = require("framework.util.bit")
local band, bor, bnot, lshift, rshift = bit.band, bit.bor, bit.bnot, bit.lshift, bit.rshift

local Bus = {}
Bus.__index = Bus

function Bus.new(opts)
  local self = setmetatable({}, Bus)
  self.ram = opts.ram
  self.flash = opts.flash
  self.lcd = opts.lcd
  self.keyboard = opts.keyboard
  self.cpu = opts.cpu -- set after CPU construction if needed
  self.io = {}
  self.io7 = {} -- $700000 HW2+ LCD / ASIC
  self.io71 = {} -- $710000 HW3+ RTC / power ASIC (256 bytes)
  for i = 0, 0x1F do
    self.io[i] = 0
    self.io7[i] = 0
  end
  for i = 0, 0xFF do
    self.io71[i] = 0
  end
  -- Default HW2+ power-on values (battery OK, screen enabled).
  self.io7[0x1D] = 0x07 -- bits0-1 battery A/B + screen enable
  self.io7[0x1F] = 0x07
  -- RAM exec protect: bit SET = fetch forbidden. Reset allows $005xxx only.
  self.io7[0x00], self.io7[0x01] = 0xFF, 0xDF
  self.io7[0x02], self.io7[0x03] = 0xFF, 0xFF
  self.io7[0x04], self.io7[0x05] = 0xFF, 0xFF
  self.io7[0x06], self.io7[0x07] = 0xFF, 0xFF
  -- Flash exec protect: n=$18 -> classic $390000-$3FFFFF (archive).
  self.io7[0x12], self.io7[0x13] = 0x00, 0x18
  -- Cached classic-map cutoff for flash exec (updated with $700012/$13).
  self.flash_exec_first = 0x210000 + 0x18 * 0x10000
  -- HW3 $710055: AMS AI3 path needs bits 2+4 set.
  self.io71[0x55] = 0x14
  -- HW3 RTC control ($71005F): TiEmu powers up with bit7 set. Bit0 = clock
  -- enabled; AMS install checks bit0 before advancing past the date dialog.
  self.io71[0x5F] = 0x80
  self.io[0] = 0x00
  -- Link port idle status (J89hw): $8D. Zero broke AI4 / OS event paths.
  self.io[0x0C] = 0x8D
  self.io[0x0F] = 0x00
  -- Keyboard row mask power-on (docs: $0280 / $0380).
  self.io[0x18] = 0x02
  self.io[0x19] = 0x80
  self.timer_ai1 = 0
  self.timer_ai3 = 0
  self.timer_ai4 = 0
  self.timer_ai5 = 0
  self.irq_pending = 0 -- bitmask of levels 1..6
  self.sleep_mask = 0 -- $600005 wake bits; 0 = not sleeping via port
  self.link = { tip = 1, ring = 1 }
  self.hw = 3 -- Titanium
  -- Protection latch off until AMS enables it; RAM page masks still stored.
  self.protect_enabled = false
  self.rtc_div = 0 -- $700014 increment divider
  -- HW3 RTC ($710040-$710049): load regs + running seconds since load.
  self.rtc3_load_s = 0
  self.rtc3_load_frac = 0 -- 1/16th seconds (0..15)
  self.rtc3_cycles = 0 -- cycles since last reload while enabled
  return self
end

function Bus:reset()
  for i = 0, 0x1F do
    self.io[i] = 0
    self.io7[i] = 0
  end
  for i = 0, 0xFF do
    self.io71[i] = 0
  end
  self.io7[0x1D] = 0x07
  self.io7[0x1F] = 0x07
  self.io7[0x00], self.io7[0x01] = 0xFF, 0xDF
  self.io7[0x02], self.io7[0x03] = 0xFF, 0xFF
  self.io7[0x04], self.io7[0x05] = 0xFF, 0xFF
  self.io7[0x06], self.io7[0x07] = 0xFF, 0xFF
  self.io7[0x12], self.io7[0x13] = 0x00, 0x18
  self.flash_exec_first = 0x210000 + 0x18 * 0x10000
  self.io71[0x55] = 0x14
  self.io71[0x5F] = 0x80
  self.io[0x0C] = 0x8D
  self.io[0x0F] = 0x00
  self.io[0x18] = 0x02
  self.io[0x19] = 0x80
  self.timer_ai1 = 0
  self.timer_ai3 = 0
  self.timer_ai4 = 0
  self.timer_ai5 = 0
  self.irq_pending = 0
  self.sleep_mask = 0
  self.protect_enabled = false
  self.rtc_div = 0
  self.rtc3_load_s = 0
  self.rtc3_load_frac = 0
  self.rtc3_cycles = 0
  self.lcd:reset()
  self.keyboard:reset()
  self.keyboard:write_mask(0x0280)
  self.ram:clear()
end

--- Refresh $710045-$710049 from load + elapsed time while RTC is enabled.
function Bus:rtc3_update_count()
  local enabled = band(self.io71[0x5F] or 0, 0x01) ~= 0
  local frac = self.rtc3_load_frac or 0
  local secs = self.rtc3_load_s or 0
  if enabled then
    local add = math.floor((self.rtc3_cycles or 0) / 16000000)
    secs = band(secs + add, 0xFFFFFFFF)
    -- Advance 1/16th roughly with leftover; good enough for AMS probes.
    local rem = (self.rtc3_cycles or 0) % 16000000
    frac = band(frac + math.floor(rem / 1000000), 0x0F)
  end
  self.io71[0x45] = band(frac, 0x0F)
  self.io71[0x46] = band(rshift(secs, 24), 0xFF)
  self.io71[0x47] = band(rshift(secs, 16), 0xFF)
  self.io71[0x48] = band(rshift(secs, 8), 0xFF)
  self.io71[0x49] = band(secs, 0xFF)
end

function Bus:io71_write(off, value)
  value = band(value, 0xFF)
  if off >= 0x45 and off <= 0x49 then
    -- Counting registers are read-only.
    return
  end
  if off == 0x44 then
    value = band(value, 0x0F)
    self.io71[off] = value
    return
  end
  if off == 0x5F then
    -- TiEmu: only bits 0-1 writable; bit7 always set.
    value = bor(band(value, 0x03), 0x80)
    if band(value, 0x01) == 0 then
      -- Clock disabled: clear load seconds.
      self.io71[0x40], self.io71[0x41] = 0, 0
      self.io71[0x42], self.io71[0x43] = 0, 0
      self.rtc3_load_s = 0
      self.rtc3_load_frac = 0
      self.rtc3_cycles = 0
      self:rtc3_update_count()
    elseif band(value, 0x02) == 0 then
      -- bit0=1, bit1=0: reload load regs into counting regs / time base.
      self.rtc3_load_s = bor(
        lshift(self.io71[0x40] or 0, 24),
        lshift(self.io71[0x41] or 0, 16),
        lshift(self.io71[0x42] or 0, 8),
        self.io71[0x43] or 0
      )
      self.rtc3_load_frac = band(self.io71[0x44] or 0, 0x0F)
      self.rtc3_cycles = 0
      self:rtc3_update_count()
    end
    self.io71[0x5F] = value
    return
  end
  self.io71[off] = value
end

function Bus:io71_read(off)
  if off >= 0x45 and off <= 0x49 then
    self:rtc3_update_count()
  elseif off == 0x44 then
    return band(self.io71[0x44] or 0, 0x0F)
  end
  return self.io71[off] or 0
end

function Bus:raise_irq(level)
  if level > 0 and level < 8 then
    self.irq_pending = bor(self.irq_pending, lshift(1, level))
  end
end

local function flash_offset(addr)
  -- Titanium: $800000-$BFFFFF. Classic dumps: $200000-$5FFFFF.
  if addr >= 0x800000 and addr < 0xC00000 then
    return addr - 0x800000
  end
  if addr >= 0x200000 and addr < 0x600000 then
    return addr - 0x200000
  end
  return nil
end

local function map_read(self, addr)
  addr = band(addr, 0xFFFFFF)
  if addr < 0x200000 then
    return self.ram:read8(addr)
  end
  local foff = flash_offset(addr)
  if foff then
    return self.flash:read8(foff)
  end
  if addr >= 0x600000 and addr < 0x600020 then
    return self:io6_read(addr - 0x600000)
  end
  if addr >= 0x700000 and addr < 0x700020 then
    return self:io7_read(addr - 0x700000)
  end
  if addr >= 0x710000 and addr < 0x710100 then
    return self:io71_read(addr - 0x710000)
  end
  return 0xFF
end

local function map_write(self, addr, value)
  addr = band(addr, 0xFFFFFF)
  value = band(value, 0xFF)
  if addr < 0x200000 then
    local ram_off = addr % self.ram.SIZE
    -- Real HW write-protects $000000-$00011F (288 bytes), including via the
    -- 256KB RAM mirrors. AMS boot vectors come from the ROM copy at reset.
    if ram_off < 0x120 then
      return
    end
    self.ram:write8(addr, value)
    -- HW2+/Titanium LCD snoops writes into the selected 4KB window.
    self.lcd:snoop_write(ram_off, value)
    return
  end
  if addr >= 0x600000 and addr < 0x600020 then
    self:io6_write(addr - 0x600000, value)
    return
  end
  if addr >= 0x700000 and addr < 0x700020 then
    self:io7_write(addr - 0x700000, value)
    return
  end
  if addr >= 0x710000 and addr < 0x710100 then
    self:io71_write(addr - 0x710000, value)
    return
  end
  local foff = flash_offset(addr)
  if foff then
    self.flash:write8(foff, value)
  end
end

function Bus:io6_read(off)
  if off == 0 then
    -- bit2: battery voltage OK (1) when checker enabled
    return bor(self.io[0] or 0, 0x04)
  end
  if off == 0x0C then
    -- Link status: keep idle $8D unless AMS is mid-reset ($E0).
    local v = self.io[0x0C] or 0x8D
    if v == 0xE0 then return 0xE0 end
    return 0x8D
  end
  if off == 0x1A then
    return self.keyboard:read_on()
  end
  if off == 0x1B then
    return self.keyboard:read()
  end
  return self.io[off] or 0
end

function Bus:io6_write(off, value)
  self.io[off] = value
  if off == 0x05 then
    -- Halt OSC1/CPU; wake on ON (AI6) and masked auto-ints.
    self.sleep_mask = value
    if value ~= 0 and self.cpu then
      self.cpu.stopped = true
      self.cpu.sleep_unmask = true
    end
  elseif off == 0x0C then
    -- Link reset sequence: $E0 then $8D.
    if value == 0x8D or value == 0xE0 then
      self.io[0x0C] = value
    else
      self.io[0x0C] = 0x8D
    end
  elseif off == 0x10 or off == 0x11 then
    -- HW1 LCD base (/8). Harmless no-op for display on HW2+/Titanium.
    local lo = self.io[0x10] or 0
    local hi = self.io[0x11] or 0
    self.lcd:set_base_div8(bor(lshift(hi, 8), lo))
  elseif off == 0x12 then
    self.lcd.width_reg = value
  elseif off == 0x13 then
    self.lcd.height_reg = value
  elseif off == 0x15 then
    -- bit1 = LCD data enable
    self.lcd.display_on = band(value, 0x02) ~= 0 or band(value, 0x01) ~= 0
  elseif off == 0x18 or off == 0x19 then
    -- Big-endian word at $600018: hi at +0, lo at +1.
    local hi = self.io[0x18] or 0
    local lo = self.io[0x19] or 0
    self.keyboard:write_mask(bor(lshift(hi, 8), lo))
  elseif off == 0x1A then
    -- AI6 ack
  elseif off == 0x1B then
    -- AI2 ack
  end
end

function Bus:io7_read(off)
  return self.io7[off] or 0
end

function Bus:io7_write(off, value)
  value = band(value, 0xFF)
  -- Ghost ports $700008-$70000F mirror RAM exec protect $700000-$700007.
  local ram_prot = off
  if off >= 0x08 and off <= 0x0F then
    ram_prot = off - 0x08
  end
  if ram_prot >= 0 and ram_prot <= 0x07 then
    -- Real HW only accepts changes while Protection is disabled; we always
    -- store so AMS/tools can program the masks, and enforce via protect_enabled.
    self.io7[ram_prot] = value
    self.io7[ram_prot + 0x08] = value
  else
    self.io7[off] = value
  end
  if off == 0x17 then
    -- HW2+ LCD snoop range select ($700017)
    self.lcd:set_snoop_range(value)
  elseif off == 0x1D then
    -- bit1 = screen enable
    self.lcd.display_on = band(value, 0x02) ~= 0
  elseif off == 0x12 or off == 0x13 then
    -- Flash exec protect word ($700012 hi / $700013 lo).
    local n = band(self.io7[0x13] or 0x18, 0x3F)
    self.flash_exec_first = 0x210000 + n * 0x10000
  end
  -- $700012/$700013: flash ROM execution protection (word, hi at +0).
  -- LCD geometry is only $600012/$600013 (io6).
end

--- Return false if an instruction fetch at addr is forbidden by HW2+ protect.
-- Flash archive guard ($700012) is always applied (safe for AMS below the
-- cutoff). RAM page bits apply only when protect_enabled (the HW "Protection"
-- latch); default false so early boot / unit tests can run from low RAM.
function Bus:exec_allowed(addr)
  local cutoff = self.flash_exec_first or 0x390000
  -- Hot path: AMS runs from Titanium flash $8xxxxx below the archive cutoff.
  if addr >= 0x800000 and addr < 0xC00000 then
    local classic = 0x200000 + (addr - 0x800000)
    return classic < cutoff
  end
  if addr >= 0x200000 and addr < 0x600000 then
    -- Classic window is 4MB-wide, but 2MB HW2 images (TI-92+) often fetch from
    -- $40xxxx aliases. Flash:read8 already wraps with addr%size; protect must
    -- use the same physical offset so $400132 (->$000132) is not treated as archive.
    local foff = addr - 0x200000
    local sz = self.flash and self.flash.size
    if sz and sz > 0 and foff >= sz then
      foff = foff % sz
    end
    return (0x200000 + foff) < cutoff
  end
  if not self.protect_enabled then return true end
  -- RAM: 256KB mirrored; each bit in $700000-$700007 covers a 4KB page.
  addr = band(addr or 0, 0xFFFFFF)
  if addr < 0x200000 then
    local page = rshift(addr % self.ram.SIZE, 12) -- 0..63
    if addr >= 0x40000 then
      -- Shadow RAM $040000-$1FFFFF shares the last page bit (HW2+).
      page = 63
    end
    local word = rshift(page, 4) -- 0..3 -> ports $700000/$02/$04/$06
    local bitn = page % 16
    local hi = self.io7[word * 2] or 0
    local lo = self.io7[word * 2 + 1] or 0
    local mask = bor(lshift(hi, 8), lo)
    -- bit SET => fetch forbidden. $700000:15-0 = $00Fxxx-$000xxx
    -- (bit0=$000xxx ... bit15=$00Fxxx). Reset $FFDF allows $005xxx only.
    if band(mask, lshift(1, bitn)) ~= 0 then return false end
  end
  return true
end

function Bus:read8(addr) return map_read(self, addr) end
function Bus:write8(addr, v) map_write(self, addr, v) end

function Bus:read16(addr)
  -- Fast path: aligned flash instruction/data fetch (vast majority of reads).
  -- Inline sticky page cache (same idea as TI-83+ banked arrays, sparse for 4MB).
  if addr >= 0x800000 and addr < 0xC00000 then
    local flash = self.flash
    if flash.mode == "read" or flash.mode == nil then
      local foff = addr - 0x800000
      local p = flash._page_p
      local page = math.floor(foff / 65536)
      if flash._page_i == page and p then
        local o = foff - page * 65536
        return (p[o] or 0xFF) * 256 + (p[o + 1] or 0xFF)
      end
      return flash:read16_data(foff)
    end
  elseif addr >= 0x200000 and addr < 0x600000 then
    local flash = self.flash
    if flash.mode == "read" or flash.mode == nil then
      local foff = addr - 0x200000
      local p = flash._page_p
      local page = math.floor(foff / 65536)
      if flash._page_i == page and p then
        local o = foff - page * 65536
        return (p[o] or 0xFF) * 256 + (p[o + 1] or 0xFF)
      end
      return flash:read16_data(foff)
    end
  elseif addr < 0x200000 then
    local bytes = self.ram.bytes
    local o = addr % self.ram.SIZE
    return (bytes[o] or 0) * 256 + (bytes[o + 1] or 0)
  end
  addr = band(addr, 0xFFFFFF)
  return map_read(self, addr) * 256 + map_read(self, addr + 1)
end

function Bus:write16(addr, v)
  addr = band(addr, 0xFFFFFF)
  v = band(v, 0xFFFF)
  local foff = flash_offset(addr)
  if foff then
    -- Flash commands are word-oriented; do not split into write8.
    self.flash:write16(foff, v)
    return
  end
  self:write8(addr, rshift(v, 8))
  self:write8(addr + 1, band(v, 0xFF))
end

function Bus:read32(addr)
  return bor(lshift(self:read16(addr), 16), self:read16(addr + 2))
end

function Bus:write32(addr, v)
  self:write16(addr, rshift(v, 16))
  self:write16(addr + 2, band(v, 0xFFFF))
end

function Bus:tick(cycles)
  -- AI1 ≈ 256 Hz ≈ 62500 cyc; AI3 ≈ 1 Hz ≈ 16e6 cyc; AI4 ≈ 8 Hz ≈ 2e6 cyc;
  -- AI5 ≈ 20 Hz ≈ 800000 cyc.
  -- AMS TRAP #4 sleeps with $600005 = $0C (AI3|AI4); without AI3/AI4 that
  -- sleep never wakes and first-boot install cannot reach $86D6E4.
  self.timer_ai1 = self.timer_ai1 + cycles
  self.timer_ai3 = self.timer_ai3 + cycles
  self.timer_ai4 = self.timer_ai4 + cycles
  self.timer_ai5 = self.timer_ai5 + cycles
  if band(self.io71[0x5F] or 0, 0x01) ~= 0 then
    self.rtc3_cycles = (self.rtc3_cycles or 0) + cycles
  end
  if self.timer_ai1 >= 62500 then
    self.timer_ai1 = self.timer_ai1 - 62500
    self:raise_irq(1)
  end
  if self.timer_ai3 >= 16000000 then
    self.timer_ai3 = self.timer_ai3 - 16000000
    self:raise_irq(3)
  end
  if self.timer_ai4 >= 2000000 then
    self.timer_ai4 = self.timer_ai4 - 2000000
    self:raise_irq(4)
  end
  if self.timer_ai5 >= 800000 then
    self.timer_ai5 = self.timer_ai5 - 800000
    self:raise_irq(5)
  end
  -- $700014 RTC: when $70001F bits2+1 = 11, increment every 8192 seconds.
  -- We use a free-running divider so AMS timekeeping can observe change.
  local rtc_en = band(self.io7[0x1F] or 0, 0x06)
  if rtc_en == 0x06 then
    self.rtc_div = self.rtc_div + cycles
    -- Speed: 1 RTC tick per emulated second (vs real 8192s) so boot/time paths move.
    if self.rtc_div >= 16000000 then
      self.rtc_div = self.rtc_div - 16000000
      local lo = self.io7[0x15] or 0
      local hi = self.io7[0x14] or 0
      local v = band(bor(lshift(hi, 8), lo) + 1, 0xFFFF)
      self.io7[0x14] = rshift(v, 8)
      self.io7[0x15] = band(v, 0xFF)
    end
  end
  local kb = self.keyboard
  if kb.changed then
    kb.changed = false
    self:raise_irq(2)
  end
  if kb.on_edge then
    kb.on_edge = false
    self:raise_irq(6)
  end
end

function Bus:irq_level_pending()
  local pending = self.irq_pending
  if pending == 0 then return 0 end
  local sleep = self.sleep_mask
  local cpu = self.cpu
  local ipl = 0
  local unmask = false
  if cpu then
    ipl = rshift(band(cpu.sr, 0x0700), 8)
    unmask = cpu.sleep_unmask and sleep and sleep ~= 0
  end
  -- Highest level first (6..1).
  for lvl = 6, 1, -1 do
    local bitv = lshift(1, lvl)
    if band(pending, bitv) ~= 0 then
      -- 68000: only levels strictly above IPL (7 is NMI-like), unless
      -- waking from $600005 sleep (hardware ignores IPL for wake IRQs).
      local ipl_ok = unmask or lvl > ipl or lvl == 7
      local wake = true
      if sleep and sleep ~= 0 then
        if lvl == 6 then
          wake = true
        elseif lvl >= 1 and lvl <= 5 then
          wake = band(sleep, lshift(1, lvl - 1)) ~= 0
        else
          wake = false
        end
      end
      if ipl_ok and wake then
        self.irq_pending = band(pending, bnot(bitv))
        if sleep and sleep ~= 0 then self.sleep_mask = 0 end
        return lvl
      end
    end
  end
  return 0
end

return Bus
