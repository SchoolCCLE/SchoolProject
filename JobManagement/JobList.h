#ifndef JOBLIST_H
#define JOBLIST_H

#include <QObject>
#include <QList>

class JobList : public QList<QObject*>
{
    Q_OBJECT
public:
    explicit JobList();

signals:

public slots:

};

#endif // JOBLIST_H
