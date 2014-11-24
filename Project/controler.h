#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include <QList>
#include <QCryptographicHash>
#include <QDebug>
#include "storeUser.h"
#include "databaseEngine/databaseengine.h"

class Controler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(StoreUser usuario READ getUsuario WRITE setUsuario NOTIFY usuarioChanged)

public:
    DatabaseEngine *dababaseEngine_;

    static Controler *getInstance();

    ~Controler(){}

    StoreUser getUsuario() const { return m_usuario; }

    void encode(QString cad);

public slots:

    void recibeUserIdentification(QString nickName, QString password);

    void setUsuario(StoreUser arg) {
        if ( (m_usuario.getFullName() == arg.getFullName()) && (m_usuario.getPassword() == arg.getPassword()) )
            return;

        m_usuario = arg;
        emit usuarioChanged(arg);
    }

signals:
    void usuarioChanged(StoreUser arg);

private:
    Controler();

    static Controler* controler_;

    datamap usersList_;
    StoreUser m_usuario;
};

#endif // CONTROLER_H
