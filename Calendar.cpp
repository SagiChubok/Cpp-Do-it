#include "Calendar.h"
#include "ui_Calendar.h"

Calendar::Calendar(QWidget *parent) : QDialog(parent), ui(new Ui::Calendar), resetClicked(false), deadlineClicked(false)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget->clearFocus();
}

Calendar::~Calendar() { delete ui; }

void Calendar::showAllDeadlines(std::vector<QDate> deadlines)
{
    QTextCharFormat deadlineHighlight;
    deadlineHighlight.setBackground(Qt::yellow);

    for(auto& deadline : deadlines)
        ui->calendarWidget->setDateTextFormat(deadline, deadlineHighlight);
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    deadlineClicked = true;
    Calendar::close();
}

void Calendar::on_pushButton_clicked()
{
    resetClicked = true;
    Calendar::close();
}

const QString Calendar::getDeadline() { return ui->calendarWidget->selectedDate().toString("dd/MM/yyyy"); }

bool Calendar::getResetClicked() { return resetClicked; }

bool Calendar::getDeadlineClicked() { return deadlineClicked; }
