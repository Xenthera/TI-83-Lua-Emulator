#ifndef TI_RECT_H
#define TI_RECT_H

/* Portable rect - host maps this to raylib Rectangle / whatever. */
typedef struct TiRect {
  float x, y, w, h;
} TiRect;

#endif
