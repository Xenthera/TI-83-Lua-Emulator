#ifndef TI_LCD_HDR
#define TI_LCD_HDR

#include <stdbool.h>
#include <stdint.h>

/*
 * Toshiba T6A04 LCD (TI-83+).
 *
 * Prefer the named ops below - each is 1:1 with one hardware command byte
 * (WikiTI 83Plus:Ports:10). ti_lcd_command() is only a dispatcher from the
 * raw port-10 encoding used by mechanical ASM->C.
 */

#define TI_LCD_W 96
#define TI_LCD_HEIGHT 64
#define TI_LCD_BPR 12
#define TI_LCD_FB_SIZE (TI_LCD_BPR * TI_LCD_HEIGHT)
#define TI_LCD_INT_W 120
#define TI_LCD_INT_BPR 15
#define TI_LCD_INT_FB_SIZE (TI_LCD_INT_BPR * TI_LCD_HEIGHT)

/* Raw command encodings (for documentation / encode helpers). */
enum {
  TI_LCD_CMD_6BIT = 0x00,
  TI_LCD_CMD_8BIT = 0x01,
  TI_LCD_CMD_DISPLAY_OFF = 0x02,
  TI_LCD_CMD_DISPLAY_ON = 0x03,
  TI_LCD_CMD_INC_X_DOWN = 0x04, /* auto-inc row, down */
  TI_LCD_CMD_INC_X_UP = 0x05,   /* auto-inc row, up */
  TI_LCD_CMD_INC_Y_DOWN = 0x06, /* auto-inc col, down */
  TI_LCD_CMD_INC_Y_UP = 0x07,   /* auto-inc col, up */
  TI_LCD_CMD_COL_BASE = 0x20,   /* 0x20..0x3F -> column */
  TI_LCD_CMD_Z_BASE = 0x40,     /* 0x40..0x7F -> Z scroll */
  TI_LCD_CMD_ROW_BASE = 0x80,   /* 0x80..0xBF -> row */
  TI_LCD_CMD_CONTRAST_BASE = 0xC0
};

typedef struct TiLcd {
  uint8_t int_fb[TI_LCD_INT_FB_SIZE];
  uint8_t fb[TI_LCD_FB_SIZE]; /* visible 96x64 for host present */
  bool display_on;
  int contrast;
  int z;

  int col; /* TI "Y" */
  int row; /* TI "X" */
  bool bits8;
  bool inc_col;
  bool inc_up;
  int busy;
  uint8_t read_reg;
} TiLcd;

void ti_lcd_init(TiLcd *lcd);
void ti_lcd_clear(TiLcd *lcd);
void ti_lcd_sync_visible(TiLcd *lcd);

/* ---- Named ops (1:1 with T6A04 commands) ---- */
void ti_lcd_op_6bit(TiLcd *lcd);            /* 0x00 */
void ti_lcd_op_8bit(TiLcd *lcd);            /* 0x01 */
void ti_lcd_op_display_off(TiLcd *lcd);     /* 0x02 */
void ti_lcd_op_display_on(TiLcd *lcd);      /* 0x03 */
void ti_lcd_op_inc_x_down(TiLcd *lcd);      /* 0x04 */
void ti_lcd_op_inc_x_up(TiLcd *lcd);        /* 0x05 */
void ti_lcd_op_inc_y_down(TiLcd *lcd);      /* 0x06 */
void ti_lcd_op_inc_y_up(TiLcd *lcd);        /* 0x07 */
void ti_lcd_op_power(TiLcd *lcd, uint8_t cmd); /* 0x08..0x1F (no-op host) */
void ti_lcd_op_set_col(TiLcd *lcd, uint8_t col);      /* 0x20|col */
void ti_lcd_op_set_z(TiLcd *lcd, uint8_t z);          /* 0x40|z */
void ti_lcd_op_set_row(TiLcd *lcd, uint8_t row);      /* 0x80|row */
void ti_lcd_op_set_contrast(TiLcd *lcd, uint8_t c);   /* 0xC0|c */

/* Data port (port 11) - still 1:1 with hardware. */
void ti_lcd_op_write(TiLcd *lcd, uint8_t val);
uint8_t ti_lcd_op_read(TiLcd *lcd);

/* Encode named parameters back to the command byte (round-trip). */
uint8_t ti_lcd_encode_set_col(uint8_t col);
uint8_t ti_lcd_encode_set_z(uint8_t z);
uint8_t ti_lcd_encode_set_row(uint8_t row);
uint8_t ti_lcd_encode_set_contrast(uint8_t c);

/* Raw port-10 dispatcher -> named ops (mechanical / hw_out path). */
void ti_lcd_command(TiLcd *lcd, uint8_t cmd);
uint8_t ti_lcd_status(const TiLcd *lcd);

/* Compat aliases used by older call sites. */
static inline void ti_lcd_data_write(TiLcd *lcd, uint8_t val) {
  ti_lcd_op_write(lcd, val);
}
static inline uint8_t ti_lcd_data_read(TiLcd *lcd) {
  return ti_lcd_op_read(lcd);
}

void ti_lcd_set_pixel(TiLcd *lcd, int x, int y, bool on);
bool ti_lcd_get_pixel(const TiLcd *lcd, int x, int y);
void ti_lcd_draw_rect(TiLcd *lcd, int x, int y, int w, int h, bool on);

#endif
