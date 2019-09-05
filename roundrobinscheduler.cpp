#include "roundrobinscheduler.h"

const int PreemptionTime = 2;

void RoundRobinScheduler::execute(std::list<Task> &runningTasksList)
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

    it = runningTasksList.begin();
    if(it != runningTasksList.end() && it->consecutiveCount >= PreemptionTime) {
        it->consecutiveCount = 0;
        runningTasksList.splice(runningTasksList.end(), runningTasksList, it);

    }

}
