#ifndef CARTUCHOCONTROLLER_H
#define CARTUCHOCONTROLLER_H

#include <QObject>
#include <QList>

//#include <cartuchomodel.h"

class CartuchoController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> cartuchos READ cartuchos WRITE setCartuchos NOTIFY cartuchosChanged)

public:
    explicit CartuchoController(QObject *parent = 0);

    QList<QObject*> cartuchos() const;


signals:

    void cartuchosChanged(QList<QObject*> arg);

public slots:

    void setCartuchos(QList<QObject*> arg);




private:
    QList<QObject*> m_cartuchos;

};

#endif // CARTUCHOCONTROLLER_H
