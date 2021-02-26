#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "IController.h"

#include <QString>

/*--------------------------------------------------------------------------------------

  Description: This class describes our controller implementation that that
               provides the means for user interaction with the data represented
               by the model. It provides the means by which changes are made,
               either to the information in the model or to the appearance of the view.

---------------------------------------------------------------------------------------*/

class MyController : public IController
{
public:
    MyController();
    ~MyController();

    void setView(IView* view);
    void setModel(IModel* model);

    void start();

    void addTask(const QString& taskInfo,const QString& deadline,const bool& status);
    void updateTask(const QString& taskInfo,const QString& deadline,const bool& status, const int& id, const QString& oldDeadline = "");
    void removeTask(const QString& deadline,const int& id);

    void getAllTasks();
    void getFilteredTasks(const QString& deadline);
    void getAllDeadlines();

private:
    IModel* _model;
    IView* _view;
};

#endif // MYCONTROLLER_H
