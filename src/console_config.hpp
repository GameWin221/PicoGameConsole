#ifndef CONSOLE_CONFIG_HPP
#define CONSOLE_CONFIG_HPP

/// console_audio ///
#define BUZZER_PIN 14

#define PWM_WRAP 10000
#define PWM_DUTY (PWM_WRAP / 2)

/// console_input ///
#define JOYSTICK_XAXIS_PIN 27
#define JOYSTICK_YAXIS_PIN 26

#define BUTTON_LEFT_PIN 16
#define BUTTON_RIGHT_PIN 17

/// console_lcd ///
#define LCD_DIN 19
#define LCD_CLK 18
#define LCD_CS  11
#define LCD_DC  12 
#define LCD_RST 13
#define LCD_BL  15

// Sending data at 65.536MHz - the max possible spi frequency
#define SPI_FREQ 65536000
#define SPI_CHANNEL spi0

#define LCD_CMD_SLEEP_IN 0x11
#define LCD_CMD_SLEEP_OUT 0x11
#define LCD_CMD_INVERSION_ON 0x21
#define LCD_CMD_INVERSION_OFF 0x20
#define LCD_CMD_GAMMA_SET 0x26
#define LCD_CMD_DISPLAY_ON 0x29
#define LCD_CMD_DISPLAY_OFF 0x28
#define LCD_CMD_COLUMN_ADDR_SET 0x2a
#define LCD_CMD_ROW_ADDR_SET 0x2b
#define LCD_CMD_MEMORY_WRITE 0x2c
#define LCD_CMD_TEARING_ON 0x35
#define LCD_CMD_TEARING_OFF 0x34
#define LCD_CMD_MEM_ACCESS_CTL 0x36
#define LCD_CMD_COLOR_MODE 0x3a

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

#endif