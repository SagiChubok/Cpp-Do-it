#include "Task.h"

Task::Task(const QString& taskInfo, const QString& deadline, const bool status, const int id) : _id(id), _taskInfo(taskInfo), _deadline(deadline), _status(status) { }

const QString Task::getTaskInfo() { return _taskInfo; }
const QString Task::getDeadline() { return _deadline; }
bool Task::getStatus() { return _status; }
int Task::getID() { return _id; }

void Task::setTaskInfo(const QString& taskInfo) { _taskInfo = taskInfo; }
void Task::setDeadline(const QString& deadline){ _deadline = deadline; }
void Task::setStatus(const bool& status) { _status = status; }
void Task::setID(const int& id) { _id = id; }
