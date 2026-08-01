-- Love2D mini IDE: Tiny-C / ASM editors + multi-machine LCD emulator.

local function project_root()
  local src = love.filesystem.getSource():gsub("\\", "/")
  local root = src:match("^(.*)/frontends/love2d/?$")
  if root then return root end
  return src .. "/../.."
end

local ROOT = project_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Manager = require("framework.manager")
local Debugger = require("framework.debugger")
local NVRAM = require("framework.nvram")
local Machine83 = require("machines.ti83plus.machine")
local Render83 = require("frontends.love2d.render")
local Render84 = require("frontends.love2d.render_ti84")
local Render89 = require("frontends.love2d.render_ti89")
local Render92 = require("frontends.love2d.render_ti92")
local RenderRV64 = require("frontends.love2d.render_riscv64")
local RenderGB = require("frontends.love2d.render_gameboy")
package.path = love.filesystem.getSource() .. "/?.lua;"
  .. ROOT .. "/frontends/love2d/?.lua;" .. package.path
local Input = require("input")
local Input89 = require("input_ti89")
local Input92 = require("input_ti92")
local InputGB = require("input_gameboy")
local AudioGB = require("audio_gameboy")
local Ide = require("ide")

local manager
local machine
local render
local debugger
local save_slot
local show_debug = false
local machine_ids = { "ti83plus", "ti84plus", "ti89", "ti92plus", "riscv64", "gameboy" }
local machine_idx = 1
local ide
local force_present = true
local cycles_this_sec = 0
local sec_accum = 0
local cps = 0
local frame_count = 0
local fps = 0
local mono
local gb_audio

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
    ide:log("Game Boy ready — place a .gb cart in rom/gb/ (e.g. rom/gb/tetris.gb)")
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
    -- 2) Kernel-only (Lua SBI shim) — early bring-up without OpenSBI binary
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
          ide:log("RV64 Image boot (Lua SBI, S-mode) — add fw_jump.bin for OpenSBI")
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
          ide:log("RV64 console firmware: " .. name .. " — focus LCD and type")
          mark_present()
          return true
        end
        ide:log("RV64 firmware load failed: " .. tostring(err))
      end
    end
    machine:reset()
    ide.running = false
    ide:log("RV64 ready — rom/riscv64/{fw_jump.bin,Image,board.dtb} or rom/riscv64.bin")
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
        ide:log(string.format("Cart save (%s) → %s", reason or "quit", tostring(cpath or m.save_path)))
      elseif cpath then
        ide:log("Cart save failed: " .. tostring(cpath))
      end
    end
  end
  local ok, err = NVRAM.save(ROOT, m)
  if ide then
    if ok then
      ide:log(string.format("Battery saved (%s) → saves/%s/", reason or "nvram", m.MACHINE_ID or "?"))
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
    if not gb_audio then
      gb_audio = AudioGB.new()
      if ide and gb_audio._ok then
        ide:log("Game Boy audio: Love2D queueable source @ 32768 Hz")
      elseif ide then
        ide:log("Game Boy audio: unavailable (love.audio.newQueueableSource failed)")
      end
    end
  else
    render = Render83.new()
    if gb_audio then
      gb_audio:stop()
    end
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

function love.load()
  love.keyboard.setKeyRepeat(true)
  mono = make_ui_font()
  love.graphics.setFont(mono)
  love.graphics.setDefaultFilter("linear", "linear", 1)

  manager = Manager.new()
  ide = Ide.new(ROOT)
  ide.on_select_machine = attach_machine
  attach_machine("ti83plus")
  local dpi = love.window.getDPIScale and love.window.getDPIScale() or 1
  ide:log(string.format("Retro Emulator Studio ready - HiDPI scale=%.1fx", dpi))
  ide:log("Machine: toolbar TI-83+ / TI-89 / TI-92+   F7=save  Shift+F7=load  F8=debugger")
  ide:log("Battery memory: auto-saves to saves/<machine>/ on quit or machine switch")

  if not machine.rom_loaded then
    ide.tab = "tc"
    ide:build(machine, mark_present)
  end
end

function love.quit()
  if gb_audio then gb_audio:stop() end
  persist_machine(machine, "quit")
end

function love.update(dt)
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

  if gb_audio and machine and machine.MACHINE_ID == "gameboy" then
    local want_mute = not ide.running or not machine.rom_loaded
    if gb_audio.muted ~= want_mute then
      gb_audio:set_muted(want_mute)
    end
    gb_audio:update(machine)
  end
end

function love.draw()
  love.graphics.clear(0.10, 0.11, 0.12, 1)
  love.graphics.setFont(mono)

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
  ide:mousepressed(x, y, machine, mark_present)
end

function love.mousemoved(x, y)
  ide:mousemoved(x, y, machine)
end

function love.mousereleased(x, y, button)
  if button == 1 then
    ide:mousereleased(machine)
  end
end

function love.textinput(t)
  if ide.focus == "lcd" and manager and manager.current_id == "riscv64" and machine then
    for i = 1, #t do
      machine:set_key(t:sub(i, i), true)
    end
    force_present = true
  end
  ide:textinput(t)
end

function love.keypressed(key)
  if key == "f6" and love.keyboard.isDown("lctrl", "rctrl") then
    -- Ctrl+F6 still cycles machines; plain F6 stays Play (IDE).
    machine_idx = machine_idx % #machine_ids + 1
    attach_machine(machine_ids[machine_idx])
    return
  end
  if key == "f7" then
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
  if ide:keypressed(key, machine, mark_present) then
    return
  end
  if ide.focus == "lcd" then
    local mid = manager.current_id
    if mid == "riscv64" then
      -- printable chars arrive via love.textinput → UART RX
    elseif mid == "gameboy" then
      InputGB.apply(machine, key, true)
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
  local mid = manager.current_id
  if mid == "riscv64" then
    return
  elseif mid == "gameboy" then
    InputGB.apply(machine, key, false)
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
  ide:wheelmoved(x, y)
end

function love.resize(w, h)
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
