#include "printerengine.h"

PrinterEngine::PrinterEngine(QObject *parent) :
    QObject(parent)
{

    m_printerType = 1;
    if (m_printerType == 0){
    m_cartridges.append(new Cartridge("Cyan",30,200));
    m_cartridges.append(new Cartridge("Magenta",30,200));
    m_cartridges.append(new Cartridge("Yellow",30,200));
    m_cartridges.append(new Cartridge("Black",30,200));
    }
    if (m_printerType == 1){
    m_cartridges.append(new Cartridge("Cyan",50,200));
    m_cartridges.append(new Cartridge("Magenta",30,200));
    m_cartridges.append(new Cartridge("Yellow",20,200));
    m_cartridges.append(new Cartridge("Black",100,200));
    m_cartridges.append(new Cartridge("Cyan",40,200));
    m_cartridges.append(new Cartridge("Magenta",100,200));
    m_cartridges.append(new Cartridge("Yellow",100,200));
    m_cartridges.append(new Cartridge("Black",90,200));
    }

}

void PrinterEngine::changeState(int state)
{
    if (state ==1){
        setStateNumber(1);
        m_stateText = "Idle";
    }
    if (state ==3){
        setStateNumber(3);
        m_stateText = "Warning";
    }
    if (state ==4){
        setStateNumber(4);
        m_stateText = "Error";
    }

}
