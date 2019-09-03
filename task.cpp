#include "task.h"

#include <fstream>
#include <sstream>

std::vector<Task> readTasksFromFile(std::string path)
{
    std::ifstream fileStream(path);

    std::string line;
    //ignore first line as it's dynamic
    //maybe validate if first line < 100
    std::getline(fileStream, line);
    std::getline(fileStream, line);
    std::stringstream startTimeStream(line);

    std::vector<Task> taskVector;
    int buff;

    while(startTimeStream >> buff) {
        Task task;
        task.startTime = buff;
        taskVector.push_back(task);
    }


    std::getline(fileStream, line);
    std::stringstream totalTimeStream(line);

    for(int i = 0; totalTimeStream >> buff; ++i)
        taskVector[i].totalTime = buff;

    std::getline(fileStream, line);
    std::stringstream priorityStream(line);

    for(int i = 0; priorityStream >> buff; ++i)
        taskVector[i].priority = buff;

    return taskVector;

}
