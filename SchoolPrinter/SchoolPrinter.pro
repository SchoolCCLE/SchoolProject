TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    usercontroller.cpp \
    showqml.cpp \
    ../databaseEngine/databaseengine.cpp \
    Printheads/PrintheadModel.cpp \
    Printheads/PrintheadsController.cpp \
    printerengine.cpp \
    cartridge.cpp \
    job.cpp \
    jobcontroller.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    usercontroller.h \
    showqml.h \
    ../databaseEngine/databaseengine.h \
    Printheads/PrintheadModel.h \
    Printheads/PrintheadsController.h \
    printerengine.h \
    cartridge.h \
    job.h \
    jobcontroller.h

OTHER_FILES += \
    Cartridge.qml \
    Cartridges.qml
