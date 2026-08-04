-- Love2D mini IDE: Tiny-C / ASM editors + multi-machine LCD emulator.

local function file_exists(path)
  local f = io.open(path, "rb")
  if not f then return false end
  f:close()
  return true
end

local function boot_log(msg)
  local base = love.filesystem.getSourceBaseDirectory()
  if not base or base == "" then return end
  local path = base:gsub("\\", "/") .. "/boot.log"
  local f = io.open(path, "a")
  if not f then return end
  f:write(os.date("!%Y-%m-%dT%H:%M:%SZ "), tostring(msg), "\n")
  f:close()
end

--- Project ROOT: packaged host dir (+ macOS .app walk-up), else repo via frontends/love2d.
local function project_root()
  local base = love.filesystem.getSourceBaseDirectory()
  boot_log("getSourceBaseDirectory=" .. tostring(base))
  boot_log("getSource=" .. tostring(love.filesystem.getSource()))
  if base and base ~= "" then
    base = base:gsub("\\", "/")
    -- Fused exe / .love beside sidecar: machines/ next to host.
    if file_exists(base .. "/machines") or file_exists(base .. "/framework/manager.lua") then
      boot_log("ROOT=base (sidecar present)")
      return base
    end
    -- macOS .app: getSourceBaseDirectory is often .../RetroStudio.app/Contents/Resources
    local app = base:match("^(.*%.app)/Contents/")
    if app then
      local parent = app:match("^(.*)/[^/]+%.app$")
      if parent and (file_exists(parent .. "/machines")
          or file_exists(parent .. "/framework/manager.lua")) then
        boot_log("ROOT=macos app parent")
        return parent
      end
    end
  end

  local src = love.filesystem.getSource():gsub("\\", "/")
  -- Dev: source is the frontends/love2d folder.
  local root = src:match("^(.*)/frontends/love2d/?$")
  if root and file_exists(root .. "/machines") then
    boot_log("ROOT=dev frontends/love2d parent")
    return root
  end
  -- Packaged .love only (no fused path): base dir of the archive.
  if base and base ~= "" and not src:match("%.love$") then
    local up = (base .. "/../.."):gsub("\\", "/")
    if file_exists(up .. "/machines") then
      boot_log("ROOT=up2")
      return up
    end
  end
  if base and file_exists(base .. "/machines") then
    boot_log("ROOT=base machines")
    return base
  end
  boot_log("ROOT=fallback")
  return root or (src .. "/../..")
end

local ROOT = project_root()
boot_log("resolved ROOT=" .. tostring(ROOT))
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

-- Match tools/bench_gb.lua / bench_nes.lua: give LuaJIT more trace room for cores.
if jit and jit.opt then
  jit.opt.start("maxtrace=8000", "maxrecord=16000", "minstitch=3", "maxmcode=40960")
end

local function must_require(name)
  local ok, mod = pcall(require, name)
  if not ok then
    boot_log("REQUIRE FAILED " .. name .. ": " .. tostring(mod))
    error(mod)
  end
  return mod
end

local Manager = must_require("framework.manager")
Manager.ensure_discovered(ROOT)

local Debugger = must_require("framework.debugger")
local NVRAM = must_require("framework.nvram")
local Machine83 = must_require("machines.ti83plus.machine")
-- Frontend modules live inside the Love source / .love (short names).
package.path = love.filesystem.getSource() .. "/?.lua;"
  .. ROOT .. "/frontends/love2d/?.lua;" .. package.path
local Render83 = must_require("render")
local Render84 = must_require("render_ti84")
local Render89 = must_require("render_ti89")
local Render92 = must_require("render_ti92")
local RenderRV64 = must_require("render_riscv64")
local RenderGB = must_require("render_gameboy")
local RenderNES = must_require("render_nes")
local Input = must_require("input")
local Input89 = must_require("input_ti89")
local Input92 = must_require("input_ti92")
local InputGB = must_require("input_gameboy")
local InputNES = must_require("input_nes")
local AudioGB = must_require("audio_gameboy")
local AudioNES = must_require("audio_nes")
local Ide = must_require("ide")
local Launcher = must_require("launcher")
boot_log("requires ok")

