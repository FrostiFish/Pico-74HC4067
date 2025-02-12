#include <stdio.h>
#include <strings.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include"74hc4067.h"

PinConfig_74hc4067 configure_74hc4067(uint32_t select_mask, uint enable_pin, uint signal_pin) {
    PinConfig_74hc4067 pin_config;
    pin_config.SELECT_MASK = select_mask;
    pin_config.MASK_FIRST_PIN = ffs(select_mask) - 1;
    pin_config.ENABLE_PIN = enable_pin;
    pin_config.SIGNAL_PIN = signal_pin;

    uint32_t init_mask = select_mask | (1 << enable_pin);
    gpio_init_mask(init_mask);
    gpio_set_dir_out_masked(init_mask);

    return pin_config;
}

PinConfig_74hc4067 configure_74hc4067_no_enable(uint32_t select_mask, uint signal_pin) {
    PinConfig_74hc4067 pin_config;
    pin_config.SELECT_MASK = select_mask;
    pin_config.MASK_FIRST_PIN = ffs(select_mask) - 1;
    pin_config.SIGNAL_PIN = signal_pin;

    gpio_init_mask(select_mask);
    gpio_set_dir_out_masked(select_mask);

    return pin_config;
}

void mux_put_address(PinConfig_74hc4067 * pin_config, uint32_t address) {
    gpio_put_masked(pin_config->SELECT_MASK, address << pin_config->MASK_FIRST_PIN);
    pin_config->_ADDRESS = address;
}