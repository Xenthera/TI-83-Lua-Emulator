-- Love2D mini IDE: Tiny-C / ASM editors + LCD emulator.

local function project_root()
  local src = love.filesystem.getSource():gsub("\\", "/")
  local root = src:match("^(.*)/frontend/love2d/?$")
  if root then return root end
  return src .. "/../.."
end

local ROOT = project_root()
package.path = ROOT .. "/?.lua;" .. ROOT .. "/?/init.lua;" .. package.path

local Machine = require("core.machine")
local Render = require("frontend.love2d.render")
package.path = love.filesystem.getSource() .. "/?.lua;" .. package.path
local Input = require("input")
local Ide = require("ide")

local machine
local render
local ide
local force_present = true
local cycles_this_sec = 0
local sec_accum = 0
local cps = 0
local frame_count = 0
local fps = 0
local mono

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
  -- Bundled JetBrains Mono (OFL) - crisp monospace for the IDE.
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

function love.load()
  love.keyboard.setKeyRepeat(true)
  mono = make_ui_font()
  love.graphics.setFont(mono)
  love.graphics.setDefaultFilter("linear", "linear", 1)

  machine = Machine.new()
  render = Render.new()
  ide = Ide.new(ROOT)
  local dpi = love.window.getDPIScale and love.window.getDPIScale() or 1
  ide:log(string.format("IDE ready - HiDPI scale=%.1fx  (F5 Build / Boot OS)", dpi))

  -- Prefer real TI OS if a dump is present; otherwise Tiny-C pipeline demo.
  local os_rom = ROOT .. "/rom/ti83plus.rom"
  local f = io.open(os_rom, "rb")
  if f then
    local n = #f:read("*a")
    f:close()
    if n == 512 * 1024 then
      ide:boot_os(machine, mark_present)
      return
    end
  end
  ide.tab = "tc"
  ide:build(machine, mark_present)
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
end

function love.draw()
  love.graphics.clear(0.10, 0.11, 0.12, 1)
  love.graphics.setFont(mono)

  if force_present or machine:display_dirty() then
    render:present(machine:framebuffer(), machine:is_display_on() or not machine.rom_loaded)
    machine:clear_display_dirty()
    force_present = false
  end

  ide:draw()
  render:draw(ide:lcd_panel())

  -- Stats under the calculator face (column footer), never over keys/LCD.
  local cr = ide:calc_panel()
  if cr and cr.w > 0 then
    love.graphics.setColor(0.55, 0.6, 0.55, 1)
    local speed = (cps > 0) and (cps / Machine.CPU_HZ * 100) or 0
    local mode
    if not ide.running then
      mode = "PAUSE"
    elseif ide.gate_active then
      mode = string.format("GATE %d/s", ide.gate_hz)
    else
      mode = "6MHz"
    end
    love.graphics.print(string.format(
      "FPS %d  %.1f%%  PC=%04X  %s",
      fps, speed, machine.rom_loaded and machine:pc() or 0,
      mode
    ), cr.x + 8, cr.y + cr.h - 18)
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
  ide:textinput(t)
end

function love.keypressed(key)
  if ide:keypressed(key, machine, mark_present) then
    return
  end
  -- Keypad only when LCD focused
  if ide.focus == "lcd" then
    Input.apply(machine, key, true)
  end
end

function love.keyreleased(key)
  -- Always release: if focus left the LCD while a key was held, dropping the
  -- release left that matrix key stuck (breaks zDoom CLEAR's exact match).
  Input.apply(machine, key, false)
end

function love.wheelmoved(x, y)
  ide:wheelmoved(x, y)
end

function love.resize()
  force_present = true
end

function love.focus(focused)
  if not focused and machine then
    Input.release_all(machine)
  end
  -- Pick up Cursor/AI/external project edits when returning to the IDE.
  if focused and ide then
    ide:poll_project_disk()
  end
end
