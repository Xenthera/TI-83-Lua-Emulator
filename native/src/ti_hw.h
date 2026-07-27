#ifndef TI_HW_H
#define TI_HW_H

#include "ti_keypad.h"
#include "ti_lcd.h"
#include "ti_mmu.h"

#include <stdbool.h>
#include <stdint.h>

/* Logical device ports (match TI-83+ ASIC numbers). */
enum {
  PORT_LINK = 0x00,
  PORT_KEYPAD = 0x01,
  PORT_STATUS = 0x02,
  PORT_INTMASK = 0x03,
  PORT_INTACK = 0x04,
  PORT_ASYN = 0x05,
  PORT_MMU_A = 0x06,
  PORT_MMU_B = 0x07,
  PORT_LCD_CMD = 0x10,
  PORT_LCD_DATA = 0x11,
  PORT_SE_STATUS = 0x20
};

typedef struct TiHw {
  TiLcd lcd;
  TiKeypad keypad;
  TiMmu mmu;
  uint8_t asic_status;
  uint8_t se_status;
  uint8_t int_mask;   /* port 03 */
  uint8_t int_status; /* latched IRQ sources (bits 0-2); read via port 04 */
  uint8_t port04;     /* last port 04 write (mem mode / timer speed) */
  bool on_prev;       /* edge detect for ON key IRQ */
} TiHw;

void ti_hw_init(TiHw *hw);
void ti_hw_tick(TiHw *hw);
void ti_hw_poll_on(TiHw *hw); /* latch ON interrupt on press edge */
uint8_t ti_hw_in(TiHw *hw, uint8_t port);
void ti_hw_out(TiHw *hw, uint8_t port, uint8_t val);

#endif
