#include "ti_hw_api.h"

#include "ti_cpu.h"
#include "ti_mmu.h"
#include "ti_os_gen.h"

#include <stdio.h>

TiHw g_hw;

/* Host may set this; when exceeded, halt() yields back to the UI. */
static int g_os_steps;
static int g_os_step_limit = 200000;

void hw_runtime_init(void) {
  ti_hw_init(&g_hw);
  g_os_steps = 0;
}

void hw_init_ports(void) {
  /* Port numbers are compile-time enums in ti_hw.h. */
}

void os_reset_steps(void) {
  g_os_steps = 0;
}

void os_set_step_limit(int n) {
  g_os_step_limit = n > 0 ? n : 200000;
}

static void os_step(void) {
  if (++g_os_steps >= g_os_step_limit) {
    os_yield_step_limit();
  }
}

void os_bump_step(void) { os_step(); }

uint8_t hw_in(uint8_t port) {
  os_step();
  return ti_hw_in(&g_hw, port);
}

void hw_out(uint8_t port, uint8_t val) {
  os_step();
  ti_hw_out(&g_hw, port, val);
}

uint8_t link_in(void) {
  return 0xFF;
}

void link_out(uint8_t v) {
  (void)v;
}

void mmu_set_bank_a(uint8_t page) {
  ti_mmu_set_bank_a(&g_hw.mmu, page);
}

void mmu_set_bank_b(uint8_t page) {
  ti_mmu_set_bank_b(&g_hw.mmu, page);
}

void os_bcall(uint16_t id) {
  os_step();
  (void)id; /* unresolved ROM calls stubbed */
}

/* os_banked_call / os_jp_hl / os_jp_ix / os_jp_iy are in gen/dispatch.c */

void link_io_stub(void) {
}

uint8_t key_scan(uint8_t group) {
  uint8_t row;
  (void)hw_in(PORT_STATUS);
  (void)hw_in(PORT_SE_STATUS);
  hw_out(PORT_KEYPAD, group);
  row = hw_in(PORT_KEYPAD);
  hw_out(PORT_KEYPAD, 0xFF);
  return row;
}

void lcd_busy_wait(void) {
}

/* Mechanical path: command/data byte in A -> same named ops as lcd_op_*. */
void lcd_write_cmd(void) {
  ti_lcd_command(&g_hw.lcd, a);
}

void lcd_write_data(void) {
  ti_lcd_op_write(&g_hw.lcd, a);
}

void lcd_op_6bit(void) { ti_lcd_op_6bit(&g_hw.lcd); }
void lcd_op_8bit(void) { ti_lcd_op_8bit(&g_hw.lcd); }
void lcd_op_display_off(void) { ti_lcd_op_display_off(&g_hw.lcd); }
void lcd_op_display_on(void) { ti_lcd_op_display_on(&g_hw.lcd); }
void lcd_op_inc_x_down(void) { ti_lcd_op_inc_x_down(&g_hw.lcd); }
void lcd_op_inc_x_up(void) { ti_lcd_op_inc_x_up(&g_hw.lcd); }
void lcd_op_inc_y_down(void) { ti_lcd_op_inc_y_down(&g_hw.lcd); }
void lcd_op_inc_y_up(void) { ti_lcd_op_inc_y_up(&g_hw.lcd); }

void lcd_op_set_col(uint8_t col) { ti_lcd_op_set_col(&g_hw.lcd, col); }
void lcd_op_set_z(uint8_t z) { ti_lcd_op_set_z(&g_hw.lcd, z); }
void lcd_op_set_row(uint8_t row) { ti_lcd_op_set_row(&g_hw.lcd, row); }
void lcd_op_set_contrast(uint8_t c) { ti_lcd_op_set_contrast(&g_hw.lcd, c); }
void lcd_op_write(uint8_t val) { ti_lcd_op_write(&g_hw.lcd, val); }
uint8_t lcd_op_read(void) { return ti_lcd_op_read(&g_hw.lcd); }

void lcd_cmd_05(void) { lcd_op_inc_x_up(); }
void lcd_cmd_07(void) { lcd_op_inc_y_up(); }
