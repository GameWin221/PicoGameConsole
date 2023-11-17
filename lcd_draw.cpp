#include "lcd_draw.hpp"
#include "lcd_fonts/lcd_fonts.hpp"
#include "lcd.hpp"

#include <string.h>

static unsigned short canvas[LCD_WIDTH * LCD_HEIGHT] = { 0 };

const unsigned short* lcd_draw_get_canvas()
{
    return canvas;
}

void lcd_draw_fill(unsigned short color)
{
    for(unsigned short i = 0; i < LCD_WIDTH * LCD_HEIGHT; ++i)
        canvas[i] = (color >> 8) | (color << 8);
}
void lcd_draw_rectangle(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned short color)
{
    for(unsigned short y = y0; y < y1; ++y)
        for(unsigned short x = x0; x < x1; ++x)
            lcd_draw_pixel(x, y, color);
}
void lcd_draw_pixel(unsigned short x, unsigned short y, unsigned short color)
{
    canvas[y * LCD_WIDTH + x] = (color >> 8) | (color << 8);
}

void lcd_draw_char(unsigned short x_start, unsigned short y_start,const char character, const font_t* font,unsigned short color_foreground, unsigned short color_background, bool transparent_background)
{
    unsigned int char_offset = (character - ' ') * font->height * (font->width / 8 + (font->width % 8 ? 1 : 0));

    for (unsigned short page = 0; page < font->height; ++page) 
    {
        for (unsigned short column = 0; column < font->width; ++column) 
        {

            if (font->table[char_offset] & ((1<<7) >> (column % 8))) 
                lcd_draw_pixel(x_start + column, y_start + page, color_foreground);
            else if(!transparent_background)
                lcd_draw_pixel(x_start + column, y_start + page, color_background);

            if (column % 8 == 7)
                ++char_offset;
        }

        if (font->width % 8 != 0)
            ++char_offset;
    }
}
void lcd_draw_string(unsigned short x_start, unsigned short y_start, const char* str, const font_t* font,  unsigned short color_foreground, unsigned short color_background, bool transparent_background) 
{
    unsigned short x_cursor = x_start;
    unsigned short y_cursor = y_start;

    for (; *str != '\0'; ++str) 
    {
        if (x_cursor + font->width > LCD_WIDTH) 
        {
            x_cursor = x_start;
            y_cursor += font->height;
        }

        if (y_cursor + font->height > LCD_HEIGHT) 
        {
            x_cursor = x_start;
            y_cursor = y_start;
        }

        lcd_draw_char(x_cursor, y_cursor, *str, font, color_foreground, color_background, transparent_background);

        x_cursor += font->width;
    }
}