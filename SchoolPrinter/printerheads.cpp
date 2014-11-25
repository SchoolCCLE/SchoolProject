#include "printerheads.h"

PrinterHeads::PrinterHeads()
{
}

PrinterHeads::PrinterHeads(int _id, QList<QVariant> ph)
{
    id = _id;
    color = ph[0];
    salud = ph[1];
    garantia = ph[2];
    fechaInstalacion = ph[3];

}
int PrinterHeads::getColor() const
{
    return color;
}

void PrinterHeads::setColor(int value)
{
    color = value;
}
int PrinterHeads::getSalud() const
{
    return salud;
}

void PrinterHeads::setSalud(int value)
{
    salud = value;
}
bool PrinterHeads::getGarantia() const
{
    return garantia;
}

void PrinterHeads::setGarantia(bool value)
{
    garantia = value;
}
QDateTime PrinterHeads::getFechaInstalacion() const
{
    return fechaInstalacion;
}

void PrinterHeads::setFechaInstalacion(const QDateTime &value)
{
    fechaInstalacion = value;
}
int PrinterHeads::getId() const
{
    return id;
}

void PrinterHeads::setId(int value)
{
    id = value;
}





