#include "printerengine.h"
#include <QDebug>
#include <QString>
PrinterEngine::PrinterEngine(Type printerCap)
{

    timer.start();
    qDebug()<< "Creado printerengine" << printerCap;
    printerCapacity = printerCap;
}
int PrinterEngine::getPrinterStatus()
{
    int ptr = printerStatus;
    qDebug()<< ptr;
    return ptr;
}
int PrinterEngine::runningTime()
{
    //RETURNS THE TIME SINCE THE PRINTERENGINE WAS INSTANCIATED
    int tmr;
    time = timer.elapsed();
    tmr = time;
    qDebug()<< tmr;
    return tmr;

}
QString PrinterEngine::getPrinterCapacity()
{
    QString capacity;
    switch (printerCapacity) {
    case 0:
        capacity = "HIGH_CAPACITY";
        break;
    case 1:
        capacity = "LOW_CAPACITY";
        break;
    default:
        break;
    }
    qDebug()<< capacity;
    return capacity;
}

void PrinterEngine::setPrinterStatus(int status)
{
    printerStatus = status;
    setStringStatus(status);

}
QString PrinterEngine::getStringStatus()
{
    QString str = stringStatus;
    qDebug()<< str;
    return str;
}
void PrinterEngine::setStringStatus(int status)
{
    switch (status) {
    case 0:
        stringStatus = "IDLE";
        break;
    case 1:
        stringStatus = "PRINTING";
        break;
    case 2:
        stringStatus = "WARNING";
        break;
    case 3:
        stringStatus = "ERROR";
        break;
    default:
        break;
    }
}
PrinterEngine::~PrinterEngine()
{
    qDebug()<< "Printer Destroyed";
}
