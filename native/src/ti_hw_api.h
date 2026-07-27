#ifndef TI_HW_API_H
#define TI_HW_API_H

#include "ti_hw.h"
#include "ti_lcd.h"

#include <stdint.h>

/* Global device used by hw_in / hw_out and lcd_* ops. */
extern TiHw g_hw;

void hw_runtime_init(void);
void hw_init_ports(void);
void os_reset_steps(void);
void os_set_step_limit(int n);
/* Host longjmp codes: 1 = step limit, 2 = HALT. */
void os_yield_step_limit(void);

uint8_t hw_in(uint8_t port);
void hw_out(uint8_t port, uint8_t val);

uint8_t link_in(void);
void link_out(uint8_t v);
void mmu_set_bank_a(uint8_t page);
void mmu_set_bank_b(uint8_t page);

void os_bcall(uint16_t id);
void os_banked_call(uint16_t cpu_addr);
void os_jp_hl(void);
void os_jp_ix(void);
void os_jp_iy(void);
void link_io_stub(void);

uint8_t key_scan(uint8_t group);
void lcd_busy_wait(void);

/*
 * LCD API for OS / recovered code.
 *
 * Prefer lcd_op_* (named, 1:1 with T6A04 commands).
 * lcd_write_cmd / lcd_write_data keep the mechanical A-register convention
 * (command/data byte in global `a`) and dispatch into the same ops.
 */
void lcd_write_cmd(void);  /* ti_lcd_command(&g_hw.lcd, a) */
void lcd_write_data(void); /* ti_lcd_op_write(&g_hw.lcd, a) */

void lcd_op_6bit(void);
void lcd_op_8bit(void);
void lcd_op_display_off(void);
void lcd_op_display_on(void);
void lcd_op_inc_x_down(void);
void lcd_op_inc_x_up(void);
void lcd_op_inc_y_down(void);
void lcd_op_inc_y_up(void);
void lcd_op_set_col(uint8_t col);
void lcd_op_set_z(uint8_t z);
void lcd_op_set_row(uint8_t row);
void lcd_op_set_contrast(uint8_t c);
void lcd_op_write(uint8_t val);
uint8_t lcd_op_read(void);

/* Legacy curated names -> named ops */
void lcd_cmd_05(void); /* = lcd_op_inc_x_up */
void lcd_cmd_07(void); /* = lcd_op_inc_y_up */

#endif
