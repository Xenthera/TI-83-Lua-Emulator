return function(ok)
  local ROOT = "."
  local out = "dist/_test_bundle.lua"
  os.execute("mkdir -p dist")
  local cmd = string.format(
    "lua tools/bundle.lua -o %s --root %s frontend.computercraft.api",
    out, ROOT
  )
  local ok_run = os.execute(cmd)
  ok("bundle command", ok_run == true or ok_run == 0)

  local chunk, err = loadfile(out)
  ok("bundle loadfile", chunk ~= nil, err)
  if not chunk then
    return
  end

  local api = chunk()
  ok("bundle returns api", type(api) == "table" and type(api.new_machine) == "function")
  ok("api has paint_lcd", type(api.paint_lcd) == "function")
  ok("api has KeypadView", type(api.KeypadView) == "table")
  ok("api has CC helpers", type(api.wrap_monitor) == "function" and type(api.CC) == "table")
  ok("CC.is_cc false on desktop", api.CC.is_cc() == false)

  local m = api.new_machine()
  ok("machine from bundle", m ~= nil and m.framebuffer ~= nil)

  local written = {}
  local function mock_mon(w, h)
    -- CC peripheral.wrap binds methods — called without self.
    return {
      getSize = function() return w, h end,
      setCursorPos = function(x, y) written.x, written.y = x, y end,
      blit = function(text, fg, bg)
        written.blits = (written.blits or 0) + 1
      end,
      setBackgroundColor = function() end,
      setTextColor = function() end,
      clear = function() written.cleared = true end,
      write = function(text) written.text = (written.text or "") .. tostring(text) end,
      setTextScale = function(s) written.scale = s end,
    }
  end

  local fb = {}
  for i = 0, 12 * 64 - 1 do
    fb[i] = 0
  end
  fb[0] = 0xFF

  written = {}
  local small = mock_mon(32, 16)
  api.setup_lcd(small)
  ok("setup sets scale 0.5", written.scale == 0.5)
  local ok_paint, lay = api.paint_lcd(small, fb, true)
  ok("small monitor rejected", ok_paint == false)
  ok("too-small message", type(written.text) == "string"
    and written.text:find("monitor too small", 1, true)
    and written.text:find("96x64", 1, true),
    tostring(written.text))

  written = {}
  local big = mock_mon(100, 70)
  local ok_big, lay2 = api.paint_lcd(big, fb, true)
  ok("large monitor accepted", ok_big == true)
  ok("centered x", lay2.x0 == 3, tostring(lay2 and lay2.x0)) -- floor((100-96)/2)+1 = 3
  ok("centered y", lay2.y0 == 4, tostring(lay2 and lay2.y0)) -- floor((70-64)/2)+1 = 4
  ok("painted full height", written.blits == 70)

  local pad = api.KeypadView.new(mock_mon(32, 16), { side = "right" })
  pad:draw()
  ok("keypad side stored", pad.side == "right")
  local key = pad:on_touch("right", 1, 1)
  ok("keypad on_touch", key == "yequ", tostring(key))
  ok("keypad ignores other side", pad:on_touch("left", 1, 1) == nil)
end
