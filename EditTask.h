#ifndef EDITTASK_H
#define EDITTASK_H

#include <Task.h>

#include <QDialog>

/*--------------------------------------------------------------------

  Description: This is dialog that is part of the Ui, responsible for
               the functionality of the view that editing specific task.

---------------------------------------------------------------------*/

namespace Ui {
class EditTask;
}

class EditTask : public QDialog
{
    Q_OBJECT

public:
    explicit EditTask(QWidget *parent = nullptr);

    ~EditTask();

    const QString getTaskInfo();
    const QString getDeadline();

    void setTaskInfo(const QString& taskInfo);
    void setDeadline(const QString& deadline);

    bool getButtonClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditTask *ui;

    bool buttonClicked;
};

#endif // EDITTASK_H
