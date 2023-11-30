#include "console_core.hpp"
#include "games/games_list.hpp"

#include <pico/time.h>

static void (*console_core_init_fn)() = nullptr; 
static void (*console_core_exit_fn)() = nullptr; 
static void (*console_core_update_fn)(const struct ConsoleInput* input, const ConsoleTiming* timing) = nullptr; 

static uint64_t last_frame_us{};

void console_core_init()
{
    last_frame_us = get_absolute_time();
    last_frame_us = to_us_since_boot(get_absolute_time());
}

void console_core_update_time(ConsoleTiming* timing)
{
    timing->us_since_start = to_us_since_boot(get_absolute_time());

	timing->delta_time = (timing->us_since_start - last_frame_us) / 1000000.0f;
    timing->time_since_start += timing->delta_time;

    timing->ticks_since_start++;

    last_frame_us = timing->us_since_start;
}

void console_core_wait_ms(uint32_t milliseconds)
{
    sleep_ms(milliseconds);
}

void console_core_wait_us(uint32_t microseconds)
{
    sleep_us(microseconds);
}

void console_core_load_game(const struct GameInfo* game_info)
{
    if(console_core_exit_fn)
        console_core_exit_fn();

    if(game_info == nullptr)
    {
        console_core_init_fn = nullptr;
        console_core_update_fn = nullptr;
        console_core_exit_fn = nullptr;
    }

    console_core_init_fn = game_info->game_init_fn;
    console_core_exit_fn = game_info->game_exit_fn;
    console_core_update_fn = game_info->game_update_fn;

    console_core_init_fn();
}

void console_core_update_game(const struct ConsoleInput* input, const ConsoleTiming* timing)
{
    if(console_core_update_fn)
        console_core_update_fn(input, timing);
}