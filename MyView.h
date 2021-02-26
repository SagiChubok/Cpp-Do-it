#ifndef MYVIEW_H
#define MYVIEW_H

#include "IController.h"
#include "IView.h"
#include "MainWindow.h"

#include <QObject>
#include <QSettings>

/*-------------------------------------------------------------------------------

  Description: This class describes our view implementation that  manages the
               visual display of the data represented by the model. It produces
               the visual representation of the model object and displays the data
               to the user.

--------------------------------------------------------------------------------*/

class MyView : public IView
{
public:
    MyView();
    ~MyView();

    MainWindow* getMainWindow();
    IController* getController();

    void setController(IController* controller);

    void start();

    void showAllTasks(const std::multimap<QDate, Task*>& tasks);
    void showAllFilteredTasks(const std::vector<Task*>& tasks);
    void showAllDeadlines(std::vector<QDate> deadlines);

private:
    MainWindow* _mainWindow;
    IController* _controller;
};

#endif // MYVIEW_H
