#ifndef CONSOLE_AUDIO_HPP
#define CONSOLE_AUDIO_HPP

#include <cinttypes>

struct ConsoleSound {
    uint16_t frequency_hz, duration_ms;
};

extern void console_audio_init();
extern void console_audio_play_sounds(const ConsoleSound* sounds, uint16_t count);

#endif