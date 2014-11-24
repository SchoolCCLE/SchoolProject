#ifndef LOGINCONTROLER_H
#define LOGINCONTROLER_H

#include <QObject>
#include <QString>
#include <databaseengine.h>

class LoginControler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickName READ getNickName WRITE setNickName NOTIFY nickNameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY paswordChanged)
    QString m_password;

    QString m_nickName;
    Users *myUsers;


public:
    explicit LoginControler(QObject *parent = 0);

QString getPassword() const
{
    return m_password;
}

QString getNickName() const
{
    return m_nickName;
}

    bool comprobarDatos(QString _nick, QString _pass);

signals:

void paswordChanged(QString arg);

void nickNameChanged(QString arg);

public slots:

void setPassword(QString arg)
{
    if (m_password == arg)
        return;

    m_password = arg;
    emit paswordChanged(arg);
}
void setNickName(QString arg)
{
    if (m_nickName == arg)
        return;

    m_nickName = arg;
    emit nickNameChanged(arg);
}
};

#endif // LOGINCONTROLER_H
