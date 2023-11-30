#include "lcd_draw.hpp"
#include "lcd_fonts/lcd_fonts.hpp"
#include "lcd.hpp"

#include <string.h>

static uint16_t canvas[LCD_WIDTH * LCD_HEIGHT] = { 0 };

const uint16_t* lcd_draw_get_canvas()
{
    return canvas;
}

void lcd_draw_fill(uint16_t color)
{
    for(uint16_t i = 0; i < LCD_WIDTH * LCD_HEIGHT; ++i)
        canvas[i] = (color >> 8) | (color << 8);
}
void lcd_draw_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
    for(uint16_t y = y0; y < y1; ++y)
        for(uint16_t x = x0; x < x1; ++x)
            lcd_draw_pixel(x, y, color);
}
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    canvas[y * LCD_WIDTH + x] = (color >> 8) | (color << 8);
}

void lcd_draw_char(uint16_t x, uint16_t y, uint16_t color, char character, const Font& font)
{
    uint16_t bytes_per_row = (font.width + 7) / 8;
    uint16_t glyph_id = character - ' ';
    uint16_t glyph_byte = glyph_id * font.height * bytes_per_row;

    for (uint16_t byte_y = 0; byte_y < font.height; ++byte_y) 
    {
        for(uint16_t byte_x = 0; byte_x < bytes_per_row; ++byte_x)
        {
            for(uint16_t bit = 0; bit < 8; ++bit)
            {
                if (font.data[glyph_byte + byte_y * bytes_per_row + byte_x] & ((1 << 7) >> bit)) 
                    lcd_draw_pixel(x + byte_x * 8 + bit, y + byte_y, color);
            }
        }
    }
}
void lcd_draw_string(uint16_t x, uint16_t y, uint16_t color, const char* str, const Font& font) 
{
    lcd_draw_string_rect(x, y, LCD_WIDTH, LCD_HEIGHT, color, str, font);
}
void lcd_draw_string_rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, const char* str, const struct Font& font)
{
    uint16_t cursor_x = x0;
    uint16_t cursor_y = y0;

    for (; *str != '\0'; ++str) 
    {
        if (cursor_x + font.width >= x1 || *str == '\n') 
        {
            cursor_x = x0;
            cursor_y += font.height;
        }

        if (cursor_y + font.height >= y1) 
        {
            cursor_x = x0;
            cursor_y = y0;
        }

        lcd_draw_char(cursor_x, cursor_y, color, *str, font);

        cursor_x += font.width;
    }
}