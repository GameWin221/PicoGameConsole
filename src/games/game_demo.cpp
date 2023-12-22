#include "games_list.hpp"

#include <lcd_fonts/lcd_fonts.hpp>
#include <console_draw.hpp>
#include <console_lcd.hpp>

#include <console_core.hpp>
#include <console_audio.hpp>
#include <console_timing.hpp>
#include <console_input.hpp>

constexpr static ConsoleSound left_button_sounds[1] = {
	{ 200, 100 }
};
constexpr static ConsoleSound right_button_sounds[1] = {
	{ 600, 100 }
};
constexpr static ConsoleSound both_button_sounds[11] = {
	{ 200, 200 },
	{ 0, 200 },
	{ 200, 200 },
	{ 0, 100 },
	{ 240, 400 },
	{ 0, 100 },
	{ 200, 400 },
	{ 0, 100 },
	{ 270, 400 },
	{ 0, 100 },
	{ 245, 600 }
};

static void game_demo_init() {
	
}
static void game_demo_exit() {
	
}
static void game_demo_update(const ConsoleInput& input, const ConsoleTiming& timing) {
    if(input.button_right && input.button_left && (input.button_left_changed || input.button_right_changed)) {
		console_audio_play_sounds(both_button_sounds, 11);
	} else if(input.button_right && input.button_right_changed) {
		console_audio_play_sounds(right_button_sounds, 1);
	} else if(input.button_left && input.button_left_changed) {
		console_audio_play_sounds(left_button_sounds, 1);
	}

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