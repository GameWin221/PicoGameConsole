#ifndef CONSOLE_TIMING_HPP
#define CONSOLE_TIMING_HPP

#include <inttypes.h>

struct ConsoleTiming 
{
    float delta_time = 0.0f;
    float time_since_start = 0.0f;

    uint64_t ticks_since_start = 0;
    uint64_t us_since_start = 0;
};

extern void console_timing_init();
extern void console_timing_update(ConsoleTiming* timing);
extern void console_timing_wait_ms(uint32_t milliseconds);
extern void console_timing_wait_us(uint32_t microseconds);

#endif