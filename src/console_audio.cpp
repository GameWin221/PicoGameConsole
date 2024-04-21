#include "console_audio.hpp"
#include "console_config.hpp"

#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "hardware/clocks.h"

static uint32_t buzzer_slice{};
static uint32_t buzzer_channel{};
static alarm_id_t buzzer_alarm_id{};

static const ConsoleSound* current_sounds{};
static uint16_t current_sounds_count{};
static uint16_t current_sound_id{};

static int64_t _alarm_callback(alarm_id_t, void*) {
    if (current_sound_id == current_sounds_count) {
        pwm_set_gpio_level(BUZZER_PIN, 0);

        if (buzzer_alarm_id != 0) {
            cancel_alarm(buzzer_alarm_id);
        }

        return 0;
    }

    ConsoleSound sound = current_sounds[current_sound_id];

    if(sound.frequency_hz == 0) {
        pwm_set_gpio_level(BUZZER_PIN, 0);
    } else {
        if(sound.frequency_hz < 60) {
            sound.frequency_hz = 60;
        } else if(sound.frequency_hz > 10000) {
            sound.frequency_hz = 10000;
        }

        float clkdiv = (float)clock_get_hz(clk_sys) / (sound.frequency_hz * PWM_WRAP);

        pwm_set_clkdiv(buzzer_slice, clkdiv);
        pwm_set_gpio_level(BUZZER_PIN, PWM_DUTY);
    }
    
    current_sound_id += 1;

    cancel_alarm(buzzer_alarm_id);

    buzzer_alarm_id = add_alarm_in_ms(sound.duration_ms, _alarm_callback, nullptr, true);

    return 0;
}

void console_audio_init() {
    gpio_init(BUZZER_PIN);
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

	buzzer_slice = pwm_gpio_to_slice_num(BUZZER_PIN);
    buzzer_channel = pwm_gpio_to_channel(BUZZER_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, PWM_WRAP);
    pwm_init(buzzer_slice, &config, true);

    pwm_set_gpio_level(BUZZER_PIN, 0);
}

void console_audio_play_sounds(const ConsoleSound* sounds, uint16_t count) {
    current_sounds = sounds;
    current_sounds_count = count;
    current_sound_id = 0;

    if (buzzer_alarm_id != 0) {
        cancel_alarm(buzzer_alarm_id);
    }

    add_alarm_in_ms(0, _alarm_callback, nullptr, true);
}