-- Nintendo Entertainment System (NTSC) machine facade.

local Cart = require("machines.nes.mem.cart")
local Ppu = require("machines.nes.hw.ppu")
local Apu = require("machines.nes.hw.apu")
local Joypad = require("machines.nes.hw.joypad")
local CPU = require("cpus.mos6502.mos6502")
local Protocol = require("framework.machine")
local Path = require("framework.path")
local bit = require("framework.util.bit")
local band = bit.band

local CPU_HZ = 1789773
local MACHINE_ID = "nes"

local Machine = {}
Machine.__index = Machine
Machine.CPU_HZ = CPU_HZ
Machine.MACHINE_ID = MACHINE_ID

local function has_fs()
  return type(fs) == "table" and type(fs.open) == "function"
end

local function read_bytes(path)
  if has_fs() then
    local h = fs.open(path, "rb") or fs.open(path, "r")
    if not h then return nil, "cannot open " .. tostring(path) end
    local data = h.readAll and h.readAll() or h.read("*a")
    h.close()
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
    local h = fs.open(path, "wb") or fs.open(path, "w")
    if not h then return nil, "cannot write" end
    pcall(function() h.write(data) end)
    h.close()
    return true
  end
  local parent = tostring(path):match("^(.*)[/\\][^/\\]+$")
  if parent and parent ~= "" then Path.ensure_dir(parent) end
  local f, err = io.open(path, "wb")
  if not f then return nil, err end
  f:write(data)
  f:close()
  return true
end

function Machine.save_path_for(rom_path, opts)
  opts = opts or {}
  if opts.save_path and opts.save_path ~= "" then return opts.save_path end
  if not rom_path or rom_path == "" then return nil end
  local name = tostring(rom_path)
  local base = name:gsub("%.[nN][eE][sS]$", "")
  local sav_name = (base:match("([^/\\]+)$") or base) .. ".sav"
  if opts.save_dir and opts.save_dir ~= "" and not name:find("[/\\]") then
    return tostring(opts.save_dir):gsub("[/\\]+$", "") .. "/" .. sav_name
  end
  if name:find("[/\\]") then
    local dir = name:match("^(.*)[/\\][^/\\]+$") or "."
    return dir .. "/" .. sav_name
  end
  return sav_name
end

function Machine.new(opts)
  opts = opts or {}
  local self = setmetatable({}, Machine)
  self.cart = Cart.new()
  self.joypad = Joypad.new()
  local apu_opts = opts.apu or {}
  if type(opts.apu_synth) == "string" then
    apu_opts = { synth = opts.apu_synth }
  end
  self.apu = Apu.new(apu_opts)
  self.ram = {}
  for i = 0, 0x7FF do self.ram[i] = 0 end

  self.ppu = Ppu.new(self.cart, nil)
  self.lcd = self.ppu

  local ram, cart, ppu, apu, joy = self.ram, self.cart, self.ppu, self.apu, self.joypad
  self.cpu_open_bus = 0

  -- Catch-up timing: accumulate CPU cycles, flush PPU before MMIO / IRQ poll.
  local ppu_owed = 0
  local function ppu_flush()
    local n = ppu_owed
    if n ~= 0 then
      ppu_owed = 0
      ppu:tick(n)
      apu:owe(n)
    end
  end
  self._ppu_flush = ppu_flush

  local function cpu_read(addr)
    addr = band(addr, 0xFFFF)
    if addr >= 0x2000 and addr < 0x4018 then
      ppu_flush()
    end
    local v
    if addr < 0x2000 then
      v = ram[band(addr, 0x7FF)] or 0
    elseif addr < 0x4000 then
      v = ppu:read_reg(addr)
    elseif addr == 0x4015 then
      v = apu:read(addr)
    elseif addr == 0x4016 then
      v = joy:read(1)
    elseif addr == 0x4017 then
      v = joy:read(2)
    elseif addr < 0x4018 then
      -- Most APU regs are write-only -> CPU open bus
      v = apu:read(addr)
      if v == nil then v = self.cpu_open_bus end
    elseif addr < 0x6000 then
      -- Unmapped I/O $4018-$5FFF: open bus
      v = self.cpu_open_bus
    else
      v = cart:cpu_read(addr)
    end
    self.cpu_open_bus = band(v, 0xFF)
    return self.cpu_open_bus
  end

  local function cpu_write(addr, v)
    addr = band(addr, 0xFFFF)
    v = band(v, 0xFF)
    if addr >= 0x2000 and addr < 0x4018 then
      ppu_flush()
    end
    self.cpu_open_bus = v
    if addr < 0x2000 then
      ram[band(addr, 0x7FF)] = v
    elseif addr < 0x4000 then
      ppu:write_reg(addr, v)
    elseif addr == 0x4014 then -- OAM DMA
      ppu:oam_dma_write(v, cpu_read)
      if self.cpu then self.cpu:oam_dma_stall() end
    elseif addr == 0x4016 then
      joy:write(v)
    elseif addr < 0x4018 then
      apu:write(addr, v)
    elseif addr >= 0x4020 then
      -- Expansion / mapper regs ($4020-$5FFF) and cart space ($6000+)
      cart:cpu_write(addr, v)
    end
  end

  self.cpu = CPU.new({
    read = cpu_read,
    write = cpu_write,
    tick = function(c)
      ppu_owed = ppu_owed + c
    end,
    flush = ppu_flush,
  })
  ppu:set_cpu(self.cpu)
  cart:set_cpu(self.cpu)
  apu:set_cpu(self.cpu)

  self.rom_loaded = false
  self.rom_path = nil
  self.save_path = nil
  self.rom_data = {}
  self.total_cycles = 0
  Protocol.apply(self)
  return self
