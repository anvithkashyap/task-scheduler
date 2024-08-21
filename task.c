#include "task.h"

void create_task(Task *task, int id, int priority, int execution_time) {
    task->id = id;
    task->priority = priority;
    task->execution_time = execution_time;
    task->status = 0; // Task is initially not started
}
