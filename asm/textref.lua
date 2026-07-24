-- Host-side expected framebuffer for pipeline screen tests.

local font8 = require("asm.font8")

local M = {}

function M.expected_text_screen()
  local fb = font8.new_fb()
  font8.render_string(fb, "Bobby is cool", 0, 0)
  font8.render_string(fb, "FAIL!", 0, 16)
  font8.render_string(fb, "0123456789", 0, 32)
  return fb
end

function M.diff(actual, expected)
  local mismatches = 0
  local first
  for i = 0, 12 * 64 - 1 do
    local a, e = actual[i] or 0, expected[i] or 0
    if a ~= e then
      mismatches = mismatches + 1
      if not first then
        first = { i = i, a = a, e = e, row = math.floor(i / 12), col = i % 12 }
      end
    end
  end
  return mismatches, first
end

return M
