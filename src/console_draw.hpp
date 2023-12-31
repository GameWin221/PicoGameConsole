#ifndef LCD_DRAW_HPP
#define LCD_DRAW_HPP

#include <cinttypes>

#define RGB565(r8, g8, b8) (((uint16_t)(r8 & 0b11111000) << 8) | ((uint16_t)(g8 & 0b11111100) << 3) | (uint16_t)((b8 & 0b11111000) >> 3))

extern void console_draw_fill(uint16_t color);
extern void console_draw_rectangle(uint_fast16_t x0, uint_fast16_t y0, uint_fast16_t x1, uint_fast16_t y1, uint16_t color);
extern void console_draw_pixel(uint_fast16_t x, uint_fast16_t y, uint16_t color);
extern void console_draw_char(uint_fast16_t x, uint_fast16_t y, uint16_t color, char character, const struct Font& font);
extern void console_draw_string(uint_fast16_t x, uint_fast16_t y, uint16_t color, const char* str, const struct Font& font);
extern void console_draw_string_rect(uint_fast16_t x0, uint_fast16_t y0, uint_fast16_t x1, uint_fast16_t y1, uint16_t color, const char* str, const struct Font& font);

extern const uint16_t* console_draw_get_canvas();

#endif