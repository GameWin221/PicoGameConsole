#include "console_input.hpp"

#include <pico/stdlib.h>
#include <hardware/adc.h>

#define JOYSTICK_BUTTON_PIN 15
#define JOYSTICK_XAXIS_PIN 26
#define JOYSTICK_YAXIS_PIN 27

#define BUTTON_LEFT_PIN 16
#define BUTTON_RIGHT_PIN 17
#define BUTTON_POWER_PIN 18

void console_input_init() {
    stdio_init_all();  

	adc_init();

	adc_gpio_init(JOYSTICK_XAXIS_PIN);
	adc_gpio_init(JOYSTICK_YAXIS_PIN);

	gpio_init(JOYSTICK_BUTTON_PIN);
	gpio_set_dir(JOYSTICK_BUTTON_PIN, GPIO_IN);

	gpio_init(BUTTON_POWER_PIN);
	gpio_set_dir(BUTTON_POWER_PIN, GPIO_OUT);
	gpio_put(BUTTON_POWER_PIN, 1);

	gpio_init(BUTTON_LEFT_PIN);
	gpio_set_dir(BUTTON_LEFT_PIN, GPIO_IN);

	gpio_init(BUTTON_RIGHT_PIN);
	gpio_set_dir(BUTTON_RIGHT_PIN, GPIO_IN);
}

void console_input_poll(ConsoleInput* console_input) {
	// use 3723.64 instead of 4096 in order to make it work with 3.0V instead of 3.3V
	// ADC reading 3.3V -> 4096.0
	// ADC reading 3.0V -> 3723.64

    adc_select_input(JOYSTICK_XAXIS_PIN-26);
	console_input->joystick_x = ((float)adc_read() / 3723.64f * 2.0f - 1.0f);
	
	adc_select_input(JOYSTICK_YAXIS_PIN-26);
	console_input->joystick_y = ((float)adc_read() / 3723.64f * 2.0f - 1.0f);

	bool joystick_button = gpio_get(JOYSTICK_BUTTON_PIN);
	bool button_left = gpio_get(BUTTON_LEFT_PIN);
	bool button_right = gpio_get(BUTTON_RIGHT_PIN);

	console_input->joystick_button_changed = joystick_button != console_input->joystick_button;
	console_input->joystick_button = joystick_button;

	console_input->button_left_changed = button_left != console_input->button_left;
	console_input->button_left = button_left;

	console_input->button_right_changed = button_right != console_input->button_right;
	console_input->button_right = button_right;
}