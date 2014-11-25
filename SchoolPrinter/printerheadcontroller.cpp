#include "printerheadcontroller.h"

printerHeadcontroller *printerHeadcontroller::getInstance()
{
    static printerHeadcontroller * theInstance = new printerHeadcontroller();
    return theInstance;
}

printerHeadcontroller::printerHeadcontroller(){
    dataBase_ = DatabaseEngine::getInstance();
    dataBase_->setParent(this);
    QList<QVariant> data;

    data.clear();
    data << QVariant(1) << QVariant("red")<<QVariant("95")<<QVariant(getWarranty(1))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(2) << QVariant("blue")<<QVariant("97")<<QVariant(getWarranty(2))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(3) << QVariant("brown")<<QVariant("85")<<QVariant(getWarranty(3))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(4) << QVariant("grey")<<QVariant("46")<<QVariant(getWarranty(4))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(5) << QVariant("green")<<QVariant("87")<<QVariant(getWarranty(5))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(6) << QVariant("orange")<<QVariant("95")<<QVariant(getWarranty(6))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(7) << QVariant("yellow")<<QVariant("91")<<QVariant(getWarranty(7))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
    data << QVariant(8) << QVariant("black")<<QVariant("49")<<QVariant(getWarranty(8))<<QVariant(QDateTime(QDate(2014,4,21),QTime(12,23)));
    dataBase_->setPrinthead(data);
    data.clear;
}


QString printerHeadcontroller::getColor(QString id){
    datamap printerHeads = dataBase_->getPrintheads();
    for (datamap::iterator it = printerHeads.begin() ; it != printerHeads.end(); ++it)
    {
        if(it.value().at(0).toString() == id)
        {
            return it.value().at(1).toString();
        }
    }

}

QString printerHeadcontroller::getSalud(QString id){

    datamap printerHeads = dataBase_->getPrintheads();
    for (datamap::iterator it = printerHeads.begin() ; it != printerHeads.end(); ++it)
    {
        if(it.value().at(0).toString() == id)
        {
            return it.value().at(2).toString();
        }
    }
}

QString printerHeadcontroller::getWarranty(QString id){

    datamap printerHeads = dataBase_->getPrintheads();
    for (datamap::iterator it = printerHeads.begin() ; it != printerHeads.end(); ++it)
    {
        if(it.value().at(0).toString() == id)
        {
            if(it.value().at(4)==QDateTime.currentDateTime()){
                it.value().at(3)="SI";
            } else{
                it.value().at(3)="NO";
            }
        }
    }
}

