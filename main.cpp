#include "MyView.h"
#include "MyModel.h"
#include "MyController.h"

#include <QApplication>
#include <QFile>

QByteArray readTextFile(const QString & file_path) {
  QFile input_file(file_path);
  QByteArray input_data;

  if (input_file.open(QIODevice::Text | QIODevice::Unbuffered | QIODevice::ReadOnly))
  {
    input_data = input_file.readAll();
    input_file.close();
    return input_data;
  }
  else
    return QByteArray();
}

int main(int argc, char * argv[]) {
  // Read style sheet file
  QString style_sheet = readTextFile(":/stylesheets/style.qss");

  // Set the application resources
  QApplication application(argc, argv);
  application.setStyleSheet(style_sheet);
  application.setWindowIcon(QIcon(":/myappico.ico"));

  // Creating the application component
  IModel* model = new MyModel;
  IView* view = new MyView;
  IController* controller = new MyController;

  // Connecting the components with each other
  controller->setModel(model);
  controller->setView(view);
  view->setController(controller);

  controller->start();
  int exitCode = application.exec();
  delete controller;

  return exitCode;
}
