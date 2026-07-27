#include "ti_hw.h"

void ti_hw_init(TiHw *hw) {
  ti_lcd_init(&hw->lcd);
  ti_keypad_init(&hw->keypad);
  ti_mmu_init(&hw->mmu);
  hw->asic_status = 0x02;
  hw->se_status = 0x00;
  hw->int_mask = 0x00;
  hw->int_status = 0x00;
  hw->port04 = 0x00;
  hw->on_prev = false;
}

void ti_hw_tick(TiHw *hw) {
  if (hw->lcd.busy > 0) hw->lcd.busy--;
  ti_hw_poll_on(hw);
}

void ti_hw_poll_on(TiHw *hw) {
  bool on_now = hw->keypad.on_pressed;
  if (on_now && !hw->on_prev) {
    hw->int_status = (uint8_t)(hw->int_status | 0x01);
  }
  hw->on_prev = on_now;
}

uint8_t ti_hw_in(TiHw *hw, uint8_t port) {
  switch (port) {
    case PORT_LINK:
      return 0xFF;
    case PORT_KEYPAD:
      return ti_keypad_read(&hw->keypad);
    case PORT_STATUS: {
      /* bit0 battery ok, bit1 LCD ready, bit7 clear on 83+ */
      uint8_t s = 0x01;
      if (hw->lcd.busy <= 0) s = (uint8_t)(s | 0x02);
      return s;
    }
    case PORT_INTMASK:
      return hw->int_mask;
    case PORT_INTACK: {
      /* Read: interrupt status. Bit3 = ON key up (not pressed). */
      uint8_t v = (uint8_t)(hw->int_status & 0x07);
      if (!hw->keypad.on_pressed) v = (uint8_t)(v | 0x08);
      return v;
    }
    case PORT_MMU_A: {
      uint8_t v = hw->mmu.bank_a;
      if (hw->mmu.bank_a_ram) v = (uint8_t)(v | 0x40);
      return v;
    }
    case PORT_MMU_B: {
      uint8_t v = hw->mmu.bank_b;
      if (hw->mmu.bank_b_ram) v = (uint8_t)(v | 0x40);
      return v;
    }
    case PORT_SE_STATUS:
      return hw->se_status;
    case PORT_LCD_CMD:
      return ti_lcd_status(&hw->lcd);
    case PORT_LCD_DATA:
      return ti_lcd_data_read(&hw->lcd);
    default:
      return 0xFF;
  }
}

void ti_hw_out(TiHw *hw, uint8_t port, uint8_t val) {
  switch (port) {
    case PORT_LINK:
      break;
    case PORT_KEYPAD:
      ti_keypad_write_group(&hw->keypad, val);
      break;
    case PORT_INTMASK:
      /* Writing 0 to an enable bit acknowledges that source (TI behavior). */
      hw->int_mask = val;
      if ((val & 0x01) == 0) hw->int_status = (uint8_t)(hw->int_status & (uint8_t)~0x01);
      if ((val & 0x02) == 0) hw->int_status = (uint8_t)(hw->int_status & (uint8_t)~0x02);
      if ((val & 0x04) == 0) hw->int_status = (uint8_t)(hw->int_status & (uint8_t)~0x04);
      break;
    case PORT_MMU_A:
      ti_mmu_set_bank_a(&hw->mmu, val);
      break;
    case PORT_MMU_B:
      ti_mmu_set_bank_b(&hw->mmu, val);
      break;
    case PORT_INTACK:
      /* Write: bit0 mem map mode; bits1-2 timer speed (timer stubbed). */
      hw->port04 = val;
      ti_mmu_set_mode(&hw->mmu, (uint8_t)(val & 0x01));
      break;
    case PORT_SE_STATUS:
      hw->se_status = val;
      break;
    case PORT_LCD_CMD:
      ti_lcd_command(&hw->lcd, val);
      break;
    case PORT_LCD_DATA:
      ti_lcd_op_write(&hw->lcd, val);
      break;
    default:
      break;
  }
}
