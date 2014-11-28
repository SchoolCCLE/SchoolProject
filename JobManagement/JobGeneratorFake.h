#ifndef JOBGENERATORFAKE_H
#define JOBGENERATORFAKE_H

#include <QObject>
#include <QTimer>
#include "Job.h"

class JobGeneratorFake : public QObject
{
    Q_OBJECT
public:
    explicit JobGeneratorFake(QObject *parent = 0);

    void start();
    void stop();
signals:
    void jobGenerated(Job* job);
public slots:
    void generateJob();

private:
    QTimer* generatorTimer_;

    QString generateTitle();
};

#endif // JOBGENERATORFAKE_H
