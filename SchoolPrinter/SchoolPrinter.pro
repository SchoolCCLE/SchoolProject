TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    usercontroller.cpp \
    showqml.cpp \
    ../databaseEngine/databaseengine.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    usercontroller.h \
    showqml.h \
    ../databaseEngine/databaseengine.h