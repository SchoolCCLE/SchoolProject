#include "engine.h"

Engine::Engine(QObject *parent) :
    QObject(parent)
{
}
QString Engine::getState() const
{
    return state;
}

void Engine::setState(const QString &value)
{
    state = value;
}
QString Engine::getTimeWorking() const
{
    return timeWorking;
}

void Engine::setTimeWorking(const QString &value)
{
    timeWorking = value;
}
QString Engine::getPrinterType() const
{
    return printerType;
}

void Engine::setPrinterType(const QString &value)
{
    printerType = value;
}



