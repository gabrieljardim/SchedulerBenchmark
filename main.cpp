#include <iostream>
#include <sstream>
#include <vector>
#include "task.h"

using namespace std;

int main()
{   
    std::vector<Task> tasks = readTasksFromFile("tasks.txt");

    for(auto& task : tasks) {
        std::cout << std::endl;
        std::cout << "StartTime: " << task.startTime << std::endl <<
                     "TotalTime: " << task.totalTime << std::endl <<
                     "Priority:  " << task.priority << std::endl;
        std::cout << std::endl;
    }


    return 0;
}
