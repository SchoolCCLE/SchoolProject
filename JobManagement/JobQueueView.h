#ifndef JOBQUEUEVIEW_H
#define JOBQUEUEVIEW_H

#include <QObject>

class JobQueueView : public QObject
{
    Q_OBJECT
public:
    explicit JobQueueView(QObject *parent = 0);

    void show();
signals:

public slots:

};

#endif // JOBQUEUEVIEW_H
