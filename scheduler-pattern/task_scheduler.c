/*
    File:    task_scheduler.c
    Created: 2025.07.15. 15:19:46
    Author:  Daniel Szilagyi
*/

#include "task_scheduler.h"

static task_t tasks[SCHEDULER_MAX_TASKS]; // internal task list
static uint32_t task_count = 0;

task_t* scheduler_add_task(void (*function)(void), uint8_t enabled, uint32_t time_next, uint32_t time_interval)
{
    if (task_count >= MAX_TASKS)
    {
        return NULL; // no space left
    }

    task_t* result = &tasks[task_count];
    task_count++;

    result->function = function;
    result->enabled = enabled;
    result->time_next = time_next;
    result->time_interval = time_interval;

    return result;
}

void scheduler_set_enabled(task_t* task, uint8_t enabled)
{
    if (!task)
    {
        return;
    }

    task->enabled = enabled;
}

void scheduler_set_time_next(task_t* task, uint32_t time_next)
{
    if (!task)
    {
        return;
    }

    task->time_next = time_next;
}

void scheduler_set_time_interval(task_t* task, uint32_t time_interval)
{
    if (!task)
    {
        return;
    }

    task->time_interval = time_interval;
}

void scheduler_run_tasks(uint32_t now_ms)
{
    for (uint32_t i = 0; i < task_count; i++)
    {
        task_t* task = &tasks[i];
        if (task && task->enabled && (int32_t)(now_ms - task->time_next) >= 0)
        //                              ^ This limits the maximum size of task->time_interval
        {
            task->function(); // Run task

            if (task->time_interval > 0)
            {
                task->time_next += task->time_interval; // Re-schedule
            }
            else
            {
                task->enabled = 0; // Disable
            }
        }
    }
}
