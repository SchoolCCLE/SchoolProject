#include "PrintheadsController.h"
#include "PrintheadModel.h"


PrintheadsController::PrintheadsController(QObject *parent) :
    QObject(parent)
{
    m_numPrintheads = 4;

    //for(int i=0 ; i< m_numPrintheads; i++){
        m_printheads.append(new PrintheadModel("Cyan"));
        m_printheads.append(new PrintheadModel("Magenta"));
        m_printheads.append(new PrintheadModel("Yellow"));
        m_printheads.append(new PrintheadModel("Black"));
    //}
}

QList<QObject *> PrintheadsController::printheads() const
{
    return m_printheads;
}

void PrintheadsController::setPrintheads(QList<QObject *> arg)
{
    if (m_printheads != arg) {
        m_printheads = arg;
        emit printheadsChanged(arg);
    }
}
