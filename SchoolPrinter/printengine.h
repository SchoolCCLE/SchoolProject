#ifndef PRINTENGINE_H
#define PRINTENGINE_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QDateTime>

class PrintEngine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString printType READ printType WRITE setPrintType NOTIFY printTypeChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int int_status READ int_status WRITE setInt_status NOTIFY int_statusChanged)

    enum PrintType{HighCapacity,LowCapacity};

private:
    int m_time;
    QString m_printType;
    QString m_status;
    int m_int_status;
    QDateTime timeStr;
    PrintType type;
    QMap<int,QString> statusMap;
    void initializeStatusMap();

public:
    PrintEngine(PrintType type, QObject *parent = 0);
    int time() const
    {
        return timeStr.secsTo(QDateTime::currentDateTime());
    }
    QString printType() const
    {

        return m_printType;
    }

    QString status() const
    {
        return m_status;
    }

    int getPrntStatus() const;
    void setPrntStatus(int value);
    QString getStringStatus();

    int int_status() const
    {
        return m_int_status;
    }

public slots:
    void setTime(int arg)
    {
        if (m_time == arg)
            return;

        m_time = arg;
        emit timeChanged(arg);
    }
    void setPrintType(QString arg)
    {
        if ((int) type == (int) this->HighCapacity)
            m_printType = "High Capacity";
        else
            m_printType = "Low Capacity";

        emit printTypeChanged(m_printType);
    }

    void setStatus(QString arg)
    {
        if (m_status == arg)
            return;

        m_status = arg;
        emit statusChanged(arg);
    }

    void setInt_status(int arg)
    {
        if (m_int_status == arg)
            return;

        m_int_status = arg;
        emit int_statusChanged(arg);
    }

signals:
    void timeChanged(int arg);
    void printTypeChanged(QString arg);
    void statusChanged(QString arg);
    void int_statusChanged(int arg);
};

#endif // PRINTENGINE_H
