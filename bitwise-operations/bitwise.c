/*
    File:    bitwise.c
    Created: 2025.07.10 (Thu)
    Author:  Daniel Szilagyi
*/

#include <stdint.h>
#include <stdarg.h>
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

uint8_t combine_bytes(uint8_t argc, ...)
{
    uint8_t result = 0;
    va_list args;
    va_start(args, argc);
    for (uint8_t i = 0; i < argc; i++)
    {
        uint8_t value = va_arg(args, uint8_t); 
        result |= value;
    }
    va_end(args);
    return result;
}
