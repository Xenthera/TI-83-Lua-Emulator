return function(ok)
  local ROOT = "."
  local out = "dist/_test_bundle.lua"
  require("framework.path").ensure_dir("dist")
  local cmd = string.format(
    "lua tools/bundle.lua - o %s --root %s frontends.computercraft.api",
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
    return {
      getSize = function() return w, h end,
      setCursorPos = function(x, y) written.x, written.y = x, y end,
      blit = function(text, fg, bg)
        written.blits = (written.blits or 0) + 1
        written.last_bg = bg
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
  local ok_paint = api.paint_lcd(small, fb, true)
  ok("small monitor rejected", ok_paint == false)
  ok("too-small message", type(written.text) == "string"
    and written.text:find("monitor too small", 1, true)
    and written.text:find("48x22", 1, true),
    tostring(written.text))

  written = {}
  local big = mock_mon(100, 70)
  local painter = api.new_lcd_painter(big, {})
  local lay = painter:setup()
  ok("painter layout ok", lay.ok == true)
  written.blits = 0
  local ok_big, lay2, n = painter:paint(fb, true)
  ok("large monitor accepted", ok_big == true)
  -- NEED 48x22 centered in 100x70 -> x0=27, y0=25
  ok("centered x", lay2.x0 == 27, tostring(lay2 and lay2.x0))
  ok("centered y", lay2.y0 == 25, tostring(lay2 and lay2.y0))
  ok("first paint blits 22 sixtel rows", n == 22 and written.blits == 22,
    tostring(n) .. "/" .. tostring(written.blits))

  written.blits = 0
  local _, _, n2 = painter:paint(fb, true)
  ok("unchanged frame skips blits", n2 == 0 and written.blits == 0, tostring(n2))

  fb[0] = 0x0F
  written.blits = 0
  local _, _, n3 = painter:paint(fb, true)
  ok("dirty row blits once", n3 == 1 and written.blits == 1, tostring(n3))

  local pad = api.KeypadView.new(mock_mon(32, 16), { side = "right" })
  pad:draw()
  ok("keypad side stored", pad.side == "right")
  -- Y= key occupies columns starting at x0>=2 on a 32x16 layout (gutter).
  local yequ = pad.buttons[1]
  local hx = yequ and yequ.x0 or 2
  local hy = yequ and yequ.y0 or 1
  local key = pad:on_touch("right", hx, hy)
  ok("keypad on_touch", key == "yequ", tostring(key))
  ok("keypad ignores other side", pad:on_touch("left", hx, hy) == nil)
end
