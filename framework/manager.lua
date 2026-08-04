-- Emulator manager: register and create machines by id.

local Discover = require("framework.discover")

local Manager = {}
Manager.__index = Manager

local REGISTRY = {}
local DISCOVERED = false

function Manager.register(id, factory)
  REGISTRY[id] = factory
end

local function registry_ids()
  local ids = {}
  for id in pairs(REGISTRY) do
    ids[#ids + 1] = id
  end
  table.sort(ids)
  return ids
end

function Manager.ensure_discovered(root)
  if DISCOVERED and root == nil then
    return registry_ids()
  end
  if root ~= nil then
    for k in pairs(REGISTRY) do
      REGISTRY[k] = nil
    end
  end
  local ids = Discover.register_machines(Manager, root)
  DISCOVERED = true
  Manager._hardware = Discover.catalog_hardware(root or Discover.project_root(root))
  return ids
end

function Manager.list()
  Manager.ensure_discovered()
  return registry_ids()
end

function Manager.create(id, opts)
  Manager.ensure_discovered()
  local factory = REGISTRY[id]
  if not factory then
    return nil, "unknown machine: " .. tostring(id)
  end
  return factory(opts)
end

function Manager.new()
  Manager.ensure_discovered()
  return setmetatable({
    current = nil,
    current_id = nil,
    paused = false,
    speed = 1.0,
  }, Manager)
end

function Manager:select(id, opts)
  local m, err = Manager.create(id, opts)
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

-- Discover machines from package.path / cwd at load (tests + tools).
Manager.ensure_discovered()

return Manager
