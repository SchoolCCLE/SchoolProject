#include "cartridgescontroller.h"
#include "cartridgemodel.h"

CartridgesController::CartridgesController(PrinterEngine::PrinterType printerType, QObject *parent) : QObject(parent)
{
    CartridgeModel * cartridge;
    if(printerType == 1){
        n_numCartridges = 4;
        cartridge = new CartridgeModel();
        cartridge->setInkLevel(100);
        m_cartridges.append(cartridge);
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
    }else{
        n_numCartridges = 8;
        cartridge = new CartridgeModel();
        cartridge->setInkLevel(100);
        m_cartridges.append(cartridge);

        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
        m_cartridges.append(new CartridgeModel());
    }
}
