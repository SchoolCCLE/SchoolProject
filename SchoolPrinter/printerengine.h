#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H
#include <QObject>
#include <QTime>
#include <showqml.h>
class PrinterEngine : public QObject
{
    Q_PROPERTY(int status READ getStatus WRITE setStatus NOTIFY statusChanged)

    Q_OBJECT
public:
    enum Type {HIGH_CAPACITY=0, LOW_CAPACITY};

    PrinterEngine(Type printerCap);
    int getPrinterStatus();
    QString getStringStatus();
    int runningTime();
    QString getPrinterType();
    void setPrinterStatus(int status);
    void setStringStatus(int status);
    QString getPrinterCapacity();
    ~PrinterEngine();
    int getStatus() const
    {
        return m_status;
    }

    QString getLoadPrinter() const
    {
        return m_loadPrinter;
    }

signals:

    void statusChanged(int arg);


public slots:

void setStatus(int arg)
{
    if (m_status == arg)
        return;

    m_status = arg;
    emit statusChanged(arg);
}

void setLoadPrinter()
{
    ShowQml::setQml("Printer.qml");
}

private:

    int printerStatus =0;
    int time;
    QTime timer;
    QString stringStatus;
    Type printerCapacity;
    int m_status;
    QString m_loadPrinter;
};

#endif // PRINTERENGINE_H
