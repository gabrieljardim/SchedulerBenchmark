#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "task.h"
#include "fcfsscheduler.h"
#include "roundrobinscheduler.h"
#include "sjfscheduler.h"
#include "srtfscheduler.h"

using namespace std;

void moveFinishedTasksToFinishedTaskList(std::list<Task>& tasksToBeMoved, std::list<Task>& finishedTaskList) {
    for(auto it = tasksToBeMoved.begin(); it != tasksToBeMoved.end(); ++it) {
        if(it->remainingTime == 0) {
            auto aux = it;
            it--;
            finishedTaskList.splice(finishedTaskList.end(), tasksToBeMoved, aux );
        }

    }

}

void moveFromTaskListToRunningTask(std::list<Task>& tasksToBeMoved, std::list<Task>& runningTaskList, int schedulerTime) {
    for(auto it = tasksToBeMoved.begin(); it != tasksToBeMoved.end(); ++it) {
        if(it->startTime == schedulerTime) {
            auto aux = it;
            it--;
            runningTaskList.splice(runningTaskList.end(), tasksToBeMoved, aux );
        }

    }

}


int main()
{   
    std::vector<Task> tasks = readTasksFromFile("tasks.txt");
    std::list<Task> taskList(tasks.begin(), tasks.end());
    std::list<Task> runningTaskList;
    std::list<Task> finishedRunningTaskList;
    int currentTime = 0;

    while(!taskList.empty() || !runningTaskList.empty()) {
        moveFromTaskListToRunningTask(taskList, runningTaskList, currentTime);
        SrtfScheduler::execute(runningTaskList);
        moveFinishedTasksToFinishedTaskList(runningTaskList, finishedRunningTaskList);
        currentTime++;

    }

    float waitTimeAverage = 0.0;
    float elapsedTimeAverage = 0.0;
    //not counting first task to enter in schedule hence the -1 instead of 0
    int contextSwitchCount = -1;

    for(auto& task : finishedRunningTaskList) {
        std::cout << std::endl;
        waitTimeAverage += task.waitTime;
        elapsedTimeAverage += task.elapsedTime;
        contextSwitchCount += task.switchCount;
    }

    waitTimeAverage /= finishedRunningTaskList.size();
    elapsedTimeAverage /= finishedRunningTaskList.size();


    std::cout << "AverageElapsedTime:    " << elapsedTimeAverage << std::endl <<
                 "AverageWaitTime:       " << waitTimeAverage    << std::endl <<
                 "ContextSwitchCount:    " << contextSwitchCount << std::endl;


    return 0;
}
