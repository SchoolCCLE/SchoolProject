#ifndef PRINTERHEADCONTROLLER_H
#define PRINTERHEADCONTROLLER_H

#include <QObject>
#include "../databaseEngine/databaseengine.h"


class printerHeadcontroller: public QObject
{
    Q_OBJECT
public:
    static printerHeadcontroller* getInstance();
    QString getSalud(QString id);
    QString getColor(QString id);
    QString getWarranty(QList<QVariant> printHead);
signals:
    Q_INVOKABLE void statusFailed(bool status);
public slots:
    void checkStatus(QString);
private:
    explicit printerHeadcontroller(QObject *parent = 0);
    DatabaseEngine* dataBase_;

};

#endif // PRINTERHEADCONTROLLER_H
