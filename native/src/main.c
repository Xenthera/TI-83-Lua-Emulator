/*
 * Raylib host for mechanically translated TI-OS (ASM->C).
 *
 *   cmake -S native -B native/build && cmake --build native/build
 *   ./native/build/ti83_raylib
 */

#include "host_raylib.h"
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_keypad.h"
#include "ti_mem.h"
#include "ti_os_gen.h"
#include "ti_rect.h"

#include "raylib.h"

#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

static jmp_buf g_host_jmp;
static int g_in_os;
static int g_os_halted; /* cold-start reached OS HALT; ON resumes wake path */
static char g_status[128];

enum { YIELD_STEP = 1, YIELD_HALT = 2 };

void halt(void) {
  if (g_in_os) longjmp(g_host_jmp, YIELD_HALT);
}

void os_yield_step_limit(void) {
  if (g_in_os) longjmp(g_host_jmp, YIELD_STEP);
}

static int load_rom(void) {
  FILE *f = fopen("rom/ti83plus.rom", "rb");
  if (!f) f = fopen("../rom/ti83plus.rom", "rb");
  if (!f) f = fopen("../../rom/ti83plus.rom", "rb");
  if (!f) {
    TraceLog(LOG_WARNING, "ROM not found; flash empty");
    snprintf(g_status, sizeof(g_status), "ROM missing");
    return 0;
  }
  uint8_t buf[TI_FLASH_MAX];
  size_t n = fread(buf, 1, sizeof(buf), f);
  fclose(f);
  mem_load_flash(buf, n);
  snprintf(g_status, sizeof(g_status), "ROM %zuKB", n / 1024);
  return (int)n;
}

static int fb_nz(void) {
  int n = 0;
  for (int i = 0; i < TI_LCD_FB_SIZE; i++) {
    if (g_hw.lcd.fb[i]) n++;
  }
  return n;
}

static void run_os_entry(void (*fn)(void)) {
  int yield = 0;
  g_in_os = 1;
  os_reset_steps();
  yield = setjmp(g_host_jmp);
  if (yield == 0) {
    fn();
  }
  g_in_os = 0;

  /* Only wipe on step-limit (runaway / incomplete). Keep OS/boot LCD on HALT. */
  if (yield == YIELD_STEP) {
    ti_lcd_clear(&g_hw.lcd);
    g_hw.lcd.display_on = true;
    g_os_halted = 0;
  } else if (yield == YIELD_HALT) {
    g_os_halted = 1;
  }

  const char *tag = "OS returned";
  if (yield == YIELD_HALT) tag = "OS HALT (press ON)";
  else if (yield == YIELD_STEP) tag = "OS step-limit (blanked)";

  snprintf(g_status, sizeof(g_status),
           "%s A=%02X%s B=%02X%s mode=%d fb=%d sp=%04X",
           tag,
           g_hw.mmu.bank_a, g_hw.mmu.bank_a_ram ? "R" : "F",
           g_hw.mmu.bank_b, g_hw.mmu.bank_b_ram ? "R" : "F",
           g_hw.mmu.mem_mode, fb_nz(), sp);
  TraceLog(LOG_INFO, "%s", g_status);
}

static void on_key_boot_or_wake(void) {
  if (g_os_halted) {
    /* IM1 wake: latch ON IRQ, run RST 38h, then insn after HALT. */
    g_os_halted = 0;
    ti_keypad_set(&g_hw.keypad, "on", true);
    ti_hw_poll_on(&g_hw);
    run_os_entry(p00_rst38_isr);
    run_os_entry(p00_lcd_busy_wait);
    ti_keypad_set(&g_hw.keypad, "on", false);
  } else {
    run_os_entry(p00_rst00_boot);
  }
}

int main(void) {
  const int win_w = 420;
  const int win_h = 720;

  SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE);
  InitWindow(win_w, win_h, "TI-83 Plus - mechanical ASM->C");
  SetWindowMinSize(360, 600);
  SetTargetFPS(60);

  mem_init();
  cpu_init();
  hw_runtime_init();
  load_rom();
  os_set_step_limit(2000000);

  a = 0xFE;
  run_os_entry(p00_key_scan);

  /* Cold boot -> OS power-off HALT, ON wake, then cold-init (LCD + UI). */
  TraceLog(LOG_INFO, "auto-boot p00_rst00_boot");
  run_os_entry(p00_rst00_boot);
  if (g_os_halted) {
    TraceLog(LOG_INFO, "auto-ON wake");
    on_key_boot_or_wake();
  }
  if (!g_hw.lcd.display_on) {
    TraceLog(LOG_INFO, "LCD bring-up p00_L_3EEB");
    iy = 0x89F0;
    os_set_step_limit(200000);
    run_os_entry(p00_L_3EEB);
  }

  int nkeys = 0;
  const TiKeyDef *defs = ti_keypad_layout(&nkeys);
  TiRect *rects = (TiRect *)MemAlloc((unsigned)nkeys * sizeof(TiRect));

  const char *hover = NULL;
  const char *pressed = NULL;

  while (!WindowShouldClose()) {
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    int margin = 16;
    int body_x = margin;
    int body_y = margin + 28;
    int body_w = w - margin * 2;
    int body_h = h - margin * 2 - 28;

    int glass_h = body_h * 28 / 100;
    int glass_y = body_y + 12;
    int glass_x = body_x + 18;
    int glass_w = body_w - 36;

    int pad_y = glass_y + glass_h + 16;
    int pad_h = body_y + body_h - pad_y - 10;
    int pad_x = body_x + 10;
    int pad_w = body_w - 20;

    ti_keypad_layout_rects(defs, nkeys, pad_x, pad_y, pad_w, pad_h, rects);

    Vector2 mouse = GetMousePosition();
    hover = ti_keypad_hit(defs, nkeys, rects, (int)mouse.x, (int)mouse.y);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && hover) {
      pressed = hover;
      ti_keypad_set(&g_hw.keypad, pressed, true);
      if (strcmp(pressed, "on") == 0) {
        on_key_boot_or_wake();
      }
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && pressed) {
      ti_keypad_set(&g_hw.keypad, pressed, false);
      pressed = NULL;
    }

    const char *kb = host_keyboard_to_key();
    if (kb) {
      ti_keypad_set(&g_hw.keypad, kb, true);
      if (strcmp(kb, "on") == 0) {
        on_key_boot_or_wake();
      }
      ti_keypad_set(&g_hw.keypad, kb, false);
    }

    ti_hw_tick(&g_hw);

    BeginDrawing();
    ClearBackground((Color){ 32, 34, 38, 255 });

    DrawText("TI-83 Plus", body_x, 8, 20, (Color){ 230, 235, 225, 255 });
    DrawText(g_status, body_x + 130, 12, 12, (Color){ 160, 168, 150, 255 });

    DrawRectangleRounded(
        (Rectangle){ (float)body_x, (float)body_y, (float)body_w, (float)body_h },
        0.04f, 8, (Color){ 48, 50, 56, 255 });
    DrawRectangleRoundedLinesEx(
        (Rectangle){ (float)body_x, (float)body_y, (float)body_w, (float)body_h },
        0.04f, 8, 2.0f, (Color){ 70, 74, 82, 255 });

    DrawText("TEXAS INSTRUMENTS", glass_x, glass_y - 14, 10,
             (Color){ 180, 185, 175, 255 });

    host_present_lcd(&g_hw.lcd, glass_x, glass_y, glass_w, glass_h);
    host_draw_keypad(&g_hw.keypad, defs, nkeys, rects, hover, pressed);

    EndDrawing();
  }

  MemFree(rects);
  CloseWindow();
  return 0;
}
