#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <pico/stdlib.h>
#include <pico/time.h>

#include "lcd_fonts/lcd_fonts.hpp"
#include "lcd.hpp"
#include "lcd_draw.hpp"
#include "console_io.hpp"

// Overclock frequency, 133kHz is default
#define PICO_CORE_FREQ 120000

/// Potential optimisations:
// Second core for SPI canvas transfer

void panic_msg(const char* msg)
{
	lcd_draw_fill(RGB565(0, 0, 0));
	lcd_draw_string(2, 2, msg, &lcd_font_12px, 0xffff, 0, true);
	lcd_display((const uint8_t*)lcd_draw_get_canvas());

	for(;;);
}

int main()
{
	console_io_init();

	lcd_init();

	if(!set_sys_clock_khz(PICO_CORE_FREQ, true))
		panic_msg("set_sys_clock_khz fail");

	float dt = 0.0;

	uint64_t last_frame = to_us_since_boot(get_absolute_time());
	uint64_t now = last_frame;

	ConsoleInput input{};

	while(true)
	{
		now = to_us_since_boot(get_absolute_time());

		dt = (now - last_frame) / 1000000.0f;

		last_frame = now;

		console_io_poll(&input);
		console_io_buzzer(input.button_right);

		int16_t joy_icon_x = (int16_t)(input.joystick_x * -40);
		int16_t joy_icon_y = (int16_t)(input.joystick_y * -40);

		lcd_draw_fill(RGB565(0, 127, 0));

		lcd_draw_string(2, 2, "Hello World!", &lcd_font_12px, 0xffff, 0x0000, true);

		lcd_draw_rectangle(LCD_WIDTH / 2 - 40 - 1, LCD_HEIGHT / 2 - 40 - 1, LCD_WIDTH / 2 + 40 - 1, LCD_HEIGHT / 2 + 40 - 1, RGB565(0, 0, 0));
		lcd_draw_rectangle(LCD_WIDTH / 2 - 5 - 1 + joy_icon_x, LCD_HEIGHT / 2 - 5 - 1 + joy_icon_y, LCD_WIDTH / 2 + 5 - 1 + joy_icon_x, LCD_HEIGHT / 2 + 5 - 1 + joy_icon_y, RGB565(255, 255, 255));

		lcd_draw_rectangle(5 - 1, LCD_HEIGHT / 2 - 15 - 1, 5 - 1 + 30, LCD_HEIGHT / 2 + 15 - 1, input.button_left ? 0x0000 : 0xffff);
		lcd_draw_rectangle(LCD_WIDTH - 35 - 1, LCD_HEIGHT / 2 - 15 - 1, LCD_WIDTH - 35 - 1 + 30, LCD_HEIGHT / 2 + 15 - 1, input.button_right ? 0x0000 : 0xffff);

		lcd_display((const uint8_t*)lcd_draw_get_canvas());

		sleep_ms(2);
	}
}