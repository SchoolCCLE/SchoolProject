#include "printerengine.h"
#include "QDateTime"

PrinterEngine::PrinterEngine(QObject *parent) :
    QObject(parent)
{

    dataBase_ = DatabaseEngine::getInstance();
    dataBase_->setParent(this);
    QList<QVariant> data;

    data.clear();
    data << QVariant(0) << QVariant(1) << QVariant(100) << QVariant(true) << QVariant(QDateTime::currentDateTime());
    dataBase_->setPrintHead(data);
    data.clear();
    data << QVariant(1) << QVariant(2) << QVariant(80) << QVariant(true) << QVariant(QDateTime::currentDateTime());
    dataBase_->setPrintHead(data);
    data.clear();
    data << QVariant(2) << QVariant(3) << QVariant(10) << QVariant(false) << QVariant(QDateTime::currentDateTime());
    dataBase_->setPrintHead(data);
    data.clear();
    data << QVariant(3) << QVariant(4) << QVariant(30) << QVariant(true) << QVariant(QDateTime::currentDateTime());
    dataBase_->setPrintHead(data);
    data.clear();

    QList<PrinterHeads> myListOfPH;
    myListOfPH.clear();

    //setTimeStarted(QDateTime::currentDateTime().toString());

    setPrinterType(1);

    datamap phDDBB;
    phDDBB = DatabaseEngine::getPrintheads();
    for (int i=0;i<4;++i){
        myListOfPH.append(PrinterHeads::PrinterHeads(i,phDDBB[i]));


    }



    if (getPrinterType() == 1){
        for (int i=0;i<4;++i){
            myListOfPH.append(myListOfPH[i]);
         }
     }
    setCabezales(myListOfPH);


}
