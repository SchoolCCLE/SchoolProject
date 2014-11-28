#ifndef JOBMANAGER_H
#define JOBMANAGER_H

#include <QObject>
#include "Job.h"
#include <QQmlContext>

class JobManager : public QObject
{
    Q_OBJECT
public:
    explicit JobManager(QQmlContext* context, QObject *parent = 0);

    void start();

    QList<QObject*> list();
signals:

    void listUpdated();
public slots:
    void addJob(Job* job);

private:
    QList<QObject*> list_;


    Job* currentJob;
    QQmlContext* context_;


private slots:

    void startNextJob();
    void endCurrentJob();


    void updateContext();
};

#endif // JOBMANAGER_H
