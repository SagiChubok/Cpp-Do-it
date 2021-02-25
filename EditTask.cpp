#include "EditTask.h"
#include "ui_EditTask.h"

EditTask::EditTask(QWidget *parent) : QDialog(parent), ui(new Ui::EditTask), buttonClicked(false)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

EditTask::~EditTask() { delete ui; }

const QString EditTask::getTaskInfo(){
    return ui->lineEdit->text();
}

const QString EditTask::getDeadline(){
    return ui->dateEdit->date().toString("dd/MM/yyyy");
}

void EditTask::setTaskInfo(const QString &taskInfo){
    ui->lineEdit->setText(taskInfo);
}

void EditTask::setDeadline(const QString &deadline){
    ui->dateEdit->setDate(QDate::fromString(deadline.simplified().remove(" "),"dd/MM/yyyy"));
}

void EditTask::on_pushButton_clicked()
{
    buttonClicked = true;
    EditTask::close();
}

bool EditTask::getButtonClicked(){
    return buttonClicked;
}
