#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "IController.h"
#include "IView.h"
#include "AddTask.h"
#include "EditTask.h"
#include "Calendar.h"
#include "ui_MainWindow.h"

#include <QMainWindow>

/*--------------------------------------------------------------------------

  Description: This is the mainwindow that is part of the Ui, responsible for
               the functionality of the main view.

---------------------------------------------------------------------------*/

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

  public:
    explicit MainWindow(IView* view, QWidget *parent = 0);
    ~MainWindow();

    void update();

    void showTasks(const std::multimap<QDate, Task*>& tasks);
    void showAllFilteredTasks(const std::vector<Task*>& tasks);
    void showAllDeadlines(std::vector<QDate> deadlines);

private slots:

      // Edit task on double click
      void on_listWidget_doubleClicked();

      // Add task (Green button)
      void on_addTask_clicked();

      // Remove task (Red button)
      void on_removeTask_clicked();

      // Filter tasks by deadkine (Calendar button)
      void on_filterBtn_clicked();

      // Checking the checkbox will update the specific task
      void on_listWidget_itemChanged(QListWidgetItem *item);

private:
      Ui::MainWindow *ui;
      Calendar* _calendar;
      IView* _view;

      bool _stateChanged; // Reduce calls on items changed
      bool _filterStatus; // For show the correct tasks (All / Filtered)

      QString _selectedDeadline; // Deadline for filtering
};

#endif // MAINWINDOW_H
