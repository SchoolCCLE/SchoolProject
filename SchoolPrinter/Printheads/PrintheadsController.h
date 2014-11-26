#ifndef PRINTHEADSCONTROLLER_H
#define PRINTHEADSCONTROLLER_H

#include <QObject>
#include <QList>


class PrintheadsController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> printheads READ printheads WRITE setPrintheads NOTIFY printheadsChanged)

public:
    explicit PrintheadsController(QObject *parent = 0);

    QList<QObject*> printheads() const;

signals:

    void printheadsChanged(QList<QObject*> arg);

public slots:

    void setPrintheads(QList<QObject *> arg);

private:
    QList<QObject*> m_printheads;
    int m_numPrintheads;
};

#endif // PRINTHEADSCONTROLLER_H
