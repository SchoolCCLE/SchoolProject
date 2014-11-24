#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>
#include <QString>
#include <databaseengine.h>

class LoginController : public QObject
{
    Q_OBJECT

public:
    explicit LoginController(QObject *parent = 0);

public slots:

    bool loginAttempt(QString nickname, QString password);

};

#endif // LOGINCONTROLLER_H
