-- TI-84 Plus machine facade (SE-class Z80 sibling of TI-83 Plus).

local Flash = require("machines.ti84plus.mem.flash")
local Ram = require("machines.ti84plus.mem.ram")
local Mmu = require("machines.ti84plus.mem.mmu")
local Lcd = require("machines.ti84plus.hw.lcd")
local Keypad = require("machines.ti84plus.hw.keypad")
local Timer = require("machines.ti84plus.hw.timer")
local Asic = require("machines.ti84plus.hw.asic")
local Z80 = require("cpus.z80.z80")
local romutil = require("machines.ti84plus.util.rom")
local Protocol = require("framework.machine")
local SaveState = require("framework.savestate")

local CPU_HZ = 15000000
local MACHINE_ID = "ti84plus"
local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ
Machine.MACHINE_ID = MACHINE_ID
Machine.MODEL = "TI-84 Plus"

function Machine.new()
  local self = setmetatable({}, Machine)
  self.flash = Flash.new()
  self.ram = Ram.new()
  self.mmu = Mmu.new(self.flash, self.ram)
  self.lcd = Lcd.new()
  self.keypad = Keypad.new()
  self.timer = Timer.new(CPU_HZ)
  self._cpu_hz = 6000000 -- power-on default; OS raises via port 20
  self.timer:set_cpu_hz(self._cpu_hz)
  local machine_ref = self
  self.asic = Asic.new({
    mmu = self.mmu,
    lcd = self.lcd,
    keypad = self.keypad,
    timer = self.timer,
    on_cpu_hz = function(hz)
      machine_ref._cpu_hz = hz
    end,
  })

  local asic = self.asic
  local mmu = self.mmu
  self.cpu = Z80.new({
    read = function(addr) return mmu:read(addr) end,
    write = function(addr, value) mmu:write(addr, value) end,
    in_port = function(port) return asic:in_port(port) end,
    out_port = function(port, value) asic:out_port(port, value) end,
    irq_pending = function() return asic:irq_line() end,
    ack_irq = function() asic:ack_interrupt() end,
    im2_vector_lo = 0xFF,
  })

  self.rom_loaded = false
  self.total_cycles = 0
  -- Short on-screen keypad taps can finish before a game's key poll.
  -- zDoom (and similar) only sample input every ~6-10 timer IRQs (~25-85ms),
  -- so a 1-frame hold (~16ms) is often missed. Keep taps down ~100ms.
  self.min_key_hold_cycles = math.floor(6000000 / 10)
  -- TI power-on from HALT needs ON held ~0.5M+ cycles at 6 MHz class timing.
  self.min_on_hold_cycles = math.floor(6000000 / 2)
  self._key_down_at = {}
  self._key_release_at = {}
  Protocol.apply(self)
  return self
end

function Machine:load_rom_bytes(bytes)
  local data, err = romutil.validate(bytes)
  if not data then
    return nil, err
  end
  self.flash:load(data)
  self.rom_loaded = true
  return true
end

function Machine:load_rom_file(path)
  local data, err = romutil.load(path)
  if not data then
    return nil, err
  end
  self.flash:load(data)
  self.rom_loaded = true
  return true
end

--- Full cold reset: RAM, ASIC/LCD/keypad/timer/MMU banks, CPU. Stays at PC=0.
function Machine:reset()
  self.ram:clear()
  self.asic:reset()
  self.cpu:reset()
  self.total_cycles = 0
  self._key_down_at = {}
  self._key_release_at = {}
  self.lcd._dirty = true
end

function Machine:_release_due_keys()
  for name, at in pairs(self._key_release_at) do
    if self.total_cycles >= at then
      self.keypad:set_key(name, false)
      self._key_release_at[name] = nil
      self._key_down_at[name] = nil
    end
  end
end

