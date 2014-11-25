#include "printerengine.h"

PrinterEngine::PrinterEngine(QObject *parent, QString tipoImpresora) :
    QObject(parent)
{
    tipo = tipoImpresora;
}

