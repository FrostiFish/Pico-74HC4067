add_library(Pico-74HC4067 INTERFACE 74HC4067.c)

target_sources(Pico-74HC4067 INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/74HC4067.c
)

# Add the used pico libraries to the library
target_link_libraries(Pico-74HC4067 INTERFACE
        pico_stdlib
        hardware_gpio)