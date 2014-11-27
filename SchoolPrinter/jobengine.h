#ifndef JOBENGINE_H
#define JOBENGINE_H

#include <QObject>
#include <QList>
#include <job.h>
#include <QTime>

class JobEngine : public QObject
{
    Q_OBJECT
    QList<QObject*> m_jobs;

public:
    explicit JobEngine(QObject *parent = 0);
    Q_PROPERTY(QList<QObject*> jobs READ jobs WRITE setJobs NOTIFY jobsChanged)


QList<QObject*> jobs() const
{
    return m_jobs;
}

signals:

void jobsChanged(QList<QObject*> arg);

public slots:

void setJobs(QList<QObject*> arg)
{
    if (m_jobs == arg)
        return;

    m_jobs = arg;
    emit jobsChanged(arg);
}
};

#endif // JOBENGINE_H
