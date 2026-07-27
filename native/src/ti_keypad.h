#ifndef TI_KEYPAD_H
#define TI_KEYPAD_H

#include "ti_rect.h"

#include <stdbool.h>
#include <stdint.h>

#define TI_KEY_GROUPS 8

typedef struct TiKeypad {
  bool keys[TI_KEY_GROUPS][8];
  uint8_t group_mask;
  bool on_pressed;
} TiKeypad;

typedef struct TiKeyDef {
  const char *id;
  const char *label;
  int group;
  int bit;
  float col;
  float row;
  float w;
  float h;
  int style; /* host may theme: 0 graph ... 8 arrow */
} TiKeyDef;

void ti_keypad_init(TiKeypad *pad);
void ti_keypad_reset(TiKeypad *pad);
bool ti_keypad_set(TiKeypad *pad, const char *id, bool down);
void ti_keypad_write_group(TiKeypad *pad, uint8_t mask);
uint8_t ti_keypad_read(const TiKeypad *pad);

const TiKeyDef *ti_keypad_layout(int *count);

void ti_keypad_layout_rects(const TiKeyDef *defs, int n,
                            int panel_x, int panel_y, int panel_w, int panel_h,
                            TiRect *out_rects);

const char *ti_keypad_hit(const TiKeyDef *defs, int n, const TiRect *rects,
                          int mx, int my);

#endif
