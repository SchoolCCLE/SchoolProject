#include "jobcontroller.h"

JobController::JobController(QObject *parent) : QObject(parent)
{

    this->status = false;
}

QList<QObject*> JobController::jobs() const
{
    return m_jobs;
}

void JobController::setJobs(QList<QObject*> arg)
{
    if (m_jobs == arg)
        return;

    m_jobs = arg;
    emit jobsChanged(arg);
}

void JobController::addJob(QString name, int type)
{
    Job* jb = new Job(name,type);
    m_jobs.push_back(jb);

    emit jobsChanged(m_jobs);
}

void JobController::changeStatus(bool status)
{
    this->status = status;
}

void JobController::nextJob()
{
    if (status) {
        for(QList<QObject*>::iterator it = m_jobs.begin(); it != m_jobs.end(); ++it ) {
            if (static_cast<Job*>(*it)->status() == "WAITING TO PRINT" ) {
                static_cast<Job*>(*it)->changeTimer();
            }
        }
    }
}
