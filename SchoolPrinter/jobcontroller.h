#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include <QObject>
#include <QList>
// ANGEL: Include context dependency
#include <QQmlContext>
#include <job.h>

class JobController: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> jobs READ jobs WRITE setJobs NOTIFY jobsChanged)

public:
    // ANGEL: Modify the constructor to pass the context
    JobController(QQmlContext* context, QObject *parent = 0);
    QList<QObject*> jobs() const;

public slots:
    void setJobs(QList<QObject*> arg);
    void addJob(QString name, int type);
    void changeStatus(bool status);
    void nextJob();
    void deleteJobs();
    // ANGEL: New slot to update context
    void updateContext();

signals:
    void jobsChanged(QList<QObject*> arg);
    Q_INVOKABLE void createJob(QString,int);
    Q_INVOKABLE void statusChanged(bool);
    Q_INVOKABLE void deleteAll();

private:
    QList<QObject*> m_jobs;
    bool status;
    // ANGEL: Store the context
    QQmlContext* context_;
};

#endif // JOBCONTROLLER_H
