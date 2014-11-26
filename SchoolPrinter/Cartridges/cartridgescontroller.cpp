#include "cartridgescontroller.h"
#include "cartridgemodel.h"

CartridgesController::CartridgesController(PrinterEngine::PrinterType printerType, QObject *parent) : QObject(parent)
{
    CartridgeModel * cartridge;
    if(printerType == 1){
        n_numCartridges = 4;
        cartridge = new CartridgeModel();
        cartridge->setInkCapacity(150);
        cartridge->setInkLevel(1);
        cartridge->setIdColor(333399);
        cartridge->setInstallationDate(QDateTime::currentDateTime());
        m_cartridges.append(cartridge);
        cartridge = new CartridgeModel();
        cartridge->setInkCapacity(150);
        cartridge->setInkLevel(0);
        cartridge->setIdColor(345678);
        cartridge->setInstallationDate(QDateTime::currentDateTime());
        m_cartridges.append(cartridge);
    }else{
        n_numCartridges = 8;
        cartridge = new CartridgeModel();
        cartridge->setInkCapacity(150);
        cartridge->setInkLevel(4);
        cartridge->setIdColor(333399);
        cartridge->setInstallationDate(QDateTime::currentDateTime());
        m_cartridges.append(cartridge);
        cartridge = new CartridgeModel();
        cartridge->setInkCapacity(150);
        cartridge->setInkLevel(0);
        cartridge->setIdColor(345678);
        cartridge->setInstallationDate(QDateTime::currentDateTime());
        m_cartridges.append(cartridge);
    }

    for(int i = 2; i < n_numCartridges; i++){
        cartridge = new CartridgeModel();
        cartridge->setInkCapacity(150);
        cartridge->setInkLevel(75);
        cartridge->setIdColor(993300);
        cartridge->setInstallationDate(QDateTime::currentDateTime());
        m_cartridges.append(cartridge);
    }
}
