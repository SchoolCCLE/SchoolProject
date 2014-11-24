TEMPLATE = app

QT += qml quick widgets sql network

SOURCES += main.cpp \
    databaseEngine/databaseengine.cpp \
    controler.cpp \
    storeUser.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    databaseEngine/databaseengine.h \
    controler.h \
    storeUser.h