function Machine:run_cycles(budget)
  if not self.rom_loaded then
    return 0
  end
  local cpu = self.cpu
  local asic = self.asic
  local mmu = self.mmu
  local crystal = asic.crystal
  local ran = 0
  local pending = 0
  local BATCH = 48

  while ran < budget do
    -- End OS crystal busy-waits instantly (force port-$04 expiry bit) without
    -- warping ASIC time. Must re-check every insn: the delay is often armed
    -- mid-budget (caching has_oneshot left us stuck in the spin forever).
    if crystal and crystal.oneshot_live
        and crystal:is_port04_delay_spin(mmu, cpu.pc) then
      crystal:force_nearest_expiry()
    end

    local cyc = cpu:step()
    pending = pending + cyc
    ran = ran + cyc
    if pending >= BATCH or cpu.halted then
      asic:tick(pending)
      pending = 0
    end
  end
  if pending > 0 then
    asic:tick(pending)
  end
  self.total_cycles = self.total_cycles + ran
  self:_release_due_keys()
  return ran
end

--- After reset: reach soft power-off, hold ON, then run until homescreen VAT is up.
-- opts.yield = optional fn called between slices (ComputerCraft).
-- opts.slice = cycles per slice (default 500k; larger = fewer yields on CC).
-- Returns true if Eightxp.vat_ready within the post-ON budget.
function Machine:wake_os(opts)
  opts = opts or {}
  local Eightxp = require("machines.ti84plus.util.eightxp")
  local yield = opts.yield
  local slice = tonumber(opts.slice) or 500000
  if slice < 50000 then
    slice = 50000
  end
  -- Scale wake budgets with current CPU Hz (15 MHz needs more cycles/sec).
  local scale = (self._cpu_hz or CPU_HZ) / 6000000
  if scale < 1 then scale = 1 end

  local function pump(max_cycles, pred)
    local left = max_cycles
    while left > 0 do
      if pred and pred() then
        return true
      end
      local n = left
      if n > slice then
        n = slice
      end
      self:run_cycles(n)
      left = left - n
      if yield then
        yield()
      end
    end
    return pred and pred() or false
  end

  pump(math.floor(5 * 1000 * 1000 * scale), function()
    return self.cpu.halted
  end)

  self:set_key("on", true)
  local hold = self.min_on_hold_cycles or math.floor(6000000 / 2)
  if hold < 3000000 then
    hold = 3000000
  end
  hold = math.floor(hold * scale)
  pump(hold, nil)
  self:set_key("on", false)

  local ready = pump(math.floor(20 * 1000 * 1000 * scale), function()
    return Eightxp.vat_ready(self.mmu)
  end)
  self.lcd._dirty = true
  return ready
end

function Machine:set_key(name, down)
  if down then
    self._key_release_at[name] = nil
    if not self._key_down_at[name] then
      self._key_down_at[name] = self.total_cycles
    end
    return self.keypad:set_key(name, true)
  end

  local down_at = self._key_down_at[name]
  if not down_at then
    return self.keypad:set_key(name, false)
  end

  local hold = self.min_key_hold_cycles
  if name == "on" then
    hold = self.min_on_hold_cycles or hold
  end
  local release_at = down_at + hold
  if self.total_cycles >= release_at then
    self._key_down_at[name] = nil
    self._key_release_at[name] = nil
    return self.keypad:set_key(name, false)
  end

  -- Defer release until the key has been down long enough for TI-OS to see it.
  self._key_release_at[name] = release_at
  return true
end

function Machine:set_key_matrix(group, bitn, down)
  self.keypad:set_key_matrix(group, bitn, down)
end

function Machine:framebuffer()
  return self.lcd:framebuffer()
end

function Machine:display_dirty()
  return self.lcd:dirty()
end

function Machine:clear_display_dirty()
  self.lcd:clear_dirty()
end

function Machine:is_display_on()
  return self.lcd:is_display_on()
end

function Machine:pc()
  return self.cpu.pc
end

--- Execute one Z80 instruction (and tick ASIC by its cycle cost).
--- Respects HALT: burns 4 T-states until an interrupt wakes the CPU.
function Machine:step_instruction()
  if not self.rom_loaded then
    return 0
  end
  local cyc = self.cpu:step()
  self.asic:tick(cyc)
  self.total_cycles = self.total_cycles + cyc
  self.lcd._dirty = true
  self:_release_due_keys()
  return cyc
