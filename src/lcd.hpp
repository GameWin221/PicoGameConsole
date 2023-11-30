#ifndef LCD_ST7735S_HPP
#define LCD_ST7735S_HPP

#include <inttypes.h>

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

#define GAMMA_CURVE_2_2 0x01
#define GAMMA_CURVE_1_8 0x02
#define GAMMA_CURVE_2_5 0x04
#define GAMMA_CURVE_2_0 0x08
#define GAMMA_CURVE_DEFAULT GAMMA_CURVE_2_2

#define COLOR_MODE_4R4G4B 0x03
#define COLOR_MODE_5R6G5B 0x05
#define COLOR_MODE_6R6G6B 0x06
#define COLOR_MODE_DEFAULT COLOR_MODE_5R6G5B

#define INVERSION_DEFAULT false

#define TEARING_V_BLANK 0x00
#define TEARING_VH_BLANK 0x01
#define TEARING_OFF 0x02
#define TEARING_DEFAULT TEARING_OFF

#define MEM_CTL_MY  (1<<7) // Row Address Order        (0 = Left to right, 1 = Right to left)
#define MEM_CTL_MX  (1<<6) // Column Address Order     (0 = Bottom to top, 1 = Top to bottom)
#define MEM_CTL_MV  (1<<5) // Row / Column Exchange    (0 = (X: Column, Y: Row), 1 = (X: Row, Y: Column))
#define MEM_CTL_ML  (1<<4) // Vertical Refresh Order   (0 = Top to bottom, 1 = Bottom to top)
#define MEM_CTL_BGR (1<<3) // RGB or BGR Order         (0 = RGB, 1 = BGR)
#define MEM_CTL_MH  (1<<2) // Horizontal Refresh Order (0 = Left to right, 1 = Right to left)
#define MEM_CTL_DEFAULT 0

extern void lcd_set_inversion(uint8_t inversion);
extern void lcd_set_sleep(uint8_t sleep);
extern void lcd_set_gamma(uint8_t gamma);
extern void lcd_set_enabled(uint8_t enabled);
extern void lcd_set_tearing(uint8_t tearing);
extern void lcd_set_color_mode(uint8_t mode);
extern void lcd_set_mem_access_ctl(uint8_t flags);

extern void lcd_init();
extern void lcd_display(const uint8_t* image);

#endif
