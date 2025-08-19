/*
    File:    command.h
    Created: 2025.08.19. 14:44:02
    Author:  Daniel Szilagyi
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>

#define COMMAND_MAX_LENGTH (32)
#define COMMAND_MAX_COMMANDS (10)

typedef struct command
{
    char command[COMMAND_MAX_LENGTH];
    void (*function)(void);
    uint8_t enabled;
} command_t;

command_t* command_create_command(const char* command, void (*function)(void), uint8_t enabled);
void command_add_command(command_t* command);
void command_enable_command(command_t* command);
void command_disable_command(command_t* command);
void command_run_command(const char* command);

#endif // COMMAND_H
