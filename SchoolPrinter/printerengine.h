#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H
#include <QDateTime>
#include <QObject>
#include <QString>
enum PrinterType {HIGH_CAPACITY, LOW_CAPACITY};
enum StateType {IDLE, PRINTING, WARNING, ERROR};

class PrinterEngine : public QObject
{
    Q_PROPERTY(StateType printerState READ getPrinterState WRITE setPrinterState NOTIFY printerStateChanged)

    Q_OBJECT
public:

    explicit PrinterEngine(PrinterType type, QObject *parent = 0);

    int getStartTime() const;
    QString getPrinterStateText();

    PrinterType getPrinterType() const;

    StateType getPrinterState() const
    {
        return m_printerState;
    }

private:

    QDateTime startTime;
    PrinterType printerType;

    StateType m_printerState;

signals:

void printerStateChanged(StateType arg);

public slots:


void setPrinterState(StateType arg)
{
    if (m_printerState == arg)
        return;

    m_printerState = arg;
    emit printerStateChanged(arg);
}
};

#endif // PRINTERENGINE_H
