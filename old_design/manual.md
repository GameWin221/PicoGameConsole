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