end

function Machine:cycles_per_frame(fps)
  fps = fps or 60
  return math.floor((self._cpu_hz or CPU_HZ) / fps)
end

local function pack_key_matrix(keys)
  local out = {}
  for g = 0, 7 do
    local row = keys[g] or {}
    local bits = 0
    for b = 0, 7 do
      if row[b] then
        bits = bits + (2 ^ b)
      end
    end
    out[g + 1] = bits
  end
  return out
end

local function unpack_key_matrix(keypad, packed)
  keypad:reset()
  for g = 0, 7 do
    local bits = packed[g + 1] or 0
    for b = 0, 7 do
      if math.floor(bits / (2 ^ b)) % 2 == 1 then
        keypad.keys[g][b] = true
        if g == 5 and b == 0 then
          keypad.on_pressed = true
        end
      end
    end
  end
  keypad.input_dirty = true
end

function Machine:saveState()
  local cpu = self.cpu
  local asic = self.asic
  local lcd = self.lcd
  local timer = self.timer
  local mmu = self.mmu
  local keypad = self.keypad

  return SaveState.new(MACHINE_ID, {
    cpu = cpu:getRegisters(),
    cpu_extra = {
      ei_delay = cpu.ei_delay,
      cycles = cpu.cycles,
    },
    ram = SaveState.pack_bytes(self.ram.bytes, self.ram.SIZE),
    flash = SaveState.pack_bytes(self.flash.bytes, self.flash.SIZE or (0x4000 * 64)),
    flash_cmd = {
      cmd_state = self.flash.cmd_state,
      override_reads = self.flash.override_reads,
    },
    mmu = {
      page_boot = mmu.page_boot,
      page_bankA = mmu.page_bankA,
      page_bankB = mmu.page_bankB,
      bankA_is_ram = mmu.bankA_is_ram,
      bankB_is_ram = mmu.bankB_is_ram,
      mem_mode = mmu.mem_mode,
      ram_page = mmu.ram_page,
      flash_unlocked = mmu.flash_unlocked,
    },
    lcd = {
      fb = SaveState.pack_bytes(lcd.fb, 15 * 64),
      x = lcd.x, y = lcd.y, z = lcd.z,
      contrast = lcd.contrast,
      display_on = lcd.display_on,
      bits8 = lcd.bits8,
      inc_col = lcd.inc_col,
      inc_up = lcd.inc_up,
      busy_cycles = lcd.busy_cycles,
      read_reg = lcd.read_reg,
    },
    timer = {
      counter1 = timer.counter1,
      counter2 = timer.counter2,
      speed = timer.speed,
      period1 = timer.period1,
      period2 = timer.period2,
      pending1 = timer.pending1,
      pending2 = timer.pending2,
    },
    asic = {
      int_mask = asic.int_mask,
      int_status = asic.int_status,
      port04 = asic.port04,
      link_out = asic.link_out,
      flash_port = asic.flash_port,
      ram_page_port = asic.ram_page_port,
      cpu_speed = asic.cpu_speed,
      port21 = asic.port21,
      rtc_ctrl = asic.rtc_ctrl,
      rtc_set = { asic.rtc_set[1], asic.rtc_set[2], asic.rtc_set[3], asic.rtc_set[4] },
      rtc_cur = { asic.rtc_cur[1], asic.rtc_cur[2], asic.rtc_cur[3], asic.rtc_cur[4] },
      on_prev = asic._on_prev,
    },
    keypad = {
      group_mask = keypad.group_mask,
      on_pressed = keypad.on_pressed,
      matrix = pack_key_matrix(keypad.keys),
    },
    machine = {
      rom_loaded = self.rom_loaded,
      total_cycles = self.total_cycles,
      min_key_hold_cycles = self.min_key_hold_cycles,
      min_on_hold_cycles = self.min_on_hold_cycles,
      key_down_at = self._key_down_at,
      key_release_at = self._key_release_at,
    },
  })
