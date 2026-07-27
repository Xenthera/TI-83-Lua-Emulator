-- Builtin native signatures + documentation for Tiny-C / IDE compendium.

local BUILTINS = {
  lcd_init = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Turn the LCD on and set auto-increment column mode.",
    detail = "Call once at startup before pixel drawing. Works in bare-metal and Flash Apps. "
      .. "Maps to T6A04 display-on + X auto-inc.",
    example = "lcd_init();",
  },
  lcd_clear = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Fill the 96x64 framebuffer with zeros (blank screen).",
    detail = "Does not turn the display off. Safe to call anytime after lcd_init(). "
      .. "Preferred over os_clr_lcd when using draw_pixel / stdlib/gfx.tc.",
    example = "lcd_clear();",
  },
  draw_string = {
    ret = "void",
    params = { "byte", "byte", "string" },
    param_names = { "col", "row", "str" },
    summary = "Draw a NUL-terminated string with the 8x8 monospace font.",
    detail = "col is a byte column 0..11 (8 pixels wide). row is a pixel row 0..56. "
      .. "Charset: space, 0-9, A-Z, and a few symbols (- . ! : /). Unknown glyphs become space.",
    example = 'draw_string(0, 0, "HI TI-83");',
  },
  draw_pixel = {
    ret = "void",
    params = { "byte", "byte" },
    param_names = { "x", "y" },
    summary = "Set one pixel on the 96x64 LCD (OR into the framebuffer byte).",
    detail = "x is 0..95, y is 0..63. Out-of-range coordinates are ignored. "
      .. "Works in bare-metal and Flash Apps (after lcd_init). "
      .. "Higher-level shapes live in stdlib/gfx.tc (#include <stdlib/gfx.tc>).",
    example = "draw_pixel(48, 32);",
  },
  clear_pixel = {
    ret = "void",
    params = { "byte", "byte" },
    param_names = { "x", "y" },
    summary = "Clear one pixel on the 96x64 LCD (AND with inverted mask).",
    detail = "x is 0..95, y is 0..63. Prefer erase_rect for areas — per-pixel clears are slow.",
    example = "clear_pixel(48, 32);",
  },
  erase_rect = {
    ret = "void",
    params = { "byte", "byte", "byte", "byte" },
    param_names = { "x", "y", "w", "h" },
    summary = "Fast-clear a rectangle by writing LCD bytes (masked on edges).",
    detail = "Much faster than looping clear_pixel. Full 8-pixel columns are a single "
      .. "zero write; partial edge columns do one read-modify-write. "
      .. "Native (stdlib/gfx.tc does not redefine it).",
    example = "erase_rect(10, 28, 80, 18);",
  },
  poke = {
    ret = "void",
    params = { "word", "byte" },
    param_names = { "addr", "val" },
    summary = "Write one byte to memory address addr.",
    detail = "RAM lives at 0x8000-0xFFFF (banked). Pipeline tests often use 0xC001 as a magic flag.",
    example = "poke(0xC001, 0xA5);",
  },
  peek = {
    ret = "byte",
    params = { "word" },
    param_names = { "addr" },
    summary = "Read one byte from memory address addr.",
    detail = "Return value is in A (byte). Useful for reading RAM you previously poked.",
    example = "byte v;\nv = peek(0xC001);",
  },
  halt = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Stop the CPU until the next interrupt (or forever if IRQs disabled).",
    detail = "Common pattern: while (1) { halt(); } for an idle loop after drawing.",
    example = "while (1) { halt(); }",
  },
  fmul = {
    ret = "word",
    params = { "word", "word" },
    param_names = { "a", "b" },
    summary = "Signed Q8.8 fixed-point multiply (a * b) with 8 fractional bits.",
    detail = "Interprets a and b as int16 with 8 fractional bits (1.0 = 256). "
      .. "Returns ((int32)a * (int32)b) >> 8 as a word. Use for Mandelbrot / soft float. "
      .. "Integer multiply is the * operator (low 16 bits).",
    example = "word p;\np = fmul(0x0180, 0x0200); // 1.5 * 2.0 = 3.0",
  },
  key_scan = {
    ret = "byte",
    params = {},
    param_names = {},
    summary = "Poll the keypad once; return a GetCSC-style scancode or 0.",
    detail = "Bare-metal read of port 01 (no TI-OS). Scancodes match WikiTI sk* values "
      .. "(enter=0x09, arrows 0x01-0x04, ...). Returns 0 if idle or multiple keys. "
      .. "See #include <stdlib/key.tc> for the full table.",
    example = "byte k;\nk = key_scan();\nif (k == 0x09) { /* enter */ }",
  },
  key_wait = {
    ret = "byte",
    params = {},
    param_names = {},
    summary = "Block until a key is pressed and released; return its scancode.",
    detail = "Busy-waits on key_scan(). Good for menus; for games prefer key_scan/key_down.",
    example = "byte k;\nk = key_wait();",
  },
  key_down = {
    ret = "byte",
    params = { "byte" },
    param_names = { "code" },
    summary = "Return 1 if scancode is currently held, else 0.",
    detail = "Use for held keys / multi-key (e.g. move while another key is down).",
    example = "if (key_down(0x03)) { /* right arrow held */ }",
  },
  in_port = {
    ret = "byte",
    params = { "byte" },
    param_names = { "port" },
    summary = "Read one byte from Z80 I/O port.",
    detail = "Maps to IN A,(n) when port is constant, else IN A,(C). Used by OS lifts.",
    example = "byte s;\ns = in_port(0x02);",
  },
  out_port = {
    ret = "void",
    params = { "byte", "byte" },
    param_names = { "port", "val" },
    summary = "Write one byte to Z80 I/O port.",
    detail = "Maps to OUT (n),A when port is constant, else OUT (C),A. Used by OS lifts.",
    example = "out_port(0x06, page);",
  },
  os_clr_lcd = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Flash App: clear the LCD via TI-OS ClrLCDFull.",
    detail = "Requires tiproj/compile target=app. Calls BCALL 0x4540.",
    example = "os_clr_lcd();",
  },
  os_home_up = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Flash App: move cursor to top-left (HomeUp).",
    detail = "Requires target=app. BCALL 0x4558.",
    example = "os_home_up();",
  },
  os_newline = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Flash App: advance to the next text row (NewLine).",
    detail = "Requires target=app. BCALL 0x452E.",
    example = "os_newline();",
  },
  os_put_str = {
    ret = "void",
    params = { "string" },
    param_names = { "str" },
    summary = "Flash App: print a NUL-terminated string (PutS).",
    detail = "Requires target=app. HL = NUL-terminated string (Flash OK; uses PutC loop, not PutS).",
    example = 'os_put_str("HELLO");',
  },
  os_get_key = {
    ret = "byte",
    params = {},
    param_names = {},
    summary = "Flash App: block for a key via TI-OS GetKey.",
    detail = "Requires target=app. Returns OS keycode in A (BCALL 0x4972).",
    example = "byte k;\nk = os_get_key();",
  },
  os_exit = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Flash App: return to the TI-OS homescreen (never returns).",
    detail = "Requires target=app. BCALL JForceCmdNoChar (0x4027). main() calls this automatically if it falls off the end.",
    example = "os_exit();",
  },
  entropy = {
    ret = "word",
    params = {},
    param_names = {},
    summary = "Return seed material for a PRNG (not wall-clock time).",
    detail = "The TI-83+ has no RTC — GetTime exists only on TI-84+. This mixes the Z80 R "
      .. "register, SP, and a short IRQ-skewed spin. Use with #include <stdlib/rand.tc>: "
      .. "srand(entropy()); or srand_auto();",
    example = "srand(entropy());",
  },
}

