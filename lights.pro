TEMPLATE = app
TARGET = lights

QT += core gui widgets

DEPENDPATH += .
INCLUDEPATH += .

HEADERS += main_window.h model.h frame_widget.h \
    frame.h

SOURCES += main.cpp main_window.cpp model.cpp frame_widget.cpp \
    frame.cpp

RESOURCES += app.qrc