local manager
local machine
local render
local debugger
local save_slot
local show_debug = false
local machine_ids = {}
local machine_idx = 1
local ide
local launcher
local screen_mode = "launcher" -- "launcher" | "ide"
local force_present = true
local cycles_this_sec = 0
local sec_accum = 0
local cps = 0
local frame_count = 0
local fps = 0
local mono
local gb_audio
local nes_audio

--- Human-readable clock rate for the status strip (measured or target).
local function fmt_hz(hz)
  hz = tonumber(hz) or 0
  if hz >= 1e6 then
    return string.format("%.2f MHz", hz / 1e6)
  end
  if hz >= 1e3 then
    return string.format("%.1f kHz", hz / 1e3)
  end
  return string.format("%.0f Hz", hz)
end

local TITLES = {
  ti83plus = "Retro Emulator Studio - TI-83 Plus",
  ti84plus = "Retro Emulator Studio - TI-84 Plus",
  ti89 = "Retro Emulator Studio - TI-89 Titanium",
  ti92plus = "Retro Emulator Studio - TI-92 Plus",
  riscv64 = "Retro Emulator Studio - RV64 Custom",
  gameboy = "Retro Emulator Studio - Game Boy",
  nes = "Retro Emulator Studio - NES",
}

local function mark_present()
  force_present = true
end

local function load_font_file(path, size)
  local ok, font = pcall(love.graphics.newFont, path, size)
  if ok and font then return font end
  return nil
end

local function load_font_abs(abs_path, size)
  local f = io.open(abs_path, "rb")
  if not f then return nil end
  local data = f:read("*a")
  f:close()
  if not data or #data < 100 then return nil end
  local ok_fd, fd = pcall(love.filesystem.newFileData, data, "ui.ttf")
  if not ok_fd or not fd then return nil end
  local ok, font = pcall(love.graphics.newFont, fd, size)
  if ok and font then return font end
  return nil
end

local function make_ui_font()
  local size = 14
  local font = load_font_file("assets/fonts/JetBrainsMono-Regular.ttf", size)
  if not font then
    local candidates = {
      "/System/Library/Fonts/SFNSMono.ttf",
      "/System/Library/Fonts/Menlo.ttc",
      "/System/Library/Fonts/Supplemental/Andale Mono.ttf",
      "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf",
      "/usr/share/fonts/truetype/liberation/LiberationMono-Regular.ttf",
      "C:/Windows/Fonts/consola.ttf",
      "C:/Windows/Fonts/cascadiamono.ttf",
    }
    for _, path in ipairs(candidates) do
      font = load_font_abs(path, size)
      if font then break end
    end
  end
  if not font then
    font = love.graphics.newFont(size)
  end
  font:setFilter("linear", "linear")
  return font
end

