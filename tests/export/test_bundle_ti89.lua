return function(ok)
  local ROOT = "."
  local out = "dist/_test_bundle_ti89.lua"
  require("framework.path").ensure_dir("dist")
  local cmd = string.format(
    "lua tools/bundle.lua - o %s --root %s --entry frontends.computercraft.api_ti89 frontends.computercraft.api_ti89",
    out, ROOT
  )
  local ok_run = os.execute(cmd)
  ok("ti89 bundle command", ok_run == true or ok_run == 0)

  local chunk, err = loadfile(out)
  ok("ti89 bundle loadfile", chunk ~= nil, err)
  if not chunk then
    return
  end

  local api = chunk()
  ok("ti89 bundle returns api", type(api) == "table" and type(api.new_machine) == "function")
  ok("ti89 MACHINE_ID", api.MACHINE_ID == "ti89")
  ok("ti89 LCD 160x100", api.LCD_WIDTH == 160 and api.LCD_HEIGHT == 100,
    tostring(api.LCD_WIDTH) .. "x" .. tostring(api.LCD_HEIGHT))
  ok("ti89 has paint_lcd", type(api.paint_lcd) == "function")
  ok("ti89 has KeypadView", type(api.KeypadView) == "table")
  ok("ti89 Profile", api.Profile and api.Profile.id == "ti89")

  local m = api.new_machine()
  ok("ti89 machine from bundle", m ~= nil and m.framebuffer ~= nil)

  local written = {}
  local function mock_mon(w, h)
    return {
      getSize = function() return w, h end,
      setCursorPos = function(x, y) written.x, written.y = x, y end,
      blit = function(text, fg, bg)
        written.blits = (written.blits or 0) + 1
        written.last_len = #text
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
  for i = 0, 20 * 100 - 1 do
    fb[i] = 0
  end
  fb[0] = 0xFF

  written = {}
  local small = mock_mon(40, 20)
  api.setup_lcd(small)
  local ok_paint = api.paint_lcd(small, fb, true)
  ok("ti89 small monitor rejected", ok_paint == false)
  ok("ti89 too-small mentions 80x34", type(written.text) == "string"
    and written.text:find("80x34", 1, true),
    tostring(written.text))

  written = {}
  local big = mock_mon(100, 50)
  local painter = api.new_lcd_painter(big, {})
  local lay = painter:setup()
  ok("ti89 painter layout ok", lay.ok == true)
  written.blits = 0
  local ok_big, lay2, n = painter:paint(fb, true)
  ok("ti89 large monitor accepted", ok_big == true)
  ok("ti89 first paint blits 34 sixtel rows", n == 34 and written.blits == 34,
    tostring(n) .. "/" .. tostring(written.blits))
  ok("ti89 blit width 80", written.last_len == 80, tostring(written.last_len))

  -- Key names match TI-89 keyboard matrix
  local pad = api.KeypadView.new(mock_mon(40, 30), { side = "right" })
  ok("ti89 keypad has buttons", #pad.buttons > 20)
  local hit = pad:hit(2, 2)
  ok("ti89 keypad hit returns string or nil", hit == nil or type(hit) == "string")
end
