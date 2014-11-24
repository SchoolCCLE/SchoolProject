#include "usuario.h"
#include <QCryptographicHash>

Usuario::Usuario()
{
}

QString Usuario::getNick() const
{
    return nick;
}

void Usuario::setNick(const QString &value)
{
    nick = value;
}

int Usuario::getId() const
{
    return id;
}

void Usuario::setId(int value)
{
    id = value;
}

QString Usuario::getFullName() const
{
    return fullName;
}

void Usuario::setFullName(const QString &value)
{
    fullName = value;
}

QString Usuario::getPassword() const
{
    return password;
}

QString Usuario::getPasswordHash() const
{
     QCryptographicHash hash(QCryptographicHash::Sha1);
     hash.addData(aOriginalText.toUtf8());
     return hash.result().toHex();
}

void Usuario::setPassword(const QString &value)
{
    password = value;
}

QList<QString> Usuario::getRollList() const
{
    return rollList;
}

void Usuario::setRollList(const QList<QString> &value)
{
    rollList = value;
}

void Usuario::addRoll(QString roll)
{
    rollList.append(roll);

}

QString Usuario::getRoll(int position)
{
    return rollList.at(position);
}