local function try_boot_machine(id)
  if id == "ti83plus" then
    local os_rom = ROOT .. "/rom/ti83plus.rom"
    local f = io.open(os_rom, "rb")
    if f then
      local n = #f:read("*a")
      f:close()
      if n == 512 * 1024 then
        ide:boot_os(machine, mark_present)
        return true
      end
    end
    return false
  end

  if id == "ti84plus" then
    for _, name in ipairs({ "ti84plus.rom", "ti84p.rom", "ti84.rom" }) do
      local path = ROOT .. "/rom/" .. name
      local f = io.open(path, "rb")
      if f then
        local n = #f:read("*a")
        f:close()
        if n == 1024 * 1024 then
          local ok, err = machine:load_rom_file(path)
          if ok then
            -- Cold boot parks at $0C99 (EI; HALT soft power-off). Wake like TI-83+.
            machine:reset()
            ide.running = true
            ide.focus = "lcd"
            local nz = ide:_wake_os(machine)
            ide:log(string.format(
              "TI-84 Plus OS up (%s)  PC=%04X  fb_nz=%d",
              name, machine:pc(), nz or 0
            ))
            mark_present()
            return true
          end
          ide:log("TI-84+ ROM load failed: " .. tostring(err))
        else
          ide:log(string.format("TI-84+ ROM %s is %d bytes (need 1MB)", name, n))
        end
      end
    end
    ide:log("TI-84 Plus ready (no ROM in rom/). Place ti84plus.rom / ti84p.rom (1MB)")
    return false
  end

  if id == "ti92plus" then
    for _, name in ipairs({ "ti92plus.rom", "ti92p.rom", "ti92.rom" }) do
      local path = ROOT .. "/rom/" .. name
      local f = io.open(path, "rb")
      if f then
        f:close()
        local ok, err = machine:load_rom_file(path)
        if ok then
          machine:reset()
          ide.running = true
          local meta = machine.rom_meta
          if meta and meta.format == "tifl_os" then
            ide:log(string.format(
              "TI-92+ AMS from TIFL (%s): PC=$%06X SSP=$%06X (%dKB)",
              tostring(meta.name or "?"), meta.pc or 0, meta.ssp or 0,
              math.floor((meta.size or 0) / 1024)
            ))
          else
            ide:log("TI-92 Plus ROM loaded: " .. name)
          end
          mark_present()
          return true
        end
        ide:log("TI-92+ ROM load failed: " .. tostring(err))
      end
    end
    ide:log("TI-92 Plus ready (no ROM in rom/). Use Load ROM or place ti92plus.rom / .9xu")
    return false
  end

  if id == "gameboy" then
    local gb_dir = ROOT .. "/rom/gb/"
    -- Prefer commercial/named carts; leave gameboy_test.gb as last resort.
    local prefer = {
      "tetris.gb", "testris.gb", "gameboy.gb", "dmg.gb",
    }
    local function try_gb(path, name)
      local f = io.open(path, "rb")
      if not f then return false end
      f:close()
      local ok, err = machine:load_rom_file(path)
      if ok then
        machine:reset()
        ide.running = true
        ide.focus = "lcd"
        local title = machine.cart.title
        local sav = ""
        if machine.rom_data and machine.rom_data.loaded and machine.save_path then
          sav = "  + " .. tostring(machine.save_path)
        end
        ide:log("Game Boy cart: " .. name .. (title ~= "" and (" (" .. title .. ")") or "") .. sav)
        mark_present()
        return true
      end
      ide:log("Game Boy load failed: " .. tostring(err))
      return false
    end
    for _, name in ipairs(prefer) do
      if try_gb(gb_dir .. name, name) then return true end
    end
    -- Any other .gb in rom/gb/ (skip *_test.gb until end)
    local sep = package.config:sub(1, 1)
    local dir = ROOT .. sep .. "rom" .. sep .. "gb"
    local p = io.popen('dir /b "' .. dir .. '\\*.gb" 2>nul')
    if not p then
      p = io.popen('ls -1 "' .. dir .. '"/*.gb 2>/dev/null')
    end
    local fallback
    if p then
      local listing = p:read("*a") or ""
      p:close()
      for name in listing:gmatch("[^\r\n]+") do
        name = name:match("([^/\\]+)$") or name
        local low = name:lower()
        if low:match("%.gb$") then
          if low:match("test") then
            fallback = fallback or name
          elseif try_gb(gb_dir .. name, name) then
            return true
          end
        end
      end
    end
    if fallback and try_gb(gb_dir .. fallback, fallback) then
      return true
    end
    ide.running = false
    ide:log("Game Boy ready - place a .gb cart in rom/gb/ (e.g. rom/gb/tetris.gb)")
    mark_present()
    return false
  end

  if id == "nes" then
    local nes_dir = ROOT .. "/rom/nes/"
    local function try_nes(path, name)
      local f = io.open(path, "rb")
      if not f then return false end
      f:close()
      local ok, err = machine:load_rom_file(path)
      if ok then
        machine:reset()
        ide.running = true
        ide.focus = "lcd"
        local mapper = machine.cart and machine.cart.mapper
        ide:log("NES cart: " .. name .. (mapper and (" (mapper " .. mapper .. ")") or ""))
        mark_present()
        return true
      end
      ide:log("NES load failed: " .. tostring(err))
      return false
    end
    -- Prefer known smoke carts; avoid alphabetically-first timing torture carts.
    local prefer = {
      "smb.nes", "mario.nes", "nestest.nes", "super_mario_bros.nes",
    }
    for _, name in ipairs(prefer) do
      if try_nes(nes_dir .. name, name) then return true end
    end
    local sep = package.config:sub(1, 1)
    local dir = ROOT .. sep .. "rom" .. sep .. "nes"
    local p = io.popen('dir /b "' .. dir .. '\\*.nes" 2>nul')
    if not p then
      p = io.popen('ls -1 "' .. dir .. '"/*.nes 2>/dev/null')
    end
    local fallback
    if p then
      local listing = p:read("*a") or ""
      p:close()
      for name in listing:gmatch("[^\r\n]+") do
        name = name:match("([^/\\]+)$") or name
        local low = name:lower()
        if low:match("%.nes$") then
          -- Defer known timing-sensitive carts unless nothing else is present.
          if low:find("battletoads", 1, true) or low:find("nestest", 1, true) then
            fallback = fallback or name
          elseif try_nes(nes_dir .. name, name) then
            return true
          end
        end
      end
    end
    if fallback and try_nes(nes_dir .. fallback, fallback) then
      return true
    end
    ide.running = false
    ide:log("NES ready - place a .nes cart in rom/nes/")
    mark_present()
    return false
  end

  if id == "riscv64" then
    local dir = ROOT .. "/rom/riscv64/"
    -- 1) OpenSBI + Image + DTB (standard fw_jump layout)
    do
      local fw_path
      for _, name in ipairs({ "fw_jump.bin", "opensbi.bin", "fw_payload.bin" }) do
        local f = io.open(dir .. name, "rb")
        if f then f:close(); fw_path = dir .. name; break end
      end
      local img_path = dir .. "Image"
      local fi = io.open(img_path, "rb")
      if fw_path and fi then
        local kernel = fi:read("*a")
        fi:close()
        local dtb
        local fd = io.open(dir .. "board.dtb", "rb")
        if fd then dtb = fd:read("*a"); fd:close() end
        local ok, err = machine:boot_opensbi({
          fw_path = fw_path,
          kernel_bytes = kernel,
          dtb_bytes = dtb,
        })
        if ok then
          ide.running = true
          ide.focus = "lcd"
          ide:log("RV64 OpenSBI boot: " .. fw_path:match("[^/\\]+$") .. " + Image")
          mark_present()
          return true
        end
        ide:log("RV64 OpenSBI boot failed: " .. tostring(err))
      elseif fi then
        fi:close()
      end
    end
    -- 2) Kernel-only (Lua SBI shim) - early bring-up without OpenSBI binary
    do
      local img_path = dir .. "Image"
      local fi = io.open(img_path, "rb")
      if fi then
        local kernel = fi:read("*a")
        fi:close()
        local dtb
        local fd = io.open(dir .. "board.dtb", "rb")
        if fd then dtb = fd:read("*a"); fd:close() end
        local ok, err = machine:boot_linux({
          kernel_bytes = kernel,
          dtb_bytes = dtb,
          entry = 0x80200000,
          dtb_addr = 0x82000000,
        })
        if ok then
          ide.running = true
          ide.focus = "lcd"
          ide:log("RV64 Image boot (Lua SBI, S-mode) - add fw_jump.bin for OpenSBI")
          mark_present()
          return true
        end
        ide:log("RV64 Image boot failed: " .. tostring(err))
      end
    end
    -- 3) Interactive console demo firmware
    for _, name in ipairs({ "riscv64.bin", "firmware.bin", "rv64.bin" }) do
      local path = ROOT .. "/rom/" .. name
      local f = io.open(path, "rb")
      if f then
        f:close()
        local ok, err = machine:load_rom_file(path)
        if ok then
          ide.running = true
          ide.focus = "lcd"
          ide:log("RV64 console firmware: " .. name .. " - focus LCD and type")
          mark_present()
          return true
        end
        ide:log("RV64 firmware load failed: " .. tostring(err))
      end
    end
    machine:reset()
    ide.running = false
    ide:log("RV64 ready - rom/riscv64/{fw_jump.bin,Image,board.dtb} or rom/riscv64.bin")
    mark_present()
    return false
  end

  -- TI-89 Titanium: raw 2/4MB dumps or TIFL .89u OS upgrades (extracted on load).
  for _, name in ipairs({ "ti89titanium.rom", "ti89.rom", "ti89hw2.rom" }) do
    local path = ROOT .. "/rom/" .. name
    local f = io.open(path, "rb")
    if f then
      f:close()
      local ok, err = machine:load_rom_file(path)
      if ok then
        machine:reset()
        ide.running = true
        local meta = machine.rom_meta
        if meta and meta.format == "tifl_os" then
          ide:log(string.format(
            "TI-89 Titanium AMS from TIFL (%s): PC=$%06X SSP=$%06X (%dKB)",
            tostring(meta.name or "?"), meta.pc or 0, meta.ssp or 0,
            math.floor((meta.size or 0) / 1024)
          ))
        else
          ide:log("TI-89 Titanium ROM loaded: " .. name)
        end
        mark_present()
        return true
      end
      ide:log("TI-89 Titanium ROM load failed: " .. tostring(err))
    end
  end
  ide:log("TI-89 Titanium ready (no ROM in rom/). Use Load ROM or place ti89titanium.rom")
  return false
