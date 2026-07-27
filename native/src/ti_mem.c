#include "ti_mem.h"

#include <string.h>

static uint8_t flash[TI_FLASH_MAX];
static size_t flash_len;
static uint8_t ram[TI_MEM_SIZE]; /* 4x16KB RAM pages packed in 64K */

static uint8_t mem_mode;
static uint8_t bank_a, bank_b;
static int bank_a_ram, bank_b_ram;

void mem_init(void) {
  memset(flash, 0xFF, sizeof(flash));
  memset(ram, 0, sizeof(ram));
  flash_len = 0;
  mem_mode = 0;
  bank_a = bank_b = 0;
  bank_a_ram = bank_b_ram = 0;
}

int mem_load_flash(const uint8_t *data, size_t len) {
  if (!data) return 0;
  if (len > TI_FLASH_MAX) len = TI_FLASH_MAX;
  memcpy(flash, data, len);
  flash_len = len;
  /* Mirror page0 into low RAM image for naive code that assumes flat ROM. */
  size_t n0 = len < TI_FLASH_PAGE ? len : TI_FLASH_PAGE;
  memcpy(ram, flash, n0);
  return (int)len;
}

void mem_set_map(uint8_t mode, uint8_t a, int a_ram, uint8_t b, int b_ram) {
  mem_mode = mode & 1;
  bank_a = a & 0x1F;
  bank_b = b & 0x1F;
  bank_a_ram = a_ram ? 1 : 0;
  bank_b_ram = b_ram ? 1 : 0;
}

static uint8_t flash_at(uint8_t page, uint16_t off) {
  size_t idx = (size_t)page * TI_FLASH_PAGE + (off & 0x3FFF);
  if (idx >= flash_len) return 0xFF;
  return flash[idx];
}

static uint8_t *ram_page(uint8_t page, uint16_t off) {
  size_t idx = ((size_t)(page & 3) * TI_FLASH_PAGE) + (off & 0x3FFF);
  return &ram[idx];
}

uint8_t mem_read8(uint16_t addr) {
  uint16_t off = (uint16_t)(addr & 0x3FFF);
  if (addr < 0x4000) {
    return flash_at(0, off);
  }
  if (mem_mode == 0) {
    if (addr < 0x8000) {
      if (bank_a_ram) return *ram_page(bank_a, off);
      return flash_at(bank_a, off);
    }
    if (addr < 0xC000) {
      if (bank_b_ram) return *ram_page(bank_b, off);
      return flash_at(bank_b, off);
    }
    return *ram_page(0, off);
  }
  /* mode 1 (boot): 4000=A&~1, 8000=A, C000=B */
  if (addr < 0x8000) {
    uint8_t p = (uint8_t)(bank_a & ~1u);
    if (bank_a_ram) return *ram_page(p, off);
    return flash_at(p, off);
  }
  if (addr < 0xC000) {
    if (bank_a_ram) return *ram_page(bank_a, off);
    return flash_at(bank_a, off);
  }
  if (bank_b_ram) return *ram_page(bank_b, off);
  return flash_at(bank_b, off);
}

void mem_write8(uint16_t addr, uint8_t v) {
  uint16_t off = (uint16_t)(addr & 0x3FFF);
  if (addr < 0x4000) {
    /* boot page not writable */
    return;
  }
  if (mem_mode == 0) {
    if (addr < 0x8000) {
      if (bank_a_ram) *ram_page(bank_a, off) = v;
      return;
    }
    if (addr < 0xC000) {
      if (bank_b_ram) *ram_page(bank_b, off) = v;
      return;
    }
    *ram_page(0, off) = v;
    return;
  }
  if (addr < 0x8000) {
    uint8_t p = (uint8_t)(bank_a & ~1u);
    if (bank_a_ram) *ram_page(p, off) = v;
    return;
  }
  if (addr < 0xC000) {
    if (bank_a_ram) *ram_page(bank_a, off) = v;
    return;
  }
  if (bank_b_ram) *ram_page(bank_b, off) = v;
}

uint16_t mem_read16(uint16_t addr) {
  return (uint16_t)(mem_read8(addr) | (mem_read8((uint16_t)(addr + 1)) << 8));
}

void mem_write16(uint16_t addr, uint16_t v) {
  mem_write8(addr, (uint8_t)v);
  mem_write8((uint16_t)(addr + 1), (uint8_t)(v >> 8));
}

uint8_t *mem_raw(void) {
  return ram;
}
