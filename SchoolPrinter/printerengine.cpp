#include "printerengine.h"

PrinterEngine::PrinterEngine(PrinterType type, QObject *parent) : QObject(parent)
{
    if ((int)type == (int) this->HighCapacity)
        this->setType("High Capacity");
    else
        this->setType("Low Capacity");
    this->setStatus("IDLE");
    this->setStatusNumber(0);
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

    //Update status number and associated image
    if (arg == "IDLE" || arg == "OK") {
        this->setStatusNumber(0);
        emit setImage("idle.png");
    } else if (arg == "PRINTING") {
        this->setStatusNumber(1);
        emit setImage("printing.jpg");
    } else if (arg == "WARNING") {
        this->setStatusNumber(2);
        emit setImage("Stop.png");
    } else if (arg == "ERROR") {
        this->setStatusNumber(3);
        emit setImage("error.png");
    }

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