end

local function persist_machine(m, reason)
  if not m then return end
  -- Game Boy: flush cartridge SRAM sidecar (.sav) via saveState / save_cart_save.
  if m.save_cart_save and m.cart and m.cart.has_save_ram and m.cart:has_save_ram() then
    local cok, cpath = m:save_cart_save()
    if ide then
      if cok then
        ide:log(string.format("Cart save (%s) -> %s", reason or "quit", tostring(cpath or m.save_path)))
      elseif cpath then
        ide:log("Cart save failed: " .. tostring(cpath))
      end
    end
  end
  local ok, err = NVRAM.save(ROOT, m)
  if ide then
    if ok then
      ide:log(string.format("Battery saved (%s) -> saves/%s/", reason or "nvram", m.MACHINE_ID or "?"))
    else
      ide:log("Battery save failed: " .. tostring(err))
    end
  end
end

local function restore_battery(m)
  if not m or not NVRAM.exists(ROOT, m.MACHINE_ID) then
    return false
  end
  local ok, err = NVRAM.load(ROOT, m)
  if ok then
    if ide then
      ide:log("Restored battery memory for " .. tostring(m.MACHINE_ID))
      ide.running = true
      ide.focus = "lcd"
    end
    mark_present()
    return true
  end
  if ide then
    ide:log("Battery restore failed: " .. tostring(err))
  end
  return false
