#include "MainWindow.h"

MainWindow::MainWindow(IView* view, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _calendar(nullptr), _view(view)
{
    _stateChanged = true;
    _filterStatus = false;

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    ui->listWidget->clear();
    if(!_filterStatus)
    {
        _view->getController()->getAllTasks();
    }
    else
    {
        _view->getController()->getFilteredTasks(_selectedDeadline);
    }
}

void MainWindow::on_addTask_clicked()
{
    AddTask addDialog;

    addDialog.setModal(true);
    addDialog.exec();

    QString taskInfo = addDialog.getTaskInfo();
    if(taskInfo != "")
    {
        QString deadline = addDialog.getDeadline();

        _view->getController()->addTask(taskInfo, deadline, false);
    }
}

void MainWindow::on_listWidget_doubleClicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    if(items.count() != 1)
        return;

    foreach(QListWidgetItem * item, items)
    {
        EditTask editDialog;

        editDialog.setTaskInfo(item->text().split("\n").at(0));
        QString oldDeadline = item->text().split("\n").at(1);
        editDialog.setDeadline(oldDeadline);

        editDialog.setModal(true);
        editDialog.exec();
        if(editDialog.getButtonClicked())
        {
            QString taskInfo = editDialog.getTaskInfo();
            QString deadline = editDialog.getDeadline();

            bool status = false;
            if(item->checkState() == Qt::Checked)
                status = true;

            QVariant v = item->data(Qt::UserRole);
            int id = v.value<int>();

            _view->getController()->updateTask(taskInfo, deadline, status, id, oldDeadline);
        }
    }

}

void MainWindow::on_removeTask_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    int count = items.count();
    std::vector<std::pair<QString,int>> taskToDelete;
    taskToDelete.reserve(count);

    foreach(QListWidgetItem* item, items)
    {
        QVariant v = item->data(Qt::UserRole);

        int id = v.value<int>();
        QString deadline = item->text().split("\n").at(1);

        taskToDelete.emplace_back(std::make_pair(deadline,id));
    }

    for(int i = 0; i < count; i++)
        _view->getController()->removeTask(taskToDelete[i].first,taskToDelete[i].second);
}

void MainWindow::on_filterBtn_clicked()
{
    Calendar* calendarDialog = new Calendar();

    _calendar = calendarDialog;

    _view->getController()->getAllDeadlines();

    calendarDialog->setModal(true);
    calendarDialog->exec();

    if(_calendar->getResetClicked())
    {
        _filterStatus = false;
        ui->filterStatus->setStyleSheet("QLabel {font: 10pt; font-weight:600; color:#df543c;}");
        ui->filterStatus->setText(QString("OFF"));

        update();
    }
    else if(_calendar->getDeadlineClicked())
    {
        _filterStatus = true;
        ui->filterStatus->setStyleSheet("QLabel {font: 10pt; font-weight:600; color:#55b957;}");
        ui->filterStatus->setText(QString("ON"));

        ui->listWidget->clear();

        _selectedDeadline = _calendar->getDeadline();
        _view->getController()->getFilteredTasks(_selectedDeadline);
    }

    delete calendarDialog;
    _calendar = nullptr;
}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item)
{
    if(_stateChanged)
    {
        bool status = false;
        if(item->checkState() == Qt::Checked)
            status = true;

        QVariant v = item->data(Qt::UserRole);
        int id = v.value<int>();

        QString taskInfo = item->text().split("\n").at(0);
        QString deadline = item->text().split("\n").at(1);

        _view->getController()->updateTask(taskInfo, deadline, status, id, deadline);
    }
}

void MainWindow::showTasks(const std::multimap<QDate, Task*>& tasks)
{
    _stateChanged = false;

    for(auto& task : tasks){
        QString taskInfo = task.second->getTaskInfo();
        QString deadline = task.second->getDeadline();
        bool status = task.second->getStatus();

        auto *item = new QListWidgetItem(taskInfo + "\n" + deadline, ui->listWidget);

        QVariant v;
        v.setValue(task.second->getID());
        item->setData(Qt::UserRole, v);

        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(status)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }

    _stateChanged = true;
}

void MainWindow::showAllFilteredTasks(const std::vector<Task*>& tasks)
{
    _stateChanged = false;

    for(auto& task : tasks){
        QString taskInfo = task->getTaskInfo();
        QString deadline = task->getDeadline();
        bool status = task->getStatus();

        auto *item = new QListWidgetItem(taskInfo + "\n" + deadline, ui->listWidget);

        QVariant v;
        v.setValue(task->getID());
        item->setData(Qt::UserRole, v);

        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(status)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }

    _stateChanged = true;
}

void MainWindow::showAllDeadlines(std::vector<QDate> deadlines)
{
    if(_calendar)
        _calendar->showAllDeadlines(deadlines);
}
