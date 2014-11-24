TEMPLATE = app

QT += qml quick sql network

SOURCES += main.cpp \
            databaseengine.cpp \
    logincontroler.cpp\
    usuario.cpp


HEADERS += databaseengine.h \
    logincontroler.h \
    usuario.h



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
