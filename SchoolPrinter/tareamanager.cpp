#include "tareamanager.h"

#include <QDebug>

//Cada Job debe de tener su propio Thread



TareaManager::TareaManager(QObject * parent): QObject(parent)
{
    qsrand(QTime::currentTime().msec());


//    m_extension = "Pdf";
//    m_name = "Trabajo de fin de clase";
//    m_status = 0;//Waiting = 0
    m_printingTime= qrand() % ((300 + 1) - 30) + 30;
    //qDebug() << printingTime;
}

TareaManager::TareaManager(int number, QString miUrl,QObject * parent): QObject(parent)
{
    qsrand(QTime::currentTime().msec());


    m_extension = "Pdf";
    m_name = "Trabajo de fin de clase";
    m_status = 0;//Waiting = 0
    m_printingTime= qrand() % ((300 + 1) - 30) + 30;
    qDebug() <<"Objteo creado";

}

void TareaManager::buttonOkClass(int x, QString miUrl)
{
    qDebug() << "He recibido int: " << x;
    qDebug() << "He recibido QString: " << miUrl;
    m_extension="PDF";
    m_name = "trabajo";


    listaT.append(new TareaManager(x, miUrl));
//    if(estado == false)
//    {
//    m_status = 1;
//    estado =true;
//    }
//    else
//    {
//        m_status =0;
//    }

}

//void TareaManager::cuentaAtras()
//{
//    m_printingTime--;
//}
