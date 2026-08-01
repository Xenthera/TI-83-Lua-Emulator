-- Machine-independent save-state helpers.
-- Format: { version, machine_id, blobs = { name = binary_string_or_table } }

local SaveState = {}
SaveState.VERSION = 1

--- Pack a 0-based byte array (sparse or dense) into a binary string.
function SaveState.pack_bytes(arr, size)
  local parts = {}
  local n = size or 0
  if not size then
    local max = -1
    for k in pairs(arr) do
      if type(k) == "number" and k > max then
        max = k
      end
    end
    n = max + 1
  end
  for i = 0, n - 1 do
    parts[i + 1] = string.char((arr[i] or 0) % 256)
  end
  return table.concat(parts)
end

--- Unpack a binary string into a 0-based byte array (mutates or creates arr).
function SaveState.unpack_bytes(data, arr)
  arr = arr or {}
  for i = 1, #data do
    arr[i - 1] = data:byte(i)
  end
  return arr
end

function SaveState.new(machine_id, blobs)
  return {
    version = SaveState.VERSION,
    machine_id = machine_id,
    blobs = blobs or {},
  }
end

function SaveState.validate(state, expect_id)
  if type(state) ~= "table" then
    return nil, "save state must be a table"
  end
  if state.version ~= SaveState.VERSION then
    return nil, "unsupported save state version"
  end
  if expect_id and state.machine_id ~= expect_id then
    return nil, "save state machine mismatch: " .. tostring(state.machine_id)
  end
  if type(state.blobs) ~= "table" then
    return nil, "save state missing blobs"
  end
  return true
end

return SaveState
