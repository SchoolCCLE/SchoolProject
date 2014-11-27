#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include <QObject>
#include <job.h>
#include <QDebug>
class JobController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Job*> jobsList READ getJobsList WRITE setJobsList NOTIFY jobsListChanged)

    QList<Job*> m_jobsList;

public:
    explicit JobController(QObject *parent = 0);


QList<Job*> getJobsList() const
{
    return m_jobsList;
}

signals:

void jobsListChanged(QList<Job*> arg);

public slots:

void setJobsList(QList<Job*> arg)
{
    if (m_jobsList == arg)
        return;

    m_jobsList = arg;
    emit jobsListChanged(arg);
}

void addJob(QString fileURL){
    Job * myJob = new Job(fileURL);
    QObject::connect(myJob, SIGNAL(printEnd()), this, SLOT(executeJob()));
    m_jobsList.append(myJob);
}

void executeJob(){

    if (!m_jobsList.isEmpty())
    {

        for (int i=0; i < m_jobsList.count(); i++)
        {
            if (m_jobsList.at(i)->getJobStatus() == "WAITING TO PRINT")
            {
                m_jobsList.at(i)->setJobStatus("PRINTING");
                break;
            }

        }
    }else{
        qDebug() << "No jobs to print";
    }
}
};

#endif // JOBCONTROLLER_H