end

local function attach_machine(id)
  -- Keep the outgoing calc's flash/RAM like a battery between sessions/switches.
  if machine and manager and manager.current_id and manager.current_id ~= id then
    persist_machine(machine, "switch")
  end

  local m, err = manager:select(id)
  if not m then
    if ide then ide:log("machine: " .. tostring(err)) end
    return
  end
  machine = m
  debugger = Debugger.new(machine)
  save_slot = nil
  for i, mid in ipairs(machine_ids) do
    if mid == id then machine_idx = i break end
  end

  if ide then
    ide:set_machine_ui(id)
  end

  if id == "ti89" then
    render = Render89.new()
  elseif id == "ti92plus" then
    render = Render92.new()
  elseif id == "ti84plus" then
    render = Render84.new()
  elseif id == "riscv64" then
    render = RenderRV64.new()
  elseif id == "gameboy" then
    render = RenderGB.new()
    if nes_audio then nes_audio:stop() end
    if not gb_audio then
      gb_audio = AudioGB.new()
      if ide and gb_audio._ok then
        ide:log("Game Boy audio: Love2D queueable source @ 32768 Hz")
      elseif ide then
        ide:log("Game Boy audio: unavailable (love.audio.newQueueableSource failed)")
      end
    end
  elseif id == "nes" then
    render = RenderNES.new()
    if gb_audio then gb_audio:stop() end
    if not nes_audio then
      nes_audio = AudioNES.new()
      if ide and nes_audio._ok then
        ide:log("NES audio: Love2D queueable source @ 48000 Hz")
      elseif ide then
        ide:log("NES audio: unavailable (love.audio.newQueueableSource failed)")
      end
    end
  else
    render = Render83.new()
    if gb_audio then gb_audio:stop() end
    if nes_audio then nes_audio:stop() end
  end

  force_present = true
  love.window.setTitle(TITLES[id] or ("Retro Emulator Studio - " .. id))
  if ide then
    ide:log("Selected machine: " .. id)
    -- Stock ROM first (if present), then overlay battery-backed state.
    try_boot_machine(id)
    restore_battery(machine)
  end
