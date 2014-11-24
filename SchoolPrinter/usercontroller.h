#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>
#include "../databaseEngine/databaseengine.h"

class UserController : public QObject
{
    Q_OBJECT
public:
    static UserController* getInstance();

signals:
    Q_INVOKABLE void accessGranted(bool access);
public slots:
    void checkLoging(QString,QString);
private:
    explicit UserController(QObject *parent = 0);
    DatabaseEngine* dataBase_;

    QString getPassHash(QString passwd);
    QString getUserHash(QString user);
};

#endif // USERCONTROLLER_H
