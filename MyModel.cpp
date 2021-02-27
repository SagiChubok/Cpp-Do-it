#include "MyModel.h"

int id = 0;

MyModel::MyModel()
{
    // Load data from file
    QFile file(QString("Doit"));
    QTextStream stream(&file);

    if(file.open(QIODevice::ReadOnly| QIODevice::Text)){
        while(!stream.atEnd())
        {
            QString line = stream.readLine();

            QString taskInfo = line.split(",  ").at(1);
            QString deadline = line.split(",  ").at(2);
            bool status = false;
            if(line.split(",  ").first() == "1")
                status = true;

            Task* task = new Task(taskInfo, deadline, status, id++);
            _tasks.insert(std::make_pair(QDate::fromString(deadline,"dd/MM/yyyy"), task));
        }
        file.close();
    }
}

MyModel::~MyModel()
{
        QFile file(QString("Doit"));
        QTextStream stream(&file);

        if(file.open(QIODevice::WriteOnly| QIODevice::Text))
        {

            for(auto& task: _tasks){
                if(task.second->getStatus())
                    stream << "1,  ";
                else
                    stream << "0,  ";
                stream << task.second->getTaskInfo() << ",  " << task.second->getDeadline() << "\n";

                delete task.second;
            }

            file.close();
        }
}

void MyModel::addTask(Task* task)
{
    if(task->getID() == -1)
        task->setID(id++);

    _tasks.insert(std::make_pair(QDate::fromString(task->getDeadline(), "dd/MM/yyyy"), task));
    notify();
}

void MyModel::updateTask(Task* task)
{
    bool found = false;

    int id = task->getID();
    QString deadline = task->getDeadline();
    QString taskInfo = task->getTaskInfo();
    bool status = task->getStatus();

    auto tasksOnDeadLine = _tasks.equal_range(QDate::fromString(deadline, "dd/MM/yyyy"));
    for (auto itr = tasksOnDeadLine.first; itr != tasksOnDeadLine.second; ++itr) {
        if(itr->second->getID() == id)
        {
            found = true;
            if(taskInfo != "")
                 itr->second->setTaskInfo(taskInfo);
            itr->second->setStatus(status);
            break;
        }
    }

    delete task;

    if(found)
        notify();
}

void MyModel::removeTask(const QString& deadline,const int& id)
{
    bool found = false;

    auto tasksOnDeadLine = _tasks.equal_range(QDate::fromString(deadline, "dd/MM/yyyy"));
    for (auto itr = tasksOnDeadLine.first; itr != tasksOnDeadLine.second; ++itr) {
        if(itr->second->getID() == id)
        {
            found = true;
            delete itr->second;
            _tasks.erase(itr);
            break;
        }
    }

    if(found)
        notify();
}

const std::multimap<QDate, Task*>& MyModel::getAllTasks() { return _tasks; }

const std::vector<Task*>& MyModel::getFilteredTasks(const QString& deadline)
{
    _filteredTasks.clear();

    QDate Qdeadline = QDate::fromString(deadline, "dd/MM/yyyy");

    int count = _tasks.count(Qdeadline);
    _filteredTasks.reserve(count);

    auto tasksOnDeadLine = _tasks.equal_range(Qdeadline);
    for (auto itr = tasksOnDeadLine.first; itr != tasksOnDeadLine.second; ++itr) {
       _filteredTasks.emplace_back(itr->second);
    }

    return _filteredTasks;
}

std::vector<QDate> MyModel::getAllDeadlines()
{
    std::vector<QDate> deadlines;

    for(auto iter = _tasks.begin(); iter != _tasks.end(); ++iter)
        deadlines.push_back(iter->first);

    return deadlines;
}
