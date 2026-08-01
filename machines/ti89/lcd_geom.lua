-- TI-89 / Titanium physical LCD geometry only (no controller / no bit ops).
-- Safe for thin CC WebSocket clients to require without pulling the emu.

return {
  WIDTH = 160,
  HEIGHT = 100,
  BYTES_PER_ROW = 20,
  LOGICAL_WIDTH = 240,
  LOGICAL_HEIGHT = 128,
}