end

local function enter_launcher()
  screen_mode = "launcher"
  if ide then ide.running = false end
  if gb_audio then gb_audio:stop() end
  if nes_audio then nes_audio:stop() end
  if launcher then launcher:refresh() end
  love.window.setTitle("Retro Emulator Studio")
end

local function enter_machine(id)
  screen_mode = "ide"
  attach_machine(id)
  if machine and not machine.rom_loaded and ide and ide:tinyc_supported(id) then
    ide.tab = "tc"
    ide:build(machine, mark_present)
  end
end

function love.load()
  boot_log("love.load start")
  local ok, err = xpcall(function()
    love.keyboard.setKeyRepeat(true)
    mono = make_ui_font()
    love.graphics.setFont(mono)
    love.graphics.setDefaultFilter("linear", "linear", 1)

    manager = Manager.new()
    machine_ids = Manager.list()
    boot_log("machines=" .. table.concat(machine_ids, ","))
    ide = Ide.new(ROOT)
    ide.on_select_machine = attach_machine
    ide.on_home = enter_launcher
    launcher = Launcher.new(ROOT, Manager)

    local dpi = love.window.getDPIScale and love.window.getDPIScale() or 1
    ide:log(string.format("Retro Emulator Studio ready - HiDPI scale=%.1fx  ROOT=%s", dpi, ROOT))
    ide:log("Discovered machines: " .. table.concat(machine_ids, ", "))
    ide:log("Launcher: pick a machine  ·  Esc=home  ·  F7=save  Shift+F7=load  Ctrl+F8=debugger")
    ide:log("Battery memory: auto-saves to saves/<machine>/ on quit or machine switch")
    enter_launcher()
    boot_log("love.load ok mode=launcher")
  end, debug.traceback)
  if not ok then
    boot_log("love.load FAILED: " .. tostring(err))
    error(err)
  end
end

function love.quit()
  if gb_audio then gb_audio:stop() end
  if nes_audio then nes_audio:stop() end
  persist_machine(machine, "quit")
end

