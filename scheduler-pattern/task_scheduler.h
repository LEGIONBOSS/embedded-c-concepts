/*
    File:    task_scheduler.h
    Created: 2025.07.15. 15:19:16
    Author:  Daniel Szilagyi
*/

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdint.h>

// Task type
typedef struct task
{
    // task function pointer
    // enabled bool
    // next_run time (ms)
    // interval time (ms)
} task_t;

void scheduler_disable_task(/*task pointer*/);
void scheduler_add_task(/*task pointer*/);
void scheduler_run_tasks(uint32_t now_ms);

#endif // TASK_SCHEDULER_H
