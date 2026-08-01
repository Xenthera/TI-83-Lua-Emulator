package.path = "./?.lua;./?/init.lua;" .. package.path
local f = assert(io.open(arg[1] or "rom/ti89.rom", "rb"))
local d = f:read("*a")
f:close()

local needle = "Installation"
local pos = d:find(needle, 1, true)
if not pos then
  print("not found")
  os.exit(1)
end
local off = pos - 1
print(string.format("string at flash offset %06X  abs %06X", off, 0x800000 + off))
print("text:", (d:sub(pos, pos + 60):gsub("%c", ".")))

local abs = 0x800000 + off
local b1 = math.floor(abs / 0x1000000) % 256
local b2 = math.floor(abs / 0x10000) % 256
local b3 = math.floor(abs / 0x100) % 256
local b4 = abs % 256
local pat = string.char(b1, b2, b3, b4)
print(string.format("looking for pointer %02X %02X %02X %02X", b1, b2, b3, b4))

local i = 1
local n = 0
while n < 30 do
  local j = d:find(pat, i, true)
  if not j then break end
  n = n + 1
  print(string.format("  ptr at %06X (abs %06X)", j - 1, 0x800000 + j - 1))
  i = j + 1
end

-- Also search PC-relative style: just the low 3 bytes as used in LEA
local pat3 = string.char(b2, b3, b4)
i = 1
n = 0
print("3-byte tail refs:")
while n < 20 do
  local j = d:find(pat3, i, true)
  if not j then break end
  -- likely preceded by 00 or 008x
  local pre = d:byte(j - 1) or 0
  if pre == 0x00 or pre == 0x80 or pre == 0x81 then
    n = n + 1
    print(string.format("  at %06X pre=%02X", j - 2, pre))
  end
  i = j + 1
end
