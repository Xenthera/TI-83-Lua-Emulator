/*
 * Headless boot smoke for mechanical ASM->C (no raylib).
 *
 * Pass bar (same as tools/boot_os_smoke.lua):
 *   display_on && fb_nz >= 50
 *
 *   cmake --build native/build --target ti83_boot_smoke
 *   ./native/build/ti83_boot_smoke
 */

#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_keypad.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

#include <setjmp.h>
#include <stdio.h>
#include <string.h>

static jmp_buf g_jmp;
static int g_in;

enum { YIELD_STEP = 1, YIELD_HALT = 2 };

void halt(void) {
  /* Power-off wait loops are `halt; jr $-1` - yield to the host. */
  if (g_in) longjmp(g_jmp, YIELD_HALT);
}

void os_yield_step_limit(void) {
  if (g_in) longjmp(g_jmp, YIELD_STEP);
}

static int load_rom(void) {
  FILE *f = fopen("rom/ti83plus.rom", "rb");
  if (!f) f = fopen("../rom/ti83plus.rom", "rb");
  if (!f) f = fopen("../../rom/ti83plus.rom", "rb");
  if (!f) {
    fprintf(stderr, "FAIL: cannot open rom/ti83plus.rom\n");
    return 0;
  }
  uint8_t buf[512 * 1024];
  size_t n = fread(buf, 1, sizeof(buf), f);
  fclose(f);
  mem_load_flash(buf, n);
  printf("rom_loaded=%zu\n", n);
  return (int)n;
}

static int fb_nonzero(void) {
  int n = 0;
  for (int i = 0; i < TI_LCD_FB_SIZE; i++) {
    if (g_hw.lcd.fb[i]) n++;
  }
  return n;
}

static int run(void (*fn)(void), const char *tag) {
  int yield;
  g_in = 1;
  os_reset_steps();
  yield = setjmp(g_jmp);
  if (yield == 0) {
    fn();
    printf("[%s] returned normally\n", tag);
  } else if (yield == YIELD_HALT) {
    printf("[%s] HALT\n", tag);
  } else {
    printf("[%s] step-limit\n", tag);
  }
  g_in = 0;
  printf("[%s] disp=%d fb_nz=%d sp=%04X iy=%04X bank_a=%02X\n",
         tag, g_hw.lcd.display_on ? 1 : 0, fb_nonzero(), sp, iy,
         g_hw.mmu.bank_a);
  return yield;
}

static void dump_fb(void) {
  for (int row = 0; row < TI_LCD_HEIGHT; row++) {
    int nz = 0;
    for (int c = 0; c < TI_LCD_BPR; c++) {
      if (g_hw.lcd.fb[row * TI_LCD_BPR + c]) nz++;
    }
    if (!nz) continue;
    printf("R%02d", row);
    for (int c = 0; c < TI_LCD_BPR; c++) {
      printf(" %02X", g_hw.lcd.fb[row * TI_LCD_BPR + c]);
    }
    printf("\n");
  }
}

int main(void) {
  int fail = 0;

  mem_init();
  cpu_init();
  hw_runtime_init();
  if (!load_rom()) return 1;

  os_set_step_limit(300000);

  printf("--- boot (OS cold start) ---\n");
  run(p00_rst00_boot, "boot");
  if (sp != 0xFFC5) {
    fprintf(stderr, "FAIL: expected OS cold-start sp=FFC5, got %04X\n", sp);
    fail = 1;
  }

  /* LCD bring-up: page0 3EEB -> page6 4D0E/4D15 (DISPLAY_ON=0x03). */
  printf("--- LCD bring-up p00_L_3EEB ---\n");
  iy = 0x89F0;
  os_set_step_limit(100000);
  run(p00_L_3EEB, "lcd_3EEB");

  printf("lcd contrast=%d col=%d row=%d disp=%d fb_nz=%d\n",
         g_hw.lcd.contrast, g_hw.lcd.col, g_hw.lcd.row,
         g_hw.lcd.display_on ? 1 : 0, fb_nonzero());
  dump_fb();

  if (!g_hw.lcd.display_on) {
    fprintf(stderr, "FAIL: display still off after 3EEB\n");
    fail = 1;
  }
  if (fb_nonzero() < 50) {
    fprintf(stderr,
            "FAIL: expected homescreen pixels (fb_nz>=50), got %d "
            "(page1 glyph blit not reached/working yet)\n",
            fb_nonzero());
    fail = 1;
  }

  if (fail) {
    fprintf(stderr, "BOOT OS SMOKE FAIL\n");
    return 1;
  }
  printf("BOOT OS SMOKE OK\n");
  return 0;
}
