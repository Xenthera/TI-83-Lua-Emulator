-- Emulator manager: register and create machines by id.

local Manager = {}
Manager.__index = Manager

local REGISTRY = {}

function Manager.register(id, factory)
  REGISTRY[id] = factory
end

function Manager.list()
  local ids = {}
  for id in pairs(REGISTRY) do
    ids[#ids + 1] = id
  end
  table.sort(ids)
  return ids
end

function Manager.create(id)
  local factory = REGISTRY[id]
  if not factory then
    return nil, "unknown machine: " .. tostring(id)
  end
  return factory()
end

function Manager.new()
  return setmetatable({
    current = nil,
    current_id = nil,
    paused = false,
    speed = 1.0,
  }, Manager)
end

function Manager:select(id)
  local m, err = Manager.create(id)
  if not m then return nil, err end
  self.current = m
  self.current_id = id
  self.paused = false
  return m
end

function Manager:reset()
  if self.current then self.current:reset() end
end

function Manager:pause() self.paused = true end
function Manager:resume() self.paused = false end

function Manager:set_speed(mult)
  self.speed = tonumber(mult) or 1.0
  if self.speed < 0.1 then self.speed = 0.1 end
  if self.speed > 16 then self.speed = 16 end
end

function Manager:update(dt)
  if self.paused or not self.current then return 0 end
  if self.current.update then
    return self.current:update(dt * self.speed)
  end
  return self.current:run_cycles(self.current:cycles_per_frame(60) * self.speed)
end

-- Built-in registrations (lazy require).
Manager.register("ti83plus", function()
  return require("machines.ti83plus.machine").new()
end)
Manager.register("ti84plus", function()
  return require("machines.ti84plus.machine").new()
end)
Manager.register("ti89", function()
  return require("machines.ti89.machine").new()
end)
Manager.register("ti92plus", function()
  return require("machines.ti92plus.machine").new()
end)
Manager.register("riscv64", function()
  return require("machines.riscv64.machine").new()
end)
Manager.register("gameboy", function()
  return require("machines.gameboy.machine").new()
end)

return Manager
