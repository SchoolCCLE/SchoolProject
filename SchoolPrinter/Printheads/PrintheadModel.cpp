#include "PrintheadModel.h"

PrintheadModel::PrintheadModel(QString color, QObject *parent) :
    QObject(parent)
{
    m_color = color;
    m_status = OK;
}

PrintheadModel::Status PrintheadModel::status() const
{
    return m_status;
}

QString PrintheadModel::color() const
{
    return m_color;
}

int PrintheadModel::health() const
{
    return m_health;
}

bool PrintheadModel::warranty() const
{
    return m_warranty;
}

QDateTime* PrintheadModel::installDate() const
{
    return m_installDate;
}

void PrintheadModel::setStatus(PrintheadModel::Status arg)
{
    if (m_status != arg) {
        m_status = arg;
        emit statusChanged(arg);
    }
}

void PrintheadModel::setColor(QString arg)
{
    if (m_color != arg) {
        m_color = arg;
        emit colorChanged(arg);
    }
}

void PrintheadModel::setHealth(int arg)
{
    if (m_health != arg) {
        m_health = arg;
        emit healthChanged(arg);
    }
}

void PrintheadModel::setWarranty(bool arg)
{
    if (m_warranty != arg) {
        m_warranty = arg;
        emit warrantyChanged(arg);
    }
}

void PrintheadModel::setInstallDate(QDateTime* arg)
{
    if (m_installDate != arg) {
        m_installDate = arg;
        emit installDateChanged(arg);
    }
}
