#include "printerengine.h"

PrinterEngine::PrinterEngine(int tipoImpresora, QObject* parent) : QObject(parent)
{
    if(tipoImpresora == 0)
        tipo = "Baja Calidad";
    if(tipoImpresora == 1)
        tipo = "Alta Calidad";
}

