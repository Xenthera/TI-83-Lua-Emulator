-- Shared machine protocol helpers for Retro Emulator Studio.
--
-- Every machine should provide (primary names kept for TI-83+ compat):
--   reset, run_cycles, step_instruction, set_key, framebuffer,
--   display_dirty, clear_display_dirty, is_display_on, pc,
--   load_rom_bytes / load_rom_file, cycles_per_frame, CPU_HZ
--
-- Vision aliases (added by apply_protocol):
--   update(dt), step(), runFrame([fps]), keyDown/keyUp,
--   getLCD(), getCPU(), getMemory(), saveState/loadState

local Protocol = {}

--- Attach standard aliases onto a machine instance (or class table).
function Protocol.apply(machine)
  if not machine.update then
    function machine:update(dt)
      local fps = 60
      local budget = self:cycles_per_frame(fps)
      if dt and dt > 0 then
        budget = math.floor(self.CPU_HZ * dt + 0.5)
      end
      return self:run_cycles(budget)
    end
  end

  if not machine.step then
    function machine:step()
      return self:step_instruction()
    end
  end

  if not machine.runFrame then
    function machine:runFrame(fps)
      return self:run_cycles(self:cycles_per_frame(fps or 60))
    end
  end

  if not machine.keyDown then
    function machine:keyDown(key)
      return self:set_key(key, true)
    end
  end

  if not machine.keyUp then
    function machine:keyUp(key)
      return self:set_key(key, false)
    end
  end

  if not machine.getLCD then
    function machine:getLCD()
      return {
        framebuffer = self:framebuffer(),
        dirty = self:display_dirty(),
        on = self:is_display_on(),
      }
    end
  end

  if not machine.getCPU then
    function machine:getCPU()
      return self.cpu
    end
  end

  if not machine.getMemory then
    function machine:getMemory()
      return self.mmu or self.memory or self.bus
    end
  end

  return machine
end

return Protocol
