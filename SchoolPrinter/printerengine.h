#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H
#include <QObject>
#include <QTime>

class PrinterEngine : public QObject
{
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
signals:

public slots:

private:

    int printerStatus =0;
    int time;
    QTime timer;
    QString stringStatus;
    Type printerCapacity;
};

#endif // PRINTERENGINE_H
