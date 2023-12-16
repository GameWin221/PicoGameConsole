#include "console_audio.hpp"

#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "hardware/clocks.h"

#define BUZZER_PIN 19

// 20% duty cycle results in better audio quality for a buzzer
// (in case of an usual speaker 50% is usually the best)
#define PWM_WRAP 10000
#define PWM_DUTY (PWM_WRAP / 5)

static uint32_t buzzer_slice{};
static uint32_t buzzer_channel{};

static alarm_id_t buzzer_alarm_id{};

static int64_t _alarm_callback(alarm_id_t, void*) {
    pwm_set_gpio_level(BUZZER_PIN, 0);
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

void console_audio_buzzer(uint16_t frequency_hz, uint16_t duration_ms) {
	if(frequency_hz == 0 || duration_ms == 0) return;

    // Safe bounds
    if(frequency_hz < 60) {
        frequency_hz = 60;
    } else if(frequency_hz > 10000) {
        frequency_hz = 10000;
    }

    float clkdiv = (float)clock_get_hz(clk_sys) / (frequency_hz * PWM_WRAP);
    
    pwm_set_clkdiv(buzzer_slice, clkdiv);
    pwm_set_gpio_level(BUZZER_PIN, PWM_DUTY);
    
    if (buzzer_alarm_id != 0) {
        cancel_alarm(buzzer_alarm_id);
    }

    buzzer_alarm_id = add_alarm_in_ms(duration_ms, _alarm_callback, nullptr, true);
}