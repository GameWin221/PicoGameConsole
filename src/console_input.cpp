#include "console_input.hpp"

#include <pico/stdlib.h>
#include <pico/stdio.h>
#include <stdio.h>
#include <hardware/adc.h>

#define JOYSTICK_XAXIS_PIN 27
#define JOYSTICK_YAXIS_PIN 26

#define BUTTON_LEFT_PIN 16
#define BUTTON_RIGHT_PIN 17

void console_input_init() {
    stdio_init_all();  

	adc_init();
	
	adc_gpio_init(JOYSTICK_XAXIS_PIN);
	adc_gpio_init(JOYSTICK_YAXIS_PIN);

	gpio_init(BUTTON_LEFT_PIN);
	gpio_set_dir(BUTTON_LEFT_PIN, GPIO_IN);
	gpio_pull_down(BUTTON_LEFT_PIN);

	gpio_init(BUTTON_RIGHT_PIN);
	gpio_set_dir(BUTTON_RIGHT_PIN, GPIO_IN);
	gpio_pull_down(BUTTON_RIGHT_PIN);
}

void console_input_poll(ConsoleInput* console_input) {
    adc_select_input(JOYSTICK_XAXIS_PIN-26);
	console_input->joystick_x = ((float)(adc_read() * 2) / 4095.0f - 1.0f);
	
	adc_select_input(JOYSTICK_YAXIS_PIN-26);
	console_input->joystick_y = -((float)(adc_read() * 2) / 4095.0f - 1.0f);

	bool button_left = gpio_get(BUTTON_LEFT_PIN);
	bool button_right = gpio_get(BUTTON_RIGHT_PIN);

	console_input->button_left_changed = button_left != console_input->button_left;
	console_input->button_left = button_left;

	console_input->button_right_changed = button_right != console_input->button_right;
	console_input->button_right = button_right;
}