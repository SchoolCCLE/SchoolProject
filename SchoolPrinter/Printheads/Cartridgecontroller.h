#ifndef CARTRIDGECONTROLLER_H
#define CARTRIDGECONTROLLER_H

#include <QObject>
#include <QList>
#include "cartridgemodel.h"

class CartridgeController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> cartridges READ cartridges WRITE setCartridges NOTIFY cartridgesChanged)

public:
    explicit CartridgeController(QObject *parent = 0);

    QList<QObject*> cartridges() const;

signals:

    void cartridgesChanged(QList<QObject*> arg);

public slots:

    void setCartridges(QList<QObject *> arg);

private:
    QList<QObject*> m_cartridges;
    int m_numCartridges;
};

#endif // CARTRIDGECONTROLLER_H
