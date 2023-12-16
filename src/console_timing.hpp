#ifndef CONSOLE_TIMING_HPP
#define CONSOLE_TIMING_HPP

#include <cinttypes>

struct ConsoleTiming {
    float delta_time{};
    float time_since_start{};

    uint64_t ticks_since_start{};
    uint64_t us_since_start{};
};

extern void console_timing_init();
extern void console_timing_wait_ms(uint32_t milliseconds);
extern void console_timing_wait_us(uint32_t microseconds);

// NEVER call inside a game's update function (will break timing)
extern void console_timing_update(ConsoleTiming* timing);

#endif