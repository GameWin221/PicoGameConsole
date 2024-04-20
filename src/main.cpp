#include "lcd_fonts/lcd_fonts.hpp"
#include "console_lcd.hpp"
#include "console_draw.hpp"
#include "console_core.hpp"
#include "console_timing.hpp"
#include "console_audio.hpp"
#include "console_input.hpp"

#include "games/games_list.hpp"

/// Potential optimisations:
// Second core for SPI canvas transfer
// Update only a part of the screen (set Windows before draw)
// Use uint16_fast_t

/// TODO:
// Make my own font
// Fix the bottom line (visible in doom game)
// README
// Improve console_audio module to use actual hz values
// Improve console_lcd module to sync with horizontal and vertical lines signals (pseudo vsync)

int main() {
	ConsoleInput input{};
	ConsoleTiming timing{};
	
	console_lcd_init();
	console_timing_init();
	console_input_init();
	console_audio_init();
	
	console_core_load_game(game_menu_info);

	while(true) {
		console_input_poll(&input);
		console_timing_update(&timing);
		console_core_update_game(input, timing);
		console_lcd_display((const uint8_t*)console_draw_get_canvas());
	}
}