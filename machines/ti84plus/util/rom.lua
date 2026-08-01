-- Load and validate a TI-84 Plus flash dump (1MB / 64×16KB pages).

local FLASH_SIZE = 1024 * 1024

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
    return nil, ("expected %d-byte TI-84+ dump, got %d"):format(FLASH_SIZE, n)
  end
  local b0 = bytes:byte(1)
  if b0 ~= 0xC3 and b0 ~= 0xF3 and b0 ~= 0xED and b0 ~= 0xC7 then
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
