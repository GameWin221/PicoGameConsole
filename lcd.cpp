#include "lcd.hpp"

#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define DIN 11
#define CLK 10
#define CS  9
#define DC  8
#define RST 12
#define BL  13

// Sending data at 65.536MHz
// It's the max possible frequency
#define SPI_FREQ 65536000

#define CMD_SLEEP_IN 0x11
#define CMD_SLEEP_OUT 0x11
#define CMD_INVERSION_ON 0x21
#define CMD_INVERSION_OFF 0x20
#define CMD_GAMMA_SET 0x26
#define CMD_DISPLAY_ON 0x29
#define CMD_DISPLAY_OFF 0x28
#define CMD_COLUMN_ADDR_SET 0x2a
#define CMD_ROW_ADDR_SET 0x2b
#define CMD_MEMORY_WRITE 0x2c
#define CMD_TEARING_ON 0x35
#define CMD_TEARING_OFF 0x34
#define CMD_MEM_ACCESS_CTL 0x36
#define CMD_COLOR_MODE 0x3a

static unsigned char lcd_current_color_mode = 0;

static inline void lcd_send_command(unsigned char cmd) 
{
    gpio_put(DC, 0);
    gpio_put(CS, 0);
    spi_write_blocking(spi1, &cmd, 1);
    gpio_put(CS, 1);
}

static inline void lcd_send_byte(unsigned char data) 
{
    gpio_put(DC, 1);
    gpio_put(CS, 0);
    spi_write_blocking(spi1, &data, 1);
    gpio_put(CS, 1);
}

static inline void lcd_reset() 
{
    gpio_put(RST, 1);
    sleep_ms(2);
    gpio_put(RST, 0);
    sleep_ms(2);
    gpio_put(RST, 1);
    sleep_ms(2);
}

static void lcd_set_windows(unsigned short xStart, unsigned short yStart, unsigned short xEnd, unsigned short yEnd) 
{
    // Set X coordinate
    lcd_send_command(CMD_COLUMN_ADDR_SET);
    lcd_send_byte(0x00);
    lcd_send_byte(xStart);
    lcd_send_byte(0x00);
    lcd_send_byte(xEnd);

    // Set Y coordinate
    lcd_send_command(CMD_ROW_ADDR_SET);
    lcd_send_byte(0x00);
    lcd_send_byte(yStart);
    lcd_send_byte(0x00);
    lcd_send_byte(yEnd);
}

void lcd_set_inversion(unsigned char inversion) 
{
    lcd_send_command(inversion ? CMD_INVERSION_ON : CMD_INVERSION_OFF);
}
void lcd_set_sleep(unsigned char sleep) 
{
    lcd_send_command(sleep ? CMD_SLEEP_IN : CMD_SLEEP_OUT);
}

void lcd_set_gamma(unsigned char gamma) 
{
    lcd_send_command(CMD_GAMMA_SET);
    lcd_send_byte(gamma);
}

void lcd_set_enabled(unsigned char enabled) 
{
    lcd_send_command(enabled ? CMD_DISPLAY_ON : CMD_DISPLAY_OFF);
}

void lcd_set_tearing(unsigned char tearing) 
{
    if(tearing != TEARING_OFF)
    {
        lcd_send_command(CMD_TEARING_ON);
        lcd_send_byte(tearing);
    }
    else
        lcd_send_command(CMD_TEARING_OFF);
}

void lcd_set_color_mode(unsigned char mode) 
{
    lcd_current_color_mode = mode;
    lcd_send_command(CMD_COLOR_MODE);
    lcd_send_byte(mode);
}

void lcd_set_mem_access_ctl(unsigned char flags) 
{
    lcd_send_command(CMD_MEM_ACCESS_CTL);
    lcd_send_byte(flags);
}

void lcd_display(const unsigned char* image) 
{    
    #if LCD_SCAN_DIRECTION == LCD_SCAN_HORIZONTAL
    lcd_set_windows(1, 2, LCD_WIDTH, LCD_HEIGHT+1);
    #elif LCD_SCAN_DIRECTION == LCD_SCAN_VERTICAL
    lcd_set_windows(2, 1, LCD_WIDTH+1, LCD_HEIGHT);
    #endif

    lcd_send_command(CMD_MEMORY_WRITE);

    gpio_put(DC, 1);
    gpio_put(CS, 0);

    if(lcd_current_color_mode == COLOR_MODE_4R4G4B)
        spi_write_blocking(spi1, image, LCD_WIDTH*LCD_HEIGHT*12/8);
    else if(lcd_current_color_mode == COLOR_MODE_5R6G5B)
        spi_write_blocking(spi1, image, LCD_WIDTH*LCD_HEIGHT*16/8);
    else if(lcd_current_color_mode == COLOR_MODE_6R6G6B)
        spi_write_blocking(spi1, image, LCD_WIDTH*LCD_HEIGHT*18/8);
    else
        for(;;);

    gpio_put(CS, 1);
}

void lcd_init() 
{
    spi_init(spi1, SPI_FREQ);
    gpio_set_function(CLK, GPIO_FUNC_SPI);
    gpio_set_function(DIN, GPIO_FUNC_SPI);

    gpio_init(RST);
    gpio_init(DC);
    gpio_init(CS);
    gpio_init(BL);

    gpio_set_dir(RST, GPIO_OUT);
    gpio_set_dir(DC, GPIO_OUT);
    gpio_set_dir(CS, GPIO_OUT);
    gpio_set_dir(BL, GPIO_OUT);

    gpio_put(CS, 1);
    gpio_put(DC, 0);
    gpio_put(BL, 0);
    gpio_put(RST, 0);

    unsigned int slice = pwm_gpio_to_slice_num(BL);
    gpio_set_function(BL, GPIO_FUNC_PWM);
    pwm_set_wrap(slice, 100);
    pwm_set_clkdiv(slice,50);
    pwm_set_enabled(slice, true);
    pwm_set_chan_level(slice, PWM_CHAN_B, 90);

    lcd_reset();
    lcd_set_mem_access_ctl((LCD_SCAN_DIRECTION == LCD_SCAN_HORIZONTAL ? MEM_CTL_MV : MEM_CTL_DEFAULT) | MEM_CTL_MY);
    lcd_set_color_mode(COLOR_MODE_DEFAULT);
    lcd_set_gamma(GAMMA_CURVE_DEFAULT);
    lcd_set_inversion(INVERSION_DEFAULT);
    lcd_set_tearing(TEARING_DEFAULT);

    lcd_set_sleep(false);
    lcd_set_enabled(true);
}