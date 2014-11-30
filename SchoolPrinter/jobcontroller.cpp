#include "jobcontroller.h"
#include <QDebug>

JobController::JobController(QQmlContext* context, QObject *parent) : QObject(parent)
{

    this->status = false;

    // ANGEL: Store the context
    this->context_ = context;

    connect(this,SIGNAL(deleteAll()),this, SLOT(deleteJobs()));
    connect(this,SIGNAL(createJob(QString,int)),this,SLOT(addJob(QString,int)));
    connect(this,SIGNAL(statusChanged(bool)), this, SLOT(changeStatus(bool)));
    // ANGEL: Connect each job list change to slot to update the context
    connect(this,SIGNAL(jobsChanged(QList<QObject*>)), this, SLOT(updateContext()), Qt::UniqueConnection);
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
    qDebug() << "add job";
    connect(jb,SIGNAL(endPrinting()), this, SLOT(nextJob()));

    emit jobsChanged(m_jobs);
}

void JobController::changeStatus(bool status)
{
    this->status = status;

    this->nextJob();
}

void JobController::nextJob()
{

    if (status) {

        //Recorro la lista hasta que encuentre el primero a la espera
        for(QList<QObject*>::iterator it = m_jobs.begin(); it != m_jobs.end(); ++it ) {
            if (static_cast<Job*>(*it)->status() == "WAITING TO PRINT" ) {
                static_cast<Job*>(*it)->changeTimer();
            }
        }
    }
}

void JobController::deleteJobs()
{
    bool find = false;

    //Recorro la lista borrando el elemento inicial hasta que el primero no se halla impreso
    while(!find || m_jobs.size() != 0){
        if (static_cast<Job*>(m_jobs.at(0))->status() == "PRINTED") {
            m_jobs.removeAt(0);
        }
        else{
            find = true;
        }
    }

}

void JobController::updateContext()
{
    // ANGEL: This will update the context. This is a fix to use your list.
    // A better solution should be use QAbstractListModel Class http://qt-project.org/doc/qt-5/qabstractlistmodel.html
    context_->setContextProperty("jobs", this);
}
