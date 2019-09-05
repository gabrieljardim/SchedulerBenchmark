#include "srtfscheduler.h"

bool compareTaskByShortestRemainingTime(const Task& t1, const Task& t2) {
    if(t1.remainingTime < t2.remainingTime)
        return true;
    else
        return false;
}

void SrtfScheduler::execute(std::list<Task> &runningTasksList)
{

    runningTasksList.sort(compareTaskByShortestRemainingTime);

    auto it = runningTasksList.begin();

    if(it != runningTasksList.end()){
        if(it->consecutiveCount == 0) {
            it->switchCount++;
        }
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
