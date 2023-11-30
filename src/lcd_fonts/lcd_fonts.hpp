#ifndef LCD_FONTS_HPP
#define LCD_FONTS_HPP

#include <inttypes.h>

struct Font 
{    
    const uint8_t* data;
    const uint16_t width;
    const uint16_t height;
};

extern const Font lcd_font_24px;
extern const Font lcd_font_20px;
extern const Font lcd_font_16px;
extern const Font lcd_font_12px;
extern const Font lcd_font_8px;

#endif