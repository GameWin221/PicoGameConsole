#ifndef CONSOLE_IO_HPP
#define CONSOLE_IO_HPP

struct ConsoleInput
{
    float joystick_x{}, joystick_y{};

    bool joystick_button{};
    
    bool button_right{}, button_left{};
};

extern void console_io_init();
extern void console_io_poll(ConsoleInput* console_input);
extern void console_io_buzzer(bool state);

extern float console_io_temperature();

#endif