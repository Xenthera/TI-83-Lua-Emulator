#ifndef HOST_RAYLIB_H
#define HOST_RAYLIB_H

#include "ti_keypad.h"
#include "ti_lcd.h"
#include "ti_rect.h"

/* Raylib-only presentation + input bridge. Portable core never includes raylib. */

void host_present_lcd(const TiLcd *lcd, int x, int y, int w, int h);

void host_draw_keypad(const TiKeypad *pad, const TiKeyDef *defs, int n,
                      const TiRect *rects, const char *hover_id,
                      const char *pressed_id);

/* Map host keyboard -> keypad id; returns id or NULL. */
const char *host_keyboard_to_key(void);

#endif
