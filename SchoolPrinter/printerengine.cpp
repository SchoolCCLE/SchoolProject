#include "printerengine.h"

PrinterEngine::PrinterEngine(int type, QObject *parent) :
    QObject(parent)
{

    setPrinterType(type);
}
