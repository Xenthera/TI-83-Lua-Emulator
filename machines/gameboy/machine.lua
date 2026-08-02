-- Original Game Boy (DMG) machine facade.

local Cart = require("machines.gameboy.mem.cart")
local Wram = require("machines.gameboy.mem.wram")
local Mmu = require("machines.gameboy.mem.mmu")
local Irq = require("machines.gameboy.hw.irq")
local Timer = require("machines.gameboy.hw.timer")
local Joypad = require("machines.gameboy.hw.joypad")
local Ppu = require("machines.gameboy.hw.ppu")
local Apu = require("machines.gameboy.hw.apu")
local SM83 = require("cpus.sm83.sm83")
local Protocol = require("framework.machine")
local SaveState = require("framework.savestate")
local Path = require("framework.path")

local CPU_HZ = 4194304
local MACHINE_ID = "gameboy"

local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ
Machine.MACHINE_ID = MACHINE_ID

local function has_fs()
  return type(fs) == "table" and type(fs.open) == "function"
end

local function read_bytes(path)
  if has_fs() then
    if fs.exists and not fs.exists(path) then
      return nil, "file not found"
    end
    local h = fs.open(path, "rb")
    if not h then h = fs.open(path, "r") end
    if not h then return nil, "cannot open " .. tostring(path) end
    local data = h.readAll and h.readAll() or h.read("*a")
    h.close()
    if data == nil then return nil, "failed to read " .. tostring(path) end
    return data
  end
  local f, err = io.open(path, "rb")
  if not f then return nil, err end
  local data = f:read("*a")
  f:close()
  return data
end

local function write_bytes(path, data)
  data = data or ""
  if has_fs() then
    local parent = tostring(path):match("^(.*)[/\\][^/\\]+$")
    if parent and parent ~= "" and fs.makeDir and not fs.exists(parent) then
      pcall(fs.makeDir, parent)
    end
    local h = fs.open(path, "wb")
    if not h then h = fs.open(path, "w") end
    if not h then return nil, "cannot write " .. tostring(path) end
    local ok = pcall(function() h.write(data) end)
    if not ok then
      for i = 1, #data do h.write(data:byte(i)) end
    end
    h.close()
    return true
  end
  local parent = tostring(path):match("^(.*)[/\\][^/\\]+$")
  if parent and parent ~= "" then
    Path.ensure_dir(parent)
  end
  local f, err = io.open(path, "wb")
  if not f then return nil, err end
  f:write(data)
  f:close()
  return true
end

--- Map a cart path to its sidecar .sav (ROM file stays read-only).
-- opts.save_path wins; else opts.save_dir + basename; else beside the ROM.
function Machine.save_path_for(rom_path, opts)
  opts = opts or {}
  if opts.save_path and opts.save_path ~= "" then
    return opts.save_path
  end
  if not rom_path or rom_path == "" then
    return nil
  end
  local name = tostring(rom_path)
  local base = name:gsub("%.[gG][bB][cC]?$", "")
  if base == name then
    base = name
  end
  local sav_name = (base:match("([^/\\]+)$") or base) .. ".sav"
  local has_dir = name:find("[/\\]") ~= nil
  if opts.save_dir and opts.save_dir ~= "" and not has_dir then
    local dir = tostring(opts.save_dir):gsub("[/\\]+$", "")
    return dir .. "/" .. sav_name
  end
  if has_dir then
    local dir = name:match("^(.*)[/\\][^/\\]+$") or "."
    return dir .. "/" .. sav_name
  end
  return sav_name
end

function Machine.new()
  local self = setmetatable({}, Machine)
  self.irq = Irq.new()
  self.cart = Cart.new()
  self.wram = Wram.new()
  self.ppu = Ppu.new(self.irq)
  -- CC host writes machine.lcd._dirty; alias PPU as lcd.
  self.lcd = self.ppu
  self.timer = Timer.new(self.irq)
  self.joypad = Joypad.new(self.irq)
  self.apu = Apu.new()
  self.mmu = Mmu.new({
    cart = self.cart,
    wram = self.wram,
    ppu = self.ppu,
    timer = self.timer,
    joypad = self.joypad,
    irq = self.irq,
    apu = self.apu,
  })

  local mmu = self.mmu
  local timer, ppu, apu = self.timer, self.ppu, self.apu
  -- APU is batched to instruction boundaries (flush on I/O / sample drain).
  -- Timer/PPU stay per-M-cycle for mem_timing / mid-scanline LCDC demos.
  self.cpu = SM83.new({
    read = function(addr) return mmu:read(addr) end,
    write = function(addr, value) mmu:write(addr, value) end,
    tick = function(t)
      timer:tick(t)
      ppu:tick(t)
      apu:owe(t)
      if mmu.serial.cycles > 0 then
        mmu:tick(t)
      end
    end,
    irq = self.irq,
  })

  self.rom_loaded = false
  self.rom_path = nil
  self.save_path = nil
  -- Sidecar cart files (SRAM etc.). ROM bytes stay in cart.rom; never rewritten.
  self.rom_data = {}
  self.total_cycles = 0
  self.use_boot_rom = false
  Protocol.apply(self)
  return self
