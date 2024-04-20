# Shamino Console
My own game console powered by Raspberry Pi Pico and ST7735 LCD display.

### Software Design
The console framework is made to be **elegant**, **readable** and as **performant** as possible. It is written in C++ only for some convenience features and most of it is almost pure embedded-style C. Thanks to the functional and modular code structure it is easy to port it for other platforms.

You can make your own game just by declaring a new `GameInfo` inside `games_list.hpp` file and defining its functions inside other `.cpp` file. (Look at other example games provided in the repository)

### Hardware Design
The new improved version of the "Shamino Console" now features a custom PCB. This greatly improves the general quality of the console. It just looks and feels better now :)

There will be a 3D printed casing for it soon.

<img src="/pcb/pico_game_console/picogameconsole2.png" alt="picogameconsole.png" width="800"/>

To see the old version, look inside the `/old_design` directory.

### Required componnts:
- [Raspberry Pi Pico (W)](https://www.raspberrypi.com/products/raspberry-pi-pico/)

- [Waveshare ST7735 1.8" LCD](https://www.waveshare.com/wiki/1.8inch_LCD_Module)

- [Generic Thumb Joystick](https://botland.store/joystick/1942-thumb-joystick-5904422356231.html)

- 2x [12mm x 12mm Tact Switches](https://botland.store/tact-switch/3663-tact-switch-12x12mm-with-cap-red-mushroom-5pcs-5904422307486.html)

- [Female Connectors for Raspberry Pi Pico](https://botland.store/raspberry-pi-pico-accessories/18863-set-of-female-connectors-for-raspberry-pi-pico-5904422328528.html)

- [5V 12mm Passive Buzzer](https://botland.store/buzzers-sound-generators/18290-buzzer-without-generator-5v-1mm-tht-5904422366025.html)

- ~47Ω Resistor

- ~4,7kΩ Resistor

- [1x8 Goldpin connector](https://botland.store/connectors-goldpin/20031-straight-goldpin-1x40-connector-with-254mm-pitch-black-10pcs-justpi-5904422329198.html)

- (Optional) 2x 5mm M3 Screw to mount the LCD

- 4x 10mm M3 Screws to mount the PCB to the 3D printed casing.

- [Battery Holder for 2x AA batteries **with a power switch** (3x AA batteries will work fine too)](https://botland.store/battery-holders/738-battery-holder-for-2-aa-r6-batteries-with-cover-and-switch-5904422329617.html)

# How to compile? 
### Prerequisites
- [Pico SDK](https://github.com/raspberrypi/pico-sdk) (St the `PICO_SDK_PATH` enviromental variable)
- [ARM Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) (Set the `PICO_TOOLCHAIN_PATH` enviromental variable)
- [CMake](https://cmake.org/) (Add to path)
- [MinGW](https://winlibs.com/) or other C++ compiler (Add to path)

### Commands (Using MinGW):
1. `mkdir build && cd build`
2. `cmake -G "MinGW Makefiles" ..`
3. `make` or `mingw32-make`
4. If everything compiled successfully - copy the `GameOnConsole.uf2` file to your Pico

On Windows you can use the `run.bat` script (You will most likely need to specify the target drive which is your Pico)