end

function Machine:loadState(state)
  local ok, err = SaveState.validate(state, MACHINE_ID)
  if not ok then
    return nil, err
  end
  local b = state.blobs
  local cpu = self.cpu
  local asic = self.asic
  local lcd = self.lcd
  local timer = self.timer
  local mmu = self.mmu
  local keypad = self.keypad

  cpu:setRegisters(b.cpu)
  if b.cpu_extra then
    cpu.ei_delay = b.cpu_extra.ei_delay
    cpu.cycles = b.cpu_extra.cycles or 0
  end

  SaveState.unpack_bytes(b.ram, self.ram.bytes)
  SaveState.unpack_bytes(b.flash, self.flash.bytes)
  self.flash.data = b.flash
  if b.flash_cmd then
    self.flash.cmd_state = b.flash_cmd.cmd_state
    self.flash.override_reads = b.flash_cmd.override_reads
  end

  if b.mmu then
    mmu.page_boot = b.mmu.page_boot
    mmu.page_bankA = b.mmu.page_bankA
    mmu.page_bankB = b.mmu.page_bankB
    mmu.bankA_is_ram = b.mmu.bankA_is_ram
    mmu.bankB_is_ram = b.mmu.bankB_is_ram
    mmu.mem_mode = b.mmu.mem_mode
    mmu.ram_page = b.mmu.ram_page or 0
    mmu.flash_unlocked = b.mmu.flash_unlocked
    mmu:_rebuild_map()
  end

  if b.lcd then
    SaveState.unpack_bytes(b.lcd.fb, lcd.fb)
    lcd.x = b.lcd.x
    lcd.y = b.lcd.y
    lcd.z = b.lcd.z
    lcd.contrast = b.lcd.contrast
    lcd.display_on = b.lcd.display_on
    lcd.bits8 = b.lcd.bits8
    lcd.inc_col = b.lcd.inc_col
    lcd.inc_up = b.lcd.inc_up
    lcd.busy_cycles = b.lcd.busy_cycles
    lcd.read_reg = b.lcd.read_reg
    lcd._dirty = true
  end

  if b.timer then
    for k, v in pairs(b.timer) do
      timer[k] = v
    end
  end

  if b.asic then
    asic.int_mask = b.asic.int_mask
    asic.int_status = b.asic.int_status
    asic.port04 = b.asic.port04
    asic.link_out = b.asic.link_out
    asic.flash_port = b.asic.flash_port
    asic.ram_page_port = b.asic.ram_page_port
    asic.cpu_speed = b.asic.cpu_speed or 0
    asic.port21 = b.asic.port21 or 0
    asic.rtc_ctrl = b.asic.rtc_ctrl or 0
    if b.asic.rtc_set then
      for i = 1, 4 do asic.rtc_set[i] = b.asic.rtc_set[i] or 0 end
    end
    if b.asic.rtc_cur then
      for i = 1, 4 do asic.rtc_cur[i] = b.asic.rtc_cur[i] or 0 end
    end
    asic._on_prev = b.asic.on_prev
    self._cpu_hz = asic:effective_cpu_hz()
    self.timer:set_cpu_hz(self._cpu_hz)
  end

  if b.keypad then
    unpack_key_matrix(keypad, b.keypad.matrix or {})
    keypad.group_mask = b.keypad.group_mask or 0xFF
    keypad.on_pressed = not not b.keypad.on_pressed
  end

  if b.machine then
    self.rom_loaded = b.machine.rom_loaded
    self.total_cycles = b.machine.total_cycles or 0
    self.min_key_hold_cycles = b.machine.min_key_hold_cycles or self.min_key_hold_cycles
    self.min_on_hold_cycles = b.machine.min_on_hold_cycles or self.min_on_hold_cycles
    self._key_down_at = b.machine.key_down_at or {}
    self._key_release_at = b.machine.key_release_at or {}
  end

  return true
end

return Machine
