# TI-83 Plus Emulator (Lua)

Pure-Lua TI-83 Plus emulator with a modular display backend. The first frontend is [LOVE](https://love2d.org/) (Love2D); the `core/` package has no engine dependencies so rendering can be ported later.

## Layout

- `core/` - Z80, MMU/flash/RAM, ASIC ports, T6A04 LCD, keypad, timer, `Machine` API
- `asm/` - simple Z80 assembler, 8x8 font, host text reference, LCD/text libs, screen tests
- `frontend/love2d/` - Love2D window, nearest-neighbor LCD present, keyboard -> key matrix
- `frontend/computercraft/` - monitor LCD + second-monitor keypad API (bundleable)
- `rom/` - generated test images + optional real 512KB TI dump (not shipped)
- `tests/` - unit tests (no Love2D required)
- `tools/` - bring-up, pipeline build/verify, `bundle.lua` / `export_computercraft.lua`
- `dist/` - generated single-file exports (optional build output)

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
love frontend/love2d
```

The frontend is a small IDE:

- **Open / Save** - project folders (`projects/shapes/*.tc`); Ctrl+O / Ctrl+S
- **Tiny-C file tabs** - edit on-disk sources; `#include` pulls in siblings / stdlib
- **ASM / Stdlib tabs** - generated assembly and native docs
- **Build (F5)** - compile TC->ASM (or assemble ASM), load ROM, reset, play
- **Play / Pause (F6)** - run or freeze the emulator
- **LCD panel** - click it to send keypad keys; click the editor to type code

Console at the bottom shows build errors and status.

## Tests

```bash
lua tests/run_tests.lua          # unit tests + full pipeline
```

## Machine API

```lua
local Machine = require("core.machine")
local m = Machine.new()
m:load_rom_file("rom/pipeline.rom")
m:reset()
m:run_cycles(m:cycles_per_frame(60))
local fb = m:framebuffer() -- 96x64, 12 bytes/row, MSB leftmost
```

## ComputerCraft export (single-file bundle)

The modular tree under `core/` and `frontend/computercraft/` stays the source of truth.
A build step flattens it into one Lua file via `package.preload` (same `require` names):

```bash
lua tools/export_computercraft.lua
# -> dist/ti83_cc.lua  (+ dist/ti83_run.lua launcher)
```

Or bundle any entry module:

```bash
lua tools/bundle.lua -o dist/core_only.lua core.machine
```

### Wiring monitors

Copy `dist/ti83_cc.lua` (and optionally `ti83_run.lua`) plus a 512KB ROM onto a CC computer. Attach **two advanced monitors** (LCD + keypad).

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

`frontend/love2d/` is not included in the CC bundle (no Love dependency).

## Real TI ROM (legal)

Supply a dump from a calculator you own: **524288 bytes** at `rom/ti83plus.rom`. Not redistributed here.
