#include "console_lcd.hpp"
#include "console_config.hpp"

#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

static uint8_t console_lcd_current_color_mode = 0;

static inline void send_command(uint8_t cmd) {
    gpio_put(LCD_DC, 0);
    gpio_put(LCD_CS, 0);
    spi_write_blocking(SPI_CHANNEL, &cmd, 1);
    gpio_put(LCD_CS, 1);
}

static inline void send_byte(uint8_t data) {
    gpio_put(LCD_DC, 1);
    gpio_put(LCD_CS, 0);
    spi_write_blocking(SPI_CHANNEL, &data, 1);
    gpio_put(LCD_CS, 1);
}

static inline void reset() {
    gpio_put(LCD_RST, 1);
    sleep_ms(2);
    gpio_put(LCD_RST, 0);
    sleep_ms(2);
    gpio_put(LCD_RST, 1);
    sleep_ms(2);
}

static void set_windows(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd) {
    // Set X coordinate
    send_command(LCD_CMD_COLUMN_ADDR_SET);
    send_byte(0x00);
    send_byte(xStart);
    send_byte(0x00);
    send_byte(xEnd);

    // Set Y coordinate
    send_command(LCD_CMD_ROW_ADDR_SET);
    send_byte(0x00);
    send_byte(yStart);
    send_byte(0x00);
    send_byte(yEnd);
}

void console_lcd_set_inversion(uint8_t inversion) {
    send_command(inversion ? LCD_CMD_INVERSION_ON : LCD_CMD_INVERSION_OFF);
}
void console_lcd_set_sleep(uint8_t sleep)  {
    send_command(sleep ? LCD_CMD_SLEEP_IN : LCD_CMD_SLEEP_OUT);
}

void console_lcd_set_gamma(uint8_t gamma)  {
    send_command(LCD_CMD_GAMMA_SET);
    send_byte(gamma);
}

void console_lcd_set_enabled(uint8_t enabled) {
    send_command(enabled ? LCD_CMD_DISPLAY_ON : LCD_CMD_DISPLAY_OFF);
}

void console_lcd_set_tearing(uint8_t tearing) {
    if(tearing != LCD_TEARING_OFF) {
        send_command(LCD_CMD_TEARING_ON);
        send_byte(tearing);
    } else {
        send_command(LCD_CMD_TEARING_OFF);
    }
}

void console_lcd_set_color_mode(uint8_t mode) {
    console_lcd_current_color_mode = mode;
    send_command(LCD_CMD_COLOR_MODE);
    send_byte(mode);
}

void console_lcd_set_mem_access_ctl(uint8_t flags) {
    send_command(LCD_CMD_MEM_ACCESS_CTL);
    send_byte(flags);
}

void console_lcd_display(const uint8_t* image) {   
    #if LCD_SCAN_DIRECTION == LCD_SCAN_HORIZONTAL
    set_windows(1, 2, LCD_WIDTH, LCD_HEIGHT+1);
    #elif LCD_SCAN_DIRECTION == LCD_SCAN_VERTICAL
    set_windows(2, 1, LCD_WIDTH+1, LCD_HEIGHT);
    #endif

    send_command(LCD_CMD_MEMORY_WRITE);

    gpio_put(LCD_DC, 1);
    gpio_put(LCD_CS, 0);

    if(console_lcd_current_color_mode == LCD_COLOR_MODE_4R4G4B) {
        spi_write_blocking(SPI_CHANNEL, image, LCD_WIDTH*LCD_HEIGHT*12/8);
    } else if(console_lcd_current_color_mode == LCD_COLOR_MODE_5R6G5B) {
        spi_write_blocking(SPI_CHANNEL, image, LCD_WIDTH*LCD_HEIGHT*16/8);
    } else if(console_lcd_current_color_mode == LCD_COLOR_MODE_6R6G6B) {
        spi_write_blocking(SPI_CHANNEL, image, LCD_WIDTH*LCD_HEIGHT*18/8);
    } else {
        for(;;);
    }

    gpio_put(LCD_CS, 1);
}

void console_lcd_init() {
    spi_init(SPI_CHANNEL, SPI_FREQ);
    gpio_set_function(LCD_CLK, GPIO_FUNC_SPI);
    gpio_set_function(LCD_DIN, GPIO_FUNC_SPI);

    gpio_init(LCD_RST);
    gpio_init(LCD_DC);
    gpio_init(LCD_CS);
    gpio_init(LCD_BL);

    gpio_set_dir(LCD_RST, GPIO_OUT);
    gpio_set_dir(LCD_DC, GPIO_OUT);
    gpio_set_dir(LCD_CS, GPIO_OUT);
    gpio_set_dir(LCD_BL, GPIO_OUT);

    gpio_put(LCD_CS, 1);
    gpio_put(LCD_DC, 0);
    gpio_put(LCD_BL, 1);
    gpio_put(LCD_RST, 0);

    reset();
    console_lcd_set_mem_access_ctl((LCD_SCAN_DIRECTION == LCD_SCAN_HORIZONTAL ? LCD_MEM_CTL_MV : LCD_MEM_CTL_DEFAULT) | LCD_MEM_CTL_MY);
    console_lcd_set_color_mode(LCD_COLOR_MODE_DEFAULT);
    console_lcd_set_gamma(LCD_GAMMA_CURVE_DEFAULT);
    console_lcd_set_inversion(LCD_INVERSION_DEFAULT);
    console_lcd_set_tearing(LCD_TEARING_DEFAULT);

    console_lcd_set_sleep(false);
    console_lcd_set_enabled(true);
}