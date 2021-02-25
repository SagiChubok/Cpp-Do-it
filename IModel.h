#ifndef IMODEL_H
#define IMODEL_H

#include "Observable.h"
#include "Task.h"

#include <QDate>
#include <iostream>
#include <utility>
#include <map>

/*--------------------------------------------------------------------

  Description: This is the interface for every model that is part of
               Do it system.

---------------------------------------------------------------------*/

class IModel : public Observable {
   public:
    virtual ~IModel(){};

    virtual void addTask(Task* task) = 0;
    virtual void updateTask(Task* task) = 0;
    virtual void removeTask(const QString& deadline,const int& id) = 0;

    virtual const std::multimap<QDate, Task*>& getAllTasks() = 0;
    virtual const std::vector<Task*>& getFilteredTasks(const QString& deadline) = 0;
    virtual std::vector<QDate> getAllDeadlines() = 0;
};

#endif // IMODEL_H
