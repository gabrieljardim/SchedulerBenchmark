#ifndef FCFSSCHEDULER_H
#define FCFSSCHEDULER_H

#include "task.h"
#include <list>

namespace FcfsScheduler
{
    void execute(std::list<Task>& runningTasksList);
}

#endif // FCFSSCHEDULER_H
