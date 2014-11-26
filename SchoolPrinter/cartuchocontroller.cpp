#include "cartuchocontroller.h"

CartuchoController::CartuchoController(QObject *parent):
    QObject(parent)
{

}

QList<QObject *> CartuchoController::cartuchos() const
{
    return m_cartuchos;
}

void CartuchoController::setCartuchos(QList<QObject *> arg)
{
    {
        if (m_cartuchos == arg)
            return;

        m_cartuchos = arg;
        emit cartuchosChanged(arg);
    }
}


