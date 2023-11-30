#include "lcd_fonts/lcd_fonts.hpp"
#include "lcd.hpp"
#include "lcd_draw.hpp"
#include "console_core.hpp"
#include "console_audio.hpp"
#include "console_input.hpp"

#include "games/games_list.hpp"

/// Potential optimisations:
// Second core for SPI canvas transfer
// Update only a part of the screen (set Windows before draw)

/// TODO:
// Audio queue, maybe separate thread?
// Make audio an IRQ handle and make the speaker math use Hz values
// Make audio use accurate Hz values
// Make LCD a part of the 'console' library
// Make my own font
// Actual games

int main()
{
	ConsoleInput input{};
	ConsoleTiming timing{};

	lcd_init();

	console_core_init();
	console_input_init();
	console_audio_init();
	
	console_core_load_game(&game_demo_info);

	while(true)
	{
		console_input_poll(&input);
		console_core_update_time(&timing);

		console_core_update_game(&input, &timing);

		lcd_display((const uint8_t*)lcd_draw_get_canvas());
	}
}