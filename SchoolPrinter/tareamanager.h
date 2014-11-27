#ifndef TAREAMANAGER_H
#define TAREAMANAGER_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QString>
#include <QTime>
#include <QtConcurrent/QtConcurrent>


class TareaManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int printingTime READ printingTime WRITE setPrintingTime NOTIFY printingTimeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString extension READ extension WRITE setExtension NOTIFY extensionChanged)

public:

    /*
     * estado 0 = waiting
     * estado 1 = printing
     */
    //static bool estado=false;

    QList <TareaManager*> listaT;

    TareaManager(QObject *parent =0);
    TareaManager(int, QString, QObject *parent =0);

    int status() const
    {
        return m_status;
    }

    int printingTime() const
    {
        return m_printingTime;
    }

    QString name() const
    {
        return m_name;
    }

    QString extension() const
    {
        return m_extension;
    }

signals:

    void statusChanged(int arg);

    void printingTimeChanged(int arg);

    void nameChanged(QString arg);

    void extensionChanged(QString arg);

public slots:

void setStatus(int arg)
{
    if (m_status == arg)
        return;

    m_status = arg;
    emit statusChanged(arg);
}

void setPrintingTime(int arg)
{
    if (m_printingTime == arg)
        return;

    m_printingTime = arg;
    emit printingTimeChanged(arg);
}

void setName(QString arg)
{
    if (m_name == arg)
        return;

    m_name = arg;
    emit nameChanged(arg);
}

void setExtension(QString arg)
{
    if (m_extension == arg)
        return;

    m_extension = arg;
    emit extensionChanged(arg);
}

void buttonOkClass(int,QString);

private:


    int m_status;
    int m_printingTime;
    QString m_name;
    QString m_extension;
};

#endif // TAREAMANAGER_H
