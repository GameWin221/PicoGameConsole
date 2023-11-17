#ifndef LCD_FONTS_HPP
#define LCD_FONTS_HPP

struct font_t 
{    
    const unsigned char* table;
    unsigned short width;
    unsigned short height;
};

extern font_t lcd_font_24px;
extern font_t lcd_font_20px;
extern font_t lcd_font_16px;
extern font_t lcd_font_12px;
extern font_t lcd_font_8px;

#endif