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

    qmlView->show();

    PrinterEngine* pe = new PrinterEngine(0);
    pe->setStateNum(1);
    pe->setStateText("Printing");
    pe->setTiempo(60);

    qDebug() << "Tipo de impresora:" << pe->getTipo() << endl
             << "Estado de la impresora" << pe->getStateText() << endl
             << "Tiempo activa:" << pe->getTiempo() << endl;

    qmlView->getContext()->setContextProperty("pe_",pe);

    return app.exec();
}
