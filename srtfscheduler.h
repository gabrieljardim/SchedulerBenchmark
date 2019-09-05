#ifndef SRTFSCHEDULER_H
#define SRTFSCHEDULER_H


#include <list>
#include "task.h"

namespace SrtfScheduler
{
    void execute(std::list<Task>& runningTasksList);
}

#endif // SRTFSCHEDULER_H
