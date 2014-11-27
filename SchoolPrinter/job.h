#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QTime>

class Job : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int jobID READ jobID WRITE setJobID NOTIFY jobIDChanged)
    Q_PROPERTY(int jobType READ jobType WRITE setJobType NOTIFY jobTypeChanged)
    Q_PROPERTY(QString jobName READ jobName WRITE setJobName NOTIFY jobNameChanged)
    Q_PROPERTY(int timePrinting READ timePrinting WRITE setTimePrinting NOTIFY timePrintingChanged)
    Q_PROPERTY(int jobState READ jobState WRITE setJobState NOTIFY jobStateChanged)


    int m_jobType;

    int m_jobID;

QString m_jobName;

int m_timePrinting;

int m_jobState;

public:
    explicit Job(QObject *parent = 0);

    void generateTime();

int jobType() const
{
    return m_jobType;
}

int jobID() const
{
    return m_jobID;
}

QString jobName() const
{
    return m_jobName;
}

int timePrinting() const
{
    return m_timePrinting;
}

int jobState() const
{
    return m_jobState;
}

signals:

void jobTypeChanged(int arg);

void jobIDChanged(int arg);

void jobNameChanged(QString arg);

void timePrintingChanged(int arg);

void jobStateChanged(int arg);

public slots:

void setJobType(int arg)
{
    if (m_jobType == arg)
        return;

    m_jobType = arg;
    emit jobTypeChanged(arg);
}
void setJobID(int arg)
{
    if (m_jobID == arg)
        return;

    m_jobID = arg;
    emit jobIDChanged(arg);
}
void setJobName(QString arg)
{
    if (m_jobName == arg)
        return;

    m_jobName = arg;
    emit jobNameChanged(arg);
}
void setTimePrinting(int arg)
{
    if (m_timePrinting == arg)
        return;

    m_timePrinting = arg;
    emit timePrintingChanged(arg);
}
void setJobState(int arg)
{
    if (m_jobState == arg)
        return;

    m_jobState = arg;
    emit jobStateChanged(arg);
}
};

#endif // JOB_H
