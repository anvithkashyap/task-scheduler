#ifndef TASK_H
#define TASK_H

typedef struct {
    int id;
    int priority;
    int execution_time; // in milliseconds
    int status;         // 0: not started, 1: running, 2: paused, 3: completed
} Task;

void create_task(Task *task, int id, int priority, int execution_time);

#endif /* TASK_H */
