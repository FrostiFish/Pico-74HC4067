#ifndef _74hc4067_H
#define _74hc4067_H

/* Structs */
typedef struct PinConfig_74hc4067
{
    uint32_t SELECT_MASK; // pin mask of 4 select pins s0, s1, s2 and s3
    uint MASK_FIRST_PIN; // first pin of mask, computed in configure_74HC4067()
    uint ENABLE_PIN; // pin mask of active low chip enable pin
    uint SIGNAL_PIN; // signal pin of the mux, connect to desired pin on MCU (e.g. adc, gpio)
    uint8_t _ADDRESS;
} PinConfig_74hc4067;

/* Constructors */
//configure 74HC4067 pin struct, computes first pin of the pin select mask, sets gpio pin modes
PinConfig_74hc4067 configure_74hc4067(uint32_t select_mask, uint enable_pin, uint signal_pin);

//configure 74HC4067 pin struct, computes first pin of the pin select mask, sets gpio pin modes, no enable pin
PinConfig_74hc4067 configure_74hc4067_no_enable(uint32_t select_mask, uint signal_pin);

/* API */
void mux_put_address(PinConfig_74hc4067 * pin_config, uint32_t address);

#endif