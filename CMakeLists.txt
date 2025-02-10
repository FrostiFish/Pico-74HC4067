
cmake_minimum_required(VERSION 3.13)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Pico-74HC4067 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_library(Pico-74HC4067 74HC4067.c)

# Add the standard library to the build
target_link_libraries(Pico-74HC4067
        pico_stdlib)