#include "cartridgemodel.h"

CartridgeModel::CartridgeModel(QString color, QObject *parent) : QObject(parent)
{
    m_color = color;
    m_status = OK;
    m_installDate = QDateTime::currentDateTime();
}

CartridgeModel::Status CartridgeModel::status() const
{
    return m_status;
}

QString CartridgeModel::color() const
{
    return m_color;
}

int CartridgeModel::level() const
{
    return m_level;
}

QDateTime CartridgeModel::installDate() const
{
    return m_installDate;
}

void CartridgeModel::setStatus(CartridgeModel::Status arg)
{
    if (m_status != arg) {
        m_status = arg;
        emit statusChanged(arg);
    }
}

void CartridgeModel::setColor(QString arg)
{
    if (m_color != arg) {
        m_color = arg;
        emit colorChanged(arg);
    }
}

void CartridgeModel::setLevel(int arg)
{
    if (m_level != arg) {
        m_level = arg;
        emit levelChanged(arg);
    }
}

void CartridgeModel::setInstallDate(QDateTime arg)
{
    if (m_installDate != arg) {
        m_installDate = arg;
        emit installDateChanged(arg);
    }
}

