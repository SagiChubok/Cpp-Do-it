#ifndef IVIEW_H
#define IVIEW_H

#include "Observer.h"
#include "Task.h"

#include <QDate>
#include <iostream>
#include <utility>
#include <map>

/*--------------------------------------------------------------------

  Description: This is the interface for every view that is part of
               Do it system.

---------------------------------------------------------------------*/

class IController; // Forward declaration

class IView {
   public:
    virtual ~IView(){};

    virtual IController* getController() = 0;

    virtual void setController(IController* controller) = 0;

    virtual void start() = 0;

    virtual void showAllTasks(const std::multimap<QDate, Task*>& tasks) = 0;
    virtual void showAllFilteredTasks(const std::vector<Task*>& tasks) = 0;
    virtual void showAllDeadlines(std::vector<QDate> deadlines) = 0;
};

#endif // IVIEW_H
