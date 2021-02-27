#include "MyView.h"

MyView::MyView() : _mainWindow(new MainWindow(this)), _controller(nullptr) { }

MyView::~MyView() { delete _mainWindow; }

IController* MyView::getController() { return _controller; }

MainWindow* MyView::getMainWindow() { return _mainWindow; }

void MyView::setController(IController* controller) { _controller = controller; }

void MyView::start() {
    _mainWindow->show();
    _controller->getAllTasks();
}

void MyView::showAllTasks(const std::multimap<QDate, Task*>& tasks) { _mainWindow->showTasks(tasks); }

void MyView::showAllFilteredTasks(const std::vector<Task*>& tasks) { _mainWindow->showAllFilteredTasks(tasks); }

void MyView::showAllDeadlines(std::vector<QDate> deadlines) { _mainWindow->showAllDeadlines(deadlines); }
