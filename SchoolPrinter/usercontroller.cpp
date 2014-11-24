#include "usercontroller.h"
#include <QDebug>
#include <QCryptographicHash>

UserController *UserController::getInstance()
{
    static UserController * theInstance = new UserController();
    return theInstance;
}

UserController::UserController(QObject *parent) :
    QObject(parent)
{
    dataBase_ = DatabaseEngine::getInstance();
    dataBase_->setParent(this);
    QList<QVariant> data;

    data.clear();
    data << QVariant(1) << QVariant("root") << QVariant("Super User") << QVariant(getPassHash("root"));
    dataBase_->setUser(data);
    data.clear();
    data << QVariant(2) << QVariant("user") << QVariant("Admin") << QVariant(getPassHash("admin"));
    dataBase_->setUser(data);
}

QString UserController::getPassHash(QString passwd)
{
    QCryptographicHash hashGenerator(QCryptographicHash::Sha1);
    hashGenerator.addData(passwd.toLatin1());
    return QString(hashGenerator.result().toHex()).toUpper();
}

QString UserController::getUserHash(QString user)
{
    datamap users =dataBase_->getUsers();
    for (datamap::iterator it = users.begin() ; it != users.end(); ++it)
    {
        if(it.value().at(0).toString() == user)
        {
            return it.value().at(2).toString();
        }
    }
    return "";
}

void UserController::checkLoging(QString user,QString passwd){
    qDebug() << "User[" << user << "] Passwd[" << passwd << "]";
    QString hash = getUserHash(user);
    if(hash == getPassHash(passwd)){
        emit accessGranted(true);
    }
    else
    {
        emit accessGranted(false);
    }
}
