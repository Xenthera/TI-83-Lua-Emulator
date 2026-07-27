return function(ok)
  local bit = require("core.util.bit")
  local band, bor = bit.band, bit.bor
  local Lcd = require("core.hw.lcd")
  local lcd = Lcd.new()

  lcd:command(0x03)
  ok("display on", lcd:is_display_on())

  -- 8-bit column auto-increment
  lcd:command(0x01)
  lcd:command(0x07)
  lcd:command(0x20)
  lcd:command(0x80)
  lcd:data_write(0xFF)
  lcd:data_write(0x81)
  ok("8bit fb write", lcd.fb[0] == 0xFF and lcd.fb[1] == 0x81)
  ok("8bit column advanced", lcd.x == 2)
  ok("dirty", lcd:dirty())

  -- 6-bit mode: column 0 occupies pixels 0-5
  lcd:reset()
  lcd:command(0x00) -- 6-bit
  lcd:command(0x05) -- row auto-inc
  lcd:command(0x20) -- col 0
  lcd:command(0x80) -- row 0
  lcd:data_write(0x3F) -- all 6 pixels on
  -- pixels 0-5 set => first byte 0xFC (bits 7..2)
  ok("6bit packs into byte0", lcd.fb[0] == 0xFC)
  ok("6bit row advanced", lcd.y == 1)

  lcd:command(0x21) -- col 1 -> pixels 6-11
  lcd:command(0x80)
  lcd:data_write(0x3F)
  -- pixel 6-7 in byte0, 8-11 in byte1
  ok("6bit col1 touches byte0+1", band(lcd.fb[0], 0x03) == 0x03 and band(lcd.fb[1], 0xF0) == 0xF0)

  lcd:command(0x40 + 5) -- Z scroll
  local fb = lcd:framebuffer()
  ok("visible fb is 12-wide", fb[0] ~= nil and fb[12 * 63 + 11] ~= nil)

  lcd:command(0x02)
  ok("display off", not lcd:is_display_on())

  lcd:command(0x01) -- 8-bit
  lcd:command(0x03)
  lcd:tick(100)
  local st = lcd:status()
  ok("status display+8bit", band(st, 0x60) == 0x60)

  -- T6A04 output latch: first read after set-address is dummy.
  lcd:reset()
  lcd:command(0x01)
  lcd:command(0x07) -- column auto-inc
  lcd:command(0x20)
  lcd:command(0x80)
  lcd:data_write(0xA5)
  lcd:data_write(0x5A)
  lcd:command(0x20) -- back to col 0
  lcd:command(0x80)
  local dummy = lcd:data_read()
  local first = lcd:data_read()
  local second = lcd:data_read()
  ok("dummy read is stale latch", dummy == 0)
  ok("first real read is col0", first == 0xA5)
  ok("second read is col1", second == 0x5A)
  -- dummy+2 reads each advance once -> column 3
  ok("pointer advanced after latch reads", lcd.x == 3)

  -- draw_pixel-style RMW: must dummy-read or OR clobbers sibling bits.
  lcd:reset()
  lcd:command(0x01) -- 8-bit
  lcd:command(0x05) -- row auto-inc (pipeline lcd_init default)
  lcd:command(0x03)
  lcd:command(0x20)
  lcd:command(0x80)
  lcd:data_write(0x80) -- pixel 0 set
  lcd:command(0x20)
  lcd:command(0x80)
  local _ = lcd:data_read() -- dummy
  local cur = lcd:data_read() -- real
  ok("rmw dummy+read sees existing bit", cur == 0x80)
  lcd:command(0x20)
  lcd:command(0x80)
  lcd:data_write(bor(cur, 0x40)) -- set pixel 1, keep pixel 0
  ok("rmw keeps sibling pixels", lcd.fb[0] == 0xC0)

  -- One read after set-address returns the latch, not the freshly written cell.
  lcd:command(0x20)
  lcd:command(0x80)
  lcd:data_write(0xFF)
  lcd:command(0x20)
  lcd:command(0x80)
  local stale = lcd:data_read()
  ok("single read after rewrite is latch not 0xFF", stale ~= 0xFF)
  local fresh = lcd:data_read()
  ok("second read after rewrite is 0xFF", fresh == 0xFF)
end
