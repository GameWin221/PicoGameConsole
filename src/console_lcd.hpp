#ifndef LCD_ST7735S_HPP
#define LCD_ST7735S_HPP

#include <cinttypes>

#define LCD_SCAN_HORIZONTAL 0x00
#define LCD_SCAN_VERTICAL 0x01

#define LCD_SCAN_DIRECTION LCD_SCAN_HORIZONTAL

#if LCD_SCAN_DIRECTION == LCD_SCAN_HORIZONTAL
    #define LCD_HEIGHT 128
    #define LCD_WIDTH 160
#elif LCD_SCAN_DIRECTION == LCD_SCAN_VERTICAL
    #define LCD_HEIGHT 160
    #define LCD_WIDTH 128
#endif

#define LCD_GAMMA_CURVE_2_2 0x01
#define LCD_GAMMA_CURVE_1_8 0x02
#define LCD_GAMMA_CURVE_2_5 0x04
#define LCD_GAMMA_CURVE_2_0 0x08
#define LCD_GAMMA_CURVE_DEFAULT LCD_GAMMA_CURVE_2_2

#define LCD_COLOR_MODE_4R4G4B 0x03
#define LCD_COLOR_MODE_5R6G5B 0x05
#define LCD_COLOR_MODE_6R6G6B 0x06
#define LCD_COLOR_MODE_DEFAULT LCD_COLOR_MODE_5R6G5B

#define LCD_INVERSION_DEFAULT false

#define LCD_TEARING_V_BLANK 0x00
#define LCD_TEARING_VH_BLANK 0x01
#define LCD_TEARING_OFF 0x02
#define LCD_TEARING_DEFAULT LCD_TEARING_OFF

#define LCD_MEM_CTL_MY  (1<<7) // Row Address Order        (0 = Left to right, 1 = Right to left)
#define LCD_MEM_CTL_MX  (1<<6) // Column Address Order     (0 = Bottom to top, 1 = Top to bottom)
#define LCD_MEM_CTL_MV  (1<<5) // Row / Column Exchange    (0 = (X: Column, Y: Row), 1 = (X: Row, Y: Column))
#define LCD_MEM_CTL_ML  (1<<4) // Vertical Refresh Order   (0 = Top to bottom, 1 = Bottom to top)
#define LCD_MEM_CTL_BGR (1<<3) // RGB or BGR Order         (0 = RGB, 1 = BGR)
#define LCD_MEM_CTL_MH  (1<<2) // Horizontal Refresh Order (0 = Left to right, 1 = Right to left)
#define LCD_MEM_CTL_DEFAULT 0

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
