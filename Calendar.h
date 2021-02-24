#ifndef CALENDAR_H
#define CALENDAR_H

#include "Task.h"
#include "IView.h"

#include <QDialog>
#include<QTextCharFormat>

/*--------------------------------------------------------------------------

  Description: This is dialog that is part of the Ui, responsible for
               the functionality of the view that the user filtering tasks.

---------------------------------------------------------------------------*/

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

    // Mark all the deadlines on the calendar with yellow
    void showAllDeadlines(std::vector<QDate> deadlines);

    // Return the choosen deadline for filtering
    const QString getDeadline();

    // Ensure the correct action of the user
    bool getResetClicked();
    bool getDeadlineClicked();

private slots:

    // Click date on the calendar will choose deadline for filtering
    void on_calendarWidget_clicked(const QDate &date);

    // Reset button for reset the filter
    void on_pushButton_clicked();

private:
    Ui::Calendar *ui;

    bool resetClicked;
    bool deadlineClicked;

};

#endif // CALENDAR_H
