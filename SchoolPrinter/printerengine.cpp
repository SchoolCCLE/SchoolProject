#include "printerengine.h"

PrinterEngine::PrinterEngine(PrinterType type, QObject *parent) : QObject(parent)
{
    if ((int)type == (int) this->HighCapacity)
        this->m_type = "High Capacity";
    else
        this->m_type = "Low Capacity";
    this->m_status = "IDLE";
    this->m_image = "idle.png";
    this->m_statusNumber = 0;
    this->timeStr = QDateTime::currentDateTime();

}

QString PrinterEngine::status() const
{
    return m_status;
}

int PrinterEngine::statusNumber() const
{
    return m_statusNumber;
}

int PrinterEngine::time() const
{
    return this->timeStr.msecsTo(QDateTime::currentDateTime());
}

QString PrinterEngine::type() const
{
    return m_type;
}

QString PrinterEngine::image() const
{
    return m_image;
}

void PrinterEngine::setStatus(QString arg)
{
    if (m_status == arg)
        return;

    m_status = arg;

    if (arg == "IDLE")
        emit imageChanged("idle.png");
    else if (arg == "PRINTING")
        emit imageChanged("printing.jpg");
    else if (arg == "WARNING")
        emit imageChanged("Stop.jpg");
    else if (arg == "ERROR")
        emit imageChanged("Error.jpg");

    emit statusChanged(arg);
}
void PrinterEngine::setStatusNumber(int arg)
{
    if (m_statusNumber == arg)
        return;

    m_statusNumber = arg;
    emit statusNumberChanged(arg);
}

void PrinterEngine::setTime(int arg)
{
    if (m_time == arg)
        return;

    m_time = arg;
    emit timeChanged(arg);
}

void PrinterEngine::setType(QString arg)
{
    if (m_type == arg)
        return;

    m_type = arg;
    emit typeChanged(arg);
}

void PrinterEngine::setImage(QString arg)
{
    if (m_image == arg)
        return;

    m_image = arg;
    emit imageChanged(arg);
}
