/*
    File:    bitwise.c
    Created: 2025.07.10 (Thu)
    Author:  Daniel Szilagyi
*/

#include <stdint.h>
#include "bitwise.h"

uint8_t test_bit(uint8_t* byte, uint8_t pos)
{
    if (pos > 7 || !(*byte & (1 << pos)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void set_bit(uint8_t* byte, uint8_t pos)
{
    if (pos < 8)
    {
        *byte | (1 << pos);
    }
}

void clear_bit(uint8_t* byte, uint8_t pos)
{
    if (pos < 8)
    {
        *byte & ~(1 << pos);
    }
}

void toggle_bit(uint8_t* byte, uint8_t pos)
{
    if (pos < 8)
    {
        *byte ^ (1 << pos);
    }
}
