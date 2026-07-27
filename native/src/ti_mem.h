#ifndef TI_MEM_H
#define TI_MEM_H

#include <stddef.h>
#include <stdint.h>

#define TI_MEM_SIZE 0x10000
#define TI_FLASH_MAX (512 * 1024)
#define TI_FLASH_PAGE 0x4000

void mem_init(void);
int mem_load_flash(const uint8_t *data, size_t len);

/* Update bank map (called when ports 04/06/07 change). */
void mem_set_map(uint8_t mem_mode, uint8_t bank_a, int bank_a_ram,
                 uint8_t bank_b, int bank_b_ram);

uint8_t mem_read8(uint16_t addr);
void mem_write8(uint16_t addr, uint8_t v);
uint16_t mem_read16(uint16_t addr);
void mem_write16(uint16_t addr, uint16_t v);

uint8_t *mem_raw(void); /* writable 64K view (legacy / debug) */

#endif
