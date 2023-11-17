#ifndef LCD_DRAW_HPP
#define LCD_DRAW_HPP

#define RGB565(r8, g8, b8) (((uint16_t)(r8 & 0b11111000) << 8) | ((uint16_t)(g8 & 0b11111100) << 3) | (uint16_t)((b8 & 0b11111000) >> 3))

extern void lcd_draw_fill(unsigned short color);
extern void lcd_draw_rectangle(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color);
extern void lcd_draw_pixel(unsigned short x, unsigned short y, unsigned short color);
extern void lcd_draw_char(unsigned short x_start, unsigned short y_start, const char character, const struct font_t* font,unsigned short color_foreground, unsigned short color_background, bool transparent_background);
extern void lcd_draw_string(unsigned short x_start, unsigned short y_start, const char* str, const struct font_t* font, unsigned short color_foreground, unsigned short color_background, bool transparent_background);

extern const unsigned short* lcd_draw_get_canvas();

#endif