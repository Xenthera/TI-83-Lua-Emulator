# TI Calculator Emulators (Lua)

Pure-Lua TI-83 Plus / TI-84 Plus / TI-89 Titanium / TI-92 Plus emulators with modular frontends ([LOVE](https://love2d.org/), ComputerCraft). Machine code lives under `machines/` / `cpus/` with no engine dependencies.

## Layout

- `machines/` - TI-83+, TI-84+, TI-89, TI-92+ machine packages (MMU, LCD, keypad, ROM helpers)
- `cpus/` - Z80 and m68k CPU cores
- `framework/` - shared path helpers, bit util, machine manager, savestate, debugger
- `frontends/love2d/` - Love2D mini IDE + LCD presenters
- `frontends/computercraft/` - CC advanced-monitor / GPU / WebSocket clients
- `bridge/` - LuaJIT WebSocket host (remote emu for CC thin clients)
- `asm/`, `lang/`, `stdlib/`, `projects/` - assembler, Tiny-C, demos
- `rom/` - local ROM dumps (not shipped)
- `tests/`, `tools/`, `dist/` - tests, export/pipeline scripts, generated bundles

## Tiny-C (`tc`) -> Z80

Minimal C-like language that compiles to our assembler and can call native LCD/text helpers:

```c
void main() {
  lcd_init();
  lcd_clear();
  draw_string(0, 0, "HI TI-83");
  poke(0xC001, 0xA5);
  while (1) { halt(); }
}
```

```bash
lua tools/tc_compile.lua examples/hello.tc   # -> asm/generated/hello.asm
lua tools/pipeline_test.lua                  # compile + assemble + emulate + verify
```

Natives: `lcd_init`, `lcd_clear`, `draw_string(col,row,str)`, `draw_pixel(x,y)`, `poke`, `peek`, `halt`.  
Types: `void` / `byte` / `word`. Control: `if`/`else`, `while`, functions. Font: 8x8 monospace.

Includes: `#include "file.tc"` (project) or `#include <stdlib/gfx.tc>` (repo stdlib).  
Graphics helpers in `stdlib/gfx.tc`: `draw_hline`, `draw_vline`, `draw_line`, `draw_rect`, `fill_rect`.

Projects are folders of real `.tc` files plus a thin `project.tiproj` manifest (demo: `projects/shapes/`). Packed single-file `.tiproj` still opens and unpacks. Build reloads sources from disk so external/AI edits apply.

## Pipeline (no TI ROM required)

Compiles [`examples/hello.tc`](examples/hello.tc), packs a 512KB flash image, runs it, and checks the LCD against a host-side reference blit:

```bash
lua tools/pipeline_test.lua
lua tools/build_pipeline_rom.lua   # build only
```

Runtime libs: `asm/lib/lcd.asm`, `asm/lib/text.asm`, `asm/lib/gfx.asm`, `asm/font8.lua`.
## Run (Love2D mini IDE)

```bash
love frontends/love2d
```

Startup shows a **pixel launcher** that scans `machines/*/machine.lua` (and catalogs `cpus/`). Pick a machine to open the IDE; **Esc** or **Home** returns to the launcher. Place `rom/ti84plus.rom` (1MB) for 84+, or `rom/ti92plus.rom` / `.9xu` for 92+; Game Boy / NES carts under `rom/gb/` and `rom/nes/`.

The frontend is a small IDE:

- **Open / Save** - project folders (`projects/shapes/*.tc`); Ctrl+O / Ctrl+S
- **Tiny-C file tabs** - edit on-disk sources; `#include` pulls in siblings / stdlib
- **ASM / Stdlib tabs** - generated assembly and native docs
- **Build (F5)** - compile TC->ASM (or assemble ASM), load ROM, reset, play
- **Play / Pause (F6)** - run or freeze the emulator
- **LCD panel** - click it to send keypad keys; click the editor to type code

Console at the bottom shows build errors and status.

## Portable packages (Love2D)

One command builds a runnable folder: fused/wrapped Love host **plus** mirrored sidecar trees (`machines/`, `cpus/`, `framework/`, `ui/`, `lang/`, `asm/`, `stdlib/`, `projects/`, `rom/`, `saves/`) next to the host. No hand-built layout.

**Windows**

```bat
tools\package_love.cmd
```

Output: `dist/windows/RetroStudio/` — run `RetroStudio.exe`.

**Linux / macOS**

```bash
./tools/package_love.sh          # auto-detect
./tools/package_love.sh linux
./tools/package_love.sh macos
```

Outputs: `dist/linux/RetroStudio/run.sh` or `dist/macos/RetroStudio/RetroStudio.app` (sidecar dirs sit beside the `.app`).

Love 11.5 runtimes download once into `tools/love/` (gitignored). Drop a new machine under repo `machines/<id>/` (with `machine.lua`) and re-run the packager, or copy it into the staged `machines/` folder for a local test.

## Tests

```bash
lua tests/run_tests.lua          # unit tests + full pipeline
```

## Machine API

```lua
local Machine = require("machines.ti83plus.machine")
local m = Machine.new()
m:load_rom_file("rom/pipeline.rom")
m:reset()
m:run_cycles(m:cycles_per_frame(60))
local fb = m:framebuffer() -- 96x64, 12 bytes/row, MSB leftmost
```

## ComputerCraft export (single-file bundle)

The modular tree under `machines/`, `cpus/`, and `frontends/computercraft/` is the source of truth.
A build step flattens it into one Lua file via `package.preload` (same `require` names):

```bash
lua tools/export_computercraft.lua
# -> dist/ti83_cc.lua  (+ dist/test.lua copy)

lua tools/export_computercraft_ti89.lua
# -> dist/ti89_cc.lua
```

Or bundle any entry module:

```bash
lua tools/bundle.lua - o dist/machine_only.lua machines.ti83plus.machine
```

### Wiring monitors (TI-83+)

Copy `dist/ti83_cc.lua` (or `dist/test.lua`) plus a 512KB ROM onto a CC computer. Attach **two advanced monitors** (LCD + keypad).

```lua
local ti83 = dofile("ti83_cc.lua")

-- Wraps peripherals, pulls monitor_touch / timer / terminate:
ti83.run({
  lcd = "left",            -- peripheral side (or omit to auto-find)
  pad = "right",
  rom = "ti83plus.rom",
  fps = 30,
})

-- Or wire peripherals yourself:
local lcd = peripheral.wrap("left")
local pad_mon = peripheral.wrap("right")
assert(peripheral.getType("left") == "monitor")

local m = ti83.new_machine()
m:load_rom_bytes(assert(ti83.read_rom_file("ti83plus.rom")))
m:reset()

ti83.setup_lcd(lcd)
local pad = ti83.KeypadView.new(pad_mon)  -- stores side via peripheral.getName
pad:draw()

while true do
  local timer = os.startTimer(1 / 30)
  while true do
    local ev, a, b, c = os.pullEventRaw()
    if ev == "timer" and a == timer then break
    elseif ev == "monitor_touch" then
      local key = pad:on_touch(a, b, c)
      if key then m:set_key(key, true) end
    elseif ev == "terminate" then return
    end
  end
  ti83.run_frame(m, 30)
  m:set_key("enter", false)  -- example release; host auto-taps
  ti83.present(m, lcd)
end
```

`frontends/love2d/` is not included in the CC bundle (no Love dependency).

### Remote emu (LuaJIT + WebSocket)

Emulation can run on the PC; CC only paints and sends keys. Existing in-CC
bundles are unchanged.

```bat
REM 1) PC host (LuaJIT FFI sockets - no LuaSocket install needed)
bridge\run.cmd --machine ti89 --rom rom\ti89titanium.rom --port 8765

REM 2) Export thin clients
tools\export_computercraft_ti89_gpu_ws.cmd
tools\export_computercraft_ti89_ws.cmd
tools\export_computercraft_ti83_ws.cmd
```

| Dist | Role |
|------|------|
| `ti89_gpu_cc_ws.lua` | Tom's GPU face, remote CPU |
| `ti89_cc_ws.lua` | Advanced monitors, remote CPU |
| `ti83_cc_ws.lua` | Advanced monitors, remote CPU |

```
ti89_gpu_cc_ws --url ws://127.0.0.1:8765
```

### TI-89 Titanium on ComputerCraft

```bash
lua tools/export_computercraft_ti89.lua
# -> dist/ti89_cc.lua
```

Copy `dist/ti89_cc.lua` plus `ti89.rom` / `ti89titanium.rom` onto a CC computer. LCD needs about **80×34** cells at text scale 0.5 (2×3 sixtels; same pixels as 160×100, ~⅓ the old monitor wall). `.8xk` / `.8xp` install is TI-83+ only.

```lua
local ti89 = dofile("ti89_cc.lua")
ti89.run({
  rom = "ti89titanium.rom",  -- or ti89.rom
  lcd = "left",
  pad = "right",
})
```

## Real TI ROM (legal)

Supply a dump from a calculator you own. TI-83+: **524288 bytes** at `rom/ti83plus.rom`. TI-89: AMS / TIFL OS image at `rom/ti89.rom` (or `ti89titanium.rom`). Not redistributed here.
