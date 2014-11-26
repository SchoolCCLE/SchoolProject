#ifndef CARTRIDGECONTROLLER_H
#define CARTRIDGECONTROLLER_H

#include <QObject>
#include <QList>
#include "cartridges.h"

class CartridgeController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> cartridge READ cartridge WRITE escribirCartRidge NOTIFY cartRidgeCambio)

public:
    explicit CartridgeController(QObject *parent = 0);

    QList<QObject*> cartridge() const;

signals:

    void cartRidgeCambio(QList<QObject*> arg);

public slots:

    void escribirCartRidge(QList<QObject *> arg);

private:
    QList<QObject*> m_cartridge;
    int m_numCartRidges;
};

#endif // CARTRIDGECONTROLLER_H
