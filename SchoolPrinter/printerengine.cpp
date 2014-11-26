#include "printerengine.h"
#include <QDateTime>
#include <QString>
#include <QDebug>
PrinterEngine::PrinterEngine(PrinterType type, QObject *parent) :
    QObject(parent)
{
    printerType = type;
    startTime = QDateTime::currentDateTime();
    setPrinterState(IDLE);
}
int PrinterEngine::getTimeWorking() const
{
    QDateTime timeWorking = QDateTime::currentDateTime();
    return startTime.time().msecsTo(timeWorking.time());
}


PrinterEngine::PrinterType PrinterEngine::getPrinterType() const
{
    return printerType;
}





