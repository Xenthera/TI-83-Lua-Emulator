return function(ok)
  local ROOT = "."
  package.path = ROOT .. "/frontends/love2d/?.lua;" .. package.path
  local BuildSvc = require("buildsvc")

  local f = assert(io.open(ROOT .. "/rom/ti83plus_p0_dis.asm", "r"))
  local src = f:read("*a")
  f:close()
  ok("page0 disasm present", #src > 1000)

  -- Disasm may emit absolute L_XXXX refs into the middle of an instruction
  -- without a matching label; define dangling ones so reassembly can proceed.
  local defined = {}
  for label in src:gmatch("%f[%w_](L_%x+):") do
    defined[label] = true
  end
  for label, hex in src:gmatch("%f[%w_](L_(%x+))%s+[Ee][Qq][Uu]") do
    defined[label] = true
  end
  local equ = {}
  for label in src:gmatch("%f[%w_](L_%x%x%x%x+)%f[^%w_]") do
    if not defined[label] then
      local addr = label:match("^L_(%x+)$")
      if addr and #addr >= 4 then
        equ[#equ + 1] = label .. ": equ 0x" .. addr
        defined[label] = true
      end
    end
  end
  if #equ > 0 then
    src = table.concat(equ, "\n") .. "\n" .. src
  end

  local rom, err, result, info = BuildSvc.build_asm(ROOT, src)
  ok("build_asm page0", rom ~= nil, err)
  if rom then
    ok("512KB flash", #rom == 512 * 1024)
    ok("spliced into stock ROM", info and info.spliced == true, info and tostring(info.spliced))

    local stock = assert(io.open(ROOT .. "/rom/ti83plus.rom", "rb")):read("*a")
    local mism = 0
    local first
    for i = 1, #rom do
      if rom:byte(i) ~= stock:byte(i) then
        mism = mism + 1
        if not first then first = i - 1 end
      end
    end
    ok("byte-identical to stock ROM", mism == 0, first and ("first @" .. string.format("0x%05X", first)) or nil)
  end

  -- Tiny demo still zero-pads (no splice)
  local demo = [[
    org 0
    jp main
    org 0x100
main:
    halt
]]
  local rom2, err2, _, info2 = BuildSvc.build_asm(ROOT, demo)
  ok("demo assembles", rom2 ~= nil, err2)
  ok("demo not spliced", info2 and info2.spliced == false)
  if rom2 then
    local rest = 0
    for i = 0x4001, #rom2 do
      if rom2:byte(i) ~= 0 then rest = rest + 1 end
    end
    ok("demo pages 1+ are zero", rest == 0)
  end
end
