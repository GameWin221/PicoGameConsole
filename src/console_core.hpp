#ifndef CONSOLE_CORE_HPP
#define CONSOLE_CORE_HPP

#include <inttypes.h>

struct ConsoleTiming 
{
    float delta_time = 0.0f;
    float time_since_start = 0.0f;

    uint64_t ticks_since_start = 0;
    uint64_t us_since_start = 0;
};

extern void console_core_init();
extern void console_core_update_time(ConsoleTiming* timing);
extern void console_core_wait_ms(uint32_t milliseconds);
extern void console_core_wait_us(uint32_t microseconds);

extern void console_core_load_game(const struct GameInfo* game_info);
extern void console_core_update_game(const struct ConsoleInput* input, const ConsoleTiming* timing);

#endif