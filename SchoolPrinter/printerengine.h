#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H

#include <QObject>
#include <QString>
#include <cartridge.h>
#include <job.h>

class PrinterEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int stateNumber READ getStateNumber WRITE setStateNumber NOTIFY stateNumberChanged)
    Q_PROPERTY(QString stateText READ getStateText NOTIFY stateTextChanged)
    Q_PROPERTY(int printerType READ getPrinterType WRITE setPrinterType NOTIFY printerTypeChanged)//Entero que nos dice el tipo de impresora 1=Alta Capacidad 0=Baja Capacidad
    Q_PROPERTY(int timeStarted READ getTimeStarted WRITE setTimeStarted NOTIFY timeStartedChanged)
    Q_PROPERTY(QList<QObject*> cartridges READ getCartridges WRITE setCartridges NOTIFY cartridgesChanged)
    Q_PROPERTY(QList<QObject*> jobs READ getJobs WRITE setJobs NOTIFY jobsChanged)
    Q_PROPERTY(QList<QObject*> jobsPrinted READ getJobsPrinted WRITE setJobsPrinted NOTIFY jobsPrintedChanged)

    int m_stateNumber;

    int m_printerType;

    int m_timeStarted;

    QList<QObject*> m_cartridges;

    QList<QObject*> m_jobs;

    QList<QObject*> m_jobsPrinted;

public:
    explicit PrinterEngine(QObject *parent = 0);

    void startJobs();

    int getStateNumber() const
    {
        return m_stateNumber;
    }

    QString getStateText() const
    {
        //Find into main.qml
        switch (m_stateNumber) {
        case 1:
            return "Ok";
            break;
        case 2:
            return "Printer";
            break;
        case 3:
            return "Warning";
            break;
        default:
            return "Error";
            break;
        }
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

    QList<QObject*> getJobs() const { return m_jobs; }

    QList<QObject*> getJobsPrinted() const { return m_jobsPrinted; }

signals:

    void stateNumberChanged(int arg);

    void stateTextChanged(QString arg);

    void printerTypeChanged(int arg);

    void timeStartedChanged(int arg);

    void cartridgesChanged(QList<QObject*> arg);

    void jobsChanged(QList<QObject*> arg);

    void jobsPrintedChanged(QList<QObject*> arg);

public slots:

    void changeState(int state);

    void setStateNumber(int arg)
    {
        if (m_stateNumber == arg)
            return;

        m_stateNumber = arg;
        emit stateNumberChanged(arg);
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

    void setJobs(QList<QObject*> arg)
    {
        if (m_jobs == arg)
            return;

        m_jobs = arg;
        emit jobsChanged(arg);
    }

    void setJobsPrinted(QList<QObject*> arg)
    {
        if (m_jobsPrinted == arg)
            return;

        m_jobsPrinted = arg;
        emit jobsPrintedChanged(arg);
    }
};

#endif // PRINTERENGINE_H
