#include "AddTask.h"
#include "ui_AddTask.h"

AddTask::AddTask(QWidget *parent) : QDialog(parent), ui(new Ui::AddTask)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

const QString AddTask::getTaskInfo() { return ui->lineEdit->text(); }

const QString AddTask::getDeadline() { return QString(ui->dateEdit->date().toString("dd/MM/yyyy")); }

void AddTask::on_pushButton_clicked() { AddTask::close(); }

AddTask::~AddTask() { delete ui; }
