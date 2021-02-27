QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = doit
TEMPLATE = app

SOURCES += main.cpp\
        AddTask.cpp \
        Calendar.cpp \
        EditTask.cpp \
        MainWindow.cpp \
        MyController.cpp \
        MyModel.cpp \
        MyView.cpp \
        Observable.cpp \
        Observer.cpp \
        Task.cpp

HEADERS += \
    AddTask.h \
    Calendar.h \
    EditTask.h \
    IController.h \
    IModel.h \
    IView.h \
    MainWindow.h \
    MyController.h \
    MyModel.h \
    MyView.h \
    Observable.h \
    Observer.h \
    Task.h

FORMS += \
    AddTask.ui \
    Calendar.ui \
    EditTask.ui \
    MainWindow.ui

RESOURCES += \
    resources.qrc
