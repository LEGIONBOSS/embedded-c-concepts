/*
    File:    command.c
    Created: 2025.08.19. 15:07:59
    Author:  Daniel Szilagyi
*/

#include "command.h"
#include <string.h>

static command_t* commands[COMMAND_MAX_COMMANDS]; // internal command list
static uint32_t command_count = 0;

command_t* command_create_command(const char* command, void (*function)(void), uint8_t enabled)
{
    command_t* result = (command_t*)malloc(sizeof(command_t));
    if (!result)
    {
        return NULL; // malloc failed
    }

    result->command = command;
    result->function = function;
    result->enabled = enabled;

    return result;
}

void command_add_command(command_t* command)
{
    if (!command || command_count >= COMMAND_MAX_COMMANDS)
    {
        return;
    }

    commands[command_count] = command;
    command_count++;
}

void command_enable_command(command_t* command)
{
    if (!command)
    {
        return;
    }

    command->enabled = 1;
}

void command_disable_command(command_t* command)
{
    if (!command)
    {
        return;
    }

    command->enabled = 0;
}

void command_run_command(const char* command)
{
    if (!command)
    {
        return;
    }

    for (uint32_t i = 0; i < command_count; i++)
    {
        if (strcmp(commands[i]->command, command) == 0 && commands[i]->enabled)
        {
            commands[i]->function();
        }
    }
}
