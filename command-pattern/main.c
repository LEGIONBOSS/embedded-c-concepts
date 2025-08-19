/*
    File:    main.c
    Created: 2025.08.19. 14:38:04
    Author:  Daniel Szilagyi
*/

#include <stdio.h>
#include "command.h"

// Imaginary serial handling functions
uint64_t serial_available();
char* serial_read();

// Some dummy commands to call
void fn1();
void fn2();

// Command words for the dummy command functions
const char* fn1_c = "func1";
const char* fn2_c = "func2";

int main(void)
{
    // Create commands
    command_t* command1 = command_create_command(fn1_c, fn1, 1);
    command_t* command2 = command_create_command(fn2_c, fn2, 1);

    // Add commands to active list
    command_add_command(command1);
    command_add_command(command2);

    while(1)
    {
        // Check for command words on serial
        if (serial_available())
        {
            // Attempt to run command
            char* command = serial_read();
            command_run_command(command);
        }
    }
    
    return 0;
}
