#ifndef CONSOLE_AUDIO_HPP
#define CONSOLE_AUDIO_HPP

#include <cinttypes>

extern void console_audio_init();
extern void console_audio_buzzer(uint16_t frequency_hz, uint16_t duration_ms);

#endif