#include "MyView.h"
#include "MyController.h"

MyController::MyController() :
    _model(nullptr), _view(nullptr) { }

MyController::~MyController() {
    MyView* ptr = dynamic_cast<MyView*> (_view);
    if(ptr)
        _model->removeObserver(ptr->getMainWindow());

    delete _model;
    delete _view;
}

void MyController::setView(IView* view)
{
    _view = view;
}

void MyController::setModel(IModel *model)
{
    _model = model;
}

void MyController::start() {
    MyView* ptr = dynamic_cast<MyView*> (_view);
    if(ptr)
        _model->addObserver(ptr->getMainWindow());

    _view->start();
}

void MyController::addTask(const QString& taskInfo, const QString& deadline, const bool& status)
{
    _model->addTask(new Task(taskInfo,deadline,status));
}

void MyController::updateTask(const QString& taskInfo, const QString& deadline, const bool& status, const int& id,  const QString& oldDeadline)
{
    if(deadline == oldDeadline)
    {
        _model->updateTask(new Task(taskInfo, deadline, status, id));
    }
    else
    {
        _model->removeTask(oldDeadline, id);
        _model->addTask(new Task(taskInfo, deadline, status, id));
    }
}

void MyController::removeTask(const QString& deadline,const int& id)
{
    _model->removeTask(deadline, id);
}

void MyController::getAllTasks()
{
    auto tasks = _model->getAllTasks();
    _view->showAllTasks(tasks);
}

void MyController::getFilteredTasks(const QString& deadline)
{
    auto tasks = _model->getFilteredTasks(deadline);
    _view->showAllFilteredTasks(tasks);
}

void MyController::getAllDeadlines()
{
    auto deadlines = _model->getAllDeadlines();
    _view->showAllDeadlines(deadlines);
}
