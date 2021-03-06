#include "printerengine.h"
#include "QDebug"

PrinterEngine::PrinterEngine(QObject *parent) :
    QObject(parent)
{
    m_stateNumber=1;
    m_printerType = 1;
    if (m_printerType == 0){
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
    }
    if (m_printerType == 1){
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
    }

}

void PrinterEngine::fake(int n, QString s)
{
    qDebug() << n << s;
}

void PrinterEngine::changeState(int state)
{
    if (state ==1){
        m_stateNumber = 1;
        //m_stateText = "Idle";
    }
    if (state ==3){
        m_stateNumber = 3;
        //m_stateText = "Warning";
    }
    if (state ==4){
        m_stateNumber = 4;
        //m_stateText = "Error";
    }

}
