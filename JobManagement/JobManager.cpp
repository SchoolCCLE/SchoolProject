#include "JobManager.h"
#include <QDebug>

JobManager::JobManager(QQmlContext* context, QObject *parent) :
    QObject(parent)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    context_ = context;
    connect(this, SIGNAL(listUpdated()), this, SLOT(updateContext()));
}

void JobManager::start()
{
    startNextJob();
}

QList<QObject *> JobManager::list()
{
    return list_;
}

void JobManager::addJob(Job *job)
{
    job->setId(list_.size());
    list_.append(job);
    emit listUpdated();
}

void JobManager::startNextJob()
{
    disconnect(this, SIGNAL(listUpdated()), this, SLOT(startNextJob()));
    int i = 0;
    currentJob = 0;
    while( i < list_.size() && !currentJob) {
        Job* job = qobject_cast<Job*>(list_.at(i));
        if (!job->isPrinted())
        {
            currentJob = job;
        }
        i++;
    }

    if (currentJob)
    {
        currentJob->setPrinting(true);
        qDebug() << "Start job " << currentJob->getId() << " time: " << currentJob->getPrintTime();
        QTimer::singleShot(currentJob->getPrintTime()*1000, this, SLOT(endCurrentJob()));
    }
    else {
        connect(this, SIGNAL(listUpdated()), this, SLOT(startNextJob()), Qt::UniqueConnection);
    }
}

void JobManager::endCurrentJob()
{
    currentJob->setPrinting(false);
    currentJob->setprinted(true);
    qDebug() << "Ended job " << currentJob->getId();
    startNextJob();
}

void JobManager::updateContext()
{
    context_->setContextProperty("list", QVariant::fromValue(list_));
}
