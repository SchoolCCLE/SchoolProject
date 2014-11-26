#include "printerengine.h"
#include <QDateTime>
#include <QString>
#include <QDebug>
PrinterEngine::PrinterEngine(PrinterType type, QObject *parent) :
    QObject(parent)
{
    printerType = type;
    startTime = QDateTime::currentDateTime();
}
int PrinterEngine::getTimeWorking() const
{
    QDateTime timeWorking = QDateTime::currentDateTime();
    return startTime.time().msecsTo(timeWorking.time());
}

QString PrinterEngine::getPrinterStateText()
{
    switch (m_printerState) {
    case IDLE:
        return "IDLE";

    case PRINTING:
        return "PRINTING";

    case WARNING:
        return "WARNING";

    case ERROR:
        return "ERROR";

    default:
        break;
    }
}

PrinterType PrinterEngine::getPrinterType() const
{
    return printerType;
}





