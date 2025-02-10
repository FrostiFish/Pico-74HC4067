# Pico-74HC4067
 
A library for the Raspberry Pi Pico C SDK to interface with the 74HC4067 16-channel multiplexer.
To use, add this repository to existing Pico C SDK Project. Also add the folder to your projects CMakeLists.txt by adding include_directories() and add_subdirectory(). See example code and CMakeLists.txt below.

Example code:
```c
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "74HC4067.h"

#define MUX_ENABLE_PIN 0
#define MUX_MASK 0b11110

PinConfig_74HC4067 mux;

int main()
{
    stdio_init_all();

    mux = configure_74HC4067(MUX_MASK, MUX_ENABLE_PIN, 3);

    while (true) {
        for (uint8_t i=0; i<16; i++) {
            gpio_put(mux.ENABLE_PIN, true);
            mux_put_address(&mux, i);
            gpio_put(mux.ENABLE_PIN, false);
            printf("select mask: %i, mask first pin: %i, enable pin: %i, signal pin %i, last address: %i \n", 
                mux.SELECT_MASK, mux.MASK_FIRST_PIN, mux.ENABLE_PIN, mux.SIGNAL_PIN, mux._ADDRESS);
            sleep_ms(100);
        }
        gpio_put(mux.ENABLE_PIN, true);
        
        sleep_ms(1000);
    }
}
```

Example CMakeLists.txt:
```cmake
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Pico-74HC4067-Example C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Include directories and subdirectory
include_directories(Pico-74HC4067)
add_subdirectory(Pico-74HC4067)

# Add executable. Default name is the project name, version 0.1

add_executable(Pico-74HC4067-Example Pico-74HC4067-example.c)

pico_set_program_name(Pico-74HC4067-Example "Pico-74HC4067-Example")
pico_set_program_version(Pico-74HC4067-Example "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Pico-74HC4067-Example 0)
pico_enable_stdio_usb(Pico-74HC4067-Example 1)

# Add the standard library to the build
target_link_libraries(Pico-74HC4067-Example
        pico_stdlib
        Pico-74HC4067)

# Add the standard include files to the build
target_include_directories(Pico-74HC4067-Example PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Pico-74HC4067-Example)
```
