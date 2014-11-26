#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H

#include <QObject>
#include <QString>
#include <cartridge.h>

class PrinterEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int stateNumber READ getStateNumber WRITE setStateNumber NOTIFY stateNumberChanged)
    Q_PROPERTY(QString stateText READ getStateText WRITE setStateText NOTIFY stateTextChanged)
    Q_PROPERTY(int printerType READ getPrinterType WRITE setPrinterType NOTIFY printerTypeChanged)//Entero que nos dice el tipo de impresora 1=Alta Capacidad 0=Baja Capacidad
    Q_PROPERTY(int timeStarted READ getTimeStarted WRITE setTimeStarted NOTIFY timeStartedChanged)
    Q_PROPERTY(QList<QObject*> cartridges READ getCartridges WRITE setCartridges NOTIFY cartridgesChanged)
    int m_stateNumber;

    QString m_stateText;

int m_printerType;

int m_timeStarted;

QList<QObject*> m_cartridges;

public:
    explicit PrinterEngine(int type, QObject *parent = 0);

int getStateNumber() const
{
    return m_stateNumber;
}

QString getStateText() const
{
    return m_stateText;
}

int getPrinterType() const
{
    return m_printerType;
}

int getTimeStarted() const
{
    return m_timeStarted;
}

QList<QObject*> getCartridges() const
{
    return m_cartridges;
}

signals:

void stateNumberChanged(int arg);

void stateTextChanged(QString arg);

void printerTypeChanged(int arg);

void timeStartedChanged(int arg);

void cartridgesChanged(QList<QObject*> arg);

public slots:

void changeState(int state);

void setStateNumber(int arg)
{
    if (m_stateNumber == arg)
        return;

    m_stateNumber = arg;
    emit stateNumberChanged(arg);
}
void setStateText(QString arg)
{
    if (m_stateText == arg)
        return;

    m_stateText = arg;
    emit stateTextChanged(arg);
}
void setPrinterType(int arg)
{
    if (m_printerType == arg)
        return;

    m_printerType = arg;
    emit printerTypeChanged(arg);
}
void setTimeStarted(int arg)
{
    if (m_timeStarted == arg)
        return;

    m_timeStarted = arg;
    emit timeStartedChanged(arg);
}
void setCartridges(QList<QObject*> arg)
{
    if (m_cartridges == arg)
        return;

    m_cartridges = arg;
    emit cartridgesChanged(arg);
}
};

#endif // PRINTERENGINE_H
