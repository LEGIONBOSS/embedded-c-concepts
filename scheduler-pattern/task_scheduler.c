/*
    File:    task_scheduler.c
    Created: 2025.07.15. 15:19:46
    Author:  Daniel Szilagyi
*/

#include "task_scheduler.h"

task_t* scheduler_create_task(void (*function)(void), uint8_t enabled, uint32_t time_next, uint32_t time_interval)
{
    task_t* result = (task_t*)malloc(sizeof(task_t));
    if (!result) // malloc failed
    {
        return NULL;
    }

    result->function = function;
    result->enabled = enabled;
    result->time_next = time_next;
    result->time_interval = time_interval;

    return result;
}
