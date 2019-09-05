#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

class Task
{
public:
    int startTime;
    int totalTime;
    int priority;
    int elapsedTime;
    int waitTime;
    int remainingTime;
    int consecutiveCount;
    int switchCount;
};

std::vector<Task> readTasksFromFile(std::string path);


#endif // TASK_H
