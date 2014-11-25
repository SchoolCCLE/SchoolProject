#include "engine.h"

int Engine:: counterEvent = 0;

Engine::Engine(QObject *parent) :
    QObject(parent)
{
    startTimer(1000); // 1 sec timer
}
QString Engine::getState() const
{
    return state;
}

void Engine::setState(const QString &value)
{
    state = value;
}

QString Engine::getPrinterType() const
{
    return printerType;
}

void Engine::setPrinterType(const QString &value)
{
    printerType = value;
}
int Engine::getTimeWorking() const
{
    return timeWorking;
}

void Engine::setTimeWorking(int value)
{
    timeWorking = value;
}

QString Engine::formatTimeWorking()
{
    int days = timeWorking / 60 / 60 / 24;
    int hours = (timeWorking / 60 / 60) % 24;
    int minutes = (timeWorking / 60) % 60;
    int seconds = timeWorking % 60;

    QString time;
    time << days << " Days" << hours << " Hours" <<  minutes << " Minutes" << seconds << " Seconds";
    return time;
}


void Engine::timerEvent(QTimerEvent *evt)
{
    counterEvent =  counterEvent + 1;
    setTimeWorking(counterEvent);
}