function love.update(dt)
  if screen_mode == "launcher" then
    return
  end
  if not ide or not machine then return end
  ide:update(dt, machine)
  frame_count = frame_count + 1
  sec_accum = sec_accum + dt
  if sec_accum >= 1 then
    fps = frame_count
    cps = cycles_this_sec
    frame_count = 0
    cycles_this_sec = 0
    sec_accum = sec_accum - 1
  end

  local ran = ide:run_emu(dt, machine, mark_present)
  cycles_this_sec = cycles_this_sec + ran

  local want_mute = not ide.running or not machine.rom_loaded
  if gb_audio and machine and machine.MACHINE_ID == "gameboy" then
    if gb_audio.muted ~= want_mute then
      gb_audio:set_muted(want_mute)
    end
    gb_audio:update(machine)
  end
  if nes_audio and machine and machine.MACHINE_ID == "nes" then
    if nes_audio.muted ~= want_mute then
      nes_audio:set_muted(want_mute)
    end
    nes_audio:update(machine)
  end
end

function love.draw()
  love.graphics.setFont(mono)
  if screen_mode == "launcher" then
    if launcher then launcher:draw() end
    return
  end

  love.graphics.clear(0.10, 0.11, 0.12, 1)
  if not machine then return end

  if force_present or machine:display_dirty() then
    if render then
      render:present(machine:framebuffer(), machine:is_display_on() or not machine.rom_loaded)
    end
    machine:clear_display_dirty()
    force_present = false
  end

  ide:draw()
  if ide.panel_editor then
    return
  end
  if render then
    render:draw(ide:lcd_panel())
  end

  local cr = ide:calc_panel()
  if cr and cr.w > 0 then
    love.graphics.setColor(0.55, 0.6, 0.55, 1)
    local target_hz = machine._cpu_hz or machine.CPU_HZ or Machine83.CPU_HZ
    local speed = (target_hz > 0 and cps > 0) and (cps / target_hz * 100) or 0
    local mode
    if not ide.running then
      mode = "PAUSE"
    elseif ide.gate_active then
      mode = string.format("GATE %d/s", ide.gate_hz)
    else
      mode = manager.current_id or "?"
    end
    -- Measured guest clock (cycles last second) + % of that machine's target Hz.
    love.graphics.print(string.format(
      "FPS %d  %s (%.1f%% of %s)  PC=%X  %s",
      fps, fmt_hz(cps), speed, fmt_hz(target_hz),
      machine.rom_loaded and machine:pc() or 0,
      mode
    ), cr.x + 8, cr.y + cr.h - 18)
  end

  if show_debug and debugger then
    local regs = debugger:registers()
    love.graphics.setColor(0, 0, 0, 0.7)
    love.graphics.rectangle("fill", 8, 8, 420, 160)
    love.graphics.setColor(0.8, 0.95, 0.8, 1)
    love.graphics.print(debugger:disassemble_at(machine:pc()), 16, 16)
    local y = 36
    if regs.d then
      for i = 0, 7 do
        love.graphics.print(string.format("D%d=%08X", i, regs.d[i] or 0), 16 + (i % 4) * 100, y + math.floor(i / 4) * 16)
      end
      y = y + 40
      for i = 0, 7 do
        love.graphics.print(string.format("A%d=%08X", i, regs.a and regs.a[i] or 0), 16 + (i % 4) * 100, y + math.floor(i / 4) * 16)
      end
    else
      love.graphics.print(string.format("PC=%04X AF=%04X BC=%04X DE=%04X HL=%04X",
        regs.pc or 0, regs.af or 0, regs.bc or 0, regs.de or 0, regs.hl or 0), 16, y)
    end
  end
end

function love.mousepressed(x, y, button)
  if button ~= 1 then return end
  if screen_mode == "launcher" then
    local id = launcher and launcher:mousepressed(x, y)
    if id then enter_machine(id) end
    return
  end
  ide:mousepressed(x, y, machine, mark_present)
end

function love.mousemoved(x, y)
  if screen_mode == "launcher" then
    if launcher then launcher:mousemoved(x, y) end
    return
  end
  ide:mousemoved(x, y, machine)
end

function love.mousereleased(x, y, button)
  if screen_mode == "launcher" then return end
  if button == 1 then
    ide:mousereleased(machine)
  end
