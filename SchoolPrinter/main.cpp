#include <QQmlApplicationEngine>
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
#include <jobengine.h>

#include "Printheads/PrintheadsController.h"


int main(int argc, char *argv[])
{


    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);
    PrinterEngine* pe = new PrinterEngine();
    pe->setParent(&app);
    JobEngine* je =new JobEngine();

    //PrintheadsController* phController = new PrintheadsController();

    //engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));
    //engine.rootContext()->setContextProperty("cartridges_",QVariant::fromValue(phController->printheads()));//NECESITAMOS CLASE CARTRIDGES QUE DEFINA NUMERO DE CARTRIDGES.
    engine.rootContext()->setContextProperty("_myModel",pe);
    engine.rootContext()->setContextProperty("_jobs",je);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    QObject::connect(engine.rootObjects().at(0),SIGNAL(addJob(string)),je, SLOT(addNewJob(QString)));


    //QObject::connect(pe, SIGNAL(cartridgeStatusChanged(int)), pe , SLOT(changeState(int)));
    return app.exec();
}
