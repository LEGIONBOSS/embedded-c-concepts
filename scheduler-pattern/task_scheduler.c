/*
    File:    task_scheduler.c
    Created: 2025.07.15. 15:19:46
    Author:  Daniel Szilagyi
*/

#include "task_scheduler.h"

static task_t* tasks[SCHEDULER_MAX_TASKS]; // internal task list
static uint32_t task_count = 0;

task_t* scheduler_create_task(void (*function)(void), uint8_t enabled, uint32_t time_next, uint32_t time_interval)
{
    task_t* result = (task_t*)malloc(sizeof(task_t));
    if (!result)
    {
        return NULL; // malloc failed
    }

    result->function = function;
    result->enabled = enabled;
    result->time_next = time_next;
    result->time_interval = time_interval;

    return result;
}

void scheduler_add_task(task_t* task)
{
    if (!task || task_count >= SCHEDULER_MAX_TASKS)
    {
        return;
    }

    tasks[task_count] = task;
    task_count++;
}

void scheduler_enable_task(task_t* task)
{
    if (!task)
    {
        return;
    }

    task->enabled = 1;
}

void scheduler_disable_task(task_t* task)
{
    if (!task)
    {
        return;
    }

    task->enabled = 0;
}

void scheduler_run_tasks(uint32_t now_ms)
{
    for (uint32_t i = 0; i < task_count; i++)
    {
        task_t* task = tasks[i];
        if (task && task->enabled && current_time >= task->next_run)
        //                                        ^ NOT OVERFLOW SAFE!
        {
            task->function(); // Run task

            if (task->time_interval > 0)
            {
                task->time_next = now_ms + task->time_interval; // Re-schedule
            }
            else
            {
                task->enabled = 0; // Disable
            }
        }
    }
}
