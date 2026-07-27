#include "ti_keypad.h"

#include <string.h>

void ti_keypad_init(TiKeypad *pad) {
  ti_keypad_reset(pad);
}

void ti_keypad_reset(TiKeypad *pad) {
  memset(pad, 0, sizeof(*pad));
  pad->group_mask = 0xFF;
}

bool ti_keypad_set(TiKeypad *pad, const char *id, bool down) {
  int n = 0;
  const TiKeyDef *defs = ti_keypad_layout(&n);
  for (int i = 0; i < n; i++) {
    if (strcmp(defs[i].id, id) == 0) {
      if (defs[i].group < 0 || defs[i].group >= TI_KEY_GROUPS) return false;
      pad->keys[defs[i].group][defs[i].bit] = down;
      if (strcmp(id, "on") == 0) pad->on_pressed = down;
      return true;
    }
  }
  return false;
}

void ti_keypad_write_group(TiKeypad *pad, uint8_t mask) {
  pad->group_mask = mask;
}

uint8_t ti_keypad_read(const TiKeypad *pad) {
  uint8_t result = 0xFF;
  for (int g = 0; g < TI_KEY_GROUPS; g++) {
    if ((pad->group_mask & (1u << g)) == 0) {
      for (int b = 0; b < 8; b++) {
        if (pad->keys[g][b]) {
          result = (uint8_t)(result & ~(1u << b));
        }
      }
    }
  }
  return result;
}

const TiKeyDef *ti_keypad_layout(int *count) {
  static const TiKeyDef keys[] = {
    { "yequ", "Y=", 6, 4, 0, 0, 1, 1, 0 },
    { "window", "WINDOW", 6, 3, 1, 0, 1, 1, 0 },
    { "zoom", "ZOOM", 6, 2, 2, 0, 1, 1, 0 },
    { "trace", "TRACE", 6, 1, 3, 0, 1, 1, 0 },
    { "graph", "GRAPH", 6, 0, 4, 0, 1, 1, 0 },

    { "2nd", "2nd", 6, 5, 0, 1.15f, 1, 1, 2 },
    { "mode", "MODE", 6, 6, 1, 1.15f, 1, 1, 1 },
    { "del", "DEL", 6, 7, 2, 1.15f, 1, 1, 1 },
    { "up", "^", 0, 3, 3.5f, 1.0f, 1, 0.85f, 8 },

    { "alpha", "ALPHA", 5, 7, 0, 2.3f, 1, 1, 3 },
    { "xt", "X,T,n", 4, 7, 1, 2.3f, 1, 1, 1 },
    { "stat", "STAT", 3, 7, 2, 2.3f, 1, 1, 1 },
    { "left", "<", 0, 1, 3.0f, 2.15f, 0.9f, 0.85f, 8 },
    { "right", ">", 0, 2, 4.1f, 2.15f, 0.9f, 0.85f, 8 },

    { "down", "v", 0, 0, 3.5f, 3.15f, 1, 0.85f, 8 },

    { "math", "MATH", 5, 6, 0, 4.2f, 1, 1, 1 },
    { "apps", "APPS", 4, 6, 1, 4.2f, 1, 1, 1 },
    { "prgm", "PRGM", 3, 6, 2, 4.2f, 1, 1, 1 },
    { "vars", "VARS", 2, 6, 3, 4.2f, 1, 1, 1 },
    { "clear", "CLEAR", 1, 6, 4, 4.2f, 1, 1, 1 },

    { "recip", "x^-1", 5, 5, 0, 5.35f, 1, 1, 5 },
    { "sin", "SIN", 4, 5, 1, 5.35f, 1, 1, 1 },
    { "cos", "COS", 3, 5, 2, 5.35f, 1, 1, 1 },
    { "tan", "TAN", 2, 5, 3, 5.35f, 1, 1, 1 },
    { "power", "^", 1, 5, 4, 5.35f, 1, 1, 5 },

    { "square", "x^2", 5, 4, 0, 6.5f, 1, 1, 5 },
    { "comma", ",", 4, 4, 1, 6.5f, 1, 1, 5 },
    { "lparen", "(", 3, 4, 2, 6.5f, 1, 1, 5 },
    { "rparen", ")", 2, 4, 3, 6.5f, 1, 1, 5 },
    { "div", "/", 1, 4, 4, 6.5f, 1, 1, 5 },

    { "log", "LOG", 5, 3, 0, 7.65f, 1, 1, 1 },
    { "7", "7", 4, 3, 1, 7.65f, 1, 1, 4 },
    { "8", "8", 3, 3, 2, 7.65f, 1, 1, 4 },
    { "9", "9", 2, 3, 3, 7.65f, 1, 1, 4 },
    { "mul", "*", 1, 3, 4, 7.65f, 1, 1, 5 },

    { "ln", "LN", 5, 2, 0, 8.8f, 1, 1, 1 },
    { "4", "4", 4, 2, 1, 8.8f, 1, 1, 4 },
    { "5", "5", 3, 2, 2, 8.8f, 1, 1, 4 },
    { "6", "6", 2, 2, 3, 8.8f, 1, 1, 4 },
    { "minus", "-", 1, 2, 4, 8.8f, 1, 1, 5 },

    { "sto", "STO>", 5, 1, 0, 9.95f, 1, 1, 1 },
    { "1", "1", 4, 1, 1, 9.95f, 1, 1, 4 },
    { "2", "2", 3, 1, 2, 9.95f, 1, 1, 4 },
    { "3", "3", 2, 1, 3, 9.95f, 1, 1, 4 },
    { "plus", "+", 1, 1, 4, 9.95f, 1, 1, 5 },

    { "on", "ON", 5, 0, 0, 11.1f, 1, 1, 6 },
    { "0", "0", 4, 0, 1, 11.1f, 1, 1, 4 },
    { "dot", ".", 3, 0, 2, 11.1f, 1, 1, 4 },
    { "neg", "(-)", 2, 0, 3, 11.1f, 1, 1, 4 },
    { "enter", "ENTER", 1, 0, 4, 11.1f, 1, 1.15f, 7 },
  };
  if (count) *count = (int)(sizeof(keys) / sizeof(keys[0]));
  return keys;
}

void ti_keypad_layout_rects(const TiKeyDef *defs, int n,
                            int panel_x, int panel_y, int panel_w, int panel_h,
                            TiRect *out_rects) {
  const float design_cols = 5.0f;
  const float design_rows = 12.4f;
  const float pad = 6.0f;
  float cw = (panel_w - pad * 2) / design_cols;
  float ch = (panel_h - pad * 2) / design_rows;
  float face_h = ch * 0.85f;

  for (int i = 0; i < n; i++) {
    out_rects[i].x = panel_x + pad + defs[i].col * cw + 2;
    out_rects[i].y = panel_y + pad + defs[i].row * ch + 2;
    out_rects[i].w = defs[i].w * cw - 4;
    out_rects[i].h = defs[i].h * face_h - 2;
  }
}

const char *ti_keypad_hit(const TiKeyDef *defs, int n, const TiRect *rects,
                          int mx, int my) {
  for (int i = 0; i < n; i++) {
    if (mx >= rects[i].x && mx < rects[i].x + rects[i].w &&
        my >= rects[i].y && my < rects[i].y + rects[i].h) {
      return defs[i].id;
    }
  }
  return NULL;
}
