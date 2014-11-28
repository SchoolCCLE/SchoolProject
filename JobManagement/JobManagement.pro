TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    JobQueueView.cpp \
    Job.cpp \
    JobManager.cpp \
    JobGeneratorFake.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    JobQueueView.h \
    Job.h \
    JobManager.h \
    JobGeneratorFake.h
