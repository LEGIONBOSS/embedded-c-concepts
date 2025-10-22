/*
    File:    task_scheduler.h
    Created: 2025.07.15. 15:19:16
    Author:  Daniel Szilagyi
*/

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdint.h>

#define SCHEDULER_MAX_TASKS (10)

typedef struct task
{
    void (*function)(void);
    uint8_t enabled;
    uint32_t time_next;
    uint32_t time_interval;
} task_t;

task_t* scheduler_add_task(void (*function)(void), uint8_t enabled, uint32_t time_next, uint32_t time_interval);
void scheduler_set_enabled(task_t* task, uint8_t enabled);
void scheduler_set_time_next(task_t* task, uint32_t time_next);
void scheduler_set_time_interval(task_t* task, uint32_t time_interval);
void scheduler_run_tasks(uint32_t now_ms);

#endif // TASK_SCHEDULER_H
