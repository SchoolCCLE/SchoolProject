#include "job.h"

Job::Job(QObject *parent) :
    QObject(parent)
{
    generateTime();
}

void Job::generateTime()
{
    m_timePrinting = qrand()%301+30;
}