end

function Machine:load_rom_bytes(bytes, opts)
  if type(opts) == "string" then
    opts = { path = opts }
  end
  opts = opts or {}

  -- Persist previous cart SRAM before wiping it with a new image.
  if self.rom_loaded and self.cart:has_save_ram() and not opts.skip_flush then
    self:save_cart_save()
  end

  local ok, err = self.cart:load(bytes)
  if not ok then return nil, err end
  self.mmu:_bind_fast()
  self.rom_loaded = true
  self.rom_path = opts.path
  self.save_path = Machine.save_path_for(opts.path, opts)
  self.rom_data = {
    save_path = self.save_path,
    rom_path = self.rom_path,
    title = self.cart.title,
  }

  if not opts.skip_save and self.cart:has_save_ram() and self.save_path then
    local lok = self:load_cart_save(self.save_path)
    if lok then
      self.rom_data.loaded = true
    end
  end
  return true
end

function Machine:load_rom_file(path, opts)
  opts = opts or {}
  local f, err = io.open(path, "rb")
  if not f then return nil, err or "open failed" end
  local data = f:read("*a")
  f:close()
  opts.path = opts.path or path
  return self:load_rom_bytes(data, opts)
end

function Machine:load_boot_rom_file(path)
  local f, err = io.open(path, "rb")
  if not f then return nil, err or "open failed" end
  local data = f:read("*a")
  f:close()
  local ok, e = self.mmu:load_boot_rom(data)
  if ok then self.use_boot_rom = true end
  return ok, e
end

--- Import cartridge flash/SRAM from a .sav (or any binary) into cart RAM.
function Machine:load_cart_save(path)
  path = path or self.save_path
  if not path then return nil, "no save path" end
  if not self.cart:has_save_ram() then return nil, "cart has no save RAM" end
  local data, err = read_bytes(path)
  if not data then return nil, err end
  local ok, ierr = self.cart:import_ram(data)
  if not ok then return nil, ierr end
  self.rom_data = self.rom_data or {}
  self.rom_data.save = data
  self.rom_data.save_path = path
  self.rom_data.loaded = true
  self.save_path = path
  return true
end

--- Export cartridge flash/SRAM to the sidecar .sav (does not touch the ROM file).
function Machine:save_cart_save(path)
  path = path or self.save_path
  if not path then return nil, "no save path" end
  if not self.cart:has_save_ram() then return nil, "cart has no save RAM" end
  local data = self.cart:export_ram()
  local ok, err = write_bytes(path, data)
  if not ok then return nil, err end
  self.rom_data = self.rom_data or {}
  self.rom_data.save = data
  self.rom_data.save_path = path
  self.save_path = path
  return true, path
end

function Machine:saveState()
  local cart = self.cart
  local blobs = {
    rom_title = cart.title,
    cart_type = cart.cart_type,
    rom_path = self.rom_path,
    save_path = self.save_path,
    machine = {
      rom_loaded = self.rom_loaded,
      total_cycles = self.total_cycles,
    },
  }
  -- rom_data.bin: writable cartridge SRAM (battery flash), not the ROM image.
  if cart:has_save_ram() then
    blobs.rom_data = cart:export_ram()
  end
  if cart.mbc == 3 then
    local r = cart.rtc
    blobs.rtc = { s = r.s, m = r.m, h = r.h, dl = r.dl, dh = r.dh }
  end
  -- Also flush sidecar when NVRAM is written (Love/CC quit/switch).
  if self.save_path and cart:has_save_ram() then
    pcall(function() self:save_cart_save(self.save_path) end)
  end
  return SaveState.new(MACHINE_ID, blobs)
end

