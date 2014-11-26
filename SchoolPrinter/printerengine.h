#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H
#include <QDateTime>
#include <QObject>
#include <QString>


class PrinterEngine : public QObject
{
    Q_PROPERTY(StateType printerState READ getPrinterState WRITE setPrinterState NOTIFY printerStateChanged)
    Q_PROPERTY(QString printerStateText READ getPrinterStateText WRITE setPrinterStateText NOTIFY printerStateTextChanged)

    Q_OBJECT
public:
    enum PrinterType {HIGH_CAPACITY, LOW_CAPACITY};
    enum StateType {IDLE, PRINTING, WARNING, ERROR};

    explicit PrinterEngine(PrinterType type, QObject *parent = 0);

    int getTimeWorking() const;


    PrinterType getPrinterType() const;

    StateType getPrinterState() const
    {
        return m_printerState;
    }

    QString getPrinterStateText() const
    {
        switch (m_printerState) {
        case IDLE:
            return "IDLE";

        case PRINTING:
            return "PRINTING";

        case WARNING:
            return "WARNING";

        case ERROR:
            return "ERROR";

        default:
            return "";
        }
    }

private:

    QDateTime startTime;
    PrinterType printerType;

    StateType m_printerState;

    QString m_printerStateText;

signals:

void printerStateChanged(StateType arg);

void printerStateTextChanged(QString arg);

public slots:


void setPrinterState(StateType arg)
{
    if (m_printerState == arg)
        return;

    m_printerState = arg;
    switch (m_printerState) {
    case IDLE:
        setPrinterStateText("IDLE");

    case PRINTING:
        setPrinterStateText("PRINTING");

    case WARNING:
        setPrinterStateText("WARNING");

    case ERROR:
        setPrinterStateText("ERROR");

    default:
        break;
    }
    emit printerStateChanged(arg);
}


void setPrinterStateText(QString arg)
{
    if (m_printerStateText == arg)
        return;

    m_printerStateText = arg;
    emit printerStateTextChanged(arg);
}
};

#endif // PRINTERENGINE_H
