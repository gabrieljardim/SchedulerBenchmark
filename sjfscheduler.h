#ifndef SJFSCHEDULER_H
#define SJFSCHEDULER_H

#include <list>
#include "task.h"

namespace SjfScheduler
{
    void execute(std::list<Task>& runningTasksList);
}

#endif // SJFSCHEDULER_H