function Machine:loadState(state)
  local ok, err = SaveState.validate(state, MACHINE_ID)
  if not ok then return nil, err end
  local b = state.blobs or {}

  -- Do not apply another game's SRAM onto the current cart.
  if b.rom_title and b.rom_title ~= "" and self.cart.title ~= ""
      and b.rom_title ~= self.cart.title then
    return nil, "save is for different cart: " .. tostring(b.rom_title)
  end

  if type(b.rom_data) == "string" and self.cart:has_save_ram() then
    local iok, ierr = self.cart:import_ram(b.rom_data)
    if not iok then return nil, ierr end
    self.rom_data = self.rom_data or {}
    self.rom_data.save = b.rom_data
    self.rom_data.loaded = true
  end

  if type(b.rtc) == "table" and self.cart.rtc then
    local r = self.cart.rtc
    r.s = b.rtc.s or r.s
    r.m = b.rtc.m or r.m
    r.h = b.rtc.h or r.h
    r.dl = b.rtc.dl or r.dl
    r.dh = b.rtc.dh or r.dh
  end

  if b.save_path then self.save_path = b.save_path end
  if b.rom_path then self.rom_path = b.rom_path end
  if b.machine then
    self.total_cycles = b.machine.total_cycles or self.total_cycles
  end
  return true
end

function Machine:reset()
  self.wram:clear()
  self.irq:reset()
  self.timer:reset()
  self.joypad:reset()
  self.ppu:reset()
  self.apu:reset()
  self.cart:reset_banks()
  self.cpu:reset()
  self.total_cycles = 0
  if self.use_boot_rom and self.mmu.boot_rom then
    self.mmu.boot_enabled = true
  else
    self.mmu.boot_enabled = false
    self.cpu:power_on_dmg()
    -- Post-boot I/O defaults
    self.ppu.lcdc = 0x91
    self.ppu.stat = 0x85
    self.ppu.bgp = 0xFC
    self.timer.div = 0xAB00
    -- NR52 power on (post-boot); games reprogram the rest.
    self.apu:write(0xFF26, 0x80)
  end
  self.ppu._dirty = true
end

function Machine:run_cycles(budget)
  if not self.rom_loaded then
    return 0
  end
  local cpu = self.cpu
  local timer = self.timer
  local ppu = self.ppu
  local apu = self.apu
  local mmu = self.mmu
  local ran = 0
  local irq = self.irq
  -- Hardware is ticked inside cpu:step() via bus.tick (per M-cycle).
  while ran < budget do
    local cyc = cpu:step()
    ran = ran + cyc
    apu:flush()
    if cpu.halted and irq:pending() == 0 then
      -- Fast-forward HALT, but stop at mode boundaries so LYC/STAT can wake us.
      -- Use _line (true scanline); LY reads 0 mid-line-153 via the DMG quirk.
      local into = ppu.line_cycles
      local scan = ppu._line or ppu.ly
      local skip
      if scan == 153 and into < 4 then
        skip = 4 - into -- LY=153->0 quirk edge (LYC=0 often fires here)
      elseif scan >= 144 then
        skip = 456 - into
      elseif into < 80 then
        skip = 80 - into
      elseif into < 252 then
        skip = 252 - into
      else
        skip = 456 - into
      end
      if skip <= 0 then skip = 1 end
      local left = budget - ran
      if skip > left then skip = left end
      if skip > 0 then
        timer:tick(skip)
        ppu:tick(skip)
        apu:tick(skip)
        mmu:tick(skip)
        ran = ran + skip
        cpu.cycles = cpu.cycles + skip
      end
    end
  end
  self.total_cycles = self.total_cycles + ran
  return ran
end

function Machine:step_instruction()
  if not self.rom_loaded then return 0 end
  local cyc = self.cpu:step()
  self.apu:flush()
  self.total_cycles = self.total_cycles + cyc
  return cyc
end

function Machine:set_key(name, down)
  return self.joypad:set_key(name, down)
end

function Machine:framebuffer()
  return self.ppu:framebuffer()
end

function Machine:display_dirty()
  return self.ppu._dirty
end

function Machine:clear_display_dirty()
  self.ppu._dirty = false
end

function Machine:is_display_on()
  return self.ppu:lcd_on()
end

function Machine:pc()
  return self.cpu.pc
end

function Machine:cycles_per_frame(fps)
  fps = fps or 60
  -- 154 lines × 456 T-cycles
  return 154 * 456
end

return Machine
