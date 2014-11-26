#include "cartridgecontroller.h"
#include "printerengine.h"

CartridgeController::CartridgeController(QObject *parent) :
    QObject(parent)
{


    //for(int i=0 ; i< m_numPrintheads; i++){
        m_cartridge.append(new Cartridge("Cyan"));
        m_cartridge.append(new Cartridge("Magenta"));
        m_cartridge.append(new Cartridge("Yellow"));
        m_cartridge.append(new Cartridge("Black"));
    //}

}

QList<QObject *> CartridgeController::cartridge() const
{
    return m_cartridge;
}

void CartridgeController::escribirCartRidge(QList<QObject *> arg)
{
    if (m_cartridge != arg) {
        m_cartridge = arg;
        emit cartRidgeCambio(arg);
    }
}

