-- Effective-address helpers for MC68000 (big-endian bus callbacks).
local bit = require("framework.util.bit")
local band, bor, bxor, bnot, lshift, rshift = bit.band, bit.bor, bit.bxor, bit.bnot, bit.lshift, bit.rshift

local EA = {}

function EA.sign_extend(v, bits)
  if bits == 8 then
    if band(v, 0x80) ~= 0 then return bor(v, 0xFFFFFF00) end
    return band(v, 0xFF)
  elseif bits == 16 then
    if band(v, 0x8000) ~= 0 then return bor(v, 0xFFFF0000) end
    return band(v, 0xFFFF)
  end
  return band(v, 0xFFFFFFFF)
end

function EA.mask(size)
  if size == 1 then return 0xFF
  elseif size == 2 then return 0xFFFF
  end
  return 0xFFFFFFFF
end

--- Mode/reg from 6-bit EA field. Returns address (or nil for Dn/An direct), and category.
-- categories: "dn","an","mem","imm","other"
function EA.decode_mode_reg(cpu, mode, reg, size)
  size = size or 2
  if mode == 0 then
    return nil, "dn", reg
  elseif mode == 1 then
    return nil, "an", reg
  elseif mode == 2 then
    return cpu:get_a(reg), "mem", reg
  elseif mode == 3 then
    local addr = cpu:get_a(reg)
    local inc = size
    if reg == 7 and size == 1 then
      inc = 2
    end
    cpu:set_a(reg, band(addr + inc, 0xFFFFFFFF))
    return addr, "mem", reg
  elseif mode == 4 then
    local dec = size
    if reg == 7 and size == 1 then dec = 2 end
    local addr = band(cpu:get_a(reg) - dec, 0xFFFFFFFF)
    cpu:set_a(reg, addr)
    return addr, "mem", reg
  elseif mode == 5 then
    local disp = EA.sign_extend(cpu:fetch16(), 16)
    return band(cpu:get_a(reg) + disp, 0xFFFFFFFF), "mem", reg
  elseif mode == 6 then
    return EA.brief_ext(cpu, cpu:get_a(reg)), "mem", reg
  elseif mode == 7 then
    if reg == 0 then
      return EA.sign_extend(cpu:fetch16(), 16), "mem", reg
    elseif reg == 1 then
      return cpu:fetch32(), "mem", reg
    elseif reg == 2 then
      local pc_base = cpu.pc
      local disp = EA.sign_extend(cpu:fetch16(), 16)
      return band(pc_base + disp, 0xFFFFFFFF), "mem", reg
    elseif reg == 3 then
      local base = cpu.pc
      return EA.brief_ext(cpu, base), "mem", reg
    elseif reg == 4 then
      if size == 1 then
        local v = band(cpu:fetch16(), 0xFF) -- byte immediate in low byte of word
        return v, "imm", reg
      elseif size == 2 then
        return cpu:fetch16(), "imm", reg
      else
        return cpu:fetch32(), "imm", reg
      end
    end
  end
  return nil, "other", reg
end

function EA.brief_ext(cpu, base)
  local ext = cpu:fetch16()
  local da = band(rshift(ext, 15), 1)
  local reg = band(rshift(ext, 12), 7)
  local wl = band(rshift(ext, 11), 1)
  local scale = band(rshift(ext, 9), 3) -- 68020+; 68000 ignores (treat as 0)
  local disp = EA.sign_extend(band(ext, 0xFF), 8)
  local idx
  if da == 0 then
    idx = cpu.d[reg]
  else
    idx = cpu:get_a(reg)
  end
  if wl == 0 then
    idx = EA.sign_extend(idx, 16)
  end
  -- Classic 68000: scale always 1
  return band(base + disp + idx, 0xFFFFFFFF)
end

function EA.read_ea(cpu, mode, reg, size)
  local addr, cat, r = EA.decode_mode_reg(cpu, mode, reg, size)
  if cat == "dn" then
    return band(cpu.d[r], EA.mask(size)), addr, cat
  elseif cat == "an" then
    return band(cpu:get_a(r), EA.mask(size)), addr, cat
  elseif cat == "imm" then
    return addr, nil, cat -- addr holds immediate value
  else
    if size == 1 then return cpu:read8(addr), addr, cat
    elseif size == 2 then return cpu:read16(addr), addr, cat
    else return cpu:read32(addr), addr, cat end
  end
end

function EA.write_ea(cpu, mode, reg, size, value, addr_hint, cat_hint)
  local m = EA.mask(size)
  value = band(value, m)
  if cat_hint == "dn" or mode == 0 then
    if size == 1 then
      cpu.d[reg] = bor(band(cpu.d[reg], 0xFFFFFF00), value)
    elseif size == 2 then
      cpu.d[reg] = bor(band(cpu.d[reg], 0xFFFF0000), value)
    else
      cpu.d[reg] = value
    end
    return
  end
  if cat_hint == "an" or mode == 1 then
    if size == 2 then
      cpu:set_a(reg, EA.sign_extend(value, 16))
    else
      cpu:set_a(reg, value)
    end
    return
  end
  local addr = addr_hint
  if not addr then
    addr = EA.decode_mode_reg(cpu, mode, reg, size)
  end
  if size == 1 then cpu:write8(addr, value)
  elseif size == 2 then cpu:write16(addr, value)
  else cpu:write32(addr, value) end
end

return EA
