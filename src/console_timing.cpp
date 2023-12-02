#include "console_timing.hpp"

#include <pico/time.h>

static uint64_t last_frame_us{};

void console_timing_init()
{
    last_frame_us = get_absolute_time();
    last_frame_us = to_us_since_boot(get_absolute_time());
}

void console_timing_update(ConsoleTiming* timing)
{
    timing->us_since_start = to_us_since_boot(get_absolute_time());

	timing->delta_time = (timing->us_since_start - last_frame_us) / 1000000.0f;
    timing->time_since_start += timing->delta_time;

    timing->ticks_since_start++;

    last_frame_us = timing->us_since_start;
}

void console_timing_wait_ms(uint32_t milliseconds)
{
    sleep_ms(milliseconds);
}

void console_timing_wait_us(uint32_t microseconds)
{
    sleep_us(microseconds);
}