#include "cartuchomodel.h"

int CartuchoModel::id = 0;

CartuchoModel::CartuchoModel(QString color, QObject *parent) :
    QObject(parent)
{
    this->setColor(color);
    this->setStatus("OK");
    this->setCapacity(750);
    this->setLevel(750);
    this->setInstallDate(QDateTime::currentDateTime());
    id++;
}

QString CartuchoModel::status() const
{
    return m_status;
}

QString CartuchoModel::color() const
{
    return m_color;
}

int CartuchoModel::level() const
{
    return m_level;
}

int CartuchoModel::capacity() const
{
    return m_capacity;
}

QDateTime CartuchoModel::installDate() const
{
    return m_installDate;
}

void CartuchoModel::setStatus(QString arg)
{
    if (m_status == arg)
        return;


    //Update status number and associated image
    if (arg == "IDLE" || arg == "OK") {
        emit setImage("idle.png");
    } else if (arg == "PRINTING") {
        emit setImage("printing.jpg");
    } else if (arg == "WARNING") {
        emit setImage("Stop.png");
    } else if (arg == "ERROR") {
        emit setImage("error.png");
    }

    m_status = arg;
    emit statusChanged(arg);
}

void CartuchoModel::setColor(QString arg)
{
    if (m_color == arg)
        return;

    m_color = arg;
    emit colorChanged(arg);
}

void CartuchoModel::setLevel(int arg)
{
    if (m_level == arg)
        return;

    m_level = arg;

    //Update status cartdrige
    if (arg < 5)
        emit setStatus("WARNING");
    else if (arg == 0)
        emit setStatus("ERROR");
    else
        emit setStatus("OK");

    emit levelChanged(arg);
}

void CartuchoModel::setCapacity(int arg)
{
    if (m_capacity == arg)
        return;

    m_capacity = arg;
    emit capacityChanged(arg);
}

void CartuchoModel::setInstallDate(QDateTime arg)
{
    if (m_installDate == arg)
        return;

    m_installDate = arg;
    emit installDateChanged(arg);
}

QString CartuchoModel::image() const
{
    return m_image;
}

void CartuchoModel::setImage(QString arg)
{
    if (m_image == arg)
        return;

    m_image = arg;
    emit imageChanged(arg);
}
