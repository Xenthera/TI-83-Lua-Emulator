#include "host_raylib.h"

#include "raylib.h"

#include <stddef.h>
#include <string.h>

void host_present_lcd(const TiLcd *lcd, int x, int y, int w, int h) {
  int cell = w / TI_LCD_W;
  if (h / TI_LCD_HEIGHT < cell) cell = h / TI_LCD_HEIGHT;
  if (cell < 2) cell = 2;

  float inset = cell * 0.12f;
  if (inset > 0.35f) inset = 0.35f;
  float pix = (float)cell - inset * 2.0f;

  int dw = TI_LCD_W * cell;
  int dh = TI_LCD_HEIGHT * cell;
  int x0 = x + (w - dw) / 2;
  int y0 = y + (h - dh) / 2;

  Color bezel = { 158, 168, 148, 255 };
  Color bg = { 133, 148, 122, 255 };
  Color on = { 31, 46, 31, 255 };

  DrawRectangleRounded(
      (Rectangle){ (float)(x0 - 4), (float)(y0 - 4), (float)(dw + 8), (float)(dh + 8) },
      0.08f, 6, bezel);
  DrawRectangle(x0, y0, dw, dh, bg);

  if (!lcd->display_on) return;

  for (int row = 0; row < TI_LCD_HEIGHT; row++) {
    for (int col = 0; col < TI_LCD_BPR; col++) {
      uint8_t byte = lcd->fb[row * TI_LCD_BPR + col];
      for (int bit = 0; bit < 8; bit++) {
        if (byte & (0x80u >> bit)) {
          int lx = col * 8 + bit;
          DrawRectangle(
              (int)(x0 + lx * cell + inset),
              (int)(y0 + row * cell + inset),
              (int)(pix + 0.5f),
              (int)(pix + 0.5f),
              on);
        }
      }
    }
  }
}

static Color style_color(int style, bool pressed) {
  Color c;
  switch (style) {
    case 0: c = (Color){ 41, 71, 122, 255 }; break;
    case 2: c = (Color){ 209, 184, 46, 255 }; break;
    case 3: c = (Color){ 56, 140, 77, 255 }; break;
    case 4: c = (Color){ 140, 143, 148, 255 }; break;
    case 5: c = (Color){ 41, 71, 122, 255 }; break;
    case 6: c = (Color){ 107, 36, 36, 255 }; break;
    case 7: c = (Color){ 41, 71, 122, 255 }; break;
    case 8: c = (Color){ 46, 56, 77, 255 }; break;
    default: c = (Color){ 46, 56, 77, 255 }; break;
  }
  if (pressed) {
    c.r = (unsigned char)(c.r * 0.7f);
    c.g = (unsigned char)(c.g * 0.7f);
    c.b = (unsigned char)(c.b * 0.7f);
  }
  return c;
}

void host_draw_keypad(const TiKeypad *pad, const TiKeyDef *defs, int n,
                      const TiRect *rects, const char *hover_id,
                      const char *pressed_id) {
  (void)pad;
  for (int i = 0; i < n; i++) {
    bool pressed = pressed_id && strcmp(defs[i].id, pressed_id) == 0;
    bool hover = hover_id && strcmp(defs[i].id, hover_id) == 0;
    Rectangle r = { rects[i].x, rects[i].y, rects[i].w, rects[i].h };
    DrawRectangleRounded(r, 0.18f, 4, style_color(defs[i].style, pressed));
    if (hover && !pressed) DrawRectangleLinesEx(r, 2.0f, RAYWHITE);
    int fs = (int)(r.height * 0.38f);
    if (fs < 8) fs = 8;
    if (fs > 16) fs = 16;
    int tw = MeasureText(defs[i].label, fs);
    DrawText(defs[i].label,
             (int)(r.x + (r.width - tw) / 2),
             (int)(r.y + (r.height - fs) / 2),
             fs, RAYWHITE);
  }
}

const char *host_keyboard_to_key(void) {
  struct {
    int key;
    const char *id;
  } map[] = {
      { KEY_ENTER, "enter" },      { KEY_KP_ENTER, "enter" },
      { KEY_BACKSPACE, "del" },    { KEY_DELETE, "clear" },
      { KEY_SPACE, "on" },
      { KEY_ZERO, "0" },           { KEY_ONE, "1" },
      { KEY_TWO, "2" },            { KEY_THREE, "3" },
      { KEY_FOUR, "4" },           { KEY_FIVE, "5" },
      { KEY_SIX, "6" },            { KEY_SEVEN, "7" },
      { KEY_EIGHT, "8" },          { KEY_NINE, "9" },
      { KEY_KP_0, "0" },           { KEY_KP_1, "1" },
      { KEY_KP_2, "2" },           { KEY_KP_3, "3" },
      { KEY_KP_4, "4" },           { KEY_KP_5, "5" },
      { KEY_KP_6, "6" },           { KEY_KP_7, "7" },
      { KEY_KP_8, "8" },           { KEY_KP_9, "9" },
      { KEY_EQUAL, "plus" },       { KEY_KP_ADD, "plus" },
      { KEY_MINUS, "minus" },      { KEY_KP_SUBTRACT, "minus" },
      { KEY_KP_MULTIPLY, "mul" },  { KEY_KP_DIVIDE, "div" },
      { KEY_PERIOD, "dot" },       { KEY_KP_DECIMAL, "dot" },
  };
  for (size_t i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
    if (IsKeyPressed(map[i].key)) return map[i].id;
  }
  int ch;
  while ((ch = GetCharPressed()) > 0) {
    if (ch == '(') return "lparen";
    if (ch == ')') return "rparen";
    if (ch == '*') return "mul";
    if (ch == '/') return "div";
    if (ch == '+') return "plus";
  }
  return NULL;
}
