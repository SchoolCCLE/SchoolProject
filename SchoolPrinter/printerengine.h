#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H

#include <QObject>
#include <QDateTime>

/**
 * @brief The PrinterEngine class
 * author Roberto de Castro
 */
class PrinterEngine  : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int statusNumber READ statusNumber WRITE setStatusNumber NOTIFY statusNumberChanged)
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)

public:
    enum PrinterType {HighCapacity, LowCapacity};
    enum PrinterStatus {
        IDLE,
        PRINTING,
        WARNING,
        ERROR
    };
    PrinterEngine(PrinterType type, QObject *parent = 0);

    QString status() const;
    int statusNumber() const;
    int time() const;
    QString type() const;
    QString image() const;

public slots:
    void setStatus(QString arg);
    void setStatusNumber(int arg);
    void setTime(int arg);
    void setType(QString arg);
    void setImage(QString arg);

private:
    QString m_status;
    int m_statusNumber;
    int m_time;
    QString m_type;
    QDateTime timeStr;

    QString m_image;

signals:
    void statusChanged(QString arg);
    void statusNumberChanged(int arg);
    void timeChanged(int arg);
    void typeChanged(QString arg);
    void imageChanged(QString arg);
};

#endif // PRINTERENGINE_H
