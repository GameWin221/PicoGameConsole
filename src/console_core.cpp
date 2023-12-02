#include "console_core.hpp"
#include "games/games_list.hpp"

#include <pico/time.h>

static void (*console_core_init_fn)() = nullptr; 
static void (*console_core_exit_fn)() = nullptr; 
static void (*console_core_update_fn)(const struct ConsoleInput& input, const struct ConsoleTiming& timing) = nullptr; 

void console_core_load_game(const struct GameInfo& game_info)
{
    if(console_core_exit_fn)
        console_core_exit_fn();

    console_core_init_fn = game_info.game_init_fn;
    console_core_exit_fn = game_info.game_exit_fn;
    console_core_update_fn = game_info.game_update_fn;

    console_core_init_fn();
}

void console_core_update_game(const struct ConsoleInput& input, const struct ConsoleTiming& timing)
{
    if(console_core_update_fn)
        console_core_update_fn(input, timing);
}