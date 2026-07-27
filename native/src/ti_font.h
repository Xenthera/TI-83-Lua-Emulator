#ifndef TI_FONT_HDR
#define TI_FONT_HDR

#include "ti_lcd.h"

#include <stdbool.h>

#define TI_FONT_CELL_W 6  /* cell width including gap */
#define TI_FONT_CELL_H 8

void ti_font_draw_char(TiLcd *lcd, int x, int y, char ch, bool on);
void ti_font_draw_text(TiLcd *lcd, int x, int y, const char *s, bool on);
int ti_font_text_width(const char *s);

#endif
