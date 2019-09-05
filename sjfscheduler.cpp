#include "sjfscheduler.h"

bool compareTaskByShortestTime(const Task& t1, const Task& t2) {
    if(t1.totalTime < t2.totalTime)
        return true;
    else
        return false;
}
void SjfScheduler::execute(std::list<Task> &runningTasksList)
{
    auto it = runningTasksList.begin();

    if(it != runningTasksList.end()){
        if(it->consecutiveCount == 0) {
            runningTasksList.sort(compareTaskByShortestTime);
            it = runningTasksList.begin();
        }

    }

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
