#include "printengine.h"
#include <QDateTime>

PrintEngine::PrintEngine(PrintType type, QObject *parent) : QObject(parent)
{
    this->initializeStatusMap();
    this->type = type;
    this->m_int_status = 0;
    this->setPrintType("");
    this->timeStr  = QDateTime::currentDateTime();
}

int PrintEngine::getPrntStatus() const
{
    return m_int_status;
}

void PrintEngine::setPrntStatus(int value)
{
    m_status = statusMap.take(value);
    m_int_status = value;
}

QString PrintEngine::getStringStatus()
{
    return statusMap.take(this->getPrntStatus());
}

void PrintEngine::initializeStatusMap()
{
    statusMap.insert(0,"Idle");
    statusMap.insert(1,"Printing");
    statusMap.insert(2,"Warning");
    statusMap.insert(3,"Error");
}
