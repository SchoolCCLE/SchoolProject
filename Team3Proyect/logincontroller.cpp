#include "logincontroller.h"
#include <QDebug>
#include <QMap>

LoginController::LoginController(QObject *parent) :
    QObject(parent)
{
}

bool LoginController::loginAttempt(QString nickname, QString password)
{
    datamap users = DatabaseEngine::getInstance()->getUsers();

    // Falta hashear la password para compararla

    for(int i = 0; i < users[1].size() ; i++)
    {
        if((nickname == users[i].at(0).toString()) && (password == users[i].at(2).toString())){
            return true;
        }
    }
    return false;
}
