-- Builtin native signatures + documentation for Tiny-C / IDE compendium.

local BUILTINS = {
  lcd_init = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Turn the LCD on and set auto-increment column mode.",
    detail = "Call once at startup before drawing. Maps to T6A04 display-on + X auto-inc.",
    example = "lcd_init();",
  },
  lcd_clear = {
    ret = "void",
    params = {},
    param_names = {},
    summary = "Fill the 96x64 framebuffer with zeros (blank screen).",
    detail = "Does not turn the display off. Safe to call anytime after lcd_init().",
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
      .. "Higher-level shapes live in stdlib/gfx.tc (#include <stdlib/gfx.tc>).",
    example = "draw_pixel(48, 32);",
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
      .. "(enter=0x09, arrows 0x01-0x04, …). Returns 0 if idle or multiple keys. "
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
}

-- Stable display order for the compendium
local ORDER = {
  "lcd_init", "lcd_clear", "draw_string", "draw_pixel",
  "key_scan", "key_wait", "key_down",
  "poke", "peek", "fmul", "halt",
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
    body = "if / else, while, { } blocks, return.",
  },
  {
    title = "Expressions",
    body = "+ - * << >> & | ^   and comparisons == != < > <= >=. "
      .. "byte ops stay 8-bit; mix with word or use * / shifts to promote. "
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
      .. "There is no OS GetKey — you are the firmware.",
  },
  {
    title = "Includes",
    body = '#include "file.tc" (project-relative) or #include <stdlib/gfx.tc>. '
      .. "Projects are folders of .tc files (+ project.tiproj manifest).",
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
    summary = "Filled axis-aligned rectangle.",
    example = "fill_rect(40, 24, 16, 16);",
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
