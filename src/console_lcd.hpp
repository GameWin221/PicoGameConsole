#ifndef LCD_ST7735S_HPP
#define LCD_ST7735S_HPP

#include <cinttypes>

extern void console_lcd_set_inversion(uint8_t inversion);
extern void console_lcd_set_sleep(uint8_t sleep);
extern void console_lcd_set_gamma(uint8_t gamma);
extern void console_lcd_set_enabled(uint8_t enabled);
extern void console_lcd_set_tearing(uint8_t tearing);
extern void console_lcd_set_color_mode(uint8_t mode);
extern void console_lcd_set_mem_access_ctl(uint8_t flags);

extern void console_lcd_init();
extern void console_lcd_display(const uint8_t* image);

#endif