end

function love.textinput(t)
  if screen_mode == "launcher" then return end
  if ide.focus == "lcd" and manager and manager.current_id == "riscv64" and machine then
    for i = 1, #t do
      machine:set_key(t:sub(i, i), true)
    end
    force_present = true
  end
  ide:textinput(t)
end

function love.keypressed(key)
  if screen_mode == "launcher" then
    local id = launcher and launcher:keypressed(key)
    if id then enter_machine(id) end
    return
  end
  if key == "escape" and ide and not ide.panel_editor then
    enter_launcher()
    return
  end
  if key == "f6" and love.keyboard.isDown("lctrl", "rctrl") then
    -- Ctrl+F6 still cycles machines; plain F6 stays Play (IDE).
    machine_ids = Manager.list()
    if #machine_ids == 0 then return end
    machine_idx = machine_idx % #machine_ids + 1
    attach_machine(machine_ids[machine_idx])
    return
  end
  if key == "f7" then
    if not machine then return end
    if love.keyboard.isDown("lshift", "rshift") then
      if save_slot then
        local ok, err = machine:loadState(save_slot)
        ide:log(ok and "State loaded" or ("Load failed: " .. tostring(err)))
        force_present = true
      else
        ide:log("No save slot")
      end
    else
      if machine.saveState then
        save_slot = machine:saveState()
        ide:log("State saved")
      end
    end
    return
  end
  if key == "f8" and love.keyboard.isDown("lctrl", "rctrl") then
    show_debug = not show_debug
    return
  end
  -- F9: toggle NES APU render (classic hardware mix vs modern HQ PolyBLEP).
  if key == "f9" and machine and machine.MACHINE_ID == "nes" and machine.apu
      and machine.apu.set_synth then
    local next = (machine.apu.synth == "hq") and "classic" or "hq"
    machine.apu:set_synth(next)
    if ide then ide:log("NES APU synth: " .. next) end
    return
  end
  if ide:keypressed(key, machine, mark_present) then
    return
  end
  if ide.focus == "lcd" then
    local mid = manager.current_id
    if mid == "riscv64" then
      -- printable chars arrive via love.textinput -> UART RX
    elseif mid == "gameboy" then
      InputGB.apply(machine, key, true)
    elseif mid == "nes" then
      InputNES.apply(machine, key, true)
    elseif mid == "ti83plus" or mid == "ti84plus" then
      Input.apply(machine, key, true)
    elseif mid == "ti92plus" then
      local ti = Input92.to_ti_key(key)
      if ti then machine:keyDown(ti) end
    else
      local ti = Input89.to_ti_key(key)
      if ti then machine:keyDown(ti) end
    end
  end
end

function love.keyreleased(key)
  if screen_mode == "launcher" or not machine then return end
  local mid = manager.current_id
  if mid == "riscv64" then
    return
  elseif mid == "gameboy" then
    InputGB.apply(machine, key, false)
  elseif mid == "nes" then
    InputNES.apply(machine, key, false)
  elseif mid == "ti83plus" or mid == "ti84plus" then
    Input.apply(machine, key, false)
  elseif mid == "ti92plus" then
    local ti = Input92.to_ti_key(key)
    if ti then machine:keyUp(ti) end
  else
    local ti = Input89.to_ti_key(key)
    if ti then machine:keyUp(ti) end
  end
end

function love.wheelmoved(x, y)
  if screen_mode == "launcher" then
    if launcher then launcher:wheelmoved(x, y) end
    return
  end
  ide:wheelmoved(x, y)
end

function love.resize(w, h)
  if launcher then launcher:layout(w, h) end
  if ide then
    ide:layout(w, h)
  end
  force_present = true
end

function love.focus(focused)
  if not focused and machine then
    if manager.current_id == "ti83plus" then
      Input.release_all(machine)
    end
  end
  if focused and ide then
    ide:poll_project_disk()
  end
end
