#include "games_list.hpp"

#include <lcd_fonts/lcd_fonts.hpp>
#include <console_draw.hpp>
#include <console_lcd.hpp>

#include <console_core.hpp>
#include <console_audio.hpp>
#include <console_timing.hpp>
#include <console_input.hpp>

static void game_demo_init() {
	
}
static void game_demo_exit() {
	
}
static void game_demo_update(const ConsoleInput& input, const ConsoleTiming& timing) {
	console_draw_fill(RGB565(0, 0, 0));

    console_draw_string(0, 5, 0xfff, "Select a game:", lcd_font_16px);
    console_draw_string(0, 32, 0xfff, "Left button - Demo", lcd_font_12px);
    console_draw_string(0, 52, 0xfff, "Right button - Doom", lcd_font_12px);

    if (input.button_left && input.button_left_changed) {
        console_core_load_game(game_demo_info);
    } else if(input.button_right && input.button_right_changed) {
        console_core_load_game(game_doom_info);
    }
}

GameInfo game_menu_info {
	.game_init_fn = game_demo_init,
	.game_exit_fn = game_demo_exit,
	.game_update_fn = game_demo_update
};