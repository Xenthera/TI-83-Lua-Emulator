-- Load and validate a TI-83 Plus flash dump.

local FLASH_SIZE = 512 * 1024

local function load_file(path)
  local f, err = io.open(path, "rb")
  if not f then
    return nil, ("cannot open ROM: %s"):format(err or path)
  end
  local data = f:read("*a")
  f:close()
  if not data then
    return nil, "failed to read ROM file"
  end
  return data
end

local function validate(bytes)
  if type(bytes) ~= "string" then
    return nil, "ROM must be a binary string"
  end
  local n = #bytes
  if n ~= FLASH_SIZE then
    return nil, ("expected %d-byte TI-83+ dump, got %d"):format(FLASH_SIZE, n)
  end
  -- Soft check: reset vector at 0000 should look like a jump/far call into flash.
  local b0, b1, b2 = bytes:byte(1, 3)
  if b0 ~= 0xC3 and b0 ~= 0xF3 and b0 ~= 0xED and b0 ~= 0xC7 then
    -- Still allow; some dumps start differently. Warn via return ok + note.
    return bytes, nil, "warning: unusual bytes at reset vector"
  end
  return bytes
end

local function load(path)
  local bytes, err = load_file(path)
  if not bytes then
    return nil, err
  end
  return validate(bytes)
end

return {
  FLASH_SIZE = FLASH_SIZE,
  load = load,
  validate = validate,
}
