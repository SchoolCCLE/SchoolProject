#include "cartridge.h"

Cartridge::Cartridge(QString col,int level,int capacity, QObject *parent) :
    QObject(parent)
{

    m_level=level;
    m_capacity = capacity;
    m_color = col;

    m_cartridgeStatus = 1;

    if (m_level = 0){
        m_cartridgeStatus = 4;
    }
    if ((m_level < 5)&&(m_level >0)){
        m_cartridgeStatus = 3;
    }

}