-- Stable display order for the compendium
local ORDER = {
  "lcd_init", "lcd_clear", "draw_string", "draw_pixel", "clear_pixel", "erase_rect",
  "key_scan", "key_wait", "key_down",
  "os_clr_lcd", "os_home_up", "os_newline", "os_put_str", "os_get_key", "os_exit",
  "poke", "peek", "in_port", "out_port", "fmul", "halt", "entropy",
}

local LANG_NOTES = {
  {
    title = "Types",
    body = "void, byte (u8), word (u16). Locals and globals supported.",
  },
  {
    title = "Functions",
    body = "Declare with an explicit return type: void/byte/word name(params) { ... }. "
      .. "return; for void, return expr; for byte/word. "
      .. "Calling convention matches the Z80: byte results in A, word in HL, call/ret. "
      .. "No floats or other types the CPU does not have.",
  },
  {
    title = "Control flow",
    body = "if / else, while, for (init;cond;step), break, continue, { } blocks, return.",
  },
  {
    title = "Arrays",
    body = "byte a[N]; / word w[N];  index with a[i]; pass arrays as word base (decay). "
      .. "Params: byte p[] decays to word address. No pointers beyond this.",
  },
  {
    title = "Expressions",
    body = "+ - * / % << >> & | ^   and comparisons == != < > <= >=. "
      .. "byte ops stay 8-bit; mix with word or use * / % / shifts to promote. "
      .. "fmul(a,b) is signed Q8.8 fixed-point multiply.",
  },
  {
    title = "Display",
    body = "96x64 mono LCD. Text cells are 8x8 -> 12 columns, 8 text rows.",
  },
  {
    title = "Keypad",
    body = "Your program owns the ASIC: key_scan/key_wait/key_down read port 01 directly "
      .. "(same scancodes as TI-OS GetCSC). #include <stdlib/key.tc> for the code table. "
      .. "There is no OS GetKey - you are the firmware.",
  },
  {
    title = "Includes",
    body = '#include "file.tc" (project-relative) or #include <stdlib/gfx.tc>. '
      .. "Projects are folders of .tc files (+ project.tiproj manifest).",
  },
  {
    title = "OS lift",
    body = "in_port/out_port for ASIC I/O. "
      .. "extern void name(); declares an asm label to call. "
      .. "Trailing osabi uses TI-OS register ABI (byte arg in A). "
      .. "Optional saveaf after osabi preserves AF (e.g. lcd_busy_wait).",
  },
  {
    title = "Flash Apps",
    body = 'Compile with target=app (tiproj or --app) to emit a .8xk. '
      .. "Use os_* for TI-OS text/keys, or lcd_init/draw_pixel/clear_pixel "
      .. "(and #include <stdlib/gfx.tc>) for pixel UI. "
      .. "LCD helpers insert real-hardware busy delays and DI around RMW "
      .. "(the emu is instant; a real T6A04 is not). "
      .. "key_scan/key_wait/key_down stay bare-metal only — use os_get_key. "
      .. "No TI-84+ clock APIs — seed PRNGs with entropy() / stdlib/rand.tc. "
      .. "Programs larger than 16KB are auto-split across archive pages "
      .. "(up to 14 x 16KB = 224KB) with far-call bank switching. "
      .. "For a real calculator, leave Sign on (tiproj sign:true / --sign); "
      .. "builds use RabbitSign with free key 0104. Run tools/install_rabbitsign.sh once.",
  },
}

