#include "console_io.hpp"

#include <pico/stdlib.h>
#include <hardware/adc.h>

#define JOYSTICK_BUTTON_PIN 15
#define JOYSTICK_XAXIS_PIN 26
#define JOYSTICK_YAXIS_PIN 27

#define BUTTON_LEFT_PIN 16
#define BUTTON_RIGHT_PIN 17
#define BUTTON_POWER_PIN 18

#define BUZZER_PIN 19

void console_io_init()
{
    stdio_init_all();  

	adc_init();
	adc_set_temp_sensor_enabled(true);

	adc_gpio_init(JOYSTICK_XAXIS_PIN);
	adc_gpio_init(JOYSTICK_YAXIS_PIN);

	gpio_init(JOYSTICK_BUTTON_PIN);
	gpio_set_dir(JOYSTICK_BUTTON_PIN, GPIO_IN);

	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
	gpio_put(PICO_DEFAULT_LED_PIN, 1);

	gpio_init(BUZZER_PIN);
	gpio_set_dir(BUZZER_PIN, GPIO_OUT);

	gpio_init(BUTTON_POWER_PIN);
	gpio_set_dir(BUTTON_POWER_PIN, GPIO_OUT);
	gpio_put(BUTTON_POWER_PIN, 1);

	gpio_init(BUTTON_LEFT_PIN);
	gpio_set_dir(BUTTON_LEFT_PIN, GPIO_IN);

	gpio_init(BUTTON_RIGHT_PIN);
	gpio_set_dir(BUTTON_RIGHT_PIN, GPIO_IN);
}

void console_io_poll(ConsoleInput* console_input)
{
    adc_select_input(JOYSTICK_XAXIS_PIN-26);
	console_input->joystick_x = ((float)adc_read() / 4096.0f * 2.0f - 1.0f)/* + 0.08f*/;
	
	adc_select_input(JOYSTICK_YAXIS_PIN-26);
	console_input->joystick_y = ((float)adc_read() / 4096.0f * 2.0f - 1.0f)/* + 0.08f*/;

	console_input->button_left = gpio_get(BUTTON_LEFT_PIN);
	console_input->button_right = gpio_get(BUTTON_RIGHT_PIN);
}

float console_io_temperature()
{
	adc_select_input(4);
	return 27.0f - (((float)adc_read() * (3.3f / 4096)) - 0.706f)/0.001721f;
}

void console_io_buzzer(bool state)
{
    gpio_put(BUZZER_PIN, state);
}