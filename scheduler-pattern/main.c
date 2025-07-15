/*
    File:    main.c
    Created: 2025.07.15. 15:11:27
    Author:  Daniel Szilagyi
*/

#include <stdint.h>
#include "task_scheduler.h"

// Imaginary function that returns the elapsed milliseconds since boot
uint32_t now_ms();

// Some dummy functions can call
void fn1(void);
void fn2(void);
void fn3(void);

int main(void)
{
    // Create tasks
    task_t* task1 = scheduler_create_task(fn1, 1, 1000, 0); // Runs once
    task_t* task2 = scheduler_create_task(fn2, 1, 0, 500); // Runs periodically

    // Add functions to scheduler
    scheduler_add_task(task1);
    scheduler_add_task(task2);

    while(1)
    {
        // Run scheduler
        uint32_t now = now_ms();
        scheduler_run_tasks(now);

        // Call another function
        fn3(); // Runs every time
    }

    return 0;
}
