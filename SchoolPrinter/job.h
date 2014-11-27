#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QString>
#include <QTimer>

class Job : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)

public:
    enum JobType {PDF=0, JPG, PNG, TIFF};
    enum JobStatus {PRINTING=0, WAITINGPRINT, PRINTED};

    Job(QString name, JobType type, QObject *parent = 0);
    ~Job();
    int type() const;
    QString name() const;
    int time() const;
    QString status() const;
    int getJobId();
    int getInkCyan() const;
    void setInkCyan(int value);
    int getInkMagenta() const;
    void setInkMagenta(int value);
    int getInkYellow() const;
    void setInkYellow(int value);
    int getInkBlack() const;
    void setInkBlack(int value);

    int getInitialTime() const;
    void setInitialTime(int value);

public slots:
    void setType(int arg);
    void setName(QString arg);
    void setTime(int arg);
    void setStatus(QString arg);
    void changeTimer();

signals:
    void typeChanged(int arg);
    void nameChanged(QString arg);
    void timeChanged(int arg);
    void statusChanged(QString arg);
    void changeStatusPrinter(int);

private:
    static int id;
    int jobId;
    int initialTime;
    int inkCyan;
    int inkMagenta;
    int inkYellow;
    int inkBlack;
    QTimer* printTime;

    int m_type;
    QString m_name;
    int m_time;
    QString m_status;

    int randomNumber(int floor, int top);
};

#endif // JOB_H