end

function Machine:load_rom_bytes(bytes, opts)
  opts = opts or {}
  if self.rom_loaded and self.cart:has_save_ram() and not opts.skip_flush then
    self:save_cart_save()
  end
  local ok, err = self.cart:load(bytes)
  if not ok then return nil, err end
  self.rom_loaded = true
  self.rom_path = opts.path
  self.save_path = Machine.save_path_for(opts.path, opts)
  self.rom_data = {
    save_path = self.save_path,
    rom_path = self.rom_path,
    title = self.cart.title,
    mapper = self.cart.mapper,
  }
  if not opts.skip_save and self.cart:has_save_ram() and self.save_path then
    if self:load_cart_save(self.save_path) then
      self.rom_data.loaded = true
    end
  end
  return true
end

function Machine:load_rom_file(path, opts)
  opts = opts or {}
  local data, err = read_bytes(path)
  if not data then return nil, err end
  opts.path = opts.path or path
  return self:load_rom_bytes(data, opts)
end

function Machine:load_cart_save(path)
  path = path or self.save_path
  if not path or not self.cart:has_save_ram() then return nil, "no save" end
  local data, err = read_bytes(path)
  if not data then return nil, err end
  return self.cart:import_ram(data)
end

function Machine:save_cart_save(path)
  path = path or self.save_path
  if not path or not self.cart:has_save_ram() then return nil, "no save" end
  return write_bytes(path, self.cart:export_ram())
end

function Machine:reset()
  for i = 0, 0x7FF do self.ram[i] = 0 end
  self.cart:reset_banks()
  self.ppu:reset()
  self.apu:reset()
  self.joypad:reset()
  self.cpu:power_on()
  self.total_cycles = 0
  self.ppu._dirty = true
end

function Machine:run_cycles(budget)
  if not self.rom_loaded then return 0 end
  local cpu, apu = self.cpu, self.apu
  local ran = 0
  while ran < budget do
    ran = ran + cpu:step()
  end
  self._ppu_flush()
  apu:flush()
  self.total_cycles = self.total_cycles + ran
  return ran
end

function Machine:step_instruction()
  if not self.rom_loaded then return 0 end
  local cyc = self.cpu:step()
  self._ppu_flush()
  self.apu:flush()
  self.total_cycles = self.total_cycles + cyc
  return cyc
end

function Machine:set_key(name, down)
  -- Optional pad2_ prefix for controller 2
  local pad = 1
  local n = name
  if type(name) == "string" and name:sub(1, 5) == "pad2_" then
    pad = 2
    n = name:sub(6)
  end
  return self.joypad:set_key(n, down, pad)
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
  return true
end

function Machine:pc()
  return self.cpu.pc
end

function Machine:cycles_per_frame()
  -- NTSC: 262 lines * 341 PPU dots / 3 ≈ 29780.5
  return 29781
end

return Machine
