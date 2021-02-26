#ifndef MYMODEL_H
#define MYMODEL_H

#include "IModel.h"

#include <QFile>
#include <QIODevice>
#include <QTextStream>

/*-------------------------------------------------------------------------------

  Description: This class describes our model implementation that manages the data
               and conducts all transformations on that data. The model has no
               specific knowledge of either its controllers or its views.

--------------------------------------------------------------------------------*/

class MyModel : public IModel
{
public:
    MyModel();
    ~MyModel();

    void addTask(Task* task);
    void updateTask(Task* task);
    void removeTask(const QString& deadline,const int& id);

    const std::multimap<QDate, Task*>& getAllTasks();
    const std::vector<Task*>& getFilteredTasks(const QString& deadline);
    std::vector<QDate> getAllDeadlines();

private:
    std::multimap<QDate, Task*> _tasks;
    std::vector<Task*> _filteredTasks;
};

#endif // MYMODEL_H
