#include "ti_lcd.h"

#include <string.h>

static int max_col(const TiLcd *lcd) {
  return lcd->bits8 ? 14 : 19;
}

static void advance(TiLcd *lcd) {
  if (lcd->inc_col) {
    int wrap = max_col(lcd);
    if (lcd->inc_up) {
      lcd->col++;
      if (lcd->col > wrap) lcd->col = 0;
    } else {
      lcd->col--;
      if (lcd->col < 0) lcd->col = wrap;
    }
  } else {
    if (lcd->inc_up) lcd->row = (lcd->row + 1) & 0x3F;
    else lcd->row = (lcd->row - 1) & 0x3F;
  }
}

static void set_pixel_int(TiLcd *lcd, int px, int row, bool on) {
  if (px < 0 || px >= TI_LCD_INT_W || row < 0 || row > 63) return;
  int byte_i = px / 8;
  int bitn = 7 - (px % 8);
  int idx = row * TI_LCD_INT_BPR + byte_i;
  uint8_t mask = (uint8_t)(1u << bitn);
  if (on) lcd->int_fb[idx] |= mask;
  else lcd->int_fb[idx] &= (uint8_t)~mask;
}

static bool get_pixel_int(const TiLcd *lcd, int px, int row) {
  if (px < 0 || px >= TI_LCD_INT_W || row < 0 || row > 63) return false;
  int byte_i = px / 8;
  int bitn = 7 - (px % 8);
  int idx = row * TI_LCD_INT_BPR + byte_i;
  return (lcd->int_fb[idx] & (1u << bitn)) != 0;
}

static uint8_t peek(const TiLcd *lcd, int col, int row) {
  if (row < 0 || row > 63) return 0;
  if (lcd->bits8) {
    if (col >= 0 && col <= 14) return lcd->int_fb[row * TI_LCD_INT_BPR + col];
    return 0;
  }
  if (col < 0 || col > 19) return 0;
  uint8_t value = 0;
  int base = col * 6;
  for (int i = 0; i < 6; i++) {
    if (get_pixel_int(lcd, base + i, row)) value |= (uint8_t)(1u << (5 - i));
  }
  return value;
}

static bool poke(TiLcd *lcd, int col, int row, uint8_t value) {
  if (row < 0 || row > 63) return false;
  if (lcd->bits8) {
    if (col >= 0 && col <= 14) {
      lcd->int_fb[row * TI_LCD_INT_BPR + col] = value;
      return true;
    }
    return false;
  }
  if (col < 0 || col > 19) return false;
  int base = col * 6;
  for (int i = 0; i < 6; i++) {
    bool on = (value & (1u << (5 - i))) != 0;
    set_pixel_int(lcd, base + i, row, on);
  }
  return true;
}

void ti_lcd_sync_visible(TiLcd *lcd) {
  for (int row = 0; row < TI_LCD_HEIGHT; row++) {
    int src_row = (row + lcd->z) & 0x3F;
    for (int col = 0; col < TI_LCD_BPR; col++) {
      lcd->fb[row * TI_LCD_BPR + col] =
          lcd->int_fb[src_row * TI_LCD_INT_BPR + col];
    }
  }
}

void ti_lcd_init(TiLcd *lcd) {
  memset(lcd, 0, sizeof(*lcd));
  lcd->display_on = false;
  lcd->contrast = 0x3F;
  lcd->bits8 = true;
  lcd->inc_col = false;
  lcd->inc_up = true;
  ti_lcd_sync_visible(lcd);
}

void ti_lcd_clear(TiLcd *lcd) {
  memset(lcd->int_fb, 0, sizeof(lcd->int_fb));
  ti_lcd_sync_visible(lcd);
}

uint8_t ti_lcd_status(const TiLcd *lcd) {
  uint8_t s = 0;
  if (lcd->inc_up) s |= 0x01;
  if (lcd->inc_col) s |= 0x02;
  if (lcd->display_on) s |= 0x20;
  if (lcd->bits8) s |= 0x40;
  if (lcd->busy > 0) s |= 0x80;
  return s;
}

/* ---- Named ops ---- */

void ti_lcd_op_6bit(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->bits8 = false;
}

void ti_lcd_op_8bit(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->bits8 = true;
}

void ti_lcd_op_display_off(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->display_on = false;
}

void ti_lcd_op_display_on(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->display_on = true;
}

void ti_lcd_op_inc_x_down(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->inc_col = false;
  lcd->inc_up = false;
}

void ti_lcd_op_inc_x_up(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->inc_col = false;
  lcd->inc_up = true;
}

void ti_lcd_op_inc_y_down(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->inc_col = true;
  lcd->inc_up = false;
}

