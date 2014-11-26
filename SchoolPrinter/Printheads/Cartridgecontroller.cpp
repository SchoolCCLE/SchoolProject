#include "Cartridgecontroller.h"

CartridgeController::CartridgeController(QObject *parent) : QObject(parent)
{
    m_numCartridges = 4;

    CartridgeModel *cyan = new CartridgeModel("Cyan");
    cyan->setIdColor("idCyan");
    cyan->setLevel(50);
    cyan->setCapacity(100);

    CartridgeModel *magenta = new CartridgeModel("Magenta");
    magenta->setIdColor("idMagenta");
    magenta->setLevel(60);
    magenta->setCapacity(100);

    CartridgeModel *yellow = new CartridgeModel("Yellow");
    yellow->setIdColor("idCyan");
    yellow->setLevel(30);
    yellow->setCapacity(100);

    CartridgeModel *black = new CartridgeModel("Black");
    black->setIdColor("idBlack");
    black->setLevel(80);
    black->setCapacity(100);

    m_cartridges.append(cyan);
    m_cartridges.append(magenta);
    m_cartridges.append(yellow);
    m_cartridges.append(black);

}

QList<QObject *> CartridgeController::cartridges() const
{
    return m_cartridges;
}

void CartridgeController::setCartridges(QList<QObject *> arg)
{
    if (m_cartridges != arg) {
        m_cartridges = arg;
        emit cartridgesChanged(arg);
    }
}
