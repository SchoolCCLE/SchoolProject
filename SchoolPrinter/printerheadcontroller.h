#ifndef PRINTERHEADCONTROLLER_H
#define PRINTERHEADCONTROLLER_H

#include <QObject>
#include "../databaseEngine/databaseengine.h"
#include <QTime>


class printerHeadcontroller: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString Salud READ getSalud WRITE setSalud NOTIFY saludChanged)
    Q_PROPERTY(QString Warranty READ getWarranty WRITE setWarranty NOTIFY warrrantyChanged)

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
