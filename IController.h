#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "IModel.h"
#include "IView.h"

#include "Task.h"

/*--------------------------------------------------------------------

  Description: This is the interface for every controller that is part of
               Do it system.

---------------------------------------------------------------------*/

class IController {
   public:
   virtual ~IController(){};

   virtual void setView(IView* view) = 0;
   virtual void setModel(IModel* model) = 0;

   virtual void start() = 0; // Start the system

   virtual void addTask(const QString& taskInfo,const QString& deadline,const bool& status) = 0;
   virtual void updateTask(const QString& taskInfo,const QString& deadline,const bool& status, const int& id, const QString& oldDeadline = "") = 0;
   virtual void removeTask(const QString& deadline,const int& id) = 0;

   virtual void getAllTasks() = 0;
   virtual void getFilteredTasks(const QString& deadline) = 0;
   virtual void getAllDeadlines() = 0;
};

#endif // ICONTROLLER_H
