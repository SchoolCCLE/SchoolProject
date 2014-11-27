#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include <QObject>
#include <QList>
#include <job.h>

class JobController: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> jobs READ jobs WRITE setJobs NOTIFY jobsChanged)

public:
    JobController(QObject *parent = 0);
    QList<QObject*> jobs() const;

public slots:
    void setJobs(QList<QObject*> arg);
    void addJob(QString name, int type);
    void changeStatus(bool status);
    void nextJob();

signals:
    void jobsChanged(QList<QObject*> arg);
    Q_INVOKABLE void createJob(QString,int);
    Q_INVOKABLE void statusChanged(bool);

private:
    QList<QObject*> m_jobs;
    bool status;
};

#endif // JOBCONTROLLER_H
