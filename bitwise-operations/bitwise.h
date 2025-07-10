/*
    File:    bitwise.h
    Created: 2025.07.10 (Thu)
    Author:  Daniel Szilagyi
*/

#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>

uint8_t test_bit(uint8_t* byte, uint8_t pos);
void set_bit(uint8_t* byte, uint8_t pos);
void clear_bit(uint8_t* byte, uint8_t pos);
void toggle_bit(uint8_t* byte, uint8_t pos);

#endif // BITWISE_H
