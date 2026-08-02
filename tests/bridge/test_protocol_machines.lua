return function(ok)
  local Protocol = require("bridge.protocol")

  local function has(id, w, h, bpr)
    local info = Protocol.machine_info(id)
    ok("info " .. id, info ~= nil)
    if info then
      ok(id .. " w", info.w == w)
      ok(id .. " h", info.h == h)
      ok(id .. " bpr", info.bpr == bpr)
    end
  end

  has("ti83plus", 96, 64, 12)
  has("ti84plus", 96, 64, 12)
  has("ti84", 96, 64, 12)
  has("ti89", 160, 100, 20)
  has("ti92plus", 240, 128, 30)
  has("ti92", 240, 128, 30)
  has("gameboy", 160, 144, 160)
  has("gb", 160, 144, 160)
  ok("gb fmt shade", Protocol.machine_info("gameboy").fmt == "shade")
  has("nes", 256, 240, 256)
  has("famicom", 256, 240, 256)
  ok("nes fmt", Protocol.machine_info("nes").fmt == "nes")
  ok("canonical ti84_gpu", Protocol.canonical_id("ti84_gpu") == "ti84plus")
  ok("canonical gb_gpu", Protocol.canonical_id("gb_gpu") == "gameboy")
  ok("canonical famicom", Protocol.canonical_id("famicom") == "nes")
end
