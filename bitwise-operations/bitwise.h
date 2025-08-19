/*
    File:    bitwise.h
    Created: 2025.07.10 12:00:00
    Author:  Daniel Szilagyi
*/

#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>
#include <stdarg.h>

// Standard functions
uint8_t test_bit(uint8_t* byte, uint8_t pos);
void set_bit(uint8_t* byte, uint8_t pos);
void clear_bit(uint8_t* byte, uint8_t pos);
void toggle_bit(uint8_t* byte, uint8_t pos);

// Extended functions
uint8_t combine_bytes(uint8_t argc, ...);

#endif // BITWISE_H
