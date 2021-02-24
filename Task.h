#ifndef TASK_H
#define TASK_H

#include <QString>

/*--------------------------------------------------------------------

  Description: This class describes task component, each task
               including info about the task, deadline, and boolean
               value, (status) that implemented in the gui using checkbox.

---------------------------------------------------------------------*/

class Task
{
public:
    // Parameterized Constructor
    Task(const QString& taskInfo, const QString& deadline, const bool status = false, const int id = -1);

    // Getters
    const QString getTaskInfo();
    const QString getDeadline();
    bool getStatus();
    int getID();

    // Setters
    void setTaskInfo(const QString& taskInfo);
    void setDeadline(const QString& deadline);
    void setStatus(const bool& status);
    void setID(const int& id);

private:
    int _id;

    QString _taskInfo;
    QString _deadline;

    bool _status;
};

#endif // TASK_H
