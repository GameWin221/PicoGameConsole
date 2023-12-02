#include "games_list.hpp"

#include <lcd_fonts/lcd_fonts.hpp>
#include <console_draw.hpp>
#include <console_lcd.hpp>

#include <console_core.hpp>
#include <console_audio.hpp>
#include <console_input.hpp>

static void game_demo_init()
{
	
}
static void game_demo_exit()
{
	
}
static void game_demo_update(const ConsoleInput& input, const ConsoleTiming& timing)
{
    if(input.button_right && input.button_left)
		console_audio_buzzer(40.0f, 0.3f);
	else if(input.button_right)
		console_audio_buzzer(20.0f, 0.3f);
	else if(input.button_left)
		console_audio_buzzer(10.0f, 0.3f);
	else
		console_audio_buzzer(1.0, 0.0f);

	int16_t joy_icon_x = (int16_t)(input.joystick_x * -40);
	int16_t joy_icon_y = (int16_t)(input.joystick_y * -40);

	console_draw_fill(RGB565(0, 127, 0));

	console_draw_string(1, 1, 0xffff, "Hello World!", lcd_font_16px);

    console_draw_rectangle(LCD_WIDTH / 2 - 40 - 1, LCD_HEIGHT / 2 - 40 - 1, LCD_WIDTH / 2 + 40 - 1, LCD_HEIGHT / 2 + 40 - 1, RGB565(0, 0, 0));
	console_draw_rectangle(LCD_WIDTH / 2 - 5 - 1 + joy_icon_x, LCD_HEIGHT / 2 - 5 - 1 + joy_icon_y, LCD_WIDTH / 2 + 5 - 1 + joy_icon_x, LCD_HEIGHT / 2 + 5 - 1 + joy_icon_y, RGB565(255, 255, 255));
	console_draw_rectangle(5 - 1, LCD_HEIGHT / 2 - 15 - 1, 5 - 1 + 30, LCD_HEIGHT / 2 + 15 - 1, input.button_left ? 0x0000 : 0xffff);
	console_draw_rectangle(LCD_WIDTH - 35 - 1, LCD_HEIGHT / 2 - 15 - 1, LCD_WIDTH - 35 - 1 + 30, LCD_HEIGHT / 2 + 15 - 1, input.button_right ? 0x0000 : 0xffff);
}

GameInfo game_demo_info {
	.game_init_fn = game_demo_init,
	.game_exit_fn = game_demo_exit,
	.game_update_fn = game_demo_update
};