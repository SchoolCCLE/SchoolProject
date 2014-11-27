#include "job.h"

Job::Job(int type, QString name, QObject *parent) :
    QObject(parent)
{
    generateTime();
    m_jobName = name;
    m_jobType = type;
    m_jobState = 3;
    m_jobID = ids_jobs;
    ++ids_jobs;

}

void Job::generateTime()
{
    m_timePrinting = qrand()%301+30;
}

int Job::ids_jobs = 0;
