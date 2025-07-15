/*
    File:    task_scheduler.h
    Created: 2025.07.15. 15:19:16
    Author:  Daniel Szilagyi
*/

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdint.h>

#define SCHEDULER_MAX_TASKS 10

typedef struct task
{
    void (*function)(void);
    uint8_t enabled;
    uint32_t time_next;
    uint32_t time_interval;
} task_t;

task_t* scheduler_create_task(void (*function)(void), uint8_t enabled, uint32_t time_next, uint32_t time_interval);
void scheduler_add_task(task_t* task);
void scheduler_enable_task(task_t* task);
void scheduler_disable_task(task_t* task);
void scheduler_run_tasks(uint32_t now_ms);

#endif // TASK_SCHEDULER_H
