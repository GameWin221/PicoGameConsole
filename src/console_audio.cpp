#include "console_audio.hpp"

#include <pico/stdlib.h>
#include <hardware/adc.h>
#include <hardware/pwm.h>

#define BUZZER_PIN 19

static uint32_t buzzer_pin_slice{};

void console_audio_init()
{
    gpio_init(BUZZER_PIN);
	gpio_set_dir(BUZZER_PIN, GPIO_OUT);
	gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

	// Run buzzer at 1000Hz
	buzzer_pin_slice = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_clkdiv(buzzer_pin_slice, SYS_CLK_KHZ / 100.0f);
    pwm_set_wrap(buzzer_pin_slice, 10000);
    pwm_set_enabled(buzzer_pin_slice, true);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

void console_audio_buzzer(float frequency, float volume)
{
	float wrap = 10000.0f / frequency;
	pwm_set_wrap(buzzer_pin_slice, (uint16_t)wrap);
	pwm_set_gpio_level(BUZZER_PIN, (uint16_t)(wrap * volume));
}