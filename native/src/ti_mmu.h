#ifndef TI_MMU_H
#define TI_MMU_H

#include <stdint.h>

typedef struct TiMmu {
  uint8_t bank_a;
  uint8_t bank_b;
  int bank_a_ram;
  int bank_b_ram;
  uint8_t mem_mode; /* port 04 bit0 */
  int bank_switches;
} TiMmu;

void ti_mmu_init(TiMmu *mmu);
void ti_mmu_set_bank_a(TiMmu *mmu, uint8_t page_port_val);
void ti_mmu_set_bank_b(TiMmu *mmu, uint8_t page_port_val);
void ti_mmu_set_mode(TiMmu *mmu, uint8_t mode);
void ti_mmu_apply(TiMmu *mmu);

#endif
