#include "fcfsscheduler.h"

void FcfsScheduler::execute(std::list<Task>& runningTasksList)
{
    auto it = runningTasksList.begin();

    if(it != runningTasksList.end()){
        if(it->consecutiveCount == 0)
            it->switchCount++;
        it->elapsedTime++;
        it->remainingTime--;
        it->consecutiveCount++;
        it++;
    }

    while(it != runningTasksList.end()) {
        it->waitTime++;
        it->elapsedTime++;
        it->consecutiveCount = 0;
        it++;
    }

}
