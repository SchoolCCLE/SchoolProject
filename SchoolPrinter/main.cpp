#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>
#include "usercontroller.h"
#include "showqml.h"
#include "printerengine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    ShowQml * qmlView = new ShowQml();

    qmlView->getContext()->setContextProperty("userModel_",uc);

    QObject::connect(qmlView->getEngine(),SIGNAL(quit()),&app,SLOT(quit()));
    qmlView->setQml("login.qml");

    QObject::connect(qmlView->getRootItem() ,SIGNAL(dataInput(QString,QString)),uc,SLOT(checkLoging(QString,QString)));
    QObject::connect(qmlView->getRootItem() ,SIGNAL(cancel()),&app,SLOT(quit()));
    QObject::connect(uc ,SIGNAL(accessGranted(bool)),qmlView,SLOT(accessGranted(bool)));

    PrinterEngine *p = new PrinterEngine(PrinterEngine::HIGH_CAPACITY);
    p->setPrinterStatus(0);
    p->getPrinterStatus();
    p->getStringStatus();
    p->setPrinterStatus(1);
    p->getPrinterStatus();
    p->getStringStatus();
    p->setPrinterStatus(2);
    p->getPrinterStatus();
    p->getStringStatus();
    p->setPrinterStatus(3);
    p->getPrinterStatus();
    p->getStringStatus();
    p->getPrinterCapacity();
    p->setStatus(2);

    p->runningTime();

    qmlView->getContext()->setContextProperty("_model", p);

    qmlView->setQml("HomeScreen.qml");
    QObject::connect(qmlView->getRootItem() ,SIGNAL(loadPrinter()),p,SLOT(setLoadPrinter()));
//    qmlView->setQml("login.qml");


    qmlView->show();


    return app.exec();
}
