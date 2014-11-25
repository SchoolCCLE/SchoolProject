#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QList>
#include <printerheads.h>
#include <../databaseEngine/databaseengine.h>

class PrinterEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int stateNumber READ getStateNumber WRITE setStateNumber NOTIFY stateNumberChanged)
    Q_PROPERTY(QString stateText READ getStateText WRITE setStateText NOTIFY stateTextChanged)
    Q_PROPERTY(int printerType READ getPrinterType WRITE setPrinterType NOTIFY printerTypeChanged)//Entero que nos dice el tipo de impresora 1=Alta Capacidad 0=Baja Capacidad
//    Q_PROPERTY(QTime timeStarted READ getTimeStarted WRITE setTimeStarted NOTIFY timeStartedChanged)
//    Q_PROPERTY(QString timeStarted READ getTimeStarted WRITE setTimeStarted NOTIFY timeStartedChanged)
    Q_PROPERTY(QList<PrinterHeads> cabezales READ getCabezales WRITE setCabezales NOTIFY cabezalesChanged)

public:
    explicit PrinterEngine(QObject *parent = 0);

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



//    QTime getTimeStarted() const
//    {
//        return m_timeStarted;
//    }

    QList<PrinterHeads> getCabezales() const
    {
        return m_cabezales;
    }

//    QString getTimeStarted() const
//    {
//        return m_timeStarted;
//    }

signals:

    void stateNumberChanged(int arg);

    void stateTextChanged(QString arg);

    void printerTypeChanged(int arg);



//    void timeStartedChanged(QTime arg);

    void cabezalesChanged(QList<PrinterHeads> arg);

//    void timeStartedChanged(QString arg);

public slots:

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



//void setTimeStarted(QTime arg)
//{
//    if (m_timeStarted == arg)
//        return;

//    m_timeStarted = arg;
//    emit timeStartedChanged(arg);
//}

void setCabezales(QList<PrinterHeads> arg)
{
    if (m_cabezales == arg)
        return;

    m_cabezales = arg;
    emit cabezalesChanged(arg);
}

//void setTimeStarted(QString arg)
//{
//    if (m_timeStarted == arg)
//        return;

//    m_timeStarted = arg;
//    emit timeStartedChanged(arg);
//}

private:




int m_stateNumber;
QString m_stateText;
int m_printerType;
long m_timeStarted;
QList<PrinterHeads> m_cabezales;
};

#endif // PRINTERENGINE_H
