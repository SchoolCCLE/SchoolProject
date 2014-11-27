#include "job.h"
#include <QtGlobal>

int Job::id = 0;

Job::Job(QString name, JobType type, QObject *parent) : QObject(parent)
{
    this->jobId = id;
    this->setName(name);
    this->setType((int) type);
    this->setStatus("WAITING TO PRINT");
    this->setTime(this->randomNumber(30,330)*1000);
    this->setInkBlack(this->randomNumber(100,1000));
    this->setInkCyan(this->randomNumber(100,1000));
    this->setInkMagenta(this->randomNumber(100,1000));
    this->setInkYellow(this->randomNumber(100,1000));
    this->setInitialTime(this->time());

    this->printTime = new QTimer(this);
    this->printTime->setInterval(this->time());

    connect(this->printTime, SIGNAL(timeout()), this, SLOT(setStatus("PRINTED")));

    id++;
}

Job::~Job()
{
    delete this->printTime;
}

int Job::type() const
{
    return m_type;
}

QString Job::name() const
{
    return m_name;
}

int Job::time() const
{
    return m_time;
}

QString Job::status() const
{
    return m_status;
}

int Job::getJobId()
{
    return this->jobId;
}

void Job::setType(int arg)
{
    if (m_type == arg)
        return;

    m_type = arg;
    emit typeChanged(arg);
}

void Job::setName(QString arg)
{
    if (m_name == arg)
        return;

    m_name = arg;
    emit nameChanged(arg);
}

void Job::setTime(int arg)
{
    if (m_time == arg)
        return;

    m_time = arg;
    emit timeChanged(arg);
}

void Job::setStatus(QString arg)
{
    if (m_status == arg)
        return;

    m_status = arg;
    emit statusChanged(arg);
}

void Job::changeTimer()
{
    if (this->printTime->isActive()) {
        this->printTime->stop();
        this->setStatus("WAITING TO PRINT");
        emit changeStatusPrinter(1);
    } else {
        this->printTime->start();
        this->setStatus("PRINTING");
        emit changeStatusPrinter(2);
    }
}
int Job::getInitialTime() const
{
    return initialTime;
}

void Job::setInitialTime(int value)
{
    initialTime = value;
}


int Job::getInkBlack() const
{
    return inkBlack;
}

void Job::setInkBlack(int value)
{
    inkBlack = value;
}

int Job::getInkYellow() const
{
    return inkYellow;
}

void Job::setInkYellow(int value)
{
    inkYellow = value;
}

int Job::getInkMagenta() const
{
    return inkMagenta;
}

void Job::setInkMagenta(int value)
{
    inkMagenta = value;
}

int Job::getInkCyan() const
{
    return inkCyan;
}

void Job::setInkCyan(int value)
{
    inkCyan = value;
}

int Job::randomNumber(int floor, int top)
{
    return qrand() % ((top + 1) - floor) + floor;
}
