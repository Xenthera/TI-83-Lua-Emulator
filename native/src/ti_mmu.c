#include "ti_mmu.h"

#include "ti_mem.h"

void ti_mmu_apply(TiMmu *mmu) {
  mem_set_map(mmu->mem_mode, mmu->bank_a, mmu->bank_a_ram,
              mmu->bank_b, mmu->bank_b_ram);
}

void ti_mmu_init(TiMmu *mmu) {
  mmu->bank_a = 0;
  mmu->bank_b = 0;
  mmu->bank_a_ram = 0;
  mmu->bank_b_ram = 0;
  mmu->mem_mode = 0;
  mmu->bank_switches = 0;
  ti_mmu_apply(mmu);
}

void ti_mmu_set_bank_a(TiMmu *mmu, uint8_t page_port_val) {
  int ram = (page_port_val & 0x40) != 0;
  uint8_t page = (uint8_t)(page_port_val & 0x1F);
  if (mmu->bank_a != page || mmu->bank_a_ram != ram) mmu->bank_switches++;
  mmu->bank_a = page;
  mmu->bank_a_ram = ram;
  ti_mmu_apply(mmu);
}

void ti_mmu_set_bank_b(TiMmu *mmu, uint8_t page_port_val) {
  int ram = (page_port_val & 0x40) != 0;
  uint8_t page = (uint8_t)(page_port_val & 0x1F);
  if (mmu->bank_b != page || mmu->bank_b_ram != ram) mmu->bank_switches++;
  mmu->bank_b = page;
  mmu->bank_b_ram = ram;
  ti_mmu_apply(mmu);
}

void ti_mmu_set_mode(TiMmu *mmu, uint8_t mode) {
  mmu->mem_mode = (uint8_t)(mode & 1);
  ti_mmu_apply(mmu);
}
