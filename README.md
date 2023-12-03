# PicoGameConsole
My game console powered by Raspberry Pi Pico and an ST7735 LCD display.

### Software Design
The console framework is made to be **elegant**, **readable** and as **performant** as possible. It is written in C++ only for some convenience features and most of it is almost pure embedded-style C. Thanks to the functional and modular code structure it is easy to port it for other platforms.

You can make your own game just by declaring a new `GameInfo` inside `games_list.hpp` file and defining its functions inside other `.cpp` file. (Look at other example games provided in the repository)

### Hardware/3D Print Design
I know the design is really poor and the assembly won't be easy but it might improve over time. I definitely wouldn't consider myself an electrical engineer ;)

<img src="https://github.com/GameWin221/PicoGameConsole/assets/72656547/d8c7c89d-9682-4cd6-8720-f5b30de5c2ff" alt="drawing1" width="400"/>
<img src="https://github.com/GameWin221/PicoGameConsole/assets/72656547/6c2c1a7e-9e3a-4989-8c76-0ffd25bf83aa" alt="drawing2" width="400"/>

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

# How to assemble?

### Required Components:
- [Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/)

- [Waveshare ST7735 1.8" LCD](https://www.waveshare.com/wiki/1.8inch_LCD_Module)

- [Iduino ST1079 Joystick Module](https://botland.store/joystick/4093-thumb-joystick-with-v2-button-module-with-a-5903351241441.html)

- 2x [6x6mm / 4,3mm Tact Switches](https://botland.store/tact-switch/377-tact-switch-6x6mm-43mm-dip-5-pcs-5904422307622.html)

- [5V Active Buzzer](https://botland.store/buzzers-sound-generators/786-active-buzzer-with-generator-5v-12mm-tht-5904422366940.html)

- 6x M3 **Exactly 10mm** Screws

- 2x M3 Hex Nuts

- 2x M3 10-30mm Screws

- 2x AA Battery Holder

- 2x AA Battery

### Component Connection Diagram:
Look at the `wiring_diagram.svg` file provided in the repository for better quality.

<img src="https://github.com/GameWin221/PicoGameConsole/assets/72656547/3dd5a16d-ea45-400f-b820-1fa6d51b2558" alt="drawing1" width="1000"/>

*The diagram was made with the EasyEDA editor.*

### 3D Printed Case:
Fusion 360 Project Link: https://a360.co/3T8A1c6 or use the .stl files provided in the repository.

### Required Tools:
- Soldering iron
- Glue that works on 3D printed plasic
- Hex screwdriver that fits M3 screws

### Assembly Instructions:
- Glue `PushBlock.stl` on the bottom side under `Holder.stl`'s tact switch poles. (This will ensure that Raspberry Pi Pico doesn't move inside.
- Glue the tact switches to the tact switch poles on `Holder.stl`.
- Screw the LCD display and the joystick module to `Holder.stl`.
- Screw `UpperCover.stl` to `Holder.stl`.
- Put in the buzzer (and glue it in if necessary) in the hole on the top of `UpperCover.stl`.
- Connect all of the components as shown on the component connection diagram.
- Put the Raspberry Pi Pico upside down with its micro-usb port facing the micro-usb hole in the 3D printed case.
- Screw `UpperCover.stl` and `BottomCover.stl` together. (Make sure no wires get damaged)
