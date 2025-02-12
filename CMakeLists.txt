add_library(pico_74hc4067 INTERFACE)

target_sources(pico_74hc4067 INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/74hc4067.c
)

target_include_directories(pico_74hc4067 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Add the used pico libraries to the library
target_link_libraries(pico_74hc4067 INTERFACE
        pico_stdlib
        hardware_gpio)
