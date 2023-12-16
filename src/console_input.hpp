#ifndef CONSOLE_INPUT_HPP
#define CONSOLE_INPUT_HPP

struct ConsoleInput {
    float joystick_x = 0.0f;
    float joystick_y = 0.0f;

    bool joystick_button = false;
    bool joystick_button_changed = false;

    bool button_right = false;
    bool button_right_changed = false;

    bool button_left = false;
    bool button_left_changed = false;
};

extern void console_input_init();
extern void console_input_poll(ConsoleInput* console_input);

#endif