#ifndef PRINTERHEADS_H
#define PRINTERHEADS_H
#include <../databaseEngine/databaseengine.h>
#include <QDateTime>
#include <QVariant>
#include <QList>

class PrinterHeads
{
public:
    PrinterHeads();
    PrinterHeads(int _id, QList<QVariant> ph);

    int getColor() const;
    void setColor(int value);

    int getSalud() const;
    void setSalud(int value);

    bool getGarantia() const;
    void setGarantia(bool value);

    QDateTime getFechaInstalacion() const;
    void setFechaInstalacion(const QDateTime &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    int color;
    int salud;
    bool garantia;
    QDateTime fechaInstalacion;



};

#endif // PRINTERHEADS_H
