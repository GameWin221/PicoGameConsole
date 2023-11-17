cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(GameOnConsole C CXX ASM)

pico_sdk_init()

file(GLOB GAME_CONSOLE_SRC CONFIGURE_DEPENDS "*.hpp" "*.cpp" "*/*.hpp" "*/*.cpp")

add_executable(${PROJECT_NAME} ${GAME_CONSOLE_SRC})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

target_link_libraries(${PROJECT_NAME} pico_stdlib pico_time hardware_spi hardware_pwm hardware_adc pico_multicore)

pico_add_extra_outputs(${PROJECT_NAME})