#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>

/*--------------------------------------------------------------------

  Description: This is dialog that is part of the Ui, responsible for
               the functionality of the view that adding new task.

---------------------------------------------------------------------*/

namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);

    ~AddTask();

    const QString getTaskInfo();
    const QString getDeadline();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddTask *ui;
};

#endif // ADDTASK_H