void ti_lcd_op_inc_y_up(TiLcd *lcd) {
  lcd->busy = 1;
  lcd->inc_col = true;
  lcd->inc_up = true;
}

void ti_lcd_op_power(TiLcd *lcd, uint8_t cmd) {
  lcd->busy = 1;
  (void)cmd; /* host: power/mirror/test ignored */
}

void ti_lcd_op_set_col(TiLcd *lcd, uint8_t col) {
  lcd->busy = 1;
  lcd->col = col & 0x1F;
}

void ti_lcd_op_set_z(TiLcd *lcd, uint8_t z) {
  lcd->busy = 1;
  lcd->z = z & 0x3F;
  ti_lcd_sync_visible(lcd);
}

void ti_lcd_op_set_row(TiLcd *lcd, uint8_t row) {
  lcd->busy = 1;
  lcd->row = row & 0x3F;
}

void ti_lcd_op_set_contrast(TiLcd *lcd, uint8_t c) {
  lcd->busy = 1;
  lcd->contrast = c & 0x3F;
}

void ti_lcd_op_write(TiLcd *lcd, uint8_t val) {
  lcd->busy = 1;
  if (poke(lcd, lcd->col, lcd->row, val)) {
    ti_lcd_sync_visible(lcd);
  }
  advance(lcd);
}

uint8_t ti_lcd_op_read(TiLcd *lcd) {
  lcd->busy = 1;
  uint8_t value = lcd->read_reg;
  lcd->read_reg = peek(lcd, lcd->col, lcd->row);
  advance(lcd);
  return value;
}

uint8_t ti_lcd_encode_set_col(uint8_t col) {
  return (uint8_t)(TI_LCD_CMD_COL_BASE | (col & 0x1F));
}

uint8_t ti_lcd_encode_set_z(uint8_t z) {
  return (uint8_t)(TI_LCD_CMD_Z_BASE | (z & 0x3F));
}

uint8_t ti_lcd_encode_set_row(uint8_t row) {
  return (uint8_t)(TI_LCD_CMD_ROW_BASE | (row & 0x3F));
}

uint8_t ti_lcd_encode_set_contrast(uint8_t c) {
  return (uint8_t)(TI_LCD_CMD_CONTRAST_BASE | (c & 0x3F));
}

void ti_lcd_command(TiLcd *lcd, uint8_t cmd) {
  /* Pure dispatcher: raw port-10 byte -> named op. */
  if (cmd == TI_LCD_CMD_6BIT) {
    ti_lcd_op_6bit(lcd);
  } else if (cmd == TI_LCD_CMD_8BIT) {
    ti_lcd_op_8bit(lcd);
  } else if (cmd == TI_LCD_CMD_DISPLAY_OFF) {
    ti_lcd_op_display_off(lcd);
  } else if (cmd == TI_LCD_CMD_DISPLAY_ON) {
    ti_lcd_op_display_on(lcd);
  } else if (cmd == TI_LCD_CMD_INC_X_DOWN) {
    ti_lcd_op_inc_x_down(lcd);
  } else if (cmd == TI_LCD_CMD_INC_X_UP) {
    ti_lcd_op_inc_x_up(lcd);
  } else if (cmd == TI_LCD_CMD_INC_Y_DOWN) {
    ti_lcd_op_inc_y_down(lcd);
  } else if (cmd == TI_LCD_CMD_INC_Y_UP) {
    ti_lcd_op_inc_y_up(lcd);
  } else if (cmd >= 0x08 && cmd <= 0x1F) {
    ti_lcd_op_power(lcd, cmd);
  } else if (cmd >= 0x20 && cmd <= 0x3F) {
    ti_lcd_op_set_col(lcd, (uint8_t)(cmd & 0x1F));
  } else if (cmd >= 0x40 && cmd <= 0x7F) {
    ti_lcd_op_set_z(lcd, (uint8_t)(cmd & 0x3F));
  } else if (cmd >= 0x80 && cmd <= 0xBF) {
    ti_lcd_op_set_row(lcd, (uint8_t)(cmd & 0x3F));
  } else {
    ti_lcd_op_set_contrast(lcd, (uint8_t)(cmd & 0x3F));
  }
}

void ti_lcd_set_pixel(TiLcd *lcd, int x, int y, bool on) {
  set_pixel_int(lcd, x, y, on);
  ti_lcd_sync_visible(lcd);
}

bool ti_lcd_get_pixel(const TiLcd *lcd, int x, int y) {
  return get_pixel_int(lcd, x, y);
}

void ti_lcd_draw_rect(TiLcd *lcd, int x, int y, int w, int h, bool on) {
  for (int yy = y; yy < y + h; yy++) {
    for (int xx = x; xx < x + w; xx++) {
      ti_lcd_set_pixel(lcd, xx, yy, on);
    }
  }
}
