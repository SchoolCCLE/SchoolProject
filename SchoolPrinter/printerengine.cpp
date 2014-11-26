#include "printerengine.h"

PrinterEngine::PrinterEngine(int type, QObject *parent) :
    QObject(parent)
{

    m_printerType = type;
    if (m_printerType == 0){
    m_cartridges.append(new Cartridge("Cyan"));
    m_cartridges.append(new Cartridge("Magenta"));
    m_cartridges.append(new Cartridge("Yellow"));
    m_cartridges.append(new Cartridge("Black"));
    }
    if (m_printerType == 1){
    m_cartridges.append(new Cartridge("Cyan"));
    m_cartridges.append(new Cartridge("Magenta"));
    m_cartridges.append(new Cartridge("Yellow"));
    m_cartridges.append(new Cartridge("Black"));
    m_cartridges.append(new Cartridge("Cyan"));
    m_cartridges.append(new Cartridge("Magenta"));
    m_cartridges.append(new Cartridge("Yellow"));
    m_cartridges.append(new Cartridge("Black"));
    }

}

void PrinterEngine::changeState(int state)
{
    if (state ==1){
        m_stateNumber = 1;
        m_stateText = "Idle";
    }
    if (state ==3){
        m_stateNumber = 3;
        m_stateText = "Warning";
    }
    if (state ==4){
        m_stateNumber = 4;
        m_stateText = "Error";
    }

}