-- Soft library documented in Stdlib tab (not CPU natives).
local GFX_LIB = {
  {
    name = "draw_hline",
    ret = "void",
    params = { "byte", "byte", "byte" },
    param_names = { "x0", "x1", "y" },
    summary = "Horizontal line from x0 to x1 at row y (inclusive).",
    example = "draw_hline(0, 95, 32);",
  },
  {
    name = "draw_vline",
    ret = "void",
    params = { "byte", "byte", "byte" },
    param_names = { "x", "y0", "y1" },
    summary = "Vertical line from y0 to y1 at column x (inclusive).",
    example = "draw_vline(48, 0, 63);",
  },
  {
    name = "draw_line",
    ret = "void",
    params = { "byte", "byte", "byte", "byte" },
    param_names = { "x0", "y0", "x1", "y1" },
    summary = "Bresenham line between two points (screen coords).",
    example = "draw_line(0, 0, 95, 63);",
  },
  {
    name = "draw_rect",
    ret = "void",
    params = { "byte", "byte", "byte", "byte" },
    param_names = { "x", "y", "w", "h" },
    summary = "Axis-aligned rectangle outline (w/h in pixels).",
    example = "draw_rect(8, 8, 80, 48);",
  },
  {
    name = "fill_rect",
    ret = "void",
    params = { "byte", "byte", "byte", "byte" },
    param_names = { "x", "y", "w", "h" },
    summary = "Filled axis-aligned rectangle (sets pixels on).",
    example = "fill_rect(40, 24, 16, 16);",
  },
  {
    name = "erase_rect",
    ret = "void",
    params = { "byte", "byte", "byte", "byte" },
    param_names = { "x", "y", "w", "h" },
    summary = "Fast-clear a rectangle (native byte-oriented LCD clear).",
    example = "erase_rect(10, 10, 14, 18);",
  },
}

local M = {}

function M.is_native(name)
  return BUILTINS[name] ~= nil
end

function M.get(name)
  return BUILTINS[name]
end

function M.list()
  local out = {}
  for _, name in ipairs(ORDER) do
    local b = BUILTINS[name]
    out[#out + 1] = { name = name, info = b }
  end
  return out
end

function M.signature(name)
  local b = BUILTINS[name]
  if not b then return nil end
  local args = {}
  for i, t in ipairs(b.params) do
    local n = b.param_names[i] or ("a" .. i)
    args[#args + 1] = t .. " " .. n
  end
  return string.format("%s %s(%s)", b.ret, name, table.concat(args, ", "))
end

local function fmt_sig(info)
  local args = {}
  for i, t in ipairs(info.params) do
    args[#args + 1] = t .. " " .. (info.param_names[i] or ("a" .. i))
  end
  return string.format("%s %s(%s)", info.ret, info.name, table.concat(args, ", "))
end

function M.lang_notes()
  return LANG_NOTES
end

function M.gfx_lib()
  local out = {}
  for _, info in ipairs(GFX_LIB) do
    out[#out + 1] = { name = info.name, info = info, signature = fmt_sig(info) }
  end
  return out
end

return M
