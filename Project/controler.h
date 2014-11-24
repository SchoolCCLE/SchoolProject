#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include <QList>
#include <QCryptographicHash>
#include <QDebug>
#include "user.h"
#include "databaseengine.h"

class Controler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(User usuario READ getUsuario WRITE setUsuario NOTIFY usuarioChanged)

public:
    DatabaseEngine *dababaseEngine_;

    static Controler *getInstance();

    ~Controler(){}

    User getUsuario() const { return m_usuario; }

    void encode(QString cad);

public slots:

    void recibeUserIdentification(QString nickName, QString password);

    void setUsuario(User arg) {
        if ( (m_usuario.getFullName() == arg.getFullName()) && (m_usuario.getPassword() == arg.getPassword()) )
            return;

        m_usuario = arg;
        emit usuarioChanged(arg);
    }

signals:
    void usuarioChanged(User arg);

private:
    Controler();

    static Controler* controler_;

    datamap usersList_;
    User m_usuario;
};

#endif // CONTROLER_H
