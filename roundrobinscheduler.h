#ifndef ROUNDROBINSCHEDULER_H
#define ROUNDROBINSCHEDULER_H

#include <list>
#include "task.h"

namespace RoundRobinScheduler
{
    void execute(std::list<Task>& runningTasksList);
}

#endif // ROUNDROBINSCHEDULER_H
